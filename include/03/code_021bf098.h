#pragma once

#include "types.h"
#include "03/code_021d1770.h"
#include "03/code_021d3488.h"

typedef struct Unk021d34e0 Unk021d34e0;

typedef struct Unk021da108 {
    /* 00 */ Unk021d1770 *mUnk_00[2];
    /* 08 */ Unk021d1770 *mUnk_08;
    /* 0c */ Unk021d34e0 *mUnk_0c;
    /* 10 */ u32 mUnk_10;
    /* 14 */ u16 mUnk_14;
    /* 16 */ s8 mUnk_16;
    /* 17 */ u8 mUnk_17;
    /* 18 */ u8 mUnk_18;
    /* 19 */ u8 mUnk_19;
} Unk021da108;

void func_ov003_021bf098(Unk021d34e0 *a);
void func_ov003_021bf0d8(void);
void func_ov003_021bf1d8(Unk021d34e0 *b);
void func_ov003_021bf20c(Unk021d34e0 *c);
void func_ov003_021bf258(s32 b);
void func_ov003_021bf2d0(void);
void func_ov003_021bf2e0(void);
u32 func_ov003_021bf2f0(void);
void func_ov003_021bf310(s8 a);
void func_ov003_021bf31c(s32 value);
int func_ov003_021bf334(void);
void func_ov003_021bf344(void);
void func_ov003_021bf364(u32 c);
