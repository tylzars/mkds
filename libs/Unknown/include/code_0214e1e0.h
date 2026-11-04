#pragma once

#include "types.h"

// Four words; DateToDays checks each against a range, TimeToSeconds reads the first three.
typedef struct Unk0214e1e0 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
} Unk0214e1e0;

s64 DateTimeToSeconds(const Unk0214e1e0 *a, const Unk0214e1e0 *b);
