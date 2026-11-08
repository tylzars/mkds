#pragma once

#include "types.h"
#include "Main/Unknown/code_020c5e30.h"

void UpdateRaceHudSubScreenItemBoxCells(void);
void DrawRaceHudSubScreenItemBoxCells(RaceHudOamBuffer *a);
void RefreshRaceNewRecordTaRecordFlags(void);
s32 IsRaceNewRecordTaFinishRecord(void);
BOOL IsRaceNewRecordTaFinishRecordFirst(void);
s32 IsRaceNewRecordTaBestLapRecord(void);
