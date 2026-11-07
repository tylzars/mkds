#pragma once

#include "types.h"

// Start sequence of the race, one record behind gRaceStartSequence (0xc bytes, allocated by InitRaceStartSequence, set
// NULL by func_020b36c8 in the release slot). mSequenceFrames starts at -0x78 (func_020b36a4), counts once mCounting is
// set, calls func_0203c98c at -1 and at 180 starts the race (StartRaceSounds, StartRace, mDone); the sounds at 0, 60,
// 120 (0x27) and 175 (0x28) are played by func_020b3410 from the HUD draw. The counter never stops (it keeps counting
// up to INT_MAX), and karts, map objects and HUD read it through GetRaceStartSequenceFrames as the frames since the
// countdown began.
typedef struct RaceStartSequence {
    // Counter gate: FALSE at allocation and in func_020b36a4; set TRUE by UpdateRaceStartSequence when
    // FinishDataSharingSync()
    // == 1 (in mode 5: when data_0217aa14->mUnk_75c & 2, with SetRaceUpdateFramesUnlimited /
    // SetMapObjectsRunUpdateLists) and never cleared otherwise.
    /* 00 */ BOOL mCounting;
    // Set to 1 once, at frame 180; 0 at allocation, never cleared; read by IsRaceStartSequenceDone.
    /* 04 */ s32 mDone;
    // -0x78 after func_020b36a4; +1 per call of UpdateRaceStartSequence while mCounting; saturates only at INT_MAX (the
    // 200 limit ends the one-shot checks, not the count).
    /* 08 */ s32 mSequenceFrames;
} RaceStartSequence;

extern RaceStartSequence *gRaceStartSequence;
