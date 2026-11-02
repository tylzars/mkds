#include "Main/Unknown/code_020bb51c.h"

#include "Main/Unknown/code_020bb530.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"

void func_020bb530(void) {
    Unk0217b3cc *p;

    p = func_02036bec(func_020364e0(func_020364e8()), 0x2c);
    data_0217b3cc = p;
    p->mUnk_00 = 0;
    data_0217b3cc->mUnk_04 = 0;
    data_0217b3cc->mUnk_08 = 0x13;
    data_0217b3cc->mUnk_0c = 0x13;
    data_0217b3cc->mUnk_10 = 0;
    data_0217b3cc->mUnk_14 = 0;
    data_0217b3cc->mUnk_18.mUnk_00 = 0;
    data_0217b3cc->mUnk_18.mUnk_04 = 0x1000;
    data_0217b3cc->mUnk_18.mUnk_08 = 0x1000;
    data_0217b3cc->mUnk_18.mUnk_0c = -0x666;
    data_0217b3cc->mUnk_18.mUnk_10 = 0x800;
}

u32 func_020bb51c(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &data_0217b3cc;
    value1 = 0u;
    *(u32 *) ((value0) + (0)) = value1;
    return value0;
}
