#include "00/code_021a9640.h"

void func_ov000_021a9640(Unk021a998c *a) {
    Unk021a998c_0c *c = a->mUnk_0c;
    s32 b;
    s32 d;
    u16 *f;
    u16 *g;
    u16 *h;
    u16 *i;
    u8 *e;
    u8 *j;
    s32 m;
    u8 *p;
    u8 *k;
    c->mUnk_000->mUnk_20[0] = 3;
    c->mUnk_000->mUnk_20[1] = 0;
    func_ov000_021a9ca8(&c->mUnk_000->mUnk_20[2], 0x2e);
    b = c->mUnk_568;
    d = (b * 2) / 2;
    e = data_ov000_021b63a4(b);
    if (e == 0) {
        c->mUnk_429 = 9;
        return;
    }
    e[0] = 0;
    e[1] = 2;
    func_ov000_021a9ca8(e + 2, b - 0x33);
    e[b - 0x31] = 0;
    func_0214d1fc(c->mUnk_000->mUnk_20, e + b - 0x30, 0x30);
    f = (u16 *) data_ov000_021b63a4(d * 8);
    if (f == 0) {
        data_ov000_021b63ac(e);
        c->mUnk_429 = 9;
        return;
    }
    g = f + d;
    h = g + d;
    i = h + d;
    func_ov000_021ac4b8(g, e, b, d);
    func_ov000_021ac4b8(h, c->mUnk_56c, c->mUnk_574, d);
    func_ov000_021ac4b8(i, c->mUnk_468, b, d);
    if (data_ov000_021b49f4 < 0x20) {
        Unk0200db5c *n = data_0216ff5c.mUnk_04;
        u32 o = func_0200dcd8(n);
        func_0200dce0(n, data_ov000_021b49f4);
        func_ov000_021ac7e8(f, g, h, d, i);
        func_0200dce0(n, o);
    } else {
        func_ov000_021ac7e8(f, g, h, d, i);
    }
    j = data_ov000_021b63a4(b + 0x49);
    if (j == 0) {
        data_ov000_021b63ac(e);
        data_ov000_021b63ac(f);
        c->mUnk_429 = 9;
        return;
    }
    j[0] = 0x16;
    j[1] = 3;
    j[2] = 0;
    j[3] = (b + 4) >> 8;
    j[4] = b + 4;
    j[5] = 0x10;
    j[6] = b >> 16;
    j[7] = b >> 8;
    p = j + 9;
    j[8] = b;
    if (b & 1) {
        *p = f[b / 2];
        p += 1;
    }
    for (m = b / 2 - 1; m >= 0; m--) {
        *p = f[m] >> 8;
        k = p + 1;
        p += 2;
        *k = f[m];
    }
    func_ov000_021adcec(j, b + 9, 0, 0, a);
    func_ov000_021ab728(c->mUnk_378, j + 5, (u32) b + 4);
    func_ov000_021abca0(c->mUnk_2c0, j + 5, b + 4);
    data_ov000_021b63ac(j);
    data_ov000_021b63ac(f);
    data_ov000_021b63ac(e);
}

void func_ov000_021a9868(Unk021a998c *a) {
    Unk021a998c_0c *c = a->mUnk_0c;
    u8 *b;
    u8 *d;
    u8 *e;
    u32 f;
    s32 g;
    u32 i;
    u16 *h;
    b = data_ov000_021b63a4(0x98);
    if (b == 0) {
        c->mUnk_429 = 9;
        return;
    }
    d = b + 9;
    b[9] = 3;
    d[1] = 0;
    f = func_ov000_021ab5bc();
    c->mUnk_008[0] = f >> 24;
    c->mUnk_008[1] = f >> 16;
    c->mUnk_008[2] = f >> 8;
    c->mUnk_008[3] = f;
    func_ov000_021a9ca8(&c->mUnk_008[4], 0x1c);
    func_0214d1fc(c->mUnk_008, d + 2, 0x20);
    c->mUnk_000 = func_ov000_021ab63c(a->mUnk_1c, a->mUnk_18);
    if (c->mUnk_000 != 0) {
        d[0x22] = 0x20;
        func_0214d1fc(c->mUnk_000, d + 0x23, 0x20);
        d += 0x43;
    } else {
        e = d + 0x22;
        d += 0x23;
        *e = 0;
    }
    i = 0;
    *d = 0;
    e = d + 1;
    d += 2;
    *e = 4;
    h = data_ov000_021b4a00;
    for (; i < 2; i++) {
        *d = *h >> 8;
        e = d + 1;
        d += 2;
        *e = *h;
        h++;
    }
    *d = 1;
    d[1] = 0;
    e = d + 2;
    g = e - b - 5;
    b[0] = 0x16;
    b[1] = 3;
    b[2] = 0;
    b[3] = g >> 8;
    b[4] = g;
    b[5] = 1;
    b[6] = (g - 4) >> 16;
    b[7] = (g - 4) >> 8;
    b[8] = g - 4;
    func_ov000_021adcec(b, g + 5, 0, 0, a);
    func_ov000_021ab728(c->mUnk_378, b + 5, g);
    func_ov000_021abca0(c->mUnk_2c0, b + 5, g);
    data_ov000_021b63ac(b);
}
