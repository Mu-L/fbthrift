/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

package com.facebook.thrift.util.resources;

import static com.facebook.thrift.util.resources.ResourceConfiguration.enableForkJoinPool;
import static com.facebook.thrift.util.resources.ResourceConfiguration.enableVirtualThreadScheduler;
import static com.facebook.thrift.util.resources.ResourceConfiguration.eventLoopGroupThreadPrefix;
import static com.facebook.thrift.util.resources.ResourceConfiguration.forceClientExecutionOffEventLoop;
import static com.facebook.thrift.util.resources.ResourceConfiguration.forceExecutionOffEventLoop;
import static com.facebook.thrift.util.resources.ResourceConfiguration.forkJoinPoolClientThreads;
import static com.facebook.thrift.util.resources.ResourceConfiguration.forkJoinPoolThreads;
import static com.facebook.thrift.util.resources.ResourceConfiguration.limitVirtualThreadConcurrency;
import static com.facebook.thrift.util.resources.ResourceConfiguration.maxPendingTasksForOffLoop;
import static com.facebook.thrift.util.resources.ResourceConfiguration.minNumThreadsForOffLoop;
import static com.facebook.thrift.util.resources.ResourceConfiguration.minPendingTasksBeforeNewThread;
import static com.facebook.thrift.util.resources.ResourceConfiguration.numThreadsForEventLoop;
import static com.facebook.thrift.util.resources.ResourceConfiguration.numThreadsForOffLoop;
import static com.facebook.thrift.util.resources.ResourceConfiguration.separateOffLoopScheduler;
import static com.facebook.thrift.util.resources.ResourceConfiguration.virtualThreadMaxConcurrency;

import com.google.common.util.concurrent.ThreadFactoryBuilder;
import io.netty.channel.EventLoopGroup;
import io.netty.channel.SingleThreadEventLoop;
import io.netty.util.HashedWheelTimer;
import io.netty.util.ResourceLeakDetector;
import io.netty.util.concurrent.EventExecutor;
import io.netty.util.internal.PlatformDependent;
import io.rsocket.Closeable;
import java.util.Map;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.ThreadFactory;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import reactor.core.publisher.Mono;
import reactor.core.publisher.MonoProcessor;
import reactor.core.scheduler.Scheduler;
import reactor.netty.resources.LoopResources;

class ResourcesHolder implements Closeable {
  private static final Logger LOGGER = LoggerFactory.getLogger(ResourcesHolder.class);

  private final MonoProcessor<Void> onClose = MonoProcessor.create();

  private final HashedWheelTimer timer;
  private final EventLoopGroup eventLoopGroup;
  private final LoopResources loopResources;
  private final ThriftScheduler offLoopScheduler;
  private final ThriftScheduler clientOffLoopScheduler;

  public ResourcesHolder() {
    this.timer = createHashedWheelTimer();
    this.eventLoopGroup =
        com.facebook.thrift.util.NettyUtil.createEventLoopGroup(
            numThreadsForEventLoop, eventLoopGroupThreadPrefix);
    this.loopResources = (preferNative) -> eventLoopGroup;
    this.offLoopScheduler = createOffLoopScheduler();
    this.clientOffLoopScheduler =
        separateOffLoopScheduler ? createClientOffLoopScheduler() : offLoopScheduler;

    // If system properties does not contain leak detection, disable it
    if (!System.getProperties().containsKey("io.netty.leakDetectionLevel")) {
      ResourceLeakDetector.setLevel(ResourceLeakDetector.Level.DISABLED);
    }
  }

  public HashedWheelTimer getTimer() {
    return timer;
  }

  public EventLoopGroup getEventLoopGroup() {
    return eventLoopGroup;
  }

  public LoopResources getLoopResources() {
    return loopResources;
  }

  public Scheduler getOffLoopScheduler() {
    return offLoopScheduler;
  }

  public ExecutorService getOffLoopExecutor() {
    return offLoopScheduler.getExecutor();
  }

  public Scheduler getClientOffLoopScheduler() {
    return clientOffLoopScheduler;
  }

  public ExecutorService getClientOffLoopExecutor() {
    return clientOffLoopScheduler.getExecutor();
  }

  private HashedWheelTimer createHashedWheelTimer() {
    ThreadFactory threadFactory =
        new ThreadFactoryBuilder()
            .setDaemon(true)
            .setUncaughtExceptionHandler(
                (t, e) -> LOGGER.error("uncaught exception on thread {}", t.getName(), e))
            .setNameFormat("thrift-timer-%d")
            .build();

    return new HashedWheelTimer(threadFactory);
  }

  private void shutdownHashedWheelTimer() {
    timer.stop();
  }

  private void shutdownEventLoopGroup() {
    try {
      eventLoopGroup.shutdownGracefully().get();
    } catch (Exception e) {
      LOGGER.error("Error closing event loop", e);
      throw new IllegalStateException("Exception shutting down event loop", e);
    }
  }

  private ThriftScheduler createOffLoopScheduler() {
    LOGGER.info("force execution off event loop enabled:  {}", forceExecutionOffEventLoop);
    if (enableVirtualThreadScheduler) {
      if (!runtimeSupportsVirtualThreads()) {
        throw new IllegalStateException(
            "Virtual threads not supported on runtime version: "
                + System.getProperty("java.version"));
      }
      LOGGER.info("Enabling VirtualThreadScheduler");
      LOGGER.info("Virtual thread concurrency limited: {}", limitVirtualThreadConcurrency);
      LOGGER.info("Virtual thread max concurrency: {}", virtualThreadMaxConcurrency);
      return new VirtualThreadScheduler(limitVirtualThreadConcurrency, virtualThreadMaxConcurrency);
    } else if (enableForkJoinPool) {
      LOGGER.info("creating ForkJoinPoolScheduler scheduler");
      LOGGER.info("off event loop max threads: {}", forkJoinPoolThreads);
      return ForkJoinPoolScheduler.create("thrift-forkjoin-scheduler", forkJoinPoolThreads);
    } else {
      LOGGER.info("creating ThreadPoolScheduler scheduler");
      LOGGER.info("off event loop max threads: {}", numThreadsForOffLoop);
      LOGGER.info("off event loop max pending tasks: {}", maxPendingTasksForOffLoop);
      return new ThreadPoolScheduler(
          minNumThreadsForOffLoop,
          numThreadsForOffLoop,
          maxPendingTasksForOffLoop,
          minPendingTasksBeforeNewThread);
    }
  }

  /**
   * Virtual threads introduced in version 19, runtime must be greater than or equal to 19 to enable
   * features
   *
   * @return if runtime major version supports virtual threads
   */
  private boolean runtimeSupportsVirtualThreads() {
    return PlatformDependent.javaVersion() >= 19;
  }

  private ThriftScheduler createClientOffLoopScheduler() {
    LOGGER.info("force client execution off event loop enabled:  {}", forceExecutionOffEventLoop);
    if (enableVirtualThreadScheduler) {
      if (!runtimeSupportsVirtualThreads()) {
        throw new IllegalStateException(
            "Virtual threads not supported on runtime version: "
                + System.getProperty("java.version"));
      }
      LOGGER.info("Enabling seprate VirtualThreadScheduler for client ");
      LOGGER.info("Client virtual thread concurrency limited: {}", limitVirtualThreadConcurrency);
      LOGGER.info("Client virtual thread max concurrency: {}", virtualThreadMaxConcurrency);
      return new VirtualThreadScheduler(limitVirtualThreadConcurrency, virtualThreadMaxConcurrency);
    } else if (enableForkJoinPool) {
      LOGGER.info("creating separate ForkJoinPoolScheduler scheduler for client");
      LOGGER.info("off event loop max threads: {}", forkJoinPoolClientThreads);
      return ForkJoinPoolScheduler.create(
          "thrift-forkjoin-client-scheduler", forkJoinPoolClientThreads);
    } else {
      LOGGER.info("creating separate ThreadPoolScheduler scheduler for client");
      LOGGER.info("client off event loop max threads: {}", numThreadsForOffLoop);
      LOGGER.info("client off event loop max pending tasks: {}", maxPendingTasksForOffLoop);
      return new ThreadPoolScheduler(
          minNumThreadsForOffLoop,
          numThreadsForOffLoop,
          maxPendingTasksForOffLoop,
          minPendingTasksBeforeNewThread);
    }
  }

  protected void shutdownOffLoopScheduler() {
    try {
      offLoopScheduler.dispose();
    } catch (Exception e) {
      LOGGER.error("Error closing event loop", e);
      throw new IllegalStateException("Exception shutting down event loop", e);
    }
  }

  public int getNumThreadsForEventLoop() {
    return numThreadsForEventLoop;
  }

  public int pendingTasksForEventLoop() {
    int pending = 0;
    for (EventExecutor eventExecutor : eventLoopGroup) {
      SingleThreadEventLoop loop = (SingleThreadEventLoop) eventExecutor;
      pending += loop.pendingTasks();
    }

    return pending;
  }

  public boolean isForceExecutionOffEventLoop() {
    return forceExecutionOffEventLoop;
  }

  public boolean isForceClientExecutionOffEventLoop() {
    return forceClientExecutionOffEventLoop;
  }

  public Map<String, Long> stats() {
    return offLoopScheduler.getStats();
  }

  @Override
  public Mono<Void> onClose() {
    return onClose;
  }

  @Override
  public void dispose() {
    try {
      shutdownHashedWheelTimer();
      shutdownEventLoopGroup();
      shutdownOffLoopScheduler();
    } finally {
      onClose.onComplete();
    }
  }
}
