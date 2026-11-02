#include "Main/Unknown/code_020cffd0.h"

#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020b837c.h"
#include "Main/Unknown/code_020c0000.h"
#include "Main/Unknown/code_020c0d9c.h"
#include "Main/Unknown/code_020d0108.h"

void func_020d0108(void) {
    u32 value0;
    u32 value12;
    value12 = (u32) &func_020c0b84;
    value0 = (u32) &data_0217b494;
    func_020c0b84((Unk0217b498 **) value0);
}

void func_020cffec(void) {
    s32 i;
    s32 n;
    s32 v;
    Unk0217b498_00 *e;
    Vec3 *p;

    n = 0;
    v = func_020c0db0();
    for (i = 0; i < data_0217b494->mUnk_08; i++) {
        e = data_0217b494->mUnk_00[i];
        p = &e->mUnk_04;
        if (func_020b5ae8(p, &data_0217b494->mUnk_10[n].mUnk_00, v, 1, 1) != 0) {
            data_0217b494->mUnk_10[n].mUnk_08 = GetRaceSNcerEntry(0xb7);
            data_0217b494->mUnk_10[n].mUnk_0c = func_020b4e70(p) != 0 ? 2 : 3;
            data_0217b494->mUnk_10[n].mUnk_10 = e->mUnk_7e;
            data_0217b494->mUnk_0c[n].mUnk_00 = e->mUnk_1c / 6;
            n++;
        }
    }
    data_0217b494->mUnk_04 = n;
}

void func_020cffd0(Unk020c06c4 *a) {
    func_020c06c4(a, data_0217b494, 1);
}
