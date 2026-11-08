#pragma once

#include "types.h"

typedef struct Segment Segment;
typedef struct GroupFollower GroupFollower;

s32 GetGroupFollowerProgress(GroupFollower *p);
void GetSegmentCurveXzLinearY(Segment *segment, s32 fraction, Vec3 *result);
void GetSegmentCurvePosStepXz(Segment *segment, s32 fraction, s32 scale, Vec3 *firstResult, Vec3 *secondResult);
BOOL AdvanceGroupFollower(GroupFollower *path);
void SetupGroupFollowerAtEntry(GroupFollower *path, u16 follower, s32 entryIndex);
