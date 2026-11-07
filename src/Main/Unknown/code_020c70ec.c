#include "Main/Unknown/code_020c70ec.h"
#include "Main/Unknown/code_020c06c4.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020b837c.h"
#include "Main/Unknown/code_020c0000.h"
#include "Main/Unknown/code_020c0d9c.h"
#include "Main/Unknown/code_0203c5f8.h"

void UpdateRaceHudSubScreenItemBoxCells(void) {
    s32 i;
    s32 k;
    s32 n;
    s32 c;
    Unk0217b498_00 *p;
    Vec3 *v;

    n = 0;
    c = func_020c0db0();
    k = 0;
    for (i = 0; i < gRaceHudSubScreenItemBoxCells->mObjectCount; i++) {
        if (data_0217b3f8 == 0 ||
            IsRaceHudSubScreenPairNearCenter(&gRaceHudSubScreenItemBoxCells->mUnk_0c[i]) != FALSE) {
            p = gRaceHudSubScreenItemBoxCells->mObjects[i];
            if ((p->mFlags & 1) == 0) {
                v = &p->mPos;
                if (ComputeRaceHudSubScreenPosition(v, &gRaceHudSubScreenItemBoxCells->mCells[k].mDrawPos, c, 0, 0) !=
                    FALSE) {
                    gRaceHudSubScreenItemBoxCells->mCells[k].mCell = GetRaceSNcerEntry(0x4e);
                    gRaceHudSubScreenItemBoxCells->mCells[k].mUnk_0c = func_020b4e70(v) != 0 ? 2 : 3;
                    gRaceHudSubScreenItemBoxCells->mCells[k].mUnk_0e = p->mFlags & 0x20;
                    n++;
                    k++;
                }
            }
        }
    }
    gRaceHudSubScreenItemBoxCells->mCellCount = n;
}

void DrawRaceHudSubScreenItemBoxCells(Unk020c06c4 *a) {
    DrawRaceHudSubScreenCells(a, gRaceHudSubScreenItemBoxCells, 0);
}

void RefreshRaceNewRecordTaRecordFlags(void) {
    u8 minute;
    u8 second;
    u16 millisecond;
    u8 bestMinute;
    u8 bestSecond;
    u16 bestMillisecond;
    s32 j;
    s32 finishMs;
    TimeRecord *record;
    TimeRecord *records;

    if (gRaceSetup->mMode != MODE_TIME_ATTACK) {
        return;
    }
    if (gRaceNewRecordTa == NULL) {
        return;
    }
    if (gRaceSetup->mRaceKind == RACE_KIND_NORMAL) {
        gRaceNewRecordTa->mFinishTimeIsRecord = func_020c657c(0);
        gRaceNewRecordTa->mBestLapIsRecord = func_020c6428(0);
        return;
    }
    GetKartFinishTime(GetFollowedKartOrEntryIndex(), &minute, &second, &millisecond);
    records = gRaceNewRecordTa->mRecords;
    finishMs = second * 1000 + minute * 60000 + millisecond;
    for (j = 4; j >= 0; j--) {
        record = &records[j];
        if (record->mFilled != 0 &&
            finishMs == record->mMillisecond + (record->mSecond * 1000 + record->mMinute * 60000)) {
            j = 1;
            goto found;
        }
    }
    j = 0;
found:
    gRaceNewRecordTa->mFinishTimeIsRecord = j;
    record = &gRaceNewRecordTa->mRecords[TIME_RECORD_BEST_LAP];
    gRaceNewRecordTa->mBestLapNumber =
        GetKartBestLapTime(GetFollowedKartOrEntryIndex(), &bestMinute, &bestSecond, &bestMillisecond);
    gRaceNewRecordTa->mBestLapIsRecord =
        (bestMinute == record->mMinute && bestSecond == record->mSecond && bestMillisecond == record->mMillisecond) ? 1
                                                                                                                    : 0;
}

s32 IsRaceNewRecordTaFinishRecord(void) {
    return gRaceNewRecordTa != NULL ? gRaceNewRecordTa->mFinishTimeIsRecord : 0;
}

BOOL IsRaceNewRecordTaFinishRecordFirst(void) {
    if (gRaceNewRecordTa != NULL) {
        if (gRaceNewRecordTa->mFinishTimeIsRecord != 0) {
            if (gRaceNewRecordTa->mFinishRecordIndex == 0) {
                return TRUE;
            }
        }
        return FALSE;
    }
    return FALSE;
}

s32 IsRaceNewRecordTaBestLapRecord(void) {
    return gRaceNewRecordTa != NULL ? gRaceNewRecordTa->mBestLapIsRecord : 0;
}
