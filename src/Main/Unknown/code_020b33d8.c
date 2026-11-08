#include "Main/Unknown/code_020b33d8.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02053e74.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_02089ef4.h"

#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_02061000.h"
#include "Main/Unknown/code_02054000.h"
#include "Main/Unknown/code_02089000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02105ec0.h"
#include "Main/Unknown/code_02108ea0.h"
#include "Main/Unknown/code_0210dc7c.h"
#include "Main/Unknown/code_020d3c7c.h"
#include "Main/Unknown/code_020b1de4.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "code_0212bcac.h"
#include "code_0212df7c.h"
#include "Main/Unknown/code_020b36c8.h"
#include "Main/Unknown/code_020b36dc.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_0203c8dc.h"

void InitRaceStartSequence(void) {
    gRaceStartSequence = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0xc);
    gRaceStartSequence->mCounting = FALSE;
    gRaceStartSequence->mDone = 0;
    gRaceStartSequence->mSequenceFrames = 0;
}

u32 ClearRaceStartSequencePointer(void) {
    u32 pointerAddress;
    u32 nullValue;
    pointerAddress = (u32) &gRaceStartSequence;
    nullValue = 0u;
    *(u32 *) ((pointerAddress) + (0)) = nullValue;
    return pointerAddress;
}

void ResetRaceStartSequenceFrames(void) {
    gRaceStartSequence->mCounting = FALSE;
    gRaceStartSequence->mSequenceFrames = -0x78;
}

// Per-frame step from func_020af66c: no sounds (they are in the draw, UpdateRaceStartSequenceSounds).
void UpdateRaceStartSequence(void) {
    RaceStartSequence *sequence = gRaceStartSequence;
    s32 frames;
    s32 *framesAddress;

    if (sequence->mCounting != FALSE) {
        frames = sequence->mSequenceFrames;
        if (frames < 200) {
            sequence->mSequenceFrames = frames + 1;
            if (frames == -1) {
                StartRaceInput();
                return;
            }
            if (frames != 180) {
                return;
            }
            StartRaceSounds();
            StartRace();
            gRaceStartSequence->mDone = 1;
            return;
        }
        framesAddress = &sequence->mSequenceFrames;
        if (frames < 0x7fffffff) {
            *framesAddress = frames + 1;
        }
        return;
    }
    if (gRaceSetup->mMode == 5) {
        if ((data_0217aa14->mUnk_75c & 2) == 0) {
            return;
        }
        sequence->mCounting = TRUE;
        SetRaceUpdateFramesUnlimited();
        SetMapObjectsRunUpdateLists();
        return;
    }
    if (FinishDataSharingSync() == 1) {
        gRaceStartSequence->mCounting = TRUE;
    }
}

void UpdateRaceStartSequenceSounds(void) {
    NNSSndSeqPlayer **seqPlayer;
    s32 frames = gRaceStartSequence->mSequenceFrames;

    if (frames < -21) {
        return;
    }
    if (frames >= 200) {
        return;
    }
    if (frames == 0 || frames == 60 || frames == 120) {
        if (data_0217c780 & 1) {
            seqPlayer = TakeSoundHandleEntry(func_02108ea0(0));
            if (data_0217d084.mUnk_0c != 0) {
                if (*seqPlayer != NULL) {
                    NNS_SndPlayerStopSeq(seqPlayer, 0);
                }
                if (*seqPlayer != NULL) {
                    NNS_SndPlayerStopSeq(seqPlayer, 0);
                }
                NNS_SndArcPlayerStartSeqArc(seqPlayer, 0, 0x27);
            }
        }
    }
    if (frames == 175) {
        if (data_0217c780 & 1) {
            seqPlayer = TakeSoundHandleEntry(func_02108ea0(0));
            if (data_0217d084.mUnk_0c != 0) {
                if (*seqPlayer != NULL) {
                    NNS_SndPlayerStopSeq(seqPlayer, 0);
                }
                if (*seqPlayer != NULL) {
                    NNS_SndPlayerStopSeq(seqPlayer, 0);
                }
                NNS_SndArcPlayerStartSeqArc(seqPlayer, 0, 0x28);
            }
        }
    }
    if (frames == -21) {
        SetStemSet(0);
    }
    if (frames != 180) {
        return;
    }
    SetStemSet(1);
}

s32 GetRaceStartSequenceFrames(void) {
    if (gRaceStartSequence != NULL) {
        return gRaceStartSequence->mSequenceFrames;
    }
    return -0x78;
}

s32 IsRaceStartSequenceDone(void) {
    if (gRaceStartSequence != NULL) {
        return gRaceStartSequence->mDone;
    }
    return 0;
}
