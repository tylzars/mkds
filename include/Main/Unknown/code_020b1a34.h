#pragma once

#include "types.h"

// Three words: the code multiplies the first by 60, adds the second, multiplies by 1000 and adds the third.
typedef struct Unk020b1bf8 {
    /* 00 */ s32 mMinutes;
    /* 04 */ s32 mSeconds;
    /* 08 */ s32 mMilliseconds;
} Unk020b1bf8;

// Four bytes: a halfword and two bytes.
typedef struct Unk020b1a34_0c {
    /* 00 */ u16 mMilliseconds;
    /* 02 */ u8 mMinutes;
    /* 03 */ u8 mSeconds;
} Unk020b1a34_0c;

s32 ComputeTimeDifference(Unk020b1bf8 *first, Unk020b1bf8 *second, Unk020b1a34_0c *difference);
void func_020b1a34(void);
