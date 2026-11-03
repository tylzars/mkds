#pragma once

#include "types.h"
#include "Main/Unknown/code_02124094.h" // Unk02124b1c

typedef struct Unk020b4934 Unk020b4934;
typedef struct Unk020b4a44 Unk020b4a44;
typedef struct Unk02021dc8 Unk02021dc8;

// Elements of the table at member 0x14 of Unk0217b43c.
typedef struct Unk0217b43c_14 {
    /* 0 */ void (*mUnk_00)(void);
    /* 4 */ void (*mUnk_04)(u32 a);
} Unk0217b43c_14;

// Object behind data_0217b43c.
typedef struct Unk0217b43c {
    /* 000 */ s32 mUnk_000;
    /* 004 */ s32 mUnk_004;
    /* 008 */ s32 mUnk_008;
    /* 00c */ s32 mUnk_00c;
    /* 010 */ s32 mUnk_010;
    /* 014 */ Unk0217b43c_14 mUnk_014[0x1e];
    /* 104 */ s32 mUnk_104;
    /* 108 */ u8 mUnk_108[0x404];
    /* 50c */ u8 mUnk_50c[0x404];
    /* 910 */ Unk020b4a44 *mSinglePlaySelectModeMONclr;
    /* 914 */ Unk020b4934 *mSinglePlaySelectModeMNcgr;
    /* 918 */ Unk02021dc8 *mSinglePlaySelectModeMNcer;
    /* 91c */ u8 mUnk_91c[4];
    /* 920 */ Unk020b4a44 *mSinglePlaySelectModeSONclr;
    /* 924 */ Unk020b4934 *mSinglePlaySelectModeSNcgr;
    /* 928 */ Unk02021dc8 *mSinglePlaySelectModeSNcer;
    /* 92c */ u8 mUnk_92c[4];
    /* 930 */ s32 mUnk_930;
    /* 934 */ s32 mUnk_934;
    /* 938 */ s16 mUnk_938;
    /* 93a */ u8 mUnk_93a[2];
    /* 93c */ Unk02124b1c *mUnk_93c;
    /* 940 */ void *mSinglePlaySelectModeMBncl;
    /* 944 */ s32 mUnk_944;
    /* 948 */ Unk02124b1c *mUnk_948;
    /* 94c */ void *mSinglePlaySelectModeSBncl;
    /* 950 */ void *mSinglePlaySelectModeSBnbl;
    /* 954 */ u8 *mUnk_954;
    /* 958 */ s32 mUnk_958;
    /* 95c */ s32 mUnk_95c;
} Unk0217b43c;

void func_020cae8c(void);
