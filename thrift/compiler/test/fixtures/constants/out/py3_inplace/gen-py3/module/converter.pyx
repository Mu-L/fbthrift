
#
# Autogenerated by Thrift for thrift/compiler/test/fixtures/constants/src/module.thrift
#
# DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
#  @generated
#

from libcpp.memory cimport make_shared, unique_ptr
from cython.operator cimport dereference as deref, address
from libcpp.utility cimport move as cmove
from thrift.py3.types cimport const_pointer_cast
cimport module.thrift_converter as _module_thrift_converter
import module.types as _module_types


cdef shared_ptr[_fbthrift_cbindings.cInternship] Internship_convert_to_cpp(object inst) except*:
    try:
        inst = inst._fbthrift__inner
    except AttributeError:
        pass

    return make_shared[_fbthrift_cbindings.cInternship](
        _module_thrift_converter.Internship_convert_to_cpp(inst)
    )
cdef object Internship_from_cpp(const shared_ptr[_fbthrift_cbindings.cInternship]& c_struct):
    _py_struct = _module_thrift_converter.Internship_from_cpp(deref(const_pointer_cast(c_struct)))
    _py_struct = _module_types.Internship.from_python(_py_struct)
    return _py_struct

cdef shared_ptr[_fbthrift_cbindings.cRange] Range_convert_to_cpp(object inst) except*:
    try:
        inst = inst._fbthrift__inner
    except AttributeError:
        pass

    return make_shared[_fbthrift_cbindings.cRange](
        _module_thrift_converter.Range_convert_to_cpp(inst)
    )
cdef object Range_from_cpp(const shared_ptr[_fbthrift_cbindings.cRange]& c_struct):
    _py_struct = _module_thrift_converter.Range_from_cpp(deref(const_pointer_cast(c_struct)))
    _py_struct = _module_types.Range.from_python(_py_struct)
    return _py_struct

cdef shared_ptr[_fbthrift_cbindings.cstruct1] struct1_convert_to_cpp(object inst) except*:
    try:
        inst = inst._fbthrift__inner
    except AttributeError:
        pass

    return make_shared[_fbthrift_cbindings.cstruct1](
        _module_thrift_converter.struct1_convert_to_cpp(inst)
    )
cdef object struct1_from_cpp(const shared_ptr[_fbthrift_cbindings.cstruct1]& c_struct):
    _py_struct = _module_thrift_converter.struct1_from_cpp(deref(const_pointer_cast(c_struct)))
    _py_struct = _module_types.struct1.from_python(_py_struct)
    return _py_struct

cdef shared_ptr[_fbthrift_cbindings.cstruct2] struct2_convert_to_cpp(object inst) except*:
    try:
        inst = inst._fbthrift__inner
    except AttributeError:
        pass

    return make_shared[_fbthrift_cbindings.cstruct2](
        _module_thrift_converter.struct2_convert_to_cpp(inst)
    )
cdef object struct2_from_cpp(const shared_ptr[_fbthrift_cbindings.cstruct2]& c_struct):
    _py_struct = _module_thrift_converter.struct2_from_cpp(deref(const_pointer_cast(c_struct)))
    _py_struct = _module_types.struct2.from_python(_py_struct)
    return _py_struct

cdef shared_ptr[_fbthrift_cbindings.cstruct3] struct3_convert_to_cpp(object inst) except*:
    try:
        inst = inst._fbthrift__inner
    except AttributeError:
        pass

    return make_shared[_fbthrift_cbindings.cstruct3](
        _module_thrift_converter.struct3_convert_to_cpp(inst)
    )
cdef object struct3_from_cpp(const shared_ptr[_fbthrift_cbindings.cstruct3]& c_struct):
    _py_struct = _module_thrift_converter.struct3_from_cpp(deref(const_pointer_cast(c_struct)))
    _py_struct = _module_types.struct3.from_python(_py_struct)
    return _py_struct

cdef shared_ptr[_fbthrift_cbindings.cstruct4] struct4_convert_to_cpp(object inst) except*:
    try:
        inst = inst._fbthrift__inner
    except AttributeError:
        pass

    return make_shared[_fbthrift_cbindings.cstruct4](
        _module_thrift_converter.struct4_convert_to_cpp(inst)
    )
cdef object struct4_from_cpp(const shared_ptr[_fbthrift_cbindings.cstruct4]& c_struct):
    _py_struct = _module_thrift_converter.struct4_from_cpp(deref(const_pointer_cast(c_struct)))
    _py_struct = _module_types.struct4.from_python(_py_struct)
    return _py_struct

cdef shared_ptr[_fbthrift_cbindings.cunion1] union1_convert_to_cpp(object inst) except*:
    try:
        inst = inst._fbthrift__inner
    except AttributeError:
        pass

    return make_shared[_fbthrift_cbindings.cunion1](
        _module_thrift_converter.union1_convert_to_cpp(inst)
    )
cdef object union1_from_cpp(const shared_ptr[_fbthrift_cbindings.cunion1]& c_struct):
    _py_struct = _module_thrift_converter.union1_from_cpp(deref(const_pointer_cast(c_struct)))
    _py_struct = _module_types.union1.from_python(_py_struct)
    return _py_struct

cdef shared_ptr[_fbthrift_cbindings.cunion2] union2_convert_to_cpp(object inst) except*:
    try:
        inst = inst._fbthrift__inner
    except AttributeError:
        pass

    return make_shared[_fbthrift_cbindings.cunion2](
        _module_thrift_converter.union2_convert_to_cpp(inst)
    )
cdef object union2_from_cpp(const shared_ptr[_fbthrift_cbindings.cunion2]& c_struct):
    _py_struct = _module_thrift_converter.union2_from_cpp(deref(const_pointer_cast(c_struct)))
    _py_struct = _module_types.union2.from_python(_py_struct)
    return _py_struct


