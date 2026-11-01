#include "01/code_02191888.h"
#include "01/code_02193000.h"
#include "01/unk_021a9000.h"
#include "Main/Unknown/code_0212a000.h"
#include "Main/Unknown/code_0214a000.h"
#include "Main/Unknown/code_0214d000.h"

void func_ov001_02191adc(Unk02188950 *param_1) {
    Vec3 v = {0, 0, 0};
    func_ov001_02187218(param_1, 3, 0);
    func_ov001_02188d64(param_1, param_1->mUnk_0a0->mUnk_1c0, param_1->mUnk_0a0->mUnk_1c4);
    func_ov001_02188c90(param_1);
    func_ov001_02188cec(param_1, 0);
    func_ov001_02188950(param_1, &v);
    func_ov001_02188e24(param_1, param_1->mUnk_0a0->mUnk_1c8, 0);
}

void func_ov001_02191a3c(Unk02188950 *param_1) {
    Vec3 v = {0, 0, 0};
    v.y = param_1->mUnk_0a0->mUnk_1bc;
    func_ov001_02187218(param_1, 3, 0);
    func_ov001_02188d64(param_1, param_1->mUnk_0a0->mUnk_1a4, param_1->mUnk_0a0->mUnk_1a8);
    func_ov001_02188950(param_1, &v);
    func_ov001_02188b78(param_1, param_1->mUnk_0a0->mUnk_1b4, param_1->mUnk_0a0->mUnk_1b8);
    func_ov001_02188cd8(param_1, param_1->mUnk_0a0->mUnk_1ac, param_1->mUnk_0a0->mUnk_1b0);
    func_ov001_02188db8(param_1, func_ov001_02191adc);
    param_1->mUnk_2c0 = 1;
}

void func_ov001_02191980(Unk02188950 *param_1) {
    Vec3 v = {0, 0, 0};
    func_ov001_02187218(param_1, 3, 0);
    func_ov001_02188d64(param_1, param_1->mUnk_0a0->mUnk_184, param_1->mUnk_0a0->mUnk_188);
    func_ov001_02188b78(param_1, param_1->mUnk_0a0->mUnk_194, param_1->mUnk_0a0->mUnk_198);
    func_ov001_02188cd8(param_1, param_1->mUnk_0a0->mUnk_18c, param_1->mUnk_0a0->mUnk_190);
    func_ov001_02188950(param_1, &v);
    func_ov001_02188de0(param_1, param_1->mUnk_0a0->mUnk_19c, 0, &param_1->mUnk_1ac, func_ov001_02191a3c);
    func_ov001_02188e24(param_1, param_1->mUnk_0a0->mUnk_0ec, func_ov001_02191a3c);
    param_1->mUnk_2c0 = 0;
}

void func_ov001_021918c8(Unk02188950 *param_1) {
    Vec3 v = {0, 0, 0};
    v.y = param_1->mUnk_0a0->mUnk_17c;
    func_ov001_021924cc();
    func_ov001_02187218(param_1, 3, 0);
    func_ov001_02188d64(param_1, param_1->mUnk_0a0->mUnk_164, param_1->mUnk_0a0->mUnk_168);
    func_ov001_02188950(param_1, &v);
    func_ov001_02188b78(param_1, param_1->mUnk_0a0->mUnk_174, param_1->mUnk_0a0->mUnk_178);
    func_ov001_02188998(param_1, &param_1->mUnk_1ac);
    func_ov001_02188cd8(param_1, param_1->mUnk_0a0->mUnk_16c, param_1->mUnk_0a0->mUnk_170);
    func_ov001_02188e24(param_1, param_1->mUnk_0a0->mUnk_180, func_ov001_02191980);
}

int func_ov001_02191888(Unk02188950 *param_1) {
    if (param_1->mUnk_174 > 0) {
        func_020d275c(&param_1->mUnk_000, (u32) (0x219));
    } else {
        func_ov001_02187af4(param_1);
        func_ov001_02188200(param_1, func_ov001_02192878);
        param_1->mUnk_158 = 0;
    }
    return 0;
}
