#pragma once

#include "types.h"

typedef struct Unk020e43a8 Unk020e43a8;

// 0x10-byte request built on the stack here.
typedef struct Unk020e4e08 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ Vec3 mUnk_04;
} Unk020e4e08;

void DrawPukupukuShadow(u32 a, Unk020e43a8 *pukupuku, u32 b, u32 alpha);
