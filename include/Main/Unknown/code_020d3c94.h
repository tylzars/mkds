#pragma once

#include "types.h"

typedef struct MapObject MapObject;

s32 GetHeightAboveWaterOrEfct(s32 y);
s32 func_020d3d10(s32 y);
void func_020d3cc8(void);
s32 func_020d3c94(MapObject *mapObject, s32 itemKind, Vec3 *hitOffset);
