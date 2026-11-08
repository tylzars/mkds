#include "01/code_0218ac04.h"
#include "01/code_02187eb0.h"
#include "01/code_02188cd8.h"
#include "01/code_02187000.h"
#include "01/code_02185ef4.h"
#include "01/code_02187e78.h"
#include "01/code_02188000.h"
#include "01/code_02188da4.h"
#include "01/code_02188e24.h"
#include "01/code_0218ad68.h"
#include "Main/Unknown/code_020d2000.h"
#include "01/code_0218a000.h"
#include "01/code_0218add0.h"
#include "01/unk_021a6000.h"
#include "01/unk_021a7000.h"
#include "Main/Unknown/code_020fd000.h"

void func_ov001_0218acb4(Unk02188950 *mapObject) {
    Vec3 velocity = {0, 0, 0};

    IncrementEntryIndex(mapObject);
    func_ov001_02187218(mapObject, 3, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_1c0, mapObject->mPrm->mUnk_1c4);
    func_ov001_02188c48(mapObject, mapObject->mPrm->mUnk_1d0, mapObject->mPrm->mUnk_1d4);
    SetAnglePointAndMoveAnglePoint(mapObject, &GetCurrentGroupEntry(mapObject)->mPos);
    SetSpeedTargetAndPerCall(mapObject, mapObject->mPrm->mUnk_1c8, mapObject->mPrm->mUnk_1cc);
    SetVelocity(mapObject, &velocity);
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->mUnk_1d8, func_ov001_0218ad68);
    mapObject->mGravityEnabled = FALSE;
}

void func_ov001_0218ac04(Unk02188950 *mapObject) {
    Vec3 velocity = {0, 0, 0};

    velocity.y = mapObject->mPrm->mUnk_1b8;
    func_ov001_02187218(mapObject, 3, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_1a8, mapObject->mPrm->mUnk_1ac);
    SetVelocity(mapObject, &velocity);
    SetSpeedTargetAndPerCall(mapObject, mapObject->mPrm->mUnk_1b0, mapObject->mPrm->mUnk_1b4);
    SetCourseCollisionCallback(mapObject, func_ov001_0218ae60);
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->mUnk_1bc, func_ov001_0218acb4);
    StartMapObjectSound(&mapObject->mUnk_000, 0x239);
    mapObject->mUnk_000.mFlags |= data_ov001_021a6594;
}
