#include "00/code_0219d734.h"
#include "00/code_0218f960.h"
#include "00/code_0219c000.h"
#include "00/code_0219c39c.h"
#include "00/code_0219c384.h"
#include "00/code_0219caac.h"
#include "00/code_0219cfc0.h"
#include "00/code_0219d2c4.h"
#include "00/code_0219d2e8.h"
#include "00/code_0219d478.h"
#include "00/code_0219d49c.h"
#include "00/code_0219746c.h"

void func_ov000_0219d81c(void) {
    if (data_ov000_021b5664 == 0) {
        return;
    }
    if (data_ov000_021b5664->mUnk_18 == 0) {
        return;
    }
    if (func_ov000_0219c39c() != 0) {
        return;
    }
    if (func_ov000_0219caf4() != 0 && func_ov000_0219746c() == 0) {
        func_ov000_0219d734(6, -0x1194a);
        return;
    }
    if (data_ov000_021b5664->mUnk_04 != 0 && data_ov000_021b5664->mUnk_04->mUnk_00 != 0) {
        if (func_ov000_0219d034(func_ov000_0219d49c()) != 0) {
            return;
        }
        if (data_ov000_021b5664->mUnk_18 != 0 && data_ov000_021b5664->mUnk_1e != 3 &&
            data_ov000_021b5664->mUnk_08 > 7) {
            if (data_ov000_021b5664->mUnk_1e <= 1) {
                func_ov000_0219d2e8(data_ov000_021b5664->mUnk_18, data_ov000_021b5664->mUnk_14);
            }
            if (data_ov000_021b5664->mUnk_1c >= data_ov000_021b5664->mUnk_14) {
                data_ov000_021b5664->mUnk_1e = 3;
                data_ov000_021b5664->mUnk_1f++;
            }
        }
    }
    if (data_ov000_021b5664->mUnk_1f >= 2) {
        data_ov000_021b5664->mUnk_1f = 0;
        func_ov000_0219d2c4();
    }
}

void func_ov000_0219d770(s32 a, const u8 *b, void (*c)(s32, u8, void *), void *d, void (*e)(s32, u8, void *, void *),
                         void *f, void (*g)(s32, s32, void *), void *h) {
    s32 i;
    s32 j;
    s32 k;
    s8 l[0x28];
    data_ov000_021b5664->mUnk_2c = c;
    data_ov000_021b5664->mUnk_30 = d;
    data_ov000_021b5664->mUnk_34 = e;
    data_ov000_021b5664->mUnk_38 = f;
    data_ov000_021b5664->mUnk_3c = g;
    data_ov000_021b5664->mUnk_40 = h;
    i = 0;
    data_ov000_021b5664->mUnk_1d = 0;
    data_ov000_021b5664->mUnk_1e = 0;
    data_ov000_021b5664->mUnk_1f = 0;
    data_ov000_021b5664->mUnk_00 = 1;
    if (((s8 *) data_ov000_021b5664->mUnk_28)[i] != 0) {
        j = i;
        for (; i < 5; i++) {
            k = func_ov000_02197690(j);
            if (k == 0) {
                break;
            }
            if (k != 2 || i == 4) {
                func_ov000_0219cfc0(k);
                return;
            }
        }
        func_ov000_02197a9c((const u8 *) func_ov000_021975f4(0), b, l);
        func_ov000_02197594(0, a, (s32) l, func_ov000_0219cc30, 0);
        func_ov000_0219cb30();
    } else {
        data_ov000_021b5664->mUnk_1f++;
    }
}

void func_ov000_0219d734(s32 a, s32 b) {
    if (data_ov000_021b5664 != 0 && a != 0) {
        func_ov000_0219c384(a, b);
        if (data_ov000_021b5664->mUnk_00 != 0 && data_ov000_021b5664->mUnk_00 != 2) {
            data_ov000_021b5664->mUnk_2c(a, data_ov000_021b5664->mUnk_1d, data_ov000_021b5664->mUnk_30);
        }
        func_ov000_0219d478();
    }
}
