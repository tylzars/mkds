#include "Main/Unknown/code_02079b40.h"

u32 func_02079b40(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    value2 = (u32) &gKartModels;
    value1 = 0xb4u;
    value2 = (u32) * (const u32 *) ((value2) + (0));
    value2 = (u32) * (const u32 *) ((value2) + (0));
    value1 = (value0) * (value1) + (value2);
    value0 = (u32) * (const u16 *) ((value1) + (104));
    return value0;
}
