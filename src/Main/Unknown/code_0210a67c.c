#include "Main/Unknown/code_0210a67c.h"
#include "Main/Unknown/code_020d3c94.h"
#include "code_0212d214.h"
#include "Main/Unknown/code_0210bcf4.h"

#include "Main/Unknown/code_020d3000.h"
#include "Main/Unknown/code_021059e0.h"
#include "Main/Unknown/code_02105ec0.h"
#include "Main/Unknown/code_0210fad4.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/code_0210aa0c.h"
#include "Main/Unknown/code_0210aa14.h"
#include "Main/Unknown/code_02079b40.h"
#include "Main/Unknown/code_0210f000.h"
#include "Main/Unknown/code_0210faac.h"
#include "code_0212bcac.h"
#include "code_0212df7c.h"
#include "Main/Unknown/code_0210ab30.h"
#include "Main/Unknown/code_0210ab48.h"
#include "Main/Unknown/code_02109054.h"
#include "Main/Unknown/code_0203c5ac.h"
#include "Main/Unknown/code_021053e4.h"
#include "Main/Unknown/code_0210bafc.h"
#include "Main/Unknown/code_0210c1b0.h"
#include "Main/Unknown/code_0211057c.h"
#include "Main/Unknown/code_02110590.h"
#include "Main/Unknown/unk_0217d000.h"
#include "code_020172d0.h"
#include "Main/Unknown/code_0210b564.h"
#include "Main/Unknown/code_0210b610.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/code_0210b6a0.h"
#include "code_02147cd8.h"

u32 InitSoundPitchSwing(void) {
    u32 value0;
    u32 value1;
    u32 value2;
    u32 value3;
    u32 value12;
    value1 = 0xafc8000u;
    value0 = 0x384000u;
    value0 = FX_Div(value0, value1);
    value2 = (u32) &data_0217ccb0;
    value1 = 0xafc8000u;
    *(u32 *) ((value2) + (0)) = value0;
    value0 = 0x1c2000u;
    value0 = FX_Div(value0, value1);
    value3 = (u32) &data_0217ccbc;
    value2 = (u32) &gSoundPitchSwing;
    value12 = 0u;
    value1 = (u32) &gSoundPitchSwingAngle;
    *(u32 *) ((value3) + (0)) = value0;
    *(u32 *) ((value2) + (0)) = value12;
    *(u32 *) ((value1) + (0)) = value12;
    return value0;
}

void UpdateSoundPitchSwing(void) {
    s32 angle;
    s32 wrappedAngle;
    s32 c;
    s64 d;

    angle = *(u32 *) gSoundPitchSwingAngle + 0x1999;
    *(u32 *) gSoundPitchSwingAngle = angle;
    wrappedAngle = angle & 0xffff;
    c = gPairsByAngle[(wrappedAngle >> 4) * 2];
    d = (s64) c * 0x90000 + 0x800;
    *(u32 *) gSoundPitchSwingAngle = wrappedAngle;
    gSoundPitchSwing = (s32) (d >> 12) >> 12;
}

void StartSurfaceSound(SoundSource *source, int entryIndex, u32 surfaceKind, u32 surfaceVariant, u32 waterDepth) {
    int v1;
    if ((source->mUnk_34 & 1) == 0) {
        return;
    }
    if (entryIndex == 2) {
        if ((0x00009c40u) < waterDepth) {
            StartSound(source, 0x70, 0x7f, 0);
            return;
        }
        if (waterDepth != 0) {
            StartSound(source, 0x6f, 0x7f, 0);
            return;
        }
    }
    v1 = GetSurfaceSoundId(entryIndex, surfaceKind, surfaceVariant);
    if (v1 != 0xffff) {
        StartSound(source, v1, 0x7f, 0);
        return;
    }
}

void func_0210b4e0(Kart *kart, s32 b, s32 surfaceKind, s32 surfaceVariant) {
    u32 soundId;

    switch (kart->mUnk_490) {
        case 0:
            soundId = 0xb2;
            break;
        case 1:
            soundId = 0xb9;
            break;
        case 2:
            soundId = 0xc0;
            break;
    }
    if (b != 0) {
        StartSoundWhileRequested(&kart->mSoundSource, GetSurfaceSoundId(1, surfaceKind, surfaceVariant), 0x5f, -0x345);
    }
    StartSoundWhileRequested(&kart->mSoundSource, soundId, 0x7f, 0);
}

void StartKartSurfaceSoundWhileRequested(Kart *kart, s32 entryIndex, s32 surfaceKind, s32 surfaceVariant,
                                         u32 waterDepth) {
    Unk0206bcb0_A *soundState;
    s16 f;
    s32 volume;
    BOOL isEntryKart;
    s16 depthPitch;
    u32 soundId;
    s32 lapProgress;
    s32 k;
    u32 m;
    u32 baseSoundId;

    if (!(kart->mSoundSource.mUnk_34 & 1)) {
        return;
    }
    if (kart->mUnk_4c & 0x10000000) {
        return;
    }
    soundState = &kart->mUnk_450;
    f = soundState->mUnk_08 >> 12;
    if (f > 0x1fc) {
        volume = 0x7f;
    } else {
        volume = f >> 2;
    }
    if (entryIndex == 1) {
        if (waterDepth != 0) {
            f = f + 0x1c0;
        } else {
            f = (s16) (f - 0x7d0) >> 2;
        }
    }
    if (waterDepth != 0) {
        depthPitch = 0;
        isEntryKart = kart->mIndex == gRaceSetup->mEntryIndex;
        if (waterDepth > 0x11170) {
            depthPitch = 0x384;
            if (isEntryKart != FALSE) {
                depthPitch += gSoundPitchSwing;
            }
        } else if (waterDepth > 0x61a8 && waterDepth <= 0x11170) {
            depthPitch = ((s32) ((((s64) data_0217ccb0 * (s32) ((waterDepth - 0x61a8) << 12)) + 0x800) >> 12)) >> 12;
            if (isEntryKart != FALSE) {
                depthPitch += gSoundPitchSwing >> 1;
            }
        }
        StartSoundWhileRequested(&kart->mSoundSource, 0x74, volume & 0xff, (s16) (f - depthPitch));
    } else {
        soundId = GetSurfaceSoundId(entryIndex, surfaceKind, surfaceVariant);
        if (soundId == 0xffff) {
            return;
        }
        switch (soundId) {
            case 0xffd0:
            case 0xffd1:
                m = soundId & 1;
                lapProgress = GetKartLapProgress(kart->mIndex);
                k = lapProgress - soundState->mUnk_28;
                if (k < 0) {
                    k = -k;
                }
                if (k > GetLapProgressSoundGap(m)) {
                    baseSoundId = GetLapProgressSoundId(m);
                    soundState->mUnk_2c++;
                    StartSound(&kart->mSoundSource, (u16) ((soundState->mUnk_2c & 1) + baseSoundId), 0x7f, 0);
                    soundState->mUnk_28 = lapProgress;
                }
                break;
            default:
                StartSoundWhileRequested(&kart->mSoundSource, soundId, volume & 0xff, f);
                break;
        }
    }
}

void func_0210b234(Kart *kart, s32 b, s32 c, s32 d, s32 f) {
    u32 soundId;

    if (!(kart->mSoundSource.mUnk_34 & 1)) {
        return;
    }
    soundId = func_0210bafc(b, c, d);
    if (soundId == 0xffff) {
        return;
    }
    if (gRaceSetup->mCourseId == COURSE_ID_RAINBOW) {
        soundId = 0x1b6;
    }
    StartSound(&kart->mSoundSource, soundId, 0x7f, 0);
}

void func_0210b198(s32 a, s32 b, u32 volume, s32 d, s32 e) {
    NNSSndSeqPlayer *sndHandle;
    u16 f;

    if (func_02105504() == 0) {
        return;
    }
    NNS_SndHandleInit(&sndHandle);
    f = a * 0xe + b;
    if (sndHandle != NULL) {
        NNS_SndPlayerStopSeq(&sndHandle, 0);
    }
    NNS_SndArcPlayerStartSeqArcEx(&sndHandle, d, -1, e, 2, f);
    SetSndHandleTrackVolume(&sndHandle, volume);
    NNS_SndHandleReleaseSeq(&sndHandle);
}

void StartKartCollisionSound(Kart *kart, s32 b, s16 d) {
    PlayingSound *playingSound;
    s32 soundId;

    soundId = b + 0xc1;
    if (gSceneSoundState.mRaceFrames < 0x78) {
        return;
    }
    playingSound = StartSoundEx(&kart->mSoundSource, 0, soundId, 0x7f, 0);
    if (playingSound == NULL) {
        return;
    }
    playingSound->mUnk_19 |= 0x20;
    playingSound->mUnk_19 |= 0x40;
}

void func_0210af40(Kart *kart, s32 b, s32 c) {
    NNSSndSeqPlayer *sndHandle;
    Unk0206bcb0_A *soundState;
    u32 raceFrames;
    s32 volume;
    BOOL isEntryKart;
    u16 sequenceNo;
    s32 minFrames;
    s32 minFrameGap;

    raceFrames = gSceneSoundState.mRaceFrames;
    if (!(kart->mSoundSource.mUnk_34 & 1)) {
        return;
    }
    soundState = &kart->mUnk_450;
    if (kart->mUnk_4c & 0x10000000) {
        return;
    }
    if (kart->mUnk_7c & KART_7C_ENTRY_KIND_2) {
        return;
    }
    if (gSceneSoundState.mRaceState != 1) {
        if (gSceneSoundState.mRaceState != 0) {
            return;
        }
        volume = 0x7f;
        isEntryKart = kart->mIndex == gRaceSetup->mEntryIndex;
        if (c == 5) {
            volume = 0x7f;
        } else if (c == 3) {
            volume = 0x7f;
        }
        if (isEntryKart != FALSE) {
            if (func_02105504() == 0) {
                return;
            }
            NNS_SndHandleInit(&sndHandle);
            sequenceNo = b * 0xe + c;
            if (sndHandle != NULL) {
                NNS_SndPlayerStopSeq(&sndHandle, 0);
            }
            NNS_SndArcPlayerStartSeqArcEx(&sndHandle, 1, -1, 0x7f, 2, sequenceNo);
            SetSndHandleTrackVolume(&sndHandle, volume);
            NNS_SndHandleReleaseSeq(&sndHandle);
        } else {
            if (c != 3 && c != 5) {
                return;
            }
            StartSoundEx(&kart->mSoundSource, 2, b * 0xe + (c + 1), 0x73, 0);
        }
    } else {
        minFrames = 0xf0;
        minFrameGap = 0x1e;
        if (c == 1 || c == 2) {
            minFrames = 0x3c;
            minFrameGap = 0;
        }
        if (raceFrames < minFrames) {
            return;
        }
        if (raceFrames - soundState->mUnk_30 < minFrameGap) {
            return;
        }
        StartSoundEx(&kart->mSoundSource, 2, b * 0xe + c, 0x7f, 0);
        soundState->mUnk_30 = raceFrames;
    }
}

void InitKartSoundQueue(void) {
    s32 i;
    KartSoundQueue *queue = &gKartSoundQueue;

    queue->mCount = 0;
    queue->mDisabled = FALSE;
    for (i = 0; i < 8; i++) {
        queue->mKarts[i] = NULL;
        queue->mFramesSinceStart[i] = 0;
    }
    queue->mVolume = 0x5f;
    queue->mDelayFrames = -1;
}

void UpdateKartSoundQueue(void) {
    KartSoundQueue *queue = &gKartSoundQueue;
    s32 i;

    if (queue->mDisabled != FALSE) {
        return;
    }
    if (queue->mDelayFrames != -1) {
        queue->mDelayFrames++;
        if (queue->mDelayFrames >= 0x19) {
            queue->mDelayFrames = -1;
        }
        return;
    }
    for (i = 0; i < 8; i++) {
        if (queue->mKarts[i] == NULL) {
            continue;
        }
        if (queue->mFramesSinceStart[i] == 0) {
            if (i != 0 && queue->mFramesSinceStart[i - 1] < 0x14) {
                continue;
            }
            if (i != 0 && queue->mFramesSinceStart[i - 1] == 0x14) {
                queue->mVolume -= 0xf;
            } else {
                queue->mVolume = 0x5f;
            }
            if (queue->mVolume < 0x1e) {
                queue->mVolume = 0x1e;
            }
            StartQueuedKartSound(queue->mKarts[i], queue->mUnk_20[i], 0, queue->mVolume);
            queue->mFramesSinceStart[i]++;
        } else {
            queue->mFramesSinceStart[i]++;
        }
    }
}

void QueueKartSound(Kart *kart, s32 b) {
    KartSoundQueue *queue = &gKartSoundQueue;

    if (queue->mDisabled != FALSE) {
        return;
    }
    if (kart->mIndex == gRaceSetup->mEntryIndex) {
        StartQueuedKartSound(kart, b, 1, 0x6e);
        queue->mDelayFrames = 0;
        return;
    }
    queue->mKarts[queue->mCount] = kart;
    queue->mUnk_20[queue->mCount] = b;
    queue->mCount++;
}

void StartQueuedKartSound(Kart *kart, s32 b, s32 c, s32 volume) {
    NNSSndSeqPlayer *sndHandle;
    PlayingSound *playingSound;
    PlayingSound *stoppedSound;
    BOOL e;
    u16 sequenceNo;
    enum { K0 } k;

    playingSound = kart->mSoundSource.mPlayingSounds.mHead;
    if (playingSound != NULL) {
        do {
            if (playingSound->mUnk_18 == 2) {
                stoppedSound = playingSound;
                playingSound = NNS_FndGetNextListObject(&kart->mSoundSource.mPlayingSounds, playingSound);
                StopPlayingSound(&kart->mSoundSource, stoppedSound, 0);
            } else {
                playingSound = NNS_FndGetNextListObject(&kart->mSoundSource.mPlayingSounds, playingSound);
            }
        } while (playingSound != NULL);
    }
    e = TRUE;
    if (data_0217d084.mMode != 2 && data_0217d084.mMode != 3) {
        e = FALSE;
    }
    if (e == FALSE) {
        return;
    }
    k = 0xd;
    if (c != 0) {
        StartSoundEx(&kart->mSoundSource, 2, b * 0xe + k, 0x7f, 0);
        return;
    }
    if (func_02105504() == 0) {
        return;
    }
    NNS_SndHandleInit(&sndHandle);
    sequenceNo = b * 0xe + k;
    if (sndHandle != NULL) {
        NNS_SndPlayerStopSeq(&sndHandle, 0);
    }
    NNS_SndArcPlayerStartSeqArcEx(&sndHandle, -1, -1, 0x6e, 2, sequenceNo);
    SetSndHandleTrackVolume(&sndHandle, volume);
    NNS_SndHandleReleaseSeq(&sndHandle);
}

void func_0210ab48(s32 a, s32 b) {
    NNSSndSeqPlayer *sndHandle;
    s32 c;
    u16 d;

    c = b != 0 ? 0xc : 0xd;
    gKartSoundQueue.mDisabled = TRUE;
    if (func_02105504() == 0) {
        return;
    }
    NNS_SndHandleInit(&sndHandle);
    d = a * 0xe + c;
    if (sndHandle != NULL) {
        NNS_SndPlayerStopSeq(&sndHandle, 0);
    }
    NNS_SndArcPlayerStartSeqArcEx(&sndHandle, 7, -1, -1, 2, d);
    SetSndHandleTrackVolume(&sndHandle, 0x6e);
    NNS_SndHandleReleaseSeq(&sndHandle);
}

void func_0210ab44(Kart *a, PlayingSound *b, s32 c) {}

void func_0210ab40(Kart *a, PlayingSound *b, s32 c) {}

void func_0210ab30(Kart *a) {
    a->mSoundSource.mUnk_2c = (void (*)(void *, void *, u32)) func_0210ab40;
}

void StartKartPlayingSoundSeq(Kart *kart, PlayingSound *playingSound, s32 c) {
    u32 d;
    u32 soundId;
    s32 f;
    NNSSndSeqParam *seqParam;
    u32 g;

    d = playingSound->mUnk_18;
    soundId = playingSound->mSoundId;
    f = -1;
    if (kart->mIndex == gRaceSetup->mEntryIndex) {
        seqParam = NNS_SndArcGetSeqArcParam(d, soundId);
        g = seqParam->mPlayerNo;
        if (g == 2) {
            f = 4;
        } else if (g == 3) {
            f = 5;
        } else if (g == 6) {
            if (IsThunderShrinkFlagSet() != 0 || IsKartNear() != 0) {
                f = 7;
            }
        }
    }
    if ((playingSound->mUnk_19 & 0x20) && (playingSound->mUnk_19 & 0x40)) {
        g = GetKartVariant(kart->mIndex) + 0x2d;
        NNS_SndArcPlayerStartSeqArcEx(&playingSound->mUnk_00, f, g, c, d, soundId);
        if (playingSound == NULL) {
            return;
        }
        NNS_SndPlayerWriteVariable(&playingSound->mUnk_00, 0, kart->mUnk_4b8);
    } else {
        NNS_SndArcPlayerStartSeqArcEx(&playingSound->mUnk_00, f, -1, c, d, soundId);
    }
}

u32 func_0210aa0c(void) {
    return 0x0u;
}

void SetKartPlayingSoundVolumePitch(Kart *kart, PlayingSound *playingSound, s32 pitchOffset) {
    s32 totalPitchOffset;
    u32 volume;
    u32 waterDepth;
    BOOL isEntryKart;
    s16 depthPitch;

    volume = playingSound->mVolume;
    totalPitchOffset = pitchOffset + kart->mUnk_48c(&kart->mUnk_518);
    if (playingSound->mUnk_18 != 2) {
        waterDepth = kart->mWaterDepth;
        depthPitch = 0;
        isEntryKart = kart->mIndex == gRaceSetup->mEntryIndex;
        if (waterDepth > 0x11170) {
            depthPitch = 0x384;
            if (isEntryKart != FALSE) {
                depthPitch += gSoundPitchSwing;
            }
        } else if (waterDepth > 0x61a8 && waterDepth <= 0x11170) {
            depthPitch = ((s32) ((((s64) data_0217ccb0 * (s32) ((waterDepth - 0x61a8) << 12)) + 0x800) >> 12)) >> 12;
            if (isEntryKart != FALSE) {
                depthPitch += gSoundPitchSwing >> 1;
            }
        }
        totalPitchOffset -= depthPitch;
    } else {
        waterDepth = kart->mWaterDepth;
        depthPitch = 0;
        if (waterDepth > 0x11170) {
            depthPitch += gSoundPitchSwing;
        } else if (waterDepth > 0x61a8 && waterDepth <= 0x11170) {
            depthPitch += gSoundPitchSwing;
        }
        totalPitchOffset -= depthPitch;
    }
    SetSndHandleTrackVolume(&playingSound->mUnk_00, volume);
    SetSndHandleTrackPitch(&playingSound->mUnk_00, playingSound->mUnk_14 + totalPitchOffset);
}

void func_0210a77c(Kart *kart, PlayingSound *playingSound) {
    Vec3 *o;
    u32 volume;
    s32 v;
    s16 depthPitch;
    u32 depth;
    s32 heightAboveWater;

    v = 0;
    volume = playingSound->mVolume;
    if (kart->mUnk_44 == 0) {
        o = (Vec3 *) &kart->mUnk_168.y;
    } else {
        o = (Vec3 *) &kart->mUnk_250.z;
    }
    v += o->z;
    heightAboveWater = GetHeightAboveWaterOrEfct(kart->mTurnedForward.y);
    if (heightAboveWater < 0) {
        depth = -heightAboveWater;
        depthPitch = 0;
        if (depth > 0x11170) {
            depthPitch = 0x1c2;
            depthPitch += gSoundPitchSwing;
        } else if (depth > 0x61a8 && depth <= 0x11170) {
            depthPitch = ((s32) ((((s64) data_0217ccbc * (s32) ((depth - 0x61a8) << 12)) + 0x800) >> 12)) >> 12;
            depthPitch += gSoundPitchSwing >> 1;
        }
        v -= depthPitch;
    }
    SetSndHandleTrackVolume(&playingSound->mUnk_00, volume);
    SetSndHandleTrackPitch(&playingSound->mUnk_00, playingSound->mUnk_14 + v);
}

void UpdateKartPlayingSound(Kart *kart, PlayingSound *playingSound) {
    SetKartPlayingSoundVolumePitch(kart, playingSound, 0);
}

void func_0210a724(Kart *kart, PlayingSound *playingSound) {
    u32 c;
    s32 pitchOffset;

    c = playingSound->mUnk_19;
    pitchOffset = 0;
    if (!(c & 0x10) && gSceneSoundState.mRaceFrames > kart->mUnk_450.mUnk_34 + 1) {
        pitchOffset = 0x180;
        if (c & 0x80) {
            pitchOffset += 0x100;
        }
    }
    SetKartPlayingSoundVolumePitch(kart, playingSound, pitchOffset);
}

void func_0210a6ec(Kart *kart, PlayingSound *playingSound) {
    u32 c;

    c = kart->mUnk_4c;
    SetSndHandleTrackVolume(&playingSound->mUnk_00, playingSound->mVolume);
    SetSndHandleTrackPitch(&playingSound->mUnk_00, playingSound->mUnk_14 + c);
}

void func_0210a6b4(Kart *kart, PlayingSound *playingSound) {
    u32 c;

    c = kart->mUnk_4c;
    SetSndHandleTrackVolume(&playingSound->mUnk_00, playingSound->mVolume);
    SetSndHandleTrackPitch(&playingSound->mUnk_00, playingSound->mUnk_14 + c);
}

void func_0210a67c(Kart *kart, PlayingSound *playingSound) {
    s32 turnCounter;

    turnCounter = (s32) kart->mTowardTurnCounter;
    SetSndHandleTrackVolume(&playingSound->mUnk_00, playingSound->mVolume);
    SetSndHandleTrackPitch(&playingSound->mUnk_00, playingSound->mUnk_14 + turnCounter);
}
