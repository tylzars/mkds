#include "Main/Unknown/code_020a6cb4.h"
#include "Main/Unknown/code_020a10f0.h"

#include "Main/Unknown/code_020a1000.h"
#include "Main/Unknown/code_020a1218.h"
#include "Main/Unknown/code_020a3f2c.h"
#include "Main/Unknown/code_020ac524.h"
#include "Main/Unknown/code_0209bef0.h"
#include "Main/Unknown/code_020d3b10.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_021000d0.h"
#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020a7148.h"
#include "Main/Unknown/code_0209bf70.h"
#include "Main/Unknown/code_02077bc0.h"

void func_020a7148(MapObject *a) {
    if (CountMapObjectsOfKind(MAP_OBJECT_KIND_SHINE16) == 0) {
        CreateParkedMapObjects(MAP_OBJECT_KIND_SHINE16, 0x14, a);
        CreateParkedMapObjects(MAP_OBJECT_KIND_SHINE_BALLOON, gRaceSetup->mKartCount, a);
        SetStandingsKartHitCallback(func_020a72c8);
        SetStandingsKartEliminatedCallback(func_020a7270);
        SetStandingsEndCallback(func_020a71c8);
        return;
    }
    ParkMapObject(a);
}

BOOL func_020a6f94(Unk02100094 *a) {
    s32 i;
    s32 v1;
    Unk020a6cb4 *e;
    BOOL f;
    u32 n;
    u32 m;
    u32 r;
    u16 v2;
    u32 k;
    Unk020f41c4_B *g;

    v1 = 0;
    if (a != NULL) {
        for (i = 0; i < a->mUnk_04 && (e = a->mUnk_00[i]) != NULL; i++) {
            f = FALSE;
            if (e->mUnk_a0 == FALSE) {
                if (e->mUnk_a4 == FALSE) {
                    f = TRUE;
                }
            }
            v1 += f;
        }
    }
    if (v1 > 0) {
        n = (u16) v1;
        if (n == 0x10000) {
            g = func_020d22d0();
            g->mUnk_00 = (s64) g->mUnk_08 * (s64) g->mUnk_00 + g->mUnk_10;
            v2 = ((u64) (u32) (g->mUnk_00 >> 32) * 0x10000) >> 32;
        } else {
            g = func_020d22d0();
            if ((u16) n == 0) {
                r = 0;
            } else {
                g->mUnk_00 = (s64) g->mUnk_08 * (s64) g->mUnk_00 + g->mUnk_10;
                m = (u16) n;
                if (m == 0) {
                    r = g->mUnk_00 >> 32;
                } else {
                    r = ((g->mUnk_00 >> 32) * m) >> 32;
                }
            }
            v2 = r;
        }
        k = v2;
        if (a != NULL) {
            for (i = 0; i < a->mUnk_04 && (e = a->mUnk_00[i]) != NULL; i++) {
                if (e->mUnk_a0 == FALSE && e->mUnk_a4 == FALSE) {
                    if (k-- == 0) {
                        StartShine16(&e->mUnk_00.mPos, i, 1);
                        e->mUnk_a0 = TRUE;
                        return TRUE;
                    }
                }
            }
        }
    }
    return FALSE;
}

void func_020a6e70(Unk02100094 *a) {
    s32 i;
    s32 n;
    s32 j;
    s32 v;
    BOOL f;
    Unk020a6cb4 *e;

    n = gRaceSetup->mKartCount;
    for (i = 0; i < n; i++) {
        if (i == gRaceSetup->mEntryIndex) {
            f = FALSE;
            v = gRaceSetup->mCurrentEntries[(u16) i].mPlayer.mKind;
            if ((u32) v <= 3) {
                if ((1 << v) & PLAYER_KIND_MASK_HUMAN_GHOST_PEER) {
                    f = TRUE;
                }
            }
            if (f != FALSE) {
                continue;
            }
        }
        StartShineBalloon(GetKart((u16) i));
    }
    if (a == NULL) {
        return;
    }
    for (j = 0; j < a->mUnk_04 && (e = a->mUnk_00[j]) != NULL; j++) {
        e->mUnk_a4 = TRUE;
        if (e->mUnk_00.mCourseMapRow->mUnk_28 != 0) {
            n = gRaceSetup->mKartCount;
            v = GetShineCount();
            if (v + GetTotalBalloonOrShineCount() < n + 1) {
                StartShine16(&e->mUnk_00.mPos, j, GetRaceUseChainCameras());
                e->mUnk_a0 = TRUE;
            }
        }
    }
}

void func_020a6d8c(Unk02100094 *a, Unk020a6cb4 *b) {
    s32 n;
    s32 v;

    if (GetShineCount() >= 3) {
        return;
    }
    n = gRaceSetup->mKartCount;
    v = GetShineCount();
    if (v + GetTotalBalloonOrShineCount() >= n + 1) {
        return;
    }
    b->mUnk_a8 += 1;
    if (b->mUnk_a8 <= 0x5a) {
        return;
    }
    b->mUnk_a8 = 0;
    while (GetShineCount() < 3 &&
           (n = gRaceSetup->mKartCount, v = GetShineCount(), v + GetTotalBalloonOrShineCount() < n + 1)) {
        if (func_020a6f94(a) == FALSE) {
            return;
        }
    }
}

s32 func_020a6d40(void) {
    if (gRaceSetup->mMode == MODE_BATTLE && gRaceSetup->mBattleKind == BATTLE_KIND_SHINE) {
        return CreateEmptyMapObjectKindData();
    }
    return 0;
}

void *func_020a6d20(void) {
    return CreateMapObjectUpdateList(func_020a6e70, func_020a6d8c, NULL);
}

void func_020a6cb4(s32 a) {
    Unk02100094 *v1;
    Unk020a6cb4 *e;
    s32 i;

    v1 = func_02100138(0x6b);
    if (v1 == NULL) {
        return;
    }
    for (i = 0; i < v1->mUnk_04 && (e = v1->mUnk_00[i]) != NULL; i++) {
        if (i == a) {
            e->mUnk_a0 = FALSE;
            e->mUnk_a4 = TRUE;
        } else {
            e->mUnk_a4 = FALSE;
        }
    }
}
