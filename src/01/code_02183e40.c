#include "01/code_02183e40.h"
#include "01/unk_021a6000.h"

void func_ov001_02183e40(Unk02188950 *param_1) {
    Vec3 sp = {0, 0, 0};

    sp.y = param_1->mUnk_0a0->mUnk_154;
    func_ov001_02187218(param_1, 5, (s32(*)(Unk02188950 *)) func_ov001_02183ebc);
    func_ov001_02188d64(param_1, param_1->mUnk_0a0->mUnk_14c, param_1->mUnk_0a0->mUnk_150);
    func_ov001_02188a8c(param_1, param_1->mUnk_0a0->mUnk_158, param_1->mUnk_0a0->mUnk_158);
    func_ov001_02188950(param_1, &sp);
    func_ov001_02188db8(param_1, func_ov001_02183ed4);
}
