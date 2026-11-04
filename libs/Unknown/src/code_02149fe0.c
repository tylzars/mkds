#include "code_02149fe0.h"

u32 G2sBg1CntBits2To5Address(void) {
    u32 value0;
    value0 = 0x400100au;
    value0 = (u32) * (const u16 *) ((value0) + (0));
    value0 = (value0) & (0x3cu);
    value0 = ((u32) ((s32) value0 >> 2));
    value0 = (value0 << 14);
    value0 = (value0) + (0x6200000u);
    return value0;
}
