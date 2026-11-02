#include "Main/Unknown/code_02145878.h"

#include "Main/Unknown/code_02145888.h"
#include "Main/Unknown/code_021458b4.h"

u32 func_021458b4(void) {
    u32 value0;
    value0 = (u32) &data_0217f9e0;
    value0 = (u32) * (const u32 *) ((value0) + (0));
    return value0;
}

void func_02145888(void) {
    u32 value0;
    u32 compareLeft0;
    u32 compareRight0;
    value0 = (u32) func_021458b4();
    compareLeft0 = value0;
    compareRight0 = 0u;
    if (compareLeft0 != compareRight0) {
    }
    if (compareLeft0 != compareRight0) {
    }
    if (compareLeft0 != compareRight0) {
        return;
    }
    func_0200fd1c();
}

void func_02145878(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    value1 = (u32) &data_0217f9e0;
    *(u32 *) ((value1) + (0)) = value0;
}
