#pragma once

#include "types.h"

typedef struct MapObject MapObject;

// Starts sound arg1 at volume 0x7f on the sound source behind MapObject.mUnk_94 with StartSoundWhileRequested.
void StartMapObjectSoundWhileRequested(MapObject *arg0, u32 arg1);
// Starts sound arg1 at volume 0x7f on the sound source behind MapObject.mUnk_94 (StartSound).
void StartMapObjectSound(MapObject *arg0, u32 arg1);
