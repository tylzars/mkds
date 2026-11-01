#include "Main/Unknown/code_020336ec.h"
#include "Main/Unknown/code_02025000.h"
#include "Main/Unknown/code_02025bb4.h"
#include "Main/Unknown/code_020ade08.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_02124094.h"
#include "Main/Unknown/code_02124bc8.h"
#include "code_02148ca0.h"
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

// non-matching: 0x158 bytes, original 0x154; the original reads the count at 0xd4 into one register and the loop
// counter in another through the table loops (ours keeps the table entry in a stack word), and its two stack words for
// the pair of constants are swapped
void func_020336ec(void *a) {
    Unk02174e60 *o;
    Unk02174e14_00 *t;
    s32 x;
    s32 c;
    s32 d;
    s32 e;
    s32 f;
    s32 n;
    s32 i;
    s32 j;
    s32 k;
    s32 m;

    o = data_02174e60;
    t = &o->mUnk_048[0];
    if (o->mUnk_0dc != 3) {
        x = 1;
    } else {
        x = 0;
    }
    n = 0;
    c = o->mUnk_0d4;
    d = c + data_usa_02153eb0[c - 1];
    if (c <= 5) {
        e = 1;
        f = 0x38;
    } else {
        e = 0;
        f = 0x39;
    }
    o->mUnk_0cc = 0x3a;
    data_02174e60->mUnk_0ce = 0x44;
    for (i = 0; i < 0x38; i++) {
        t->mUnk_18[i].mUnk_00 = 0;
    }
    for (j = data_usa_02153eb0[data_02174e60->mUnk_0d4 - 1];
         j < data_usa_02153eb0[data_02174e60->mUnk_0d4 - 1] + data_02174e60->mUnk_0d4 * 2; j++) {
        t->mUnk_18[j].mUnk_00 = 1;
    }
    if (data_02174e60->mUnk_0dc == 3) {
        for (k = data_usa_02153eb0[data_02174e60->mUnk_0d4 - 1];
             k < data_02174e60->mUnk_0d4 + data_usa_02153eb0[data_02174e60->mUnk_0d4 - 1]; k++) {
            func_02025c48(k, f, t->mUnk_0c);
        }
    }
    for (m = 0; m < data_02174e60->mUnk_0d8; m++) {
        if (x == data_021759c0->mUnk_68[(u16) m].mUnk_08.mUnk_04) {
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
    s32 e;
    s32 i;

    t = &data_02174e60->mUnk_048[0];
    c = data_02174e60->mUnk_0d4;
    d = c + data_usa_02153ea0[c - 2];
    if (c > 4) {
        e = 0;
    } else {
        e = 1;
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

// non-matching: same size (0x114), 16 words differ; the original compares the halfword count with ble (ours beq) and
// keeps the remaining size in r7 and the loop counter in r6, ours the opposite; its last loop is laid out with the
// constant 0 loaded first
void func_020338f8(void *a) {
    Unk02174e14_00 *t;
    u32 r;
    s32 n;
    s32 j;
    s32 m;
    s32 h;
    u8 *p;
    u16 w[11];

    t = &data_02174e60->mUnk_048[0];
    r = func_02148cb8();
    n = 0;
    h = t->mUnk_0c->mUnk_06;
    data_02174e60->mUnk_0cc = 8;
    data_02174e60->mUnk_0ce = 0x12;
    j = 0;
    if (t->mUnk_14->mUnk_06 > 0) {
        p = data_usa_02153ec0;
        do {
            r -= func_02025a00(n, a, t, p, r);
            p += 8;
            j++;
        } while (j < t->mUnk_14->mUnk_06);
    }
    func_0212426c(0, 0, t->mUnk_14, func_020b3f7c(data_02174e60->mUnk_0c8, 0x7a), t->mUnk_0c, t->mUnk_18);
    for (m = 0; m < data_02174e60->mUnk_0d8; m++) {
        if (data_02174e60->mUnk_0e4[m].mUnk_00 == 0) {
            func_020338f8_inline(w, 0x16);
            func_020adff0((u16) m, w, 1);
            n++;
            func_0212426c(0, n, t->mUnk_14, w, t->mUnk_0c, t->mUnk_18);
        }
    }
    while (n < 7) {
        n++;
        t->mUnk_18[n].mUnk_00 = 0;
        t->mUnk_18[h + n].mUnk_00 = 0;
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

// non-matching: same size (0xc8), 5 words differ from +0x7c; the original loads the word at 0x10c of data_0217b488
// before the member at 0xc of the entry, ours after it
void func_02033ab8(s32 a, s32 b, s32 c, s32 d) {
    Unk02174e14_00 *q;
    Unk02174e14_00 *s;
    s32 r;
    Unk020b4a44 *u;
    u8 *p;
    u8 v;

    s = &data_02174e60->mUnk_048[a];
    if (d == 1) {
        q = &data_02174e60->mUnk_048[2];
    } else {
        q = &data_02174e60->mUnk_048[3];
    }
    r = data_021759c0->mUnk_68[(u16) b].mUnk_00;
    func_0212463c(r, q->mUnk_08, q->mUnk_00, q->mUnk_04, q->mUnk_0c, a, c, s->mUnk_08, s->mUnk_0c);
    if (r == 0xc) {
        if (d == 1) {
            u = (Unk020b4a44 *) data_02174e60->mUnk_0c0;
        } else {
            u = (Unk020b4a44 *) data_02174e60->mUnk_0c4;
        }
        v = func_02124a68(c, s->mUnk_08, s->mUnk_0c);
        p = data_0217b488->mUnk_10c[b] * 0x20 + (u8 *) u->mUnk_0c;
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
    if (data_021759c0->mUnk_08 == 2 && data_021759c0->mUnk_58 != 0 && data_021759c0->mUnk_1c == 1) {
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
    s32 b;
    s32 c;
    s32 d;
    s32 e;

    t = &data_02174e60->mUnk_048[1];
    if (data_02174e60->mUnk_0d0 == a) {
        d = 1;
    } else {
        d = 0;
    }
    r = data_02174e60->mUnk_0e4[a].mUnk_08;
    if (data_021759c0->mUnk_58 != 0) {
        if (data_021759c0->mUnk_68[(u16) a].mUnk_08.mUnk_04 == 1) {
            b = 1;
        } else {
            b = 0;
        }
        e = 0;
        if (b == 0) {
            c = 1;
        } else {
            c = 0;
        }
        if (c != 0 && d != 0) {
            e = 1;
        }
        t->mUnk_18[r + 0x10].mUnk_00 = e;
        if (c != 0 && d == 0) {
            c = 1;
        } else {
            c = 0;
        }
        t->mUnk_18[r + 0x18].mUnk_00 = c;
        if (b != 0 && d != 0) {
            c = 1;
        } else {
            c = 0;
        }
        t->mUnk_18[r + 0x20].mUnk_00 = c;
        if (b != 0 && d == 0) {
            d = 1;
        } else {
            d = 0;
        }
        t->mUnk_18[r + 0x28].mUnk_00 = d;
        t->mUnk_18[r + 8].mUnk_00 = 0;
        t->mUnk_18[r].mUnk_00 = t->mUnk_18[r + 8].mUnk_00;
    } else {
        t->mUnk_18[r].mUnk_00 = d;
        if (d == 0) {
            d = 1;
        } else {
            d = 0;
        }
        t->mUnk_18[r + 8].mUnk_00 = d;
        t->mUnk_18[r + 0x28].mUnk_00 = 0;
        t->mUnk_18[r + 0x20].mUnk_00 = t->mUnk_18[r + 0x28].mUnk_00;
        t->mUnk_18[r + 0x18].mUnk_00 = t->mUnk_18[r + 0x20].mUnk_00;
        t->mUnk_18[r + 0x10].mUnk_00 = t->mUnk_18[r + 0x18].mUnk_00;
    }
}

#pragma thumb off
