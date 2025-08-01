#
# Autogenerated by Thrift
#
# DO NOT EDIT
#  @generated
#

from __future__ import annotations

import folly.iobuf as _fbthrift_iobuf

from abc import ABCMeta as _fbthrift_ABCMeta
import test.fixtures.enums.module.thrift_abstract_types as _fbthrift_abstract_types
import thrift.python.types as _fbthrift_python_types
import thrift.python.mutable_types as _fbthrift_python_mutable_types
import thrift.python.mutable_containers as _fbthrift_python_mutable_containers
import thrift.python.mutable_exceptions as _fbthrift_python_mutable_exceptions
import thrift.python.mutable_typeinfos as _fbthrift_python_mutable_typeinfos


from test.fixtures.enums.module.thrift_enums import (
    Metasyntactic,
    Metasyntactic as _fbthrift_Metasyntactic,
    MyEnum1,
    MyEnum1 as _fbthrift_MyEnum1,
    MyEnum2,
    MyEnum2 as _fbthrift_MyEnum2,
    MyEnum3,
    MyEnum3 as _fbthrift_MyEnum3,
    MyEnum4,
    MyEnum4 as _fbthrift_MyEnum4,
    MyBitmaskEnum1,
    MyBitmaskEnum1 as _fbthrift_MyBitmaskEnum1,
    MyBitmaskEnum2,
    MyBitmaskEnum2 as _fbthrift_MyBitmaskEnum2,
)


class SomeStruct(metaclass=_fbthrift_python_mutable_types.MutableStructMeta):
    _fbthrift_SPEC = (
        _fbthrift_python_types.FieldInfo(
            1,  # id
            _fbthrift_python_types.FieldQualifier.Unqualified, # qualifier
            "reasonable",  # name
            "reasonable",  # python name (from @python.Name annotation)
            lambda: _fbthrift_python_types.EnumTypeInfo(Metasyntactic),  # typeinfo
            lambda: Metasyntactic.FOO,  # default value
            None,  # adapter info
            False, # field type is primitive
            10, # IDL type (see BaseTypeEnum)
        ),
        _fbthrift_python_types.FieldInfo(
            2,  # id
            _fbthrift_python_types.FieldQualifier.Unqualified, # qualifier
            "fine",  # name
            "fine",  # python name (from @python.Name annotation)
            lambda: _fbthrift_python_types.EnumTypeInfo(Metasyntactic),  # typeinfo
            lambda: Metasyntactic.BAR,  # default value
            None,  # adapter info
            False, # field type is primitive
            10, # IDL type (see BaseTypeEnum)
        ),
        _fbthrift_python_types.FieldInfo(
            3,  # id
            _fbthrift_python_types.FieldQualifier.Unqualified, # qualifier
            "questionable",  # name
            "questionable",  # python name (from @python.Name annotation)
            lambda: _fbthrift_python_types.EnumTypeInfo(Metasyntactic),  # typeinfo
            lambda: _fbthrift_python_types.BadEnum(Metasyntactic, -1),  # default value
            None,  # adapter info
            False, # field type is primitive
            10, # IDL type (see BaseTypeEnum)
        ),
        _fbthrift_python_types.FieldInfo(
            4,  # id
            _fbthrift_python_types.FieldQualifier.Unqualified, # qualifier
            "tags",  # name
            "tags",  # python name (from @python.Name annotation)
            lambda: _fbthrift_python_mutable_typeinfos.MutableSetTypeInfo(_fbthrift_python_types.typeinfo_i32),  # typeinfo
            lambda: _fbthrift_python_types.Set(_fbthrift_python_types.typeinfo_i32, ()),  # default value
            None,  # adapter info
            False, # field type is primitive
            15, # IDL type (see BaseTypeEnum)
        ),
    )

    @staticmethod
    def __get_thrift_name__() -> str:
        return "module.SomeStruct"

    @staticmethod
    def __get_thrift_uri__():
        return "test.dev/fixtures/enums/SomeStruct"

    @staticmethod
    def __get_metadata__():
        raise NotImplementedError(f"__get_metadata__() is not yet implemented for mutable thrift-python structs: {type(self)}")


    def _to_python(self):
        from thrift.python import converter
        import importlib
        immutable_types = importlib.import_module("test.fixtures.enums.module.thrift_types")
        return converter.to_python_struct(immutable_types.SomeStruct, self)

    def _to_mutable_python(self):
        return self

    def _to_py3(self):
        import importlib
        py3_types = importlib.import_module("test.fixtures.enums.module.types")
        from thrift.py3 import converter
        return converter.to_py3_struct(py3_types.SomeStruct, self)

    def _to_py_deprecated(self):
        import importlib
        from thrift.util import converter
        try:
            py_deprecated_types = importlib.import_module("module.ttypes")
            return converter.to_py_struct(py_deprecated_types.SomeStruct, self)
        except ModuleNotFoundError:
            py_asyncio_types = importlib.import_module("module.ttypes")
            return converter.to_py_struct(py_asyncio_types.SomeStruct, self)

_fbthrift_ABCMeta.register(_fbthrift_abstract_types.SomeStruct, SomeStruct)
_fbthrift_SomeStruct = SomeStruct

class MyStruct(metaclass=_fbthrift_python_mutable_types.MutableStructMeta):
    _fbthrift_SPEC = (
        _fbthrift_python_types.FieldInfo(
            1,  # id
            _fbthrift_python_types.FieldQualifier.Unqualified, # qualifier
            "me2_3",  # name
            "me2_3",  # python name (from @python.Name annotation)
            lambda: _fbthrift_python_types.EnumTypeInfo(MyEnum2),  # typeinfo
            lambda: _fbthrift_python_types.BadEnum(MyEnum2, 3),  # default value
            None,  # adapter info
            False, # field type is primitive
            10, # IDL type (see BaseTypeEnum)
        ),
        _fbthrift_python_types.FieldInfo(
            2,  # id
            _fbthrift_python_types.FieldQualifier.Unqualified, # qualifier
            "me3_n3",  # name
            "me3_n3",  # python name (from @python.Name annotation)
            lambda: _fbthrift_python_types.EnumTypeInfo(MyEnum3),  # typeinfo
            lambda: _fbthrift_python_types.BadEnum(MyEnum3, -3),  # default value
            None,  # adapter info
            False, # field type is primitive
            10, # IDL type (see BaseTypeEnum)
        ),
        _fbthrift_python_types.FieldInfo(
            4,  # id
            _fbthrift_python_types.FieldQualifier.Unqualified, # qualifier
            "me1_t1",  # name
            "me1_t1",  # python name (from @python.Name annotation)
            lambda: _fbthrift_python_types.EnumTypeInfo(MyEnum1),  # typeinfo
            lambda: MyEnum1.ME1_1,  # default value
            None,  # adapter info
            False, # field type is primitive
            10, # IDL type (see BaseTypeEnum)
        ),
        _fbthrift_python_types.FieldInfo(
            6,  # id
            _fbthrift_python_types.FieldQualifier.Unqualified, # qualifier
            "me1_t2",  # name
            "me1_t2",  # python name (from @python.Name annotation)
            lambda: _fbthrift_python_types.EnumTypeInfo(MyEnum1),  # typeinfo
            lambda: MyEnum1.ME1_1,  # default value
            None,  # adapter info
            False, # field type is primitive
            10, # IDL type (see BaseTypeEnum)
        ),
    )

    @staticmethod
    def __get_thrift_name__() -> str:
        return "module.MyStruct"

    @staticmethod
    def __get_thrift_uri__():
        return "test.dev/fixtures/enums/MyStruct"

    @staticmethod
    def __get_metadata__():
        raise NotImplementedError(f"__get_metadata__() is not yet implemented for mutable thrift-python structs: {type(self)}")


    def _to_python(self):
        from thrift.python import converter
        import importlib
        immutable_types = importlib.import_module("test.fixtures.enums.module.thrift_types")
        return converter.to_python_struct(immutable_types.MyStruct, self)

    def _to_mutable_python(self):
        return self

    def _to_py3(self):
        import importlib
        py3_types = importlib.import_module("test.fixtures.enums.module.types")
        from thrift.py3 import converter
        return converter.to_py3_struct(py3_types.MyStruct, self)

    def _to_py_deprecated(self):
        import importlib
        from thrift.util import converter
        try:
            py_deprecated_types = importlib.import_module("module.ttypes")
            return converter.to_py_struct(py_deprecated_types.MyStruct, self)
        except ModuleNotFoundError:
            py_asyncio_types = importlib.import_module("module.ttypes")
            return converter.to_py_struct(py_asyncio_types.MyStruct, self)

_fbthrift_ABCMeta.register(_fbthrift_abstract_types.MyStruct, MyStruct)
_fbthrift_MyStruct = MyStruct


_fbthrift_all_enums = [
    Metasyntactic,
    MyEnum1,
    MyEnum2,
    MyEnum3,
    MyEnum4,
    MyBitmaskEnum1,
    MyBitmaskEnum2,
]


_fbthrift_all_structs = [
    SomeStruct,
    MyStruct,
]
_fbthrift_python_mutable_types.fill_specs(*_fbthrift_all_structs)
