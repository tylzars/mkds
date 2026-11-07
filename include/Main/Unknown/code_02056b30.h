#pragma once

#include "types.h"

typedef struct PackedGrandPrixRecord PackedGrandPrixRecord;
typedef struct PackedCourseTimeRecord PackedCourseTimeRecord;

// A saved record: the time, the name, the character and the kart; the Grand Prix kind also has a cup rank.
typedef struct TimeRecord {
    /* 00 */ u16 mMillisecond;
    /* 02 */ u8 mMinute;
    /* 03 */ u8 mSecond;
    /* 04 */ u16 mName[10];
    /* 18 */ u8 mFilled;
    /* 19 */ u8 mCharacterIndex;
    /* 1a */ u8 mKartIndex;
    /* 1b */ u8 mUnk_1b;
    /* 1c */ u8 mCupRank;
    /* 1d */ u8 mUnk_1d;
    /* 1e */ u8 mUnk_1e;
    /* 1f */ u8 mUnk_1f;
} TimeRecord;
// Slot of a course's time records that holds the best lap; slots 0 to 4 are the ranked race times.
#define TIME_RECORD_BEST_LAP 5

void func_02056b30(PackedGrandPrixRecord *a, TimeRecord *b);
s32 func_02056bc0(s32 a, s32 b, TimeRecord *c);
void func_02056c0c(PackedCourseTimeRecord *a, TimeRecord *b);
