#pragma once

#include "types.h"

void BounceItemVelocityOffSurface(Vec3 *velocity, Vec3 *normal);
typedef struct ItemObject ItemObject;

void func_020f9320(ItemObject *item, unsigned int clearBits);
