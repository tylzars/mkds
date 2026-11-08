#pragma once

#include "types.h"

typedef struct SoundSource SoundSource;

void SetSoundSourceFlagBit(SoundSource *source, s32 bit, s32 value);
void SetSoundSourceEnabled(SoundSource *source, s32 enabled);
