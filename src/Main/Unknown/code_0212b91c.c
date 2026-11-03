#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_0212b91c.h"

#include "Main/Unknown/code_0212b928.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "code_0214d018.h"

#pragma thumb on
void func_0212b928(void *a, Unk020b4a44 *b, u32 c) {
    s32 i;
    s32 v;
    data_0217d410 = func_02036bec(a, 0x90);
    data_0217d410->mUnk_00 = 0;
    data_0217d410->mUnk_04 = 0;
    data_0217d410->mUnk_08 = c;
    data_0217d410->mUnk_8c = 1;
    func_0214d1fc(b->mUnk_0c + c * 0x10, data_0217d410->mUnk_0a, 0x20);
    for (i = 0; i < 4; i++) {
        v = data_0217d410->mUnk_14[i];
        data_0217d410->mUnk_2c[i].mUnk_00 = v & 0x1f;
        data_0217d410->mUnk_2c[i].mUnk_04 = (v & 0x3e0) >> 5;
        data_0217d410->mUnk_2c[i].mUnk_08 = (v & 0x7c00) >> 10;
    }
    for (i = 0; i < 4; i++) {
        v = data_0217d410->mUnk_1c[i];
        data_0217d410->mUnk_5c[i].mUnk_00 = v & 0x1f;
        data_0217d410->mUnk_5c[i].mUnk_04 = (v & 0x3e0) >> 5;
        data_0217d410->mUnk_5c[i].mUnk_08 = (v & 0x7c00) >> 10;
    }
}
#pragma thumb off

#pragma thumb on
void func_0212b91c(void) {
    u32 value0;
    u32 value1;
    value1 = 0u;
    value0 = (u32) &data_0217d410;
    *(u32 *) ((value0) + 0u) = value1;
}
#pragma thumb off
