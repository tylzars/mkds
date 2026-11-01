#include "00/code_02193f50.h"
#include "00/code_02193818.h"
#include "00/code_02193eac.h"
#include "00/code_02194000.h"
#include "00/code_02196000.h"
#include "00/code_0218d000.h"
#include "00/code_0218e80c.h"
#include "00/code_0218dc44.h"
#include "00/code_0218e524.h"
#include "00/code_0218e53c.h"
#include "00/code_0218e644.h"
#include "00/code_021a3668.h"
#include "00/unk_021b2000.h"
#include "00/unk_021b3000.h"
#include "code_0213442c.h"
#include "00/code_0218da04.h"

s32 func_ov000_02194160(Unk0218f960 *param_1, Unk02193f2cNode *param_2) {
    s32 a = 0;

    if (param_2->mUnk_00 == 0x64) {
        func_0213442c(data_ov000_021b3468, data_ov000_021b333c, 0, 0x1d9);
    }
    if (param_2->mUnk_00 != 0x69) {
        if (param_2->mUnk_04 != 0) {
            a = func_ov000_02194590(param_1, param_2);
        } else {
            a = func_ov000_021943f0(param_1, param_2);
        }
    }
    if (a == 0 && param_2->mUnk_00 == 0x69) {
        a = func_ov000_021941c4(param_1, param_2);
    }
    return a;
}

void func_ov000_02194120(Unk0218f960 *param_1, Unk02193f2cNode *param_2) {
    func_ov000_0218e524(param_2->mUnk_08, 2);
    func_ov000_0218e53c(param_2->mUnk_08);
    func_ov000_021a3668(param_2->mUnk_18);
    param_2->mUnk_18 = 0;
    func_ov000_021a3668(*(void **) param_2->mUnk_28);
    *(void **) param_2->mUnk_28 = 0;
    if (param_2->mUnk_38 != 0) {
        func_ov000_0218dc48(param_2->mUnk_38);
        param_2->mUnk_38 = 0;
    }
    func_ov000_021a3668(param_2);
}

void func_ov000_0219405c(Unk0218f960 *param_1, Unk02193f2cNode *param_2) {
    Unk0218f960_00 *a = param_1->mUnk_00;
    Unk02193f2cNode *b;
    Unk02193f2cNode *c;
    Unk0219405c *d;
    s32 e;

    if (param_2 == 0) {
        func_0213442c(data_ov000_021b332c, data_ov000_021b333c, 0, 0x213);
    }
    b = a->mUnk_434;
    if (b == param_2) {
        a->mUnk_434 = param_2->mNext;
    } else {
        c = b->mNext;
        while (c != param_2) {
            if (c == 0) {
                func_0213442c(data_ov000_021b3440, data_ov000_021b333c, 0, 0x225);
                func_ov000_0219690c(param_1, data_ov000_021b3444);
                return;
            }
            b = c;
            c = c->mNext;
        }
        b->mNext = param_2->mNext;
    }
    if (func_ov000_0218dc44(param_2->mUnk_38) != 0) {
        do {
            d = func_ov000_0218dbf8(param_2->mUnk_38, 0);
            if (d->mUnk_10 < 0x64) {
                func_ov000_0218fbe0(param_1, param_2->mUnk_0c, d->mUnk_10, (const u8 *) (d->mUnk_00 + d->mUnk_14));
            }
            func_ov000_0218da5c(param_2->mUnk_38, 0);
        } while (func_ov000_0218dc44(param_2->mUnk_38) != 0);
    }
    func_ov000_02194120(param_1, param_2);
}

void func_ov000_02193ff4(s32 param_1) {
    func_ov000_0218e7dc(param_1, 0x4000);
    func_ov000_0218e7dc(param_1, 0x8000);
    func_ov000_0218e7dc(param_1, 0x10000);
    func_ov000_0218e7dc(param_1, 0x20000);
    func_ov000_0218e7dc(param_1, 0x40000);
    func_ov000_0218e7ac(param_1, 0x4000);
    func_ov000_0218e7ac(param_1, 0x8000);
    func_ov000_0218e7ac(param_1, 0x10000);
    func_ov000_0218e77c(param_1);
    func_ov000_0218e74c(param_1);
}

s32 func_ov000_02193f50(Unk0218f960 *param_1) {
    Unk0218f960_00 *a = param_1->mUnk_00;
    Unk02193f2cNode *b;
    Unk02193f2cNode *c;
    s32 d;

    if (a->mUnk_204 != -1 && func_ov000_0218e668(a->mUnk_204) != 0) {
        d = func_ov000_0218e478(a->mUnk_204, 0, 0);
        if (d != -1) {
            b = func_ov000_02193eac(param_1, -1, 0);
            if (b != 0) {
                b->mUnk_00 = 0x68;
                b->mUnk_08 = d;
                func_ov000_0218e80c(d, 0);
                func_ov000_02193ff4(b->mUnk_08);
            } else {
                func_ov000_0218e53c(d);
            }
        }
    }
    b = a->mUnk_434;
    while (b != 0) {
        c = b->mNext;
        d = func_ov000_02194160(param_1, b);
        if (b->mUnk_00 == 0x6a || d != 0 || (s32) func_ov000_0218e320(0) > b->mUnk_10) {
            func_ov000_0219405c(param_1, b);
        }
        b = c;
    }
    return 0;
}
