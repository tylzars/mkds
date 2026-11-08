#pragma once

#include "types.h"

typedef struct MapObject MapObject;
typedef struct MapObjectList MapObjectList;

u32 AddMapObjectToDrawList(MapObjectList *list, MapObject *mapObject);
u32 InitMapObjectDrawList(MapObjectList *list);
