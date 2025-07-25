#
# Autogenerated by Thrift for thrift/compiler/test/fixtures/inheritance/src/module.thrift
#
# DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
#  @generated
#
from libc.stdint cimport (
    int8_t as cint8_t,
    int16_t as cint16_t,
    int32_t as cint32_t,
    int64_t as cint64_t,
)
from libcpp.memory cimport shared_ptr, make_shared, unique_ptr
from libcpp.string cimport string
from libcpp cimport bool as cbool
from cpython cimport bool as pbool
from libcpp.vector cimport vector
from libcpp.set cimport set as cset
from libcpp.map cimport map as cmap
from libcpp.utility cimport move as cmove
from cython.operator cimport dereference as deref, typeid
from cpython.ref cimport PyObject
from thrift.py3.client cimport cRequestChannel_ptr, makeClientWrapper, cClientWrapper
from thrift.py3.exceptions cimport try_make_shared_exception
from thrift.python.exceptions cimport create_py_exception
from folly cimport cFollyTry, cFollyUnit, c_unit
from folly.cast cimport down_cast_ptr
from libcpp.typeinfo cimport type_info
import thrift.py3.types
cimport thrift.py3.types
from thrift.py3.types cimport make_unique
import thrift.py3.client
cimport thrift.py3.client
from thrift.python.common cimport (
    RpcOptions as __RpcOptions,
    cThriftServiceMetadataResponse as __fbthrift_cThriftServiceMetadataResponse,
    ServiceMetadata,
    MetadataBox as __MetadataBox,
)

from folly.futures cimport bridgeFutureWith
from folly.executor cimport get_executor
cimport folly.iobuf as _fbthrift_iobuf
import folly.iobuf as _fbthrift_iobuf
from folly.iobuf cimport move as move_iobuf
cimport cython

import sys
import types as _py_types
from asyncio import get_event_loop as asyncio_get_event_loop, shield as asyncio_shield, InvalidStateError as asyncio_InvalidStateError

cimport module.types as _module_types
cimport module.cbindings as _module_cbindings
import module.types as _module_types

cimport module.services_interface as _fbthrift_services_interface

from module.clients_wrapper cimport cMyRootAsyncClient, cMyRootClientWrapper
from module.clients_wrapper cimport cMyNodeAsyncClient, cMyNodeClientWrapper
from module.clients_wrapper cimport cMyLeafAsyncClient, cMyLeafClientWrapper


cdef void MyRoot_do_root_callback(
    cFollyTry[cFollyUnit]&& result,
    PyObject* userdata
) noexcept:
    client, pyfuture, options = <object> userdata  
    if result.hasException():
        pyfuture.set_exception(create_py_exception(result.exception(), <__RpcOptions>options))
    else:
        try:
            pyfuture.set_result(None)
        except Exception as ex:
            pyfuture.set_exception(ex.with_traceback(None))

cdef void MyNode_do_mid_callback(
    cFollyTry[cFollyUnit]&& result,
    PyObject* userdata
) noexcept:
    client, pyfuture, options = <object> userdata  
    if result.hasException():
        pyfuture.set_exception(create_py_exception(result.exception(), <__RpcOptions>options))
    else:
        try:
            pyfuture.set_result(None)
        except Exception as ex:
            pyfuture.set_exception(ex.with_traceback(None))

cdef void MyLeaf_do_leaf_callback(
    cFollyTry[cFollyUnit]&& result,
    PyObject* userdata
) noexcept:
    client, pyfuture, options = <object> userdata  
    if result.hasException():
        pyfuture.set_exception(create_py_exception(result.exception(), <__RpcOptions>options))
    else:
        try:
            pyfuture.set_result(None)
        except Exception as ex:
            pyfuture.set_exception(ex.with_traceback(None))


cdef object _MyRoot_annotations = _py_types.MappingProxyType({
})


@cython.auto_pickle(False)
cdef class MyRoot(thrift.py3.client.Client):
    annotations = _MyRoot_annotations

    cdef const type_info* _typeid(MyRoot self):
        return &typeid(cMyRootAsyncClient)

    cdef bind_client(MyRoot self, cRequestChannel_ptr&& channel):
        self._client = makeClientWrapper[cMyRootAsyncClient, cMyRootClientWrapper](
            cmove(channel)
        )

    _fbthrift_annotations_DO_NOT_USE_do_root = {
        'return': 'None',
        
    }

    @cython.always_allow_keywords(True)
    def do_root(
            MyRoot self,
            *,
            __RpcOptions rpc_options=None
    ):
        if rpc_options is None:
            rpc_options = <__RpcOptions>__RpcOptions.__new__(__RpcOptions)
        self._check_connect_future()
        __loop = self._loop
        __future = __loop.create_future()
        __userdata = (self, __future, rpc_options)
        bridgeFutureWith[cFollyUnit](
            self._executor,
            down_cast_ptr[cMyRootClientWrapper, cClientWrapper](self._client.get()).do_root(rpc_options._cpp_obj, 
            ),
            MyRoot_do_root_callback,
            <PyObject *> __userdata
        )
        return asyncio_shield(__future)


    @staticmethod
    def __get_metadata__():
        cdef __fbthrift_cThriftServiceMetadataResponse response
        ServiceMetadata[_fbthrift_services_interface.cMyRootSvIf].gen(response)
        return __MetadataBox.box(cmove(deref(response.metadata_ref())))

    @staticmethod
    def __get_thrift_name__():
        return "module.MyRoot"

cdef object _MyNode_annotations = _py_types.MappingProxyType({
})


@cython.auto_pickle(False)
cdef class MyNode(MyRoot):
    annotations = _MyNode_annotations

    cdef const type_info* _typeid(MyNode self):
        return &typeid(cMyNodeAsyncClient)

    cdef bind_client(MyNode self, cRequestChannel_ptr&& channel):
        self._client = makeClientWrapper[cMyNodeAsyncClient, cMyNodeClientWrapper](
            cmove(channel)
        )

    _fbthrift_annotations_DO_NOT_USE_do_mid = {
        'return': 'None',
        
    }

    @cython.always_allow_keywords(True)
    def do_mid(
            MyNode self,
            *,
            __RpcOptions rpc_options=None
    ):
        if rpc_options is None:
            rpc_options = <__RpcOptions>__RpcOptions.__new__(__RpcOptions)
        self._check_connect_future()
        __loop = self._loop
        __future = __loop.create_future()
        __userdata = (self, __future, rpc_options)
        bridgeFutureWith[cFollyUnit](
            self._executor,
            down_cast_ptr[cMyNodeClientWrapper, cClientWrapper](self._client.get()).do_mid(rpc_options._cpp_obj, 
            ),
            MyNode_do_mid_callback,
            <PyObject *> __userdata
        )
        return asyncio_shield(__future)


    @staticmethod
    def __get_metadata__():
        cdef __fbthrift_cThriftServiceMetadataResponse response
        ServiceMetadata[_fbthrift_services_interface.cMyNodeSvIf].gen(response)
        return __MetadataBox.box(cmove(deref(response.metadata_ref())))

    @staticmethod
    def __get_thrift_name__():
        return "module.MyNode"

cdef object _MyLeaf_annotations = _py_types.MappingProxyType({
})


@cython.auto_pickle(False)
cdef class MyLeaf(MyNode):
    annotations = _MyLeaf_annotations

    cdef const type_info* _typeid(MyLeaf self):
        return &typeid(cMyLeafAsyncClient)

    cdef bind_client(MyLeaf self, cRequestChannel_ptr&& channel):
        self._client = makeClientWrapper[cMyLeafAsyncClient, cMyLeafClientWrapper](
            cmove(channel)
        )

    _fbthrift_annotations_DO_NOT_USE_do_leaf = {
        'return': 'None',
        
    }

    @cython.always_allow_keywords(True)
    def do_leaf(
            MyLeaf self,
            *,
            __RpcOptions rpc_options=None
    ):
        if rpc_options is None:
            rpc_options = <__RpcOptions>__RpcOptions.__new__(__RpcOptions)
        self._check_connect_future()
        __loop = self._loop
        __future = __loop.create_future()
        __userdata = (self, __future, rpc_options)
        bridgeFutureWith[cFollyUnit](
            self._executor,
            down_cast_ptr[cMyLeafClientWrapper, cClientWrapper](self._client.get()).do_leaf(rpc_options._cpp_obj, 
            ),
            MyLeaf_do_leaf_callback,
            <PyObject *> __userdata
        )
        return asyncio_shield(__future)


    @staticmethod
    def __get_metadata__():
        cdef __fbthrift_cThriftServiceMetadataResponse response
        ServiceMetadata[_fbthrift_services_interface.cMyLeafSvIf].gen(response)
        return __MetadataBox.box(cmove(deref(response.metadata_ref())))

    @staticmethod
    def __get_thrift_name__():
        return "module.MyLeaf"

