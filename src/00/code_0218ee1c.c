#include "00/code_0218ee1c.h"
#include "00/code_0218faac.h"
#include "00/code_02190b80.h"
#include "00/code_02190988.h"
#include "00/code_0219218c.h"
#include "00/code_021960a4.h"
#include "00/code_02196590.h"
#include "00/code_02196914.h"
#include "00/unk_021b2000.h"
#include "00/unk_021b23b0.h"

u32 func_ov000_0218ee1c(Unk0218f960 *a, u32 b) {
    Unk0218f960_00 *o;
    if (a == 0 || (o = a->mUnk_00) == 0) {
        return 2;
    }
    if (o->mUnk_108 != 0) {
        return 0;
    }
    if (o->mUnk_1d8 == 4) {
        func_ov000_02196590(a, data_ov000_021b23e8);
        return 2;
    }
    return func_ov000_0218faac(a, b);
}

u32 func_ov000_0218ee70(Unk0218f960 *a, u32 b, const u8 *c) {
    Unk0218f960_00 *o;
    u8 e[0x401];
    s8 *g;
    if (a == 0 || (o = a->mUnk_00) == 0) {
        return 2;
    }
    if (o->mUnk_108 != 0) {
        return 0;
    }
    if (o->mUnk_1d8 == 4) {
        func_ov000_02196590(a, data_ov000_021b23e8);
        return 2;
    }
    if (c == 0) {
        func_ov000_02196590(a, data_ov000_021b24dc);
        return 2;
    }
    func_ov000_02196914(e, c, 0x401);
    if (*(s8 *) e != 0) {
        g = (s8 *) e;
        do {
            if (*g == 0x5c) {
                *g = 0x2f;
            }
            g++;
        } while (*g != 0);
    }
    func_ov000_02190b80(a, &o->mUnk_1f4, data_ov000_021b24ec);
    func_ov000_02190b80(a, &o->mUnk_1f4, data_ov000_021b2418);
    func_ov000_02190b58(a, &o->mUnk_1f4, o->mUnk_198);
    func_ov000_02190b80(a, &o->mUnk_1f4, data_ov000_021b24f8);
    func_ov000_02190b58(a, &o->mUnk_1f4, b);
    func_ov000_02190b80(a, &o->mUnk_1f4, data_ov000_021b2508);
    func_ov000_02190b80(a, &o->mUnk_1f4, e);
    func_ov000_02190b80(a, &o->mUnk_1f4, data_ov000_021b2424);
    return 0;
}

u32 func_ov000_0218efa8(Unk0218f960 *a, s32 b, const s8 *c) {
    Unk0218f960_00 *o;
    if (a == 0 || (o = a->mUnk_00) == 0) {
        return 2;
    }
    if (o->mUnk_108 != 0) {
        return 0;
    }
    if (o->mUnk_1d8 == 4) {
        func_ov000_02196590(a, data_ov000_021b23e8);
        return 2;
    }
    return func_ov000_021923b4(a, b, c);
}

u32 func_ov000_0218eff8(Unk0218f960 *a, u32 b, s32 c, u32 d, Unk0218eff8Cb e, u32 f) {
    Unk0218f960_00 *o;
    if (a == 0 || (o = a->mUnk_00) == 0 || b == 0) {
        return 2;
    }
    if (e == 0) {
        func_ov000_02196590(a, data_ov000_021b242c);
        return 2;
    }
    if (o->mUnk_108 != 0) {
        Unk0218eff8Arg g = {0};
        e(a, &g, f);
        return 0;
    }
    if (o->mUnk_1d8 == 4) {
        func_ov000_02196590(a, data_ov000_021b23e8);
        return 2;
    }
    return func_ov000_0219222c(a, b, c, d, (u32) e, f);
}

u32 func_ov000_0218f0a8(Unk0218f960 *a, s8 *b, s8 *c, s8 *d, s8 *e, s8 *f, s32 g, u32 h, Unk0218f0a8Cb i, u32 j) {
    Unk0218f960_00 *o;
    if (a == 0 || (o = a->mUnk_00) == 0) {
        return 2;
    }
    if (i == 0) {
        func_ov000_02196590(a, data_ov000_021b242c);
        return 2;
    }
    if (o->mUnk_108 != 0) {
        Unk0218f0a8Arg k = {0};
        k.mUnk_08 = 0x601;
        i(a, &k, j);
        return 0;
    }
    return func_ov000_021960a4(a, b, c, d, e, f, g, 0, h, (u32) i, j);
}
