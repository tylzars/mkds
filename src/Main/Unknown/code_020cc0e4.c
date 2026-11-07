#include "Main/Unknown/code_020cc0e4.h"

#include "Main/Unknown/code_020cc134.h"
#include "00/code_02181f98.h"

u32 func_020cc150(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    value2 = 0x4000000u;
    value1 = *(const u32 *) ((value2) + (0));
    value1 = (value1) & ~(0xe000u);
    value0 = (value1) | ((value0 << 13));
    *(u32 *) ((value2) + (0)) = value0;
    return value0;
}

u32 func_020cc134(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    value2 = 0x4001000u;
    value1 = *(const u32 *) ((value2) + (0));
    value1 = (value1) & ~(0xe000u);
    value0 = (value1) | ((value0 << 13));
    *(u32 *) ((value2) + (0)) = value0;
    return value0;
}

u32 func_020cc120(void) {
    return (data_0217b488->mUnk_08);
}

void func_020cc10c(u32 value) {
    data_0217b488->mUnk_04 = value;
}

u32 func_020cc0f8(void) {
    return (data_0217b488->mUnk_10);
}

u32 func_020cc0e4(void) {
    return (data_0217b488->mUnk_14);
}
