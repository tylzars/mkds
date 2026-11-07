#include "Main/Unknown/code_0210cf20.h"
#include "Main/Unknown/code_02105ec0.h"

#include "Main/Unknown/code_0210cf9c.h"
#include "Main/Unknown/code_0210cfe8.h"
#include "Main/Unknown/code_0210d020.h"
#include "Main/Unknown/code_0210d078.h"
#include "Main/Unknown/code_0210dc7c.h"
#include "Main/Unknown/unk_0216c000.h"
#include "code_0212bcac.h"
#include "Main/Unknown/code_0210d0b4.h"
#include "Main/Unknown/code_0210d120.h"
#include "Main/Unknown/code_0210bafc.h"
#include "code_0212d214.h"
#include "Main/Unknown/code_0210bcf4.h"
#include "Main/Unknown/code_0210c1b0.h"
#include "Main/Unknown/code_0210e000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "code_020172d0.h"
#include "Main/Unknown/code_0210d4a0.h"
#include "Main/Unknown/code_0210d4a4.h"
#include "Main/Unknown/code_0210e328.h"
#include "Main/Unknown/code_0210bce0.h"
#include "code_0201750c.h"

// Builds the pool of sounds, resets each one, empties the three source lists and zeroes the two pass counters.
void InitPlayingSoundPool(PlayingSound *sounds, s32 count) {
    s32 i;

    func_0210e2c4(&data_0217d034, sounds, count, 0x1c);
    for (i = 0; i < count; i++) {
        func_0210e328(sounds);
        func_0210bce0(&sounds->mUnk_08);
        sounds->mUnk_18 = 0;
        sounds->mSoundId = 0;
        sounds->mUnk_19 = 0;
        sounds->mUnk_14 = 0;
        sounds->mVolume = 0x7f;
        sounds++;
    }
    NNS_FndInitList(&data_0217d028, 0);
    for (i = 0; i < 2; i++) {
        NNS_FndInitList(&data_0217d048[i], 0x1c);
    }
    data_0217d010[0] = 0;
    data_0217d024[0] = 0;
}

u32 func_0210d4a0(u32 p0) {
    return p0;
}

// The sound pass: list 0 sources get volume and pan every call, list 1 sources in turns over four calls.
void UpdateSoundSources(void) {
    NNSFndList *l;
    u32 t;
    PlayingSound *q;
    NNSFndList *m;
    SoundSource *p;

    if (data_0217d084.mUnk_10 == 0) {
        return;
    }
    if (data_0217d020 != 0) {
        for (p = data_0217d028.mHead; p != NULL; p = NNS_FndGetNextListObject(&data_0217d028, p)) {
            func_0210cc3c(p);
        }
        data_0217d020 = 0;
    }
    func_0210e280(&data_0217d034);
    l = data_0217d048;
    for (p = l->mHead; p != NULL; p = l->mHead) {
        SetPlayingSoundsParams(p);
        if (p->mUnk_18 != 3) {
            func_0210bc54(&l[p->mUnk_18], p);
            p->mUnk_18 = 3;
        }
    }
    m = &data_0217d054;
    p = m->mHead;
    t = data_0217d024[0];
    if (p != NULL) {
        l = data_0217d048;
        do {
            if ((t++ & 3) == data_0217d010[0]) {
                SetPlayingSoundsParams(p);
            } else if ((t & 1) == (data_0217d010[0] & 1)) {
                for (q = p->mPlayingSounds.mHead; q != NULL; q = NNS_FndGetNextListObject(&p->mPlayingSounds, q)) {
                    if (q->mUnk_00 != NULL) {
                        p->mUnk_30(p, q, NULL);
                    }
                }
            }
            if (p->mUnk_18 != 3) {
                func_0210bc54(&l[p->mUnk_18], p);
                p->mUnk_18 = 3;
            }
            p = m->mHead;
        } while (p != NULL);
    }
    data_0217d010[0]++;
    if (data_0217d010[0] == 4) {
        data_0217d010[0] = 0;
    }
    data_0217d024[0] = 0;
}

// Stops every sound of every source, removes the entries from the source and the source from its update list.
void StopSoundsOnAllSources(u32 fadeSteps) {
    SoundSource *source;
    PlayingSound *sound;

    source = data_0217d028.mHead;
    if (source == NULL) {
        return;
    }
    do {
        sound = source->mPlayingSounds.mHead;
        if (sound != NULL) {
            do {
                NNS_SndPlayerStopSeq(&sound->mUnk_00, fadeSteps);
                sound->mUnk_19 &= ~4;
                sound->mUnk_19 &= ~8;
                sound->mUnk_19 &= ~2;
                func_0210bc54(&source->mPlayingSounds, sound);
                sound = source->mPlayingSounds.mHead;
            } while (sound != NULL);
        }
        if (source->mUnk_18 != 3) {
            func_0210bc54(&data_0217d048[source->mUnk_18], source);
            source->mUnk_18 = 3;
        }
        source = NNS_FndGetNextListObject(&data_0217d028, source);
    } while (source != NULL);
}

// Fades every sound in the pool to the volume over the given number of steps.
void StartPlayingSoundsFade(s32 volume, s32 steps) {
    u8 *p;
    s32 i;

    p = data_0217d034.mUnk_0c;
    for (i = 0; i < data_0217d034.mUnk_00; i++) {
        NNS_SndPlayerMoveVolume(&((PlayingSound *) p)->mUnk_00, volume, steps);
        p += data_0217d034.mUnk_10;
    }
}

void StopAllPlayingSounds(u32 fadeSteps) {
    u8 *p;
    s32 i;

    p = data_0217d034.mUnk_0c;
    for (i = 0; i < data_0217d034.mUnk_00; i++) {
        NNS_SndPlayerStopSeq(&((PlayingSound *) p)->mUnk_00, fadeSteps);
        ((PlayingSound *) p)->mUnk_19 &= ~4;
        ((PlayingSound *) p)->mUnk_19 &= ~8;
        ((PlayingSound *) p)->mUnk_19 &= ~2;
        p += data_0217d034.mUnk_10;
    }
}

void ReleaseAllSoundSources(void) {
    while (data_0217d028.mHead != NULL) {
        StopAllSoundsAndReleaseSoundSource(data_0217d028.mHead);
    }
}

// Start slot of a source (offset 0x2c): starts the library sequence of the entry at the given priority.
void StartPlayingSoundSeqArc(u32 a, PlayingSound *sound, u32 priority) {
    NNS_SndArcPlayerStartSeqArcEx(&sound->mUnk_00, -1, -1, priority, sound->mUnk_18, sound->mSoundId);
}

// Per-entry slot of a source (offset 0x30): sets track volume and pitch of a started sound.
void SetPlayingSoundTrackParams(u32 a, PlayingSound *sound) {
    NNS_SndPlayerSetTrackVolume(&sound->mUnk_00, data_0216cb20, sound->mVolume);
    NNS_SndPlayerSetTrackPitch(&sound->mUnk_00, data_0216cb20, sound->mUnk_14);
}

void StartSoundSeqArc(NNSSndSeqPlayer **handle, u32 b, u32 soundId, u32 priority) {
    NNS_SndArcPlayerStartSeqArcEx(handle, -1, -1, priority, b, soundId);
}

void SetSoundPanFunction(s32 (*p0)(Unk0210bcf4 *)) {
    data_0217d01c = p0;
}

void SetSoundDistanceFunction(u32 (*p0)(Unk0210bcf4 *)) {
    data_0217d018 = p0;
}

void SetSoundVolumeFunction(s32 (*p0)(Unk0210bcf4 *)) {
    data_0217d014 = p0;
}

void ResetPlayingSound(PlayingSound *arg0) {
    func_0210e328(arg0);
    func_0210bce0(&arg0->mUnk_08);
    arg0->mUnk_18 = 0;
    arg0->mSoundId = 0;
    arg0->mUnk_19 = 0;
    arg0->mUnk_14 = 0;
    arg0->mVolume = 0x7f;
}

// Every caller passes bit 2 with 1: the sound pass then flips bit 0 and clears bit 2.
void SetSoundSourceFlagBit(SoundSource *p, s32 bit, s32 value) {
    if (value == 1) {
        p->mUnk_34 |= 1 << bit;
    } else {
        p->mUnk_34 &= ~(1 << bit);
    }
}

// Bit 0 of the flag word: a sound can start on the source only while it is set.
void SetSoundSourceEnabled(SoundSource *p, s32 enabled) {
    if (enabled == 1) {
        p->mUnk_34 |= 1;
    } else {
        p->mUnk_34 &= ~1;
    }
}

void func_0210cf20(SoundSource *a, u32 b) {
    void *v1;
    void *v2;
    NNS_FndInitList(&a->mPlayingSounds, 8);
    v1 = (void *) StartPlayingSoundSeqArc;
    a->mUnk_38 = 1;
    v2 = (void *) SetPlayingSoundTrackParams;
    a->mUnk_2c = v1;
    a->mUnk_30 = v2;
    a->mUnk_34 = 0;
    a->mOwnerPosSource = b;
    a->mUnk_18 = 3;
    func_0210bce0(a->mUnk_1c);
    func_0210bce0((u32 *) a);
    func_0210bc8c(&data_0217d028, a);
}
