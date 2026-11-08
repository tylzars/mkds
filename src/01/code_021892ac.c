#include "01/code_021892ac.h"

#include "01/code_02188e88.h"
#include "01/code_02188950.h"
#include "01/code_021857a4.h"
#include "01/code_0218c790.h"
#include "01/unk_021a9000.h"
#include "Main/Unknown/code_021000d0.h"
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
#include "Main/Unknown/code_020c06c4.h"
#include "Main/Unknown/code_020c0b84.h"
#include "Main/Unknown/code_020c0ba8.h"
#include "Main/Unknown/code_020c0d9c.h"
#include "01/code_0218c000.h"
#include "Main/Unknown/code_020a3000.h"
#include "01/code_0218b298.h"
#include "01/code_0218f900.h"
#include "01/unk_021a6000.h"
#include "Main/Unknown/code_0209bef0.h"
#include "Main/Unknown/code_020b47b4.h"
#include "Main/Unknown/code_020b85f0.h"
#include "Main/Unknown/code_020b8624.h"
#include "00/code_02181f98.h"
#include "code_0200eddc.h"

RaceHudSubScreenCells *gRaceHudSubScreenIwanteCells;

#pragma thumb off

s32 CreateRaceHudSubScreenIwanteCells(void) {
    return CreateRaceHudSubScreenCells(&gRaceHudSubScreenIwanteCells, MAP_OBJECT_KIND_IWANTE);
}

void ClearRaceHudSubScreenIwanteCells(void) {
    ClearRaceHudSubScreenCells(&gRaceHudSubScreenIwanteCells);
}

void UpdateRaceHudSubScreenIwanteCells(void) {
    u32 var;
    s32 i;
    s32 cellCount = 0;
    u32 entryIndex;
    Unk0217b498_00 *object;
    Vec3 *position;

    var = func_020c0db0();
    for (i = 0; i < gRaceHudSubScreenIwanteCells->mObjectCount; i++) {
        object = gRaceHudSubScreenIwanteCells->mObjects[i];
        if (!(object->mFlags & 1)) {
            position = &object->mPos;
            if (ComputeRaceHudSubScreenPosition(position, &gRaceHudSubScreenIwanteCells->mCells[cellCount].mDrawPos,
                                                var, 1, 1)) {
                if (func_ov001_0218f9c0((Unk02188950 *) object)) {
                    entryIndex = (object->mFlags & 0x400) ? 0xc8 : 0xc6;
                } else {
                    entryIndex = (object->mFlags & 0x400) ? 0xc7 : 0xc5;
                }
                gRaceHudSubScreenIwanteCells->mCells[cellCount].mCell = GetRaceSNcerEntry(entryIndex);
                gRaceHudSubScreenIwanteCells->mCells[cellCount].mUnk_0c = IsPositionOutsideBox(position) ? 2 : 3;
                gRaceHudSubScreenIwanteCells->mCells[cellCount].mUnk_0e = object->mFlags & 0x20;
                gRaceHudSubScreenIwanteCells->mCells[cellCount].mUnk_10 = object->mAngle;
                cellCount++;
            }
        }
    }
    gRaceHudSubScreenIwanteCells->mCellCount = cellCount;
}

void DrawRaceHudSubScreenIwanteCells(void *oamBuffer) {
    DrawRaceHudSubScreenCells(oamBuffer, gRaceHudSubScreenIwanteCells, 0);
}

s32 CreateRaceHudSubScreenKurikingCells(void) {
    return CreateRaceHudSubScreenCells(&gRaceHudSubScreenKurikingCells, MAP_OBJECT_KIND_KURIKING);
}

void ClearRaceHudSubScreenKurikingCells(void) {
    ClearRaceHudSubScreenCells(&gRaceHudSubScreenKurikingCells);
}

// Also copies one row of the race_transfer_map_mr_s_o palette into the race palette for each object.
void UpdateRaceHudSubScreenKurikingCells(void) {
    u32 var;
    s32 i;
    s32 cellCount = 0;
    s32 row;
    s32 k;
    Unk0217b498_00 *object;
    u16 *racePalette;
    Nclr *nclr;
    Vec3 *position;

    var = func_020c0db0();
    for (i = 0; i < gRaceHudSubScreenKurikingCells->mObjectCount; i++) {
        object = gRaceHudSubScreenKurikingCells->mObjects[i];
        if (!(object->mFlags & 1)) {
            position = &object->mPos;
            if (ComputeRaceHudSubScreenPosition(position, &gRaceHudSubScreenKurikingCells->mCells[cellCount].mDrawPos,
                                                var, 1, 1)) {
                row = func_ov001_0218b2d4((Unk02188950 *) object);
                racePalette = GetRaceNclrNcgr(6)->mNclr->mData;
                nclr = NULL;
                LocateNclr((&nclr), (FindSceneFileWrapper("race_transfer_map_mr_s_o.NCLR")));
                for (k = 0; k < 16; k++) {
                    racePalette[0x50 + k] = nclr->mData[(row + 2) * 16 + k];
                }
                DC_FlushRange(GetRaceNclrNcgr(6)->mNclr->mData, GetRaceNclrNcgr(6)->mNclr->mDataSize);
                gRaceHudSubScreenKurikingCells->mCells[cellCount].mCell = GetRaceSNcerEntry(0xc5);
                gRaceHudSubScreenKurikingCells->mCells[cellCount].mUnk_0c = IsPositionOutsideBox(position) ? 2 : 3;
                gRaceHudSubScreenKurikingCells->mCells[cellCount].mUnk_0e = object->mFlags & 0x20;
                gRaceHudSubScreenKurikingCells->mCells[cellCount].mUnk_10 = object->mAngle;
                cellCount++;
            }
        }
    }
    gRaceHudSubScreenKurikingCells->mCellCount = cellCount;
}

#pragma thumb on

RaceHudSubScreenCells *gRaceHudSubScreenHanachanCells;
RaceHudSubScreenCells *gRaceHudSubScreenMissionGateCells;
RaceHudSubScreenCells *gRaceHudSubScreenStopSignCells;
RaceHudSubScreenCells *gRaceHudSubScreenBossDonketuCells;
RaceHudSubScreenCells *gRaceHudSubScreenBombKingCells;
RaceHudSubScreenCells *gRaceHudSubScreenKurikingCells;

#pragma thumb off

void DrawRaceHudSubScreenKurikingCells(void *oamBuffer) {
    DrawRaceHudSubScreenCells(oamBuffer, gRaceHudSubScreenKurikingCells, 0);
}

s32 CreateRaceHudSubScreenBombKingCells(void) {
    return CreateRaceHudSubScreenCells(&gRaceHudSubScreenBombKingCells, MAP_OBJECT_KIND_BOMB_KING);
}

void ClearRaceHudSubScreenBombKingCells(void) {
    ClearRaceHudSubScreenCells(&gRaceHudSubScreenBombKingCells);
}

void UpdateRaceHudSubScreenBombKingCells(void) {
    s32 i;
    s32 cellCount;
    u32 unk;
    Unk0217b498_00 *object;
    Vec3 *position;

    cellCount = 0;
    unk = func_020c0db0();
    for (i = 0; i < gRaceHudSubScreenBombKingCells->mObjectCount; i++) {
        object = gRaceHudSubScreenBombKingCells->mObjects[i];
        if (object->mFlags & 1) {
            continue;
        }
        position = &object->mPos;
        if (ComputeRaceHudSubScreenPosition(position, &gRaceHudSubScreenBombKingCells->mCells[cellCount].mDrawPos, unk,
                                            1, 1)) {
            gRaceHudSubScreenBombKingCells->mCells[cellCount].mCell = GetRaceSNcerEntry(0xc5);
            gRaceHudSubScreenBombKingCells->mCells[cellCount].mUnk_0c = IsPositionOutsideBox(position) ? 2 : 3;
            gRaceHudSubScreenBombKingCells->mCells[cellCount].mUnk_0e = object->mFlags & 0x20;
            gRaceHudSubScreenBombKingCells->mCells[cellCount].mUnk_10 = object->mAngle;
            cellCount++;
        }
    }
    gRaceHudSubScreenBombKingCells->mCellCount = cellCount;
}

void DrawRaceHudSubScreenBombKingCells(void *oamBuffer) {
    DrawRaceHudSubScreenCells(oamBuffer, gRaceHudSubScreenBombKingCells, 0);
}

s32 CreateRaceHudSubScreenBossDonketuCells(void) {
    return CreateRaceHudSubScreenCells(&gRaceHudSubScreenBossDonketuCells, MAP_OBJECT_KIND_BOSS_DONKETU);
}

void ClearRaceHudSubScreenBossDonketuCells(void) {
    ClearRaceHudSubScreenCells(&gRaceHudSubScreenBossDonketuCells);
}

void UpdateRaceHudSubScreenBossDonketuCells(void) {
    s32 i;
    s32 cellCount;
    u32 unk;
    Unk0217b498_00 *object;
    Vec3 *position;

    cellCount = 0;
    unk = func_020c0db0();
    for (i = 0; i < gRaceHudSubScreenBossDonketuCells->mObjectCount; i++) {
        object = gRaceHudSubScreenBossDonketuCells->mObjects[i];
        if (object->mFlags & 1) {
            continue;
        }
        position = &object->mPos;
        if (ComputeRaceHudSubScreenPosition(position, &gRaceHudSubScreenBossDonketuCells->mCells[cellCount].mDrawPos,
                                            unk, 1, 1)) {
            gRaceHudSubScreenBossDonketuCells->mCells[cellCount].mCell = GetRaceSNcerEntry(0xc5);
            gRaceHudSubScreenBossDonketuCells->mCells[cellCount].mUnk_0c = IsPositionOutsideBox(position) ? 2 : 3;
            gRaceHudSubScreenBossDonketuCells->mCells[cellCount].mUnk_0e = object->mFlags & 0x20;
            gRaceHudSubScreenBossDonketuCells->mCells[cellCount].mUnk_10 = object->mAngle;
            cellCount++;
        }
    }
    gRaceHudSubScreenBossDonketuCells->mCellCount = cellCount;
}

void DrawRaceHudSubScreenBossDonketuCells(void *oamBuffer) {
    DrawRaceHudSubScreenCells(oamBuffer, gRaceHudSubScreenBossDonketuCells, 0);
}

s32 CreateRaceHudSubScreenStopSignCells(void) {
    return CreateRaceHudSubScreenCells(&gRaceHudSubScreenStopSignCells, MAP_OBJECT_KIND_STOP_SIGN);
}

void ClearRaceHudSubScreenStopSignCells(void) {
    ClearRaceHudSubScreenCells(&gRaceHudSubScreenStopSignCells);
}

void UpdateRaceHudSubScreenStopSignCells(void) {
    s32 i;
    s32 cellCount;
    u32 unk;
    Unk0217b498_00 *object;
    Vec3 *position;

    cellCount = 0;
    unk = func_020c0db0();
    for (i = 0; i < gRaceHudSubScreenStopSignCells->mObjectCount; i++) {
        object = gRaceHudSubScreenStopSignCells->mObjects[i];
        position = &object->mPos;
        if (ComputeRaceHudSubScreenPosition(position, &gRaceHudSubScreenStopSignCells->mCells[cellCount].mDrawPos, unk,
                                            1, 1)) {
            gRaceHudSubScreenStopSignCells->mCells[cellCount].mCell = GetRaceSNcerEntry(0x5b);
            gRaceHudSubScreenStopSignCells->mCells[cellCount].mUnk_0c = IsPositionOutsideBox(position) ? 2 : 3;
            gRaceHudSubScreenStopSignCells->mCells[cellCount].mUnk_0e = 0;
            gRaceHudSubScreenStopSignCells->mCells[cellCount].mUnk_10 = object->mAngle;
            cellCount++;
        }
    }
    gRaceHudSubScreenStopSignCells->mCellCount = cellCount;
}

void DrawRaceHudSubScreenStopSignCells(void *oamBuffer) {
    DrawRaceHudSubScreenCells(oamBuffer, gRaceHudSubScreenStopSignCells, 1);
}

s32 CreateRaceHudSubScreenMissionGateCells(void) {
    return CreateRaceHudSubScreenCells(&gRaceHudSubScreenMissionGateCells, MAP_OBJECT_KIND_MISSION_GATE);
}

void ClearRaceHudSubScreenMissionGateCells(void) {
    ClearRaceHudSubScreenCells(&gRaceHudSubScreenMissionGateCells);
}

void UpdateRaceHudSubScreenMissionGateCells(void) {
    s32 i;
    s32 cellCount;
    u32 unk;
    Unk0217b498_00 *object;
    Vec3 *position;

    cellCount = 0;
    unk = func_020c0db0();
    for (i = 0; i < gRaceHudSubScreenMissionGateCells->mObjectCount; i++) {
        object = gRaceHudSubScreenMissionGateCells->mObjects[i];
        position = &object->mPos;
        if (ComputeRaceHudSubScreenPosition(position, &gRaceHudSubScreenMissionGateCells->mCells[cellCount].mDrawPos,
                                            unk, 1, 1)) {
            gRaceHudSubScreenMissionGateCells->mCells[cellCount].mCell =
                GetRaceSNcerEntry(func_ov001_02185b50((MissionGateObject *) object) ? 0x5a : 0x59);
            gRaceHudSubScreenMissionGateCells->mCells[cellCount].mUnk_0c = IsPositionOutsideBox(position) ? 2 : 3;
            gRaceHudSubScreenMissionGateCells->mCells[cellCount].mUnk_0e = 0;
            gRaceHudSubScreenMissionGateCells->mCells[cellCount].mUnk_10 = object->mAngle;
            cellCount++;
        }
    }
    gRaceHudSubScreenMissionGateCells->mCellCount = cellCount;
}

void DrawRaceHudSubScreenMissionGateCells(void *oamBuffer) {
    DrawRaceHudSubScreenCells(oamBuffer, gRaceHudSubScreenMissionGateCells, 1);
}

s32 CreateRaceHudSubScreenHanachanCells(void) {
    return CreateRaceHudSubScreenCells(&gRaceHudSubScreenHanachanCells, MAP_OBJECT_KIND_HANACHAN);
}

void ClearRaceHudSubScreenHanachanCells(void) {
    ClearRaceHudSubScreenCells(&gRaceHudSubScreenHanachanCells);
}

void UpdateRaceHudSubScreenHanachanCells(void) {
    s32 i;
    s32 cellCount;
    u32 unk;
    Unk0217b498_00 *object;
    Vec3 *position;

    cellCount = 0;
    unk = func_020c0db0();
    for (i = 0; i < gRaceHudSubScreenHanachanCells->mObjectCount; i++) {
        object = gRaceHudSubScreenHanachanCells->mObjects[i];
        if (object->mFlags & 1) {
            continue;
        }
        position = &object->mPos;
        if (ComputeRaceHudSubScreenPosition(position, &gRaceHudSubScreenHanachanCells->mCells[cellCount].mDrawPos, unk,
                                            1, 1)) {
            gRaceHudSubScreenHanachanCells->mCells[cellCount].mCell =
                GetRaceSNcerEntry(GetMapObjectNsbtpFrameIndex((Unk02188950 *) object) >= 2 ? 0xc6 : 0xc5);
            gRaceHudSubScreenHanachanCells->mCells[cellCount].mUnk_0c = IsPositionOutsideBox(position) ? 2 : 3;
            gRaceHudSubScreenHanachanCells->mCells[cellCount].mUnk_0e = object->mFlags & 0x20;
            gRaceHudSubScreenHanachanCells->mCells[cellCount].mUnk_10 = object->mAngle;
            cellCount++;
        }
    }
    gRaceHudSubScreenHanachanCells->mCellCount = cellCount;
}

void DrawRaceHudSubScreenHanachanCells(void *oamBuffer) {
    DrawRaceHudSubScreenCells(oamBuffer, gRaceHudSubScreenHanachanCells, 0);
}

#pragma thumb on
