#include "Main/Unknown/code_021281b4.h"

#pragma thumb on
void func_021281c8(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    value1 = (u32) &gSelectReturn;
    value2 = (u32) * (const u32 *) ((value1) + 0u);
    value1 = 0x824u;
    *(u32 *) ((value2) + (value1)) = value0;
}
#pragma thumb off

#pragma thumb on
u32 func_021281b4(void) {
    u32 value0;
    u32 value1;
    u32 value2;
    value2 = 0u;
    value0 = (u32) &data_0217d3f4;
    value1 = (u32) * (const u32 *) ((value0) + 0u);
    value0 = 0x8a0u;
    *(u32 *) ((value1) + (value0)) = value2;
    return value0;
}
#pragma thumb off
