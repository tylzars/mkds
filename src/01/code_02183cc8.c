#include "01/code_02183cc8.h"
#include "01/unk_021a6000.h"

s32 func_ov001_02183d94(Unk02188950 *param_1) {
    func_ov001_02188998(param_1, &func_0207a974((u16) data_021759c0->mUnk_62)->mUnk_80);
    if (param_1->mUnk_174 < param_1->mUnk_0a0->mUnk_108) {
        func_ov001_02188200(param_1, func_ov001_02184874);
        func_ov001_02184e6c(param_1);
    }
    return 0;
}

void func_ov001_02183cc8(Unk02188950 *param_1) {
    Unk0206bcb0 *r4;

    r4 = func_0207a974((u16) data_021759c0->mUnk_62);
    func_ov001_02187218(param_1, 2, func_ov001_02183d94);
    func_ov001_02188d64(param_1, param_1->mUnk_0a0->mUnk_10c, param_1->mUnk_0a0->mUnk_110);
    func_ov001_02188c48(param_1, param_1->mUnk_0a0->mUnk_118, param_1->mUnk_0a0->mUnk_118);
    func_ov001_02188998(param_1, &r4->mUnk_80);
    func_ov001_021889c8(param_1);
    func_ov001_02188cd8(param_1, 0, param_1->mUnk_0a0->mUnk_114);
    func_ov001_02188dcc(param_1, func_ov001_02184cc8);
    func_ov001_02188200(param_1, func_ov001_021843b0);
    if (param_1->mUnk_174 < param_1->mUnk_0a0->mUnk_114) {
        func_ov001_02188200(param_1, func_ov001_02184874);
    }
    func_ov001_02184e18((u16 *) param_1);
}
