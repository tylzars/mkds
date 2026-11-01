#include "Main/Unknown/code_020c06c4.h"
#include "Main/Unknown/code_020ae000.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/unk_021759c0.h"
#include "code_020222ec.h"

void func_020c092c(Unk020c06c4 *a, Unk0217b498 *b, s32 c) {
    s32 i;
    s32 l;
    u16 v;
    u16 n;
    s32 d[4];
    s32 e[2];
    s32 p;
    s32 q;
    s32 k;
    Unk020c06c4_08 *t;
    Unk0217b498_10 *r;
    s32 x;
    s32 y;
    void *z;

    l = data_0217b3dc->mUnk_000;
    if (c != 0) {
        v = func_020b6368();
    }
    for (i = 0; i < b->mUnk_04; i++) {
        p = b->mUnk_10[i].mUnk_0c;
        if (l <= p) {
            q = b->mUnk_10[i].mUnk_0e;
            n = 0;
            if (c != 0) {
                if (data_021759c0->mUnk_57 != 0) {
                    func_020b4cb0(d, (u16) (b->mUnk_10[i].mUnk_10 + 0x8000 - v));
                } else {
                    func_020b4cb0(d, (u16) (v + (0x8000 - b->mUnk_10[i].mUnk_10)));
                }
                n = func_020ae5c4(a);
                a->mUnk_000.mUnk_20[n].mUnk_06 = d[0] >> 4;
                a->mUnk_000.mUnk_20[n].mUnk_0e = d[1] >> 4;
                a->mUnk_000.mUnk_20[n].mUnk_16 = d[2] >> 4;
                a->mUnk_000.mUnk_20[n].mUnk_1e = d[3] >> 4;
            }
            r = &b->mUnk_10[i];
            x = r->mUnk_00.mUnk_00;
            z = r->mUnk_08;
            y = r->mUnk_00.mUnk_04;
            k = a->mUnk_400;
            e[0] = x << 12;
            e[1] = y << 12;
            a->mUnk_400 +=
                func_020224e0((Unk020224e0_o *) &a->mUnk_000.mUnk_00[k], 0x80 - k, z, c != 0 ? d : 0, e, n, 1);
            t = &a->mUnk_000.mUnk_00[k];
            for (; k < a->mUnk_400; k++, t++) {
                if ((q != 0 ? 1 : -1) != -1) {
                    t->mUnk_0a = q != 0 ? 1 : -1;
                }
                if (p != -1) {
                    t->mUnk_0e = p;
                }
            }
        }
    }
}

void func_020c06c4(Unk020c06c4 *a, Unk0217b498 *b, s32 c) {
    s32 i;
    s32 l;
    u16 v;
    s32 d[4];
    s32 e[2];
    s32 p;
    s32 q;
    s32 k;
    u16 n;
    Unk020c06c4_08 *t;
    Unk0217b498_10 *r;
    s32 x;
    s32 y;
    void *z;

    l = data_0217b3dc->mUnk_000;
    if (c != 0) {
        v = func_020b6368();
    }
    for (i = 0; i < b->mUnk_04; i++) {
        p = b->mUnk_10[i].mUnk_0c;
        if (l <= p) {
            q = b->mUnk_10[i].mUnk_0e;
            if (c != 0) {
                if (data_021759c0->mUnk_57 != 0) {
                    func_020b4bf8(d, b->mUnk_0c[i].mUnk_00, (u16) (b->mUnk_10[i].mUnk_10 - v));
                } else {
                    func_020b4bf8(d, b->mUnk_0c[i].mUnk_00, (u16) (v - b->mUnk_10[i].mUnk_10));
                }
            } else {
                func_020b4cec(d, b->mUnk_0c[i].mUnk_00);
            }
            n = func_020ae5c4(a);
            a->mUnk_000.mUnk_20[n].mUnk_06 = d[0] >> 4;
            a->mUnk_000.mUnk_20[n].mUnk_0e = d[1] >> 4;
            a->mUnk_000.mUnk_20[n].mUnk_16 = d[2] >> 4;
            a->mUnk_000.mUnk_20[n].mUnk_1e = d[3] >> 4;
            r = &b->mUnk_10[i];
            x = r->mUnk_00.mUnk_00;
            z = r->mUnk_08;
            y = r->mUnk_00.mUnk_04;
            k = a->mUnk_400;
            e[0] = x << 12;
            e[1] = y << 12;
            a->mUnk_400 += func_020224e0((Unk020224e0_o *) &a->mUnk_000.mUnk_00[k], 0x80 - k, z, d, e, n, 1);
            t = &a->mUnk_000.mUnk_00[k];
            for (; k < a->mUnk_400; k++, t++) {
                if ((q != 0 ? 1 : -1) != -1) {
                    t->mUnk_0a = q != 0 ? 1 : -1;
                }
                if (p != -1) {
                    t->mUnk_0e = p;
                }
            }
        }
    }
}
