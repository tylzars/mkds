#include "01/code_02184274.h"

#include "01/unk_021a6000.h"
#include "Main/Unknown/code_020d3c94.h"

s32 func_ov001_02184274(Unk02188950 *donketu) {
    if (donketu->mUnk_000.mPos.y >= -GetHeightAboveWaterOrEfct(0)) {
        func_ov001_02187444(donketu, 4, 0);
        StartMapObjectSound(&donketu->mUnk_000, 0x241);
        donketu->mUnk_158 = func_ov001_021842b4;
    }
    return 0;
}
