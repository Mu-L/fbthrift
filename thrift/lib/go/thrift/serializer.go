/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

package thrift

import (
	"github.com/facebook/fbthrift/thrift/lib/go/thrift/types"
)

// A Serializer is used to turn a Struct in to a byte stream
type Serializer struct {
	Transport *MemoryBuffer
	Protocol  types.Encoder
}

// NewSerializer create a new serializer using the binary protocol
func NewSerializer() *Serializer {
	transport := NewMemoryBufferLen(1024)
	protocol := NewBinaryFormat(transport)
	return &Serializer{transport, protocol}
}

// NewCompactSerializer creates a new serializer using the compact protocol
func NewCompactSerializer() *Serializer {
	transport := NewMemoryBufferLen(1024)
	protocol := NewCompactProtocol(transport)
	return &Serializer{transport, protocol}
}

func serializeCompact(msg types.Struct) ([]byte, error) {
	return NewCompactSerializer().Write(msg)
}

// NewJSONSerializer creates a new serializer using the JSON protocol
func NewJSONSerializer() *Serializer {
	transport := NewMemoryBufferLen(1024)
	protocol := NewJSONProtocol(transport)
	return &Serializer{transport, protocol}
}

// NewSimpleJSONSerializer creates a new serializer using the SimpleJSON protocol
func NewSimpleJSONSerializer() *Serializer {
	transport := NewMemoryBufferLen(1024)
	protocol := NewSimpleJSONProtocol(transport)
	return &Serializer{transport, protocol}
}

// WriteString writes msg to the serializer and returns it as a string
func (s *Serializer) WriteString(msg types.Struct) (str string, err error) {
	s.Transport.Reset()

	if err = msg.Write(s.Protocol); err != nil {
		return
	}

	if err = s.Protocol.Flush(); err != nil {
		return
	}

	return s.Transport.String(), nil
}

// Write writes msg to the serializer and returns it as a byte array
func (s *Serializer) Write(msg types.Struct) (b []byte, err error) {
	s.Transport.Reset()

	if err = msg.Write(s.Protocol); err != nil {
		return
	}

	if err = s.Protocol.Flush(); err != nil {
		return
	}

	b = append(b, s.Transport.Bytes()...)
	return
}
