#include "Main/Unknown/code_020c06c4.h"
#include "Main/Unknown/code_020c0ba8.h"
#include "Main/Unknown/code_020c77a0.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020b837c.h"
#include "Main/Unknown/code_020c0000.h"
#include "Main/Unknown/code_020c0b84.h"
#include "Main/Unknown/code_020c0d9c.h"
#include "Main/Unknown/code_020daf20.h"
#include "Main/Unknown/code_020de9f8.h"
#include "Main/Unknown/code_020e0680.h"
#include "Main/Unknown/code_021000d0.h"
#include "Main/Unknown/unk_0217b000.h"

void func_020c783c(void) {
    s32 i;
    s32 n;
    Unk0217b498_00 *p;
    u32 a;
    s32 t;

    n = 0;
    a = func_020c0db0();
    for (i = 0; i < data_0217b408->mUnk_08; i++) {
        if (func_020b5f68(&data_0217b408->mUnk_0c[i]) != 0) {
            p = data_0217b408->mUnk_00[i];
            if (func_020b5ae8(&p->mUnk_04, &data_0217b408->mUnk_10[n].mUnk_00, a, 0, 0) != 0) {
                data_0217b408->mUnk_10[n].mUnk_08 = GetRaceSNcerEntry(0xaf);
                data_0217b408->mUnk_10[n].mUnk_0c = 1;
                data_0217b408->mUnk_10[n + 1].mUnk_00 = data_0217b408->mUnk_10[(u32) n].mUnk_00;
                data_0217b408->mUnk_10[n + 1].mUnk_08 = GetRaceSNcerEntry(0xb0);
                data_0217b408->mUnk_10[n + 1].mUnk_0c = 2;
                n += 2;
                t = func_020db4c4((Unk020db2b8 *) p) * 16 >> 12;
                data_0217b408->mUnk_10[n - 2].mUnk_00.mUnk_04 -= t;
            }
        }
    }
    data_0217b408->mUnk_04 = n;
}

void func_020c7820(Unk020c06c4 *a) {
    func_020c092c(a, data_0217b408, 0);
}

s32 func_020c77a0(void) {
    u16 a[2] = {0x196, 0x1a5};
    u16 i;
    u16 b;

    for (i = 0; i < 2; i++) {
        b = a[i];
        if (func_021000d0(b) != NULL) {
            return func_020c0c2c(&data_0217b404, b);
        }
    }
    return 0;
}
