#pragma once

#include "types.h"

typedef struct Unk02089ecc {
    /* 00 */ u16 mTimer;
    /* 02 */ u16 mUnk_02;
    /* 04 */ u16 mColor;
    /* 06 */ u8 mUnk_06[0x2];
    /* 08 */ u32 mEnabled;
} Unk02089ecc;

void StartTimedQuad(Unk02089ecc *timedQuad);
