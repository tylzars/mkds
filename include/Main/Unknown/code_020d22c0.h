#pragma once

#include "types.h"

// Three 64-bit words: x, a and c of x = x * a + c (x = x * [8] + [0x10] in TallyPickedCourse). GetRaceRandom and
// GetMapObjectRandom return one; Unk0217aa00 has one at 0x1ee8, RaceProgress three and WiFiSession one at 0x1954.
typedef struct RandomState64 {
    /* 00 */ u64 mValue;
    /* 08 */ u64 mMultiplier;
    /* 10 */ u64 mIncrement;
} RandomState64;

typedef struct MapObject MapObject;

RandomState64 *GetRaceRandom(void);
RandomState64 *GetMapObjectRandom(void);
void SetRaceRandomPointers(void);
void UnparkMapObject(MapObject *mapObject);
void ParkMapObject(MapObject *mapObject);
