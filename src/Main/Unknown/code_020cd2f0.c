#include "Main/Unknown/code_020cd2f0.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020b837c.h"
#include "Main/Unknown/code_020c0ba8.h"
#include "Main/Unknown/code_020c0d9c.h"
#include "Main/Unknown/unk_0217b000.h"

void func_020cd328(void) {
    s32 i;
    s32 a;
    u32 n;
    Unk0217b498_00 *e;
    Vec3 *v;

    a = 0;
    n = func_020c0db0();
    for (i = 0; i < data_0217b44c->mUnk_08; i++) {
        if (func_020b5f68(&data_0217b44c->mUnk_0c[i]) != 0) {
            e = data_0217b44c->mUnk_00[i];
            if ((e->mUnk_02 & 1) == 0) {
                v = &e->mUnk_04;
                if (func_020b5ae8(v, &data_0217b44c->mUnk_10[a].mUnk_00, n, 0, 0) != 0) {
                    data_0217b44c->mUnk_10[a].mUnk_08 = GetRaceSNcerEntry(0x5c);
                    data_0217b44c->mUnk_10[a].mUnk_0c = func_020b4e70(v) != 0 ? 2 : 3;
                    a++;
                }
            }
        }
    }
    data_0217b44c->mUnk_04 = a;
}

void func_020cd30c(Unk020c06c4 *a) {
    func_020c092c(a, data_0217b44c, 0);
}

s32 func_020cd2f0(void) {
    return func_020c0c2c(&data_0217b448, 0x1a9);
}
