#include "Main/Unknown/code_020c7d54.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020b837c.h"
#include "Main/Unknown/code_020c0000.h"
#include "Main/Unknown/code_020c0b84.h"
#include "Main/Unknown/code_020c0d9c.h"
#include "Main/Unknown/code_020de9f8.h"
#include "Main/Unknown/code_020e0680.h"
#include "Main/Unknown/unk_0217b000.h"

void func_020c7d8c(void) {
    s32 i;
    s32 n;
    Unk0217b498_00 *p;
    u32 a;
    s32 v;
    s32 w;

    n = 0;
    a = func_020c0db0();
    for (i = 0; i < data_0217b418->mUnk_08; i++) {
        if (func_020b5f68(&data_0217b418->mUnk_0c[i]) != 0) {
            p = data_0217b418->mUnk_00[i];
            if (func_020b5ae8(&p->mUnk_04, &data_0217b418->mUnk_10[n].mUnk_00, a, 0, 0) != 0) {
                v = p->mUnk_04.y - p->mUnk_a8;
                if (v >= -0x9000) {
                    w = v > 0 ? 1 : 0;
                    data_0217b418->mUnk_10[n].mUnk_08 = func_020b83dc(w != 0 ? 0xa7 : 0xa8);
                    data_0217b418->mUnk_10[n].mUnk_0c = w != 0 ? 1 : 2;
                    data_0217b418->mUnk_10[n + 1].mUnk_00 = data_0217b418->mUnk_10[n].mUnk_00;
                    data_0217b418->mUnk_10[n + 1].mUnk_08 = func_020b83dc(0xa9);
                    data_0217b418->mUnk_10[n + 1].mUnk_0c = 2;
                    n += 2;
                    data_0217b418->mUnk_10[n - 2].mUnk_00.mUnk_04 -= v >> 14;
                } else {
                    data_0217b418->mUnk_10[n].mUnk_08 = func_020b83dc(0xa9);
                    data_0217b418->mUnk_10[n].mUnk_0c = 2;
                    n++;
                }
            }
        }
    }
    data_0217b418->mUnk_04 = n;
}

void func_020c7d70(Unk020c06c4 *a) {
    func_020c092c(a, data_0217b418, 0);
}

s32 func_020c7d54(void) {
    return func_020c0c2c(&data_0217b414, 0x19b);
}
