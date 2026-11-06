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

void func_020ce694(void) {
    ClearRaceHudSubScreenCells(&data_0217b480);
}

void func_020ce580(void) {
    s32 i;
    s32 a;
    u32 n;
    Unk0217b498_00 *e;
    Vec3 *v;

    a = 0;
    n = func_020c0db0();
    for (i = 0; i < data_0217b480->mObjectCount; i++) {
        e = data_0217b480->mObjects[i];
        v = &e->mPos;
        if (ComputeRaceHudSubScreenPosition(v, &data_0217b480->mCells[a].mUnk_00, n, 1, 1) != FALSE) {
            data_0217b480->mCells[a].mUnk_08 = GetRaceSNcerEntry(0xb3);
            data_0217b480->mCells[a].mUnk_0c = func_020b4e70(v) != 0 ? 2 : 3;
            data_0217b480->mCells[a].mUnk_0e = 0;
            data_0217b480->mCells[a].mUnk_10 = e->mAngle;
            a++;
        }
    }
    data_0217b480->mCellCount = a;
}

void func_020ce564(Unk020c06c4 *a) {
    DrawRaceHudSubScreenCells(a, data_0217b480, 1);
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
                if (ComputeRaceHudSubScreenPosition(v, &gRaceHudSubScreenBasabasaCells->mCells[a].mUnk_00, n, 1, 1) !=
                    FALSE) {
                    if (m == 2) {
                        w = GetRaceSNcerEntry(0xb5);
                    } else {
                        w = GetRaceSNcerEntry(0xb4);
                    }
                    gRaceHudSubScreenBasabasaCells->mCells[a].mUnk_08 = w;
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
                if (ComputeRaceHudSubScreenPosition(v, &gRaceHudSubScreenMkdEfBubbleCells->mCells[a].mUnk_00, n, 0,
                                                    1) != FALSE) {
                    gRaceHudSubScreenMkdEfBubbleCells->mCells[a].mUnk_00.mUnk_04 -= d >> 14;
                    gRaceHudSubScreenMkdEfBubbleCells->mCells[a].mUnk_08 = GetRaceSNcerEntry(0xb1);
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

s32 func_020ce264(void) {
    return CreateRaceHudSubScreenCells(&data_0217b474, 0x1a8);
}

void func_020ce250(void) {
    ClearRaceHudSubScreenCells(&data_0217b474);
}

void func_020ce134(void) {
    s32 i;
    s32 a;
    u32 n;
    Unk0217b498_00 *e;
    Vec3 *v;

    a = 0;
    n = func_020c0db0();
    for (i = 0; i < data_0217b474->mObjectCount; i++) {
        e = data_0217b474->mObjects[i];
        v = &e->mPos;
        if (ComputeRaceHudSubScreenPosition(v, &data_0217b474->mCells[a].mUnk_00, n, 1, 1) != FALSE) {
            data_0217b474->mCells[a].mUnk_08 = GetRaceSNcerEntry(0x91);
            data_0217b474->mCells[a].mUnk_0c = func_020b4e70(v) != 0 ? 2 : 3;
            data_0217b474->mCells[a].mUnk_10 = e->mAngle;
            data_0217b474->mUnk_0c[a].mUnk_00 = e->mUnk_1c / 6;
            a++;
        }
    }
    data_0217b474->mCellCount = a;
}

void func_020ce118(Unk020c06c4 *a) {
    DrawRaceHudSubScreenCellsScaled(a, data_0217b474, 1);
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
            if (ComputeRaceHudSubScreenPosition(v, &gRaceHudSubScreenMkdEfBurnerCells->mCells[a].mUnk_00, n, 0, 0) !=
                FALSE) {
                gRaceHudSubScreenMkdEfBurnerCells->mCells[a].mUnk_08 =
                    GetRaceSNcerEntry(data_021759c0->mCourseId == COURSE_ID_AIRSHIP ? 0xae : 0xb2);
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
            if (ComputeRaceHudSubScreenPosition(v, &data_0217b46c->mCells[a].mUnk_00, n, 1, 1) != FALSE) {
                data_0217b46c->mCells[a].mUnk_08 = GetRaceSNcerEntry(0x8d);
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
            if (ComputeRaceHudSubScreenPosition(v, &gRaceHudSubScreenIronBallCells->mCells[a].mUnk_00, n, 1, 1) !=
                FALSE) {
                gRaceHudSubScreenIronBallCells->mCells[a].mUnk_08 = GetRaceSNcerEntry(0x92);
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
            if (ComputeRaceHudSubScreenPosition(v, &gRaceHudSubScreenKuriboCells->mCells[a].mUnk_00, n, 0, 1) !=
                FALSE) {
                gRaceHudSubScreenKuriboCells->mCells[a].mUnk_08 = GetRaceSNcerEntry(0xa3);
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

s32 func_020cdb54(void) {
    return CreateRaceHudSubScreenCells(&data_0217b460, 0x1a6);
}

void func_020cdb40(void) {
    ClearRaceHudSubScreenCells(&data_0217b460);
}

void func_020cda14(void) {
    s32 i;
    s32 a;
    u32 n;
    Unk0217b498_00 *e;
    Vec3 *v;

    a = 0;
    n = func_020c0db0();
    for (i = 0; i < data_0217b460->mObjectCount; i++) {
        if (IsRaceHudSubScreenPairNearCenter(&data_0217b460->mUnk_0c[i]) != FALSE) {
            e = data_0217b460->mObjects[i];
            if ((e->mFlags & 1) == 0) {
                v = &e->mPos;
                if (ComputeRaceHudSubScreenPosition(v, &data_0217b460->mCells[a].mUnk_00, n, 0, 0) != FALSE) {
                    data_0217b460->mCells[a].mUnk_08 = GetRaceSNcerEntry(((e->mUnk_b8 & 0x10) >> 4) != 0 ? 0xa2 : 0xa1);
                    data_0217b460->mCells[a].mUnk_0c = func_020b4e70(v) != 0 ? 2 : 3;
                    a++;
                }
            }
        }
    }
    data_0217b460->mCellCount = a;
}

void func_020cd9f8(Unk020c06c4 *a) {
    DrawRaceHudSubScreenCells(a, data_0217b460, 0);
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
                if (ComputeRaceHudSubScreenPosition(v, &gRaceHudSubScreenCoverPooHoleCells->mCells[a].mUnk_00, n, 0,
                                                    0) != FALSE) {
                    gRaceHudSubScreenCoverPooHoleCells->mCells[a].mUnk_00.mUnk_04 -= func_02095f30(e) >> 14;
                    gRaceHudSubScreenCoverPooHoleCells->mCells[a].mUnk_08 =
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

s32 func_020cd844(void) {
    return CreateRaceHudSubScreenCells(&data_0217b458, 0x1b1);
}

void func_020cd830(void) {
    ClearRaceHudSubScreenCells(&data_0217b458);
}

void func_020cd72c(void) {
    s32 i;
    s32 a;
    u32 n;
    Unk0217b498_00 *e;
    Vec3 *v;

    a = 0;
    n = func_020c0db0();
    for (i = 0; i < data_0217b458->mObjectCount; i++) {
        e = data_0217b458->mObjects[i];
        if ((e->mFlags & 2) == 0) {
            v = &e->mPos;
            if (ComputeRaceHudSubScreenPosition(v, &data_0217b458->mCells[a].mUnk_00, n, 1, 1) != FALSE) {
                data_0217b458->mCells[a].mUnk_08 = GetRaceSNcerEntry(0x8f);
                data_0217b458->mCells[a].mUnk_0c = func_020b4e70(v) != 0 ? 2 : 3;
                data_0217b458->mCells[a].mUnk_10 += 0x400;
                a++;
            }
        }
    }
    data_0217b458->mCellCount = a;
}

void func_020cd710(Unk020c06c4 *a) {
    DrawRaceHudSubScreenCells(a, data_0217b458, 1);
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
                if (ComputeRaceHudSubScreenPosition(v, &gRaceHudSubScreenSanboCells->mCells[a].mUnk_00, n, 0, 0) !=
                    FALSE) {
                    gRaceHudSubScreenSanboCells->mCells[a].mUnk_08 = GetRaceSNcerEntry(0x8e);
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

s32 func_020cd598(void) {
    return CreateRaceHudSubScreenCells(&data_0217b450, 0x192);
}

void func_020cd584(void) {
    ClearRaceHudSubScreenCells(&data_0217b450);
}

void func_020cd480(void) {
    s32 i;
    s32 a;
    u32 n;
    Unk0217b498_00 *e;
    Vec3 *v;

    a = 0;
    n = func_020c0db0();
    for (i = 0; i < data_0217b450->mObjectCount; i++) {
        e = data_0217b450->mObjects[i];
        if ((e->mFlags & 2) == 0) {
            v = &e->mPos;
            if (ComputeRaceHudSubScreenPosition(v, &data_0217b450->mCells[a].mUnk_00, n, 1, 1) != FALSE) {
                data_0217b450->mCells[a].mUnk_08 = GetRaceSNcerEntry(0x99);
                data_0217b450->mCells[a].mUnk_0c = func_020b4e70(v) != 0 ? 2 : 3;
                data_0217b450->mCells[a].mUnk_10 += 0x400;
                a++;
            }
        }
    }
    data_0217b450->mCellCount = a;
}

void func_020cd464(Unk020c06c4 *a) {
    DrawRaceHudSubScreenCells(a, data_0217b450, 1);
}

s32 func_020cd44c(void) {
    return CreateRaceHudSubScreenCells(&data_0217b44c, 0x67);
}

void func_020cd438(void) {
    ClearRaceHudSubScreenCells(&data_0217b44c);
}

void func_020cd328(void) {
    s32 i;
    s32 a;
    u32 n;
    Unk0217b498_00 *e;
    Vec3 *v;

    a = 0;
    n = func_020c0db0();
    for (i = 0; i < data_0217b44c->mObjectCount; i++) {
        if (IsRaceHudSubScreenPairNearCenter(&data_0217b44c->mUnk_0c[i]) != FALSE) {
            e = data_0217b44c->mObjects[i];
            if ((e->mFlags & 1) == 0) {
                v = &e->mPos;
                if (ComputeRaceHudSubScreenPosition(v, &data_0217b44c->mCells[a].mUnk_00, n, 0, 0) != FALSE) {
                    data_0217b44c->mCells[a].mUnk_08 = GetRaceSNcerEntry(0x5c);
                    data_0217b44c->mCells[a].mUnk_0c = func_020b4e70(v) != 0 ? 2 : 3;
                    a++;
                }
            }
        }
    }
    data_0217b44c->mCellCount = a;
}

void func_020cd30c(Unk020c06c4 *a) {
    DrawRaceHudSubScreenCells(a, data_0217b44c, 0);
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
            if (ComputeRaceHudSubScreenPosition(v, &gRaceHudSubScreenFlipperCells->mCells[a].mUnk_00, n, 1, 1) !=
                FALSE) {
                gRaceHudSubScreenFlipperCells->mCells[a].mUnk_08 = GetRaceSNcerEntry(0x90);
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
                if (data_021759c0->mUnk_57 != 0) {
                    func_020b4c74(v1, (u16) (d + (gRaceHudSubScreenFlipperCells->mCells[i].mUnk_10 + 0x4000)));
                } else {
                    func_020b4c74(v1, (u16) (0x4000 - gRaceHudSubScreenFlipperCells->mCells[i].mUnk_10 - d));
                }
            } else {
                if (data_021759c0->mUnk_57 != 0) {
                    func_020b4cb0(v1, (u16) (gRaceHudSubScreenFlipperCells->mCells[i].mUnk_10 + 0x4000 - d));
                } else {
                    func_020b4cb0(v1, (u16) (d + (0x4000 - gRaceHudSubScreenFlipperCells->mCells[i].mUnk_10)));
                }
            }
            k = func_020ae5c4(a);
            a->mUnk_000.mUnk_20[k].mUnk_06 = v1[0] >> 4;
            a->mUnk_000.mUnk_20[k].mUnk_0e = v1[1] >> 4;
            a->mUnk_000.mUnk_20[k].mUnk_16 = v1[2] >> 4;
            a->mUnk_000.mUnk_20[k].mUnk_1e = v1[3] >> 4;
            w = a->mUnk_400;
            x = &gRaceHudSubScreenFlipperCells->mCells[i];
            x0 = x->mUnk_00.mUnk_00;
            x8 = x->mUnk_08;
            x4 = x->mUnk_00.mUnk_04;
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
            if (ComputeRaceHudSubScreenPosition(&e->mPos, &gRaceHudSubScreenNsKiller2Cells->mCells[a].mUnk_00, n, 1,
                                                1) != FALSE) {
                gRaceHudSubScreenNsKiller2Cells->mCells[a].mUnk_08 = GetRaceSNcerEntry(0xad);
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

s32 func_020cce24(void) {
    return CreateRaceHudSubScreenCells(&data_0217b440, 0xcf);
}

void func_020cce10(void) {
    ClearRaceHudSubScreenCells(&data_0217b440);
}

void func_020cccf4(void) {
    s32 i;
    s32 a;
    u32 n;
    Unk0217b498_00 *e;
    Vec3 *v;

    a = 0;
    n = func_020c0db0();
    for (i = 0; i < data_0217b440->mObjectCount; i++) {
        e = data_0217b440->mObjects[i];
        if ((e->mFlags & 2) == 0) {
            v = &e->mPos;
            if (ComputeRaceHudSubScreenPosition(v, &data_0217b440->mCells[a].mUnk_00, n, 1, 1) != FALSE) {
                data_0217b440->mCells[a].mUnk_08 = GetRaceSNcerEntry(0xa0);
                data_0217b440->mCells[a].mUnk_0c = func_020b4e70(v) != 0 ? 2 : 3;
                data_0217b440->mCells[a].mUnk_0e = 0;
                data_0217b440->mCells[a].mUnk_10 = e->mAngle;
                a++;
            }
        }
    }
    data_0217b440->mCellCount = a;
}

void func_020cccd8(Unk020c06c4 *a) {
    DrawRaceHudSubScreenCells(a, data_0217b440, 1);
}
