#include "Main/Unknown/code_02056b30.h"
#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_0214d018.h"

#pragma thumb on

void UnpackCourseTimeRecord(PackedCourseTimeRecord *packedCourseTimeRecord, TimeRecord *timeRecord) {
    if (packedCourseTimeRecord->mFilled != 0) {
        MI_CpuCopy8(packedCourseTimeRecord->mName, timeRecord->mName, 0x14);
        timeRecord->mCharacterIndex = packedCourseTimeRecord->mCharacterIndex;
        timeRecord->mKartIndex = packedCourseTimeRecord->mKartIndex;
        timeRecord->mMinute = packedCourseTimeRecord->mMinute;
        timeRecord->mSecond = packedCourseTimeRecord->mSecond;
        timeRecord->mMillisecond = packedCourseTimeRecord->mMillisecond;
        timeRecord->mFilled = 1;
    } else {
        MI_CpuFill8(timeRecord, 0, 0x20);
    }
}

BOOL GetCourseTimeRecord(s32 courseId, s32 recordIndex, TimeRecord *timeRecord) {
    BOOL found;
    s32 cupCourseIndex;

    cupCourseIndex = FindCupCourseIndex(courseId);
    found = TRUE;
    if (cupCourseIndex != -1) {
        UnpackCourseTimeRecord(&data_0217aa08->mCourseTimeRecordBlock->mRecords[recordIndex][cupCourseIndex],
                               timeRecord);
    } else {
        found = FALSE;
    }
    if (found == FALSE) {
        timeRecord->mFilled = 0;
    }
    return found;
}

void PackGrandPrixRecord(PackedGrandPrixRecord *packedGrandPrixRecord, TimeRecord *timeRecord) {
    if (timeRecord->mFilled != 0) {
        MI_CpuCopy8(timeRecord->mName, packedGrandPrixRecord->mName, 0x14);
        packedGrandPrixRecord->mFilled = 1;
        packedGrandPrixRecord->mCharacterIndex = timeRecord->mCharacterIndex;
        packedGrandPrixRecord->mUnk_00_b[1] = timeRecord->mKartIndex;
        packedGrandPrixRecord->mMinute = timeRecord->mMinute;
        packedGrandPrixRecord->mSecond = timeRecord->mSecond;
        packedGrandPrixRecord->mMillisecond = timeRecord->mMillisecond;
        packedGrandPrixRecord->mUnk_00_b[3] = timeRecord->mUnk_1e;
        packedGrandPrixRecord->mUnk_00_b[2] = timeRecord->mTotalPoints;
        packedGrandPrixRecord->mUnk_04_b[0] = timeRecord->mCupRank;
    }
}

#pragma thumb off
