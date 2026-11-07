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
    s32 a;
    u32 n;
    Unk0217b498_00 *e;
    Vec3 *v;

    a = 0;
    n = func_020c0db0();
    for (i = 0; i < gRaceHudSubScreenRainStarCells->mObjectCount; i++) {
        e = gRaceHudSubScreenRainStarCells->mObjects[i];
        v = &e->mPos;
        if (ComputeRaceHudSubScreenPosition(v, &gRaceHudSubScreenRainStarCells->mCells[a].mDrawPos, n, 1, 1) != FALSE) {
            gRaceHudSubScreenRainStarCells->mCells[a].mCell = GetRaceSNcerEntry(0xb3);
            gRaceHudSubScreenRainStarCells->mCells[a].mUnk_0c = func_020b4e70(v) != 0 ? 2 : 3;
            gRaceHudSubScreenRainStarCells->mCells[a].mUnk_0e = 0;
            gRaceHudSubScreenRainStarCells->mCells[a].mUnk_10 = e->mAngle;
            a++;
        }
    }
    gRaceHudSubScreenRainStarCells->mCellCount = a;
}

void DrawRaceHudSubScreenRainStarCells(Unk020c06c4 *a) {
    DrawRaceHudSubScreenCells(a, gRaceHudSubScreenRainStarCells, 1);
}

s32 CreateRaceHudSubScreenBasabasaCells(void) {
    return CreateRaceHudSubScreenCells(&gRaceHudSubScreenBasabasaCells, MAP_OBJECT_KIND_BASABASA);
}

void ClearRaceHudSubScreenBasabasaCells(void) {
    ClearRaceHudSubScreenCells(&gRaceHudSubScreenBasabasaCells);
}

void UpdateRaceHudSubScreenBasabasaCells(void) {
    s32 i;
    s32 a;
    u32 n;
    u32 m;
    Unk0217b498_00 *e;
    Vec3 *v;
    void *w;

    a = 0;
    n = func_020c0db0();
    for (i = 0; i < gRaceHudSubScreenBasabasaCells->mObjectCount; i++) {
        e = gRaceHudSubScreenBasabasaCells->mObjects[i];
        if ((e->mFlags & 1) == 0) {
            m = func_02092194(e);
            if (m != 0) {
                v = &e->mPos;
                if (ComputeRaceHudSubScreenPosition(v, &gRaceHudSubScreenBasabasaCells->mCells[a].mDrawPos, n, 1, 1) !=
                    FALSE) {
                    if (m == 2) {
                        w = GetRaceSNcerEntry(0xb5);
                    } else {
                        w = GetRaceSNcerEntry(0xb4);
                    }
                    gRaceHudSubScreenBasabasaCells->mCells[a].mCell = w;
                    gRaceHudSubScreenBasabasaCells->mCells[a].mUnk_0c = func_020b4e70(v) != 0 ? 2 : 3;
                    a++;
                }
            }
        }
    }
    gRaceHudSubScreenBasabasaCells->mCellCount = a;
}

void DrawRaceHudSubScreenBasabasaCells(Unk020c06c4 *a) {
    DrawRaceHudSubScreenCells(a, gRaceHudSubScreenBasabasaCells, 0);
}

s32 CreateRaceHudSubScreenMkdEfBubbleCells(void) {
    return CreateRaceHudSubScreenCells(&gRaceHudSubScreenMkdEfBubbleCells, MAP_OBJECT_KIND_MKD_EF_BUBBLE);
}

void ClearRaceHudSubScreenMkdEfBubbleCells(void) {
    ClearRaceHudSubScreenCells(&gRaceHudSubScreenMkdEfBubbleCells);
}

void UpdateRaceHudSubScreenMkdEfBubbleCells(void) {
    s32 i;
    s32 a;
    u32 n;
    Unk0217b498_00 *e;
    s32 d;
    Vec3 *v;

    a = 0;
    n = func_020c0db0();
    for (i = 0; i < gRaceHudSubScreenMkdEfBubbleCells->mObjectCount; i++) {
        if (IsRaceHudSubScreenPairNearCenter(&gRaceHudSubScreenMkdEfBubbleCells->mUnk_0c[i]) != FALSE) {
            e = gRaceHudSubScreenMkdEfBubbleCells->mObjects[i];
            d = e->mPos.y - e->mUnk_ac;
            if (d >= 0) {
                v = &e->mPos;
                if (ComputeRaceHudSubScreenPosition(v, &gRaceHudSubScreenMkdEfBubbleCells->mCells[a].mDrawPos, n, 0,
                                                    1) != FALSE) {
                    gRaceHudSubScreenMkdEfBubbleCells->mCells[a].mDrawPos.mUnk_04 -= d >> 14;
                    gRaceHudSubScreenMkdEfBubbleCells->mCells[a].mCell = GetRaceSNcerEntry(0xb1);
                    gRaceHudSubScreenMkdEfBubbleCells->mCells[a].mUnk_0c = func_020b4e70(v) != 0 ? 2 : 3;
                    a++;
                }
            }
        }
    }
    gRaceHudSubScreenMkdEfBubbleCells->mCellCount = a;
}

void DrawRaceHudSubScreenMkdEfBubbleCells(Unk020c06c4 *a) {
    DrawRaceHudSubScreenCells(a, gRaceHudSubScreenMkdEfBubbleCells, 0);
}

s32 CreateRaceHudSubScreenBoundCells(void) {
    return CreateRaceHudSubScreenCells(&gRaceHudSubScreenBoundCells, MAP_OBJECT_KIND_BOUND);
}

void ClearRaceHudSubScreenBoundCells(void) {
    ClearRaceHudSubScreenCells(&gRaceHudSubScreenBoundCells);
}

void UpdateRaceHudSubScreenBoundCells(void) {
    s32 i;
    s32 a;
    u32 n;
    Unk0217b498_00 *e;
    Vec3 *v;

    a = 0;
    n = func_020c0db0();
    for (i = 0; i < gRaceHudSubScreenBoundCells->mObjectCount; i++) {
        e = gRaceHudSubScreenBoundCells->mObjects[i];
        v = &e->mPos;
        if (ComputeRaceHudSubScreenPosition(v, &gRaceHudSubScreenBoundCells->mCells[a].mDrawPos, n, 1, 1) != FALSE) {
            gRaceHudSubScreenBoundCells->mCells[a].mCell = GetRaceSNcerEntry(0x91);
            gRaceHudSubScreenBoundCells->mCells[a].mUnk_0c = func_020b4e70(v) != 0 ? 2 : 3;
            gRaceHudSubScreenBoundCells->mCells[a].mUnk_10 = e->mAngle;
            gRaceHudSubScreenBoundCells->mUnk_0c[a].mUnk_00 = e->mScaleX / 6;
            a++;
        }
    }
    gRaceHudSubScreenBoundCells->mCellCount = a;
}

void DrawRaceHudSubScreenBoundCells(Unk020c06c4 *a) {
    DrawRaceHudSubScreenCellsScaled(a, gRaceHudSubScreenBoundCells, 1);
}

s32 CreateRaceHudSubScreenMkdEfBurnerCells(void) {
    return CreateRaceHudSubScreenCells(&gRaceHudSubScreenMkdEfBurnerCells, MAP_OBJECT_KIND_MKD_EF_BURNER);
}

void ClearRaceHudSubScreenMkdEfBurnerCells(void) {
    ClearRaceHudSubScreenCells(&gRaceHudSubScreenMkdEfBurnerCells);
}

void UpdateRaceHudSubScreenMkdEfBurnerCells(void) {
    s32 i;
    s32 a;
    s32 b;
    u32 n;
    Unk0217b498_00 *e;
    Vec3 *v;

    a = 0;
    n = func_020c0db0();
    gRaceHudSubScreenMkdEfBurnerCells->mUnk_0c[0].mUnk_04++;
    if (gRaceHudSubScreenMkdEfBurnerCells->mUnk_0c[0].mUnk_04 < 0 ||
        gRaceHudSubScreenMkdEfBurnerCells->mUnk_0c[0].mUnk_04 >= 8) {
        gRaceHudSubScreenMkdEfBurnerCells->mUnk_0c[0].mUnk_04 = 0;
    }
    b = gRaceHudSubScreenMkdEfBurnerCells->mUnk_0c[0].mUnk_04 < 4 ? 1 : 0;
    for (i = 0; i < gRaceHudSubScreenMkdEfBurnerCells->mObjectCount; i++) {
        e = gRaceHudSubScreenMkdEfBurnerCells->mObjects[i];
        if ((e->mFlags & 1) == 0 && func_020931ac(e) != 0) {
            v = &e->mPos;
            if (ComputeRaceHudSubScreenPosition(v, &gRaceHudSubScreenMkdEfBurnerCells->mCells[a].mDrawPos, n, 0, 0) !=
                FALSE) {
                gRaceHudSubScreenMkdEfBurnerCells->mCells[a].mCell =
                    GetRaceSNcerEntry(gRaceSetup->mCourseId == COURSE_ID_AIRSHIP ? 0xae : 0xb2);
                gRaceHudSubScreenMkdEfBurnerCells->mCells[a].mUnk_0c = func_020b4e70(v) != 0 ? 2 : 3;
                gRaceHudSubScreenMkdEfBurnerCells->mUnk_0c[a].mUnk_00 = b != 0 ? 0x1000 : 0xccd;
                a++;
            }
        }
    }
    gRaceHudSubScreenMkdEfBurnerCells->mCellCount = a;
}

void DrawRaceHudSubScreenMkdEfBurnerCells(Unk020c06c4 *a) {
    DrawRaceHudSubScreenCellsScaled(a, gRaceHudSubScreenMkdEfBurnerCells, 0);
}

s32 func_020cdf18(void) {
    return CreateRaceHudSubScreenCells(&data_0217b46c, 0x1ae);
}

void func_020cdf04(void) {
    ClearRaceHudSubScreenCells(&data_0217b46c);
}

void func_020cde18(void) {
    s32 i;
    s32 a;
    u32 n;
    Unk0217b498_00 *e;
    Vec3 *v;

    a = 0;
    n = func_020c0db0();
    for (i = 0; i < data_0217b46c->mObjectCount; i++) {
        e = data_0217b46c->mObjects[i];
        if ((e->mFlags & 1) == 0) {
            v = &e->mPos;
            if (ComputeRaceHudSubScreenPosition(v, &data_0217b46c->mCells[a].mDrawPos, n, 1, 1) != FALSE) {
                data_0217b46c->mCells[a].mCell = GetRaceSNcerEntry(0x8d);
                data_0217b46c->mCells[a].mUnk_0c = func_020b4e70(v) != 0 ? 2 : 3;
                a++;
            }
        }
    }
    data_0217b46c->mCellCount = a;
}

void func_020cddfc(Unk020c06c4 *a) {
    DrawRaceHudSubScreenCells(a, data_0217b46c, 0);
}

s32 CreateRaceHudSubScreenIronBallCells(void) {
    return CreateRaceHudSubScreenCells(&gRaceHudSubScreenIronBallCells, MAP_OBJECT_KIND_IRON_BALL);
}

void ClearRaceHudSubScreenIronBallCells(void) {
    ClearRaceHudSubScreenCells(&gRaceHudSubScreenIronBallCells);
}

void UpdateRaceHudSubScreenIronBallCells(void) {
    s32 i;
    s32 a;
    u32 n;
    Unk0217b498_00 *e;
    Vec3 *v;

    a = 0;
    n = func_020c0db0();
    for (i = 0; i < gRaceHudSubScreenIronBallCells->mObjectCount; i++) {
        e = gRaceHudSubScreenIronBallCells->mObjects[i];
        if ((e->mFlags & 2) == 0) {
            v = &e->mPos;
            if (ComputeRaceHudSubScreenPosition(v, &gRaceHudSubScreenIronBallCells->mCells[a].mDrawPos, n, 1, 1) !=
                FALSE) {
                gRaceHudSubScreenIronBallCells->mCells[a].mCell = GetRaceSNcerEntry(0x92);
                gRaceHudSubScreenIronBallCells->mCells[a].mUnk_0c = func_020b4e70(v) != 0 ? 2 : 3;
                gRaceHudSubScreenIronBallCells->mCells[a].mUnk_0e = e->mFlags & 0x20;
                a++;
            }
        }
    }
    gRaceHudSubScreenIronBallCells->mCellCount = a;
}

void DrawRaceHudSubScreenIronBallCells(Unk020c06c4 *a) {
    DrawRaceHudSubScreenCells(a, gRaceHudSubScreenIronBallCells, 0);
}

s32 CreateRaceHudSubScreenKuriboCells(void) {
    return CreateRaceHudSubScreenCells(&gRaceHudSubScreenKuriboCells, MAP_OBJECT_KIND_KURIBO);
}

void ClearRaceHudSubScreenKuriboCells(void) {
    ClearRaceHudSubScreenCells(&gRaceHudSubScreenKuriboCells);
}

void UpdateRaceHudSubScreenKuriboCells(void) {
    s32 i;
    s32 a;
    u32 n;
    Unk0217b498_00 *e;
    Vec3 *v;

    a = 0;
    n = func_020c0db0();
    for (i = 0; i < gRaceHudSubScreenKuriboCells->mObjectCount; i++) {
        e = gRaceHudSubScreenKuriboCells->mObjects[i];
        v = &e->mPos;
        if ((e->mFlags & 2) == 0) {
            if (ComputeRaceHudSubScreenPosition(v, &gRaceHudSubScreenKuriboCells->mCells[a].mDrawPos, n, 0, 1) !=
                FALSE) {
                gRaceHudSubScreenKuriboCells->mCells[a].mCell = GetRaceSNcerEntry(0xa3);
                gRaceHudSubScreenKuriboCells->mCells[a].mUnk_0c = func_020b4e70(v) != 0 ? 2 : 3;
                a++;
            }
        }
    }
    gRaceHudSubScreenKuriboCells->mCellCount = a;
}

void DrawRaceHudSubScreenKuriboCells(Unk020c06c4 *a) {
    DrawRaceHudSubScreenCells(a, gRaceHudSubScreenKuriboCells, 0);
}

s32 CreateRaceHudSubScreenObPakkunSfCells(void) {
    return CreateRaceHudSubScreenCells(&gRaceHudSubScreenObPakkunSfCells, MAP_OBJECT_KIND_OB_PAKKUN_SF);
}

void ClearRaceHudSubScreenObPakkunSfCells(void) {
    ClearRaceHudSubScreenCells(&gRaceHudSubScreenObPakkunSfCells);
}

void UpdateRaceHudSubScreenObPakkunSfCells(void) {
    s32 i;
    s32 a;
    u32 n;
    Unk0217b498_00 *e;
    Vec3 *v;

    a = 0;
    n = func_020c0db0();
    for (i = 0; i < gRaceHudSubScreenObPakkunSfCells->mObjectCount; i++) {
        if (IsRaceHudSubScreenPairNearCenter(&gRaceHudSubScreenObPakkunSfCells->mUnk_0c[i]) != FALSE) {
            e = gRaceHudSubScreenObPakkunSfCells->mObjects[i];
            if ((e->mFlags & 1) == 0) {
                v = &e->mPos;
                if (ComputeRaceHudSubScreenPosition(v, &gRaceHudSubScreenObPakkunSfCells->mCells[a].mDrawPos, n, 0,
                                                    0) != FALSE) {
                    gRaceHudSubScreenObPakkunSfCells->mCells[a].mCell =
                        GetRaceSNcerEntry(((e->mUnk_b8 & 0x10) >> 4) != 0 ? 0xa2 : 0xa1);
                    gRaceHudSubScreenObPakkunSfCells->mCells[a].mUnk_0c = func_020b4e70(v) != 0 ? 2 : 3;
                    a++;
                }
            }
        }
    }
    gRaceHudSubScreenObPakkunSfCells->mCellCount = a;
}

void DrawRaceHudSubScreenObPakkunSfCells(Unk020c06c4 *a) {
    DrawRaceHudSubScreenCells(a, gRaceHudSubScreenObPakkunSfCells, 0);
}

s32 CreateRaceHudSubScreenCoverPooHoleCells(void) {
    return CreateRaceHudSubScreenCells(&gRaceHudSubScreenCoverPooHoleCells, MAP_OBJECT_KIND_COVER_POO_HOLE);
}

void ClearRaceHudSubScreenCoverPooHoleCells(void) {
    ClearRaceHudSubScreenCells(&gRaceHudSubScreenCoverPooHoleCells);
}

void UpdateRaceHudSubScreenCoverPooHoleCells(void) {
    s32 i;
    s32 a;
    u32 n;
    Unk0217b498_00 *e;
    Vec3 *v;

    a = 0;
    n = func_020c0db0();
    for (i = 0; i < gRaceHudSubScreenCoverPooHoleCells->mObjectCount; i++) {
        if (IsRaceHudSubScreenPairNearCenter(&gRaceHudSubScreenCoverPooHoleCells->mUnk_0c[i]) != FALSE) {
            e = gRaceHudSubScreenCoverPooHoleCells->mObjects[i];
            if ((e->mFlags & 1) == 0) {
                v = &e->mPos;
                if (ComputeRaceHudSubScreenPosition(v, &gRaceHudSubScreenCoverPooHoleCells->mCells[a].mDrawPos, n, 0,
                                                    0) != FALSE) {
                    gRaceHudSubScreenCoverPooHoleCells->mCells[a].mDrawPos.mUnk_04 -= func_02095f30(e) >> 14;
                    gRaceHudSubScreenCoverPooHoleCells->mCells[a].mCell =
                        GetRaceSNcerEntry(func_02095f38(e) != FALSE ? 0xab : 0xaa);
                    gRaceHudSubScreenCoverPooHoleCells->mCells[a].mUnk_0c = func_020b4e70(v) != 0 ? 2 : 3;
                    a++;
                }
            }
        }
    }
    gRaceHudSubScreenCoverPooHoleCells->mCellCount = a;
}

void DrawRaceHudSubScreenCoverPooHoleCells(Unk020c06c4 *a) {
    DrawRaceHudSubScreenCells(a, gRaceHudSubScreenCoverPooHoleCells, 0);
}

s32 CreateRaceHudSubScreenRock2Cells(void) {
    return CreateRaceHudSubScreenCells(&gRaceHudSubScreenRock2Cells, MAP_OBJECT_KIND_ROCK2);
}

void ClearRaceHudSubScreenRock2Cells(void) {
    ClearRaceHudSubScreenCells(&gRaceHudSubScreenRock2Cells);
}

void UpdateRaceHudSubScreenRock2Cells(void) {
    s32 i;
    s32 a;
    u32 n;
    Unk0217b498_00 *e;
    Vec3 *v;

    a = 0;
    n = func_020c0db0();
    for (i = 0; i < gRaceHudSubScreenRock2Cells->mObjectCount; i++) {
        e = gRaceHudSubScreenRock2Cells->mObjects[i];
        if ((e->mFlags & 2) == 0) {
            v = &e->mPos;
            if (ComputeRaceHudSubScreenPosition(v, &gRaceHudSubScreenRock2Cells->mCells[a].mDrawPos, n, 1, 1) !=
                FALSE) {
                gRaceHudSubScreenRock2Cells->mCells[a].mCell = GetRaceSNcerEntry(0x8f);
                gRaceHudSubScreenRock2Cells->mCells[a].mUnk_0c = func_020b4e70(v) != 0 ? 2 : 3;
                gRaceHudSubScreenRock2Cells->mCells[a].mUnk_10 += 0x400;
                a++;
            }
        }
    }
    gRaceHudSubScreenRock2Cells->mCellCount = a;
}

void DrawRaceHudSubScreenRock2Cells(Unk020c06c4 *a) {
    DrawRaceHudSubScreenCells(a, gRaceHudSubScreenRock2Cells, 1);
}

s32 CreateRaceHudSubScreenSanboCells(void) {
    return CreateRaceHudSubScreenCells(&gRaceHudSubScreenSanboCells, MAP_OBJECT_KIND_SANBO);
}

void ClearRaceHudSubScreenSanboCells(void) {
    ClearRaceHudSubScreenCells(&gRaceHudSubScreenSanboCells);
}

void UpdateRaceHudSubScreenSanboCells(void) {
    s32 i;
    s32 a;
    u32 n;
    Unk0217b498_00 *e;
    Vec3 *v;

    a = 0;
    n = func_020c0db0();
    for (i = 0; i < gRaceHudSubScreenSanboCells->mObjectCount; i++) {
        if (IsRaceHudSubScreenPairNearCenter(&gRaceHudSubScreenSanboCells->mUnk_0c[i]) != FALSE) {
            e = gRaceHudSubScreenSanboCells->mObjects[i];
            if ((e->mFlags & 1) == 0) {
                v = &e->mPos;
                if (ComputeRaceHudSubScreenPosition(v, &gRaceHudSubScreenSanboCells->mCells[a].mDrawPos, n, 0, 0) !=
                    FALSE) {
                    gRaceHudSubScreenSanboCells->mCells[a].mCell = GetRaceSNcerEntry(0x8e);
                    gRaceHudSubScreenSanboCells->mCells[a].mUnk_0c = func_020b4e70(v) != 0 ? 2 : 3;
                    a++;
                }
            }
        }
    }
    gRaceHudSubScreenSanboCells->mCellCount = a;
}

void DrawRaceHudSubScreenSanboCells(Unk020c06c4 *a) {
    DrawRaceHudSubScreenCells(a, gRaceHudSubScreenSanboCells, 0);
}

s32 CreateRaceHudSubScreenRockCells(void) {
    return CreateRaceHudSubScreenCells(&gRaceHudSubScreenRockCells, MAP_OBJECT_KIND_ROCK);
}

void ClearRaceHudSubScreenRockCells(void) {
    ClearRaceHudSubScreenCells(&gRaceHudSubScreenRockCells);
}

void UpdateRaceHudSubScreenRockCells(void) {
    s32 i;
    s32 a;
    u32 n;
    Unk0217b498_00 *e;
    Vec3 *v;

    a = 0;
    n = func_020c0db0();
    for (i = 0; i < gRaceHudSubScreenRockCells->mObjectCount; i++) {
        e = gRaceHudSubScreenRockCells->mObjects[i];
        if ((e->mFlags & 2) == 0) {
            v = &e->mPos;
            if (ComputeRaceHudSubScreenPosition(v, &gRaceHudSubScreenRockCells->mCells[a].mDrawPos, n, 1, 1) != FALSE) {
                gRaceHudSubScreenRockCells->mCells[a].mCell = GetRaceSNcerEntry(0x99);
                gRaceHudSubScreenRockCells->mCells[a].mUnk_0c = func_020b4e70(v) != 0 ? 2 : 3;
                gRaceHudSubScreenRockCells->mCells[a].mUnk_10 += 0x400;
                a++;
            }
        }
    }
    gRaceHudSubScreenRockCells->mCellCount = a;
}

void DrawRaceHudSubScreenRockCells(Unk020c06c4 *a) {
    DrawRaceHudSubScreenCells(a, gRaceHudSubScreenRockCells, 1);
}

s32 CreateRaceHudSubScreenWoodbox1Cells(void) {
    return CreateRaceHudSubScreenCells(&gRaceHudSubScreenWoodbox1Cells, MAP_OBJECT_KIND_WOODBOX1);
}

void ClearRaceHudSubScreenWoodbox1Cells(void) {
    ClearRaceHudSubScreenCells(&gRaceHudSubScreenWoodbox1Cells);
}

void UpdateRaceHudSubScreenWoodbox1Cells(void) {
    s32 i;
    s32 a;
    u32 n;
    Unk0217b498_00 *e;
    Vec3 *v;

    a = 0;
    n = func_020c0db0();
    for (i = 0; i < gRaceHudSubScreenWoodbox1Cells->mObjectCount; i++) {
        if (IsRaceHudSubScreenPairNearCenter(&gRaceHudSubScreenWoodbox1Cells->mUnk_0c[i]) != FALSE) {
            e = gRaceHudSubScreenWoodbox1Cells->mObjects[i];
            if ((e->mFlags & 1) == 0) {
                v = &e->mPos;
                if (ComputeRaceHudSubScreenPosition(v, &gRaceHudSubScreenWoodbox1Cells->mCells[a].mDrawPos, n, 0, 0) !=
                    FALSE) {
                    gRaceHudSubScreenWoodbox1Cells->mCells[a].mCell = GetRaceSNcerEntry(0x5c);
                    gRaceHudSubScreenWoodbox1Cells->mCells[a].mUnk_0c = func_020b4e70(v) != 0 ? 2 : 3;
                    a++;
                }
            }
        }
    }
    gRaceHudSubScreenWoodbox1Cells->mCellCount = a;
}

void DrawRaceHudSubScreenWoodbox1Cells(Unk020c06c4 *a) {
    DrawRaceHudSubScreenCells(a, gRaceHudSubScreenWoodbox1Cells, 0);
}

s32 CreateRaceHudSubScreenFlipperCells(void) {
    return CreateRaceHudSubScreenCells(&gRaceHudSubScreenFlipperCells, MAP_OBJECT_KIND_FLIPPER);
}

void ClearRaceHudSubScreenFlipperCells(void) {
    ClearRaceHudSubScreenCells(&gRaceHudSubScreenFlipperCells);
}

void UpdateRaceHudSubScreenFlipperCells(void) {
    s32 i;
    s32 a;
    u32 n;
    Unk0217b498_00 *e;
    Vec3 *v;

    a = 0;
    n = func_020c0db0();
    for (i = 0; i < gRaceHudSubScreenFlipperCells->mObjectCount; i++) {
        e = gRaceHudSubScreenFlipperCells->mObjects[i];
        if ((e->mFlags & 2) == 0) {
            v = &e->mPos;
            if (ComputeRaceHudSubScreenPosition(v, &gRaceHudSubScreenFlipperCells->mCells[a].mDrawPos, n, 1, 1) !=
                FALSE) {
                gRaceHudSubScreenFlipperCells->mCells[a].mCell = GetRaceSNcerEntry(0x90);
                gRaceHudSubScreenFlipperCells->mCells[a].mUnk_0c = func_020b4e70(v) != 0 ? 2 : 3;
                gRaceHudSubScreenFlipperCells->mCells[a].mUnk_0e = e->mFlags & 0x400;
                gRaceHudSubScreenFlipperCells->mCells[a].mUnk_10 = e->mAngle;
                a++;
            }
        }
    }
    gRaceHudSubScreenFlipperCells->mCellCount = a;
}

void DrawRaceHudSubScreenFlipperCells(Unk020c06c4 *a) {
    s32 i;
    s32 c;
    u16 d;
    u16 h;
    s32 w;
    u16 k;
    RaceHudSubScreenCell *x;
    s32 v1[4];
    s32 z[2];
    s32 x0;
    struct Unk020224e0_c *x8;
    s32 x4;

    c = func_020c0dc4();
    d = func_020b6368();
    for (i = 0; i < gRaceHudSubScreenFlipperCells->mCellCount; i++) {
        h = gRaceHudSubScreenFlipperCells->mCells[i].mUnk_0c;
        if (c <= h) {
            if (gRaceHudSubScreenFlipperCells->mCells[i].mUnk_0e != 0) {
                if (gRaceSetup->mMirrorMode != 0) {
                    func_020b4c74(v1, (u16) (d + (gRaceHudSubScreenFlipperCells->mCells[i].mUnk_10 + 0x4000)));
                } else {
                    func_020b4c74(v1, (u16) (0x4000 - gRaceHudSubScreenFlipperCells->mCells[i].mUnk_10 - d));
                }
            } else {
                if (gRaceSetup->mMirrorMode != 0) {
                    Matrix2x2Rotation(v1, (u16) (gRaceHudSubScreenFlipperCells->mCells[i].mUnk_10 + 0x4000 - d));
                } else {
                    Matrix2x2Rotation(v1, (u16) (d + (0x4000 - gRaceHudSubScreenFlipperCells->mCells[i].mUnk_10)));
                }
            }
            k = func_020ae5c4(a);
            a->mUnk_000.mUnk_20[k].mUnk_06 = v1[0] >> 4;
            a->mUnk_000.mUnk_20[k].mUnk_0e = v1[1] >> 4;
            a->mUnk_000.mUnk_20[k].mUnk_16 = v1[2] >> 4;
            a->mUnk_000.mUnk_20[k].mUnk_1e = v1[3] >> 4;
            w = a->mUnk_400;
            x = &gRaceHudSubScreenFlipperCells->mCells[i];
            x0 = x->mDrawPos.mUnk_00;
            x8 = x->mCell;
            x4 = x->mDrawPos.mUnk_04;
            z[0] = x0 << 12;
            z[1] = x4 << 12;
            a->mUnk_400 += NNS_G2dMakeCellToOams((Unk020224e0_o *) &a->mUnk_000.mUnk_00[w], 0x80 - w, x8, v1, z, k, 1);
            for (; w < a->mUnk_400; w++) {
                if (h != -1) {
                    a->mUnk_000.mUnk_00[w].mUnk_0e = h;
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
    s32 a;
    u32 n;
    Unk0217b498_00 *e;

    a = 0;
    n = func_020c0db0();
    for (i = 0; i < gRaceHudSubScreenNsKiller2Cells->mObjectCount; i++) {
        e = gRaceHudSubScreenNsKiller2Cells->mObjects[i];
        if ((e->mFlags & 1) == 0 && (e->mFlags & 2) == 0) {
            if (ComputeRaceHudSubScreenPosition(&e->mPos, &gRaceHudSubScreenNsKiller2Cells->mCells[a].mDrawPos, n, 1,
                                                1) != FALSE) {
                gRaceHudSubScreenNsKiller2Cells->mCells[a].mCell = GetRaceSNcerEntry(0xad);
                gRaceHudSubScreenNsKiller2Cells->mCells[a].mUnk_0c = 3;
                gRaceHudSubScreenNsKiller2Cells->mCells[a].mUnk_0e = 0;
                gRaceHudSubScreenNsKiller2Cells->mCells[a].mUnk_10 = e->mAngle;
                a++;
            }
        }
    }
    gRaceHudSubScreenNsKiller2Cells->mCellCount = a;
}

void DrawRaceHudSubScreenNsKiller2Cells(Unk020c06c4 *a) {
    DrawRaceHudSubScreenCells(a, gRaceHudSubScreenNsKiller2Cells, 1);
}

s32 CreateRaceHudSubScreenPendulumCells(void) {
    return CreateRaceHudSubScreenCells(&gRaceHudSubScreenPendulumCells, MAP_OBJECT_KIND_PENDULUM);
}

void ClearRaceHudSubScreenPendulumCells(void) {
    ClearRaceHudSubScreenCells(&gRaceHudSubScreenPendulumCells);
}

void UpdateRaceHudSubScreenPendulumCells(void) {
    s32 i;
    s32 a;
    u32 n;
    Unk0217b498_00 *e;
    Vec3 *v;

    a = 0;
    n = func_020c0db0();
    for (i = 0; i < gRaceHudSubScreenPendulumCells->mObjectCount; i++) {
        e = gRaceHudSubScreenPendulumCells->mObjects[i];
        if ((e->mFlags & 2) == 0) {
            v = &e->mPos;
            if (ComputeRaceHudSubScreenPosition(v, &gRaceHudSubScreenPendulumCells->mCells[a].mDrawPos, n, 1, 1) !=
                FALSE) {
                gRaceHudSubScreenPendulumCells->mCells[a].mCell = GetRaceSNcerEntry(0xa0);
                gRaceHudSubScreenPendulumCells->mCells[a].mUnk_0c = func_020b4e70(v) != 0 ? 2 : 3;
                gRaceHudSubScreenPendulumCells->mCells[a].mUnk_0e = 0;
                gRaceHudSubScreenPendulumCells->mCells[a].mUnk_10 = e->mAngle;
                a++;
            }
        }
    }
    gRaceHudSubScreenPendulumCells->mCellCount = a;
}

void DrawRaceHudSubScreenPendulumCells(Unk020c06c4 *a) {
    DrawRaceHudSubScreenCells(a, gRaceHudSubScreenPendulumCells, 1);
}
