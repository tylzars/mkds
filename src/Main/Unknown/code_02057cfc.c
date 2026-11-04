#include "Main/Unknown/code_02057cfc.h"
#include "01/code_021956dc.h"
#include "code_0214d018.h"

#pragma thumb on
void func_02057cfc(u32 arg0, u32 arg1) {
    u32 value0 = arg0;
    u32 value1 = arg1;
    u32 value2;
    u32 value3;
    value2 = (value1) + (0u);
    value1 = (u32) &data_021759d4;
    value1 = (u32) * (const u32 *) ((value1) + 0u);
    value1 = (u32) * (const u32 *) ((value1) + 104u);
    value3 = (u32) &MemCopy;
    MemCopy((const void *) value0, (void *) value1, value2);
}
#pragma thumb off
