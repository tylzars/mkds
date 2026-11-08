#pragma once

#include "types.h"

// Row of the array at 0x00 of the object behind gCourseMap.
typedef struct CourseMapRow {
    /* 00 */ Vec3 mUnk_00;
    /* 0c */ Vec3 mUnk_0c;
    /* 18 */ Vec3 mUnk_18;
    /* 24 */ u16 mKind;
    /* 26 */ s16 mUnk_26;
    /* 28 */ s16 mUnk_28;
    /* 2a */ s16 mUnk_2a;
    /* 2c */ s16 mUnk_2c;
    /* 2e */ s16 mUnk_2e;
    /* 30 */ s16 mUnk_30;
    /* 32 */ s16 mUnk_32;
    /* 34 */ s16 mUnk_34;
    /* 36 */ s16 mUnk_36;
    /* 38 */ u16 mUnk_38;
    /* 3a */ u8 mUnk_3a[2];
} CourseMapRow;

#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_0210b000.h" // SoundDistanceSquaredChange

// Object GetViewTransposeMatrix returns: a vector at 0x18.
typedef struct Unk020e6b38 {
    /* 00 */ u8 mUnk_00[0x18];
    /* 18 */ Vec3 mUnk_18;
} Unk020e6b38;

// Stack object of InitItemKouraWFromData: the two vectors Vec3NormalizeAndGetLengthUnchecked and
// QuaternionFromYAxisToVec3 write.
typedef struct DirectionQuaternion {
    /* 00 */ Vec3 mDirection;
    /* 0c */ Vec3 mQuaternion;
    /* 18 */ u8 mUnk_18[8];
} DirectionQuaternion;

// Object of item kind 5, element of gItemPools[5].
typedef struct ItemKouraW {
    /* 000 */ ItemObject mUnk_000;
    /* 12c */ u8 mUnk_12c[4];
    /* 130 */ u32 mDirection;
    /* 134 */ u8 mUnk_134[0x2c];
    /* 160 */ s32 mUnk_160;
    /* 164 */ u8 mUnk_164[4];
    /* 168 */ ItemPointLink *mTargetLink;
    /* 16c */ s32 mUnk_16c;
    /* 170 */ u32 mUnk_170;
    /* 174 */ u8 mUnk_174[0xa8];
    /* 21c */ s32 mPreviousLink;
    /* 220 */ u8 mUnk_220[8];
    /* 228 */ struct KartItems *mKartItems;
    /* 22c */ Vec3 mUnk_22c;
    /* 238 */ Vec3 mUnk_238;
    /* 244 */ Vec3 mUnk_244;
    /* 250 */ Vec3 mUnk_250;
    /* 25c */ s32 mAngle;
    /* 260 */ s32 mUnk_260;
    /* 264 */ s32 mUnk_264;
    /* 268 */ u16 mDrawOffsetAngle;
    /* 26a */ u8 mUnk_26a[2];
    /* 26c */ s32 mPosStrip;
    /* 270 */ s32 mSoundId;
    /* 274 */ u16 mRank;
    /* 276 */ u16 mRankKartIndex;
    /* 278 */ s32 mUnk_278;
    /* 27c */ s32 mUnk_27c;
    /* 280 */ u16 mKartMask;
    /* 282 */ u8 mUnk_282[2];
    /* 284 */ s32 mUnk_284;
    /* 288 */ u16 mUnk_288;
    /* 28a */ u8 mUnk_28a[2];
    /* 28c */ Vec3 mUnk_28c;
    /* 298 */ Vec3 mUnk_298;
    /* 2a4 */ Vec3 mUnk_2a4;
    /* 2b0 */ struct ModelEffect *mModelEffect;
    /* 2b4 */ u8 mUnk_2b4[0x30];
    /* 2e4 */ s32 mUnk_2e4;
    /* 2e8 */ u8 mUnk_2e8[4];
    /* 2ec */ u32 mStateFrames;
    /* 2f0 */ u8 mUnk_2f0[6];
    /* 2f6 */ u16 mState;
    /* 2f8 */ u16 mNextState;
    /* 2fa */ u16 mNextStateRequested;
    /* 2fc */ s32 mUnk_2fc;
    /* 300 */ SoundDistanceSquaredChange mUnk_300;
    /* 310 */ u8 mUnk_310[0xc];
} ItemKouraW;

typedef struct ItemKouraW ItemKouraW;

#include "Main/Unknown/code_020f1d70.h"

#include "Main/Unknown/code_020f6be8.h"
#include "Main/Unknown/code_020ea670.h"
#include "Main/Unknown/code_0206bcb0.h"

extern Nsbmd *gKouraW;

void func_020f9c6c(ItemObject *item);
void CreateItemObjectCollisionSlot(void *objectParam);
s32 func_020f9ce8(ItemObject *item);
s32 func_020f9dc8(ItemObject *item);
void SetItemObjectScaleByRatios(ItemObject *objectParam, s32 xRatio, s32 yRatio);
void func_020f9fa8(ItemObject *item);
void RefreshItemObjectScale(ItemObject *item);
s32 GrowItemObjectScale(void *objectParam, s32 limit, s32 step);
s32 func_020fa0e8(s32 kind, s32 param_2);
void InitItems(void);
void StartCourseMapItemObjects(void);
// Takes an object of kind param_1 from its pool, reserves, starts and places it; returns 0 when the pool is full
// (mLimit - mReservedCount <= 0).
void *StartItemObjectOrZero(s32 kind, u16 param_2, void *param_3, void *param_4);
struct ItemObject *GetCollidedItemObject(u32 index);
s32 CollideKartWithItemObjects(Kart *kart);
void StartItemSlotForKart(s32 kartIndex, s32 param_2, s32 param_3);
void DrawItems(void *a);
// Per-frame item step: mode-5 sync, the object pools whose mUnk_14 is set, every kart's record, the item timers, two
// map-object steps
void UpdateItems(void);
void func_020fa9e4(void);
BOOL TryReleaseItemObjectsForItemInfo(s32 itemInfoIndex);
BOOL ReplaceUnavailableItem(s32 *itemInfoIndexPointer);
BOOL IsItemInfoObjectCountFree(s32 itemInfoIndex);
void SetupItemKouraWKind(void);
Vec3 *GetItemKouraWState7Info(ItemKouraW *item, s32 *stateFrames, s32 *scaleRatio);
BOOL IsItemKouraWState7(ItemKouraW *item);
s32 RequestItemKouraWState7(ItemKouraW *item);
void DrawItemKouraW(ItemKouraW *item, s32 param_2, s32 param_3);
void DrawItemKouraWModel(ItemKouraW *item, s32 param_2, s32 param_3);
void InitItemKouraWFromData(ItemKouraW *item);
void *func_020fb208(void *param_1, ItemKouraW *item, void *param_3);
void UpdateItemKouraWState7(ItemKouraW *item);
void EnterItemKouraWState7(ItemKouraW *param_1);
void UpdateItemKouraWState6(ItemKouraW *item);
void EnterItemKouraWState6(ItemKouraW *item);
void UpdateItemKouraWState5(ItemKouraW *item);
void EnterItemKouraWState5(ItemKouraW *item);
void UpdateItemKouraWState4(ItemKouraW *item);
void EnterItemKouraWState4(ItemKouraW *item);
void UpdateItemKouraWState2(ItemKouraW *item);
void UpdateItemKouraWState3(ItemKouraW *item);
void EnterItemKouraWState3(ItemKouraW *item);
void UpdateItemKouraWState1(ItemKouraW *item);
void UpdateItemKouraWState0(ItemKouraW *item);
void AdvanceItemKouraW(ItemKouraW *item);
void UpdateItemKouraWOrientation(ItemKouraW *item, Vec3 *direction, s32 followDelta, Vec3 *normal);
void UpdateItemKouraWDrawPos(ItemKouraW *item);
s32 InitItemKouraW(ItemInUse *itemInUse, ItemKouraW *item);
void SetItemKouraWKartItemsAndStateIfNone(ItemKouraW *item, s32 kartIndex);
void func_020fc94c(ItemKouraW *item);
void ResetItemKouraW(ItemKouraW *item);
void func_020fcb30(ItemKouraW *item);
