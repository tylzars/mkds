#include "Main/Unknown/code_020a02c8.h"
#include "Main/Unknown/code_021000d0.h"

u32 func_020a02c8(void) {
    u32 value0;
    value0 = 0xau;
    value0 = (u32) func_02100138(value0);
    value0 = (u32) * (const u32 *) ((value0) + (0));
    value0 = (u32) * (const u32 *) ((value0) + (0));
    value0 = (u32) * (const u32 *) ((value0) + (164));
    value0 = (0x7f000u) - (value0);
    value0 = ((u32) ((s32) value0 >> 12));
    return value0;
}
