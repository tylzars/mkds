#include "Main/Unknown/code_020ce744.h"

void GxDispCntBits8To12Write(int bits) {
    u32 value0 = bits;
    u32 value1;
    u32 registerAddress;
    registerAddress = 0x4000000u;
    value1 = *(const u32 *) ((registerAddress) + (0));
    value1 = (value1) & ~(0x1f00u);
    value0 = (value1) | ((value0 << 8));
    *(u32 *) ((registerAddress) + (0)) = value0;
}

void GxsDispCntBits8To12Write(int bits) {
    u32 value0 = bits;
    u32 value1;
    u32 registerAddress;
    registerAddress = 0x4001000u;
    value1 = *(const u32 *) ((registerAddress) + (0));
    value1 = (value1) & ~(0x1f00u);
    value0 = (value1) | ((value0 << 8));
    *(u32 *) ((registerAddress) + (0)) = value0;
}
