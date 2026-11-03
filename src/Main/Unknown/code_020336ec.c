#include "Main/Unknown/code_0202578c.h"
#include "Main/Unknown/code_020336ec.h"
#include "Main/Unknown/code_02025000.h"
#include "Main/Unknown/code_02025bb4.h"
#include "Main/Unknown/code_020ade08.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_02124094.h"
#include "Main/Unknown/code_02124bc8.h"
#include "code_02148950.h"
#include "00/code_02182fdc.h"
#include "Main/Unknown/unk_02174000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "code_02016468.h"
#include "code_0214cfe4.h"

// Fills with 0 through a halfword stack offset of its own.
static inline void func_020338f8_inline(void *p, s32 n) {
    volatile u16 v = 0;
    func_0214cfe4(v, p, n);
}

#pragma thumb on

void func_020336ec(void *a) {
    Unk02174e60 *o;
    Unk02174e14_00 *t;
    s32 x;
    s32 c;
    s32 d;
    s32 f;
    s32 n;
    s32 i;
    BOOL e;
    s32 j;
    s32 k;
    s32 m;

    o = data_02174e60;
    t = &o->mUnk_048[0];
    switch (o->mUnk_0dc) {
        case 3:
            x = 0;
            break;
        default:
            x = 1;
            break;
    }
    n = 0;
    c = o->mUnk_0d4;
    d = c + data_usa_02153eb0[c - 1];
    if (c <= 5) {
        e = TRUE;
        f = 0x38;
    } else {
        e = FALSE;
        f = 0x39;
    }
    o->mUnk_0cc = 0x3a;
    data_02174e60->mUnk_0ce = 0x44;
    for (i = 0; i < 0x38; i++) {
        t->mUnk_18[i].mUnk_00 = 0;
    }
    j = data_usa_02153eb0[data_02174e60->mUnk_0d4 - 1];
    j = (u32) j;
    if (j < data_usa_02153eb0[data_02174e60->mUnk_0d4 - 1] + data_02174e60->mUnk_0d4 * 2) {
        do {
            t->mUnk_18[j].mUnk_00 = 1;
            j++;
        } while (j < data_usa_02153eb0[data_02174e60->mUnk_0d4 - 1] + data_02174e60->mUnk_0d4 * 2);
    }
    if (data_02174e60->mUnk_0dc == 3) {
        for (k = data_usa_02153eb0[data_02174e60->mUnk_0d4 - 1];
             k < data_02174e60->mUnk_0d4 + data_usa_02153eb0[data_02174e60->mUnk_0d4 - 1]; k++) {
            func_02025c48(k, f, t->mUnk_0c);
        }
    }
    for (m = 0; m < data_02174e60->mUnk_0d8; m++) {
        if (x == data_021759c0->mUnk_68[(u16) m].mUnk_08.mTeamIndex) {
            func_02033ab8(0, m, d + n, e);
            n++;
        }
    }
    t->mUnk_18[0x39].mUnk_00 = 0;
    t->mUnk_18[0x38].mUnk_00 = t->mUnk_18[0x39].mUnk_00;
}

void func_02033840(void *a) {
    Unk02174e14_00 *t;
    s32 c;
    s32 d;
    BOOL e;
    s32 i;

    t = &data_02174e60->mUnk_048[0];
    c = data_02174e60->mUnk_0d4;
    d = c + data_usa_02153ea0[c - 2];
    if (c > 4) {
        e = FALSE;
    } else {
        e = TRUE;
    }
    data_02174e60->mUnk_0cc = 0x46;
    data_02174e60->mUnk_0ce = 0x50;
    for (i = 0; i < 0x46; i++) {
        t->mUnk_18[i].mUnk_00 = 0;
    }
    for (i = data_usa_02153ea0[data_02174e60->mUnk_0d4 - 2];
         i < data_usa_02153ea0[data_02174e60->mUnk_0d4 - 2] + data_02174e60->mUnk_0d4 * 2; i++) {
        t->mUnk_18[i].mUnk_00 = 1;
    }
    for (i = 0; i < data_02174e60->mUnk_0d4; i++) {
        func_02033ab8(0, i, d + i, e);
    }
}

void func_020338f8(void *a) {
    Unk02174e14_00 *t;
    s32 n;
    s32 j;
    s32 m;
    s32 h;
    u32 r;
    u8 *p;
    u16 w[11];
    s32 b;
    Unk02124b1c *c;

    t = &data_02174e60->mUnk_048[0];
    r = func_02148cb8();
    n = 0;
    h = t->mUnk_0c->mUnk_06;
    data_02174e60->mUnk_0cc = 8;
    data_02174e60->mUnk_0ce = 0x12;
    j = 0;
    b = t->mUnk_14->mUnk_06;
    if (b > 0) {
        p = data_usa_02153ec0;
        do {
            r -= func_02025a00(n, a, t, p, r);
            p += 8;
            j++;
        } while (j < t->mUnk_14->mUnk_06);
    }
    func_0212426c(0, 0, t->mUnk_14, GetBmgEntry(data_02174e60->mUnk_0c8, 0x7a), t->mUnk_0c, t->mUnk_18);
    for (m = 0; m < data_02174e60->mUnk_0d8; m++) {
        if (data_02174e60->mUnk_0e4[m].mUnk_00 == 0) {
            func_020338f8_inline(w, 0x16);
            func_020adff0((u16) m, w, 1);
            n++;
            func_0212426c(0, n, t->mUnk_14, w, t->mUnk_0c, t->mUnk_18);
        }
    }
    while (n < 7) {
        n = n + 1;
        t->mUnk_18[n].mUnk_00 = 0;
        n = (u32) n;
        c = &t->mUnk_18[n + h];
        c->mUnk_00 = 0;
    }
}

void func_02033a0c(void *a) {
    s32 j;
    u32 r;
    Unk02174e14_00 *t;
    u8 *p;
    u16 w[11];

    r = func_02148cb8();
    t = &data_02174e60->mUnk_048[0];
    data_02174e60->mUnk_0cc = 1;
    data_02174e60->mUnk_0ce = 0xb;
    j = 0;
    if ((s32) t->mUnk_14->mUnk_06 > 0) {
        p = data_usa_02153e98;
        do {
            r -= func_02025a00(0, a, t, p, r);
            p += 8;
            j++;
        } while (j < (s32) t->mUnk_14->mUnk_06);
    }
    func_020338f8_inline(w, 0x16);
    func_020adff0((u16) data_02174e60->mUnk_0d0, w, 1);
    func_0212426c(0, 0, t->mUnk_14, w, t->mUnk_0c, t->mUnk_18);
    func_02033ab8(0, data_02174e60->mUnk_0d0, 0, 1);
}

void func_02033ab8(s32 a, s32 b, s32 c, s32 d) {
    Unk02174e14_00 *q;
    Unk02174e14_00 *s;
    s32 r;
    Nclr *u;
    u8 *p;
    u8 v;
    u32 e;

    s = &data_02174e60->mUnk_048[a];
    if (d == 1) {
        q = &data_02174e60->mUnk_048[2];
    } else {
        q = &data_02174e60->mUnk_048[3];
    }
    r = data_021759c0->mUnk_68[(u16) b].mCharacterIndex;
    func_0212463c(r, q->mUnk_08, q->mUnk_00, q->mUnk_04, q->mUnk_0c, a, c, s->mUnk_08, s->mUnk_0c);
    if (r == 0xc) {
        if (d == 1) {
            u = (Nclr *) data_02174e60->mUnk_0c0;
        } else {
            u = (Nclr *) data_02174e60->mUnk_0c4;
        }
        v = func_02124a68(c, s->mUnk_08, s->mUnk_0c);
        e = data_0217b488->mUnk_10c[b];
        p = e * 0x20 + (u8 *) u->mData;
        if (a == 0) {
            func_02016468(0xe, v << 5, p, 0x20);
        } else {
            func_02016468(0x1e, v << 5, p, 0x20);
        }
    }
}

void func_02033b80(s32 a) {
    Unk02174e14_00 *t;
    s32 r;
    s32 q;
    s32 n;
    u16 w[4];

    t = &data_02174e60->mUnk_048[1];
    r = data_02174e60->mUnk_0e4[a].mUnk_08;
    q = data_02174e60->mUnk_0e4[a].mUnk_04;
    if (data_021759c0->mUnk_08 == 2 && data_021759c0->mUseTeams != 0 && data_021759c0->mUnk_1c == 1) {
        t->mUnk_18[r + 0x38].mUnk_00 = 0;
        t->mUnk_18[r + 0x48].mUnk_00 = 0;
        return;
    }
    n = 0;
    func_020338f8_inline(w, 8);
    if (q >= 100) {
        w[n++] = 0x30 + (q / 100) % 10;
    }
    if (q >= 10) {
        w[n++] = 0x30 + (q / 10) % 10;
    }
    w[n++] = 0x30 + q % 10;
    w[n] = 0;
    func_02124224(1, r + 8, t->mUnk_14, w, t->mUnk_0c, t->mUnk_18, 6);
    r += 0x38;
    t->mUnk_18[r].mUnk_00 = 1;
    func_02025c48(r, data_02174e60->mUnk_0e4[a].mUnk_00 + 0x40, t->mUnk_0c);
}

void func_02033c80(s32 a) {
    Unk02174e14_00 *t;
    s32 r;
    BOOL b;
    BOOL c;
    BOOL d;
    BOOL e;

    t = &data_02174e60->mUnk_048[1];
    if (data_02174e60->mUnk_0d0 == a) {
        d = TRUE;
    } else {
        d = FALSE;
    }
    r = data_02174e60->mUnk_0e4[a].mUnk_08;
    if (data_021759c0->mUseTeams != 0) {
        if (data_021759c0->mUnk_68[(u16) a].mUnk_08.mTeamIndex == 1) {
            b = TRUE;
        } else {
            b = FALSE;
        }
        e = FALSE;
        if (b == FALSE) {
            c = TRUE;
        } else {
            c = FALSE;
        }
        if (c != FALSE && d != FALSE) {
            e = TRUE;
        }
        t->mUnk_18[r + 0x10].mUnk_00 = e;
        if (c != FALSE && d == FALSE) {
            c = TRUE;
        } else {
            c = FALSE;
        }
        t->mUnk_18[r + 0x18].mUnk_00 = c;
        if (b != FALSE && d != FALSE) {
            c = TRUE;
        } else {
            c = FALSE;
        }
        t->mUnk_18[r + 0x20].mUnk_00 = c;
        if (b != FALSE && d == FALSE) {
            d = TRUE;
        } else {
            d = FALSE;
        }
        t->mUnk_18[r + 0x28].mUnk_00 = d;
        t->mUnk_18[r + 8].mUnk_00 = 0;
        t->mUnk_18[r].mUnk_00 = t->mUnk_18[r + 8].mUnk_00;
    } else {
        t->mUnk_18[r].mUnk_00 = d;
        if (d == FALSE) {
            d = TRUE;
        } else {
            d = FALSE;
        }
        t->mUnk_18[r + 8].mUnk_00 = d;
        t->mUnk_18[r + 0x28].mUnk_00 = 0;
        t->mUnk_18[r + 0x20].mUnk_00 = t->mUnk_18[r + 0x28].mUnk_00;
        t->mUnk_18[r + 0x18].mUnk_00 = t->mUnk_18[r + 0x20].mUnk_00;
        t->mUnk_18[r + 0x10].mUnk_00 = t->mUnk_18[r + 0x18].mUnk_00;
    }
}

#pragma thumb off
