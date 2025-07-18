/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */

package test.fixtures.service_schema;

import com.facebook.thrift.client.*;
import java.util.*;

public class ExtendedServiceBlockingReactiveWrapper  extends com.facebook.thrift.test.BaseServiceBlockingReactiveWrapper
    implements ExtendedService.Reactive {
    private final ExtendedService _delegate;

    public ExtendedServiceBlockingReactiveWrapper(ExtendedService _delegate) {
        super(_delegate);
        this._delegate = _delegate;
    }

    @java.lang.Override
    public void dispose() {
        _delegate.close();
    }

    @java.lang.Override
    public reactor.core.publisher.Mono<Long> init(final long param0, final long param1) {
        reactor.core.publisher.Mono<Long> _m = reactor.core.publisher.Mono.create(_sink -> {
            try {
                reactor.util.context.ContextView _contextView = _sink.contextView();
                com.facebook.nifty.core.RequestContext
                    .tryContextView(_contextView)
                    .ifPresent(com.facebook.nifty.core.RequestContexts::setCurrentContext);
                _sink.success(_delegate.init(param0, param1));
            } catch (Throwable _e) {
                _sink.error(_e);
            }
        });

        if (!com.facebook.thrift.util.resources.RpcResources.isForceExecutionOffEventLoop()) {
            _m = _m.subscribeOn(com.facebook.thrift.util.resources.RpcResources.getOffLoopScheduler());
        }

        return _m;
    }

}
