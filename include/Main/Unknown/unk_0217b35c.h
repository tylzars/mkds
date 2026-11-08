#pragma once

#include "types.h"

// Object behind gRaceEnd, 0x10 bytes, allocated by InitRaceEnd.
typedef struct RaceEnd {
    /* 00 */ s32 mEndFrames;
    /* 04 */ BOOL mStemSetRequested;
    // Calls counted while the request flag is set; never zeroed after allocation, so only the first request is served.
    /* 08 */ s32 mStemSetRequestFrames;
    /* 0c */ BOOL mResultsSet;
} RaceEnd;

extern RaceEnd *gRaceEnd;
