# Copyright (c) Meta Platforms, Inc. and affiliates.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

# pyre-strict

import unittest

from testing.a.types import Foo, Mixin3, Union
from testing.b.types import Mixin1, Mixin2


class MixinTest(unittest.TestCase):
    def make_foo(self) -> Foo:
        return Foo(
            field4="4",
            m2=Mixin2(
                m1=Mixin1(
                    field1="1",
                )
            ),
            m3=Mixin3(
                field3="3",
            ),
            u=Union(
                field5="5",
            ),
        )

    def test_foo_basic(self) -> None:
        foo = self.make_foo()
        self.assertEqual(foo.field4, "4")

    def test_foo_mixin_python_compat(self) -> None:
        foo = self.make_foo()
        self.assertIsNone(foo.m2.field2)
        self.assertEqual(foo.m2.m1.field1, "1")
        self.assertEqual(foo.m3.field3, "3")
        self.assertEqual(foo.u.field5, "5")
