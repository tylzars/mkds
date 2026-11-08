#pragma once

#include "types.h"

typedef struct Unk02188950 Unk02188950;

void SetPointInRangeCallback(Unk02188950 *mapObject, s32 pointRadius, s32 pointHalfAngle, Vec3 *point,
                             UnkFunc *callback);
