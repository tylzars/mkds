#include "Main/Unknown/code_020ae15c.h"

#include "Main/Unknown/code_020ae178.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_020b47b4.h"
#include "Main/Unknown/unk_02168000.h"
#include "Main/Unknown/code_020ae1f4.h"
#include "Main/Unknown/code_020ae214.h"
#include "Main/Unknown/code_020ae21c.h"
#include "Main/Unknown/code_020ae23c.h"

u32 func_020ae23c(u32 p0) {
    return ((u32) * (const u16 *) ((u8 *) p0 + 0));
}

u32 func_020ae21c(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    u32 value12;
    value2 = (u32) &data_02175628;
    value1 = 0x5cu;
    value1 = (value0) * (value1) + (value2);
    value12 = (u32) &func_020ae23c;
    value0 = (value1) + (0x48u);
    value0 = (u32) func_020ae23c(value0);
    return value0;
}

u32 func_020ae214(u32 p0) {
    return ((u32) * (const u16 *) ((u8 *) p0 + 2));
}

u32 func_020ae1f4(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    u32 value12;
    value2 = (u32) &data_02175628;
    value1 = 0x5cu;
    value1 = (value0) * (value1) + (value2);
    value12 = (u32) &func_020ae214;
    value0 = (value1) + (0x48u);
    value0 = (u32) func_020ae214(value0);
    return value0;
}

#pragma thumb on

u32 func_020ae1d0(u32 a) {
    return (u8) (a >> 24) + (((u8) (a >> 16) << 8) + (((u8) a << 24) + ((u8) (a >> 8) << 16)));
}

void *func_020ae178(u32 a, u32 b) {
    u32 v[13] = {20, 25, 24, 27, 22, 26, 23, 21, 29, 28, 30, 31, 32};
    u32 t;

    if (b != 0 && a == 1) {
        t = 0x21;
    } else if (b != 0 && a == 8) {
        t = 0x22;
    } else {
        t = v[a];
    }
    return GetBmgEntry(func_020b47cc(gCommonBmgName), t);
}

#pragma thumb off

u32 func_020ae15c(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    value2 = (u32) &data_021759c0;
    value1 = 0x30u;
    value2 = (u32) * (const u32 *) ((value2) + (0));
    value1 = (value0) * (value1) + (value2);
    value0 = (u32) * (const u32 *) ((value1) + (112));
    return value0;
}
