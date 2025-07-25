#
# Autogenerated by Thrift for thrift/compiler/test/fixtures/transitive-deps/src/a.thrift
#
# DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
#  @generated
#
cimport cython as __cython
from cpython.object cimport PyTypeObject
from libcpp.memory cimport shared_ptr, make_shared, unique_ptr
from libcpp.optional cimport optional as __optional
from libcpp.string cimport string
from libcpp cimport bool as cbool
from libcpp.iterator cimport inserter as cinserter
from libcpp.utility cimport move as cmove
from cpython cimport bool as pbool
from cython.operator cimport dereference as deref, preincrement as inc, address as ptr_address
import thrift.py3.types
from thrift.py3.types import _IsSet as _fbthrift_IsSet
from thrift.py3.types cimport make_unique
cimport thrift.py3.types
cimport thrift.py3.exceptions
cimport thrift.python.exceptions
import thrift.python.converter
from thrift.python.types import EnumMeta as __EnumMeta
from thrift.python.std_libcpp cimport sv_to_str as __sv_to_str, string_view as __cstring_view
from thrift.python.types cimport BadEnum as __BadEnum
from thrift.py3.types cimport (
    richcmp as __richcmp,
    init_unicode_from_cpp as __init_unicode_from_cpp,
    set_iter as __set_iter,
    map_iter as __map_iter,
    reference_shared_ptr as __reference_shared_ptr,
    get_field_name_by_index as __get_field_name_by_index,
    reset_field as __reset_field,
    translate_cpp_enum_to_python,
    const_pointer_cast,
    make_const_shared,
    constant_shared_ptr,
    mixin_deprecation_log_error,
)
from thrift.py3.types cimport _ensure_py3_or_raise, _ensure_py3_container_or_raise
cimport thrift.py3.serializer as serializer
from thrift.python.protocol cimport Protocol as __Protocol
import folly.iobuf as _fbthrift_iobuf
from folly.optional cimport cOptional
from folly.memory cimport to_shared_ptr as __to_shared_ptr
from folly.range cimport Range as __cRange

import sys
from collections.abc import Sequence, Set, Mapping, Iterable
import weakref as __weakref
import builtins as _builtins
import importlib
cimport b.types as _b_types
import b.types as _b_types
cimport c.types as _c_types
import c.types as _c_types

import a.thrift_types as _fbthrift_python_types

from a.containers_FBTHRIFT_ONLY_DO_NOT_USE import (
    List__c_C,
    List__List__c_C,
)

_fbthrift__module_name__ = "a.types"

cdef object get_types_reflection():
    return importlib.import_module(
        "a.types_reflection"
    )

@__cython.auto_pickle(False)
@__cython.final
cdef class A(thrift.py3.types.Struct):
    __module__ = _fbthrift__module_name__

    def __init__(A self, **kwargs):
        self._cpp_obj_FBTHRIFT_ONLY_DO_NOT_USE = make_shared[_a_cbindings.cA]()
        self._fields_setter = _fbthrift_types_fields.__A_FieldsSetter._fbthrift_create(self._cpp_obj_FBTHRIFT_ONLY_DO_NOT_USE.get())
        super().__init__(**kwargs)

    def __call__(A self, **kwargs):
        if not kwargs:
            return self
        cdef A __fbthrift_inst = A.__new__(A)
        __fbthrift_inst._cpp_obj_FBTHRIFT_ONLY_DO_NOT_USE = make_shared[_a_cbindings.cA](deref(self._cpp_obj_FBTHRIFT_ONLY_DO_NOT_USE))
        __fbthrift_inst._fields_setter = _fbthrift_types_fields.__A_FieldsSetter._fbthrift_create(__fbthrift_inst._cpp_obj_FBTHRIFT_ONLY_DO_NOT_USE.get())
        for __fbthrift_name, _fbthrift_value in kwargs.items():
            (<thrift.py3.types.Struct>__fbthrift_inst)._fbthrift_set_field(__fbthrift_name, _fbthrift_value)
        return __fbthrift_inst

    cdef void _fbthrift_set_field(self, str name, object value) except *:
        self._fields_setter.set_field(name.encode("utf-8"), value)

    cdef object _fbthrift_isset(self):
        return _fbthrift_IsSet("A", {
          "b": deref(self._cpp_obj_FBTHRIFT_ONLY_DO_NOT_USE).b_ref().has_value(),
          "other": deref(self._cpp_obj_FBTHRIFT_ONLY_DO_NOT_USE).other_ref().has_value(),
        })

    @staticmethod
    cdef _create_FBTHRIFT_ONLY_DO_NOT_USE(shared_ptr[_a_cbindings.cA] cpp_obj):
        __fbthrift_inst = <A>A.__new__(A)
        __fbthrift_inst._cpp_obj_FBTHRIFT_ONLY_DO_NOT_USE = cmove(cpp_obj)
        return __fbthrift_inst

    cdef inline b_impl(self):
        if self.__fbthrift_cached_b is None:
            self.__fbthrift_cached_b = List__List__c_C__from_cpp(deref(self._cpp_obj_FBTHRIFT_ONLY_DO_NOT_USE).b_ref().ref())
        return self.__fbthrift_cached_b

    @property
    def b(self):
        return self.b_impl()

    cdef inline other_impl(self):
        if self.__fbthrift_cached_other is None:
            self.__fbthrift_cached_other = List__c_C__from_cpp(deref(self._cpp_obj_FBTHRIFT_ONLY_DO_NOT_USE).other_ref().ref())
        return self.__fbthrift_cached_other

    @property
    def other(self):
        return self.other_impl()


    def __hash__(A self):
        return super().__hash__()

    def __repr__(A self):
        return super().__repr__()

    def __str__(A self):
        return super().__str__()


    def __copy__(A self):
        return self

    def __richcmp__(self, other, int op):
        r = self._fbthrift_cmp_sametype(other, op)
        return __richcmp[_a_cbindings.cA](
            self._cpp_obj_FBTHRIFT_ONLY_DO_NOT_USE,
            (<A>other)._cpp_obj_FBTHRIFT_ONLY_DO_NOT_USE,
            op,
        ) if r is None else r

    @staticmethod
    def __get_reflection__():
        return get_types_reflection().get_reflection__A()

    @staticmethod
    def __get_metadata__():
        cdef __fbthrift_cThriftMetadata meta
        _a_cbindings.StructMetadata[_a_cbindings.cA].gen(meta)
        return __MetadataBox.box(cmove(meta))

    @staticmethod
    def __get_thrift_name__():
        return "a.A"

    @classmethod
    def _fbthrift_get_field_name_by_index(cls, idx):
        return __sv_to_str(__get_field_name_by_index[_a_cbindings.cA](idx))

    @classmethod
    def _fbthrift_get_struct_size(cls):
        return 2

    cdef _fbthrift_iobuf.IOBuf _fbthrift_serialize(A self, __Protocol proto):
        cdef unique_ptr[_fbthrift_iobuf.cIOBuf] data
        with nogil:
            data = cmove(serializer.cserialize[_a_cbindings.cA](self._cpp_obj_FBTHRIFT_ONLY_DO_NOT_USE.get(), proto))
        return _fbthrift_iobuf.from_unique_ptr(cmove(data))

    cdef cuint32_t _fbthrift_deserialize(A self, const _fbthrift_iobuf.cIOBuf* buf, __Protocol proto) except? 0:
        cdef cuint32_t needed
        self._cpp_obj_FBTHRIFT_ONLY_DO_NOT_USE = make_shared[_a_cbindings.cA]()
        with nogil:
            needed = serializer.cdeserialize[_a_cbindings.cA](buf, self._cpp_obj_FBTHRIFT_ONLY_DO_NOT_USE.get(), proto)
        return needed


    def _to_python(self):
        return thrift.python.converter.to_python_struct(
            _fbthrift_python_types.A,
            self,
        )

    def _to_py3(self):
        return self

    def _to_py_deprecated(self):
        import thrift.util.converter
        py_deprecated_types = importlib.import_module("a.ttypes")
        return thrift.util.converter.to_py_struct(py_deprecated_types.A, self)

cdef vector[_c_cbindings.cC] List__c_C__make_instance(object items) except *:
    cdef vector[_c_cbindings.cC] c_inst
    if items is None:
        return cmove(c_inst)
    for item in items:
        if not isinstance(item, _c_types.C):
            raise TypeError(f"{item!r} is not of type _c_types.C")
        c_inst.push_back(deref((<_c_types.C>item)._cpp_obj_FBTHRIFT_ONLY_DO_NOT_USE))
    return cmove(c_inst)

cdef object List__c_C__from_cpp(const vector[_c_cbindings.cC]& c_vec) except *:
    cdef list py_list = []
    cdef int idx = 0
    for idx in range(c_vec.size()):
        py_list.append(_c_types.C._create_FBTHRIFT_ONLY_DO_NOT_USE(make_shared[_c_cbindings.cC](c_vec[idx])))
    return List__c_C(py_list, thrift.py3.types._fbthrift_list_private_ctor)

cdef vector[vector[_c_cbindings.cC]] List__List__c_C__make_instance(object items) except *:
    cdef vector[vector[_c_cbindings.cC]] c_inst
    if items is None:
        return cmove(c_inst)
    for item in items:
        if item is None:
            raise TypeError("None is not of the type _typing.Sequence[_c_types.C]")
        if not isinstance(item, List__c_C):
            item = List__c_C(item)
        c_inst.push_back(List__c_C__make_instance(item))
    return cmove(c_inst)

cdef object List__List__c_C__from_cpp(const vector[vector[_c_cbindings.cC]]& c_vec) except *:
    cdef list py_list = []
    cdef int idx = 0
    for idx in range(c_vec.size()):
        py_list.append(List__c_C__from_cpp(c_vec[idx]))
    return List__List__c_C(py_list, thrift.py3.types._fbthrift_list_private_ctor)


