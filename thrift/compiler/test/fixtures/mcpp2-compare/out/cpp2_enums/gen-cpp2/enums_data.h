/**
 * Autogenerated by Thrift for thrift/compiler/test/fixtures/mcpp2-compare/src/enums.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated @nocommit
 */
#pragma once

#include <thrift/lib/cpp2/gen/module_data_h.h>

#include "thrift/compiler/test/fixtures/mcpp2-compare/gen-cpp2/enums_types.h"

namespace apache { namespace thrift {

template <> struct TEnumDataStorage<::facebook::ns::qwerty::AnEnumA> {
  using type = ::facebook::ns::qwerty::AnEnumA;
  static constexpr const std::size_t size = 1;
  static constexpr std::array<type, size> values = { {
      type::FIELDA,
  }};
  static constexpr std::array<std::string_view, size> names = { {
      "FIELDA"sv,
  }};
};

template <> struct TEnumDataStorage<::facebook::ns::qwerty::AnEnumB> {
  using type = ::facebook::ns::qwerty::AnEnumB;
  static constexpr const std::size_t size = 2;
  static constexpr std::array<type, size> values = { {
      type::FIELDA,
      type::FIELDB,
  }};
  static constexpr std::array<std::string_view, size> names = { {
      "FIELDA"sv,
      "FIELDB"sv,
  }};
};

template <> struct TEnumDataStorage<::facebook::ns::qwerty::AnEnumC> {
  using type = ::facebook::ns::qwerty::AnEnumC;
  static constexpr const std::size_t size = 1;
  static constexpr std::array<type, size> values = { {
      type::FIELDC,
  }};
  static constexpr std::array<std::string_view, size> names = { {
      "FIELDC"sv,
  }};
};

template <> struct TEnumDataStorage<::facebook::ns::qwerty::AnEnumD> {
  using type = ::facebook::ns::qwerty::AnEnumD;
  static constexpr const std::size_t size = 1;
  static constexpr std::array<type, size> values = { {
      type::FIELDD,
  }};
  static constexpr std::array<std::string_view, size> names = { {
      "FIELDD"sv,
  }};
};

template <> struct TEnumDataStorage<::facebook::ns::qwerty::AnEnumE> {
  using type = ::facebook::ns::qwerty::AnEnumE;
  static constexpr const std::size_t size = 1;
  static constexpr std::array<type, size> values = { {
      type::FIELDA,
  }};
  static constexpr std::array<std::string_view, size> names = { {
      "FIELDA"sv,
  }};
};

template <> struct TStructDataStorage<::facebook::ns::qwerty::SomeStruct> {
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
