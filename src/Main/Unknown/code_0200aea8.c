#include "Main/Unknown/code_0200aea8.h"
#include "code_0214d018.h"

#pragma thumb on
void ClearDataRangeTable(u32 table) {
    u32 address = table;
    u32 fillValue;
    u32 byteCount;
    u32 value3;
    fillValue = 0u;
    byteCount = 112u;
    MI_CpuFill8((void *) address, fillValue, byteCount);
}
#pragma thumb off
