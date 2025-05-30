/**
 * Autogenerated by Thrift for thrift/compiler/test/fixtures/mcpp2-compare/src/includes.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated @nocommit
 */
#include "thrift/compiler/test/fixtures/mcpp2-compare/gen-cpp2/includes_types.h"
#include "thrift/compiler/test/fixtures/mcpp2-compare/gen-cpp2/includes_types.tcc"

#include <thrift/lib/cpp2/gen/module_types_cpp.h>

#include "thrift/compiler/test/fixtures/mcpp2-compare/gen-cpp2/includes_data.h"
[[maybe_unused]] static constexpr std::string_view kModuleName = "includes";


namespace apache { namespace thrift {

const std::string_view TEnumTraits<::a::different::ns::AnEnum>::__fbthrift_module_name_internal_do_not_use = kModuleName;
folly::Range<::a::different::ns::AnEnum const*> const TEnumTraits<::a::different::ns::AnEnum>::values = folly::range(TEnumDataStorage<::a::different::ns::AnEnum>::values);
folly::Range<std::string_view const*> const TEnumTraits<::a::different::ns::AnEnum>::names = folly::range(TEnumDataStorage<::a::different::ns::AnEnum>::names);

bool TEnumTraits<::a::different::ns::AnEnum>::findName(type value, std::string_view* out) noexcept {
  return ::apache::thrift::detail::st::enum_find_name(value, out);
}

bool TEnumTraits<::a::different::ns::AnEnum>::findValue(std::string_view name, type* out) noexcept {
  return ::apache::thrift::detail::st::enum_find_value(name, out);
}

}} // apache::thrift


namespace apache {
namespace thrift {
namespace detail {

void TccStructTraits<::a::different::ns::AStruct>::translateFieldName(
    std::string_view _fname,
    int16_t& fid,
    apache::thrift::protocol::TType& _ftype) noexcept {
  using data = apache::thrift::TStructDataStorage<::a::different::ns::AStruct>;
  static const st::translate_field_name_table table{
      data::fields_size,
      data::fields_names.data(),
      data::fields_ids.data(),
      data::fields_types.data()};
  st::translate_field_name(_fname, fid, _ftype, table);
}

} // namespace detail
} // namespace thrift
} // namespace apache

namespace a::different::ns {

std::string_view AStruct::__fbthrift_get_field_name(::apache::thrift::FieldOrdinal ord) {
  if (ord == ::apache::thrift::FieldOrdinal{0}) { return {}; }
  return apache::thrift::TStructDataStorage<AStruct>::fields_names[folly::to_underlying(ord) - 1];
}
std::string_view AStruct::__fbthrift_get_class_name() {
  return apache::thrift::TStructDataStorage<AStruct>::name;
}


AStruct::AStruct(apache::thrift::FragileConstructor, ::std::int32_t FieldA__arg) :
    __fbthrift_field_FieldA(std::move(FieldA__arg)) { 
  __isset.set(folly::index_constant<0>(), true);
}


void AStruct::__fbthrift_clear() {
  // clear all fields
  this->__fbthrift_field_FieldA = ::std::int32_t();
  __isset = {};
}

void AStruct::__fbthrift_clear_terse_fields() {
}

bool AStruct::__fbthrift_is_empty() const {
  return false;
}

bool AStruct::operator==([[maybe_unused]] const AStruct& rhs) const {
  return ::apache::thrift::op::detail::StructEquality{}(*this, rhs);
}

bool AStruct::operator<([[maybe_unused]] const AStruct& rhs) const {
  return ::apache::thrift::op::detail::StructLessThan{}(*this, rhs);
}


::std::int32_t AStruct::get_FieldA() const {
  return __fbthrift_field_FieldA;
}

::std::int32_t& AStruct::set_FieldA(::std::int32_t FieldA_) {
  FieldA_ref() = FieldA_;
  return __fbthrift_field_FieldA;
}

void swap([[maybe_unused]] AStruct& a, [[maybe_unused]] AStruct& b) {
  using ::std::swap;
  swap(a.__fbthrift_field_FieldA, b.__fbthrift_field_FieldA);
  swap(a.__isset, b.__isset);
}

template void AStruct::readNoXfer<>(apache::thrift::SimpleJSONProtocolReader*);
template uint32_t AStruct::write<>(apache::thrift::SimpleJSONProtocolWriter*) const;
template uint32_t AStruct::serializedSize<>(apache::thrift::SimpleJSONProtocolWriter const*) const;
template uint32_t AStruct::serializedSizeZC<>(apache::thrift::SimpleJSONProtocolWriter const*) const;


} // namespace a::different::ns

namespace apache {
namespace thrift {
namespace detail {

void TccStructTraits<::a::different::ns::AStructB>::translateFieldName(
    std::string_view _fname,
    int16_t& fid,
    apache::thrift::protocol::TType& _ftype) noexcept {
  using data = apache::thrift::TStructDataStorage<::a::different::ns::AStructB>;
  static const st::translate_field_name_table table{
      data::fields_size,
      data::fields_names.data(),
      data::fields_ids.data(),
      data::fields_types.data()};
  st::translate_field_name(_fname, fid, _ftype, table);
}

} // namespace detail
} // namespace thrift
} // namespace apache

namespace a::different::ns {

std::string_view AStructB::__fbthrift_get_field_name(::apache::thrift::FieldOrdinal ord) {
  if (ord == ::apache::thrift::FieldOrdinal{0}) { return {}; }
  return apache::thrift::TStructDataStorage<AStructB>::fields_names[folly::to_underlying(ord) - 1];
}
std::string_view AStructB::__fbthrift_get_class_name() {
  return apache::thrift::TStructDataStorage<AStructB>::name;
}

AStructB::AStructB(const AStructB&) = default;
AStructB& AStructB::operator=(const AStructB&) = default;
AStructB::AStructB() :
    __fbthrift_field_FieldA(std::make_shared<::a::different::ns::AStruct>()) {
}


AStructB::~AStructB() {}

AStructB::AStructB([[maybe_unused]] AStructB&& other) noexcept :
    __fbthrift_field_FieldA(std::move(other.__fbthrift_field_FieldA)) {
}

AStructB& AStructB::operator=([[maybe_unused]] AStructB&& other) noexcept {
    this->__fbthrift_field_FieldA = std::move(other.__fbthrift_field_FieldA);
    return *this;
}


AStructB::AStructB(apache::thrift::FragileConstructor, ::std::shared_ptr<const ::a::different::ns::AStruct> FieldA__arg) :
    __fbthrift_field_FieldA(std::move(FieldA__arg)) { 
}


void AStructB::__fbthrift_clear() {
  // clear all fields
  if (this->__fbthrift_field_FieldA) this->__fbthrift_field_FieldA = ::apache::thrift::detail::make_mutable_smart_ptr<::std::shared_ptr<const ::a::different::ns::AStruct>>();
}

void AStructB::__fbthrift_clear_terse_fields() {
}

bool AStructB::__fbthrift_is_empty() const {
  return false;
}

bool AStructB::operator==([[maybe_unused]] const AStructB& rhs) const {
  return ::apache::thrift::op::detail::StructEquality{}(*this, rhs);
}

bool AStructB::operator<([[maybe_unused]] const AStructB& rhs) const {
  return ::apache::thrift::op::detail::StructLessThan{}(*this, rhs);
}


void swap([[maybe_unused]] AStructB& a, [[maybe_unused]] AStructB& b) {
  using ::std::swap;
  swap(a.__fbthrift_field_FieldA, b.__fbthrift_field_FieldA);
}

template void AStructB::readNoXfer<>(apache::thrift::SimpleJSONProtocolReader*);
template uint32_t AStructB::write<>(apache::thrift::SimpleJSONProtocolWriter*) const;
template uint32_t AStructB::serializedSize<>(apache::thrift::SimpleJSONProtocolWriter const*) const;
template uint32_t AStructB::serializedSizeZC<>(apache::thrift::SimpleJSONProtocolWriter const*) const;

static_assert(
    ::apache::thrift::detail::st::gen_check_json<
        AStructB,
        ::apache::thrift::type_class::structure,
        ::a::different::ns::AStruct>,
    "inconsistent use of json option");

} // namespace a::different::ns

namespace a::different::ns { namespace {
[[maybe_unused]] FOLLY_ERASE void validateAdapters() {
}
}} // namespace a::different::ns
namespace apache::thrift::detail::annotation {
}
