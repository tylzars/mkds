#pragma once

#include "types.h"

typedef struct MapObjectList MapObjectList;

void *RaceHudSubScreenGetMapObjects(MapObjectList *list);
void **GetMapObjects(MapObjectList *list);
