#include "code_0214a2f4.h"

u32 func_0214a2f4(void) {
    u32 value0;
    value0 = 0x4001008u;
    value0 = (u32) * (const u16 *) ((value0) + (0));
    value0 = (value0) & (0x1f00u);
    value0 = ((u32) ((s32) value0 >> 8));
    value0 = (value0 << 11);
    value0 = (value0) + (0x6200000u);
    return value0;
}
