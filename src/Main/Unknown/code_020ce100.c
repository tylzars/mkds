#include "Main/Unknown/code_020ce100.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020b837c.h"
#include "Main/Unknown/code_020c0ba8.h"
#include "Main/Unknown/code_020c0d9c.h"
#include "Main/Unknown/unk_0217b000.h"

void func_020ce134(void) {
    s32 i;
    s32 a;
    u32 n;
    Unk0217b498_00 *e;
    Vec3 *v;

    a = 0;
    n = func_020c0db0();
    for (i = 0; i < data_0217b474->mUnk_08; i++) {
        e = data_0217b474->mUnk_00[i];
        v = &e->mUnk_04;
        if (func_020b5ae8(v, &data_0217b474->mUnk_10[a].mUnk_00, n, 1, 1) != 0) {
            data_0217b474->mUnk_10[a].mUnk_08 = GetRaceSNcerEntry(0x91);
            data_0217b474->mUnk_10[a].mUnk_0c = func_020b4e70(v) != 0 ? 2 : 3;
            data_0217b474->mUnk_10[a].mUnk_10 = e->mUnk_7e;
            data_0217b474->mUnk_0c[a].mUnk_00 = e->mUnk_1c / 6;
            a++;
        }
    }
    data_0217b474->mUnk_04 = a;
}

void func_020ce118(Unk020c06c4 *a) {
    func_020c06c4(a, data_0217b474, 1);
}

s32 func_020ce100(void) {
    return func_020c0c2c(&data_0217b470, 0x1a4);
}
