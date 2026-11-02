#include "Main/Unknown/code_020c7464.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020b837c.h"
#include "Main/Unknown/code_020c0000.h"
#include "Main/Unknown/code_020c0b84.h"
#include "Main/Unknown/code_020c0d9c.h"
#include "Main/Unknown/code_020de9f8.h"
#include "Main/Unknown/code_020e0680.h"
#include "Main/Unknown/code_021000d0.h"
#include "Main/Unknown/unk_0217b000.h"

void func_020c756c(void) {
    s32 i;
    s32 n;
    Unk0217b498_00 *p;
    Vec3 *v;
    u32 a;

    n = 0;
    a = func_020c0db0();
    for (i = 0; i < data_0217b400->mUnk_08; i++) {
        if (func_020b5f68(&data_0217b400->mUnk_0c[i]) != 0) {
            p = data_0217b400->mUnk_00[i];
            if ((p->mUnk_02 & 1) == 0) {
                v = &p->mUnk_04;
                if (func_020b5ae8(v, &data_0217b400->mUnk_10[n].mUnk_00, a, 0, 0) != 0) {
                    data_0217b400->mUnk_10[n].mUnk_08 = GetRaceSNcerEntry(0x8c);
                    data_0217b400->mUnk_10[n].mUnk_0c = func_020b4e70(v) != 0 ? 2 : 3;
                    n++;
                }
            }
        }
    }
    data_0217b400->mUnk_04 = n;
}

void func_020c7550(Unk020c06c4 *a) {
    func_020c092c(a, data_0217b400, 0);
}

s32 func_020c7464(void) {
    u16 a[2] = {0x65, 0xc9};
    u16 i;
    u16 b;
    s32 n;
    s32 m;
    s32 j;

    for (i = 0; i < 2; i++) {
        b = a[i];
        if (func_021000d0(b) != 0) {
            n = func_020c0c2c(&data_0217b3fc, b);
            m = 0;
            for (j = 0; j < data_0217b3fc->mUnk_08; j++) {
                s32 v = func_020de9f8((Unk020de6a8 *) data_0217b3fc->mUnk_00[j]);
                if (v > m) {
                    m = v;
                }
            }
            if (m < 0x3e8000) {
                data_0217b3f8 = 1;
            } else {
                data_0217b3f8 = 0;
            }
            return n;
        }
    }
    return 0;
}
