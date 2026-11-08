#include "01/code_021842ec.h"
#include "01/unk_021a6000.h"

void func_ov001_021842ec(Unk02188950 *donketu) {
    func_ov001_02187218(donketu, 7, NULL);
    func_ov001_02188d30(donketu, donketu->mPrm->mUnk_23c, donketu->mPrm->mUnk_240, NULL);
    func_ov001_02188c90(donketu);
    func_ov001_02188cec(donketu, 0);
    StartEffectAtRowHeight(donketu, 0, 0, 0, 0x411, 0);
    StartEffectAtRowHeight(donketu, 0, 0, 0, 0x412, 0);
    StartMapObjectSound(&donketu->mUnk_000, 0x242);
    StartCameraWobbleAtDistance(donketu->mUnk_000.mDistanceSquaredAndFlags & 0x3fffffe0, 0x1000);
    func_ov001_02188200(donketu, func_ov001_02184874);
    donketu->mUnk_000.mFlags &= ~0x20;
}
