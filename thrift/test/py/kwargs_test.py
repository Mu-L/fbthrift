#!/usr/bin/env python
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

from __future__ import absolute_import, division, print_function, unicode_literals

import unittest

from thrift.test.py.kwargs.ttypes import Bar, Foo


class KwargsTest(unittest.TestCase):
    def test_initializer(self) -> None:
        foo = Foo(
            **{
                "field1": 1,
                "field2": 2,
                "field3": 3,
                "field4": 4,
                "field5": 5,
                "field6": 6,
                "field7": 7,
                "field8": 8,
                "field9": 9,
                "field10": 10,
                "field11": 11,
                "field12": 12,
                "field13": 13,
                "field14": 14,
                "field15": 15,
                "field16": 16,
                "field17": 17,
                "field18": 18,
                "field19": 19,
                "field20": 20,
                "field21": 21,
                "field22": 22,
                "field23": 23,
                "field24": 24,
                "field25": 25,
                "field26": 26,
                "field27": 27,
                "field28": 28,
                "field29": 29,
                "field30": 30,
                "field31": 31,
                "field32": 32,
                "field33": 33,
                "field34": 34,
                "field35": 35,
                "field36": 36,
                "field37": 37,
                "field38": 38,
                "field39": 39,
                "field40": 40,
                "field41": 41,
                "field42": 42,
                "field43": 43,
                "field44": 44,
                "field45": 45,
                "field46": 46,
                "field47": 47,
                "field48": 48,
                "field49": 49,
                "field50": 50,
                "field51": 51,
                "field52": 52,
                "field53": 53,
                "field54": 54,
                "field55": 55,
                "field56": 56,
                "field57": 57,
                "field58": 58,
                "field59": 59,
                "field60": 60,
                "field61": 61,
                "field62": 62,
                "field63": 63,
                "field64": 64,
                "field65": 65,
                "field66": 66,
                "field67": 67,
                "field68": 68,
                "field69": 69,
                "field70": 70,
                "field71": 71,
                "field72": 72,
                "field73": 73,
                "field74": 74,
                "field75": 75,
                "field76": 76,
                "field77": 77,
                "field78": 78,
                "field79": 79,
                "field80": 80,
                "field81": 81,
                "field82": 82,
                "field83": 83,
                "field84": 84,
                "field85": 85,
                "field86": 86,
                "field87": 87,
                "field88": 88,
                "field89": 89,
                "field90": 90,
                "field91": 91,
                "field92": 92,
                "field93": 93,
                "field94": 94,
                "field95": 95,
                "field96": 96,
                "field97": 97,
                "field98": 98,
                "field99": 99,
                "field100": 100,
                "field101": 101,
                "field102": 102,
                "field103": 103,
                "field104": 104,
                "field105": 105,
                "field106": 106,
                "field107": 107,
                "field108": 108,
                "field109": 109,
                "field110": 110,
                "field111": 111,
                "field112": 112,
                "field113": 113,
                "field114": 114,
                "field115": 115,
                "field116": 116,
                "field117": 117,
                "field118": 118,
                "field119": 119,
                "field120": 120,
                "field121": 121,
                "field122": 122,
                "field123": 123,
                "field124": 124,
                "field125": 125,
                "field126": 126,
                "field127": 127,
                "field128": 128,
                "field129": 129,
                "field130": 130,
                "field131": 131,
                "field132": 132,
                "field133": 133,
                "field134": 134,
                "field135": 135,
                "field136": 136,
                "field137": 137,
                "field138": 138,
                "field139": 139,
                "field140": 140,
                "field141": 141,
                "field142": 142,
                "field143": 143,
                "field144": 144,
                "field145": 145,
                "field146": 146,
                "field147": 147,
                "field148": 148,
                "field149": 149,
                "field150": 150,
                "field151": 151,
                "field152": 152,
                "field153": 153,
                "field154": 154,
                "field155": 155,
                "field156": 156,
                "field157": 157,
                "field158": 158,
                "field159": 159,
                "field160": 160,
                "field161": 161,
                "field162": 162,
                "field163": 163,
                "field164": 164,
                "field165": 165,
                "field166": 166,
                "field167": 167,
                "field168": 168,
                "field169": 169,
                "field170": 170,
                "field171": 171,
                "field172": 172,
                "field173": 173,
                "field174": 174,
                "field175": 175,
                "field176": 176,
                "field177": 177,
                "field178": 178,
                "field179": 179,
                "field180": 180,
                "field181": 181,
                "field182": 182,
                "field183": 183,
                "field184": 184,
                "field185": 185,
                "field186": 186,
                "field187": 187,
                "field188": 188,
                "field189": 189,
                "field190": 190,
                "field191": 191,
                "field192": 192,
                "field193": 193,
                "field194": 194,
                "field195": 195,
                "field196": 196,
                "field197": 197,
                "field198": 198,
                "field199": 199,
                "field200": 200,
                "field201": 201,
                "field202": 202,
                "field203": 203,
                "field204": 204,
                "field205": 205,
                "field206": 206,
                "field207": 207,
                "field208": 208,
                "field209": 209,
                "field210": 210,
                "field211": 211,
                "field212": 212,
                "field213": 213,
                "field214": 214,
                "field215": 215,
                "field216": 216,
                "field217": 217,
                "field218": 218,
                "field219": 219,
                "field220": 220,
                "field221": 221,
                "field222": 222,
                "field223": 223,
                "field224": 224,
                "field225": 225,
                "field226": 226,
                "field227": 227,
                "field228": 228,
                "field229": 229,
                "field230": 230,
                "field231": 231,
                "field232": 232,
                "field233": 233,
                "field234": 234,
                "field235": 235,
                "field236": 236,
                "field237": 237,
                "field238": 238,
                "field239": 239,
                "field240": 240,
                "field241": 241,
                "field242": 242,
                "field243": 243,
                "field244": 244,
                "field245": 245,
                "field246": 246,
                "field247": 247,
                "field248": 248,
                "field249": 249,
                "field250": 250,
                "field251": 251,
                "field252": 252,
                "field253": 253,
                "field254": 254,
                "field255": 255,
                "field256": 256,
            }
        )
        self.assertEqual(255, foo.field255)
        self.assertEqual(256, foo.field256)

        foo = Foo(field256=512)
        self.assertEqual(512, foo.field256)

    def test_unexpected_argument(self) -> None:
        with self.assertRaises(TypeError):
            # pyre-ignore[28]:Unexpected keyword argument `field257`
            Foo(field257=257)

    def test_default_value(self) -> None:
        foo = Foo()
        self.assertEqual(1024, foo.field42)

    def test_compiler_options(self) -> None:
        # pyre didnt complain because we enabled the compiler opetion of "enable_pos_args" in buck file
        Bar(1, 2, 3)


if __name__ == "__main__":
    unittest.main()
