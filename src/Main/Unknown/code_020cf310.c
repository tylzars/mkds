#include "Main/Unknown/code_020cf310.h"
#include "Main/Unknown/code_02062ed8.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_02062000.h"
#include "Main/Unknown/code_020b6000.h"
#include "Main/Unknown/code_020c0000.h"
#include "Main/Unknown/code_020c0ba8.h"
#include "Main/Unknown/code_020d3dbc.h"
#include "Main/Unknown/code_020df890.h"
#include "Main/Unknown/code_020e3b08.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_02100084.h"
#include "Main/Unknown/code_021000d0.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "code_0200eddc.h"
#include "code_0214b338.h"

// placeholder: an object of the original file that is not known yet; it only sets the order of the tables below
u8 data_020cfca4_pad[24];

void func_020cfca4(void) {
    s32 i;
    s32 j;

    switch (gRaceSetup->mCourseId) {
        case COURSE_ID_OLD_NOKO_SFC:
            for (i = 0; i < 9; i++) {
                for (j = 0; j < 3; j++) {
                    data_0217b490->mUnk_02.mUnk_01[i][j] = ((u16 *) 0x05000400)[i * 16 + j + 0x40];
                }
            }
            break;
        case 0x11: {
            s32 table[5] = {0, 5, 10, 16, 21};

            for (i = 0; i < 5; i++) {
                for (j = 0; j < 4; j++) {
                    data_0217b490->mUnk_02.mUnk_02[i][j] = ((u16 *) 0x05000400)[table[i] + j + 0x80];
                }
            }
            break;
        }
        case COURSE_ID_TOWN:
            for (i = 0; i < 20; i++) {
                data_0217b490->mUnk_02.mUnk_00[i] = ((u16 *) 0x05000400)[0x78 + i];
            }
            data_0217b490->mUnk_02.mUnk_00[20] = ((u16 *) 0x05000400)[0];
            break;
        case COURSE_ID_BEACH:
            for (i = 0; i < 3; i++) {
                data_0217b490->mUnk_02.mUnk_00[i] = ((u16 *) 0x05000400)[0x46 + i];
            }
            break;
        case COURSE_ID_KOOPA:
            for (i = 0; i < 6; i++) {
                data_0217b490->mUnk_02.mUnk_03.mUnk_00[i] = ((u16 *) 0x05000400)[0x54 + i];
            }
            for (i = 0; i < 2; i++) {
                for (j = 0; j < 3; j++) {
                    data_0217b490->mUnk_02.mUnk_03.mUnk_0c[i][j] = ((u16 *) 0x05000400)[i * 3 + j + 0x5a];
                }
            }
            for (i = 0; i < 2; i++) {
                data_0217b490->mUnk_02.mUnk_03.mUnk_18[i] = ((u16 *) 0x05000400)[i];
            }
            break;
        case COURSE_ID_MINI_STAGE3:
            for (i = 0; i < 5; i++) {
                data_0217b490->mUnk_02.mUnk_00[i] = ((u16 *) 0x05000400)[0xfb + i];
            }
            break;
    }
    data_0217b490->mUnk_00 = 0;
}

void UpdateRaceHudSubScreenBgPalette(RaceHudSubScreenBgPalette *palette) {
    s32 i;
    s32 j;
    s32 shift;
    s32 n;
    s32 k;
    s32 v;
    u32 waterAngle;
    float threshold;

    switch (gRaceSetup->mCourseId) {
        case COURSE_ID_OLD_NOKO_SFC:
            v = GetCourseModelNsbtpFrame();
            for (i = 0; i < 3; i++) {
                palette->mUnk_00[i + 0x40] = data_0217b490->mUnk_02.mUnk_01[v / 10][i];
            }
            DC_FlushRange(&palette->mUnk_00[0x40], 6);
            GXS_BeginLoadBGExtPltt();
            GXS_LoadBGExtPltt(&palette->mUnk_00[0x40], 0x4080, 6);
            if (IsCourseWithMap2DLocal3() != 0) {
                GXS_LoadBGExtPltt(&palette->mUnk_00[0x40], 0x6080, 6);
            }
            GXS_EndLoadBGExtPltt();
            break;
        case 0x11: {
            s32 table[5] = {0, 5, 10, 16, 21};
            Unk0217b498_00 **objects;
            void *p;
            u16 angle;

            p = FindMapObjectKindDrawList0(0xcb);
            if (p != NULL) {
                objects = RaceHudSubScreenGetMapObjects(p);
                for (i = 0; i < 5; i++) {
                    angle = objects[i]->mAngle;
                    if (i == 4) {
                        shift = (angle * 0xb4) >> 16;
                    } else {
                        shift = (angle * 0x48) >> 16;
                    }
                    for (j = 0; j < 4; j++) {
                        palette->mUnk_00[table[i] + j + 0x80] = data_0217b490->mUnk_02.mUnk_02[i][(j + shift) % 4];
                    }
                }
            }
            DC_FlushRange(&palette->mUnk_00[0x80], 0x34);
            GXS_BeginLoadBGExtPltt();
            GXS_LoadBGExtPltt(&palette->mUnk_00[0x80], 0x4100, 0x34);
            if (IsCourseWithMap2DLocal3() != 0) {
                GXS_LoadBGExtPltt(&palette->mUnk_00[0x80], 0x6100, 0x34);
            }
            GXS_EndLoadBGExtPltt();
            break;
        }
        case 0x1c: {
            u8 table[6][20] = {{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19},
                               {20, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19},
                               {20, 20, 1, 2, 3, 4, 5, 6, 7, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19},
                               {20, 20, 20, 1, 2, 3, 4, 5, 6, 7, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18},
                               {20, 20, 20, 20, 1, 2, 3, 4, 5, 6, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18},
                               {20, 20, 20, 20, 20, 1, 2, 3, 4, 5, 6, 9, 10, 11, 12, 13, 14, 15, 16, 17}};
            u8 *p;

            v = func_020e3b08();
            if (v < 0x13) {
                j = 0;
            } else if (v < 0x2c) {
                j = 1;
            } else if (v < 0x38) {
                j = 2;
            } else if (v < 0x43) {
                j = 3;
            } else if (v < 0x4c) {
                j = 4;
            } else {
                j = 5;
            }
            p = table[j];
            for (i = 0; i < 20; i++) {
                palette->mUnk_00[i + 0x78] = data_0217b490->mUnk_02.mUnk_00[*p];
                p++;
            }
            DC_FlushRange(&palette->mUnk_00[0x78], 0x28);
            GXS_BeginLoadBGExtPltt();
            GXS_LoadBGExtPltt(&palette->mUnk_00[0x78], 0x40f0, 0x28);
            if (IsCourseWithMap2DLocal3() != 0) {
                GXS_LoadBGExtPltt(&palette->mUnk_00[0x78], 0x60f0, 0x28);
            }
            GXS_EndLoadBGExtPltt();
            break;
        }
        case COURSE_ID_BEACH:
            if (IsWaterPresent() != FALSE) {
                n = GetWaterHeightFactor();
                for (k = 7; k > 0; k--) {
                    threshold = (7 - k) * 0.286f + -0.858f;
                    v = threshold > 0.0f ? threshold * 4096.0f + 0.5f : threshold * 4096.0f - 0.5f;
                    if (n < v) {
                        break;
                    }
                }
                for (j = 0; j < k; j++) {
                    palette->mUnk_00[j + 0x50] = data_0217b490->mUnk_02.mUnk_00[0];
                }
                for (j = k; j == k; j++) {
                    palette->mUnk_00[j + 0x50] = data_0217b490->mUnk_02.mUnk_00[1];
                }
                for (j = k + 1; j < 8; j++) {
                    palette->mUnk_00[j + 0x50] = data_0217b490->mUnk_02.mUnk_00[2];
                }
            }
            DC_FlushRange(&palette->mUnk_00[0x50], 0x10);
            GXS_BeginLoadBGExtPltt();
            GXS_LoadBGExtPltt(&palette->mUnk_00[0x50], 0x40a0, 0x10);
            if (IsCourseWithMap2DLocal3() != 0) {
                GXS_LoadBGExtPltt(&palette->mUnk_00[0x50], 0x60a0, 0x10);
            }
            GXS_EndLoadBGExtPltt();
            break;
        case 0x20: {
            void *p;
            Unk0217b498_00 **objects;
            Unk020e005c **blocks;

            p = FindMapObjectKindDrawList0(0xd0);
            if (p != NULL) {
                objects = RaceHudSubScreenGetMapObjects(p);
                v = (objects[1]->mAngle * 0x48) >> 16;
                for (i = 0; i < 6; i++) {
                    palette->mUnk_00[i + 0x54] = data_0217b490->mUnk_02.mUnk_03.mUnk_00[(i + 0x48 - v) % 6];
                }
                k = (objects[0]->mAngle << 5) >> 16;
                for (i = 0; i < 2; i++) {
                    for (j = 0; j < 3; j++) {
                        palette->mUnk_00[j + i * 3 + 0x5a] =
                            data_0217b490->mUnk_02.mUnk_03.mUnk_0c[i][(j + 0x20 - k) % 3];
                    }
                }
            }
            p = FindMapObjectKindDrawList0(MAP_OBJECT_KIND_KOOPA_BLOCK);
            if (p != NULL) {
                blocks = RaceHudSubScreenGetMapObjects(p);
                for (i = 0; i < 4; i++) {
                    v = func_020dff4c(blocks[i]);
                    if (i % 2 != 0) {
                        n = (v << 3) >> 12;
                    } else {
                        n = 8 - ((v << 3) >> 12);
                    }
                    for (j = 0; j < n; j++) {
                        palette->mUnk_00[i * 16 + j + 0x60] = data_0217b490->mUnk_02.mUnk_03.mUnk_18[0];
                    }
                    for (j = n; j < n + 8; j++) {
                        palette->mUnk_00[i * 16 + j + 0x60] = data_0217b490->mUnk_02.mUnk_03.mUnk_18[1];
                    }
                    for (j = n + 8; j < 16; j++) {
                        palette->mUnk_00[i * 16 + j + 0x60] = data_0217b490->mUnk_02.mUnk_03.mUnk_18[0];
                    }
                }
            }
            DC_FlushRange(&palette->mUnk_00[0x54], 0x98);
            GXS_BeginLoadBGExtPltt();
            GXS_LoadBGExtPltt(&palette->mUnk_00[0x54], 0x40a8, 0x98);
            if (IsCourseWithMap2DLocal3() != 0) {
                GXS_LoadBGExtPltt(&palette->mUnk_00[0x54], 0x60a8, 0x98);
            }
            GXS_EndLoadBGExtPltt();
            break;
        }
        case COURSE_ID_MINI_STAGE3:
            if (IsWaterPresent() != FALSE) {
                n = GetWaterHeightFactor();
                waterAngle = GetWaterHeightAngle();
                for (k = 0; k < 0x13; k++) {
                    threshold = k * 0.105f + -0.945f;
                    v = threshold > 0.0f ? threshold * 4096.0f + 0.5f : threshold * 4096.0f - 0.5f;
                    if (n < v) {
                        break;
                    }
                }
                k += 2;
                for (j = 0; j < k - 2; j++) {
                    palette->mUnk_00[j + 0xe0] = data_0217b490->mUnk_02.mUnk_00[0];
                }
                for (j = k - 4; j < k - 2; j++) {
                    if (j >= 0) {
                        palette->mUnk_00[j + 0xe0] = data_0217b490->mUnk_02.mUnk_00[1];
                    }
                }
                for (j = k - 2; j <= k; j++) {
                    palette->mUnk_00[j + 0xe0] = data_0217b490->mUnk_02.mUnk_00[2];
                }
                if (waterAngle >= 0x4000 && waterAngle < 0xc000) {
                    for (j = k + 1; j <= k + 2 && j < 0x15; j++) {
                        palette->mUnk_00[j + 0xe0] = data_0217b490->mUnk_02.mUnk_00[3];
                    }
                    k += 2;
                }
                for (j = k + 1; j < 0x15; j++) {
                    palette->mUnk_00[j + 0xe0] = data_0217b490->mUnk_02.mUnk_00[4];
                }
            }
            DC_FlushRange(&palette->mUnk_00[0xe0], 0x2c);
            GXS_BeginLoadBGExtPltt();
            GXS_LoadBGExtPltt(&palette->mUnk_00[0xe0], 0x41c0, 0x2c);
            if (IsCourseWithMap2DLocal3() != 0) {
                GXS_LoadBGExtPltt(&palette->mUnk_00[0xe0], 0x61c0, 0x2c);
            }
            GXS_EndLoadBGExtPltt();
            break;
    }
}

s32 CreateRaceHudSubScreenBombKouraWCells(void) {
    s32 itemCount;

    itemCount = 0;
    itemCount += gItemKinds[5].mObjectCount;
    itemCount += gItemKinds[9].mObjectCount;
    return CreateRaceHudSubScreenCellsWithCount(&gRaceHudSubScreenBombKouraWCells, itemCount);
}
