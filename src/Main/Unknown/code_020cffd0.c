#include "Main/Unknown/code_020cffd0.h"
#include "Main/Unknown/code_020ae000.h"

#include "Main/Unknown/code_020c06c4.h"
#include "Main/Unknown/code_020c0b84.h"
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
#include "Main/Unknown/code_020d0108.h"
#include "Main/Unknown/code_020c0ba8.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_02044618.h"
#include "Main/Unknown/code_020ade08.h"
#include "Main/Unknown/code_020c70ec.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_020c5db0.h"
#include "Main/Unknown/code_020c70d8.h"
#include "Main/Unknown/code_02044000.h"
#include "code_020222ec.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_020c7000.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_0203c5f8.h"
#include "Main/Unknown/code_021000d0.h"

void ClearRaceHudSubScreenFireball2Cells(void) {
    u32 value0;
    u32 value12;
    value0 = (u32) &gRaceHudSubScreenFireball2Cells;
    ClearRaceHudSubScreenCells((RaceHudSubScreenCells **) value0);
}

void UpdateRaceHudSubScreenFireball2Cells(void) {
    s32 i;
    s32 n;
    BOOL v;
    u32 a;
    Unk0217b498_00 *e;
    Vec3 *p;

    n = 0;
    a = func_020c0db0();
    gRaceHudSubScreenFireball2Cells->mUnk_0c->mUnk_04++;
    if (gRaceHudSubScreenFireball2Cells->mUnk_0c->mUnk_04 < 0 ||
        gRaceHudSubScreenFireball2Cells->mUnk_0c->mUnk_04 >= 0x14) {
        gRaceHudSubScreenFireball2Cells->mUnk_0c->mUnk_04 = 0;
    }
    v = gRaceHudSubScreenFireball2Cells->mUnk_0c->mUnk_04 < 10;
    for (i = 0; i < gRaceHudSubScreenFireball2Cells->mObjectCount; i++) {
        e = gRaceHudSubScreenFireball2Cells->mObjects[i];
        p = &e->mPos;
        if (ComputeRaceHudSubScreenPosition(p, (UnkPair020b502c *) &gRaceHudSubScreenFireball2Cells->mCells[n], a, 1,
                                            1) == FALSE) {
            continue;
        }
        gRaceHudSubScreenFireball2Cells->mCells[n].mCell = GetRaceSNcerEntry(v != FALSE ? 0xa5 : 0xa6);
        gRaceHudSubScreenFireball2Cells->mCells[n].mUnk_0c = 1;
        gRaceHudSubScreenFireball2Cells->mCells[n].mUnk_0e = 0;
        gRaceHudSubScreenFireball2Cells->mCells[n].mUnk_10 = e->mAngle;
        n++;
    }
    gRaceHudSubScreenFireball2Cells->mCellCount = n;
}

void DrawRaceHudSubScreenFireball2Cells(void *a) {
    DrawRaceHudSubScreenCells(a, gRaceHudSubScreenFireball2Cells, 1);
}

void InitRaceGoalTimes(void) {
    u16 i;

    gRaceGoalTimes = HeapAlloc(GetHeap(func_020364e8()), 0xb0);
    gRaceGoalTimes->mFinishTime.mUnk_00[0] = 0;
    gRaceGoalTimes->mFinishTime.mUnk_00[1] = 0;
    gRaceGoalTimes->mFinishTime.mUnk_00[2] = 0;
    gRaceGoalTimes->mFinishTime.mUnk_00[3] = 0;
    gRaceGoalTimes->mFinishTime.mUnk_00[4] = 0;
    gRaceGoalTimes->mFinishTime.mUnk_00[5] = 0;
    gRaceGoalTimes->mFinishTime.mUnk_00[6] = 0;
    for (i = 0; i < 5; i++) {
        gRaceGoalTimes->mLapTimes[i].mUnk_00[0] = 0;
        gRaceGoalTimes->mLapTimes[i].mUnk_00[1] = 0;
        gRaceGoalTimes->mLapTimes[i].mUnk_00[2] = 0;
        gRaceGoalTimes->mLapTimes[i].mUnk_00[3] = 0;
        gRaceGoalTimes->mLapTimes[i].mUnk_00[4] = 0;
        gRaceGoalTimes->mLapTimes[i].mUnk_00[5] = 0;
        gRaceGoalTimes->mLapTimes[i].mUnk_00[6] = 0;
    }
    gRaceGoalTimes->mUnk_a8 = 0;
    gRaceGoalTimes->mCellIndexAdd = 0;
}

u32 ClearRaceGoalTimesPointer(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &gRaceGoalTimes;
    value1 = 0u;
    *(u32 *) ((value0) + (0)) = value1;
    return value0;
}

void UpdateRaceGoalTimes(void) {
    u8 a;
    u8 b;
    u16 c;
    u16 i;
    s32 v;

    if (gRaceSetup->mMode != MODE_GRAND_PRIX && gRaceSetup->mMode != MODE_TIME_ATTACK) {
        return;
    }
    GetKartFinishTime(GetFollowedKartOrEntryIndex(), &a, &b, &c);
    SplitTimeDigits(a, b, c, &gRaceGoalTimes->mFinishTime);
    for (i = 0; i < GetLapCount(); i++) {
        GetKartLapTime(GetFollowedKartOrEntryIndex(), i + 1, &a, &b, &c);
        SplitTimeDigits(a, b, c, &gRaceGoalTimes->mLapTimes[i]);
    }
    if (gRaceSetup->mMode != MODE_TIME_ATTACK) {
        return;
    }
    if (IsRaceNewRecordTaFinishRecord() == 0 && IsRaceNewRecordTaBestLapRecord() == 0) {
        return;
    }
    gRaceGoalTimes->mUnk_a8++;
    if (gRaceGoalTimes->mUnk_a8 >= 0x10) {
        gRaceGoalTimes->mUnk_a8 = 0;
    }
    v = gRaceGoalTimes->mUnk_a8 % 16;
    if (v < 4) {
        gRaceGoalTimes->mCellIndexAdd = 0;
        return;
    }
    if (v < 8) {
        gRaceGoalTimes->mCellIndexAdd = 0xd;
        return;
    }
    if (v < 12) {
        gRaceGoalTimes->mCellIndexAdd = 0x1a;
    } else {
        gRaceGoalTimes->mCellIndexAdd = 0xd;
    }
}

// Draws the finish time and lap times of the goal screen.
void DrawRaceGoalTimes(RaceHudOamBuffer *a) {
    Unk020224e0_c *c;
    s32 q[4][2];
    s32 t[6];
    u16 i;
    s32 n;
    s32 j;
    s32 k;

    n = GetRaceGoalMUpdateFrames();
    if (gRaceSetup->mMode != MODE_GRAND_PRIX && gRaceSetup->mMode != MODE_TIME_ATTACK) {
        return;
    }
    if (gRaceSetup->mRaceKind == 4 || gRaceSetup->mRaceKind == RACE_KIND_DEMO) {
        return;
    }
    if (func_020c70bc() != 0) {
        c = GetRaceGoalMNcerEntry(0x43);
        q[0][0] = 0x80000;
        q[0][1] = 0x60000;
        a->mOamCount += NNS_G2dMakeCellToOams(&a->mOams[a->mOamCount], 0x80 - a->mOamCount, c, NULL, q[0], 0, 1);
    }
    if (n <= 0) {
        return;
    }
    for (i = 0; i < 6; i++) {
        t[i] = InterpolateS16(1, 0x80, 0, n - i * 4, 0x14);
    }
    c = GetRaceGoalMNcerEntry((IsRaceNewRecordTaFinishRecord() != 0 ? gRaceGoalTimes->mCellIndexAdd : 0) + 0x15);
    q[1][0] = (t[0] + 0xa2) << 12;
    q[1][1] = 0x10000;
    a->mOamCount += NNS_G2dMakeCellToOams(&a->mOams[a->mOamCount], 0x80 - a->mOamCount, c, NULL, q[1], 0, 1);
    DrawRaceGoalTimeDigits(a, t[0], 0x10, &gRaceGoalTimes->mFinishTime,
                           IsRaceNewRecordTaFinishRecord() != 0 ? gRaceGoalTimes->mCellIndexAdd : 0);
    c = GetRaceGoalMNcerEntry((IsRaceNewRecordTaBestLapRecord() != 0 ? gRaceGoalTimes->mCellIndexAdd : 0) + 0x16);
    q[2][0] = (t[1] + 0x99) << 12;
    q[2][1] = 0x28000;
    a->mOamCount += NNS_G2dMakeCellToOams(&a->mOams[a->mOamCount], 0x80 - a->mOamCount, c, NULL, q[2], 0, 1);
    for (i = 0; i < GetLapCount(); i++) {
        j = 0;
        if (IsRaceNewRecordTaBestLapRecord() != 0 && i + 1 == GetRaceNewRecordTaBestLapNumber()) {
            j = gRaceGoalTimes->mCellIndexAdd;
        }
        c = GetRaceGoalMNcerEntry(i + 0x18 + j);
        k = i * 16 + 0x28;
        q[3][0] = (t[i + 1] + 0x9e) << 12;
        q[3][1] = k << 12;
        a->mOamCount += NNS_G2dMakeCellToOams(&a->mOams[a->mOamCount], 0x80 - a->mOamCount, c, NULL, q[3], 0, 1);
        DrawRaceGoalTimeDigits(a, t[i + 1], k, &gRaceGoalTimes->mLapTimes[i], j);
    }
}

// Draws the seven digits of e and the two separators; the first digit is skipped when it is 0.
void DrawRaceGoalTimeDigits(RaceHudOamBuffer *a, s32 b, s32 d, TimeDigits *e, s32 f) {
    Unk020224e0_c *c;
    s32 p0[2];
    s32 p1[2];
    s32 p2[2];
    s32 p3[2];
    s32 p4[2];
    s32 p5[2];
    s32 p6[2];
    s32 p7[2];
    s32 p8[2];
    s32 t[9] = {170, 179, 188, 198, 207, 216, 226, 235, 244};

    if (e->mUnk_00[0] != 0) {
        c = GetRaceGoalMNcerEntry(e->mUnk_00[0] + 0x17 + f);
        p0[0] = (b + t[0]) << 12;
        p0[1] = d << 12;
        a->mOamCount += NNS_G2dMakeCellToOams(&a->mOams[a->mOamCount], 0x80 - a->mOamCount, c, NULL, p0, 0, 1);
    }
    c = GetRaceGoalMNcerEntry(e->mUnk_00[1] + 0x17 + f);
    p1[0] = (b + t[1]) << 12;
    p1[1] = d << 12;
    a->mOamCount += NNS_G2dMakeCellToOams(&a->mOams[a->mOamCount], 0x80 - a->mOamCount, c, NULL, p1, 0, 1);
    c = GetRaceGoalMNcerEntry(f + 0x21);
    p2[0] = (b + t[2]) << 12;
    p2[1] = d << 12;
    a->mOamCount += NNS_G2dMakeCellToOams(&a->mOams[a->mOamCount], 0x80 - a->mOamCount, c, NULL, p2, 0, 1);
    c = GetRaceGoalMNcerEntry(e->mUnk_00[2] + 0x17 + f);
    p3[0] = (b + t[3]) << 12;
    p3[1] = d << 12;
    a->mOamCount += NNS_G2dMakeCellToOams(&a->mOams[a->mOamCount], 0x80 - a->mOamCount, c, NULL, p3, 0, 1);
    c = GetRaceGoalMNcerEntry(e->mUnk_00[3] + 0x17 + f);
    p4[0] = (b + t[4]) << 12;
    p4[1] = d << 12;
    a->mOamCount += NNS_G2dMakeCellToOams(&a->mOams[a->mOamCount], 0x80 - a->mOamCount, c, NULL, p4, 0, 1);
    c = GetRaceGoalMNcerEntry(f + 0x21);
    p5[0] = (b + t[5]) << 12;
    p5[1] = d << 12;
    a->mOamCount += NNS_G2dMakeCellToOams(&a->mOams[a->mOamCount], 0x80 - a->mOamCount, c, NULL, p5, 0, 1);
    c = GetRaceGoalMNcerEntry(e->mUnk_00[4] + 0x17 + f);
    p6[0] = (b + t[6]) << 12;
    p6[1] = d << 12;
    a->mOamCount += NNS_G2dMakeCellToOams(&a->mOams[a->mOamCount], 0x80 - a->mOamCount, c, NULL, p6, 0, 1);
    c = GetRaceGoalMNcerEntry(e->mUnk_00[5] + 0x17 + f);
    p7[0] = (b + t[7]) << 12;
    p7[1] = d << 12;
    a->mOamCount += NNS_G2dMakeCellToOams(&a->mOams[a->mOamCount], 0x80 - a->mOamCount, c, NULL, p7, 0, 1);
    c = GetRaceGoalMNcerEntry(e->mUnk_00[6] + 0x17 + f);
    p8[0] = (b + t[8]) << 12;
    p8[1] = d << 12;
    a->mOamCount += NNS_G2dMakeCellToOams(&a->mOams[a->mOamCount], 0x80 - a->mOamCount, c, NULL, p8, 0, 1);
}

s32 CreateRaceHudSubScreenBerryCells(void) {
    return CreateRaceHudSubScreenCells(&gRaceHudSubScreenBerryCells, MAP_OBJECT_KIND_BERRY);
}

void ClearRaceHudSubScreenBerryCells(void) {
    u32 value0;
    u32 value12;
    value0 = (u32) &gRaceHudSubScreenBerryCells;
    ClearRaceHudSubScreenCells((RaceHudSubScreenCells **) value0);
}

void UpdateRaceHudSubScreenBerryCells(void) {
    s32 i;
    s32 n;
    u32 a;
    Unk0217b498_00 *e;
    Vec3 *p;

    n = 0;
    a = func_020c0db0();
    for (i = 0; i < gRaceHudSubScreenBerryCells->mObjectCount; i++) {
        e = gRaceHudSubScreenBerryCells->mObjects[i];
        p = &e->mPos;
        if (ComputeRaceHudSubScreenPosition(p, (UnkPair020b502c *) &gRaceHudSubScreenBerryCells->mCells[n], a, 1, 1) ==
            FALSE) {
            continue;
        }
        gRaceHudSubScreenBerryCells->mCells[n].mCell = GetRaceSNcerEntry(0xb8);
        gRaceHudSubScreenBerryCells->mCells[n].mUnk_0c = func_020b4e70(p) != 0 ? 2 : 3;
        gRaceHudSubScreenBerryCells->mCells[n].mUnk_10 = e->mAngle;
        gRaceHudSubScreenBerryCells->mUnk_0c[n].mUnk_00 = e->mScaleX / 6;
        n++;
    }
    gRaceHudSubScreenBerryCells->mCellCount = n;
}

void DrawRaceHudSubScreenBerryCells(void *a) {
    DrawRaceHudSubScreenCellsScaled(a, gRaceHudSubScreenBerryCells, 1);
}

s32 CreateRaceHudSubScreenCreamCells(void) {
    return CreateRaceHudSubScreenCells(&gRaceHudSubScreenCreamCells, MAP_OBJECT_KIND_CREAM);
}

void ClearRaceHudSubScreenCreamCells(void) {
    u32 value0;
    u32 value12;
    value0 = (u32) &gRaceHudSubScreenCreamCells;
    ClearRaceHudSubScreenCells((RaceHudSubScreenCells **) value0);
}

void UpdateRaceHudSubScreenCreamCells(void) {
    s32 i;
    s32 n;
    s32 v;
    Unk0217b498_00 *e;
    Vec3 *p;

    n = 0;
    v = func_020c0db0();
    for (i = 0; i < gRaceHudSubScreenCreamCells->mObjectCount; i++) {
        e = gRaceHudSubScreenCreamCells->mObjects[i];
        p = &e->mPos;
        if (ComputeRaceHudSubScreenPosition(p, &gRaceHudSubScreenCreamCells->mCells[n].mDrawPos, v, 1, 1) != FALSE) {
            gRaceHudSubScreenCreamCells->mCells[n].mCell = GetRaceSNcerEntry(0xb7);
            gRaceHudSubScreenCreamCells->mCells[n].mUnk_0c = func_020b4e70(p) != 0 ? 2 : 3;
            gRaceHudSubScreenCreamCells->mCells[n].mUnk_10 = e->mAngle;
            gRaceHudSubScreenCreamCells->mUnk_0c[n].mUnk_00 = e->mScaleX / 6;
            n++;
        }
    }
    gRaceHudSubScreenCreamCells->mCellCount = n;
}

void DrawRaceHudSubScreenCreamCells(Unk020c06c4 *a) {
    DrawRaceHudSubScreenCellsScaled(a, gRaceHudSubScreenCreamCells, 1);
}
