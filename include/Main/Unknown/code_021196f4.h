#pragma once

#include "types.h"

void RequestSelectCupCourseState7(void);
void RequestSelectCupCourseState8(void);
void InitSelectCupCourse(void *parentHeap, void *mainOam, void *subOam, s32 mode);
void ReleaseSelectCupCourse(void);
