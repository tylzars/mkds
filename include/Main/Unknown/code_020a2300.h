#pragma once

#include "types.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020a3fa8.h" // KartBalloons

void func_020a2300(unsigned int p0);
void SetStandingsEndCallback(void (*a)(void));
void SetStandingsKartEliminatedCallback(void (*p0)(u16 a));
void func_020a233c(s32 (*p0)(u16 a, u16 b));
void func_020a2350(unsigned int p0);
void func_020a2364(unsigned int p0);
KartBalloons *func_020a2378(void);
void func_020a238c(KartBalloons *p0);
