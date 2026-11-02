#include "01/code_02184274.h"

#include "01/unk_021a6000.h"

s32 func_ov001_02184274(Unk02188950 *param_1) {
    if (param_1->mUnk_000.mUnk_04.y >= -func_020d3d48(0)) {
        func_ov001_02187444(param_1, 4, 0);
        func_020d2774(&param_1->mUnk_000, (u32) (0x241));
        param_1->mUnk_158 = (s32(*)(Unk02188950 *)) func_ov001_021842b4;
    }
    return 0;
}
