#include "Main/Unknown/code_020d8654.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02042044.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "code_02147cd8.h"
#include "registers.h"

u32 GetMaxXzDistanceToGroup(GroupFollower *follower, Vec3 *point) {
    GroupPath *path;
    s32 segmentIndex;
    s64 maxDistanceSquared;
    Segment *segment;
    s64 distanceSquared;
    s32 pointX;
    s32 pointZ;
    s32 delta;
    path = follower->mPath;
    maxDistanceSquared = 0;
    segmentIndex = path->mSegmentCount - 1;
    segment = path->mSegments;
    if (segmentIndex >= 0) {
        segment = &segment[segmentIndex];
        pointX = point->x;
        pointZ = point->z;
        do {
            delta = pointX - segment->mPoints[0].x;
            distanceSquared = (s64) delta * delta;
            delta = pointZ - segment->mPoints[0].z;
            distanceSquared = distanceSquared + (s64) delta * delta;
            if (maxDistanceSquared < distanceSquared) {
                maxDistanceSquared = distanceSquared;
            }
            delta = pointX - segment->mPoints[3].x;
            distanceSquared = (s64) delta * delta;
            delta = pointZ - segment->mPoints[3].z;
            distanceSquared = distanceSquared + (s64) delta * delta;
            if (maxDistanceSquared < distanceSquared) {
                maxDistanceSquared = distanceSquared;
            }
            segment--;
            segmentIndex--;
        } while (segmentIndex >= 0);
    }
    reg_CP_SQRTCNT = 1;
    *(vs64 *) 0x40002b8 = maxDistanceSquared;
    while (reg_CP_SQRTCNT & 0x8000) {
    }
    return reg_CP_SQRT_RESULT;
}

void GetGroupFollowerLinearXz(GroupFollower *follower, Vec3 *position) {
    Segment *segment;
    s32 progress;
    s32 remaining;
    segment = &follower->mPath->mSegments[follower->mSegmentIndex];
    progress = follower->mProgress;
    remaining = 0x1000000 - progress;
    position->x = ((s64) segment->mPoints[0].x * remaining) >> 24;
    position->z = ((s64) segment->mPoints[0].z * remaining) >> 24;
    position->x = position->x + (s32) (((s64) segment->mPoints[3].x * progress) >> 24);
    position->z = position->z + (s32) (((s64) segment->mPoints[3].z * progress) >> 24);
}

Vec3 *CreateCourseMapGroupSideVectors(CourseMapRow *row) {
    u16 entryIndex;
    u16 groupIndex;
    u16 entryCount;
    Vec3 *sideVectors;
    Vec3 direction;
    CourseMapGroupEntry *endEntry;
    CourseMapGroupEntry *startEntry;
    s32 savedZ;
    groupIndex = row->mUnk_26;
    entryCount = gCourseMap->mEntryGroups[groupIndex].mEntryCount;
    sideVectors = HeapAlloc(GetHeap(GetCurrentHeapCall()), entryCount * 12);
    for (entryIndex = 0; entryIndex < entryCount; entryIndex++) {
        if (entryIndex == entryCount - 1) {
            if (*(u8 *) ((u32) gCourseMap->mEntryGroups + groupIndex * 4 + 1) == 0) {
                continue;
            }
            endEntry = GetCourseMapGroupEntry(groupIndex, 0);
            startEntry = GetCourseMapGroupEntry(groupIndex, entryCount - 1);
            VEC_Subtract(&endEntry->mPos, &startEntry->mPos, &direction);
        } else {
            endEntry = GetCourseMapGroupEntry(groupIndex, entryIndex + 1);
            startEntry = GetCourseMapGroupEntry(groupIndex, entryIndex);
            VEC_Subtract(&endEntry->mPos, &startEntry->mPos, &direction);
        }
        savedZ = direction.z;
        direction.z = -direction.x;
        direction.y = 0;
        direction.x = savedZ;
        direction.y = 0;
        Vec3NormalizeAndGetLengthUnchecked(&direction, &sideVectors[entryIndex]);
    }
    return sideVectors;
}
