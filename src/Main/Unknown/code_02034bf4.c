#include "Main/Unknown/code_02034bf4.h"
#include "Main/Unknown/code_0202578c.h"
#include "Main/Unknown/code_0202dd9c.h"
#include "Main/Unknown/code_0202db04.h"
#include "Main/Unknown/code_02025000.h"
#include "Main/Unknown/code_02025b84.h"
#include "Main/Unknown/code_02025bb4.h"
#include "Main/Unknown/code_02025d5c.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_02124094.h"
#include "Main/Unknown/code_02125ed0.h"
#include "Main/Unknown/code_02126230.h"
#include "Main/Unknown/code_0212775c.h"
#include "code_02148950.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_02153000.h"
#include "Main/Unknown/unk_02163000.h"
#include "Main/Unknown/unk_02164000.h"
#include "Main/Unknown/unk_02174000.h"
#include "code_0214d018.h"
#include "Main/Unknown/code_02025edc.h"
#include "Main/Unknown/code_02025f80.h"
#include "Main/Unknown/code_0204f240.h"

#pragma thumb on

void func_02035114(void) {
    Unk02174e64 *p;
    Unk02174e14_00 *s;
    s32 i;

    p = data_02174e64;
    s = &p->mUnk_02c[1];
    if (p->mUnk_080 < 0) {
        for (i = 0; i < 4; i++) {
            if (p->mUnk_09c[i].mUnk_28 != FALSE) {
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
        if (p->mUnk_09c[p->mUnk_080].mUnk_28 == FALSE) {
            for (i = 0; i < 4; i++) {
                if (p->mUnk_09c[i].mUnk_28 != FALSE) {
                    p->mUnk_080 = i;
                    return;
                }
            }
        }
    }
}

void func_02035060(void) {
    Unk02174e14_00 *s;
    s32 m;
    s32 i;
    s16 c;
    s16 v;

    s = &data_02174e64->mUnk_02c[1];
    m = s->mUnk_0c->mUnk_06;
    for (i = 0; i < 4; i++) {
        func_02025edc(&data_02174e64->mUnk_09c[i].mUnk_2c);
        c = func_02025ebc(&data_02174e64->mUnk_09c[i].mUnk_2c);
        s->mUnk_18[m + data_02164254[i + 4][0]].mUnk_04 = c;
        v = s->mUnk_18[m + ((const s16(*)[4]) data_02164254)[i + 4][0]].mUnk_04;
        s->mUnk_18[m + data_02164254[i][0]].mUnk_04 = v;
        v = s->mUnk_18[m + data_02164254[i][0]].mUnk_04;
        s->mUnk_18[data_02164254[i][3]].mUnk_04 = v;
        if (data_02174e64->mUnk_080 == i) {
            s->mUnk_18[4].mUnk_04 = c;
        }
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

void func_02034f60(void) {
    Unk02174e64_9c *e;
    s32 i;
    Unk02174e14_00 *s;
    s32 n;
    BOOL v;

    s = &data_02174e64->mUnk_02c[0];
    e = &data_02174e64->mUnk_09c[data_02174e64->mUnk_080];
    n = s->mUnk_0c->mUnk_06 + s->mUnk_14->mUnk_06;
    for (i = 0; i < n; i++) {
        if (data_02174e64->mUnk_080 >= 0) {
            v = TRUE;
        } else {
            v = FALSE;
        }
        s->mUnk_18[i].mUnk_00 = v;
    }
    if (data_02174e64->mUnk_080 >= 0) {
        func_0202de00((Unk02174e14 *) &data_02174e64->mUnk_02c[0], data_02154034, e, e->mUnk_00.mUnk_18[0],
                      e->mUnk_00.mUnk_18[1], e->mUnk_00.mUnk_18[2], (Unk0202de00_g *) &e->mUnk_00.mUnk_24);
    }
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

BOOL func_02034e68(Unk02174e64_9c_00 *a, Unk02174e64_9c_00 *b) {
    s32 i;
    s32 d;
    BOOL f;

    d = 0;
    for (i = 0; i < 11; i++) {
        if (a->mUnk_00[i] != b->mUnk_00[i]) {
            f = TRUE;
        } else {
            f = FALSE;
        }
        d |= f;
    }
    if (d != 0 || a->mUnk_18[1] != b->mUnk_18[1] || a->mUnk_18[0] != b->mUnk_18[0] || a->mUnk_18[2] != b->mUnk_18[2] ||
        a->mUnk_26 != b->mUnk_26 || a->mUnk_27 != b->mUnk_27 || a->mUnk_24 != b->mUnk_24) {
        return TRUE;
    }
    return FALSE;
}

void func_02034bf4(void *a, void *b, void *c) {
    void *h;
    Unk02174e14_00 *s;
    u32 n;
    s32 i;
    s32 j;
    s32 k;
    s32 m;
    s16 *t;
    BOOL z;

    h = CreateFrmHeapFromMaxFree(a);
    data_02174e64 = HeapAlloc(h, 0x1a8);
    MemFillWordsByBlock_inline(data_02174e64, 0x1a8);
    data_02174e64->mHeap = h;
    data_02174e64->mUnk_024[0] = b;
    data_02174e64->mUnk_024[1] = c;
    data_02174e64->mUnk_084 = func_02047a28(data_02164294);
    data_02174e64->mUnk_088 = FindSceneFile(data_021642a0);
    func_0204f240(data_02174e64->mHeap, 2);
    data_02174e64->mUnk_080 = -1;
    for (i = 0; i < 4; i++) {
        func_02025f80(&data_02174e64->mUnk_09c[i].mUnk_2c, 3, 10, 0x100, 0);
    }
    func_020258d4(0, data_02174e64, data_021642ac, data_021642cc, data_021642ec, 0, FindSceneFile);
    s = &data_02174e64->mUnk_02c[0];
    n = func_02148cb8();
    func_02025b20(s, data_02164308, data_02164328, data_02164348, data_02164368, data_02164384, NULL, FindSceneFile);
    z = FALSE;
    func_02025a50(0, data_02174e64->mHeap, s);
    i = 0;
    if (i < s->mUnk_14->mUnk_06) {
        t = (s16 *) data_02154034;
        do {
            n -= func_02025a00(z, data_02174e64->mHeap, s, t, n);
            t += 4;
            i++;
        } while (i < s->mUnk_14->mUnk_06);
    }
    j = s->mUnk_0c->mUnk_06 + s->mUnk_14->mUnk_06;
    for (i = 0; i < j; i++) {
        s->mUnk_18[i].mUnk_00 = 0;
    }
    s = &data_02174e64->mUnk_02c[1];
    n = func_02148ca0();
    k = 0;
    func_02025b20(s, data_021643a0, data_021643c0, data_021643e0, data_02164400, data_02164420, data_02164440,
                  FindSceneFile);
    func_02025a50(1, data_02174e64->mHeap, s);
    m = s->mUnk_0c->mUnk_06;
    i = 0;
    if (i < s->mUnk_14->mUnk_06) {
        t = (s16 *) data_02164254;
        do {
            if (t[3] < 0) {
                t[3] = m + k++;
            }
            n -= func_02025a00(1, data_02174e64->mHeap, s, data_02164254[i], n);
            t += 4;
            i++;
        } while (i < s->mUnk_14->mUnk_06);
    }
    for (j = 0; j < m; j++) {
        func_021249a8(j, 3, s->mUnk_08, s->mUnk_0c);
    }
    s->mUnk_18[4].mUnk_00 = 0;
    func_02025b84(0, &data_02174e64->mUnk_064);
    func_02025f80(&data_02174e64->mUnk_194, 3, 10, -0xc0, 0);
    func_021281c8(0xf);
    FrmHeapShrinkInParent(data_02174e64->mHeap);
}

#pragma thumb off
