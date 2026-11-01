#include "code_020220f0.h"

u32 func_020220f0(u32 arg0) {
    u32 value0 = (u32) arg0;
    u32 value1;
    u32 value2;
    value1 = (u32) * (const u32 *) ((value0) + (24));
    value2 = (u32) * (const u32 *) ((value0) + (0));
    value0 = (u32) * (const u32 *) ((value1) + (12));
    value0 = (value2) - (value0);
    value0 = (value0 << 13);
    value0 = (value0 >> 16);
    return (u32) value0;
}
