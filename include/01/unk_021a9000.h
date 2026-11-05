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
#include "Main/Unknown/types_02180728.h" // Unk02180728

// Four callbacks; the first receives OptionStates::mStateHeap.
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
    // one 0x40-byte record per cell of the Bncl member, built by func_02124ed0
    /* 1c */ Unk02124b1c *mOptionHensyuMenuSTable;
    /* 20 */ struct Unk02021dc8 *mOptionHensyuMenuSNcer;
    /* 24 */ Ncgr *mOptionHensyuMenuSNcgr;
    /* 28 */ Nclr *mOptionHensyuMenuSONclr;
    /* 2c */ void *mOptionHensyuMenuSBncl;
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

// Object behind data_ov001_021a9b90.
typedef struct Unk021a9b90 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ u16 mUnk_04;
    /* 06 */ u16 mUnk_06;
    /* 08 */ u16 mUnk_08;
    /* 0a */ u16 mUnk_0a;
    /* 0c */ u16 mUnk_0c;
    /* 0e */ u16 mUnk_0e;
    /* 10 */ u16 mUnk_10;
    /* 12 */ u16 mUnk_12;
    /* 14 */ u16 mUnk_14;
    /* 16 */ u16 mUnk_16;
    /* 18 */ UnkFunc *mUnk_18;
    /* 1c */ UnkFunc *mUnk_1c;
    /* 20 */ UnkFunc *mUnk_20;
    /* 24 */ UnkFunc *mUnk_24;
    /* 28 */ Vec3 mUnk_28;
    /* 34 */ Vec3 mUnk_34;
    /* 40 */ u16 mUnk_40;
    /* 42 */ u16 mUnk_42;
    /* 44 */ s32 mUnk_44;
    /* 48 */ struct Unk02188950 *mUnk_48[8];
} Unk021a9b90;

// Object behind data_ov001_021a9b88: a square grid of mUnk_00 by mUnk_00 cells.
typedef struct Unk021a9b88 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ BOOL mUnk_0c;
    /* 10 */ s32 mUnk_10;
    /* 14 */ s32 mUnk_14;
    /* 18 */ u16 *mUnk_18;
    /* 1c */ u8 *mUnk_1c[5];
} Unk021a9b88;

// Allocated by InitSelectBattleStage and held in gSelectBattleStage.
typedef struct SelectBattleStage {
    /* 0000 */ s32 mState;
    /* 0004 */ s32 mNextState;
    /* 0008 */ s32 mIndex;
    /* 000c */ s32 mStateFrames;
    /* 0010 */ s32 mUnk_10;
    /* 0014 */ s32 mUnk_14;
    /* 0018 */ s32 mUnk_18;
    /* 001c */ s32 mUnk_1c;
    /* 0020 */ BOOL mUnk_20;
    /* 0024 */ s32 mResult;
    /* 0028 */ s32 mPendingResult;
    /* 002c */ BOOL mUnk_2c;
    /* 0030 */ u16 mSelectBattleStageMNscrCopy[64][32];
    /* 1030 */ void *mHeap;
    /* 1034 */ Unk02124b1c *mSelectBattleStageTables[2];
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
    /* 1080 */ void *mMenuMessages;
    /* 1084 */ void *mCommonMessages;
} SelectBattleStage;

// Object that func_ov001_02180610 allocates and data_ov001_021a99e4 points to.
typedef struct Unk021a99e4 {
    /* 0000 */ s32 mUnk_0000;
    /* 0004 */ s32 mUnk_0004;
    /* 0008 */ s32 mUnk_0008;
    /* 000c */ void *mUnk_000c[3];
    /* 0018 */ u8 mUnk_0018[3][0x20];
    /* 0078 */ Unk02180728 mUnk_0078[3];
    /* 00a8 */ u16 mUnk_00a8[0x3000];
    /* 60a8 */ u16 mUnk_60a8[0x300];
} Unk021a99e4;

// Objects whose layout isn't known yet.
extern const char *data_ov001_021a9278;
extern const char *data_ov001_021a927c;
extern const char *data_ov001_021a9280;
extern const char *data_ov001_021a9284;
extern const char *data_ov001_021a928c;
extern const char *data_ov001_021a9298;
extern const char *data_ov001_021a929c;
extern const char *data_ov001_021a92a0;
extern const char *data_ov001_021a92a4;
extern const char *data_ov001_021a92a8;
extern const char *data_ov001_021a92ac;
extern const char *data_ov001_021a92b0;
extern const char *data_ov001_021a92bc;
extern const char *data_ov001_021a92c0;
extern const char *data_ov001_021a92c4;
extern const char *data_ov001_021a9938;
extern const char *data_ov001_021a993c;
extern const char *data_ov001_021a9940;
extern const char *data_ov001_021a9944;
extern Unk021a99e4 *data_ov001_021a99e4;
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
    /* 34 */ Unk02124b1c *mOptionEmbremSelectSTable;
    /* 38 */ struct Unk02021dc8 *mOptionEmbremSelectSNcer;
    /* 3c */ Ncgr *mOptionEmbremSelectSNcgr;
    /* 40 */ Nclr *mOptionEmbremSelectSONclr;
    /* 44 */ Unk0201ea30 *mOptionEmbremSelectSBncl;
    /* 48 */ void *mOptionEmbremSelectSBnbl;
    /* 4c */ void *mOptionEmbremSelectSBnll;
    /* 50 */ void *mOptionMessages;
    /* 54 */ void *mCommonMessages;
} OptionEmbremSelect;

extern const char *data_ov001_021a90a8;
extern const char *data_ov001_021a90e4;
extern const char *data_ov001_021a90cc;
extern const char *data_ov001_021a90dc;
extern const char *data_ov001_021a90b8;
extern const char *data_ov001_021a90bc;
extern const char *data_ov001_021a90c8;
extern const char *data_ov001_021a90a4;
extern const char *data_ov001_021a90d8;
extern const char *data_ov001_021a90d4;
extern const char *data_ov001_021a90c4;
extern const char *data_ov001_021a90c0;
extern const char *data_ov001_021a94dc;
extern const char *data_ov001_021a94e0;
extern const char *data_ov001_021a94e4;
extern const char *data_ov001_021a94e8;
extern const char *data_ov001_021a94ec;
extern const char *data_ov001_021a94f0;
extern const char *data_ov001_021a94f4;
extern const char *data_ov001_021a94f8;
extern const char *data_ov001_021a94fc;
extern const char *data_ov001_021a9500;
extern const char *data_ov001_021a9504;
extern const char *data_ov001_021a9508;
extern const char *data_ov001_021a950c;
extern const char *data_ov001_021a9510;
extern s32 data_ov001_021a99e8;
extern u16 data_ov001_021a99ec[];
extern char data_ov001_021a94a4[];
extern char data_ov001_021a94b0[];
extern char data_ov001_021a94bc[];
extern char data_ov001_021a94d0[];
typedef struct TimeAttackTopMenu {
    /* 00 */ struct Unk02021dc8 *mTimeAttackTopMenuSNcer;
    /* 04 */ void *mTimeAttackTopMenuSBncl;
    /* 08 */ void *mTimeAttackTopMenuSBnbl;
    // one 0x40-byte record per cell of the Bncl member, built by func_02124ed0
    /* 0c */ Unk02124b1c *mTimeAttackTopMenuSTable;
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

extern Unk0217b498 *data_ov001_021a9bc0;
extern u16 data_ov001_021a9b94;
extern const char *data_ov001_021a90e8[5];
extern const char *data_ov001_021a92c8[5];

#include "00/code_021832d8.h"
