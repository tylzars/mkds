#include "Main/Unknown/code_02093ff0.h"
#include "Main/Unknown/code_0209b634.h"
#include "Main/Unknown/code_020d2000.h"

#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_02073eb8.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_021000d0.h"
#include "Main/Unknown/code_02102674.h"
#include "Main/Unknown/unk_0217b000.h"
#include "code_02148538.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_0209bef0.h"
#include "Main/Unknown/code_020d3b10.h"
#include "Main/Unknown/code_020e6b58.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_02166000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_02077bc0.h"

u32 InitTeresa(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    ParkMapObject((void *) value0);
    value0 = (u32) &gUnparkedTeresaCount;
    value1 = 0u;
    *(u32 *) ((value0) + (0)) = value1;
    return value0;
}

void CreateTeresa(Unk02094db4 *a) {
    gTeresa = CreateMapObjectModelNsbmdNsbtp(a, gTeresaNsbmdName, gTeresaNsbtpName);
    SetMapObjectModelPolygonId(gTeresa, 0x3f);
    a->mUnk_1c = 1;
}

void SetupDrawTeresa(void *a) {
    func_0209bbd0(a, gTeresa);
}

void DrawTeresa(void *a, Teresa *b) {
    s32 w;
    s32 v[3];

    if (b->mUnk_ac == 0) {
        return;
    }
    GetKart((u16) gRaceSetup->mEntryIndex);
    SetMapObjectModelPolygonId(gTeresa, AllocPolygonIdWrapping());
    SetMapObjectModelNsbtpFrameIndex(gTeresa, b->mUnk_ae);
    SetMapObjectModelAlpha(gTeresa, b->mUnk_ac);
    SetMapObjectModelFogEnabled(gTeresa, IsFadeFogActive());
    SetMapObjectModelMirror(gTeresa, b->mUnk_b0, 0);
    w = 0x1e;
    func_01ff9048(0x14, &w, 1);
    func_01ff9048(0x19, SetViewTransposeMatrixPos(&b->mUnk_00.mPos), 0xc);
    if (GetCurrentCameraKind() == 2) {
        v[0] = 0x2000;
        v[1] = 0x2000;
        v[2] = 0x2000;
        func_01ff9048(0x1b, v, 3);
    }
    func_01ff9048(0x1b, &b->mUnk_00.mScale, 3);
    DrawMapObjectModel(a, gTeresa, b);
}

static inline void func_02094768_inline(Teresa *o) {
    o->mUnk_fc = o->mUnk_fc + o->mUnk_100;
    if (o->mUnk_fc >= o->mUnk_108) {
        o->mUnk_100 = -o->mUnk_100;
        o->mUnk_fc = o->mUnk_108 * 2 - o->mUnk_fc;
    } else if (o->mUnk_fc <= o->mUnk_104) {
        o->mUnk_100 = -o->mUnk_100;
        o->mUnk_fc = o->mUnk_104 * 2 - o->mUnk_fc;
    }
    o->mUnk_ac = o->mUnk_fc >> 12;
}

static inline void func_02094768_inline_2(s32 *p, s32 *q) {
    s32 k = *p;
    if (k > 0) {
        k += *q;
        if (k <= 0) {
            k = 0;
        }
        *p = k;
    } else if (k < 0) {
        k += *q;
        if (k >= 0) {
            k = 0;
        }
        *p = k;
    }
}

// Gives each Teresa two values from its place in the list: bit 0 and bit 1 of its index.
void InitTeresaObjects(Unk020946b8 *a) {
    s32 i;
    Teresa *o;

    if (a == NULL) {
        return;
    }
    for (i = 0; i < a->mUnk_04 && (o = a->mUnk_00[i]) != NULL; i++) {
        o->mUnk_ae = i & 1;
        o->mUnk_b0 = (i / 2) & 1;
    }
}

s16 func_02094c0c(s32 a) {
    return gPairsByAngle[(a >> 4) * 2];
}

s32 func_02094bf0(s32 a, s32 b) {
    return ((s64) a * b + 0x800) >> 12;
}

s16 func_02094bd0(s32 a) {
    return gPairsByAngle[(a >> 4) * 2 + 1];
}

void UpdateTeresa(void *a, Teresa *o) {
    s32 t;
    s32 x;
    s32 y;
    u16 w;
    s32 n;
    s32 m;
    Kart *g;

    switch (o->mState) {
        case 1:
            t = o->mUnk_b4;
            o->mUnk_b4 = t - 1;
            if (t <= 0) {
                o->mUnk_b4 = 0;
                func_02094768_inline(o);
                if (o->mUnk_fc >= 0x2000) {
                    o->mState = 0;
                }
            }
            break;
        case 0:
            t = o->mUnk_b8;
            o->mUnk_b8 = t - 1;
            if (t <= 0) {
                o->mUnk_b8 = 0;
                o->mUnk_fc = o->mUnk_fc - 0x1000;
                if (o->mUnk_fc > 0) {
                    o->mUnk_ac = o->mUnk_fc >> 12;
                } else {
                    o->mUnk_ac = 0;
                    ParkMapObject(&o->mUnk_00);
                    gUnparkedTeresaCount--;
                }
            } else {
                func_02094768_inline(o);
            }
            break;
    }
    if (o->mUnk_b8 <= 0) {
        return;
    }
    o->mUnk_bc.mUnk_00 = o->mUnk_bc.mUnk_00 + o->mUnk_bc.mUnk_18;
    x = func_02094bf0(o->mUnk_bc.mUnk_10, func_02094c0c(o->mUnk_bc.mUnk_00));
    o->mUnk_bc.mUnk_08 = o->mUnk_bc.mUnk_0c + x - o->mUnk_bc.mUnk_04;
    o->mUnk_bc.mUnk_04 = o->mUnk_bc.mUnk_04 + o->mUnk_bc.mUnk_08;
    func_02094768_inline_2(&o->mUnk_bc.mUnk_10, &o->mUnk_bc.mUnk_14);
    func_02094768_inline_2(&o->mUnk_bc.mUnk_18, &o->mUnk_bc.mUnk_1c);
    w = o->mUnk_bc.mUnk_04;
    o->mUnk_dc.mUnk_00 = o->mUnk_dc.mUnk_00 + o->mUnk_dc.mUnk_18;
    y = func_02094bd0(o->mUnk_dc.mUnk_00);
    x = func_02094bf0(o->mUnk_dc.mUnk_10 / 2, 0x1000 - y);
    o->mUnk_dc.mUnk_08 = o->mUnk_dc.mUnk_0c + x - o->mUnk_dc.mUnk_04;
    o->mUnk_dc.mUnk_04 = o->mUnk_dc.mUnk_04 + o->mUnk_dc.mUnk_08;
    func_02094768_inline_2(&o->mUnk_dc.mUnk_10, &o->mUnk_dc.mUnk_14);
    func_02094768_inline_2(&o->mUnk_dc.mUnk_18, &o->mUnk_dc.mUnk_1c);
    m = o->mUnk_dc.mUnk_04;
    n = o->mUnk_10c;
    if (GetCurrentCameraKind() == 2) {
        o->mUnk_00.mPos.x = o->mUnk_a0.x + (s32) (((s64) n * gPairsByAngle[(w >> 4) * 2 + 1]) >> 12);
        o->mUnk_00.mPos.y = o->mUnk_a0.y + m;
        o->mUnk_00.mPos.z = o->mUnk_a0.z + (s32) (((s64) n * gPairsByAngle[(w >> 4) * 2]) >> 12);
    } else {
        g = GetKart((u16) gRaceSetup->mEntryIndex);
        o->mUnk_00.mPos.x = g->mPos.x + (o->mUnk_a0.x + (s32) (((s64) n * gPairsByAngle[(w >> 4) * 2 + 1]) >> 12));
        o->mUnk_00.mPos.y = o->mUnk_a0.y + m;
        o->mUnk_00.mPos.z = g->mPos.z + (o->mUnk_a0.z + (s32) (((s64) n * gPairsByAngle[(w >> 4) * 2]) >> 12));
    }
}

void CreateTeresaDrawList(void) {
    CreateMapObjectDrawList2(CreateTeresa, DrawTeresa, SetupDrawTeresa);
}

void CreateTeresaUpdateList(void) {
    CreateMapObjectUpdateList(InitTeresaObjects, UpdateTeresa, NULL);
}

void ClearTeresaTimers(void) {
    Unk020946b8 *l;
    Teresa *o;
    s32 i;

    l = func_02100138(MAP_OBJECT_KIND_TERESA);
    if (l == NULL) {
        return;
    }
    for (i = 0; i < l->mUnk_04 && (o = l->mUnk_00[i]) != NULL; i++) {
        o->mUnk_b4 = 0;
        o->mUnk_b8 = 0;
    }
}

static inline u32 func_02094000_inline(RandomState64 *b, u32 n) {
    b->mValue = b->mMultiplier * b->mValue + b->mIncrement;
    if (n == 0) {
        return b->mValue >> 32;
    }
    return ((b->mValue >> 32) * n) >> 32;
}

static inline void func_02094000_inline_2(Unk02094000_bc *p, u16 a, s32 b, s32 c, s32 d, s32 e, s32 f) {
    p->mUnk_00 = a;
    p->mUnk_0c = b;
    p->mUnk_10 = c;
    p->mUnk_14 = d;
    p->mUnk_18 = e;
    p->mUnk_1c = f;
}

void StartTeresa(Vec3 *a) {
    Teresa *o;
    Camera *g;
    s32 p;
    s32 q;
    s32 e;
    s16 c;
    u16 b;
    s32 k;
    s32 d;
    s32 f;

    o = UnparkFirstParkedMapObject(func_02100138(MAP_OBJECT_KIND_TERESA));
    if (o == NULL) {
        return;
    }
    o->mUnk_ac = 0;
    o->mUnk_a0 = *a;
    if (GetCurrentCameraKind() == 0) {
        g = GetChaseCamera();
        e = func_02094000_inline(&gRaceProgress->mLocalRandom, 0x30);
        c = (u16) (func_02094000_inline(&gRaceProgress->mLocalRandom, 0) >> 20);
        b = func_02094000_inline(&gRaceProgress->mLocalRandom, 0x5555);
        k = FX_Atan2Idx(g->mLookAt.z - g->mPos.z, g->mLookAt.x - g->mPos.x) + b - 0x2aaa;
        func_02094000_inline_2(&o->mUnk_bc, func_02094000_inline(&gRaceProgress->mLocalRandom, 0x10000), k, c + 0x1000,
                               0, e + 0x60, 0);
    } else {
        e = func_02094000_inline(&gRaceProgress->mLocalRandom, 0x30);
        c = (u16) (func_02094000_inline(&gRaceProgress->mLocalRandom, 0) >> 20);
        func_02094000_inline_2(&o->mUnk_bc, func_02094000_inline(&gRaceProgress->mLocalRandom, 0x10000),
                               (u16) func_02094000_inline(&gRaceProgress->mLocalRandom, 0x10000), c + 0x1000, 0,
                               e + 0x60, 0);
    }
    d = func_02094000_inline(&gRaceProgress->mLocalRandom, 0x80);
    f = func_02094000_inline(&gRaceProgress->mLocalRandom, 0xa000);
    func_02094000_inline_2(&o->mUnk_dc, 0, func_02094000_inline(&gRaceProgress->mLocalRandom, 0x19000) + 0x19000,
                           f + 0xa000, 0, d + 0x100, 0);
    o->mUnk_10c = func_02094000_inline(&gRaceProgress->mLocalRandom, 0x3c000) + 0x3c000;
    p = func_02094000_inline(&gRaceProgress->mLocalRandom, 0xc000) + 0xe000;
    q = func_02094000_inline(&gRaceProgress->mLocalRandom, 0x200) + 0x400;
    o->mUnk_fc = 0;
    o->mUnk_100 = q;
    o->mUnk_104 = 0x2000;
    o->mUnk_108 = p;
    if (GetCurrentCameraKind() == 2) {
        o->mUnk_b4 = 0;
        o->mUnk_b8 = 0xffff;
        o->mState = 0;
    } else {
        o->mUnk_b4 = (u16) func_02094000_inline(&gRaceProgress->mLocalRandom, 0x4b);
        o->mUnk_b8 = (u16) func_02094000_inline(&gRaceProgress->mLocalRandom, 0x96) + 0x12c;
        o->mState = 1;
    }
    gUnparkedTeresaCount++;
}

s32 GetUnparkedTeresaCount(void) {
    return gUnparkedTeresaCount;
}
