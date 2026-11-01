#include "code_020176b0.h"

u32 func_020176b0(u32 arg0, u32 arg1) {
    u32 value0 = arg0;
    u32 value1 = arg1;
    u32 value2;
    value2 = (value0) + (0x24u);
    value0 = (u32) * (const u16 *) ((value2) + (16));
    *(u16 *) ((value2) + (16)) = (u16) value1;
    return value0;
}
