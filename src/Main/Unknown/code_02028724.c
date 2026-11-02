#include "Main/Unknown/code_02028724.h"
#include "Main/Unknown/unk_02175628.h"

u32 func_0202876c(u32 p0) {
    return ((u32) * (const u16 *) ((u8 *) p0 + 0));
}

u32 func_0202874c(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    u32 value12;
    value2 = (u32) &data_02175628;
    value1 = 0x5cu;
    value1 = (value0) * (value1) + (value2);
    value12 = (u32) &func_0202876c;
    value0 = (value1) + (0x48u);
    value0 = (u32) func_0202876c(value0);
    return value0;
}

u32 func_02028744(u32 p0) {
    return ((u32) * (const u16 *) ((u8 *) p0 + 2));
}

u32 func_02028724(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    u32 value12;
    value2 = (u32) &data_02175628;
    value1 = 0x5cu;
    value1 = (value0) * (value1) + (value2);
    value12 = (u32) &func_02028744;
    value0 = (value1) + (0x48u);
    value0 = (u32) func_02028744(value0);
    return value0;
}
