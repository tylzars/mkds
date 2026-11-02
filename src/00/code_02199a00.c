#include "00/code_02199a00.h"

u32 func_ov000_02199a00(u32 arg0, u32 arg1) {
    u32 value0 = arg0;
    u32 value1 = arg1;
    u32 value3;
    value0 = (u32) * (const u16 *) ((value0) + 12u);
    value1 = (u32) * (const u16 *) ((value1) + 12u);
    value3 = (u32) &func_ov000_0219a014;
    value0 = func_ov000_0219a014(value0, value1);
    return value0;
}
