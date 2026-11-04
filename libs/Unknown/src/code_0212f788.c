#include "code_0212f788.h"

// Sets mUnk_00 to the current value of InterpolatorGetValue, mUnk_04 to b, mUnk_0c to c and clears mUnk_08.
void InterpolatorStart(Interpolator *a, s32 b, s32 c) {
    a->mFromValue = InterpolatorGetValue(a);
    a->mToValue = b;
    a->mTotalCount = c;
    a->mDoneCount = 0;
}

// Returns mUnk_00 + mUnk_08 * (mUnk_04 - mUnk_00) / mUnk_0c, or mUnk_04 once mUnk_08 reaches mUnk_0c.
s32 InterpolatorGetValue(Interpolator *a) {
    s32 n;

    if (a->mDoneCount >= a->mTotalCount) {
        return a->mToValue;
    }
    n = a->mFromValue;
    return n + a->mDoneCount * (a->mToValue - n) / a->mTotalCount;
}

// Raises mUnk_08 while it is below mUnk_0c.
void InterpolatorStep(Interpolator *a) {
    if (a->mDoneCount < a->mTotalCount) {
        a->mDoneCount++;
    }
}

// Returns whether mUnk_08 has reached mUnk_0c.
u32 InterpolatorIsDone(Interpolator *a) {
    return a->mDoneCount >= a->mTotalCount;
}

// Returns the 12-byte record b of a, or 0 when b is out of range or the first word of the record is -1.
u32 *func_0212f788(Unk0212f788 *a, s32 b) {
    u32 *p;

    if (b < 0) {
        return 0;
    }
    if (b >= a->mUnk_1c) {
        return 0;
    }
    p = (u32 *) ((u8 *) a->mUnk_20 + b * 12);
    if (*p == -1) {
        return 0;
    }
    return p;
}
