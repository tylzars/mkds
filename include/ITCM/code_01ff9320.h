#pragma once

#include "types.h"

typedef struct NNSG3dMatAnmResult NNSG3dMatAnmResult;

// Command word and the 18 words sent with it: a mode, a 4x4 matrix and a trailing value.
typedef struct Unk01ff9320_buf {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ s32 mUnk_08[16];
    /* 48 */ u32 mUnk_48;
    /* 4c */ u32 mUnk_4c;
} Unk01ff9320_buf;

typedef void (*Unk01ff9320_Fn)(s32 *, NNSG3dMatAnmResult *);

void func_01ff9320(NNSG3dMatAnmResult *p);
void func_01ff946c(s32 *o);
void func_01ff9490(s32 *o, const NNSG3dMatAnmResult *in);
void func_01ff94d4(s32 *o, const NNSG3dMatAnmResult *in);
