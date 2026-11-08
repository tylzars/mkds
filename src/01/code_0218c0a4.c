#include "01/code_0218c0a4.h"
#include "01/code_02187eb0.h"
#include "01/code_02188cd8.h"
#include "01/code_02188de0.h"
#include "01/code_02185ef4.h"
#include "01/code_02187000.h"
#include "01/code_02188000.h"
#include "01/code_02188218.h"
#include "01/code_02188e24.h"
#include "01/code_0218c584.h"
#include "01/code_0218c5fc.h"
#include "01/code_0219b1c4.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_0208b000.h"
#include "Main/Unknown/code_0208b484.h"
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
#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_020f49bc.h"
#include "01/code_02187d14.h"
#include "01/code_0218c000.h"
#include "Main/Unknown/code_020f4000.h"
#include "Main/Unknown/unk_0217c000.h"

void func_ov001_0218c490(Unk02188950 *mapObject) {
    Kart *kart = GetKart((u16) gRaceSetup->mEntryIndex);

    func_ov001_02187218(mapObject, 2, func_ov001_0218c5d4);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_104, mapObject->mPrm->mUnk_108);
    func_ov001_0219b1c4(mapObject->mNsbmd, mapObject->mPrm->mUnk_10c, mapObject->mPrm->mUnk_108, 0);
    SetSpeedTargetAndPerCall(mapObject, mapObject->mPrm->mUnk_110, mapObject->mPrm->mUnk_114);
    func_ov001_02188c48(mapObject, mapObject->mPrm->mUnk_118, mapObject->mPrm->mUnk_11c);
    SetAnglePointAndMoveAnglePoint(mapObject, &kart->mPos);
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->mUnk_12c, NULL);
    func_ov001_0218c5fc(mapObject);
}

void func_ov001_0218c3ac(Unk02188950 *mapObject) {
    if (func_ov001_02188220(mapObject) == 0) {
        SetSpeedTargetAndPerCall(mapObject, mapObject->mPrm->mUnk_0a4, mapObject->mPrm->mUnk_0a8);
        func_ov001_02188c48(mapObject, mapObject->mPrm->mUnk_0ac, mapObject->mPrm->mUnk_0b0);
    } else if (func_ov001_02188220(mapObject) == 1) {
        SetSpeedTargetAndPerCall(mapObject, mapObject->mPrm->mUnk_0bc, mapObject->mPrm->mUnk_0c0);
        func_ov001_02188c48(mapObject, mapObject->mPrm->mUnk_0c4, mapObject->mPrm->mUnk_0c8);
    } else {
        SetSpeedTargetAndPerCall(mapObject, mapObject->mPrm->mUnk_0cc, mapObject->mPrm->mUnk_0d0);
        func_ov001_02188c48(mapObject, mapObject->mPrm->mUnk_0d4, mapObject->mPrm->mUnk_0d8);
    }
    SetAnglePointAndMoveAnglePoint(mapObject, &GetCurrentGroupEntry(mapObject)->mPos);
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->mUnk_0b8, NULL);
    SetPointInRangeCallback(mapObject, mapObject->mPrm->mUnk_0b4, 0, &GetCurrentGroupEntry(mapObject)->mPos, NULL);
}

void func_ov001_0218c354(Unk02188950 *mapObject) {
    func_ov001_02187218(mapObject, 1, func_ov001_0218c5ac);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_098, mapObject->mPrm->mUnk_09c);
    func_ov001_0219b1c4(mapObject->mNsbmd, mapObject->mPrm->mUnk_0a0, mapObject->mPrm->mUnk_09c, 0);
    func_ov001_0218c3ac(mapObject);
    func_ov001_0218c5fc(mapObject);
}

void ThrowBombsAndKinoko(Unk02188950 *mapObject) {
    MissionRunPrm *prm;
    RandomState64 *random;
    u32 firstRange;
    u32 secondRange;
    u32 firstRangeLow;
    u32 secondRangeLow;
    u32 firstScaledDraw;
    u32 secondScaledDraw;
    u16 firstResult;
    u16 secondResult;
    s32 sel;
    s32 angle;
    s32 radius;
    s32 i;

    prm = mapObject->mPrm;
    angle = mapObject->mAngle - prm->mUnk_1a4 * (mapObject->mUnk_138 / 2);
    firstRange = prm->mUnk_1a8;
    if (firstRange == 0x10000) {
        random = GetMapObjectRandom();
        random->mValue = random->mIncrement + (s64) random->mMultiplier * (s64) random->mValue;
        firstResult = (random->mValue >> 32) * 0x10000 >> 32;
    } else {
        random = GetMapObjectRandom();
        if ((u16) firstRange == 0) {
            firstScaledDraw = 0;
        } else {
            random->mValue = random->mIncrement + (s64) random->mMultiplier * (s64) random->mValue;
            firstRangeLow = (u16) firstRange;
            if (firstRangeLow == 0) {
                firstScaledDraw = random->mValue >> 32;
            } else {
                firstScaledDraw = ((s64) (random->mValue >> 32) * firstRangeLow) >> 32;
            }
        }
        firstResult = firstScaledDraw;
    }
    if (firstResult == 0) {
        secondRange = mapObject->mUnk_138;
        if (secondRange == 0x10000) {
            random = GetMapObjectRandom();
            random->mValue = random->mIncrement + (s64) random->mMultiplier * (s64) random->mValue;
            secondResult = (random->mValue >> 32) * 0x10000 >> 32;
        } else {
            random = GetMapObjectRandom();
            if ((u16) secondRange == 0) {
                secondScaledDraw = 0;
            } else {
                random->mValue = random->mIncrement + (s64) random->mMultiplier * (s64) random->mValue;
                secondRangeLow = (u16) secondRange;
                if (secondRangeLow == 0) {
                    secondScaledDraw = random->mValue >> 32;
                } else {
                    secondScaledDraw = ((s64) (random->mValue >> 32) * secondRangeLow) >> 32;
                }
            }
            secondResult = secondScaledDraw;
        }
        sel = secondResult;
    } else {
        sel = -1;
    }
    radius = mapObject->mPrm->mUnk_198;
    for (i = 0; i < mapObject->mUnk_138; i++) {
        Vec3 pos;
        Vec3 vel = {0, 0, 0};

        pos.x = mapObject->mUnk_000.mPos.x + (((s64) radius * gPairsByAngle[((u16) angle >> 4) * 2]) >> 12);
        pos.y = mapObject->mUnk_000.mPos.y + mapObject->mPrm->mUnk_194;
        pos.z = mapObject->mUnk_000.mPos.z + (((s64) radius * gPairsByAngle[((u16) angle >> 4) * 2 + 1]) >> 12);
        vel.x = ((s64) mapObject->mPrm->mUnk_1a0 * gPairsByAngle[((u16) angle >> 4) * 2]) >> 12;
        vel.y = mapObject->mPrm->mUnk_19c;
        vel.z = ((s64) mapObject->mPrm->mUnk_1a0 * gPairsByAngle[((u16) angle >> 4) * 2 + 1]) >> 12;
        if (i == sel) {
            ThrowItemKinokoFromPosition(StartItemKinokoOrZero(), &pos, &vel, mapObject->mPrm->mUnk_1ac);
        } else {
            ThrowItemBombFromPosition(StartItemBombWithParkedKuribo(), &pos, &vel, mapObject->mPrm->mUnk_1b0);
        }
        angle += mapObject->mPrm->mUnk_1a4;
        StartEffect(0x3f7, &pos);
        StartEffect(0x3f6, &pos);
    }
    StartMapObjectSound(&mapObject->mUnk_000, 0x222);
}
