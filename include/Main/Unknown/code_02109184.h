#pragma once

#include "types.h"

typedef struct Kart Kart;
typedef struct Unk0210bcf4 Unk0210bcf4;

// Five words of constant data used by InitSoundFalloffs.
typedef struct SoundFalloffSettings {
    /* 00 */ s32 mOuterDistance;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mInnerDistance;
    /* 10 */ s32 mMaxVolume;
} SoundFalloffSettings;

void StopKartSoundWhileRequested(Kart *a);
void InitSoundFalloffs(void);
// Returns the volume of a source from the distance in the mUnk_10 member of p and the forward distance in its mUnk_08
// member, by the SoundFalloff of the source: the maximum up to the inner distance, falling to 0 at the outer distance.
// Writes nothing.
s32 ComputeSoundVolume(Unk0210bcf4 *p);
s32 ComputeSoundPan(Unk0210bcf4 *p);
u32 ComputeSoundDistanceAndOffsets(Unk0210bcf4 *p);
