#include "00/code_0218e8c4.h"
#include "00/code_0218f960.h"
#include "00/code_02190000.h"
#include "code_02139f70.h"
#include "00/code_0218d000.h"
#include "00/code_021a3000.h"
#include "00/unk_021b2000.h"
#include "code_0213442c.h"
#include "00/code_0218dc44.h"
#include "00/code_0218e368.h"
#include "00/code_021965a0.h"
#include "00/code_02190ba0.h"
#include "00/code_02196000.h"
#include "code_02135014.h"
#include "00/code_021906e4.h"
#include "00/code_02196590.h"
#include "00/code_02196914.h"
#include "00/unk_021b23b0.h"
#include "code_0200f5ac.h"
#include "code_0200f6e4.h"

u32 func_ov000_0218eb44(Unk0218f960 *a, u32 b) {
    Unk0218f960_00 *o;
    u32 r;
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
    r = func_ov000_0218f960(a, b);
    if (r == 0) {
        return 0;
    }
    return r;
}

u32 func_ov000_0218e974(Unk0218f960 *a, s32 b, const u8 *c, const u8 *d) {
    Unk0218f960_00 *o;
    u8 e[0x100];
    u8 f[0x100];
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
        func_ov000_02196590(a, data_ov000_021b2450);
        return 2;
    }
    if (d == 0) {
        func_ov000_02196590(a, data_ov000_021b2468);
        return 2;
    }
    func_ov000_02196914(e, c, 0x100);
    if (*(s8 *) e != 0) {
        g = (s8 *) e;
        do {
            if (*g == 0x5c) {
                *g = 0x2f;
            }
            g++;
        } while (*g != 0);
    }
    func_ov000_02196914(f, d, 0x100);
    if (*(s8 *) f != 0) {
        g = (s8 *) f;
        do {
            if (*g == 0x5c) {
                *g = 0x2f;
            }
            g++;
        } while (*g != 0);
    }
    if (b == o->mUnk_214 && func_0213a074(e, o->mUnk_218) == 0 && func_0213a074(f, o->mUnk_318) == 0) {
        return 0;
    }
    o->mUnk_214 = b;
    func_ov000_02196914(o->mUnk_218, e, 0x100);
    func_ov000_02196914(o->mUnk_318, f, 0x100);
    func_ov000_02190b80(a, &o->mUnk_1f4, data_ov000_021b2480);
    func_ov000_02190b58(a, &o->mUnk_1f4, b);
    func_ov000_02190b80(a, &o->mUnk_1f4, data_ov000_021b2418);
    func_ov000_02190b58(a, &o->mUnk_1f4, o->mUnk_198);
    func_ov000_02190b80(a, &o->mUnk_1f4, data_ov000_021b248c);
    func_ov000_02190b80(a, &o->mUnk_1f4, e);
    func_ov000_02190b80(a, &o->mUnk_1f4, data_ov000_021b249c);
    func_ov000_02190b80(a, &o->mUnk_1f4, f);
    func_ov000_02190b80(a, &o->mUnk_1f4, data_ov000_021b2424);
    return 0;
}

u32 func_ov000_0218e908(Unk0218f960 *a, s32 b, const u8 *c) {
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
    if (c == 0) {
        func_ov000_02196590(a, data_ov000_021b243c);
        return 2;
    }
    return func_ov000_0218fb3c(a, b, 1, c);
}

u32 func_ov000_0218e8c4(void) {
    u64 t;
    if (func_0200f6e4() != 1) {
        func_0213442c(data_ov000_021b23b0, data_ov000_021b23d0, 0, 0x109);
    }
    t = func_0200f5ac();
    return (t << 6) / 0x82ea;
}
