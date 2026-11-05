#pragma once

#include "types.h"

typedef struct Water Water;

// Publishes the WaterEfct object as gCourseWaterEfct.
void SetCourseWaterEfct(void *p0);
// Publishes the Water object as gCourseWater.
void SetCourseWater(Water *p0);
