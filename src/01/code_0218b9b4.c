#include "01/code_0218b9b4.h"
#include "01/code_02188230.h"
#include "01/code_02188cd8.h"

#include "01/code_0218b298.h"
#include "01/code_0218b2dc.h"
#include "01/unk_021a6000.h"
#include "01/code_02188000.h"
#include "01/code_0218c000.h"
#include "Main/Unknown/code_0209b634.h"
#include "Main/Unknown/code_020d4000.h"
#include "01/code_02185ef4.h"
#include "01/code_02187d14.h"
#include "Main/Unknown/code_020f4000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "01/code_02188158.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02073000.h"
#include "Main/Unknown/code_020ac000.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_02109000.h"
#include "01/unk_021a9000.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020f9c6c.h"

void func_ov001_0218bee4(Unk02188950 *mapObject) {
    Kart *kart;

    kart = GetKart((u16) gRaceSetup->mEntryIndex);
    func_ov001_02187218(mapObject, 2, (s32(*)(Unk02188950 *)) func_ov001_0218c55c);
    StartAnimationWithEndCallback(mapObject, mapObject->mPrm->mUnk_184, mapObject->mPrm->mUnk_188, func_ov001_0218bfc8);
    func_ov001_0219b1c4(mapObject->mNsbmd, mapObject->mPrm->mUnk_18c, mapObject->mPrm->mUnk_188, 0);
    SetSpeedTargetAndPerCall(mapObject, 0, mapObject->mPrm->mUnk_144);
    func_ov001_02188a30(mapObject, 0, mapObject->mPrm->mUnk_154, mapObject->mPrm->mUnk_148, mapObject->mPrm->mUnk_14c);
    SetAnglePoint(mapObject, &kart->mPos);
    SetMoveAnglePoint(mapObject, &GetCurrentGroupEntry(mapObject)->mPos);
    SetAnimationFrameCallback(mapObject, mapObject->mPrm->mUnk_190, ThrowBombsAndKinoko);
}

void func_ov001_0218bde8(Unk02188950 *mapObject) {
    Kart *kart;

    kart = GetKart((u16) gRaceSetup->mEntryIndex);
    func_ov001_02187218(mapObject, 2, (s32(*)(Unk02188950 *)) func_ov001_0218c55c);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_134, mapObject->mPrm->mUnk_138);
    func_ov001_0219b1c4(mapObject->mNsbmd, mapObject->mPrm->mUnk_13c, mapObject->mPrm->mUnk_138, 0);
    SetSpeedTargetAndPerCall(mapObject, mapObject->mPrm->mUnk_140, mapObject->mPrm->mUnk_144);
    func_ov001_02188a30(mapObject, mapObject->mPrm->mUnk_150, mapObject->mPrm->mUnk_154, mapObject->mPrm->mUnk_148,
                        mapObject->mPrm->mUnk_14c);
    SetAnglePoint(mapObject, &kart->mPos);
    SetMoveAnglePoint(mapObject, &GetCurrentGroupEntry(mapObject)->mPos);
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->mUnk_158, func_ov001_0218bee4);
    mapObject->mUnk_138 = func_ov001_02187f7c(mapObject);
    func_ov001_0218c5fc(mapObject);
}

void func_ov001_0218bd80(Unk02188950 *mapObject) {
    func_ov001_02187218(mapObject, 7, NULL);
    StartAnimationWithEndCallback(mapObject, mapObject->mPrm->mUnk_1f8, mapObject->mPrm->mUnk_1fc, NULL);
    func_ov001_0219b1c4(mapObject->mNsbmd, mapObject->mPrm->mUnk_200, mapObject->mPrm->mUnk_1fc, 0);
    func_ov001_02188c90(mapObject);
    SetSpeedAndClearTarget(mapObject, 0);
    mapObject->mUnk_000.mFlags &= ~0x20;
}

void func_ov001_0218bcc4(Unk02188950 *mapObject) {
    Vec3 velocity = {0, 0, 0};

    velocity.y = mapObject->mPrm->mUnk_1f4;
    func_ov001_02187218(mapObject, 7, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_1e0, mapObject->mPrm->mUnk_1e4);
    func_ov001_0219b1c4(mapObject->mNsbmd, mapObject->mPrm->mUnk_1e8, mapObject->mPrm->mUnk_1e4, 0);
    SetVelocity(mapObject, &velocity);
    func_ov001_02188c90(mapObject);
    SetSpeedTargetAndPerCall(mapObject, mapObject->mPrm->mUnk_1ec, mapObject->mPrm->mUnk_1f0);
    SetCourseCollisionCallback(mapObject, func_ov001_0218bd80);
    StartMapObjectSound(&mapObject->mUnk_000, 0x226);
    mapObject->mUnk_000.mFlags |= data_ov001_021a65a8;
}

void func_ov001_0218bc60(Unk02188950 *mapObject) {
    func_ov001_02187218(mapObject, 7, NULL);
    StartAnimationWithEndCallback(mapObject, mapObject->mPrm->mUnk_1d4, mapObject->mPrm->mUnk_1d8, func_ov001_0218bcc4);
    func_ov001_0219b1c4(mapObject->mNsbmd, mapObject->mPrm->mUnk_1dc, mapObject->mPrm->mUnk_1d8, 0);
    func_ov001_02188c90(mapObject);
    SetSpeedAndClearTarget(mapObject, 0);
}

void func_ov001_0218bbac(Unk02188950 *mapObject) {
    func_ov001_02187218(mapObject, 7, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_1b4, mapObject->mPrm->mUnk_1b8);
    func_ov001_0219b1c4(mapObject->mNsbmd, mapObject->mPrm->mUnk_1bc, mapObject->mPrm->mUnk_1b8, 0);
    func_ov001_02188c48(mapObject, mapObject->mPrm->mUnk_1c8, mapObject->mPrm->mUnk_1cc);
    SetAnglePointAndMoveAnglePoint(mapObject, &mapObject->mUnk_000.mCourseMapRow->mUnk_00);
    SetSpeedTargetAndPerCall(mapObject, mapObject->mPrm->mUnk_1c0, mapObject->mPrm->mUnk_1c4);
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->mUnk_1d0, func_ov001_0218bc60);
    func_ov001_0218c5fc(mapObject);
}

int func_ov001_0218bb74(Unk02188950 *mapObject) {
    if (func_ov001_02188220(mapObject) == 1) {
        StartMapObjectSoundWhileRequested(&mapObject->mUnk_000, 0x220);
    } else if (func_ov001_02188220(mapObject) == 2) {
        StartMapObjectSoundWhileRequested(&mapObject->mUnk_000, 0x221);
    }
    return 0;
}

void func_ov001_0218ba48(Unk02188950 *mapObject) {
    func_ov001_02187218(mapObject, 8, func_ov001_0218bb74);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_0dc, mapObject->mPrm->mUnk_0e0);
    func_ov001_0219b1c4(mapObject->mNsbmd, mapObject->mPrm->mUnk_0e4, mapObject->mPrm->mUnk_0e0, 0);
    SetSpeedTargetAndPerCall(mapObject, mapObject->mPrm->mUnk_0e8, mapObject->mPrm->mUnk_0ec);
    func_ov001_02188c48(mapObject, mapObject->mPrm->mUnk_0f0, mapObject->mPrm->mUnk_0f4);
    SetAnglePointAndMoveAnglePoint(mapObject, &GetCurrentGroupEntry(mapObject)->mPos);
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->mUnk_100, func_ov001_0218c354);
    SetScaleTargetAndPerCall(mapObject, (mapObject->mUnk_000.mScale.x + mapObject->mPrm->mUnk_0f8),
                             mapObject->mPrm->mUnk_0fc);
    SetSpeedAndClearTarget(mapObject, 0);
    SetMapObjectModelNsbtpFrameIndex(mapObject->mNsbmd, func_ov001_02188220(mapObject));
    if (func_ov001_02188220(mapObject) == 0) {
        SetDoubledCollisionAndShadowTargets(mapObject);
        StartEffectAtScaledOffset(mapObject, 0, 0x1800, 0, 0x419, 0);
    } else if (func_ov001_02188220(mapObject) == 1) {
        SetTripledCollisionAndShadowTargets(mapObject);
        StartEffectAtScaledOffset(mapObject, 0, 0x1800, 0, 0x41a, 0);
    }
}

void func_ov001_0218ba34(Unk02188950 *mapObject) {
    func_ov001_0218ba48(mapObject);
    func_ov001_02188230(mapObject);
}

void func_ov001_0218b9b4(Unk02188950 *mapObject) {
    Kart *kart;

    kart = GetKart((u16) gRaceSetup->mEntryIndex);
    func_ov001_02187218(mapObject, 8, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_078, mapObject->mPrm->mUnk_07c);
    func_ov001_02188c48(mapObject, mapObject->mPrm->mUnk_20c, mapObject->mPrm->mUnk_210);
    SetAnglePointAndMoveAnglePoint(mapObject, &kart->mPos);
    SetSpeedTargetAndPerCall(mapObject, mapObject->mPrm->mUnk_204, mapObject->mPrm->mUnk_208);
}
