#include "03/code_021b807c.h"
#include "03/code_021b7bb4.h"
#include "03/code_021b7efc.h"
#include "03/code_021b8050.h"
#include "03/code_021b7d04.h"
#include "03/code_021b7c30.h"

u32 func_ov003_021b807c(Unk021b807c *p) {
    u8 *s;
    u32 n;
    u8 i;
    u8 j;
    u8 a;
    u8 b;
    s = p->mUnk_08;
    n = p->mUnk_0c;
    i = (p->mUnk_00 + 1) % n;
    a = s[i];
    j = (a + p->mUnk_04) % n;
    b = s[j];
    p->mUnk_00 = i;
    p->mUnk_04 = j;
    s[j] = a;
    s[i] = b;
    return s[(a + b) % p->mUnk_0c];
}

void func_ov003_021b80c4(Unk021b807c *p, u8 *v1, const u8 *v2, u32 n) {
    u32 i;
    u8 a;
    for (i = 0; i < n; i++) {
        a = func_ov003_021b807c(p);
        v1[i] = a ^ v2[i];
    }
}

void func_ov003_021b80f4(Unk021b807c *p, const u8 *v1, u32 v2, u32 n) {
    u8 *s;
    u32 i;
    u32 j;
    u32 k;
    u8 a;
    u8 t;
    s = p->mUnk_08;
    p->mUnk_04 = 0;
    p->mUnk_00 = p->mUnk_04;
    p->mUnk_0c = n;
    for (i = 0; i < n; i++) {
        s[i] = i;
    }
    j = 0;
    k = 0;
    for (i = 0; i < n; i++) {
        a = s[i];
        j = (j + v1[k] + a) % p->mUnk_0c;
        t = s[j];
        s[j] = a;
        s[i] = t;
        k++;
        if (k >= v2) {
            k = 0;
        }
    }
}

s32 func_ov003_021b8160(const u8 *a, u8 *b, s32 c, u32 d, const u8 *e, const u8 *f, s32 g) {
    Unk021b807c t;
    u8 r;
    t.mUnk_08 = func_ov003_021ba178(c);
    if (t.mUnk_08 == 0) {
        func_ov003_021b94b8(2);
        return -1;
    }
    func_ov003_021b7d90(data_ov003_021d7c88, e, 2);
    func_ov003_021b7d90(data_ov003_021d7c8a, f, g);
    func_ov003_021b80f4(&t, data_ov003_021d7c88, g + 2, c);
    func_ov003_021b80c4(&t, b, a, c);
    r = func_ov003_021b8050(b, c);
    if (r != d) {
        func_ov003_021b94b8(0x12);
        func_ov003_021ba164(t.mUnk_08);
        return -1;
    }
    func_ov003_021ba164(t.mUnk_08);
    return 0;
}

s32 func_ov003_021b81f4(const u8 *a, u8 *b, s32 c, s8 *d, u8 *e, const u8 *f, s32 g) {
    u16 h;
    Unk021b807c t;
    *d = func_ov003_021b8050(a, c);
    t.mUnk_08 = func_ov003_021ba178(c);
    if (t.mUnk_08 == 0) {
        return -1;
    }
    h = func_ov003_021b7bb4();
    func_ov003_021b7d90(e, &h, 2);
    func_ov003_021b7d90(data_ov003_021d7c88, e, 2);
    func_ov003_021b7d90(data_ov003_021d7c8a, f, g);
    func_ov003_021b80f4(&t, data_ov003_021d7c88, g + 2, c);
    func_ov003_021b80c4(&t, b, a, c);
    func_ov003_021ba164(t.mUnk_08);
    return 0;
}

s32 func_ov003_021b8278(void *a, s32 b, u32 c, s32 d) {
    Unk021b7cec t;
    func_ov003_021b7d84(&t, 0, 8);
    t.mUnk_01 = 2;
    t.mUnk_02 = func_ov003_021b7c94(0x5790);
    t.mUnk_04 = func_ov003_021b7cac(data_ov003_021d7c6c.mUnk_10);
    if (c == 0xff || data_ov003_021d7c6c.mUnk_18 == 0) {
        t.mUnk_04 = -1;
    }
    return func_ov003_021b7d04(d, a, b, 0, &t, 8);
}

void func_ov003_021b82e0(void *p, s32 b, s32 c, s32 d, s8 e, s8 f, const u8 *g) {
    Unk021b82e0 *h = p;
    h->mUnk_00 = func_ov003_021b7c94(1);
    h->mUnk_02 = 0;
    h->mUnk_04 = 0;
    h->mUnk_06 = func_ov003_021b7c94(b);
    h->mUnk_08 = 0;
    h->mUnk_0a = func_ov003_021b7c94(c);
    h->mUnk_0c = func_ov003_021b7c94(d);
    h->mUnk_0e = e;
    h->mUnk_0f = f;
    func_ov003_021b7d90(h->mUnk_10, g, 8);
}

void func_ov003_021b8340(s32 a, void *b, const void *c, s16 *d, s16 *e, s8 *f) {
    Unk021b8340 *g = b;
    if (a == 1) {
        *e = 1;
        func_ov003_021b81f4(c, g->mUnk_04, *d, f, g->mUnk_02, data_ov003_021d7c58, 8);
        g->mUnk_00 = func_ov003_021b7c94(*d);
        *d += 4;
    } else {
        func_ov003_021b7d90(g, c, *d);
    }
}

s16 func_ov003_021b839c(void *a) {
    Unk021b839c *b = a;
    Unk021b839c *c;
    s16 d;
    s16 e;
    s16 f;
    u32 g;
    f = 0;
    b->mUnk_00 = data_ov003_021d7c6c.mUnk_19;
    b->mUnk_01 = 1;
    d = data_ov003_021d7c6c.mUnk_04;
    func_ov003_021b7d90(b->mUnk_06, data_ov003_021d7c6c.mUnk_00, d);
    b->mUnk_02 = func_ov003_021b7c94(d);
    d += 6;
    e = (d + 1) / 2 * 2;
    b->mUnk_04 = func_ov003_021b7c94(e);
    f += e;
    c = (Unk021b839c *) ((u8 *) b + e);
    ((u8 *) b)[e] = 0x60;
    c->mUnk_01 = 0;
    c->mUnk_04 = func_ov003_021b7c94(0);
    g = func_ov003_021b7cac(0xe);
    func_ov003_021b7d90(c->mUnk_06, &g, 4);
    c->mUnk_02 = func_ov003_021b7c94(4);
    f += 0xa;
    return f;
}

s32 func_ov003_021b8428(Unk021b86e4 *a, Unk021b916c *b, s32 c) {
    Unk021d7c54 *d;
    u8 e[8];
    d = data_ov003_021d7c54;
    func_ov003_021b7d84(d, 0, 0x5dc);
    func_ov003_021b7d90(e, &b[2], 8);
    func_ov003_021b7f48(e, 8, data_ov003_021d6868, func_ov003_021b7c30(data_ov003_021d6868));
    func_ov003_021b82e0(d, 0x3000, 0, 0, 0, 0x11, e);
    func_ov003_021b8278(d, 0x18, 0, c);
    return 0;
}

s32 func_ov003_021b8498(Unk021b86e4 *a, Unk021b916c *b, s32 c) {
    s8 d;
    s16 g;
    s16 h;
    u8 k[8];
    Unk021b7cec e;
    Unk021d7c54 *f;
    d = 0;
    g = 0;
    h = 0;
    f = data_ov003_021d7c54;
    func_ov003_021b7d84(&e, 0, 8);
    func_ov003_021b7d84(f, 0, 0x5dc);
    e.mUnk_00 = 2;
    e.mUnk_01 = 0;
    e.mUnk_02 = func_ov003_021b7c94(4);
    e.mUnk_04 = data_ov003_021d7c6c.mUnk_08;
    e.mUnk_04 = func_ov003_021b7cac(e.mUnk_04);
    g = 8;
    func_ov003_021b8340(data_ov003_021d7c40, &f->mUnk_0c[12], &e, &g, &h, &d);
    func_ov003_021b7d90(k, &b[1], 8);
    if (func_ov003_021b7f48(k, 8, data_ov003_021d6868, 6) != 0) {
        func_ov003_021b94b8(2);
        return -1;
    }
    func_ov003_021b82e0(f, 0x2000, g, h, d, 0x11, k);
    g += 0x18;
    func_ov003_021b8278(f, g, 0, c);
    return 0;
}

s32 func_ov003_021b858c(Unk021b86e4 *a, Unk021b916c *b, s32 c) {
    Unk021b8498 d;
    Unk021d7c54 *e;
    Unk021b858c *f;
    u8 *g;
    d.mUnk_00 = 0;
    d.mUnk_02 = 0;
    d.mUnk_04 = 0;
    e = data_ov003_021d7c54;
    func_ov003_021b7d84(e, 0, 0x5dc);
    f = func_ov003_021ba178(0x210);
    if (f == 0) {
        func_ov003_021b94b8(2);
        return -1;
    }
    func_ov003_021b7d84(f, 0, 0x210);
    g = &e->mUnk_0c[12];
    func_ov003_021b7d90(data_ov003_021d7c58, b, 8);
    func_ov003_021b7d90(d.mUnk_06, data_ov003_021d7c58, 8);
    d.mUnk_02 = func_ov003_021b839c(f->mUnk_04);
    if (d.mUnk_02 < 0) {
        func_ov003_021b94b8(3);
        if (f != 0) {
            func_ov003_021ba164(f);
        }
        return -1;
    }
    f->mUnk_00 = 0;
    f->mUnk_02 = func_ov003_021b7c94(d.mUnk_02);
    d.mUnk_02 += 4;
    func_ov003_021b8340(0, g, f, &d.mUnk_02, &d.mUnk_04, &d.mUnk_00);
    d.mUnk_04 |= 0x10;
    if (func_ov003_021b7f48(d.mUnk_06, 8, data_ov003_021d6868, 6) != 0) {
        func_ov003_021b94b8(2);
        if (f != 0) {
            func_ov003_021ba164(f);
        }
        return -1;
    }
    func_ov003_021b82e0(e, 0x1000, d.mUnk_02, d.mUnk_04, d.mUnk_00, 0x11, d.mUnk_06);
    d.mUnk_02 += 0x18;
    func_ov003_021b8278(e, d.mUnk_02, 0xff, c);
    if (f != 0) {
        func_ov003_021ba164(f);
    }
    return 0;
}

s32 func_ov003_021b86e4(s32 v1, Unk021b86e4 *v2, Unk021b916c *v3, s32 v4) {
    switch (v1) {
        case 0:
            func_ov003_021b9134(2);
            return func_ov003_021b858c(v2, v3, v4);
        case 1:
            func_ov003_021b9134(3);
            return func_ov003_021b8498(v2, v3, v4);
        case 2:
            func_ov003_021b9134(5);
            return func_ov003_021b8428(v2, v3, v4);
    }
    return -1;
}
