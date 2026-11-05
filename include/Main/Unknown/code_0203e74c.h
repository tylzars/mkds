#pragma once

#include "types.h"

typedef struct RaceProgressKart RaceProgressKart;

void func_0203e74c(u16 param_1);
void func_0203e788(s32 a, s32 b);
// b is goal reached; b == 0 ends the entry without the goal (status 3). Also tells the input source and the HUD.
void FinishRaceProgressKart(RaceProgressKart *a, s32 b);
void func_0203eb38(void);
void func_0203ecf0(void);
void func_0203ee28(void);
s32 func_0203ef58(void);
