
/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT
 *  @generated
 *
 */

#include <folly/python/import.h>
#include <thrift/lib/python/capi/iobuf.h>
#include <thrift/lib/python/types.h>

#include <thrift/compiler/test/fixtures/namespace/gen-python-capi/emptyns/thrift_types_api.h>
#include <thrift/compiler/test/fixtures/namespace/gen-python-capi/emptyns/thrift_types_capi.h>


namespace apache::thrift::python::capi {
namespace {
bool ensure_module_imported() {
  static ::folly::python::import_cache_nocapture import((
      ::import_emptyns__thrift_types_capi));
  return import();
}
  static constexpr std::int16_t _fbthrift__Foo__tuple_pos[1] = {
    1
  };
} // namespace

ExtractorResult<::cpp2::Foo>
Extractor<::apache::thrift::python::capi::PythonNamespaced<::cpp2::Foo, ::emptyns::NamespaceTag>>::operator()(PyObject* obj) {
  int tCheckResult = typeCheck(obj);
  if (tCheckResult != 1) {
      if (tCheckResult == 0) {
        PyErr_SetString(PyExc_TypeError, "Not a Foo");
      }
      return extractorError<::cpp2::Foo>(
          "Marshal error: Foo");
  }
  StrongRef fbThriftData(getThriftData(obj));
  return Extractor<::apache::thrift::python::capi::ComposedStruct<
      ::cpp2::Foo, ::emptyns::NamespaceTag>>{}(*fbThriftData);
}

ExtractorResult<::cpp2::Foo>
Extractor<::apache::thrift::python::capi::ComposedStruct<
    ::cpp2::Foo, ::emptyns::NamespaceTag>>::operator()(PyObject* fbThriftData) {
  ::cpp2::Foo cpp;
  std::optional<std::string_view> error;
  Extractor<int64_t>{}.extractInto(
      cpp.MyInt_ref(),
      PyTuple_GET_ITEM(fbThriftData, _fbthrift__Foo__tuple_pos[0]),
      error);
  if (error) {
    return folly::makeUnexpected(*error);
  }
  return cpp;
}


int Extractor<::apache::thrift::python::capi::PythonNamespaced<::cpp2::Foo, ::emptyns::NamespaceTag>>::typeCheck(PyObject* obj) {
  if (!ensure_module_imported()) {
    ::folly::python::handlePythonError(
      "Module emptyns import error");
  }
  int result =
      can_extract__emptyns__Foo(obj);
  if (result < 0) {
    ::folly::python::handlePythonError(
      "Unexpected type check error: Foo");
  }
  return result;
}


PyObject* Constructor<::apache::thrift::python::capi::PythonNamespaced<::cpp2::Foo, ::emptyns::NamespaceTag>>::operator()(
    const ::cpp2::Foo& val) {
  if (!ensure_module_imported()) {
    DCHECK(PyErr_Occurred() != nullptr);
    return nullptr;
  }
  Constructor<::apache::thrift::python::capi::ComposedStruct<
        ::cpp2::Foo, ::emptyns::NamespaceTag>> ctor;
  StrongRef fbthrift_data(ctor(val));
  if (!fbthrift_data) {
    return nullptr;
  }
  return init__emptyns__Foo(*fbthrift_data);
}

PyObject* Constructor<::apache::thrift::python::capi::ComposedStruct<
        ::cpp2::Foo, ::emptyns::NamespaceTag>>::operator()(
    [[maybe_unused]] const ::cpp2::Foo& val) {
  StrongRef fbthrift_data(createStructTuple(1));
  StrongRef _fbthrift__MyInt(
    Constructor<int64_t>{}
    .constructFrom(val.MyInt_ref()));
  if (!_fbthrift__MyInt ||
      setStructField(
          *fbthrift_data,
          _fbthrift__Foo__tuple_pos[0],
          *_fbthrift__MyInt) == -1) {
    return nullptr;
  }
  return std::move(fbthrift_data).release();
}


} // namespace apache::thrift::python::capi
