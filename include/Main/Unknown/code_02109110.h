#pragma once

#include "types.h"

typedef struct SoundSource SoundSource;

// Sets up the sound source p: its number a (the volume curve), the pointer v to the owner's position, an empty sound
// list and the entry in the list of all sound sources (data_0217d028). The source starts not enabled (bit 0 of its
// mUnk_34 member is clear).
void InitSoundSource(SoundSource *p, u32 a, Vec3 *v);
