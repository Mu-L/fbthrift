#
# Autogenerated by Thrift for thrift/compiler/test/fixtures/basic/src/module.thrift
#
# DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
#  @generated
#

import enum as _python_std_enum
import folly.iobuf as _fbthrift_iobuf
import thrift.py3.types
import thrift.python.types
import thrift.py3.exceptions
import typing as _typing

import sys
import itertools
import test.fixtures.basic.module.thrift_types


MyEnum = test.fixtures.basic.module.thrift_types.MyEnum
HackEnum = test.fixtures.basic.module.thrift_types.HackEnum

class MyStruct(thrift.py3.types.Struct, _typing.Hashable):
    class __fbthrift_IsSet:
        MyIntField: bool
        MyStringField: bool
        MyDataField: bool
        myEnum: bool
        oneway: bool
        readonly: bool
        idempotent: bool
        floatSet: bool
        no_hack_codegen_field: bool
        pass

    MyIntField: _typing.Final[int] = ...
    MyStringField: _typing.Final[str] = ...
    MyDataField: _typing.Final[MyDataItem] = ...
    myEnum: _typing.Final[MyEnum] = ...
    oneway: _typing.Final[bool] = ...
    readonly: _typing.Final[bool] = ...
    idempotent: _typing.Final[bool] = ...
    floatSet: _typing.Final[_typing.AbstractSet[float]] = ...
    no_hack_codegen_field: _typing.Final[str] = ...

    def __init__(
        self, *,
        MyIntField: _typing.Optional[int]=None,
        MyStringField: _typing.Optional[str]=None,
        MyDataField: _typing.Optional[MyDataItem]=None,
        myEnum: _typing.Optional[MyEnum]=None,
        oneway: _typing.Optional[bool]=None,
        readonly: _typing.Optional[bool]=None,
        idempotent: _typing.Optional[bool]=None,
        floatSet: _typing.Optional[_typing.AbstractSet[float]]=None,
        no_hack_codegen_field: _typing.Optional[str]=None
    ) -> None: ...

    def __call__(
        self, *,
        MyIntField: _typing.Union[int, None]=None,
        MyStringField: _typing.Union[str, None]=None,
        MyDataField: _typing.Union[MyDataItem, None]=None,
        myEnum: _typing.Union[MyEnum, None]=None,
        oneway: _typing.Union[bool, None]=None,
        readonly: _typing.Union[bool, None]=None,
        idempotent: _typing.Union[bool, None]=None,
        floatSet: _typing.Union[_typing.AbstractSet[float], None]=None,
        no_hack_codegen_field: _typing.Union[str, None]=None
    ) -> MyStruct: ...

    def __reduce__(self) -> _typing.Tuple[_typing.Callable, _typing.Tuple[_typing.Type['MyStruct'], bytes]]: ...
    def __hash__(self) -> int: ...
    def __str__(self) -> str: ...
    def __repr__(self) -> str: ...
    def __lt__(self, other: 'MyStruct') -> bool: ...
    def __gt__(self, other: 'MyStruct') -> bool: ...
    def __le__(self, other: 'MyStruct') -> bool: ...
    def __ge__(self, other: 'MyStruct') -> bool: ...

    def _to_python(self) -> test.fixtures.basic.module.thrift_types.MyStruct: ...
    def _to_py3(self) -> MyStruct: ...
    def _to_py_deprecated(self) -> "module.ttypes.MyStruct": ...   # type: ignore

class Containers(thrift.py3.types.Struct, _typing.Hashable):
    class __fbthrift_IsSet:
        I32List: bool
        StringSet: bool
        StringToI64Map: bool
        pass

    I32List: _typing.Final[_typing.Sequence[int]] = ...
    StringSet: _typing.Final[_typing.AbstractSet[str]] = ...
    StringToI64Map: _typing.Final[_typing.Mapping[str, int]] = ...

    def __init__(
        self, *,
        I32List: _typing.Optional[_typing.Sequence[int]]=None,
        StringSet: _typing.Optional[_typing.AbstractSet[str]]=None,
        StringToI64Map: _typing.Optional[_typing.Mapping[str, int]]=None
    ) -> None: ...

    def __call__(
        self, *,
        I32List: _typing.Union[_typing.Sequence[int], None]=None,
        StringSet: _typing.Union[_typing.AbstractSet[str], None]=None,
        StringToI64Map: _typing.Union[_typing.Mapping[str, int], None]=None
    ) -> Containers: ...

    def __reduce__(self) -> _typing.Tuple[_typing.Callable, _typing.Tuple[_typing.Type['Containers'], bytes]]: ...
    def __hash__(self) -> int: ...
    def __str__(self) -> str: ...
    def __repr__(self) -> str: ...
    def __lt__(self, other: 'Containers') -> bool: ...
    def __gt__(self, other: 'Containers') -> bool: ...
    def __le__(self, other: 'Containers') -> bool: ...
    def __ge__(self, other: 'Containers') -> bool: ...

    def _to_python(self) -> test.fixtures.basic.module.thrift_types.Containers: ...
    def _to_py3(self) -> Containers: ...
    def _to_py_deprecated(self) -> "module.ttypes.Containers": ...   # type: ignore

class MyDataItem(thrift.py3.types.Struct, _typing.Hashable):
    class __fbthrift_IsSet:
        pass


    def __init__(
        self, 
    ) -> None: ...

    def __call__(
        self, 
    ) -> MyDataItem: ...

    def __reduce__(self) -> _typing.Tuple[_typing.Callable, _typing.Tuple[_typing.Type['MyDataItem'], bytes]]: ...
    def __hash__(self) -> int: ...
    def __str__(self) -> str: ...
    def __repr__(self) -> str: ...
    def __lt__(self, other: 'MyDataItem') -> bool: ...
    def __gt__(self, other: 'MyDataItem') -> bool: ...
    def __le__(self, other: 'MyDataItem') -> bool: ...
    def __ge__(self, other: 'MyDataItem') -> bool: ...

    def _to_python(self) -> test.fixtures.basic.module.thrift_types.MyDataItem: ...
    def _to_py3(self) -> MyDataItem: ...
    def _to_py_deprecated(self) -> "module.ttypes.MyDataItem": ...   # type: ignore

_MyUnionValueType = _typing.Union[None, MyEnum, MyStruct, MyDataItem, _typing.AbstractSet[float]]

class MyUnion(thrift.py3.types.Union, _typing.Hashable):
    class __fbthrift_IsSet:
        myEnum: bool
        myStruct: bool
        myDataItem: bool
        floatSet: bool
        pass

    myEnum: _typing.Final[MyEnum] = ...
    myStruct: _typing.Final[MyStruct] = ...
    myDataItem: _typing.Final[MyDataItem] = ...
    floatSet: _typing.Final[_typing.AbstractSet[float]] = ...

    def __init__(
        self, *,
        myEnum: _typing.Optional[MyEnum]=None,
        myStruct: _typing.Optional[MyStruct]=None,
        myDataItem: _typing.Optional[MyDataItem]=None,
        floatSet: _typing.Optional[_typing.AbstractSet[float]]=None
    ) -> None: ...

    def __hash__(self) -> int: ...
    def __str__(self) -> str: ...
    def __repr__(self) -> str: ...
    def __lt__(self, other: 'MyUnion') -> bool: ...
    def __gt__(self, other: 'MyUnion') -> bool: ...
    def __le__(self, other: 'MyUnion') -> bool: ...
    def __ge__(self, other: 'MyUnion') -> bool: ...

    class Type(_python_std_enum.Enum):
        EMPTY: MyUnion.Type = ...
        myEnum: MyUnion.Type = ...
        myStruct: MyUnion.Type = ...
        myDataItem: MyUnion.Type = ...
        floatSet: MyUnion.Type = ...

    @staticmethod
    def fromValue(value: _MyUnionValueType) -> MyUnion: ...
    type: _typing.Final[MyUnion.Type]
    value: _typing.Final[_MyUnionValueType]
    def get_type(self) -> MyUnion.Type: ...

    def _to_python(self) -> test.fixtures.basic.module.thrift_types.MyUnion: ...
    def _to_py3(self) -> MyUnion: ...
    def _to_py_deprecated(self) -> "module.ttypes.MyUnion": ...   # type: ignore

class MyException(thrift.py3.exceptions.GeneratedError, _typing.Hashable):
    class __fbthrift_IsSet:
        MyIntField: bool
        MyStringField: bool
        myStruct: bool
        myUnion: bool
        pass

    MyIntField: _typing.Final[int] = ...
    MyStringField: _typing.Final[str] = ...
    myStruct: _typing.Final[MyStruct] = ...
    myUnion: _typing.Final[MyUnion] = ...

    def __init__(
        self, *,
        MyIntField: _typing.Optional[int]=None,
        MyStringField: _typing.Optional[str]=None,
        myStruct: _typing.Optional[MyStruct]=None,
        myUnion: _typing.Optional[MyUnion]=None
    ) -> None: ...

    def __hash__(self) -> int: ...
    def __str__(self) -> str: ...
    def __repr__(self) -> str: ...
    def __lt__(self, other: 'MyException') -> bool: ...
    def __gt__(self, other: 'MyException') -> bool: ...
    def __le__(self, other: 'MyException') -> bool: ...
    def __ge__(self, other: 'MyException') -> bool: ...

    def _to_python(self) -> test.fixtures.basic.module.thrift_types.MyException: ...
    def _to_py3(self) -> MyException: ...
    def _to_py_deprecated(self) -> "module.ttypes.MyException": ...   # type: ignore

class MyExceptionWithMessage(thrift.py3.exceptions.GeneratedError, _typing.Hashable):
    class __fbthrift_IsSet:
        MyIntField: bool
        MyStringField: bool
        myStruct: bool
        myUnion: bool
        pass

    MyIntField: _typing.Final[int] = ...
    MyStringField: _typing.Final[str] = ...
    myStruct: _typing.Final[MyStruct] = ...
    myUnion: _typing.Final[MyUnion] = ...

    def __init__(
        self, *,
        MyIntField: _typing.Optional[int]=None,
        MyStringField: _typing.Optional[str]=None,
        myStruct: _typing.Optional[MyStruct]=None,
        myUnion: _typing.Optional[MyUnion]=None
    ) -> None: ...

    def __hash__(self) -> int: ...
    def __str__(self) -> str: ...
    def __repr__(self) -> str: ...
    def __lt__(self, other: 'MyExceptionWithMessage') -> bool: ...
    def __gt__(self, other: 'MyExceptionWithMessage') -> bool: ...
    def __le__(self, other: 'MyExceptionWithMessage') -> bool: ...
    def __ge__(self, other: 'MyExceptionWithMessage') -> bool: ...

    def _to_python(self) -> test.fixtures.basic.module.thrift_types.MyExceptionWithMessage: ...
    def _to_py3(self) -> MyExceptionWithMessage: ...
    def _to_py_deprecated(self) -> "module.ttypes.MyExceptionWithMessage": ...   # type: ignore

class ReservedKeyword(thrift.py3.types.Struct, _typing.Hashable):
    class __fbthrift_IsSet:
        reserved_field: bool
        pass

    reserved_field: _typing.Final[int] = ...

    def __init__(
        self, *,
        reserved_field: _typing.Optional[int]=None
    ) -> None: ...

    def __call__(
        self, *,
        reserved_field: _typing.Union[int, None]=None
    ) -> ReservedKeyword: ...

    def __reduce__(self) -> _typing.Tuple[_typing.Callable, _typing.Tuple[_typing.Type['ReservedKeyword'], bytes]]: ...
    def __hash__(self) -> int: ...
    def __str__(self) -> str: ...
    def __repr__(self) -> str: ...
    def __lt__(self, other: 'ReservedKeyword') -> bool: ...
    def __gt__(self, other: 'ReservedKeyword') -> bool: ...
    def __le__(self, other: 'ReservedKeyword') -> bool: ...
    def __ge__(self, other: 'ReservedKeyword') -> bool: ...

    def _to_python(self) -> test.fixtures.basic.module.thrift_types.ReservedKeyword: ...
    def _to_py3(self) -> ReservedKeyword: ...
    def _to_py_deprecated(self) -> "module.ttypes.ReservedKeyword": ...   # type: ignore

_UnionToBeRenamedValueType = _typing.Union[None, int]

class UnionToBeRenamed(thrift.py3.types.Union, _typing.Hashable):
    class __fbthrift_IsSet:
        reserved_field: bool
        pass

    reserved_field: _typing.Final[int] = ...

    def __init__(
        self, *,
        reserved_field: _typing.Optional[int]=None
    ) -> None: ...

    def __hash__(self) -> int: ...
    def __str__(self) -> str: ...
    def __repr__(self) -> str: ...
    def __lt__(self, other: 'UnionToBeRenamed') -> bool: ...
    def __gt__(self, other: 'UnionToBeRenamed') -> bool: ...
    def __le__(self, other: 'UnionToBeRenamed') -> bool: ...
    def __ge__(self, other: 'UnionToBeRenamed') -> bool: ...

    class Type(_python_std_enum.Enum):
        EMPTY: UnionToBeRenamed.Type = ...
        reserved_field: UnionToBeRenamed.Type = ...

    @staticmethod
    def fromValue(value: _UnionToBeRenamedValueType) -> UnionToBeRenamed: ...
    type: _typing.Final[UnionToBeRenamed.Type]
    value: _typing.Final[_UnionToBeRenamedValueType]
    def get_type(self) -> UnionToBeRenamed.Type: ...

    def _to_python(self) -> test.fixtures.basic.module.thrift_types.UnionToBeRenamed: ...
    def _to_py3(self) -> UnionToBeRenamed: ...
    def _to_py_deprecated(self) -> "module.ttypes.UnionToBeRenamed": ...   # type: ignore

class Set__float(_typing.AbstractSet[float], _typing.Hashable):
    def __init__(self, items: _typing.Optional[_typing.AbstractSet[float]]=None) -> None: ...
    def __len__(self) -> int: ...
    def __hash__(self) -> int: ...
    def __copy__(self) -> _typing.AbstractSet[float]: ...
    def __contains__(self, x: object) -> bool: ...
    def union(self, other: _typing.AbstractSet[float]) -> 'Set__float': ...
    def intersection(self, other: _typing.AbstractSet[float]) -> 'Set__float': ...
    def difference(self, other: _typing.AbstractSet[float]) -> 'Set__float': ...
    def symmetric_difference(self, other: _typing.AbstractSet[float]) -> 'Set__float': ...
    def issubset(self, other: _typing.AbstractSet[float]) -> bool: ...
    def issuperset(self, other: _typing.AbstractSet[float]) -> bool: ...
    def __iter__(self) -> _typing.Iterator[float]: ...


_List__i32T = _typing.TypeVar('_List__i32T', bound=_typing.Sequence[int])


class List__i32(_typing.Sequence[int], _typing.Hashable):
    def __init__(self, items: _typing.Optional[_typing.Sequence[int]]=None) -> None: ...
    def __len__(self) -> int: ...
    def __hash__(self) -> int: ...
    def __copy__(self) -> _typing.Sequence[int]: ...
    @_typing.overload
    def __getitem__(self, i: int) -> int: ...
    @_typing.overload
    def __getitem__(self, s: slice) -> _typing.Sequence[int]: ...
    def __add__(self, other: _typing.Sequence[int]) -> 'List__i32': ...
    def __radd__(self, other: _typing.Sequence[int]) -> 'List__i32': ...
    def __reversed__(self) -> _typing.Iterator[int]: ...
    #pyre-ignore[14]: no idea what pyre is on about
    def __iter__(self) -> _typing.Iterator[int]: ...


class Set__string(_typing.AbstractSet[str], _typing.Hashable):
    def __init__(self, items: _typing.Optional[_typing.AbstractSet[str]]=None) -> None: ...
    def __len__(self) -> int: ...
    def __hash__(self) -> int: ...
    def __copy__(self) -> _typing.AbstractSet[str]: ...
    def __contains__(self, x: object) -> bool: ...
    def union(self, other: _typing.AbstractSet[str]) -> 'Set__string': ...
    def intersection(self, other: _typing.AbstractSet[str]) -> 'Set__string': ...
    def difference(self, other: _typing.AbstractSet[str]) -> 'Set__string': ...
    def symmetric_difference(self, other: _typing.AbstractSet[str]) -> 'Set__string': ...
    def issubset(self, other: _typing.AbstractSet[str]) -> bool: ...
    def issuperset(self, other: _typing.AbstractSet[str]) -> bool: ...
    def __iter__(self) -> _typing.Iterator[str]: ...


class Map__string_i64(_typing.Mapping[str, int], _typing.Hashable):
    def __init__(self, items: _typing.Optional[_typing.Mapping[str, int]]=None) -> None: ...
    def __len__(self) -> int: ...
    def __hash__(self) -> int: ...
    def __copy__(self) -> _typing.Mapping[str, int]: ...
    def __getitem__(self, key: str) -> int: ...
    def __iter__(self) -> _typing.Iterator[str]: ...


class Map__string_List__i32(_typing.Mapping[str, _typing.Sequence[int]], _typing.Hashable):
    def __init__(self, items: _typing.Optional[_typing.Mapping[str, _typing.Sequence[int]]]=None) -> None: ...
    def __len__(self) -> int: ...
    def __hash__(self) -> int: ...
    def __copy__(self) -> _typing.Mapping[str, _typing.Sequence[int]]: ...
    def __getitem__(self, key: str) -> _typing.Sequence[int]: ...
    def __iter__(self) -> _typing.Iterator[str]: ...


FLAG: bool = ...
OFFSET: int = ...
COUNT: int = ...
MASK: int = ...
E: float = ...
DATE: str = ...
AList: List__i32 = ...
ASet: Set__string = ...
AMap: Map__string_List__i32 = ...
MyEnumAlias = MyEnum
MyDataItemAlias = MyDataItem
