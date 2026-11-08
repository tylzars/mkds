#pragma once

#include "types.h"

typedef struct RandomState64 RandomState64;

BOOL func_02045874(void);
s32 func_020458cc(void);
s32 func_02045914(void);
s32 AdvanceToNextCourse(void);
void SetupStaffRollRace(s32 useTrueStaffRoll);
BOOL func_02045bd4(void);
void func_02045ed0(void);
void BuildCourseList(s32 isVersus);
u32 func_02046524(RandomState64 *randomState64, u32 limit);
void AssignCpuNumbers(void);
BOOL func_02046648(s32 a);
