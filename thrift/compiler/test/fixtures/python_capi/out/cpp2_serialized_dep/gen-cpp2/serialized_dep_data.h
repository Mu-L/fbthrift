/**
 * Autogenerated by Thrift for thrift/compiler/test/fixtures/python_capi/src/serialized_dep.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated @nocommit
 */
#pragma once

#include <thrift/lib/cpp2/gen/module_data_h.h>

#include "thrift/compiler/test/fixtures/python_capi/gen-cpp2/serialized_dep_types.h"

namespace apache { namespace thrift {

template <> struct TEnumDataStorage<::test::fixtures::python_capi::SerializedUnion::Type> {
  using type = ::test::fixtures::python_capi::SerializedUnion::Type;
  static constexpr const std::size_t size = 2;
  static constexpr std::array<type, size> values = { {
      type::s,
      type::i,
  }};
  static constexpr std::array<std::string_view, size> names = { {
      "s"sv,
      "i"sv,
  }};
};

template <> struct TEnumDataStorage<::test::fixtures::python_capi::MarshalUnion::Type> {
  using type = ::test::fixtures::python_capi::MarshalUnion::Type;
  static constexpr const std::size_t size = 2;
  static constexpr std::array<type, size> values = { {
      type::s,
      type::i,
  }};
  static constexpr std::array<std::string_view, size> names = { {
      "s"sv,
      "i"sv,
  }};
};

template <> struct TStructDataStorage<::test::fixtures::python_capi::SerializedStruct> {
  static constexpr const std::size_t fields_size = 4;
  static const std::string_view name;
  static const std::array<std::string_view, fields_size> fields_names;
  static const std::array<int16_t, fields_size> fields_ids;
  static const std::array<protocol::TType, fields_size> fields_types;

 private:
  // The following fields describe internal storage metadata, and are private to
  // prevent user logic from accessing them, but they can be inspected by
  // debuggers.
  // -1 if the field has no isset.
  static const std::array<int, fields_size> isset_indexes;
};

template <> struct TStructDataStorage<::test::fixtures::python_capi::SerializedUnion> {
  static constexpr const std::size_t fields_size = 2;
  static const std::string_view name;
  static const std::array<std::string_view, fields_size> fields_names;
  static const std::array<int16_t, fields_size> fields_ids;
  static const std::array<protocol::TType, fields_size> fields_types;

 private:
  // The following fields describe internal storage metadata, and are private to
  // prevent user logic from accessing them, but they can be inspected by
  // debuggers.
  // -1 if the field has no isset.
  static const std::array<int, fields_size> isset_indexes;
};

template <> struct TStructDataStorage<::test::fixtures::python_capi::SerializedError> {
  static constexpr const std::size_t fields_size = 3;
  static const std::string_view name;
  static const std::array<std::string_view, fields_size> fields_names;
  static const std::array<int16_t, fields_size> fields_ids;
  static const std::array<protocol::TType, fields_size> fields_types;

 private:
  // The following fields describe internal storage metadata, and are private to
  // prevent user logic from accessing them, but they can be inspected by
  // debuggers.
  // -1 if the field has no isset.
  static const std::array<int, fields_size> isset_indexes;
};

template <> struct TStructDataStorage<::test::fixtures::python_capi::MarshalStruct> {
  static constexpr const std::size_t fields_size = 4;
  static const std::string_view name;
  static const std::array<std::string_view, fields_size> fields_names;
  static const std::array<int16_t, fields_size> fields_ids;
  static const std::array<protocol::TType, fields_size> fields_types;

 private:
  // The following fields describe internal storage metadata, and are private to
  // prevent user logic from accessing them, but they can be inspected by
  // debuggers.
  // -1 if the field has no isset.
  static const std::array<int, fields_size> isset_indexes;
};

template <> struct TStructDataStorage<::test::fixtures::python_capi::MarshalUnion> {
  static constexpr const std::size_t fields_size = 2;
  static const std::string_view name;
  static const std::array<std::string_view, fields_size> fields_names;
  static const std::array<int16_t, fields_size> fields_ids;
  static const std::array<protocol::TType, fields_size> fields_types;

 private:
  // The following fields describe internal storage metadata, and are private to
  // prevent user logic from accessing them, but they can be inspected by
  // debuggers.
  // -1 if the field has no isset.
  static const std::array<int, fields_size> isset_indexes;
};

template <> struct TStructDataStorage<::test::fixtures::python_capi::MarshalError> {
  static constexpr const std::size_t fields_size = 3;
  static const std::string_view name;
  static const std::array<std::string_view, fields_size> fields_names;
  static const std::array<int16_t, fields_size> fields_ids;
  static const std::array<protocol::TType, fields_size> fields_types;

 private:
  // The following fields describe internal storage metadata, and are private to
  // prevent user logic from accessing them, but they can be inspected by
  // debuggers.
  // -1 if the field has no isset.
  static const std::array<int, fields_size> isset_indexes;
};

}} // apache::thrift
