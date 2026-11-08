#include "01/code_0218a568.h"
#include "01/code_02185ef4.h"
#include "01/code_02187c4c.h"
#include "01/code_02187c60.h"
#include "01/code_02187e78.h"
#include "01/code_02187eb0.h"
#include "01/code_02188158.h"
#include "01/code_02188cd8.h"
#include "01/code_02188de0.h"
#include "01/code_02187000.h"
#include "01/code_0218a000.h"
#include "01/code_0218ac04.h"
#include "01/code_0218b000.h"
#include "01/code_0218b034.h"
#include "01/code_0218b278.h"
#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/code_020d275c.h"
#include "Main/Unknown/code_02042044.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020fd83c.h"
#include "Main/Unknown/code_020fd000.h"
#include "Main/Unknown/code_020fd264.h"

void func_ov001_0218aba0(Unk02188950 *mapObject) {
    func_ov001_02187218(mapObject, 3, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_198, mapObject->mPrm->mUnk_19c);
    func_ov001_02188c90(mapObject);
    SetSpeedAndClearTarget(mapObject, 0);
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->mUnk_1a0, &func_ov001_0218ac04);
    StartMapObjectSound(&mapObject->mUnk_000, 0x238);
}

void StartBombKingJumpCycle(Unk02188950 *mapObject) {
    IncrementEntryIndex(mapObject);
    func_ov001_02187218(mapObject, 3, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_17c, mapObject->mPrm->mUnk_180);
    func_ov001_02188c48(mapObject, mapObject->mPrm->mUnk_18c, mapObject->mPrm->mUnk_190);
    SetAnglePointAndMoveAnglePoint(mapObject, &GetCurrentGroupEntry(mapObject)->mPos);
    SetSpeedTargetAndPerCall(mapObject, mapObject->mPrm->mUnk_184, mapObject->mPrm->mUnk_188);
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->mUnk_194, &func_ov001_0218aba0);
    func_ov001_0218b278(mapObject);
}

void StartBombKingThrowBombsState(Unk02188950 *mapObject) {
    func_ov001_02187218(mapObject, 3, NULL);
    StartAnimationWithEndCallback(mapObject, mapObject->mPrm->mUnk_140, mapObject->mPrm->mUnk_144, NULL);
    func_ov001_02188c90(mapObject);
    SetSpeedAndClearTarget(mapObject, 0);
    SetAnimationFrameCallback(mapObject, mapObject->mPrm->mUnk_148, func_ov001_0218b034);
}

void func_ov001_0218aa34(Unk02188950 *mapObject) {
    void *bomb;

    if (IsItemBombStored(mapObject) == 0) {
        bomb = StartItemBomb();
        if (bomb != NULL) {
            ReleaseAndSetItemBomb(mapObject, (bomb));
        }
    }
    if (IsItemBombStored(mapObject) != 0) {
        func_ov001_02187218(mapObject, 3, NULL);
        StartAnimationWithEndCallback(mapObject, mapObject->mPrm->mUnk_0d4, mapObject->mPrm->mUnk_0d8, 0);
        SetSpeedAndClearTarget(mapObject, 0);
        SetAnimationFrameCallback(mapObject, mapObject->mPrm->mUnk_0dc, ThrowStoredItemBomb);
    }
    StartMapObjectSound(&mapObject->mUnk_000, 0x23c);
}

void StartBombKingChaseState(Unk02188950 *mapObject) {
    Kart *kart;

    kart = GetEntryKartInRange(mapObject, mapObject->mPrm->mUnk_0c0, mapObject->mPrm->mUnk_0c4);
    if (kart != NULL) {
        func_ov001_02187218(mapObject, 3, NULL);
        StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_104, mapObject->mPrm->mUnk_108);
        func_ov001_02188c48(mapObject, mapObject->mPrm->mUnk_0bc, mapObject->mPrm->mUnk_0bc);
        SetAnglePointAndMoveAnglePoint(mapObject, &kart->mPos);
        SetSpeedAndClearTarget(mapObject, mapObject->mPrm->mUnk_0b8);
        SetPointInRangeCallback(mapObject, mapObject->mPrm->mUnk_0cc, mapObject->mPrm->mUnk_0d0, &kart->mPos,
                                &func_ov001_0218aa34);
        StartStateFrameCountCallback(mapObject, mapObject->mPrm->mUnk_0c8, 0);
        func_ov001_0218b278(mapObject);
    } else {
        func_ov001_02188e88(mapObject);
    }
}

void StartItemBombThrow(Unk02188950 *mapObject) {
    if (IsItemBombStored(mapObject) != 0) {
        func_ov001_02187218(mapObject, 3, NULL);
        StartAnimationWithEndCallback(mapObject, mapObject->mPrm->mUnk_0d4, mapObject->mPrm->mUnk_0d8, 0);
        SetSpeedAndClearTarget(mapObject, 0);
        SetAnimationFrameCallback(mapObject, mapObject->mPrm->mUnk_0dc, ThrowStoredItemBomb);
        StartMapObjectSound(&mapObject->mUnk_000, 0x23c);
    }
}

void func_ov001_0218a828(Unk02188950 *mapObject) {
    ItemBomb *bomb;
    Kart *kart;

    bomb = FindItemBombInRange(mapObject, mapObject->mPrm->mUnk_11c, mapObject->mPrm->mUnk_120);
    if (bomb != NULL) {
        kart = GetEntryKartInRange(mapObject, mapObject->mPrm->mUnk_0c0, mapObject->mPrm->mUnk_0c4);
        if (kart != NULL) {
            func_020fd754(bomb);
            ReleaseAndSetItemBomb(mapObject, bomb);
            func_ov001_02187218(mapObject, 3, NULL);
            StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_0ec, mapObject->mPrm->mUnk_0f0);
            func_ov001_02188c48(mapObject, mapObject->mPrm->mUnk_0f8, mapObject->mPrm->mUnk_0f8);
            SetAnglePointAndMoveAnglePoint(mapObject, &kart->mPos);
            SetSpeedAndClearTarget(mapObject, mapObject->mPrm->mUnk_0f4);
            SetPointInRangeCallback(mapObject, mapObject->mPrm->mUnk_0cc, mapObject->mPrm->mUnk_0d0, &kart->mPos,
                                    &StartItemBombThrow);
            func_ov001_0218b278(mapObject);
        } else {
            func_020fd754(bomb);
            ReleaseAndSetItemBomb(mapObject, bomb);
            StartItemBombThrow(mapObject);
        }
    }
}

void StartBombKingWalkToBombState(Unk02188950 *mapObject) {
    ItemBomb *bomb;

    bomb = FindItemBombInRange(mapObject, mapObject->mPrm->mUnk_114, mapObject->mPrm->mUnk_118);
    if (bomb != NULL) {
        func_ov001_02187218(mapObject, 3, NULL);
        StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_104, mapObject->mPrm->mUnk_108);
        func_ov001_02188c48(mapObject, mapObject->mPrm->mUnk_110, mapObject->mPrm->mUnk_110);
        SetAnglePointAndMoveAnglePoint(mapObject, &bomb->mUnk_000.mItemObject.mPos);
        SetSpeedAndClearTarget(mapObject, mapObject->mPrm->mUnk_10c);
        SetPointInRangeCallback(mapObject, mapObject->mPrm->mUnk_11c, mapObject->mPrm->mUnk_120,
                                &bomb->mUnk_000.mItemObject.mPos, &func_ov001_0218a828);
        StartStateFrameCountCallback(mapObject, mapObject->mPrm->mUnk_124, 0);
        func_ov001_0218b278(mapObject);
    }
}

void StartBombKingRandomState(Unk02188950 *mapObject) {
    u32 randomLimit;
    RandomState64 *rng;
    u32 randomValue;

    randomLimit = (u16) mapObject->mPrm->mUnk_208;
    if (randomLimit == 0x10000) {
        rng = GetMapObjectRandom();
        rng->mValue = rng->mMultiplier * rng->mValue + rng->mIncrement;
        randomValue = (u16) (((rng->mValue >> 32) * 0x10000) >> 32);
    } else {
        rng = GetMapObjectRandom();
        if ((u16) randomLimit == 0) {
            randomValue = 0;
        } else {
            rng->mValue = rng->mMultiplier * rng->mValue + rng->mIncrement;
            if ((u16) randomLimit == 0) {
                randomValue = rng->mValue >> 32;
            } else {
                randomValue = ((rng->mValue >> 32) * (s64) (u16) randomLimit) >> 32;
            }
        }
        randomValue = (u16) randomValue;
    }
    if (randomValue != 0) {
        StartBombKingThrowBombsState(mapObject);
    } else {
        StartBombKingChaseState(mapObject);
    }
}

void StartBombKingWalkState(Unk02188950 *mapObject) {
    MissionRunPrm *prm;

    IncrementEntryIndex(mapObject);
    func_ov001_02187218(mapObject, 2, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_084, mapObject->mPrm->mUnk_088);
    func_ov001_02188c48(mapObject, mapObject->mPrm->mUnk_090, mapObject->mPrm->mUnk_090);
    SetAnglePointAndMoveAnglePoint(mapObject, &GetCurrentGroupEntry(mapObject)->mPos);
    SetSpeedAndClearTarget(mapObject, mapObject->mPrm->mUnk_08c);
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->mUnk_09c, &StartBombKingRandomState);
    prm = mapObject->mPrm;
    SetPointInRangeCallback(mapObject, prm->mUnk_094, prm->mUnk_098, &GetCurrentGroupEntry(mapObject)->mPos,
                            &StartBombKingThrowBombsState);
    func_ov001_0218b278(mapObject);
}

int StartBombKingBounceEffects(Unk02188950 *mapObject) {
    if ((mapObject->mCollisionBits & 0x1e34ef) != 0) {
        if (mapObject->mVelocity.y > 0x3333) {
            ReleaseEffects(mapObject);
            StartEffectAtRowHeight(mapObject, 0, 0, 0, 0x411, 0);
            StartEffectAtRowHeight(mapObject, 0, 0, 0, 0x412, 0);
        }
        if (mapObject->mVelocity.y > 0) {
            StartMapObjectSound(&mapObject->mUnk_000, 0x23b);
        }
    }
    return 0;
}

int func_ov001_0218a568(Unk02188950 *mapObject) {
    if ((mapObject->mCollisionBits & 0x1e34ef) != 0) {
        mapObject->mUnk_158 = StartBombKingBounceEffects;
    }
    return 0;
}
