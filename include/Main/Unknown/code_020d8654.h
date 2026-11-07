#pragma once

#include "types.h"

typedef struct Unk020e0144 Unk020e0144;
typedef struct CourseMapRow CourseMapRow;

u32 GetMaxXzDistanceToGroup(Unk020e0144 *follower, Vec3 *point);
void GetGroupFollowerLinearXz(Unk020e0144 *follower, Vec3 *position);
Vec3 *CreateCourseMapGroupSideVectors(CourseMapRow *row);
