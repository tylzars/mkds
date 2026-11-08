#pragma once

#include "types.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_0207ffa4.h"
#include "Main/Unknown/code_0208fd8c.h"
#include "Main/Unknown/code_02080cd0.h"

typedef struct MapObject MapObject;

// Object of 0x34 bytes at 0xe8 of the object KartAi starts: func_02089a24 writes the words at 0x28 and 0x2c and
// the halfword at 0x30.
typedef struct KartAiRaceSpeedLimit {
    /* 00 */ s32 mBaseSpeedLimit;
    /* 04 */ s32 mSpeedLimit;
    /* 08 */ s32 mSpeedLimitAddition;
    /* 0c */ s32 mTurnSpeedLimit;
    /* 10 */ s32 mSpeedLimitBeforeTurn;
    /* 14 */ s32 mRank;
    /* 18 */ s32 mSpeedLimitReduced;
    /* 1c */ s32 mUnk_1c;
    /* 20 */ s32 mUnk_20;
    /* 24 */ s32 mUnk_24;
    /* 28 */ s32 mUnk_28;
    /* 2c */ s32 mBoostsAtRaceStart;
    /* 30 */ u16 mRaceStartBoostChoice;
    /* 32 */ u8 mUnk_32[2];
} KartAiRaceSpeedLimit;

// Object at 0x140 of the object KartAi starts: AdvanceBattleKartAiSpeedLimit and SetBattleKartAiTurnSpeedLimit write
// the words at 0x04, 0x0c and 0x10.
typedef struct KartAiSpeedLimit {
    /* 00 */ s32 mBaseSpeedLimit;
    /* 04 */ s32 mSpeedLimit;
    /* 08 */ s32 mUnk_08;
    /* 0c */ BOOL mUnk_0c;
    /* 10 */ s32 mTurnSpeedLimit;
} KartAiSpeedLimit;

// One per Kart: follows the kart (mKart), steers it and requests its bits and items.
// Object of 0x158 bytes (FindKartAiTargetShine to func_02089a24 take it first): the Kart it follows at 0x00, a
// LinkCursor at 0x28, vectors at 0x44, 0x50, 0x60 and 0xdc, a KartAiRaceSpeedLimit at 0xe8, a KartAiItemUse at 0x11c, a
// KartAiSpeedLimit at 0x140 and a word at 0x154.
typedef struct KartAi {
    /* 00 */ Kart *mKart;
    /* 04 */ u16 mIndex;
    /* 06 */ u16 mUnk_06;
    /* 08 */ Unk02080d34 mUnk_08;
    /* 28 */ LinkCursor mBattleLinkCursor;
    /* 44 */ Vec3 mLinkPosWithSideOffset;
    /* 50 */ Vec3 mTargetKartPos;
    // Points at the position the CPU kart heads to: mLinkPosWithSideOffset, mTargetKartPos or mTargetShinePos.
    /* 5c */ Vec3 *mHeadingPos;
    /* 60 */ Vec3 mSideOffset;
    /* 6c */ u16 mUnk_6c;
    /* 6e */ u16 mUnk_6e;
    /* 70 */ s32 mTurnAngleDegrees;
    /* 74 */ s32 mSideOffsetRatio;
    /* 78 */ u16 mUnk_78;
    /* 7a */ u16 mUnk_7a;
    /* 7c */ s32 mUnk_7c;
    /* 80 */ u16 mUnk_80;
    /* 82 */ u8 mUnk_82[2];
    /* 84 */ s32 mUnk_84;
    /* 88 */ s32 mUnk_88;
    /* 8c */ s32 mDriftChargeRandomLimit;
    /* 90 */ s32 mUnk_90;
    /* 94 */ s32 mTurnSide;
    /* 98 */ s32 mUnk_98;
    /* 9c */ s32 mMinVelocityLength;
    /* a0 */ BOOL mUnk_a0;
    /* a4 */ s32 mLinkSpeedLimit;
    /* a8 */ s32 mUnk_a8;
    /* ac */ s16 mUnk_ac;
    /* ae */ u8 mUnk_ae[2];
    /* b0 */ Kart *mTargetKart;
    /* b4 */ s32 mTargetAhead;
    /* b8 */ s32 mTargetDistanceSquared;
    /* bc */ s32 mTargetForwardDot;
    /* c0 */ s16 mBalloonCountGoal;
    /* c2 */ s16 mUnk_c2;
    /* c4 */ BOOL mUnk_c4;
    /* c8 */ u16 mUnk_c8;
    /* ca */ u16 mUnk_ca;
    /* cc */ s32 mUnk_cc;
    /* d0 */ MapObject *mTargetShine;
    /* d4 */ s16 mEntrySearchStartIndex;
    /* d6 */ u8 mUnk_d6[2];
    /* d8 */ s32 mEntryForwardDot;
    /* dc */ Vec3 mTargetShinePos;
    /* e8 */ KartAiRaceSpeedLimit mUnk_e8;
    /* 11c */ KartAiItemUse mItemUse;
    /* 140 */ KartAiSpeedLimit mAiSpeedLimit;
    /* 154 */ s32 mUnk_154;
} KartAi;

void AdvanceBattleKartAiSpeedLimit(KartAiSpeedLimit *a, KartAi *b);
void SetBattleKartAiTurnSpeedLimit(KartAiSpeedLimit *a, KartAi *b, s32 c);
void func_02089a24(KartAi *a, KartAiRaceSpeedLimit *b);
void SetupBattleKartAiParams(void);
void ResetBattleKartAi(KartAi *p);
void SetupBattleKartAi(KartAi *p, Kart *q);
void ResetBattleKartAiAtPointLink(KartAi *p, PointLink *a);
void AdvanceBattleKartAi(KartAi *p);
void func_02089494(KartAi *p);
void AdvanceBattleKartAiSideOffset(KartAi *p);
void AdvanceBattleKartAiTargetKart(KartAi *p);
void func_02088d34(KartAi *p);
void PickKartAiBalloonCountGoal(KartAi *p);
void AdvanceBattleKartAiTargetShine(KartAi *p);
BOOL FindKartAiTargetShine(KartAi *p, s32 a, s32 b);
