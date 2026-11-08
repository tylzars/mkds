#include "Main/Unknown/code_0210bcf4.h"
#include "code_0212d214.h"

#include "Main/Unknown/unk_0216c000.h"
#include "Main/Unknown/code_0210b000.h"
#include "Main/Unknown/code_0210e000.h"
#include "Main/Unknown/code_0210c1b0.h"
#include "Main/Unknown/code_0210bafc.h"
#include "Main/Unknown/code_0210cfe8.h"
#include "code_0212bcac.h"
#include "Main/Unknown/unk_0217d000.h"
#include "code_020172d0.h"
#include "Main/Unknown/code_0210bce0.h"
#include "Main/Unknown/code_0210d078.h"
#include "Main/Unknown/code_0210d0b4.h"
#include "code_0201750c.h"

void func_0210c134(SoundSource *source, u32 positionSource) {
    void *startFunction;
    void *trackParamsFunction;
    NNS_FndInitList(&source->mPlayingSounds, 8);
    startFunction = (void *) StartPlayingSoundSeqArc;
    source->mUnk_38 = 1;
    trackParamsFunction = (void *) SetPlayingSoundTrackParams;
    source->mStartSeqFunction = startFunction;
    source->mTrackParamsFunction = trackParamsFunction;
    source->mSourceFlags = 0;
    source->mOwnerPosSource = positionSource;
    source->mUpdateListIndex = 3;
    ClearThreeWords((u32 *) source->mUnk_1c);
    ClearThreeWords((u32 *) source);
    TryAppendListObject(&data_0217d028, source);
}

void func_0210c0bc(SoundSource *source) {
    void *sound;

    StopSoundsStartedWhileRequested(source, 0);
    for (sound = source->mPlayingSounds.mHead; sound != NULL; sound = source->mPlayingSounds.mHead) {
        RemoveListObject(&source->mPlayingSounds, (u8 *) sound);
    }
    if (source->mUpdateListIndex != 3) {
        RemoveListObject(&data_0217d048[source->mUpdateListIndex], (u8 *) source);
        source->mUpdateListIndex = 3;
    }
}

void func_0210c084(PlayingSound *sound, u32 fadeSteps) {
    NNS_SndPlayerStopSeq(&sound->mSeqPlayer, fadeSteps);
    sound->mFlags &= ~4;
    sound->mFlags &= ~8;
    sound->mFlags &= ~2;
}

void RefreshSoundSourceUpdateList(SoundSource *source) {
    PlayingSound *sound;
    u32 updateListIndex;
    u8 soundFlags;

    updateListIndex = 3;
    for (sound = source->mPlayingSounds.mHead; sound != NULL;
         sound = NNS_FndGetNextListObject(&source->mPlayingSounds, sound)) {
        soundFlags = sound->mFlags;
        if (soundFlags & 2) {
            updateListIndex = 0;
            break;
        }
        if (soundFlags & 8 || soundFlags & 1) {
            updateListIndex = 1;
        }
    }
    if (source->mUpdateListIndex != updateListIndex) {
        if (source->mUpdateListIndex != 3) {
            RemoveListObject(&data_0217d048[source->mUpdateListIndex], (u8 *) source);
            source->mUpdateListIndex = 3;
        }
        if (updateListIndex != 3) {
            TryAppendListObject(&data_0217d048[updateListIndex], source);
            source->mUpdateListIndex = updateListIndex;
        }
    }
}

void func_0210bf24(u32 seqArcNo, u32 soundId, u32 positionSource, void *request) {
    PlayingSound *sound;
    NNSFndList *sourceList;

    if (data_0217d084.mUnk_10 == 0) {
        return;
    }
    sound = TakeSoundHandleEntry(&data_0217d034);
    func_0210c084(sound, 0);
    sourceList = sound->mUnk_10;
    if (sourceList != NULL) {
        RemoveListObject(sourceList, (u8 *) sound);
        RefreshSoundSourceUpdateList((SoundSource *) (sourceList - 1));
    }
    ResetPlayingSound(sound);
    func_0210bcf4(seqArcNo, soundId, positionSource, &sound->mSeqPlayer, request);
}

u32 func_0210bee8(u32 seqArcNo, u32 soundId, u32 positionSource, NNSSndSeqPlayer **handle, void *request) {
    if (data_0217d084.mUnk_10 == 0) {
        return seqArcNo;
    }
    return func_0210bcf4(seqArcNo, soundId, positionSource, handle, request);
}

u32 func_0210bcf4(u32 seqArcNo, u32 soundId, u32 positionSource, NNSSndSeqPlayer **handle, void *request) {
    SoundParams params;
    u32 v;
    u32 runThisCall;
    u32 countThisPass;
    s32 priority;
    s32 volumeForPriority;

    v = 0;
    runThisCall = v;
    if (data_0217d084.mMode == 4) {
        return v;
    }
    if (data_0217d084.mMode == 0) {
        return v;
    }
    if (*handle == NULL) {
        v = 1;
        runThisCall = v;
    } else {
        countThisPass = data_0217d024[0];
        data_0217d024[0] = countThisPass + 1;
        if ((countThisPass & 3) == data_0217d010[0]) {
            runThisCall = 1;
        }
    }
    if (runThisCall == 0) {
        return runThisCall;
    }
    params.mSource = NULL;
    params.mPositionSource = positionSource;
    params.mUnk_20 = request;
    params.mVolume = 0;
    params.mUnk_1c = 0;
    params.mPan = 0;
    if (positionSource == 0) {
        params.mDistance = 0;
        params.mVolume = 0x7f;
        params.mUnk_1c = 0x7f;
        params.mPan = 0;
    } else {
        params.mDistance = data_0217d018(&params);
        params.mUnk_1c = params.mVolume = data_0217d014(&params);
        params.mPan = data_0217d01c(&params);
    }
    if (params.mVolume <= 0) {
        if (*handle == NULL) {
            return (u32) *handle;
        }
        return NNS_SndPlayerStopSeq(handle, 0);
    }
    volumeForPriority = params.mUnk_1c;
    priority = volumeForPriority + (NNS_SndArcGetSeqArcParam(seqArcNo, soundId)->mPlayerPrio - 0x40);
    if (priority > 0) {
        if (priority >= 0x7f) {
            priority = 0x7f;
        }
    } else {
        priority = 0;
    }
    if (v != 0) {
        data_0216cb1c[0](handle, seqArcNo, soundId, priority);
    }
    NNS_SndPlayerSetVolume(handle, params.mVolume);
    NNS_SndPlayerSetPlayerPriority(handle, priority);
    return NNS_SndPlayerSetTrackPan(handle, data_0216cb20, params.mPan);
}
