#pragma once

#include "types.h"

// Only meaningful after all laps.
u16 GetKartBestLapTime(u16 kartIndex, u8 *outMinute, u8 *outSecond, u16 *outMillisecond);
void GetKartLapTime(s32 kartIndex, u16 lap, u8 *outMinute, u8 *outSecond, u16 *outMillisecond);
void GetKartFinishTime(s32 kartIndex, u8 *outMinute, u8 *outSecond, u16 *outMillisecond);
// True for status 1, 2 and 3.
s32 IsKartEnded(u32 kartIndex);
