#pragma once

#include "types.h"

// The kart's place, 1 for first. In mode 5 reads the net table.
u32 GetKartRank(u32 param_1);
// The time jitters while the clock runs.
void GetRaceClockTime(u8 *a, u8 *b, u16 *c);
void func_0203c98c(void);
