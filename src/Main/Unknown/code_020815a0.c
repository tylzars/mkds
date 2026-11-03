#include "Main/Unknown/code_020815a0.h"
#include "Main/Unknown/code_0208b6b0.h"
#include "Main/Unknown/unk_0217a000.h"

u32 func_020815dc(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    u32 value3;
    u32 compareLeft0;
    u32 compareRight0;
    value2 = (u32) &data_0217ae84;
    value1 = 0x58u;
    value2 = (u32) * (const u32 *) ((value2) + (0));
    value3 = (value0) * (value1) + (value2);
    value2 = (u32) * (const u32 *) ((value3) + (44));
    compareLeft0 = value2;
    compareRight0 = 0u;
    if (compareLeft0 == compareRight0) {
        return value0;
    }
    value1 = (u32) * (const u32 *) ((value2) + (36));
    value0 = 0u;
    value1 = (value1) & ~(1u);
    value1 = (value1) | (1u);
    *(u32 *) ((value2) + (36)) = value1;
    *(u32 *) ((value3) + (44)) = value0;
    return value0;
}

void func_020815a0(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    u32 value4;
    u32 compareLeft0;
    u32 compareRight0;
    value2 = (u32) &data_0217ae84;
    value1 = 0x58u;
    value2 = (u32) * (const u32 *) ((value2) + (0));
    value4 = (value0) * (value1) + (value2);
    value0 = (u32) * (const u32 *) ((value4) + (44));
    compareLeft0 = value0;
    compareRight0 = 0u;
    if (compareLeft0 == compareRight0) {
    }
    if (compareLeft0 == compareRight0) {
        return;
    }
    func_0208b710((Unk0201ca6c *) value0);
    value0 = 0u;
    *(u32 *) ((value4) + (44)) = value0;
}
