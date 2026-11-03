#include "code_02022aa8.h"
#include "code_020219e8.h"
#include "code_020245a4.h"
#include "Main/Unknown/code_02024000.h"
#include "Main/Unknown/unk_02153000.h"

u32 func_02022dd8(Unk02022dd8 *a, u32 b) {
    u32 r;
    Unk02021a5c *lo;
    Unk02021a5c *hi;
    Unk02021a5c *mid;
    Unk02022dd8_s *q;

    r = 0xffff;
    switch (a->mUnk_04) {
        case 0:
            r = (u16) (a->mUnk_0c.mUnk_00 + (b - a->mUnk_00));
            break;
        case 1:
            r = ((u16 *) ((u8 *) a + 0xc))[b - a->mUnk_00];
            break;
        case 2:
            q = &a->mUnk_0c;
            lo = q->mUnk_02;
            hi = lo + (q->mUnk_00 - 1);
            while (lo <= hi) {
                mid = lo + (hi - lo) / 2;
                if (mid->mUnk_00 < b) {
                    lo = mid + 1;
                } else if (b < mid->mUnk_00) {
                    hi = mid - 1;
                } else {
                    r = mid->mUnk_02;
                    break;
                }
            }
            break;
    }
    return r;
}

void func_02022d88(Unk02022aa8 *a, Unk02021f9c *b) {
    u32 v;
    u32 f;

    v = func_0202469c(b, &a->mUnk_00);
    f = a->mUnk_00->mUnk_07;
    a->mUnk_08 = v - 1;
    a->mUnk_0a = a->mUnk_08 != 0 ? 2 : 3;
    a->mUnk_04 = data_021530e8[f];
}

void func_02022d44(Unk02022aa8 *a, Unk02021f9c *b) {
    a->mUnk_08 = func_0202469c(b, &a->mUnk_00) - 1;
    a->mUnk_0a = a->mUnk_08 != 0 ? 2 : 3;
    a->mUnk_04 = func_02024960;
}

u32 func_02022ce4(Unk02022aa8 *a, u32 b) {
    Unk02022dd8 *p;

    p = a->mUnk_00->mUnk_10;
    while (p != 0) {
        if (p->mUnk_00 <= b && b <= p->mUnk_02) {
            return func_02022dd8(p, b);
        }
        p = p->mUnk_08;
    }
    return 0xffff;
}

Unk02022c80 *func_02022c80(Unk02022aa8 *a, u32 b) {
    Unk02022c80_n *p;
    Unk02022ce4 *f;

    f = a->mUnk_00;
    p = f->mUnk_0c;
    while (p != 0) {
        if (p->mUnk_00 <= b && b <= p->mUnk_02) {
            return (Unk02022c80 *) ((u8 *) p + 8 + a->mUnk_0a * (b - p->mUnk_00));
        }
        p = p->mUnk_04;
    }
    return &f->mUnk_04;
}

s32 func_02022bbc(Unk02022aa8 *a, s32 b, u8 *c, u8 **d) {
    u8 *q = c;
    s32 w;
    Unk02022aa8_f *f;
    u16 ch;
    u32 g;
    Unk02022c80 *e;
    s32 k;

    f = a->mUnk_04;
    w = 0;
    ch = f(&q);
    while (ch != 0) {
        if (ch == 10) {
            break;
        }
        g = func_02022ce4(a, ch);
        if (g == 0xffff) {
            g = a->mUnk_00->mUnk_02;
        }
        e = func_02022c80(a, g);
        if (a->mUnk_08 != 0) {
            k = e->mUnk_00 + e->mUnk_01;
        } else {
            k = e->mUnk_02;
        }
        w += b + k;
        ch = f(&q);
    }
    if (d != 0) {
        *d = ch == 10 ? q : 0;
    }
    if (w > 0) {
        w -= b;
    }
    return w;
}

s32 func_02022b44(Unk02022aa8 *a, s32 b, u8 *c) {
    u8 *q = c;
    Unk02022b10 z = {0, 0};
    s32 n;
    Unk02022aa8_f *f;
    u16 ch;

    f = a->mUnk_04;
    n = 1;
    ch = f(&q);
    while (ch != 0) {
        if (ch == 10) {
            n++;
        }
        ch = f(&q);
    }
    return n * (b + a->mUnk_00->mUnk_01) - b;
}

void func_02022aa8(Unk02022b10 *a, Unk02022aa8 *b, s32 c, s32 d, u8 *e) {
    Unk02022b10 t = {0, 0};
    s32 n;
    s32 w;

    n = 1;
    while (e != 0) {
        w = func_02022bbc(b, c, e, &e);
        if (w > t.mUnk_00) {
            t.mUnk_00 = w;
        }
        n++;
    }
    t.mUnk_04 = (n - 1) * (d + b->mUnk_00->mUnk_01) - d;
    *a = t;
}
