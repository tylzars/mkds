#include "Main/Unknown/code_0210c1b0.h"

#include "Main/Unknown/unk_0216c000.h"
#include "Main/Unknown/code_0210b000.h"
#include "Main/Unknown/code_0210e000.h"
#include "code_0212bcac.h"
#include "code_0212d214.h"
#include "Main/Unknown/code_0210bcf4.h"
#include "Main/Unknown/code_0210bafc.h"
#include "Main/Unknown/code_0210cfe8.h"
#include "Main/Unknown/code_0210bce0.h"
#include "Main/Unknown/code_0210e328.h"
#include "Main/Unknown/unk_0217d000.h"
#include "code_020172d0.h"

#pragma opt_loop_invariants off

void func_0210cc3c(SoundSource *source) {
    PlayingSound *sound;
    PlayingSound *removedSound;
    u32 v;
    u32 hadBit8;

    v = 0;
    if (data_0217d084.mUnk_10 == 0) {
        return;
    }
    if ((source->mSourceFlags & 1) == 0) {
        if (source->mSourceFlags & 2) {
            StopSoundsStartedWhileRequested(source, 0);
        }
        source->mSourceFlags &= ~2;
        if ((source->mSourceFlags & 4) == 0) {
            return;
        }
        if ((source->mSourceFlags & 1) == 0) {
            source->mSourceFlags |= 1;
        } else {
            source->mSourceFlags &= ~1;
        }
        source->mSourceFlags &= ~4;
        return;
    }
    source->mSourceFlags |= 2;
    if (source->mSourceFlags & 4) {
        if ((source->mSourceFlags & 1) == 0) {
            source->mSourceFlags |= 1;
        } else {
            source->mSourceFlags &= ~1;
        }
        source->mSourceFlags &= ~4;
    }
    sound = source->mPlayingSounds.mHead;
    while (sound != NULL) {
        hadBit8 = (sound->mFlags & 8) != 0;
        sound->mFlags &= ~8;
        if (sound->mSeqPlayer != NULL) {
            if (sound->mFlags & 4) {
                if (hadBit8 == 0) {
                    removedSound = sound;
                    sound = NNS_FndGetNextListObject(&source->mPlayingSounds, sound);
                    NNS_SndPlayerStopSeq(&removedSound->mSeqPlayer, 0);
                    removedSound->mFlags &= ~4;
                    removedSound->mFlags &= ~8;
                    removedSound->mFlags &= ~2;
                    RemoveListObject(&source->mPlayingSounds, removedSound);
                    v = 1;
                    continue;
                }
            } else if (sound->mFlags & 1) {
                if (source->mUpdateListIndex == 3) {
                    TryAppendListObject(&data_0217d054, source);
                    source->mUpdateListIndex = 1;
                }
            }
        } else if ((sound->mFlags & 2) == 0) {
            removedSound = sound;
            sound = NNS_FndGetNextListObject(&source->mPlayingSounds, sound);
            NNS_SndPlayerStopSeq(&removedSound->mSeqPlayer, 0);
            removedSound->mFlags &= ~4;
            removedSound->mFlags &= ~8;
            removedSound->mFlags &= ~2;
            RemoveListObject(&source->mPlayingSounds, removedSound);
            v = 1;
            continue;
        }
        sound = NNS_FndGetNextListObject(&source->mPlayingSounds, sound);
    }
    if (v == 0) {
        return;
    }
    v = 3;
    for (sound = source->mPlayingSounds.mHead; sound != NULL;
         sound = NNS_FndGetNextListObject(&source->mPlayingSounds, sound)) {
        if (sound->mFlags & 2) {
            v = 0;
            break;
        }
        if (sound->mFlags & 8 || sound->mFlags & 1) {
            v = 1;
        }
    }
    if (source->mUpdateListIndex != v) {
        if (source->mUpdateListIndex != 3) {
            RemoveListObject(&data_0217d048[source->mUpdateListIndex], source);
            source->mUpdateListIndex = 3;
        }
        if (v != 3) {
            TryAppendListObject(&data_0217d048[v], source);
            source->mUpdateListIndex = v;
        }
    }
}

static inline s32 func_0210ca4c_inline(u32 volumeForPriority, u8 seqArcNo, u16 soundId) {
    s32 priority = volumeForPriority + (NNS_SndArcGetSeqArcParam(seqArcNo, soundId)->mPlayerPrio - 0x40);
    if (priority > 0) {
        if (priority >= 0x7f) {
            priority = 0x7f;
        }
        return priority;
    }
    return 0;
}

u32 SetPlayingSoundsParams(SoundSource *source) {
    SoundParams params;
    s32 n;
    PlayingSound *sound;

    n = source->mOwnerPosSource;
    params.mSource = source;
    params.mPositionSource = n;
    params.mUnk_20 = NULL;
    params.mVolume = 0;
    params.mUnk_1c = 0;
    params.mPan = 0;
    if (params.mPositionSource == 0) {
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
        func_0210c0bc(source);
        return 0;
    }
    for (sound = source->mPlayingSounds.mHead; sound != NULL;
         sound = NNS_FndGetNextListObject(&source->mPlayingSounds, sound)) {
        n = -1;
        if (sound->mFlags & 2) {
            n = func_0210ca4c_inline(params.mUnk_1c, sound->mSeqArcNo, sound->mSoundId);
            source->mStartSeqFunction(source, sound, n);
            sound->mFlags &= ~2;
        }
        if (sound->mSeqPlayer != NULL) {
            if (n == -1) {
                n = func_0210ca4c_inline(params.mUnk_1c, sound->mSeqArcNo, sound->mSoundId);
            }
            NNS_SndPlayerSetVolume(&sound->mSeqPlayer, params.mVolume);
            NNS_SndPlayerSetPlayerPriority(&sound->mSeqPlayer, n);
            NNS_SndPlayerSetTrackPan(&sound->mSeqPlayer, data_0216cb20, params.mPan);
            source->mTrackParamsFunction(source, sound, &params);
        }
    }
    return 1;
}

PlayingSound *StartSoundEx(SoundSource *source, u32 seqArcNo, u32 soundId, u32 volume, s16 pitch) {
    PlayingSound *sound;
    PlayingSound *candidate;
    NNSFndList *sourceList;
    u32 matches;

    sound = NULL;
    if (data_0217d084.mUnk_10 == 0) {
        return sound;
    }
    if ((source->mSourceFlags & 1) == 0) {
        return sound;
    }
    for (candidate = source->mPlayingSounds.mHead; candidate != NULL;
         candidate = NNS_FndGetNextListObject(&source->mPlayingSounds, candidate)) {
        matches = (candidate->mSoundId == soundId) && (candidate->mSeqArcNo == seqArcNo);
        if (matches) {
            StopPlayingSound(source, candidate, 0);
            ResetPlayingSoundHandle(candidate);
            ClearThreeWords(&candidate->mUnk_08);
            candidate->mSeqArcNo = 0;
            candidate->mSoundId = 0;
            candidate->mFlags = 0;
            candidate->mPitch = 0;
            candidate->mVolume = 0x7f;
            sound = candidate;
            break;
        }
    }
    if (sound == NULL) {
        sound = TakeSoundHandleEntry(&data_0217d034);
        func_0210c084(sound, 0);
        sourceList = sound->mUnk_10;
        if (sourceList != NULL) {
            RemoveListObject(sourceList, sound);
            RefreshSoundSourceUpdateList((SoundSource *) (sourceList - 1));
        }
        ResetPlayingSound(sound);
    }
    ResetPlayingSoundHandle(sound);
    ClearThreeWords(&sound->mUnk_08);
    sound->mSeqArcNo = 0;
    sound->mSoundId = 0;
    sound->mFlags = 0;
    sound->mPitch = 0;
    sound->mVolume = 0x7f;
    sound->mSeqArcNo = seqArcNo;
    sound->mSoundId = soundId;
    sound->mFlags |= 2;
    sound->mVolume = volume;
    sound->mPitch = pitch;
    TryAppendListObject(&source->mPlayingSounds, sound);
    if (source->mUpdateListIndex != 0) {
        if (source->mUpdateListIndex != 3) {
            RemoveListObject(&data_0217d048[source->mUpdateListIndex], source);
            source->mUpdateListIndex = 3;
        }
        TryAppendListObject(data_0217d048, source);
        source->mUpdateListIndex = 0;
    }
    return sound;
}

PlayingSound *StartSoundWhileRequestedEx(SoundSource *source, u32 seqArcNo, u32 soundId, u32 volume, s16 pitch) {
    PlayingSound *sound;
    PlayingSound *candidate;
    NNSFndList *sourceList;
    u32 matches;

    sound = NULL;
    if (data_0217d084.mUnk_10 == 0) {
        return sound;
    }
    if ((source->mSourceFlags & 1) == 0) {
        return sound;
    }
    for (candidate = source->mPlayingSounds.mHead; candidate != NULL;
         candidate = NNS_FndGetNextListObject(&source->mPlayingSounds, candidate)) {
        if (candidate->mFlags & 4) {
            matches = (candidate->mSoundId == soundId) && (candidate->mSeqArcNo == seqArcNo);
            if (matches) {
                if (candidate->mSeqPlayer != NULL) {
                    candidate->mFlags |= 8;
                    candidate->mVolume = volume;
                    candidate->mPitch = pitch;
                    if (source->mUpdateListIndex == 3) {
                        TryAppendListObject(&data_0217d054, source);
                        source->mUpdateListIndex = 1;
                    }
                    return candidate;
                }
                StopPlayingSound(source, candidate, 0);
                ResetPlayingSoundHandle(candidate);
                ClearThreeWords(&candidate->mUnk_08);
                candidate->mSeqArcNo = 0;
                candidate->mSoundId = 0;
                candidate->mFlags = 0;
                candidate->mPitch = 0;
                candidate->mVolume = 0x7f;
                sound = candidate;
                break;
            }
        }
    }
    if (sound == NULL) {
        sound = TakeSoundHandleEntry(&data_0217d034);
        func_0210c084(sound, 0);
        sourceList = sound->mUnk_10;
        if (sourceList != NULL) {
            RemoveListObject(sourceList, sound);
            RefreshSoundSourceUpdateList((SoundSource *) (sourceList - 1));
        }
        ResetPlayingSound(sound);
    }
    ResetPlayingSoundHandle(sound);
    ClearThreeWords(&sound->mUnk_08);
    sound->mSeqArcNo = 0;
    sound->mSoundId = 0;
    sound->mFlags = 0;
    sound->mPitch = 0;
    sound->mVolume = 0x7f;
    sound->mSeqArcNo = seqArcNo;
    sound->mSoundId = soundId;
    sound->mFlags |= 2;
    sound->mVolume = volume;
    sound->mPitch = pitch;
    sound->mFlags |= 4;
    sound->mFlags |= 8;
    TryAppendListObject(&source->mPlayingSounds, sound);
    if (source->mUpdateListIndex != 0) {
        if (source->mUpdateListIndex != 3) {
            RemoveListObject(&data_0217d048[source->mUpdateListIndex], source);
            source->mUpdateListIndex = 3;
        }
        TryAppendListObject(data_0217d048, source);
        source->mUpdateListIndex = 0;
    }
    return sound;
}

static inline u32 func_0210c558_inline(PlayingSound *sound, u32 seqArcNo, u32 soundId) {
    return sound->mSoundId == soundId && sound->mSeqArcNo == seqArcNo;
}

void StopSoundEx(SoundSource *source, u32 seqArcNo, u32 soundId, u32 fadeSteps) {
    PlayingSound *sound;
    u32 matches;

    if (data_0217d084.mUnk_10 == 0) {
        return;
    }
    sound = source->mPlayingSounds.mHead;
    while (sound != NULL) {
        matches = (sound->mSeqPlayer != NULL) && func_0210c558_inline(sound, seqArcNo, soundId);
        if (matches) {
            StopPlayingSound(source, sound, fadeSteps);
            return;
        }
        sound = NNS_FndGetNextListObject(&source->mPlayingSounds, sound);
    }
}

void StopPlayingSound(SoundSource *source, PlayingSound *sound, u32 fadeSteps) {
    PlayingSound *entry;
    void *n;
    u32 updateListIndex;
    u32 soundFlags;

    NNS_SndPlayerStopSeq(&sound->mSeqPlayer, fadeSteps);
    sound->mFlags &= ~4;
    sound->mFlags &= ~8;
    sound->mFlags &= ~2;
    RemoveListObject(&source->mPlayingSounds, sound);
    updateListIndex = 3;
    for (entry = source->mPlayingSounds.mHead; entry != NULL;
         entry = NNS_FndGetNextListObject(&source->mPlayingSounds, entry)) {
        soundFlags = entry->mFlags;
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
            RemoveListObject(&data_0217d048[source->mUpdateListIndex], source);
            source->mUpdateListIndex = 3;
        }
        if (updateListIndex != 3) {
            TryAppendListObject(&data_0217d048[updateListIndex], source);
            source->mUpdateListIndex = updateListIndex;
        }
    }
}

void StopAllSoundsAndReleaseSoundSource(SoundSource *source) {
    PlayingSound *sound;

    for (sound = source->mPlayingSounds.mHead; sound != NULL; sound = source->mPlayingSounds.mHead) {
        NNS_SndPlayerStopSeq(&sound->mSeqPlayer, 0);
        sound->mFlags &= ~4;
        sound->mFlags &= ~8;
        sound->mFlags &= ~2;
        RemoveListObject(&source->mPlayingSounds, sound);
    }
    if (source->mUpdateListIndex != 3) {
        RemoveListObject(&data_0217d048[source->mUpdateListIndex], source);
        source->mUpdateListIndex = 3;
    }
    ReleaseSoundSource(source);
}

void StopSoundsStartedWhileRequested(SoundSource *source, u32 fadeSteps) {
    PlayingSound *sound;
    PlayingSound *removedSound;
    u32 v;
    u8 soundFlags;

    v = 0;
    sound = source->mPlayingSounds.mHead;
    while (sound != NULL) {
        if (sound->mFlags & 4) {
            removedSound = sound;
            sound = NNS_FndGetNextListObject(&source->mPlayingSounds, sound);
            NNS_SndPlayerStopSeq(&removedSound->mSeqPlayer, fadeSteps);
            removedSound->mFlags &= ~4;
            removedSound->mFlags &= ~8;
            removedSound->mFlags &= ~2;
            RemoveListObject(&source->mPlayingSounds, removedSound);
            v = 1;
            continue;
        }
        sound = NNS_FndGetNextListObject(&source->mPlayingSounds, sound);
    }
    if (v == 0) {
        return;
    }
    v = 3;
    for (sound = source->mPlayingSounds.mHead; sound != NULL;
         sound = NNS_FndGetNextListObject(&source->mPlayingSounds, sound)) {
        soundFlags = sound->mFlags;
        if (soundFlags & 2) {
            v = 0;
            break;
        }
        if (soundFlags & 8 || soundFlags & 1) {
            v = 1;
        }
    }
    if (source->mUpdateListIndex != v) {
        if (source->mUpdateListIndex != 3) {
            RemoveListObject(&data_0217d048[source->mUpdateListIndex], source);
            source->mUpdateListIndex = 3;
        }
        if (v != 3) {
            TryAppendListObject(&data_0217d048[v], source);
            source->mUpdateListIndex = v;
        }
    }
}

void ReleaseSoundSource(SoundSource *source) {
    void *sound;

    StopSoundsStartedWhileRequested(source, 0);
    for (sound = source->mPlayingSounds.mHead; sound != NULL; sound = source->mPlayingSounds.mHead) {
        RemoveListObject(&source->mPlayingSounds, sound);
    }
    if (source->mUpdateListIndex != 3) {
        RemoveListObject(&data_0217d048[source->mUpdateListIndex], source);
        source->mUpdateListIndex = 3;
    }
    RemoveListObject(&data_0217d028, source);
    source->mUnk_38 = 0;
}
