#include "01/code_021841e0.h"
#include "01/unk_021a6000.h"

s32 func_ov001_02184274(Unk02188950 *param_1) {
    if (param_1->mUnk_000.mUnk_04.y >= -func_020d3d48(0)) {
        func_ov001_02187444(param_1, 4, 0);
        func_020d2774(&param_1->mUnk_000, (u32) (0x241));
        param_1->mUnk_158 = (s32(*)(Unk02188950 *)) func_ov001_021842b4;
    }
    return 0;
}

void func_ov001_021841e0(Unk02188950 *param_1) {
    Vec3 sp = {0, 0, 0};

    sp.y = param_1->mUnk_0a0->mUnk_238;
    func_ov001_02187218(param_1, 8, func_ov001_02184274);
    func_ov001_02188d64(param_1, param_1->mUnk_0a0->mUnk_224, param_1->mUnk_0a0->mUnk_228);
    func_ov001_02188950(param_1, &sp);
    func_ov001_02188c90(param_1);
    func_ov001_02188cd8(param_1, param_1->mUnk_0a0->mUnk_230, param_1->mUnk_0a0->mUnk_234);
    func_ov001_02188db8(param_1, func_ov001_021842ec);
    param_1->mUnk_000.mUnk_02 |= data_ov001_021a6578;
}
