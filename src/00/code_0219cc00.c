#include "00/code_0219cc00.h"
#include "00/code_02197000.h"
#include "00/code_0219c000.h"
#include "00/code_0219d000.h"
#include "00/unk_021b5000.h"
#include "00/code_0219d128.h"
#include "00/code_0219c93c.h"
#include "00/code_0219d934.h"

#include "00/code_0219c954.h"
#include "00/code_0219cb00.h"
#include "00/code_021947e4.h"
#include "00/code_02196000.h"
#include "00/code_021a3000.h"
#include "00/unk_021b2000.h"
#include "00/code_0218eb9c.h"
#include "00/unk_021b4000.h"
#include "code_0200d118.h"
#include "code_02139f70.h"
#include "Main/Unknown/code_02152000.h"
#include "code_02152500.h"
#include "code_02152934.h"
#include "code_021522a0.h"
#include "Main/Unknown/code_02152468.h"
#include "Main/Unknown/code_02152a1c.h"

void func_ov000_0219ce48(Unk0218f960 *a, Unk0219c400 *b, u32 c) {
    s32 i;
    s32 k;
    s32 n;
    if (b->mUnk_00 == 0 && b->mUnk_04 != 0 && func_02152a1c(&data_ov000_021b5664->mUnk_18[c]) != 0) {
        if (data_ov000_021b5664->mUnk_00 == 1) {
            data_ov000_021b5664->mUnk_1d = 1;
            for (i = 0; i < b->mUnk_04; i++) {
                if (func_ov000_0219d210(data_ov000_021b5664->mUnk_18, c, b->mUnk_0c[i].mUnk_00) != 0) {
                    data_ov000_021b5664->mUnk_1c++;
                    data_ov000_021b5664->mUnk_1e = 1;
                    b->mUnk_08 = 0x601;
                    return;
                }
            }
            k = 0;
            for (i = 0; i < b->mUnk_04; i++) {
                func_ov000_0219d034(func_ov000_0218ebe8(a, b->mUnk_0c[i].mUnk_00, &n));
                if (n == ~k) {
                    func_ov000_0219d128(b->mUnk_0c[i].mUnk_00);
                } else {
                    func_02152468(&data_ov000_021b5664->mUnk_18[c], b->mUnk_0c[0].mUnk_00);
                    func_021529bc(&data_ov000_021b5664->mUnk_18[c]);
                    func_ov000_0219d504(c);
                    data_ov000_021b5664->mUnk_1c++;
                    data_ov000_021b5664->mUnk_1e = 1;
                    b->mUnk_08 = 0x601;
                    return;
                }
            }
            if (b->mUnk_08 != 0x600) {
                data_ov000_021b5664->mUnk_1c++;
                data_ov000_021b5664->mUnk_1e = 1;
            }
        }
    } else {
        if (b->mUnk_00 != 0) {
            if (func_ov000_0219d034(b->mUnk_00) != 0) {
                return;
            }
        } else if (data_ov000_021b5664->mUnk_00 == 1 || func_02152a1c(&data_ov000_021b5664->mUnk_18[c]) == 0) {
            data_ov000_021b5664->mUnk_1c++;
            data_ov000_021b5664->mUnk_1e = 1;
        }
    }
}

void func_ov000_0219cd74(Unk0218f960 *a, Unk0219c400 *b, u32 c) {
    Unk0218f960 *h = a;
    s32 i;
    s32 f;
    u8 s[0x18];
    u32 t;
    f = 0;
    i = 0;
    for (; i < data_ov000_021b5664->mUnk_14; i++) {
        if (func_02152a1c(&data_ov000_021b5664->mUnk_18[i]) == 1) {
            func_02152458(func_ov000_0219c9c4(), &data_ov000_021b5664->mUnk_18[i], s);
            if (func_0213a074(s, (const u8 *) b->mUnk_8e) == 0) {
                func_ov000_0218ee1c(h, b->mUnk_04);
                func_02152468(&data_ov000_021b5664->mUnk_18[i], b->mUnk_04);
                f = 1;
            }
        } else if (func_02152a1c(&data_ov000_021b5664->mUnk_18[i]) == 3 ||
                   func_02152a1c(&data_ov000_021b5664->mUnk_18[i]) == 2) {
            t = b->mUnk_04;
            if (t == func_02152520(func_ov000_0219c9c4(), &data_ov000_021b5664->mUnk_18[i])) {
                func_ov000_0218ee1c(h, t);
                f = 1;
            }
        }
    }
    if (f != 0) {
        func_ov000_0219d128(b->mUnk_04);
    } else {
        func_ov000_0218ed74(h, b->mUnk_04);
    }
}

void func_ov000_0219cc94(Unk0218f960 *a, Unk0219c400 *b, u32 c) {
    s32 i;
    s32 f;
    u8 s[0x1c];
    u32 t;
    f = 0;
    i = 0;
    for (; i < data_ov000_021b5664->mUnk_14; i++) {
        if (func_02152a1c(&data_ov000_021b5664->mUnk_18[i]) == 1) {
            func_02152458(func_ov000_0219c9c4(), &data_ov000_021b5664->mUnk_18[i], s);
            if (func_0213a074(s, (const u8 *) b->mUnk_8e) == 0) {
                func_02152468(&data_ov000_021b5664->mUnk_18[i], b->mUnk_04);
                func_021529bc(&data_ov000_021b5664->mUnk_18[i]);
                f = 1;
            }
        } else if (func_02152a1c(&data_ov000_021b5664->mUnk_18[i]) == 3 ||
                   func_02152a1c(&data_ov000_021b5664->mUnk_18[i]) == 2) {
            t = b->mUnk_04;
            if (t == func_02152520(func_ov000_0219c9c4(), &data_ov000_021b5664->mUnk_18[i])) {
                func_02152468(&data_ov000_021b5664->mUnk_18[i], t);
                func_021529bc(&data_ov000_021b5664->mUnk_18[i]);
                f = 1;
            }
        }
    }
    if (f != 0) {
        func_ov000_0219d504(
            func_ov000_0219d14c(data_ov000_021b5664->mUnk_18, data_ov000_021b5664->mUnk_14, b->mUnk_04));
        data_ov000_021b5664->mUnk_1d = 1;
    }
}

void func_ov000_0219cc30(u32 a, u32 b, u32 c) {
    char s[0x40];
    func_ov000_0219cb00();
    if (c == 0 || a != 0) {
        func_ov000_0219d734(6, -72200);
        return;
    }
    data_ov000_021b5664->mUnk_24 = b;
    func_0200d9e0(s, 0x40, data_ov000_021b4068, data_ov000_021b5664->mUnk_28);
    func_ov000_0219cc00(data_ov000_021b5664->mUnk_24, 3, (u32) s, 0x80000001);
}

void func_ov000_0219cc00(u32 param_1, u32 param_2, u32 param_3, u32 param_4) {
    func_ov000_0219cb30();
    func_ov000_02197558((u32) (0), (u32) (param_1), (u32) (param_2), (u32) (0), (u32) (param_3),
                        (u32) &func_ov000_0219cb64, (u32) (param_4));
    return;
}
