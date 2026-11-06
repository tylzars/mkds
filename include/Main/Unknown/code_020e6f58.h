#pragma once

#include "types.h"

typedef struct MapObject MapObject;
typedef struct MapObjectList MapObjectList;

void AddMapObjectToUpdateList(MapObjectList *p, MapObject *q);
