#pragma once

#include "types.h"
#include "Main/Unknown/code_020f36d8.h"

typedef struct SegmentProgress SegmentProgress;

void GetSegmentProgressPointXz(SegmentProgress *segmentProgress, Vec3 *output);
void GetSegmentProgressPoint(SegmentPoints *progressOwner, Vec3 *output);
