#pragma once

#include "types.h"

typedef struct MapObjectList MapObjectList;

void AddToMapObjectListCount(MapObjectList *p, s32 n);
void ClearMapObjectListCount(MapObjectList *p);
