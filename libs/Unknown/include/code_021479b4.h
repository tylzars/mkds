#pragma once

#include "types.h"

// Sixteen words.
typedef struct MtxFx44 {
    /* 00 */ s32 mUnk_00[16];
} MtxFx44;

void MTX_Concat44(const s32 *a, const s32 *b, s32 *ab);
