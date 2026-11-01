#include "00/code_021aefc0.h"
#include "00/code_021a9228.h"
#include "00/code_021ae0c4.h"
#include "00/code_021ae314.h"
#include "00/code_021af550.h"
#include "00/code_021b0014.h"
#include "00/code_021ae958.h"
#include "00/code_021af284.h"
#include "00/code_021af2a0.h"
#include "code_02133048.h"
#include "code_0200dc3c.h"
#include "Main/Unknown/unk_0216f000.h"

void func_ov000_021af1e4(Unk021ae3f0 *param_1, Unk021af1e4 *param_2, u32 param_3) {
    if (func_ov000_021b0188(param_2, param_3) == 0xffff) {
        if (func_ov000_021af284((u32) (((u16) ((param_1->mUnk_0c >> 8) | (param_1->mUnk_0c << 8)) << 16) |
                                       (u16) ((param_1->mUnk_0e >> 8) | (param_1->mUnk_0e << 8))),
                                (u32) (((u16) ((param_1->mUnk_10 >> 8) | (param_1->mUnk_10 << 8)) << 16) |
                                       (u16) ((param_1->mUnk_12 >> 8) | (param_1->mUnk_12 << 8)))) != 0) {
            switch (param_2->mUnk_00) {
                case 0:
                    func_ov000_021af2a0(param_1, param_2, param_3);
                    break;
                case 8:
                    if (data_ov000_021b4c24 != 0) {
                        func_ov000_021af348(param_1, param_2, param_3);
                    }
                    break;
            }
        }
    }
}

Unk021a998c *func_ov000_021af15c(const Unk021ae3f0 *param_1, const Unk021ae87c *param_2) {
    Unk021a998c *b;
    Unk0200db5c *a;

    for (a = data_0216ff5c.mUnk_08; a != 0; a = a->mUnk_68) {
        b = *(Unk021a998c **) a->mUnk_a4;
        if (b == 0 || b->mUnk_00 == 0 || b->mUnk_08 != 1 ||
            b->mUnk_0a != (u16) ((param_2->mUnk_02 >> 8) | (param_2->mUnk_02 << 8))) {
            continue;
        }
        if (b->mUnk_18 != 0 && b->mUnk_18 != (u16) ((param_2->mUnk_00 >> 8) | (param_2->mUnk_00 << 8))) {
            continue;
        }
        if (b->mUnk_1c != 0 && b->mUnk_1c != (u32) (((u16) ((param_1->mUnk_0c >> 8) | (param_1->mUnk_0c << 8)) << 16) |
                                                    (u16) ((param_1->mUnk_0e >> 8) | (param_1->mUnk_0e << 8)))) {
            continue;
        }
        return b;
    }
    return 0;
}

u32 func_ov000_021af0dc(const Unk021ae3f0 *param_1, const Unk021ae87c *param_2, const Unk021a998c *param_3) {
    u32 a = 0;
    u32 c = 0;
    u32 b = 0;
    u32 d = 0;

    if (param_3->mUnk_08 != 0xa && param_3->mUnk_08 != 0xb) {
        d = 1;
    }
    if (d != 0) {
        if (param_3->mUnk_0a == (u16) ((param_2->mUnk_02 >> 8) | (param_2->mUnk_02 << 8))) {
            b = 1;
        }
    }
    if (b != 0) {
        if (param_3->mUnk_18 == (u16) ((param_2->mUnk_00 >> 8) | (param_2->mUnk_00 << 8))) {
            c = 1;
        }
    }
    if (c != 0) {
        if (param_3->mUnk_1c == (u32) (((u16) ((param_1->mUnk_0c >> 8) | (param_1->mUnk_0c << 8)) << 16) |
                                       (u16) ((param_1->mUnk_0e >> 8) | (param_1->mUnk_0e << 8)))) {
            a = 1;
        }
    }
    return a;
}

Unk021a998c *func_ov000_021af090(const Unk021ae3f0 *param_1, const Unk021ae87c *param_2) {
    Unk021a998c *b;
    Unk0200db5c *a;

    a = data_0216ff5c.mUnk_08;
    while (a != 0) {
        b = *(Unk021a998c **) a->mUnk_a4;
        if (b != 0 && b->mUnk_00 != 0 && func_ov000_021af0dc(param_1, param_2, b) != 0) {
            return b;
        }
        a = a->mUnk_68;
    }
    return 0;
}

void func_ov000_021af030(const Unk021ae87c *param_1, Unk021a998c *param_2) {
    const u8 *a;
    s32 b;
    s32 c;
    s32 e;
    u8 d;

    param_2->mUnk_2e = 0x218;
    b = (param_1->mUnk_0c & 0xf0) / 4 - 0x14;
    a = (const u8 *) param_1 + 0x14;
    c = b - 1;
    if (b != 0) {
        do {
            d = *a++;
            if (d == 0) {
                break;
            }
            if (d != 1) {
                if (d == 2) {
                    param_2->mUnk_2e = (a[1] << 8) | a[2];
                    a += 3;
                    c -= 3;
                } else {
                    e = a[0] - 1;
                    c -= e;
                    a += e;
                }
            }
        } while (c-- != 0);
    }
}

u32 func_ov000_021af010(u32 param_1) {
    u32 a;

    a = func_ov000_021b00e0(param_1);
    if (a == 0) {
        return 1;
    }
    return (u32) func_ov000_021afd00(a);
}

void func_ov000_021aefc0(Unk021a998c *param_1, u32 param_2, u16 param_3) {
    if (func_ov000_021af010(param_1->mUnk_1c) != 0 || data_0216ff5c.mUnk_04 != &data_ov000_021b661c) {
        func_ov000_021af550(0, 0, param_1, param_2, param_3);
    } else {
        func_ov000_021afc5c(func_ov000_021b00e0(param_1->mUnk_1c));
    }
}
