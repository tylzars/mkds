#pragma once

#include "types.h"

typedef struct TimeRecord TimeRecord;

void SetCourseTimeRecord(u32 courseId, int recordIndex, TimeRecord *timeRecord);
