#pragma once

#include "types.h"

typedef struct Unk020ffd94 {
    /* 00 */ u8 mUnk_00[0xac];
    /* ac */ u32 mUnk_ac;
} Unk020ffd94;

void EnterDramState2(Unk020ffd94 *dram);
