#pragma once

#include "types.h"

typedef struct RaceHudOamBuffer RaceHudOamBuffer;

void UpdateRaceHudSubScreenShine16Cells(void);
void DrawRaceHudSubScreenShine16Cells(RaceHudOamBuffer *a);
s32 CreateRaceHudSubScreenCrabCells(void);
