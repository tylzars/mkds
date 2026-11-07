#pragma once

#include "types.h"

typedef struct MapObject MapObject;
typedef struct Kart Kart;

u32 StartSoundIfKartStarOrKiller(MapObject *mapObject, Kart *kart);
