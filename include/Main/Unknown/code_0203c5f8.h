#pragma once

#include "types.h"

// Only meaningful after all laps.
u16 GetKartBestLapTime(u16 a, u8 *b, u8 *c, u16 *d);
void GetKartLapTime(s32 a, u16 b, u8 *c, u8 *d, u16 *e);
void GetKartFinishTime(s32 a, u8 *b, u8 *c, u16 *d);
// True for status 1, 2 and 3.
s32 IsKartEnded(u32 param_1);
