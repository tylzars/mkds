#include "Main/Unknown/code_020d8cac.h"
#include "Main/Unknown/code_020d94dc.h"
#include "Main/Unknown/code_02042044.h"

void GetSegmentCurvePosStepXz(Segment *segment, s32 fraction, s32 scale, Vec3 *firstResult, Vec3 *secondResult) {
    s32 firstWeight0;
    s32 firstWeight1;
    s32 firstWeight2;
    s32 firstWeight3;
    s32 secondWeight0;
    s32 secondWeight1;
    s32 secondWeight2;
    s32 secondWeight3;
    GetCurveAndSlopeWeights(fraction, &firstWeight0, &firstWeight1, &firstWeight2, &firstWeight3, &secondWeight0,
                            &secondWeight1, &secondWeight2, &secondWeight3);
    ComputeWeightedPointXz(segment->mPoints, firstResult, firstWeight0, firstWeight1, firstWeight2, firstWeight3);
    ComputeWeightedPointXz(segment->mPoints, secondResult, secondWeight0, secondWeight1, secondWeight2, secondWeight3);
    secondResult->x = ((s64) secondResult->x * scale) >> 24;
    secondResult->z = ((s64) secondResult->z * scale) >> 24;
}

void GetSegmentCurveXzLinearY(Segment *segment, s32 fraction, Vec3 *result) {
    s32 weight0;
    s32 weight1;
    s32 weight2;
    s32 weight3;
    GetCurveWeights(fraction, &weight0, &weight1, &weight2, &weight3);
    ComputeWeightedPointXz(segment->mPoints, result, weight0, weight1, weight2, weight3);
    result->y = ((s64) segment->mPoints[0].y * (0x1000000 - fraction)) >> 24;
    result->y = result->y + (s32) (((s64) segment->mPoints[3].y * fraction) >> 24);
}

void SetupGroupFollowerAtEntry(GroupFollower *follower, u16 entryIndex, s32 ascending) {
    GroupPath *path;
    u16 currentIndex;
    u16 nextIndex;
    s32 speedScale;
    path = follower->mPath;
    if (path->mWraps != 0) {
        if (entryIndex == 0 && ascending == 0) {
            entryIndex = path->mSegmentCount;
        }
    } else if (entryIndex == 0 && ascending == 0) {
        ascending = 1;
    } else if (entryIndex == path->mSegmentCount) {
        if (ascending != 0) {
            ascending = 0;
        }
    }
    follower->mSegmentIndex = ascending != 0 ? entryIndex : entryIndex - 1;
    speedScale = path->mSegments[follower->mSegmentIndex].mInverseProgressLength;
    follower->mProgressStep = speedScale != 0 ? (s32) (((s64) follower->mSpeed * speedScale) >> 12) : 0x1000000;
    follower->mProgress = ascending != 0 ? 0 : 0x1000000;
    follower->mForward = ascending;
    currentIndex = entryIndex;
    if (follower->mForward == 0 && path->mWraps != 0 && entryIndex == path->mSegmentCount) {
        currentIndex = 0;
    }
    follower->mFromEntry = GetCourseMapGroupEntry(follower->mGroupIndex, currentIndex);
    nextIndex = follower->mForward != 0 ? entryIndex + 1 : entryIndex - 1;
    if (follower->mForward != 0 && path->mWraps != 0 && nextIndex == path->mSegmentCount) {
        nextIndex = 0;
    }
    follower->mToEntry = GetCourseMapGroupEntry(follower->mGroupIndex, nextIndex);
}

BOOL AdvanceGroupFollower(GroupFollower *follower) {
    GroupPath *path;
    s32 speedScale;
    s32 segmentIndex;
    path = follower->mPath;
    if (follower->mForward != 0) {
        follower->mProgress = follower->mProgress + follower->mProgressStep;
        if (follower->mProgress >= 0x1000000) {
            if (follower->mSegmentIndex == path->mSegmentCount - 1) {
                if (path->mWraps != 0) {
                    follower->mProgress -= 0x1000000;
                    follower->mProgress =
                        ((s64) follower->mProgress * path->mSegments[follower->mSegmentIndex].mProgressLength) >> 12;
                    follower->mSegmentIndex = 0;
                    follower->mFromEntry = follower->mToEntry;
                    follower->mToEntry = GetCourseMapGroupEntry(follower->mGroupIndex, 1);
                    speedScale = path->mSegments[follower->mSegmentIndex].mInverseProgressLength;
                    if (speedScale != 0) {
                        follower->mProgress = ((s64) follower->mProgress * speedScale) >> 24;
                    }
                    follower->mProgressStep =
                        speedScale != 0 ? (s32) (((s64) follower->mSpeed * speedScale) >> 12) : 0x1000000;
                } else {
                    follower->mForward = 0;
                    follower->mProgress = 0x1000000;
                    follower->mFromEntry = follower->mToEntry;
                    follower->mToEntry = GetCourseMapGroupEntry(follower->mGroupIndex, follower->mSegmentIndex);
                }
            } else {
                follower->mProgress -= 0x1000000;
                follower->mProgress =
                    ((s64) follower->mProgress * path->mSegments[follower->mSegmentIndex].mProgressLength) >> 12;
                follower->mSegmentIndex = follower->mSegmentIndex + 1;
                follower->mFromEntry = follower->mToEntry;
                if (follower->mSegmentIndex == path->mSegmentCount - 1 && path->mWraps != 0) {
                    follower->mToEntry = GetCourseMapGroupEntry(follower->mGroupIndex, 0);
                } else {
                    follower->mToEntry = GetCourseMapGroupEntry(follower->mGroupIndex, follower->mSegmentIndex + 1);
                }
                speedScale = path->mSegments[follower->mSegmentIndex].mInverseProgressLength;
                if (speedScale != 0) {
                    follower->mProgress = ((s64) follower->mProgress * speedScale) >> 24;
                }
                follower->mProgressStep =
                    speedScale != 0 ? (s32) (((s64) follower->mSpeed * speedScale) >> 12) : 0x1000000;
            }
            return TRUE;
        }
    } else {
        follower->mProgress = follower->mProgress - follower->mProgressStep;
        if (follower->mProgress <= 0) {
            segmentIndex = follower->mSegmentIndex;
            if (segmentIndex == 0) {
                if (path->mWraps != 0) {
                    follower->mProgress =
                        ((s64) follower->mProgress * path->mSegments[segmentIndex].mProgressLength) >> 12;
                    follower->mSegmentIndex = path->mSegmentCount - 1;
                    follower->mFromEntry = follower->mToEntry;
                    follower->mToEntry = GetCourseMapGroupEntry(follower->mGroupIndex, path->mSegmentCount - 1);
                    speedScale = path->mSegments[follower->mSegmentIndex].mInverseProgressLength;
                    if (speedScale != 0) {
                        follower->mProgress = ((s64) follower->mProgress * speedScale) >> 24;
                    }
                    follower->mProgress = follower->mProgress + 0x1000000;
                    follower->mProgressStep =
                        speedScale != 0 ? (s32) (((s64) follower->mSpeed * speedScale) >> 12) : 0x1000000;
                } else {
                    follower->mForward = 1;
                    follower->mProgress = 0;
                    follower->mFromEntry = follower->mToEntry;
                    follower->mToEntry = GetCourseMapGroupEntry(follower->mGroupIndex, 1);
                }
            } else {
                follower->mProgress = ((s64) follower->mProgress * path->mSegments[segmentIndex].mProgressLength) >> 12;
                follower->mSegmentIndex = follower->mSegmentIndex - 1;
                follower->mFromEntry = follower->mToEntry;
                follower->mToEntry = GetCourseMapGroupEntry(follower->mGroupIndex, follower->mSegmentIndex);
                speedScale = path->mSegments[follower->mSegmentIndex].mInverseProgressLength;
                if (speedScale != 0) {
                    follower->mProgress = ((s64) follower->mProgress * speedScale) >> 24;
                }
                follower->mProgress = follower->mProgress + 0x1000000;
                follower->mProgressStep =
                    speedScale != 0 ? (s32) (((s64) follower->mSpeed * speedScale) >> 12) : 0x1000000;
            }
            return TRUE;
        }
    }
    return FALSE;
}

s32 GetGroupFollowerProgress(GroupFollower *follower) {
    s32 progress;
    if (follower->mForward != 0) {
        progress = follower->mProgress;
    } else {
        progress = 0x1000000 - follower->mProgress;
    }
    return progress >> 12;
}
