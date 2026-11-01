#include "code_02021764.h"
#include "code_02020eb0.h"

u32 func_02021764(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    value2 = (u32) &data_02174da0;
    value1 = 0xcu;
    value1 = (value0) * (value1) + (value2);
    value0 = (u32) * (const u8 *) ((value1) + (8));
    value0 = (value0) + (1u);
    *(u8 *) ((value1) + (8)) = (u8) value0;
    return value0;
}
