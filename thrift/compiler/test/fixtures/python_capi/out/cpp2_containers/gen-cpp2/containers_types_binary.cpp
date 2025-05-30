/**
 * Autogenerated by Thrift for thrift/compiler/test/fixtures/python_capi/src/containers.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated @nocommit
 */
#include "thrift/compiler/test/fixtures/python_capi/gen-cpp2/containers_types.tcc"

namespace test::fixtures::python_capi {

template void TemplateLists::readNoXfer<>(apache::thrift::BinaryProtocolReader*);
template uint32_t TemplateLists::write<>(apache::thrift::BinaryProtocolWriter*) const;
template uint32_t TemplateLists::serializedSize<>(apache::thrift::BinaryProtocolWriter const*) const;
template uint32_t TemplateLists::serializedSizeZC<>(apache::thrift::BinaryProtocolWriter const*) const;

template void TemplateSets::readNoXfer<>(apache::thrift::BinaryProtocolReader*);
template uint32_t TemplateSets::write<>(apache::thrift::BinaryProtocolWriter*) const;
template uint32_t TemplateSets::serializedSize<>(apache::thrift::BinaryProtocolWriter const*) const;
template uint32_t TemplateSets::serializedSizeZC<>(apache::thrift::BinaryProtocolWriter const*) const;

template void TemplateMaps::readNoXfer<>(apache::thrift::BinaryProtocolReader*);
template uint32_t TemplateMaps::write<>(apache::thrift::BinaryProtocolWriter*) const;
template uint32_t TemplateMaps::serializedSize<>(apache::thrift::BinaryProtocolWriter const*) const;
template uint32_t TemplateMaps::serializedSizeZC<>(apache::thrift::BinaryProtocolWriter const*) const;

template void TWrapped::readNoXfer<>(apache::thrift::BinaryProtocolReader*);
template uint32_t TWrapped::write<>(apache::thrift::BinaryProtocolWriter*) const;
template uint32_t TWrapped::serializedSize<>(apache::thrift::BinaryProtocolWriter const*) const;
template uint32_t TWrapped::serializedSizeZC<>(apache::thrift::BinaryProtocolWriter const*) const;

template void IndirectionA::readNoXfer<>(apache::thrift::BinaryProtocolReader*);
template uint32_t IndirectionA::write<>(apache::thrift::BinaryProtocolWriter*) const;
template uint32_t IndirectionA::serializedSize<>(apache::thrift::BinaryProtocolWriter const*) const;
template uint32_t IndirectionA::serializedSizeZC<>(apache::thrift::BinaryProtocolWriter const*) const;

template void IndirectionB::readNoXfer<>(apache::thrift::BinaryProtocolReader*);
template uint32_t IndirectionB::write<>(apache::thrift::BinaryProtocolWriter*) const;
template uint32_t IndirectionB::serializedSize<>(apache::thrift::BinaryProtocolWriter const*) const;
template uint32_t IndirectionB::serializedSizeZC<>(apache::thrift::BinaryProtocolWriter const*) const;

template void IndirectionC::readNoXfer<>(apache::thrift::BinaryProtocolReader*);
template uint32_t IndirectionC::write<>(apache::thrift::BinaryProtocolWriter*) const;
template uint32_t IndirectionC::serializedSize<>(apache::thrift::BinaryProtocolWriter const*) const;
template uint32_t IndirectionC::serializedSizeZC<>(apache::thrift::BinaryProtocolWriter const*) const;

} // namespace test::fixtures::python_capi
