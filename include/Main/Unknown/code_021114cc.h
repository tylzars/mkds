#pragma once

#include "types.h"

// The Record scene object: runs one of the five Record screens at a time and switches between them on request.
typedef struct RecordScreenCallbacks {
    /* 00 */ void (*mInit)(void *);
    /* 04 */ void (*mRelease)(void);
    /* 08 */ void (*mAdvance)(void);
    /* 0c */ void (*mWriteOffsets)(void);
    /* 10 */ void (*mWriteRegisters)(void);
} RecordScreenCallbacks;

typedef struct RecordScene {
    /* 00 */ void *mHeap;
    /* 04 */ void *mStateHeap;
    /* 08 */ s32 mScreen;
    /* 0c */ s32 mNextScreen;
    /* 10 */ s32 mPrevScreen;
    /* 14 */ s16 mPrevScene;
    /* 16 */ s16 mNextScene;
    /* 18 */ RecordScreenCallbacks mScreenCallbacks;
    /* 2c */ s32 mRegistersTimer;
    /* 30 */ s16 mPageIndex;
    /* 32 */ s16 mIndex;
} RecordScene;

void AdvanceRecordScene(void);
