#pragma once

#include "types.h"
#include "code_0212d254.h" // Unk0212f788

// 16 bytes. InterpolatorStart sets mUnk_00, mUnk_04 and mUnk_0c and clears mUnk_08; InterpolatorStep raises mUnk_08 up
// to mUnk_0c; InterpolatorGetValue returns mUnk_00 + mUnk_08 * (mUnk_04 - mUnk_00) / mUnk_0c, or mUnk_04 once mUnk_08
// reaches mUnk_0c.
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
