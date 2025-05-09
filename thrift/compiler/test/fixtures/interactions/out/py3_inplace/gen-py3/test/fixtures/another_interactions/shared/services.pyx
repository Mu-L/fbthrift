#
# Autogenerated by Thrift for shared.thrift
#
# DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
#  @generated
#

cimport cython
from typing import AsyncIterator
from cpython.version cimport PY_VERSION_HEX
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
from libcpp.pair cimport pair
from cython.operator cimport dereference as deref
from cpython.ref cimport PyObject
from thrift.python.exceptions cimport (
    ApplicationError as __ApplicationError,
    cTApplicationException,
    cTApplicationExceptionType__UNKNOWN,
)
from thrift.py3.server cimport ServiceInterface
from thrift.python.server_impl.request_context cimport (
    Cpp2RequestContext,
    RequestContext,
    THRIFT_REQUEST_CONTEXT as __THRIFT_REQUEST_CONTEXT,
)
from thrift.python.server_impl.request_context import RequestContext
from folly cimport (
  cFollyPromise,
  cFollyUnit,
  c_unit,
)
from thrift.python.common cimport (
    cThriftServiceMetadataResponse as __fbthrift_cThriftServiceMetadataResponse,
    ServiceMetadata,
    MetadataBox as __MetadataBox,
)

from thrift.py3.types cimport make_unique, deref_const

cimport folly.futures
from folly.executor cimport get_executor
cimport folly.iobuf as _fbthrift_iobuf
import folly.iobuf as _fbthrift_iobuf
from folly.iobuf cimport move as move_iobuf
from folly.memory cimport to_shared_ptr as __to_shared_ptr

cimport test.fixtures.another_interactions.shared.types as _test_fixtures_another_interactions_shared_types
cimport test.fixtures.another_interactions.shared.cbindings as _test_fixtures_another_interactions_shared_cbindings
cimport test.fixtures.another_interactions.shared.thrift_converter as _test_fixtures_another_interactions_shared_thrift_converter
import test.fixtures.another_interactions.shared.types as _test_fixtures_another_interactions_shared_types

cimport test.fixtures.another_interactions.shared.services_interface as _fbthrift_services_interface

import asyncio
import functools
import sys
import traceback
import types as _py_types

from test.fixtures.another_interactions.shared.services_wrapper cimport cInteractLocallyInterface



@cython.auto_pickle(False)
cdef class Promise__test_fixtures_another_interactions_shared_cbindings_cDoSomethingResult:
    cdef cFollyPromise[unique_ptr[_test_fixtures_another_interactions_shared_cbindings.cDoSomethingResult]]* cPromise

    def __cinit__(self):
        self.cPromise = new cFollyPromise[unique_ptr[_test_fixtures_another_interactions_shared_cbindings.cDoSomethingResult]](cFollyPromise[unique_ptr[_test_fixtures_another_interactions_shared_cbindings.cDoSomethingResult]].makeEmpty())

    def __dealloc__(self):
        del self.cPromise

    @staticmethod
    cdef _fbthrift_create(cFollyPromise[unique_ptr[_test_fixtures_another_interactions_shared_cbindings.cDoSomethingResult]] cPromise):
        cdef Promise__test_fixtures_another_interactions_shared_cbindings_cDoSomethingResult inst = Promise__test_fixtures_another_interactions_shared_cbindings_cDoSomethingResult.__new__(Promise__test_fixtures_another_interactions_shared_cbindings_cDoSomethingResult)
        inst.cPromise[0] = cmove(cPromise)
        return inst

@cython.auto_pickle(False)
cdef class Promise_cint32_t:
    cdef cFollyPromise[cint32_t]* cPromise

    def __cinit__(self):
        self.cPromise = new cFollyPromise[cint32_t](cFollyPromise[cint32_t].makeEmpty())

    def __dealloc__(self):
        del self.cPromise

    @staticmethod
    cdef _fbthrift_create(cFollyPromise[cint32_t] cPromise):
        cdef Promise_cint32_t inst = Promise_cint32_t.__new__(Promise_cint32_t)
        inst.cPromise[0] = cmove(cPromise)
        return inst

@cython.auto_pickle(False)
cdef class Promise_cFollyUnit:
    cdef cFollyPromise[cFollyUnit]* cPromise

    def __cinit__(self):
        self.cPromise = new cFollyPromise[cFollyUnit](cFollyPromise[cFollyUnit].makeEmpty())

    def __dealloc__(self):
        del self.cPromise

    @staticmethod
    cdef _fbthrift_create(cFollyPromise[cFollyUnit] cPromise):
        cdef Promise_cFollyUnit inst = Promise_cFollyUnit.__new__(Promise_cFollyUnit)
        inst.cPromise[0] = cmove(cPromise)
        return inst

cdef object _InteractLocally_annotations = _py_types.MappingProxyType({
})


@cython.auto_pickle(False)
cdef class InteractLocallyInterface(
    ServiceInterface
):
    annotations = _InteractLocally_annotations

    def __cinit__(self):
        self._cpp_obj = cInteractLocallyInterface(
            <PyObject *> self,
            get_executor()
        )

    @staticmethod
    def __get_metadata__():
        cdef __fbthrift_cThriftServiceMetadataResponse response
        ServiceMetadata[_fbthrift_services_interface.cInteractLocallySvIf].gen(response)
        return __MetadataBox.box(cmove(deref(response.metadata_ref())))

    @staticmethod
    def __get_thrift_name__():
        return "shared.InteractLocally"



cdef api void call_cy_InteractLocally_onStartServing(
    object self,
    cFollyPromise[cFollyUnit] cPromise
) noexcept:
    cdef Promise_cFollyUnit __promise = Promise_cFollyUnit._fbthrift_create(cmove(cPromise))
    asyncio.get_event_loop().create_task(
        InteractLocally_onStartServing_coro(
            self,
            __promise
        )
    )
cdef api void call_cy_InteractLocally_onStopRequested(
    object self,
    cFollyPromise[cFollyUnit] cPromise
) noexcept:
    cdef Promise_cFollyUnit __promise = Promise_cFollyUnit._fbthrift_create(cmove(cPromise))
    asyncio.get_event_loop().create_task(
        InteractLocally_onStopRequested_coro(
            self,
            __promise
        )
    )
async def InteractLocally_onStartServing_coro(
    object self,
    Promise_cFollyUnit promise
):
    try:
        result = await self.onStartServing()
    except __ApplicationError as ex:
        # If the handler raised an ApplicationError convert it to a C++ one
        promise.cPromise.setException(cTApplicationException(
            ex.type.value, ex.message.encode('UTF-8')
        ))
    except Exception as ex:
        print(
            "Unexpected error in service handler InteractLocally.onStartServing:",
            file=sys.stderr)
        traceback.print_exc()
        promise.cPromise.setException(cTApplicationException(
            cTApplicationExceptionType__UNKNOWN, repr(ex).encode('UTF-8')
        ))
    except asyncio.CancelledError as ex:
        print("Coroutine was cancelled in service handler InteractLocally.onStartServing:", file=sys.stderr)
        traceback.print_exc()
        promise.cPromise.setException(cTApplicationException(
            cTApplicationExceptionType__UNKNOWN, (f'Application was cancelled on the server with message: {str(ex)}').encode('UTF-8')
        ))
    else:
        promise.cPromise.setValue(c_unit)

async def InteractLocally_onStopRequested_coro(
    object self,
    Promise_cFollyUnit promise
):
    try:
        result = await self.onStopRequested()
    except __ApplicationError as ex:
        # If the handler raised an ApplicationError convert it to a C++ one
        promise.cPromise.setException(cTApplicationException(
            ex.type.value, ex.message.encode('UTF-8')
        ))
    except Exception as ex:
        print(
            "Unexpected error in service handler InteractLocally.onStopRequested:",
            file=sys.stderr)
        traceback.print_exc()
        promise.cPromise.setException(cTApplicationException(
            cTApplicationExceptionType__UNKNOWN, repr(ex).encode('UTF-8')
        ))
    except asyncio.CancelledError as ex:
        print("Coroutine was cancelled in service handler InteractLocally.onStopRequested:", file=sys.stderr)
        traceback.print_exc()
        promise.cPromise.setException(cTApplicationException(
            cTApplicationExceptionType__UNKNOWN, (f'Application was cancelled on the server with message: {str(ex)}').encode('UTF-8')
        ))
    else:
        promise.cPromise.setValue(c_unit)

