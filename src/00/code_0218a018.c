#include "00/code_0218a018.h"

u32 func_ov000_0218a018(const u8 *arg0) {
    u32 value0 = (u32) arg0;
    u32 value1;
    u32 value2;
    u32 value3;
    u32 value4;
    value1 = 0u;
    value2 = *(const u8 *) ((value0) + 0u);
    value2 = (value2 << 24);
    value1 = (value1) | (value2);
    value2 = *(const u8 *) ((value0) + 1u);
    value2 = (value2 << 16);
    value1 = (value1) | (value2);
    value2 = *(const u8 *) ((value0) + 2u);
    value2 = (value2 << 8);
    value1 = (value1) | (value2);
    value0 = *(const u8 *) ((value0) + 3u);
    value1 = (value1) | (value0);
    value0 = (value1 << 24);
    value2 = 0xff000000u;
    value0 = (value0) & (value2);
    value4 = (value1 << 8);
    value2 = 0xff0000u;
    value4 = (value4) & (value2);
    value3 = (value1 >> 24);
    value2 = 255u;
    value3 = (value3) & (value2);
    value2 = (value1 >> 8);
    value1 = 0xff00u;
    value2 = (value2) & (value1);
    value3 = (value3) | (value2);
    value4 = (value4) | (value3);
    value0 = (value0) | (value4);
    return value0;
}
