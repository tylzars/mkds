#include "01/code_0218add0.h"
#include "01/code_02185ef4.h"
#include "01/code_02187d14.h"
#include "01/code_02188158.h"
#include "01/code_02188cd8.h"
#include "01/code_02188da4.h"
#include "01/code_0218b298.h"
#include "01/unk_021a6000.h"
#include "01/unk_021a9000.h"
#include "Main/Unknown/code_02073eb8.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020d275c.h"
#include "Main/Unknown/code_020fd264.h"

void func_ov001_0218aef4(Unk02188950 *a) {
    RandomState64 *rng;
    s32 angle;
    s32 i;
    s32 idx;
    Vec3 pos;

    rng = GetMapObjectRandom();
    rng->mValue = (s64) rng->mMultiplier * (s64) rng->mValue + rng->mIncrement;
    angle = (u16) (((rng->mValue >> 32) << 16) >> 32);
    for (i = 0; i < 3; i++) {
        Vec3 vel = {0, 0, 0};
        angle += 0x5555;
        idx = ((u16) angle >> 4) * 2;
        pos.x = a->mUnk_000.mPos.x + (s32) (((s64) a->mPrm->mUnk_1e4 * gPairsByAngle[idx]) >> 12);
        pos.y = a->mUnk_000.mPos.y;
        pos.z = a->mUnk_000.mPos.z + (s32) (((s64) a->mPrm->mUnk_1e4 * gPairsByAngle[idx + 1]) >> 12);
        ThrowItemBombFromPosition(StartItemBomb(), &pos, &vel, a->mPrm->mUnk_1e8);
    }
    {
        Vec3 pos2;
        Vec3 vel2 = {0, 0, 0};
        pos2.x = a->mUnk_000.mPos.x;
        pos2.y = a->mUnk_000.mPos.y;
        pos2.z = a->mUnk_000.mPos.z;
        ThrowItemBombFromPosition(StartItemBombWithParkedItemBox(9), &pos2, &vel2, a->mPrm->mUnk_1ec);
    }
    SetSpeedAndClearTarget(a, 0);
}

void func_ov001_0218ae60(Unk02188950 *a) {
    func_ov001_02187218(a, 3, NULL);
    StartAnimationWithEndCallback(a, a->mPrm->mUnk_200, a->mPrm->mUnk_204, NULL);
    func_ov001_02188c90(a);
    SetSpeedAndClearTarget(a, 0);
    StartEffectAtRowHeight(a, 0, 0, 0, 0x411, 0);
    StartEffectAtRowHeight(a, 0, 0, 0, 0x412, 0);
    StartCameraWobbleAtDistance(a->mUnk_000.mDistanceSquaredAndFlags & 0x3fffffe0, 0x1000);
    a->mUnk_000.mFlags &= ~0x20;
    SetKartCollisionCallback(a, NULL);
}

void func_ov001_0218add0(Unk02188950 *a) {
    Vec3 vec = {0, 0, 0};

    vec.y = a->mPrm->mUnk_1fc;
    func_ov001_02187218(a, 3, NULL);
    StartAnimationNoEndCallback(a, a->mPrm->mUnk_1f4, a->mPrm->mUnk_1f8);
    SetVelocity(a, &vec);
    func_ov001_02188c90(a);
    SetSpeedAndClearTarget(a, 0);
    SetCourseCollisionCallback(a, func_ov001_0218ae60);
    a->mGravityEnabled = TRUE;
    StartMapObjectSound(&a->mUnk_000, 0x23a);
    SetKartCollisionCallback(a, func_ov001_0218b2b8);
}
