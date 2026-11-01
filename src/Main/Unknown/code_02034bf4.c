#include "Main/Unknown/code_02034bf4.h"
#include "Main/Unknown/code_0202db04.h"
#include "Main/Unknown/code_02025000.h"
#include "Main/Unknown/code_02025b84.h"
#include "Main/Unknown/code_02025bb4.h"
#include "Main/Unknown/code_02025d5c.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020472a8.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_02124094.h"
#include "Main/Unknown/code_02125ed0.h"
#include "Main/Unknown/code_02126230.h"
#include "Main/Unknown/code_021281b4.h"
#include "code_02148ca0.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_02153000.h"
#include "Main/Unknown/unk_02163000.h"
#include "Main/Unknown/unk_02164000.h"
#include "Main/Unknown/unk_02174000.h"

#pragma thumb on

// non-matching: 0x278 bytes, original 0x274; 266 lines differ; first: original `ldr r1, [pc, #516]`, ours `ldr r1, [pc,
// #520]`
void func_02034bf4(void *a, void *b, void *c) {
    void *h;
    Unk02174e64 *p;
    Unk02174e14_00 *s;
    u32 n;
    s32 i;
    s32 j;
    s32 k;
    s32 m;
    s16 *t;
    s32 z;

    h = func_02036948(a);
    data_02174e64 = func_02036bec(h, 0x1a8);
    func_0214d05c_inline(data_02174e64, 0x1a8);
    data_02174e64->mUnk_1a4 = h;
    data_02174e64->mUnk_024[0] = b;
    data_02174e64->mUnk_024[1] = c;
    data_02174e64->mUnk_084 = func_02047a28(data_02164294);
    data_02174e64->mUnk_088 = func_0204799c(data_021642a0);
    func_0204f240(data_02174e64->mUnk_1a4, 2);
    data_02174e64->mUnk_080 = -1;
    p = data_02174e64;
    for (i = 0, j = 0; i < 4; i++, j += 0x3c) {
        func_02025f80((Unk02025ebc *) ((u8 *) p->mUnk_09c + 0x2c + j), 3, 10, 0x100, 0);
    }
    func_020258d4(0, data_02174e64, data_021642ac, data_021642cc, data_021642ec, 0, func_0204799c);
    s = &data_02174e64->mUnk_02c[0];
    n = func_02148cb8();
    func_02025b20(s, data_02164308, data_02164328, data_02164348, data_02164368, data_02164384, 0, func_0204799c);
    z = 0;
    func_02025a50(0, data_02174e64->mUnk_1a4, s);
    i = 0;
    if (s->mUnk_14->mUnk_06 > 0) {
        t = (s16 *) data_02154034;
        for (; i < s->mUnk_14->mUnk_06; i++) {
            n -= func_02025a00(z, data_02174e64->mUnk_1a4, s, t, n);
            t += 4;
        }
    }
    m = s->mUnk_0c->mUnk_06 + s->mUnk_14->mUnk_06;
    for (j = 0; j < m; j++) {
        s->mUnk_18[j].mUnk_00 = 0;
    }
    s = &data_02174e64->mUnk_02c[1];
    n = func_02148ca0();
    k = 0;
    func_02025b20(s, data_021643a0, data_021643c0, data_021643e0, data_02164400, data_02164420, data_02164440,
                  func_0204799c);
    func_02025a50(1, data_02174e64->mUnk_1a4, s);
    m = s->mUnk_0c->mUnk_06;
    i = 0;
    if (s->mUnk_14->mUnk_06 > 0) {
        t = (s16 *) data_02164254;
        for (; i < s->mUnk_14->mUnk_06; i++) {
            if (t[3] < 0) {
                t[3] = m + k;
                k++;
            }
            n -= func_02025a00(1, data_02174e64->mUnk_1a4, s, t, n);
            t += 4;
        }
    }
    for (j = 0; j < m; j++) {
        func_021249a8(j, 3, s->mUnk_08, s->mUnk_0c);
    }
    s->mUnk_18[4].mUnk_00 = 0;
    func_02025b84(0, &data_02174e64->mUnk_064);
    func_02025f80(&data_02174e64->mUnk_194, 3, 10, -0xc0, 0);
    func_021281c8(0xf);
    func_02036820(data_02174e64->mUnk_1a4);
}

s32 func_02034e68(Unk02174e64_9c_00 *a, Unk02174e64_9c_00 *b) {
    s32 i;
    s32 d;
    s32 f;

    d = 0;
    for (i = 0; i < 11; i++) {
        if (a->mUnk_00[i] != b->mUnk_00[i]) {
            f = 1;
        } else {
            f = 0;
        }
        d |= f;
    }
    if (d != 0 || a->mUnk_1c != b->mUnk_1c || a->mUnk_18 != b->mUnk_18 || a->mUnk_20 != b->mUnk_20 ||
        a->mUnk_26 != b->mUnk_26 || a->mUnk_27 != b->mUnk_27 || a->mUnk_24 != b->mUnk_24) {
        return 1;
    }
    return 0;
}

void func_02034ef0(void) {
    s32 i;
    Unk02174e14_00 *s;
    s32 v;
    s32 w;

    s = &data_02174e64->mUnk_02c[1];
    for (i = 0; i < 4; i++) {
        w = i + 4;
        if (i == data_02174e64->mUnk_080) {
            v = 14;
        } else {
            v = 15;
        }
        func_02124100(w, (u8) v, s->mUnk_14, s->mUnk_18, s->mUnk_0c);
        func_02124100(i, (u8) v, s->mUnk_14, s->mUnk_18, s->mUnk_0c);
    }
    if (data_02174e64->mUnk_080 >= 0) {
        func_02025c6c(4, data_02164254[data_02174e64->mUnk_080][3], s->mUnk_0c);
    }
}

void func_02034f60(void) {
    Unk02174e64_9c *e;
    s32 i;
    Unk02174e14_00 *s;
    s32 n;
    s32 v;

    s = &data_02174e64->mUnk_02c[0];
    e = &data_02174e64->mUnk_09c[data_02174e64->mUnk_080];
    n = s->mUnk_0c->mUnk_06 + s->mUnk_14->mUnk_06;
    for (i = 0; i < n; i++) {
        if (data_02174e64->mUnk_080 >= 0) {
            v = 1;
        } else {
            v = 0;
        }
        s->mUnk_18[i].mUnk_00 = v;
    }
    if (data_02174e64->mUnk_080 >= 0) {
        func_0202de00((Unk02174e14 *) &data_02174e64->mUnk_02c[0], data_02154034, e, e->mUnk_00.mUnk_18,
                      e->mUnk_00.mUnk_1c, e->mUnk_00.mUnk_20, (Unk0202de00_g *) &e->mUnk_00.mUnk_24);
    }
}

void func_02034fec(void) {
    Unk02174e14_00 *s;
    Unk02174e14_00 *t;
    s32 n;
    s32 m;
    s32 i;
    s16 c;

    s = &data_02174e64->mUnk_02c[0];
    t = &data_02174e64->mUnk_02c[1];
    n = s->mUnk_0c->mUnk_06 + s->mUnk_14->mUnk_06;
    m = t->mUnk_0c->mUnk_06 + t->mUnk_14->mUnk_06;
    c = func_02025ebc(&data_02174e64->mUnk_194);
    for (i = 0; i < n; i++) {
        s->mUnk_18[i].mUnk_06 = -c;
    }
    for (i = 0; i < m; i++) {
        t->mUnk_18[i].mUnk_06 = c;
    }
}

// non-matching: same size; 73 lines differ; first: original `ldrh r6, [r0, #6]`, ours `ldrh r0, [r0, #6]`
void func_02035060(void) {
    Unk02174e14_00 *s;
    s16 *t;
    s32 m;
    s32 i;
    s32 o;
    s16 c;
    s16 v;

    s = &data_02174e64->mUnk_02c[1];
    m = s->mUnk_0c->mUnk_06;
    t = (s16 *) data_02164254;
    o = 0;
    for (i = 0; i < 4; i++) {
        func_02025edc((Unk02025ebc *) ((u8 *) data_02174e64->mUnk_09c + 0x2c + o));
        c = func_02025ebc((Unk02025ebc *) ((u8 *) data_02174e64->mUnk_09c + 0x2c + o));
        s->mUnk_18[m + data_02164254[i + 4][0]].mUnk_04 = c;
        v = s->mUnk_18[m + data_02164254[i + 4][0]].mUnk_04;
        s->mUnk_18[m + t[0]].mUnk_04 = v;
        v = s->mUnk_18[m + t[0]].mUnk_04;
        s->mUnk_18[t[3]].mUnk_04 = v;
        if (data_02174e64->mUnk_080 == i) {
            s->mUnk_18[4].mUnk_04 = c;
        }
        o += 0x3c;
        t += 4;
    }
}

void func_02035114(void) {
    Unk02174e64 *p;
    Unk02174e14_00 *s;
    s32 i;

    p = data_02174e64;
    s = &p->mUnk_02c[1];
    if (p->mUnk_080 < 0) {
        for (i = 0; i < 4; i++) {
            if (p->mUnk_09c[i].mUnk_28 != 0) {
                p->mUnk_080 = i;
                s->mUnk_18[4].mUnk_00 = 1;
                func_02025c6c(4, data_02164254[i][3], s->mUnk_0c);
                return;
            }
        }
    } else {
        if (p->mUnk_190 == 0) {
            s->mUnk_18[4].mUnk_00 = 0;
            data_02174e64->mUnk_080 = -1;
            return;
        }
        if (p->mUnk_09c[p->mUnk_080].mUnk_28 == 0) {
            for (i = 0; i < 4; i++) {
                if (p->mUnk_09c[i].mUnk_28 != 0) {
                    p->mUnk_080 = i;
                    return;
                }
            }
        }
    }
}

#pragma thumb off
