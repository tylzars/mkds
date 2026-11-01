#include "01/code_021910fc.h"

void func_ov001_0219116c(Unk02188950 *param_1) {
    func_ov001_02187218(param_1, 7, (s32(*)(Unk02188950 *))(0));
    func_ov001_02188d30(param_1, (s32) (param_1->mUnk_0a0->mUnk_234), (s32) (param_1->mUnk_0a0->mUnk_238),
                        (UnkFunc *) &func_ov001_021918c8);
    func_ov001_021922e0(param_1);
}

void func_ov001_02191130(Unk02188950 *param_1) {
    func_ov001_02187218(param_1, 7, (s32(*)(Unk02188950 *))(0));
    func_ov001_02188d30(param_1, (s32) (param_1->mUnk_0a0->mUnk_22c), (s32) (param_1->mUnk_0a0->mUnk_230),
                        (UnkFunc *) &func_ov001_0219116c);
    func_ov001_021921e4(param_1);
}

s32 func_ov001_021910fc(Unk02188950 *param_1) {
    if ((param_1->mUnk_2c8 & 0x001e34ef) != 0) {
        func_020d2774(&param_1->mUnk_000, (u32) 0x218);
        param_1->mUnk_158 = 0;
    }
    return 0;
}
