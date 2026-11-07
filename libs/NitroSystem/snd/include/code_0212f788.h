#pragma once

#include "types.h"
#include "code_0212d214.h"

// 16 bytes. Fades a value from NNSSndFader.mOrigin to NNSSndFader.mTarget over NNSSndFader.mFrame steps.
typedef struct NNSSndFader {
    /* 00 */ s32 mOrigin;
    /* 04 */ s32 mTarget;
    /* 08 */ s32 mCounter;
    /* 0c */ s32 mFrame;
} NNSSndFader;

NNSSndSeqArcSeqInfo *NNSi_SndSeqArcGetSeqInfo(Unk0212f788 *archive, s32 entry);
u32 NNSi_SndFaderIsFinished(NNSSndFader *fade);
void NNSi_SndFaderUpdate(NNSSndFader *fade);
s32 NNSi_SndFaderGet(NNSSndFader *fade);
void NNSi_SndFaderSet(NNSSndFader *fade, s32 target, s32 steps);
