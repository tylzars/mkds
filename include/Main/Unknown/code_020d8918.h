#pragma once

#include "types.h"

typedef struct GroupFollower GroupFollower;

void GetGroupFollowerCurvePosStepXz(GroupFollower *follower, Vec3 *position, Vec3 *step);
void GetGroupFollowerLinearPosition(GroupFollower *follower, Vec3 *position);
void GetGroupFollowerLinearPosStep(GroupFollower *follower, Vec3 *position, Vec3 *step);
