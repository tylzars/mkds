#pragma once

#include "types.h"

typedef struct MapObject MapObject;

void InitShine16(MapObject *p); /* parks the pooled object, then allocates its 0x44 effect record */
