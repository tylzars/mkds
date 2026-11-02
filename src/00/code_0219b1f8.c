#include "00/code_0219b1f8.h"
#include "00/code_0218d000.h"
#include "00/code_021a3000.h"
#include "00/unk_021b2000.h"
#include "code_0213442c.h"
#include "00/code_0218dc44.h"
#include "00/unk_021b4000.h"
#include "00/code_0218e368.h"
#include "00/code_0219887c.h"
#include "00/code_0219a654.h"
#include "00/code_0219b8a8.h"
#include "00/code_0219b8bc.h"
#include "00/code_0219c384.h"
#include "00/code_0219d000.h"
#include "00/code_0219c000.h"
#include "00/unk_021b5000.h"
#include "code_02139f70.h"
#include "00/code_0219d128.h"
#include "code_0200d118.h"
#include "00/code_021a10b0.h"
#include "00/code_021a17bc.h"
#include "00/code_021a1ae0.h"
#include "00/code_021a2ccc.h"
#include "00/code_021a4784.h"
#include "code_02134d30.h"
#include "code_0213a460.h"
#include "00/code_0219b580.h"

Unk0219b1d4 *func_ov000_0219b1f8(u32 a) {
    s32 b;
    Unk0219b1d4 *c;

    if (data_ov000_021b52c4 == 0) {
        return 0;
    }
    for (b = 0; b < func_ov000_0218dc44((u32 *) data_ov000_021b52c4); b++) {
        c = func_ov000_0218dbf8(data_ov000_021b52c4, b);
        if (c->mUnk_08 == a) {
            return c;
        }
    }
    return 0;
}

void func_ov000_0219b240(u32 *a) {
    data_ov000_021b54cc = func_ov000_0218e368(func_ov000_021988d8(a));
    func_ov000_0219c384(0xb, -0x17aeb);
    data_ov000_021b54c8->mUnk_00 = 0;
}

void func_ov000_0219b274(Unk0219887c *a, u32 b) {
    func_ov000_021a314c(a, b);
}

void func_ov000_0219b27c(Unk0219887c *a, u32 b) {
    u32 e;
    s32 d;
    s32 f;
    u8 *g;
    u32 h;
    s32 c;
    u32 i;
    Unk021b54c8 *j;
    u32 k;
    void **m;

    e = 0;
    f = 0;
    if (func_ov000_021a141c() != 0) {
        return;
    }
    switch (b) {
        case 0:
        case 1:
            c = 0;
            break;
        case 2:
        case 3:
            c = 6;
            d = -0x1db0;
            break;
        case 4:
            c = 0xb;
            d = -0x1db1;
            break;
    }
    if (c == 0) {
        g = func_ov000_0219887c(a);
        if (g == 0) {
            return;
        }
        h = g[1];
        i = (data_ov000_021b54c8->mUnk_33c.mUnk_2d8 & (1 << h)) != 0;
        func_ov000_021a2ff8(h);
        j = data_ov000_021b54c8;
        if ((j->mUnk_33c.mUnk_15 == 2 && b == 0) || (j->mUnk_33c.mUnk_15 == 3 && h == 0)) {
            f = 1;
        }
        e = func_ov000_0219b868(h);
        data_ov000_021b54d0[g[0]] = 0;
        data_ov000_021b54c8->mUnk_33c.mUnk_0d--;
        data_ov000_021b54c8->mUnk_33c.mUnk_14--;
    }
    if (data_ov000_021b54c8->mUnk_2d == 0 && data_ov000_021b54c8->mUnk_24 == 6 && i == 0) {
        if (data_ov000_021b54c8->mUnk_33c.mUnk_15 == 2 && c == 0) {
            func_ov000_021a1488();
            func_ov000_021a1798(e);
        }
        return;
    }
    if (func_ov000_021a17bc(c, d, e) != 0) {
        return;
    }
    if (c != 0) {
        func_ov000_0219c384(c, d);
        return;
    }
    if (data_ov000_021b54c8->mUnk_33c.mUnk_15 == 2) {
        if (data_ov000_021b54c8->mUnk_2d == 0) {
            func_ov000_021a1488();
        } else if (data_ov000_021b54c8->mUnk_33c.mUnk_0d == 0) {
            func_ov000_0219d558(1, data_ov000_021b4054, 0);
        }
    } else if (data_ov000_021b54c8->mUnk_33c.mUnk_0d == 0) {
        func_ov000_0219d558(1, data_ov000_021b4054, 0);
    }
    if (data_ov000_021b54c8->mUnk_33c.mUnk_15 == 0 || data_ov000_021b54c8->mUnk_33c.mUnk_15 == 1) {
        data_ov000_021b54c8->mUnk_33c.mUnk_16 = data_ov000_021b54c8->mUnk_33c.mUnk_14;
        func_ov000_021a4818(data_ov000_021b54c8->mUnk_33c.mUnk_10);
    }
    j = data_ov000_021b54c8;
    if (j->mUnk_7c != 0 && i != 0) {
        if (b == 0) {
            b = 1;
        } else {
            b = 0;
        }
        k = func_ov000_0219d5e4(e);
        m = &j->mUnk_80;
        data_ov000_021b54c8->mUnk_7c(c, b, f, h, k, *m);
    }
    if (data_ov000_021b54c8->mUnk_2d != 0 || data_ov000_021b54c8->mUnk_33c.mUnk_15 != 2) {
        if (data_ov000_021b54c8->mUnk_33c.mUnk_0d == 0) {
            func_ov000_0219b110();
            func_ov000_021a1a10();
            func_ov000_0219b8a8(3);
        }
    }
}

void func_ov000_0219b4a4(Unk0219887c *a, void *b, s32 c, u32 d) {
    func_ov000_021a317c(a, b, c, d);
}

void func_ov000_0219b4b4(u32 a, Unk0219b4b4 *b, u32 g) {
    u8 *d;
    u8 c[12] = {0};
    u32 e;
    Unk021b54c8 *f;

    d = b->mUnk_08;
    if (func_ov000_0219d6c4(a, (u32 *) b, g) == 0) {
        if (func_02134d30(d, data_ov000_021b4058, func_0213a434(data_ov000_021b4058)) == 0) {
            d += func_0213a434(data_ov000_021b4058);
            e = func_02139ffc(d, 0x76) - d;
            func_0213a228(c, d, e);
            if (e <= 10) {
                if (func_0213c074(c, 0, 10) == 3) {
                    d += e + 1;
                    if (func_02134d30(d, data_ov000_021b4060, func_0213a434(data_ov000_021b4060)) == 0) {
                        f = data_ov000_021b54c8;
                        if (f->mUnk_24 == 5 || f->mUnk_33c.mUnk_15 == 2 || f->mUnk_33c.mUnk_15 == 3) {
                            d += func_0213a434(data_ov000_021b4060);
                            func_ov000_021a1ae0(a, b->mUnk_00, d);
                        }
                    }
                }
            }
        }
    }
}
