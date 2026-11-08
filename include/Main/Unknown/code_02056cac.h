#pragma once

#include "types.h"

typedef struct TimeRecord TimeRecord;
typedef struct PackedCourseTimeRecord PackedCourseTimeRecord;

void PackCourseTimeRecord(PackedCourseTimeRecord *packedCourseTimeRecord, TimeRecord *timeRecord);
