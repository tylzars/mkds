#include "Main/Unknown/code_0209bf70.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_02042044.h"
#include "Main/Unknown/unk_021759c0.h"

#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_0209b634.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_0209bc5c.h"
#include "Main/Unknown/code_0209bef0.h"
#include "Main/Unknown/code_0209d5e8.h"
#include "Main/Unknown/code_0209d5ec.h"
#include "Main/Unknown/code_0209d694.h"
#include "Main/Unknown/code_0203c8c0.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_0207a000.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_0208aea8.h"
#include "Main/Unknown/code_0208b484.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_020a1e40.h"
#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/code_020d2450.h"
#include "Main/Unknown/code_020d26e0.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_020d7da8.h"
#include "Main/Unknown/code_020d8bc0.h"
#include "Main/Unknown/code_020d8cac.h"
#include "Main/Unknown/code_020ea670.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/code_021000d0.h"
#include "Main/Unknown/code_020ec8bc.h"
#include "Main/Unknown/code_021031f4.h"
#include "Main/Unknown/code_0210b760.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_020d8918.h"
#include "Main/Unknown/code_020ac524.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_020e6b58.h"
#include "Main/Unknown/code_020d3b10.h"
#include "Main/Unknown/code_0209d650.h"
#include "Main/Unknown/code_02077bc0.h"

void InitSun(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    u32 value4;
    value4 = value0;
    value1 = *(const u32 *) ((value4) + (156));
    value0 = (value4) + (0xb8u);
    value2 = 0u;
    InitGroupFollower((Unk020e0144 *) value0, (CourseMapRow *) value1, value2);
    value0 = 0x1aeu;
    value2 = value4;
    value1 = 0x1eu;
    CreateParkedMapObjects(value0, value1, (void *) value2);
    value0 = 0u;
    *(u32 *) ((value4) + (16)) = value0;
    *(u32 *) ((value4) + (20)) = value0;
    *(u32 *) ((value4) + (24)) = value0;
}

void CreateSunAndSunLOD(void *a) {
    gSun = CreateMapObjectModelAnimated(a, gSunNsbmdName);
    CreateMapObjectModelNsbcaAnimation(gSun, gSunNsbcaName);
    gSunLOD = CreateMapObjectModelAnimated(a, gSunLODNsbmdName);
    SetMapObjectModelPolygonId(gSun, AllocPolygonId());
}

u32 func_0209d5e8(u32 p0) {
    return p0;
}

void DrawSun(void *a, Unk0209d3fc *b) {
    s32 s;
    s32 t;
    s32 k;
    Vec3 v;

    s = 0x1e;
    func_01ff9048(0x14, &s, 1);
    func_01ff9048(0x19, SetViewTransposeMatrixPos(&b->mUnk_00.mPos), 0xc);
    if (b->mState == 3 || b->mState == 4) {
        t = (s32) (((s64) gPairsByAngle[((u16) b->mUnk_ac >> 4) * 2 + 1] * -0x14000) >> 12) + 0x14000;
        k = (b->mUnk_b0 >> 4) * 2;
        v.x = (s32) (((s64) t * gPairsByAngle[k + 1]) >> 12) >> 4;
        v.y = (s32) (((s64) t * gPairsByAngle[k]) >> 12) >> 4;
        v.z = 0;
        func_01ff9048(0x1c, &v, 3);
    }
    func_01ff9048(0x1b, &b->mUnk_00.mScale, 3);
    if (GetCurrentCameraKind() == 2) {
        func_0209bbd0(a, gSun);
        SetMapObjectModelNsbcaFrameIndex(gSun, b->mNsbcaFrameIndex);
        DrawMapObjectModel(a, gSun, b);
    } else if ((s32) (b->mUnk_00.mDistanceSquaredAndFlags & 0x3fffffe0) < 0x3d0900) {
        func_0209bbd0(a, gSun);
        SetMapObjectModelNsbcaFrameIndex(gSun, b->mNsbcaFrameIndex);
        DrawMapObjectModel(a, gSun, b);
    } else {
        func_0209bbd0(a, gSunLOD);
        DrawMapObjectModel1Mat1Shp(a, gSunLOD, b);
    }
}

static inline u32 CollideKartWithBound_inline(Unk020f41c4_B *b) {
    b->mValue = b->mMultiplier * b->mValue + b->mIncrement;
    return b->mValue >> 32;
}

void InitSunObjects(Unk02100094 *a) {
    s32 i;
    Sun *p;

    if (a == NULL) {
        return;
    }
    for (i = 0; i < a->mUnk_04 && (p = a->mUnk_00[i]) != NULL; i++) {
        if (gRaceSetup->mMode == MODE_TIME_ATTACK) {
            p->mTimer = (u16) p->mUnk_000.mCourseMapRow->mUnk_28;
        } else if (gRaceSetup->mMode == 5) {
            p->mTimer = (u16) p->mUnk_000.mCourseMapRow->mUnk_2a;
        }
    }
}

static inline BOOL UpdateSun_inline(void) {
    s32 i;

    for (i = 0; i < gRaceSetup->mKartCount; i++) {
        if ((s32) GetKartHighestLap((u16) i) >= 2) {
            return TRUE;
        }
    }
    return FALSE;
}

static inline BOOL UpdateSun_inline_b(Sun *p) {
    s32 i;
    Kart *k;
    Vec3 *q;
    s32 x;
    s32 z;

    for (i = 0; i < gRaceSetup->mKartCount; i++) {
        k = GetKart((u16) i);
        q = &k->mPos;
        x = q->x - p->mUnk_000.mPos.x;
        z = q->z - p->mUnk_000.mPos.z;
        if ((s64) x * x + (s64) z * z < 0x15f900000000LL) {
            return TRUE;
        }
    }
    return FALSE;
}

void UpdateSun(Unk02100094 *a, Sun *p) {
    Vec3 v;
    Vec3 w;
    s32 t;
    s32 k;

    switch (p->mState) {
        case 0:
            if (p->mUnk_000.mFlags & 0x800) {
                if (p->mTimer-- <= 0) {
                    p->mState = 1;
                }
            } else if (UpdateSun_inline()) {
                p->mState = 1;
            }
            break;
        case 1:
            p->mUnk_0b8.mUnk_04 = 0x3c000;
            p->mUnk_0b8.mUnk_10 = ((s64) p->mUnk_0b8.mUnk_00->mUnk_00[p->mUnk_0b8.mUnk_0c].mUnk_34 * 0x3c000) >> 12;
            if (func_020d8cc8(&p->mUnk_0b8) != FALSE && (t = p->mUnk_0b8.mUnk_1c->mUnk_0e) != 0) {
                if (p->mUnk_000.mFlags & 0x800) {
                    k = gRaceSetup->mMode;
                    if (k == MODE_TIME_ATTACK) {
                        p->mTimer = t;
                    } else if (k == 5) {
                        p->mTimer = p->mUnk_0b8.mUnk_1c->mUnk_10;
                    }
                }
                p->mState = 2;
            }
            GetGroupFollowerLinearPosition(&p->mUnk_0b8, &p->mUnk_000.mPos);
            break;
        case 2:
            if (p->mUnk_000.mFlags & 0x800) {
                if (p->mTimer-- <= 0) {
                    p->mUnk_0b0 = 0;
                    p->mUnk_0ac = p->mUnk_0b0;
                    p->mTimer = 5;
                    p->mState = 3;
                }
            } else if (UpdateSun_inline_b(p)) {
                p->mUnk_0b0 = 0;
                p->mUnk_0ac = p->mUnk_0b0;
                p->mTimer = 5;
                p->mState = 3;
            }
            break;
        case 3:
            p->mUnk_0b0 += 0xe39;
            if (p->mUnk_0ac < 0x8000) {
                p->mUnk_0ac += 0x222;
            }
            if (p->mTimer-- > 0) {
                break;
            }
            if (p->mUnk_0a0 == 0) {
                p->mUnk_0a4 = ((u64) CollideKartWithBound_inline(GetMapObjectRandom()) * 0x10000) >> 32;
            } else {
                p->mUnk_0a4 += 0x8000;
            }
            v.x = p->mUnk_000.mPos.x;
            v.y = p->mUnk_000.mPos.y - 0x1e000;
            v.z = p->mUnk_000.mPos.z;
            w.x = gPairsByAngle[(p->mUnk_0a4 >> 4) * 2];
            w.y = 0;
            w.z = gPairsByAngle[(p->mUnk_0a4 >> 4) * 2 + 1];
            func_0209d694(&v, &w);
            p->mUnk_0a0 += 1;
            if (p->mUnk_0a0 >= 2) {
                p->mUnk_0a0 = 0;
                p->mState = 4;
            } else {
                p->mTimer = 0x1e;
            }
            break;
        case 4:
            p->mUnk_0b0 += 0xe39;
            p->mUnk_0ac += 0x222;
            if (p->mUnk_0ac > 0x10000) {
                p->mTimer = 0x1e;
                p->mState = 0;
            }
            break;
    }
    if ((s32) (p->mUnk_000.mDistanceSquaredAndFlags & ~0xc000001f) >= 0x3d0900) {
        return;
    }
    if (p->mState == 3) {
        t = p->mNsbcaFrameIndexPerFrame + 0x19a;
        if (t >= 0x8000) {
            t = 0x8000;
        }
        p->mNsbcaFrameIndexPerFrame = t;
    } else {
        t = p->mNsbcaFrameIndexPerFrame - 0x19a;
        if (t <= 0x1000) {
            t = 0x1000;
        }
        p->mNsbcaFrameIndexPerFrame = t;
    }
    p->mNsbcaFrameIndex += p->mNsbcaFrameIndexPerFrame >> 12;
    if (p->mNsbcaFrameIndex >= GetMapObjectModelNsbcaFrameCount(gSun)) {
        p->mNsbcaFrameIndex = 0;
    }
}

void CreateSunDrawList(void) {
    CreateMapObjectDrawList1(CreateSunAndSunLOD, DrawSun, func_0209d5e8);
}

void CreateSunUpdateList(void) {
    CreateMapObjectUpdateList(InitSunObjects, UpdateSun, NULL);
}

void InitBound(Bound *p) {
    p->mUnk_000.mFlags |= data_usa_021565d4;
    RefreshMapObjectMatrixFromHitNormal(p);
    p->mInitialScaleX = p->mUnk_000.mScale.x;
}

// Shared by Bound, Cream and Berry: sets the object's motion from the Kart, starts the wobble and plays a sound.
s32 CollideKartWithBound(Bound *p, Kart *k, u8 *b, u8 *c) {
    Vec3 v0;
    Vec3 v1;
    Vec3 v2;
    Vec3 v3;
    Vec3 *q;
    u8 d;
    s32 t;
    u32 e;

    e = *b;
    d = *c;
    if (e == 3 || e == 4) {
        if (p->mKartTimers[k->mIndex] == 0) {
            VEC_Subtract(&k->mPos, &p->mUnk_000.mPos, &v2);
            t = VEC_DotProduct(&k->mVelocityDirection, &v2);
            v0.x = ((s64) k->mVelocityDirection.x * t) >> 12;
            v0.y = ((s64) k->mVelocityDirection.y * t) >> 12;
            v0.z = ((s64) k->mVelocityDirection.z * t) >> 12;
            v1.x = v2.x - v0.x;
            v1.y = v2.y - v0.y;
            v1.z = v2.z - v0.z;
            t = VEC_DotProduct(&p->mUnk_000.mMatrix.mUnk_00[1], &v1);
            v0.x = ((s64) p->mUnk_000.mMatrix.mUnk_00[1].x * t) >> 12;
            v0.y = ((s64) p->mUnk_000.mMatrix.mUnk_00[1].y * t) >> 12;
            v0.z = ((s64) p->mUnk_000.mMatrix.mUnk_00[1].z * t) >> 12;
            v1.x -= v0.x;
            v1.y -= v0.y;
            v1.z -= v0.z;
            if ((s64) v1.x * v1.x + (s64) v1.y * v1.y + (s64) v1.z * v1.z < 0x10) {
                q = &k->mUnk_120;
                p->mUnk_000.mUnk_10.x = ((s64) k->mUnk_120.x * 0xc000) >> 12;
                p->mUnk_000.mUnk_10.y = ((s64) q->y * 0xc000) >> 12;
                p->mUnk_000.mUnk_10.z = ((s64) q->z * 0xc000) >> 12;
            } else {
                Vec3NormalizeAndGetLengthUnchecked(&v1, &v1);
                p->mUnk_000.mUnk_10.x = ((s64) v1.x * 0xc000) >> 12;
                p->mUnk_000.mUnk_10.y = ((s64) v1.y * 0xc000) >> 12;
                p->mUnk_000.mUnk_10.z = ((s64) v1.z * 0xc000) >> 12;
            }
            VEC_Subtract(&v0, &p->mUnk_000.mMatrix.mUnk_00[1], &v0);
            VEC_MultAdd(0x19a, &v0, &p->mUnk_000.mUnk_10, &p->mUnk_000.mUnk_10);
            p->mKartTimers[k->mIndex] = 0x1f;
            if (gRaceSetup->mMode == MODE_BATTLE) {
                CallStandingsKartOffsetCallback(k->mIndex, (s32) &p->mUnk_000.mUnk_10);
            }
        } else {
            p->mUnk_000.mUnk_10.x = 0;
            p->mUnk_000.mUnk_10.y = 0;
            p->mUnk_000.mUnk_10.z = 0;
        }
        if (gRaceSetup->mCurrentEntries[k->mIndex].mPlayer.mKind != PLAYER_KIND_GHOST && p->mWobbling == FALSE) {
            p->mWobbleXAngle = 0x8000;
            p->mWobbleXMid = 0x1000;
            p->mWobbleXAmplitude = 0x400;
            p->mWobbleXAmplitudePerFrame = -0x29;
            p->mWobbleXAnglePerFrame = 0x1000;
            p->mUnk_0d4 = 0;
            p->mWobbleYAngle = 0;
            p->mWobbleYMid = 0x1000;
            p->mWobbleYAmplitude = 0x400;
            p->mWobbleYAmplitudePerFrame = -0x29;
            p->mWobbleYAnglePerFrame = 0x1000;
            p->mUnk_0f4 = 0;
            p->mWobbling = TRUE;
            switch (p->mUnk_000.mKind) {
                case MAP_OBJECT_KIND_CREAM:
                    func_020d26ec(k, 0x156);
                    break;
                case MAP_OBJECT_KIND_BERRY:
                    func_020d26ec(k, 0x155);
                    break;
                case 0x1a8:
                    func_020d26ec(k, 0x1cf);
                    break;
            }
            if ((u16) (p->mUnk_000.mKind + 0xfe4c) <= 1) {
                StartOrthoQuadsCreamEffect(
                    k->mIndex, (u16) (((u64) CollideKartWithBound_inline(&gRaceProgress->mLocalRandom) * 3) >> 32) + 1);
                VEC_Subtract(&p->mUnk_000.mPos, &k->mCollisionCenter, &v3);
                if (!((s64) v3.x * v3.x + (s64) v3.y * v3.y + (s64) v3.z * v3.z < 0x10)) {
                    Vec3NormalizeAndGetLengthUnchecked(&v3, &v3);
                }
                VEC_MultAdd(k->mRadius, &v3, &k->mCollisionCenter, &v3);
                if (k->mIndex == gRaceSetup->mEntryIndex) {
                    StartEffect(0x74, &v3);
                } else {
                    StartEffect(0x75, &v3);
                }
            }
        }
        return d;
    }
    p->mUnk_000.mUnk_10.x = 0;
    p->mUnk_000.mUnk_10.y = 0;
    p->mUnk_000.mUnk_10.z = 0;
    return 2;
}

// Shared by Bound, Cream and Berry: when *b is 2, starts a smaller wobble; returns *c.
u8 CollideItemObjectWithBound(Bound *p, void *a, u8 *b, u8 *c) {
    u32 d;

    d = *c;
    if (*b == 2 && p->mWobbling == FALSE) {
        p->mWobbleXAngle = 0x8000;
        p->mWobbleXMid = 0x1000;
        p->mWobbleXAmplitude = 0x200;
        p->mWobbleXAmplitudePerFrame = -0x14;
        p->mWobbleXAnglePerFrame = 0x1000;
        p->mUnk_0d4 = 0;
        p->mWobbleYAngle = 0;
        p->mWobbleYMid = 0x1000;
        p->mWobbleYAmplitude = 0x200;
        p->mWobbleYAmplitudePerFrame = -0x14;
        p->mWobbleYAnglePerFrame = 0x1000;
        p->mUnk_0f4 = 0;
        p->mWobbling = TRUE;
        p->mUnk_000.mDistanceSquaredAndFlags |= data_usa_021565d0;
    }
    return d;
}

BOOL func_0209c8b0(Bound *p, Vec3 *a, s32 b, Vec3 *c) {
    if ((p->mUnk_000.mFlags & 0x800) == 0 && p->mWobbling == TRUE) {
        p->mUnk_0a4 = ComputeSphereHitOnRotatedCylinder(a, &p->mUnk_000.mPos, &p->mUnk_000.mMatrix.mUnk_00[0],
                                                        ((s64) p->mUnk_000.mExtent.x * p->mWobbleScaleX) >> 12,
                                                        p->mUnk_000.mExtent.y, 0, b, c);
    } else {
        p->mUnk_0a4 = ComputeSphereHitOnRotatedCylinder(a, &p->mUnk_000.mPos, &p->mUnk_000.mMatrix.mUnk_00[0],
                                                        p->mUnk_000.mExtent.x, p->mUnk_000.mExtent.y, 0, b, c);
    }
    return p->mUnk_0a4 != 0;
}

void CreateBound(void *a) {
    gBound = CreateMapObjectModelAnimated(a, gBoundNsbmdName);
    CreateMapObjectModelNsbtpAnimation(gBound, gBoundNsbtpName);
}

void DrawBound(Unk02100094 *a, Bound *p) {
    s32 v[4];
    s32 x;
    s32 y;

    v[0] = 0x1e;
    func_01ff9048(0x14, &v[0], 1);
    p->mUnk_000.mMatrix.mUnk_00[3].x = p->mUnk_000.mPos.x >> 4;
    p->mUnk_000.mMatrix.mUnk_00[3].y = p->mUnk_000.mPos.y >> 4;
    p->mUnk_000.mMatrix.mUnk_00[3].z = p->mUnk_000.mPos.z >> 4;
    func_01ff9048(0x19, &p->mUnk_000.mMatrix, 0xc);
    if (p->mWobbling == TRUE) {
        x = p->mWobbleScaleX;
        y = p->mWobbleScaleY;
        v[1] = x;
        v[2] = y;
        v[3] = x;
        func_01ff9048(0x1b, &v[1], 3);
    }
    func_01ff9048(0x1b, &p->mUnk_000.mScale, 3);
    SetMapObjectModelNsbtpFrameIndex(gBound, p->mNsbtpFrameIndex);
    DrawMapObjectModel(a, gBound, p);
}

void CreateCream(void *a) {
    gCream = CreateMapObjectModelAnimated(a, gCreamNsbmdName);
    CreateOrthoQuadCreamEffect(data_usa_02167328);
}

void CreateBerry(void *a) {
    gBerry = CreateMapObjectModelAnimated(a, gBerryNsbmdName);
    CreateOrthoQuadCreamEffect(gCreamEffectNsbmdName);
}

void DrawCream(Unk02100094 *a, Bound *p) {
    s32 v[4];
    s32 x;
    s32 y;

    v[0] = 0x1e;
    func_01ff9048(0x14, &v[0], 1);
    p->mUnk_000.mMatrix.mUnk_00[3].x = p->mUnk_000.mPos.x >> 4;
    p->mUnk_000.mMatrix.mUnk_00[3].y = p->mUnk_000.mPos.y >> 4;
    p->mUnk_000.mMatrix.mUnk_00[3].z = p->mUnk_000.mPos.z >> 4;
    func_01ff9048(0x19, &p->mUnk_000.mMatrix, 0xc);
    if (p->mWobbling == TRUE) {
        x = p->mWobbleScaleX;
        y = p->mWobbleScaleY;
        v[1] = x;
        v[2] = y;
        v[3] = x;
        func_01ff9048(0x1b, &v[1], 3);
    }
    func_01ff9048(0x1b, &p->mUnk_000.mScale, 3);
    DrawMapObjectModel(a, gCream, p);
}

void DrawBerry(Unk02100094 *a, Bound *p) {
    s32 v[4];
    s32 x;
    s32 y;

    v[0] = 0x1e;
    func_01ff9048(0x14, &v[0], 1);
    p->mUnk_000.mMatrix.mUnk_00[3].x = p->mUnk_000.mPos.x >> 4;
    p->mUnk_000.mMatrix.mUnk_00[3].y = p->mUnk_000.mPos.y >> 4;
    p->mUnk_000.mMatrix.mUnk_00[3].z = p->mUnk_000.mPos.z >> 4;
    func_01ff9048(0x19, &p->mUnk_000.mMatrix, 0xc);
    if (p->mWobbling == TRUE) {
        x = p->mWobbleScaleX;
        y = p->mWobbleScaleY;
        v[1] = x;
        v[2] = y;
        v[3] = x;
        func_01ff9048(0x1b, &v[1], 3);
    }
    func_01ff9048(0x1b, &p->mUnk_000.mScale, 3);
    DrawMapObjectModel(a, gBerry, p);
}

void InitBoundAndCreamAndBerryObjects(Unk02100094 *a) {
    s32 i;
    Bound *p;

    if (a == NULL) {
        return;
    }
    for (i = 0; i < a->mUnk_04 && (p = a->mUnk_00[i]) != NULL; i++) {
        if (p->mUnk_000.mCourseMapRow->mUnk_26 >= 0) {
            InitGroupFollower(&p->mUnk_0f8, p->mUnk_000.mCourseMapRow, 0);
            p->mUnk_0f8.mUnk_04 = 0x3000;
            p->mUnk_0f8.mUnk_10 = ((s64) p->mUnk_0f8.mUnk_00->mUnk_00[p->mUnk_0f8.mUnk_0c].mUnk_34 * 0x3000) >> 12;
        } else {
            p->mUnk_0f8.mUnk_08 = 0xffff;
        }
    }
}

s16 func_0209c4d8(s32 a) {
    return gPairsByAngle[(a >> 4) * 2];
}

s32 func_0209c4bc(s32 a, s32 b) {
    return ((s64) a * b + 0x800) >> 12;
}

void UpdateBoundAndCreamAndBerry(Unk02100094 *a, Bound *p) {
    u16 v;
    s32 t;
    s32 i;
    s32 n;

    if (p->mUnk_0f8.mUnk_08 != 0xffff) {
        func_020d8cc8(&p->mUnk_0f8);
        func_020d8bf8(&p->mUnk_0f8, &p->mUnk_000.mPos, &p->mUnk_000.mUnk_10);
        v = GetMapObjectModelNsbtpFrameCount(gBound);
        p->mNsbtpFrameIndex += 1;
        if (p->mNsbtpFrameIndex >= v) {
            p->mNsbtpFrameIndex = 1;
        }
    } else {
        p->mUnk_000.mUnk_10.x = 0;
        p->mUnk_000.mUnk_10.y = 0;
        p->mUnk_000.mUnk_10.z = 0;
        p->mNsbtpFrameIndex = 0;
    }
    if (p->mWobbling == TRUE) {
        p->mWobbleXAngle += p->mWobbleXAnglePerFrame;
        t = func_0209c4bc(p->mWobbleXAmplitude, func_0209c4d8(p->mWobbleXAngle));
        p->mUnk_0c0 = p->mWobbleXMid + t - p->mWobbleScaleX;
        p->mWobbleScaleX += p->mUnk_0c0;
        if (p->mWobbleXAmplitude > 0) {
            t = p->mWobbleXAmplitude + p->mWobbleXAmplitudePerFrame;
            if (t <= 0) {
                t = 0;
            }
            p->mWobbleXAmplitude = t;
        } else if (p->mWobbleXAmplitude < 0) {
            t = p->mWobbleXAmplitude + p->mWobbleXAmplitudePerFrame;
            if (t >= 0) {
                t = 0;
            }
            p->mWobbleXAmplitude = t;
        }
        if (p->mWobbleXAnglePerFrame > 0) {
            t = p->mWobbleXAnglePerFrame + p->mUnk_0d4;
            if (t <= 0) {
                t = 0;
            }
            p->mWobbleXAnglePerFrame = t;
        } else if (p->mWobbleXAnglePerFrame < 0) {
            t = p->mWobbleXAnglePerFrame + p->mUnk_0d4;
            if (t >= 0) {
                t = 0;
            }
            p->mWobbleXAnglePerFrame = t;
        }
        p->mWobbleYAngle += p->mWobbleYAnglePerFrame;
        t = func_0209c4bc(p->mWobbleYAmplitude, func_0209c4d8(p->mWobbleYAngle));
        p->mUnk_0e0 = p->mWobbleYMid + t - p->mWobbleScaleY;
        p->mWobbleScaleY += p->mUnk_0e0;
        if (p->mWobbleYAmplitude > 0) {
            t = p->mWobbleYAmplitude + p->mWobbleYAmplitudePerFrame;
            if (t <= 0) {
                t = 0;
            }
            p->mWobbleYAmplitude = t;
        } else if (p->mWobbleYAmplitude < 0) {
            t = p->mWobbleYAmplitude + p->mWobbleYAmplitudePerFrame;
            if (t >= 0) {
                t = 0;
            }
            p->mWobbleYAmplitude = t;
        }
        if (p->mWobbleYAnglePerFrame > 0) {
            t = p->mWobbleYAnglePerFrame + p->mUnk_0f4;
            if (t <= 0) {
                t = 0;
            }
            p->mWobbleYAnglePerFrame = t;
        } else if (p->mWobbleYAnglePerFrame < 0) {
            t = p->mWobbleYAnglePerFrame + p->mUnk_0f4;
            if (t >= 0) {
                t = 0;
            }
            p->mWobbleYAnglePerFrame = t;
        }
        if (p->mWobbleXAmplitude == 0 && p->mWobbleYAmplitude == 0) {
            p->mWobbling = FALSE;
            p->mUnk_000.mScale.x = p->mInitialScaleX;
        } else {
            p->mUnk_000.mScale.x = ((s64) p->mInitialScaleX * p->mWobbleScaleX) >> 12;
        }
    } else {
        p->mUnk_000.mScale.x = p->mInitialScaleX;
    }
    n = gRaceSetup->mKartCount;
    for (i = 0; i < n; i++) {
        if (p->mKartTimers[i] > 0) {
            p->mKartTimers[i] -= 1;
        }
    }
}

void CreateBoundKindData(void) {
    Unk0209bf70 *o;

    o = CreateMapObjectKindData(CollideKartWithBound, CollideItemObjectWithBound, func_0209c8b0, 1, 1);
    o->mUnk_28 = 0x1cf;
}

void CreateCreamKindData(void) {
    Unk0209bf70 *o;

    o = CreateMapObjectKindData(CollideKartWithBound, CollideItemObjectWithBound, func_0209c8b0, 1, 1);
    o->mUnk_28 = 0x156;
}

void CreateBerryKindData(void) {
    Unk0209bf70 *o;

    o = CreateMapObjectKindData(CollideKartWithBound, CollideItemObjectWithBound, func_0209c8b0, 1, 1);
    o->mUnk_28 = 0x155;
}

void CreateBoundDrawList(void) {
    CreateMapObjectDrawList1(CreateBound, DrawBound, NULL);
}

void CreateCreamDrawList(void) {
    CreateMapObjectDrawList1(CreateCream, DrawCream, NULL);
}

void CreateBerryDrawList(void) {
    CreateMapObjectDrawList1(CreateBerry, DrawBerry, NULL);
}

void CreateBoundUpdateList(void) {
    CreateMapObjectUpdateList(InitBoundAndCreamAndBerryObjects, UpdateBoundAndCreamAndBerry, NULL);
}

// Starts the wobble of object a of the 0x1a8 list, with a sound unless the object is far; FALSE if already wobbling.
BOOL StartBoundWobble(s32 a) {
    Bound *p;
    Unk0210b7a8 s;
    s32 k;

    p = GetMapObjectFromList(func_02100138(MAP_OBJECT_KIND_BOUND), a);
    if (p->mWobbling == FALSE) {
        p->mWobbleXAngle = 0x8000;
        p->mWobbleXMid = 0x1000;
        p->mWobbleXAmplitude = 0x400;
        p->mWobbleXAmplitudePerFrame = -0x29;
        p->mWobbleXAnglePerFrame = 0x1000;
        p->mUnk_0d4 = 0;
        p->mWobbleYAngle = 0;
        p->mWobbleYMid = 0x1000;
        p->mWobbleYAmplitude = 0x400;
        p->mWobbleYAmplitudePerFrame = -0x29;
        p->mWobbleYAnglePerFrame = 0x1000;
        p->mUnk_0f4 = 0;
        p->mWobbling = TRUE;
        if ((p->mUnk_000.mDistanceSquaredAndFlags & 4) == 0) {
            if (p->mUnk_000.mFarDistanceSquared == gSoundFalloffs[2].mUnk_20) {
                k = 2;
            } else if (p->mUnk_000.mFarDistanceSquared == gSoundFalloffs[3].mUnk_20) {
                k = 3;
            } else {
                k = 4;
            }
            s.mUnk_00 = 0x1cf;
            s.mUnk_04 = &p->mUnk_000.mPos;
            s.mUnk_08 = k;
            s.mUnk_0c = GetHorizontalCameraDistanceSquared(&p->mUnk_000.mPos);
            func_0210b7a8(&s);
        }
        return TRUE;
    }
    return FALSE;
}

#pragma thumb on

void *CreateMapObjectKindData(void *param_1, void *param_2, void *param_3, u32 param_4, u16 param_5) {
    Unk0209bf70 *o;

    GetHeap(GetCurrentHeapCall());
    o = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x40);
    o->mUnk_00 = param_1;
    o->mUnk_04 = param_2;
    o->mUnk_20 = param_4;
    o->mUnk_1c = param_5;
    o->mUnk_18 = param_3;
    return o;
}

u32 CreateEmptyMapObjectKindData(void) {
    return (u32) CreateMapObjectKindData(NULL, NULL, NULL, 0, 1);
}

Unk0209bf70 *func_0209bf70(void *a, void *b, void *c, u32 d, u16 e, u16 f) {
    Unk0209bf70 *o;

    o = CreateMapObjectKindData(a, b, c, d, e);
    o->mUnk_24 = f;
    return o;
}
