#pragma once

#include "types.h"

typedef struct RaceHudSubScreenCells RaceHudSubScreenCells;

BOOL CreateRaceHudSubScreenCells(RaceHudSubScreenCells **outCells, s32 kind);
BOOL CreateRaceHudSubScreenCellsWithCount(RaceHudSubScreenCells **outCells, s32 objectCount);
