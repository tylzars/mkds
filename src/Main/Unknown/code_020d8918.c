#include "Main/Unknown/code_020d8918.h"
#include "Main/Unknown/code_020d8cac.h"
#include "Main/Unknown/code_020e005c.h"
#include "code_02147cd8.h"

void GetGroupFollowerCurvePosStepXz(GroupFollower *follower, Vec3 *position, Vec3 *step) {
    GetSegmentCurvePosStepXz(&follower->mPath->mSegments[follower->mSegmentIndex], follower->mProgress,
                             follower->mProgressStep, position, step);
    if (follower->mForward == 0) {
        step->x = -step->x;
        step->z = -step->z;
    }
}

void GetGroupFollowerLinearPosition(GroupFollower *follower, Vec3 *position) {
    Segment *segment;
    s32 progress;
    s32 remaining;
    segment = &follower->mPath->mSegments[follower->mSegmentIndex];
    progress = follower->mProgress;
    remaining = 0x1000000 - progress;
    position->x = ((s64) segment->mPoints[0].x * remaining) >> 24;
    position->y = ((s64) segment->mPoints[0].y * remaining) >> 24;
    position->z = ((s64) segment->mPoints[0].z * remaining) >> 24;
    position->x = position->x + (s32) (((s64) segment->mPoints[3].x * progress) >> 24);
    position->y = position->y + (s32) (((s64) segment->mPoints[3].y * progress) >> 24);
    position->z = position->z + (s32) (((s64) segment->mPoints[3].z * progress) >> 24);
}

void GetGroupFollowerLinearPosStep(GroupFollower *follower, Vec3 *position, Vec3 *step) {
    Segment *segment;
    s32 progress;
    s32 remaining;
    s32 rate;
    segment = &follower->mPath->mSegments[follower->mSegmentIndex];
    progress = follower->mProgress;
    remaining = 0x1000000 - progress;
    position->x = ((s64) segment->mPoints[0].x * remaining) >> 24;
    position->y = ((s64) segment->mPoints[0].y * remaining) >> 24;
    position->z = ((s64) segment->mPoints[0].z * remaining) >> 24;
    position->x = position->x + (s32) (((s64) segment->mPoints[3].x * progress) >> 24);
    position->y = position->y + (s32) (((s64) segment->mPoints[3].y * progress) >> 24);
    position->z = position->z + (s32) (((s64) segment->mPoints[3].z * progress) >> 24);
    VEC_Subtract(&segment->mPoints[3], &segment->mPoints[0], step);
    rate = follower->mProgressStep;
    step->x = ((s64) step->x * rate) >> 24;
    step->y = ((s64) step->y * rate) >> 24;
    step->z = ((s64) step->z * rate) >> 24;
    if (follower->mForward == 0) {
        step->x = -step->x;
        step->y = -step->y;
        step->z = -step->z;
    }
}
