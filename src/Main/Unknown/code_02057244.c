#include "Main/Unknown/code_02057244.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_0214d018.h"

#pragma thumb on
void ClearBuddyRecordBlock(void) {
    u32 value0;
    u32 fillValue;
    u32 size;
    u32 value3;
    value0 = (u32) &data_0217aa08;
    value0 = *(const u32 *) ((value0) + 0u);
    value0 = *(const u32 *) ((value0) + 32u);
    fillValue = 0u;
    size = 0xc00u;
    MI_CpuFill8((void *) value0, fillValue, size);
}
#pragma thumb off
