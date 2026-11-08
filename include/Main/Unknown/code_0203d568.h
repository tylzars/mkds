#pragma once

#include "types.h"

typedef struct RaceProgressKart RaceProgressKart;
typedef struct RankTimeGp RankTimeGp;

void func_0203d568(void);
// In mode 4 also creates the mission object.
void CreateRaceProgress(void *heap);
void SetRankTimeFromRankTimeGp(RankTimeGp *rankTimeGp);
// Updates every kart's progress, the rank order, the first place frames and the pending finishes, and consumes flag 8.
void UpdateRaceProgressKarts(void);
void UpdateRaceProgressKart(Vec3 *position, RaceProgressKart *kart);
void EnterRaceProgressKartCheckpoint(RaceProgressKart *kart, s32 checkpoint);
void func_0203e4c4(u32 kartIndex, u32 b);
void CompleteRaceProgressKartLap(RaceProgressKart *kart);
