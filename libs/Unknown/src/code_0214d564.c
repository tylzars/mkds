#include "code_0214d564.h"

void func_0214d564(u32 arg0, u32 arg1, u32 arg2) {
    u32 value0 = arg0;
    u32 value1 = arg1;
    u32 value2 = arg2;
    *(u32 *) ((value0) + (0)) = value1;
    value2 = (u32) * (const u32 *) ((value2) + (0));
    value1 = 0u;
    value2 = (value2 >> 8);
    *(u32 *) ((value0) + (4)) = value2;
    *(u8 *) ((value0) + (11)) = (u8) value1;
    *(u8 *) ((value0) + (12)) = (u8) value1;
    *(u8 *) ((value0) + (13)) = (u8) value1;
    *(u8 *) ((value0) + (14)) = (u8) value1;
    *(u16 *) ((value0) + (8)) = (u16) value1;
    *(u8 *) ((value0) + (10)) = (u8) value1;
}
