#pragma once

#include "types.h"

// Halfwords written by UpdateRaceHudSubScreenBgPalette (it writes up to element 0xf5).
typedef struct Unk020cf340 {
    /* 000 */ u16 mUnk_00[0xf6];
} Unk020cf340;

s32 CreateRaceHudSubScreenBombKouraWCells(void);
void UpdateRaceHudSubScreenBgPalette(Unk020cf340 *palette);
void func_020cfca4(void);
