/**
 * Autogenerated by Thrift for thrift/compiler/test/fixtures/basic-structured-annotations/src/module.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated @nocommit
 */
#include "thrift/compiler/test/fixtures/basic-structured-annotations/gen-cpp2/module_types.tcc"

namespace test::fixtures::basic-structured-annotations {

template void runtime_annotation::readNoXfer<>(apache::thrift::CompactProtocolReader*);
template uint32_t runtime_annotation::write<>(apache::thrift::CompactProtocolWriter*) const;
template uint32_t runtime_annotation::serializedSize<>(apache::thrift::CompactProtocolWriter const*) const;
template uint32_t runtime_annotation::serializedSizeZC<>(apache::thrift::CompactProtocolWriter const*) const;

template void structured_annotation_inline::readNoXfer<>(apache::thrift::CompactProtocolReader*);
template uint32_t structured_annotation_inline::write<>(apache::thrift::CompactProtocolWriter*) const;
template uint32_t structured_annotation_inline::serializedSize<>(apache::thrift::CompactProtocolWriter const*) const;
template uint32_t structured_annotation_inline::serializedSizeZC<>(apache::thrift::CompactProtocolWriter const*) const;

template void structured_annotation_with_default::readNoXfer<>(apache::thrift::CompactProtocolReader*);
template uint32_t structured_annotation_with_default::write<>(apache::thrift::CompactProtocolWriter*) const;
template uint32_t structured_annotation_with_default::serializedSize<>(apache::thrift::CompactProtocolWriter const*) const;
template uint32_t structured_annotation_with_default::serializedSizeZC<>(apache::thrift::CompactProtocolWriter const*) const;

template void structured_annotation_recursive::readNoXfer<>(apache::thrift::CompactProtocolReader*);
template uint32_t structured_annotation_recursive::write<>(apache::thrift::CompactProtocolWriter*) const;
template uint32_t structured_annotation_recursive::serializedSize<>(apache::thrift::CompactProtocolWriter const*) const;
template uint32_t structured_annotation_recursive::serializedSizeZC<>(apache::thrift::CompactProtocolWriter const*) const;

template void structured_annotation_forward::readNoXfer<>(apache::thrift::CompactProtocolReader*);
template uint32_t structured_annotation_forward::write<>(apache::thrift::CompactProtocolWriter*) const;
template uint32_t structured_annotation_forward::serializedSize<>(apache::thrift::CompactProtocolWriter const*) const;
template uint32_t structured_annotation_forward::serializedSizeZC<>(apache::thrift::CompactProtocolWriter const*) const;

template void structured_annotation_nested::readNoXfer<>(apache::thrift::CompactProtocolReader*);
template uint32_t structured_annotation_nested::write<>(apache::thrift::CompactProtocolWriter*) const;
template uint32_t structured_annotation_nested::serializedSize<>(apache::thrift::CompactProtocolWriter const*) const;
template uint32_t structured_annotation_nested::serializedSizeZC<>(apache::thrift::CompactProtocolWriter const*) const;

template void MyStruct::readNoXfer<>(apache::thrift::CompactProtocolReader*);
template uint32_t MyStruct::write<>(apache::thrift::CompactProtocolWriter*) const;
template uint32_t MyStruct::serializedSize<>(apache::thrift::CompactProtocolWriter const*) const;
template uint32_t MyStruct::serializedSizeZC<>(apache::thrift::CompactProtocolWriter const*) const;

template void MyException::readNoXfer<>(apache::thrift::CompactProtocolReader*);
template uint32_t MyException::write<>(apache::thrift::CompactProtocolWriter*) const;
template uint32_t MyException::serializedSize<>(apache::thrift::CompactProtocolWriter const*) const;
template uint32_t MyException::serializedSizeZC<>(apache::thrift::CompactProtocolWriter const*) const;

template void MyUnion::readNoXfer<>(apache::thrift::CompactProtocolReader*);
template uint32_t MyUnion::write<>(apache::thrift::CompactProtocolWriter*) const;
template uint32_t MyUnion::serializedSize<>(apache::thrift::CompactProtocolWriter const*) const;
template uint32_t MyUnion::serializedSizeZC<>(apache::thrift::CompactProtocolWriter const*) const;

} // namespace test::fixtures::basic-structured-annotations
