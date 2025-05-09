/**
 * Autogenerated by Thrift for thrift/compiler/test/fixtures/complex-union/src/module.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated @nocommit
 */
#pragma once

#include <thrift/lib/cpp2/gen/module_data_h.h>

#include "thrift/compiler/test/fixtures/complex-union/gen-cpp2/module_types.h"

namespace apache { namespace thrift {

template <> struct TEnumDataStorage<::cpp2::ComplexUnion::Type> {
  using type = ::cpp2::ComplexUnion::Type;
  static constexpr const std::size_t size = 6;
  static constexpr std::array<type, size> values = { {
      type::intValue,
      type::stringValue,
      type::intListValue,
      type::stringListValue,
      type::typedefValue,
      type::stringRef,
  }};
  static constexpr std::array<std::string_view, size> names = { {
      "intValue"sv,
      "stringValue"sv,
      "intListValue"sv,
      "stringListValue"sv,
      "typedefValue"sv,
      "stringRef"sv,
  }};
};

template <> struct TEnumDataStorage<::cpp2::ListUnion::Type> {
  using type = ::cpp2::ListUnion::Type;
  static constexpr const std::size_t size = 2;
  static constexpr std::array<type, size> values = { {
      type::intListValue,
      type::stringListValue,
  }};
  static constexpr std::array<std::string_view, size> names = { {
      "intListValue"sv,
      "stringListValue"sv,
  }};
};

template <> struct TEnumDataStorage<::cpp2::DataUnion::Type> {
  using type = ::cpp2::DataUnion::Type;
  static constexpr const std::size_t size = 2;
  static constexpr std::array<type, size> values = { {
      type::binaryData,
      type::stringData,
  }};
  static constexpr std::array<std::string_view, size> names = { {
      "binaryData"sv,
      "stringData"sv,
  }};
};

template <> struct TEnumDataStorage<::cpp2::ValUnion::Type> {
  using type = ::cpp2::ValUnion::Type;
  static constexpr const std::size_t size = 2;
  static constexpr std::array<type, size> values = { {
      type::v1,
      type::v2,
  }};
  static constexpr std::array<std::string_view, size> names = { {
      "v1"sv,
      "v2"sv,
  }};
};

template <> struct TEnumDataStorage<::cpp2::VirtualComplexUnion::Type> {
  using type = ::cpp2::VirtualComplexUnion::Type;
  static constexpr const std::size_t size = 2;
  static constexpr std::array<type, size> values = { {
      type::thingOne,
      type::thingTwo,
  }};
  static constexpr std::array<std::string_view, size> names = { {
      "thingOne"sv,
      "thingTwo"sv,
  }};
};

template <> struct TEnumDataStorage<::cpp2::NonCopyableUnion::Type> {
  using type = ::cpp2::NonCopyableUnion::Type;
  static constexpr const std::size_t size = 1;
  static constexpr std::array<type, size> values = { {
      type::s,
  }};
  static constexpr std::array<std::string_view, size> names = { {
      "s"sv,
  }};
};

template <> struct TStructDataStorage<::cpp2::ComplexUnion> {
  static constexpr const std::size_t fields_size = 6;
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

template <> struct TStructDataStorage<::cpp2::ListUnion> {
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

template <> struct TStructDataStorage<::cpp2::DataUnion> {
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

template <> struct TStructDataStorage<::cpp2::Val> {
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

template <> struct TStructDataStorage<::cpp2::ValUnion> {
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

template <> struct TStructDataStorage<::cpp2::VirtualComplexUnion> {
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

template <> struct TStructDataStorage<::cpp2::NonCopyableStruct> {
  static constexpr const std::size_t fields_size = 1;
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

template <> struct TStructDataStorage<::cpp2::NonCopyableUnion> {
  static constexpr const std::size_t fields_size = 1;
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
