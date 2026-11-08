#pragma once

#include "types.h"
#include "00/code_02181f98.h"

typedef struct EndingScene {
    /* 000 */ s32 mState;
    /* 004 */ s32 mNextState;
    /* 008 */ s32 mUnk_008;
    /* 00c */ s32 mKind;
    /* 010 */ void *mHeap;
    /* 014 */ s16 mNextScene;
    /* 016 */ u8 mUnk_016[0x2];
    /* 018 */ BOOL mIndex1Queued;
    /* 01c */ void *mUnk_01c;
    /* 020 */ LayoutTableEntry *mEndingThanksTable;
    /* 024 */ struct Unk02021dc8 *mThanksYouMNcer;
    /* 028 */ u8 mUnk_028[0x4];
    /* 02c */ Nclr *mThanksYouMO00Nclr;
    /* 030 */ struct Unk0201ea30 *mEndingThanksBncl;
    /* 034 */ struct Unk0201ea30 *mEndingThanksBnll;
    /* 038 */ Ncgr *mLogoEndMarioKartMBAndThanksYouMBNcgrs[2];
    /* 040 */ Nscr *mLogoEndMarioKartMBgAndThanksYouMBgNscrs[2];
    /* 048 */ Nclr *mLogoEndMarioKartMBAndThanksYouMBNclrs[2];
    /* 050 */ Ncgr *mEndAllRightsReservedSBAndLogoEndNintendoSBNcgrs[2];
    /* 058 */ Nscr *mEndAllRightsReservedSBgAndLogoEndNintendoSBgNscrs[2];
    /* 060 */ Nclr *mEndAllRightsReservedSBAndLogoEndNintendoSBNclrs[2];
    /* 068 */ u8 mMainOam[0x404];
    /* 46c */ struct Bmg *mCommonMessages;
} EndingScene;

// Objects whose layout isn't known yet.
// Object behind gMissionRunLVsel.
typedef struct MissionRunLVsel {
    /* 00 */ struct Unk02021dc8 *mMissionRunLVselSNcer;
    // mr/Mission_run_LVsel_s_7.bncl when mUnk_4a >= 6, else _s_6; Bnbl and Bnll follow the same test
    // (mUnk_4a is the highest level number whose conditions hold: set at code_0219eab4.c:165-183)
    /* 04 */ Unk0201ea30 *mMissionRunLVselS7Or6Bncl;
    // same variant as mMissionRunLVselS7Or6Bncl (.bnbl)
    /* 08 */ void *mMissionRunLVselS7Or6Bnbl;
    // same variant as mMissionRunLVselS7Or6Bncl (.bnll)
    /* 0c */ struct Unk0201ea30 *mMissionRunLVselS7Or6Bnll;
    // cell records of mMissionRunLVselS7Or6Bncl and Bnll
    /* 10 */ LayoutTableEntry *mMissionRunLVselS7Or6Table;
    /* 14 */ void *mUnk_14;
    /* 18 */ void *mHeap;
    /* 1c */ s32 mState;
    /* 20 */ s32 mNextState;
    /* 24 */ s32 mStateFrames; /* counted only in states 1, 4, 5; zeroed by the next-state setter */
    /* 28 */ s32 mUnk_28[7];
    /* 44 */ s32 mBg0Offset;
    /* 48 */ s16 mUnk_48;
    /* 4a */ s16 mUnk_4a;
    /* 4c */ s16 mIndex; /* level number - 1 */
    /* 4e */ u8 mUnk_4e[0x2];
    /* 50 */ void *mUnk_50;
    /* 54 */ void *mUnk_54;
    /* 58 */ s32 mResult; /* 1 = level chosen, 2 = Back; also read by ReleaseMissionRunLVsel for the sound */
} MissionRunLVsel;

// Object behind MissionRunMSsel.mUnk_1c.
typedef struct Unk021ca414_1c {
    /* 00 */ u8 mUnk_00[0x8];
    /* 08 */ u32 mUnk_08;
    /* 0c */ u8 *mUnk_0c;
} Unk021ca414_1c;

// 0x2c-byte element of the table behind MissionRunMSsel.mUnk_50.
typedef struct Unk021ca414_50 {
    /* 00 */ u8 mUnk_00[0xc];
    /* 0c */ u16 mUnk_0c;
    /* 0e */ u8 mUnk_0e[0x1e];
} Unk021ca414_50;

// Object behind gMissionRunMSsel.
typedef struct MissionRunMSsel {
    /* 00 */ struct Unk02021dc8 *mMissionRunMSselMNcer;
    /* 04 */ Unk0201ea30 *mMissionRunMSselMBncl;
    /* 08 */ struct Unk0201ea30 *mMissionRunMSselMBnll;
    /* 0c */ struct Unk02021dc8 *mMissionRunMSselSNcer;
    /* 10 */ Unk0201ea30 *mMissionRunMSselSBncl;
    /* 14 */ void *mMissionRunMSselSBnbl;
    /* 18 */ struct Unk0201ea30 *mMissionRunMSselSBnll;
    /* 1c */ Unk021ca414_1c *mUnk_1c;
    /* 20 */ u16 mUnk_20[0x10];
    // one 0x40-byte record per cell of the Bncl (plus Bnll) members, built by InitLayoutTable
    /* 40 */ LayoutTableEntry *mMissionRunMSselMTable;
    // one 0x40-byte record per cell of the Bncl (plus Bnll) members, built by InitLayoutTable
    /* 44 */ LayoutTableEntry *mMissionRunMSselSTable;
    /* 48 */ void *mUnk_48;
    // missionTable.mtbl: byte table, header u16 row width at +6, data at +8; GetMissionTableValue(table, row, column)
    // returns the mission number
    /* 4c */ void *mMissionTableMtbl;
    /* 50 */ Unk021ca414_50 *mUnk_50;
    /* 54 */ struct Bmg *mCommonMessages;
    /* 58 */ void *mMissionMessages;
    /* 5c */ void *mHeap;
    /* 60 */ u32 mState;
    /* 64 */ s32 mNextState;
    /* 68 */ s32 mStateFrames; /* counted only in states 1, 4, 8; zeroed by the next-state setter */
    /* 6c */ s32 mUnk_6c[9];
    // X half of reg_G2_BG0OFS (0x04000010, main engine BG0), stored negated
    /* 90 */ s32 mBg0OffsetX;
    // Y half of reg_G2_BG0OFS (0x04000010, main engine BG0), stored negated
    /* 94 */ s32 mBg0OffsetY;
    // Y half of reg_G2_BG1OFS (0x04000014, main engine BG1), stored negated; X is not written
    /* 98 */ s32 mBg1Offset;
    /* 9c */ s16 mUnk_9c;
    /* 9e */ s16 mIndex; /* mission number - 1, 8 = ninth mission */
    /* a0 */ s32 mUnk_a0;
    /* a4 */ BOOL mUnk_a4;
    /* a8 */ s32 mUnk_a8;
    /* ac */ s32 mUnk_ac;
    /* b0 */ s16 mUnk_b0;
    /* b2 */ u8 mUnk_b2[0x2];
    /* b4 */ void *mUnk_b4;
    /* b8 */ void *mUnk_b8;
    /* bc */ s32 mResult; /* 1 = mission chosen, 2 = Back; also read by ReleaseMissionRunMSsel for the sound */
} MissionRunMSsel;

// Object behind gSelectEngine.
typedef struct SelectEngine {
    /* 00 */ struct Unk02021dc8 *mSelectEngineMNcer;
    /* 04 */ struct Unk0201ea30 *mSelectEngineMBncl;
    /* 08 */ struct Unk02021dc8 *mSelectEngineSNcer;
    // gp/select_engine_B_s.bncl when IsBackupFlagSet(0x10) != 0, else gp/select_engine_A_s.bncl; the same flag hides
    // item 3 (A layout has no fourth item) (code_021a11a4.c:139-143 zeroes the cells of item 3 when
    // IsBackupFlagSet(0x10) is 0)
    /* 0c */ struct Unk0201ea30 *mSelectEngineAOrBSBncl;
    // same variant as mSelectEngineAOrBSBncl (.bnbl)
    /* 10 */ void *mSelectEngineAOrBSBnbl;
    // one 0x40-byte record per cell of the Bncl (plus Bnll) members, built by InitLayoutTable
    /* 14 */ LayoutTableEntry *mSelectEngineMTable;
    // cell records of mSelectEngineAOrBSBncl (variant chosen by IsBackupFlagSet(0x10))
    /* 18 */ LayoutTableEntry *mSelectEngineAOrBSTable;
    /* 1c */ void *mUnk_1c;
    /* 20 */ void *mHeap;
    /* 24 */ s32 mState;
    /* 28 */ s32 mNextState;
    /* 2c */ s32 mStateFrames; /* counted only in states 1, 2, 5, 6; zeroed by the next-state setter */
    /* 30 */ s32 mBg0Offset;
    /* 34 */ s32 mIndex;
    /* 38 */ BOOL mUnk_38;
    /* 3c */ s32 mUnk_3c;
    /* 40 */ s16 mUnk_40;
    /* 42 */ u8 mUnk_42[0x2];
    /* 44 */ void *mUnk_44;
    /* 48 */ void *mUnk_48;
    /* 4c */ s32 mResult;
} SelectEngine;

// Object behind data_ov001_021ca420, allocated by func_ov001_021a6238.
typedef struct Unk021ca420 {
    /* 00 */ s32 mMode;
    /* 04 */ s32 mSizeIndex;
    /* 08 */ u8 mCellValue;
    /* 09 */ u8 mUnk_09[0x3];
    /* 0c */ s32 mCellShift;
    /* 10 */ s32 mOriginX;
    /* 14 */ s32 mOriginY;
    /* 18 */ s32 mSide;
    /* 1c */ u8 mUnk_1c[0xc];
    /* 28 */ s32 mPrevX;
    /* 2c */ s32 mPrevY;
    /* 30 */ s32 mPrevDown;
    /* 34 */ s32 mCellX;
    /* 38 */ s32 mCellY;
    /* 3c */ s32 mPrevCellX;
    /* 40 */ s32 mPrevCellY;
} Unk021ca420;

typedef struct Unk021ca424_08 {
    /* 00 */ u8 mUnk_00[0xc];
    /* 0c */ u8 *mUnk_0c;
} Unk021ca424_08;

typedef struct MissionRunBossIcon {
    /* 00 */ Ncgr *mNcgr;
    /* 04 */ struct Unk02021dc8 *mNcer;
    /* 08 */ Unk021ca424_08 *mNclr;
    /* 0c */ void *mBncl;
} MissionRunBossIcon;

extern u8 *gNicknameBuffers;
extern u8 *gOptionBuffers;
extern MissionRunBossIcon *gMissionRunBossIcon;

#include "00/code_021832d8.h"
