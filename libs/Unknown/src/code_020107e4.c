#include "code_020107e4.h"

u32 func_020107e4(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    value2 = (u32) * (const u16 *) ((value0) + (50));
    value1 = 0u;
    value2 = (value2) & ~(1u);
    *(u16 *) ((value0) + (50)) = (u16) value2;
    value2 = (u32) * (const u32 *) ((value0) + (44));
    *(u32 *) ((value0) + (44)) = value1;
    value0 = value2;
    return value0;
}
