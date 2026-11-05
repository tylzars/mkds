#pragma once

#include "types.h"
#include "code_0212d214.h"

// 16 bytes. InterpolatorStart sets mFromValue, mToValue and mTotalCount and clears mDoneCount; InterpolatorStep raises
// mDoneCount up to mTotalCount; InterpolatorGetValue returns mFromValue + mDoneCount * (mToValue - mFromValue) /
// mTotalCount, or mToValue once mDoneCount reaches mTotalCount.
typedef struct Interpolator {
    /* 00 */ s32 mFromValue;
    /* 04 */ s32 mToValue;
    /* 08 */ s32 mDoneCount;
    /* 0c */ s32 mTotalCount;
} Interpolator;

u32 *func_0212f788(Unk0212f788 *a, s32 b);
u32 InterpolatorIsDone(Interpolator *a);
void InterpolatorStep(Interpolator *a);
s32 InterpolatorGetValue(Interpolator *a);
void InterpolatorStart(Interpolator *a, s32 b, s32 c);
