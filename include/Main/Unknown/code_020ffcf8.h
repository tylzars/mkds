#pragma once

#include "types.h"

typedef struct Unk020ffcf8 {
    /* 00 */ u8 mUnk_00[0xac];
    /* ac */ u32 mUnk_ac;
} Unk020ffcf8;

void EnterDramState4(Unk020ffcf8 *dram);
