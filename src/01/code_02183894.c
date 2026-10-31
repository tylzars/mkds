#include "01/code_02183894.h"
#include "01/unk_021a6000.h"

void func_ov001_02183ad8(Unk02188950 *param_1) {
    Unk0206bcb0 *r4;

    r4 = func_0207a974((u16)data_021759c0->mUnk_62);
    func_ov001_02187218(param_1, 3, 0);
    func_ov001_02188d64(param_1, param_1->mUnk_0a0->mUnk_0cc, param_1->mUnk_0a0->mUnk_0d0);
    func_ov001_02188c48(param_1, param_1->mUnk_0a0->mUnk_0d8, param_1->mUnk_0a0->mUnk_0d8);
    func_ov001_02188998(param_1, &r4->mUnk_80);
    func_ov001_02188cec(param_1, param_1->mUnk_0a0->mUnk_0d4);
    func_ov001_02188de0(param_1, 0, param_1->mUnk_0a0->mUnk_0e4, &r4->mUnk_80, func_ov001_02183c08);
    if (param_1->mUnk_000.mUnk_00 == 0x1f5) {
        func_020d2774(&param_1->mUnk_000, (u32) (0x214));
    } else if (param_1->mUnk_000.mUnk_00 == 0x1f6) {
        func_020d2774(&param_1->mUnk_000, (u32) (0x245));
    }
    func_ov001_02184e6c(param_1);
}

void func_ov001_021839ac(Unk02188950 *param_1) {
    if (func_ov001_021881a8(param_1, (Vec3 *) param_1->mUnk_000.mUnk_9c,
                            (s32) (param_1->mUnk_0a0->mUnk_180 + 0x28), 0)) {
        func_ov001_02187218(param_1, 3, 0);
        func_ov001_02188d64(param_1, param_1->mUnk_0a0->mUnk_168, param_1->mUnk_0a0->mUnk_16c);
        func_ov001_02188c48(param_1, param_1->mUnk_0a0->mUnk_178, 0x270f000);
        func_ov001_02188998(param_1, &param_1->mUnk_000.mUnk_9c->mUnk_00);
        func_ov001_02188cd8(param_1, param_1->mUnk_0a0->mUnk_174, param_1->mUnk_0a0->mUnk_170);
        func_ov001_02188e24(param_1, param_1->mUnk_0a0->mUnk_17c, 0);
        func_ov001_02188200(param_1, func_ov001_02184874);
    } else {
        func_ov001_02187218(param_1, 3, 0);
        func_ov001_02188d64(param_1, param_1->mUnk_0a0->mUnk_168, param_1->mUnk_0a0->mUnk_16c << 2);
        func_ov001_02188c48(param_1, param_1->mUnk_0a0->mUnk_178, 0x270f000);
        func_ov001_02188998(param_1, &param_1->mUnk_000.mUnk_9c->mUnk_00);
        func_ov001_02188cd8(param_1, -param_1->mUnk_0a0->mUnk_174, param_1->mUnk_0a0->mUnk_170);
        func_ov001_02188e24(param_1, param_1->mUnk_0a0->mUnk_17c, 0);
        func_ov001_02188200(param_1, func_ov001_02184874);
    }
    func_ov001_02184e6c(param_1);
}

void func_ov001_02183894(Unk02188950 *param_1) {
    Unk02188950_a0 *a0;

    a0 = param_1->mUnk_0a0;
    if (func_ov001_021881a8(param_1, (Vec3 *) func_ov001_02187fc0(param_1), (s32) (a0->mUnk_0ac), (s32) (a0->mUnk_0b0))) {
        func_ov001_02187218(param_1, 1, 0);
        func_ov001_02188d64(param_1, param_1->mUnk_0a0->mUnk_0b8, param_1->mUnk_0a0->mUnk_0bc);
        func_ov001_02188b2c(param_1, param_1->mUnk_0a0->mUnk_0c4, param_1->mUnk_0a0->mUnk_0c4, 0);
        func_ov001_02188998(param_1, &func_ov001_02187fc0(param_1)->mUnk_00);
        func_ov001_02188cd8(param_1, param_1->mUnk_0a0->mUnk_0c0, param_1->mUnk_0a0->mUnk_0c0);
        func_ov001_02188e24(param_1, param_1->mUnk_0a0->mUnk_0c8, 0);
    } else {
        func_ov001_02187e78(param_1);
        func_ov001_02187218(param_1, 1, 0);
        func_ov001_02188d64(param_1, param_1->mUnk_0a0->mUnk_09c, param_1->mUnk_0a0->mUnk_0a0);
        func_ov001_02188c48(param_1, param_1->mUnk_0a0->mUnk_0a8, param_1->mUnk_0a0->mUnk_0a8);
        func_ov001_02188998(param_1, &func_ov001_02187fc0(param_1)->mUnk_00);
        func_ov001_02188cd8(param_1, param_1->mUnk_0a0->mUnk_0a4, param_1->mUnk_0a0->mUnk_0a4);
        a0 = param_1->mUnk_0a0;
        func_ov001_02188de0(param_1, a0->mUnk_0ac, a0->mUnk_0b0, &func_ov001_02187fc0(param_1)->mUnk_00, 0);
    }
    func_ov001_02184e6c(param_1);
}
