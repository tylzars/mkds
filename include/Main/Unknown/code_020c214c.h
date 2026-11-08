#pragma once

#include "types.h"

typedef struct Unk020c06c4 Unk020c06c4;

void UpdateRaceGoalSOffset(void);
void InitRaceGoalS(void);

void DrawRaceGoalSTeams(Unk020c06c4 *oamBuffer);
void DrawRaceGoalSTeamNumber(Unk020c06c4 *oamBuffer, s32 number, s32 x, s32 y);
void DrawRaceGoalSTeamKart(Unk020c06c4 *oamBuffer, u32 kartIndex, s32 x, s32 y);
void DrawRaceGoalSKarts(Unk020c06c4 *oamBuffer);
void UpdateRaceGoalS(void);
void func_020c3b6c(s32 row, s32 style);
