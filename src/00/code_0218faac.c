#include "00/code_0218faac.h"
#include "00/code_02190000.h"
#include "00/code_02190548.h"
#include "00/code_02190b80.h"
#include "00/code_02190988.h"
#include "00/code_021947e4.h"
#include "00/code_021948f8.h"
#include "00/code_02193818.h"
#include "00/code_02193e70.h"
#include "00/code_02193eac.h"
#include "00/code_02193f2c.h"
#include "00/code_02196590.h"
#include "00/code_02196914.h"
#include "00/code_021a3668.h"
#include "00/unk_021b2000.h"
#include "00/unk_021b23b0.h"

u32 func_ov000_0218fbe0(Unk0218f960 *a, s32 b, s32 c, const u8 *d) {
    Unk0218f960_00 *o;
    u8 e[0xdad];
    o = a->mUnk_00;
    func_ov000_02196914(e, d, 0xdad);
    func_ov000_02190b80(a, &o->mUnk_1f4, data_ov000_021b27c4);
    func_ov000_02190b58(a, &o->mUnk_1f4, c);
    func_ov000_02190b80(a, &o->mUnk_1f4, data_ov000_021b275c);
    func_ov000_02190b58(a, &o->mUnk_1f4, o->mUnk_198);
    func_ov000_02190b80(a, &o->mUnk_1f4, data_ov000_021b27cc);
    func_ov000_02190b58(a, &o->mUnk_1f4, b);
    func_ov000_02190b80(a, &o->mUnk_1f4, data_ov000_021b27d0);
    func_ov000_02190b80(a, &o->mUnk_1f4, e);
    func_ov000_02190b80(a, &o->mUnk_1f4, data_ov000_021b2778);
    return 0;
}

u32 func_ov000_0218fb3c(Unk0218f960 *a, s32 b, s32 c, const u8 *d) {
    Unk02194934 *e;
    Unk02193f2cNode *n;
    u32 r;
    n = func_ov000_02193f2c(a, b);
    if (n == 0) {
        if (func_ov000_02194934(a, b, &e) == 0 || e->mUnk_08 == 0 || e->mUnk_08->mUnk_14 == 0) {
            return func_ov000_0218fbe0(a, b, c, d);
        }
        n = func_ov000_02193eac(a, b, 1);
        if (n == 0) {
            return 1;
        }
        if (e->mUnk_18 == 0) {
            r = func_ov000_02193e70(a, n);
            if (r != 0) {
                return r;
            }
        } else {
            r = func_ov000_02193d64(a, n);
            if (r != 0) {
                return r;
            }
        }
    }
    r = func_ov000_02193c74(a, n, c, d);
    if (r == 0) {
        return 0;
    }
    return r;
}

u32 func_ov000_0218faac(Unk0218f960 *a, u32 b) {
    Unk0218f960_00 *o;
    Unk02194934 *e;
    u32 r;
    o = a->mUnk_00;
    if (func_ov000_02194934(a, b, &e) == 0) {
        func_ov000_02196590(a, data_ov000_021b273c);
        return 2;
    }
    if (e->mUnk_10 == 0) {
        func_ov000_02196590(a, data_ov000_021b273c);
        return 2;
    }
    r = func_ov000_02190548(a, e);
    if (r == 0) {
        e->mUnk_14--;
        if (o->mUnk_100 == 0 && e->mUnk_14 <= 0) {
            func_ov000_021a3668(e->mUnk_10);
            e->mUnk_10 = 0;
            if (func_ov000_021947e4(e) != 0) {
                func_ov000_021948f8(a, e);
            }
        }
        return 0;
    }
    return r;
}
