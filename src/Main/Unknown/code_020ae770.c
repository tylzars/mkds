#include "Main/Unknown/code_020ae770.h"

#pragma optimize_for_size on

#pragma thumb on

// Splits minutes, seconds and milliseconds into the seven digits of a TimeDigits (no clamping; the callers pass minutes
// < 100).
void SplitTimeDigits(s32 a, s32 b, s32 c, TimeDigits *d) {
    d->mDigits[0] = a / 10;
    d->mDigits[1] = a % 10;
    d->mDigits[2] = b / 10;
    d->mDigits[3] = b % 10;
    d->mDigits[4] = c / 100;
    d->mDigits[5] = (c - d->mDigits[4] * 100) / 10;
    d->mDigits[6] = c % 10;
}

// Exchange sort in place: afterwards keys[indices[0]] <= keys[indices[1]] <= ... for the first count entries (a smaller
// key first; unstable); all callers pass 0..mKartCount-1 in indices and negate the keys for a descending order.
void SortIndicesByKey(s32 *a, s32 *b, s32 c) {
    s32 i;
    s32 j;
    s32 *p;
    s32 *q;
    s32 x;
    s32 y;
    s32 u;
    s32 w;

    for (i = 0; i < c - 1; i++) {
        j = c - 1;
        p = &a[i];
        for (; j > i; j--) {
            q = &a[j];
            x = a[j];
            y = *p;
            u = b[y];
            w = b[x];
            if (u > w) {
                *p = x;
                *q = y;
            }
        }
    }
}

#pragma thumb off
