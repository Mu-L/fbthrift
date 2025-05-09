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

#include <gtest/gtest.h>

#include <folly/io/IOBuf.h>
#include <thrift/lib/cpp2/transport/rocket/framing/parser/FrameLengthParserStrategy.h>
#include <thrift/lib/cpp2/transport/rocket/framing/parser/ParserStrategy.h>
#include <thrift/lib/cpp2/transport/rocket/framing/parser/test/TestUtil.h>

namespace apache::thrift::rocket {

TEST(ParserTest, testAppendFrame) {
  FakeOwner owner;
  ParserStrategy<FakeOwner, FrameLengthParserStrategy> parser(owner);

  void* buf;
  size_t lenReturn;
  parser.getReadBuffer(&buf, &lenReturn);

  HeaderSerializer serializer(static_cast<uint8_t*>(buf), lenReturn);
  serializer.writeFrameOrMetadataSize(20);
  std::string b(20, 'b');
  memcpy(&static_cast<uint8_t*>(buf)[3], b.data(), 20);

  parser.readDataAvailable(23);

  EXPECT_EQ(owner.memoryCounter_, 0);
  EXPECT_EQ(owner.frames_.size(), 1);

  auto frame = std::move(owner.frames_[0]);
  EXPECT_EQ(frame->length(), 20);
}

TEST(ParserTest, testAppendLessThanFullFrame) {
  FakeOwner owner;
  ParserStrategy<FakeOwner, FrameLengthParserStrategy> parser(owner);

  void* buf;
  size_t lenReturn;
  parser.getReadBuffer(&buf, &lenReturn);

  HeaderSerializer serializer(static_cast<uint8_t*>(buf), lenReturn);
  serializer.writeFrameOrMetadataSize(20);
  std::string b(20, 'b');
  memcpy(&static_cast<uint8_t*>(buf)[3], b.data(), 20);

  parser.readDataAvailable(10);

  EXPECT_EQ(owner.memoryCounter_, 23);
  EXPECT_EQ(owner.frames_.size(), 0);
}

} // namespace apache::thrift::rocket
