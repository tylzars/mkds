#pragma once

#include "types.h"
#include "code_02012b30.h" // Unk02012f58

// Nine words.
typedef struct Unk02146dfc {
    /* 00 */ s32 mUnk_00[9];
} Unk02146dfc;

void Vec3MultiplyMatrix3x3(const Vec3 *a, const s32 *b, Vec3 *c);
void func_02146dfc(const s32 *a, const s32 *b, s32 *c);
void func_02146f98(Unk02012f58 *a, const Vec3 *b, s32 c, s32 d);
void func_021470f8(const Unk02012f58 *a, Unk02012f58 *b, s32 c, s32 d, s32 e);
