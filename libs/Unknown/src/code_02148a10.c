#include "code_02148a10.h"
#include "Main/Unknown/unk_0216f000.h"
#include "Main/Unknown/unk_02180000.h"

void func_02148a10(void) {
    u32 value0;
    u32 value1;
    u32 value2;
    u32 value3;
    u32 value12;
    u32 value14;
    value14 = 0x4000000u;
    value12 = (u32) * (const u32 *) ((value14) + (0));
    value1 = (u32) &data_0216f070;
    value2 = (value12) & (0x30000u);
    value3 = 0u;
    value0 = (u32) &data_021802ac;
    value2 = (value2 >> 16);
    *(u16 *) ((value1) + (0)) = (u16) value3;
    *(u16 *) ((value0) + (0)) = (u16) value2;
    value0 = (value12) & ~(0x30000u);
    *(u32 *) ((value14) + (0)) = value0;
}
