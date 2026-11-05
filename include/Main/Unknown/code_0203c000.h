#pragma once

#include "types.h"

void func_0203c2e4(u16 a);
void GetKartFinishTime(s32 a, u8 *b, u8 *c, u16 *d);
void GetKartLapTime(s32 a, u16 b, u8 *c, u8 *d, u16 *e);
u32 GetKartRank(u32 param_1);
s32 IsKartEnded(u32 param_1);
BOOL IsKartOnLastLap(u16 a);
u16 GetKartBestLapTime(u16 a, u8 *b, u8 *c, u16 *d);
void func_0203cd04(u16 a);
void func_0203c98c(void);
void GetRaceClockTime(u8 *a, u8 *b, u16 *c);
void UpdateRaceProgress(void);
