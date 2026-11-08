#pragma once

#include "types.h"
#include "Main/Unknown/unk_021759c0.h" // MinuteSecondMillisecondTime

// Minutes, seconds and milliseconds summed part by part (seconds and milliseconds can pass 59 and 999).
typedef struct MinuteSecondMillisecondTotal {
    /* 00 */ s32 mMinutes;
    /* 04 */ s32 mSeconds;
    /* 08 */ s32 mMilliseconds;
} MinuteSecondMillisecondTotal;

s32 ComputeTimeDifference(MinuteSecondMillisecondTotal *first, MinuteSecondMillisecondTotal *second,
                          MinuteSecondMillisecondTime *difference);
void func_020b1a34(void);
