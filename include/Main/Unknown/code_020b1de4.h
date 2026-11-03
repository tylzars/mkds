#pragma once

#include "types.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_02024000.h"

// Seven words: six values and the number of values set.
typedef struct ChoisesSList {
    /* 00 */ s32 mValues[6];
    /* 18 */ s32 mValueCount;
} ChoisesSList;

// Object behind gChoisesS, 0x1a4 bytes allocated by InitChoisesS.
typedef struct ChoisesS {
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
    /* 038 */ ChoisesSList mLists[4];
    /* 0a8 */ void *mUnk_0a8;
    /* 0ac */ u8 mUnk_0ac[4][0x20];
    /* 12c */ Unk02180728 mUnk_12c[4];
    /* 16c */ Nclr *mChoisesSBNclr;
    /* 170 */ Ncgr *mChoisesSBNcgr;
    /* 174 */ u16 *mUnk_174;
    /* 178 */ u16 *mUnk_178;
    /* 17c */ Nscr *mList0Nscr;
    /* 180 */ Nscr *mList1Nscr;
    /* 184 */ Nscr *mList2Nscr;
    /* 188 */ Nscr *mList3Nscr;
    /* 18c */ Nscr *mChoisesSNscrs[6];
} ChoisesS;

void func_020b24cc(Unk02180728 *a, void *b, void *c, s32 d, s32 e);
u32 func_020b24a4(Unk02180728 *a, s32 b, s32 c, u32 d, u32 e, void *f);
void InitChoisesS(void);
void func_020b1de4(void);
