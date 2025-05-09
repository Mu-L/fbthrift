
/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT
 *  @generated
 *
 */

#pragma once

#include <thrift/lib/python/capi/constructor.h>
#include <thrift/lib/python/capi/extractor.h>

#include <thrift/compiler/test/fixtures/includes/gen-cpp2/module_types.h>

namespace module {

struct NamespaceTag {};

} // namespace module

namespace apache::thrift::python::capi {
template <>
struct Extractor<::apache::thrift::python::capi::PythonNamespaced<::cpp2::MyStruct, ::module::NamespaceTag>>
    : public BaseExtractor<::apache::thrift::python::capi::PythonNamespaced<::cpp2::MyStruct, ::module::NamespaceTag>> {
  static const bool kUsingMarshal = true;
  ExtractorResult<::cpp2::MyStruct> operator()(PyObject* obj);
  int typeCheck(PyObject* obj);
};

template <>
struct Extractor<::apache::thrift::python::capi::ComposedStruct<
        ::cpp2::MyStruct, ::module::NamespaceTag >>
    : public BaseExtractor<::apache::thrift::python::capi::ComposedStruct<
        ::cpp2::MyStruct, ::module::NamespaceTag>> {
  ExtractorResult<::cpp2::MyStruct> operator()(PyObject* obj);
};

template <>
struct Constructor<::apache::thrift::python::capi::PythonNamespaced<::cpp2::MyStruct, ::module::NamespaceTag>>
    : public BaseConstructor<::apache::thrift::python::capi::PythonNamespaced<::cpp2::MyStruct, ::module::NamespaceTag>> {
  static const bool kUsingMarshal = true;
  PyObject* operator()(const ::cpp2::MyStruct& val);
};

template <>
struct Constructor<::apache::thrift::python::capi::ComposedStruct<
        ::cpp2::MyStruct, ::module::NamespaceTag>>
    : public BaseConstructor<::apache::thrift::python::capi::ComposedStruct<
        ::cpp2::MyStruct, ::module::NamespaceTag>> {
  PyObject* operator()(const ::cpp2::MyStruct& val);
};

} // namespace apache::thrift::python::capi
