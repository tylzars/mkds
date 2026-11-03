#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/unk_0217a000.h"

u32 func_0207a8a4(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    value2 = (u32) &data_0217ad18;
    value1 = 0x5a8u;
    value2 = (u32) * (const u32 *) ((value2) + (0));
    value1 = (value0) * (value1) + (value2);
    value0 = (u32) * (const u32 *) ((value1) + (668));
    return value0;
}

u16 func_0207a880(s32 arg0) {
    u32 value0 = (u32) arg0;
    u32 value1;
    u32 value2;
    value2 = (u32) &data_0217ad18;
    value1 = 0x5a8u;
    value2 = (u32) * (const u32 *) ((value2) + (0));
    value1 = (value0) * (value1) + (value2);
    value0 = (value1) + (0x200u);
    value0 = (u32) * (const u16 *) ((value0) + (54));
    return (u16) value0;
}
