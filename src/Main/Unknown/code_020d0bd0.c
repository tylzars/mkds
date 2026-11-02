#include "Main/Unknown/code_020d0bd0.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020b837c.h"
#include "Main/Unknown/code_020c0000.h"
#include "Main/Unknown/code_020c0d9c.h"
#include "Main/Unknown/code_020d011c.h"
#include "Main/Unknown/code_020d0280.h"

void func_020d0cd8(void) {
    s32 i;
    s32 n;
    s32 v;
    u32 a;
    Unk0217b498_00 *e;
    Vec3 *p;

    n = 0;
    a = func_020c0db0();
    data_0217b4a0->mUnk_0c->mUnk_04++;
    if (data_0217b4a0->mUnk_0c->mUnk_04 < 0 || data_0217b4a0->mUnk_0c->mUnk_04 >= 0x14) {
        data_0217b4a0->mUnk_0c->mUnk_04 = 0;
    }
    v = data_0217b4a0->mUnk_0c->mUnk_04 < 10;
    for (i = 0; i < data_0217b4a0->mUnk_08; i++) {
        e = data_0217b4a0->mUnk_00[i];
        p = &e->mUnk_04;
        if (func_020b5ae8(p, (UnkPair020b502c *) &data_0217b4a0->mUnk_10[n], a, 1, 1) == 0) {
            continue;
        }
        data_0217b4a0->mUnk_10[n].mUnk_08 = func_020b83dc(v != 0 ? 0xa5 : 0xa6);
        data_0217b4a0->mUnk_10[n].mUnk_0c = 1;
        data_0217b4a0->mUnk_10[n].mUnk_0e = 0;
        data_0217b4a0->mUnk_10[n].mUnk_10 = e->mUnk_7e;
        n++;
    }
    data_0217b4a0->mUnk_04 = n;
}

void func_020d0cbc(void *a) {
    func_020c092c(a, data_0217b4a0, 1);
}

void func_020d0bd0(void) {
    u16 i;

    data_0217b49c = func_02036bec(func_020364e0(func_020364e8()), 0xb0);
    data_0217b49c->mUnk_00.mUnk_00 = 0;
    data_0217b49c->mUnk_00.mUnk_04 = 0;
    data_0217b49c->mUnk_00.mUnk_08 = 0;
    data_0217b49c->mUnk_00.mUnk_0c = 0;
    data_0217b49c->mUnk_00.mUnk_10 = 0;
    data_0217b49c->mUnk_00.mUnk_14 = 0;
    data_0217b49c->mUnk_00.mUnk_18 = 0;
    for (i = 0; i < 5; i++) {
        data_0217b49c->mUnk_1c[i].mUnk_00 = 0;
        data_0217b49c->mUnk_1c[i].mUnk_04 = 0;
        data_0217b49c->mUnk_1c[i].mUnk_08 = 0;
        data_0217b49c->mUnk_1c[i].mUnk_0c = 0;
        data_0217b49c->mUnk_1c[i].mUnk_10 = 0;
        data_0217b49c->mUnk_1c[i].mUnk_14 = 0;
        data_0217b49c->mUnk_1c[i].mUnk_18 = 0;
    }
    data_0217b49c->mUnk_a8 = 0;
    data_0217b49c->mUnk_ac = 0;
}
