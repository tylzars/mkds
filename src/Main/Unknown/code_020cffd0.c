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
    u32 cellsPointerAddress;
    u32 value12;
    cellsPointerAddress = (u32) &gRaceHudSubScreenFireball2Cells;
    ClearRaceHudSubScreenCells((RaceHudSubScreenCells **) cellsPointerAddress);
}

void UpdateRaceHudSubScreenFireball2Cells(void) {
    s32 i;
    s32 cellCount;
    BOOL inFirstHalf;
    u32 a;
    Unk0217b498_00 *object;
    Vec3 *position;

    cellCount = 0;
    a = func_020c0db0();
    gRaceHudSubScreenFireball2Cells->mUnk_0c->mUnk_04++;
    if (gRaceHudSubScreenFireball2Cells->mUnk_0c->mUnk_04 < 0 ||
        gRaceHudSubScreenFireball2Cells->mUnk_0c->mUnk_04 >= 0x14) {
        gRaceHudSubScreenFireball2Cells->mUnk_0c->mUnk_04 = 0;
    }
    inFirstHalf = gRaceHudSubScreenFireball2Cells->mUnk_0c->mUnk_04 < 10;
    for (i = 0; i < gRaceHudSubScreenFireball2Cells->mObjectCount; i++) {
        object = gRaceHudSubScreenFireball2Cells->mObjects[i];
        position = &object->mPos;
        if (ComputeRaceHudSubScreenPosition(
                position, (UnkPair020b502c *) &gRaceHudSubScreenFireball2Cells->mCells[cellCount], a, 1, 1) == FALSE) {
            continue;
        }
        gRaceHudSubScreenFireball2Cells->mCells[cellCount].mCell =
            GetRaceSNcerEntry(inFirstHalf != FALSE ? 0xa5 : 0xa6);
        gRaceHudSubScreenFireball2Cells->mCells[cellCount].mUnk_0c = 1;
        gRaceHudSubScreenFireball2Cells->mCells[cellCount].mUnk_0e = 0;
        gRaceHudSubScreenFireball2Cells->mCells[cellCount].mUnk_10 = object->mAngle;
        cellCount++;
    }
    gRaceHudSubScreenFireball2Cells->mCellCount = cellCount;
}

void DrawRaceHudSubScreenFireball2Cells(void *oamBuffer) {
    DrawRaceHudSubScreenCells(oamBuffer, gRaceHudSubScreenFireball2Cells, 1);
}

void InitRaceGoalTimes(void) {
    u16 i;

    gRaceGoalTimes = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0xb0);
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
    s32 cycleStep;

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
    cycleStep = gRaceGoalTimes->mUnk_a8 % 16;
    if (cycleStep < 4) {
        gRaceGoalTimes->mCellIndexAdd = 0;
        return;
    }
    if (cycleStep < 8) {
        gRaceGoalTimes->mCellIndexAdd = 0xd;
        return;
    }
    if (cycleStep < 12) {
        gRaceGoalTimes->mCellIndexAdd = 0x1a;
    } else {
        gRaceGoalTimes->mCellIndexAdd = 0xd;
    }
}

// Draws the finish time and lap times of the goal screen.
void DrawRaceGoalTimes(RaceHudOamBuffer *oamBuffer) {
    Unk020224e0_c *cell;
    s32 positions[4][2];
    s32 slideOffsets[6];
    u16 i;
    s32 updateFrames;
    s32 cellOffset;
    s32 rowY;

    updateFrames = GetRaceGoalMUpdateFrames();
    if (gRaceSetup->mMode != MODE_GRAND_PRIX && gRaceSetup->mMode != MODE_TIME_ATTACK) {
        return;
    }
    if (gRaceSetup->mRaceKind == 4 || gRaceSetup->mRaceKind == RACE_KIND_DEMO) {
        return;
    }
    if (func_020c70bc() != 0) {
        cell = GetRaceGoalMNcerEntry(0x43);
        positions[0][0] = 0x80000;
        positions[0][1] = 0x60000;
        oamBuffer->mOamCount += NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount],
                                                      0x80 - oamBuffer->mOamCount, cell, NULL, positions[0], 0, 1);
    }
    if (updateFrames <= 0) {
        return;
    }
    for (i = 0; i < 6; i++) {
        slideOffsets[i] = InterpolateS16(1, 0x80, 0, updateFrames - i * 4, 0x14);
    }
    cell = GetRaceGoalMNcerEntry((IsRaceNewRecordTaFinishRecord() != 0 ? gRaceGoalTimes->mCellIndexAdd : 0) + 0x15);
    positions[1][0] = (slideOffsets[0] + 0xa2) << 12;
    positions[1][1] = 0x10000;
    oamBuffer->mOamCount += NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount,
                                                  cell, NULL, positions[1], 0, 1);
    DrawRaceGoalTimeDigits(oamBuffer, slideOffsets[0], 0x10, &gRaceGoalTimes->mFinishTime,
                           IsRaceNewRecordTaFinishRecord() != 0 ? gRaceGoalTimes->mCellIndexAdd : 0);
    cell = GetRaceGoalMNcerEntry((IsRaceNewRecordTaBestLapRecord() != 0 ? gRaceGoalTimes->mCellIndexAdd : 0) + 0x16);
    positions[2][0] = (slideOffsets[1] + 0x99) << 12;
    positions[2][1] = 0x28000;
    oamBuffer->mOamCount += NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount,
                                                  cell, NULL, positions[2], 0, 1);
    for (i = 0; i < GetLapCount(); i++) {
        cellOffset = 0;
        if (IsRaceNewRecordTaBestLapRecord() != 0 && i + 1 == GetRaceNewRecordTaBestLapNumber()) {
            cellOffset = gRaceGoalTimes->mCellIndexAdd;
        }
        cell = GetRaceGoalMNcerEntry(i + 0x18 + cellOffset);
        rowY = i * 16 + 0x28;
        positions[3][0] = (slideOffsets[i + 1] + 0x9e) << 12;
        positions[3][1] = rowY << 12;
        oamBuffer->mOamCount += NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount],
                                                      0x80 - oamBuffer->mOamCount, cell, NULL, positions[3], 0, 1);
        DrawRaceGoalTimeDigits(oamBuffer, slideOffsets[i + 1], rowY, &gRaceGoalTimes->mLapTimes[i], cellOffset);
    }
}

// Draws the seven digits of e and the two separators; the first digit is skipped when it is 0.
void DrawRaceGoalTimeDigits(RaceHudOamBuffer *oamBuffer, s32 originX, s32 originY, TimeDigits *digits, s32 cellOffset) {
    Unk020224e0_c *cell;
    s32 digit0Position[2];
    s32 digit1Position[2];
    s32 separator0Position[2];
    s32 digit2Position[2];
    s32 digit3Position[2];
    s32 separator1Position[2];
    s32 digit4Position[2];
    s32 digit5Position[2];
    s32 digit6Position[2];
    s32 columnOffsets[9] = {170, 179, 188, 198, 207, 216, 226, 235, 244};

    if (digits->mUnk_00[0] != 0) {
        cell = GetRaceGoalMNcerEntry(digits->mUnk_00[0] + 0x17 + cellOffset);
        digit0Position[0] = (originX + columnOffsets[0]) << 12;
        digit0Position[1] = originY << 12;
        oamBuffer->mOamCount += NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount],
                                                      0x80 - oamBuffer->mOamCount, cell, NULL, digit0Position, 0, 1);
    }
    cell = GetRaceGoalMNcerEntry(digits->mUnk_00[1] + 0x17 + cellOffset);
    digit1Position[0] = (originX + columnOffsets[1]) << 12;
    digit1Position[1] = originY << 12;
    oamBuffer->mOamCount += NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount,
                                                  cell, NULL, digit1Position, 0, 1);
    cell = GetRaceGoalMNcerEntry(cellOffset + 0x21);
    separator0Position[0] = (originX + columnOffsets[2]) << 12;
    separator0Position[1] = originY << 12;
    oamBuffer->mOamCount += NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount,
                                                  cell, NULL, separator0Position, 0, 1);
    cell = GetRaceGoalMNcerEntry(digits->mUnk_00[2] + 0x17 + cellOffset);
    digit2Position[0] = (originX + columnOffsets[3]) << 12;
    digit2Position[1] = originY << 12;
    oamBuffer->mOamCount += NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount,
                                                  cell, NULL, digit2Position, 0, 1);
    cell = GetRaceGoalMNcerEntry(digits->mUnk_00[3] + 0x17 + cellOffset);
    digit3Position[0] = (originX + columnOffsets[4]) << 12;
    digit3Position[1] = originY << 12;
    oamBuffer->mOamCount += NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount,
                                                  cell, NULL, digit3Position, 0, 1);
    cell = GetRaceGoalMNcerEntry(cellOffset + 0x21);
    separator1Position[0] = (originX + columnOffsets[5]) << 12;
    separator1Position[1] = originY << 12;
    oamBuffer->mOamCount += NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount,
                                                  cell, NULL, separator1Position, 0, 1);
    cell = GetRaceGoalMNcerEntry(digits->mUnk_00[4] + 0x17 + cellOffset);
    digit4Position[0] = (originX + columnOffsets[6]) << 12;
    digit4Position[1] = originY << 12;
    oamBuffer->mOamCount += NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount,
                                                  cell, NULL, digit4Position, 0, 1);
    cell = GetRaceGoalMNcerEntry(digits->mUnk_00[5] + 0x17 + cellOffset);
    digit5Position[0] = (originX + columnOffsets[7]) << 12;
    digit5Position[1] = originY << 12;
    oamBuffer->mOamCount += NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount,
                                                  cell, NULL, digit5Position, 0, 1);
    cell = GetRaceGoalMNcerEntry(digits->mUnk_00[6] + 0x17 + cellOffset);
    digit6Position[0] = (originX + columnOffsets[8]) << 12;
    digit6Position[1] = originY << 12;
    oamBuffer->mOamCount += NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount,
                                                  cell, NULL, digit6Position, 0, 1);
}

s32 CreateRaceHudSubScreenBerryCells(void) {
    return CreateRaceHudSubScreenCells(&gRaceHudSubScreenBerryCells, MAP_OBJECT_KIND_BERRY);
}

void ClearRaceHudSubScreenBerryCells(void) {
    u32 cellsPointerAddress;
    u32 value12;
    cellsPointerAddress = (u32) &gRaceHudSubScreenBerryCells;
    ClearRaceHudSubScreenCells((RaceHudSubScreenCells **) cellsPointerAddress);
}

void UpdateRaceHudSubScreenBerryCells(void) {
    s32 i;
    s32 cellCount;
    u32 a;
    Unk0217b498_00 *object;
    Vec3 *position;

    cellCount = 0;
    a = func_020c0db0();
    for (i = 0; i < gRaceHudSubScreenBerryCells->mObjectCount; i++) {
        object = gRaceHudSubScreenBerryCells->mObjects[i];
        position = &object->mPos;
        if (ComputeRaceHudSubScreenPosition(
                position, (UnkPair020b502c *) &gRaceHudSubScreenBerryCells->mCells[cellCount], a, 1, 1) == FALSE) {
            continue;
        }
        gRaceHudSubScreenBerryCells->mCells[cellCount].mCell = GetRaceSNcerEntry(0xb8);
        gRaceHudSubScreenBerryCells->mCells[cellCount].mUnk_0c = IsPositionOutsideBox(position) != 0 ? 2 : 3;
        gRaceHudSubScreenBerryCells->mCells[cellCount].mUnk_10 = object->mAngle;
        gRaceHudSubScreenBerryCells->mUnk_0c[cellCount].mUnk_00 = object->mScaleX / 6;
        cellCount++;
    }
    gRaceHudSubScreenBerryCells->mCellCount = cellCount;
}

void DrawRaceHudSubScreenBerryCells(void *oamBuffer) {
    DrawRaceHudSubScreenCellsScaled(oamBuffer, gRaceHudSubScreenBerryCells, 1);
}

s32 CreateRaceHudSubScreenCreamCells(void) {
    return CreateRaceHudSubScreenCells(&gRaceHudSubScreenCreamCells, MAP_OBJECT_KIND_CREAM);
}

void ClearRaceHudSubScreenCreamCells(void) {
    u32 cellsPointerAddress;
    u32 value12;
    cellsPointerAddress = (u32) &gRaceHudSubScreenCreamCells;
    ClearRaceHudSubScreenCells((RaceHudSubScreenCells **) cellsPointerAddress);
}

void UpdateRaceHudSubScreenCreamCells(void) {
    s32 i;
    s32 cellCount;
    s32 v;
    Unk0217b498_00 *object;
    Vec3 *position;

    cellCount = 0;
    v = func_020c0db0();
    for (i = 0; i < gRaceHudSubScreenCreamCells->mObjectCount; i++) {
        object = gRaceHudSubScreenCreamCells->mObjects[i];
        position = &object->mPos;
        if (ComputeRaceHudSubScreenPosition(position, &gRaceHudSubScreenCreamCells->mCells[cellCount].mDrawPos, v, 1,
                                            1) != FALSE) {
            gRaceHudSubScreenCreamCells->mCells[cellCount].mCell = GetRaceSNcerEntry(0xb7);
            gRaceHudSubScreenCreamCells->mCells[cellCount].mUnk_0c = IsPositionOutsideBox(position) != 0 ? 2 : 3;
            gRaceHudSubScreenCreamCells->mCells[cellCount].mUnk_10 = object->mAngle;
            gRaceHudSubScreenCreamCells->mUnk_0c[cellCount].mUnk_00 = object->mScaleX / 6;
            cellCount++;
        }
    }
    gRaceHudSubScreenCreamCells->mCellCount = cellCount;
}

void DrawRaceHudSubScreenCreamCells(Unk020c06c4 *oamBuffer) {
    DrawRaceHudSubScreenCellsScaled(oamBuffer, gRaceHudSubScreenCreamCells, 1);
}
