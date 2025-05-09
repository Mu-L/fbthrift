/**
 * Autogenerated by Thrift for thrift/compiler/test/fixtures/terse_write/src/terse_write.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated @nocommit
 */
#include "thrift/compiler/test/fixtures/terse_write/gen-cpp2/terse_write_types.tcc"

namespace facebook::thrift::test::terse_write {

template void MyStruct::readNoXfer<>(apache::thrift::CompactProtocolReader*);
template uint32_t MyStruct::write<>(apache::thrift::CompactProtocolWriter*) const;
template uint32_t MyStruct::serializedSize<>(apache::thrift::CompactProtocolWriter const*) const;
template uint32_t MyStruct::serializedSizeZC<>(apache::thrift::CompactProtocolWriter const*) const;

template void MyUnion::readNoXfer<>(apache::thrift::CompactProtocolReader*);
template uint32_t MyUnion::write<>(apache::thrift::CompactProtocolWriter*) const;
template uint32_t MyUnion::serializedSize<>(apache::thrift::CompactProtocolWriter const*) const;
template uint32_t MyUnion::serializedSizeZC<>(apache::thrift::CompactProtocolWriter const*) const;

template void MyStructWithCustomDefault::readNoXfer<>(apache::thrift::CompactProtocolReader*);
template uint32_t MyStructWithCustomDefault::write<>(apache::thrift::CompactProtocolWriter*) const;
template uint32_t MyStructWithCustomDefault::serializedSize<>(apache::thrift::CompactProtocolWriter const*) const;
template uint32_t MyStructWithCustomDefault::serializedSizeZC<>(apache::thrift::CompactProtocolWriter const*) const;

template void StructLevelTerseStruct::readNoXfer<>(apache::thrift::CompactProtocolReader*);
template uint32_t StructLevelTerseStruct::write<>(apache::thrift::CompactProtocolWriter*) const;
template uint32_t StructLevelTerseStruct::serializedSize<>(apache::thrift::CompactProtocolWriter const*) const;
template uint32_t StructLevelTerseStruct::serializedSizeZC<>(apache::thrift::CompactProtocolWriter const*) const;

template void FieldLevelTerseStruct::readNoXfer<>(apache::thrift::CompactProtocolReader*);
template uint32_t FieldLevelTerseStruct::write<>(apache::thrift::CompactProtocolWriter*) const;
template uint32_t FieldLevelTerseStruct::serializedSize<>(apache::thrift::CompactProtocolWriter const*) const;
template uint32_t FieldLevelTerseStruct::serializedSizeZC<>(apache::thrift::CompactProtocolWriter const*) const;

template void AdaptedFields::readNoXfer<>(apache::thrift::CompactProtocolReader*);
template uint32_t AdaptedFields::write<>(apache::thrift::CompactProtocolWriter*) const;
template uint32_t AdaptedFields::serializedSize<>(apache::thrift::CompactProtocolWriter const*) const;
template uint32_t AdaptedFields::serializedSizeZC<>(apache::thrift::CompactProtocolWriter const*) const;

template void TerseException::readNoXfer<>(apache::thrift::CompactProtocolReader*);
template uint32_t TerseException::write<>(apache::thrift::CompactProtocolWriter*) const;
template uint32_t TerseException::serializedSize<>(apache::thrift::CompactProtocolWriter const*) const;
template uint32_t TerseException::serializedSizeZC<>(apache::thrift::CompactProtocolWriter const*) const;

} // namespace facebook::thrift::test::terse_write
