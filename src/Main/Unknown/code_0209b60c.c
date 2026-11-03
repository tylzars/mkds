#include "Main/Unknown/code_0209b60c.h"
#include "01/code_0219b250.h"

u32 func_0209b620(Unk0219b250 *arg0) {
    u32 value0 = (u32) arg0->mUnk_1c->mUnk_0c;
    value0 = (value0 << 4);
    value0 = (value0 >> 16);
    return value0;
}

u32 func_0209b60c(u32 arg0) {
    u32 value0 = arg0;
    value0 = (u32) * (const u32 *) ((value0) + (32));
    value0 = (u32) * (const u32 *) ((value0) + (12));
    value0 = (value0 << 4);
    value0 = (value0 >> 16);
    return value0;
}
