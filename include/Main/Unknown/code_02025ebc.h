#pragma once

#include "types.h"

// Eases an s16 from a start to an end value while a counter steps from 0 up to its limit, and back down.
typedef struct Interpolation {
    /* 00 */ s32 mState;
    /* 04 */ s32 mCounter;
    /* 08 */ s32 mCounterLimit;
    /* 0c */ s16 mStartValue;
    /* 0e */ s16 mEndValue;
} Interpolation;

s16 GetInterpolatedValue(Interpolation *interpolation);
