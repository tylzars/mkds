#pragma once

#include "types.h"

typedef struct Unk020e34ec {
    /* 00 */ u8 mUnk_00[0x14];
    /* 14 */ u32 mUnk_14;
} Unk020e34ec;

void EnterChoropuState2(Unk020e34ec *choropu);
