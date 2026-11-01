#include "code_02013730.h"

u32 func_02013730(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    value1 = (u32) * (const u16 *) ((value0) + (12));
    value1 = (u32) * (const u32 *) ((value0) + (value1));
    value0 = (value0) + (value1);
    return value0;
}
