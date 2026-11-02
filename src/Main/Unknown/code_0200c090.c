#include "Main/Unknown/code_0200c090.h"
#include "03/code_021b94b8.h"
#include "Main/Unknown/unk_0216f000.h"

#pragma thumb on
u32 func_0200c0ac(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    value2 = (u32) &data_0216fdec;
    *(u32 *) ((value2) + 0u) = value0;
    value1 = 0u;
    *(u32 *) ((value0) + 12u) = value1;
    value0 = (u32) * (const u32 *) ((value2) + 0u);
    *(u16 *) ((value0) + 26u) = (u16) value1;
    value0 = (u32) * (const u32 *) ((value2) + 0u);
    *(u16 *) ((value0) + 30u) = (u16) value1;
    value0 = (u32) * (const u32 *) ((value2) + 0u);
    *(u16 *) ((value0) + 32u) = (u16) value1;
    value0 = (u32) * (const u32 *) ((value2) + 0u);
    *(u16 *) ((value0) + 28u) = (u16) value1;
    value0 = (u32) * (const u32 *) ((value2) + 0u);
    *(u32 *) ((value0) + 4u) = value1;
    value0 = (u32) * (const u32 *) ((value2) + 0u);
    *(u32 *) ((value0) + 8u) = value1;
    value0 = (u32) * (const u32 *) ((value2) + 0u);
    *(u32 *) ((value0) + 0u) = value1;
    return value0;
}
#pragma thumb off

#pragma thumb on

void func_0200c090(u32 p0) {
    u32 v1 = ((p0) + (0x0u));
    u32 v2 = ((u32) func_0200fca0());
    u32 v3 = ((u32) (&data_0216fdec));
    u32 v4 = ((u32) * (u32 *) ((v3) + (0)));
    u32 v6;
    *(u32 *) ((v4) + (0)) = v1;
    v6 = ((u32) func_0200fcb4(v2));
}

#pragma thumb off
