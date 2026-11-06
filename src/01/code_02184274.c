#include "01/code_02184274.h"

#include "01/unk_021a6000.h"
#include "Main/Unknown/code_020d3c94.h"

s32 func_ov001_02184274(Unk02188950 *a) {
    if (a->mUnk_000.mPos.y >= -GetHeightAboveWaterOrEfct(0)) {
        func_ov001_02187444(a, 4, 0);
        StartMapObjectSound(&a->mUnk_000, 0x241);
        a->mUnk_158 = func_ov001_021842b4;
    }
    return 0;
}
