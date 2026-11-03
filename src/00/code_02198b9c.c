#include "00/code_02198714.h"
#include "00/code_02198b9c.h"

u32 func_ov000_02198b9c(u32 arg0, u32 arg1, u32 arg2) {
    u32 value0 = arg0;
    u32 value1 = arg1;
    u32 value2 = arg2;
    u32 value3;
    value3 = 103u;
    *(u8 *) ((value1) + 2u) = (u8) value3;
    value3 = (u32) &func_ov000_02198714;
    value0 = (u32) func_ov000_02198714((u32 *) value0, value1, value2);
    return value0;
}
