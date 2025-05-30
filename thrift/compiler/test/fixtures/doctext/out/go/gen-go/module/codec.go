// Autogenerated by Thrift for thrift/compiler/test/fixtures/doctext/src/module.thrift
//
// DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
//  @generated

package module


import (
    thrift "github.com/facebook/fbthrift/thrift/lib/go/thrift/types"
)

// (needed to ensure safety because of naive import list construction)
var _ = thrift.VOID

// Premade codec specs
var (
    premadeCodecTypeSpec_module_B = &thrift.TypeSpec{
        FullName: "module.B",
        CodecEnumSpec:
            &thrift.CodecEnumSpec{
                ScopedName: "module.B",
            },
    }
    premadeCodecTypeSpec_i32 = &thrift.TypeSpec{
        FullName: "i32",
        CodecPrimitiveSpec:
            &thrift.CodecPrimitiveSpec{
                PrimitiveType: thrift.CODEC_PRIMITIVE_TYPE_I32,
            },
    }
    premadeCodecTypeSpec_module_A = &thrift.TypeSpec{
        FullName: "module.A",
        CodecStructSpec:
            &thrift.CodecStructSpec{
                ScopedName: "module.A",
                IsUnion:    false,
                NewFunc:    func() thrift.Struct { return NewA() },
            },
    }
    premadeCodecTypeSpec_string = &thrift.TypeSpec{
        FullName: "string",
        CodecPrimitiveSpec:
            &thrift.CodecPrimitiveSpec{
                PrimitiveType: thrift.CODEC_PRIMITIVE_TYPE_STRING,
            },
    }
    premadeCodecTypeSpec_module_U = &thrift.TypeSpec{
        FullName: "module.U",
        CodecStructSpec:
            &thrift.CodecStructSpec{
                ScopedName: "module.U",
                IsUnion:    true,
                NewFunc:    func() thrift.Struct { return NewU() },
            },
    }
    premadeCodecTypeSpec_module_Bang = &thrift.TypeSpec{
        FullName: "module.Bang",
        CodecStructSpec:
            &thrift.CodecStructSpec{
                ScopedName: "module.Bang",
                IsUnion:    false,
                NewFunc:    func() thrift.Struct { return NewBang() },
            },
    }
    premadeCodecTypeSpec_module_lanyard = &thrift.TypeSpec{
        FullName: "module.lanyard",
        CodecTypedefSpec:
            &thrift.CodecTypedefSpec{
                ScopedName:         "module.lanyard",
            	UnderlyingTypeSpec: premadeCodecTypeSpec_string,
            },
    }
    premadeCodecTypeSpec_module_number = &thrift.TypeSpec{
        FullName: "module.number",
        CodecTypedefSpec:
            &thrift.CodecTypedefSpec{
                ScopedName:         "module.number",
            	UnderlyingTypeSpec: premadeCodecTypeSpec_i32,
            },
    }
    premadeCodecTypeSpec_void = &thrift.TypeSpec{
        FullName: "void",
        CodecPrimitiveSpec:
            &thrift.CodecPrimitiveSpec{
                PrimitiveType: thrift.CODEC_PRIMITIVE_TYPE_VOID,
            },
    }
    premadeCodecTypeSpec_set_i32 = &thrift.TypeSpec{
        FullName: "set<i32>",
        CodecSetSpec:
            &thrift.CodecSetSpec{
                ElementWireType: thrift.I32,
            	ElementTypeSpec: premadeCodecTypeSpec_i32,
            },
    }
)

// Premade struct specs
var (
    premadeStructSpec_A =
        &thrift.StructSpec{
            Name:                 "A",
            ScopedName:           "module.A",
            IsUnion:              false,
            IsException:          false,
            FieldSpecs:           []thrift.FieldSpec{
                {
                    ID:                   1,
                    WireType:             thrift.I32,
                    Name:                 "useless_field",
                    ReflectIndex:         0,
                    IsOptional:           false,
                    ValueTypeSpec:        premadeCodecTypeSpec_i32,
                    MustBeSetToSerialize: false,
                },
            },
            FieldSpecIDToIndex:   map[int16]int{
                1: 0,
            },
            FieldSpecNameToIndex: map[string]int{
                "useless_field": 0,
            },
        }
    premadeStructSpec_U =
        &thrift.StructSpec{
            Name:                 "U",
            ScopedName:           "module.U",
            IsUnion:              true,
            IsException:          false,
            FieldSpecs:           []thrift.FieldSpec{
                {
                    ID:                   1,
                    WireType:             thrift.I32,
                    Name:                 "i",
                    ReflectIndex:         0,
                    IsOptional:           false,
                    ValueTypeSpec:        premadeCodecTypeSpec_i32,
                    MustBeSetToSerialize: true,
                },
                {
                    ID:                   2,
                    WireType:             thrift.STRING,
                    Name:                 "s",
                    ReflectIndex:         1,
                    IsOptional:           false,
                    ValueTypeSpec:        premadeCodecTypeSpec_string,
                    MustBeSetToSerialize: true,
                },
            },
            FieldSpecIDToIndex:   map[int16]int{
                1: 0,
                2: 1,
            },
            FieldSpecNameToIndex: map[string]int{
                "i": 0,
                "s": 1,
            },
        }
    premadeStructSpec_Bang =
        &thrift.StructSpec{
            Name:                 "Bang",
            ScopedName:           "module.Bang",
            IsUnion:              false,
            IsException:          true,
            FieldSpecs:           []thrift.FieldSpec{
                {
                    ID:                   1,
                    WireType:             thrift.STRING,
                    Name:                 "message",
                    ReflectIndex:         0,
                    IsOptional:           false,
                    ValueTypeSpec:        premadeCodecTypeSpec_string,
                    MustBeSetToSerialize: false,
                },
            },
            FieldSpecIDToIndex:   map[int16]int{
                1: 0,
            },
            FieldSpecNameToIndex: map[string]int{
                "message": 0,
            },
        }
    premadeStructSpec_reqCF =
        &thrift.StructSpec{
            Name:                 "reqCF",
            ScopedName:           "module.reqCF",
            IsUnion:              false,
            IsException:          false,
            FieldSpecs:           []thrift.FieldSpec{
            },
            FieldSpecIDToIndex:   map[int16]int{
            },
            FieldSpecNameToIndex: map[string]int{
            },
        }
    premadeStructSpec_respCF =
        &thrift.StructSpec{
            Name:                 "respCF",
            ScopedName:           "module.respCF",
            IsUnion:              false,
            IsException:          false,
            FieldSpecs:           []thrift.FieldSpec{
            },
            FieldSpecIDToIndex:   map[int16]int{
            },
            FieldSpecNameToIndex: map[string]int{
            },
        }
    premadeStructSpec_reqCNumbers =
        &thrift.StructSpec{
            Name:                 "reqCNumbers",
            ScopedName:           "module.reqCNumbers",
            IsUnion:              false,
            IsException:          false,
            FieldSpecs:           []thrift.FieldSpec{
            },
            FieldSpecIDToIndex:   map[int16]int{
            },
            FieldSpecNameToIndex: map[string]int{
            },
        }
    premadeStructSpec_respCNumbers =
        &thrift.StructSpec{
            Name:                 "respCNumbers",
            ScopedName:           "module.respCNumbers",
            IsUnion:              false,
            IsException:          false,
            FieldSpecs:           []thrift.FieldSpec{
            },
            FieldSpecIDToIndex:   map[int16]int{
            },
            FieldSpecNameToIndex: map[string]int{
            },
        }
    premadeStructSpec_streamCNumbers =
        &thrift.StructSpec{
            Name:                 "streamCNumbers",
            ScopedName:           "module.streamCNumbers",
            IsUnion:              false,
            IsException:          false,
            FieldSpecs:           []thrift.FieldSpec{
                {
                    ID:                   0,
                    WireType:             thrift.I32,
                    Name:                 "success",
                    ReflectIndex:         0,
                    IsOptional:           true,
                    ValueTypeSpec:        premadeCodecTypeSpec_module_number,
                    MustBeSetToSerialize: true,
                },
            },
            FieldSpecIDToIndex:   map[int16]int{
                0: 0,
            },
            FieldSpecNameToIndex: map[string]int{
                "success": 0,
            },
        }
    premadeStructSpec_reqCThing =
        &thrift.StructSpec{
            Name:                 "reqCThing",
            ScopedName:           "module.reqCThing",
            IsUnion:              false,
            IsException:          false,
            FieldSpecs:           []thrift.FieldSpec{
                {
                    ID:                   1,
                    WireType:             thrift.I32,
                    Name:                 "a",
                    ReflectIndex:         0,
                    IsOptional:           false,
                    ValueTypeSpec:        premadeCodecTypeSpec_i32,
                    MustBeSetToSerialize: false,
                },
                {
                    ID:                   2,
                    WireType:             thrift.STRING,
                    Name:                 "b",
                    ReflectIndex:         1,
                    IsOptional:           false,
                    ValueTypeSpec:        premadeCodecTypeSpec_string,
                    MustBeSetToSerialize: false,
                },
                {
                    ID:                   3,
                    WireType:             thrift.SET,
                    Name:                 "c",
                    ReflectIndex:         2,
                    IsOptional:           false,
                    ValueTypeSpec:        premadeCodecTypeSpec_set_i32,
                    MustBeSetToSerialize: false,
                },
            },
            FieldSpecIDToIndex:   map[int16]int{
                1: 0,
                2: 1,
                3: 2,
            },
            FieldSpecNameToIndex: map[string]int{
                "a": 0,
                "b": 1,
                "c": 2,
            },
        }
    premadeStructSpec_respCThing =
        &thrift.StructSpec{
            Name:                 "respCThing",
            ScopedName:           "module.respCThing",
            IsUnion:              false,
            IsException:          false,
            FieldSpecs:           []thrift.FieldSpec{
                {
                    ID:                   0,
                    WireType:             thrift.STRING,
                    Name:                 "success",
                    ReflectIndex:         0,
                    IsOptional:           true,
                    ValueTypeSpec:        premadeCodecTypeSpec_string,
                    MustBeSetToSerialize: true,
                },
                {
                    ID:                   1,
                    WireType:             thrift.STRUCT,
                    Name:                 "bang",
                    ReflectIndex:         1,
                    IsOptional:           true,
                    ValueTypeSpec:        premadeCodecTypeSpec_module_Bang,
                    MustBeSetToSerialize: true,
                },
            },
            FieldSpecIDToIndex:   map[int16]int{
                0: 0,
                1: 1,
            },
            FieldSpecNameToIndex: map[string]int{
                "success": 0,
                "bang": 1,
            },
        }
)

var premadeCodecSpecsMap = func() map[string]*thrift.TypeSpec {
    fbthriftTypeSpecsMap := make(map[string]*thrift.TypeSpec)
    fbthriftTypeSpecsMap[premadeCodecTypeSpec_module_B.FullName] = premadeCodecTypeSpec_module_B
    fbthriftTypeSpecsMap[premadeCodecTypeSpec_i32.FullName] = premadeCodecTypeSpec_i32
    fbthriftTypeSpecsMap[premadeCodecTypeSpec_module_A.FullName] = premadeCodecTypeSpec_module_A
    fbthriftTypeSpecsMap[premadeCodecTypeSpec_string.FullName] = premadeCodecTypeSpec_string
    fbthriftTypeSpecsMap[premadeCodecTypeSpec_module_U.FullName] = premadeCodecTypeSpec_module_U
    fbthriftTypeSpecsMap[premadeCodecTypeSpec_module_Bang.FullName] = premadeCodecTypeSpec_module_Bang
    fbthriftTypeSpecsMap[premadeCodecTypeSpec_module_lanyard.FullName] = premadeCodecTypeSpec_module_lanyard
    fbthriftTypeSpecsMap[premadeCodecTypeSpec_module_number.FullName] = premadeCodecTypeSpec_module_number
    fbthriftTypeSpecsMap[premadeCodecTypeSpec_void.FullName] = premadeCodecTypeSpec_void
    return fbthriftTypeSpecsMap
}()

// GetMetadataThriftType (INTERNAL USE ONLY).
// Returns metadata TypeSpec for a given full type name.
func GetCodecTypeSpec(fullName string) *thrift.TypeSpec {
    return premadeCodecSpecsMap[fullName]
}
