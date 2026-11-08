#pragma once

#include "types.h"

typedef struct RaceHudOamBuffer RaceHudOamBuffer;

typedef struct RaceHudOamBuffer RaceHudOamBuffer;

typedef struct RaceHudOamBuffer RaceHudOamBuffer;

typedef struct RaceHudOamBuffer RaceHudOamBuffer;

void InitRaceTimeDigits(void);
void DrawRaceLapAndTimeDifference(RaceHudOamBuffer *oamBuffer);
void UpdateRaceLapNumber(void);
u32 ClearRaceLapNumberPointer(void);
void InitRaceLapNumber(void);
void DrawRaceRankListBattleState1To3Rows(RaceHudOamBuffer *oamBuffer);
void DrawRaceRankListBattleState0Rows(RaceHudOamBuffer *oamBuffer);
void DrawRaceRankListNonBattleRows(RaceHudOamBuffer *a);
void DrawRaceRankListState1To3Rows(RaceHudOamBuffer *oamBuffer);
void DrawRaceRankListState0Rows(RaceHudOamBuffer *oamBuffer);
void DrawRaceRankListRankCells(RaceHudOamBuffer *oamBuffer);
u32 GetRaceRankListSNcerIndex(u16 kartIndex);
void DrawRaceRankList(RaceHudOamBuffer *oamBuffer);
void UpdateRaceRankList(void);
u32 ClearRaceRankListPointer(void);
