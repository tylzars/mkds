#pragma once

#include "types.h"

typedef struct SoundSource SoundSource;

void StartSurfaceSound(SoundSource *source, int entryIndex, u32 surfaceKind, u32 surfaceVariant, u32 waterDepth);
