#include "Main/Unknown/code_02060004.h"
#include "Main/Unknown/code_0203b6ac.h"
#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_020563ec.h"
#include "Main/Unknown/code_02056408.h"
#include "Main/Unknown/code_02056a7c.h"
#include "Main/Unknown/code_02056b30.h"
#include "Main/Unknown/code_02056c6c.h"
#include "Main/Unknown/code_02057304.h"
#include "Main/Unknown/code_02057624.h"
#include "Main/Unknown/code_0205edcc.h"
#include "Main/Unknown/code_0205ee14.h"
#include "Main/Unknown/code_021526a0.h"
#include "Main/Unknown/code_02152918.h"
#include "code_0214d018.h"
#include "code_02152500.h"
#include "code_02152a24.h"
#include "00/code_021832d8.h"
#include "00/code_0219d948.h"

static inline s32 func_02060004_inline(s32 courseId, s32 recordIndex, TimeRecord *timeRecord) {
    BOOL isFilled;

    if (GetCourseTimeRecord(courseId, recordIndex, timeRecord) != 0 && timeRecord->mFilled != 0) {
        isFilled = TRUE;
    } else {
        isFilled = FALSE;
    }
    return isFilled;
}

void CopyWiFiBuddiesToRecordBlock(Unk0217d384_19f0 *buddies) {
    MI_CpuCopy8(buddies, (u8 *) data_0217aa08->mBuddyRecordBlock + 0x874, 0x2d0);
}

void RefreshNotYetBuddyFlags(void) {
    BuddyRecord buddyRecord;
    u8 recordIndex;

    for (recordIndex = 0; recordIndex < 60; recordIndex++) {
        GetBuddyRecord(recordIndex, &buddyRecord);
        if (buddyRecord.mFilled == 1 && buddyRecord.mNotYetBuddy == 1 &&
            DWC_IsBuddyFriendData(
                (DWCAccFriendData *) ((u8 *) data_0217aa08->mBuddyRecordBlock + 0x874 + recordIndex * 12)) != 0) {
            buddyRecord.mNotYetBuddy = 0;
            SetBuddyRecord(recordIndex, &buddyRecord);
        }
    }
}

BOOL IsBuddyRecordFilled(u8 recordIndex) {
    BuddyRecord buddyRecord;

    GetBuddyRecord(recordIndex, &buddyRecord);
    if (buddyRecord.mFilled == 1) {
        return TRUE;
    }
    return FALSE;
}

s32 IsBuddyRecordFlagged(u8 recordIndex) {
    BuddyRecord buddyRecord;

    GetBuddyRecord(recordIndex, &buddyRecord);
    if (buddyRecord.mFilled == 1) {
        return buddyRecord.mFlagged;
    }
    return 0;
}

s32 func_02060ac8(u8 recordIndex) {
    BuddyRecord buddyRecord;

    GetBuddyRecord(recordIndex, &buddyRecord);
    if (buddyRecord.mFilled == 1) {
        return buddyRecord.mResultCounts[0][0];
    }
    return -1;
}

s32 func_02060a94(u8 recordIndex) {
    BuddyRecord buddyRecord;

    GetBuddyRecord(recordIndex, &buddyRecord);
    if (buddyRecord.mFilled == 1) {
        return buddyRecord.mResultCounts[0][1];
    }
    return -1;
}

s32 func_02060a60(u8 recordIndex) {
    BuddyRecord buddyRecord;

    GetBuddyRecord(recordIndex, &buddyRecord);
    if (buddyRecord.mFilled == 1) {
        return buddyRecord.mResultCounts[1][0];
    }
    return -1;
}

s32 func_02060a2c(u8 recordIndex) {
    BuddyRecord buddyRecord;

    GetBuddyRecord(recordIndex, &buddyRecord);
    if (buddyRecord.mFilled == 1) {
        return buddyRecord.mResultCounts[1][1];
    }
    return -1;
}

s32 func_020609f8(u8 recordIndex) {
    BuddyRecord buddyRecord;

    GetBuddyRecord(recordIndex, &buddyRecord);
    if (buddyRecord.mFilled == 1) {
        return buddyRecord.mResultCounts[2][0];
    }
    return -1;
}

s32 func_020609c4(u8 recordIndex) {
    BuddyRecord buddyRecord;

    GetBuddyRecord(recordIndex, &buddyRecord);
    if (buddyRecord.mFilled == 1) {
        return buddyRecord.mResultCounts[2][1];
    }
    return -1;
}

BOOL GetBuddyRecordDate(u8 recordIndex, u8 *dateOut) {
    BuddyRecord buddyRecord;

    GetBuddyRecord(recordIndex, &buddyRecord);
    if (buddyRecord.mFilled != 1) {
        return FALSE;
    }
    dateOut[0] = buddyRecord.mYear;
    dateOut[1] = buddyRecord.mMonth;
    dateOut[2] = buddyRecord.mDay;
    return TRUE;
}

BOOL GetBuddyRecordName(u8 recordIndex, void *nameOut) {
    BuddyRecord buddyRecord;

    GetBuddyRecord(recordIndex, &buddyRecord);
    if (buddyRecord.mFilled != 1) {
        return FALSE;
    }
    MI_CpuCopy8(buddyRecord.mName, nameOut, 0x14);
    return TRUE;
}

BOOL SetBuddyRecordFlag(u8 recordIndex, s32 flag) {
    BuddyRecord buddyRecord;

    GetBuddyRecord(recordIndex, &buddyRecord);
    if (buddyRecord.mFilled == 1) {
        buddyRecord.mFlagged = flag != 0;
        SetBuddyRecord(recordIndex, &buddyRecord);
        return TRUE;
    }
    return FALSE;
}

s32 RemoveBuddyRecord(u8 recordIndex) {
    BuddyRecord buddyRecord;
    BOOL wasFilled;

    GetBuddyRecord(recordIndex, &buddyRecord);
    wasFilled = buddyRecord.mFilled == 1;
    MI_CpuFill8(&buddyRecord, 0, 0x24);
    buddyRecord.mFilled = 0;
    SetBuddyRecord(recordIndex, &buddyRecord);
    if (gWiFiSession->mUnk_0008.mState != 0) {
        RemoveBuddyEntry((u8 *) data_0217aa08->mBuddyRecordBlock + 0x874 + recordIndex * 12);
    } else {
        MI_CpuFill8((u8 *) data_0217aa08->mBuddyRecordBlock + 0x874 + recordIndex * 12, 0, 0xc);
    }
    WriteBackupBuddyRecords();
    return wasFilled;
}

void MergeBuddyRecords(u8 keptIndex, u8 mergedIndex) {
    BuddyRecord keptRecord;
    BuddyRecord mergedRecord;
    BuddyRecord combinedRecord;

    GetBuddyRecord(keptIndex, &keptRecord);
    GetBuddyRecord(mergedIndex, &mergedRecord);
    ResetBuddyRecord((u32) &combinedRecord);
    if (mergedRecord.mNotYetBuddy == 0) {
        combinedRecord.mResultCounts[0][0] = combinedRecord.mResultCounts[0][0] + mergedRecord.mResultCounts[0][0];
        combinedRecord.mResultCounts[0][1] = combinedRecord.mResultCounts[0][1] + mergedRecord.mResultCounts[0][1];
        combinedRecord.mResultCounts[1][0] = combinedRecord.mResultCounts[1][0] + mergedRecord.mResultCounts[1][0];
        combinedRecord.mResultCounts[1][1] = combinedRecord.mResultCounts[1][1] + mergedRecord.mResultCounts[1][1];
        combinedRecord.mResultCounts[2][0] = combinedRecord.mResultCounts[2][0] + mergedRecord.mResultCounts[2][0];
        combinedRecord.mResultCounts[2][1] = combinedRecord.mResultCounts[2][1] + mergedRecord.mResultCounts[2][1];
        MI_CpuCopy8(mergedRecord.mName, combinedRecord.mName, 0x14);
        combinedRecord.mYear = mergedRecord.mYear;
        combinedRecord.mMonth = mergedRecord.mMonth;
        combinedRecord.mDay = mergedRecord.mDay;
    }
    if (keptRecord.mNotYetBuddy == 0) {
        combinedRecord.mResultCounts[0][0] = combinedRecord.mResultCounts[0][0] + keptRecord.mResultCounts[0][0];
        combinedRecord.mResultCounts[0][1] = combinedRecord.mResultCounts[0][1] + keptRecord.mResultCounts[0][1];
        combinedRecord.mResultCounts[1][0] = combinedRecord.mResultCounts[1][0] + keptRecord.mResultCounts[1][0];
        combinedRecord.mResultCounts[1][1] = combinedRecord.mResultCounts[1][1] + keptRecord.mResultCounts[1][1];
        combinedRecord.mResultCounts[2][0] = combinedRecord.mResultCounts[2][0] + keptRecord.mResultCounts[2][0];
        combinedRecord.mResultCounts[2][1] = combinedRecord.mResultCounts[2][1] + mergedRecord.mResultCounts[2][1];
        MI_CpuCopy8(keptRecord.mName, combinedRecord.mName, 0x14);
        combinedRecord.mYear = keptRecord.mYear;
        combinedRecord.mMonth = keptRecord.mMonth;
        combinedRecord.mDay = keptRecord.mDay;
    }
    combinedRecord.mFilled = 1;
    combinedRecord.mNotYetBuddy = 0;
    combinedRecord.mUnk_22_2 = keptRecord.mUnk_22_2;
    combinedRecord.mFlagged = keptRecord.mFlagged == 1 || mergedRecord.mFlagged == 1;
    SetBuddyRecord(keptIndex, &combinedRecord);
    MI_CpuFill8(&mergedRecord, 0, 0x24);
    mergedRecord.mFilled = 0;
    SetBuddyRecord(mergedIndex, &mergedRecord);
}

BOOL GetBuddyFriendKeyText(u8 recordIndex, void *textOut) {
    u8 *friendData;
    BOOL found;
    BOOL hasFriendKey;
    BuddyRecord buddyRecord;

    found = FALSE;
    GetBuddyRecord(recordIndex, &buddyRecord);
    friendData = (u8 *) data_0217aa08->mBuddyRecordBlock + 0x874 + recordIndex * 12;
    if (buddyRecord.mFilled == 1 && buddyRecord.mNotYetBuddy == 1 && IsFriendDataTypeNonZero(friendData) != 0) {
        hasFriendKey = TRUE;
    } else {
        hasFriendKey = FALSE;
    }
    if (hasFriendKey != FALSE) {
        u64 friendKey = DWC_GetFriendKey((DWCAccFriendData *) friendData);

        FormatFriendKey(friendKey, friendKey >> 32, (u32) textOut);
        found = TRUE;
    }
    return found;
}

s32 IsGrandPrixRecordFilled(s32 cup, s32 engineClass) {
    TimeRecord timeRecord;

    GetGrandPrixRecord(cup, engineClass, &timeRecord);
    if (timeRecord.mFilled == 0) {
        return 0;
    }
    return timeRecord.mFilled;
}

s32 GetGrandPrixRecordCharacterIndex(s32 cup, s32 engineClass) {
    TimeRecord timeRecord;

    GetGrandPrixRecord(cup, engineClass, &timeRecord);
    if (timeRecord.mFilled != 0) {
        return timeRecord.mCharacterIndex;
    }
    return -1;
}

s32 GetGrandPrixRecordKartIndex(s32 cup, s32 engineClass) {
    TimeRecord timeRecord;

    GetGrandPrixRecord(cup, engineClass, &timeRecord);
    if (timeRecord.mFilled != 0) {
        return timeRecord.mKartIndex;
    }
    return -1;
}

s32 GetGrandPrixRecordCupRank(s32 cup, s32 engineClass) {
    TimeRecord timeRecord;

    GetGrandPrixRecord(cup, engineClass, &timeRecord);
    if (timeRecord.mFilled != 0) {
        return timeRecord.mCupRank;
    }
    return 3;
}

s32 GetGrandPrixRecordTotalPoints(s32 cup, s32 engineClass) {
    TimeRecord timeRecord;

    GetGrandPrixRecord(cup, engineClass, &timeRecord);
    if (timeRecord.mFilled != 0) {
        return (s8) timeRecord.mTotalPoints;
    }
    return -1;
}

s32 func_02060364(s32 cup, s32 engineClass) {
    TimeRecord timeRecord;

    GetGrandPrixRecord(cup, engineClass, &timeRecord);
    if (timeRecord.mFilled != 0) {
        return timeRecord.mUnk_1e;
    }
    return 9;
}

BOOL GetGrandPrixRecordTime(s32 cup, s32 engineClass, void *timeOut) {
    TimeRecord timeRecord;

    GetGrandPrixRecord(cup, engineClass, &timeRecord);
    if (timeRecord.mFilled == 0) {
        return FALSE;
    }
    MI_CpuCopy8(&timeRecord, timeOut, 4);
    return TRUE;
}

BOOL func_02060268(s32 courseId) {
    u8 recordIndex;
    BOOL noRecords;
    s32 cupCourseIndex;
    TimeRecord timeRecord;

    noRecords = TRUE;
    cupCourseIndex = FindCupCourseIndex(courseId);
    if (cupCourseIndex == -1) {
        return noRecords;
    }
    if (IsCourseGhostBitSet(cupCourseIndex) == 0) {
        return noRecords;
    }
    for (recordIndex = 0; recordIndex < 6; recordIndex++) {
        if (func_02060004_inline(courseId, recordIndex, &timeRecord)) {
            noRecords = FALSE;
            break;
        }
    }
    return noRecords;
}

BOOL IsTimeRecordFilled(s32 courseId, s32 recordIndex) {
    TimeRecord timeRecord;

    if (GetCourseTimeRecord(courseId, recordIndex, &timeRecord) != 0 && timeRecord.mFilled != 0) {
        return TRUE;
    }
    return FALSE;
}

s32 GetTimeRecordCharacterIndex(s32 courseId, s32 recordIndex) {
    TimeRecord timeRecord;

    if (func_02060004_inline(courseId, recordIndex, &timeRecord)) {
        return timeRecord.mCharacterIndex;
    }
    return -1;
}

s32 GetTimeRecordKartIndex(s32 courseId, s32 recordIndex) {
    TimeRecord timeRecord;

    if (func_02060004_inline(courseId, recordIndex, &timeRecord)) {
        return timeRecord.mKartIndex;
    }
    return -1;
}

BOOL GetTimeRecordTime(s32 courseId, s32 recordIndex, void *timeOut) {
    TimeRecord timeRecord;
    TimeRecord *outRecord;

    if (!func_02060004_inline(courseId, recordIndex, &timeRecord)) {
        return FALSE;
    }
    outRecord = timeOut;
    outRecord->mMinute = timeRecord.mMinute;
    outRecord->mSecond = timeRecord.mSecond;
    outRecord->mMillisecond = timeRecord.mMillisecond;
    return TRUE;
}

BOOL GetTimeRecordName(s32 courseId, s32 recordIndex, void *nameOut) {
    TimeRecord timeRecord;

    if (!func_02060004_inline(courseId, recordIndex, &timeRecord)) {
        return FALSE;
    }
    MI_CpuCopy8(timeRecord.mName, nameOut, 0x14);
    return TRUE;
}

s32 func_020600b4(s32 courseId) {
    return func_0203b96c(FindCupIndexOfCourse(courseId));
}

void ClearCourseTimeRecords(s32 courseId) {
    u8 recordIndex;
    BOOL ghostBitCleared;
    u8 e;
    s32 cupCourseIndex;
    TimeRecord timeRecord;

    cupCourseIndex = FindCupCourseIndex(courseId);
    ghostBitCleared = FALSE;
    if (cupCourseIndex == -1) {
        return;
    }
    e = cupCourseIndex;
    if (IsCourseGhostBitSet(e) != 0) {
        ClearCourseGhostBit(e);
        ghostBitCleared = TRUE;
    }
    for (recordIndex = 0; recordIndex < 6; recordIndex++) {
        MI_CpuFill8(&timeRecord, 0, 0x20);
        SetCourseTimeRecord(courseId, recordIndex, &timeRecord);
    }
    if (ghostBitCleared != FALSE) {
        func_020563ec();
    } else {
        WriteBackupCourseTimeRecords();
    }
}
