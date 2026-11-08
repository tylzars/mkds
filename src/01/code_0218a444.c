#include "01/code_0218a444.h"
#include "01/code_02185ef4.h"
#include "01/code_02188cd8.h"
#include "01/code_02189da4.h"
#include "01/code_0218a568.h"

void func_ov001_0218a52c(Unk02188950 *mapObject) {
    func_ov001_02187218(mapObject, 7, NULL);
    StartAnimationWithEndCallback(mapObject, mapObject->mPrm->mUnk_174, mapObject->mPrm->mUnk_178, NULL);
    SetItemCollisionCallback(mapObject, (UnkFunc *) &func_ov001_02189ed8);
}

void func_ov001_0218a4d0(Unk02188950 *mapObject) {
    func_ov001_02187218(mapObject, 7, &func_ov001_0218a568);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_164, mapObject->mPrm->mUnk_168);
    SetStoppedCallback(mapObject, &func_ov001_0218a52c);
    SetSpeedAndClearTarget(mapObject, 0);
    mapObject->mBounceEnabled = TRUE;
    SetItemCollisionCallback(mapObject, (UnkFunc *) &func_ov001_02189fe0);
}

void func_ov001_0218a4a0(Unk02188950 *mapObject) {
    func_ov001_02187218(mapObject, 7, NULL);
    StartAnimationWithEndCallback(mapObject, mapObject->mPrm->mUnk_070, mapObject->mPrm->mUnk_074, NULL);
    SetItemCollisionCallback(mapObject, (UnkFunc *) &func_ov001_02189ed8);
}

void func_ov001_0218a444(Unk02188950 *mapObject) {
    func_ov001_02187218(mapObject, 7, &func_ov001_0218a568);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_164, mapObject->mPrm->mUnk_168);
    SetStoppedCallback(mapObject, &func_ov001_0218a4a0);
    SetSpeedAndClearTarget(mapObject, 0);
    mapObject->mBounceEnabled = TRUE;
    SetItemCollisionCallback(mapObject, (UnkFunc *) &func_ov001_02189fe0);
}
