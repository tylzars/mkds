#include "code_02022aa8.h"

#include "code_020219e8.h"
#include "code_020245a4.h"
#include "Main/Unknown/code_02024000.h"
#include "Main/Unknown/unk_02153000.h"
#include "Main/Unknown/code_02022000.h"

void func_020232b0(u16 *a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, u32 h) {
    s32 xe;
    s32 ye;
    s32 x;
    u16 *row;
    u32 p;
    s32 r;
    s32 col;

    if (f <= 0x20) {
        func_02023244(a + (f * e + d), b, c, f, g, h);
        return;
    }
    ye = e + c;
    xe = d + b;
    p = (u16) (h << 12);
    for (; e < ye; e++) {
        if (e < 0x20) {
            r = e;
        } else {
            r = e + 0x20;
        }
        x = d;
        row = a + r * 32;
        for (; x < xe; x++) {
            if (x < 0x20) {
                col = x;
            } else {
                col = x + 0x3e0;
            }
            row[col] = p | g;
            g++;
        }
    }
}

void func_02023244(u16 *a, s32 b, s32 c, s32 d, s32 e, u32 f) {
    s32 j;
    s32 i;
    u16 *p;
    u32 t;

    t = (u16) (f << 12);
    for (i = 0; i < c; i++) {
        p = a;
        for (j = 0; j < b; j++) {
            *p++ = t | e++;
        }
        a += d;
    }
}

u32 func_020231e4(u32 a, u32 b) {
    u32 ax;
    u32 by;
    u32 a2;
    u32 b2;
    u32 r;
    u32 u;
    u32 t;

    ax = a >> 3;
    by = b >> 3;
    a2 = (a & 4) >> 2;
    b2 = (b & 4) >> 2;
    r = ((a & 2) >> 1) + (a & 1);
    u = ((b & 2) >> 1) + (b & 1);
    t = 0;
    t += ax * by;
    t += by * (a2 + (r << 1));
    t += ax * (b2 + (u << 1));
    return (r + a2) * (u + b2) + t;
}

static inline u32 clz_inline(u32 x) {
    u32 r;
    asm { clz r, x }
    return r;
}

s32 func_02022eb0(void *a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h) {
    Unk02022eb0 *p;
    u8 *q;
    s32 lc;
    s32 lb;
    s32 sx;
    s32 sy;
    u32 mx;
    u32 my;
    s32 m;
    s32 nx;
    s32 t;
    s32 i;
    s32 r;
    s32 n;
    s32 ny;
    s32 k;
    s32 j;
    u32 w;
    s32 s;

    p = (Unk02022eb0 *) a;
    if (b >= 8) {
        lb = 3;
    } else {
        lb = 31 - clz_inline(b);
    }
    if (c >= 8) {
        lc = 3;
    } else {
        lc = 31 - clz_inline(c);
    }
    q = data_usa_021530f8[lc][lb];
    sx = q[0];
    sy = q[1];
    mx = b & (-1 << sx);
    my = c & (-1 << sy);
    if (f == 0) {
        m = 1;
    } else {
        m = 2;
    }
    n = 0;
    k = func_02024168(q);
    nx = b >> sx;
    ny = c >> sy;
    t = (m << sx << sy) >> h;
    for (j = 0; j < ny; j++) {
        r = e + (j << sy) * 8;
        for (i = 0; i < nx; i++) {
            w = (d + (i << sx) * 8) & 0x1ff;
            p->mUnk_00 = (p->mUnk_00 & 0xfe00ff00) | (r & 0xff) | (w << 16);
            p->mUnk_00 = (p->mUnk_00 & 0x3fff3fff) | k;
            p->mUnk_04 = (p->mUnk_04 & -0x400) | g;
            g += t;
            p->mUnk_00 = (p->mUnk_00 & ~0x2000) | (f << 13);
            p++;
        }
    }
    n += nx * ny;
    if (mx < b) {
        w = b - mx;
        s = d + mx * 8;
        r = func_02022eb0(p, w, my, s, e, f, g, h);
        p += r;
        g += (m * w * my) >> h;
        n += r;
    }
    if (my < c) {
        w = c - my;
        r = func_02022eb0(p, mx, w, d, e + my * 8, f, g, h);
        p += r;
        g += (m * mx * w) >> h;
        n += r;
    }
    if (mx < b && my < c) {
        n += func_02022eb0(p, b - mx, c - my, d + mx * 8, e + my * 8, f, g, h);
    }
    return n;
}

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
    a->mUnk_04 = CharReadHalfword;
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
