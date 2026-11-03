#include "Main/Unknown/code_0200b7cc.h"
#include "Main/Unknown/unk_0216f000.h"

#pragma thumb on
u32 func_0200b7cc(void) {
    u32 value0;
    u32 value1;
    u32 value2;
    value2 = 0u;
    value0 = (u32) &data_0216fde8;
    value1 = (u32) * (const u32 *) ((value0) + 0u);
    value0 = 0x5f00u;
    *(u32 *) ((value1) + (value0)) = value2;
    return value0;
}
#pragma thumb off
