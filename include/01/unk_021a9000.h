#pragma once

#include "types.h"
#include "01/code_02188e88.h"
#include "01/code_0219b250.h"
#include "01/code_0219853c.h"
#include "01/code_02198854.h"
#include "01/code_0219a050.h"
#include "01/code_0219b540.h"
#include "01/code_02193c5c.h"
#include "00/code_02181f98.h"
#include "Main/Unknown/types_02180728.h" // TextCanvas

// Four callbacks; the first receives OptionStates.mStateHeap.
typedef struct OptionStateCallbacks {
    /* 00 */ void (*mInit)(void *);
    /* 04 */ UnkFunc *mRelease;
    /* 08 */ UnkFunc *mAdvance;
    /* 0c */ UnkFunc *mUnk_0c;
} OptionStateCallbacks;

extern const OptionStateCallbacks gOptionTopMenuCallbacks;

// Object behind gOptionHensyuMenu.
typedef struct OptionHensyuMenu {
    /* 00 */ s32 mState;
    /* 04 */ s32 mNextState;
    /* Init leaves it unset when the previous option state is not 0, 3, 5 or 6 (0, 5 -> 0, 3, 6 -> 1) */
    /* 08 */ s32 mIndex;
    /* counted only in states 1, 4, 5; zeroed when 1 and 4 hand over; state 5 keeps counting while it requests the
       next option state */
    /* 0c */ s32 mStateFrames;
    /* option state passed to RequestOptionState (0, 3, 5 or 6); no initial store, set by the input handler (state
       3); also tested inside the screen */
    /* 10 */ s32 mNextOptionState;
    /* 14 */ BOOL mUnk_14;
    /* 18 */ void *mUnk_18;
    // one 0x40-byte record per cell of the Bncl member, built by InitLayoutTable
    /* 1c */ LayoutTableEntry *mOptionHensyuMenuSTable;
    /* 20 */ struct Unk02021dc8 *mOptionHensyuMenuSNcer;
    /* 24 */ Ncgr *mOptionHensyuMenuSNcgr;
    /* 28 */ Nclr *mOptionHensyuMenuSONclr;
    /* 2c */ struct Unk0201ea30 *mOptionHensyuMenuSBncl;
    /* 30 */ void *mOptionHensyuMenuSBnbl;
} OptionHensyuMenu;

// Allocated by InitOptionStates and held in gOptionStates.
typedef struct OptionStates {
    /* 00 */ void *mHeap;
    /* 04 */ void *mStateHeap;
    /* 08 */ s32 mState;
    /* 0c */ s32 mNextState;
    /* 10 */ s32 mPrevState;
    /* 14 */ s16 mUnk_14;
    /* 16 */ u8 mUnk_16[2];
    /* 18 */ OptionStateCallbacks mCallbacks;
    /* 28 */ void *mUnk_28;
} OptionStates;

typedef struct MissionRunData {
    /* 00 */ s32 mSinceHitCallbackFrames;
    /* 04 */ u16 mCount;
    /* 06 */ u16 mBossCount;
    /* 08 */ u16 mPendingCountUp;
    /* 0a */ u16 mPendingDrop;
    /* 0c */ u16 mPendingBossTransfer;
    /* 0e */ u16 mTimer;
    /* 10 */ u16 mUnk_10;
    /* 12 */ u16 mUnk_12;
    /* 14 */ u16 mUnk_14;
    /* 16 */ u16 mUnk_16;
    /* 18 */ UnkFunc *mCountUpCallback;
    /* 1c */ UnkFunc *mDropCallback;
    /* 20 */ UnkFunc *mBossTransferCallback;
    /* 24 */ UnkFunc *mTimerEndCallback;
    /* 28 */ Vec3 mKartPos;
    /* 34 */ Vec3 mPrevKartPos;
    /* 40 */ u16 mKartHeadingAngle;
    /* 42 */ u16 mPrevKartHeadingAngle;
    /* 44 */ s32 mMapObjectCount;
    /* 48 */ struct Unk02188950 *mMapObjects[8];
} MissionRunData;

// A square grid of mSide by mSide cells.
typedef struct EmblemGrid {
    /* 00 */ s32 mSide;
    /* 04 */ s32 mScrSide;
    /* 08 */ s32 mTableCount;
    /* 0c */ BOOL mCopied;
    /* 10 */ s32 mChanged;
    /* 14 */ s32 mSwapped;
    /* 18 */ u16 *mUnk_18;
    /* 1c */ u8 *mBuffers[5];
} EmblemGrid;

// Allocated by InitSelectBattleStage and held in gSelectBattleStage.
typedef struct SelectBattleStage {
    /* 0000 */ s32 mState;
    /* 0004 */ s32 mNextState;
    /* 0008 */ s32 mIndex;
    /* 000c */ s32 mStateFrames;
    /* 0010 */ s32 mOffsetTimer;
    /* 0014 */ s32 mUnk_14;
    /* 0018 */ s32 mUnk_18;
    /* 001c */ s32 mOffset;
    /* 0020 */ BOOL mUnk_20;
    /* 0024 */ s32 mResult;
    /* 0028 */ s32 mPendingResult;
    /* 002c */ BOOL mUnk_2c;
    /* 0030 */ u16 mSelectBattleStageMNscrCopy[64][32];
    /* 1030 */ void *mHeap;
    /* 1034 */ LayoutTableEntry *mSelectBattleStageTables[2];
    /* 103c */ struct Unk02021dc8 *mSelectBattleStageMNcer;
    /* 1040 */ struct Unk02021dc8 *mSelectBattleStageSNcer;
    /* 1044 */ Ncgr *mSelectBattleStageMNcgr;
    /* 1048 */ Ncgr *mSelectBattleStageSNcgr;
    /* 104c */ u8 pad_104c[8];
    /* 1054 */ Unk0201ea30 *mSelectBattleStageBncls[2];
    /* 105c */ void *mSelectBattleStageBnbls[2];
    /* 1064 */ void *mSelectBattleStageBnlls[2];
    /* 106c */ Nscr *mSelectBattleStageMNscrs[3];
    /* 1078 */ void *mUnk_1078;
    /* 107c */ void *mUnk_107c;
    /* 1080 */ struct Bmg *mMenuMessages;
    /* 1084 */ struct Bmg *mCommonMessages;
} SelectBattleStage;

// Object that func_ov001_02180610 allocates and gTestScene points to.
typedef struct TestScene {
    /* 0000 */ s32 mUnk_0000;
    /* 0004 */ s32 mState;
    /* 0008 */ s32 mStateChanged;
    /* 000c */ void *mFonts[3];
    /* 0018 */ u8 mCharCanvases[3][0x20];
    /* 0078 */ TextCanvas mTextCanvases[3];
    /* 00a8 */ u16 mChars[0x3000];
    /* 60a8 */ u16 mScreenMap[0x300];
} TestScene;

// Objects whose layout isn't known yet.
extern const char *gMissionRunMSselMNcgrName;
extern const char *gMissionRunMSselSONclrName;
extern const char *gMissionRunMSselSBnllName;
extern const char *gMissionRunMSselSNcerName;
extern const char *gMissionRunMSselMWNscrName;
extern const char *gMissionRunMSselMONclrName;
extern const char *gMissionRunMSselMBnclName;
extern const char *gMissionRunMSselSBnblName;
extern const char *gMissionRunMSselSBnclName;
extern const char *gMissionRunMSselMBNclrName;
extern const char *gMissionRunMSselMBnllName;
extern const char *gMissionRunMSselSNcgrName;
extern const char *gMissionRunMSselMBNcgrName;
extern const char *gMissionRunMSselMNscrName;
extern const char *gMissionRunMSselMNcerName;
extern const char *gMissionRunBossIconSNcerName;
extern const char *gMissionRunBossIconSNcgrName;
extern const char *gMissionRunBossIconSBnclName;
extern const char *gMissionRunBossIconSONclrName;
extern TestScene *gTestScene;
extern u16 data_ov001_021a9ba0;
extern SelectBattleStage *gSelectBattleStage;
// One pair of halfwords of the object behind gOptionEmbremSelect.
typedef struct Unk021a9bfc_18 {
    /* 00 */ s16 mUnk_00;
    /* 02 */ s16 mUnk_02;
} Unk021a9bfc_18;

// Object behind gOptionEmbremSelect.
typedef struct OptionEmbremSelect {
    /* 00 */ s32 mState;
    /* 04 */ s32 mNextState;
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ s32 mUnk_10;
    /* 14 */ s32 mStateFrames;
    /* 18 */ Unk021a9bfc_18 mUnk_18[2];
    /* 20 */ s32 mNextOptionState;
    /* 24 */ BOOL mUnk_24;
    // Set to 6 by a press; counts down to 0 only while mUnk_08 == 1. 6 - timer indexes a table through func_020adc64
    // (a displacement that returns to 0); [0] is subtracted from a row member, [1] added to one.
    /* 28 */ s32 mOffsetTimers[2];
    /* 30 */ void *mUnk_30;
    /* 34 */ LayoutTableEntry *mOptionEmbremSelectSTable;
    /* 38 */ struct Unk02021dc8 *mOptionEmbremSelectSNcer;
    /* 3c */ Ncgr *mOptionEmbremSelectSNcgr;
    /* 40 */ Nclr *mOptionEmbremSelectSONclr;
    /* 44 */ Unk0201ea30 *mOptionEmbremSelectSBncl;
    /* 48 */ void *mOptionEmbremSelectSBnbl;
    /* 4c */ struct Unk0201ea30 *mOptionEmbremSelectSBnll;
    /* 50 */ struct Bmg *mOptionMessages;
    /* 54 */ void *mCommonMessages;
} OptionEmbremSelect;

extern const char *gMissionRunLVselMBNcgrName;
extern const char *gMissionRunLVselMNscrName;
extern const char *gMissionRunLVselMBNclrName;
extern const char *gMissionRunLVselS7BnclName;
extern const char *gMissionRunLVselS7BnblName;
extern const char *gMissionRunLVselS7BnllName;
extern const char *gMissionRunLVselS6BnclName;
extern const char *gMissionRunLVselS6BnblName;
extern const char *gMissionRunLVselS6BnllName;
extern const char *gMissionRunLVselSNcgrName;
extern const char *gMissionRunLVselSNcerName;
extern const char *gMissionRunLVselSONclrName;
extern const char *gSelectEngineMNcgrName;
extern const char *gSelectEngineASBnblName;
extern const char *gSelectEngineMNcerName;
extern const char *gSelectEngineBSBnclName;
extern const char *gSelectEngineMBNcgrName;
extern const char *gSelectEngineMNscrName;
extern const char *gSelectEngineSNcgrName;
extern const char *gSelectEngineSNcerName;
extern const char *gSelectEngineSONclrName;
extern const char *gSelectEngineASBnclName;
extern const char *gSelectEngineMBnclName;
extern const char *gSelectEngineMBNclrName;
extern const char *gSelectEngineMONclrName;
extern const char *gSelectEngineBSBnblName;
extern s32 gTestSceneCharTableIndex;
extern u16 gTestSceneCharText[];
extern char data_ov001_021a94a4[];
extern char data_ov001_021a94b0[];
extern char data_ov001_021a94bc[];
extern char data_ov001_021a94d0[];
typedef struct TimeAttackTopMenu {
    /* 00 */ struct Unk02021dc8 *mTimeAttackTopMenuSNcer;
    /* 04 */ struct Unk0201ea30 *mTimeAttackTopMenuSBncl;
    /* 08 */ void *mTimeAttackTopMenuSBnbl;
    // one 0x40-byte record per cell of the Bncl member, built by InitLayoutTable
    /* 0c */ LayoutTableEntry *mTimeAttackTopMenuSTable;
    /* 10 */ void *mUnk_10;
    /* 14 */ void *mHeap;
    /* 18 */ s32 mState;
    /* 1c */ s32 mNextState;
    /* 20 */ s32 mStateFrames; /* counted only in states 0, 1, 4, 5; zeroed by the next-state setter */
    /* 24 */ s32 mBg0Offset;
    /* 28 */ s32 mIndex;
    /* 2c */ void *mUnk_2c;
    /* 30 */ s32 mUnk_30;
    /* 34 */ s32 mResult;
} TimeAttackTopMenu;

extern RaceHudSubScreenCells *data_ov001_021a9bc0;
extern u16 data_ov001_021a9b94;
extern const char *data_ov001_021a90e8[5];
extern const char *data_ov001_021a92c8[5];

#include "00/code_021832d8.h"
