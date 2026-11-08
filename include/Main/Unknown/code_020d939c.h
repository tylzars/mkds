#pragma once

#include "types.h"

typedef struct Segment Segment;

void GetSegmentCurvePosStep(Segment *segment, s32 fraction, s32 scale, Vec3 *firstResult, Vec3 *secondResult);
