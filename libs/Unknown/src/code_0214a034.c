#include "code_0214a034.h"

u32 func_0214a034(void) {
    u32 value0;
    value0 = 0x4001008u;
    value0 = (u32) * (const u16 *) ((value0) + (0));
    value0 = (value0) & (0x3cu);
    value0 = ((u32) ((s32) value0 >> 2));
    value0 = (value0 << 14);
    value0 = (value0) + (0x6200000u);
    return value0;
}
