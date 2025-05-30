#
# Autogenerated by Thrift for thrift/compiler/test/fixtures/mcpp2-compare/src/module.thrift
#
# DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
#  @generated
#
import typing as _typing

import folly.iobuf as _fbthrift_iobuf
import thrift.py3.builder

import includes.types as _includes_types

import module.types as _module_types


_fbthrift_struct_type__Empty = _module_types.Empty
class Empty_Builder(thrift.py3.builder.StructBuilder):
    _struct_type = _fbthrift_struct_type__Empty

    def __init__(self):
        pass

    def __iter__(self):
        pass

_fbthrift_struct_type__ASimpleStruct = _module_types.ASimpleStruct
class ASimpleStruct_Builder(thrift.py3.builder.StructBuilder):
    _struct_type = _fbthrift_struct_type__ASimpleStruct

    def __init__(self):
        self.boolField: _typing.Optional[int] = None

    def __iter__(self):
        yield "boolField", self.boolField

_fbthrift_struct_type__ASimpleStructNoexcept = _module_types.ASimpleStructNoexcept
class ASimpleStructNoexcept_Builder(thrift.py3.builder.StructBuilder):
    _struct_type = _fbthrift_struct_type__ASimpleStructNoexcept

    def __init__(self):
        self.boolField: _typing.Optional[int] = None

    def __iter__(self):
        yield "boolField", self.boolField

_fbthrift_struct_type__MyStruct = _module_types.MyStruct
class MyStruct_Builder(thrift.py3.builder.StructBuilder):
    _struct_type = _fbthrift_struct_type__MyStruct

    def __init__(self):
        self.MyBoolField: _typing.Optional[bool] = None
        self.MyIntField: _typing.Optional[int] = None
        self.MyStringField: _typing.Optional[str] = None
        self.MyStringField2: _typing.Optional[str] = None
        self.MyBinaryField: _typing.Optional[bytes] = None
        self.MyBinaryField2: _typing.Optional[bytes] = None
        self.MyBinaryField3: _typing.Optional[bytes] = None
        self.MyBinaryListField4: _typing.Optional[list] = None
        self.MyMapEnumAndInt: _typing.Optional[dict] = None
        self.MyCustomField: _typing.Optional[_fbthrift_iobuf.IOBuf] = None
        self.MyOptCustomField: _typing.Optional[_fbthrift_iobuf.IOBuf] = None

    def __iter__(self):
        yield "MyBoolField", self.MyBoolField
        yield "MyIntField", self.MyIntField
        yield "MyStringField", self.MyStringField
        yield "MyStringField2", self.MyStringField2
        yield "MyBinaryField", self.MyBinaryField
        yield "MyBinaryField2", self.MyBinaryField2
        yield "MyBinaryField3", self.MyBinaryField3
        yield "MyBinaryListField4", self.MyBinaryListField4
        yield "MyMapEnumAndInt", self.MyMapEnumAndInt
        yield "MyCustomField", self.MyCustomField
        yield "MyOptCustomField", self.MyOptCustomField

_fbthrift_struct_type__SimpleUnion = _module_types.SimpleUnion
class SimpleUnion_Builder(thrift.py3.builder.StructBuilder):
    _struct_type = _fbthrift_struct_type__SimpleUnion

    def __init__(self):
        self.intValue: _typing.Optional[int] = None
        self.stringValue: _typing.Optional[str] = None

    def __iter__(self):
        yield "intValue", self.intValue
        yield "stringValue", self.stringValue

_fbthrift_struct_type__ComplexUnion = _module_types.ComplexUnion
class ComplexUnion_Builder(thrift.py3.builder.StructBuilder):
    _struct_type = _fbthrift_struct_type__ComplexUnion

    def __init__(self):
        self.intValue: _typing.Optional[int] = None
        self.opt_intValue: _typing.Optional[int] = None
        self.stringValue: _typing.Optional[str] = None
        self.opt_stringValue: _typing.Optional[str] = None
        self.intValue2: _typing.Optional[int] = None
        self.intValue3: _typing.Optional[int] = None
        self.doubelValue: _typing.Optional[float] = None
        self.boolValue: _typing.Optional[bool] = None
        self.union_list: _typing.Optional[list] = None
        self.union_set: _typing.Optional[set] = None
        self.union_map: _typing.Optional[dict] = None
        self.opt_union_map: _typing.Optional[dict] = None
        self.enum_field: _typing.Optional[_module_types.MyEnumA] = None
        self.enum_container: _typing.Optional[list] = None
        self.a_struct: _typing.Any = None
        self.a_set_struct: _typing.Optional[set] = None
        self.a_union: _typing.Any = None
        self.opt_a_union: _typing.Any = None
        self.a_union_list: _typing.Optional[list] = None
        self.a_union_typedef: _typing.Optional[set] = None
        self.a_union_typedef_list: _typing.Optional[list] = None
        self.MyBinaryField: _typing.Optional[bytes] = None
        self.MyBinaryField2: _typing.Optional[bytes] = None
        self.MyBinaryListField4: _typing.Optional[list] = None
        self.ref_field: _typing.Any = None
        self.ref_field2: _typing.Any = None
        self.excp_field: _typing.Any = None
        self.MyCustomField: _typing.Optional[_fbthrift_iobuf.IOBuf] = None

    def __iter__(self):
        yield "intValue", self.intValue
        yield "opt_intValue", self.opt_intValue
        yield "stringValue", self.stringValue
        yield "opt_stringValue", self.opt_stringValue
        yield "intValue2", self.intValue2
        yield "intValue3", self.intValue3
        yield "doubelValue", self.doubelValue
        yield "boolValue", self.boolValue
        yield "union_list", self.union_list
        yield "union_set", self.union_set
        yield "union_map", self.union_map
        yield "opt_union_map", self.opt_union_map
        yield "enum_field", self.enum_field
        yield "enum_container", self.enum_container
        yield "a_struct", self.a_struct
        yield "a_set_struct", self.a_set_struct
        yield "a_union", self.a_union
        yield "opt_a_union", self.opt_a_union
        yield "a_union_list", self.a_union_list
        yield "a_union_typedef", self.a_union_typedef
        yield "a_union_typedef_list", self.a_union_typedef_list
        yield "MyBinaryField", self.MyBinaryField
        yield "MyBinaryField2", self.MyBinaryField2
        yield "MyBinaryListField4", self.MyBinaryListField4
        yield "ref_field", self.ref_field
        yield "ref_field2", self.ref_field2
        yield "excp_field", self.excp_field
        yield "MyCustomField", self.MyCustomField

_fbthrift_struct_type__AnException = _module_types.AnException
class AnException_Builder(thrift.py3.builder.StructBuilder):
    _struct_type = _fbthrift_struct_type__AnException

    def __init__(self):
        self.code: _typing.Optional[int] = None
        self.req_code: _typing.Optional[int] = None
        self.message2: _typing.Optional[str] = None
        self.req_message: _typing.Optional[str] = None
        self.exception_list: _typing.Optional[list] = None
        self.exception_set: _typing.Optional[set] = None
        self.exception_map: _typing.Optional[dict] = None
        self.req_exception_map: _typing.Optional[dict] = None
        self.enum_field: _typing.Optional[_module_types.MyEnumA] = None
        self.enum_container: _typing.Optional[list] = None
        self.a_struct: _typing.Any = None
        self.a_set_struct: _typing.Optional[set] = None
        self.a_union_list: _typing.Optional[list] = None
        self.union_typedef: _typing.Optional[set] = None
        self.a_union_typedef_list: _typing.Optional[list] = None
        self.MyCustomField: _typing.Optional[_fbthrift_iobuf.IOBuf] = None
        self.MyOptCustomField: _typing.Optional[_fbthrift_iobuf.IOBuf] = None

    def __iter__(self):
        yield "code", self.code
        yield "req_code", self.req_code
        yield "message2", self.message2
        yield "req_message", self.req_message
        yield "exception_list", self.exception_list
        yield "exception_set", self.exception_set
        yield "exception_map", self.exception_map
        yield "req_exception_map", self.req_exception_map
        yield "enum_field", self.enum_field
        yield "enum_container", self.enum_container
        yield "a_struct", self.a_struct
        yield "a_set_struct", self.a_set_struct
        yield "a_union_list", self.a_union_list
        yield "union_typedef", self.union_typedef
        yield "a_union_typedef_list", self.a_union_typedef_list
        yield "MyCustomField", self.MyCustomField
        yield "MyOptCustomField", self.MyOptCustomField

_fbthrift_struct_type__AnotherException = _module_types.AnotherException
class AnotherException_Builder(thrift.py3.builder.StructBuilder):
    _struct_type = _fbthrift_struct_type__AnotherException

    def __init__(self):
        self.code: _typing.Optional[int] = None
        self.req_code: _typing.Optional[int] = None
        self.message: _typing.Optional[str] = None

    def __iter__(self):
        yield "code", self.code
        yield "req_code", self.req_code
        yield "message", self.message

_fbthrift_struct_type__containerStruct = _module_types.containerStruct
class containerStruct_Builder(thrift.py3.builder.StructBuilder):
    _struct_type = _fbthrift_struct_type__containerStruct

    def __init__(self):
        self.fieldA: _typing.Optional[bool] = None
        self.req_fieldA: _typing.Optional[bool] = None
        self.opt_fieldA: _typing.Optional[bool] = None
        self.fieldB: _typing.Optional[dict] = None
        self.req_fieldB: _typing.Optional[dict] = None
        self.opt_fieldB: _typing.Optional[dict] = None
        self.fieldC: _typing.Optional[set] = None
        self.req_fieldC: _typing.Optional[set] = None
        self.opt_fieldC: _typing.Optional[set] = None
        self.fieldD: _typing.Optional[str] = None
        self.fieldE: _typing.Optional[str] = None
        self.req_fieldE: _typing.Optional[str] = None
        self.opt_fieldE: _typing.Optional[str] = None
        self.fieldF: _typing.Optional[list] = None
        self.fieldG: _typing.Optional[dict] = None
        self.fieldH: _typing.Optional[list] = None
        self.fieldI: _typing.Optional[bool] = None
        self.fieldJ: _typing.Optional[dict] = None
        self.fieldK: _typing.Optional[list] = None
        self.fieldL: _typing.Optional[set] = None
        self.fieldM: _typing.Optional[dict] = None
        self.fieldN: _typing.Optional[int] = None
        self.fieldO: _typing.Optional[list] = None
        self.fieldP: _typing.Optional[list] = None
        self.fieldQ: _typing.Optional[_module_types.MyEnumA] = None
        self.fieldR: _typing.Optional[_module_types.MyEnumA] = None
        self.req_fieldR: _typing.Optional[_module_types.MyEnumA] = None
        self.opt_fieldR: _typing.Optional[_module_types.MyEnumA] = None
        self.fieldS: _typing.Optional[_module_types.MyEnumA] = None
        self.fieldT: _typing.Optional[list] = None
        self.fieldU: _typing.Optional[list] = None
        self.fieldV: _typing.Any = None
        self.req_fieldV: _typing.Any = None
        self.opt_fieldV: _typing.Any = None
        self.fieldW: _typing.Optional[set] = None
        self.fieldX: _typing.Any = None
        self.req_fieldX: _typing.Any = None
        self.opt_fieldX: _typing.Any = None
        self.fieldY: _typing.Optional[list] = None
        self.fieldZ: _typing.Optional[set] = None
        self.fieldAA: _typing.Optional[list] = None
        self.fieldAC: _typing.Optional[_module_types.MyEnumB] = None
        self.fieldAD: _typing.Optional[_includes_types.AnEnum] = None
        self.fieldAE: _typing.Optional[dict] = None

    def __iter__(self):
        yield "fieldA", self.fieldA
        yield "req_fieldA", self.req_fieldA
        yield "opt_fieldA", self.opt_fieldA
        yield "fieldB", self.fieldB
        yield "req_fieldB", self.req_fieldB
        yield "opt_fieldB", self.opt_fieldB
        yield "fieldC", self.fieldC
        yield "req_fieldC", self.req_fieldC
        yield "opt_fieldC", self.opt_fieldC
        yield "fieldD", self.fieldD
        yield "fieldE", self.fieldE
        yield "req_fieldE", self.req_fieldE
        yield "opt_fieldE", self.opt_fieldE
        yield "fieldF", self.fieldF
        yield "fieldG", self.fieldG
        yield "fieldH", self.fieldH
        yield "fieldI", self.fieldI
        yield "fieldJ", self.fieldJ
        yield "fieldK", self.fieldK
        yield "fieldL", self.fieldL
        yield "fieldM", self.fieldM
        yield "fieldN", self.fieldN
        yield "fieldO", self.fieldO
        yield "fieldP", self.fieldP
        yield "fieldQ", self.fieldQ
        yield "fieldR", self.fieldR
        yield "req_fieldR", self.req_fieldR
        yield "opt_fieldR", self.opt_fieldR
        yield "fieldS", self.fieldS
        yield "fieldT", self.fieldT
        yield "fieldU", self.fieldU
        yield "fieldV", self.fieldV
        yield "req_fieldV", self.req_fieldV
        yield "opt_fieldV", self.opt_fieldV
        yield "fieldW", self.fieldW
        yield "fieldX", self.fieldX
        yield "req_fieldX", self.req_fieldX
        yield "opt_fieldX", self.opt_fieldX
        yield "fieldY", self.fieldY
        yield "fieldZ", self.fieldZ
        yield "fieldAA", self.fieldAA
        yield "fieldAC", self.fieldAC
        yield "fieldAD", self.fieldAD
        yield "fieldAE", self.fieldAE

_fbthrift_struct_type__MyIncludedStruct = _module_types.MyIncludedStruct
class MyIncludedStruct_Builder(thrift.py3.builder.StructBuilder):
    _struct_type = _fbthrift_struct_type__MyIncludedStruct

    def __init__(self):
        self.MyIncludedInt: _typing.Optional[int] = None
        self.MyIncludedStruct: _typing.Any = None
        self.ARefField: _typing.Any = None
        self.ARequiredField: _typing.Any = None

    def __iter__(self):
        yield "MyIncludedInt", self.MyIncludedInt
        yield "MyIncludedStruct", self.MyIncludedStruct
        yield "ARefField", self.ARefField
        yield "ARequiredField", self.ARequiredField

_fbthrift_struct_type__AnnotatedStruct = _module_types.AnnotatedStruct
class AnnotatedStruct_Builder(thrift.py3.builder.StructBuilder):
    _struct_type = _fbthrift_struct_type__AnnotatedStruct

    def __init__(self):
        self.no_annotation: _typing.Any = None
        self.cpp_unique_ref: _typing.Any = None
        self.cpp2_unique_ref: _typing.Any = None
        self.container_with_ref: _typing.Optional[dict] = None
        self.req_cpp_unique_ref: _typing.Any = None
        self.req_cpp2_unique_ref: _typing.Any = None
        self.req_container_with_ref: _typing.Optional[list] = None
        self.opt_cpp_unique_ref: _typing.Any = None
        self.opt_cpp2_unique_ref: _typing.Any = None
        self.opt_container_with_ref: _typing.Optional[set] = None
        self.ref_type_unique: _typing.Any = None
        self.ref_type_shared: _typing.Any = None
        self.ref_type_const: _typing.Optional[dict] = None
        self.req_ref_type_shared: _typing.Any = None
        self.req_ref_type_const: _typing.Any = None
        self.req_ref_type_unique: _typing.Optional[list] = None
        self.opt_ref_type_const: _typing.Any = None
        self.opt_ref_type_unique: _typing.Any = None
        self.opt_ref_type_shared: _typing.Optional[set] = None
        self.base_type: _typing.Optional[int] = None
        self.list_type: _typing.Optional[list] = None
        self.set_type: _typing.Optional[set] = None
        self.map_type: _typing.Optional[dict] = None
        self.map_struct_type: _typing.Optional[dict] = None
        self.iobuf_type: _typing.Optional[_fbthrift_iobuf.IOBuf] = None
        self.iobuf_ptr: _typing.Optional[_fbthrift_iobuf.IOBuf] = None
        self.list_i32_template: _typing.Optional[list] = None
        self.list_string_template: _typing.Optional[list] = None
        self.set_template: _typing.Optional[set] = None
        self.map_template: _typing.Optional[dict] = None
        self.typedef_list_template: _typing.Optional[list] = None
        self.typedef_deque_template: _typing.Optional[list] = None
        self.typedef_set_template: _typing.Optional[set] = None
        self.typedef_map_template: _typing.Optional[dict] = None
        self.iobuf_type_val: _typing.Optional[_fbthrift_iobuf.IOBuf] = None
        self.iobuf_ptr_val: _typing.Optional[_fbthrift_iobuf.IOBuf] = None
        self.struct_struct: _typing.Any = None

    def __iter__(self):
        yield "no_annotation", self.no_annotation
        yield "cpp_unique_ref", self.cpp_unique_ref
        yield "cpp2_unique_ref", self.cpp2_unique_ref
        yield "container_with_ref", self.container_with_ref
        yield "req_cpp_unique_ref", self.req_cpp_unique_ref
        yield "req_cpp2_unique_ref", self.req_cpp2_unique_ref
        yield "req_container_with_ref", self.req_container_with_ref
        yield "opt_cpp_unique_ref", self.opt_cpp_unique_ref
        yield "opt_cpp2_unique_ref", self.opt_cpp2_unique_ref
        yield "opt_container_with_ref", self.opt_container_with_ref
        yield "ref_type_unique", self.ref_type_unique
        yield "ref_type_shared", self.ref_type_shared
        yield "ref_type_const", self.ref_type_const
        yield "req_ref_type_shared", self.req_ref_type_shared
        yield "req_ref_type_const", self.req_ref_type_const
        yield "req_ref_type_unique", self.req_ref_type_unique
        yield "opt_ref_type_const", self.opt_ref_type_const
        yield "opt_ref_type_unique", self.opt_ref_type_unique
        yield "opt_ref_type_shared", self.opt_ref_type_shared
        yield "base_type", self.base_type
        yield "list_type", self.list_type
        yield "set_type", self.set_type
        yield "map_type", self.map_type
        yield "map_struct_type", self.map_struct_type
        yield "iobuf_type", self.iobuf_type
        yield "iobuf_ptr", self.iobuf_ptr
        yield "list_i32_template", self.list_i32_template
        yield "list_string_template", self.list_string_template
        yield "set_template", self.set_template
        yield "map_template", self.map_template
        yield "typedef_list_template", self.typedef_list_template
        yield "typedef_deque_template", self.typedef_deque_template
        yield "typedef_set_template", self.typedef_set_template
        yield "typedef_map_template", self.typedef_map_template
        yield "iobuf_type_val", self.iobuf_type_val
        yield "iobuf_ptr_val", self.iobuf_ptr_val
        yield "struct_struct", self.struct_struct

_fbthrift_struct_type__ComplexContainerStruct = _module_types.ComplexContainerStruct
class ComplexContainerStruct_Builder(thrift.py3.builder.StructBuilder):
    _struct_type = _fbthrift_struct_type__ComplexContainerStruct

    def __init__(self):
        self.map_of_iobufs: _typing.Optional[dict] = None
        self.map_of_iobuf_ptrs: _typing.Optional[dict] = None

    def __iter__(self):
        yield "map_of_iobufs", self.map_of_iobufs
        yield "map_of_iobuf_ptrs", self.map_of_iobuf_ptrs

_fbthrift_struct_type__FloatStruct = _module_types.FloatStruct
class FloatStruct_Builder(thrift.py3.builder.StructBuilder):
    _struct_type = _fbthrift_struct_type__FloatStruct

    def __init__(self):
        self.floatField: _typing.Optional[float] = None
        self.doubleField: _typing.Optional[float] = None

    def __iter__(self):
        yield "floatField", self.floatField
        yield "doubleField", self.doubleField

_fbthrift_struct_type__FloatUnion = _module_types.FloatUnion
class FloatUnion_Builder(thrift.py3.builder.StructBuilder):
    _struct_type = _fbthrift_struct_type__FloatUnion

    def __init__(self):
        self.floatSide: _typing.Optional[float] = None
        self.doubleSide: _typing.Optional[float] = None

    def __iter__(self):
        yield "floatSide", self.floatSide
        yield "doubleSide", self.doubleSide

_fbthrift_struct_type__AllRequiredNoExceptMoveCtrStruct = _module_types.AllRequiredNoExceptMoveCtrStruct
class AllRequiredNoExceptMoveCtrStruct_Builder(thrift.py3.builder.StructBuilder):
    _struct_type = _fbthrift_struct_type__AllRequiredNoExceptMoveCtrStruct

    def __init__(self):
        self.intField: _typing.Optional[int] = None

    def __iter__(self):
        yield "intField", self.intField

