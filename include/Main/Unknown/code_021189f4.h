#pragma once

#include "types.h"

void AdvanceSelectCupCourseState3(void);
void AdvanceSelectCupCourseState4(void);
void AdvanceSelectCupCourseState5(void);
void AdvanceSelectCupCourseState6(void);
void AdvanceSelectCupCourseState7(void);
void AdvanceSelectCupCourseState8(void);
s32 AdvanceSelectCupCourse(void);
void WriteSelectCupCourseBgOffsets(void);
void LoadSelectCupGridData(void);
void func_02118b48(void);
// Returns whether cup a can be chosen in the current mode: the cups 0, 1, 4 and 5 always (mode 3 only 0 and 4), the
// others by the result of IsBackupFlagSet (func_0205fbb8 in mode 4) for the flag of that cup; changes nothing.
u32 GetSelectCupGridCupEnabled(u32 cupIndex);
