#include "00/code_0219f8b0.h"
#include "00/code_021988e8.h"
#include "00/code_0219a000.h"
#include "00/code_0219f000.h"
#include "00/code_0219fb48.h"
#include "00/code_021a01dc.h"
#include "00/code_021a0958.h"
#include "00/code_021a17bc.h"
#include "00/code_021a4818.h"
#include "code_0200f5ac.h"

u32 func_ov000_0219f9bc(u32 a) {
    s32 i;
    u32 b;

    if (data_ov000_021b566c->mUnk_17 != 0 && data_ov000_021b566c->mUnk_20 == data_ov000_021b566c->mUnk_1e8) {
        b = 0;
    } else {
        b = 1;
    }
    if (b != 0) {
        data_ov000_021b566c->mUnk_17 = 0;
        data_ov000_021b566c->mUnk_20 = 0;
        func_ov000_021a4818(data_ov000_021b566c->mUnk_10);
    }
    if (data_ov000_021b566c->mUnk_0d < 0x1f) {
        data_ov000_021b566c->mUnk_f4[data_ov000_021b566c->mUnk_0d + 1] = 0;
    }
    data_ov000_021b566c->mUnk_3b4 = 0xff;
    if (data_ov000_021b566c->mUnk_194 != 0) {
        func_ov000_0219ac50(data_ov000_021b566c->mUnk_194);
        data_ov000_021b566c->mUnk_194 = 0;
    }
    data_ov000_021b566c->mUnk_14 = data_ov000_021b566c->mUnk_0d;
    data_ov000_021b566c->mUnk_1ec = 0;
    if (b == 0) {
        if (data_ov000_021b566c->mUnk_15 != 3) {
            func_ov000_0219f214();
        }
    } else if (data_ov000_021b566c->mUnk_15 == 0) {
        data_ov000_021b566c->mUnk_198 = 3;
        data_ov000_021b566c->mUnk_e8 = 2;
        data_ov000_021b566c->mUnk_ec = func_0200f5ac();
    } else if (data_ov000_021b566c->mUnk_15 == 1) {
        data_ov000_021b566c->mUnk_198 = 4;
        func_ov000_0219fbec(1, 0);
    } else if (data_ov000_021b566c->mUnk_15 == 2) {
        data_ov000_021b566c->mUnk_198 = 14;
        data_ov000_021b566c->mUnk_1cc = 0;
        data_ov000_021b566c->mUnk_1a8 = 0;
        func_ov000_0219f124(a);
        for (i = 1; i <= data_ov000_021b566c->mUnk_0d; i++) {
            if (func_ov000_0219edb0(data_ov000_021b566c->mUnk_f4[i], 0xd) == 0) {
                return 0;
            }
        }
        if (data_ov000_021b566c->mUnk_0d == 0) {
            func_ov000_0219f23c(2);
        }
    }
    return 1;
}

u32 func_ov000_0219f938(u32 a) {
    u32 b;

    b = 1;
    if (data_ov000_021b566c->mUnk_15 == 3) {
        if (data_ov000_021b566c->mUnk_0d != 0) {
            func_ov000_0219f0f4();
        }
        func_ov000_021a1a38(6, -80430);
        return 0;
    }
    data_ov000_021b566c->mUnk_14 = data_ov000_021b566c->mUnk_0d;
    data_ov000_021b566c->mUnk_1f0 = 0;
    if (data_ov000_021b566c->mUnk_194 != 0) {
        func_ov000_0219ac50(data_ov000_021b566c->mUnk_194);
        data_ov000_021b566c->mUnk_194 = 0;
    }
    if (data_ov000_021b566c->mUnk_0d != 0) {
        func_ov000_0219f214();
    } else {
        data_ov000_021b566c->mUnk_198 = 4;
        b = func_ov000_0219fb48();
    }
    return b;
}

u32 func_ov000_0219f8b0(void) {
    s32 i;
    u32 r;

    for (i = 1; i <= data_ov000_021b566c->mUnk_0d; i++) {
        r = func_ov000_021a0ae8(10, data_ov000_021b566c->mUnk_f4[i], data_ov000_021b566c->mUnk_24[i],
                                data_ov000_021b566c->mUnk_a4[i], data_ov000_021b566c->mUnk_330,
                                data_ov000_021b566c->mUnk_330[0] + 1);
        if (r != 0) {
            return r;
        }
    }
    data_ov000_021b566c->mUnk_17 = 0;
    data_ov000_021b566c->mUnk_20 = 0;
    data_ov000_021b566c->mUnk_1a0 = 1;
    func_ov000_021988e8(*data_ov000_021b566c->mUnk_04);
    data_ov000_021b566c->mUnk_1a0 = 0;
    return 0;
}
