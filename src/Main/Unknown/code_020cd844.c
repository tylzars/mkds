#include "Main/Unknown/code_020cd844.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_02095f30.h"
#include "Main/Unknown/code_02095f38.h"
#include "Main/Unknown/code_020b837c.h"
#include "Main/Unknown/code_020c0ba8.h"
#include "Main/Unknown/code_020c0d9c.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_02095000.h"

void func_020cd87c(void) {
    s32 i;
    s32 a;
    u32 n;
    Unk0217b498_00 *e;
    Vec3 *v;

    a = 0;
    n = func_020c0db0();
    for (i = 0; i < data_0217b45c->mUnk_08; i++) {
        if (func_020b5f68(&data_0217b45c->mUnk_0c[i]) != 0) {
            e = data_0217b45c->mUnk_00[i];
            if ((e->mUnk_02 & 1) == 0) {
                v = &e->mUnk_04;
                if (func_020b5ae8(v, &data_0217b45c->mUnk_10[a].mUnk_00, n, 0, 0) != 0) {
                    data_0217b45c->mUnk_10[a].mUnk_00.mUnk_04 -= func_02095f30(e) >> 14;
                    data_0217b45c->mUnk_10[a].mUnk_08 = func_020b83dc(func_02095f38(e) != 0 ? 0xab : 0xaa);
                    data_0217b45c->mUnk_10[a].mUnk_0c = func_020b4e70(v) != 0 ? 2 : 3;
                    a++;
                }
            }
        }
    }
    data_0217b45c->mUnk_04 = a;
}

void func_020cd860(Unk020c06c4 *a) {
    func_020c092c(a, data_0217b45c, 0);
}

s32 func_020cd844(void) {
    return func_020c0c2c(&data_0217b458, 0x1b1);
}
