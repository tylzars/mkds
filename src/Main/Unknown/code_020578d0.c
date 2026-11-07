#include "Main/Unknown/code_020578d0.h"
#include "01/code_021956dc.h"
#include "code_0214d018.h"

#pragma thumb on
void func_020578e8(u32 buffer, u32 length) {
    u32 source = buffer;
    u32 value1;
    u32 size;
    u32 value3;
    value1 = (u32) &data_021759d4;
    value1 = *(const u32 *) ((value1) + 0u);
    value1 = *(const u32 *) ((value1) + 104u);
    size = 48u;
    MI_CpuCopy8((const void *) source, (void *) value1, size);
}
#pragma thumb off

#pragma thumb on
void func_020578d0(u32 buffer, u32 length) {
    u32 source = buffer;
    u32 value1;
    u32 size;
    u32 value3;
    value1 = (u32) &data_021759d4;
    value1 = *(const u32 *) ((value1) + 0u);
    value1 = *(const u32 *) ((value1) + 104u);
    size = 0x230u;
    MI_CpuCopy8((const void *) source, (void *) value1, size);
}
#pragma thumb off
