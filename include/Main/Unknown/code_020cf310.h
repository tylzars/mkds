#pragma once

#include "types.h"

// Halfwords written by UpdateRaceHudSubScreenBgPalette (it writes up to element 0xf5).
typedef struct RaceHudSubScreenBgPalette {
    /* 000 */ u16 mUnk_00[0xf6];
} RaceHudSubScreenBgPalette;

s32 CreateRaceHudSubScreenBombKouraWCells(void);
void UpdateRaceHudSubScreenBgPalette(RaceHudSubScreenBgPalette *palette);
void func_020cfca4(void);
