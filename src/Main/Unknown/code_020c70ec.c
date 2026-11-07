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

void func_020c7164(void) {
    u8 a;
    u8 b;
    u16 c;
    u8 d;
    u8 e;
    u16 f;
    s32 j;
    s32 t;
    TimeRecord *q;
    TimeRecord *r;

    if (gRaceSetup->mMode != MODE_TIME_ATTACK) {
        return;
    }
    if (gRaceNewRecordTa == NULL) {
        return;
    }
    if (gRaceSetup->mRaceKind == RACE_KIND_NORMAL) {
        gRaceNewRecordTa->mUnk_08 = func_020c657c(0);
        gRaceNewRecordTa->mUnk_10 = func_020c6428(0);
        return;
    }
    GetKartFinishTime(GetFollowedKartOrEntryIndex(), &a, &b, &c);
    r = gRaceNewRecordTa->mRecords;
    t = b * 1000 + a * 60000 + c;
    for (j = 4; j >= 0; j--) {
        q = &r[j];
        if (q->mFilled != 0 && t == q->mMillisecond + (q->mSecond * 1000 + q->mMinute * 60000)) {
            j = 1;
            goto found;
        }
    }
    j = 0;
found:
    gRaceNewRecordTa->mUnk_08 = j;
    q = &gRaceNewRecordTa->mRecords[TIME_RECORD_BEST_LAP];
    gRaceNewRecordTa->mUnk_14 = GetKartBestLapTime(GetFollowedKartOrEntryIndex(), &d, &e, &f);
    gRaceNewRecordTa->mUnk_10 = (d == q->mMinute && e == q->mSecond && f == q->mMillisecond) ? 1 : 0;
}

s32 func_020c7148(void) {
    return gRaceNewRecordTa != NULL ? gRaceNewRecordTa->mUnk_08 : 0;
}

BOOL func_020c7108(void) {
    if (gRaceNewRecordTa != NULL) {
        if (gRaceNewRecordTa->mUnk_08 != 0) {
            if (gRaceNewRecordTa->mUnk_0c == 0) {
                return TRUE;
            }
        }
        return FALSE;
    }
    return FALSE;
}

s32 func_020c70ec(void) {
    return gRaceNewRecordTa != NULL ? gRaceNewRecordTa->mUnk_10 : 0;
}
