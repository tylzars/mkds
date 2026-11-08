#pragma once

#include "types.h"
#include "code_0212bcac.h"

typedef struct SoundParams SoundParams;

void SetSoundVolumeFunction(s32 (*volumeFunction)(SoundParams *));
void SetSoundDistanceFunction(u32 (*distanceFunction)(SoundParams *));
void SetSoundPanFunction(s32 (*panFunction)(SoundParams *));
void StartSoundSeqArc(NNSSndSeqPlayer **handle, u32 seqArcNo, u32 soundId, u32 priority);
