#include "Main/Unknown/code_020c7464.h"

#include "Main/Unknown/code_020c06c4.h"
#include "Main/Unknown/code_020c0ba8.h"
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
#include "Main/Unknown/code_020c0b84.h"
#include "Main/Unknown/code_020c0d9c.h"
#include "Main/Unknown/code_020de9f8.h"
#include "Main/Unknown/code_020e0680.h"
#include "Main/Unknown/code_021000d0.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020daf20.h"
#include "Main/Unknown/code_020ade08.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020ae000.h"
#include "Main/Unknown/code_02100084.h"
#include "Main/Unknown/code_02100094.h"
#include "code_020222ec.h"
#include "code_02148538.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_0207a000.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_020b4dc4.h"
#include "Main/Unknown/code_020d3c94.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_020f8e78.h"
#include "Main/Unknown/code_020fd83c.h"
#include "Main/Unknown/code_021001a0.h"
#include "Main/Unknown/code_02100de4.h"
#include "Main/Unknown/unk_02169000.h"
#include "Main/Unknown/unk_027e0000.h"
#include "Main/Unknown/code_0203c8dc.h"
#include "Main/Unknown/code_02077bc0.h"

// Indices into gItemKinds and gItemPools.
s32 gRaceHudSubScreenItemPoolIndices[10] = {0, 1, 2, 3, 4, 5, 9, 7, 8, 11};

void UpdateRaceHudSubScreenCrabCells(void) {
    s32 i;
    s32 cellCount;
    u32 v;

    cellCount = 0;
    v = GetRaceHudSubScreenScale();
    for (i = 0; i < gRaceHudSubScreenCrabCells->mObjectCount; i++) {
        Unk0217b498_00 *object;

        object = gRaceHudSubScreenCrabCells->mObjects[i];
        if (!(object->mFlags & 1)) {
            if (ComputeRaceHudSubScreenPosition(&object->mPos, &gRaceHudSubScreenCrabCells->mCells[cellCount].mDrawPos,
                                                v, 1, 1)) {
                gRaceHudSubScreenCrabCells->mCells[cellCount].mCell = GetRaceSNcerEntry(0x8a);
                gRaceHudSubScreenCrabCells->mCells[cellCount].mUnk_0c = 2;
                cellCount++;
            }
        }
    }
    gRaceHudSubScreenCrabCells->mCellCount = cellCount;
}

void DrawRaceHudSubScreenCrabCells(RaceHudOamBuffer *oamBuffer) {
    DrawRaceHudSubScreenCells(oamBuffer, gRaceHudSubScreenCrabCells, 0);
}

s32 CreateRaceHudSubScreenItemCells(void) {
    s32 objectCount;
    s32 i;

    objectCount = 0;
    for (i = 0; i < 10; i++) {
        objectCount += gItemKinds[gRaceHudSubScreenItemPoolIndices[i]].mObjectCount;
    }
    return CreateRaceHudSubScreenCellsWithCount(&gRaceHudSubScreenItemCells, objectCount);
}

void ClearRaceHudSubScreenItemCells(void) {
    ClearRaceHudSubScreenCells(&gRaceHudSubScreenItemCells);
}

void UpdateRaceHudSubScreenItemCells(void) {
    enum { K0 } poolIndex;
    s32 cellCount;
    s32 a;
    s32 tableIndex;
    s32 j;
    ItemPool *pool;
    ItemObject **objects;
    s32 activeCount;
    Unk020224e0_c *cell;
    ItemObject *object;
    Vec3 *position;
    s32 v;

    cellCount = 0;
    a = GetRaceHudSubScreenScale();
    for (tableIndex = 0; tableIndex < 10; tableIndex++) {
        poolIndex = gRaceHudSubScreenItemPoolIndices[tableIndex];
        pool = &gItemPools[poolIndex];
        objects = pool->mObjects;
        activeCount = pool->mActiveCount;
        {
            s32 cellIndices[10] = {0x4c, 0x4d, 0x4b, 0x4f, 0x50, 0x56, 0x55, 0x54, 0x4e, 0x57};

            cell = GetRaceSNcerEntry(cellIndices[tableIndex]);
        }
        for (j = 0; j < activeCount; j++) {
            object = objects[j];
            if ((object->mFlags & 0x80000) != 0) {
                position = NULL;
            } else {
                position = &object->mPos;
            }
            if (tableIndex == 9) {
                if (position != NULL) {
                    if (ComputeRaceHudSubScreenPosition(
                            position, &gRaceHudSubScreenItemCells->mCells[cellCount].mDrawPos, a, 1, 1) != FALSE) {
                        if (object->mAlpha > 0) {
                            v = ((ItemTeresa *) object)->mOffsetY;
                            gRaceHudSubScreenItemCells->mCells[cellCount].mDrawPos.mUnk_04 -=
                                0x88 * v / func_021001a0();
                            if (gRaceHudSubScreenItemCells->mCells[cellCount].mDrawPos.mUnk_04 > 0) {
                                gRaceHudSubScreenItemCells->mCells[cellCount].mCell = cell;
                                gRaceHudSubScreenItemCells->mCells[cellCount].mUnk_0c =
                                    IsPositionOutsideBox(position) != 0 ? 2 : 3;
                                gRaceHudSubScreenItemCells->mCells[cellCount].mUnk_0e = 0;
                                cellCount++;
                            }
                        }
                    }
                }
            } else if (tableIndex == 6) {
                if (((ItemBomb *) object)->mVisible != FALSE && position != NULL) {
                    if (ComputeRaceHudSubScreenPosition(
                            position, &gRaceHudSubScreenItemCells->mCells[cellCount].mDrawPos, a, 1, 1) != FALSE) {
                        if (func_020d3d10(position->y) == 0) {
                            gRaceHudSubScreenItemCells->mCells[cellCount].mCell = cell;
                            gRaceHudSubScreenItemCells->mCells[cellCount].mUnk_0c =
                                IsPositionOutsideBox(position) != 0 ? 2 : 3;
                            gRaceHudSubScreenItemCells->mCells[cellCount].mUnk_0e =
                                (object->mFlags & 0x40000) != 0 ? 1 : 0;
                            cellCount++;
                        }
                    }
                }
            } else {
                if (position != NULL) {
                    if (ComputeRaceHudSubScreenPosition(
                            position, &gRaceHudSubScreenItemCells->mCells[cellCount].mDrawPos, a, 1, 1) != FALSE) {
                        if (func_020d3d10(position->y) == 0) {
                            gRaceHudSubScreenItemCells->mCells[cellCount].mCell = cell;
                            gRaceHudSubScreenItemCells->mCells[cellCount].mUnk_0c =
                                IsPositionOutsideBox(position) != 0 ? 2 : 3;
                            gRaceHudSubScreenItemCells->mCells[cellCount].mUnk_0e =
                                (object->mFlags & 0x40000) != 0 ? 1 : 0;
                            cellCount++;
                        }
                    }
                }
            }
        }
    }
    gRaceHudSubScreenItemCells->mCellCount = cellCount;
}

void DrawRaceHudSubScreenItemCells(RaceHudOamBuffer *oamBuffer) {
    DrawRaceHudSubScreenCells(oamBuffer, gRaceHudSubScreenItemCells, 0);
}

s32 CreateRaceHudSubScreenKarts(void) {
    s32 i;

    gRaceHudSubScreenKarts = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x194);
    CreateRaceHudSubScreenCellsWithCount(&gRaceHudSubScreenKarts->mUnk_190, 0x18);
    for (i = 0; i < 8; i++) {
        gRaceHudSubScreenKarts->mUnk_000[i] = 0;
        gRaceHudSubScreenKarts->mUnk_020[i] = 0;
        gRaceHudSubScreenKarts->mUnk_060[i].mUnk_00 = 0;
        gRaceHudSubScreenKarts->mUnk_060[i].mUnk_04 = 0;
        gRaceHudSubScreenKarts->mUnk_100[i] = 0;
        gRaceHudSubScreenKarts->mUnk_130[i] = 0;
    }
    return 1;
}

void ClearRaceHudSubScreenKarts(void) {
    ClearRaceHudSubScreenCells(&gRaceHudSubScreenKarts->mUnk_190);
    gRaceHudSubScreenKarts = NULL;
}

void UpdateRaceHudSubScreenKarts(void) {
    s32 sortKeys[8];
    u32 a;
    u16 i;
    Vec3 kartPosition;
    Vec3 w;
    Vec3 t;
    ItemObject **objects;
    s32 objectCount;
    s32 cellCount;
    s32 j;
    s32 f;
    ItemObject *object;
    Vec3 *position;
    u32 b;
    ItemInUse *itemInUse;
    s32 screenX;
    s32 screenY;

    a = GetRaceHudSubScreenScale();
    for (i = 0; i < (u32) gRaceSetup->mKartCount; i++) {
        gRaceHudSubScreenKarts->mUnk_000[i] = 0;
        gRaceHudSubScreenKarts->mUnk_130[i] = i;
        sortKeys[i] = GetKartRank(i & 0xff);
    }
    switch (GetRaceHudSubScreenState()) {
        case 0:
            for (i = 0; i < (u32) gRaceSetup->mKartCount; i++) {
                ComputeSubScreenState0KartPosition(i, &gRaceHudSubScreenKarts->mUnk_060[i]);
                screenX = gRaceHudSubScreenKarts->mUnk_060[i].mUnk_00;
                screenY = gRaceHudSubScreenKarts->mUnk_060[i].mUnk_04;
                if (screenX > -0x10 && screenX < 0x110 && screenY > -0x10 && screenY < 0xd0 && func_0207a84c(i) == 0) {
                    gRaceHudSubScreenKarts->mUnk_000[i] = 1;
                    if (gRaceSetup->mMode == MODE_TIME_ATTACK &&
                        gRaceSetup->mCurrentEntries[i].mPlayer.mKind == PLAYER_KIND_GHOST) {
                        gRaceHudSubScreenKarts->mUnk_040[i] = 1;
                    } else {
                        gRaceHudSubScreenKarts->mUnk_040[i] = 0;
                    }
                    GetKartScale(&gRaceHudSubScreenKarts->mUnk_0a0[i], i);
                    if (GetKart(i)->mState != KART_STATE_NORMAL) {
                        gRaceHudSubScreenKarts->mUnk_110[i]++;
                        gRaceHudSubScreenKarts->mUnk_100[i] = (gRaceHudSubScreenKarts->mUnk_110[i] << 12) % 0x10000;
                    } else {
                        gRaceHudSubScreenKarts->mUnk_100[i] = 0;
                        gRaceHudSubScreenKarts->mUnk_110[i] = 0;
                    }
                }
            }
            break;
        case 1:
        case 2:
        case 3:
            gRaceHudSubScreenKarts->mUnk_190->mCellCount = 0;
            for (i = 0; i < (u32) gRaceSetup->mKartCount; i++) {
                GetKartPos(&kartPosition, i & 0xff);
                ComputeRaceHudSubScreenKartPosition(i, &gRaceHudSubScreenKarts->mUnk_060[i], a);
                screenX = gRaceHudSubScreenKarts->mUnk_060[i].mUnk_00;
                screenY = gRaceHudSubScreenKarts->mUnk_060[i].mUnk_04;
                if (screenX > -0x10 && screenX < 0x110 && screenY > -0x10 && screenY < 0xd0 && func_0207a84c(i) == 0) {
                    gRaceHudSubScreenKarts->mUnk_000[i] = 1;
                    gRaceHudSubScreenKarts->mUnk_040[i] = func_020b4dc4(i);
                    GetKartScale(&gRaceHudSubScreenKarts->mUnk_0a0[i], i);
                    if (GetKart(i)->mState != KART_STATE_NORMAL) {
                        gRaceHudSubScreenKarts->mUnk_110[i]++;
                        gRaceHudSubScreenKarts->mUnk_100[i] = (gRaceHudSubScreenKarts->mUnk_110[i] << 12) % 0x10000;
                    } else {
                        gRaceHudSubScreenKarts->mUnk_100[i] = 0;
                        gRaceHudSubScreenKarts->mUnk_110[i] = 0;
                    }
                    gRaceHudSubScreenKarts->mUnk_150[i] = IsPositionOutsideBox(&kartPosition) != 0 ? 2 : 3;
                    itemInUse = &gKartItems[i].mItemInUse;
                    objects = itemInUse->mObjects;
                    objectCount = itemInUse->mObjectCount;
                    cellCount = gRaceHudSubScreenKarts->mUnk_190->mCellCount;
                    b = GetRaceHudSubScreenScale();
                    for (j = 0; j < objectCount; j++) {
                        object = objects[j];
                        if ((object->mFlags & 0x80000) != 0) {
                            position = NULL;
                        } else {
                            position = &object->mPos;
                        }
                        f = func_020f91e0(object);
                        if (position != NULL && f != 0) {
                            ComputePointAlongLine(&t, &kartPosition, position);
                            w = t;
                            if (ComputeRaceHudSubScreenPosition(
                                    &w, &gRaceHudSubScreenKarts->mUnk_190->mCells[cellCount].mDrawPos, b, 0, 1) !=
                                FALSE) {
                                switch (object->mKind) {
                                    case 0:
                                        gRaceHudSubScreenKarts->mUnk_190->mCells[cellCount].mCell =
                                            GetRaceSNcerEntry(0x4c);
                                        break;
                                    case 1:
                                        gRaceHudSubScreenKarts->mUnk_190->mCells[cellCount].mCell =
                                            GetRaceSNcerEntry(0x4d);
                                        break;
                                    case 2:
                                        gRaceHudSubScreenKarts->mUnk_190->mCells[cellCount].mCell =
                                            GetRaceSNcerEntry(0x4b);
                                        break;
                                    case 5:
                                        gRaceHudSubScreenKarts->mUnk_190->mCells[cellCount].mCell =
                                            GetRaceSNcerEntry(0x56);
                                        break;
                                    case 9:
                                        gRaceHudSubScreenKarts->mUnk_190->mCells[cellCount].mCell =
                                            GetRaceSNcerEntry(0x55);
                                        break;
                                    case 7:
                                        gRaceHudSubScreenKarts->mUnk_190->mCells[cellCount].mCell =
                                            GetRaceSNcerEntry(0x54);
                                        break;
                                    case 8:
                                        gRaceHudSubScreenKarts->mUnk_190->mCells[cellCount].mCell =
                                            GetRaceSNcerEntry(0x4e);
                                        break;
                                    default:
                                        gRaceHudSubScreenKarts->mUnk_190->mCells[cellCount].mCell =
                                            GetRaceSNcerEntry(0x4c);
                                        break;
                                }
                                gRaceHudSubScreenKarts->mUnk_190->mCells[cellCount].mUnk_0c =
                                    IsPositionOutsideBox(&w) != 0 ? 2 : 3;
                                gRaceHudSubScreenKarts->mUnk_190->mCells[cellCount].mUnk_0e =
                                    (object->mFlags & 0x40000) != 0 ? 1 : 0;
                                cellCount++;
                            }
                        }
                    }
                    gRaceHudSubScreenKarts->mUnk_190->mCellCount = cellCount;
                }
            }
            break;
    }
    for (i = 0; i < (u32) gRaceSetup->mKartCount; i++) {
        if (GetKartItemEffect(i) == 1) {
            gRaceHudSubScreenKarts->mUnk_170[i]++;
        } else {
            gRaceHudSubScreenKarts->mUnk_170[i] = 0;
        }
        if (i != GetFollowedKartOrEntryIndex() && (GetKart(i)->mUnk_7c & 0x402000) != 0) {
            gRaceHudSubScreenKarts->mUnk_020[i] = 1;
        } else {
            gRaceHudSubScreenKarts->mUnk_020[i] = 0;
        }
    }
    for (i = 0; i < (u32) gRaceSetup->mKartCount; i++) {
        if (gRaceHudSubScreenKarts->mUnk_040[i] == 0) {
            sortKeys[i] -= 0x20;
        }
        if (i == GetFollowedKartOrEntryIndex()) {
            sortKeys[i] -= 0x10;
        }
    }
    if (gRaceSetup->mMode == MODE_TIME_ATTACK) {
        return;
    }
    SortIndicesByKey(gRaceHudSubScreenKarts->mUnk_130, sortKeys, gRaceSetup->mKartCount);
}

static inline void func_020c8dbc_inline(RaceHudOamBuffer *oamBuffer, Unk020224e0_c *cell, s32 *matrix, s32 x, s32 y,
                                        u16 v, s32 s, s32 g) {
    s32 position[2];
    s32 oamIndex;
    RaceHudOamBits *oam;

    oamIndex = oamBuffer->mOamCount;
    position[0] = x << 12;
    position[1] = y << 12;
    oam = &oamBuffer->mOamBits[oamIndex];
    oamBuffer->mOamCount += NNS_G2dMakeCellToOams((GXOamAttr *) oam, 0x80 - oamIndex, cell, matrix, position, v, 1);
    for (; oamIndex < oamBuffer->mOamCount; oamIndex++) {
        if (s != -1) {
            oam->mUnk_0a = s;
        }
        if (g != -1) {
            oam->mUnk_0e = g;
        }
        oam++;
    }
}

static inline void func_020c8dbc_inline2(RaceHudOamBuffer *oamBuffer, Unk020224e0_c *cell, s32 x, s32 y) {
    s32 position[2];
    s32 oamIndex;

    position[0] = x << 12;
    position[1] = y << 12;
    oamIndex = oamBuffer->mOamCount;
    oamBuffer->mOamCount +=
        NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamIndex], 0x80 - oamIndex, cell, NULL, position, 0, 1);
}

static inline void func_020c8dbc_inline3(RaceHudOamBuffer *oamBuffer, s32 kartIndex, s32 frame) {
    s32 j;
    s32 angleIndex;
    s32 offsetX;
    s32 offsetY;
    Unk020224e0_c *cell;

    for (j = 0; j < 3; j++) {
        angleIndex = (u16) (((frame + 12 - j * 4) << 16) / 64) >> 4;
        offsetX = (s16) gPairsByAngle[angleIndex * 2 + 1] * 11 >> 12;
        offsetY = (s16) gPairsByAngle[angleIndex * 2] * 11 >> 12;
        cell = GetRaceSNcerEntry(frame % 12 < 6 ? 93 + j * 2 : 94 + j * 2);
        func_020c8dbc_inline2(oamBuffer, cell, gRaceHudSubScreenKarts->mUnk_060[kartIndex].mUnk_00 + offsetX,
                              gRaceHudSubScreenKarts->mUnk_060[kartIndex].mUnk_04 + offsetY);
    }
}

void DrawRaceHudSubScreenKarts(RaceHudOamBuffer *oamBuffer) {
    s32 kartIndex;
    s32 f;
    Unk020224e0_c *cell;
    s32 rotationMatrix[4];
    s32 r1[4];
    s32 drawOrderIndex;
    s32 g;
    s32 b;
    u16 rotationSlot;
    u16 angle;
    s32 a;
    u16 n;
    s32 screenX;
    s32 screenY;

    switch (GetRaceHudSubScreenState()) {
        case 0:
            for (drawOrderIndex = 0; drawOrderIndex < gRaceSetup->mKartCount; drawOrderIndex++) {
                kartIndex = gRaceHudSubScreenKarts->mUnk_130[drawOrderIndex];
                if (gRaceHudSubScreenKarts->mUnk_000[kartIndex] != 0) {
                    f = gRaceHudSubScreenKarts->mUnk_040[kartIndex];
                    if (gRaceHudSubScreenKarts->mUnk_020[kartIndex] == 0) {
                        if (gRaceHudSubScreenKarts->mUnk_0a0[kartIndex].y != 0x1000 ||
                            gRaceHudSubScreenKarts->mUnk_110[kartIndex] != 0) {
                            rotationSlot = AllocOamMatrixIndex(oamBuffer);
                            Matrix2x2RotationReciprocalScale(rotationMatrix,
                                                             gRaceHudSubScreenKarts->mUnk_0a0[kartIndex].y,
                                                             gRaceHudSubScreenKarts->mUnk_100[kartIndex]);
                            if (GetKartItemEffect((u16) kartIndex) == 3) {
                                cell = GetRaceSNcerEntry(0x10);
                            } else {
                                cell = GetRaceSNcerEntry(kartIndex);
                            }
                            func_020c8dbc_inline(
                                oamBuffer, cell, rotationMatrix, gRaceHudSubScreenKarts->mUnk_060[kartIndex].mUnk_00,
                                gRaceHudSubScreenKarts->mUnk_060[kartIndex].mUnk_04, rotationSlot, f != 0 ? 1 : -1, -1);
                            oamBuffer->mMatrices[rotationSlot].mUnk_06 = rotationMatrix[0] >> 4;
                            oamBuffer->mMatrices[rotationSlot].mUnk_0e = rotationMatrix[1] >> 4;
                            oamBuffer->mMatrices[rotationSlot].mUnk_16 = rotationMatrix[2] >> 4;
                            oamBuffer->mMatrices[rotationSlot].mUnk_1e = rotationMatrix[3] >> 4;
                        } else {
                            if (GetKartItemEffect((u16) kartIndex) == 3) {
                                cell = GetRaceSNcerEntry(0x10);
                            } else {
                                cell = GetRaceSNcerEntry(kartIndex);
                            }
                            func_020c8dbc_inline(
                                oamBuffer, cell, NULL, gRaceHudSubScreenKarts->mUnk_060[kartIndex].mUnk_00,
                                gRaceHudSubScreenKarts->mUnk_060[kartIndex].mUnk_04, 0, f != 0 ? 1 : -1, -1);
                        }
                    }
                    if (gRaceHudSubScreenKarts->mUnk_170[kartIndex] != 0) {
                        func_020c8dbc_inline3(oamBuffer, kartIndex, gRaceHudSubScreenKarts->mUnk_170[kartIndex]);
                    }
                }
            }
            break;
        case 1:
        case 2:
        case 3:
            a = func_020c0dc4();
            for (drawOrderIndex = 0; drawOrderIndex < gRaceSetup->mKartCount; drawOrderIndex++) {
                kartIndex = gRaceHudSubScreenKarts->mUnk_130[drawOrderIndex];
                g = gRaceHudSubScreenKarts->mUnk_150[kartIndex];
                if (gRaceHudSubScreenKarts->mUnk_000[kartIndex] != 0 && a <= g) {
                    if (gRaceHudSubScreenKarts->mUnk_020[kartIndex] == 0) {
                        screenX = gRaceHudSubScreenKarts->mUnk_060[kartIndex].mUnk_00;
                        screenY = gRaceHudSubScreenKarts->mUnk_060[kartIndex].mUnk_04;
                        b = gRaceHudSubScreenKarts->mUnk_040[kartIndex];
                        if (gRaceHudSubScreenKarts->mUnk_0a0[kartIndex].y != 0x1000 ||
                            gRaceHudSubScreenKarts->mUnk_110[kartIndex] != 0) {
                            n = AllocOamMatrixIndex(oamBuffer);
                            if (gRaceHudSubScreenKarts->mUnk_110[kartIndex] != 0) {
                                angle = gRaceHudSubScreenKarts->mUnk_100[kartIndex] +
                                        GetSubScreenAngleAndClearScrollTimer();
                            } else {
                                angle = 0;
                            }
                            Matrix2x2RotationReciprocalScale(r1, gRaceHudSubScreenKarts->mUnk_0a0[kartIndex].y, angle);
                            if (GetKartItemEffect((u16) kartIndex) == 3) {
                                cell = GetRaceSNcerEntry(0x10);
                            } else {
                                cell = GetRaceSNcerEntry(kartIndex);
                            }
                            func_020c8dbc_inline(oamBuffer, cell, r1, screenX, screenY, n, b != 0 ? 1 : -1, g);
                            oamBuffer->mMatrices[n].mUnk_06 = r1[0] >> 4;
                            oamBuffer->mMatrices[n].mUnk_0e = r1[1] >> 4;
                            oamBuffer->mMatrices[n].mUnk_16 = r1[2] >> 4;
                            oamBuffer->mMatrices[n].mUnk_1e = r1[3] >> 4;
                        } else {
                            if (GetKartItemEffect((u16) kartIndex) == 3) {
                                cell = GetRaceSNcerEntry(0x10);
                            } else {
                                cell = GetRaceSNcerEntry(kartIndex);
                            }
                            func_020c8dbc_inline(oamBuffer, cell, NULL, screenX, screenY, 0, b != 0 ? 1 : -1, g);
                        }
                    }
                    if (gRaceHudSubScreenKarts->mUnk_170[kartIndex] != 0) {
                        func_020c8dbc_inline3(oamBuffer, kartIndex, gRaceHudSubScreenKarts->mUnk_170[kartIndex]);
                    }
                }
            }
            DrawRaceHudSubScreenCells(oamBuffer, gRaceHudSubScreenKarts->mUnk_190, 0);
            break;
    }
}

BOOL CreateRaceHudSubScreenSecondHand(void) {
    MapObjectList *kindEntry;
    s32 objectCount;

    kindEntry = FindMapObjectKindDrawList0(MAP_OBJECT_KIND_SECOND_HAND);
    if (kindEntry == NULL) {
        return FALSE;
    }
    objectCount = func_02100094(kindEntry);
    if (objectCount == 0) {
        return FALSE;
    }
    gRaceHudSubScreenSecondHand = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x44);
    gRaceHudSubScreenSecondHand->mObjects = RaceHudSubScreenGetMapObjects(kindEntry);
    gRaceHudSubScreenSecondHand->mUnk_04 = objectCount;
    gRaceHudSubScreenSecondHand->mObjectCount = objectCount;
    return TRUE;
}

u32 ClearRaceHudSubScreenSecondHandPointer(void) {
    u32 address;
    u32 zero;
    address = (u32) &gRaceHudSubScreenSecondHand;
    zero = 0u;
    *(u32 *) ((address) + (0)) = zero;
    return address;
}

void UpdateRaceHudSubScreenSecondHand(void) {
    s32 i;
    u32 a;
    Unk020e1e98 *object;
    s32 extentZ;
    Vec3 *position;
    s32 deltaX;
    s32 deltaZ;
    Vec3 endPosition;

    a = GetRaceHudSubScreenScale();
    for (i = 0; i < gRaceHudSubScreenSecondHand->mObjectCount; i++) {
        object = gRaceHudSubScreenSecondHand->mObjects[i];
        extentZ = object->mUnk_000.mExtent.z;
        position = &object->mUnk_000.mPos;
        deltaX = (s64) object->mUnk_000.mMatrix.mUnk_00[2].x * extentZ >> 12;
        deltaZ = (s64) object->mUnk_000.mMatrix.mUnk_00[2].z * extentZ >> 12;
        if (gRaceSetup->mMirrorMode != 0) {
            gRaceHudSubScreenSecondHand->mAngles[i] = FX_Atan2Idx(-deltaZ, deltaX) + 0x8000;
        } else {
            gRaceHudSubScreenSecondHand->mAngles[i] = FX_Atan2Idx(deltaZ, deltaX);
        }
        ComputeRaceHudSubScreenPosition(position, &gRaceHudSubScreenSecondHand->mDrawPositions[i], a, 0, 0);
        endPosition.x = position->x + deltaX;
        endPosition.z = position->z + deltaZ;
        ComputeRaceHudSubScreenPosition(&endPosition, &gRaceHudSubScreenSecondHand->mUnk_2c[i], a, 0, 0);
    }
}

void DrawRaceHudSubScreenSecondHand(RaceHudOamBuffer *oamBuffer) {
    Unk020224e0_c *cell;
    s32 rotationMatrix[4];
    u32 a;
    u16 rotationSlot0;
    u16 rotationSlot1;
    u16 rotationSlot2;
    u16 angle0;
    s32 screenX0;
    s32 screenY0;
    s32 trailDeltaX0;
    s32 trailDeltaY0;
    s32 trailSumX0;
    s32 trailSumY0;
    s32 trailStep0;
    u16 angle2;
    s32 screenX2;
    s32 screenY2;
    s32 trailDeltaX2;
    s32 trailDeltaY2;
    s32 trailSumX2;
    s32 trailSumY2;
    s32 trailStep2;
    u16 angle1;
    s32 screenX1;
    s32 screenY1;
    s32 trailDeltaX1;
    s32 trailDeltaY1;
    s32 trailSumX1;
    s32 trailSumY1;
    s32 trailStep1;
    s32 endPosition0[2];
    s32 middlePosition0[2];
    s32 drawPosition0[2];
    s32 endPosition2[2];
    s32 middlePosition2[2];
    s32 drawPosition2[2];
    s32 endPosition1[2];
    s32 middlePosition1[2];
    s32 drawPosition1[2];

    a = func_020c0dc4();
    if (gRaceHudSubScreenSecondHand->mUnk_04 <= 0) {
        return;
    }
    if (a == 0) {
        if (gRaceSetup->mMirrorMode != 0) {
            angle0 = gRaceHudSubScreenSecondHand->mAngles[0] - GetSubScreenAngleAndClearScrollTimer();
        } else {
            angle0 = gRaceHudSubScreenSecondHand->mAngles[0] + GetSubScreenAngleAndClearScrollTimer();
        }
        rotationSlot0 = AllocOamMatrixIndex(oamBuffer);
        Matrix2x2Rotation(rotationMatrix, angle0);
        screenX0 = gRaceHudSubScreenSecondHand->mUnk_2c[0].mUnk_00;
        screenY0 = gRaceHudSubScreenSecondHand->mUnk_2c[0].mUnk_04;
        if (screenX0 > -32 && screenX0 < 288 && screenY0 > -32 && screenY0 < 224) {
            cell = GetRaceSNcerEntry(156);
            endPosition0[0] = screenX0 << 12;
            endPosition0[1] = screenY0 << 12;
            oamBuffer->mOamCount +=
                NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell,
                                      rotationMatrix, endPosition0, rotationSlot0, 1);
        }
        trailDeltaX0 =
            gRaceHudSubScreenSecondHand->mDrawPositions[0].mUnk_00 - gRaceHudSubScreenSecondHand->mUnk_2c[0].mUnk_00;
        trailDeltaY0 =
            gRaceHudSubScreenSecondHand->mDrawPositions[0].mUnk_04 - gRaceHudSubScreenSecondHand->mUnk_2c[0].mUnk_04;
        for (trailStep0 = 0, trailSumX0 = 0, trailSumY0 = 0; trailStep0 < 3; trailStep0++) {
            screenX0 = gRaceHudSubScreenSecondHand->mUnk_2c[0].mUnk_00 + (trailSumX0 + trailDeltaX0) / 4;
            screenY0 = gRaceHudSubScreenSecondHand->mUnk_2c[0].mUnk_04 + (trailSumY0 + trailDeltaY0) / 4;
            if (screenX0 > -32 && screenX0 < 288 && screenY0 > -32 && screenY0 < 224) {
                cell = GetRaceSNcerEntry(155);
                middlePosition0[0] = screenX0 << 12;
                middlePosition0[1] = screenY0 << 12;
                oamBuffer->mOamCount +=
                    NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell,
                                          rotationMatrix, middlePosition0, rotationSlot0, 1);
            }
            trailSumX0 += trailDeltaX0;
            trailSumY0 += trailDeltaY0;
        }
        screenX0 = gRaceHudSubScreenSecondHand->mDrawPositions[0].mUnk_00;
        screenY0 = gRaceHudSubScreenSecondHand->mDrawPositions[0].mUnk_04;
        if (screenX0 > -32 && screenX0 < 288 && screenY0 > -32 && screenY0 < 224) {
            cell = GetRaceSNcerEntry(154);
            drawPosition0[0] = screenX0 << 12;
            drawPosition0[1] = screenY0 << 12;
            oamBuffer->mOamCount +=
                NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell,
                                      rotationMatrix, drawPosition0, rotationSlot0, 1);
        }
        oamBuffer->mMatrices[rotationSlot0].mUnk_06 = rotationMatrix[0] >> 4;
        oamBuffer->mMatrices[rotationSlot0].mUnk_0e = rotationMatrix[1] >> 4;
        oamBuffer->mMatrices[rotationSlot0].mUnk_16 = rotationMatrix[2] >> 4;
        oamBuffer->mMatrices[rotationSlot0].mUnk_1e = rotationMatrix[3] >> 4;
    }
    if (gRaceHudSubScreenSecondHand->mObjectCount == 3 && a == 0) {
        if (gRaceSetup->mMirrorMode != 0) {
            angle2 = gRaceHudSubScreenSecondHand->mAngles[2] - GetSubScreenAngleAndClearScrollTimer();
        } else {
            angle2 = gRaceHudSubScreenSecondHand->mAngles[2] + GetSubScreenAngleAndClearScrollTimer();
        }
        rotationSlot2 = AllocOamMatrixIndex(oamBuffer);
        Matrix2x2Rotation(rotationMatrix, angle2);
        screenX2 = gRaceHudSubScreenSecondHand->mUnk_2c[2].mUnk_00;
        screenY2 = gRaceHudSubScreenSecondHand->mUnk_2c[2].mUnk_04;
        if (screenX2 > -32 && screenX2 < 288 && screenY2 > -32 && screenY2 < 224) {
            cell = GetRaceSNcerEntry(156);
            endPosition2[0] = screenX2 << 12;
            endPosition2[1] = screenY2 << 12;
            oamBuffer->mOamCount +=
                NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell,
                                      rotationMatrix, endPosition2, rotationSlot2, 1);
        }
        trailDeltaX2 =
            gRaceHudSubScreenSecondHand->mDrawPositions[2].mUnk_00 - gRaceHudSubScreenSecondHand->mUnk_2c[2].mUnk_00;
        trailDeltaY2 =
            gRaceHudSubScreenSecondHand->mDrawPositions[2].mUnk_04 - gRaceHudSubScreenSecondHand->mUnk_2c[2].mUnk_04;
        for (trailStep2 = 0, trailSumX2 = 0, trailSumY2 = 0; trailStep2 < 2; trailStep2++) {
            screenX2 = gRaceHudSubScreenSecondHand->mUnk_2c[2].mUnk_00 + (trailSumX2 + trailDeltaX2) / 3;
            screenY2 = gRaceHudSubScreenSecondHand->mUnk_2c[2].mUnk_04 + (trailSumY2 + trailDeltaY2) / 3;
            if (screenX2 > -32 && screenX2 < 288 && screenY2 > -32 && screenY2 < 224) {
                cell = GetRaceSNcerEntry(155);
                middlePosition2[0] = screenX2 << 12;
                middlePosition2[1] = screenY2 << 12;
                oamBuffer->mOamCount +=
                    NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell,
                                          rotationMatrix, middlePosition2, rotationSlot2, 1);
            }
            trailSumX2 += trailDeltaX2;
            trailSumY2 += trailDeltaY2;
        }
        screenX2 = gRaceHudSubScreenSecondHand->mDrawPositions[2].mUnk_00;
        screenY2 = gRaceHudSubScreenSecondHand->mDrawPositions[2].mUnk_04;
        if (screenX2 > -32 && screenX2 < 288 && screenY2 > -32 && screenY2 < 224) {
            cell = GetRaceSNcerEntry(154);
            drawPosition2[0] = screenX2 << 12;
            drawPosition2[1] = screenY2 << 12;
            oamBuffer->mOamCount +=
                NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell,
                                      rotationMatrix, drawPosition2, rotationSlot2, 1);
        }
        oamBuffer->mMatrices[rotationSlot2].mUnk_06 = rotationMatrix[0] >> 4;
        oamBuffer->mMatrices[rotationSlot2].mUnk_0e = rotationMatrix[1] >> 4;
        oamBuffer->mMatrices[rotationSlot2].mUnk_16 = rotationMatrix[2] >> 4;
        oamBuffer->mMatrices[rotationSlot2].mUnk_1e = rotationMatrix[3] >> 4;
    }
    if (gRaceSetup->mMirrorMode != 0) {
        angle1 = gRaceHudSubScreenSecondHand->mAngles[1] - GetSubScreenAngleAndClearScrollTimer();
    } else {
        angle1 = gRaceHudSubScreenSecondHand->mAngles[1] + GetSubScreenAngleAndClearScrollTimer();
    }
    rotationSlot1 = AllocOamMatrixIndex(oamBuffer);
    Matrix2x2Rotation(rotationMatrix, angle1);
    screenX1 = gRaceHudSubScreenSecondHand->mUnk_2c[1].mUnk_00;
    screenY1 = gRaceHudSubScreenSecondHand->mUnk_2c[1].mUnk_04;
    if (screenX1 > -16 && screenX1 < 272 && screenY1 > -16 && screenY1 < 208) {
        cell = GetRaceSNcerEntry(159);
        endPosition1[0] = screenX1 << 12;
        endPosition1[1] = screenY1 << 12;
        oamBuffer->mOamCount +=
            NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell,
                                  rotationMatrix, endPosition1, rotationSlot1, 1);
    }
    trailDeltaX1 =
        gRaceHudSubScreenSecondHand->mDrawPositions[1].mUnk_00 - gRaceHudSubScreenSecondHand->mUnk_2c[1].mUnk_00;
    trailDeltaY1 =
        gRaceHudSubScreenSecondHand->mDrawPositions[1].mUnk_04 - gRaceHudSubScreenSecondHand->mUnk_2c[1].mUnk_04;
    for (trailStep1 = 0, trailSumX1 = 0, trailSumY1 = 0; trailStep1 < 3; trailStep1++) {
        screenX1 = gRaceHudSubScreenSecondHand->mUnk_2c[1].mUnk_00 + (trailSumX1 + trailDeltaX1) / 4;
        screenY1 = gRaceHudSubScreenSecondHand->mUnk_2c[1].mUnk_04 + (trailSumY1 + trailDeltaY1) / 4;
        if (screenX1 > -16 && screenX1 < 272 && screenY1 > -16 && screenY1 < 208) {
            cell = GetRaceSNcerEntry(158);
            middlePosition1[0] = screenX1 << 12;
            middlePosition1[1] = screenY1 << 12;
            oamBuffer->mOamCount +=
                NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell,
                                      rotationMatrix, middlePosition1, rotationSlot1, 1);
        }
        trailSumX1 += trailDeltaX1;
        trailSumY1 += trailDeltaY1;
    }
    screenX1 = gRaceHudSubScreenSecondHand->mDrawPositions[1].mUnk_00;
    screenY1 = gRaceHudSubScreenSecondHand->mDrawPositions[1].mUnk_04;
    if (screenX1 > -16 && screenX1 < 272 && screenY1 > -16 && screenY1 < 208) {
        cell = GetRaceSNcerEntry(157);
        drawPosition1[0] = screenX1 << 12;
        drawPosition1[1] = screenY1 << 12;
        oamBuffer->mOamCount +=
            NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell,
                                  rotationMatrix, drawPosition1, rotationSlot1, 1);
    }
    oamBuffer->mMatrices[rotationSlot1].mUnk_06 = rotationMatrix[0] >> 4;
    oamBuffer->mMatrices[rotationSlot1].mUnk_0e = rotationMatrix[1] >> 4;
    oamBuffer->mMatrices[rotationSlot1].mUnk_16 = rotationMatrix[2] >> 4;
    oamBuffer->mMatrices[rotationSlot1].mUnk_1e = rotationMatrix[3] >> 4;
}

BOOL CreateRaceHudSubScreenCarCells(void) {
    u16 kinds[3] = {MAP_OBJECT_KIND_CAR_A, MAP_OBJECT_KIND_BUS_A, MAP_OBJECT_KIND_TRUCK_A};
    u16 i;
    u16 kind;

    for (i = 0; i < 3; i++) {
        kind = kinds[i];
        if (FindMapObjectKindDrawList0(kind) != NULL) {
            return CreateRaceHudSubScreenCells(&gRaceHudSubScreenCarCells, kind);
        }
    }
    return FALSE;
}

void ClearRaceHudSubScreenCarCells(void) {
    ClearRaceHudSubScreenCells(&gRaceHudSubScreenCarCells);
}

void UpdateRaceHudSubScreenCarCells(void) {
    s32 i;
    s32 cellCount;
    Unk020e1e98 *object;
    Vec3 *position;
    u32 a;
    u16 kind;
    u16 angle;

    cellCount = 0;
    a = GetRaceHudSubScreenScale();
    for (i = 0; i < gRaceHudSubScreenCarCells->mObjectCount; i++) {
        object = (Unk020e1e98 *) gRaceHudSubScreenCarCells->mObjects[i];
        position = &object->mUnk_000.mPos;
        if (ComputeRaceHudSubScreenPosition(&object->mUnk_000.mPos,
                                            &gRaceHudSubScreenCarCells->mCells[cellCount].mDrawPos, a, 1, 1) != FALSE) {
            kind = object->mUnk_000.mKind;
            angle = object->mUnk_000.mAngle;
            switch (kind) {
                case MAP_OBJECT_KIND_CAR_A:
                    gRaceHudSubScreenCarCells->mCells[cellCount].mCell = GetRaceSNcerEntry(object->mUnk_130 + 0x95);
                    break;
                case MAP_OBJECT_KIND_BUS_A:
                    gRaceHudSubScreenCarCells->mCells[cellCount].mCell = GetRaceSNcerEntry(0x93);
                    break;
                case MAP_OBJECT_KIND_TRUCK_A:
                    gRaceHudSubScreenCarCells->mCells[cellCount].mCell = GetRaceSNcerEntry(0x94);
                    break;
            }
            gRaceHudSubScreenCarCells->mCells[cellCount].mUnk_0c =
                IsPositionOutsideBox((Vec3 *) &position) != 0 ? 2 : 3;
            gRaceHudSubScreenCarCells->mCells[cellCount].mUnk_10 = angle;
            cellCount++;
        }
    }
    gRaceHudSubScreenCarCells->mCellCount = cellCount;
}

void DrawRaceHudSubScreenCarCells(RaceHudOamBuffer *oamBuffer) {
    DrawRaceHudSubScreenCells(oamBuffer, gRaceHudSubScreenCarCells, 1);
}

s32 CreateRaceHudSubScreenKoopaBlockCells(void) {
    return CreateRaceHudSubScreenCells(&gRaceHudSubScreenKoopaBlockCells, MAP_OBJECT_KIND_KOOPA_BLOCK);
}

void ClearRaceHudSubScreenKoopaBlockCells(void) {
    ClearRaceHudSubScreenCells(&gRaceHudSubScreenKoopaBlockCells);
}

void UpdateRaceHudSubScreenKoopaBlockCells(void) {
    s32 i;
    s32 cellCount;
    u32 a;

    cellCount = 0;
    a = GetRaceHudSubScreenScale();
    for (i = 0; i < gRaceHudSubScreenKoopaBlockCells->mObjectCount; i++) {
        if (ComputeRaceHudSubScreenPosition(&gRaceHudSubScreenKoopaBlockCells->mObjects[i]->mPos,
                                            &gRaceHudSubScreenKoopaBlockCells->mCells[cellCount].mDrawPos, a, 1,
                                            0) != FALSE) {
            gRaceHudSubScreenKoopaBlockCells->mCells[cellCount].mCell = GetRaceSNcerEntry(0x25);
            gRaceHudSubScreenKoopaBlockCells->mCells[cellCount].mUnk_0c = 2;
            cellCount++;
        }
    }
    gRaceHudSubScreenKoopaBlockCells->mCellCount = cellCount;
}

void DrawRaceHudSubScreenKoopaBlockCells(RaceHudOamBuffer *oamBuffer) {
    DrawRaceHudSubScreenCells(oamBuffer, gRaceHudSubScreenKoopaBlockCells, 0);
}

s32 CreateRaceHudSubScreenChoropuCells(void) {
    return CreateRaceHudSubScreenCells(&gRaceHudSubScreenChoropuCells, MAP_OBJECT_KIND_CHOROPU);
}

void ClearRaceHudSubScreenChoropuCells(void) {
    ClearRaceHudSubScreenCells(&gRaceHudSubScreenChoropuCells);
}

void UpdateRaceHudSubScreenChoropuCells(void) {
    s32 i;
    s32 cellCount;
    Unk0217b498_00 *object;
    u32 a;
    s32 height;
    s32 isPositiveHeight;

    cellCount = 0;
    a = GetRaceHudSubScreenScale();
    for (i = 0; i < gRaceHudSubScreenChoropuCells->mObjectCount; i++) {
        if (IsRaceHudSubScreenPairNearCenter(&gRaceHudSubScreenChoropuCells->mUnk_0c[i]) != FALSE) {
            object = gRaceHudSubScreenChoropuCells->mObjects[i];
            if (ComputeRaceHudSubScreenPosition(
                    &object->mPos, &gRaceHudSubScreenChoropuCells->mCells[cellCount].mDrawPos, a, 0, 0) != FALSE) {
                height = object->mPos.y - object->mUnk_a8;
                if (height >= -0x9000) {
                    isPositiveHeight = height > 0 ? 1 : 0;
                    gRaceHudSubScreenChoropuCells->mCells[cellCount].mCell =
                        GetRaceSNcerEntry(isPositiveHeight != 0 ? 0xa7 : 0xa8);
                    gRaceHudSubScreenChoropuCells->mCells[cellCount].mUnk_0c = isPositiveHeight != 0 ? 1 : 2;
                    gRaceHudSubScreenChoropuCells->mCells[cellCount + 1].mDrawPos =
                        gRaceHudSubScreenChoropuCells->mCells[cellCount].mDrawPos;
                    gRaceHudSubScreenChoropuCells->mCells[cellCount + 1].mCell = GetRaceSNcerEntry(0xa9);
                    gRaceHudSubScreenChoropuCells->mCells[cellCount + 1].mUnk_0c = 2;
                    cellCount += 2;
                    gRaceHudSubScreenChoropuCells->mCells[cellCount - 2].mDrawPos.mUnk_04 -= height >> 14;
                } else {
                    gRaceHudSubScreenChoropuCells->mCells[cellCount].mCell = GetRaceSNcerEntry(0xa9);
                    gRaceHudSubScreenChoropuCells->mCells[cellCount].mUnk_0c = 2;
                    cellCount++;
                }
            }
        }
    }
    gRaceHudSubScreenChoropuCells->mCellCount = cellCount;
}

void DrawRaceHudSubScreenChoropuCells(RaceHudOamBuffer *oamBuffer) {
    DrawRaceHudSubScreenCells(oamBuffer, gRaceHudSubScreenChoropuCells, 0);
}

s32 CreateRaceHudSubScreenPukupukuCells(void) {
    return CreateRaceHudSubScreenCells(&gRaceHudSubScreenPukupukuCells, MAP_OBJECT_KIND_PUKUPUKU);
}

void ClearRaceHudSubScreenPukupukuCells(void) {
    ClearRaceHudSubScreenCells(&gRaceHudSubScreenPukupukuCells);
}

void UpdateRaceHudSubScreenPukupukuCells(void) {
    s32 i;
    s32 cellCount;
    Unk0217b498_00 *object;
    u32 a;

    cellCount = 0;
    a = GetRaceHudSubScreenScale();
    for (i = 0; i < gRaceHudSubScreenPukupukuCells->mObjectCount; i++) {
        if (IsRaceHudSubScreenPairNearCenter(&gRaceHudSubScreenPukupukuCells->mUnk_0c[i]) != FALSE) {
            object = gRaceHudSubScreenPukupukuCells->mObjects[i];
            if ((object->mFlags & 2) == 0) {
                if (ComputeRaceHudSubScreenPosition(
                        &object->mPos, &gRaceHudSubScreenPukupukuCells->mCells[cellCount].mDrawPos, a, 0, 0) != FALSE) {
                    gRaceHudSubScreenPukupukuCells->mCells[cellCount].mCell = GetRaceSNcerEntry(0x89);
                    gRaceHudSubScreenPukupukuCells->mCells[cellCount].mUnk_0c = 2;
                    cellCount++;
                }
            }
        }
    }
    gRaceHudSubScreenPukupukuCells->mCellCount = cellCount;
}

void DrawRaceHudSubScreenPukupukuCells(RaceHudOamBuffer *oamBuffer) {
    DrawRaceHudSubScreenCells(oamBuffer, gRaceHudSubScreenPukupukuCells, 0);
}

s32 CreateRaceHudSubScreenMoveTreeCells(void) {
    return CreateRaceHudSubScreenCells(&gRaceHudSubScreenMoveTreeCells, MAP_OBJECT_KIND_MOVE_TREE);
}

void ClearRaceHudSubScreenMoveTreeCells(void) {
    ClearRaceHudSubScreenCells(&gRaceHudSubScreenMoveTreeCells);
}

void UpdateRaceHudSubScreenMoveTreeCells(void) {
    s32 i;
    s32 cellCount;
    u32 a;

    cellCount = 0;
    a = GetRaceHudSubScreenScale();
    for (i = 0; i < gRaceHudSubScreenMoveTreeCells->mObjectCount; i++) {
        if (ComputeRaceHudSubScreenPosition(&gRaceHudSubScreenMoveTreeCells->mObjects[i]->mPos,
                                            &gRaceHudSubScreenMoveTreeCells->mCells[cellCount].mDrawPos, a, 1,
                                            1) != FALSE) {
            gRaceHudSubScreenMoveTreeCells->mCells[cellCount].mCell = GetRaceSNcerEntry(0x8b);
            gRaceHudSubScreenMoveTreeCells->mCells[cellCount].mUnk_0c = 2;
            cellCount++;
        }
    }
    gRaceHudSubScreenMoveTreeCells->mCellCount = cellCount;
}

void DrawRaceHudSubScreenMoveTreeCells(RaceHudOamBuffer *oamBuffer) {
    DrawRaceHudSubScreenCells(oamBuffer, gRaceHudSubScreenMoveTreeCells, 0);
}

s32 CreateRaceHudSubScreenSmanCells(void) {
    return CreateRaceHudSubScreenCells(&gRaceHudSubScreenSmanCells, MAP_OBJECT_KIND_SMAN);
}

void ClearRaceHudSubScreenSmanCells(void) {
    ClearRaceHudSubScreenCells(&gRaceHudSubScreenSmanCells);
}

void UpdateRaceHudSubScreenSmanCells(void) {
    s32 i;
    s32 cellCount;
    Unk0217b498_00 *object;
    u32 a;

    cellCount = 0;
    a = GetRaceHudSubScreenScale();
    for (i = 0; i < gRaceHudSubScreenSmanCells->mObjectCount; i++) {
        if (IsRaceHudSubScreenPairNearCenter(&gRaceHudSubScreenSmanCells->mUnk_0c[i]) != FALSE) {
            object = gRaceHudSubScreenSmanCells->mObjects[i];
            if ((object->mFlags & 1) == 0) {
                if (ComputeRaceHudSubScreenPosition(
                        &object->mPos, &gRaceHudSubScreenSmanCells->mCells[cellCount].mDrawPos, a, 0, 0) != FALSE) {
                    gRaceHudSubScreenSmanCells->mCells[cellCount].mCell = GetRaceSNcerEntry(0x98);
                    gRaceHudSubScreenSmanCells->mCells[cellCount].mUnk_0c = 2;
                    cellCount++;
                }
            }
        }
    }
    gRaceHudSubScreenSmanCells->mCellCount = cellCount;
}

void DrawRaceHudSubScreenSmanCells(RaceHudOamBuffer *oamBuffer) {
    DrawRaceHudSubScreenCells(oamBuffer, gRaceHudSubScreenSmanCells, 0);
}

s32 CreateRaceHudSubScreenDossunCells(void) {
    return CreateRaceHudSubScreenCells(&gRaceHudSubScreenDossunCells, MAP_OBJECT_KIND_DOSSUN);
}

void ClearRaceHudSubScreenDossunCells(void) {
    ClearRaceHudSubScreenCells(&gRaceHudSubScreenDossunCells);
}

void UpdateRaceHudSubScreenDossunCells(void) {
    s32 i;
    s32 cellCount;
    Unk0217b498_00 *object;
    u32 a;
    s32 offset;

    cellCount = 0;
    a = GetRaceHudSubScreenScale();
    for (i = 0; i < gRaceHudSubScreenDossunCells->mObjectCount; i++) {
        if (IsRaceHudSubScreenPairNearCenter(&gRaceHudSubScreenDossunCells->mUnk_0c[i]) != FALSE) {
            object = gRaceHudSubScreenDossunCells->mObjects[i];
            if (ComputeRaceHudSubScreenPosition(
                    &object->mPos, &gRaceHudSubScreenDossunCells->mCells[cellCount].mDrawPos, a, 0, 0) != FALSE) {
                gRaceHudSubScreenDossunCells->mCells[cellCount].mCell = GetRaceSNcerEntry(0xaf);
                gRaceHudSubScreenDossunCells->mCells[cellCount].mUnk_0c = 1;
                gRaceHudSubScreenDossunCells->mCells[cellCount + 1].mDrawPos =
                    gRaceHudSubScreenDossunCells->mCells[(u32) cellCount].mDrawPos;
                gRaceHudSubScreenDossunCells->mCells[cellCount + 1].mCell = GetRaceSNcerEntry(0xb0);
                gRaceHudSubScreenDossunCells->mCells[cellCount + 1].mUnk_0c = 2;
                cellCount += 2;
                offset = func_020db4c4((Dossun *) object) * 16 >> 12;
                gRaceHudSubScreenDossunCells->mCells[cellCount - 2].mDrawPos.mUnk_04 -= offset;
            }
        }
    }
    gRaceHudSubScreenDossunCells->mCellCount = cellCount;
}

void DrawRaceHudSubScreenDossunCells(RaceHudOamBuffer *oamBuffer) {
    DrawRaceHudSubScreenCells(oamBuffer, gRaceHudSubScreenDossunCells, 0);
}

BOOL CreateRaceHudSubScreenWanwanCells(void) {
    u16 kinds[2] = {0x196, 0x1a5};
    u16 i;
    u16 kind;

    for (i = 0; i < 2; i++) {
        kind = kinds[i];
        if (FindMapObjectKindDrawList0(kind) != NULL) {
            return CreateRaceHudSubScreenCells(&gRaceHudSubScreenWanwanCells, kind);
        }
    }
    return FALSE;
}

void ClearRaceHudSubScreenWanwanCells(void) {
    ClearRaceHudSubScreenCells(&gRaceHudSubScreenWanwanCells);
}

void UpdateRaceHudSubScreenWanwanCells(void) {
    s32 i;
    s32 cellCount;
    u32 a;

    cellCount = 0;
    a = GetRaceHudSubScreenScale();
    for (i = 0; i < gRaceHudSubScreenWanwanCells->mObjectCount; i++) {
        if (ComputeRaceHudSubScreenPosition(&gRaceHudSubScreenWanwanCells->mObjects[i]->mPos,
                                            &gRaceHudSubScreenWanwanCells->mCells[cellCount].mDrawPos, a, 1,
                                            0) != FALSE) {
            gRaceHudSubScreenWanwanCells->mCells[cellCount].mCell = GetRaceSNcerEntry(0xac);
            gRaceHudSubScreenWanwanCells->mCells[cellCount].mUnk_0c = 1;
            cellCount++;
        }
    }
    gRaceHudSubScreenWanwanCells->mCellCount = cellCount;
}

void DrawRaceHudSubScreenWanwanCells(RaceHudOamBuffer *oamBuffer) {
    DrawRaceHudSubScreenCells(oamBuffer, gRaceHudSubScreenWanwanCells, 0);
}

s32 CreateRaceHudSubScreenEarthenPipeCells(void) {
    return CreateRaceHudSubScreenCells(&gRaceHudSubScreenEarthenPipeCells, MAP_OBJECT_KIND_EARTHEN_PIPE);
}

void ClearRaceHudSubScreenEarthenPipeCells(void) {
    ClearRaceHudSubScreenCells(&gRaceHudSubScreenEarthenPipeCells);
}

void UpdateRaceHudSubScreenEarthenPipeCells(void) {
    s32 i;
    s32 cellCount;
    Unk0217b498_00 *object;
    Vec3 *position;
    u32 a;

    cellCount = 0;
    a = GetRaceHudSubScreenScale();
    for (i = 0; i < gRaceHudSubScreenEarthenPipeCells->mObjectCount; i++) {
        if (IsRaceHudSubScreenPairNearCenter(&gRaceHudSubScreenEarthenPipeCells->mUnk_0c[i]) != FALSE) {
            object = gRaceHudSubScreenEarthenPipeCells->mObjects[i];
            if ((object->mFlags & 1) == 0) {
                position = &object->mPos;
                if (ComputeRaceHudSubScreenPosition(
                        position, &gRaceHudSubScreenEarthenPipeCells->mCells[cellCount].mDrawPos, a, 0, 0) != FALSE) {
                    gRaceHudSubScreenEarthenPipeCells->mCells[cellCount].mCell = GetRaceSNcerEntry(0x8c);
                    gRaceHudSubScreenEarthenPipeCells->mCells[cellCount].mUnk_0c =
                        IsPositionOutsideBox(position) != 0 ? 2 : 3;
                    cellCount++;
                }
            }
        }
    }
    gRaceHudSubScreenEarthenPipeCells->mCellCount = cellCount;
}

void DrawRaceHudSubScreenEarthenPipeCells(RaceHudOamBuffer *oamBuffer) {
    DrawRaceHudSubScreenCells(oamBuffer, gRaceHudSubScreenEarthenPipeCells, 0);
}

s32 CreateRaceHudSubScreenItemBoxCells(void) {
    u16 kinds[2] = {MAP_OBJECT_KIND_ITEM_BOX, 0xc9};
    u16 i;
    u16 kind;
    s32 created;
    s32 highest;
    s32 j;

    for (i = 0; i < 2; i++) {
        kind = kinds[i];
        if (FindMapObjectKindDrawList0(kind) != NULL) {
            created = CreateRaceHudSubScreenCells(&gRaceHudSubScreenItemBoxCells, kind);
            highest = 0;
            for (j = 0; j < gRaceHudSubScreenItemBoxCells->mObjectCount; j++) {
                s32 v = func_020de9f8((ItemBox *) gRaceHudSubScreenItemBoxCells->mObjects[j]);
                if (v > highest) {
                    highest = v;
                }
            }
            if (highest < 0x3e8000) {
                data_0217b3f8 = 1;
            } else {
                data_0217b3f8 = 0;
            }
            return created;
        }
    }
    return 0;
}
