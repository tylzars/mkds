#include "Main/Unknown/code_0203b680.h"

u32 func_0203b680(u32 arg0, u32 arg1, u32 arg2) {
    u32 value0 = arg0;
    u32 value1 = arg1;
    u32 value2 = arg2;
    u32 value3;
    value3 = *(const u16 *) ((value0) + (6));
    value2 = (value2) - (1u);
    value1 = (value1) - (1u);
    value2 = (value1) * (value3) + (value2);
    value0 = (value0) + (value2);
    value0 = *(const u8 *) ((value0) + (8));
    return value0;
}
