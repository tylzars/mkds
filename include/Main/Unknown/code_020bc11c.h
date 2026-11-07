#pragma once

#include "types.h"

typedef struct RaceHudOamBuffer RaceHudOamBuffer;

typedef struct RaceHudOamBuffer RaceHudOamBuffer;

typedef struct RaceHudOamBuffer RaceHudOamBuffer;

typedef struct RaceHudOamBuffer RaceHudOamBuffer;

void InitRaceTimeDigits(void);
void DrawRaceLapAndTimeDifference(RaceHudOamBuffer *a);
void UpdateRaceLapNumber(void);
u32 ClearRaceLapNumberPointer(void);
void InitRaceLapNumber(void);
void func_020bcbe8(RaceHudOamBuffer *a);
void func_020bd178(RaceHudOamBuffer *a);
void func_020bd7f8(RaceHudOamBuffer *a);
void func_020bd850(RaceHudOamBuffer *a);
void func_020bdb34(RaceHudOamBuffer *a);
void func_020bdf08(RaceHudOamBuffer *a);
u32 GetRaceRankListSNcerIndex(u16 kartIndex);
void DrawRaceRankList(RaceHudOamBuffer *a);
void UpdateRaceRankList(void);
u32 ClearRaceRankListPointer(void);
