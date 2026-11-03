#include "Main/Unknown/code_020ae428.h"
#include "Main/Unknown/code_020c3e44.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020b1cf4.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/unk_027e0000.h"
#include "Main/Unknown/code_020ae000.h"
#include "Main/Unknown/code_020b837c.h"
#include "code_020222ec.h"
#include "Main/Unknown/code_020b3000.h"
#include "Main/Unknown/code_020c4bec.h"

void func_020c43c4(void) {
    Unk0206bcb0 *p;
    Unk0217b3e4 *d;
    u16 j;
    s32 n;
    u32 i;

    if (data_021759c0->mUnk_08 != 1) {
        return;
    }
    if (func_020b33d8() == 0) {
        return;
    }
    if ((u16) (data_02175628[func_020435bc()].mUnk_00 & 4) != 0) {
        data_0217b3e4->mUnk_000 = data_0217b3e4->mUnk_000 == 0 ? 1 : 0;
    }
    for (i = 0; i < data_021759c0->mUnk_3d0; i = (u16) (i + 1)) {
        if ((data_027e00c8)[i].mUnk_204 != 0) {
            n = data_0217b3e4->mUnk_790[i].mUnk_00;
            data_0217b3e4->mUnk_790[i].mUnk_00 = n + 1;
            ((void (*)(Vec3 *, s32)) func_0207a91c)(&data_0217b3e4->mUnk_790[i].mUnk_04[n], i);
            data_0217b3e4->mUnk_790[i].mUnk_28[n] = func_020b4e70(&data_0217b3e4->mUnk_790[i].mUnk_04[n]) != 0 ? 2 : 3;
        }
    }
    data_0217b3e4->mUnk_00c++;
    if (data_0217b3e4->mUnk_00c > 0xf) {
        data_0217b3e4->mUnk_00c = 0;
        for (i = 0; i < data_021759c0->mUnk_3d0; i = (u16) (i + 1)) {
            for (j = 0; j < data_0217b3e4->mUnk_790[i].mUnk_00; j = (u16) (j + 1)) {
                if (data_0217b3e4->mUnk_790[i].mUnk_34[j] < 0x28) {
                    data_0217b3e4->mUnk_790[i].mUnk_34[j]++;
                }
            }
        }
        func_020b1d50();
        func_020b1d50();
        for (i = 0; i < data_021759c0->mUnk_3d0; i = (u16) (i + 1)) {
            p = func_0207a974(i);
            d = data_0217b3e4;
            for (j = 0x27; j != 0; j--) {
                d->mUnk_010[i][j] = d->mUnk_010[i][j - 1];
            }
            func_0207a91c(&data_0217b3e4->mUnk_010[i][0].mUnk_00, i);
            data_0217b3e4->mUnk_010[i][0].mUnk_14 = func_020b4e70(&data_0217b3e4->mUnk_010[i][0].mUnk_00) != 0 ? 2 : 3;
            data_0217b3e4->mUnk_010[i][0].mUnk_0c = func_020b6338(i);
            if ((p->mUnk_44 & 0xa) != 0) {
                data_0217b3e4->mUnk_010[i][0].mUnk_10 = 2;
            } else if ((p->mUnk_48 & 0x80020) != 0) {
                data_0217b3e4->mUnk_010[i][0].mUnk_10 = 3;
            } else {
                data_0217b3e4->mUnk_010[i][0].mUnk_10 = 1;
            }
            if (data_0217561c->mUnk_4cc != 0) {
                data_0217b3e4->mUnk_010[i][0].mUnk_10 = 0;
                data_0217b3e4->mUnk_004[i] = 0;
            }
        }
    }
}

void func_020c3e44(Unk020c06c4 *a) {
    UnkPair020b502c o1;
    UnkPair020b502c o2;
    s32 w1[2];
    s32 w2[2];
    u16 c;
    void *r;
    float f;
    s32 v;
    s32 s;
    s32 i;
    s32 j;
    u32 m;
    s32 n;
    Unk020c06c4_08 *e;
    void *q;
    u32 h;
    s32 d;
    Unk020c06c4_08 *p;

    if (data_021759c0->mUnk_08 != 1) {
        return;
    }
    if (data_0217b3e4->mUnk_000 == 0) {
        return;
    }
    c = func_020ae5c4(a);
    for (i = 1; i < 16; i++) {
        func_020ae5c4(a);
    }
    if ((s32) (func_020b1d50() * 3) > 0) {
        f = (float) (s32) (func_020b1d50() * 0x3000) + 0.5f;
    } else {
        f = (float) (s32) (func_020b1d50() * 0x3000) - 0.5f;
    }
    v = f;
    s = ((s64) v * 20) >> 12;
    for (i = 0; i < data_021759c0->mUnk_3d0; i++) {
        if (data_0217b3e4->mUnk_004[i] != 0) {
            if (data_0217561c->mUnk_4cc == 0) {
                for (j = 0; j < data_0217b3e4->mUnk_790[i].mUnk_00; j++) {
                    if (data_0217b3e4->mUnk_790[i].mUnk_34[j] < 0x28) {
                        if (func_020b5ae8(&data_0217b3e4->mUnk_790[i].mUnk_04[j], &o1, s, 1, 1) != 0) {
                            m = data_0217b3e4->mUnk_790[i].mUnk_28[j];
                            q = GetRaceSNcerEntry(0x4f);
                            n = a->mUnk_400;
                            w1[0] = o1.mUnk_00 << 12;
                            w1[1] = o1.mUnk_04 << 12;
                            e = &a->mUnk_000.mUnk_00[n];
                            a->mUnk_400 += func_020224e0((Unk020224e0_o *) e, 0x80 - n, q, NULL, w1, 0, 1);
                            for (; n < a->mUnk_400; n++, e++) {
                                if (m != -1) {
                                    e->mUnk_0e = m;
                                }
                            }
                        }
                    }
                }
            }
            for (j = 0; j < 0x28; j++) {
                u16 x = (u16) (data_0217b3e4->mUnk_010[i][j].mUnk_0c + func_020b6368()) + 0x800;
                u16 y = ((x << 4) / 0x10000) % 16;
                if (func_020b5ae8(&data_0217b3e4->mUnk_010[i][j].mUnk_00, &o2, s, 1, 1) != 0) {
                    switch (data_0217b3e4->mUnk_010[i][j].mUnk_10) {
                        case 0:
                            r = NULL;
                            break;
                        case 1:
                            r = GetRaceSNcerEntry(0x51);
                            break;
                        case 2:
                            r = GetRaceSNcerEntry(0x52);
                            break;
                        case 3:
                            r = GetRaceSNcerEntry(0x53);
                            break;
                    }
                    if (r != NULL) {
                        h = data_0217b3e4->mUnk_010[i][j].mUnk_14;
                        d = a->mUnk_400;
                        w2[0] = o2.mUnk_00 << 12;
                        w2[1] = o2.mUnk_04 << 12;
                        p = &a->mUnk_000.mUnk_00[d];
                        a->mUnk_400 += func_020224e0((Unk020224e0_o *) p, 0x80 - d, r,
                                                     &data_0217b3e4->mUnk_810[y].mUnk_00, w2, (u16) (y + c), 1);
                        for (; d < a->mUnk_400; d++, p++) {
                            if ((i != 0 ? 1 : -1) != -1) {
                                p->mUnk_0a = i != 0 ? 1 : -1;
                            }
                            if (h != -1) {
                                p->mUnk_0e = h;
                            }
                        }
                    }
                }
            }
        }
    }
    for (i = 0; i < 16; i++) {
        Unk0217b3e4_810 *t = &data_0217b3e4->mUnk_810[i];
        (a->mUnk_000.mUnk_20 + c)[i].mUnk_06 = t->mUnk_00 >> 4;
        (a->mUnk_000.mUnk_20 + c)[i].mUnk_0e = t->mUnk_04 >> 4;
        (a->mUnk_000.mUnk_20 + c)[i].mUnk_16 = t->mUnk_08 >> 4;
        (a->mUnk_000.mUnk_20 + c)[i].mUnk_1e = t->mUnk_0c >> 4;
    }
}
