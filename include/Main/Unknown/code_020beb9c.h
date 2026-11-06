#pragma once

#include "types.h"

// The 49 entries of gRaceHudSubScreenCellGroupFunctions.
typedef struct RaceHudSubScreenCellGroupFunctions {
    /* 00 */ s32 (*mCreate)(void);
    /* 04 */ void (*mClear)(void);
    /* 08 */ void (*mUpdate)(void);
    /* 0c */ void (*mDraw)(void *);
} RaceHudSubScreenCellGroupFunctions;

void InitRaceHudSubScreenCellGroups(void);
