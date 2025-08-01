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

from enum import Enum

class Protocol(Enum):
    BINARY: Protocol = ...
    # Do not use DEPRECATED_VERBOSE_JSON
    DEPRECATED_VERBOSE_JSON: Protocol = ...
    COMPACT: Protocol = ...
    JSON: Protocol = ...

class RpcKind(Enum):
    SINGLE_REQUEST_SINGLE_RESPONSE: RpcKind = ...
    SINGLE_REQUEST_NO_RESPONSE: RpcKind = ...
    SINGLE_REQUEST_STREAMING_RESPONSE: RpcKind = ...
    SINK: RpcKind = ...
