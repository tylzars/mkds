#include "Main/Unknown/code_020918a8.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_0209219c.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Unknown/code_0209b634.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_0209bef0.h"
#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_020e6b58.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/code_0210b760.h"
#include "Main/Unknown/unk_02156000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_02166000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "code_02147cd8.h"
#include "code_02148538.h"
#include "Main/Unknown/code_02045874.h"
#include "Main/Unknown/code_02077bc0.h"

static inline u32 func_020919e8_inline(u32 n) {
    Unk020f41c4_B *b;

    b = func_020d22d0();
    b->mUnk_00 = b->mUnk_08 * b->mUnk_00 + b->mUnk_10;
    return (u32) (((b->mUnk_00 >> 32) * n) >> 32);
}

static inline u16 func_020919e8_inline_2(u32 n) {
    Unk020f41c4_B *b;

    b = func_020d22d0();
    b->mUnk_00 = b->mUnk_08 * b->mUnk_00 + b->mUnk_10;
    return (u32) (((b->mUnk_00 >> 32) * n) >> 32);
}

static inline void func_020919e8_inline_3(Unk020919e8 *p, s32 n) {
    Unk0210b7a8 s;
    s32 v;

    if (p->mUnk_00.mDistanceSquaredAndFlags & 4) {
        return;
    }
    if (p->mUnk_00.mFarDistanceSquared == gSoundFalloffs[2].mUnk_20) {
        v = 2;
    } else if (p->mUnk_00.mFarDistanceSquared == gSoundFalloffs[3].mUnk_20) {
        v = 3;
    } else {
        v = 4;
    }
    s.mUnk_00 = n;
    s.mUnk_04 = &p->mUnk_00.mPos;
    s.mUnk_08 = v;
    s.mUnk_0c = func_020d4ef4(&p->mUnk_00.mPos);
    func_0210b7a8(&s);
}

void CreateKanoke64(void *a) {
    gKanoke64 = CreateMapObjectModelAnimated(a, gKanoke64NsbmdName);
    CreateMapObjectModelNsbcaAnimation(gKanoke64, gKanoke64NsbcaName);
}

void DrawKanoke64(void *a, Unk020919e8 *p) {
    s32 w;

    SetMapObjectModelNsbcaFrameIndex(gKanoke64, p->mUnk_a0);
    w = 0x1e;
    func_01ff9048(0x14, &w, 1);
    p->mUnk_00.mMatrix.mUnk_00[3].x = p->mUnk_00.mPos.x >> 4;
    p->mUnk_00.mMatrix.mUnk_00[3].y = p->mUnk_00.mPos.y >> 4;
    p->mUnk_00.mMatrix.mUnk_00[3].z = p->mUnk_00.mPos.z >> 4;
    func_01ff9048(0x19, &p->mUnk_00.mMatrix, 0xc);
    func_01ff9048(0x1b, &p->mUnk_00.mScale, 3);
    DrawMapObjectModel(a, gKanoke64, p);
}

void func_02091fd8(Unk020e6fd4 *a) {
    s32 i;
    Unk020919e8 *p;

    if (a == NULL) {
        return;
    }
    for (i = 0; i < a->mUnk_04 && (p = (Unk020919e8 *) a->mUnk_00[i]) != NULL; i++) {
        if (p->mUnk_00.mFlags & 0x800) {
            p->mUnk_a4 = (u16) (func_020919e8_inline_2(25) + 200);
        }
    }
}

u32 func_02091f6c(Unk020f41c4_B *a, u32 b) {
    if (b == 0) {
        return 0;
    }
    a->mUnk_00 = a->mUnk_08 * a->mUnk_00 + a->mUnk_10;
    if (b == 0) {
        return a->mUnk_00 >> 32;
    }
    return ((a->mUnk_00 >> 32) * b) >> 32;
}

s16 func_02091f54(s32 a) {
    return gPairsByAngle[(a >> 4) * 2];
}

s32 func_02091f44(s32 a, s32 b) {
    return (s32) (((s64) a * b) >> 12);
}

static inline s64 func_020919e8_inline_5(const Vec3 *a, const Vec3 *b) {
    s32 v1;
    s32 v2;

    v1 = a->x - b->x;
    v2 = a->z - b->z;
    return (s64) v1 * v1 + (s64) v2 * v2;
}

static inline BOOL func_020919e8_inline_4(Unk020919e8 *p, s32 k) {
    s32 i;
    BOOL f;
    s32 d;
    Kart *o;

    for (i = 0; i < data_021759c0->mKartCount; i++) {
        f = FALSE;
        if ((u32) data_021759c0->mCurrentEntries[(u16) i].mPlayer.mKind <= 3 &&
            ((1 << data_021759c0->mCurrentEntries[(u16) i].mPlayer.mKind) & 0xd)) {
            f = TRUE;
        }
        if (f == FALSE && i != data_021759c0->mEntryIndex) {
            continue;
        }
        o = GetKart((u16) i);
        if (func_020919e8_inline_5(&o->mPos, &p->mUnk_00.mPos) >= 0x225510000000LL) {
            continue;
        }
        d = AngleFromPair(o->mPos.x - p->mUnk_00.mPos.x, o->mPos.z - p->mUnk_00.mPos.z) - k;
        if (d < -0x1f40) {
            continue;
        }
        if (d <= 0x1f40) {
            return TRUE;
        }
    }
    return FALSE;
}

static inline void func_020919e8_inline_6(Vec3 *v, s32 x, s32 y, s32 z) {
    v->x = x - 0x5000 + func_020919e8_inline(0xa000);
    func_020d22d0();
    v->y = y;
    v->z = z - 0x28000 + func_020919e8_inline(0x50000);
}

s16 func_02091f24(s32 a) {
    return gPairsByAngle[(a >> 4) * 2 + 1];
}

void UpdateKanoke64(void *a, Unk020919e8 *p) {
    s32 i;
    s32 r;
    u16 k;
    s32 n;
    Vec3 v3;
    Vec3 v4;

    switch (p->mUnk_ac) {
        case 0:
            if (func_02061818() == 2) {
                p->mUnk_ac = 1;
                return;
            }
            if (p->mUnk_00.mFlags & 0x800) {
                if (p->mUnk_a4-- <= 0) {
                    p->mUnk_a4 = 8;
                    p->mUnk_ac = 1;
                }
                return;
            }
            if (func_020919e8_inline_4(p, p->mUnk_00.mAngle) != FALSE) {
                p->mUnk_a4 = 8;
                p->mUnk_ac = 1;
            }
            return;
        case 1:
            break;
        default:
            return;
    }
    if (p->mUnk_a0 == 10) {
        for (i = 0; i < 3; i++) {
            func_020919e8_inline_6(&v3, p->mUnk_00.mPos.x, p->mUnk_00.mPos.y + 0x19000, p->mUnk_00.mPos.z);
            k = p->mUnk_00.mAngle;
            r = func_02091f6c(func_020d22d0(), 0x1000) + 0x800;
            k = k - 0x3e8 + func_02046524(func_020d22d0(), 0x7d0);
            v4.x = func_02091f44(r, func_02091f54(k));
            v4.y = func_02091f6c(func_020d22d0(), 0x400) + 0x2200;
            v4.z = func_02091f44(r, func_02091f24(k));
            if (i == 0 && p->mUnk_a8 == 0) {
                func_0209219c(0x50, &v3, &v4, 0x28, 1, i == 0 ? 3 : 0);
            } else {
                func_0209219c(0x50, &v3, &v4, 0x28, 0, i == 0 ? 3 : 0);
            }
        }
        p->mUnk_a8 += 1;
        if (p->mUnk_a8 >= 3) {
            p->mUnk_a8 = 0;
        }
    }
    n = p->mUnk_a0 + 1;
    if (n >= GetMapObjectModelNsbcaFrameCount(gKanoke64)) {
        n = 0;
    }
    p->mUnk_a0 = n;
    if (p->mUnk_a0 == 0) {
        if (p->mUnk_a4-- <= 0) {
            p->mUnk_a8 = 0;
            p->mUnk_ac = 0;
            if (p->mUnk_00.mFlags & 0x800) {
                p->mUnk_a4 = (u16) (func_020919e8_inline_2(25) + 200);
            }
        }
    }
    if (p->mUnk_a0 != 0) {
        return;
    }
    func_020919e8_inline_3(p, 0x188);
}

void func_020919c8(void) {
    func_0209bf1c(CreateKanoke64, DrawKanoke64, NULL);
}

void func_020919a8(void) {
    func_0209bf48(func_02091fd8, UpdateKanoke64, NULL);
}

void CreateCow(void *a) {
    gCow = CreateMapObjectModelNsbmdNsbtp(a, gCowNsbmdName, gCowNsbtpName);
    SetMapObjectModelPolygonId(gCow, 0x3f);
}

void func_02091954(void *a) {
    func_0209bbd0(a, gCow);
}

void func_020918cc(void *a, Unk020919e8 *b) {
    s32 w;

    w = 0x1e;
    func_01ff9048(0x14, &w, 1);
    func_01ff9048(0x19, func_020e6cbc(&b->mUnk_00.mPos), 0xc);
    func_01ff9048(0x1b, &b->mUnk_00.mScale, 3);
    func_0209b688(gCow, b->mUnk_00.mCourseMapRow->mUnk_28);
    DrawMapObjectModel(a, gCow, b);
}

void func_020918a8(void) {
    func_0209bef0(CreateCow, func_020918cc, func_02091954);
}
