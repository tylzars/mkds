#include "Main/Unknown/code_020810e4.h"
#include "Main/Unknown/code_0208b484.h"
#include "Main/Unknown/unk_0217a000.h"

void func_020810e4(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    u32 value4;
    u32 compareLeft0;
    u32 compareRight0;
    value2 = (u32) &gKartEffects;
    value1 = 0x58u;
    value2 = *(const u32 *) ((value2) + (0));
    value4 = (value0) * (value1) + (value2);
    value0 = *(const u32 *) ((value4) + (48));
    compareLeft0 = value0;
    compareRight0 = 0u;
    if (compareLeft0 == compareRight0) {
    }
    if (compareLeft0 == compareRight0) {
        return;
    }
    func_0208b710((Unk0201ca6c *) value0);
    value0 = 0u;
    *(u32 *) ((value4) + (48)) = value0;
}
