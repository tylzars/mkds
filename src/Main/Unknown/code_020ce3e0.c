#include "Main/Unknown/code_020ce3e0.h"
#include "Main/Unknown/code_02092194.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020b837c.h"
#include "Main/Unknown/code_020c0ba8.h"
#include "Main/Unknown/code_020c0d9c.h"
#include "Main/Unknown/unk_0217b000.h"

void func_020ce414(void) {
    s32 i;
    s32 a;
    u32 n;
    u32 m;
    Unk0217b498_00 *e;
    Vec3 *v;
    void *w;

    a = 0;
    n = func_020c0db0();
    for (i = 0; i < data_0217b47c->mUnk_08; i++) {
        e = data_0217b47c->mUnk_00[i];
        if ((e->mUnk_02 & 1) == 0) {
            m = func_02092194(e);
            if (m != 0) {
                v = &e->mUnk_04;
                if (func_020b5ae8(v, &data_0217b47c->mUnk_10[a].mUnk_00, n, 1, 1) != 0) {
                    if (m == 2) {
                        w = func_020b83dc(0xb5);
                    } else {
                        w = func_020b83dc(0xb4);
                    }
                    data_0217b47c->mUnk_10[a].mUnk_08 = w;
                    data_0217b47c->mUnk_10[a].mUnk_0c = func_020b4e70(v) != 0 ? 2 : 3;
                    a++;
                }
            }
        }
    }
    data_0217b47c->mUnk_04 = a;
}

void func_020ce3f8(Unk020c06c4 *a) {
    func_020c092c(a, data_0217b47c, 0);
}

s32 func_020ce3e0(void) {
    return func_020c0c2c(&data_0217b478, 0x198);
}
