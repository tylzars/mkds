#include "Main/Unknown/code_020ced10.h"

#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020b837c.h"
#include "Main/Unknown/code_020c0000.h"
#include "Main/Unknown/code_020c0d9c.h"
#include "Main/Unknown/code_020cedf8.h"

void func_020cedf8(void) {
    u32 value0;
    u32 value12;
    value12 = (u32) &func_020c0b84;
    value0 = (u32) &data_0217b484;
    func_020c0b84((Unk0217b498 **) value0);
}

void func_020ced2c(void) {
    s32 i;
    s32 n;
    s32 v;
    Unk0217b498_00 *e;

    n = 0;
    v = func_020c0db0();
    for (i = 0; i < data_0217b484->mUnk_08; i++) {
        e = data_0217b484->mUnk_00[i];
        if ((e->mUnk_02 & 1) == 0) {
            if (func_020b5ae8(&e->mUnk_04, &data_0217b484->mUnk_10[n].mUnk_00, v, 1, 1) != 0) {
                data_0217b484->mUnk_10[n].mUnk_08 = GetRaceSNcerEntry(0xa4);
                data_0217b484->mUnk_10[n].mUnk_0c = 2;
                n++;
            }
        }
    }
    data_0217b484->mUnk_04 = n;
}

void func_020ced10(Unk020c06c4 *a) {
    func_020c092c(a, data_0217b484, 0);
}
