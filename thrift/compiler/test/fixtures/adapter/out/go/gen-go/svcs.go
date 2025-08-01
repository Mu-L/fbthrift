// Autogenerated by Thrift for thrift/compiler/test/fixtures/adapter/src/module.thrift
//
// DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
//  @generated

package module

import (
    "context"
    "errors"
    "fmt"
    "io"
    "reflect"

    thrift "github.com/facebook/fbthrift/thrift/lib/go/thrift/types"
    metadata "github.com/facebook/fbthrift/thrift/lib/thrift/metadata"
)

// (needed to ensure safety because of naive import list construction)
var _ = context.Background
var _ = errors.New
var _ = fmt.Printf
var _ = io.EOF
var _ = reflect.Ptr
var _ = thrift.VOID
var _ = metadata.GoUnusedProtection__


type Service interface {
    Func(ctx context.Context, arg1 StringWithAdapter_7208, arg2 StringWithCppAdapter, arg3 *Foo) (MyI32_4873, error)
}

type ServiceClientInterface interface {
    io.Closer
    Func(ctx context.Context, arg1 StringWithAdapter_7208, arg2 StringWithCppAdapter, arg3 *Foo) (MyI32_4873, error)
}

type ServiceClient struct {
    ch thrift.RequestChannel
}
// Compile time interface enforcer
var _ ServiceClientInterface = (*ServiceClient)(nil)

func NewServiceChannelClient(channel thrift.RequestChannel) *ServiceClient {
    return &ServiceClient{
        ch: channel,
    }
}

func (c *ServiceClient) Close() error {
    return c.ch.Close()
}

func (c *ServiceClient) Func(ctx context.Context, arg1 StringWithAdapter_7208, arg2 StringWithCppAdapter, arg3 *Foo) (MyI32_4873, error) {
    fbthriftReq := &reqServiceFunc{
        Arg1: arg1,
        Arg2: arg2,
        Arg3: arg3,
    }
    fbthriftResp := newRespServiceFunc()
    fbthriftErr := c.ch.SendRequestResponse(ctx, "func", fbthriftReq, fbthriftResp)
    if fbthriftErr != nil {
        return 0, fbthriftErr
    } else if fbthriftEx := fbthriftResp.Exception(); fbthriftEx != nil {
        return 0, fbthriftEx
    }
    return fbthriftResp.GetSuccess(), nil
}


type ServiceProcessor struct {
    processorFunctionMap map[string]thrift.ProcessorFunction
    functionServiceMap   map[string]string
    handler              Service
}

func NewServiceProcessor(handler Service) *ServiceProcessor {
    p := &ServiceProcessor{
        handler:              handler,
        processorFunctionMap: make(map[string]thrift.ProcessorFunction),
        functionServiceMap:   make(map[string]string),
    }
    p.AddToProcessorFunctionMap("func", &procFuncServiceFunc{handler: handler})
    p.AddToFunctionServiceMap("func", "Service")

    return p
}

func (p *ServiceProcessor) AddToProcessorFunctionMap(key string, processorFunction thrift.ProcessorFunction) {
    p.processorFunctionMap[key] = processorFunction
}

func (p *ServiceProcessor) AddToFunctionServiceMap(key, service string) {
    p.functionServiceMap[key] = service
}

func (p *ServiceProcessor) GetProcessorFunction(key string) (processor thrift.ProcessorFunction) {
    return p.processorFunctionMap[key]
}

func (p *ServiceProcessor) ProcessorFunctionMap() map[string]thrift.ProcessorFunction {
    return p.processorFunctionMap
}

func (p *ServiceProcessor) FunctionServiceMap() map[string]string {
    return p.functionServiceMap
}

func (p *ServiceProcessor) PackageName() string {
    return "module"
}

func (p *ServiceProcessor) GetThriftMetadata() *metadata.ThriftMetadata {
    return GetThriftMetadataForService("module.Service")
}


type procFuncServiceFunc struct {
    handler Service
}
// Compile time interface enforcer
var _ thrift.ProcessorFunction = (*procFuncServiceFunc)(nil)

func (p *procFuncServiceFunc) Read(decoder thrift.Decoder) (thrift.Struct, error) {
    args := newReqServiceFunc()
    if err := args.Read(decoder); err != nil {
        return nil, err
    }
    decoder.ReadMessageEnd()
    return args, nil
}

func (p *procFuncServiceFunc) Write(seqId int32, result thrift.WritableStruct, encoder thrift.Encoder) (err error) {
    var err2 error
    messageType := thrift.REPLY
    switch result.(type) {
    case thrift.ApplicationExceptionIf:
        messageType = thrift.EXCEPTION
    }

    if err2 = encoder.WriteMessageBegin("func", messageType, seqId); err2 != nil {
        err = err2
    }
    if err2 = result.Write(encoder); err == nil && err2 != nil {
        err = err2
    }
    if err2 = encoder.WriteMessageEnd(); err == nil && err2 != nil {
        err = err2
    }
    if err2 = encoder.Flush(); err == nil && err2 != nil {
        err = err2
    }
    return err
}

func (p *procFuncServiceFunc) RunContext(ctx context.Context, reqStruct thrift.Struct) (thrift.WritableStruct, thrift.ApplicationExceptionIf) {
    args := reqStruct.(*reqServiceFunc)
    result := newRespServiceFunc()
    retval, err := p.handler.Func(ctx, args.Arg1, args.Arg2, args.Arg3)
    if err != nil {
        x := thrift.NewApplicationExceptionCause(thrift.INTERNAL_ERROR, "Internal error processing Func: " + err.Error(), err)
        return x, x
    }

    result.Success = &retval
    return result, nil
}


type AdapterService interface {
    Count(ctx context.Context) (*CountingStruct, error)
    AdaptedTypes(ctx context.Context, arg *HeapAllocated) (*HeapAllocated, error)
}

type AdapterServiceClientInterface interface {
    io.Closer
    Count(ctx context.Context) (*CountingStruct, error)
    AdaptedTypes(ctx context.Context, arg *HeapAllocated) (*HeapAllocated, error)
}

type AdapterServiceClient struct {
    ch thrift.RequestChannel
}
// Compile time interface enforcer
var _ AdapterServiceClientInterface = (*AdapterServiceClient)(nil)

func NewAdapterServiceChannelClient(channel thrift.RequestChannel) *AdapterServiceClient {
    return &AdapterServiceClient{
        ch: channel,
    }
}

func (c *AdapterServiceClient) Close() error {
    return c.ch.Close()
}

func (c *AdapterServiceClient) Count(ctx context.Context) (*CountingStruct, error) {
    fbthriftReq := &reqAdapterServiceCount{
    }
    fbthriftResp := newRespAdapterServiceCount()
    fbthriftErr := c.ch.SendRequestResponse(ctx, "count", fbthriftReq, fbthriftResp)
    if fbthriftErr != nil {
        return nil, fbthriftErr
    } else if fbthriftEx := fbthriftResp.Exception(); fbthriftEx != nil {
        return nil, fbthriftEx
    }
    return fbthriftResp.GetSuccess(), nil
}

func (c *AdapterServiceClient) AdaptedTypes(ctx context.Context, arg *HeapAllocated) (*HeapAllocated, error) {
    fbthriftReq := &reqAdapterServiceAdaptedTypes{
        Arg: arg,
    }
    fbthriftResp := newRespAdapterServiceAdaptedTypes()
    fbthriftErr := c.ch.SendRequestResponse(ctx, "adaptedTypes", fbthriftReq, fbthriftResp)
    if fbthriftErr != nil {
        return nil, fbthriftErr
    } else if fbthriftEx := fbthriftResp.Exception(); fbthriftEx != nil {
        return nil, fbthriftEx
    }
    return fbthriftResp.GetSuccess(), nil
}


type AdapterServiceProcessor struct {
    processorFunctionMap map[string]thrift.ProcessorFunction
    functionServiceMap   map[string]string
    handler              AdapterService
}

func NewAdapterServiceProcessor(handler AdapterService) *AdapterServiceProcessor {
    p := &AdapterServiceProcessor{
        handler:              handler,
        processorFunctionMap: make(map[string]thrift.ProcessorFunction),
        functionServiceMap:   make(map[string]string),
    }
    p.AddToProcessorFunctionMap("count", &procFuncAdapterServiceCount{handler: handler})
    p.AddToProcessorFunctionMap("adaptedTypes", &procFuncAdapterServiceAdaptedTypes{handler: handler})
    p.AddToFunctionServiceMap("count", "AdapterService")
    p.AddToFunctionServiceMap("adaptedTypes", "AdapterService")

    return p
}

func (p *AdapterServiceProcessor) AddToProcessorFunctionMap(key string, processorFunction thrift.ProcessorFunction) {
    p.processorFunctionMap[key] = processorFunction
}

func (p *AdapterServiceProcessor) AddToFunctionServiceMap(key, service string) {
    p.functionServiceMap[key] = service
}

func (p *AdapterServiceProcessor) GetProcessorFunction(key string) (processor thrift.ProcessorFunction) {
    return p.processorFunctionMap[key]
}

func (p *AdapterServiceProcessor) ProcessorFunctionMap() map[string]thrift.ProcessorFunction {
    return p.processorFunctionMap
}

func (p *AdapterServiceProcessor) FunctionServiceMap() map[string]string {
    return p.functionServiceMap
}

func (p *AdapterServiceProcessor) PackageName() string {
    return "module"
}

func (p *AdapterServiceProcessor) GetThriftMetadata() *metadata.ThriftMetadata {
    return GetThriftMetadataForService("module.AdapterService")
}


type procFuncAdapterServiceCount struct {
    handler AdapterService
}
// Compile time interface enforcer
var _ thrift.ProcessorFunction = (*procFuncAdapterServiceCount)(nil)

func (p *procFuncAdapterServiceCount) Read(decoder thrift.Decoder) (thrift.Struct, error) {
    args := newReqAdapterServiceCount()
    if err := args.Read(decoder); err != nil {
        return nil, err
    }
    decoder.ReadMessageEnd()
    return args, nil
}

func (p *procFuncAdapterServiceCount) Write(seqId int32, result thrift.WritableStruct, encoder thrift.Encoder) (err error) {
    var err2 error
    messageType := thrift.REPLY
    switch result.(type) {
    case thrift.ApplicationExceptionIf:
        messageType = thrift.EXCEPTION
    }

    if err2 = encoder.WriteMessageBegin("count", messageType, seqId); err2 != nil {
        err = err2
    }
    if err2 = result.Write(encoder); err == nil && err2 != nil {
        err = err2
    }
    if err2 = encoder.WriteMessageEnd(); err == nil && err2 != nil {
        err = err2
    }
    if err2 = encoder.Flush(); err == nil && err2 != nil {
        err = err2
    }
    return err
}

func (p *procFuncAdapterServiceCount) RunContext(ctx context.Context, reqStruct thrift.Struct) (thrift.WritableStruct, thrift.ApplicationExceptionIf) {
    result := newRespAdapterServiceCount()
    retval, err := p.handler.Count(ctx)
    if err != nil {
        x := thrift.NewApplicationExceptionCause(thrift.INTERNAL_ERROR, "Internal error processing Count: " + err.Error(), err)
        return x, x
    }

    result.Success = retval
    return result, nil
}


type procFuncAdapterServiceAdaptedTypes struct {
    handler AdapterService
}
// Compile time interface enforcer
var _ thrift.ProcessorFunction = (*procFuncAdapterServiceAdaptedTypes)(nil)

func (p *procFuncAdapterServiceAdaptedTypes) Read(decoder thrift.Decoder) (thrift.Struct, error) {
    args := newReqAdapterServiceAdaptedTypes()
    if err := args.Read(decoder); err != nil {
        return nil, err
    }
    decoder.ReadMessageEnd()
    return args, nil
}

func (p *procFuncAdapterServiceAdaptedTypes) Write(seqId int32, result thrift.WritableStruct, encoder thrift.Encoder) (err error) {
    var err2 error
    messageType := thrift.REPLY
    switch result.(type) {
    case thrift.ApplicationExceptionIf:
        messageType = thrift.EXCEPTION
    }

    if err2 = encoder.WriteMessageBegin("adaptedTypes", messageType, seqId); err2 != nil {
        err = err2
    }
    if err2 = result.Write(encoder); err == nil && err2 != nil {
        err = err2
    }
    if err2 = encoder.WriteMessageEnd(); err == nil && err2 != nil {
        err = err2
    }
    if err2 = encoder.Flush(); err == nil && err2 != nil {
        err = err2
    }
    return err
}

func (p *procFuncAdapterServiceAdaptedTypes) RunContext(ctx context.Context, reqStruct thrift.Struct) (thrift.WritableStruct, thrift.ApplicationExceptionIf) {
    args := reqStruct.(*reqAdapterServiceAdaptedTypes)
    result := newRespAdapterServiceAdaptedTypes()
    retval, err := p.handler.AdaptedTypes(ctx, args.Arg)
    if err != nil {
        x := thrift.NewApplicationExceptionCause(thrift.INTERNAL_ERROR, "Internal error processing AdaptedTypes: " + err.Error(), err)
        return x, x
    }

    result.Success = retval
    return result, nil
}


