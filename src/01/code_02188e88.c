#include "01/code_02188e88.h"
#include "01/code_02185ef4.h"
#include "01/code_02187000.h"
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
#include "Main/Unknown/code_020c06c4.h"
#include "Main/Unknown/code_020c0b84.h"
#include "Main/Unknown/code_020c0ba8.h"
#include "Main/Unknown/code_020c0d9c.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020c0000.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_021000d0.h"

RaceHudSubScreenCells *gRaceHudSubScreenKingIceDonketuCells;
RaceHudSubScreenCells *data_ov001_021a9ba4;

#pragma thumb off

s32 CreateRaceHudSubScreenKingIceDonketuCells(void) {
    return CreateRaceHudSubScreenCells(&gRaceHudSubScreenKingIceDonketuCells, MAP_OBJECT_KIND_KING_ICE_DONKETU);
}

void ClearRaceHudSubScreenKingIceDonketuCells(void) {
    ClearRaceHudSubScreenCells(&gRaceHudSubScreenKingIceDonketuCells);
}

void UpdateRaceHudSubScreenKingIceDonketuCells(void) {
    s32 i;
    s32 cellCount = 0;
    u32 v = func_020c0db0();
    Unk0217b498_00 *object;
    Vec3 *pos;

    for (i = 0; i < gRaceHudSubScreenKingIceDonketuCells->mObjectCount; i++) {
        object = gRaceHudSubScreenKingIceDonketuCells->mObjects[i];
        if (!(object->mFlags & 1)) {
            pos = &object->mPos;
            if (ComputeRaceHudSubScreenPosition(pos, &gRaceHudSubScreenKingIceDonketuCells->mCells[cellCount].mDrawPos,
                                                v, 1, 1) != FALSE) {
                gRaceHudSubScreenKingIceDonketuCells->mCells[cellCount].mCell = GetRaceSNcerEntry(0xc5);
                gRaceHudSubScreenKingIceDonketuCells->mCells[cellCount].mUnk_0c = IsPositionOutsideBox(pos) ? 2 : 3;
                gRaceHudSubScreenKingIceDonketuCells->mCells[cellCount].mUnk_0e = object->mFlags & 0x20;
                gRaceHudSubScreenKingIceDonketuCells->mCells[cellCount].mUnk_10 = object->mAngle;
                cellCount++;
            }
        }
    }
    gRaceHudSubScreenKingIceDonketuCells->mCellCount = cellCount;
}

void DrawRaceHudSubScreenKingIceDonketuCells(void *oamBuffer) {
    DrawRaceHudSubScreenCells(oamBuffer, gRaceHudSubScreenKingIceDonketuCells, 0);
}

s32 func_ov001_02189128(void) {
    return CreateRaceHudSubScreenCells(&data_ov001_021a9ba4, 0x1fd);
}

void func_ov001_02189114(void) {
    ClearRaceHudSubScreenCells(&data_ov001_021a9ba4);
}

void func_ov001_02188ff8(void) {
    s32 i;
    s32 cellCount = 0;
    u32 v = func_020c0db0();
    Unk0217b498_00 *object;
    Vec3 *pos;

    for (i = 0; i < data_ov001_021a9ba4->mObjectCount; i++) {
        object = data_ov001_021a9ba4->mObjects[i];
        if (!(object->mFlags & 1)) {
            pos = &object->mPos;
            if (ComputeRaceHudSubScreenPosition(pos, &data_ov001_021a9ba4->mCells[cellCount].mDrawPos, v, 1, 1) !=
                FALSE) {
                data_ov001_021a9ba4->mCells[cellCount].mCell = GetRaceSNcerEntry(0xc5);
                data_ov001_021a9ba4->mCells[cellCount].mUnk_0c = IsPositionOutsideBox(pos) ? 2 : 3;
                data_ov001_021a9ba4->mCells[cellCount].mUnk_0e = object->mFlags & 0x20;
                data_ov001_021a9ba4->mCells[cellCount].mUnk_10 = object->mAngle;
                cellCount++;
            }
        }
    }
    data_ov001_021a9ba4->mCellCount = cellCount;
}

void func_ov001_02188fdc(void *oamBuffer) {
    DrawRaceHudSubScreenCells(oamBuffer, data_ov001_021a9ba4, 0);
}

#pragma thumb on

BOOL IsWithinXzDistanceOfPoint(Unk02188950 *mapObject, Vec3 *point, s32 radius) {
    Vec3 unusedOffset;
    s32 dx;
    s32 dz;
    float radiusAsFloat;
    float radiusAsFloatCopy;

    if (point != NULL) {
        VEC_Subtract(point, &mapObject->mUnk_000.mPos, &unusedOffset);
        dx = mapObject->mUnk_000.mPos.x - point->x;
        dz = mapObject->mUnk_000.mPos.z - point->z;
        if (radius > 0) {
            radiusAsFloat = 0.5f + (radius << 12);
        } else {
            radiusAsFloat = (radius << 12) - 0.5f;
        }
        if (radius > 0) {
            radiusAsFloatCopy = 0.5f + (radius << 12);
        } else {
            radiusAsFloatCopy = (radius << 12) - 0.5f;
        }
        if ((s64) dx * dx + (s64) dz * dz < (s64) (s32) radiusAsFloatCopy * (s32) radiusAsFloat) {
            return 1;
        }
        return 0;
    }
    return 0;
}

BOOL IsDirectionToPointWithinAngle(Unk02188950 *mapObject, s32 angle, Vec3 *point, s32 halfAngle) {
    s32 angleDifference;

    if (point != NULL) {
        angleDifference =
            (u16) (FX_Atan2Idx(point->x - mapObject->mUnk_000.mPos.x, point->z - mapObject->mUnk_000.mPos.z) - angle);
        if (angleDifference > 0x8000) {
            angleDifference -= 0x10000;
        }
        if (-halfAngle <= angleDifference && angleDifference <= halfAngle) {
            return 1;
        }
        return 0;
    }
    return 0;
}

void ClearAndRunCallback(Unk02188950 *mapObject, void (**callbackSlot)()) {
    void (*callback)() = *callbackSlot;

    *callbackSlot = NULL;
    if (callback != NULL) {
        callback(mapObject, callbackSlot, 0);
    }
}

void func_ov001_02188e88(Unk02188950 *mapObject) {
    func_ov001_02187218(mapObject, 0, (s32(*)(Unk02188950 *))(0));
}
