#include "00/code_021a9228.h"
#include "00/code_021a9aa0.h"

#include "00/code_021aa004.h"
#include "00/code_021ab6d4.h"
#include "00/code_021abd2c.h"
#include "00/code_021ad734.h"
#include "00/types_021a998c.h"
#include "00/types_021ab5e4.h"
#include "00/unk_021b6000.h"
#include "code_0214d018.h"
#include "00/code_021abca0.h"
#include "code_0200db4c.h"

void func_ov000_021a998c(Unk021a998c *a) {
    u8 *msg;
    Unk021a998c_0c *obj;
    obj = a->mUnk_0c;
    msg = data_ov000_021b63a4(0x83);
    if (msg == NULL) {
        obj->mUnk_429 = 9;
        return;
    }
    msg[0] = 0x14;
    msg[1] = 3;
    msg[2] = 0;
    msg[3] = 0;
    msg[4] = 1;
    msg[5] = 1;
    MemFill(obj->mUnk_1a0, 0, 8);
    msg[6] = 0x16;
    msg[7] = 3;
    msg[8] = 0;
    msg[9] = 0;
    msg[10] = 0x28;
    msg[11] = 0x14;
    msg[12] = 0;
    msg[13] = 0;
    msg[14] = 0x24;
    MemCopy(obj->mUnk_378, obj->mUnk_3d0, 0x58);
    func_ov000_021aa50c(obj, msg + 0xf, 0);
    MemCopy(obj->mUnk_3d0, obj->mUnk_378, 0x58);
    MemCopy(obj->mUnk_2c0, obj->mUnk_31c, 0x5c);
    func_ov000_021aa468(obj, msg + 0x1f, 0);
    MemCopy(obj->mUnk_31c, obj->mUnk_2c0, 0x5c);
    func_ov000_021abca0(obj->mUnk_2c0, msg + 0xb, 0x28);
    func_ov000_021ab728(obj->mUnk_378, msg + 0xb, 0x28);
    func_ov000_021adcec(msg, func_ov000_021aa054(obj, msg + 6) + 6, NULL, 0, a);
    data_ov000_021b63ac(msg);
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
    if (b == NULL) {
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
    MemCopy(c->mUnk_008, d + 2, 0x20);
    c->mUnk_000 = func_ov000_021ab63c(a->mUnk_1c, a->mUnk_18);
    if (c->mUnk_000 != NULL) {
        d[0x22] = 0x20;
        MemCopy(c->mUnk_000, d + 0x23, 0x20);
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
    func_ov000_021adcec(b, g + 5, NULL, 0, a);
    func_ov000_021ab728(c->mUnk_378, b + 5, g);
    func_ov000_021abca0(c->mUnk_2c0, b + 5, g);
    data_ov000_021b63ac(b);
}

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
    if (e == NULL) {
        c->mUnk_429 = 9;
        return;
    }
    e[0] = 0;
    e[1] = 2;
    func_ov000_021a9ca8(e + 2, b - 0x33);
    e[b - 0x31] = 0;
    MemCopy(c->mUnk_000->mUnk_20, e + b - 0x30, 0x30);
    f = (u16 *) data_ov000_021b63a4(d * 8);
    if (f == NULL) {
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
    if (j == NULL) {
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
    func_ov000_021adcec(j, b + 9, NULL, 0, a);
    func_ov000_021ab728(c->mUnk_378, j + 5, (u32) b + 4);
    func_ov000_021abca0(c->mUnk_2c0, j + 5, b + 4);
    data_ov000_021b63ac(j);
    data_ov000_021b63ac(f);
    data_ov000_021b63ac(e);
}

u32 func_ov000_021a9610(u32 a) {
    int v1;
    v1 = func_ov000_021a9d68((Unk021a998c *) a);
    if (v1 != 7) {
        return 1;
    }
    v1 = func_ov000_021a9d68((Unk021a998c *) a);
    if (v1 != 6) {
        return 1;
    }
    return 0;
}

BOOL func_ov000_021a95a0(Unk021a998c *a) {
    if (func_ov000_021a9d68(a) != 1) {
        return TRUE;
    }
    if (func_ov000_021a9aa0(a) != 0) {
        func_ov000_021aa5e0(a->mUnk_0c);
        func_ov000_021a998c(a);
        if (func_ov000_021a9610((u32) a) != 0) {
            return TRUE;
        }
    } else {
        if (func_ov000_021a9d68(a) != 5) {
            return TRUE;
        }
        if (func_ov000_021a9610((u32) a) != 0) {
            return TRUE;
        }
        func_ov000_021a998c(a);
    }
    return FALSE;
}

void func_ov000_021a9534(Unk021a998c *a) {
    Unk021a998c_0c *c = a->mUnk_0c;
    while (1) {
        func_ov000_021ae228(a);
        c->mUnk_429 = 0;
        c->mUnk_428 = 1;
        func_ov000_021abd2c((u32 *) c->mUnk_2c0);
        func_ov000_021ab7b4((u32 *) c->mUnk_378);
        if (func_ov000_021a95a0(a) == 0) {
            c->mUnk_429 = 8;
            return;
        }
        func_ov000_021ae0c4(a);
        a->mUnk_18 = a->mUnk_1a;
        a->mUnk_1c = a->mUnk_20;
    }
}

BOOL func_ov000_021a9494(Unk021a998c *a) {
    Unk021a998c_0c *c = a->mUnk_0c;
    u8 b;
    func_ov000_021a9868(a);
    while (1) {
        b = func_ov000_021a9d68(a);
        if (b == 9) {
            return TRUE;
        }
        if (b == 4 || c->mUnk_004 != 0) {
            break;
        }
    }
    if (c->mUnk_004 != 0) {
        func_ov000_021aa5e0(c);
        if (func_ov000_021a9610((u32) a) != 0) {
            return TRUE;
        }
        func_ov000_021a998c(a);
    } else {
        c->mUnk_000->mUnk_54 = a->mUnk_1c;
        c->mUnk_000->mUnk_58 = a->mUnk_18;
        func_ov000_021a9640(a);
        func_ov000_021aa7b4(c);
        func_ov000_021aa5e0(c);
        func_ov000_021a998c(a);
        if (func_ov000_021a9610((u32) a) != 0) {
            return TRUE;
        }
    }
    c->mUnk_429 = 8;
    return FALSE;
}

s32 func_ov000_021a943c(Unk021a998c *a) {
    Unk021a998c_0c *c = a->mUnk_0c;
    if (a->mState != 4 && func_ov000_021ae16c(a) != 0) {
        return 1;
    }
    c->mUnk_429 = 0;
    c->mUnk_428 = 0;
    func_ov000_021abd2c((u32 *) c->mUnk_2c0);
    func_ov000_021ab7b4((u32 *) c->mUnk_378);
    return func_ov000_021a9494(a);
}

u8 *func_ov000_021a93e0(s32 *a, Unk021a998c *b) {
    Unk021a998c_0c *c = b->mUnk_0c;
    while (c->mUnk_7f8 == NULL) {
        if (func_ov000_021a9d68(b) == 9) {
            *a = 0;
            return NULL;
        }
    }
    *a = c->mUnk_7fc - c->mUnk_800;
    return c->mUnk_7f8 + c->mUnk_800;
}

void func_ov000_021a9394(u32 a, Unk021a998c *b) {
    Unk021a998c_0c *c = b->mUnk_0c;
    if (a >= c->mUnk_7fc - c->mUnk_800) {
        data_ov000_021b63ac(c->mUnk_7f8);
        c->mUnk_7f8 = NULL;
        c->mUnk_800 = c->mUnk_7fc;
    } else {
        c->mUnk_800 += a;
    }
}

s32 func_ov000_021a9358(Unk021a998c *a) {
    Unk021a998c_0c *c = a->mUnk_0c;
    if (c->mUnk_7f8 == NULL) {
        if (a->mReceiveBufferLength == 0) {
            return 0;
        }
        func_ov000_021a9d68(a);
    }
    return c->mUnk_7fc - c->mUnk_800;
}

s32 func_ov000_021a9280(u8 *a, u32 b, u8 *c, u32 d, Unk021a998c *e) {
    Unk021a998c_0c *f = e->mUnk_0c;
    s32 g = b + d;
    u8 *l;
    s32 i;
    u32 j;
    u32 k;
    s32 h = 0;
    u8 m = 0;
    s32 n = 0;
    BOOL p = FALSE;
    while (1) {
        if (g > 0xb4f) {
            i = 0xb4f;
        } else {
            i = g;
        }
        l = data_ov000_021b63a4(i + 0x19);
        if (l == NULL) {
            break;
        }
        if (b >= i) {
            j = i;
        } else {
            j = b;
        }
        k = i - j;
        MemCopy(a, l + 5, j);
        a += j;
        b -= j;
        MemCopy(c, l + 5 + j, k);
        c += k;
        l[0] = 0x17;
        l[1] = 3;
        l[2] = m;
        l[3] = i >> 8;
        l[4] = i;
        j = func_ov000_021aa054(f, l);
        if (func_ov000_021adcec(l, j, (const u8 *) n, n, e) < j) {
            i = p;
        }
        data_ov000_021b63ac(l);
        g -= i;
        h += i;
        if (g == 0) {
            break;
        }
        if (i == 0) {
            break;
        }
    }
    return h;
}

void func_ov000_021a9228(Unk021a998c *a) {
    Unk021a998c_0c *c = a->mUnk_0c;
    u8 b[0x20];
    if (c->mUnk_429 == 8) {
        b[0] = 0x15;
        b[1] = 3;
        b[2] = 0;
        b[3] = 0;
        b[4] = 2;
        b[5] = 1;
        b[6] = 0;
        func_ov000_021adcec(b, func_ov000_021aa054(c, b), NULL, 0, a);
    }
    func_ov000_021ae0c4(a);
    c->mUnk_429 = 0;
}
