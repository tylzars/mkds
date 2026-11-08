#pragma once

#include "types.h"

typedef struct RaceHudOamBuffer RaceHudOamBuffer;

void UpdateRaceGoalSOffset(void);
void InitRaceGoalS(void);

void DrawRaceGoalSTeams(RaceHudOamBuffer *oamBuffer);
void DrawRaceGoalSTeamNumber(RaceHudOamBuffer *oamBuffer, s32 number, s32 x, s32 y);
void DrawRaceGoalSTeamKart(RaceHudOamBuffer *oamBuffer, u32 kartIndex, s32 x, s32 y);
void DrawRaceGoalSKarts(RaceHudOamBuffer *oamBuffer);
void UpdateRaceGoalS(void);
void func_020c3b6c(s32 row, s32 style);
