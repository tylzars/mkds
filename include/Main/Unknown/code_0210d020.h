#pragma once

#include "types.h"
#include "code_0212bcac.h"

typedef struct Unk0210bcf4 Unk0210bcf4;

void SetSoundVolumeFunction(s32 (*p0)(Unk0210bcf4 *));
void SetSoundDistanceFunction(u32 (*p0)(Unk0210bcf4 *));
void SetSoundPanFunction(s32 (*p0)(Unk0210bcf4 *));
void StartSoundSeqArc(NNSSndSeqPlayer **handle, u32 b, u32 soundId, u32 priority);
