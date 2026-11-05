#pragma once

#include "types.h"

// Seven decimal digits of a time (SplitTimeDigits): minutes tens and ones, seconds tens and ones, milliseconds
// hundreds, tens and ones. Embedded in the race timer object, the time difference and the digit object of
// code_020cffd0.c; code_020c5dd8.c also fills all seven with 0xb (blank) for a missing time.
typedef struct TimeDigits {
    /* 00 */ s32 mUnk_00[7];
} TimeDigits;

void SortIndicesByKey(s32 *a, s32 *b, s32 c);
void SplitTimeDigits(s32 a, s32 b, s32 c, TimeDigits *d);
