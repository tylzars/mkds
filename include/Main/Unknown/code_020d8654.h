#pragma once

#include "types.h"

typedef struct GroupFollower GroupFollower;
typedef struct CourseMapRow CourseMapRow;

u32 GetMaxXzDistanceToGroup(GroupFollower *follower, Vec3 *point);
void GetGroupFollowerLinearXz(GroupFollower *follower, Vec3 *position);
Vec3 *CreateCourseMapGroupSideVectors(CourseMapRow *row);
