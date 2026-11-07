#pragma once

#include "types.h"

#include "code_0212bcac.h"
#include "code_0212c7a0.h" // NNSSndPlayer
#include "code_0212c7f0.h" // NNSSndStrmChannel
#include "code_0212c9d4.h" // CaptureParam, EffectInfo
#include "code_0201ea58.h" // Unk0201ea30
#include "Main/Unknown/code_02124094.h" // Unk02124b1c
#include "code_0212d214.h"
#include "Main/Unknown/types_02180728.h" // Unk02180728
#include "Main/Unknown/code_02105ec0.h" // Unk0217c7c4

typedef struct OSMessageQueue OSMessageQueue;

// Three words derived from a halfword.
typedef struct Unk0217d410_2c {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
} Unk0217d410_2c;

// 0x90 bytes.
typedef struct PaletteBlend {
    /* 00 */ s32 mCycleFrames;
    /* 04 */ BOOL mStopped;
    /* 08 */ u8 mPaletteIndex;
    /* 09 */ u8 mUnk_09;
    /* 0a */ u16 mUnk_0a[5];
    /* 14 */ u16 mUnk_14[4];
    /* 1c */ u16 mUnk_1c[4];
    /* 24 */ u16 mUnk_24[3];
    /* 2a */ u8 mUnk_2a[2];
    /* 2c */ Unk0217d410_2c mBlendFrom[4];
    /* 5c */ Unk0217d410_2c mBlendTo[4];
    /* 8c */ BOOL mFirstBlend;
} PaletteBlend;

// Object behind data_0217d358.
typedef struct Unk0217d358 {
    /* 00 */ u8 *mUnk_00;
} Unk0217d358;

struct Nclr;

// 0x18 bytes.
typedef struct KartIcon {
    /* 00 */ struct Ncgr *mNcgr;
    /* 04 */ struct Unk02021dc8 *mNcer;
    /* 08 */ struct Nclr *mNclrs[3];
    /* 14 */ void *mBncl;
} KartIcon;

struct NNSSndArc;
struct NNSSndStrmThread;
struct Ncgr;
struct Nclr;
struct Nscr;

// Member 0x8 of Wait; 0xc is added to it.
typedef struct Unk0217d354_08 {
    /* 00 */ u8 mUnk_00[0xc];
    /* 0c */ u8 *mUnk_0c;
} Unk0217d354_08;

typedef struct Wait {
    /* 00 */ struct Unk02021dc8 *mNcer;
    /* 04 */ void *mNcgr;
    /* 08 */ Unk0217d354_08 *mNclr;
    /* 0c */ void *mBncl;
    /* 10 */ struct Unk02021dc8 *mDestinationNcer;
    /* 14 */ struct Unk0201ea30 *mDestinationBncl;
    /* 18 */ u32 mDestinationBnclIndex;
    /* 1c */ u16 mUnk_1c;
    /* 20 */ s32 mUnk_20;
    /* 24 */ u16 mFrameIndex;
    /* 28 */ s32 mFrameIndexFrames;
} Wait;

typedef struct RecordVSErase {
    /* 00 */ u8 mRecordVSMNcgr[4];
    /* 04 */ struct Unk02021dc8 *mRecordVSMNcer;
    /* 08 */ Unk0201ea30 *mRecordVSMBncl;
    /* 0c */ struct Unk0201ea30 *mRecordVSMBnll;
    /* 10 */ struct Nscr *mRecordVSM02Nscr;
    /* 14 */ Unk02124b1c *mRecordVSMTable;
    /* 18 */ Unk0201ea30 *mRecordVSMTransientBncl;
    /* 1c */ struct Unk0201ea30 *mRecordVSMTransientBnll;
    /* 20 */ struct Nscr *mRecordVSM03Nscr;
    /* 24 */ Unk02124b1c *mRecordVSMTransientTable;
    /* 28 */ struct Ncgr *mRecordVSSNcgr;
    /* 2c */ struct Unk02021dc8 *mRecordVSSNcer;
    /* 30 */ Unk0201ea30 *mRecordVSSEraseBncl;
    /* 34 */ struct Unk0201ea30 *mRecordVSSEraseBnbl;
    /* 38 */ struct Unk0201ea30 *mRecordVSSEraseBnll;
    /* 3c */ Unk02124b1c *mRecordVSSEraseTable;
    /* 40 */ s32 mTransientDrawn;
    /* 44 */ struct Bmg *mCommonMessages;
    /* 48 */ struct Bmg *mRecordMessages;
    /* 4c */ void *mUnk_4c;
    /* 50 */ void *mHeap;
    /* 54 */ s32 mState;
    /* 58 */ s32 mNextState;
    /* 5c */ s32 mStateFrames;
    /* 60 */ s32 mBg0OffsetX;
    /* 64 */ s32 mBg0OffsetY;
    /* 68 */ s32 mBg1OffsetX;
    /* 6c */ s32 mBg1OffsetY;
    /* 70 */ s32 mBg3Offset;
    /* 74 */ s16 mIndex;
    /* 76 */ s16 mPageIndex;
    /* 78 */ s32 mPageDecrement;
    /* 7c */ s32 mIndexChangeTimer;
    /* 80 */ s16 mShownIndex;
    /* 82 */ u8 mUnk_82[2];
    /* 84 */ u32 mErased;
    /* 88 */ struct EmblemData *mUnk_88;
    /* 8c */ void *mUnk_8c;
    /* 90 */ s32 mOffsetTimers[2];
    /* 98 */ BOOL mUnk_98;
    /* 9c */ BOOL mUnk_9c;
    /* a0 */ s32 mUnk_a0;
} RecordVSErase;

typedef struct SelectCupNameM {
    /* 00 */ void *mNcgr;
    /* 04 */ struct Unk02021dc8 *mNcer;
    /* 08 */ void *mBncl;
} SelectCupNameM;

// 0x10 bytes.
typedef struct CupMark {
    /* 00 */ struct Ncgr *mNcgr;
    /* 04 */ struct Unk02021dc8 *mNcer;
    /* 08 */ struct Nclr *mNclr;
    /* 0c */ struct Unk0201ea30 *mBncl;
} CupMark;

// Object at data_0217d070 (0x14 bytes); func_0210d740 fills it. data_0217d07c names its member 0x0c.
typedef struct Unk0217d070 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ void *mUnk_04;
    /* 08 */ u8 mUnk_08;
    /* 09 */ u8 mUnk_09;
    /* 0a */ u8 mUnk_0a;
    /* 0b */ u8 mUnk_0b;
    /* 0c */ NNSSndSeqPlayer *mUnk_0c;
    /* 10 */ NNSSndSeqPlayer *mUnk_10;
} Unk0217d070;

// Object at data_0217d084 (0x1c bytes); func_0210dc60 stores its second argument at 0x00.
typedef struct Unk0217d084 {
    /* 00 */ Unk0217d070 *mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ u32 mUnk_0c;
    /* 10 */ u32 mUnk_10;
    /* 14 */ u32 mUnk_14;
    /* 18 */ NNSSndSeqPlayer **mUnk_18;
} Unk0217d084;

// Object at data_0217d32c (0x10 bytes); mUnk_08 points to a row of six words.
typedef struct Unk0217d32c {
    /* 00 */ s32 mUnk_00;
    /* 04 */ NNSSndHeap *mUnk_04;
    /* 08 */ u32 *mUnk_08;
    /* 0c */ u32 mUnk_0c;
} Unk0217d32c;

// Object behind gRecordVS.
typedef struct RecordVS {
    /* 00 */ struct Ncgr *mRecordVSMNcgr;
    /* 04 */ struct Unk02021dc8 *mRecordVSMNcer;
    /* 08 */ Unk0201ea30 *mRecordVSMBncl;
    /* 0c */ struct Unk0201ea30 *mRecordVSMBnll;
    /* 10 */ struct Nscr *mRecordVSM02Nscr;
    // Object table of the main part of the screen (files mRecordVSMBncl / mRecordVSMBnll).
    /* 14 */ Unk02124b1c *mRecordVSMTable;
    /* 18 */ Unk0201ea30 *mRecordVSMTransientBncl;
    /* 1c */ struct Unk0201ea30 *mRecordVSMTransientBnll;
    /* 20 */ struct Nscr *mRecordVSM03Nscr;
    // Object table of the transient part of the main screen (files mRecordVSMTransientBncl / mRecordVSMTransientBnll).
    /* 24 */ Unk02124b1c *mRecordVSMTransientTable;
    /* 28 */ struct Ncgr *mRecordVSSNcgr;
    /* 2c */ struct Unk02021dc8 *mRecordVSSNcer;
    /* 30 */ Unk0201ea30 *mRecordVSSBncl;
    /* 34 */ Unk0201ea30 *mRecordVSSBnbl;
    /* 38 */ struct Unk0201ea30 *mRecordVSSBnll;
    // Object table of the sub screen (files mRecordVSSBncl / mRecordVSSBnll).
    /* 3c */ Unk02124b1c *mRecordVSSTable;
    /* 40 */ s32 mShowsFriendKey;
    /* 44 */ struct Bmg *mRecordMessages;
    /* 48 */ void *mHeap;
    /* 4c */ s32 mState;
    /* 50 */ s32 mNextState;
    /* 54 */ s32 mStateFrames; /* counts only in states 1, 2, 5 to 11 */
    // X half of reg_G2_BG0OFS (0x04000010, main engine BG0), stored negated
    /* 58 */ s32 mBg0OffsetX;
    // Y half of reg_G2_BG0OFS (0x04000010, main engine BG0), stored negated
    /* 5c */ s32 mBg0OffsetY;
    // X half of reg_G2_BG1OFS (0x04000014, main engine BG1), stored negated
    /* 60 */ s32 mBg1OffsetX;
    // Y half of reg_G2_BG1OFS (0x04000014, main engine BG1), stored negated
    /* 64 */ s32 mBg1OffsetY;
    // Position of the highlight among the six items: 0 to 4 are the records of the page, 5 the extra item; -1 can be
    // stored (count % 5 - 1 in RefreshRecordVSPage).
    /* 68 */ s16 mIndex;
    /* 6a */ s16 mPageIndex;
    /* 6c */ s32 mPageDecrement;
    // Counts 7 down to 0 after mIndex changed: AdvanceRecordVSIndexChange sets 7 when mIndex differs from mShownIndex,
    // rebuilds the page text through PrintRecordVSShownRecord at 7 and moves the objects while it runs;
    // IsRecordVSIndexChangeRunning tells whether it is non-zero.
    /* 70 */ s32 mIndexChangeTimer;
    // mIndex the page text was last built for: PrintRecordVSShownRecord builds the text of the record mShownIndex, and
    // AdvanceRecordVSIndexChange starts mIndexChangeTimer when mIndex differs from it.
    /* 74 */ s16 mShownIndex;
    /* 76 */ u8 mUnk_76[2];
    /* 78 */ struct EmblemData *mEmblem;
    /* 7c */ void *mEmblemConverted;
    /* 80 */ s32 mOffsetTimers[2];
    /* 88 */ BOOL mUnk_88;
    /* 8c */ BOOL mUnk_8c;
    /* 90 */ s32 mUnk_90;
} RecordVS;

// Object behind gSelectCupGrid: the screen that picks one of eight cups, laid out as two rows of four (a direction key
// or a touch moves mIndex to a neighbour cup that is enabled). Choosing stores the cup and the first course of that cup
// in the record behind gRaceSetupCopy (func_021185ec); SelectCupCourse then picks one of the four courses of the stored
// cup. Allocated by InitSelectCupGrid, freed by ReleaseSelectCupGrid; mMode is 0, 1 or 2 to 4 by the screen that opened
// it.
typedef struct SelectCupGrid {
    /* 00 */ struct Unk02021dc8 *mSelectCupMNcer;
    /* 04 */ Unk0201ea30 *mSelectCupMBncl;
    /* 08 */ struct Unk0201ea30 *mSelectCupMBnll;
    /* 0c */ struct Unk02021dc8 *mSelectCupSNcer;
    /* 10 */ struct Unk0201ea30 *mSelectCupSBncl;
    /* 14 */ Unk0201ea30 *mSelectCupSBnbl;
    /* 18 */ Unk02124b1c *mSelectCupMTable;
    /* 1c */ Unk02124b1c *mSelectCupSTable;
    /* 20 */ void *mUnk_20;
    /* 24 */ struct Bmg *mCommonMessages;
    /* 28 */ struct Bmg *mMenuMessages;
    /* 2c */ void *mHeap;
    /* 30 */ s32 mState;
    /* 34 */ s32 mNextState;
    /* 38 */ s32 mStateFrames;
    /* 3c */ s32 mMode;
    // Negated and shifted into the upper half-word of the BG0 offset register.
    /* 40 */ s32 mBg0Offset;
    /* 44 */ s32 mIndex;
    // One entry per cup: non-zero when the cup can be chosen, filled once at InitSelectCupGrid from
    // GetSelectCupGridCupEnabled; a disabled cup shows its other cells, plays the error sound when touched and is
    // skipped by the direction keys.
    /* 48 */ s32 mCupsEnabled[8];
    /* 68 */ BOOL mUnk_68;
    // Counts 7 down to 0 after mIndex changed: AdvanceSelectCupGridIndexChange sets 7 when mIndex differs from
    // mShownIndex, rebuilds the cells at 7 and moves them while it runs; IsSelectCupGridIndexChangeRunning tells
    // whether it is non-zero.
    /* 6c */ s32 mIndexChangeTimer;
    // mIndex that the cells were last built for: AdvanceSelectCupGridIndexChange copies mIndex here when it rebuilds
    // them and starts mIndexChangeTimer when mIndex differs from it.
    /* 70 */ s32 mShownIndex;
    // Calls of AdvanceSelectCupGridShownCourse since the shown course changed; at 0x4b the next course is shown and it
    // restarts at 0.
    /* 74 */ s32 mShownCourseFrames;
    // Position 0 to 3 of the course of the cup at mIndex whose picture is shown: indexes data_0215ca1c[mIndex];
    // AdvanceSelectCupGrid also shows the cell of that position differently from the other three.
    /* 78 */ s16 mShownCourseIndex;
    /* 7a */ u8 mUnk_7a[2];
    // Set when the cup picture was asked for; AdvanceSelectCupGrid queues its data once it is ready.
    /* 7c */ BOOL mCupPicturePending;
    /* 80 */ void *mUnk_80;
    /* 84 */ void *mUnk_84;
    /* 88 */ s32 mResult;
} SelectCupGrid;

// Object behind gSelectCupCourse.
typedef struct SelectCupCourse {
    /* 00 */ struct Unk02021dc8 *mSelectCupCourseMNcer;
    /* 04 */ Unk0201ea30 *mSelectCupCourseTaOrVsMBncl; /* ta_m file when mMode == 0, vs_m otherwise */
    /* 08 */ struct Unk0201ea30 *mSelectCupCourseTaOrVsMBnll; /* ta_m file when mMode == 0, vs_m otherwise */
    /* 0c */ struct Unk02021dc8 *mSelectCupMNcer;
    /* 10 */ Unk0201ea30 *mSelectCupMBncl;
    /* 14 */ Unk0201ea30 *mSelectCupMBnbl;
    /* 18 */ struct Unk0201ea30 *mSelectCupMBnll;
    // one 0x40-byte record per cell of the Bncl (plus Bnll) members, built by func_02124ed0; assigned only when *(vu16
    // *) 0x027ffc40 != 2
    /* 1c */ Unk02124b1c *mSelectCupCourseTaOrVsMTable;
    // one 0x40-byte record per cell of the Bncl (plus Bnll) members, built by func_02124ed0; assigned only when *(vu16
    // *) 0x027ffc40 != 2
    /* 20 */ Unk02124b1c *mSelectCupMTable;
    /* 24 */ void *mUnk_24;
    /* 28 */ struct Bmg *mCommonMessages;
    /* 2c */ void *mGhostMessages;
    /* 30 */ void *mHeap;
    /* 34 */ s32 mState;
    /* 38 */ s32 mNextState;
    /* 3c */ s32 mStateFrames; /* counts only in states 1, 4, 5, 7, 8 */
    /* 40 */ s32 mMode;
    /* 44 */ s32 mBg0Offset;
    /* 48 */ s32 mBg3Offset; /* the sub engine's BG3 offset (0x0400101c); mBg0Offset is the main engine's */
    /* 4c */ u8 mUnk_4c[4];
    /* 50 */ s16 mIndex; /* 0..3 position among the four courses of the cup: the course is data_0215cbec[row][mIndex] */
    /* 52 */ u8 mUnk_52[2];
    /* 54 */ BOOL mUnk_54;
    // Counts 7 down to 0 after mIndex changed: func_02119d78 sets 7 when mIndex differs from mShownIndex,
    // rebuilds the page through func_02119e88 at 7 and moves the objects while it runs; func_02119dfc tells whether it
    // is non-zero.
    /* 58 */ s32 mIndexChangeTimer;
    // mIndex the page was last built for: func_02119d78 copies mIndex here when func_02119e88 rebuilds the page,
    // and starts mIndexChangeTimer when mIndex differs from it.
    /* 5c */ s16 mShownIndex;
    /* 5e */ u8 mUnk_5e[2];
    // Set when the cup picture was asked for; the step queues its data once it is ready.
    /* 60 */ BOOL mCupPicturePending;
    /* 64 */ void *mUnk_64;
    /* 68 */ void *mUnk_68;
    /* 6c */ s32 mResult;
} SelectCupCourse;

// Option of the rules row with a race counter (mRaceCount).
#define SELECT_RACE_RULE_RACE 1
// Option of the rules row with a win counter (mWinCount).
#define SELECT_RACE_RULE_WIN 0
// Option of the rules row with no counter.
#define SELECT_RACE_RULE_FREE 2
// Object behind gSelectRaceRule.
typedef struct SelectRaceRule {
    /* 00 */ struct Unk02021dc8 *mNcer;
    /* 04 */ Unk0201ea30 *mBncl;
    /* 08 */ Unk0201ea30 *mBnbl;
    /* 0c */ struct Unk0201ea30 *mBnll;
    /* 10 */ struct Nclr *mNclr; /* the _o palette */
    // Object table allocated for the bncl / bnll of this screen.
    /* 14 */ Unk02124b1c *mTable;
    // Messages of common.bmg.
    /* 18 */ struct Bmg *mCommonMessages;
    // Messages of rule.bmg.
    /* 1c */ struct Bmg *mRuleMessages;
    /* 20 */ struct Nscr *mNscr; /* multi_simple_s (mMode == 3) or s_menu, two files */
    /* 24 */ void *mUnk_24;
    /* 28 */ void *mHeap;
    /* 2c */ s32 mMode;
    /* 30 */ s32 mState;
    /* 34 */ s32 mNextState;
    /* 38 */ s32 mStateFrames;
    // Set to 6 when the row's value is stepped ([row][0] down, [row][1] up), counted down each step; moves the row's
    // pair of objects.
    /* 3c */ s16 mRowChangeTimers[5][2];
    // Same shape for row 3 ([0][0] count down, [0][1] count up) and row 4 ([1][0] and [1][1] by the team a player lands
    // in).
    /* 50 */ s16 mUnk_50[2][2];
    // Vertical shift in lines of the whole layout, 0 or -0x1c by mode; added to the positions of the objects and taken
    // off the touch y.
    /* 58 */ s16 mOffsetY;
    /* 5a */ u8 mUnk_5a[0x02];
    // Offset stored negated into the sub engine's BG3 offset register.
    /* 5c */ s32 mBg3Offset;
    // Row (0 to 4) the highlight is on; the value of row n is mRowValues[n].
    /* 60 */ s32 mRow;
    // Row at the start of the step, to see whether it changed.
    /* 64 */ s32 mPrevRow;
    // Value of each row, 0 up to the row's count minus 1; stepped up and down with wrap.
    /* 68 */ s32 mRowValues[5];
    // Non-zero while the highlight is on the button below the rows instead of on a row.
    /* 7c */ s32 mOnButton;
    // mOnButton at the start of the step.
    /* 80 */ s32 mPrevOnButton;
    // Set to 0 when the button is pressed while it is already highlighted, back to 1 five calls into state 4; decides
    // which of the button's two objects shows.
    /* 84 */ u32 mUnk_84;
    // Count of the win option of row 3, kept from 1 to 10.
    /* 88 */ s16 mWinCount;
    // Count of the race option of row 3, kept from 1 to 0x20.
    /* 8a */ s16 mRaceCount;
    // Team index of each of the 8 entries.
    /* 8c */ u32 mPlayerTeamIndices[8];
    // Per team: how many of the first entries (given player kind 0 in the setup copy) are in it.
    /* ac */ u16 mUnk_ac[2];
    // Per team: how many of the entries after the first ones are in it; counted into a team's size only while row 1 is
    // not 0.
    /* b0 */ u16 mUnk_b0[2];
    /* b4 */ void *mUnk_b4;
    // Result AdvanceSelectRaceRule returns in state 8 once the state has run 10 calls: 1 or 2; 0 until set.
    /* b8 */ vu32 mResult;
} SelectRaceRule;

// 0x10 bytes.
typedef struct TrophyIcon {
    /* 00 */ struct Ncgr *mNcgr;
    /* 04 */ struct Unk02021dc8 *mNcer;
    /* 08 */ struct Nclr *mNclr;
    /* 0c */ void *mBncl;
} TrophyIcon;

// Object behind data_0217d380 (0x28 bytes), allocated by func_0211f4b0.
typedef struct Unk0217d380 {
    /* 00 */ struct Unk02021dc8 *mNcer;
    /* 04 */ Unk0201ea30 *mBncl;
    /* 08 */ u8 mUnk_08[0x4];
    /* 0c */ struct Unk0201ea30 *mBnll;
    /* 10 */ Unk02124b1c *mTable;
    /* 14 */ void *mCommonMessages;
    /* 18 */ void *mUnk_18;
    /* 1c */ s32 mState;
    /* 20 */ s32 mNextState;
    /* 24 */ s32 mStateFrames;
} Unk0217d380;

// Object at data_0217d244 (0x10 bytes).
typedef struct Unk0217d244 {
    // 0: normal; 1: volume target 0; 2: volume target full.
    /* 00 */ s32 mVolumeOverride;
    /* 04 */ s32 mPitchAngle;
    // Bit 2 is set while the selected Kart is small from the Thunder item.
    /* 08 */ s32 mFlags;
    /* 0c */ u32 mKartNear;
} Unk0217d244;

// Object at gSeqQueue.
typedef struct SeqQueue {
    // 14 queued pairs; 13 in mPairNo and 2 in mPairSide mark an empty entry.
    /* 00 */ s32 mPairNo[14];
    /* 38 */ s32 mPairSide[14];
    /* 70 */ s32 mWriteIndex;
    /* 74 */ s32 mReadIndex;
    /* 78 */ s32 mNextStartTimer;
} SeqQueue;

// Object behind data_0217d374, allocated by func_0211e480.
typedef struct Unk0217d374 {
    /* 00 */ u8 *mUnk_00;
    /* 04 */ u8 *mUnk_04;
    /* 08 */ u8 *mUnk_08;
    /* 0c */ u32 mUnk_0c;
    /* 10 */ s16 mUnk_10;
} Unk0217d374;

typedef struct SelectCupM {
    /* 00 */ struct Unk02021dc8 *mMainNcer;
    /* 04 */ Unk0201ea30 *mMainBncl;
    /* 08 */ struct Unk0201ea30 *mMainBnll;
    /* 0c */ struct Unk02021dc8 *mSubNcer;
    /* 10 */ Unk0201ea30 *mSubBncl;
    /* 14 */ struct Unk0201ea30 *mSubBnll;
    /* 18 */ Unk02124b1c *mMainTable;
    /* 1c */ Unk02124b1c *mSubTable;
    /* 20 */ void *mUnk_20;
    /* 24 */ struct Bmg *mCommonMessages;
    /* 28 */ void *mHeap;
    /* 2c */ s32 mState;
    /* 30 */ s32 mNextState;
    /* 34 */ s32 mStateFrames;
    /* 38 */ BOOL mCupPicturePending;
    /* 3c */ s32 mBg0Offset;
    /* 40 */ s32 mBg3Offset;
    /* 44 */ u8 mUnk_44[0x04];
    /* 48 */ void *mUnk_48;
    /* 4c */ void *mUnk_4c;
    /* 50 */ s32 mUnk_50;
} SelectCupM;

// One slot number of the table.
typedef struct RecordListEntry {
    /* 00 */ u16 mUnk_00;
} RecordListEntry;

// The used slots in display order, with the emblem block and the emblem2.bin picture.
typedef struct RecordList {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u8 mUnk_02[2];
    /* 04 */ RecordListEntry *mUnk_04;
    /* 08 */ struct EmblemBlock *mEmblemBlock;
    /* 0c */ void *mUnk_0c;
} RecordList;

// Object behind data_0217d3ec: 0x814 bytes allocated by func_02125de0.
typedef struct Unk0217d3ec {
    /* 000 */ BOOL mUnk_00;
    /* 004 */ BOOL mUnk_04;
    /* 008 */ BOOL mUnk_08;
    /* 00c */ s32 mBackScreenKind;
    /* 010 */ u16 mBackScreenSNscrCopy[0x400];
    /* 810 */ s32 mUnk_810;
} Unk0217d3ec;

// Objects of 0x20 bytes set up by NNS_G2dCharCanvasInitForBG; the word at 0x18 is called with the object and a value.
typedef struct Unk0217d3f0_2098 {
    /* 00 */ u8 mUnk_00[0x18];
    /* 18 */ void (*mUnk_18)(struct Unk0217d3f0_2098 *, s32);
    /* 1c */ u32 mUnk_1c;
} Unk0217d3f0_2098;

// Objects of 0x10 bytes passed first to func_0212583c; member 0x00 points to one Unk0217d3f0_2098.
typedef struct Unk0217d3f0_2178 {
    /* 00 */ Unk0217d3f0_2098 *mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ u32 mUnk_0c;
} Unk0217d3f0_2178;

// Object behind gTxtSystem: 0x2278 bytes allocated by InitTxtSystem.
typedef struct TxtSystem {
    /* 0000 */ u32 mState;
    /* 0004 */ u32 mNextState;
    /* 0008 */ u32 mPrevState;
    /* 000c */ s32 mStateFrames;
    /* 0010 */ s32 mUnk_10;
    /* 0014 */ s32 mAnimFrameIndex;
    /* 0018 */ u32 mAnimVisible[2];
    /* 0020 */ u32 mAnimRequested[2];
    /* 0028 */ s32 mExtraCanvasCount;
    /* 002c */ u32 mSelectedIndex;
    /* 0030 */ u32 mUnk_30;
    /* 0034 */ u32 mOpenRequested;
    /* 0038 */ u32 mCloseRequested;
    /* 003c */ u32 mOpenFromIndex;
    /* 0040 */ u32 mCloseToIndex;
    /* 0044 */ u32 mUnk_44;
    /* 0048 */ u32 mUnk_48;
    /* 004c */ u32 mUnk_4c;
    /* 0050 */ u32 mEnabled;
    /* 0054 */ u16 mMainScreenBuffer[0x800];
    /* 1054 */ u16 mSubScreenBuffer[0x800];
    /* 2054 */ s32 mBgOffset[2];
    /* 205c */ s32 mBgOffsetAtOpen[2];
    /* 2064 */ s32 mBgOffsetRequested[2];
    /* 206c */ s32 mBlendPlanesEnabled[2];
    /* 2074 */ u32 mBlendPlanesRequested[2];
    /* 207c */ s32 mBrightness;
    /* 2080 */ u32 mBlendPlanes[2];
    /* 2088 */ u32 mBlendEv1[2];
    /* 2090 */ u32 mBlendEv2[2];
    /* 2098 */ Unk0217d3f0_2098 mCharCanvases[7];
    /* 2178 */ Unk0217d3f0_2178 mUnk_2178[7];
    /* 21e8 */ void *mCharBuffers[7];
    /* 2204 */ u32 mCanvasInUse[7];
    /* 2220 */ u32 mCanvasFileCharIndex[7];
    /* 223c */ u32 mB01CharIndex[2];
    /* 2244 */ u16 mUnk_2244;
    /* 2246 */ u16 mUnk_2246;
    /* 2248 */ u32 mMode;
    /* 224c */ u32 mUnk_224c;
    /* 2250 */ s32 mInputSoundId;
    /* 2254 */ s32 mSecondInputSoundId;
    /* 2258 */ s32 mOpenSoundId;
    /* 225c */ struct Nscr *mBgNscrs[7];
} TxtSystem;

typedef struct SelectChoises {
    /* 000 */ u32 mEnabled;
    /* 004 */ s32 mState;
    /* 008 */ u32 mNextState;
    /* 00c */ u32 mState2Frames;
    /* 010 */ s32 mToggleFrames;
    /* 014 */ u32 mToggleOn;
    /* 018 */ u32 mIndex;
    /* 01c */ u32 mDone;
    /* 020 */ u32 mIndexNone;
    /* 024 */ u32 mState1Requested;
    /* 028 */ u32 mState0Requested;
    /* 02c */ u16 mNscrCopy[0x400];
    /* 82c */ u32 mToggleOnFirstTile;
    /* 830 */ u32 mToggleOffFirstTile;
    /* 834 */ Unk0217d3f0_2098 mCharCanvases[2];
    /* 874 */ Unk0217d3f0_2178 mUnk_874[2];
    /* 894 */ u8 *mCharBuffers[2];
    /* 89c */ s32 mFirstTileIndex;
    /* 8a0 */ u32 mUseCharBuffers;
    // Non-zero when the display bit was set at init; also gates the choice sounds.
    /* 8a4 */ u32 mDisplayBitOn;
    /* 8a8 */ s32 mSoundIds[2];
    /* 8b0 */ s32 mIndexNoneSoundId;
} SelectChoises;

// Object behind gSelectReturn: 0x828 bytes allocated by InitSelectReturn.
typedef struct SelectReturn {
    /* 000 */ BOOL mEnabled; /* only ever set to 1 by InitSelectReturn; the off path does not run in this build */
    /* 004 */ s32 mState;
    /* 008 */ s32 mNextState;
    /* 00c */ s32 mStateFrames; /* counts only in states 1, 3, 4 */
    /* 010 */ u16 mScreenMapCopy[0x400];
    /* 810 */ BOOL mState1Requested;
    /* 814 */ BOOL mState3Requested;
    /* 818 */ BOOL mState4Requested;
    /* 81c */ s32 mBg2Offset;
    /* 820 */ BOOL mDisplayBitOn;
    /* 824 */ s32 mSoundId;
} SelectReturn;

// Records of 8 bytes: 0x80 of them start an Unk0217d3fc_00, and two are at member 0x10c of Unk0217d404
// (func_0212a920 copies 6 bytes of a record into one of those).
typedef struct Unk0217d3fc_00_00 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u16 mUnk_04;
    /* 06 */ u8 mUnk_06[2];
} Unk0217d3fc_00_00;

// Objects of 0x404 bytes; two of them make the object behind data_0217d3fc.
typedef struct Unk0217d3fc_00 {
    /* 000 */ Unk0217d3fc_00_00 mUnk_00[0x80];
    /* 400 */ u16 mUnk_400;
    /* 402 */ u16 mUnk_402;
} Unk0217d3fc_00;

// Object behind data_0217d3fc: 0x808 bytes allocated by InitKeyboardScene.
typedef struct Unk0217d3fc {
    /* 000 */ Unk0217d3fc_00 mUnk_00;
    /* 404 */ Unk0217d3fc_00 mUnk_404;
} Unk0217d3fc;

// Objects of 0x18 bytes, three of them at 0x2c of Keyboard: 0 and 1 are read as halfword strings, 2 also as the
// fields at 0x10, 0x14 and 0x16.
typedef struct Unk0217d400_2c {
    /* 00 */ union {
        u16 mUnk_00[12];
        struct {
            /* 00 */ u16 mUnk_00_0[8];
            /* 10 */ s32 mUnk_10;
            // Mode of the screen as passed in by the scene (0xc, 7 or 0xb); element 2 of Keyboard.mUnk_2c only: in
            // element 0 these bytes are character 10 of the text.
            /* 14 */ s16 mMode;
            // Scene to run when the keyboard ends, -1 until set, read by GetKeyboardNextScene through the raw offset
            // 114; element 2 of Keyboard.mUnk_2c only: in element 0 these bytes are character 11 of the text.
            /* 16 */ s16 mNextScene;
        };
    };
} Unk0217d400_2c;

// Object behind gKeyboard: 0xc4 bytes allocated by InitKeyboard.
typedef struct Keyboard {
    // Heap the screen's objects are allocated from.
    /* 00 */ void *mHeap;
    // Which of the two sets (background files, text records, cell counts, object tables) the screen works on, 0 or 1;
    // set from the mode argument at start, to 1 in state 3 and back to 0 in state 8.
    /* 04 */ s32 mKind;
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mState;
    /* 10 */ s32 mNextState;
    /* 14 */ s32 mUnk_14[2];
    // Per button: non-zero while the button accepts its input; button 0 needs text entered.
    /* 1c */ s32 mButtonEnabled[2];
    /* 24 */ BOOL mUnk_24;
    // Calls spent in the current state: counted up by the handlers of states 1, 3, 4, 6, 8, 9 and 11, and by state 10
    // only while func_02125f54 or func_02125f88 returns non-zero; zeroed by the handler that leaves; the slide states
    // hold it at 0xf.
    /* 28 */ s32 mStateFrames;
    /* 2c */ Unk0217d400_2c mUnk_2c[3];
    // Object tables of the keyboard, indexed by kind and by the buffer they are drawn to.
    /* 74 */ Unk02124b1c *mTables[2][2];
    // Vertical shift in lines of the whole screen (0xc0 = slid out of view, 0 = in place); also stored negated into the
    // vertical half of the sub engine's BG3 offset.
    /* 84 */ s16 mOffsetY;
    /* 86 */ s16 mUnk_86[2][2];
    /* 8e */ u8 mUnk_8e[2];
    /* 90 */ struct Unk02021dc8 *mNcer;
    /* 94 */ struct Ncgr *mNcgr;
    /* 98 */ struct Nclr *mNclr;
    /* 9c */ Unk0201ea30 *mBncls[2];
    /* a4 */ Unk0201ea30 *mBnbls[2];
    /* ac */ void *mBnlls[2];
    /* b4 */ struct Nscr *mNscrs[2]; /* [0] flame02, [1] flame01 */
    /* bc */ void *mUnk_bc;
    // Messages of common.bmg.
    /* c0 */ struct Bmg *mCommonMessages;
} Keyboard;

// Elements of 0x20 bytes at member 0x14 of Ncgr.
typedef struct Unk0217d404_bc {
    /* 00 */ u8 mUnk_00[0x20];
} Unk0217d404_bc;

typedef struct Unk0217d404_28 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
} Unk0217d404_28;

// Object behind data_0217d404: 0x11c bytes allocated by func_0212abdc.
typedef struct Unk0217d404 {
    /* 000 */ s32 mUnk_000[5];
    /* 014 */ s32 mUnk_014[2];
    /* 01c */ s32 mUnk_01c[2];
    /* 024 */ s32 mUnk_024;
    /* 028 */ Unk0217d404_28 mUnk_028[2];
    /* 038 */ Unk0217d3fc_00 *mUnk_038;
    /* 03c */ u8 mUnk_03c[0x20];
    /* 05c */ u8 mUnk_05c[0x60];
    /* 0bc */ Unk0217d404_bc *mUnk_0bc[5][4];
    /* 10c */ Unk0217d3fc_00_00 mUnk_10c[2];
} Unk0217d404;

// Object behind data_0217d408: 0x1a44 bytes allocated by func_0212b158; the 0x20 bytes at 0x14 are set up by
// NNS_G2dCharCanvasInitForBG.
typedef struct Unk0217d408 {
    /* 0000 */ s32 mUnk_0000;
    /* 0004 */ s32 mUnk_0004;
    /* 0008 */ void *mUnk_0008;
    /* 000c */ BOOL mUnk_000c;
    /* 0010 */ s32 mUnk_0010;
    /* 0014 */ u8 mUnk_0014[0x20];
    /* 0034 */ Unk02180728 mUnk_0034;
    /* 0044 */ u16 mUnk_0044[0xa00];
    /* 1444 */ u16 mUnk_1444[0x300];
} Unk0217d408;

// Records of 8 bytes in the stream at member 0x18 of StaffRollText.
typedef struct Unk0217d40c_18 {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u8 mUnk_02;
    /* 03 */ u8 mUnk_03;
    /* 04 */ u16 mUnk_04;
    /* 06 */ u16 mUnk_06;
} Unk0217d40c_18;

// 0x85c bytes; the 0x20 bytes at 0x20 are set up by NNS_G2dCharCanvasInitForBG.
typedef struct StaffRollText {
    /* 000 */ s32 mState;
    /* 004 */ s32 mNextState;
    /* 008 */ s32 mScrollYFixed;
    /* 00c */ s32 mScrollYPerFrame;
    /* 010 */ s32 mNextReadScrollY;
    /* 014 */ s32 mScrollYRemaining;
    /* 018 */ u8 *mTextPosition;
    /* 01c */ s8 mUnk_01c;
    /* 01d */ u8 mUnk_01d[3];
    /* 020 */ u8 mUnk_020[0x20];
    /* 040 */ Unk02180728 mUnk_040;
    /* 050 */ u8 mUnk_050[0x800];
    /* 850 */ s8 mUnk_850;
    /* 851 */ u8 mUnk_851[3];
    /* 854 */ s32 mUnk_854;
    /* 858 */ void *mHeap;
} StaffRollText;

typedef struct Unk0210bcf4 Unk0210bcf4;

// Objects whose layout isn't known yet.
extern s32 (*data_0217d014)(Unk0210bcf4 *);
extern u32 (*data_0217d018)(Unk0210bcf4 *);
extern s32 (*data_0217d01c)(Unk0210bcf4 *);
extern NNSFndList data_0217d028;
extern u32 data_0217d064;
extern s32 data_0217d1f4;
extern s32 data_0217d20c;
extern s32 data_0217d21c;
extern u32 gAnySeqVariableEnabled;
extern Unk0217d244 data_0217d244;
extern struct Unk0217d344 *data_0217d344;
extern RecordVSErase *gRecordVSErase;
extern Wait *gWait;
extern Unk0217d358 *data_0217d358;
extern KartIcon *gKartIcon;
extern SelectRaceRule *gSelectRaceRule;
extern SelectCupNameM *gSelectCupNameM;
extern CupMark *gCupMark;
extern Unk0217d374 *data_0217d374;
extern SelectCupM *gSelectCupM;
extern TrophyIcon *gTrophyIcon;
extern Unk0217d380 *data_0217d380;
extern char gKartFilterString[0x64];
extern Unk0217d3ec *data_0217d3ec;
extern TxtSystem *gTxtSystem;
extern SelectChoises *gSelectChoises;
extern SelectReturn *gSelectReturn;
extern Unk0217d3fc *data_0217d3fc;
extern Keyboard *gKeyboard;
extern Unk0217d408 *data_0217d408;
extern u32 data_0217d1f0;
extern s32 gLapProgressSoundGaps[];
extern s32 data_0217d320;
extern s32 data_0217d324;
extern s32 data_0217d328;
extern StaffRollText *gStaffRollText;
extern u32 data_0217dda8;
extern CaptureParam data_0217ddd0;
extern NNSSndSeqPlayer data_0217d45c[16];
extern NNSSndPlayer data_0217d89c[];
extern NNSFndList data_0217dd1c;
extern NNSSndStrmChannel data_0217dd28[];
extern s32 data_0217ddac;
extern OSMessageQueue data_0217ddb0;
extern EffectInfo data_0217de24[8];
extern struct NNSSndArc *data_0217dec4;
extern s32 data_0217d1e8;
extern s32 data_0217d1ec;
extern s32 data_0217d1f8;
extern s32 data_0217d200;
extern s32 data_0217d208;
extern u8 data_0217d1e0;
extern u8 data_0217d1e4;
extern s32 data_0217d1fc;
extern u32 data_0217d204;
extern s32 data_0217d210;
extern s32 data_0217d214;
extern volatile s32 data_0217d218;
extern s32 data_0217d224[2];
extern SeqQueue gSeqQueue;
extern s32 data_0217d2dc[];
extern void *data_0217d33c;
extern void *data_0217d340;
extern Unk0217d404 *data_0217d404;
extern PaletteBlend *gPaletteBlend;
extern struct NNSSndStrmThread *data_0217df04;
extern u8 data_0217df08[];
extern NNSSndHeap *data_0217d130;
extern Unk0217d070 data_0217d070;
// The member at 0x0c of data_0217d070, addressed through a pool word of its own.
extern NNSSndSeqPlayer *data_0217d07c;
extern Unk0217d084 data_0217d084;
extern struct NNSSndArc data_0217d0a0;
extern Unk0217d32c data_0217d32c;
extern RecordVS *gRecordVS;
extern RecordList *gRecordList;
// Pointer to the cup chooser object: set by InitSelectCupGrid, cleared by ReleaseSelectCupGrid.
extern SelectCupGrid *gSelectCupGrid;
extern SelectCupCourse *gSelectCupCourse;
extern u32 data_0217d1bc;
extern u32 gSeqVariableEnabled[];
extern u32 data_0217d010[];
extern u32 data_0217d024[];
extern Unk0217c7c4 data_0217d034;
extern NNSFndList data_0217d048[];
extern NNSFndList data_0217d054;
extern u32 data_0217d020;
extern void *data_0217d06c;
