#pragma once

#include "types.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_02024000.h"

// Seven words: six values and the number of values set.
typedef struct Unk0217b354_38 {
    /* 00 */ s32 mUnk_00[6];
    /* 18 */ s32 mUnk_18;
} Unk0217b354_38;

// Object behind data_0217b354, 0x1a4 bytes allocated by func_020b1df0.
typedef struct Unk0217b354 {
    /* 000 */ s32 mUnk_000;
    /* 004 */ s32 mUnk_004;
    /* 008 */ s32 mUnk_008;
    /* 00c */ s32 mUnk_00c;
    /* 010 */ s32 mUnk_010;
    /* 014 */ s32 mUnk_014;
    /* 018 */ s32 mUnk_018;
    /* 01c */ s32 mUnk_01c;
    /* 020 */ s32 mUnk_020;
    /* 024 */ s32 mUnk_024;
    /* 028 */ s32 mUnk_028;
    /* 02c */ s32 mUnk_02c;
    /* 030 */ s32 mUnk_030;
    /* 034 */ s32 mUnk_034;
    /* 038 */ Unk0217b354_38 mUnk_038[4];
    /* 0a8 */ void *mUnk_0a8;
    /* 0ac */ u8 mUnk_0ac[4][0x20];
    /* 12c */ Unk02180728 mUnk_12c[4];
    /* 16c */ Unk020b4a44 *mChoisesSBNclr;
    /* 170 */ Unk020b4934 *mChoisesSBNcgr;
    /* 174 */ u16 *mUnk_174;
    /* 178 */ u16 *mUnk_178;
    /* 17c */ Unk020b47d8 *mUnk_17c;
    /* 180 */ Unk020b47d8 *mUnk_180;
    /* 184 */ Unk020b47d8 *mUnk_184;
    /* 188 */ Unk020b47d8 *mUnk_188;
    /* 18c */ Unk020b47d8 *mChoisesSNscrs[6];
} Unk0217b354;

void func_020b24cc(Unk02180728 *a, void *b, void *c, s32 d, s32 e);
u32 func_020b24a4(Unk02180728 *a, s32 b, s32 c, u32 d, u32 e, void *f);
void func_020b1df0(void);
void func_020b1de4(void);
