#include "Main/Unknown/code_02056c6c.h"
#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_02056cac.h"
#include "Main/Unknown/unk_0217a000.h"

#pragma thumb on

void SetCourseTimeRecord(u32 courseId, int recordIndex, TimeRecord *timeRecord) {
    int cupCourseIndex;
    cupCourseIndex = FindCupCourseIndex(courseId);
    if (cupCourseIndex != -1) {
        PackCourseTimeRecord(&data_0217aa08->mCourseTimeRecordBlock->mRecords[recordIndex][cupCourseIndex], timeRecord);
    }
}

#pragma thumb off
