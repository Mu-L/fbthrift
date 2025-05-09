/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */

package test.fixtures.stream;

import com.facebook.swift.codec.*;
import com.facebook.swift.codec.ThriftField.Requiredness;
import com.facebook.swift.codec.ThriftField.Recursiveness;
import java.util.*;
import javax.annotation.Nullable;
import org.apache.thrift.*;
import org.apache.thrift.transport.*;
import org.apache.thrift.protocol.*;
import com.google.common.collect.*;

@SwiftGenerated
@com.facebook.swift.codec.ThriftStruct("FooStreamEx")
public final class FooStreamEx extends org.apache.thrift.TBaseException implements com.facebook.thrift.payload.ThriftSerializable {
    private static final long serialVersionUID = 1L;

    
    public static final Map<String, Integer> NAMES_TO_IDS = new HashMap();
    public static final Map<String, Integer> THRIFT_NAMES_TO_IDS = new HashMap();
    public static final Map<Integer, TField> FIELD_METADATA = new HashMap<>();

    private static final TStruct STRUCT_DESC = new TStruct("FooStreamEx");

    static {
    }

    @ThriftConstructor
    public FooStreamEx(
    ) {
    }
    
    

    public static class Builder {
    
    public Builder() { }
        public Builder(FooStreamEx other) {
        }
    
        @ThriftConstructor
        public FooStreamEx build() {
            FooStreamEx result = new FooStreamEx (
            );
            return result;
        }
    }


    
    public static com.facebook.thrift.payload.Reader<FooStreamEx> asReader() {
      return FooStreamEx::read0;
    }
    
    public static FooStreamEx read0(TProtocol oprot) throws TException {
      TField __field;
      oprot.readStructBegin(FooStreamEx.NAMES_TO_IDS, FooStreamEx.THRIFT_NAMES_TO_IDS, FooStreamEx.FIELD_METADATA);
      FooStreamEx.Builder builder = new FooStreamEx.Builder();
      while (true) {
        __field = oprot.readFieldBegin();
        if (__field.type == TType.STOP) { break; }
        switch (__field.id) {
        default:
          TProtocolUtil.skip(oprot, __field.type);
          break;
        }
        oprot.readFieldEnd();
      }
      oprot.readStructEnd();
      return builder.build();
    }

    public void write0(TProtocol oprot) throws TException {
      oprot.writeStructBegin(STRUCT_DESC);
      oprot.writeFieldStop();
      oprot.writeStructEnd();
    }

    private static class _FooStreamExLazy {
        private static final FooStreamEx _DEFAULT = new FooStreamEx.Builder().build();
    }
    
    public static FooStreamEx defaultInstance() {
        return  _FooStreamExLazy._DEFAULT;
    }}
