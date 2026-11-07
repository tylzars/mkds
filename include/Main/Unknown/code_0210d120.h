#pragma once

#include "types.h"

void UpdateSoundSources(void);
void StopSoundsOnAllSources(u32 fadeSteps);
void StartPlayingSoundsFade(s32 volume, s32 steps);
void StopAllPlayingSounds(u32 fadeSteps);
