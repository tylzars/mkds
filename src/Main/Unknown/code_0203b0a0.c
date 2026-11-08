#include "Main/Unknown/code_0203b0a0.h"
#include "code_0214d018.h"
#include "Main/Unknown/code_0202db04.h"
#include "Main/Unknown/code_02045000.h"
#include "Main/Unknown/code_020445f8.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_0203e000.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_0204e000.h"
#include "Main/Unknown/code_020563d8.h"
#include "Main/Unknown/code_02056408.h"
#include "Main/Unknown/code_02056700.h"
#include "Main/Unknown/code_02056a7c.h"
#include "Main/Unknown/code_02056b08.h"
#include "Main/Unknown/code_0205928c.h"
#include "Main/Unknown/code_0205d0e8.h"
#include "Main/Unknown/code_0211d4a8.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_02154000.h"
#include "Main/Unknown/unk_02164000.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_02044618.h"
#include "Main/Unknown/code_0204f240.h"
#include "Main/Unknown/code_0203c5f8.h"

void SumTimes(TimeRecord *firstTime, Unk0217aa1c_144_00 *secondTime, TimeRecord *sum) {
    u16 milliseconds = firstTime->mMillisecond + secondTime->mUnk_00;
    u16 minutes = firstTime->mMinute + secondTime->mUnk_02;
    u16 seconds = firstTime->mSecond + secondTime->mUnk_03;
    u16 carry = milliseconds / 1000;
    if (carry != 0) {
        seconds += carry;
        milliseconds -= carry * 1000;
    }
    carry = seconds / 60;
    if (carry != 0) {
        minutes += carry;
        seconds -= carry * 60;
    }
    if (minutes > 99) {
        minutes = 99;
    }
    sum->mMinute = minutes;
    sum->mSecond = seconds;
    sum->mMillisecond = milliseconds;
}

void FillGrandPrixRecord(TimeRecord *record) {
    u8 courseIndex;
    record->mMinute = 0;
    record->mSecond = 0;
    record->mMillisecond = 0;
    MI_CpuCopy8(data_0217aa08->mFirstBlock->mPlayerName, record->mName, 0x14);
    for (courseIndex = 0; courseIndex < 4; courseIndex++) {
        SumTimes(record, &data_0217b488->mCourseTimes[courseIndex], record);
    }
    record->mCharacterIndex = data_0217b488->mCharacterIndex;
    record->mKartIndex = data_0217b488->mKartIndex;
    record->mUnk_1b = 0;
    record->mCupRank = gCupRankTable[data_0217b488->mCupRankIndex];
    record->mTotalPoints = data_0217b488->mTotalPoints;
    record->mUnk_1e = data_0217b488->mUnk_80;
    record->mFilled = 1;
}

BOOL ShouldSetGrandPrixRecord(TimeRecord *storedRecord, TimeRecord *newRecord) {
    s32 storedTimeMs;
    s32 newTimeMs;
    if (newRecord->mCupRank == 3) {
        return FALSE;
    }
    if (storedRecord->mFilled == 0) {
        return TRUE;
    }
    if (storedRecord->mCupRank > newRecord->mCupRank) {
        return TRUE;
    }
    if (storedRecord->mCupRank < newRecord->mCupRank) {
        return FALSE;
    }
    if (storedRecord->mUnk_1e < newRecord->mUnk_1e) {
        return TRUE;
    }
    if (storedRecord->mUnk_1e > newRecord->mUnk_1e) {
        return FALSE;
    }
    if (storedRecord->mTotalPoints < newRecord->mTotalPoints) {
        return TRUE;
    }
    if (storedRecord->mTotalPoints > newRecord->mTotalPoints) {
        return FALSE;
    }
    storedTimeMs = storedRecord->mSecond * 1000 + storedRecord->mMinute * 60000 + storedRecord->mMillisecond;
    newTimeMs = newRecord->mSecond * 1000 + newRecord->mMinute * 60000 + newRecord->mMillisecond;
    return storedTimeMs > newTimeMs;
}

BOOL TrySetGrandPrixRecord(void) {
    TimeRecord storedRecord;
    TimeRecord newRecord;
    BOOL stored = FALSE;
    s32 engineClass;
    Unk0217b488 *p = data_0217b488;
    switch (p->mEngineIndex) {
        case 0:
            engineClass = stored;
            break;
        case 1:
            engineClass = 1;
            break;
        case 2:
            engineClass = (p->mMirrorMode != 0) ? 3 : 2;
            break;
    }
    GetGrandPrixRecord(p->mCupIndex, engineClass, &storedRecord);
    FillGrandPrixRecord(&newRecord);
    if (ShouldSetGrandPrixRecord(&storedRecord, &newRecord) != FALSE) {
        SetGrandPrixRecord(data_0217b488->mCupIndex, engineClass, &newRecord);
        WriteBackupGrandPrixRecords();
        stored = TRUE;
    }
    return stored;
}

u32 TrySetMissionRecord(void) {
    UnpackedMissionRecord storedRecord;
    UnpackedMissionRecord newRecord;
    u32 stored = 0;
    s32 missionRow;
    s32 missionColumn;
    s32 t;
    BOOL shouldStore;
    missionRow = (gRaceSetup->mMode == MODE_MISSION_RUN) ? gRaceSetup->mMissionTableRow : -1;
    missionColumn = (gRaceSetup->mMode == MODE_MISSION_RUN) ? gRaceSetup->mMissionTableColumn : -1;
    t = IsKartEnded((u16) gRaceSetup->mEntryIndex);
    t = (t != 0) ? gRaceProgress->mEntryEndKind : 6;
    if (t != 0) {
        return 0;
    }
    GetMissionRecord((u16) missionRow, (u16) missionColumn, &storedRecord);
    newRecord.mFilled = 1;
    newRecord.mValue = func_0205d140();
    if (storedRecord.mFilled == 0) {
        shouldStore = TRUE;
    } else {
        shouldStore = storedRecord.mValue < newRecord.mValue;
    }
    if (shouldStore != FALSE) {
        SetMissionRecord((u16) missionRow, (u16) missionColumn, &newRecord);
        WriteBackupMissionRecords();
        stored = 1;
    }
    return stored;
}

void func_0203b1fc(void *heap) {
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2) {
        InitBlockEntries(heap, 1);
    }
    RequestMPState16ForNextRace();
}

void func_0203b1c8(void *heap) {
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2) {
        InitBlockEntries(heap, 1);
    }
    RequestMPState18();
}

void func_0203b194(void *heap) {
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2) {
        InitBlockEntries(heap, 1);
    }
    RequestMPState21();
}

void func_0203b0f8(void *heap) {
    void *bannerFile = NULL;
    s32 t;
    u32 f;
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2) {
        InitBlockEntries(heap, 1);
    } else {
        bannerFile = FindSceneFile(data_usa_0216478c);
    }
    t = data_021759d0->mUnk_20;
    f = 1;
    if (t != 1 && t != 2) {
        f = 0;
    }
    if (f != 0) {
        func_0204e928(heap, t == 1, bannerFile);
        InitMPChunkBuffers(heap);
    }
    ResetRaceSetup();
}

BOOL IsDateEarlier(const DateBytes *firstDate, const DateBytes *secondDate) {
    if (firstDate->mYear < secondDate->mYear) {
        return TRUE;
    }
    if (firstDate->mYear > secondDate->mYear) {
        return FALSE;
    }
    if (firstDate->mMonth < secondDate->mMonth) {
        return TRUE;
    }
    if (firstDate->mMonth > secondDate->mMonth) {
        return FALSE;
    }
    return firstDate->mDay < secondDate->mDay;
}
