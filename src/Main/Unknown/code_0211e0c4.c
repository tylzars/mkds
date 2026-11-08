#include "Main/Unknown/code_0211e0c4.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020435c4.h"
#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_02060cb4.h"
#include "Main/Unknown/code_02061428.h"
#include "Main/Unknown/code_02061540.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_02090354.h"

#include "Main/Unknown/code_02043000.h"
#include "Main/Unknown/code_02044000.h"
#include "Main/Unknown/code_02061000.h"
#include "Main/Unknown/code_02090000.h"
#include "01/code_021956dc.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Unknown/code_02061418.h"
#include "Main/Unknown/code_0206152c.h"
#include "Main/Unknown/code_02061644.h"
#include "Main/Unknown/code_02060000.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "code_0214cfe4.h"
#include "code_0214d018.h"

#pragma thumb on

void InitGhostRecordSet(void *heap) {
    gGhostRecordSet = HeapAlloc(heap, 0x14);
    gGhostRecordSet->mCourseGhostRecords = (u8 *) CreateCourseGhostRecords((u32) heap);
    StartReadCourseGhostRecords(gGhostRecordSet->mCourseGhostRecords);
    WaitThreadFunctionsDone();
    gGhostRecordSet->mSlotGhostRecords = (u8 *) CreateSlotGhostRecords((u32) heap);
    StartReadSlotGhostRecords(gGhostRecordSet->mSlotGhostRecords);
    WaitThreadFunctionsDone();
    gGhostRecordSet->mGhostFileRecords = (u8 *) CreateGhostFileRecords((u32) heap);
    StartReadGhostFileRecords(gGhostRecordSet->mGhostFileRecords);
    WaitThreadFunctionsDone();
    LoadStaffGhostTime(heap);
}

void ClearGhostRecordSetPointer(void) {
    gGhostRecordSet = NULL;
}

void SetupGhostRecordSetForCourse(u32 courseId) {
    s32 i;

    gGhostRecordSet->mCourseId = courseId;
    gGhostRecordSet->mSlotIndex = -1;
    for (i = 0; i < 0xa; i++) {
        if (IsGhostRecordFilled(gGhostRecordSet->mSlotGhostRecords + (u8) i * 0x230) != FALSE &&
            GetGhostRecordCourseId(gGhostRecordSet->mSlotGhostRecords + (u8) i * 0x230) == courseId) {
            gGhostRecordSet->mSlotIndex = i;
            return;
        }
    }
}

void GetGhostRecordSetTime(u32 kind, void *time) {
    u8 *records;

    switch (kind) {
        case 0:
            records = gGhostRecordSet->mCourseGhostRecords;
            GetGhostRecordTime(records + FindCupCourseIndex(gGhostRecordSet->mCourseId) * 0x30, time);
            break;
        case 1:
            GetGhostRecordTime(gGhostRecordSet->mSlotGhostRecords + (u8) gGhostRecordSet->mSlotIndex * 0x230, time);
            break;
        case 2:
            records = gGhostRecordSet->mGhostFileRecords;
            GetGhostRecordTime(records + FindCupCourseIndex(gGhostRecordSet->mCourseId) * 0x230, time);
            break;
        case 4:
            break;
    }
}

void GetGhostRecordSetName(u32 kind, void *name) {
    u8 *records;
    u8 ghostName[0x14];

    switch (kind) {
        case 0:
            records = gGhostRecordSet->mCourseGhostRecords;
            GetGhostRecordName(records + FindCupCourseIndex(gGhostRecordSet->mCourseId) * 0x30, ghostName);
            break;
        case 1:
            GetGhostRecordName(gGhostRecordSet->mSlotGhostRecords + (u8) gGhostRecordSet->mSlotIndex * 0x230,
                               ghostName);
            break;
        case 2:
            records = gGhostRecordSet->mGhostFileRecords;
            GetGhostRecordName(records + FindCupCourseIndex(gGhostRecordSet->mCourseId) * 0x230, ghostName);
            break;
        case 4:
            break;
    }
    MI_CpuFill8(name, 0, 0x20);
    MIi_CpuCopy16(ghostName, name, 0x14);
}

s32 GetGhostRecordSetCharacterIndex(u32 kind) {
    u8 *records;
    s32 characterIndex = -1;

    switch (kind) {
        case 4:
            characterIndex = -1;
            break;
        case 0:
            records = gGhostRecordSet->mCourseGhostRecords;
            characterIndex =
                GetGhostRecordCharacterIndex(records + FindCupCourseIndex(gGhostRecordSet->mCourseId) * 0x30);
            break;
        case 1:
            characterIndex = GetGhostRecordCharacterIndex(gGhostRecordSet->mSlotGhostRecords +
                                                          (u8) gGhostRecordSet->mSlotIndex * 0x230);
            break;
        case 2:
            records = gGhostRecordSet->mGhostFileRecords;
            characterIndex =
                GetGhostRecordCharacterIndex(records + FindCupCourseIndex(gGhostRecordSet->mCourseId) * 0x230);
            break;
    }
    return characterIndex;
}

s32 GetGhostRecordSetKartIndex(u32 kind) {
    u8 *records;
    s32 kartIndex = -1;

    switch (kind) {
        case 4:
            kartIndex = -1;
            break;
        case 0:
            records = gGhostRecordSet->mCourseGhostRecords;
            kartIndex = GetGhostRecordKartIndex(records + FindCupCourseIndex(gGhostRecordSet->mCourseId) * 0x30);
            break;
        case 1:
            kartIndex =
                GetGhostRecordKartIndex(gGhostRecordSet->mSlotGhostRecords + (u8) gGhostRecordSet->mSlotIndex * 0x230);
            break;
        case 2:
            records = gGhostRecordSet->mGhostFileRecords;
            kartIndex = GetGhostRecordKartIndex(records + FindCupCourseIndex(gGhostRecordSet->mCourseId) * 0x230);
            break;
    }
    return kartIndex;
}

s32 func_0211e160(u32 kind) {
    s32 result = 0;
    u8 *records;

    switch (kind) {
        case 4:
            result = 1;
            break;
        case 0:
            records = gGhostRecordSet->mCourseGhostRecords;
            result = IsGhostRecordFilled(records + FindCupCourseIndex(gGhostRecordSet->mCourseId) * 0x30);
            break;
        case 1:
            if (gGhostRecordSet->mSlotIndex != -1) {
                result = 1;
            }
            break;
        case 2:
            if (IsTimeRecordFilled(gGhostRecordSet->mCourseId, 0) != FALSE) {
                u32 time;

                GetTimeRecordTime(gGhostRecordSet->mCourseId, 0, &time);
                result = IsTimeLessThanStaffGhostTime(gGhostRecordSet->mCourseId, &time);
            } else {
                result = 0;
            }
            break;
    }
    return result;
}

BOOL func_0211e130(void) {
    u32 a = 0;

    a |= func_0211e160(a);
    a |= func_0211e160(1);
    a |= func_0211e160(2);
    if (a == 0) {
        return TRUE;
    }
    return FALSE;
}

void func_0211e0c4(u32 kind) {
    switch (kind) {
        case 4:
            func_02043fb0(gGhostRecordSet->mCourseId);
            break;
        case 0:
            func_020442d0(gGhostRecordSet->mCourseId);
            break;
        case 1:
            func_0204419c(gGhostRecordSet->mCourseId, (u8) gGhostRecordSet->mSlotIndex);
            break;
        case 2:
            func_02044060(gGhostRecordSet->mCourseId);
            break;
    }
}

#pragma thumb off
