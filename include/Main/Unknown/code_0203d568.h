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

BOOL func_0203fa60(RaceProgressKart *a, s32 *b, Vec3 *c, u16 d, u16 e);
void func_0203f334(RaceProgressKart *a, s32 b);
void func_0203e788(s32 a, s32 b);
s32 func_0203ef58(void);
void func_0203eb38(void);
void func_0203ecf0(void);
void func_0203ee28(void);
void func_0203d21c(void);
u32 func_0207a7fc(s32 a);
