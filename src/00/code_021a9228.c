#include "00/code_021a9228.h"
#include "00/code_021a9aa0.h"
#include "00/code_021a9640.h"
#include "00/code_021a9610.h"
#include "00/code_021aa054.h"
#include "00/code_021aa5e0.h"
#include "00/code_021aa7b4.h"
#include "00/code_021ab7b4.h"
#include "00/code_021abd2c.h"
#include "00/code_021ae214.h"

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
        func_ov000_021adcec(b, func_ov000_021aa054(c, b), 0, 0, a);
    }
    func_ov000_021ae0c4(a);
    c->mUnk_429 = 0;
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
    s32 p = 0;
    while (1) {
        if (g > 0xb4f) {
            i = 0xb4f;
        } else {
            i = g;
        }
        l = data_ov000_021b63a4(i + 0x19);
        if (l == 0) {
            break;
        }
        if (b >= i) {
            j = i;
        } else {
            j = b;
        }
        k = i - j;
        func_0214d1fc(a, l + 5, j);
        a += j;
        b -= j;
        func_0214d1fc(c, l + 5 + j, k);
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

s32 func_ov000_021a9358(Unk021a998c *a) {
    Unk021a998c_0c *c = a->mUnk_0c;
    if (c->mUnk_7f8 == 0) {
        if (a->mUnk_44 == 0) {
            return 0;
        }
        func_ov000_021a9d68(a);
    }
    return c->mUnk_7fc - c->mUnk_800;
}

void func_ov000_021a9394(u32 a, Unk021a998c *b) {
    Unk021a998c_0c *c = b->mUnk_0c;
    if (a >= c->mUnk_7fc - c->mUnk_800) {
        data_ov000_021b63ac(c->mUnk_7f8);
        c->mUnk_7f8 = 0;
        c->mUnk_800 = c->mUnk_7fc;
    } else {
        c->mUnk_800 += a;
    }
}

u8 *func_ov000_021a93e0(s32 *a, Unk021a998c *b) {
    Unk021a998c_0c *c = b->mUnk_0c;
    while (c->mUnk_7f8 == 0) {
        if (func_ov000_021a9d68(b) == 9) {
            *a = 0;
            return 0;
        }
    }
    *a = c->mUnk_7fc - c->mUnk_800;
    return c->mUnk_7f8 + c->mUnk_800;
}

s32 func_ov000_021a943c(Unk021a998c *a) {
    Unk021a998c_0c *c = a->mUnk_0c;
    if (a->mUnk_08 != 4 && func_ov000_021ae16c(a) != 0) {
        return 1;
    }
    c->mUnk_429 = 0;
    c->mUnk_428 = 0;
    func_ov000_021abd2c((u32 *) c->mUnk_2c0);
    func_ov000_021ab7b4((u32 *) c->mUnk_378);
    return func_ov000_021a9494(a);
}

s32 func_ov000_021a9494(Unk021a998c *a) {
    Unk021a998c_0c *c = a->mUnk_0c;
    u8 b;
    func_ov000_021a9868(a);
    while (1) {
        b = func_ov000_021a9d68(a);
        if (b == 9) {
            return 1;
        }
        if (b == 4 || c->mUnk_004 != 0) {
            break;
        }
    }
    if (c->mUnk_004 != 0) {
        func_ov000_021aa5e0(c);
        if (func_ov000_021a9610((u32) a) != 0) {
            return 1;
        }
        func_ov000_021a998c(a);
    } else {
        c->mUnk_000->mUnk_54 = a->mUnk_1c;
        c->mUnk_000->mUnk_58 = a->mUnk_18;
        func_ov000_021a9640(a);
        func_ov000_021aa7b4((int *) c);
        func_ov000_021aa5e0(c);
        func_ov000_021a998c(a);
        if (func_ov000_021a9610((u32) a) != 0) {
            return 1;
        }
    }
    c->mUnk_429 = 8;
    return 0;
}

// non-matching: 2 instructions swapped; ours computes the 0x2c0 offset (ldr, adds r6) before `movs r7, #0`, the
// original after it; size equal
void func_ov000_021a9534(Unk021a998c *a) {
    Unk021a998c_0c *c = a->mUnk_0c;
    u8 *d;
    u8 b;
    d = c->mUnk_2c0;
    b = 0;
    while (1) {
        func_ov000_021ae228(a);
        c->mUnk_429 = b;
        c->mUnk_428 = 1;
        func_ov000_021abd2c((u32 *) d);
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

s32 func_ov000_021a95a0(Unk021a998c *a) {
    if (func_ov000_021a9d68(a) != 1) {
        return 1;
    }
    if (func_ov000_021a9aa0(a) != 0) {
        func_ov000_021aa5e0(a->mUnk_0c);
        func_ov000_021a998c(a);
        if (func_ov000_021a9610((u32) a) != 0) {
            return 1;
        }
    } else {
        if (func_ov000_021a9d68(a) != 5) {
            return 1;
        }
        if (func_ov000_021a9610((u32) a) != 0) {
            return 1;
        }
        func_ov000_021a998c(a);
    }
    return 0;
}
