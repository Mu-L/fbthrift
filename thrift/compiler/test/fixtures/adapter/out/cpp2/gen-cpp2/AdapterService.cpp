/**
 * Autogenerated by Thrift for thrift/compiler/test/fixtures/adapter/src/module.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated @nocommit
 */

#include "thrift/compiler/test/fixtures/adapter/gen-cpp2/AdapterService.h"
#include "thrift/compiler/test/fixtures/adapter/gen-cpp2/AdapterService.tcc"
#include "thrift/compiler/test/fixtures/adapter/gen-cpp2/module_metadata.h"
#include <thrift/lib/cpp2/gen/service_cpp.h>

std::unique_ptr<apache::thrift::AsyncProcessor> apache::thrift::ServiceHandler<::facebook::thrift::test::AdapterService>::getProcessor() {
  return std::make_unique<::facebook::thrift::test::AdapterServiceAsyncProcessor>(this);
}

apache::thrift::ServiceHandler<::facebook::thrift::test::AdapterService>::CreateMethodMetadataResult apache::thrift::ServiceHandler<::facebook::thrift::test::AdapterService>::createMethodMetadata() {
  return ::apache::thrift::detail::ap::createMethodMetadataMap<::facebook::thrift::test::AdapterServiceAsyncProcessor>(getServiceRequestInfoMap().value().get());
}


std::optional<std::reference_wrapper<apache::thrift::ServiceRequestInfoMap const>> apache::thrift::ServiceHandler<::facebook::thrift::test::AdapterService>::getServiceRequestInfoMap() const {
  return __fbthrift_serviceInfoHolder.requestInfoMap();
}

::facebook::thrift::test::AdapterServiceServiceInfoHolder apache::thrift::ServiceHandler<::facebook::thrift::test::AdapterService>::__fbthrift_serviceInfoHolder;


void apache::thrift::ServiceHandler<::facebook::thrift::test::AdapterService>::count(::facebook::thrift::test::CountingStruct& /*_return*/) {
  apache::thrift::detail::si::throw_app_exn_unimplemented("count");
}

void apache::thrift::ServiceHandler<::facebook::thrift::test::AdapterService>::sync_count(::facebook::thrift::test::CountingStruct& _return) {
  return count(_return);
}

folly::SemiFuture<std::unique_ptr<::facebook::thrift::test::CountingStruct>> apache::thrift::ServiceHandler<::facebook::thrift::test::AdapterService>::semifuture_count() {
  auto expected{apache::thrift::detail::si::InvocationType::SemiFuture};
  __fbthrift_invocation_count.compare_exchange_strong(expected, apache::thrift::detail::si::InvocationType::Sync, std::memory_order_relaxed);
  auto ret = std::make_unique<::facebook::thrift::test::CountingStruct>();
  sync_count(*ret);
  return folly::makeSemiFuture(std::move(ret));
}

folly::Future<std::unique_ptr<::facebook::thrift::test::CountingStruct>> apache::thrift::ServiceHandler<::facebook::thrift::test::AdapterService>::future_count() {
  auto expected{apache::thrift::detail::si::InvocationType::Future};
  __fbthrift_invocation_count.compare_exchange_strong(expected, apache::thrift::detail::si::InvocationType::SemiFuture, std::memory_order_relaxed);
  return apache::thrift::detail::si::future(semifuture_count(), getInternalKeepAlive());
}

#if FOLLY_HAS_COROUTINES
folly::coro::Task<std::unique_ptr<::facebook::thrift::test::CountingStruct>> apache::thrift::ServiceHandler<::facebook::thrift::test::AdapterService>::co_count() {
  auto expected{apache::thrift::detail::si::InvocationType::Coro};
  __fbthrift_invocation_count.compare_exchange_strong(expected, apache::thrift::detail::si::InvocationType::Future, std::memory_order_relaxed);
  folly::throw_exception(apache::thrift::detail::si::UnimplementedCoroMethod::withCapturedArgs<>());
}

folly::coro::Task<std::unique_ptr<::facebook::thrift::test::CountingStruct>> apache::thrift::ServiceHandler<::facebook::thrift::test::AdapterService>::co_count(apache::thrift::RequestParams /* params */) {
  auto expected{apache::thrift::detail::si::InvocationType::CoroParam};
  __fbthrift_invocation_count.compare_exchange_strong(expected, apache::thrift::detail::si::InvocationType::Coro, std::memory_order_relaxed);
  return co_count();
}
#endif // FOLLY_HAS_COROUTINES

void apache::thrift::ServiceHandler<::facebook::thrift::test::AdapterService>::async_tm_count(apache::thrift::HandlerCallbackPtr<std::unique_ptr<::facebook::thrift::test::CountingStruct>> callback) {
  // It's possible the coroutine versions will delegate to a future-based
  // version. If that happens, we need the RequestParams arguments to be
  // available to the future through the thread-local backchannel, so we create
  // a RAII object that sets up RequestParams and clears them on destruction.
  apache::thrift::detail::si::AsyncTmPrep asyncTmPrep(this, callback.get());
#if FOLLY_HAS_COROUTINES
determineInvocationType:
#endif // FOLLY_HAS_COROUTINES
  auto invocationType = __fbthrift_invocation_count.load(std::memory_order_relaxed);
  try {
    switch (invocationType) {
      case apache::thrift::detail::si::InvocationType::AsyncTm:
      {
#if FOLLY_HAS_COROUTINES
        __fbthrift_invocation_count.compare_exchange_strong(invocationType, apache::thrift::detail::si::InvocationType::CoroParam, std::memory_order_relaxed);
        apache::thrift::RequestParams params{callback->getRequestContext(),
          callback->getThreadManager_deprecated(), callback->getEventBase(), callback->getHandlerExecutor()};
        auto task = co_count(params);
        apache::thrift::detail::si::async_tm_coro(std::move(callback), std::move(task));
        return;
#else // FOLLY_HAS_COROUTINES
        __fbthrift_invocation_count.compare_exchange_strong(invocationType, apache::thrift::detail::si::InvocationType::Future, std::memory_order_relaxed);
        [[fallthrough]];
#endif // FOLLY_HAS_COROUTINES
      }
      case apache::thrift::detail::si::InvocationType::Future:
      {
        auto fut = future_count();
        apache::thrift::detail::si::async_tm_future(std::move(callback), std::move(fut));
        return;
      }
      case apache::thrift::detail::si::InvocationType::SemiFuture:
      {
        auto fut = semifuture_count();
        apache::thrift::detail::si::async_tm_semifuture(std::move(callback), std::move(fut));
        return;
      }
#if FOLLY_HAS_COROUTINES
      case apache::thrift::detail::si::InvocationType::CoroParam:
      {
        apache::thrift::RequestParams params{callback->getRequestContext(),
          callback->getThreadManager_deprecated(), callback->getEventBase(), callback->getHandlerExecutor()};
        auto task = co_count(params);
        apache::thrift::detail::si::async_tm_coro(std::move(callback), std::move(task));
        return;
      }
      case apache::thrift::detail::si::InvocationType::Coro:
      {
        auto task = co_count();
        apache::thrift::detail::si::async_tm_coro(std::move(callback), std::move(task));
        return;
      }
#endif // FOLLY_HAS_COROUTINES
      case apache::thrift::detail::si::InvocationType::Sync:
      {
        ::facebook::thrift::test::CountingStruct _return;
        sync_count(_return);
        callback->result(std::move(_return));
        return;
      }
      default:
      {
        folly::assume_unreachable();
      }
    }
#if FOLLY_HAS_COROUTINES
  } catch (apache::thrift::detail::si::UnimplementedCoroMethod& ex) {
    std::tie() = std::move(ex).restoreArgs<>();
    goto determineInvocationType;
#endif // FOLLY_HAS_COROUTINES
  } catch (...) {
    callback->exception(std::current_exception());
  }
}

void apache::thrift::ServiceHandler<::facebook::thrift::test::AdapterService>::adaptedTypes(::facebook::thrift::test::HeapAllocated& /*_return*/, std::unique_ptr<::facebook::thrift::test::HeapAllocated> /*arg*/) {
  apache::thrift::detail::si::throw_app_exn_unimplemented("adaptedTypes");
}

void apache::thrift::ServiceHandler<::facebook::thrift::test::AdapterService>::sync_adaptedTypes(::facebook::thrift::test::HeapAllocated& _return, std::unique_ptr<::facebook::thrift::test::HeapAllocated> p_arg) {
  return adaptedTypes(_return, std::move(p_arg));
}

folly::SemiFuture<std::unique_ptr<::facebook::thrift::test::HeapAllocated>> apache::thrift::ServiceHandler<::facebook::thrift::test::AdapterService>::semifuture_adaptedTypes(std::unique_ptr<::facebook::thrift::test::HeapAllocated> p_arg) {
  auto expected{apache::thrift::detail::si::InvocationType::SemiFuture};
  __fbthrift_invocation_adaptedTypes.compare_exchange_strong(expected, apache::thrift::detail::si::InvocationType::Sync, std::memory_order_relaxed);
  auto ret = std::make_unique<::facebook::thrift::test::HeapAllocated>();
  sync_adaptedTypes(*ret, std::move(p_arg));
  return folly::makeSemiFuture(std::move(ret));
}

folly::Future<std::unique_ptr<::facebook::thrift::test::HeapAllocated>> apache::thrift::ServiceHandler<::facebook::thrift::test::AdapterService>::future_adaptedTypes(std::unique_ptr<::facebook::thrift::test::HeapAllocated> p_arg) {
  auto expected{apache::thrift::detail::si::InvocationType::Future};
  __fbthrift_invocation_adaptedTypes.compare_exchange_strong(expected, apache::thrift::detail::si::InvocationType::SemiFuture, std::memory_order_relaxed);
  return apache::thrift::detail::si::future(semifuture_adaptedTypes(std::move(p_arg)), getInternalKeepAlive());
}

#if FOLLY_HAS_COROUTINES
folly::coro::Task<std::unique_ptr<::facebook::thrift::test::HeapAllocated>> apache::thrift::ServiceHandler<::facebook::thrift::test::AdapterService>::co_adaptedTypes(std::unique_ptr<::facebook::thrift::test::HeapAllocated> p_arg) {
  auto expected{apache::thrift::detail::si::InvocationType::Coro};
  __fbthrift_invocation_adaptedTypes.compare_exchange_strong(expected, apache::thrift::detail::si::InvocationType::Future, std::memory_order_relaxed);
  folly::throw_exception(apache::thrift::detail::si::UnimplementedCoroMethod::withCapturedArgs<std::unique_ptr<::facebook::thrift::test::HeapAllocated> /*arg*/>(std::move(p_arg)));
}

folly::coro::Task<std::unique_ptr<::facebook::thrift::test::HeapAllocated>> apache::thrift::ServiceHandler<::facebook::thrift::test::AdapterService>::co_adaptedTypes(apache::thrift::RequestParams /* params */, std::unique_ptr<::facebook::thrift::test::HeapAllocated> p_arg) {
  auto expected{apache::thrift::detail::si::InvocationType::CoroParam};
  __fbthrift_invocation_adaptedTypes.compare_exchange_strong(expected, apache::thrift::detail::si::InvocationType::Coro, std::memory_order_relaxed);
  return co_adaptedTypes(std::move(p_arg));
}
#endif // FOLLY_HAS_COROUTINES

void apache::thrift::ServiceHandler<::facebook::thrift::test::AdapterService>::async_tm_adaptedTypes(apache::thrift::HandlerCallbackPtr<std::unique_ptr<::facebook::thrift::test::HeapAllocated>> callback, std::unique_ptr<::facebook::thrift::test::HeapAllocated> p_arg) {
  // It's possible the coroutine versions will delegate to a future-based
  // version. If that happens, we need the RequestParams arguments to be
  // available to the future through the thread-local backchannel, so we create
  // a RAII object that sets up RequestParams and clears them on destruction.
  apache::thrift::detail::si::AsyncTmPrep asyncTmPrep(this, callback.get());
#if FOLLY_HAS_COROUTINES
determineInvocationType:
#endif // FOLLY_HAS_COROUTINES
  auto invocationType = __fbthrift_invocation_adaptedTypes.load(std::memory_order_relaxed);
  try {
    switch (invocationType) {
      case apache::thrift::detail::si::InvocationType::AsyncTm:
      {
#if FOLLY_HAS_COROUTINES
        __fbthrift_invocation_adaptedTypes.compare_exchange_strong(invocationType, apache::thrift::detail::si::InvocationType::CoroParam, std::memory_order_relaxed);
        apache::thrift::RequestParams params{callback->getRequestContext(),
          callback->getThreadManager_deprecated(), callback->getEventBase(), callback->getHandlerExecutor()};
        auto task = co_adaptedTypes(params, std::move(p_arg));
        apache::thrift::detail::si::async_tm_coro(std::move(callback), std::move(task));
        return;
#else // FOLLY_HAS_COROUTINES
        __fbthrift_invocation_adaptedTypes.compare_exchange_strong(invocationType, apache::thrift::detail::si::InvocationType::Future, std::memory_order_relaxed);
        [[fallthrough]];
#endif // FOLLY_HAS_COROUTINES
      }
      case apache::thrift::detail::si::InvocationType::Future:
      {
        auto fut = future_adaptedTypes(std::move(p_arg));
        apache::thrift::detail::si::async_tm_future(std::move(callback), std::move(fut));
        return;
      }
      case apache::thrift::detail::si::InvocationType::SemiFuture:
      {
        auto fut = semifuture_adaptedTypes(std::move(p_arg));
        apache::thrift::detail::si::async_tm_semifuture(std::move(callback), std::move(fut));
        return;
      }
#if FOLLY_HAS_COROUTINES
      case apache::thrift::detail::si::InvocationType::CoroParam:
      {
        apache::thrift::RequestParams params{callback->getRequestContext(),
          callback->getThreadManager_deprecated(), callback->getEventBase(), callback->getHandlerExecutor()};
        auto task = co_adaptedTypes(params, std::move(p_arg));
        apache::thrift::detail::si::async_tm_coro(std::move(callback), std::move(task));
        return;
      }
      case apache::thrift::detail::si::InvocationType::Coro:
      {
        auto task = co_adaptedTypes(std::move(p_arg));
        apache::thrift::detail::si::async_tm_coro(std::move(callback), std::move(task));
        return;
      }
#endif // FOLLY_HAS_COROUTINES
      case apache::thrift::detail::si::InvocationType::Sync:
      {
        ::facebook::thrift::test::HeapAllocated _return;
        sync_adaptedTypes(_return, std::move(p_arg));
        callback->result(std::move(_return));
        return;
      }
      default:
      {
        folly::assume_unreachable();
      }
    }
#if FOLLY_HAS_COROUTINES
  } catch (apache::thrift::detail::si::UnimplementedCoroMethod& ex) {
    std::tie(p_arg) = std::move(ex).restoreArgs<std::unique_ptr<::facebook::thrift::test::HeapAllocated> /*arg*/>();
    goto determineInvocationType;
#endif // FOLLY_HAS_COROUTINES
  } catch (...) {
    callback->exception(std::current_exception());
  }
}


namespace facebook::thrift::test {

void AdapterServiceSvNull::count(::facebook::thrift::test::CountingStruct& /*_return*/) {  }

void AdapterServiceSvNull::adaptedTypes(::facebook::thrift::test::HeapAllocated& /*_return*/, std::unique_ptr<::facebook::thrift::test::HeapAllocated> /*arg*/) {  }


std::string_view AdapterServiceAsyncProcessor::getServiceName() {
  return "AdapterService";
}

void AdapterServiceAsyncProcessor::getServiceMetadata(apache::thrift::metadata::ThriftServiceMetadataResponse& response) {
  ::apache::thrift::detail::md::ServiceMetadata<::apache::thrift::ServiceHandler<::facebook::thrift::test::AdapterService>>::gen(response);
}

void AdapterServiceAsyncProcessor::processSerializedCompressedRequestWithMetadata(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedCompressedRequest&& serializedRequest, const apache::thrift::AsyncProcessorFactory::MethodMetadata& methodMetadata, apache::thrift::protocol::PROTOCOL_TYPES protType, apache::thrift::Cpp2RequestContext* context, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm) {
  apache::thrift::detail::ap::process(this, iface_, std::move(req), std::move(serializedRequest), methodMetadata, protType, context, eb, tm);
}

void AdapterServiceAsyncProcessor::executeRequest(apache::thrift::ServerRequest&& request, const apache::thrift::AsyncProcessorFactory::MethodMetadata& methodMetadata) {
  apache::thrift::detail::ap::execute(this, std::move(request), apache::thrift::detail::ServerRequestHelper::protocol(request), methodMetadata);
}

const AdapterServiceAsyncProcessor::ProcessMap& AdapterServiceAsyncProcessor::getOwnProcessMap() {
  return kOwnProcessMap_;
}

const AdapterServiceAsyncProcessor::ProcessMap AdapterServiceAsyncProcessor::kOwnProcessMap_ {
  {"count",
    {&AdapterServiceAsyncProcessor::setUpAndProcess_count<apache::thrift::CompactProtocolReader, apache::thrift::CompactProtocolWriter>,
     &AdapterServiceAsyncProcessor::setUpAndProcess_count<apache::thrift::BinaryProtocolReader, apache::thrift::BinaryProtocolWriter>,
     &AdapterServiceAsyncProcessor::executeRequest_count<apache::thrift::CompactProtocolReader, apache::thrift::CompactProtocolWriter>,
     &AdapterServiceAsyncProcessor::executeRequest_count<apache::thrift::BinaryProtocolReader, apache::thrift::BinaryProtocolWriter>}},
  {"adaptedTypes",
    {&AdapterServiceAsyncProcessor::setUpAndProcess_adaptedTypes<apache::thrift::CompactProtocolReader, apache::thrift::CompactProtocolWriter>,
     &AdapterServiceAsyncProcessor::setUpAndProcess_adaptedTypes<apache::thrift::BinaryProtocolReader, apache::thrift::BinaryProtocolWriter>,
     &AdapterServiceAsyncProcessor::executeRequest_adaptedTypes<apache::thrift::CompactProtocolReader, apache::thrift::CompactProtocolWriter>,
     &AdapterServiceAsyncProcessor::executeRequest_adaptedTypes<apache::thrift::BinaryProtocolReader, apache::thrift::BinaryProtocolWriter>}},
};

apache::thrift::ServiceRequestInfoMap const& AdapterServiceServiceInfoHolder::requestInfoMap() const {
  static folly::Indestructible<apache::thrift::ServiceRequestInfoMap> requestInfoMap{staticRequestInfoMap()};
  return *requestInfoMap;
}

apache::thrift::ServiceRequestInfoMap AdapterServiceServiceInfoHolder::staticRequestInfoMap() {
  apache::thrift::ServiceRequestInfoMap requestInfoMap = {
  {"count",
    { false,
     apache::thrift::RpcKind::SINGLE_REQUEST_SINGLE_RESPONSE,
     "AdapterService.count",
     std::nullopt,
     apache::thrift::concurrency::NORMAL,
     std::nullopt}},
  {"adaptedTypes",
    { false,
     apache::thrift::RpcKind::SINGLE_REQUEST_SINGLE_RESPONSE,
     "AdapterService.adaptedTypes",
     std::nullopt,
     apache::thrift::concurrency::NORMAL,
     std::nullopt}},
  };

  return requestInfoMap;
}
} // namespace facebook::thrift::test

namespace apache::thrift::detail {
::folly::Range<const ::std::string_view*>(*TSchemaAssociation<::facebook::thrift::test::AdapterService, false>::bundle)() =
    nullptr;
}
