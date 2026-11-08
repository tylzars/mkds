#pragma once

#include "types.h"

typedef struct GroupFollower GroupFollower;

void GetGroupFollowerCurvePosStep(GroupFollower *follower, Vec3 *position, Vec3 *step);
void GetGroupFollowerCurveXzLinearY(GroupFollower *follower, Vec3 *position);
