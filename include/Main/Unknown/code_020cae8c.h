#pragma once

#include "types.h"
#include "Main/Unknown/code_02124094.h" // Unk02124b1c

typedef struct Ncgr Ncgr;
typedef struct Nclr Nclr;
typedef struct Unk02021dc8 Unk02021dc8;

// Elements of the table at member 0x14 of Unk0217b43c.
typedef struct ScreenCallbacks {
    /* 0 */ void (*mUnk_00)(void);
    /* 4 */ void (*mUpdate)(u32 a);
} ScreenCallbacks;

// Object behind data_0217b43c.
typedef struct Unk0217b43c {
    /* 000 */ s32 mFramesSinceScreenSwitch;
    /* 004 */ s32 mUnk_004;
    /* 008 */ s32 mPreviousScreenNumber;
    /* 00c */ s32 mScreenNumber;
    /* 010 */ s32 mNextScreenNumber;
    /* 014 */ ScreenCallbacks mScreenCallbacks[0x1e];
    /* 104 */ BOOL mScreenInitPending;
    /* 108 */ u8 mMainOam[0x404];
    /* 50c */ u8 mSubOam[0x404];
    /* 910 */ Nclr *mSinglePlaySelectModeMONclr;
    /* 914 */ Ncgr *mSinglePlaySelectModeMNcgr;
    /* 918 */ Unk02021dc8 *mSinglePlaySelectModeMNcer;
    /* 91c */ u8 mUnk_91c[4];
    /* 920 */ Nclr *mSinglePlaySelectModeSONclr;
    /* 924 */ Ncgr *mSinglePlaySelectModeSNcgr;
    /* 928 */ Unk02021dc8 *mSinglePlaySelectModeSNcer;
    /* 92c */ u8 mUnk_92c[4];
    /* 930 */ s32 mSinglePlaySelectModeIndex;
    /* 934 */ BOOL mUnk_934;
    /* 938 */ s16 mUnk_938;
    /* 93a */ u8 mUnk_93a[2];
    /* 93c */ Unk02124b1c *mSinglePlaySelectModeMLayoutTable;
    /* 940 */ struct Unk0201ea30 *mSinglePlaySelectModeMBncl;
    /* 944 */ s32 mUnk_944;
    /* 948 */ Unk02124b1c *mSinglePlaySelectModeSLayoutTable;
    /* 94c */ struct Unk0201ea30 *mSinglePlaySelectModeSBncl;
    /* 950 */ void *mSinglePlaySelectModeSBnbl;
    /* 954 */ u8 *mUnk_954;
    /* 958 */ BOOL mUnk_958;
    /* 95c */ BOOL mUnk_95c;
} Unk0217b43c;

void func_020cae8c(void);
