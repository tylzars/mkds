#include "Main/Unknown/code_02094e1c.h"
#include "Main/Unknown/code_020ac524.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_020ac000.h"

#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_02093ff0.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020918a8.h"
#include "Main/Unknown/code_0209bef0.h"
#include "Main/Unknown/code_020d26e0.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_0209bf70.h"
#include "Main/Unknown/code_02077bc0.h"
#include "Main/Unknown/code_021000d0.h"

void func_020954e4(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    value2 = value0;
    value1 = *(const u32 *) ((value2) + (156));
    value0 = MAP_OBJECT_KIND_TERESA;
    value1 = *(const s16 *) ((value1) + (42));
    CreateParkedMapObjects(value0, value1, (void *) value2);
}

static inline u32 func_02095228_inline(Unk020f41c4_B *b, u32 n) {
    b->mValue = b->mMultiplier * b->mValue + b->mIncrement;
    if (n == 0) {
        return b->mValue >> 32;
    }
    return ((b->mValue >> 32) * n) >> 32;
}

static inline u16 func_020952dc_inline(u32 n) {
    Unk020f41c4_B *r;
    u32 t;
    u32 m;
    if (n == 0x10000) {
        r = &gRaceProgress->mLocalRandom;
        r->mValue = r->mMultiplier * r->mValue + r->mIncrement;
        return (r->mValue >> 32) * 0x10000 >> 32;
    }
    r = &gRaceProgress->mLocalRandom;
    m = (u16) n;
    if (m == 0) {
        t = 0;
    } else {
        r->mValue = r->mMultiplier * r->mValue + r->mIncrement;
        if (m == 0) {
            t = r->mValue >> 32;
        } else {
            t = ((r->mValue >> 32) * m) >> 32;
        }
    }
    return t;
}

void func_020952dc(Unk02094e8c *a, s32 b, s32 c, s32 d, s32 e) {
    s32 i;
    s32 k;
    s32 x;
    s32 y;
    s32 z;
    float f;
    u32 r;
    u16 q;
    Vec3 v;

    if (GetUnparkedTeresaCount() < b) {
        k = i = 0;
        for (; i < c; i++) {
            if (d > 0) {
                f = 0.5f + (d << 12);
            } else {
                f = (d << 12) - 0.5f;
            }
            z = 0;
            y = a->mUnk_00.mPos.y;
            x = 0;
            r = NextRandomBelow(GetRaceLocalRandom(), (s32) f);
            q = func_020951b4(GetRaceLocalRandom());
            v.x = x + func_0209518c(r, func_0209519c(q));
            v.y = y + NextRandomBelow(GetRaceLocalRandom(), k);
            v.z = z + func_0209518c(r, func_0209516c(q));
            StartTeresa(&v);
        }
        a->mUnk_a8 = func_020952dc_inline((u16) e);
    }
}

void func_02095228(Unk02095228 *a) {
    s32 i;
    Unk02094e8c *o;

    if (a == NULL) {
        return;
    }
    for (i = 0; i < a->mUnk_04 && (o = a->mUnk_00[i]) != NULL; i++) {
        o->mUnk_a0 = (u16) func_02095228_inline(&gRaceProgress->mLocalRandom, 0xf);
    }
}

Unk020f41c4_B *GetRaceLocalRandom(void) {
    return &gRaceProgress->mLocalRandom;
}

u16 func_020951b4(Unk020f41c4_B *a) {
    a->mValue = a->mMultiplier * a->mValue + a->mIncrement;
    return ((a->mValue >> 32) * 0x10000) >> 32;
}

s16 func_0209519c(s32 a) {
    return gPairsByAngle[(a >> 4) * 2];
}

s32 func_0209518c(s32 a, s32 b) {
    return ((s64) a * b) >> 12;
}

s16 func_0209516c(s32 a) {
    return gPairsByAngle[(a >> 4) * 2 + 1];
}

void func_02094e8c(void *a, Unk02094e8c *o) {
    s32 t;
    s32 c;
    s32 e;
    s32 v1;
    s32 v2;
    s32 i;
    BOOL k;
    s32 x;
    s32 y;
    s32 z;
    float f;
    u32 r;
    u16 q;
    Kart *g;
    Vec3 v;
    Vec3 *q2;

    t = o->mUnk_a0;
    o->mUnk_a0 = t - 1;
    if (t <= 0) {
        o->mUnk_a0 = 0xf;
        c = o->mUnk_00.mCourseMapRow->mUnk_28;
        g = GetKart((u16) gRaceSetup->mEntryIndex);
        e = c << 12;
        q2 = &g->mPos;
        v1 = q2->x - o->mUnk_00.mPos.x;
        v2 = q2->z - o->mUnk_00.mPos.z;
        if ((s64) v1 * v1 + (s64) v2 * v2 < (s64) e * e) {
            o->mUnk_a4 = TRUE;
        } else {
            o->mUnk_a4 = FALSE;
        }
    }
    switch (o->mUnk_ac) {
        case 0:
            k = FALSE;
            if (GetCurrentCameraKind() == 2) {
                for (i = 0; i < o->mUnk_00.mCourseMapRow->mUnk_2a; i++) {
                    if (o->mUnk_00.mCourseMapRow->mUnk_28 > 0) {
                        f = 0.5f + (o->mUnk_00.mCourseMapRow->mUnk_28 << 12);
                    } else {
                        f = (o->mUnk_00.mCourseMapRow->mUnk_28 << 12) - 0.5f;
                    }
                    z = o->mUnk_00.mPos.z;
                    y = o->mUnk_00.mPos.y;
                    x = o->mUnk_00.mPos.x;
                    r = NextRandomBelow(GetRaceLocalRandom(), (s32) f);
                    q = func_020951b4(GetRaceLocalRandom());
                    v.x = x + func_0209518c(r, func_0209519c(q));
                    v.y = y + NextRandomBelow(GetRaceLocalRandom(), k);
                    v.z = z + func_0209518c(r, func_0209516c(q));
                    StartTeresa(&v);
                }
            }
            o->mUnk_ac = 1;
        case 1:
            if (GetCurrentCameraKind() == 2) {
                break;
            }
            if (o->mUnk_a4 == FALSE) {
                break;
            }
            if (GetCurrentCameraKind() != 0) {
                func_020952dc(o, 0x1e, 0x14, 0x1f4, 4);
            } else {
                func_020952dc(o, 6, 4, 0xa, 0x14);
            }
            o->mUnk_ac = 2;
            break;
        case 2:
            t = o->mUnk_a8;
            o->mUnk_a8 = t - 1;
            if (t > 0) {
                break;
            }
            if (o->mUnk_a4 != FALSE) {
                if (GetCurrentCameraKind() != 0) {
                    func_020952dc(o, 0x1e, 1, 0x1f4, 4);
                } else {
                    func_020952dc(o, 6, 1, 0xa, 0x14);
                }
            } else {
                ClearTeresaTimers();
                o->mUnk_ac = 1;
            }
            break;
    }
    if (GetUnparkedTeresaCount() > 0) {
        func_020d26e0(GetKart((u16) gRaceSetup->mEntryIndex), 0x11e);
    }
}

u32 func_02094e3c(void) {
    s32 m;

    m = gRaceSetup->mMode;
    if (m == MODE_VS || m == 5) {
        if (GetCurrentCameraKind() == 0) {
            return 0;
        }
    }
    return CreateEmptyMapObjectKindData();
}

void func_02094e1c(void) {
    CreateMapObjectUpdateList(func_02095228, func_02094e8c, NULL);
}
