#include "Main/Unknown/code_020cdf18.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020b837c.h"
#include "Main/Unknown/code_020c0ba8.h"
#include "Main/Unknown/code_020c0d9c.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020931ac.h"

void func_020cdf50(void) {
    s32 i;
    s32 a;
    s32 b;
    u32 n;
    Unk0217b498_00 *e;
    Vec3 *v;

    a = 0;
    n = func_020c0db0();
    data_0217b470->mUnk_0c[0].mUnk_04++;
    if (data_0217b470->mUnk_0c[0].mUnk_04 < 0 || data_0217b470->mUnk_0c[0].mUnk_04 >= 8) {
        data_0217b470->mUnk_0c[0].mUnk_04 = 0;
    }
    b = data_0217b470->mUnk_0c[0].mUnk_04 < 4 ? 1 : 0;
    for (i = 0; i < data_0217b470->mUnk_08; i++) {
        e = data_0217b470->mUnk_00[i];
        if ((e->mUnk_02 & 1) == 0 && func_020931ac(e) != 0) {
            v = &e->mUnk_04;
            if (func_020b5ae8(v, &data_0217b470->mUnk_10[a].mUnk_00, n, 0, 0) != 0) {
                data_0217b470->mUnk_10[a].mUnk_08 = func_020b83dc(data_021759c0->mUnk_00 == 0x13 ? 0xae : 0xb2);
                data_0217b470->mUnk_10[a].mUnk_0c = func_020b4e70(v) != 0 ? 2 : 3;
                data_0217b470->mUnk_0c[a].mUnk_00 = b != 0 ? 0x1000 : 0xccd;
                a++;
            }
        }
    }
    data_0217b470->mUnk_04 = a;
}

void func_020cdf34(Unk020c06c4 *a) {
    func_020c06c4(a, data_0217b470, 0);
}

s32 func_020cdf18(void) {
    return func_020c0c2c(&data_0217b46c, 0x1ae);
}
