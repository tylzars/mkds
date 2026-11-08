#include "01/code_0218b034.h"
#include "01/code_02185ef4.h"
#include "01/code_02187bfc.h"
#include "01/code_02187c4c.h"
#include "01/code_02187d14.h"
#include "01/code_02188218.h"
#include "01/unk_021a6000.h"
#include "01/unk_021a9000.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020d275c.h"
#include "Main/Unknown/code_020fd264.h"

void ThrowStoredItemBomb(Unk02188950 *mapObject) {
    Vec3 velocity;

    if (IsItemBombStored(mapObject)) {
        velocity.x = (((s64) mapObject->mPrm->mUnk_134 * gPairsByAngle[((u16) mapObject->mMoveAngle >> 4) * 2]) >> 12);
        velocity.y = mapObject->mPrm->mUnk_138;
        velocity.z =
            (((s64) mapObject->mPrm->mUnk_134 * gPairsByAngle[((u16) mapObject->mMoveAngle >> 4) * 2 + 1]) >> 12);
        func_ov001_02187bfc(mapObject, &velocity, mapObject->mPrm->mUnk_13c);
    }
}

void func_ov001_0218b034(Unk02188950 *mapObject) {
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
        if (func_ov001_02188220(mapObject) == 0) {
            idx = ((u16) angle >> 4) * 2;
            pos.x = mapObject->mUnk_000.mPos.x + (s32) (((s64) mapObject->mPrm->mUnk_14c * gPairsByAngle[idx]) >> 12);
            pos.y = mapObject->mUnk_000.mPos.y + mapObject->mPrm->mUnk_150;
            pos.z =
                mapObject->mUnk_000.mPos.z + (s32) (((s64) mapObject->mPrm->mUnk_14c * gPairsByAngle[idx + 1]) >> 12);
        } else {
            idx = ((u16) angle >> 4) * 2;
            pos.x = mapObject->mUnk_000.mPos.x + (s32) (((s64) mapObject->mPrm->mUnk_154 * gPairsByAngle[idx]) >> 12);
            pos.y = mapObject->mUnk_000.mPos.y + mapObject->mPrm->mUnk_158;
            pos.z =
                mapObject->mUnk_000.mPos.z + (s32) (((s64) mapObject->mPrm->mUnk_154 * gPairsByAngle[idx + 1]) >> 12);
        }
        if (i == 0) {
            ThrowItemBombFromPosition(StartItemBomb(), &pos, &vel, mapObject->mPrm->mUnk_15c);
        } else {
            ThrowItemBombFromPosition(StartItemBombWithParkedItemBox(9), &pos, &vel, mapObject->mPrm->mUnk_160);
        }
    }
    StartEffectAtRowHeight(mapObject, 0x2000, 0, 0x3ae, 0x410, 0);
    StartMapObjectSound(&mapObject->mUnk_000, 0x236);
}
