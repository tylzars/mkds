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

void func_02047054(void) {
    if (gTouchMicInput->mUnk_30_0 != 0) {
        return;
    }
    TP_RequestAutoSamplingStartAsync(0xa, 4, gTouchMicInput->mAutoSamples, 5);
    TP_WaitBusy(2);
    TP_CheckError(2);
    gTouchMicInput->mUnk_30_0 = 1;
}

void func_02046fb4(void *a) {
    if (gTouchMicInput->mUnk_30_1 != 0) {
        return;
    }
    gTouchMicInput->mMicBuffer = HeapAllocAligned(a, 0x420, 0x20);
    SetupMicAutoSampling(gTouchMicInput->mMicBuffer);
    StartMicAutoSampling(gTouchMicInput->mMicBuffer);
    gTouchMicInput->mUnk_30_1 = 1;
    gTouchMicInput->mUnk_30_2 = 0;
    gTouchMicInput->mUnk_30_3 = 0;
}

void func_02046f54(void) {
    if (gTouchMicInput->mUnk_30_0 == 0) {
        return;
    }
    TP_RequestAutoSamplingStopAsync();
    TP_WaitBusy(4);
    TP_CheckError(4);
    gTouchMicInput->mUnk_30_0 = 0;
}

void func_02046ee4(void) {
    if (gTouchMicInput->mUnk_30_1 == 0) {
        return;
    }
    StopMicAutoSampling(gTouchMicInput->mMicBuffer);
    gTouchMicInput->mMicBuffer = NULL;
    gTouchMicInput->mUnk_30_1 = 0;
    gTouchMicInput->mUnk_30_2 = 0;
}

void func_02046e84(void) {
    TouchMicInput *p;

    p = gTouchMicInput;
    if (p->mUnk_30_1 == 0) {
        return;
    }
    if (p->mUnk_30_2 == 0) {
        func_0210f07c(p->mMicBuffer);
    }
    gTouchMicInput->mUnk_30_2 = 1;
}

void func_02046e24(void) {
    TouchMicInput *p;

    p = gTouchMicInput;
    if (p->mUnk_30_1 == 0) {
        return;
    }
    if (p->mUnk_30_2) {
        func_0210f068(p->mMicBuffer);
    }
    gTouchMicInput->mUnk_30_2 = 0;
}

void func_02046d7c(void) {
    TouchMicInput *p;
    u32 i;

    i = TP_GetLatestIndexInAuto();
    p = gTouchMicInput;
    p->mCalibratedPoint = *(TPData *) &p->mAutoSamples[i];
    TP_GetCalibratedPoint(&p->mCalibratedPoint, &p->mCalibratedPoint);
    if (gTouchMicInput->mUnk_30_1) {
        gTouchMicInput->mUnk_30_3 = func_0210f090(gTouchMicInput->mMicBuffer) > 0x14;
    }
}

void func_02046ca8(Unk02175628_48 *a, s32 b, s32 c) {
    TPData d;
    u32 e;
    s32 f;

    if (gTouchMicInput->mUnk_30_0) {
        f = (b >> 8) & 0xff;
        e = b & 0xff;
        if (e > 0xbf) {
            d.mY = 0;
            d.mX = 0;
            d.mTouch = 0;
        } else {
            d.mX = f;
            d.mY = e;
            d.mTouch = 1;
        }
        *(TPData *) &a->mPrevPairX = *(TPData *) a;
        *(TPData *) a = d;
        if (a->mHasPair != 0) {
            a->mNoPairCount = 0;
        } else if (a->mNoPairCount <= 5) {
            a->mNoPairCount++;
        }
    }
    if (gTouchMicInput->mUnk_30_1) {
        a->mUnk_12[0] = c;
    }
}

void func_02046c74(void) {
    func_0210f114(gTouchMicInput->mMicBuffer);
    gTouchMicInput = NULL;
}

u16 func_02046c10(void) {
    TouchMicInput *p;
    TPData *q;
    u32 a;
    u32 b;

    p = gTouchMicInput;
    q = &p->mCalibratedPoint;
    if (!p->mUnk_30_0 || q->mTouch == 0 || q->mValidity != 0) {
        a = 0xff;
        b = a;
    } else {
        a = q->mX & 0xff;
        b = q->mY & 0xff;
    }
    return b + (a << 8);
}
