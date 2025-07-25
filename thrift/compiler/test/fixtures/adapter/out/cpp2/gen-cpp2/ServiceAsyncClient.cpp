/**
 * Autogenerated by Thrift for thrift/compiler/test/fixtures/adapter/src/module.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated @nocommit
 */

#include "thrift/compiler/test/fixtures/adapter/gen-cpp2/ServiceAsyncClient.h"

#include <thrift/lib/cpp2/gen/client_cpp.h>

namespace facebook::thrift::test {
typedef apache::thrift::ThriftPresult<false, apache::thrift::FieldData<1, ::apache::thrift::type_class::string, ::facebook::thrift::test::StringWithAdapter_7208*, ::apache::thrift::type::adapted<::my::Adapter1, ::apache::thrift::type::string_t>>, apache::thrift::FieldData<2, ::apache::thrift::type_class::string, ::facebook::thrift::test::StringWithCppAdapter*, ::apache::thrift::type::adapted<::my::Adapter2, ::apache::thrift::type::string_t>>, apache::thrift::FieldData<3, ::apache::thrift::type_class::structure, ::facebook::thrift::test::Foo*>> Service_func_pargs;
typedef apache::thrift::ThriftPresult<true, apache::thrift::FieldData<0, ::apache::thrift::type_class::integral, ::facebook::thrift::test::MyI32_4873*, ::apache::thrift::type::adapted<::my::Adapter1, ::apache::thrift::type::i32_t>>> Service_func_presult;
} // namespace facebook::thrift::test
template <typename RpcOptions>
void apache::thrift::Client<::facebook::thrift::test::Service>::fbthrift_send_func(apache::thrift::SerializedRequest&& request, RpcOptions&& rpcOptions, std::shared_ptr<apache::thrift::transport::THeader> header, apache::thrift::RequestClientCallback::Ptr callback, std::unique_ptr<folly::IOBuf> interceptorFrameworkMetadata) {

  static ::apache::thrift::MethodMetadata::Data* methodMetadata =
        new ::apache::thrift::MethodMetadata::Data(
                "func",
                ::apache::thrift::FunctionQualifier::Unspecified,
                "facebook.com/thrift/test/Service");
  apache::thrift::clientSendT<apache::thrift::RpcKind::SINGLE_REQUEST_SINGLE_RESPONSE>(std::move(request), std::forward<RpcOptions>(rpcOptions), std::move(callback), std::move(header), channel_.get(), ::apache::thrift::MethodMetadata::from_static(methodMetadata), std::move(interceptorFrameworkMetadata));
}



void apache::thrift::Client<::facebook::thrift::test::Service>::func(std::unique_ptr<apache::thrift::RequestCallback> callback, const ::facebook::thrift::test::StringWithAdapter_7208& p_arg1, const ::facebook::thrift::test::StringWithCppAdapter& p_arg2, const ::facebook::thrift::test::Foo& p_arg3) {
  ::apache::thrift::RpcOptions rpcOptions;
  func(rpcOptions, std::move(callback), p_arg1, p_arg2, p_arg3);
}

void apache::thrift::Client<::facebook::thrift::test::Service>::func(apache::thrift::RpcOptions& rpcOptions, std::unique_ptr<apache::thrift::RequestCallback> callback, const ::facebook::thrift::test::StringWithAdapter_7208& p_arg1, const ::facebook::thrift::test::StringWithCppAdapter& p_arg2, const ::facebook::thrift::test::Foo& p_arg3) {
  auto [ctx, header] = funcCtx(&rpcOptions);
  if (ctx != nullptr) {
    auto argsAsRefs = std::tie(p_arg1, p_arg2, p_arg3);
    ctx->processClientInterceptorsOnRequest(apache::thrift::ClientInterceptorOnRequestArguments(argsAsRefs), header.get(), rpcOptions).throwUnlessValue();
  }
  auto [wrappedCallback, contextStack] = apache::thrift::GeneratedAsyncClient::template prepareRequestClientCallback<false /* kIsOneWay */>(std::move(callback), std::move(ctx));
  fbthrift_serialize_and_send_func(rpcOptions, std::move(header), contextStack, std::move(wrappedCallback), p_arg1, p_arg2, p_arg3);
}

apache::thrift::SerializedRequest apache::thrift::Client<::facebook::thrift::test::Service>::fbthrift_serialize_func(const RpcOptions& rpcOptions, apache::thrift::transport::THeader& header, apache::thrift::ContextStack* contextStack, const ::facebook::thrift::test::StringWithAdapter_7208& p_arg1, const ::facebook::thrift::test::StringWithCppAdapter& p_arg2, const ::facebook::thrift::test::Foo& p_arg3) {
  return apache::thrift::detail::ac::withProtocolWriter(apache::thrift::GeneratedAsyncClient::getChannel()->getProtocolId(), [&](auto&& prot) {
    using ProtocolWriter = std::decay_t<decltype(prot)>;
    ::facebook::thrift::test::Service_func_pargs args;
    args.get<0>().value = const_cast<::facebook::thrift::test::StringWithAdapter_7208*>(&p_arg1);
    args.get<1>().value = const_cast<::facebook::thrift::test::StringWithCppAdapter*>(&p_arg2);
    args.get<2>().value = const_cast<::facebook::thrift::test::Foo*>(&p_arg3);
    const auto sizer = [&](ProtocolWriter* p) { return args.serializedSizeZC(p); };
    const auto writer = [&](ProtocolWriter* p) { args.write(p); };
    return apache::thrift::preprocessSendT<ProtocolWriter>(
        &prot,
        rpcOptions,
        contextStack,
        header,
        "func",
        writer,
        sizer,
        channel_->getChecksumSamplingRate());
  });
}

void apache::thrift::Client<::facebook::thrift::test::Service>::fbthrift_serialize_and_send_func(apache::thrift::RpcOptions& rpcOptions, std::shared_ptr<apache::thrift::transport::THeader> header, apache::thrift::ContextStack* contextStack, apache::thrift::RequestClientCallback::Ptr callback, const ::facebook::thrift::test::StringWithAdapter_7208& p_arg1, const ::facebook::thrift::test::StringWithCppAdapter& p_arg2, const ::facebook::thrift::test::Foo& p_arg3, bool stealRpcOptions) {
  apache::thrift::SerializedRequest request = fbthrift_serialize_func(rpcOptions, *header, contextStack, p_arg1, p_arg2, p_arg3);
  std::unique_ptr<folly::IOBuf> interceptorFrameworkMetadata = nullptr;
  if (contextStack != nullptr) {
    interceptorFrameworkMetadata = detail::ContextStackUnsafeAPI(*contextStack).getInterceptorFrameworkMetadata(rpcOptions);
  }
  if (stealRpcOptions) {
    fbthrift_send_func(std::move(request), std::move(rpcOptions), std::move(header), std::move(callback), std::move(interceptorFrameworkMetadata));
  } else {
    fbthrift_send_func(std::move(request), rpcOptions, std::move(header), std::move(callback), std::move(interceptorFrameworkMetadata));
  }
}

std::pair<::apache::thrift::ContextStack::UniquePtr, std::shared_ptr<::apache::thrift::transport::THeader>> apache::thrift::Client<::facebook::thrift::test::Service>::funcCtx(apache::thrift::RpcOptions* rpcOptions) {
  auto header = std::make_shared<apache::thrift::transport::THeader>(
      apache::thrift::transport::THeader::ALLOW_BIG_FRAMES);
  header->setProtocolId(channel_->getProtocolId());
  if (rpcOptions) {
    header->setHeaders(rpcOptions->releaseWriteHeaders());
  }

  auto ctx = apache::thrift::ContextStack::createWithClientContext(
      handlers_,
      interceptors_,
      getServiceName(),
      "Service.func",
      *header);

  return {std::move(ctx), std::move(header)};
}

::facebook::thrift::test::MyI32_4873 apache::thrift::Client<::facebook::thrift::test::Service>::sync_func(const ::facebook::thrift::test::StringWithAdapter_7208& p_arg1, const ::facebook::thrift::test::StringWithCppAdapter& p_arg2, const ::facebook::thrift::test::Foo& p_arg3) {
  ::apache::thrift::RpcOptions rpcOptions;
  return sync_func(rpcOptions, p_arg1, p_arg2, p_arg3);
}

::facebook::thrift::test::MyI32_4873 apache::thrift::Client<::facebook::thrift::test::Service>::sync_func(apache::thrift::RpcOptions& rpcOptions, const ::facebook::thrift::test::StringWithAdapter_7208& p_arg1, const ::facebook::thrift::test::StringWithCppAdapter& p_arg2, const ::facebook::thrift::test::Foo& p_arg3) {
  apache::thrift::ClientReceiveState returnState;
  apache::thrift::ClientSyncCallback<false> callback(&returnState);
  auto protocolId = apache::thrift::GeneratedAsyncClient::getChannel()->getProtocolId();
  auto evb = apache::thrift::GeneratedAsyncClient::getChannel()->getEventBase();
  auto ctxAndHeader = funcCtx(&rpcOptions);
  auto wrappedCallback = apache::thrift::RequestClientCallback::Ptr(&callback);
  auto* contextStack  = ctxAndHeader.first.get();
  if (contextStack != nullptr) {
    auto argsAsRefs = std::tie(p_arg1, p_arg2, p_arg3);
    contextStack->processClientInterceptorsOnRequest(apache::thrift::ClientInterceptorOnRequestArguments(argsAsRefs), ctxAndHeader.second.get(), rpcOptions).throwUnlessValue();
  }
  callback.waitUntilDone(
    evb,
    [&] {
      fbthrift_serialize_and_send_func(rpcOptions, ctxAndHeader.second, ctxAndHeader.first.get(), std::move(wrappedCallback), p_arg1, p_arg2, p_arg3);
    });
  if (contextStack != nullptr) {
    contextStack->processClientInterceptorsOnResponse(returnState.header()).throwUnlessValue();
  }
  if (returnState.isException()) {
    returnState.exception().throw_exception();
  }
  returnState.resetProtocolId(protocolId);
  returnState.resetCtx(std::move(ctxAndHeader.first));
  SCOPE_EXIT {
    if (returnState.header() && !returnState.header()->getHeaders().empty()) {
      rpcOptions.setReadHeaders(returnState.header()->releaseHeaders());
    }
  };
  return folly::fibers::runInMainContext([&] {
      return recv_func(returnState);
  });
}


template <typename CallbackType>
folly::SemiFuture<::facebook::thrift::test::MyI32_4873> apache::thrift::Client<::facebook::thrift::test::Service>::fbthrift_semifuture_func(apache::thrift::RpcOptions& rpcOptions, const ::facebook::thrift::test::StringWithAdapter_7208& p_arg1, const ::facebook::thrift::test::StringWithCppAdapter& p_arg2, const ::facebook::thrift::test::Foo& p_arg3) {
  using CallbackHelper = apache::thrift::detail::FutureCallbackHelper<::facebook::thrift::test::MyI32_4873>;
  folly::Promise<CallbackHelper::PromiseResult> promise;
  auto semifuture = promise.getSemiFuture();
  auto ctxAndHeader = funcCtx(&rpcOptions);
  auto wrappedCallbackAndContextStack = apache::thrift::GeneratedAsyncClient::template prepareRequestClientCallback<false /* kIsOneWay */>(
    std::make_unique<CallbackType>(std::move(promise), recv_wrapped_func, channel_),
    std::move(ctxAndHeader.first));
  auto header = std::move(ctxAndHeader.second);
  auto* contextStack = wrappedCallbackAndContextStack.second;
  auto wrappedCallback = std::move(wrappedCallbackAndContextStack.first);
  std::unique_ptr<folly::IOBuf> interceptorFrameworkMetadata = nullptr;
  if (contextStack != nullptr) {
    auto argsAsRefs = std::tie(p_arg1, p_arg2, p_arg3);
    if (auto exTry = contextStack->processClientInterceptorsOnRequest(apache::thrift::ClientInterceptorOnRequestArguments(argsAsRefs), header.get(), rpcOptions);
        exTry.hasException()) {
      return folly::makeSemiFuture<::facebook::thrift::test::MyI32_4873>(std::move(exTry).exception());
    }
    interceptorFrameworkMetadata = detail::ContextStackUnsafeAPI(*contextStack).getInterceptorFrameworkMetadata(rpcOptions);
  }
  apache::thrift::SerializedRequest request = fbthrift_serialize_func(rpcOptions, *header, contextStack, p_arg1, p_arg2, p_arg3);
  fbthrift_send_func(std::move(request), rpcOptions, std::move(header), std::move(wrappedCallback), std::move(interceptorFrameworkMetadata));
  return std::move(semifuture).deferValue(CallbackHelper::processClientInterceptorsAndExtractResult);
}

folly::Future<::facebook::thrift::test::MyI32_4873> apache::thrift::Client<::facebook::thrift::test::Service>::future_func(const ::facebook::thrift::test::StringWithAdapter_7208& p_arg1, const ::facebook::thrift::test::StringWithCppAdapter& p_arg2, const ::facebook::thrift::test::Foo& p_arg3) {
  ::apache::thrift::RpcOptions rpcOptions;
  return future_func(rpcOptions, p_arg1, p_arg2, p_arg3);
}

folly::SemiFuture<::facebook::thrift::test::MyI32_4873> apache::thrift::Client<::facebook::thrift::test::Service>::semifuture_func(const ::facebook::thrift::test::StringWithAdapter_7208& p_arg1, const ::facebook::thrift::test::StringWithCppAdapter& p_arg2, const ::facebook::thrift::test::Foo& p_arg3) {
  ::apache::thrift::RpcOptions rpcOptions;
  return semifuture_func(rpcOptions, p_arg1, p_arg2, p_arg3);
}

folly::Future<::facebook::thrift::test::MyI32_4873> apache::thrift::Client<::facebook::thrift::test::Service>::future_func(apache::thrift::RpcOptions& rpcOptions, const ::facebook::thrift::test::StringWithAdapter_7208& p_arg1, const ::facebook::thrift::test::StringWithCppAdapter& p_arg2, const ::facebook::thrift::test::Foo& p_arg3) {
  using CallbackType = apache::thrift::FutureCallback<::facebook::thrift::test::MyI32_4873>;
  return fbthrift_semifuture_func<CallbackType>(rpcOptions, p_arg1, p_arg2, p_arg3).toUnsafeFuture();
}

folly::SemiFuture<::facebook::thrift::test::MyI32_4873> apache::thrift::Client<::facebook::thrift::test::Service>::semifuture_func(apache::thrift::RpcOptions& rpcOptions, const ::facebook::thrift::test::StringWithAdapter_7208& p_arg1, const ::facebook::thrift::test::StringWithCppAdapter& p_arg2, const ::facebook::thrift::test::Foo& p_arg3) {
  using CallbackType = apache::thrift::SemiFutureCallback<::facebook::thrift::test::MyI32_4873>;
  return fbthrift_semifuture_func<CallbackType>(rpcOptions, p_arg1, p_arg2, p_arg3);
}


void apache::thrift::Client<::facebook::thrift::test::Service>::func(folly::Function<void (::apache::thrift::ClientReceiveState&&)> callback, const ::facebook::thrift::test::StringWithAdapter_7208& p_arg1, const ::facebook::thrift::test::StringWithCppAdapter& p_arg2, const ::facebook::thrift::test::Foo& p_arg3) {
  func(std::make_unique<apache::thrift::FunctionReplyCallback>(std::move(callback)), p_arg1, p_arg2, p_arg3);
}

#if FOLLY_HAS_COROUTINES
#endif // FOLLY_HAS_COROUTINES
folly::exception_wrapper apache::thrift::Client<::facebook::thrift::test::Service>::recv_wrapped_func(::facebook::thrift::test::MyI32_4873& _return, ::apache::thrift::ClientReceiveState& state) {
  if (state.isException()) {
    return std::move(state.exception());
  }
  if (!state.hasResponseBuffer()) {
    return folly::make_exception_wrapper<apache::thrift::TApplicationException>("recv_ called without result");
  }

  using result = ::facebook::thrift::test::Service_func_presult;
  switch (state.protocolId()) {
    case apache::thrift::protocol::T_BINARY_PROTOCOL:
    {
      apache::thrift::BinaryProtocolReader reader;
      return apache::thrift::detail::ac::recv_wrapped<result>(
          &reader, state, _return);
    }
    case apache::thrift::protocol::T_COMPACT_PROTOCOL:
    {
      apache::thrift::CompactProtocolReader reader;
      return apache::thrift::detail::ac::recv_wrapped<result>(
          &reader, state, _return);
    }
    default:
    {
    }
  }
  return folly::make_exception_wrapper<apache::thrift::TApplicationException>("Could not find Protocol");
}

::facebook::thrift::test::MyI32_4873 apache::thrift::Client<::facebook::thrift::test::Service>::recv_func(::apache::thrift::ClientReceiveState& state) {
  ::facebook::thrift::test::MyI32_4873 _return;
  auto ew = recv_wrapped_func(_return, state);
  if (ew) {
    ew.throw_exception();
  }
  return _return;
}

::facebook::thrift::test::MyI32_4873 apache::thrift::Client<::facebook::thrift::test::Service>::recv_instance_func(::apache::thrift::ClientReceiveState& state) {
  return recv_func(state);
}

folly::exception_wrapper apache::thrift::Client<::facebook::thrift::test::Service>::recv_instance_wrapped_func(::facebook::thrift::test::MyI32_4873& _return, ::apache::thrift::ClientReceiveState& state) {
  return recv_wrapped_func(_return, state);
}


