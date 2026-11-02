#include "Main/Unknown/code_020ccf6c.h"
#include "code_020222ec.h"
#include "Main/Unknown/code_020ae000.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020b837c.h"
#include "Main/Unknown/code_020c0ba8.h"
#include "Main/Unknown/code_020c0d9c.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/unk_021759c0.h"

void func_020cd1c0(void) {
    s32 i;
    s32 a;
    u32 n;
    Unk0217b498_00 *e;
    Vec3 *v;

    a = 0;
    n = func_020c0db0();
    for (i = 0; i < data_0217b448->mUnk_08; i++) {
        e = data_0217b448->mUnk_00[i];
        if ((e->mUnk_02 & 2) == 0) {
            v = &e->mUnk_04;
            if (func_020b5ae8(v, &data_0217b448->mUnk_10[a].mUnk_00, n, 1, 1) != 0) {
                data_0217b448->mUnk_10[a].mUnk_08 = func_020b83dc(0x90);
                data_0217b448->mUnk_10[a].mUnk_0c = func_020b4e70(v) != 0 ? 2 : 3;
                data_0217b448->mUnk_10[a].mUnk_0e = e->mUnk_02 & 0x400;
                data_0217b448->mUnk_10[a].mUnk_10 = e->mUnk_7e;
                a++;
            }
        }
    }
    data_0217b448->mUnk_04 = a;
}

void func_020ccf88(Unk020c06c4 *a) {
    s32 i;
    s32 c;
    u16 d;
    u16 h;
    s32 w;
    u16 k;
    Unk0217b498_10 *x;
    s32 v1[4];
    s32 z[2];
    s32 x0;
    struct Unk020224e0_c *x8;
    s32 x4;

    c = func_020c0dc4();
    d = func_020b6368();
    for (i = 0; i < data_0217b448->mUnk_04; i++) {
        h = data_0217b448->mUnk_10[i].mUnk_0c;
        if (c <= h) {
            if (data_0217b448->mUnk_10[i].mUnk_0e != 0) {
                if (data_021759c0->mUnk_57 != 0) {
                    func_020b4c74(v1, (u16) (d + (data_0217b448->mUnk_10[i].mUnk_10 + 0x4000)));
                } else {
                    func_020b4c74(v1, (u16) (0x4000 - data_0217b448->mUnk_10[i].mUnk_10 - d));
                }
            } else {
                if (data_021759c0->mUnk_57 != 0) {
                    func_020b4cb0(v1, (u16) (data_0217b448->mUnk_10[i].mUnk_10 + 0x4000 - d));
                } else {
                    func_020b4cb0(v1, (u16) (d + (0x4000 - data_0217b448->mUnk_10[i].mUnk_10)));
                }
            }
            k = func_020ae5c4(a);
            a->mUnk_000.mUnk_20[k].mUnk_06 = v1[0] >> 4;
            a->mUnk_000.mUnk_20[k].mUnk_0e = v1[1] >> 4;
            a->mUnk_000.mUnk_20[k].mUnk_16 = v1[2] >> 4;
            a->mUnk_000.mUnk_20[k].mUnk_1e = v1[3] >> 4;
            w = a->mUnk_400;
            x = &data_0217b448->mUnk_10[i];
            x0 = x->mUnk_00.mUnk_00;
            x8 = x->mUnk_08;
            x4 = x->mUnk_00.mUnk_04;
            z[0] = x0 << 12;
            z[1] = x4 << 12;
            a->mUnk_400 += func_020224e0((Unk020224e0_o *) &a->mUnk_000.mUnk_00[w], 0x80 - w, x8, v1, z, k, 1);
            for (; w < a->mUnk_400; w++) {
                if (h != -1) {
                    a->mUnk_000.mUnk_00[w].mUnk_0e = h;
                }
            }
        }
    }
}

s32 func_020ccf6c(void) {
    return func_020c0c2c(&data_0217b444, 0x1a2);
}
