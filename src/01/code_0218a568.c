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

void func_ov001_0218aba0(Unk02188950 *a) {
    func_ov001_02187218(a, 3, NULL);
    StartAnimationNoEndCallback(a, a->mPrm->mUnk_198, a->mPrm->mUnk_19c);
    func_ov001_02188c90(a);
    SetSpeedAndClearTarget(a, 0);
    func_ov001_02188e24(a, a->mPrm->mUnk_1a0, &func_ov001_0218ac04);
    StartMapObjectSound(&a->mUnk_000, 0x238);
}

void func_ov001_0218ab04(Unk02188950 *a) {
    IncrementEntryIndex(a);
    func_ov001_02187218(a, 3, NULL);
    StartAnimationNoEndCallback(a, a->mPrm->mUnk_17c, a->mPrm->mUnk_180);
    func_ov001_02188c48(a, a->mPrm->mUnk_18c, a->mPrm->mUnk_190);
    SetAnglePointAndMoveAnglePoint(a, &GetCurrentGroupEntry(a)->mPos);
    SetSpeedTargetAndPerCall(a, a->mPrm->mUnk_184, a->mPrm->mUnk_188);
    func_ov001_02188e24(a, a->mPrm->mUnk_194, &func_ov001_0218aba0);
    func_ov001_0218b278(a);
}

void func_ov001_0218aaac(Unk02188950 *a) {
    func_ov001_02187218(a, 3, NULL);
    StartAnimationWithEndCallback(a, a->mPrm->mUnk_140, a->mPrm->mUnk_144, NULL);
    func_ov001_02188c90(a);
    SetSpeedAndClearTarget(a, 0);
    func_ov001_02188e74(a, a->mPrm->mUnk_148, func_ov001_0218b034);
}

void func_ov001_0218aa34(Unk02188950 *a) {
    void *b;

    if (IsItemBombStored(a) == 0) {
        b = StartItemBomb();
        if (b != NULL) {
            ReleaseAndSetItemBomb(a, (b));
        }
    }
    if (IsItemBombStored(a) != 0) {
        func_ov001_02187218(a, 3, NULL);
        StartAnimationWithEndCallback(a, a->mPrm->mUnk_0d4, a->mPrm->mUnk_0d8, 0);
        SetSpeedAndClearTarget(a, 0);
        func_ov001_02188e74(a, a->mPrm->mUnk_0dc, func_ov001_0218b1d8);
    }
    StartMapObjectSound(&a->mUnk_000, 0x23c);
}

void func_ov001_0218a970(Unk02188950 *b) {
    Kart *kart;

    kart = GetEntryKartInRange(b, b->mPrm->mUnk_0c0, b->mPrm->mUnk_0c4);
    if (kart != NULL) {
        func_ov001_02187218(b, 3, NULL);
        StartAnimationNoEndCallback(b, b->mPrm->mUnk_104, b->mPrm->mUnk_108);
        func_ov001_02188c48(b, b->mPrm->mUnk_0bc, b->mPrm->mUnk_0bc);
        SetAnglePointAndMoveAnglePoint(b, &kart->mPos);
        SetSpeedAndClearTarget(b, b->mPrm->mUnk_0b8);
        func_ov001_02188de0(b, b->mPrm->mUnk_0cc, b->mPrm->mUnk_0d0, &kart->mPos, &func_ov001_0218aa34);
        func_ov001_02188e24(b, b->mPrm->mUnk_0c8, 0);
        func_ov001_0218b278(b);
    } else {
        func_ov001_02188e88(b);
    }
}

void func_ov001_0218a910(Unk02188950 *a) {
    if (IsItemBombStored(a) != 0) {
        func_ov001_02187218(a, 3, NULL);
        StartAnimationWithEndCallback(a, a->mPrm->mUnk_0d4, a->mPrm->mUnk_0d8, 0);
        SetSpeedAndClearTarget(a, 0);
        func_ov001_02188e74(a, a->mPrm->mUnk_0dc, func_ov001_0218b1d8);
        StartMapObjectSound(&a->mUnk_000, 0x23c);
    }
}

void func_ov001_0218a828(Unk02188950 *b) {
    ItemBomb *bomb;
    Kart *kart;

    bomb = FindItemBombInRange(b, b->mPrm->mUnk_11c, b->mPrm->mUnk_120);
    if (bomb != NULL) {
        kart = GetEntryKartInRange(b, b->mPrm->mUnk_0c0, b->mPrm->mUnk_0c4);
        if (kart != NULL) {
            func_020fd754(bomb);
            ReleaseAndSetItemBomb(b, bomb);
            func_ov001_02187218(b, 3, NULL);
            StartAnimationNoEndCallback(b, b->mPrm->mUnk_0ec, b->mPrm->mUnk_0f0);
            func_ov001_02188c48(b, b->mPrm->mUnk_0f8, b->mPrm->mUnk_0f8);
            SetAnglePointAndMoveAnglePoint(b, &kart->mPos);
            SetSpeedAndClearTarget(b, b->mPrm->mUnk_0f4);
            func_ov001_02188de0(b, b->mPrm->mUnk_0cc, b->mPrm->mUnk_0d0, &kart->mPos, &func_ov001_0218a910);
            func_ov001_0218b278(b);
        } else {
            func_020fd754(bomb);
            ReleaseAndSetItemBomb(b, bomb);
            func_ov001_0218a910(b);
        }
    }
}

void func_ov001_0218a75c(Unk02188950 *b) {
    ItemBomb *bomb;

    bomb = FindItemBombInRange(b, b->mPrm->mUnk_114, b->mPrm->mUnk_118);
    if (bomb != NULL) {
        func_ov001_02187218(b, 3, NULL);
        StartAnimationNoEndCallback(b, b->mPrm->mUnk_104, b->mPrm->mUnk_108);
        func_ov001_02188c48(b, b->mPrm->mUnk_110, b->mPrm->mUnk_110);
        SetAnglePointAndMoveAnglePoint(b, &bomb->mUnk_000.mItemObject.mPos);
        SetSpeedAndClearTarget(b, b->mPrm->mUnk_10c);
        func_ov001_02188de0(b, b->mPrm->mUnk_11c, b->mPrm->mUnk_120, &bomb->mUnk_000.mItemObject.mPos,
                            &func_ov001_0218a828);
        func_ov001_02188e24(b, b->mPrm->mUnk_124, 0);
        func_ov001_0218b278(b);
    }
}

void func_ov001_0218a6b0(Unk02188950 *c) {
    u32 n;
    RandomState64 *a;
    u32 b;

    n = (u16) c->mPrm->mUnk_208;
    if (n == 0x10000) {
        a = GetMapObjectRandom();
        a->mValue = a->mMultiplier * a->mValue + a->mIncrement;
        b = (u16) (((a->mValue >> 32) * 0x10000) >> 32);
    } else {
        a = GetMapObjectRandom();
        if ((u16) n == 0) {
            b = 0;
        } else {
            a->mValue = a->mMultiplier * a->mValue + a->mIncrement;
            if ((u16) n == 0) {
                b = a->mValue >> 32;
            } else {
                b = ((a->mValue >> 32) * (s64) (u16) n) >> 32;
            }
        }
        b = (u16) b;
    }
    if (b != 0) {
        func_ov001_0218aaac(c);
    } else {
        func_ov001_0218a970(c);
    }
}

void func_ov001_0218a60c(Unk02188950 *b) {
    MissionRunPrm *a;

    IncrementEntryIndex(b);
    func_ov001_02187218(b, 2, NULL);
    StartAnimationNoEndCallback(b, b->mPrm->mUnk_084, b->mPrm->mUnk_088);
    func_ov001_02188c48(b, b->mPrm->mUnk_090, b->mPrm->mUnk_090);
    SetAnglePointAndMoveAnglePoint(b, &GetCurrentGroupEntry(b)->mPos);
    SetSpeedAndClearTarget(b, b->mPrm->mUnk_08c);
    func_ov001_02188e24(b, b->mPrm->mUnk_09c, &func_ov001_0218a6b0);
    a = b->mPrm;
    func_ov001_02188de0(b, a->mUnk_094, a->mUnk_098, &GetCurrentGroupEntry(b)->mPos, &func_ov001_0218aaac);
    func_ov001_0218b278(b);
}

int func_ov001_0218a590(Unk02188950 *a) {
    if ((a->mCollisionBits & 0x1e34ef) != 0) {
        if (a->mVelocity.y > 0x3333) {
            ReleaseEffects(a);
            StartEffectAtRowHeight(a, 0, 0, 0, 0x411, 0);
            StartEffectAtRowHeight(a, 0, 0, 0, 0x412, 0);
        }
        if (a->mVelocity.y > 0) {
            StartMapObjectSound(&a->mUnk_000, 0x23b);
        }
    }
    return 0;
}

int func_ov001_0218a568(Unk02188950 *a) {
    if ((a->mCollisionBits & 0x1e34ef) != 0) {
        a->mUnk_158 = func_ov001_0218a590;
    }
    return 0;
}
