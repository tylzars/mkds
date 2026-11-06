#include "Main/Unknown/code_020578d0.h"
#include "01/code_021956dc.h"
#include "code_0214d018.h"

#pragma thumb on
void func_020578e8(u32 arg0, u32 v1) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    u32 value3;
    value1 = (u32) &data_021759d4;
    value1 = (u32) * (const u32 *) ((value1) + 0u);
    value1 = (u32) * (const u32 *) ((value1) + 104u);
    value2 = 48u;
    MI_CpuCopy8((const void *) value0, (void *) value1, value2);
}
#pragma thumb off

#pragma thumb on
void func_020578d0(u32 arg0, u32 v1) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    u32 value3;
    value1 = (u32) &data_021759d4;
    value1 = (u32) * (const u32 *) ((value1) + 0u);
    value1 = (u32) * (const u32 *) ((value1) + 104u);
    value2 = 0x230u;
    MI_CpuCopy8((const void *) value0, (void *) value1, value2);
}
#pragma thumb off
