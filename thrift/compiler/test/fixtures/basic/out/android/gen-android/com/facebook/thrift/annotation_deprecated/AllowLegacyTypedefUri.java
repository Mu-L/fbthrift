/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
package com.facebook.thrift.annotation_deprecated;

import java.util.List;
import java.util.ArrayList;
import java.util.Map;
import java.util.HashMap;
import java.util.Set;
import java.util.HashSet;
import java.util.Collections;
import java.util.BitSet;
import java.util.Arrays;
import com.facebook.thrift.*;
import com.facebook.thrift.annotations.*;
import com.facebook.thrift.async.*;
import com.facebook.thrift.meta_data.*;
import com.facebook.thrift.server.*;
import com.facebook.thrift.transport.*;
import com.facebook.thrift.protocol.*;

/**
 * Allows the Thrift compiler to add a URI to the target typedef.
 * 
 * Use of this annotation is strongly DISCOURAGED, and is provided for
 * backwards-compatibility purposes only.
 * 
 * Indeed, Thrift IDL [typedefs](https://github.com/facebook/fbthrift/blob/main/thrift/doc/idl/index.md#typedefs)
 * do not correspond to the set of user-defined types that can have unique URIs
 * per the [Thrift Object Model](https://github.com/facebook/fbthrift/blob/main/thrift/doc/object-model/index.md#thrift-uri)
 * While it may seem like typedefs correspond to
 * [Opaque Alias Types](https://github.com/facebook/fbthrift/blob/main/thrift/doc/object-model/index.md#opaque-alias-types),
 * that is actually incorrect, as the "aliased" type that a typedef introduces
 * is considered identical - at the Object Model level - to the original type.
 * 
 * This annotation is introduced to allow "grandfathering in" existing typedef
 * URIs in preparation for the thrift compiler to reject such cases in the
 * future (unless this annotation is specified).
 * 
 * This annoation MUST NOT be applied to a typedef for which no URI is
 * specified (either explicitly via @thrift.Uri, or implicitly through a
 * non-empty
 * [package declaration](https://github.com/facebook/fbthrift/blob/main/thrift/doc/idl/index.md#package-declaration)).
 */
@SuppressWarnings({ "unused", "serial" })
public class AllowLegacyTypedefUri implements TBase, java.io.Serializable, Cloneable {
  private static final TStruct STRUCT_DESC = new TStruct("AllowLegacyTypedefUri");


  public AllowLegacyTypedefUri() {
  }

  /**
   * Performs a deep copy on <i>other</i>.
   */
  public AllowLegacyTypedefUri(AllowLegacyTypedefUri other) {
  }

  public AllowLegacyTypedefUri deepCopy() {
    return new AllowLegacyTypedefUri(this);
  }

  @Override
  public boolean equals(Object _that) {
    if (_that == null)
      return false;
    if (this == _that)
      return true;
    if (!(_that instanceof AllowLegacyTypedefUri))
      return false;
    AllowLegacyTypedefUri that = (AllowLegacyTypedefUri)_that;

    return true;
  }

  @Override
  public int hashCode() {
    return Arrays.deepHashCode(new Object[] {});
  }

  // This is required to satisfy the TBase interface, but can't be implemented on immutable struture.
  public void read(TProtocol iprot) throws TException {
    throw new TException("unimplemented in android immutable structure");
  }

  public static AllowLegacyTypedefUri deserialize(TProtocol iprot) throws TException {
    TField __field;
    iprot.readStructBegin();
    while (true)
    {
      __field = iprot.readFieldBegin();
      if (__field.type == TType.STOP) {
        break;
      }
      switch (__field.id)
      {
        default:
          TProtocolUtil.skip(iprot, __field.type);
          break;
      }
      iprot.readFieldEnd();
    }
    iprot.readStructEnd();

    AllowLegacyTypedefUri _that;
    _that = new AllowLegacyTypedefUri(
    );
    _that.validate();
    return _that;
  }

  public void write(TProtocol oprot) throws TException {
    validate();

    oprot.writeStructBegin(STRUCT_DESC);
    oprot.writeFieldStop();
    oprot.writeStructEnd();
  }

  @Override
  public String toString() {
    return toString(1, true);
  }

  @Override
  public String toString(int indent, boolean prettyPrint) {
    return TBaseHelper.toStringHelper(this, indent, prettyPrint);
  }

  public void validate() throws TException {
    // check for required fields
  }

}

