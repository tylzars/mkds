#include "Main/Unknown/code_02124094.h"
#include "code_02021e8c.h"
#include "Main/Unknown/code_02022000.h"
#include "Main/Unknown/code_02023000.h"
#include "Main/Unknown/code_02125000.h"
#include "code_02016468.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_02146cb0.h"
#include "Main/Unknown/unk_0215d000.h"
#include "code_02147cd8.h"
#include "code_021488e8.h"

#pragma thumb on

void func_02124b1c(Unk02124b1c *a, s32 b, s32 c) {
    s32 i;
    s32 *p;
    s32 *q;
    s64 r;
    s32 x;
    s32 y;
    i = (b >> 4) * 2;
    p = a->mUnk_14;
    q = a->mUnk_24;
    r = func_02147f34(0x1000, c);
    x = data_0215d4b4[i + 1];
    a->mUnk_14[0] = ((s64) x * r) >> 12;
    y = data_0215d4b4[i];
    p[1] = ((s64) y * r) >> 12;
    p[2] = -p[1];
    p[3] = a->mUnk_14[0];
    func_02146cb0(q, y, x);
    a->mUnk_24[0] = func_021488e8(a->mUnk_24[0], c);
    q[1] = func_021488e8(q[1], c);
    q[2] = func_021488e8(q[2], c);
    q[3] = func_021488e8(q[3], c);
}

s32 func_02124ae4(s32 a, Unk02021dc8 *b, Unk0201ea30 *c) {
    Unk02124a68 *p;
    Unk0201ea30_08 *e;
    e = (Unk0201ea30_08 *) (c + 1);
    e += a;
    p = (Unk02124a68 *) func_02021f1c(b, (u16) e->mUnk_04);
    if ((p->mUnk_04->mUnk_00 & 0xc00) >> 10 == 1) {
        return 1;
    }
    return 0;
}

void func_02124a98(u32 a, s32 b, void *c, void *d) {
    Unk02124a68 *p;
    Unk0201ea30_08 *e;
    s32 i;
    Unk02124a68_04 *q;
    e = (Unk0201ea30_08 *) ((Unk0201ea30 *) d + 1);
    e += a;
    p = (Unk02124a68 *) func_02021f1c(c, (u16) e->mUnk_04);
    q = p->mUnk_04;
    for (i = 0; i < p->mUnk_00; i++) {
        q->mUnk_00 &= ~0xc00;
        if (b != 0) {
            q->mUnk_00 |= 0x400;
        }
        q++;
    }
}

u8 func_02124a68(u32 a, void *b, void *c) {
    Unk02124a68 *p;
    Unk0201ea30_08 *e;
    e = (Unk0201ea30_08 *) ((Unk0201ea30 *) c + 1);
    e += a;
    p = (Unk02124a68 *) func_02021f1c(b, (u16) e->mUnk_04);
    return (p->mUnk_04->mUnk_04 & 0xf000) >> 12;
}

void func_02124a20(s32 a, s32 b, void *c, void *d) {
    Unk02124a68 *p;
    Unk0201ea30_08 *e;
    s32 i;
    Unk02124a68_04 *q;
    e = (Unk0201ea30_08 *) ((Unk0201ea30 *) d + 1);
    e += a;
    p = (Unk02124a68 *) func_02021f1c(c, (u16) e->mUnk_04);
    q = p->mUnk_04;
    for (i = 0; i < p->mUnk_00; i++) {
        q->mUnk_04 &= ~0xf000;
        q->mUnk_04 |= b << 12;
        q++;
    }
}

u8 func_021249f0(s32 a, Unk02021dc8 *b, Unk0201ea30 *c) {
    Unk02124a68 *p;
    Unk0201ea30_08 *e;
    e = (Unk0201ea30_08 *) (c + 1);
    e += a;
    p = (Unk02124a68 *) func_02021f1c(b, (u16) e->mUnk_04);
    return (p->mUnk_04->mUnk_04 & 0xc00) >> 10;
}

void func_021249a8(u32 a, u32 b, Unk02021dc8 *c, Unk0201ea30 *d) {
    Unk02124a68 *p;
    Unk0201ea30_08 *e;
    s32 i;
    Unk02124a68_04 *q;
    e = (Unk0201ea30_08 *) (d + 1);
    e += a;
    p = (Unk02124a68 *) func_02021f1c(c, (u16) e->mUnk_04);
    q = p->mUnk_04;
    for (i = 0; i < p->mUnk_00; i++) {
        q->mUnk_04 &= ~0xc00;
        q->mUnk_04 |= b << 10;
        q++;
    }
}

u16 func_0212497c(u32 a, void *b, void *c) {
    Unk02124a68 *p;
    Unk0201ea30_08 *e;
    e = (Unk0201ea30_08 *) ((Unk0201ea30 *) c + 1);
    e += a;
    p = (Unk02124a68 *) func_02021f1c(b, (u16) e->mUnk_04);
    return p->mUnk_04->mUnk_04 & 0x3ff;
}

void func_0212481c(u32 a, Unk02021dc8 *b, Unk0212463c_c *c, Unk0212463c_d *d, Unk0201ea30 *e, s32 f, u32 g,
                   Unk02021dc8 *h, Unk0201ea30 *i) {
    u8 arr[16];
    s32 n;
    s32 u;
    u8 *buf;
    Unk02124a68 *p;
    s32 j;
    Unk02124a68 *q;
    Unk02124a68_04 *r;
    Unk0201ea30_08 *s;
    Unk0201ea30_08 *s2;
    s32 v;
    u32 x;
    u32 y;
    u32 z;
    u32 w;
    s32 k;
    s32 a1;
    s32 b1;
    u8 *c1;
    s32 ln;
    s = (Unk0201ea30_08 *) (e + 1);
    s += a;
    p = (Unk02124a68 *) func_02021f1c(b, (u16) s->mUnk_04);
    s2 = (Unk0201ea30_08 *) (i + 1);
    s2 += g;
    q = (Unk02124a68 *) func_02021f1c(h, (u16) s2->mUnk_04);
    n = p->mUnk_00;
    for (k = 0; k < 16; k++) {
        arr[k] = 0;
    }
    for (j = 0; j < n; j++) {
        w = p->mUnk_04[j].mUnk_04;
        u = (q->mUnk_04[j].mUnk_04 & 0x3ff) << 5;
        r = &p->mUnk_04[j];
        y = (((u32) r->mUnk_02 << 16) & 0xc0000000) >> 30;
        x = ((u32) p->mUnk_04[j].mUnk_00 & 0xc000) >> 14;
        v = (&data_0215d024[y])[x * 4] << 5;
        buf = c->mUnk_14 + ((w & 0x3ff) << 5);
        func_0200ee74(buf, v);
        if (f == 0) {
            func_02016468(0x13, u, buf, v);
        } else {
            func_02016468(0x23, u, buf, v);
        }
        z = (w & 0xf000) >> 12;
        arr[z] = 1;
        q->mUnk_04[j].mUnk_04 &= ~0xf000;
        q->mUnk_04[j].mUnk_04 |= z << 12;
    }
    a1 = 0;
    b1 = 0;
    for (k = 0; k < 16; k++) {
        if (arr[k] != 0 && a1 + b1 < 15) {
            b1++;
        } else if (b1 > 0) {
            a1 <<= 5;
            c1 = d->mUnk_0c + a1;
            ln = b1 << 5;
            if (f == 0) {
                func_02016468(0xe, a1, c1, ln);
            } else {
                func_02016468(0x1e, a1, c1, ln);
            }
            a1 = k + 1;
            b1 = 0;
        } else {
            a1 = k + 1;
        }
    }
}

void func_02124748(u32 a, void *b, void *c, void *d, s32 e, u32 f, void *g, void *h) {
    s32 i;
    Unk02124a68 *p;
    Unk02124a68 *q;
    Unk02124a68_04 *r;
    Unk0201ea30_08 *s;
    Unk0201ea30_08 *s2;
    s32 n;
    u8 *buf;
    s32 u;
    s32 v;
    u32 t;
    u32 x;
    s = (Unk0201ea30_08 *) ((Unk0201ea30 *) d + 1);
    s += a;
    p = (Unk02124a68 *) func_02021f1c(b, (u16) s->mUnk_04);
    s2 = (Unk0201ea30_08 *) ((Unk0201ea30 *) h + 1);
    s2 += f;
    q = (Unk02124a68 *) func_02021f1c(g, (u16) s2->mUnk_04);
    i = 0;
    n = p->mUnk_00;
    for (; i < n; i++) {
        u = (q->mUnk_04[i].mUnk_04 & 0x3ff) << 5;
        r = &p->mUnk_04[i];
        t = (((u32) r->mUnk_02 << 16) & 0xc0000000) >> 30;
        x = ((u32) p->mUnk_04[i].mUnk_00 & 0xc000) >> 14;
        v = (&data_0215d024[t])[x * 4] << 5;
        buf = ((Unk0212463c_c *) c)->mUnk_14 + ((r->mUnk_04 & 0x3ff) << 5);
        func_0200ee74(buf, v);
        if (e == 0) {
            func_02016468(0x13, u, buf, v);
        } else {
            func_02016468(0x23, u, buf, v);
        }
    }
}

void func_0212463c(u32 a, Unk02021dc8 *b, Unk0212463c_c *c, Unk0212463c_d *d, Unk0201ea30 *e, s32 f, u32 g,
                   Unk02021dc8 *h, Unk0201ea30 *i) {
    s32 j;
    Unk02124a68 *p;
    Unk02124a68 *q;
    Unk02124a68_04 *r;
    Unk0201ea30_08 *s;
    Unk0201ea30_08 *s2;
    s32 n;
    u8 *buf;
    s32 u;
    s32 v;
    u32 x;
    u32 y;
    u32 k;
    u32 w;
    u8 *z;
    s = (Unk0201ea30_08 *) (e + 1);
    s += a;
    p = (Unk02124a68 *) func_02021f1c(b, (u16) s->mUnk_04);
    s2 = (Unk0201ea30_08 *) (i + 1);
    s2 += g;
    q = (Unk02124a68 *) func_02021f1c(h, (u16) s2->mUnk_04);
    j = 0;
    n = p->mUnk_00;
    for (; j < n; j++) {
        u = (q->mUnk_04[j].mUnk_04 & 0x3ff) << 5;
        r = &p->mUnk_04[j];
        y = (((u32) r->mUnk_02 << 16) & 0xc0000000) >> 30;
        x = ((u32) p->mUnk_04[j].mUnk_00 & 0xc000) >> 14;
        v = (&data_0215d024[y])[x * 4] << 5;
        buf = c->mUnk_14 + ((r->mUnk_04 & 0x3ff) << 5);
        func_0200ee74(buf, v);
        if (f == 0) {
            func_02016468(0x13, u, buf, v);
        } else {
            func_02016468(0x23, u, buf, v);
        }
    }
    w = (((u32) q->mUnk_04->mUnk_04 & 0xf000) >> 12) << 5;
    z = d->mUnk_0c + ((((u32) p->mUnk_04->mUnk_04 & 0xf000) >> 12) << 5);
    if (f == 0) {
        k = 0xe;
    } else {
        k = 0x1e;
    }
    func_02016468(k, w, z, 0x20);
}

s32 func_021243ac(void *a, s32 b, void *c, s32 d, s32 e, s32 f, void *g, void *h, void *i, s32 j) {
    Unk02022eb0 buf[128];
    Unk0212428c *p;
    Unk021243ac *q;
    Unk02124a68 *r;
    s32 w;
    s32 x;
    s32 y;
    s32 z;
    s32 k;
    s32 m;
    s32 n;
    s32 u;
    s32 v;
    s32 sa;
    s32 sb;
    s32 n2;
    void *t;
    n2 = ((Unk0201ea30 *) h)->mUnk_06;
    ((Unk02124b1c *) i)[f].mUnk_38 = b;
    q = func_02036bec(a, 0x48);
    ((Unk02124b1c *) i)[n2 + b].mUnk_3c = q;
    p = func_0201ea58(c, b);
    w = ((d - 1) >> 3) + 1;
    x = ((e - 1) >> 3) + 1;
    y = w * x;
    q->mUnk_20.mUnk_14 = y << 5;
    q->mUnk_20.mUnk_18 = ((j - 0x100) >> 5) - y;
    q->mUnk_20.mUnk_10 = func_02036bec(a, q->mUnk_20.mUnk_14);
    func_02023374(q, q->mUnk_20.mUnk_10, w, x, 4);
    q->mUnk_18(q, 0);
    sb = p->mUnk_05;
    sa = p->mUnk_04;
    t = func_020b403c(p->mUnk_06_12);
    q->mUnk_20.mUnk_00 = q;
    q->mUnk_20.mUnk_04 = t;
    q->mUnk_20.mUnk_08 = sa;
    q->mUnk_20.mUnk_0c = sb;
    q->mUnk_20.mUnk_1c = d;
    q->mUnk_20.mUnk_20 = e;
    m = 0;
    n = 0;
    if (f < n2) {
        u = func_021249f0(f, g, h);
        v = func_02124ae4(f, g, h);
    } else {
        f -= n2;
        u = func_021240d4(f, c, i, h);
        v = func_0212418c(f, c, i, h);
    }
    switch (p->mUnk_00.mUnk_00_12) {
        case 1:
            m = -(w << 2);
            break;
        case 2:
            m = -(w << 3);
            break;
    }
    switch (p->mUnk_02.mUnk_00_12) {
        case 1:
            n = -(x << 2);
            break;
        case 2:
            n = -(x << 3);
            break;
    }
    z = func_02022eb0(buf, w, x, m, n, 0, q->mUnk_20.mUnk_18, 0);
    r = func_02036bec(a, z * 6 + 0x10);
    r->mUnk_00 = z;
    r->mUnk_02 = 0;
    r->mUnk_04 = (Unk02124a68_04 *) (r + 1);
    r->mUnk_08 = w << 2;
    r->mUnk_0a = x << 2;
    r->mUnk_0c = -w << 2;
    r->mUnk_0e = -x << 2;
    for (k = 0; k < z; k++) {
        buf[k].mUnk_04 = (buf[k].mUnk_04 & ~0xc00) | (u * 0x400);
        if (v != 0) {
            m = p->mUnk_06_8;
            buf[k].mUnk_00 = (buf[k].mUnk_00 & ~0xc00) | 0x400;
            buf[k].mUnk_04 = (buf[k].mUnk_04 & ~0xf000) | (m * 0x1000);
        } else {
            m = p->mUnk_06_8;
            buf[k].mUnk_00 &= ~0xc00;
            buf[k].mUnk_04 = (buf[k].mUnk_04 & ~0xf000) | (m * 0x1000);
        }
        buf[k].mUnk_00 &= ~0x1000;
        buf[k].mUnk_00 &= 0xc1fffcff;
        r->mUnk_04[k].mUnk_00 = buf[k].mUnk_00_0;
        r->mUnk_04[k].mUnk_02 = buf[k].mUnk_00_2;
        r->mUnk_04[k].mUnk_04 = buf[k].mUnk_04;
    }
    q->mUnk_44 = r;
    return q->mUnk_20.mUnk_14;
}

void func_0212428c(s32 a, s32 b, Unk0201ea30 *c, void *d, Unk0201ea30 *e, Unk02124b1c *f, s32 g, s8 h) {
    s32 k;
    s32 w;
    s32 z;
    Unk0212428c *p;
    Unk021243ac *q;
    s32 x;
    s32 y;
    s32 n;
    u32 m;
    void *buf;
    s32 u;
    s32 v;
    p = func_0201ea58(c, b);
    q = (f + e->mUnk_06 + b)->mUnk_3c;
    k = q->mUnk_20.mUnk_1c;
    n = q->mUnk_20.mUnk_20;
    x = ((k - 1) >> 3) + 1 << 3;
    y = ((n - 1) >> 3) + 1 << 3;
    m = 0;
    w = 0;
    z = 0;
    if (p->mUnk_00.mUnk_00_12 == 0) {
        m |= 0x200;
    } else if (p->mUnk_00.mUnk_00_12 == 1) {
        m |= 0x400;
        w = (x - k) >> 1;
    } else if (p->mUnk_00.mUnk_00_12 == 2) {
        m |= 0x800;
        w = x - k;
    }
    if (p->mUnk_02.mUnk_00_12 == 0) {
        m |= 0x40;
    } else if (p->mUnk_02.mUnk_00_12 == 1) {
        m |= 0x80;
        z = (y - n) >> 1;
    } else if (p->mUnk_02.mUnk_00_12 == 2) {
        m |= 0x100;
        z = y - n;
    }
    q->mUnk_18(q, 0);
    func_02125808(&q->mUnk_20, w, z, k, n, p->mUnk_06_0, m, p->mUnk_00.mUnk_00_14, d, g, h);
    buf = q->mUnk_20.mUnk_10;
    u = q->mUnk_20.mUnk_18 << 5;
    v = q->mUnk_20.mUnk_14;
    func_0200ee74(buf, v);
    if (a == 0) {
        func_02016468(0x13, u, buf, v);
    } else {
        func_02016468(0x23, u, buf, v);
    }
}

void func_0212426c(s32 a, s32 b, void *c, void *d, void *e, void *f) {
    func_0212428c(a, b, c, d, e, f, 0, -1);
}

void func_02124248(s32 a, s32 b, void *c, void *d, void *e, void *f, s8 g) {
    func_0212428c(a, b, c, d, e, f, 0, g);
}

void func_02124224(s32 a, u32 b, void *c, void *d, void *e, void *f, s8 g) {
    func_0212428c(a, b, c, d, e, f, 1, g);
}

void func_021241c0(s32 a, s32 b, Unk0201ea30 *c, Unk0201ea30 *d, Unk02124b1c *e) {
    Unk021243ac *p;
    void *buf;
    s32 u;
    s32 v;
    func_0201ea58(c, b);
    p = (e + d->mUnk_06 + b)->mUnk_3c;
    p->mUnk_18(p, 0);
    buf = p->mUnk_20.mUnk_10;
    u = p->mUnk_20.mUnk_18 << 5;
    v = p->mUnk_20.mUnk_14;
    func_0200ee74(buf, v);
    if (a == 0) {
        func_02016468(0x13, u, buf, v);
    } else {
        func_02016468(0x23, u, buf, v);
    }
}

s32 func_0212418c(s32 a, void *b, Unk02124b1c *c, Unk0201ea30 *d) {
    Unk02124b1c *p;
    Unk02124b1c *q;
    p = c + a;
    q = p + d->mUnk_06;
    if ((q->mUnk_3c->mUnk_44->mUnk_04->mUnk_00 & 0xc00) >> 10 == 1) {
        return 1;
    }
    return 0;
}

void func_02124140(u32 a, u32 b, void *c, void *d, void *e) {
    Unk02124b1c *r;
    Unk02124b1c *s;
    s32 i;
    Unk02124a68 *p;
    Unk02124a68_04 *q;
    s = (Unk02124b1c *) d + a;
    r = s + ((Unk0201ea30 *) e)->mUnk_06;
    p = r->mUnk_3c->mUnk_44;
    q = p->mUnk_04;
    for (i = 0; i < p->mUnk_00; i++) {
        q->mUnk_00 &= ~0xc00;
        if (b != 0) {
            q->mUnk_00 |= 0x400;
        }
        q++;
    }
}

void func_02124100(s32 a, u8 b, void *c, void *d, void *e) {
    Unk02124b1c *r;
    Unk02124b1c *s;
    s32 i;
    Unk02124a68 *p;
    Unk02124a68_04 *q;
    s = (Unk02124b1c *) d + a;
    r = s + ((Unk0201ea30 *) e)->mUnk_06;
    p = r->mUnk_3c->mUnk_44;
    q = p->mUnk_04;
    for (i = 0; i < p->mUnk_00; i++) {
        q->mUnk_04 &= ~0xf000;
        q->mUnk_04 |= b << 12;
        q++;
    }
}

u8 func_021240d4(s32 a, void *b, Unk02124b1c *c, Unk0201ea30 *d) {
    Unk02124b1c *p;
    Unk02124b1c *q;
    p = c + a;
    q = p + d->mUnk_06;
    return (q->mUnk_3c->mUnk_44->mUnk_04->mUnk_04 & 0xc00) >> 10;
}

void func_02124094(u32 a, u32 b, void *c, Unk02124b1c *d, Unk0201ea30 *e) {
    Unk02124b1c *r;
    Unk02124b1c *s;
    s32 i;
    Unk02124a68 *p;
    Unk02124a68_04 *q;
    s = d + a;
    r = s + e->mUnk_06;
    p = r->mUnk_3c->mUnk_44;
    q = p->mUnk_04;
    for (i = 0; i < p->mUnk_00; i++) {
        q->mUnk_04 &= ~0xc00;
        q->mUnk_04 |= b << 10;
        q++;
    }
}

#pragma thumb off
