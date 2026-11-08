#include "Main/Unknown/code_020d7db4.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020d7000.h"
#include "Main/Unknown/code_020d9000.h"

#include "Main/Unknown/code_020d8cac.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020d6dc0.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_02042044.h"
#include "Main/Unknown/unk_02158000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020d849c.h"
#include "code_02147cd8.h"

#pragma thumb off

void GetSegmentProgressPointXzLinearY(void *segmentProgressPointer, Vec3 *position) {
    SegmentProgress *segmentProgress = segmentProgressPointer;
    GetSegmentCurveXzLinearY(&segmentProgress->mUnk_00, segmentProgress->mUnk_5c, position);
}

#pragma thumb on

void BuildSegment(Segment *segment, s32 useStraightLength, s32 computeUp, Vec3 *previousPoint, Vec3 *startPoint,
                  Vec3 *endPoint, Vec3 *nextPoint) {
    Vec3 startToEnd;
    Vec3 direction;
    Vec3 previousToEnd;
    Vec3 startSlope;
    Vec3 startToNext;
    Vec3 endSlope;
    s32 length;
    s32 startExtra = 0;
    s32 endExtra = 0;
    s32 r;
    s32 bend;
    s64 squaredUpLength;
    segment->mPoints[0] = *startPoint;
    segment->mPoints[3] = *endPoint;
    VEC_Subtract(endPoint, startPoint, &startToEnd);
    length = Vec3NormalizeAndGetLengthOrZero(&startToEnd, &direction);
    if (length == 0) {
        segment->mPoints[1] = segment->mPoints[0];
        segment->mPoints[2] = segment->mPoints[3];
        segment->mProgressLength = 0;
        segment->mInverseProgressLength = 0;
        if (computeUp != 0) {
            segment->mUp = data_0215807c;
        }
        return;
    }
    if (previousPoint != NULL) {
        VEC_Subtract(endPoint, previousPoint, &previousToEnd);
        if (Vec3NormalizeAndGetLengthOrZero(&previousToEnd, &previousToEnd) != 0) {
            bend = (0x1000 - Vec3DotUnrounded(&direction, &previousToEnd)) >> 1;
            startExtra = ((s64) length * (s64) bend) >> 12;
            if (useStraightLength != 0) {
                startSlope.x = ((s64) previousToEnd.x * length) >> 12;
                startSlope.y = ((s64) previousToEnd.y * length) >> 12;
                startSlope.z = ((s64) previousToEnd.z * length) >> 12;
            } else {
                r = length + startExtra;
                startSlope.x = ((s64) previousToEnd.x * (s64) r) >> 12;
                startSlope.y = ((s64) previousToEnd.y * (s64) r) >> 12;
                startSlope.z = ((s64) previousToEnd.z * (s64) r) >> 12;
            }
            VEC_MultAdd(0x555, &startSlope, &segment->mPoints[0], &segment->mPoints[1]);
        } else {
            segment->mPoints[1] = segment->mPoints[0];
        }
    } else {
        segment->mPoints[1] = segment->mPoints[0];
    }
    if (nextPoint != NULL) {
        VEC_Subtract(nextPoint, startPoint, &startToNext);
        if (Vec3NormalizeAndGetLengthOrZero(&startToNext, &startToNext) != 0) {
            bend = (0x1000 - Vec3DotUnrounded(&direction, &startToNext)) >> 1;
            endExtra = ((s64) length * (s64) bend) >> 12;
            if (useStraightLength != 0) {
                endSlope.x = ((s64) startToNext.x * length) >> 12;
                endSlope.y = ((s64) startToNext.y * length) >> 12;
                endSlope.z = ((s64) startToNext.z * length) >> 12;
            } else {
                r = length + endExtra;
                endSlope.x = ((s64) startToNext.x * (s64) r) >> 12;
                endSlope.y = ((s64) startToNext.y * (s64) r) >> 12;
                endSlope.z = ((s64) startToNext.z * (s64) r) >> 12;
            }
            VEC_MultAdd(-0x555, &endSlope, &segment->mPoints[3], &segment->mPoints[2]);
        } else {
            segment->mPoints[2] = segment->mPoints[3];
        }
    } else {
        segment->mPoints[2] = segment->mPoints[3];
    }
    segment->mStraightLength = length;
    segment->mInverseStraightLength = FX_Div(0x1000000, segment->mStraightLength);
    segment->mCurveLength = endExtra + (length + startExtra);
    segment->mInverseCurveLength = FX_Div(0x1000000, segment->mCurveLength);
    segment->mProgressLength = segment->mCurveLength;
    segment->mInverseProgressLength = segment->mInverseCurveLength;
    if (computeUp != 0) {
        r = VEC_DotProduct(&direction, &data_02158088);
        segment->mUp.x = data_02158088.x - (s32) (((s64) direction.x * (s64) r) >> 12);
        segment->mUp.y = data_02158088.y - (s32) (((s64) direction.y * (s64) r) >> 12);
        segment->mUp.z = data_02158088.z - (s32) (((s64) direction.z * (s64) r) >> 12);
        squaredUpLength = (s64) segment->mUp.x * segment->mUp.x + (s64) segment->mUp.y * segment->mUp.y +
                          (s64) segment->mUp.z * segment->mUp.z;
        if (squaredUpLength < 16) {
            r = 0;
        } else {
            r = Vec3NormalizeAndGetLengthUnchecked(&segment->mUp, &segment->mUp);
        }
        if (r == 0) {
            segment->mUp = data_02158088;
        }
    }
}

void BuildGroupPath(u32 groupIndex, CourseMapEntryGroup *entryGroup) {
    GroupPath *path;
    s32 entryCount;
    s32 segmentIndex;
    path = &gGroupPaths[groupIndex];
    if (path->mSegments != NULL) {
        return;
    }
    entryCount = entryGroup->mEntryCount;
    path->mSegmentCount = entryCount;
    path->mWraps = entryGroup->mUnk_01;
    if (path->mWraps == 0) {
        path->mSegmentCount = path->mSegmentCount - 1;
    }
    path->mSegments = HeapAlloc(GetHeap(GetCurrentHeapCall()), path->mSegmentCount * 0x54);
    if (entryCount == 2) {
        BuildSegment(path->mSegments, 0, 1, NULL, &GetCourseMapGroupEntry(groupIndex, 0)->mPos,
                     &GetCourseMapGroupEntry(groupIndex, 1)->mPos, NULL);
        if (path->mWraps != 0) {
            BuildSegment(&path->mSegments[1], 0, 1, NULL, &GetCourseMapGroupEntry(groupIndex, 1)->mPos,
                         &GetCourseMapGroupEntry(groupIndex, 0)->mPos, NULL);
        }
        return;
    }
    if (path->mWraps != 0) {
        BuildSegment(path->mSegments, 0, 1, &GetCourseMapGroupEntry(groupIndex, entryCount - 1)->mPos,
                     &GetCourseMapGroupEntry(groupIndex, 0)->mPos, &GetCourseMapGroupEntry(groupIndex, 1)->mPos,
                     &GetCourseMapGroupEntry(groupIndex, 2)->mPos);
    } else {
        BuildSegment(path->mSegments, 0, 1, NULL, &GetCourseMapGroupEntry(groupIndex, 0)->mPos,
                     &GetCourseMapGroupEntry(groupIndex, 1)->mPos, &GetCourseMapGroupEntry(groupIndex, 2)->mPos);
    }
    for (segmentIndex = 1; segmentIndex < entryCount - 2; segmentIndex++) {
        BuildSegment(&path->mSegments[segmentIndex], 0, 1, &GetCourseMapGroupEntry(groupIndex, segmentIndex - 1)->mPos,
                     &GetCourseMapGroupEntry(groupIndex, segmentIndex)->mPos,
                     &GetCourseMapGroupEntry(groupIndex, segmentIndex + 1)->mPos,
                     &GetCourseMapGroupEntry(groupIndex, segmentIndex + 2)->mPos);
    }
    if (path->mWraps != 0) {
        BuildSegment(&path->mSegments[segmentIndex], 0, 1, &GetCourseMapGroupEntry(groupIndex, segmentIndex - 1)->mPos,
                     &GetCourseMapGroupEntry(groupIndex, segmentIndex)->mPos,
                     &GetCourseMapGroupEntry(groupIndex, segmentIndex + 1)->mPos,
                     &GetCourseMapGroupEntry(groupIndex, 0)->mPos);
    } else {
        BuildSegment(&path->mSegments[segmentIndex], 0, 1, &GetCourseMapGroupEntry(groupIndex, segmentIndex - 1)->mPos,
                     &GetCourseMapGroupEntry(groupIndex, segmentIndex)->mPos,
                     &GetCourseMapGroupEntry(groupIndex, segmentIndex + 1)->mPos, NULL);
    }
    if (path->mWraps != 0) {
        BuildSegment(&path->mSegments[segmentIndex + 1], 0, 1, &GetCourseMapGroupEntry(groupIndex, segmentIndex)->mPos,
                     &GetCourseMapGroupEntry(groupIndex, segmentIndex + 1)->mPos,
                     &GetCourseMapGroupEntry(groupIndex, 0)->mPos, &GetCourseMapGroupEntry(groupIndex, 1)->mPos);
    }
}

void InitGroupPaths(void) {
    s32 groupCount = gCourseMap->mEntryGroupCount;
    s32 groupIndex;
    if (groupCount != 0) {
        gGroupPaths = HeapAlloc(GetHeap(GetCurrentHeapCall()), groupCount * 0xc);
    }
    for (groupIndex = 0; groupIndex < groupCount; groupIndex++) {
        gGroupPaths[groupIndex].mSegments = NULL;
    }
}

#pragma thumb off

#pragma thumb on

void InitGroupFollowerForGroup(GroupFollower *follower, u16 groupIndex, int speed) {
    follower->mGroupIndex = groupIndex;
    BuildGroupPath(follower->mGroupIndex, &gCourseMap->mEntryGroups[follower->mGroupIndex]);
    follower->mPath = &gGroupPaths[follower->mGroupIndex];
    follower->mSpeed = speed;
    SetupGroupFollowerAtEntry(follower, 0, 1);
}

#pragma thumb off
