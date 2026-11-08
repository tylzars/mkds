#pragma once

#include "types.h"

typedef struct GroupFollower GroupFollower;
typedef struct CourseMapRow CourseMapRow;

void InitGroupFollower(GroupFollower *follower, CourseMapRow *row, s32 speed);
