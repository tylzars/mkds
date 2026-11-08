#pragma once

#include "types.h"

// Two halfwords passed and stored as one value (rows of OrthoQuad, SetupOrthoQuad's second argument).
typedef union {
    u32 mWord;
    struct {
        /* 00 */ s16 mUnk_00;
        /* 02 */ s16 mUnk_02;
    } mHalf;
} HalfwordPair;

// One of the four quads: corner pairs, their velocities, the start pair, the update function, a mode and a timer.
typedef struct OrthoQuad OrthoQuad;

struct OrthoQuad {
    /* 00 */ s16 mCorners[4][2];
    // Per corner: the offset SetupOrthoQuad picks, scaled by a motion table; later a velocity added to the corners.
    /* 10 */ s16 mCornerVelocities[4][2];
    /* 20 */ s16 mStartPair[2];
    /* 24 */ void (*mUpdateFunction)(OrthoQuad *p);
    // 1 once the velocities were set from the corners; the update function then adds them to the corners.
    /* 28 */ u32 mVelocityMode;
    // Counts down from the start delay and keeps counting below 0 in the later update functions.
    /* 2c */ s32 mTimer;
    // Random 0 to 5, new every 16th call; 4 and 5 match no corner.
    /* 30 */ u32 mPickedCornerIndex;
};

void SkipOrthoQuadsHoldAndSetVelocities(int kartIndex);
void SetOrthoQuadVelocitiesFromCorners(OrthoQuad *quad);
