#include "01/code_0218a3ec.h"
#include "01/code_02185ef4.h"
#include "01/code_02188cd8.h"

void func_ov001_0218a3ec(Unk02188950 *mapObject) {
    func_ov001_02187218(mapObject, 8, (s32(*)(Unk02188950 *))(0));
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_078, mapObject->mPrm->mUnk_07c);
    func_ov001_02188c90(mapObject);
    SetSpeedAndClearTarget(mapObject, 0);
}
