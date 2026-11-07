#pragma once

#include "types.h"

typedef struct MapObject MapObject;

BOOL IsSphereHittingMapObject(Vec3 *a, s32 b, MapObject *c, Vec3 *d);
BOOL IsWaterPresent(void);
s32 GetHeightAboveWater(s32 a);
s32 GetWaterHeightFactor(void);
u32 GetWaterHeightAngle(void);
