#include "Main/Unknown/code_020d8bc0.h"
#include "Main/Unknown/code_020d8cac.h"
#include "Main/Unknown/code_020d939c.h"
#include "Main/Unknown/code_020e005c.h"

void GetGroupFollowerCurvePosStep(GroupFollower *follower, Vec3 *position, Vec3 *step) {
    GetSegmentCurvePosStep(&follower->mPath->mSegments[follower->mSegmentIndex], follower->mProgress,
                           follower->mProgressStep, position, step);
    if (follower->mForward == 0) {
        step->x = -step->x;
        step->y = -step->y;
        step->z = -step->z;
    }
}

void GetGroupFollowerCurveXzLinearY(GroupFollower *follower, Vec3 *position) {
    GetSegmentCurveXzLinearY(&follower->mPath->mSegments[follower->mSegmentIndex], follower->mProgress, position);
}
