#pragma once

#include "types.h"

// data_0217cd30 is addressed in rows of eight words.
typedef struct Unk0217cd30 {
    /* 0 */ u32 mUnk_00[8];
} Unk0217cd30;

#include "code_0212d214.h"

// Addressed at the byte offset NNSFndList.mLinkOffset of the pointer passed to func_0210bc54.
typedef struct Unk0210bc54 {
    /* 0 */ u8 mUnk_00[8];
    /* 8 */ void *mUnk_08;
} Unk0210bc54;

u32 func_0210bafc(s32 a, s32 b, s32 c);
u32 func_0210bb74(s32 a, s32 b, s32 c);
void func_0210bc14(void);
void func_0210bc54(NNSFndList *a, void *b);
u32 func_0210bc8c(void *a, void *b);
