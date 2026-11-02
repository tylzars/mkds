#include "Main/Unknown/code_020f3678.h"

#include "Main/Unknown/code_020f36a0.h"
#include "Main/Unknown/code_020b502c.h"

s32 func_020f36a0(u32 a, u32 *b) {
    if (a >= 0xff) {
        *b = 0;
    } else {
        *b = gCourseMap->mUnk_b0 + a * 0x28;
    }
    b[1] = 1;
    return 1;
}

u32 func_020f3678(u32 arg0, u32 arg1) {
    u32 value0 = arg0;
    u32 value1 = arg1;
    u32 value2;
    value2 = (u32) * (const s8 *) ((value0) + (33));
    value2 = (value2 << 6);
    *(u32 *) ((value1) + (0)) = value2;
    value2 = (u32) * (const s8 *) ((value0) + (34));
    value2 = (value2 << 6);
    *(u32 *) ((value1) + (4)) = value2;
    value0 = (u32) * (const s8 *) ((value0) + (35));
    value0 = (value0 << 6);
    *(u32 *) ((value1) + (8)) = value0;
    return value0;
}
