#include "Main/Unknown/code_0209a748.h"
#include "code_02146d78.h"

#include "Main/Unknown/code_0209b634.h"
#include "Main/Unknown/code_0209bef0.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_02042044.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_0209bf70.h"
#include "Main/Unknown/code_020f36d8.h" // ItemObject
#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/code_020d8654.h"
#include "Main/Unknown/code_020d88fc.h"
#include "Main/Unknown/code_020d8918.h"
#include "Main/Unknown/code_020d8cac.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020e6b58.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "code_02146cbc.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/code_020d26f8.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_020f8ddc.h"
#include "Main/Unknown/unk_02156000.h"
#include "Main/Unknown/code_020d7da8.h"
#include "Main/Unknown/code_02077bc0.h"

void InitCrab(u32 crab) {
    u32 value0 = crab;
    u32 courseMapRow;
    u32 speed;
    u32 value12;
    courseMapRow = *(const u32 *) ((value0) + (156));
    value0 = (value0) + (0xf0u);
    speed = 0u;
    InitGroupFollower((GroupFollower *) value0, (CourseMapRow *) courseMapRow, speed);
}

static inline u32 func_0209b388_inline(RandomState64 *random, u32 limit) {
    random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
    if (limit == 0) {
        return random->mValue >> 32;
    } else {
        return ((random->mValue >> 32) * limit) >> 32;
    }
}

void StartCrabLaunch(Crab *crab, Vec3 *sourcePosition, Vec3 *sourceDirection, Vec3 *sourceVelocity) {
    Vec3 v;
    RandomState64 *mapObjectRandom;
    s32 x;
    s32 z;

    if (sourcePosition != NULL && sourceDirection != NULL) {
        VEC_Subtract(&crab->mUnk_000.mPos, sourcePosition, &v);
        z = sourceDirection->z;
        x = sourceDirection->x;
        if ((s64) v.z * x - (s64) v.x * z < 0) {
            v.z = -x;
            v.x = z;
            v.y = 0;
            crab->mRotateZAnglePerFrame = 0x71c;
        } else {
            v.z = x;
            v.x = -z;
            v.y = 0;
            crab->mRotateZAnglePerFrame = 0xf8e4;
        }
        crab->mUnk_000.mUnk_10.x = ((s64) v.x * 0x1800) >> 12;
        crab->mUnk_000.mUnk_10.y = ((s64) v.y * 0x1800) >> 12;
        crab->mUnk_000.mUnk_10.z = ((s64) v.z * 0x1800) >> 12;
    } else {
        mapObjectRandom = GetMapObjectRandom();
        z = (u16) func_0209b388_inline(mapObjectRandom, 0x10000);
        x = gPairsByAngle[((u16) z >> 4) * 2 + 1];
        x = ((s64) x * 0x1800) >> 12;
        crab->mUnk_000.mUnk_10.x = x;
        crab->mUnk_000.mUnk_10.z = x;
        mapObjectRandom = GetMapObjectRandom();
        if ((u16) func_0209b388_inline(mapObjectRandom, 2) != 0) {
            crab->mRotateZAnglePerFrame = 0x71c;
        } else {
            crab->mRotateZAnglePerFrame = 0xf8e4;
        }
    }
    if (sourceVelocity != NULL) {
        crab->mUnk_000.mUnk_10.x += sourceVelocity->x / 2;
        crab->mUnk_000.mUnk_10.z += sourceVelocity->z / 2;
    }
    crab->mUnk_000.mUnk_10.y = 0x4000;
    crab->mTimer = 0x12c;
    crab->mState = 2;
    crab->mUnk_000.mFlags |= data_usa_0215659c;
}

u8 CollideKartWithCrab(Crab *crab, Kart *kart, u8 *c, u8 *d) {
    u32 result;

    result = *d;
    if (*c == 1) {
        StartCrabLaunch(crab, &kart->mPos, &kart->mEasedTurnedForward, &kart->mVelocity);
        StartSoundIfKartStarOrKiller(&crab->mUnk_000, kart);
    }
    return result;
}

u8 CollideItemObjectWithCrab(Crab *crab, ItemObject *itemObject, u8 *c, u8 *d) {
    Vec3 direction;
    Kart *entryKart;
    u32 result;

    result = *d;
    if (*c == 1) {
        if (itemObject != NULL) {
            if ((s64) itemObject->mVelocity.x * itemObject->mVelocity.x +
                    (s64) itemObject->mVelocity.y * itemObject->mVelocity.y +
                    (s64) itemObject->mVelocity.z * itemObject->mVelocity.z >=
                0x10) {
                Vec3NormalizeAndGetLengthUnchecked(&itemObject->mVelocity, &direction);
                StartCrabLaunch(crab, &itemObject->mPos, &direction, NULL);
            } else {
                StartCrabLaunch(crab, NULL, NULL, NULL);
            }
            func_020f8ddc(itemObject);
        } else {
            entryKart = GetKart((u16) gRaceSetup->mEntryIndex);
            StartCrabLaunch(crab, &entryKart->mPos, &entryKart->mEasedTurnedForward, &entryKart->mVelocity);
        }
    }
    return result;
}

void CreateCrabAndCrabHand(void *a) {
    gCrab = CreateMapObjectModelNsbmdNsbtp(a, "crab.nsbmd", "crab.nsbtp");
    gCrabHand = CreateMapObjectModelNsbmdNsbtp(a, "crab_hand.nsbmd", "crab_hand.nsbtp");
    SetMapObjectModelPolygonId(gCrab, 0x3f);
    SetMapObjectModelPolygonId(gCrabHand, 0x3f);
}

u32 func_0209b1f8(u32 p0) {
    return p0;
}

void DrawCrab(void *a, Crab *crab) {
    s32 w;
    s32 crabRotation[9];
    s32 handRotation[9];

    w = 0x1e;
    func_01ff9048(0x14, &w, 1);
    func_020e6d88(&crab->mUnk_000.mMatrix.mUnk_00[1]);
    func_01ff9048(0x19, func_020e6bd0(&crab->mUnk_000.mPos), 0xc);
    if (crab->mRotateZAngle != 0) {
        MTX_RotZ33_(crabRotation, gPairsByAngle[(crab->mRotateZAngle >> 4) * 2],
                    gPairsByAngle[(crab->mRotateZAngle >> 4) * 2 + 1]);
        func_01ff9048(0x1a, crabRotation, 9);
    }
    func_01ff9048(0x1b, &crab->mUnk_000.mScale, 3);
    SetMapObjectModelNsbtpFrameIndex(gCrab, crab->mCrabNsbtpFrameIndexFixed12 >> 12);
    func_0209bbd0(a, gCrab);
    DrawMapObjectModel(a, gCrab, crab);
    MTX_RotZ33_(handRotation, gPairsByAngle[((u16) crab->mHandWobble.mValue >> 4) * 2],
                gPairsByAngle[((u16) crab->mHandWobble.mValue >> 4) * 2 + 1]);
    func_01ff9048(0x1a, handRotation, 9);
    SetMapObjectModelNsbtpFrameIndex(gCrabHand, crab->mHandNsbtpFrameIndexFixed12 >> 12);
    func_0209bbd0(a, gCrabHand);
    DrawMapObjectModel(a, gCrabHand, crab);
}

void InitCrabObjects(Unk0209af98 *mapObjectList) {
    s32 i;
    Crab *crab;
    RandomState64 *mapObjectRandom;

    if (mapObjectList == NULL) {
        return;
    }
    for (i = 0; i < mapObjectList->mMapObjectCount && (crab = mapObjectList->mMapObjects[i]) != NULL; i++) {
        crab->mHandWobble.mAngle = 0;
        crab->mHandWobble.mMid = 0;
        crab->mHandWobble.mAmplitude = 0x1c7;
        crab->mHandWobble.mAmplitudePerFrame = 0;
        crab->mHandWobble.mAnglePerFrame = 0xe39;
        crab->mHandWobble.mUnk_1c = 0;
        mapObjectRandom = GetMapObjectRandom();
        mapObjectRandom->mValue = mapObjectRandom->mMultiplier * mapObjectRandom->mValue + mapObjectRandom->mIncrement;
        crab->mTimer = (u16) ((u16) (((u64) (u32) (mapObjectRandom->mValue >> 32) * 60) >> 32) + 30);
        crab->mState = 0;
    }
}

s16 func_0209af80(s32 a) {
    return gPairsByAngle[(a >> 4) * 2];
}

s32 func_0209af64(s32 a, s32 b) {
    return ((s64) a * b + 0x800) >> 12;
}

static inline void func_0209a7dc_inline(TeresaWobble *wobble) {
    s32 t;

    wobble->mAngle += wobble->mAnglePerFrame;
    wobble->mUnk_08 = wobble->mMid + func_0209af64(wobble->mAmplitude, func_0209af80(wobble->mAngle)) - wobble->mValue;
    wobble->mValue += wobble->mUnk_08;
    if (wobble->mAmplitude > 0) {
        t = wobble->mAmplitude + wobble->mAmplitudePerFrame;
        if (t <= 0) {
            t = 0;
        }
        wobble->mAmplitude = t;
    } else if (wobble->mAmplitude < 0) {
        t = wobble->mAmplitude + wobble->mAmplitudePerFrame;
        if (t >= 0) {
            t = 0;
        }
        wobble->mAmplitude = t;
    }
    if (wobble->mAnglePerFrame > 0) {
        t = wobble->mAnglePerFrame + wobble->mUnk_1c;
        if (t <= 0) {
            t = 0;
        }
        wobble->mAnglePerFrame = t;
    } else if (wobble->mAnglePerFrame < 0) {
        t = wobble->mAnglePerFrame + wobble->mUnk_1c;
        if (t >= 0) {
            t = 0;
        }
        wobble->mAnglePerFrame = t;
    }
}

void UpdateCrab(void *a, Crab *crab) {
    Vec3 v;
    RandomState64 *mapObjectRandom;

    switch (crab->mState) {
        case 0:
            crab->mHandNsbtpFrameIndexFixed12 += 0x200;
            if (crab->mHandNsbtpFrameIndexFixed12 >=
                (s32) (GetMapObjectModelNsbtpFrameCount(gCrabHand) > 0
                           ? 0.5f + (GetMapObjectModelNsbtpFrameCount(gCrabHand) << 12)
                           : (GetMapObjectModelNsbtpFrameCount(gCrabHand) << 12) - 0.5f)) {
                crab->mHandNsbtpFrameIndexFixed12 = 0;
            }
            if (crab->mTimer-- > 0) {
                return;
            }
            if (crab->mHandNsbtpFrameIndexFixed12 == 0) {
                crab->mState = 1;
            }
            break;
        case 1:
            crab->mFollower.mSpeed = 0x800;
            crab->mFollower.mProgressStep =
                ((s64) crab->mFollower.mPath->mSegments[crab->mFollower.mSegmentIndex].mInverseProgressLength *
                 0x800) >>
                12;
            if (AdvanceGroupFollower(&crab->mFollower) != FALSE) {
                crab->mHandWobble.mAngle = 0;
                crab->mHandWobble.mMid = 0;
                crab->mHandWobble.mAmplitude = 0x1c7;
                crab->mHandWobble.mAmplitudePerFrame = 0;
                crab->mHandWobble.mAnglePerFrame = 0xe39;
                crab->mHandWobble.mUnk_1c = 0;
                mapObjectRandom = GetMapObjectRandom();
                mapObjectRandom->mValue =
                    mapObjectRandom->mMultiplier * mapObjectRandom->mValue + mapObjectRandom->mIncrement;
                crab->mTimer = (u16) ((u16) (((u64) (u32) (mapObjectRandom->mValue >> 32) * 60) >> 32) + 30);
                crab->mState = 0;
            }
            crab->mCrabNsbtpFrameIndexFixed12 += 0x200;
            if (crab->mCrabNsbtpFrameIndexFixed12 >=
                (s32) (GetMapObjectModelNsbtpFrameCount(gCrab) > 0
                           ? 0.5f + (GetMapObjectModelNsbtpFrameCount(gCrab) << 12)
                           : (GetMapObjectModelNsbtpFrameCount(gCrab) << 12) - 0.5f)) {
                crab->mCrabNsbtpFrameIndexFixed12 = 0;
            }
            func_0209a7dc_inline(&crab->mHandWobble);
            GetGroupFollowerLinearPosition(&crab->mFollower, &crab->mUnk_000.mPos);
            v = *GetGroupFollowerSegmentUp(&crab->mFollower);
            VEC_Subtract(&v, &crab->mUnk_000.mMatrix.mUnk_00[1], &v);
            v.x = ((s64) v.x * 0x800) >> 12;
            v.y = ((s64) v.y * 0x800) >> 12;
            v.z = ((s64) v.z * 0x800) >> 12;
            VEC_Add(&crab->mUnk_000.mMatrix.mUnk_00[1], &v, &crab->mUnk_000.mMatrix.mUnk_00[1]);
            if ((s64) crab->mUnk_000.mMatrix.mUnk_00[1].x * crab->mUnk_000.mMatrix.mUnk_00[1].x +
                    (s64) crab->mUnk_000.mMatrix.mUnk_00[1].y * crab->mUnk_000.mMatrix.mUnk_00[1].y +
                    (s64) crab->mUnk_000.mMatrix.mUnk_00[1].z * crab->mUnk_000.mMatrix.mUnk_00[1].z >=
                0x10) {
                Vec3NormalizeAndGetLengthUnchecked(&crab->mUnk_000.mMatrix.mUnk_00[1],
                                                   &crab->mUnk_000.mMatrix.mUnk_00[1]);
            }
            break;
        case 2:
            if (crab->mTimer-- > 0) {
                crab->mUnk_000.mUnk_10.y -= 0x400;
                VEC_Add(&crab->mUnk_000.mPos, &crab->mUnk_000.mUnk_10, &crab->mUnk_000.mPos);
                crab->mRotateZAngle += crab->mRotateZAnglePerFrame;
                return;
            }
            SetupGroupFollowerAtEntry(&crab->mFollower, 0, 0);
            GetGroupFollowerLinearXz(&crab->mFollower, &crab->mUnk_000.mPos);
            crab->mUnk_000.mPos.y = crab->mUnk_000.mCourseMapRow->mUnk_00.y - 0x5000;
            crab->mCrabWobble.mAngle = 0;
            crab->mCrabWobble.mMid = 0;
            crab->mCrabWobble.mAmplitude = 0x2aab;
            crab->mCrabWobble.mAmplitudePerFrame = -0xb6;
            crab->mCrabWobble.mAnglePerFrame = 0x71c;
            crab->mCrabWobble.mUnk_1c = 0;
            func_0209a7dc_inline(&crab->mCrabWobble);
            crab->mRotateZAngle = crab->mCrabWobble.mValue;
            crab->mState = 3;
            break;
        case 3:
            crab->mHandNsbtpFrameIndexFixed12 += 0x200;
            if (crab->mHandNsbtpFrameIndexFixed12 >=
                (s32) (GetMapObjectModelNsbtpFrameCount(gCrabHand) > 0
                           ? 0.5f + (GetMapObjectModelNsbtpFrameCount(gCrabHand) << 12)
                           : (GetMapObjectModelNsbtpFrameCount(gCrabHand) << 12) - 0.5f)) {
                crab->mHandNsbtpFrameIndexFixed12 = 0;
            }
            func_0209a7dc_inline(&crab->mCrabWobble);
            crab->mRotateZAngle = crab->mCrabWobble.mValue;
            crab->mUnk_000.mPos.y += 0x200;
            if (crab->mUnk_000.mPos.y < crab->mUnk_000.mCourseMapRow->mUnk_00.y) {
                return;
            }
            crab->mUnk_000.mPos.y = crab->mUnk_000.mCourseMapRow->mUnk_00.y;
            crab->mUnk_000.mUnk_10.x = 0;
            crab->mUnk_000.mUnk_10.y = 0;
            crab->mUnk_000.mUnk_10.z = 0;
            crab->mRotateZAngle = 0;
            crab->mHandWobble.mAngle = 0;
            crab->mHandWobble.mMid = 0;
            crab->mHandWobble.mAmplitude = 0x1c7;
            crab->mHandWobble.mAmplitudePerFrame = 0;
            crab->mHandWobble.mAnglePerFrame = 0xe39;
            crab->mHandWobble.mUnk_1c = 0;
            mapObjectRandom = GetMapObjectRandom();
            mapObjectRandom->mValue =
                mapObjectRandom->mMultiplier * mapObjectRandom->mValue + mapObjectRandom->mIncrement;
            crab->mTimer = (u16) ((u16) (((u64) (u32) (mapObjectRandom->mValue >> 32) * 60) >> 32) + 30);
            crab->mState = 0;
            crab->mUnk_000.mFlags &= ~1;
            break;
    }
}

void CreateCrabKindData(void) {
    MapObjectKindData *kindData;

    kindData = func_0209bf70(CollideKartWithCrab, CollideItemObjectWithCrab, NULL, 2, 1, 0x10e);
    kindData->mUnk_28 = 0x10f;
}

void *CreateCrabDrawList(void) {
    return CreateMapObjectDrawList2(CreateCrabAndCrabHand, DrawCrab, func_0209b1f8);
}

void *CreateCrabUpdateList(void) {
    return CreateMapObjectUpdateList(InitCrabObjects, UpdateCrab, NULL);
}
