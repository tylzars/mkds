#pragma once

#include "types.h"

typedef struct RaceProgressKart RaceProgressKart;
typedef struct RankTimeGp RankTimeGp;

void func_0203d568(void);
// In mode 4 also creates the mission object.
void CreateRaceProgress(void *a);
void func_0203d8fc(RankTimeGp *a);
// Updates every kart's progress, the rank order, the first place frames and the pending finishes, and consumes flag 8.
void UpdateRaceProgressKarts(void);
void UpdateRaceProgressKart(Vec3 *a, RaceProgressKart *b);
void func_0203e370(RaceProgressKart *a, s32 b);
void func_0203e4c4(u32 a, u32 b);
void func_0203e550(RaceProgressKart *a);

u32 func_0207a7fc(s32 a);
