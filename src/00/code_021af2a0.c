#include "00/code_021af2a0.h"
#include "00/code_021a9228.h"
#include "00/code_021ae0c4.h"
#include "00/code_021ae314.h"
#include "00/code_021af550.h"
#include "00/code_021afe84.h"
#include "00/code_021b0014.h"
#include "00/unk_021b6000.h"
#include "code_0200dc3c.h"
#include "code_0214d018.h"
#include "Main/Unknown/unk_0216f000.h"

void func_ov000_021af2a0(Unk021ae3f0 *param_1, Unk021af1e4 *param_2, u32 param_3) {
    Unk0200db5c *a;
    Unk021a998c *b;

    for (a = data_0216ff5c.mUnk_08; a != 0; a = a->mUnk_68) {
        b = *(Unk021a998c **) a->mUnk_a4;
        if (b == 0 || b->mUnk_00 == 0 || b->mUnk_08 != 0xb || (u16) (u32) b->mUnk_00 != param_2->mUnk_04) {
            continue;
        }
        if (b->mUnk_0a != param_2->mUnk_06 || b->mUnk_44 != 0) {
            continue;
        }
        if (b->mUnk_1c != (u32) (((u16) ((param_1->mUnk_0c >> 8) | (param_1->mUnk_0c << 8)) << 16) |
                                 (u16) ((param_1->mUnk_0e >> 8) | (param_1->mUnk_0e << 8)))) {
            continue;
        }
        param_3 -= 8;
        if (param_3 > b->mUnk_3c) {
            b->mUnk_44 = b->mUnk_3c;
        } else {
            b->mUnk_44 = param_3;
        }
        func_0214d1fc((u8 *) param_2 + 8, b->mUnk_40, b->mUnk_44);
        if (b->mUnk_04 == 3) {
            b->mUnk_04 = 0;
            func_0200df68(b->mUnk_00);
            return;
        }
        return;
    }
}

void func_ov000_021af348(Unk021ae3f0 *param_1, Unk021af1e4 *param_2, u32 param_3) {
    u32 a;
    u32 b;
    u16 c;

    a = (u32) (((u16) ((param_1->mUnk_0c >> 8) | (param_1->mUnk_0c << 8)) << 16) |
               (u16) ((param_1->mUnk_0e >> 8) | (param_1->mUnk_0e << 8)));
    if (func_ov000_021b0094(a) != 0) {
        return;
    }
    b = func_ov000_021b00e0(a);
    if (b == 0) {
        return;
    }
    if (func_ov000_021afd00(b) == 0) {
        func_ov000_021afc5c(b);
        return;
    }
    param_2->mUnk_00 = 0;
    param_2->mUnk_02 = 0;
    c = func_ov000_021b0188(param_2, param_3);
    param_2->mUnk_02 = (u16) ((c >> 8) | (c << 8));
    func_ov000_021af858((u8 *) param_2, param_3, 0, 0,
                        (u32) (((u16) ((param_1->mUnk_0c >> 8) | (param_1->mUnk_0c << 8)) << 16) |
                               (u16) ((param_1->mUnk_0e >> 8) | (param_1->mUnk_0e << 8))),
                        1);
}

void func_ov000_021af3e8(Unk021af3e8 *param_1, u32 param_2) {
    u32 a;
    u32 b;
    u32 c;
    u32 d;
    u32 e;

    if (param_2 < 0x1c) {
        return;
    }
    if (func_ov000_021b0014(param_1->mUnk_08, data_ov000_021b63d0) == 0) {
        return;
    }
    if (data_ov000_021b63b4 == 0) {
        return;
    }
    if (param_1->mUnk_00 != 0x100) {
        return;
    }
    if (param_1->mUnk_02 != 8) {
        return;
    }
    if (param_1->mUnk_04 != 0x406) {
        return;
    }
    a = (u16) ((param_1->mUnk_06 >> 8) | (param_1->mUnk_06 << 8));
    if (a != 1 && a != 2) {
        return;
    }
    e = (u32) (((u16) ((param_1->mUnk_0e >> 8) | (param_1->mUnk_0e << 8)) << 16) |
               (u16) ((param_1->mUnk_10 >> 8) | (param_1->mUnk_10 << 8)));
    d = data_ov000_021b63b4;
    if (e == d) {
        b = 1;
    } else {
        b = 0;
    }
    if (d == (u32) (((u16) ((param_1->mUnk_18 >> 8) | (param_1->mUnk_18 << 8)) << 16) |
                    (u16) ((param_1->mUnk_1a >> 8) | (param_1->mUnk_1a << 8)))) {
        c = 1;
    } else {
        c = 0;
    }
    if (b == 0) {
        func_ov000_021afb58((u8 *) param_1->mUnk_08, e, c);
    }
    if (a == 1 && c != 0) {
        func_ov000_021af4d4(param_1);
        return;
    }
    if (a == 2 && c != 0 && b != 0) {
        data_ov000_021b6368 = 1;
    }
}

void func_ov000_021af4d4(Unk021af3e8 *param_1) {
    param_1->mUnk_06 = 0x200;
    func_0214d1fc(param_1->mUnk_08, param_1->mUnk_12, 10);
    func_0214d1fc(data_ov000_021b63d0, param_1->mUnk_08, 6);
    param_1->mUnk_0e = (u16) (((u16) (data_ov000_021b63b4 >> 16) >> 8) | ((u16) (data_ov000_021b63b4 >> 16) << 8));
    param_1->mUnk_10 = (u16) (((u16) data_ov000_021b63b4 >> 8) | ((u16) data_ov000_021b63b4 << 8));
    func_0214d1fc(param_1->mUnk_12, (u8 *) param_1 - 0xe, 6);
    func_0214d1fc(data_ov000_021b63d0, (u8 *) param_1 - 8, 6);
    func_ov000_021affcc((u8 *) param_1 - 0xe, 0x2a, 0, 0);
}
