#pragma once

#include "types.h"

typedef struct MapObject MapObject;

BOOL IsSphereHittingMapObject(Vec3 *position, s32 radius, MapObject *mapObject, Vec3 *overlapOffset);
BOOL IsWaterPresent(void);
s32 GetHeightAboveWater(s32 y);
s32 GetWaterHeightFactor(void);
u32 GetWaterHeightAngle(void);
