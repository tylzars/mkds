#include "Main/Unknown/code_020c8098.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020b837c.h"
#include "Main/Unknown/code_020c0000.h"
#include "Main/Unknown/code_020c0b84.h"
#include "Main/Unknown/code_020c0d9c.h"
#include "Main/Unknown/code_020de9f8.h"
#include "Main/Unknown/code_020e0680.h"
#include "Main/Unknown/unk_0217b000.h"

void func_020c80cc(void) {
    s32 i;
    s32 n;
    Unk020e1e98 *p;
    Vec3 *v;
    u32 a;
    u16 t;
    u16 w;

    n = 0;
    a = func_020c0db0();
    for (i = 0; i < data_0217b420->mUnk_08; i++) {
        p = (Unk020e1e98 *) data_0217b420->mUnk_00[i];
        v = &p->mUnk_000.mUnk_04;
        if (func_020b5ae8(&p->mUnk_000.mUnk_04, &data_0217b420->mUnk_10[n].mUnk_00, a, 1, 1) != 0) {
            t = p->mUnk_000.mUnk_00;
            w = p->mUnk_000.mUnk_7e;
            switch (t) {
                case 0x19a:
                    data_0217b420->mUnk_10[n].mUnk_08 = GetRaceSNcerEntry(p->mUnk_130 + 0x95);
                    break;
                case 0x195:
                    data_0217b420->mUnk_10[n].mUnk_08 = GetRaceSNcerEntry(0x93);
                    break;
                case 0x19c:
                    data_0217b420->mUnk_10[n].mUnk_08 = GetRaceSNcerEntry(0x94);
                    break;
            }
            data_0217b420->mUnk_10[n].mUnk_0c = func_020b4e70((Vec3 *) &v) != 0 ? 2 : 3;
            data_0217b420->mUnk_10[n].mUnk_10 = w;
            n++;
        }
    }
    data_0217b420->mUnk_04 = n;
}

void func_020c80b0(Unk020c06c4 *a) {
    func_020c092c(a, data_0217b420, 1);
}

s32 func_020c8098(void) {
    return func_020c0c2c(&data_0217b41c, 0xca);
}
