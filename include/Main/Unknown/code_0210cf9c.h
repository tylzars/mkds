#pragma once

#include "types.h"

typedef struct SoundSource SoundSource;

void SetSoundSourceFlagBit(SoundSource *p, s32 bit, s32 value);
void SetSoundSourceEnabled(SoundSource *p, s32 enabled);
