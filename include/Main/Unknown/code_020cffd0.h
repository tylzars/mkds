#pragma once

#include "types.h"

#include "Main/Unknown/code_020c06c4.h"

#include "Main/Unknown/unk_0217b000.h"
#include "code_02022030.h"

// Object behind gRaceGoalTimes.
typedef struct RaceGoalTimes {
    /* 00 */ TimeDigits mFinishTime;
    /* 1c */ TimeDigits mLapTimes[5];
// Counts 0 to 15; picks mCellIndexAdd by quarters.
    /* a8 */ s32 mUnk_a8;
// Added to the cell number of a time row: 0, 0xd or 0x1a.
    /* ac */ s32 mCellIndexAdd;
} RaceGoalTimes;

void DrawRaceHudSubScreenCreamCells(RaceHudOamBuffer *oamBuffer);
void UpdateRaceHudSubScreenCreamCells(void);
s32 CreateRaceHudSubScreenCreamCells(void);
void DrawRaceHudSubScreenBerryCells(void *oamBuffer);
void UpdateRaceHudSubScreenBerryCells(void);
void ClearRaceHudSubScreenBerryCells(void);
s32 CreateRaceHudSubScreenBerryCells(void);
void DrawRaceGoalTimeDigits(RaceHudOamBuffer *oamBuffer, s32 originX, s32 originY, TimeDigits *digits, s32 cellOffset);
void DrawRaceGoalTimes(RaceHudOamBuffer *oamBuffer);
void UpdateRaceGoalTimes(void);
u32 ClearRaceGoalTimesPointer(void);
void InitRaceGoalTimes(void);
void DrawRaceHudSubScreenFireball2Cells(void *oamBuffer);
void UpdateRaceHudSubScreenFireball2Cells(void);
void ClearRaceHudSubScreenFireball2Cells(void);
