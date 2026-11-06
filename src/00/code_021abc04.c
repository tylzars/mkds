#include "00/code_021abc04.h"
#include "code_0214d018.h"

void func_ov000_021abc14(u32 arg0, u32 arg1, u32 arg2) {
    u32 value0 = arg0;
    u32 value1 = arg1;
    u32 value2 = arg2;
    u32 value3;
    value3 = (value0) + (0u);
    value0 = (value1) + (0u);
    value1 = (value3) + (0u);
    value3 = (u32) &MI_CpuCopy8;
    MI_CpuCopy8((const void *) value0, (void *) value1, value2);
    return;
}

void func_ov000_021abc04(void *a, const void *b, u32 c) {
    MI_CpuCopy8(b, a, c);
}
