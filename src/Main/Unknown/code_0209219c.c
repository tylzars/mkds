#include "Main/Unknown/code_0209219c.h"
#include "Main/Unknown/code_020d2000.h"

#include "Main/Unknown/code_0209b634.h"
#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_0209bef0.h"
#include "Main/Unknown/code_021000d0.h"
#include "Main/Unknown/unk_02156000.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_02042044.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_0209bf70.h"
#include "Main/Unknown/code_020d275c.h"
#include "Main/Unknown/code_020e6b58.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02146000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/unk_02166000.h"
#include "code_02146cbc.h"
#include "code_02147cd8.h"

void InitBasabasa(MapObject *arg0) {
    MapObject *value0 = arg0;
    MapObject *value4;
    value4 = value0;
    ParkMapObject(value0);
    value0 = value4;
    CreateMapObjectSoundSourceFalloff2(value0);
}

u8 func_0209297c(Basabasa *a, Unk0209297c *b, void *c, u8 *d) {
    Vec3 u;
    Vec3 t;
    s32 k;
    s32 x;
    s32 z;
    u8 r;
    u8 m;
    s64 q;

    m = 1 << b->mUnk_74;
    r = *d;
    if ((a->mUnk_d0 & m) == 0) {
        VEC_Subtract(&b->mUnk_80, &a->mUnk_00.mPos, &t);
        k = ((s64) a->mUnk_00.mMatrix.mUnk_00[2].x * t.x + (s64) a->mUnk_00.mMatrix.mUnk_00[2].z * t.z) >> 12;
        x = t.x - (s32) (((s64) a->mUnk_00.mMatrix.mUnk_00[2].x * k) >> 12);
        z = t.z - (s32) (((s64) a->mUnk_00.mMatrix.mUnk_00[2].z * k) >> 12);
        q = (s64) x * x + (s64) u.y * u.y + (s64) z * z;
        u.x = x;
        u.z = z;
        if (q < 0x10) {
            a->mUnk_00.mUnk_10.x = ((s64) a->mUnk_00.mMatrix.mUnk_00[2].x * 0x1333) >> 12;
            a->mUnk_00.mUnk_10.y = ((s64) a->mUnk_00.mMatrix.mUnk_00[2].y * 0x1333) >> 12;
            a->mUnk_00.mUnk_10.z = ((s64) a->mUnk_00.mMatrix.mUnk_00[2].z * 0x1333) >> 12;
        } else {
            Vec3NormalizeAndGetLengthUnchecked(&u, &u);
            a->mUnk_00.mUnk_10.x = ((s64) u.x * 0x1333) >> 12;
            a->mUnk_00.mUnk_10.y = ((s64) u.y * 0x1333) >> 12;
            a->mUnk_00.mUnk_10.z = ((s64) u.z * 0x1333) >> 12;
        }
        a->mUnk_d0 |= m;
    }
    return r;
}

void CreateBasabasa(void *a) {
    gBasabasa = CreateMapObjectModelNsbmdNsbtp(a, gBasabasaNsbmdName, gBasabasaNsbtpName);
    SetMapObjectModelPolygonId(gBasabasa, 0x3f);
}

void SetupDrawBasabasa(void *a) {
    func_0209bbd0(a, gBasabasa);
}

void DrawBasabasa(void *a, Basabasa *b) {
    s32 s;
    s32 m[9];
    s32 d;

    d = 0x1fe0 - b->mUnk_c4;
    s = 0x1e;
    func_01ff9048(0x14, &s, 1);
    func_01ff9048(0x19, SetViewTransposeMatrixPos(&b->mUnk_00.mPos), 0xc);
    if (b->mUnk_cc != 0) {
        MTX_RotZ33_(m, gPairsByAngle[((u16) -d >> 4) * 2], gPairsByAngle[((u16) -d >> 4) * 2 + 1]);
    } else {
        MTX_RotZ33_(m, gPairsByAngle[((u16) d >> 4) * 2], gPairsByAngle[((u16) d >> 4) * 2 + 1]);
    }
    func_01ff9048(0x1a, m, 9);
    func_01ff9048(0x1b, &b->mUnk_00.mScale, 3);
    SetMapObjectModelNsbtpFrameIndex(gBasabasa, b->mUnk_ac);
    DrawMapObjectModel(a, gBasabasa, b);
}

void UpdateBasabasa(void *a, Basabasa *b) {
    s32 v;

    b->mUnk_c4 += b->mUnk_c8;
    b->mUnk_c8 += 0x3c;
    if (b->mUnk_c4 == 0) {
        b->mUnk_c4 += b->mUnk_c8;
        b->mUnk_c8 += 0x3c;
    } else if (b->mUnk_c4 >= 0x1fe0) {
        b->mUnk_c8 = 0x3c - b->mUnk_c8;
        b->mUnk_cc = b->mUnk_cc == 0;
    }
    switch (b->mState) {
        case 0:
            if (b->mUnk_b0-- > 0) {
                break;
            }
            b->mUnk_00.mFlags &= ~1;
            b->mUnk_00.mFlags &= ~2;
            b->mUnk_00.mFlags &= ~8;
            b->mUnk_00.mAlpha = 0x1f;
            b->mUnk_a0.x += (s32) (((s64) b->mUnk_00.mMatrix.mUnk_00[2].x * 0x19a) >> 12);
            b->mUnk_a0.y += -0x19a;
            b->mUnk_a0.z += (s32) (((s64) b->mUnk_00.mMatrix.mUnk_00[2].z * 0x19a) >> 12);
            VEC_Add(&b->mUnk_00.mPos, &b->mUnk_a0, &b->mUnk_00.mPos);
            if (b->mUnk_b4-- <= 0) {
                b->mState = 1;
            }
            break;
        case 1:
            b->mUnk_a0.x += (s32) (((s64) b->mUnk_00.mMatrix.mUnk_00[2].x * 0x19a) >> 12);
            b->mUnk_a0.y += 0x19a;
            b->mUnk_a0.z += (s32) (((s64) b->mUnk_00.mMatrix.mUnk_00[2].z * 0x19a) >> 12);
            VEC_Add(&b->mUnk_00.mPos, &b->mUnk_a0, &b->mUnk_00.mPos);
            if (b->mUnk_a0.y > 0) {
                b->mUnk_a0.y = 0;
                b->mState = 2;
            }
            break;
        case 2:
            VEC_Add(&b->mUnk_00.mPos, &b->mUnk_a0, &b->mUnk_00.mPos);
            if (b->mUnk_b8-- <= 0) {
                b->mState = 3;
            }
            break;
        case 3:
            b->mUnk_a0.x -= (s32) (((s64) b->mUnk_00.mMatrix.mUnk_00[2].x * 0xcd) >> 12);
            b->mUnk_a0.y += 0x1000;
            b->mUnk_a0.z -= (s32) (((s64) b->mUnk_00.mMatrix.mUnk_00[2].z * 0xcd) >> 12);
            VEC_Add(&b->mUnk_00.mPos, &b->mUnk_a0, &b->mUnk_00.mPos);
            if (b->mUnk_00.mPos.y >= 0x1b8000) {
                ParkMapObject(&b->mUnk_00);
            }
            break;
    }
    if (b->mUnk_b0 > 0) {
        return;
    }
    v = b->mUnk_ac + 1;
    if (v >= GetMapObjectModelNsbtpFrameCount(gBasabasa)) {
        v = 0;
    }
    b->mUnk_ac = v;
    if (b->mUnk_bc == 0) {
        return;
    }
    StartMapObjectSoundWhileRequested(&b->mUnk_00, 0x165);
}

void CreateBasabasaKindData(void) {
    CreateMapObjectKindData(&func_0209297c, NULL, NULL, 1, 0);
}

static inline u16 func_0209219c_inline(u32 n) {
    Unk020f41c4_B *b;
    u32 m;
    u32 r;

    if (n == 0x10000) {
        b = GetMapObjectRandom();
        b->mValue = b->mMultiplier * b->mValue + b->mIncrement;
        return ((b->mValue >> 32) * 0x10000) >> 32;
    } else {
        b = GetMapObjectRandom();
        m = (u16) n;
        if (m == 0) {
            r = 0;
        } else {
            b->mValue = b->mMultiplier * b->mValue + b->mIncrement;
            if (m == 0) {
                r = b->mValue >> 32;
            } else {
                r = ((b->mValue >> 32) * m) >> 32;
            }
        }
    }
    return r;
}

void CreateBasabasaDrawList(void) {
    CreateMapObjectDrawList2(CreateBasabasa, DrawBasabasa, SetupDrawBasabasa);
}

void CreateBasabasaUpdateList(void) {
    CreateMapObjectUpdateList(NULL, UpdateBasabasa, NULL);
}

void StartBasabasa(u32 a, const Vec3 *b, const Vec3 *c, u32 d, s32 e, u16 f) {
    Basabasa *p;
    Unk020f41c4_B *r;
    u32 n;
    u16 w;

    p = UnparkFirstParkedMapObject(func_02100138(MAP_OBJECT_KIND_BASABASA));
    if (p == NULL) {
        return;
    }
    p->mUnk_00.mFlags |= data_usa_02156460;
    p->mUnk_00.mFlags |= data_usa_02156464;
    p->mUnk_00.mFlags |= data_usa_02156468;
    p->mUnk_bc = e;
    p->mUnk_c0 = f;
    r = GetMapObjectRandom();
    r->mValue = r->mMultiplier * r->mValue + r->mIncrement;
    p->mUnk_b0 = (u16) (((r->mValue >> 32) * 30) >> 32);
    n = (d << 12) >> 16;
    w = func_0209219c_inline(n);
    p->mUnk_b4 = d + w;
    n = (a << 12) >> 16;
    w = func_0209219c_inline(n);
    p->mUnk_b8 = a + w;
    p->mUnk_00.mPos = *b;
    p->mUnk_a0 = *c;
    p->mState = 0;
    p->mUnk_d0 = 0;
}
