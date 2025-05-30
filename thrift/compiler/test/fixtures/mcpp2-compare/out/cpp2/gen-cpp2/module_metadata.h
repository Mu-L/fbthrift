/**
 * Autogenerated by Thrift for thrift/compiler/test/fixtures/mcpp2-compare/src/module.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated @nocommit
 */
#pragma once

#include <vector>

#include <thrift/lib/cpp2/gen/module_metadata_h.h>
#include "thrift/compiler/test/fixtures/mcpp2-compare/gen-cpp2/module_types.h"
#include "thrift/compiler/test/fixtures/mcpp2-compare/gen-cpp2/includes_metadata.h"

namespace some::valid::ns {
class EmptyService;
} // namespace some::valid::ns
namespace some::valid::ns {
class ReturnService;
} // namespace some::valid::ns
namespace some::valid::ns {
class ParamService;
} // namespace some::valid::ns

namespace apache {
namespace thrift {
namespace detail {
namespace md {

template <>
class EnumMetadata<::some::valid::ns::MyEnumA> {
 public:
  static void gen(ThriftMetadata& metadata);
};
template <>
class EnumMetadata<::some::valid::ns::AnnotatedEnum> {
 public:
  static void gen(ThriftMetadata& metadata);
};
template <>
class EnumMetadata<::some::valid::ns::AnnotatedEnum2> {
 public:
  static void gen(ThriftMetadata& metadata);
};
template <>
class EnumMetadata<::some::valid::ns::MyEnumB> {
 public:
  static void gen(ThriftMetadata& metadata);
};
template <>
class StructMetadata<::some::valid::ns::Empty> {
 public:
  static const ::apache::thrift::metadata::ThriftStruct& gen(ThriftMetadata& metadata);
};
template <>
class StructMetadata<::some::valid::ns::ASimpleStruct> {
 public:
  static const ::apache::thrift::metadata::ThriftStruct& gen(ThriftMetadata& metadata);
};
template <>
class StructMetadata<::some::valid::ns::ASimpleStructNoexcept> {
 public:
  static const ::apache::thrift::metadata::ThriftStruct& gen(ThriftMetadata& metadata);
};
template <>
class StructMetadata<::some::valid::ns::MyStruct> {
 public:
  static const ::apache::thrift::metadata::ThriftStruct& gen(ThriftMetadata& metadata);
};
template <>
class StructMetadata<::some::valid::ns::SimpleUnion> {
 public:
  static const ::apache::thrift::metadata::ThriftStruct& gen(ThriftMetadata& metadata);
};
template <>
class StructMetadata<::some::valid::ns::ComplexUnion> {
 public:
  static const ::apache::thrift::metadata::ThriftStruct& gen(ThriftMetadata& metadata);
};
template <>
class StructMetadata<::some::valid::ns::AnException> {
 public:
  static const ::apache::thrift::metadata::ThriftStruct& gen(ThriftMetadata& metadata);
};
template <>
class StructMetadata<::some::valid::ns::AnotherException> {
 public:
  static const ::apache::thrift::metadata::ThriftStruct& gen(ThriftMetadata& metadata);
};
template <>
class StructMetadata<::some::valid::ns::containerStruct> {
 public:
  static const ::apache::thrift::metadata::ThriftStruct& gen(ThriftMetadata& metadata);
};
template <>
class StructMetadata<::some::valid::ns::MyIncludedStruct> {
 public:
  static const ::apache::thrift::metadata::ThriftStruct& gen(ThriftMetadata& metadata);
};
template <>
class StructMetadata<::some::valid::ns::AnnotatedStruct> {
 public:
  static const ::apache::thrift::metadata::ThriftStruct& gen(ThriftMetadata& metadata);
};
template <>
class StructMetadata<::some::valid::ns::ComplexContainerStruct> {
 public:
  static const ::apache::thrift::metadata::ThriftStruct& gen(ThriftMetadata& metadata);
};
template <>
class StructMetadata<::some::valid::ns::FloatStruct> {
 public:
  static const ::apache::thrift::metadata::ThriftStruct& gen(ThriftMetadata& metadata);
};
template <>
class StructMetadata<::some::valid::ns::FloatUnion> {
 public:
  static const ::apache::thrift::metadata::ThriftStruct& gen(ThriftMetadata& metadata);
};
template <>
class StructMetadata<::some::valid::ns::AllRequiredNoExceptMoveCtrStruct> {
 public:
  static const ::apache::thrift::metadata::ThriftStruct& gen(ThriftMetadata& metadata);
};
template <>
class ExceptionMetadata<::some::valid::ns::AnException> {
 public:
  static void gen(ThriftMetadata& metadata);
};
template <>
class ExceptionMetadata<::some::valid::ns::AnotherException> {
 public:
  static void gen(ThriftMetadata& metadata);
};
template <>
class ServiceMetadata<::apache::thrift::ServiceHandler<::some::valid::ns::EmptyService>> {
 public:
  static void gen(ThriftServiceMetadataResponse& response);
 private:
  static const ThriftServiceContextRef* genRecurse(ThriftMetadata& metadata, std::vector<ThriftServiceContextRef>& services);

  template <typename T>
  friend class ServiceMetadata;

};
template <>
class ServiceMetadata<::apache::thrift::ServiceHandler<::some::valid::ns::ReturnService>> {
 public:
  static void gen(ThriftServiceMetadataResponse& response);
 private:
  static const ThriftServiceContextRef* genRecurse(ThriftMetadata& metadata, std::vector<ThriftServiceContextRef>& services);

  template <typename T>
  friend class ServiceMetadata;

  static void gen_noReturn(ThriftMetadata& metadata, ThriftService& context);
  static void gen_boolReturn(ThriftMetadata& metadata, ThriftService& context);
  static void gen_i16Return(ThriftMetadata& metadata, ThriftService& context);
  static void gen_i32Return(ThriftMetadata& metadata, ThriftService& context);
  static void gen_i64Return(ThriftMetadata& metadata, ThriftService& context);
  static void gen_floatReturn(ThriftMetadata& metadata, ThriftService& context);
  static void gen_doubleReturn(ThriftMetadata& metadata, ThriftService& context);
  static void gen_stringReturn(ThriftMetadata& metadata, ThriftService& context);
  static void gen_binaryReturn(ThriftMetadata& metadata, ThriftService& context);
  static void gen_mapReturn(ThriftMetadata& metadata, ThriftService& context);
  static void gen_simpleTypedefReturn(ThriftMetadata& metadata, ThriftService& context);
  static void gen_complexTypedefReturn(ThriftMetadata& metadata, ThriftService& context);
  static void gen_list_mostComplexTypedefReturn(ThriftMetadata& metadata, ThriftService& context);
  static void gen_enumReturn(ThriftMetadata& metadata, ThriftService& context);
  static void gen_list_EnumReturn(ThriftMetadata& metadata, ThriftService& context);
  static void gen_structReturn(ThriftMetadata& metadata, ThriftService& context);
  static void gen_set_StructReturn(ThriftMetadata& metadata, ThriftService& context);
  static void gen_unionReturn(ThriftMetadata& metadata, ThriftService& context);
  static void gen_list_UnionReturn(ThriftMetadata& metadata, ThriftService& context);
  static void gen_readDataEb(ThriftMetadata& metadata, ThriftService& context);
  static void gen_readData(ThriftMetadata& metadata, ThriftService& context);
};
template <>
class ServiceMetadata<::apache::thrift::ServiceHandler<::some::valid::ns::ParamService>> {
 public:
  static void gen(ThriftServiceMetadataResponse& response);
 private:
  static const ThriftServiceContextRef* genRecurse(ThriftMetadata& metadata, std::vector<ThriftServiceContextRef>& services);

  template <typename T>
  friend class ServiceMetadata;

  static void gen_void_ret_i16_param(ThriftMetadata& metadata, ThriftService& context);
  static void gen_void_ret_byte_i16_param(ThriftMetadata& metadata, ThriftService& context);
  static void gen_void_ret_map_param(ThriftMetadata& metadata, ThriftService& context);
  static void gen_void_ret_map_setlist_param(ThriftMetadata& metadata, ThriftService& context);
  static void gen_void_ret_map_typedef_param(ThriftMetadata& metadata, ThriftService& context);
  static void gen_void_ret_enum_param(ThriftMetadata& metadata, ThriftService& context);
  static void gen_void_ret_struct_param(ThriftMetadata& metadata, ThriftService& context);
  static void gen_void_ret_listunion_param(ThriftMetadata& metadata, ThriftService& context);
  static void gen_bool_ret_i32_i64_param(ThriftMetadata& metadata, ThriftService& context);
  static void gen_bool_ret_map_param(ThriftMetadata& metadata, ThriftService& context);
  static void gen_bool_ret_union_param(ThriftMetadata& metadata, ThriftService& context);
  static void gen_i64_ret_float_double_param(ThriftMetadata& metadata, ThriftService& context);
  static void gen_i64_ret_string_typedef_param(ThriftMetadata& metadata, ThriftService& context);
  static void gen_i64_ret_i32_i32_i32_i32_i32_param(ThriftMetadata& metadata, ThriftService& context);
  static void gen_double_ret_setstruct_param(ThriftMetadata& metadata, ThriftService& context);
  static void gen_string_ret_string_param(ThriftMetadata& metadata, ThriftService& context);
  static void gen_binary_ret_binary_param(ThriftMetadata& metadata, ThriftService& context);
  static void gen_map_ret_bool_param(ThriftMetadata& metadata, ThriftService& context);
  static void gen_list_ret_map_setlist_param(ThriftMetadata& metadata, ThriftService& context);
  static void gen_mapsetlistmapliststring_ret_listlistlist_param(ThriftMetadata& metadata, ThriftService& context);
  static void gen_typedef_ret_i32_param(ThriftMetadata& metadata, ThriftService& context);
  static void gen_listtypedef_ret_typedef_param(ThriftMetadata& metadata, ThriftService& context);
  static void gen_enum_ret_double_param(ThriftMetadata& metadata, ThriftService& context);
  static void gen_enum_ret_double_enum_param(ThriftMetadata& metadata, ThriftService& context);
  static void gen_listenum_ret_map_param(ThriftMetadata& metadata, ThriftService& context);
  static void gen_struct_ret_i16_param(ThriftMetadata& metadata, ThriftService& context);
  static void gen_setstruct_ret_set_param(ThriftMetadata& metadata, ThriftService& context);
  static void gen_union_ret_i32_i32_param(ThriftMetadata& metadata, ThriftService& context);
  static void gen_listunion_string_param(ThriftMetadata& metadata, ThriftService& context);
};
} // namespace md
} // namespace detail
} // namespace thrift
} // namespace apache
