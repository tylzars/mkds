#include "code_0212f1ac.h"
#include "code_0200eddc.h"
#include "code_0200fc8c.h"
#include "code_020207ec.h"
#include "code_0201ec30.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_0200f000.h"
#include "code_0214cfe4.h"
#include "code_0212c9d4.h"
#include "code_0214d018.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_0216e000.h"

// Calls func_0212f638 with c, then func_0212d154 with a, b, 0, 32000, 2, func_0212f5a0 and data_0216eaa4.
void func_0212f730(void *a, u32 b, s32 c) {
    func_0212f638(c);
    func_0212d154(a, b, 0, 32000, 2, func_0212f5a0, &data_0216eaa4);
}

// Does nothing when a equals mUnk_00 of data_0216eaa4. Otherwise clears the 0xc0 bytes at mUnk_18, stores a in mUnk_00
// and one of func_0212f59c, func_0212f3f8, func_0212f1f8 and func_0212f1ac in mUnk_04 (by a = 0 to 3); func_02020844 is
// called with 0 first when the old mUnk_00 is 1 and with 0x3000 last when a is 1.
void func_0212f638(s32 a) {
    u32 v;
    volatile u16 z;

    if (a == data_0216eaa4.mUnk_00) {
        return;
    }
    if (data_0216eaa4.mUnk_00 == 1) {
        func_02020844(0);
    }
    v = IrqDisable();
    z = 0;
    MemFillHalfwords(z, &data_0216eaa4.mUnk_18, 0xc0);
    data_0216eaa4.mUnk_00 = a;
    switch (a) {
        case 1:
            data_0216eaa4.mUnk_04 = func_0212f3f8;
            break;
        case 2:
            data_0216eaa4.mUnk_04 = func_0212f1f8;
            break;
        case 3:
            data_0216eaa4.mUnk_04 = func_0212f1ac;
            break;
        case 0:
            data_0216eaa4.mUnk_04 = func_0212f59c;
            break;
        default:
            data_0216eaa4.mUnk_04 = func_0212f59c;
            break;
    }
    IrqRestore(v);
    if (a == 1) {
        func_02020844(0x3000);
    }
}

// Calls mUnk_08, mUnk_04 and mUnk_10 of s (the first and last when not null), then DC_FlushRange on a and b.
void func_0212f5a0(void *a, void *b, u32 n, u32 d, Unk0212f1f8 *s) {
    if (s->mUnk_08 != 0) {
        s->mUnk_08(a, b, n, d, s->mUnk_0c);
    }
    s->mUnk_04(a, b, n, s);
    if (s->mUnk_10 != 0) {
        s->mUnk_10(a, b, n, d, s->mUnk_14);
    }
    DC_FlushRange(a, n);
    DC_FlushRange(b, n);
}

// Does nothing.
void func_0212f59c(void) {}

// Works on the last two entries of a and b, then on the rest from the end, with 16-bit clamping; keeps two words in
// mUnk_18 of d.
void func_0212f3f8(s16 *a, s16 *b, u32 n, Unk0212f1f8 *d) {
    s16 t[2];
    u32 m;
    s32 i;
    s32 j;
    s32 k;
    s32 x;
    s32 y;
    s32 e;
    s16 *p;
    s16 *q;

    m = n >> 1;
    for (i = 0; i < 2; i++) {
        e = *(a + m + i - 2) - *(b + m + i - 2);
        if (e < -32768) {
            e = -32768;
        } else if (e > 32767) {
            e = 32767;
        }
        t[i] = e;
    }
    p = a + (m - 1);
    q = b + (m - 1);
    for (; p >= a + 2; p--, q--) {
        e = p[-2] - q[-2];
        x = p[0] + e;
        y = q[0] - e;
        if (e >= 0) {
            if (x < 32767) {
                p[0] = x;
            } else {
                p[0] = 32767;
            }
            if (y > -32768) {
                q[0] = y;
            } else {
                q[0] = -32768;
            }
        } else {
            if (x > -32768) {
                p[0] = x;
            } else {
                p[0] = -32768;
            }
            if (y < 32767) {
                q[0] = y;
            } else {
                q[0] = 32767;
            }
        }
    }
    for (j = 1; j >= 0; j--) {
        x = a[j] + d->mUnk_18.w[j];
        if (x < -32768) {
            x = -32768;
        } else if (x > 32767) {
            x = 32767;
        }
        a[j] = x;
        y = b[j] - d->mUnk_18.w[j];
        if (y < -32768) {
            y = -32768;
        } else if (y > 32767) {
            y = 32767;
        }
        b[j] = y;
    }
    for (k = 0; k < 2; k++) {
        d->mUnk_18.w[k] = t[k];
    }
}

// Adds the pairs in mUnk_18 of d to a and b in blocks of 24 entries with 16-bit clamping and stores new pairs.
void func_0212f1f8(s16 *a, s16 *b, u32 n, Unk0212f1f8 *d) {
    u32 m;
    u32 r;
    s32 i;
    s32 j;
    s32 x;
    s32 y;
    u32 off;
    s32 c;
    s32 e;

    m = n >> 1;
    off = 0;
    while (m > off + 24) {
        for (i = 0; i < 24; i++) {
            x = a[i + off];
            x += d->mUnk_18.p[i].mUnk_00;
            y = b[i + off];
            y += d->mUnk_18.p[i].mUnk_04;
            c = x;
            if (x < -32768) {
                c = -32768;
            } else if (x > 32767) {
                c = 32767;
            }
            a[i + off] = c;
            e = y;
            if (y < -32768) {
                e = -32768;
            } else if (y > 32767) {
                e = 32767;
            }
            b[i + off] = e;
            d->mUnk_18.p[i].mUnk_00 = (y + 1) >> 2;
            d->mUnk_18.p[i].mUnk_04 = (x + 1) >> 2;
        }
        off += 24;
    }
    r = m - off;
    for (i = 0; i < r; i++) {
        j = a[i + off];
        j += d->mUnk_18.p[i].mUnk_00;
        y = b[i + off];
        y += d->mUnk_18.p[i].mUnk_04;
        if (j < -32768) {
            j = -32768;
        } else if (j > 32767) {
            j = 32767;
        }
        a[i + off] = j;
        if (y < -32768) {
            y = -32768;
        } else if (y > 32767) {
            y = 32767;
        }
        b[i + off] = y;
    }
    for (i = 0; i < 24 - r; i++) {
        d->mUnk_18.p[i].mUnk_00 = (d->mUnk_18.p + r)[i].mUnk_00;
        d->mUnk_18.p[i].mUnk_04 = (d->mUnk_18.p + r)[i].mUnk_04;
    }
    for (i = 0; i < r; i++) {
        d->mUnk_18.p[24 + i - r].mUnk_00 = (b[i + off] + 1) >> 2;
        d->mUnk_18.p[24 + i - r].mUnk_04 = (a[i + off] + 1) >> 2;
    }
}

// Replaces a with the rounded average of a and b, then calls MemCopyWordsByBlock with a, b and n.
void func_0212f1ac(s16 *a, s16 *b, u32 n) {
    u32 m;
    u32 i;

    m = n >> 1;
    for (i = 0; i < m; i++) {
        a[i] = (a[i] + b[i] + 1) >> 1;
    }
    MemCopyWordsByBlock(a, b, n);
}
