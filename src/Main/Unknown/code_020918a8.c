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
    RandomState64 *mapObjectRandom;

    mapObjectRandom = GetMapObjectRandom();
    mapObjectRandom->mValue = mapObjectRandom->mMultiplier * mapObjectRandom->mValue + mapObjectRandom->mIncrement;
    return ((mapObjectRandom->mValue >> 32) * n) >> 32;
}

static inline u16 func_020919e8_inline_2(u32 n) {
    RandomState64 *mapObjectRandom;

    mapObjectRandom = GetMapObjectRandom();
    mapObjectRandom->mValue = mapObjectRandom->mMultiplier * mapObjectRandom->mValue + mapObjectRandom->mIncrement;
    return (u32) (((mapObjectRandom->mValue >> 32) * n) >> 32);
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
    s.mSoundId = n;
    s.mPositionSource = &p->mUnk_00.mPos;
    s.mUnk_08 = v;
    s.mDistanceSquared = GetHorizontalCameraDistanceSquared(&p->mUnk_00.mPos);
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

void InitKanoke64Objects(MapObjectList *mapObjectList) {
    s32 i;
    Unk020919e8 *p;

    if (mapObjectList == NULL) {
        return;
    }
    for (i = 0; i < mapObjectList->mMapObjectCount && (p = mapObjectList->mMapObjects[i]) != NULL; i++) {
        if (p->mUnk_00.mFlags & 0x800) {
            p->mUnk_a4 = (u16) (func_020919e8_inline_2(25) + 200);
        }
    }
}

// Returns a random value below b (0 when b is 0), advancing the generator a.
u32 NextRandomBelow(RandomState64 *randomState64, u32 limit) {
    if (limit == 0) {
        return 0;
    }
    randomState64->mValue = randomState64->mMultiplier * randomState64->mValue + randomState64->mIncrement;
    if (limit == 0) {
        return randomState64->mValue >> 32;
    }
    return ((randomState64->mValue >> 32) * limit) >> 32;
}

s16 func_02091f54(s32 angle) {
    return gPairsByAngle[(angle >> 4) * 2];
}

s32 func_02091f44(s32 a, s32 b) {
    return ((s64) a * b) >> 12;
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
    Kart *kart;

    for (i = 0; i < gRaceSetup->mKartCount; i++) {
        f = FALSE;
        if (gRaceSetup->mCurrentEntries[(u16) i].mPlayer.mKind <= 3 &&
            ((1 << gRaceSetup->mCurrentEntries[(u16) i].mPlayer.mKind) & PLAYER_KIND_MASK_HUMAN_GHOST_PEER)) {
            f = TRUE;
        }
        if (f == FALSE && i != gRaceSetup->mEntryIndex) {
            continue;
        }
        kart = GetKart((u16) i);
        if (func_020919e8_inline_5(&kart->mPos, &p->mUnk_00.mPos) >= 0x225510000000LL) {
            continue;
        }
        d = FX_Atan2Idx(kart->mPos.x - p->mUnk_00.mPos.x, kart->mPos.z - p->mUnk_00.mPos.z) - k;
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
    GetMapObjectRandom();
    v->y = y;
    v->z = z - 0x28000 + func_020919e8_inline(0x50000);
}

s16 func_02091f24(s32 angle) {
    return gPairsByAngle[(angle >> 4) * 2 + 1];
}

void UpdateKanoke64(void *a, Unk020919e8 *p) {
    s32 i;
    s32 horizontalSpeed;
    u16 k;
    s32 nextFrameIndex;
    Vec3 basabasaPos;
    Vec3 basabasaVelocity;

    switch (p->mUnk_ac) {
        case 0:
            if (GetCurrentCameraKind() == 2) {
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
            func_020919e8_inline_6(&basabasaPos, p->mUnk_00.mPos.x, p->mUnk_00.mPos.y + 0x19000, p->mUnk_00.mPos.z);
            k = p->mUnk_00.mAngle;
            horizontalSpeed = NextRandomBelow(GetMapObjectRandom(), 0x1000) + 0x800;
            k = k - 0x3e8 + func_02046524(GetMapObjectRandom(), 0x7d0);
            basabasaVelocity.x = func_02091f44(horizontalSpeed, func_02091f54(k));
            basabasaVelocity.y = NextRandomBelow(GetMapObjectRandom(), 0x400) + 0x2200;
            basabasaVelocity.z = func_02091f44(horizontalSpeed, func_02091f24(k));
            if (i == 0 && p->mUnk_a8 == 0) {
                StartBasabasa(0x50, &basabasaPos, &basabasaVelocity, 0x28, 1, i == 0 ? 3 : 0);
            } else {
                StartBasabasa(0x50, &basabasaPos, &basabasaVelocity, 0x28, 0, i == 0 ? 3 : 0);
            }
        }
        p->mUnk_a8 += 1;
        if (p->mUnk_a8 >= 3) {
            p->mUnk_a8 = 0;
        }
    }
    nextFrameIndex = p->mUnk_a0 + 1;
    if (nextFrameIndex >= GetMapObjectModelNsbcaFrameCount(gKanoke64)) {
        nextFrameIndex = 0;
    }
    p->mUnk_a0 = nextFrameIndex;
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

void CreateKanoke64DrawList(void) {
    CreateMapObjectDrawList1(CreateKanoke64, DrawKanoke64, NULL);
}

void CreateKanoke64UpdateList(void) {
    CreateMapObjectUpdateList(InitKanoke64Objects, UpdateKanoke64, NULL);
}

void CreateCow(void *a) {
    gCow = CreateMapObjectModelNsbmdNsbtp(a, gCowNsbmdName, gCowNsbtpName);
    SetMapObjectModelPolygonId(gCow, 0x3f);
}

void SetupDrawCow(void *a) {
    func_0209bbd0(a, gCow);
}

void DrawCow(void *a, Unk020919e8 *b) {
    s32 w;

    w = 0x1e;
    func_01ff9048(0x14, &w, 1);
    func_01ff9048(0x19, func_020e6cbc(&b->mUnk_00.mPos), 0xc);
    func_01ff9048(0x1b, &b->mUnk_00.mScale, 3);
    SetMapObjectModelNsbtpFrameIndex(gCow, b->mUnk_00.mCourseMapRow->mUnk_28);
    DrawMapObjectModel(a, gCow, b);
}

void CreateCowDrawList(void) {
    CreateMapObjectDrawList2(CreateCow, DrawCow, SetupDrawCow);
}
