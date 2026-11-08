#pragma once

#include "types.h"

typedef struct Segment Segment;
typedef struct CourseMapEntryGroup CourseMapEntryGroup;

#include "Main/Unknown/unk_0217b000.h"

void InitGroupFollowerForGroup(GroupFollower *follower, u16 groupIndex, int speed);
void InitGroupPaths(void);
void BuildGroupPath(u32 groupIndex, CourseMapEntryGroup *entryGroup);
void BuildSegment(Segment *segment, s32 useStraightLength, s32 computeUp, Vec3 *previousPoint, Vec3 *startPoint,
                  Vec3 *endPoint, Vec3 *nextPoint);
void GetSegmentProgressPointXzLinearY(void *segmentProgressPointer, Vec3 *position);
