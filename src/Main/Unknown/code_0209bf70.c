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

void InitSun(u32 sun) {
    u32 value0 = sun;
    u32 value1;
    u32 value2;
    u32 sunObject;
    sunObject = value0;
    value1 = *(const u32 *) ((sunObject) + (156));
    value0 = (sunObject) + (0xb8u);
    value2 = 0u;
    InitGroupFollower((GroupFollower *) value0, (CourseMapRow *) value1, value2);
    value0 = 0x1aeu;
    value2 = sunObject;
    value1 = 0x1eu;
    CreateParkedMapObjects(value0, value1, (void *) value2);
    value0 = 0u;
    *(u32 *) ((sunObject) + (16)) = value0;
    *(u32 *) ((sunObject) + (20)) = value0;
    *(u32 *) ((sunObject) + (24)) = value0;
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

static inline u32 CollideKartWithBound_inline(RandomState64 *randomState64) {
    randomState64->mValue = randomState64->mMultiplier * randomState64->mValue + randomState64->mIncrement;
    return randomState64->mValue >> 32;
}

void InitSunObjects(MapObjectList *mapObjectList) {
    s32 i;
    Sun *sun;

    if (mapObjectList == NULL) {
        return;
    }
    for (i = 0; i < mapObjectList->mMapObjectCount && (sun = mapObjectList->mMapObjects[i]) != NULL; i++) {
        if (gRaceSetup->mMode == MODE_TIME_ATTACK) {
            sun->mTimer = (u16) sun->mUnk_000.mCourseMapRow->mUnk_28;
        } else if (gRaceSetup->mMode == 5) {
            sun->mTimer = (u16) sun->mUnk_000.mCourseMapRow->mUnk_2a;
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

static inline BOOL UpdateSun_inline_b(Sun *sun) {
    s32 i;
    Kart *kart;
    Vec3 *q;
    s32 x;
    s32 z;

    for (i = 0; i < gRaceSetup->mKartCount; i++) {
        kart = GetKart((u16) i);
        q = &kart->mPos;
        x = q->x - sun->mUnk_000.mPos.x;
        z = q->z - sun->mUnk_000.mPos.z;
        if ((s64) x * x + (s64) z * z < 0x15f900000000LL) {
            return TRUE;
        }
    }
    return FALSE;
}

void UpdateSun(MapObjectList *mapObjectList, Sun *sun) {
    Vec3 position;
    Vec3 direction;
    s32 t;
    s32 k;

    switch (sun->mState) {
        case 0:
            if (sun->mUnk_000.mFlags & 0x800) {
                if (sun->mTimer-- <= 0) {
                    sun->mState = 1;
                }
            } else if (UpdateSun_inline()) {
                sun->mState = 1;
            }
            break;
        case 1:
            sun->mUnk_0b8.mSpeed = 0x3c000;
            sun->mUnk_0b8.mProgressStep =
                ((s64) sun->mUnk_0b8.mPath->mSegments[sun->mUnk_0b8.mSegmentIndex].mInverseProgressLength * 0x3c000) >>
                12;
            if (AdvanceGroupFollower(&sun->mUnk_0b8) != FALSE && (t = sun->mUnk_0b8.mFromEntry->mUnk_0e) != 0) {
                if (sun->mUnk_000.mFlags & 0x800) {
                    k = gRaceSetup->mMode;
                    if (k == MODE_TIME_ATTACK) {
                        sun->mTimer = t;
                    } else if (k == 5) {
                        sun->mTimer = sun->mUnk_0b8.mFromEntry->mUnk_10;
                    }
                }
                sun->mState = 2;
            }
            GetGroupFollowerLinearPosition(&sun->mUnk_0b8, &sun->mUnk_000.mPos);
            break;
        case 2:
            if (sun->mUnk_000.mFlags & 0x800) {
                if (sun->mTimer-- <= 0) {
                    sun->mUnk_0b0 = 0;
                    sun->mUnk_0ac = sun->mUnk_0b0;
                    sun->mTimer = 5;
                    sun->mState = 3;
                }
            } else if (UpdateSun_inline_b(sun)) {
                sun->mUnk_0b0 = 0;
                sun->mUnk_0ac = sun->mUnk_0b0;
                sun->mTimer = 5;
                sun->mState = 3;
            }
            break;
        case 3:
            sun->mUnk_0b0 += 0xe39;
            if (sun->mUnk_0ac < 0x8000) {
                sun->mUnk_0ac += 0x222;
            }
            if (sun->mTimer-- > 0) {
                break;
            }
            if (sun->mUnk_0a0 == 0) {
                sun->mUnk_0a4 = ((u64) CollideKartWithBound_inline(GetMapObjectRandom()) * 0x10000) >> 32;
            } else {
                sun->mUnk_0a4 += 0x8000;
            }
            position.x = sun->mUnk_000.mPos.x;
            position.y = sun->mUnk_000.mPos.y - 0x1e000;
            position.z = sun->mUnk_000.mPos.z;
            direction.x = gPairsByAngle[(sun->mUnk_0a4 >> 4) * 2];
            direction.y = 0;
            direction.z = gPairsByAngle[(sun->mUnk_0a4 >> 4) * 2 + 1];
            func_0209d694(&position, &direction);
            sun->mUnk_0a0 += 1;
            if (sun->mUnk_0a0 >= 2) {
                sun->mUnk_0a0 = 0;
                sun->mState = 4;
            } else {
                sun->mTimer = 0x1e;
            }
            break;
        case 4:
            sun->mUnk_0b0 += 0xe39;
            sun->mUnk_0ac += 0x222;
            if (sun->mUnk_0ac > 0x10000) {
                sun->mTimer = 0x1e;
                sun->mState = 0;
            }
            break;
    }
    if ((s32) (sun->mUnk_000.mDistanceSquaredAndFlags & ~0xc000001f) >= 0x3d0900) {
        return;
    }
    if (sun->mState == 3) {
        t = sun->mNsbcaFrameIndexPerFrame + 0x19a;
        if (t >= 0x8000) {
            t = 0x8000;
        }
        sun->mNsbcaFrameIndexPerFrame = t;
    } else {
        t = sun->mNsbcaFrameIndexPerFrame - 0x19a;
        if (t <= 0x1000) {
            t = 0x1000;
        }
        sun->mNsbcaFrameIndexPerFrame = t;
    }
    sun->mNsbcaFrameIndex += sun->mNsbcaFrameIndexPerFrame >> 12;
    if (sun->mNsbcaFrameIndex >= GetMapObjectModelNsbcaFrameCount(gSun)) {
        sun->mNsbcaFrameIndex = 0;
    }
}

void CreateSunDrawList(void) {
    CreateMapObjectDrawList1(CreateSunAndSunLOD, DrawSun, func_0209d5e8);
}

void CreateSunUpdateList(void) {
    CreateMapObjectUpdateList(InitSunObjects, UpdateSun, NULL);
}

void InitBound(Bound *bound) {
    bound->mUnk_000.mFlags |= data_usa_021565d4;
    RefreshMapObjectMatrixFromHitNormal(bound);
    bound->mInitialScaleX = bound->mUnk_000.mScale.x;
}

// Shared by Bound, Cream and Berry: sets the object's motion from the Kart, starts the wobble and plays a sound.
s32 CollideKartWithBound(Bound *bound, Kart *kart, u8 *b, u8 *c) {
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
        if (bound->mKartTimers[kart->mIndex] == 0) {
            VEC_Subtract(&kart->mPos, &bound->mUnk_000.mPos, &v2);
            t = VEC_DotProduct(&kart->mVelocityDirection, &v2);
            v0.x = ((s64) kart->mVelocityDirection.x * t) >> 12;
            v0.y = ((s64) kart->mVelocityDirection.y * t) >> 12;
            v0.z = ((s64) kart->mVelocityDirection.z * t) >> 12;
            v1.x = v2.x - v0.x;
            v1.y = v2.y - v0.y;
            v1.z = v2.z - v0.z;
            t = VEC_DotProduct(&bound->mUnk_000.mMatrix.mUnk_00[1], &v1);
            v0.x = ((s64) bound->mUnk_000.mMatrix.mUnk_00[1].x * t) >> 12;
            v0.y = ((s64) bound->mUnk_000.mMatrix.mUnk_00[1].y * t) >> 12;
            v0.z = ((s64) bound->mUnk_000.mMatrix.mUnk_00[1].z * t) >> 12;
            v1.x -= v0.x;
            v1.y -= v0.y;
            v1.z -= v0.z;
            if ((s64) v1.x * v1.x + (s64) v1.y * v1.y + (s64) v1.z * v1.z < 0x10) {
                q = &kart->mUnk_120;
                bound->mUnk_000.mUnk_10.x = ((s64) kart->mUnk_120.x * 0xc000) >> 12;
                bound->mUnk_000.mUnk_10.y = ((s64) q->y * 0xc000) >> 12;
                bound->mUnk_000.mUnk_10.z = ((s64) q->z * 0xc000) >> 12;
            } else {
                Vec3NormalizeAndGetLengthUnchecked(&v1, &v1);
                bound->mUnk_000.mUnk_10.x = ((s64) v1.x * 0xc000) >> 12;
                bound->mUnk_000.mUnk_10.y = ((s64) v1.y * 0xc000) >> 12;
                bound->mUnk_000.mUnk_10.z = ((s64) v1.z * 0xc000) >> 12;
            }
            VEC_Subtract(&v0, &bound->mUnk_000.mMatrix.mUnk_00[1], &v0);
            VEC_MultAdd(0x19a, &v0, &bound->mUnk_000.mUnk_10, &bound->mUnk_000.mUnk_10);
            bound->mKartTimers[kart->mIndex] = 0x1f;
            if (gRaceSetup->mMode == MODE_BATTLE) {
                CallStandingsKartOffsetCallback(kart->mIndex, (s32) &bound->mUnk_000.mUnk_10);
            }
        } else {
            bound->mUnk_000.mUnk_10.x = 0;
            bound->mUnk_000.mUnk_10.y = 0;
            bound->mUnk_000.mUnk_10.z = 0;
        }
        if (gRaceSetup->mCurrentEntries[kart->mIndex].mPlayer.mKind != PLAYER_KIND_GHOST && bound->mWobbling == FALSE) {
            bound->mWobbleXAngle = 0x8000;
            bound->mWobbleXMid = 0x1000;
            bound->mWobbleXAmplitude = 0x400;
            bound->mWobbleXAmplitudePerFrame = -0x29;
            bound->mWobbleXAnglePerFrame = 0x1000;
            bound->mUnk_0d4 = 0;
            bound->mWobbleYAngle = 0;
            bound->mWobbleYMid = 0x1000;
            bound->mWobbleYAmplitude = 0x400;
            bound->mWobbleYAmplitudePerFrame = -0x29;
            bound->mWobbleYAnglePerFrame = 0x1000;
            bound->mUnk_0f4 = 0;
            bound->mWobbling = TRUE;
            switch (bound->mUnk_000.mKind) {
                case MAP_OBJECT_KIND_CREAM:
                    func_020d26ec(kart, 0x156);
                    break;
                case MAP_OBJECT_KIND_BERRY:
                    func_020d26ec(kart, 0x155);
                    break;
                case 0x1a8:
                    func_020d26ec(kart, 0x1cf);
                    break;
            }
            if ((u16) (bound->mUnk_000.mKind + 0xfe4c) <= 1) {
                StartOrthoQuadsCreamEffect(
                    kart->mIndex,
                    (u16) (((u64) CollideKartWithBound_inline(&gRaceProgress->mLocalRandom) * 3) >> 32) + 1);
                VEC_Subtract(&bound->mUnk_000.mPos, &kart->mCollisionCenter, &v3);
                if (!((s64) v3.x * v3.x + (s64) v3.y * v3.y + (s64) v3.z * v3.z < 0x10)) {
                    Vec3NormalizeAndGetLengthUnchecked(&v3, &v3);
                }
                VEC_MultAdd(kart->mRadius, &v3, &kart->mCollisionCenter, &v3);
                if (kart->mIndex == gRaceSetup->mEntryIndex) {
                    StartEffect(0x74, &v3);
                } else {
                    StartEffect(0x75, &v3);
                }
            }
        }
        return d;
    }
    bound->mUnk_000.mUnk_10.x = 0;
    bound->mUnk_000.mUnk_10.y = 0;
    bound->mUnk_000.mUnk_10.z = 0;
    return 2;
}

// Shared by Bound, Cream and Berry: when *b is 2, starts a smaller wobble; returns *c.
u8 CollideItemObjectWithBound(Bound *bound, void *a, u8 *b, u8 *c) {
    u32 d;

    d = *c;
    if (*b == 2 && bound->mWobbling == FALSE) {
        bound->mWobbleXAngle = 0x8000;
        bound->mWobbleXMid = 0x1000;
        bound->mWobbleXAmplitude = 0x200;
        bound->mWobbleXAmplitudePerFrame = -0x14;
        bound->mWobbleXAnglePerFrame = 0x1000;
        bound->mUnk_0d4 = 0;
        bound->mWobbleYAngle = 0;
        bound->mWobbleYMid = 0x1000;
        bound->mWobbleYAmplitude = 0x200;
        bound->mWobbleYAmplitudePerFrame = -0x14;
        bound->mWobbleYAnglePerFrame = 0x1000;
        bound->mUnk_0f4 = 0;
        bound->mWobbling = TRUE;
        bound->mUnk_000.mDistanceSquaredAndFlags |= data_usa_021565d0;
    }
    return d;
}

BOOL ComputeSphereHitOnBound(Bound *bound, Vec3 *sphereCenter, s32 sphereRadius, Vec3 *pushOut) {
    if ((bound->mUnk_000.mFlags & 0x800) == 0 && bound->mWobbling == TRUE) {
        bound->mSphereHit =
            ComputeSphereHitOnRotatedCylinder(sphereCenter, &bound->mUnk_000.mPos, &bound->mUnk_000.mMatrix.mUnk_00[0],
                                              ((s64) bound->mUnk_000.mExtent.x * bound->mWobbleScaleX) >> 12,
                                              bound->mUnk_000.mExtent.y, 0, sphereRadius, pushOut);
    } else {
        bound->mSphereHit = ComputeSphereHitOnRotatedCylinder(
            sphereCenter, &bound->mUnk_000.mPos, &bound->mUnk_000.mMatrix.mUnk_00[0], bound->mUnk_000.mExtent.x,
            bound->mUnk_000.mExtent.y, 0, sphereRadius, pushOut);
    }
    return bound->mSphereHit != 0;
}

void CreateBound(void *a) {
    gBound = CreateMapObjectModelAnimated(a, gBoundNsbmdName);
    CreateMapObjectModelNsbtpAnimation(gBound, gBoundNsbtpName);
}

void DrawBound(MapObjectList *mapObjectList, Bound *bound) {
    s32 v[4];
    s32 x;
    s32 y;

    v[0] = 0x1e;
    func_01ff9048(0x14, &v[0], 1);
    bound->mUnk_000.mMatrix.mUnk_00[3].x = bound->mUnk_000.mPos.x >> 4;
    bound->mUnk_000.mMatrix.mUnk_00[3].y = bound->mUnk_000.mPos.y >> 4;
    bound->mUnk_000.mMatrix.mUnk_00[3].z = bound->mUnk_000.mPos.z >> 4;
    func_01ff9048(0x19, &bound->mUnk_000.mMatrix, 0xc);
    if (bound->mWobbling == TRUE) {
        x = bound->mWobbleScaleX;
        y = bound->mWobbleScaleY;
        v[1] = x;
        v[2] = y;
        v[3] = x;
        func_01ff9048(0x1b, &v[1], 3);
    }
    func_01ff9048(0x1b, &bound->mUnk_000.mScale, 3);
    SetMapObjectModelNsbtpFrameIndex(gBound, bound->mNsbtpFrameIndex);
    DrawMapObjectModel(mapObjectList, gBound, bound);
}

void CreateCream(void *a) {
    gCream = CreateMapObjectModelAnimated(a, gCreamNsbmdName);
    CreateOrthoQuadCreamEffect(data_usa_02167328);
}

void CreateBerry(void *a) {
    gBerry = CreateMapObjectModelAnimated(a, gBerryNsbmdName);
    CreateOrthoQuadCreamEffect(gCreamEffectNsbmdName);
}

void DrawCream(MapObjectList *mapObjectList, Bound *bound) {
    s32 v[4];
    s32 x;
    s32 y;

    v[0] = 0x1e;
    func_01ff9048(0x14, &v[0], 1);
    bound->mUnk_000.mMatrix.mUnk_00[3].x = bound->mUnk_000.mPos.x >> 4;
    bound->mUnk_000.mMatrix.mUnk_00[3].y = bound->mUnk_000.mPos.y >> 4;
    bound->mUnk_000.mMatrix.mUnk_00[3].z = bound->mUnk_000.mPos.z >> 4;
    func_01ff9048(0x19, &bound->mUnk_000.mMatrix, 0xc);
    if (bound->mWobbling == TRUE) {
        x = bound->mWobbleScaleX;
        y = bound->mWobbleScaleY;
        v[1] = x;
        v[2] = y;
        v[3] = x;
        func_01ff9048(0x1b, &v[1], 3);
    }
    func_01ff9048(0x1b, &bound->mUnk_000.mScale, 3);
    DrawMapObjectModel(mapObjectList, gCream, bound);
}

void DrawBerry(MapObjectList *mapObjectList, Bound *bound) {
    s32 v[4];
    s32 x;
    s32 y;

    v[0] = 0x1e;
    func_01ff9048(0x14, &v[0], 1);
    bound->mUnk_000.mMatrix.mUnk_00[3].x = bound->mUnk_000.mPos.x >> 4;
    bound->mUnk_000.mMatrix.mUnk_00[3].y = bound->mUnk_000.mPos.y >> 4;
    bound->mUnk_000.mMatrix.mUnk_00[3].z = bound->mUnk_000.mPos.z >> 4;
    func_01ff9048(0x19, &bound->mUnk_000.mMatrix, 0xc);
    if (bound->mWobbling == TRUE) {
        x = bound->mWobbleScaleX;
        y = bound->mWobbleScaleY;
        v[1] = x;
        v[2] = y;
        v[3] = x;
        func_01ff9048(0x1b, &v[1], 3);
    }
    func_01ff9048(0x1b, &bound->mUnk_000.mScale, 3);
    DrawMapObjectModel(mapObjectList, gBerry, bound);
}

void InitBoundAndCreamAndBerryObjects(MapObjectList *mapObjectList) {
    s32 i;
    Bound *bound;

    if (mapObjectList == NULL) {
        return;
    }
    for (i = 0; i < mapObjectList->mMapObjectCount && (bound = mapObjectList->mMapObjects[i]) != NULL; i++) {
        if (bound->mUnk_000.mCourseMapRow->mUnk_26 >= 0) {
            InitGroupFollower(&bound->mUnk_0f8, bound->mUnk_000.mCourseMapRow, 0);
            bound->mUnk_0f8.mSpeed = 0x3000;
            bound->mUnk_0f8.mProgressStep =
                ((s64) bound->mUnk_0f8.mPath->mSegments[bound->mUnk_0f8.mSegmentIndex].mInverseProgressLength *
                 0x3000) >>
                12;
        } else {
            bound->mUnk_0f8.mGroupIndex = 0xffff;
        }
    }
}

s16 func_0209c4d8(s32 a) {
    return gPairsByAngle[(a >> 4) * 2];
}

s32 func_0209c4bc(s32 a, s32 b) {
    return ((s64) a * b + 0x800) >> 12;
}

void UpdateBoundAndCreamAndBerry(MapObjectList *mapObjectList, Bound *bound) {
    u16 nsbtpFrameCount;
    s32 t;
    s32 i;
    s32 kartCount;

    if (bound->mUnk_0f8.mGroupIndex != 0xffff) {
        AdvanceGroupFollower(&bound->mUnk_0f8);
        GetGroupFollowerCurvePosStep(&bound->mUnk_0f8, &bound->mUnk_000.mPos, &bound->mUnk_000.mUnk_10);
        nsbtpFrameCount = GetMapObjectModelNsbtpFrameCount(gBound);
        bound->mNsbtpFrameIndex += 1;
        if (bound->mNsbtpFrameIndex >= nsbtpFrameCount) {
            bound->mNsbtpFrameIndex = 1;
        }
    } else {
        bound->mUnk_000.mUnk_10.x = 0;
        bound->mUnk_000.mUnk_10.y = 0;
        bound->mUnk_000.mUnk_10.z = 0;
        bound->mNsbtpFrameIndex = 0;
    }
    if (bound->mWobbling == TRUE) {
        bound->mWobbleXAngle += bound->mWobbleXAnglePerFrame;
        t = func_0209c4bc(bound->mWobbleXAmplitude, func_0209c4d8(bound->mWobbleXAngle));
        bound->mUnk_0c0 = bound->mWobbleXMid + t - bound->mWobbleScaleX;
        bound->mWobbleScaleX += bound->mUnk_0c0;
        if (bound->mWobbleXAmplitude > 0) {
            t = bound->mWobbleXAmplitude + bound->mWobbleXAmplitudePerFrame;
            if (t <= 0) {
                t = 0;
            }
            bound->mWobbleXAmplitude = t;
        } else if (bound->mWobbleXAmplitude < 0) {
            t = bound->mWobbleXAmplitude + bound->mWobbleXAmplitudePerFrame;
            if (t >= 0) {
                t = 0;
            }
            bound->mWobbleXAmplitude = t;
        }
        if (bound->mWobbleXAnglePerFrame > 0) {
            t = bound->mWobbleXAnglePerFrame + bound->mUnk_0d4;
            if (t <= 0) {
                t = 0;
            }
            bound->mWobbleXAnglePerFrame = t;
        } else if (bound->mWobbleXAnglePerFrame < 0) {
            t = bound->mWobbleXAnglePerFrame + bound->mUnk_0d4;
            if (t >= 0) {
                t = 0;
            }
            bound->mWobbleXAnglePerFrame = t;
        }
        bound->mWobbleYAngle += bound->mWobbleYAnglePerFrame;
        t = func_0209c4bc(bound->mWobbleYAmplitude, func_0209c4d8(bound->mWobbleYAngle));
        bound->mUnk_0e0 = bound->mWobbleYMid + t - bound->mWobbleScaleY;
        bound->mWobbleScaleY += bound->mUnk_0e0;
        if (bound->mWobbleYAmplitude > 0) {
            t = bound->mWobbleYAmplitude + bound->mWobbleYAmplitudePerFrame;
            if (t <= 0) {
                t = 0;
            }
            bound->mWobbleYAmplitude = t;
        } else if (bound->mWobbleYAmplitude < 0) {
            t = bound->mWobbleYAmplitude + bound->mWobbleYAmplitudePerFrame;
            if (t >= 0) {
                t = 0;
            }
            bound->mWobbleYAmplitude = t;
        }
        if (bound->mWobbleYAnglePerFrame > 0) {
            t = bound->mWobbleYAnglePerFrame + bound->mUnk_0f4;
            if (t <= 0) {
                t = 0;
            }
            bound->mWobbleYAnglePerFrame = t;
        } else if (bound->mWobbleYAnglePerFrame < 0) {
            t = bound->mWobbleYAnglePerFrame + bound->mUnk_0f4;
            if (t >= 0) {
                t = 0;
            }
            bound->mWobbleYAnglePerFrame = t;
        }
        if (bound->mWobbleXAmplitude == 0 && bound->mWobbleYAmplitude == 0) {
            bound->mWobbling = FALSE;
            bound->mUnk_000.mScale.x = bound->mInitialScaleX;
        } else {
            bound->mUnk_000.mScale.x = ((s64) bound->mInitialScaleX * bound->mWobbleScaleX) >> 12;
        }
    } else {
        bound->mUnk_000.mScale.x = bound->mInitialScaleX;
    }
    kartCount = gRaceSetup->mKartCount;
    for (i = 0; i < kartCount; i++) {
        if (bound->mKartTimers[i] > 0) {
            bound->mKartTimers[i] -= 1;
        }
    }
}

void CreateBoundKindData(void) {
    Unk0209bf70 *kindData;

    kindData = CreateMapObjectKindData(CollideKartWithBound, CollideItemObjectWithBound, ComputeSphereHitOnBound, 1, 1);
    kindData->mUnk_28 = 0x1cf;
}

void CreateCreamKindData(void) {
    Unk0209bf70 *kindData;

    kindData = CreateMapObjectKindData(CollideKartWithBound, CollideItemObjectWithBound, ComputeSphereHitOnBound, 1, 1);
    kindData->mUnk_28 = 0x156;
}

void CreateBerryKindData(void) {
    Unk0209bf70 *kindData;

    kindData = CreateMapObjectKindData(CollideKartWithBound, CollideItemObjectWithBound, ComputeSphereHitOnBound, 1, 1);
    kindData->mUnk_28 = 0x155;
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
    Bound *bound;
    Unk0210b7a8 s;
    s32 k;

    bound = GetMapObjectFromList(func_02100138(MAP_OBJECT_KIND_BOUND), a);
    if (bound->mWobbling == FALSE) {
        bound->mWobbleXAngle = 0x8000;
        bound->mWobbleXMid = 0x1000;
        bound->mWobbleXAmplitude = 0x400;
        bound->mWobbleXAmplitudePerFrame = -0x29;
        bound->mWobbleXAnglePerFrame = 0x1000;
        bound->mUnk_0d4 = 0;
        bound->mWobbleYAngle = 0;
        bound->mWobbleYMid = 0x1000;
        bound->mWobbleYAmplitude = 0x400;
        bound->mWobbleYAmplitudePerFrame = -0x29;
        bound->mWobbleYAnglePerFrame = 0x1000;
        bound->mUnk_0f4 = 0;
        bound->mWobbling = TRUE;
        if ((bound->mUnk_000.mDistanceSquaredAndFlags & 4) == 0) {
            if (bound->mUnk_000.mFarDistanceSquared == gSoundFalloffs[2].mUnk_20) {
                k = 2;
            } else if (bound->mUnk_000.mFarDistanceSquared == gSoundFalloffs[3].mUnk_20) {
                k = 3;
            } else {
                k = 4;
            }
            s.mSoundId = 0x1cf;
            s.mPositionSource = &bound->mUnk_000.mPos;
            s.mUnk_08 = k;
            s.mDistanceSquared = GetHorizontalCameraDistanceSquared(&bound->mUnk_000.mPos);
            func_0210b7a8(&s);
        }
        return TRUE;
    }
    return FALSE;
}

#pragma thumb on

void *CreateMapObjectKindData(void *collideKartCallback, void *collideItemObjectCallback, void *sphereHitCallback,
                              u32 param_4, u16 param_5) {
    Unk0209bf70 *kindData;

    GetHeap(GetCurrentHeapCall());
    kindData = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x40);
    kindData->mUnk_00 = collideKartCallback;
    kindData->mUnk_04 = collideItemObjectCallback;
    kindData->mUnk_20 = param_4;
    kindData->mUnk_1c = param_5;
    kindData->mUnk_18 = sphereHitCallback;
    return kindData;
}

u32 CreateEmptyMapObjectKindData(void) {
    return (u32) CreateMapObjectKindData(NULL, NULL, NULL, 0, 1);
}

Unk0209bf70 *func_0209bf70(void *collideKartCallback, void *collideItemObjectCallback, void *sphereHitCallback, u32 d,
                           u16 e, u16 f) {
    Unk0209bf70 *kindData;

    kindData = CreateMapObjectKindData(collideKartCallback, collideItemObjectCallback, sphereHitCallback, d, e);
    kindData->mUnk_24 = f;
    return kindData;
}
