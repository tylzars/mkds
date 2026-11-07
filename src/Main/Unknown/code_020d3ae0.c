#include "Main/Unknown/code_020d3ae0.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020b33d8.h"

#include "Main/Unknown/code_020d3b10.h"
#include "Main/Unknown/code_020ea670.h"
#include "Main/Unknown/code_020d6538.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/unk_02156000.h"
#include "Main/Unknown/code_020d5000.h"
#include "Main/Unknown/code_020d3c7c.h"
#include "Main/Unknown/code_020d3c94.h"
#include "Main/Unknown/code_020d2c2c.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h"
#include "Main/Unknown/code_020d94dc.h"
#include "Main/Unknown/code_020d3d94.h"
#include "Main/Unknown/code_020d3dbc.h"
#include "Main/Unknown/code_020d4104.h"
#include "Main/Unknown/code_020d411c.h"
#include "Main/Unknown/code_020d4130.h"
#include "Main/Unknown/code_020d50ec.h"
#include "Main/Unknown/unk_021759c0.h"
#include "ITCM/code_01ffcf7c.h"
#include "ITCM/code_01ffd000.h"
#include "Main/Unknown/code_0207a780.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_0208ab00.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_020d50b4.h"
#include "Main/Unknown/code_020e3b28.h"
#include "Main/Unknown/code_020e6a74.h"
#include "Main/Unknown/code_020b3000.h"
#include "Main/Unknown/code_020d6000.h"
#include "Main/Unknown/code_020df890.h"
#include "Main/Unknown/code_020d4970.h"
#include "Main/Unknown/code_020d4990.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020d49d8.h"
#include "Main/Unknown/code_020d49e0.h"
#include "Main/Unknown/code_020d4a10.h"
#include "Main/Unknown/code_020d4a18.h"
#include "Main/Unknown/code_020d4a20.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_020d4bf0.h"
#include "code_0212d214.h"
#include "Main/Unknown/code_0210bcf4.h"
#include "Main/Unknown/code_0210cf9c.h"
#include "Main/Unknown/code_02146000.h"
#include "code_02146cbc.h"
#include "Main/Unknown/code_020d7000.h"
#include "Main/Unknown/code_020d50c4.h"
#include "Main/Unknown/code_020d50e0.h"

Unk0217b4f8 *func_020d50e0(void) {
    return &data_0217b4f8;
}

void func_020d50c4(void) {
    data_0217b4f8.mUnk_50 = TRUE;
    data_0217b4f8.mUnk_54 = FALSE;
}

u32 func_020d50b4(void) {
    u32 value0;
    value0 = data_0217b4f8.mUnk_54;
    return value0;
}

void func_020d4f94(Unk020d4f94 *p) {
    s32 buf[10];

    MTX_Transpose33_(p, buf);
    MTX_MultVec33(&p->mUnk_24, buf, &data_0217b4f8.mUnk_08);
    data_0217b4f8.mUnk_08.x = -data_0217b4f8.mUnk_08.x;
    data_0217b4f8.mUnk_08.y = -data_0217b4f8.mUnk_08.y;
    data_0217b4f8.mUnk_08.z = -data_0217b4f8.mUnk_08.z;
    data_0217b4f8.mUnk_08.x = data_0217b4f8.mUnk_08.x << 4;
    data_0217b4f8.mUnk_08.y = data_0217b4f8.mUnk_08.y << 4;
    data_0217b4f8.mUnk_08.z = data_0217b4f8.mUnk_08.z << 4;
    data_0217b4f8.mUnk_14.x = -buf[6];
    data_0217b4f8.mUnk_14.y = -buf[7];
    data_0217b4f8.mUnk_14.z = -buf[8];
    MTX_MultVec33(&data_0217b550.mUnk_20, buf, &data_0217b4f8.mUnk_20);
    MTX_MultVec33(&data_0217b550.mUnk_2c, buf, &data_0217b4f8.mUnk_2c);
    MTX_MultVec33(&data_0217b550.mUnk_38, buf, &data_0217b4f8.mUnk_38);
    MTX_MultVec33(&data_0217b550.mUnk_44, buf, &data_0217b4f8.mUnk_44);
    if (data_0217b4f8.mUnk_50 != FALSE) {
        data_0217b4f8.mUnk_50 = FALSE;
        data_0217b4f8.mUnk_54 = TRUE;
    } else {
        data_0217b4f8.mUnk_54 = FALSE;
    }
}

u32 func_020d4f34(Vec3 *a, s32 b, s32 c, s32 d) {
    s32 x;
    s32 z;
    s32 v;
    u32 r;

    x = (a->x - data_0217b4f8.mUnk_08.x) >> 12;
    z = (a->z - data_0217b4f8.mUnk_08.z) >> 12;
    v = x * x + z * z;
    r = v & ~0xc000001f;
    if (v > d) {
        r |= data_021568f4;
    }
    return r | 3;
}

s32 func_020d4ef4(Vec3 *p) {
    s32 x;
    s32 z;

    if (p == NULL) {
        return 0;
    }
    x = (p->x - data_0217b4f8.mUnk_08.x) >> 12;
    z = (p->z - data_0217b4f8.mUnk_08.z) >> 12;
    return x * x + z * z;
}

void func_020d4e28(ItemObject *p, Vec3 *v, u32 a) {
    s32 d;

    if (a & 4) {
        if (p->mSoundSource.mUnk_34 & 1) {
            SetSoundSourceFlagBit(&p->mSoundSource, 2, 1);
        }
        return;
    }
    d = data_0217b4f8.mUnk_08.y - v->y;
    if (d > -0x12c000 && d < data_0217b4f4) {
        if (!(p->mSoundSource.mUnk_34 & 1)) {
            SetSoundSourceFlagBit(&p->mSoundSource, 2, 1);
        }
    } else {
        if (p->mSoundSource.mUnk_34 & 1) {
            SetSoundSourceFlagBit(&p->mSoundSource, 2, 1);
        }
    }
}

BOOL func_020d4ddc(MapObject *p) {
    s32 d;

    if (p->mDistanceSquaredAndFlags & 4) {
        return TRUE;
    }
    d = data_0217b4f8.mUnk_08.y - p->mPos.y;
    if (p->mKindData->mUnk_3c < d && d < p->mKindData->mUnk_38) {
        return FALSE;
    }
    return TRUE;
}

BOOL func_020d4d60(MapObject *p, s32 a) {
    s32 h;
    Vec3 *v;
    MapObjectKindData *q;

    v = &p->mPos;
    if (a > p->mFarDistanceSquared) {
        return TRUE;
    }
    q = p->mKindData;
    h = (v->y - data_0217b4f8.mUnk_08.y) >> 12;
    if (h < q->mUnk_3c || q->mUnk_38 < h) {
        return TRUE;
    }
    return (GetKartKind3ShapeMask() & p->mDigitMask) != 0;
}

void func_020d4d44(MtxFx43 *p) {
    SetViewMatrices(p);
    func_020d7bec(p);
}

void DrawMapObjectList(MapObjectList *p, MtxFx43 *a) {
    s32 i;
    MapObject *e;
    UnkFunc *f;
    s32 n;
    void **t;
    MapObject *b;
    s32 m;

    f = p->mForEachObject;
    n = p->mMapObjectCount;
    t = p->mUnk_24;
    if (f == NULL) {
        return;
    }
    if (p->mUnk_1c != NULL) {
        b = NULL;
        for (i = 0; i < n; i++) {
            e = t[i];
            if (!(e->mFlags & 0x12) && e->mAlpha != 0) {
                f(p, e, a, e->mAlpha);
                if (b != NULL && (s32) (e->mDistanceSquaredAndFlags & ~0xc000001f) >
                                     (s32) (b->mDistanceSquaredAndFlags & ~0xc000001f)) {
                    t[m] = e;
                    t[i] = b;
                } else {
                    b = e;
                }
                m = i;
            }
        }
    } else {
        for (i = 0; i < n; i++) {
            e = t[i];
            if (!(e->mFlags & 0x12) && e->mAlpha != 0) {
                f(p, e, a, e->mAlpha);
            }
        }
    }
}

#pragma thumb on

void func_020d4bf0(void) {
    data_0217b4f8.mUnk_50 = TRUE;
    data_0217b4f8.mUnk_54 = FALSE;
    if (gRaceSetup->mRaceKind == 2) {
        data_0217b4f4 = 0x258000;
        return;
    }
    data_0217b4f4 = 0x12c000;
}

#pragma thumb off

#pragma thumb on
void func_020d4a20(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f) {
    data_0217b550.mUnk_00 = e << 4;
    data_0217b4f8.mUnk_00 = e << 4;
    data_0217b550.mUnk_04 = f << 4;
    data_0217b4f8.mUnk_04 = f << 4;

    data_0217b550.mUnk_20.x = e;
    data_0217b550.mUnk_20.y = 0;
    data_0217b550.mUnk_20.z = -c;
    if ((s64) data_0217b550.mUnk_20.z * data_0217b550.mUnk_20.z +
            ((s64) data_0217b550.mUnk_20.x * data_0217b550.mUnk_20.x +
             (s64) data_0217b550.mUnk_20.y * data_0217b550.mUnk_20.y) >=
        0x10) {
        Vec3NormalizeAndGetLengthUnchecked(&data_0217b550.mUnk_20, &data_0217b550.mUnk_20);
    }
    if (gRaceSetup->mMirrorMode != 0) {
        data_0217b550.mUnk_20.x = -data_0217b550.mUnk_20.x;
        data_0217b550.mUnk_20.y = -data_0217b550.mUnk_20.y;
        data_0217b550.mUnk_20.z = -data_0217b550.mUnk_20.z;
    }

    data_0217b550.mUnk_2c.x = -e;
    data_0217b550.mUnk_2c.y = 0;
    data_0217b550.mUnk_2c.z = d;
    if ((s64) data_0217b550.mUnk_2c.z * data_0217b550.mUnk_2c.z +
            ((s64) data_0217b550.mUnk_2c.x * data_0217b550.mUnk_2c.x +
             (s64) data_0217b550.mUnk_2c.y * data_0217b550.mUnk_2c.y) >=
        0x10) {
        Vec3NormalizeAndGetLengthUnchecked(&data_0217b550.mUnk_2c, &data_0217b550.mUnk_2c);
    }
    if (gRaceSetup->mMirrorMode != 0) {
        data_0217b550.mUnk_2c.x = -data_0217b550.mUnk_2c.x;
        data_0217b550.mUnk_2c.y = -data_0217b550.mUnk_2c.y;
        data_0217b550.mUnk_2c.z = -data_0217b550.mUnk_2c.z;
    }

    data_0217b550.mUnk_38.x = 0;
    data_0217b550.mUnk_38.y = -e;
    data_0217b550.mUnk_38.z = a;
    if ((s64) data_0217b550.mUnk_38.z * data_0217b550.mUnk_38.z +
            ((s64) data_0217b550.mUnk_38.x * data_0217b550.mUnk_38.x +
             (s64) data_0217b550.mUnk_38.y * data_0217b550.mUnk_38.y) >=
        0x10) {
        Vec3NormalizeAndGetLengthUnchecked(&data_0217b550.mUnk_38, &data_0217b550.mUnk_38);
    }

    data_0217b550.mUnk_44.x = 0;
    data_0217b550.mUnk_44.y = e;
    data_0217b550.mUnk_44.z = -b;
    if ((s64) data_0217b550.mUnk_44.z * data_0217b550.mUnk_44.z +
            ((s64) data_0217b550.mUnk_44.x * data_0217b550.mUnk_44.x +
             (s64) data_0217b550.mUnk_44.y * data_0217b550.mUnk_44.y) >=
        0x10) {
        Vec3NormalizeAndGetLengthUnchecked(&data_0217b550.mUnk_44, &data_0217b550.mUnk_44);
    }
}
#pragma thumb off

#pragma thumb on
void ClearMapObjectList(MapObjectList *arg0) {
    arg0->mMapObjects = NULL;
    arg0->mMapObjectCount = 0;
}
#pragma thumb off

#pragma thumb on
void func_020d4a10(MapObjectList *p, s32 a) {
    p->mMapObjectCount += a;
}
#pragma thumb off

#pragma thumb on
u32 InitMapObjectDrawList(MapObjectList *arg0) {
    arg0->mMapObjects = HeapAlloc(GetHeap(func_020364e8()), arg0->mMapObjectCount << 2);
    arg0->mMapObjectCount = 0;
    return 0;
}
#pragma thumb off

#pragma thumb on
u32 AddMapObjectToDrawList(MapObjectList *arg0, MapObject *arg1) {
    u32 n = arg0->mMapObjectCount;
    arg0->mMapObjectCount = n + 1;
    arg0->mMapObjects[n] = arg1;
    return n << 2;
}
#pragma thumb off

#pragma thumb on

void func_020d49d8(void *p0) {
    *(u32 *) ((u8 *) (u32) (((u32) * (const u32 *) ((u8 *) (u32) p0 + 0))) + 40) = (u32) p0;
}

#pragma thumb off

#pragma thumb on
void func_020d4990(MapObjectList *p) {
    s32 i;

    if (p->mUnk_1c != NULL) {
        p->mUnk_24 = HeapAlloc(GetHeap(func_020364e8()), p->mMapObjectCount * 4);
        for (i = 0; i < p->mMapObjectCount; i++) {
            p->mUnk_24[i] = p->mMapObjects[i];
        }
    } else {
        p->mUnk_24 = p->mMapObjects;
    }
}
#pragma thumb off

void SetCourseWater(Water *p0) {
    gCourseWater = p0;
}

void SetCourseWaterEfct(void *p0) {
    gCourseWaterEfct = p0;
}

void func_020d47e0(void) {
    u32 f;
    s32 i;
    s32 n;
    MapObject *e;
    MapObject **t;
    u32 g;
    u16 a;
    u32 b;

    n = gMapObjects->mMapObjectCount;
    t = gMapObjects->mMapObjects;
    f = GetKartKind3ShapeMask();
    g = GetRaceUpdateFrames() & 3;
    i = 0;
    if (n <= 0) {
        return;
    }
    a = data_021568ec;
    b = data_021568f0;
    do {
        e = t[i];
        e->mDistanceSquaredAndFlags &= ~8;
        if (!(e->mFlags & 2)) {
            if (e->mDistanceSquaredAndFlags & 1) {
                if (e->mAlpha != 0) {
                    e->mAlpha -= 1;
                }
            } else {
                if (e->mAlpha < 0x1f) {
                    e->mAlpha += 1;
                }
            }
            if ((i & 3) == g) {
                if (e->mDigitMask & f) {
                    e->mDistanceSquaredAndFlags = (e->mDistanceSquaredAndFlags & 0x10) | 0x5f592e7;
                    e->mFlags |= a;
                } else {
                    if (e->mUseTwoPlaneViewTest != 0) {
                        e->mDistanceSquaredAndFlags = (e->mDistanceSquaredAndFlags & 0x10) |
                                                      func_01ffd648(&e->mPos, e->mViewRadius, e->mDrawDistance,
                                                                    e->mFarDistanceSquared, e->mAlpha);
                    } else {
                        e->mDistanceSquaredAndFlags = (e->mDistanceSquaredAndFlags & 0x10) |
                                                      func_01ffd778(&e->mPos, e->mViewRadius, e->mDrawDistance,
                                                                    e->mFarDistanceSquared, e->mAlpha);
                    }
                    e->mDistanceSquaredAndFlags |= b;
                    if (e->mDistanceSquaredAndFlags & 2) {
                        e->mFlags |= a;
                    } else {
                        e->mFlags &= ~0x10;
                    }
                }
            }
        }
    } while (++i < n);
}

void func_020d4698(void) {
    u32 f;
    s32 i;
    s32 n;
    MapObject *e;
    MapObject **t;
    u16 a;
    u32 b;

    f = GetKartKind3ShapeMask();
    i = 0;
    n = gMapObjects->mMapObjectCount;
    t = gMapObjects->mMapObjects;
    if (n <= 0) {
        return;
    }
    a = data_021568ec;
    b = data_021568f0;
    do {
        e = t[i];
        e->mDistanceSquaredAndFlags &= ~8;
        if (!(e->mFlags & 2)) {
            if (e->mDigitMask & f) {
                e->mFlags |= a;
            } else {
                if (e->mUseTwoPlaneViewTest != 0) {
                    e->mDistanceSquaredAndFlags =
                        (e->mDistanceSquaredAndFlags & 0x10) |
                        func_01ffd648(&e->mPos, e->mViewRadius, e->mDrawDistance, e->mFarDistanceSquared, e->mAlpha);
                } else {
                    e->mDistanceSquaredAndFlags =
                        (e->mDistanceSquaredAndFlags & 0x10) |
                        func_01ffd778(&e->mPos, e->mViewRadius, e->mDrawDistance, e->mFarDistanceSquared, e->mAlpha);
                }
                e->mDistanceSquaredAndFlags |= b;
                if (e->mDistanceSquaredAndFlags & 1) {
                    e->mAlpha = 0;
                } else {
                    e->mAlpha = 0x1f;
                }
                if (e->mDistanceSquaredAndFlags & 2) {
                    e->mFlags |= a;
                } else {
                    e->mFlags &= ~0x10;
                }
            }
        }
    } while (++i < n);
}

void UpdateMapObjects(void) {
    MapObjectList *e;
    s32 i;
    s32 n;
    MapObjectList **t;
    s32 r;

    t = gMapObjects->mUpdateLists;
    n = gMapObjects->mUpdateListCount;
    r = GetRaceStartSequenceFrames();
    if (r <= 0x168) {
        if (gRaceSetup->mRaceKind != RACE_KIND_START_GP) {
            if (r == -0x73) {
                func_020d3b74();
            } else if (r == 0x168) {
                func_020d3b10();
            }
        }
    }
    if (gMapObjects->mRunUpdateLists != 0) {
        for (i = 0; i < n; i++) {
            e = t[i];
            if (e->mBeforeObjects != NULL) {
                e->mBeforeObjects(e);
            }
            UpdateMapObjectList(e);
            if (e->mAfterObjects != NULL) {
                e->mAfterObjects(e);
            }
        }
    }
    if (func_020d50b4() != 0) {
        func_020d4698();
    } else {
        func_020d47e0();
    }
    if (gCourseWater != NULL) {
        UpdateWater(gCourseWater);
    }
}

void DrawMapObjects(Unk020d4418 *p) {
    s32 i;
    s32 n;
    MapObjectList **t;
    MapObjectList *e;
    MtxFx43 *v;
    s32 k;
    s32 j;

    v = &p->mUnk_30;
    func_020d4d44(v);
    if (gCourseWater != NULL) {
        DrawWater(gCourseWater, v);
    }
    i = 0;
    n = gMapObjects->mUnk_12a;
    t = gMapObjects->mUnk_068;
    for (; i < n; i++) {
        e = t[i];
        func_0208ab00();
        if (e->mBeforeObjects != NULL) {
            e->mBeforeObjects(e);
        }
        DrawMapObjectList(e, v);
        if (e->mAfterObjects != NULL) {
            e->mAfterObjects(e);
        }
    }
    func_020e6a74();
    j = 0;
    k = gMapObjects->mUnk_12c;
    t = gMapObjects->mUnk_0c8;
    for (; j < k; j++) {
        e = t[j];
        if (e->mBeforeObjects != NULL) {
            e->mBeforeObjects(e);
        }
        DrawMapObjectList(e, v);
        if (e->mAfterObjects != NULL) {
            e->mAfterObjects(e);
        }
    }
}

void func_020d4418(Unk020d4418 *p) {
    MtxFx43 *v;

    v = &p->mUnk_30;
    if (gMapObjects->mUnk_17c != 0) {
        func_020dff88(v);
    }
    if (gMapObjects->mUnk_180 != 0) {
        func_020e435c(v);
    }
    if (gMapObjects->mUnk_184 != 0) {
        func_020e3b28(v);
    }
}

s32 func_020d41e0(Kart *a, Vec3 *b, Vec3 *c) {
    Vec3 v;
    Vec3 lo;
    Vec3 hi;
    s32 q;
    BOOL k;
    s32 r;
    s32 i;
    MapObject *e;
    s32 n;
    Vec3 *p;

    v = *b;
    k = (a->mUnk_48 & 0x8000000) != 0;
    q = a->mRadius;
    r = a->mItemEffect;
    p = data_0217b4dc;
    {
        Vec3 z1 = {0, 0, 0};
        lo = z1;
    }
    {
        Vec3 z2 = {0, 0, 0};
        hi = z2;
    }
    n = 0;
    c->x = c->y = c->z = 0;
    for (i = 0; i < data_0217b5a8; i++) {
        if (data_0217b5bc[i] & 0x2000) {
            e = data_0217b5c4[i];
            if (k != FALSE && !(e->mDistanceSquaredAndFlags & 0x10)) {
                continue;
            }
            if (func_020d3e34(&v, q, e, p) != FALSE) {
                if (!(e->mFlags & 0x40) && func_020d69e4(r, e) != 0) {
                    lo.x = (p->x < lo.x) ? p->x : lo.x;
                    lo.y = (p->y < lo.y) ? p->y : lo.y;
                    lo.z = (p->z < lo.z) ? p->z : lo.z;
                    hi.x = (p->x > hi.x) ? p->x : hi.x;
                    hi.y = (p->y > hi.y) ? p->y : hi.y;
                    hi.z = (p->z > hi.z) ? p->z : hi.z;
                }
                data_0217b4e8[n] = e;
                n++;
                p = &data_0217b4dc[n];
                if (n >= 0x20) {
                    n = 0x1f;
                }
            }
        }
    }
    if (n != 0 && c != NULL) {
        c->x = hi.x + lo.x;
        c->y = hi.y + lo.y;
        if (c->y < 0) {
            c->y = 0;
        }
        c->z = hi.z + lo.z;
    }
    return n;
}

s32 func_020d4130(Vec3 *a, s32 b, s32 c) {
    s32 n;
    MapObject *e;
    s32 d;
    s32 f;
    s32 i;

    n = 0;
    func_020d5180(a, b, 0x2000);
    for (i = 0; i < data_0217b5a8; i++) {
        e = data_0217b5c4[i];
        if (e->mKind == c) {
            f = a->x - e->mPos.x;
            d = a->z - e->mPos.z;
            if ((s64) f * f + (s64) d * d < (s64) b * b) {
                data_0217b4e8[n] = e;
                n++;
            }
        }
    }
    return n;
}

// Returns the i-th map object stored by the last func_020d41e0 or func_020d4130 call; i must be below the count that
// call returned.
MapObject *GetFoundMapObject(u32 arg0) {
    return data_0217b4e8[arg0];
}

Vec3 *func_020d4104(int arg0) {
    return data_0217b4dc + arg0;
}

BOOL func_020d3e34(Vec3 *a, s32 b, MapObject *c, Vec3 *d) {
    s32 t;
    s32 u;
    s32 dx;
    s32 dy;
    s32 dz;
    BOOL r;
    s32 n;
    if (c->mFlags & 1) {
        return FALSE;
    }
    switch (c->mKindData->mUnk_08) {
        case 1:
            t = b + c->mExtent.x;
            n = -t;
            dz = a->z - c->mPos.z;
            if (dz > t || dz < n) {
                r = FALSE;
            } else {
                dx = a->x - c->mPos.x;
                if (dx > t || dx < n) {
                    r = FALSE;
                } else {
                    dy = a->y - c->mPos.y;
                    if (dy > t || dy < n) {
                        r = FALSE;
                    } else {
                        r = (s64) dx * dx + (s64) dy * dy + (s64) dz * dz < (s64) t * t;
                    }
                }
            }
            if (r == FALSE) {
                return FALSE;
            }
            func_020eb3f0(a, &c->mPos, t, d);
            return TRUE;
        case 2:
            t = b + c->mExtent.x;
            u = b + c->mExtent.y;
            n = -t;
            dz = a->z - c->mPos.z;
            if (dz > t || dz < n) {
                r = FALSE;
            } else {
                dx = a->x - c->mPos.x;
                if (dx > t || dx < n) {
                    r = FALSE;
                } else {
                    dy = a->y - c->mPos.y;
                    if (dy > u || dy < -u) {
                        r = FALSE;
                    } else {
                        r = (s64) dx * dx + (s64) dz * dz < (s64) t * t;
                    }
                }
            }
            if (r == FALSE) {
                return FALSE;
            }
            func_020eb2a0(a, &c->mPos, t, u, d);
            return TRUE;
        case 3:
            return func_020ead80(a, &c->mPos, &c->mMatrix.mUnk_00[0], c->mExtent.x, c->mExtent.y, c->mExtent.y, b, d) !=
                   0;
        case 4:
            return func_020eafc4(a, &c->mPos, &c->mMatrix.mUnk_00[0], &c->mExtent, &c->mExtent, b, d) != 0;
        case 0:
            return FALSE;
        case 5:
            if (c->mKindData->mUnk_18 != NULL) {
                return c->mKindData->mUnk_18(c, a, b, d) != 0;
            }
            return FALSE;
        default:
            return FALSE;
    }
}

// TRUE when the course has a water object (gCourseWater is not NULL); asked by the camera and the HUD gauge.
BOOL IsWaterPresent(void) {
    return gCourseWater != NULL;
}

// y minus mHeight of gCourseWater (negative below the water), 0x270f000 when the course has no water; asked by the
// camera; it does not look at mUnk_170 or WaterEfct.
s32 GetHeightAboveWater(s32 a) {
    return gCourseWater != NULL ? a - gCourseWater->mHeight : 0x270f000;
}

// mHeightFactor of gCourseWater, 0 when the course has no water; asked by the HUD gauge.
s32 GetWaterHeightFactor(void) {
    return gCourseWater != NULL ? gCourseWater->mHeightFactor : 0;
}

// mHeightAngle of gCourseWater, 0 when the course has no water; the HUD gauge tests 0x4000 <= angle < 0xc000 (the
// falling half).
u32 GetWaterHeightAngle(void) {
    return gCourseWater != NULL ? gCourseWater->mHeightAngle : 0;
}

u32 func_020d3d94(void) {
    u32 r = 0;
    if (gCourseWater == NULL) {
        return r;
    }
    if (gCourseWater->mUnk_170 != 0) {
        r = 1;
    }
    return r;
}

// Y minus mHeight when the Water exists and mUnk_170 is non-zero (mini stage 3, beach), else y minus WaterEfct.mHeight,
// else 0x270f000; Or = the second source when the first is not used; asked by the kart steps, the kart sound and the
// overlay-1 objects.
s32 GetHeightAboveWaterOrEfct(s32 a) {
    if (gCourseWater != NULL && gCourseWater->mUnk_170 != 0) {
        return a - gCourseWater->mHeight;
    }
    return gCourseWaterEfct != NULL ? a - gCourseWaterEfct->mHeight : 0x270f000;
}

s32 func_020d3d10(s32 b) {
    BOOL a;
    a = FALSE;
    if (gCourseWaterEfct != NULL) {
        if (b - gCourseWaterEfct->mHeight < -0x32000) {
            a = TRUE;
        }
    }
    return a;
}

void func_020d3cc8(void) {
    s32 i;
    s32 n;
    MapObjects *q;
    MapObjectList **p;
    i = 0;
    q = gMapObjects;
    n = q->mUpdateListCount;
    p = q->mUpdateLists;
    for (; i < n; i++) {
        func_020e6fd4(p[i]);
    }
}

s32 func_020d3c94(MapObject *a, s32 b, Vec3 *c) {
    return func_020d2c2c(&a->mPos, &a->mUnk_10, a->mExtent.x, a->mCollisionSlotIndex, b, c);
}

void SetMapObjectsRunUpdateLists(void) {
    gMapObjects->mRunUpdateLists = 1;
}

u16 AllocPolygonIdWrapping(void) {
    data_0217b4c4++;
    if (data_0217b4c4 > 0x3e) {
        data_0217b4c4 = data_0217b4c8;
    }
    return data_0217b4c4;
}

u16 AllocPolygonId(void) {
    return data_0217b4d0++;
}

#pragma thumb on

u16 CountMapObjectsOfKind(u32 b) {
    s32 i;
    u16 a;
    a = 0;
    i = 0;
    for (; i < gMapObjects->mMapObjectCount; i++) {
        if (b == gMapObjects->mMapObjects[i]->mKind) {
            a++;
        }
    }
    return a;
}

void func_020d3b74(void) {
    s32 i;
    s32 n;
    MapObject **p;
    MapObject *q;
    n = gMapObjects->mMapObjectCount;
    p = gMapObjects->mMapObjects;
    for (i = 0; i < n; i++) {
        q = *p;
        if (q->mFlags & 0x80) {
            if (q->mFlags & 0x100) {
                q->mFlags &= ~0x80;
            } else {
                q->mFlags &= ~0xf000;
                q->mFlags |= (q->mFlags & 0xf) << 12;
                q->mFlags |= data_021568dc;
                if (q->mCollisionSlotIndex != -1) {
                    func_020d5114(q->mCollisionSlotIndex);
                }
            }
        }
        p++;
    }
}

void func_020d3b10(void) {
    s32 i;
    s32 n;
    MapObject **p;
    MapObject *q;
    n = gMapObjects->mMapObjectCount;
    p = gMapObjects->mMapObjects;
    for (i = 0; i < n; i++) {
        q = *p;
        if (q->mFlags & 0x80) {
            q->mFlags &= ~0x80;
            q->mFlags &= ~0xf;
            q->mFlags |= (q->mFlags & 0xf000) >> 12;
            if (q->mCollisionSlotIndex != -1) {
                func_020d50ec(q->mCollisionSlotIndex);
            }
        }
        p++;
    }
}

#pragma thumb off

#pragma thumb on

// Stores the mask of the nonzero decimal digits of a (bit d for digit d) in mUnk_74; a of 10000 or more first sets flag
// 0x80 in mFlags and loses the 10000.
void SetMapObjectMaskAndFlagFromNumber(s32 a, MapObject *b) {
    int v1;
    u32 v2;
    v1 = 0x2710;
    if (0x2710 <= a) {
        b->mFlags = b->mFlags | data_021568e8;
        a = (a - v1) * 0x10000 >> 0x10;
    }
    v2 = DecimalNonZeroDigitsToBitMask(a);
    b->mDigitMask = v2;
}

#pragma thumb off
