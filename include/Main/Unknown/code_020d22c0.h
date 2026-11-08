#pragma once

#include "types.h"

// Three 64-bit words: x, a and c of x = x * a + c. GetRaceRandom and GetMapObjectRandom return one; Unk0217aa00 has one
// at 0x1ee8 and RaceProgress three.
typedef struct Unk020f41c4_B {
    /* 00 */ u64 mUnk_00;
    /* 08 */ u64 mUnk_08;
    /* 10 */ u64 mUnk_10;
} Unk020f41c4_B;

typedef struct MapObject MapObject;

Unk020f41c4_B *GetRaceRandom(void);
Unk020f41c4_B *GetMapObjectRandom(void);
void SetRaceRandomPointers(void);
void UnparkMapObject(MapObject *mapObject);
void ParkMapObject(MapObject *mapObject);
