#pragma once

#include "types.h"
#include "Main/Unknown/code_020e43a8.h"

// Second argument of func_020e5684: a vector at 0x0c, halfwords from 0x28.
typedef struct Unk020e5684 {
    /* 00 */ u8 mUnk_00[0x0c];
    /* 0c */ Vec3 mUnk_0c;
    /* 18 */ u8 mUnk_18[0x10];
    /* 28 */ s16 mUnk_28;
    /* 2a */ s16 mUnk_2a;
    /* 2c */ s16 mUnk_2c;
    /* 2e */ s16 mUnk_2e;
    /* 30 */ s16 mUnk_30;
} Unk020e5684;

void func_020e57a0(Unk020e43a8 *p, Vec3 *a, s32 b, Vec3 *c);
void func_020e576c(void);
void func_020e5684(Unk020e43a8 *p, Unk020e5684 *q);
