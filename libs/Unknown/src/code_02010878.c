#include "code_02010878.h"

void func_02010884(u32 arg0, u32 arg1, u32 arg2) {
    u32 value0 = arg0;
    u32 value1 = arg1;
    u32 value2 = arg2;
    u32 value3;
    u32 value12;
    value12 = (u32) * (const u16 *) ((value0) + (16));
    value3 = 0u;
    value12 = (value12) & ~(1u);
    *(u16 *) ((value0) + (16)) = (u16) value12;
    value12 = (u32) * (const u16 *) ((value0) + (32));
    value12 = (value12) & ~(1u);
    *(u16 *) ((value0) + (32)) = (u16) value12;
    value12 = (u32) * (const u32 *) ((value0) + (8));
    *(u32 *) ((value1) + (0)) = value12;
    *(u32 *) ((value0) + (8)) = value3;
    value1 = (u32) * (const u32 *) ((value0) + (24));
    *(u32 *) ((value2) + (0)) = value1;
    *(u32 *) ((value0) + (24)) = value3;
}

u32 func_02010878(u32 arg0) {
    u32 value0 = arg0;
    value0 = (u32) * (const u16 *) ((value0) + (48));
    value0 = (value0 << 3);
    return value0;
}
