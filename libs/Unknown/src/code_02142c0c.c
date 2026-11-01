#include "code_02142c0c.h"

u32 func_02142c0c(u32 arg0, u32 arg1) {
    u32 value0 = arg0;
    u32 value1 = arg1;
    u32 value2;
    value2 = (u32) &data_0217eed4;
    value2 = (u32) * (const u32 *) ((value2) + (0));
    value0 = (value2) + ((value0 << 2));
    *(u32 *) ((value0) + (24)) = value1;
    return value0;
}
