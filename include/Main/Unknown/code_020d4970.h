#pragma once

#include "types.h"

typedef struct Water Water;

// Publishes the WaterEfct object as gCourseWaterEfct.
void SetCourseWaterEfct(void *waterEfct);
// Publishes the Water object as gCourseWater.
void SetCourseWater(Water *water);
