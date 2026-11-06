#include "code_0212f788.h"

// Starts a fade from the current value to target over steps.
void NNSi_SndFaderSet(NNSSndFader *fade, s32 target, s32 steps) {
    fade->mOrigin = NNSi_SndFaderGet(fade);
    fade->mTarget = target;
    fade->mFrame = steps;
    fade->mCounter = 0;
}

// Returns NNSSndFader.mOrigin moved toward NNSSndFader.mTarget by NNSSndFader.mCounter of NNSSndFader.mFrame steps;
// NNSSndFader.mTarget once the counter has reached the step count.
s32 NNSi_SndFaderGet(NNSSndFader *fade) {
    s32 start;

    if (fade->mCounter >= fade->mFrame) {
        return fade->mTarget;
    }
    start = fade->mOrigin;
    return start + fade->mCounter * (fade->mTarget - start) / fade->mFrame;
}

// Advances NNSSndFader.mCounter by one step until it reaches NNSSndFader.mFrame.
void NNSi_SndFaderUpdate(NNSSndFader *fade) {
    if (fade->mCounter < fade->mFrame) {
        fade->mCounter++;
    }
}

// Returns whether NNSSndFader.mCounter has reached NNSSndFader.mFrame.
u32 NNSi_SndFaderIsFinished(NNSSndFader *fade) {
    return fade->mCounter >= fade->mFrame;
}

// Returns record number entry (12 bytes) of the sequence archive, or 0 when entry is out of range or the record's first
// word is -1.
u32 *NNSi_SndSeqArcGetSeqInfo(Unk0212f788 *archive, s32 entry) {
    u32 *record;

    if (entry < 0) {
        return 0;
    }
    if (entry >= archive->mUnk_1c) {
        return 0;
    }
    record = (u32 *) ((u8 *) archive->mUnk_20 + entry * 12);
    if (*record == -1) {
        return 0;
    }
    return record;
}
