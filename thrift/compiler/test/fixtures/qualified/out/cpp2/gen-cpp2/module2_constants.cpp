/**
 * Autogenerated by Thrift for thrift/compiler/test/fixtures/qualified/src/module2.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated @nocommit
 */

#include "thrift/compiler/test/fixtures/qualified/gen-cpp2/module2_constants.h"

#include <thrift/lib/cpp2/gen/module_constants_cpp.h>

#include "thrift/compiler/test/fixtures/qualified/gen-cpp2/module0_constants.h"
#include "thrift/compiler/test/fixtures/qualified/gen-cpp2/module1_constants.h"

namespace module2 {
namespace module2_constants {

::module2::Struct const& c2() {
  static folly::Indestructible<::module2::Struct> const instance{ ::apache::thrift::detail::make_structured_constant<::module2::Struct>(::apache::thrift::detail::wrap_struct_argument<::apache::thrift::ident::first>(::module0::module0_constants::c0()), ::apache::thrift::detail::wrap_struct_argument<::apache::thrift::ident::second>(::module1::module1_constants::c1())) };
  return *instance;
}

::module2::Struct const& c3() {
  static folly::Indestructible<::module2::Struct> const instance{ ::module2::module2_constants::c2() };
  return *instance;
}

::module2::Struct const& c4() {
  static folly::Indestructible<::module2::Struct> const instance{ ::module2::module2_constants::c2() };
  return *instance;
}


::std::string_view _fbthrift_schema_9188ad030fa5981a() {
  return "";
}
::folly::Range<const ::std::string_view*> _fbthrift_schema_9188ad030fa5981a_includes() {
  return {};
}
::folly::Range<const ::std::string_view*> _fbthrift_schema_9188ad030fa5981a_uris() {
  return {};
}

} // namespace module2_constants
} // namespace module2
