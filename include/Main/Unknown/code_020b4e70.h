#pragma once

#include "types.h"

BOOL IsPositionOutsideBox(const Vec3 *position);
void ComputePointAlongLine(Vec3 *out, const Vec3 *startPoint, const Vec3 *endPoint);
