#include "Main/Unknown/code_020b1a34.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020b4000.h"
#include "code_0214d018.h"
#include "Main/Unknown/code_0203c5f8.h"

#pragma opt_arithtransformation off

// Absolute difference of two times (minutes, seconds, milliseconds) written to the out record (minutes capped to
// 99:59.999 from 100 minutes); returns non-zero when first >= second.
s32 ComputeTimeDifference(Unk020b1bf8 *first, Unk020b1bf8 *second, Unk020b1a34_0c *difference) {
    s32 firstMs;
    s32 secondMs;
    s32 differenceMs;
    BOOL firstNotLess;
    s32 minutes;
    s32 seconds;
    s32 milliseconds;

    firstMs = (first->mMinutes * 60 + first->mSeconds) * 1000 + first->mMilliseconds;
    secondMs = (second->mMinutes * 60 + second->mSeconds) * 1000 + second->mMilliseconds;
    firstNotLess = firstMs >= secondMs;
    if (firstNotLess != FALSE) {
        differenceMs = firstMs - secondMs;
    } else {
        differenceMs = secondMs - firstMs;
    }
    minutes = differenceMs / 60000;
    seconds = (differenceMs - minutes * 60000) / 1000;
    milliseconds = differenceMs % 1000;
    if (minutes < 100) {
        difference->mMinutes = minutes;
        difference->mSeconds = seconds;
        difference->mMilliseconds = milliseconds;
    } else {
        difference->mMinutes = 99;
        difference->mSeconds = 59;
        difference->mMilliseconds = 999;
    }
    return firstNotLess;
}

void func_020b1a34(void) {
    Unk020b1a34_0c referenceLap;
    Unk020b1a34_0c kartLap;
    Unk020b1a34_0c difference;
    Unk020b1bf8 totals[2];
    TimeDigits digits;
    u8 totalsIndex;
    u8 lap;

    if (gRaceSetup->mMode == MODE_GRAND_PRIX || gRaceSetup->mMode == MODE_TIME_ATTACK) {
        gRaceHud->mUnk_8dc = 1;
    }
    if (gRaceHud->mUseTimeDifference == 0) {
        return;
    }
    for (totalsIndex = 0; totalsIndex < 2; totalsIndex++) {
        totals[totalsIndex].mMinutes = 0;
        totals[totalsIndex].mSeconds = 0;
        totals[totalsIndex].mMilliseconds = 0;
    }
    for (lap = 1; lap <= func_020b4d2c(); lap++) {
        if (gRaceSetup->mMode == MODE_TIME_ATTACK) {
            MI_CpuCopy8(&gRaceSetup->mUnk_3ec[lap - 1], &referenceLap, 4);
        }
        totals[0].mMinutes += referenceLap.mMinutes;
        totals[0].mSeconds += referenceLap.mSeconds;
        totals[0].mMilliseconds += referenceLap.mMilliseconds;
        GetKartLapTime(GetFollowedKartOrEntryIndex(), lap, &kartLap.mMinutes, &kartLap.mSeconds,
                       &kartLap.mMilliseconds);
        totals[1].mMinutes += kartLap.mMinutes;
        totals[1].mSeconds += kartLap.mSeconds;
        totals[1].mMilliseconds += kartLap.mMilliseconds;
    }
    gRaceHud->mTimeDifferenceSign = ComputeTimeDifference(&totals[1], &totals[0], &difference);
    SplitTimeDigits(difference.mMinutes, difference.mSeconds, difference.mMilliseconds, &digits);
    gRaceHud->mTimeDifferenceDigits = digits;
}
