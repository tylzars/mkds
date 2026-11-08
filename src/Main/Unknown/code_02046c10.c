#include "Main/Unknown/code_02046c10.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_0210f0d8.h"
#include "Main/Unknown/code_0210f068.h"
#include "Main/Unknown/code_0210f090.h"
#include "Main/Unknown/code_0210f130.h"
#include "tp.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/unk_021759c0.h"

void StartTouchAutoSampling(void) {
    if (gTouchMicInput->mTouchAutoSampling != 0) {
        return;
    }
    TP_RequestAutoSamplingStartAsync(0xa, 4, gTouchMicInput->mAutoSamples, 5);
    TP_WaitBusy(2);
    TP_CheckError(2);
    gTouchMicInput->mTouchAutoSampling = 1;
}

void StartMicInput(void *heap) {
    if (gTouchMicInput->mMicAutoSampling != 0) {
        return;
    }
    gTouchMicInput->mMicBuffer = HeapAllocAligned(heap, 0x420, 0x20);
    SetupMicAutoSampling(gTouchMicInput->mMicBuffer);
    StartMicAutoSampling(gTouchMicInput->mMicBuffer);
    gTouchMicInput->mMicAutoSampling = 1;
    gTouchMicInput->mUnk_30_2 = 0;
    gTouchMicInput->mMicOverThreshold = 0;
}

void StopTouchAutoSampling(void) {
    if (gTouchMicInput->mTouchAutoSampling == 0) {
        return;
    }
    TP_RequestAutoSamplingStopAsync();
    TP_WaitBusy(4);
    TP_CheckError(4);
    gTouchMicInput->mTouchAutoSampling = 0;
}

void StopMicInput(void) {
    if (gTouchMicInput->mMicAutoSampling == 0) {
        return;
    }
    StopMicAutoSampling(gTouchMicInput->mMicBuffer);
    gTouchMicInput->mMicBuffer = NULL;
    gTouchMicInput->mMicAutoSampling = 0;
    gTouchMicInput->mUnk_30_2 = 0;
}

void func_02046e84(void) {
    TouchMicInput *touchMicInput;

    touchMicInput = gTouchMicInput;
    if (touchMicInput->mMicAutoSampling == 0) {
        return;
    }
    if (touchMicInput->mUnk_30_2 == 0) {
        func_0210f07c(touchMicInput->mMicBuffer);
    }
    gTouchMicInput->mUnk_30_2 = 1;
}

void func_02046e24(void) {
    TouchMicInput *touchMicInput;

    touchMicInput = gTouchMicInput;
    if (touchMicInput->mMicAutoSampling == 0) {
        return;
    }
    if (touchMicInput->mUnk_30_2) {
        func_0210f068(touchMicInput->mMicBuffer);
    }
    gTouchMicInput->mUnk_30_2 = 0;
}

void UpdateTouchMicInput(void) {
    TouchMicInput *touchMicInput;
    u32 latestIndex;

    latestIndex = TP_GetLatestIndexInAuto();
    touchMicInput = gTouchMicInput;
    touchMicInput->mCalibratedPoint = *(TPData *) &touchMicInput->mAutoSamples[latestIndex];
    TP_GetCalibratedPoint(&touchMicInput->mCalibratedPoint, &touchMicInput->mCalibratedPoint);
    if (gTouchMicInput->mMicAutoSampling) {
        gTouchMicInput->mMicOverThreshold = func_0210f090(gTouchMicInput->mMicBuffer) > 0x14;
    }
}

void func_02046ca8(InputSlotPair *pair, s32 b, s32 c) {
    TPData point;
    u32 pointY;
    s32 pointX;

    if (gTouchMicInput->mTouchAutoSampling) {
        pointX = (b >> 8) & 0xff;
        pointY = b & 0xff;
        if (pointY > 0xbf) {
            point.mY = 0;
            point.mX = 0;
            point.mTouch = 0;
        } else {
            point.mX = pointX;
            point.mY = pointY;
            point.mTouch = 1;
        }
        *(TPData *) &pair->mPrevPairX = *(TPData *) pair;
        *(TPData *) pair = point;
        if (pair->mHasPair != 0) {
            pair->mNoPairCount = 0;
        } else if (pair->mNoPairCount <= 5) {
            pair->mNoPairCount++;
        }
    }
    if (gTouchMicInput->mMicAutoSampling) {
        pair->mUnk_12[0] = c;
    }
}

void func_02046c74(void) {
    func_0210f114(gTouchMicInput->mMicBuffer);
    gTouchMicInput = NULL;
}

u16 GetPackedTouchPoint(void) {
    TouchMicInput *touchMicInput;
    TPData *calibratedPoint;
    u32 pointX;
    u32 pointY;

    touchMicInput = gTouchMicInput;
    calibratedPoint = &touchMicInput->mCalibratedPoint;
    if (!touchMicInput->mTouchAutoSampling || calibratedPoint->mTouch == 0 || calibratedPoint->mValidity != 0) {
        pointX = 0xff;
        pointY = pointX;
    } else {
        pointX = calibratedPoint->mX & 0xff;
        pointY = calibratedPoint->mY & 0xff;
    }
    return pointY + (pointX << 8);
}
