#pragma once

#include "types.h"

typedef struct MapObject MapObject;

// Starts sound arg1 at volume 0x7f on the sound source behind MapObject.mUnk_94 with StartSoundWhileRequested.
void StartMapObjectSoundWhileRequested(MapObject *mapObject, u32 soundId);
// Starts sound arg1 at volume 0x7f on the sound source behind MapObject.mUnk_94 (StartSound).
void StartMapObjectSound(MapObject *mapObject, u32 soundId);
