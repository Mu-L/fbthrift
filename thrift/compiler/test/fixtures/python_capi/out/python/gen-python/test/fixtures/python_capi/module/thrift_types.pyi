#
# Autogenerated by Thrift
#
# DO NOT EDIT
#  @generated
#

from __future__ import annotations

import typing as _typing

import enum

import folly.iobuf as _fbthrift_iobuf
import test.fixtures.python_capi.module.thrift_abstract_types as _fbthrift_python_abstract_types
import thrift.python.types as _fbthrift_python_types
import thrift.python.exceptions as _fbthrift_python_exceptions

import apache.thrift.type.id.thrift_types as _fbthrift__apache__thrift__type__id__thrift_types

import apache.thrift.type.schema.thrift_types as _fbthrift__apache__thrift__type__schema__thrift_types

import test.fixtures.python_capi.serialized_dep.thrift_types as _fbthrift__test__fixtures__python_capi__serialized_dep__thrift_types

import test.fixtures.python_capi.thrift_dep.thrift_types as _fbthrift__test__fixtures__python_capi__thrift_dep__thrift_types

from test.fixtures.python_capi.module.thrift_enums import (
    MyEnum as _fbthrift_MyEnum,
    AnnoyingEnum as _fbthrift_AnnoyingEnum,
)
MyEnum = _fbthrift_MyEnum
AnnoyingEnum = _fbthrift_AnnoyingEnum


class MyStruct(_fbthrift_python_types.Struct, _fbthrift_python_abstract_types.MyStruct):
    inty: _typing.Final[int] = ...
    stringy: _typing.Final[str] = ...
    myItemy: _typing.Final[_fbthrift_MyDataItem] = ...
    myEnumy: _typing.Final[_fbthrift_MyEnum] = ...
    booly: _typing.Final[bool] = ...
    floatListy: _typing.Final[_typing.Sequence[float]] = ...
    strMappy: _typing.Final[_typing.Mapping[bytes, str]] = ...
    intSetty: _typing.Final[_typing.AbstractSet[int]] = ...
    def __init__(
        self, *,
        inty: _typing.Optional[int]=...,
        stringy: _typing.Optional[str]=...,
        myItemy: _typing.Optional[MyDataItem]=...,
        myEnumy: _typing.Optional[MyEnum]=...,
        booly: _typing.Optional[bool]=...,
        floatListy: _typing.Optional[_typing.Sequence[float]]=...,
        strMappy: _typing.Optional[_typing.Mapping[bytes, str]]=...,
        intSetty: _typing.Optional[_typing.AbstractSet[int]]=...
    ) -> None: ...

    def __call__(
        self, *,
        inty: _typing.Optional[int]=...,
        stringy: _typing.Optional[str]=...,
        myItemy: _typing.Optional[MyDataItem]=...,
        myEnumy: _typing.Optional[MyEnum]=...,
        booly: _typing.Optional[bool]=...,
        floatListy: _typing.Optional[_typing.Sequence[float]]=...,
        strMappy: _typing.Optional[_typing.Mapping[bytes, str]]=...,
        intSetty: _typing.Optional[_typing.AbstractSet[int]]=...
    ) -> _typing.Self: ...
    def __iter__(self) -> _typing.Iterator[_typing.Tuple[str, _typing.Union[int, str, _fbthrift_MyDataItem, _fbthrift_MyEnum, bool, _typing.Sequence[float], _typing.Mapping[bytes, str], _typing.AbstractSet[int]]]]: ...
    def _to_python(self) -> _typing.Self: ...
    def _to_mutable_python(self) -> "test.fixtures.python_capi.module.thrift_mutable_types.MyStruct": ...  # type: ignore
    def _to_py3(self) -> "test.fixtures.python_capi.module.types.MyStruct": ...  # type: ignore
    def _to_py_deprecated(self) -> "module.ttypes.MyStruct": ...  # type: ignore
_fbthrift_MyStruct = MyStruct

class MyDataItem(_fbthrift_python_types.Struct, _fbthrift_python_abstract_types.MyDataItem):
    s: _typing.Final[str] = ...
    def __init__(
        self, *,
        s: _typing.Optional[str]=...
    ) -> None: ...

    def __call__(
        self, *,
        s: _typing.Optional[str]=...
    ) -> _typing.Self: ...
    def __iter__(self) -> _typing.Iterator[_typing.Tuple[str, _typing.Union[str]]]: ...
    def _to_python(self) -> _typing.Self: ...
    def _to_mutable_python(self) -> "test.fixtures.python_capi.module.thrift_mutable_types.MyDataItem": ...  # type: ignore
    def _to_py3(self) -> "test.fixtures.python_capi.module.types.MyDataItem": ...  # type: ignore
    def _to_py_deprecated(self) -> "module.ttypes.MyDataItem": ...  # type: ignore
_fbthrift_MyDataItem = MyDataItem

class TransitiveDoubler(_fbthrift_python_types.Struct, _fbthrift_python_abstract_types.TransitiveDoubler):
    def __init__(
        self,
    ) -> None: ...

    def __call__(
        self,
    ) -> _typing.Self: ...
    def __iter__(self) -> _typing.Iterator[_typing.Tuple[str, _typing.Union[None]]]: ...
    def _to_python(self) -> _typing.Self: ...
    def _to_mutable_python(self) -> "test.fixtures.python_capi.module.thrift_mutable_types.TransitiveDoubler": ...  # type: ignore
    def _to_py3(self) -> "test.fixtures.python_capi.module.types.TransitiveDoubler": ...  # type: ignore
    def _to_py_deprecated(self) -> "module.ttypes.TransitiveDoubler": ...  # type: ignore
_fbthrift_TransitiveDoubler = TransitiveDoubler

class DoubledPair(_fbthrift_python_types.Struct, _fbthrift_python_abstract_types.DoubledPair):
    s: _typing.Final[str] = ...
    x: _typing.Final[int] = ...
    def __init__(
        self, *,
        s: _typing.Optional[str]=...,
        x: _typing.Optional[int]=...
    ) -> None: ...

    def __call__(
        self, *,
        s: _typing.Optional[str]=...,
        x: _typing.Optional[int]=...
    ) -> _typing.Self: ...
    def __iter__(self) -> _typing.Iterator[_typing.Tuple[str, _typing.Union[str, int]]]: ...
    def _to_python(self) -> _typing.Self: ...
    def _to_mutable_python(self) -> "test.fixtures.python_capi.module.thrift_mutable_types.DoubledPair": ...  # type: ignore
    def _to_py3(self) -> "test.fixtures.python_capi.module.types.DoubledPair": ...  # type: ignore
    def _to_py_deprecated(self) -> "module.ttypes.DoubledPair": ...  # type: ignore
_fbthrift_DoubledPair = DoubledPair

class StringPair(_fbthrift_python_types.Struct, _fbthrift_python_abstract_types.StringPair):
    normal: _typing.Final[str] = ...
    doubled: _typing.Final[str] = ...
    def __init__(
        self, *,
        normal: _typing.Optional[str]=...,
        doubled: _typing.Optional[str]=...
    ) -> None: ...

    def __call__(
        self, *,
        normal: _typing.Optional[str]=...,
        doubled: _typing.Optional[str]=...
    ) -> _typing.Self: ...
    def __iter__(self) -> _typing.Iterator[_typing.Tuple[str, _typing.Union[str, str]]]: ...
    def _to_python(self) -> _typing.Self: ...
    def _to_mutable_python(self) -> "test.fixtures.python_capi.module.thrift_mutable_types.StringPair": ...  # type: ignore
    def _to_py3(self) -> "test.fixtures.python_capi.module.types.StringPair": ...  # type: ignore
    def _to_py_deprecated(self) -> "module.ttypes.StringPair": ...  # type: ignore
_fbthrift_StringPair = StringPair

class EmptyStruct(_fbthrift_python_types.Struct, _fbthrift_python_abstract_types.EmptyStruct):
    def __init__(
        self,
    ) -> None: ...

    def __call__(
        self,
    ) -> _typing.Self: ...
    def __iter__(self) -> _typing.Iterator[_typing.Tuple[str, _typing.Union[None]]]: ...
    def _to_python(self) -> _typing.Self: ...
    def _to_mutable_python(self) -> "test.fixtures.python_capi.module.thrift_mutable_types.EmptyStruct": ...  # type: ignore
    def _to_py3(self) -> "test.fixtures.python_capi.module.types.EmptyStruct": ...  # type: ignore
    def _to_py_deprecated(self) -> "module.ttypes.EmptyStruct": ...  # type: ignore
_fbthrift_EmptyStruct = EmptyStruct

class PrimitiveStruct(_fbthrift_python_types.Struct, _fbthrift_python_abstract_types.PrimitiveStruct):
    booly: _typing.Final[bool] = ...
    charry: _typing.Final[int] = ...
    shorty: _typing.Final[int] = ...
    inty: _typing.Final[int] = ...
    longy: _typing.Final[int] = ...
    floaty: _typing.Final[_typing.Optional[float]] = ...
    dubby: _typing.Final[_typing.Optional[float]] = ...
    stringy: _typing.Final[_typing.Optional[str]] = ...
    bytey: _typing.Final[_typing.Optional[bytes]] = ...
    buffy: _typing.Final[_fbthrift_iobuf.IOBuf] = ...
    pointbuffy: _typing.Final[_fbthrift_iobuf.IOBuf] = ...
    patched_struct: _typing.Final[_fbthrift_MyStruct] = ...
    empty_struct: _typing.Final[_fbthrift_EmptyStruct] = ...
    fbstring: _typing.Final[bytes] = ...
    managed_string_view: _typing.Final[str] = ...
    some_error: _typing.Final[_fbthrift__test__fixtures__python_capi__thrift_dep__thrift_types.SomeError] = ...
    def __init__(
        self, *,
        booly: _typing.Optional[bool]=...,
        charry: _typing.Optional[int]=...,
        shorty: _typing.Optional[int]=...,
        inty: _typing.Optional[int]=...,
        longy: _typing.Optional[int]=...,
        floaty: _typing.Optional[float]=...,
        dubby: _typing.Optional[float]=...,
        stringy: _typing.Optional[str]=...,
        bytey: _typing.Optional[bytes]=...,
        buffy: _typing.Optional[_fbthrift_iobuf.IOBuf]=...,
        pointbuffy: _typing.Optional[_fbthrift_iobuf.IOBuf]=...,
        patched_struct: _typing.Optional[MyStruct]=...,
        empty_struct: _typing.Optional[EmptyStruct]=...,
        fbstring: _typing.Optional[bytes]=...,
        managed_string_view: _typing.Optional[str]=...,
        some_error: _typing.Optional[_fbthrift__test__fixtures__python_capi__thrift_dep__thrift_types.SomeError]=...
    ) -> None: ...

    def __call__(
        self, *,
        booly: _typing.Optional[bool]=...,
        charry: _typing.Optional[int]=...,
        shorty: _typing.Optional[int]=...,
        inty: _typing.Optional[int]=...,
        longy: _typing.Optional[int]=...,
        floaty: _typing.Optional[float]=...,
        dubby: _typing.Optional[float]=...,
        stringy: _typing.Optional[str]=...,
        bytey: _typing.Optional[bytes]=...,
        buffy: _typing.Optional[_fbthrift_iobuf.IOBuf]=...,
        pointbuffy: _typing.Optional[_fbthrift_iobuf.IOBuf]=...,
        patched_struct: _typing.Optional[MyStruct]=...,
        empty_struct: _typing.Optional[EmptyStruct]=...,
        fbstring: _typing.Optional[bytes]=...,
        managed_string_view: _typing.Optional[str]=...,
        some_error: _typing.Optional[_fbthrift__test__fixtures__python_capi__thrift_dep__thrift_types.SomeError]=...
    ) -> _typing.Self: ...
    def __iter__(self) -> _typing.Iterator[_typing.Tuple[str, _typing.Union[bool, int, int, int, int, float, float, str, bytes, _fbthrift_iobuf.IOBuf, _fbthrift_iobuf.IOBuf, _fbthrift_MyStruct, _fbthrift_EmptyStruct, bytes, str, _fbthrift__test__fixtures__python_capi__thrift_dep__thrift_types.SomeError]]]: ...
    def _to_python(self) -> _typing.Self: ...
    def _to_mutable_python(self) -> "test.fixtures.python_capi.module.thrift_mutable_types.PrimitiveStruct": ...  # type: ignore
    def _to_py3(self) -> "test.fixtures.python_capi.module.types.PrimitiveStruct": ...  # type: ignore
    def _to_py_deprecated(self) -> "module.ttypes.PrimitiveStruct": ...  # type: ignore
_fbthrift_PrimitiveStruct = PrimitiveStruct

class AdaptedFields(_fbthrift_python_types.Struct, _fbthrift_python_abstract_types.AdaptedFields):
    adapted_int: _typing.Final[int] = ...
    list_adapted_int: _typing.Final[_typing.Sequence[int]] = ...
    set_adapted_int: _typing.Final[_typing.AbstractSet[int]] = ...
    inline_adapted_int: _typing.Final[int] = ...
    def __init__(
        self, *,
        adapted_int: _typing.Optional[int]=...,
        list_adapted_int: _typing.Optional[_typing.Sequence[int]]=...,
        set_adapted_int: _typing.Optional[_typing.AbstractSet[int]]=...,
        inline_adapted_int: _typing.Optional[int]=...
    ) -> None: ...

    def __call__(
        self, *,
        adapted_int: _typing.Optional[int]=...,
        list_adapted_int: _typing.Optional[_typing.Sequence[int]]=...,
        set_adapted_int: _typing.Optional[_typing.AbstractSet[int]]=...,
        inline_adapted_int: _typing.Optional[int]=...
    ) -> _typing.Self: ...
    def __iter__(self) -> _typing.Iterator[_typing.Tuple[str, _typing.Union[int, _typing.Sequence[int], _typing.AbstractSet[int], int]]]: ...
    def _to_python(self) -> _typing.Self: ...
    def _to_mutable_python(self) -> "test.fixtures.python_capi.module.thrift_mutable_types.AdaptedFields": ...  # type: ignore
    def _to_py3(self) -> "test.fixtures.python_capi.module.types.AdaptedFields": ...  # type: ignore
    def _to_py_deprecated(self) -> "module.ttypes.AdaptedFields": ...  # type: ignore
_fbthrift_AdaptedFields = AdaptedFields

class ListStruct(_fbthrift_python_types.Struct, _fbthrift_python_abstract_types.ListStruct):
    boolz: _typing.Final[_typing.Sequence[bool]] = ...
    intz: _typing.Final[_typing.Optional[_typing.Sequence[int]]] = ...
    stringz: _typing.Final[_typing.Optional[_typing.Sequence[str]]] = ...
    encoded: _typing.Final[_typing.Sequence[bytes]] = ...
    uidz: _typing.Final[_typing.Sequence[int]] = ...
    matrix: _typing.Final[_typing.Sequence[_typing.Sequence[float]]] = ...
    ucharz: _typing.Final[_typing.Sequence[_typing.Sequence[int]]] = ...
    voxels: _typing.Final[_typing.Sequence[_typing.Sequence[_typing.Sequence[int]]]] = ...
    buf_ptrs: _typing.Final[_typing.Sequence[_fbthrift_iobuf.IOBuf]] = ...
    def __init__(
        self, *,
        boolz: _typing.Optional[_typing.Sequence[bool]]=...,
        intz: _typing.Optional[_typing.Sequence[int]]=...,
        stringz: _typing.Optional[_typing.Sequence[str]]=...,
        encoded: _typing.Optional[_typing.Sequence[bytes]]=...,
        uidz: _typing.Optional[_typing.Sequence[int]]=...,
        matrix: _typing.Optional[_typing.Sequence[_typing.Sequence[float]]]=...,
        ucharz: _typing.Optional[_typing.Sequence[_typing.Sequence[int]]]=...,
        voxels: _typing.Optional[_typing.Sequence[_typing.Sequence[_typing.Sequence[int]]]]=...,
        buf_ptrs: _typing.Optional[_typing.Sequence[_fbthrift_iobuf.IOBuf]]=...
    ) -> None: ...

    def __call__(
        self, *,
        boolz: _typing.Optional[_typing.Sequence[bool]]=...,
        intz: _typing.Optional[_typing.Sequence[int]]=...,
        stringz: _typing.Optional[_typing.Sequence[str]]=...,
        encoded: _typing.Optional[_typing.Sequence[bytes]]=...,
        uidz: _typing.Optional[_typing.Sequence[int]]=...,
        matrix: _typing.Optional[_typing.Sequence[_typing.Sequence[float]]]=...,
        ucharz: _typing.Optional[_typing.Sequence[_typing.Sequence[int]]]=...,
        voxels: _typing.Optional[_typing.Sequence[_typing.Sequence[_typing.Sequence[int]]]]=...,
        buf_ptrs: _typing.Optional[_typing.Sequence[_fbthrift_iobuf.IOBuf]]=...
    ) -> _typing.Self: ...
    def __iter__(self) -> _typing.Iterator[_typing.Tuple[str, _typing.Union[_typing.Sequence[bool], _typing.Sequence[int], _typing.Sequence[str], _typing.Sequence[bytes], _typing.Sequence[int], _typing.Sequence[_typing.Sequence[float]], _typing.Sequence[_typing.Sequence[int]], _typing.Sequence[_typing.Sequence[_typing.Sequence[int]]], _typing.Sequence[_fbthrift_iobuf.IOBuf]]]]: ...
    def _to_python(self) -> _typing.Self: ...
    def _to_mutable_python(self) -> "test.fixtures.python_capi.module.thrift_mutable_types.ListStruct": ...  # type: ignore
    def _to_py3(self) -> "test.fixtures.python_capi.module.types.ListStruct": ...  # type: ignore
    def _to_py_deprecated(self) -> "module.ttypes.ListStruct": ...  # type: ignore
_fbthrift_ListStruct = ListStruct

class SetStruct(_fbthrift_python_types.Struct, _fbthrift_python_abstract_types.SetStruct):
    enumz: _typing.Final[_typing.AbstractSet[_fbthrift_MyEnum]] = ...
    intz: _typing.Final[_typing.Optional[_typing.AbstractSet[int]]] = ...
    binnaz: _typing.Final[_typing.Optional[_typing.AbstractSet[bytes]]] = ...
    encoded: _typing.Final[_typing.AbstractSet[bytes]] = ...
    uidz: _typing.Final[_typing.AbstractSet[int]] = ...
    charz: _typing.Final[_typing.AbstractSet[int]] = ...
    setz: _typing.Final[_typing.Sequence[_typing.AbstractSet[int]]] = ...
    def __init__(
        self, *,
        enumz: _typing.Optional[_typing.AbstractSet[MyEnum]]=...,
        intz: _typing.Optional[_typing.AbstractSet[int]]=...,
        binnaz: _typing.Optional[_typing.AbstractSet[bytes]]=...,
        encoded: _typing.Optional[_typing.AbstractSet[bytes]]=...,
        uidz: _typing.Optional[_typing.AbstractSet[int]]=...,
        charz: _typing.Optional[_typing.AbstractSet[int]]=...,
        setz: _typing.Optional[_typing.Sequence[_typing.AbstractSet[int]]]=...
    ) -> None: ...

    def __call__(
        self, *,
        enumz: _typing.Optional[_typing.AbstractSet[MyEnum]]=...,
        intz: _typing.Optional[_typing.AbstractSet[int]]=...,
        binnaz: _typing.Optional[_typing.AbstractSet[bytes]]=...,
        encoded: _typing.Optional[_typing.AbstractSet[bytes]]=...,
        uidz: _typing.Optional[_typing.AbstractSet[int]]=...,
        charz: _typing.Optional[_typing.AbstractSet[int]]=...,
        setz: _typing.Optional[_typing.Sequence[_typing.AbstractSet[int]]]=...
    ) -> _typing.Self: ...
    def __iter__(self) -> _typing.Iterator[_typing.Tuple[str, _typing.Union[_typing.AbstractSet[_fbthrift_MyEnum], _typing.AbstractSet[int], _typing.AbstractSet[bytes], _typing.AbstractSet[bytes], _typing.AbstractSet[int], _typing.AbstractSet[int], _typing.Sequence[_typing.AbstractSet[int]]]]]: ...
    def _to_python(self) -> _typing.Self: ...
    def _to_mutable_python(self) -> "test.fixtures.python_capi.module.thrift_mutable_types.SetStruct": ...  # type: ignore
    def _to_py3(self) -> "test.fixtures.python_capi.module.types.SetStruct": ...  # type: ignore
    def _to_py_deprecated(self) -> "module.ttypes.SetStruct": ...  # type: ignore
_fbthrift_SetStruct = SetStruct

class MapStruct(_fbthrift_python_types.Struct, _fbthrift_python_abstract_types.MapStruct):
    enumz: _typing.Final[_typing.Mapping[_fbthrift_MyEnum, str]] = ...
    intz: _typing.Final[_typing.Optional[_typing.Mapping[int, str]]] = ...
    binnaz: _typing.Final[_typing.Optional[_typing.Mapping[bytes, _fbthrift_PrimitiveStruct]]] = ...
    encoded: _typing.Final[_typing.Mapping[str, float]] = ...
    flotz: _typing.Final[_typing.Mapping[int, float]] = ...
    map_list: _typing.Final[_typing.Sequence[_typing.Mapping[int, int]]] = ...
    list_map: _typing.Final[_typing.Mapping[int, _typing.Sequence[int]]] = ...
    fast_list_map: _typing.Final[_typing.Mapping[int, _typing.Sequence[float]]] = ...
    buf_map: _typing.Final[_typing.Mapping[bytes, _fbthrift_iobuf.IOBuf]] = ...
    unsigned_list_map: _typing.Final[_typing.Mapping[int, _typing.Sequence[int]]] = ...
    def __init__(
        self, *,
        enumz: _typing.Optional[_typing.Mapping[_fbthrift_MyEnum, str]]=...,
        intz: _typing.Optional[_typing.Mapping[int, str]]=...,
        binnaz: _typing.Optional[_typing.Mapping[bytes, PrimitiveStruct]]=...,
        encoded: _typing.Optional[_typing.Mapping[str, float]]=...,
        flotz: _typing.Optional[_typing.Mapping[int, float]]=...,
        map_list: _typing.Optional[_typing.Sequence[_typing.Mapping[int, int]]]=...,
        list_map: _typing.Optional[_typing.Mapping[int, _typing.Sequence[int]]]=...,
        fast_list_map: _typing.Optional[_typing.Mapping[int, _typing.Sequence[float]]]=...,
        buf_map: _typing.Optional[_typing.Mapping[bytes, _fbthrift_iobuf.IOBuf]]=...,
        unsigned_list_map: _typing.Optional[_typing.Mapping[int, _typing.Sequence[int]]]=...
    ) -> None: ...

    def __call__(
        self, *,
        enumz: _typing.Optional[_typing.Mapping[_fbthrift_MyEnum, str]]=...,
        intz: _typing.Optional[_typing.Mapping[int, str]]=...,
        binnaz: _typing.Optional[_typing.Mapping[bytes, PrimitiveStruct]]=...,
        encoded: _typing.Optional[_typing.Mapping[str, float]]=...,
        flotz: _typing.Optional[_typing.Mapping[int, float]]=...,
        map_list: _typing.Optional[_typing.Sequence[_typing.Mapping[int, int]]]=...,
        list_map: _typing.Optional[_typing.Mapping[int, _typing.Sequence[int]]]=...,
        fast_list_map: _typing.Optional[_typing.Mapping[int, _typing.Sequence[float]]]=...,
        buf_map: _typing.Optional[_typing.Mapping[bytes, _fbthrift_iobuf.IOBuf]]=...,
        unsigned_list_map: _typing.Optional[_typing.Mapping[int, _typing.Sequence[int]]]=...
    ) -> _typing.Self: ...
    def __iter__(self) -> _typing.Iterator[_typing.Tuple[str, _typing.Union[_typing.Mapping[_fbthrift_MyEnum, str], _typing.Mapping[int, str], _typing.Mapping[bytes, _fbthrift_PrimitiveStruct], _typing.Mapping[str, float], _typing.Mapping[int, float], _typing.Sequence[_typing.Mapping[int, int]], _typing.Mapping[int, _typing.Sequence[int]], _typing.Mapping[int, _typing.Sequence[float]], _typing.Mapping[bytes, _fbthrift_iobuf.IOBuf], _typing.Mapping[int, _typing.Sequence[int]]]]]: ...
    def _to_python(self) -> _typing.Self: ...
    def _to_mutable_python(self) -> "test.fixtures.python_capi.module.thrift_mutable_types.MapStruct": ...  # type: ignore
    def _to_py3(self) -> "test.fixtures.python_capi.module.types.MapStruct": ...  # type: ignore
    def _to_py_deprecated(self) -> "module.ttypes.MapStruct": ...  # type: ignore
_fbthrift_MapStruct = MapStruct

class ComposeStruct(_fbthrift_python_types.Struct, _fbthrift_python_abstract_types.ComposeStruct):
    enum_: _typing.Final[_fbthrift_MyEnum] = ...
    renamed_: _typing.Final[_fbthrift_AnnoyingEnum] = ...
    primitive: _typing.Final[_fbthrift_PrimitiveStruct] = ...
    aliased: _typing.Final[_fbthrift_ListStruct] = ...
    xenum: _typing.Final[_fbthrift__test__fixtures__python_capi__thrift_dep__thrift_types.DepEnum] = ...
    xstruct: _typing.Final[_fbthrift__test__fixtures__python_capi__thrift_dep__thrift_types.DepStruct] = ...
    friends: _typing.Final[_typing.Sequence[_fbthrift__test__fixtures__python_capi__thrift_dep__thrift_types.DepStruct]] = ...
    serial_struct: _typing.Final[_fbthrift__test__fixtures__python_capi__serialized_dep__thrift_types.SerializedStruct] = ...
    serial_union: _typing.Final[_fbthrift__test__fixtures__python_capi__serialized_dep__thrift_types.SerializedUnion] = ...
    serial_error: _typing.Final[_fbthrift__test__fixtures__python_capi__serialized_dep__thrift_types.SerializedError] = ...
    def __init__(
        self, *,
        enum_: _typing.Optional[MyEnum]=...,
        renamed_: _typing.Optional[AnnoyingEnum]=...,
        primitive: _typing.Optional[PrimitiveStruct]=...,
        aliased: _typing.Optional[ListStruct]=...,
        xenum: _typing.Optional[_fbthrift__test__fixtures__python_capi__thrift_dep__thrift_types.DepEnum]=...,
        xstruct: _typing.Optional[_fbthrift__test__fixtures__python_capi__thrift_dep__thrift_types.DepStruct]=...,
        friends: _typing.Optional[_typing.Sequence[_fbthrift__test__fixtures__python_capi__thrift_dep__thrift_types.DepStruct]]=...,
        serial_struct: _typing.Optional[_fbthrift__test__fixtures__python_capi__serialized_dep__thrift_types.SerializedStruct]=...,
        serial_union: _typing.Optional[_fbthrift__test__fixtures__python_capi__serialized_dep__thrift_types.SerializedUnion]=...,
        serial_error: _typing.Optional[_fbthrift__test__fixtures__python_capi__serialized_dep__thrift_types.SerializedError]=...
    ) -> None: ...

    def __call__(
        self, *,
        enum_: _typing.Optional[MyEnum]=...,
        renamed_: _typing.Optional[AnnoyingEnum]=...,
        primitive: _typing.Optional[PrimitiveStruct]=...,
        aliased: _typing.Optional[ListStruct]=...,
        xenum: _typing.Optional[_fbthrift__test__fixtures__python_capi__thrift_dep__thrift_types.DepEnum]=...,
        xstruct: _typing.Optional[_fbthrift__test__fixtures__python_capi__thrift_dep__thrift_types.DepStruct]=...,
        friends: _typing.Optional[_typing.Sequence[_fbthrift__test__fixtures__python_capi__thrift_dep__thrift_types.DepStruct]]=...,
        serial_struct: _typing.Optional[_fbthrift__test__fixtures__python_capi__serialized_dep__thrift_types.SerializedStruct]=...,
        serial_union: _typing.Optional[_fbthrift__test__fixtures__python_capi__serialized_dep__thrift_types.SerializedUnion]=...,
        serial_error: _typing.Optional[_fbthrift__test__fixtures__python_capi__serialized_dep__thrift_types.SerializedError]=...
    ) -> _typing.Self: ...
    def __iter__(self) -> _typing.Iterator[_typing.Tuple[str, _typing.Union[_fbthrift_MyEnum, _fbthrift_AnnoyingEnum, _fbthrift_PrimitiveStruct, _fbthrift_ListStruct, _fbthrift__test__fixtures__python_capi__thrift_dep__thrift_types.DepEnum, _fbthrift__test__fixtures__python_capi__thrift_dep__thrift_types.DepStruct, _typing.Sequence[_fbthrift__test__fixtures__python_capi__thrift_dep__thrift_types.DepStruct], _fbthrift__test__fixtures__python_capi__serialized_dep__thrift_types.SerializedStruct, _fbthrift__test__fixtures__python_capi__serialized_dep__thrift_types.SerializedUnion, _fbthrift__test__fixtures__python_capi__serialized_dep__thrift_types.SerializedError]]]: ...
    def _to_python(self) -> _typing.Self: ...
    def _to_mutable_python(self) -> "test.fixtures.python_capi.module.thrift_mutable_types.ComposeStruct": ...  # type: ignore
    def _to_py3(self) -> "test.fixtures.python_capi.module.types.ComposeStruct": ...  # type: ignore
    def _to_py_deprecated(self) -> "module.ttypes.ComposeStruct": ...  # type: ignore
_fbthrift_ComposeStruct = ComposeStruct

class Onion(_fbthrift_python_types.Union, _fbthrift_python_abstract_types.Onion):
    myEnum: _typing.Final[_fbthrift_MyEnum] = ...
    myStruct: _typing.Final[_fbthrift_PrimitiveStruct] = ...
    myString: _typing.Final[str] = ...
    intSet: _typing.Final[_typing.AbstractSet[int]] = ...
    doubleList: _typing.Final[_typing.Sequence[float]] = ...
    strMap: _typing.Final[_typing.Mapping[bytes, str]] = ...
    adapted_int: _typing.Final[int] = ...
    def __init__(
        self, *,
        myEnum: _typing.Optional[MyEnum]=...,
        myStruct: _typing.Optional[PrimitiveStruct]=...,
        myString: _typing.Optional[str]=...,
        intSet: _typing.Optional[_typing.AbstractSet[int]]=...,
        doubleList: _typing.Optional[_typing.Sequence[float]]=...,
        strMap: _typing.Optional[_typing.Mapping[bytes, str]]=...,
        adapted_int: _typing.Optional[int]=...
    ) -> None: ...


    class Type(enum.Enum):
        EMPTY: Onion.Type = ...
        myEnum: Onion.Type = ...
        myStruct: Onion.Type = ...
        myString: Onion.Type = ...
        intSet: Onion.Type = ...
        doubleList: Onion.Type = ...
        strMap: Onion.Type = ...
        adapted_int: Onion.Type = ...

    class FbThriftUnionFieldEnum(enum.Enum):
        EMPTY: Onion.FbThriftUnionFieldEnum = ...
        myEnum: Onion.FbThriftUnionFieldEnum = ...
        myStruct: Onion.FbThriftUnionFieldEnum = ...
        myString: Onion.FbThriftUnionFieldEnum = ...
        intSet: Onion.FbThriftUnionFieldEnum = ...
        doubleList: Onion.FbThriftUnionFieldEnum = ...
        strMap: Onion.FbThriftUnionFieldEnum = ...
        adapted_int: Onion.FbThriftUnionFieldEnum = ...

    fbthrift_current_value: _typing.Final[_typing.Union[None, _fbthrift_MyEnum, _fbthrift_PrimitiveStruct, str, _typing.AbstractSet[int], _typing.Sequence[float], _typing.Mapping[bytes, str], int]]
    fbthrift_current_field: _typing.Final[FbThriftUnionFieldEnum]
    @classmethod
    def fromValue(cls, value: _typing.Union[None, _fbthrift_MyEnum, _fbthrift_PrimitiveStruct, str, _typing.AbstractSet[int], _typing.Sequence[float], _typing.Mapping[bytes, str], int]) -> Onion: ...
    value: _typing.Final[_typing.Union[None, _fbthrift_MyEnum, _fbthrift_PrimitiveStruct, str, _typing.AbstractSet[int], _typing.Sequence[float], _typing.Mapping[bytes, str], int]]
    type: _typing.Final[Type]
    def get_type(self) -> Type: ...
    def _to_python(self) -> _typing.Self: ...
    def _to_mutable_python(self) -> "test.fixtures.python_capi.module.thrift_mutable_types.Onion": ...  # type: ignore
    def _to_py3(self) -> "test.fixtures.python_capi.module.types.Onion": ...  # type: ignore
    def _to_py_deprecated(self) -> "module.ttypes.Onion": ...  # type: ignore
_fbthrift_Onion = Onion

class SomeBinary(_fbthrift_python_types.Union, _fbthrift_python_abstract_types.SomeBinary):
    iobuf: _typing.Final[_fbthrift_iobuf.IOBuf] = ...
    iobuf_ptr: _typing.Final[_fbthrift_iobuf.IOBuf] = ...
    iobufRef: _typing.Final[_fbthrift_iobuf.IOBuf] = ...
    def __init__(
        self, *,
        iobuf: _typing.Optional[_fbthrift_iobuf.IOBuf]=...,
        iobuf_ptr: _typing.Optional[_fbthrift_iobuf.IOBuf]=...,
        iobufRef: _typing.Optional[_fbthrift_iobuf.IOBuf]=...
    ) -> None: ...


    class Type(enum.Enum):
        EMPTY: SomeBinary.Type = ...
        iobuf: SomeBinary.Type = ...
        iobuf_ptr: SomeBinary.Type = ...
        iobufRef: SomeBinary.Type = ...

    class FbThriftUnionFieldEnum(enum.Enum):
        EMPTY: SomeBinary.FbThriftUnionFieldEnum = ...
        iobuf: SomeBinary.FbThriftUnionFieldEnum = ...
        iobuf_ptr: SomeBinary.FbThriftUnionFieldEnum = ...
        iobufRef: SomeBinary.FbThriftUnionFieldEnum = ...

    fbthrift_current_value: _typing.Final[_typing.Union[None, _fbthrift_iobuf.IOBuf, _fbthrift_iobuf.IOBuf, _fbthrift_iobuf.IOBuf]]
    fbthrift_current_field: _typing.Final[FbThriftUnionFieldEnum]
    @classmethod
    def fromValue(cls, value: _typing.Union[None, _fbthrift_iobuf.IOBuf, _fbthrift_iobuf.IOBuf, _fbthrift_iobuf.IOBuf]) -> SomeBinary: ...
    value: _typing.Final[_typing.Union[None, _fbthrift_iobuf.IOBuf, _fbthrift_iobuf.IOBuf, _fbthrift_iobuf.IOBuf]]
    type: _typing.Final[Type]
    def get_type(self) -> Type: ...
    def _to_python(self) -> _typing.Self: ...
    def _to_mutable_python(self) -> "test.fixtures.python_capi.module.thrift_mutable_types.SomeBinary": ...  # type: ignore
    def _to_py3(self) -> "test.fixtures.python_capi.module.types.SomeBinary": ...  # type: ignore
    def _to_py_deprecated(self) -> "module.ttypes.SomeBinary": ...  # type: ignore
_fbthrift_SomeBinary = SomeBinary

uint64 = int
ui64 = int
signed_byte = int
IOBuf = _fbthrift_iobuf.IOBuf
IOBufPtr = _fbthrift_iobuf.IOBuf
ListAlias = _fbthrift_ListStruct
