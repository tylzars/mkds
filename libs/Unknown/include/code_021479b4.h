#pragma once

#include "types.h"

// Sixteen words.
typedef struct Matrix4x4 {
    /* 00 */ s32 mUnk_00[16];
} Matrix4x4;

void Matrix4x4Multiply(const s32 *a, const s32 *b, s32 *c);
