#pragma once

#include "types.h"

typedef struct Unk020c06c4 Unk020c06c4;

// Object behind gRaceGoalM, 0x1c bytes allocated by InitRaceGoalM.
typedef struct RaceGoalM {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUpdateFrames;
    /* 08 */ s32 mRankIndex;
    /* 0c */ s32 mPointsGained;
    /* 10 */ u16 mFirstPlaceKartIndex;
    /* 12 */ u8 mUnk_12[2];
    /* 14 */ s32 mUnk_14;
    /* 18 */ s32 mUnk_18;
} RaceGoalM;

void InitRaceLinkLevel(void);
void DrawRaceGoalMMissionRun(Unk020c06c4 *a);
void DrawRaceGoalMGrandPrix(Unk020c06c4 *a);
void DrawRaceGoalM(Unk020c06c4 *a);
void UpdateRaceGoalM(void);
