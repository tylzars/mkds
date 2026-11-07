#pragma once

#include "types.h"

typedef struct Ncgr Ncgr;
typedef struct Nscr Nscr;
typedef struct Nclr Nclr;

s32 func_020c3e00(void);
Nscr *GetRaceGoalSNscr(unsigned int index);
// Two pointers; the elements of 8 bytes at member 0xb8 of the object behind gRaceGoalS.
typedef struct Unk020c3e2c {
    /* 00 */ Nclr *mUnk_00;
    /* 04 */ Ncgr *mUnk_04;
} Unk020c3e2c;

Unk020c3e2c *GetRaceGoalSBPaletteAndChars(unsigned int index);
