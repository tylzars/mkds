#pragma once

#include "types.h"
#include "00/code_02181f98.h"

// Object behind data_ov001_021ca400.
typedef struct Unk021ca400 {
    /* 000 */ s32 mState;
    /* 004 */ s32 mNextState;
    /* 008 */ s32 mUnk_008;
    /* 00c */ s32 mKind;
    /* 010 */ void *mHeap;
    /* 014 */ s16 mUnk_014;
    /* 016 */ u8 mUnk_016[0x2];
    /* 018 */ BOOL mUnk_018;
    /* 01c */ void *mUnk_01c;
    /* 020 */ Unk02124b1c *mUnk_020;
    /* 024 */ struct Unk02021dc8 *mThanksYouMNcer;
    /* 028 */ u8 mUnk_028[0x4];
    /* 02c */ Nclr *mThanksYouMO00Nclr;
    /* 030 */ void *mEndingThanksBncl;
    /* 034 */ void *mEndingThanksBnll;
    /* 038 */ Ncgr *mLogoEndMarioKartMBAndThanksYouMBNcgrs[2];
    /* 040 */ Nscr *mLogoEndMarioKartMBgAndThanksYouMBgNscrs[2];
    /* 048 */ Nclr *mLogoEndMarioKartMBAndThanksYouMBNclrs[2];
    /* 050 */ Ncgr *mEndAllRightsReservedSBAndLogoEndNintendoSBNcgrs[2];
    /* 058 */ Nscr *mEndAllRightsReservedSBgAndLogoEndNintendoSBgNscrs[2];
    /* 060 */ Nclr *mEndAllRightsReservedSBAndLogoEndNintendoSBNclrs[2];
    /* 068 */ u8 mUnk_068[0x404];
    /* 46c */ void *mCommonMessages;
} Unk021ca400;

// Objects whose layout isn't known yet.
// Object behind gMissionRunLVsel.
typedef struct MissionRunLVsel {
    /* 00 */ struct Unk02021dc8 *mUnk_00;
    /* 04 */ Unk0201ea30 *mUnk_04;
    /* 08 */ void *mUnk_08;
    /* 0c */ void *mUnk_0c;
    /* 10 */ Unk02124b1c *mUnk_10;
    /* 14 */ void *mUnk_14;
    /* 18 */ void *mHeap;
    /* 1c */ s32 mState;
    /* 20 */ s32 mNextState;
    /* 24 */ s32 mUnk_24;
    /* 28 */ s32 mUnk_28[7];
    /* 44 */ s32 mUnk_44;
    /* 48 */ s16 mUnk_48;
    /* 4a */ s16 mUnk_4a;
    /* 4c */ s16 mUnk_4c;
    /* 4e */ u8 mUnk_4e[0x2];
    /* 50 */ void *mUnk_50;
    /* 54 */ void *mUnk_54;
    /* 58 */ s32 mUnk_58;
} MissionRunLVsel;

// Object behind MissionRunMSsel::mUnk_1c.
typedef struct Unk021ca414_1c {
    /* 00 */ u8 mUnk_00[0x8];
    /* 08 */ u32 mUnk_08;
    /* 0c */ u8 *mUnk_0c;
} Unk021ca414_1c;

// 0x2c-byte element of the table behind MissionRunMSsel::mUnk_50.
typedef struct Unk021ca414_50 {
    /* 00 */ u8 mUnk_00[0xc];
    /* 0c */ u16 mUnk_0c;
    /* 0e */ u8 mUnk_0e[0x1e];
} Unk021ca414_50;

// Object behind gMissionRunMSsel.
typedef struct MissionRunMSsel {
    /* 00 */ struct Unk02021dc8 *mUnk_00;
    /* 04 */ Unk0201ea30 *mUnk_04;
    /* 08 */ void *mUnk_08;
    /* 0c */ struct Unk02021dc8 *mUnk_0c;
    /* 10 */ Unk0201ea30 *mUnk_10;
    /* 14 */ void *mUnk_14;
    /* 18 */ void *mUnk_18;
    /* 1c */ Unk021ca414_1c *mUnk_1c;
    /* 20 */ u16 mUnk_20[0x10];
    /* 40 */ Unk02124b1c *mUnk_40;
    /* 44 */ Unk02124b1c *mUnk_44;
    /* 48 */ void *mUnk_48;
    /* 4c */ void *mUnk_4c;
    /* 50 */ Unk021ca414_50 *mUnk_50;
    /* 54 */ void *mCommonMessages;
    /* 58 */ void *mMissionMessages;
    /* 5c */ void *mHeap;
    /* 60 */ u32 mState;
    /* 64 */ s32 mNextState;
    /* 68 */ s32 mUnk_68;
    /* 6c */ s32 mUnk_6c[9];
    /* 90 */ s32 mUnk_90;
    /* 94 */ s32 mUnk_94;
    /* 98 */ s32 mUnk_98;
    /* 9c */ s16 mUnk_9c;
    /* 9e */ s16 mUnk_9e;
    /* a0 */ s32 mUnk_a0;
    /* a4 */ s32 mUnk_a4;
    /* a8 */ s32 mUnk_a8;
    /* ac */ s32 mUnk_ac;
    /* b0 */ s16 mUnk_b0;
    /* b2 */ u8 mUnk_b2[0x2];
    /* b4 */ void *mUnk_b4;
    /* b8 */ void *mUnk_b8;
    /* bc */ s32 mUnk_bc;
} MissionRunMSsel;

// Object behind gSelectEngine.
typedef struct SelectEngine {
    /* 00 */ struct Unk02021dc8 *mUnk_00;
    /* 04 */ void *mUnk_04;
    /* 08 */ struct Unk02021dc8 *mUnk_08;
    /* 0c */ void *mUnk_0c;
    /* 10 */ void *mUnk_10;
    /* 14 */ Unk02124b1c *mUnk_14;
    /* 18 */ Unk02124b1c *mUnk_18;
    /* 1c */ void *mUnk_1c;
    /* 20 */ void *mHeap;
    /* 24 */ s32 mState;
    /* 28 */ s32 mNextState;
    /* 2c */ s32 mUnk_2c;
    /* 30 */ s32 mUnk_30;
    /* 34 */ s32 mUnk_34;
    /* 38 */ s32 mUnk_38;
    /* 3c */ s32 mUnk_3c;
    /* 40 */ s16 mUnk_40;
    /* 42 */ u8 mUnk_42[0x2];
    /* 44 */ void *mUnk_44;
    /* 48 */ void *mUnk_48;
    /* 4c */ s32 mUnk_4c;
} SelectEngine;

// Object behind data_ov001_021ca420, allocated by func_ov001_021a6238.
typedef struct Unk021ca420 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ u8 mUnk_08;
    /* 09 */ u8 mUnk_09[0x3];
    /* 0c */ s32 mUnk_0c;
    /* 10 */ s32 mUnk_10;
    /* 14 */ s32 mUnk_14;
    /* 18 */ s32 mUnk_18;
    /* 1c */ u8 mUnk_1c[0xc];
    /* 28 */ s32 mUnk_28;
    /* 2c */ s32 mUnk_2c;
    /* 30 */ s32 mUnk_30;
    /* 34 */ s32 mUnk_34;
    /* 38 */ s32 mUnk_38;
    /* 3c */ s32 mUnk_3c;
    /* 40 */ s32 mUnk_40;
} Unk021ca420;

// Object behind the pointer at 0x08 of Unk021ca424.
typedef struct Unk021ca424_08 {
    /* 00 */ u8 mUnk_00[0xc];
    /* 0c */ u8 *mUnk_0c;
} Unk021ca424_08;

// Object behind data_ov001_021ca424.
typedef struct Unk021ca424 {
    /* 00 */ Ncgr *mUnk_00;
    /* 04 */ struct Unk02021dc8 *mUnk_04;
    /* 08 */ Unk021ca424_08 *mUnk_08;
    /* 0c */ void *mUnk_0c;
} Unk021ca424;

extern u8 *data_ov001_021ca404;
extern u8 *data_ov001_021ca408;
extern Unk021ca424 *data_ov001_021ca424;

#include "00/code_021832d8.h"
