#include "Main/Unknown/code_02056cac.h"
#include "Main/Unknown/code_02056b30.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_0214d018.h"

#pragma thumb on

void PackCourseTimeRecord(PackedCourseTimeRecord *packedCourseTimeRecord, TimeRecord *timeRecord) {
    if (timeRecord->mFilled != 0) {
        MI_CpuCopy8(timeRecord->mName, packedCourseTimeRecord->mName, 0x14);
        packedCourseTimeRecord->mFilled = 1;
        packedCourseTimeRecord->mCharacterIndex = timeRecord->mCharacterIndex;
        packedCourseTimeRecord->mKartIndex = timeRecord->mKartIndex;
        packedCourseTimeRecord->mMinute = timeRecord->mMinute;
        packedCourseTimeRecord->mSecond = timeRecord->mSecond;
        packedCourseTimeRecord->mMillisecond = timeRecord->mMillisecond;
    } else {
        MI_CpuFill8(packedCourseTimeRecord, 0, 0x1c);
    }
}

#pragma thumb off
