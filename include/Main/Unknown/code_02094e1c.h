#pragma once

#include "types.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h"

// Object of 0xb0 bytes: the MapObject it starts with, then four words.
typedef struct Unk02094e8c {
    /* 00 */ MapObject mUnk_00;
    /* a0 */ s32 mUnk_a0;
    /* a4 */ BOOL mUnk_a4;
    /* a8 */ s32 mUnk_a8;
    /* ac */ s32 mUnk_ac;
} Unk02094e8c;

// Table of the objects of func_02094e8c and their number.
typedef struct Unk02095228 {
    /* 00 */ Unk02094e8c **mUnk_00;
    /* 04 */ u16 mUnk_04;
} Unk02095228;

#include "Main/Unknown/code_020d22c0.h"

void func_02094e1c(void);
u32 func_02094e3c(void);
void func_02094e8c(void *a, Unk02094e8c *o);
s16 func_0209516c(s32 a);
s32 func_0209518c(s32 a, s32 b);
s16 func_0209519c(s32 a);
u16 func_020951b4(Unk020f41c4_B *a);
Unk020f41c4_B *func_0209520c(void);
void func_02095228(Unk02095228 *a);
void func_020952dc(Unk02094e8c *a, s32 b, s32 c, s32 d, s32 e);
void func_020954e4(u32 arg0);
