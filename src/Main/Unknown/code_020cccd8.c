#include "Main/Unknown/code_020cccd8.h"

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
#include "Main/Unknown/code_020c0d9c.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020cce10.h"
#include "Main/Unknown/code_020c0ba8.h"
#include "Main/Unknown/code_020ade08.h"
#include "code_020222ec.h"
#include "Main/Unknown/code_020ae000.h"
#include "Main/Unknown/code_02095f30.h"
#include "Main/Unknown/code_02095f38.h"
#include "Main/Unknown/code_02095000.h"
#include "Main/Unknown/code_020931ac.h"
#include "Main/Unknown/code_02092194.h"
#include "Main/Unknown/code_021000d0.h"

void ClearRaceHudSubScreenRainStarCells(void) {
    ClearRaceHudSubScreenCells(&gRaceHudSubScreenRainStarCells);
}

void UpdateRaceHudSubScreenRainStarCells(void) {
    s32 i;
    s32 cellCount;
    u32 n;
    Unk0217b498_00 *object;
    Vec3 *position;

    cellCount = 0;
    n = func_020c0db0();
    for (i = 0; i < gRaceHudSubScreenRainStarCells->mObjectCount; i++) {
        object = gRaceHudSubScreenRainStarCells->mObjects[i];
        position = &object->mPos;
        if (ComputeRaceHudSubScreenPosition(position, &gRaceHudSubScreenRainStarCells->mCells[cellCount].mDrawPos, n, 1,
                                            1) != FALSE) {
            gRaceHudSubScreenRainStarCells->mCells[cellCount].mCell = GetRaceSNcerEntry(0xb3);
            gRaceHudSubScreenRainStarCells->mCells[cellCount].mUnk_0c = IsPositionOutsideBox(position) != 0 ? 2 : 3;
            gRaceHudSubScreenRainStarCells->mCells[cellCount].mUnk_0e = 0;
            gRaceHudSubScreenRainStarCells->mCells[cellCount].mUnk_10 = object->mAngle;
            cellCount++;
        }
    }
    gRaceHudSubScreenRainStarCells->mCellCount = cellCount;
}

void DrawRaceHudSubScreenRainStarCells(Unk020c06c4 *oamBuffer) {
    DrawRaceHudSubScreenCells(oamBuffer, gRaceHudSubScreenRainStarCells, 1);
}

s32 CreateRaceHudSubScreenBasabasaCells(void) {
    return CreateRaceHudSubScreenCells(&gRaceHudSubScreenBasabasaCells, MAP_OBJECT_KIND_BASABASA);
}

void ClearRaceHudSubScreenBasabasaCells(void) {
    ClearRaceHudSubScreenCells(&gRaceHudSubScreenBasabasaCells);
}

void UpdateRaceHudSubScreenBasabasaCells(void) {
    s32 i;
    s32 cellCount;
    u32 n;
    u32 m;
    Unk0217b498_00 *object;
    Vec3 *position;
    void *cell;

    cellCount = 0;
    n = func_020c0db0();
    for (i = 0; i < gRaceHudSubScreenBasabasaCells->mObjectCount; i++) {
        object = gRaceHudSubScreenBasabasaCells->mObjects[i];
        if ((object->mFlags & 1) == 0) {
            m = func_02092194(object);
            if (m != 0) {
                position = &object->mPos;
                if (ComputeRaceHudSubScreenPosition(
                        position, &gRaceHudSubScreenBasabasaCells->mCells[cellCount].mDrawPos, n, 1, 1) != FALSE) {
                    if (m == 2) {
                        cell = GetRaceSNcerEntry(0xb5);
                    } else {
                        cell = GetRaceSNcerEntry(0xb4);
                    }
                    gRaceHudSubScreenBasabasaCells->mCells[cellCount].mCell = cell;
                    gRaceHudSubScreenBasabasaCells->mCells[cellCount].mUnk_0c =
                        IsPositionOutsideBox(position) != 0 ? 2 : 3;
                    cellCount++;
                }
            }
        }
    }
    gRaceHudSubScreenBasabasaCells->mCellCount = cellCount;
}

void DrawRaceHudSubScreenBasabasaCells(Unk020c06c4 *oamBuffer) {
    DrawRaceHudSubScreenCells(oamBuffer, gRaceHudSubScreenBasabasaCells, 0);
}

s32 CreateRaceHudSubScreenMkdEfBubbleCells(void) {
    return CreateRaceHudSubScreenCells(&gRaceHudSubScreenMkdEfBubbleCells, MAP_OBJECT_KIND_MKD_EF_BUBBLE);
}

void ClearRaceHudSubScreenMkdEfBubbleCells(void) {
    ClearRaceHudSubScreenCells(&gRaceHudSubScreenMkdEfBubbleCells);
}

void UpdateRaceHudSubScreenMkdEfBubbleCells(void) {
    s32 i;
    s32 cellCount;
    u32 n;
    Unk0217b498_00 *object;
    s32 d;
    Vec3 *position;

    cellCount = 0;
    n = func_020c0db0();
    for (i = 0; i < gRaceHudSubScreenMkdEfBubbleCells->mObjectCount; i++) {
        if (IsRaceHudSubScreenPairNearCenter(&gRaceHudSubScreenMkdEfBubbleCells->mUnk_0c[i]) != FALSE) {
            object = gRaceHudSubScreenMkdEfBubbleCells->mObjects[i];
            d = object->mPos.y - object->mUnk_ac;
            if (d >= 0) {
                position = &object->mPos;
                if (ComputeRaceHudSubScreenPosition(
                        position, &gRaceHudSubScreenMkdEfBubbleCells->mCells[cellCount].mDrawPos, n, 0, 1) != FALSE) {
                    gRaceHudSubScreenMkdEfBubbleCells->mCells[cellCount].mDrawPos.mUnk_04 -= d >> 14;
                    gRaceHudSubScreenMkdEfBubbleCells->mCells[cellCount].mCell = GetRaceSNcerEntry(0xb1);
                    gRaceHudSubScreenMkdEfBubbleCells->mCells[cellCount].mUnk_0c =
                        IsPositionOutsideBox(position) != 0 ? 2 : 3;
                    cellCount++;
                }
            }
        }
    }
    gRaceHudSubScreenMkdEfBubbleCells->mCellCount = cellCount;
}

void DrawRaceHudSubScreenMkdEfBubbleCells(Unk020c06c4 *oamBuffer) {
    DrawRaceHudSubScreenCells(oamBuffer, gRaceHudSubScreenMkdEfBubbleCells, 0);
}

s32 CreateRaceHudSubScreenBoundCells(void) {
    return CreateRaceHudSubScreenCells(&gRaceHudSubScreenBoundCells, MAP_OBJECT_KIND_BOUND);
}

void ClearRaceHudSubScreenBoundCells(void) {
    ClearRaceHudSubScreenCells(&gRaceHudSubScreenBoundCells);
}

void UpdateRaceHudSubScreenBoundCells(void) {
    s32 i;
    s32 cellCount;
    u32 n;
    Unk0217b498_00 *object;
    Vec3 *position;

    cellCount = 0;
    n = func_020c0db0();
    for (i = 0; i < gRaceHudSubScreenBoundCells->mObjectCount; i++) {
        object = gRaceHudSubScreenBoundCells->mObjects[i];
        position = &object->mPos;
        if (ComputeRaceHudSubScreenPosition(position, &gRaceHudSubScreenBoundCells->mCells[cellCount].mDrawPos, n, 1,
                                            1) != FALSE) {
            gRaceHudSubScreenBoundCells->mCells[cellCount].mCell = GetRaceSNcerEntry(0x91);
            gRaceHudSubScreenBoundCells->mCells[cellCount].mUnk_0c = IsPositionOutsideBox(position) != 0 ? 2 : 3;
            gRaceHudSubScreenBoundCells->mCells[cellCount].mUnk_10 = object->mAngle;
            gRaceHudSubScreenBoundCells->mUnk_0c[cellCount].mUnk_00 = object->mScaleX / 6;
            cellCount++;
        }
    }
    gRaceHudSubScreenBoundCells->mCellCount = cellCount;
}

void DrawRaceHudSubScreenBoundCells(Unk020c06c4 *oamBuffer) {
    DrawRaceHudSubScreenCellsScaled(oamBuffer, gRaceHudSubScreenBoundCells, 1);
}

s32 CreateRaceHudSubScreenMkdEfBurnerCells(void) {
    return CreateRaceHudSubScreenCells(&gRaceHudSubScreenMkdEfBurnerCells, MAP_OBJECT_KIND_MKD_EF_BURNER);
}

void ClearRaceHudSubScreenMkdEfBurnerCells(void) {
    ClearRaceHudSubScreenCells(&gRaceHudSubScreenMkdEfBurnerCells);
}

void UpdateRaceHudSubScreenMkdEfBurnerCells(void) {
    s32 i;
    s32 cellCount;
    s32 inFirstHalf;
    u32 n;
    Unk0217b498_00 *object;
    Vec3 *position;

    cellCount = 0;
    n = func_020c0db0();
    gRaceHudSubScreenMkdEfBurnerCells->mUnk_0c[0].mUnk_04++;
    if (gRaceHudSubScreenMkdEfBurnerCells->mUnk_0c[0].mUnk_04 < 0 ||
        gRaceHudSubScreenMkdEfBurnerCells->mUnk_0c[0].mUnk_04 >= 8) {
        gRaceHudSubScreenMkdEfBurnerCells->mUnk_0c[0].mUnk_04 = 0;
    }
    inFirstHalf = gRaceHudSubScreenMkdEfBurnerCells->mUnk_0c[0].mUnk_04 < 4 ? 1 : 0;
    for (i = 0; i < gRaceHudSubScreenMkdEfBurnerCells->mObjectCount; i++) {
        object = gRaceHudSubScreenMkdEfBurnerCells->mObjects[i];
        if ((object->mFlags & 1) == 0 && func_020931ac(object) != 0) {
            position = &object->mPos;
            if (ComputeRaceHudSubScreenPosition(
                    position, &gRaceHudSubScreenMkdEfBurnerCells->mCells[cellCount].mDrawPos, n, 0, 0) != FALSE) {
                gRaceHudSubScreenMkdEfBurnerCells->mCells[cellCount].mCell =
                    GetRaceSNcerEntry(gRaceSetup->mCourseId == COURSE_ID_AIRSHIP ? 0xae : 0xb2);
                gRaceHudSubScreenMkdEfBurnerCells->mCells[cellCount].mUnk_0c =
                    IsPositionOutsideBox(position) != 0 ? 2 : 3;
                gRaceHudSubScreenMkdEfBurnerCells->mUnk_0c[cellCount].mUnk_00 = inFirstHalf != 0 ? 0x1000 : 0xccd;
                cellCount++;
            }
        }
    }
    gRaceHudSubScreenMkdEfBurnerCells->mCellCount = cellCount;
}

void DrawRaceHudSubScreenMkdEfBurnerCells(Unk020c06c4 *oamBuffer) {
    DrawRaceHudSubScreenCellsScaled(oamBuffer, gRaceHudSubScreenMkdEfBurnerCells, 0);
}

s32 func_020cdf18(void) {
    return CreateRaceHudSubScreenCells(&data_0217b46c, 0x1ae);
}

void func_020cdf04(void) {
    ClearRaceHudSubScreenCells(&data_0217b46c);
}

void func_020cde18(void) {
    s32 i;
    s32 cellCount;
    u32 n;
    Unk0217b498_00 *object;
    Vec3 *position;

    cellCount = 0;
    n = func_020c0db0();
    for (i = 0; i < data_0217b46c->mObjectCount; i++) {
        object = data_0217b46c->mObjects[i];
        if ((object->mFlags & 1) == 0) {
            position = &object->mPos;
            if (ComputeRaceHudSubScreenPosition(position, &data_0217b46c->mCells[cellCount].mDrawPos, n, 1, 1) !=
                FALSE) {
                data_0217b46c->mCells[cellCount].mCell = GetRaceSNcerEntry(0x8d);
                data_0217b46c->mCells[cellCount].mUnk_0c = IsPositionOutsideBox(position) != 0 ? 2 : 3;
                cellCount++;
            }
        }
    }
    data_0217b46c->mCellCount = cellCount;
}

void func_020cddfc(Unk020c06c4 *oamBuffer) {
    DrawRaceHudSubScreenCells(oamBuffer, data_0217b46c, 0);
}

s32 CreateRaceHudSubScreenIronBallCells(void) {
    return CreateRaceHudSubScreenCells(&gRaceHudSubScreenIronBallCells, MAP_OBJECT_KIND_IRON_BALL);
}

void ClearRaceHudSubScreenIronBallCells(void) {
    ClearRaceHudSubScreenCells(&gRaceHudSubScreenIronBallCells);
}

void UpdateRaceHudSubScreenIronBallCells(void) {
    s32 i;
    s32 cellCount;
    u32 n;
    Unk0217b498_00 *object;
    Vec3 *position;

    cellCount = 0;
    n = func_020c0db0();
    for (i = 0; i < gRaceHudSubScreenIronBallCells->mObjectCount; i++) {
        object = gRaceHudSubScreenIronBallCells->mObjects[i];
        if ((object->mFlags & 2) == 0) {
            position = &object->mPos;
            if (ComputeRaceHudSubScreenPosition(position, &gRaceHudSubScreenIronBallCells->mCells[cellCount].mDrawPos,
                                                n, 1, 1) != FALSE) {
                gRaceHudSubScreenIronBallCells->mCells[cellCount].mCell = GetRaceSNcerEntry(0x92);
                gRaceHudSubScreenIronBallCells->mCells[cellCount].mUnk_0c = IsPositionOutsideBox(position) != 0 ? 2 : 3;
                gRaceHudSubScreenIronBallCells->mCells[cellCount].mUnk_0e = object->mFlags & 0x20;
                cellCount++;
            }
        }
    }
    gRaceHudSubScreenIronBallCells->mCellCount = cellCount;
}

void DrawRaceHudSubScreenIronBallCells(Unk020c06c4 *oamBuffer) {
    DrawRaceHudSubScreenCells(oamBuffer, gRaceHudSubScreenIronBallCells, 0);
}

s32 CreateRaceHudSubScreenKuriboCells(void) {
    return CreateRaceHudSubScreenCells(&gRaceHudSubScreenKuriboCells, MAP_OBJECT_KIND_KURIBO);
}

void ClearRaceHudSubScreenKuriboCells(void) {
    ClearRaceHudSubScreenCells(&gRaceHudSubScreenKuriboCells);
}

void UpdateRaceHudSubScreenKuriboCells(void) {
    s32 i;
    s32 cellCount;
    u32 n;
    Unk0217b498_00 *object;
    Vec3 *position;

    cellCount = 0;
    n = func_020c0db0();
    for (i = 0; i < gRaceHudSubScreenKuriboCells->mObjectCount; i++) {
        object = gRaceHudSubScreenKuriboCells->mObjects[i];
        position = &object->mPos;
        if ((object->mFlags & 2) == 0) {
            if (ComputeRaceHudSubScreenPosition(position, &gRaceHudSubScreenKuriboCells->mCells[cellCount].mDrawPos, n,
                                                0, 1) != FALSE) {
                gRaceHudSubScreenKuriboCells->mCells[cellCount].mCell = GetRaceSNcerEntry(0xa3);
                gRaceHudSubScreenKuriboCells->mCells[cellCount].mUnk_0c = IsPositionOutsideBox(position) != 0 ? 2 : 3;
                cellCount++;
            }
        }
    }
    gRaceHudSubScreenKuriboCells->mCellCount = cellCount;
}

void DrawRaceHudSubScreenKuriboCells(Unk020c06c4 *oamBuffer) {
    DrawRaceHudSubScreenCells(oamBuffer, gRaceHudSubScreenKuriboCells, 0);
}

s32 CreateRaceHudSubScreenObPakkunSfCells(void) {
    return CreateRaceHudSubScreenCells(&gRaceHudSubScreenObPakkunSfCells, MAP_OBJECT_KIND_OB_PAKKUN_SF);
}

void ClearRaceHudSubScreenObPakkunSfCells(void) {
    ClearRaceHudSubScreenCells(&gRaceHudSubScreenObPakkunSfCells);
}

void UpdateRaceHudSubScreenObPakkunSfCells(void) {
    s32 i;
    s32 cellCount;
    u32 n;
    Unk0217b498_00 *object;
    Vec3 *position;

    cellCount = 0;
    n = func_020c0db0();
    for (i = 0; i < gRaceHudSubScreenObPakkunSfCells->mObjectCount; i++) {
        if (IsRaceHudSubScreenPairNearCenter(&gRaceHudSubScreenObPakkunSfCells->mUnk_0c[i]) != FALSE) {
            object = gRaceHudSubScreenObPakkunSfCells->mObjects[i];
            if ((object->mFlags & 1) == 0) {
                position = &object->mPos;
                if (ComputeRaceHudSubScreenPosition(
                        position, &gRaceHudSubScreenObPakkunSfCells->mCells[cellCount].mDrawPos, n, 0, 0) != FALSE) {
                    gRaceHudSubScreenObPakkunSfCells->mCells[cellCount].mCell =
                        GetRaceSNcerEntry(((object->mUnk_b8 & 0x10) >> 4) != 0 ? 0xa2 : 0xa1);
                    gRaceHudSubScreenObPakkunSfCells->mCells[cellCount].mUnk_0c =
                        IsPositionOutsideBox(position) != 0 ? 2 : 3;
                    cellCount++;
                }
            }
        }
    }
    gRaceHudSubScreenObPakkunSfCells->mCellCount = cellCount;
}

void DrawRaceHudSubScreenObPakkunSfCells(Unk020c06c4 *oamBuffer) {
    DrawRaceHudSubScreenCells(oamBuffer, gRaceHudSubScreenObPakkunSfCells, 0);
}

s32 CreateRaceHudSubScreenCoverPooHoleCells(void) {
    return CreateRaceHudSubScreenCells(&gRaceHudSubScreenCoverPooHoleCells, MAP_OBJECT_KIND_COVER_POO_HOLE);
}

void ClearRaceHudSubScreenCoverPooHoleCells(void) {
    ClearRaceHudSubScreenCells(&gRaceHudSubScreenCoverPooHoleCells);
}

void UpdateRaceHudSubScreenCoverPooHoleCells(void) {
    s32 i;
    s32 cellCount;
    u32 n;
    Unk0217b498_00 *object;
    Vec3 *position;

    cellCount = 0;
    n = func_020c0db0();
    for (i = 0; i < gRaceHudSubScreenCoverPooHoleCells->mObjectCount; i++) {
        if (IsRaceHudSubScreenPairNearCenter(&gRaceHudSubScreenCoverPooHoleCells->mUnk_0c[i]) != FALSE) {
            object = gRaceHudSubScreenCoverPooHoleCells->mObjects[i];
            if ((object->mFlags & 1) == 0) {
                position = &object->mPos;
                if (ComputeRaceHudSubScreenPosition(
                        position, &gRaceHudSubScreenCoverPooHoleCells->mCells[cellCount].mDrawPos, n, 0, 0) != FALSE) {
                    gRaceHudSubScreenCoverPooHoleCells->mCells[cellCount].mDrawPos.mUnk_04 -=
                        func_02095f30(object) >> 14;
                    gRaceHudSubScreenCoverPooHoleCells->mCells[cellCount].mCell =
                        GetRaceSNcerEntry(func_02095f38(object) != FALSE ? 0xab : 0xaa);
                    gRaceHudSubScreenCoverPooHoleCells->mCells[cellCount].mUnk_0c =
                        IsPositionOutsideBox(position) != 0 ? 2 : 3;
                    cellCount++;
                }
            }
        }
    }
    gRaceHudSubScreenCoverPooHoleCells->mCellCount = cellCount;
}

void DrawRaceHudSubScreenCoverPooHoleCells(Unk020c06c4 *oamBuffer) {
    DrawRaceHudSubScreenCells(oamBuffer, gRaceHudSubScreenCoverPooHoleCells, 0);
}

s32 CreateRaceHudSubScreenRock2Cells(void) {
    return CreateRaceHudSubScreenCells(&gRaceHudSubScreenRock2Cells, MAP_OBJECT_KIND_ROCK2);
}

void ClearRaceHudSubScreenRock2Cells(void) {
    ClearRaceHudSubScreenCells(&gRaceHudSubScreenRock2Cells);
}

void UpdateRaceHudSubScreenRock2Cells(void) {
    s32 i;
    s32 cellCount;
    u32 n;
    Unk0217b498_00 *object;
    Vec3 *position;

    cellCount = 0;
    n = func_020c0db0();
    for (i = 0; i < gRaceHudSubScreenRock2Cells->mObjectCount; i++) {
        object = gRaceHudSubScreenRock2Cells->mObjects[i];
        if ((object->mFlags & 2) == 0) {
            position = &object->mPos;
            if (ComputeRaceHudSubScreenPosition(position, &gRaceHudSubScreenRock2Cells->mCells[cellCount].mDrawPos, n,
                                                1, 1) != FALSE) {
                gRaceHudSubScreenRock2Cells->mCells[cellCount].mCell = GetRaceSNcerEntry(0x8f);
                gRaceHudSubScreenRock2Cells->mCells[cellCount].mUnk_0c = IsPositionOutsideBox(position) != 0 ? 2 : 3;
                gRaceHudSubScreenRock2Cells->mCells[cellCount].mUnk_10 += 0x400;
                cellCount++;
            }
        }
    }
    gRaceHudSubScreenRock2Cells->mCellCount = cellCount;
}

void DrawRaceHudSubScreenRock2Cells(Unk020c06c4 *oamBuffer) {
    DrawRaceHudSubScreenCells(oamBuffer, gRaceHudSubScreenRock2Cells, 1);
}

s32 CreateRaceHudSubScreenSanboCells(void) {
    return CreateRaceHudSubScreenCells(&gRaceHudSubScreenSanboCells, MAP_OBJECT_KIND_SANBO);
}

void ClearRaceHudSubScreenSanboCells(void) {
    ClearRaceHudSubScreenCells(&gRaceHudSubScreenSanboCells);
}

void UpdateRaceHudSubScreenSanboCells(void) {
    s32 i;
    s32 cellCount;
    u32 n;
    Unk0217b498_00 *object;
    Vec3 *position;

    cellCount = 0;
    n = func_020c0db0();
    for (i = 0; i < gRaceHudSubScreenSanboCells->mObjectCount; i++) {
        if (IsRaceHudSubScreenPairNearCenter(&gRaceHudSubScreenSanboCells->mUnk_0c[i]) != FALSE) {
            object = gRaceHudSubScreenSanboCells->mObjects[i];
            if ((object->mFlags & 1) == 0) {
                position = &object->mPos;
                if (ComputeRaceHudSubScreenPosition(position, &gRaceHudSubScreenSanboCells->mCells[cellCount].mDrawPos,
                                                    n, 0, 0) != FALSE) {
                    gRaceHudSubScreenSanboCells->mCells[cellCount].mCell = GetRaceSNcerEntry(0x8e);
                    gRaceHudSubScreenSanboCells->mCells[cellCount].mUnk_0c =
                        IsPositionOutsideBox(position) != 0 ? 2 : 3;
                    cellCount++;
                }
            }
        }
    }
    gRaceHudSubScreenSanboCells->mCellCount = cellCount;
}

void DrawRaceHudSubScreenSanboCells(Unk020c06c4 *oamBuffer) {
    DrawRaceHudSubScreenCells(oamBuffer, gRaceHudSubScreenSanboCells, 0);
}

s32 CreateRaceHudSubScreenRockCells(void) {
    return CreateRaceHudSubScreenCells(&gRaceHudSubScreenRockCells, MAP_OBJECT_KIND_ROCK);
}

void ClearRaceHudSubScreenRockCells(void) {
    ClearRaceHudSubScreenCells(&gRaceHudSubScreenRockCells);
}

void UpdateRaceHudSubScreenRockCells(void) {
    s32 i;
    s32 cellCount;
    u32 n;
    Unk0217b498_00 *object;
    Vec3 *position;

    cellCount = 0;
    n = func_020c0db0();
    for (i = 0; i < gRaceHudSubScreenRockCells->mObjectCount; i++) {
        object = gRaceHudSubScreenRockCells->mObjects[i];
        if ((object->mFlags & 2) == 0) {
            position = &object->mPos;
            if (ComputeRaceHudSubScreenPosition(position, &gRaceHudSubScreenRockCells->mCells[cellCount].mDrawPos, n, 1,
                                                1) != FALSE) {
                gRaceHudSubScreenRockCells->mCells[cellCount].mCell = GetRaceSNcerEntry(0x99);
                gRaceHudSubScreenRockCells->mCells[cellCount].mUnk_0c = IsPositionOutsideBox(position) != 0 ? 2 : 3;
                gRaceHudSubScreenRockCells->mCells[cellCount].mUnk_10 += 0x400;
                cellCount++;
            }
        }
    }
    gRaceHudSubScreenRockCells->mCellCount = cellCount;
}

void DrawRaceHudSubScreenRockCells(Unk020c06c4 *oamBuffer) {
    DrawRaceHudSubScreenCells(oamBuffer, gRaceHudSubScreenRockCells, 1);
}

s32 CreateRaceHudSubScreenWoodbox1Cells(void) {
    return CreateRaceHudSubScreenCells(&gRaceHudSubScreenWoodbox1Cells, MAP_OBJECT_KIND_WOODBOX1);
}

void ClearRaceHudSubScreenWoodbox1Cells(void) {
    ClearRaceHudSubScreenCells(&gRaceHudSubScreenWoodbox1Cells);
}

void UpdateRaceHudSubScreenWoodbox1Cells(void) {
    s32 i;
    s32 cellCount;
    u32 n;
    Unk0217b498_00 *object;
    Vec3 *position;

    cellCount = 0;
    n = func_020c0db0();
    for (i = 0; i < gRaceHudSubScreenWoodbox1Cells->mObjectCount; i++) {
        if (IsRaceHudSubScreenPairNearCenter(&gRaceHudSubScreenWoodbox1Cells->mUnk_0c[i]) != FALSE) {
            object = gRaceHudSubScreenWoodbox1Cells->mObjects[i];
            if ((object->mFlags & 1) == 0) {
                position = &object->mPos;
                if (ComputeRaceHudSubScreenPosition(
                        position, &gRaceHudSubScreenWoodbox1Cells->mCells[cellCount].mDrawPos, n, 0, 0) != FALSE) {
                    gRaceHudSubScreenWoodbox1Cells->mCells[cellCount].mCell = GetRaceSNcerEntry(0x5c);
                    gRaceHudSubScreenWoodbox1Cells->mCells[cellCount].mUnk_0c =
                        IsPositionOutsideBox(position) != 0 ? 2 : 3;
                    cellCount++;
                }
            }
        }
    }
    gRaceHudSubScreenWoodbox1Cells->mCellCount = cellCount;
}

void DrawRaceHudSubScreenWoodbox1Cells(Unk020c06c4 *oamBuffer) {
    DrawRaceHudSubScreenCells(oamBuffer, gRaceHudSubScreenWoodbox1Cells, 0);
}

s32 CreateRaceHudSubScreenFlipperCells(void) {
    return CreateRaceHudSubScreenCells(&gRaceHudSubScreenFlipperCells, MAP_OBJECT_KIND_FLIPPER);
}

void ClearRaceHudSubScreenFlipperCells(void) {
    ClearRaceHudSubScreenCells(&gRaceHudSubScreenFlipperCells);
}

void UpdateRaceHudSubScreenFlipperCells(void) {
    s32 i;
    s32 cellCount;
    u32 n;
    Unk0217b498_00 *object;
    Vec3 *position;

    cellCount = 0;
    n = func_020c0db0();
    for (i = 0; i < gRaceHudSubScreenFlipperCells->mObjectCount; i++) {
        object = gRaceHudSubScreenFlipperCells->mObjects[i];
        if ((object->mFlags & 2) == 0) {
            position = &object->mPos;
            if (ComputeRaceHudSubScreenPosition(position, &gRaceHudSubScreenFlipperCells->mCells[cellCount].mDrawPos, n,
                                                1, 1) != FALSE) {
                gRaceHudSubScreenFlipperCells->mCells[cellCount].mCell = GetRaceSNcerEntry(0x90);
                gRaceHudSubScreenFlipperCells->mCells[cellCount].mUnk_0c = IsPositionOutsideBox(position) != 0 ? 2 : 3;
                gRaceHudSubScreenFlipperCells->mCells[cellCount].mUnk_0e = object->mFlags & 0x400;
                gRaceHudSubScreenFlipperCells->mCells[cellCount].mUnk_10 = object->mAngle;
                cellCount++;
            }
        }
    }
    gRaceHudSubScreenFlipperCells->mCellCount = cellCount;
}

void DrawRaceHudSubScreenFlipperCells(Unk020c06c4 *oamBuffer) {
    s32 i;
    s32 c;
    u16 d;
    u16 h;
    s32 oamIndex;
    u16 matrixIndex;
    RaceHudSubScreenCell *cell;
    s32 matrix[4];
    s32 position[2];
    s32 drawX;
    struct Unk020224e0_c *ncerEntry;
    s32 drawY;

    c = func_020c0dc4();
    d = GetSubScreenAngleAndClearScrollTimer();
    for (i = 0; i < gRaceHudSubScreenFlipperCells->mCellCount; i++) {
        h = gRaceHudSubScreenFlipperCells->mCells[i].mUnk_0c;
        if (c <= h) {
            if (gRaceHudSubScreenFlipperCells->mCells[i].mUnk_0e != 0) {
                if (gRaceSetup->mMirrorMode != 0) {
                    Matrix2x2ReflectedRotation(matrix,
                                               (u16) (d + (gRaceHudSubScreenFlipperCells->mCells[i].mUnk_10 + 0x4000)));
                } else {
                    Matrix2x2ReflectedRotation(matrix,
                                               (u16) (0x4000 - gRaceHudSubScreenFlipperCells->mCells[i].mUnk_10 - d));
                }
            } else {
                if (gRaceSetup->mMirrorMode != 0) {
                    Matrix2x2Rotation(matrix, (u16) (gRaceHudSubScreenFlipperCells->mCells[i].mUnk_10 + 0x4000 - d));
                } else {
                    Matrix2x2Rotation(matrix, (u16) (d + (0x4000 - gRaceHudSubScreenFlipperCells->mCells[i].mUnk_10)));
                }
            }
            matrixIndex = AllocOamMatrixIndex(oamBuffer);
            oamBuffer->mUnk_000.mUnk_20[matrixIndex].mUnk_06 = matrix[0] >> 4;
            oamBuffer->mUnk_000.mUnk_20[matrixIndex].mUnk_0e = matrix[1] >> 4;
            oamBuffer->mUnk_000.mUnk_20[matrixIndex].mUnk_16 = matrix[2] >> 4;
            oamBuffer->mUnk_000.mUnk_20[matrixIndex].mUnk_1e = matrix[3] >> 4;
            oamIndex = oamBuffer->mUnk_400;
            cell = &gRaceHudSubScreenFlipperCells->mCells[i];
            drawX = cell->mDrawPos.mUnk_00;
            ncerEntry = cell->mCell;
            drawY = cell->mDrawPos.mUnk_04;
            position[0] = drawX << 12;
            position[1] = drawY << 12;
            oamBuffer->mUnk_400 += NNS_G2dMakeCellToOams((GXOamAttr *) &oamBuffer->mUnk_000.mUnk_00[oamIndex],
                                                         0x80 - oamIndex, ncerEntry, matrix, position, matrixIndex, 1);
            for (; oamIndex < oamBuffer->mUnk_400; oamIndex++) {
                if (h != -1) {
                    oamBuffer->mUnk_000.mUnk_00[oamIndex].mUnk_0e = h;
                }
            }
        }
    }
}

s32 CreateRaceHudSubScreenNsKiller2Cells(void) {
    return CreateRaceHudSubScreenCells(&gRaceHudSubScreenNsKiller2Cells, MAP_OBJECT_KIND_NS_KILLER2);
}

void ClearRaceHudSubScreenNsKiller2Cells(void) {
    ClearRaceHudSubScreenCells(&gRaceHudSubScreenNsKiller2Cells);
}

void UpdateRaceHudSubScreenNsKiller2Cells(void) {
    s32 i;
    s32 cellCount;
    u32 n;
    Unk0217b498_00 *object;

    cellCount = 0;
    n = func_020c0db0();
    for (i = 0; i < gRaceHudSubScreenNsKiller2Cells->mObjectCount; i++) {
        object = gRaceHudSubScreenNsKiller2Cells->mObjects[i];
        if ((object->mFlags & 1) == 0 && (object->mFlags & 2) == 0) {
            if (ComputeRaceHudSubScreenPosition(
                    &object->mPos, &gRaceHudSubScreenNsKiller2Cells->mCells[cellCount].mDrawPos, n, 1, 1) != FALSE) {
                gRaceHudSubScreenNsKiller2Cells->mCells[cellCount].mCell = GetRaceSNcerEntry(0xad);
                gRaceHudSubScreenNsKiller2Cells->mCells[cellCount].mUnk_0c = 3;
                gRaceHudSubScreenNsKiller2Cells->mCells[cellCount].mUnk_0e = 0;
                gRaceHudSubScreenNsKiller2Cells->mCells[cellCount].mUnk_10 = object->mAngle;
                cellCount++;
            }
        }
    }
    gRaceHudSubScreenNsKiller2Cells->mCellCount = cellCount;
}

void DrawRaceHudSubScreenNsKiller2Cells(Unk020c06c4 *oamBuffer) {
    DrawRaceHudSubScreenCells(oamBuffer, gRaceHudSubScreenNsKiller2Cells, 1);
}

s32 CreateRaceHudSubScreenPendulumCells(void) {
    return CreateRaceHudSubScreenCells(&gRaceHudSubScreenPendulumCells, MAP_OBJECT_KIND_PENDULUM);
}

void ClearRaceHudSubScreenPendulumCells(void) {
    ClearRaceHudSubScreenCells(&gRaceHudSubScreenPendulumCells);
}

void UpdateRaceHudSubScreenPendulumCells(void) {
    s32 i;
    s32 cellCount;
    u32 n;
    Unk0217b498_00 *object;
    Vec3 *position;

    cellCount = 0;
    n = func_020c0db0();
    for (i = 0; i < gRaceHudSubScreenPendulumCells->mObjectCount; i++) {
        object = gRaceHudSubScreenPendulumCells->mObjects[i];
        if ((object->mFlags & 2) == 0) {
            position = &object->mPos;
            if (ComputeRaceHudSubScreenPosition(position, &gRaceHudSubScreenPendulumCells->mCells[cellCount].mDrawPos,
                                                n, 1, 1) != FALSE) {
                gRaceHudSubScreenPendulumCells->mCells[cellCount].mCell = GetRaceSNcerEntry(0xa0);
                gRaceHudSubScreenPendulumCells->mCells[cellCount].mUnk_0c = IsPositionOutsideBox(position) != 0 ? 2 : 3;
                gRaceHudSubScreenPendulumCells->mCells[cellCount].mUnk_0e = 0;
                gRaceHudSubScreenPendulumCells->mCells[cellCount].mUnk_10 = object->mAngle;
                cellCount++;
            }
        }
    }
    gRaceHudSubScreenPendulumCells->mCellCount = cellCount;
}

void DrawRaceHudSubScreenPendulumCells(Unk020c06c4 *oamBuffer) {
    DrawRaceHudSubScreenCells(oamBuffer, gRaceHudSubScreenPendulumCells, 1);
}
