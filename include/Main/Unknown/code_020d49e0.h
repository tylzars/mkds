#pragma once

#include "types.h"

typedef struct MapObject MapObject;
typedef struct MapObjectList MapObjectList;

u32 AddMapObjectToDrawList(MapObjectList *arg0, MapObject *arg1);
u32 InitMapObjectDrawList(MapObjectList *arg0);
