#pragma once

#include "types.h"

typedef struct RaceHudOamBuffer RaceHudOamBuffer;

typedef struct RaceHudOamBuffer RaceHudOamBuffer;

void DrawRaceMissionRunCount(RaceHudOamBuffer *oamBuffer);
void DrawRaceModeCount(RaceHudOamBuffer *oamBuffer);
void UpdateRaceModeCount(void);
void InitRaceModeCount(void);
BOOL IsRaceKeyRecordingNotFull(void);
void DrawRaceItemSlot(RaceHudOamBuffer *oamBuffer);
void UpdateRaceItemSlot(void);
u32 ClearRaceItemSlotPointer(void);
