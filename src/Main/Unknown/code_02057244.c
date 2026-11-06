#include "Main/Unknown/code_02057244.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_0214d018.h"

#pragma thumb on
void func_02057244(void) {
    u32 value0;
    u32 value1;
    u32 value2;
    u32 value3;
    value0 = (u32) &data_0217aa08;
    value0 = *(const u32 *) ((value0) + 0u);
    value0 = *(const u32 *) ((value0) + 32u);
    value1 = 0u;
    value2 = 0xc00u;
    MI_CpuFill8((void *) value0, value1, value2);
}
#pragma thumb off
