#include "Main/Unknown/code_02092b3c.h"
#include "Main/Unknown/code_020918a8.h"
#include "Main/Unknown/code_020ac000.h"

#include "Main/Unknown/code_0209219c.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Unknown/code_020ac524.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_0209bef0.h"
#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "code_02147cd8.h"
#include "code_02148538.h"
#include "Main/Unknown/code_02045874.h"
#include "Main/Unknown/code_02077bc0.h"
#include "Main/Unknown/code_021000d0.h"

void func_02093190(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    u32 value12;
    value2 = value0;
    value0 = MAP_OBJECT_KIND_BASABASA;
    value1 = 8u;
    CreateParkedMapObjects(value0, value1, (void *) value2);
}

static inline u32 func_02092b5c_inline(u32 n) {
    Unk020f41c4_B *b;

    b = func_020d22d0();
    b->mUnk_00 = b->mUnk_08 * b->mUnk_00 + b->mUnk_10;
    return ((b->mUnk_00 >> 32) * n) >> 32;
}

static inline u16 func_02092b5c_inline_2(u32 n) {
    Unk020f41c4_B *b;

    b = func_020d22d0();
    b->mUnk_00 = b->mUnk_08 * b->mUnk_00 + b->mUnk_10;
    return (u32) (((b->mUnk_00 >> 32) * n) >> 32);
}

void func_020930c8(MapObjectList *a) {
    s32 i;
    Unk020919e8 *p;

    if (a == NULL) {
        return;
    }
    for (i = 0; i < a->mMapObjectCount && (p = a->mMapObjects[i]) != NULL; i++) {
        if (p->mUnk_00.mFlags & 0x800) {
            p->mUnk_a4 = (u16) (func_02092b5c_inline_2(25) + 200);
        }
    }
}

static inline s64 func_02092b5c_inline_4(const Vec3 *a, const Vec3 *b) {
    s32 v1;
    s32 v2;

    v1 = a->x - b->x;
    v2 = a->z - b->z;
    return (s64) v1 * v1 + (s64) v2 * v2;
}

static inline BOOL func_02092b5c_inline_3(Unk020919e8 *p, s32 k) {
    s32 i;
    BOOL f;
    s32 d;
    Kart *o;

    for (i = 0; i < gRaceSetup->mKartCount; i++) {
        f = FALSE;
        if (gRaceSetup->mCurrentEntries[(u16) i].mPlayer.mKind <= 3 &&
            ((1 << gRaceSetup->mCurrentEntries[(u16) i].mPlayer.mKind) & 0xd)) {
            f = TRUE;
        }
        if (f == FALSE && i != gRaceSetup->mEntryIndex) {
            continue;
        }
        o = GetKart((u16) i);
        if (func_02092b5c_inline_4(&o->mPos, &p->mUnk_00.mPos) >= 0x15f900000000LL) {
            continue;
        }
        d = FX_Atan2Idx(o->mPos.x - p->mUnk_00.mPos.x, o->mPos.z - p->mUnk_00.mPos.z) - k;
        if (d < -0x1f40) {
            continue;
        }
        if (d <= 0x1f40) {
            return TRUE;
        }
    }
    return FALSE;
}

static inline void func_02092b5c_inline_5(Vec3 *v, s32 x, s32 y, s32 z) {
    v->x = x - 0x5000 + func_02092b5c_inline(0xa000);
    v->y = y - 0x5000 + func_02092b5c_inline(0xa000);
    v->z = z - 0x28000 + func_02092b5c_inline(0x50000);
}

s16 func_020930b0(s32 a) {
    return gPairsByAngle[(a >> 4) * 2];
}

s32 func_020930a0(s32 a, s32 b) {
    return ((s64) a * b) >> 12;
}

s16 func_02093080(s32 a) {
    return gPairsByAngle[(a >> 4) * 2 + 1];
}

void func_02092b5c(void *a, Unk020919e8 *p) {
    s32 i;
    s32 r;
    u16 k;
    s32 n;
    Vec3 v3;
    Vec3 v4;

    switch (p->mUnk_ac) {
        case 0:
            if (GetCurrentCameraKind() == 2) {
                p->mUnk_ac = 1;
                return;
            }
            if (p->mUnk_00.mFlags & 0x800) {
                if (p->mUnk_a4-- <= 0) {
                    p->mUnk_a4 = 4;
                    p->mUnk_ac = 1;
                }
                return;
            }
            if (func_02092b5c_inline_3(p, p->mUnk_00.mAngle) != FALSE) {
                p->mUnk_a4 = 4;
                p->mUnk_ac = 1;
            }
            return;
        case 1:
            break;
        default:
            return;
    }
    if (p->mUnk_a0 == 0x14) {
        for (i = 0; i < 2; i++) {
            func_02092b5c_inline_5(&v3, p->mUnk_00.mPos.x, p->mUnk_00.mPos.y + 0x23000, p->mUnk_00.mPos.z);
            k = p->mUnk_00.mAngle;
            r = NextRandomBelow(func_020d22d0(), 0x1000) + 0x2000;
            k = k - 0xbb8 + func_02046524(func_020d22d0(), 0x1770);
            v4.x = func_020930a0(r, func_020930b0(k));
            v4.y = NextRandomBelow(func_020d22d0(), 0x400) - 0xa00;
            v4.z = func_020930a0(r, func_02093080(k));
            if (i == 0 && p->mUnk_a8 == 0) {
                StartBasabasa(0x8c, &v3, &v4, 0xf, 1, i == 0 ? 2 : 0);
            } else {
                StartBasabasa(0x8c, &v3, &v4, 0xf, 0, i == 0 ? 2 : 0);
            }
        }
        p->mUnk_a8 += 1;
        if (p->mUnk_a8 >= 3) {
            p->mUnk_a8 = 0;
        }
    }
    n = p->mUnk_a0 + 1;
    if (n >= 0x32) {
        n = 0;
    }
    p->mUnk_a0 = n;
    if (p->mUnk_a0 != 0) {
        return;
    }
    if (p->mUnk_a4-- > 0) {
        return;
    }
    p->mUnk_a8 = 0;
    p->mUnk_ac = 0;
    if (p->mUnk_00.mFlags & 0x800) {
        p->mUnk_a4 = (u16) (func_02092b5c_inline_2(25) + 200);
    }
}

void func_02092b3c(void) {
    CreateMapObjectUpdateList(func_020930c8, func_02092b5c, NULL);
}
