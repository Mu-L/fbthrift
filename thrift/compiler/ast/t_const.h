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

#pragma once

#include <memory>

#include <thrift/compiler/ast/t_const_value.h>
#include <thrift/compiler/ast/t_named.h>
#include <thrift/compiler/ast/t_type.h>

namespace apache::thrift::compiler {

class t_program;

/**
 * Represents a const definition.
 *
 * A const definition introduces a named constant in target languages that has
 * a type and a value. The trick here is that the declared type might not match
 * the type of the value object, since that is not determined until after
 * parsing the whole thing out.
 */
class t_const final : public t_named {
 public:
  /**
   * Constructor for t_const
   *
   * @param program  - An entire thrift program
   * @param type_ref - A thrift type
   * @param name     - The name of the constant variable
   * @param value    - The constant value
   */
  t_const(
      const t_program* program,
      t_type_ref type_ref,
      std::string name,
      std::unique_ptr<t_const_value> value)
      : t_named(program, std::move(name)),
        type_ref_(std::move(type_ref)),
        value_(std::move(value)) {
    // value->get_owner() is set when rhs is referencing another constant.
    if (value_ && value_->get_owner() == nullptr) {
      value_->set_owner(this);
    }
  }

  ~t_const() override;

  const t_type* type() const { return type_ref_.get_type(); }

  t_type_ref type_ref() const { return type_ref_; }
  t_type_ref& type_ref() { return type_ref_; }

  const t_const_value* value() const { return value_.get(); }
  t_const_value* value() { return value_.get(); }

  const t_const_value& get_value_from_structured_annotation(
      const char* key) const;
  const t_const_value* get_value_from_structured_annotation_or_null(
      const char* key) const;

  std::unique_ptr<t_const> clone() const {
    return std::make_unique<t_const>(
        program(), type_ref(), name(), value_->clone());
  }

 private:
  t_type_ref type_ref_;

  std::unique_ptr<t_const_value> value_;
};

} // namespace apache::thrift::compiler
