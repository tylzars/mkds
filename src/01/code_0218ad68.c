#include "01/code_0218ad68.h"
#include "01/code_02185ef4.h"
#include "01/code_02188cd8.h"
#include "01/code_0218add0.h"

void func_ov001_0218ad68(Unk02188950 *mapObject) {
    func_ov001_0218aef4(mapObject);
    func_ov001_02187218(mapObject, 3, (s32(*)(Unk02188950 *))(0));
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_1dc, mapObject->mPrm->mUnk_1e0);
    func_ov001_02188c90(mapObject);
    SetSpeedAndClearTarget(mapObject, 0);
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->mUnk_1f0, &func_ov001_0218add0);
    mapObject->mGravityEnabled = FALSE;
}
