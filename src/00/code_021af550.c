#include "00/code_021a998c.h"
#include "00/code_021af550.h"
#include "Main/Unknown/unk_0216f000.h"
#include "00/code_021a6934.h"
#include "00/code_021afe5c.h"
#include "00/code_021b0014.h"
#include "00/unk_021b6380.h"
#include "code_0200dc3c.h"
#include "code_0200f5ac.h"
#include "code_0200fc8c.h"
#include "code_0214d018.h"

void func_ov000_021af550(u8 *a, u32 b, Unk021a998c *c, u32 d, u16 e) {
    u8 *f;
    u32 g;
    u32 h;
    u16 i;

    if (c->mUnk_08 == 0) {
        return;
    }
    if (data_0216ff5c.mUnk_04 == &data_ov000_021b661c) {
        f = data_ov000_021b641a;
    } else {
        f = c->mUnk_4c + 0x22;
    }
    if (d & 2) {
        g = 0x18;
    } else {
        g = 0x14;
    }
    *(u16 *) (f - 0xc) = ((u16) (data_ov000_021b63b4 >> 16) >> 8) | ((u16) (data_ov000_021b63b4 >> 16) << 8);
    *(u16 *) (f - 0xa) = ((u16) data_ov000_021b63b4 >> 8) | ((u16) data_ov000_021b63b4 << 8);
    *(u16 *) (f - 8) = ((u16) (c->mUnk_1c >> 16) >> 8) | ((u16) (c->mUnk_1c >> 16) << 8);
    *(u16 *) (f - 6) = ((u16) c->mUnk_1c >> 8) | ((u16) c->mUnk_1c << 8);
    *(u16 *) (f - 4) = 0x600;
    *(u16 *) (f - 2) = ((u16) (g + b) >> 8) | ((u16) (g + b) << 8);
    *(u16 *) f = (c->mUnk_0a >> 8) | (c->mUnk_0a << 8);
    *(u16 *) (f + 2) = (c->mUnk_18 >> 8) | (c->mUnk_18 << 8);
    *(u16 *) (f + 4) = ((u16) (c->mUnk_28 >> 16) >> 8) | ((u16) (c->mUnk_28 >> 16) << 8);
    *(u16 *) (f + 6) = ((u16) c->mUnk_28 >> 8) | ((u16) c->mUnk_28 << 8);
    *(u16 *) (f + 8) = ((u16) (c->mUnk_24 >> 16) >> 8) | ((u16) (c->mUnk_24 >> 16) << 8);
    *(u16 *) (f + 0xa) = ((u16) c->mUnk_24 >> 8) | ((u16) c->mUnk_24 << 8);
    f[0xc] = (g >> 2) << 4;
    f[0xd] = d;
    *(u16 *) (f + 0xe) = ((u16) (c->mUnk_3c - c->mUnk_44) >> 8) | ((u16) (c->mUnk_3c - c->mUnk_44) << 8);
    *(u16 *) (f + 0x10) = 0;
    *(u16 *) (f + 0x12) = (e >> 8) | (e << 8);
    if (d & 2) {
        *(u16 *) (f + 0x14) = ((u16) ((data_ov000_021b6370 + 0x2040000U) >> 16) >> 8) |
                              ((u16) ((data_ov000_021b6370 + 0x2040000U) >> 16) << 8);
        *(u16 *) (f + 0x16) =
            ((u16) (data_ov000_021b6370 + 0x2040000U) >> 8) | ((u16) (data_ov000_021b6370 + 0x2040000U) << 8);
    }
    h = func_ov000_021b01b4(f - 0xc, g + 0xc, 0);
    h = func_ov000_021b01b4(a, b, h);
    i = func_ov000_021b01a0(h);
    *(u16 *) (f + 0x10) = (i >> 8) | (i << 8);
    func_ov000_021af858(f, g, a, b, c->mUnk_1c, 6);
    c->mUnk_28 += b;
    d &= 3;
    if (d != 0) {
        c->mUnk_28++;
    }
}

void func_ov000_021af70c(u8 *a, u32 b, Unk021a998c *c) {
    u8 *g;
    u8 *d;
    u32 e;
    u16 f;

    g = c->mUnk_4c;
    d = g + 0x22;
    *(u16 *) (d - 0xc) = ((u16) (data_ov000_021b63b4 >> 16) >> 8) | ((u16) (data_ov000_021b63b4 >> 16) << 8);
    *(u16 *) (d - 0xa) = ((u16) data_ov000_021b63b4 >> 8) | ((u16) data_ov000_021b63b4 << 8);
    *(u16 *) (d - 8) = ((u16) (c->mUnk_1c >> 16) >> 8) | ((u16) (c->mUnk_1c >> 16) << 8);
    *(u16 *) (d - 6) = ((u16) c->mUnk_1c >> 8) | ((u16) c->mUnk_1c << 8);
    *(u16 *) (d - 4) = 0x1100;
    f = b + 8;
    *(u16 *) (d + 4) = (f >> 8) | (f << 8);
    *(u16 *) (d - 2) = *(u16 *) (d + 4);
    *(u16 *) (d + 2) = (c->mUnk_18 >> 8) | (c->mUnk_18 << 8);
    *(u16 *) (g + 0x22) = (c->mUnk_0a >> 8) | (c->mUnk_0a << 8);
    *(u16 *) (d + 6) = 0;
    e = func_ov000_021b01b4(d - 0xc, 0x14, 0);
    e = func_ov000_021b01b4(a, b, e);
    f = func_ov000_021b01a0(e);
    *(u16 *) (d + 6) = (f >> 8) | (f << 8);
    func_ov000_021af858(d, 8, a, b, c->mUnk_1c, 0x11);
}

void func_ov000_021af7e4(u8 *a, u32 b, Unk021a998c *c) {
    u32 e;
    u16 f;
    u16 h;
    u8 *g;
    u8 *d;

    g = c->mUnk_4c;
    d = g + 0x22;
    *(u16 *) (g + 0x22) = 8;
    *(u16 *) (d + 4) = (u16) (u32) data_0216ff5c.mUnk_04;
    *(u16 *) (d + 2) = 0;
    h = data_ov000_021b636c;
    c->mUnk_0a = h;
    data_ov000_021b636c++;
    *(u16 *) (d + 6) = h;
    e = func_ov000_021b01b4(d, 8, 0);
    e = func_ov000_021b01b4(a, b, e);
    f = func_ov000_021b01a0(e);
    *(u16 *) (d + 2) = (f >> 8) | (f << 8);
    func_ov000_021af858(d, 8, a, b, c->mUnk_1c, 1);
}

void func_ov000_021af858(u8 *a, u32 b, u8 *c, u32 d, u32 e, u8 f) {
    u16 g;
    u8 *h;
    u32 i;

    a[-0x14] = 0x45;
    g = 0;
    a[-0x13] = 0;
    data_ov000_021b6378++;
    *(u16 *) (a - 0x10) = (data_ov000_021b6378 >> 8) | (data_ov000_021b6378 << 8);
    a[-0xc] = 0x80;
    a[-0xb] = f;
    *(u16 *) (a - 8) = ((u16) (data_ov000_021b63b4 >> 16) >> 8) | ((u16) (data_ov000_021b63b4 >> 16) << 8);
    *(u16 *) (a - 6) = ((u16) data_ov000_021b63b4 >> 8) | ((u16) data_ov000_021b63b4 << 8);
    *(u16 *) (a - 4) = ((u16) (e >> 16) >> 8) | ((u16) (e >> 16) << 8);
    *(u16 *) (a - 2) = ((u16) e >> 8) | ((u16) e << 8);
    if (b > 0x5c8) {
        h = a;
        while (b > 0x5c8) {
            func_ov000_021af9d0(a, 0, h, 0x5c8, e, g | 0x2000);
            h += 0x5c8;
            b -= 0x5c8;
            g += 0xb9;
        }
        if (b != 0) {
            if (d != 0) {
                func_ov000_021af9d0(a, 0, h, b, e, g | 0x2000);
            } else {
                func_ov000_021af9d0(a, 0, h, b, e, g);
            }
            g += b >> 3;
            b = 0;
        }
    }
    if (b + d > 0x5c8) {
        do {
            i = 0x5c8 - b;
            func_ov000_021af9d0(a, b, c, i, e, g | 0x2000);
            c += i;
            d -= i;
            g += 0xb9;
            b = 0;
        } while (d > 0x5c8);
    }
    if (b + d != 0) {
        func_ov000_021af9d0(a, b, c, d, e, g);
    }
}

void func_ov000_021af9d0(u8 *a, u32 b, void *c, u32 d, u32 e, u32 f) {
    u16 g;
    u32 h;

    g = b + 0x14 + d;
    *(u16 *) (a - 0x12) = (g >> 8) | (g << 8);
    g = f;
    *(u16 *) (a - 0xe) = (g >> 8) | (g << 8);
    *(u16 *) (a - 0xa) = 0;
    g = func_ov000_021b0188(a - 0x14, 0x14);
    *(u16 *) (a - 0xa) = (g >> 8) | (g << 8);
    if (e != 0x7f000001 && e != data_ov000_021b63b4) {
        func_ov000_021afaac(a - 0x14, b + 0x14, c, d, e, 0x800);
    }
    if (e == 0x7f000001 || e == data_ov000_021b63b4 || func_ov000_021b0094(e) != 0) {
        func_0214d1fc(data_ov000_021b4c40, a - 0x1c, 8);
        h = func_0200fca0();
        func_ov000_021afe84(data_ov000_021b63d0, data_ov000_021b63d0, a - 0x1c, b + 0x1c, c, d);
        func_0200fcb4(h);
    }
}

void func_ov000_021afaac(u8 *a, u32 b, void *c, u32 d, u32 e, u16 f) {
    u8 *g;

    *(u16 *) (a - 2) = (f >> 8) | (f << 8);
    if (func_ov000_021b0094(e) == 0) {
        e = func_ov000_021b00e0(e);
        if (e == 0) {
            return;
        }
        g = func_ov000_021afd00(e);
        if (g == NULL) {
            g = func_ov000_021afc20(e);
        }
        if (g == NULL) {
            return;
        }
        func_0214d1fc(g, a - 0xe, 6);
    } else {
        a[-0xe] = 1;
        a[-0xd] = 0;
        a[-0xc] = 0x5e;
        a[-0xb] = (e >> 16) & 0x7f;
        a[-0xa] = e >> 8;
        a[-9] = e;
    }
    func_0214d1fc(data_ov000_021b63d0, a - 8, 6);
    func_ov000_021affcc(a - 0xe, b + 0xe, c, d);
}

void func_ov000_021afb58(u8 *a, u32 b, u32 c) {
    u16 d;
    u16 e;
    u32 f;
    u32 g;
    Unk021b6434 *p;

    if (b == 0x7f000001 || b == data_ov000_021b63b4 || func_ov000_021b00fc(b) == 0 || func_ov000_021b0094(b) != 0) {
        return;
    }
    d = func_0200f5ac() >> 16;
    for (g = 0; g < 8; g++) {
        if (b == data_ov000_021b6434[g].mUnk_00) {
            data_ov000_021b6434[g].mUnk_0a = d;
            func_0214d1fc(a, data_ov000_021b6434[g].mUnk_04, 6);
            return;
        }
    }
    if (c != 0) {
        e = 0;
        f = 0;
        for (g = 0, p = data_ov000_021b6434; g < 8; g++) {
            if (p->mUnk_00 == 0) {
                f = g;
                break;
            }
            if ((s16) (d - p->mUnk_0a) > e) {
                e = d - p->mUnk_0a;
                f = g;
            }
            p++;
        }
        data_ov000_021b6434[f].mUnk_00 = b;
        func_0214d1fc(a, data_ov000_021b6434[f].mUnk_04, 6);
        data_ov000_021b6434[f].mUnk_0a = d;
    }
}

u8 *func_ov000_021afc20(u32 a) {
    u32 b;
    u32 c;
    u8 *d;

    for (b = 0; b < 8; b++) {
        func_ov000_021afc5c(a);
        for (c = 0; c < 0x14; c++) {
            func_0200dc3c(100);
            d = func_ov000_021afd00(a);
            if (d != NULL) {
                return d;
            }
        }
    }
    return NULL;
}

void func_ov000_021afc5c(u32 a) {
    Unk021afc5c b;

    func_0214d168(&b, 0, 0x2a);
    func_0214d168(&b, 0xff, 6);
    func_0214d1fc(data_ov000_021b63d0, b.mUnk_06, 6);
    b.mUnk_0c = 0x608;
    b.mUnk_0f = 1;
    b.mUnk_10 = 8;
    b.mUnk_12 = 0x406;
    b.mUnk_15 = 1;
    func_0214d1fc(data_ov000_021b63d0, b.mUnk_16, 6);
    b.mUnk_1c = ((u16) (*(u32 *) &data_ov000_021b63b4 >> 16) >> 8) | ((u16) (*(u32 *) &data_ov000_021b63b4 >> 16) << 8);
    b.mUnk_1e = ((u16) data_ov000_021b63b4 >> 8) | ((u16) data_ov000_021b63b4 << 8);
    b.mUnk_26 = ((u16) (a >> 16) >> 8) | ((u16) (a >> 16) << 8);
    b.mUnk_28 = ((u16) a >> 8) | ((u16) a << 8);
    func_ov000_021affcc((u8 *) &b, 0x2a, NULL, 0);
}

u8 *func_ov000_021afd00(u32 a) {
    u32 b;
    u8 *c;
    u32 d;
    u16 e;

    b = func_0200fca0();
    c = NULL;
    if (a == 0x7f000001 || a == data_ov000_021b63b4) {
        c = (u8 *) data_ov000_021b63d0;
    } else if (func_ov000_021b00b0(a) != 0 || func_ov000_021b0094(a) != 0) {
        c = data_ov000_021b4c2c;
    } else {
        for (d = 0; d < 8; d++) {
            if (a == data_ov000_021b6434[d].mUnk_00) {
                e = func_0200f5ac() >> 16;
                data_ov000_021b6434[d].mUnk_0a = e;
                c = data_ov000_021b6434[d].mUnk_04;
                break;
            }
        }
    }
    func_0200fcb4(b);
    return c;
}

void func_ov000_021afd8c(void) {
    u32 a;
    u32 b;
    u8 *c;

    a = func_0200fca0();
    b = data_ov000_021b63cc;
    c = data_ov000_021b63c4;
    data_ov000_021b63cc = b + (c[b] + ((c + b)[1] << 8));
    if (data_ov000_021b63cc >= data_ov000_021b63c8) {
        data_ov000_021b63cc = 0;
    }
    func_0200fcb4(a);
}

u8 *func_ov000_021afdcc(u32 *a) {
    u16 b;
    u32 c;
    u8 *d;

    while (data_ov000_021b63cc == data_ov000_021b6394) {
        data_ov000_021b63c0 = data_0216ff5c.mUnk_04;
        func_0200e01c(NULL);
        data_ov000_021b63c0 = NULL;
    }
    c = data_ov000_021b63c8;
    d = data_ov000_021b63c4;
    do {
        if (c - data_ov000_021b63cc < 2) {
            data_ov000_021b63cc = 0;
        }
        b = d[data_ov000_021b63cc] + ((d + data_ov000_021b63cc)[1] << 8);
        if (b == 0) {
            data_ov000_021b63cc = 0;
        }
    } while (b == 0);
    *a = b - 2;
    return data_ov000_021b63c4 + data_ov000_021b63cc + 2;
}
