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

void InitBasabasa(MapObject *mapObject) {
    MapObject *value0 = mapObject;
    MapObject *value4;
    value4 = value0;
    ParkMapObject(value0);
    value0 = value4;
    CreateMapObjectSoundSourceFalloff2(value0);
}

u8 CollideKartWithBasabasa(Basabasa *basabasa, Kart *kart, void *c, u8 *d) {
    Vec3 u;
    Vec3 offsetToKart;
    s32 k;
    s32 x;
    s32 z;
    u8 r;
    u8 kartBit;
    s64 lengthSquared;

    kartBit = 1 << kart->mIndex;
    r = *d;
    if ((basabasa->mHitKartMask & kartBit) == 0) {
        VEC_Subtract(&kart->mPos, &basabasa->mUnk_00.mPos, &offsetToKart);
        k = ((s64) basabasa->mUnk_00.mMatrix.mUnk_00[2].x * offsetToKart.x +
             (s64) basabasa->mUnk_00.mMatrix.mUnk_00[2].z * offsetToKart.z) >>
            12;
        x = offsetToKart.x - (s32) (((s64) basabasa->mUnk_00.mMatrix.mUnk_00[2].x * k) >> 12);
        z = offsetToKart.z - (s32) (((s64) basabasa->mUnk_00.mMatrix.mUnk_00[2].z * k) >> 12);
        lengthSquared = (s64) x * x + (s64) u.y * u.y + (s64) z * z;
        u.x = x;
        u.z = z;
        if (lengthSquared < 0x10) {
            basabasa->mUnk_00.mUnk_10.x = ((s64) basabasa->mUnk_00.mMatrix.mUnk_00[2].x * 0x1333) >> 12;
            basabasa->mUnk_00.mUnk_10.y = ((s64) basabasa->mUnk_00.mMatrix.mUnk_00[2].y * 0x1333) >> 12;
            basabasa->mUnk_00.mUnk_10.z = ((s64) basabasa->mUnk_00.mMatrix.mUnk_00[2].z * 0x1333) >> 12;
        } else {
            Vec3NormalizeAndGetLengthUnchecked(&u, &u);
            basabasa->mUnk_00.mUnk_10.x = ((s64) u.x * 0x1333) >> 12;
            basabasa->mUnk_00.mUnk_10.y = ((s64) u.y * 0x1333) >> 12;
            basabasa->mUnk_00.mUnk_10.z = ((s64) u.z * 0x1333) >> 12;
        }
        basabasa->mHitKartMask |= kartBit;
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

void DrawBasabasa(void *a, Basabasa *basabasa) {
    s32 s;
    s32 rotationMatrix[9];
    s32 drawAngle;

    drawAngle = 0x1fe0 - basabasa->mUnk_c4;
    s = 0x1e;
    func_01ff9048(0x14, &s, 1);
    func_01ff9048(0x19, SetViewTransposeMatrixPos(&basabasa->mUnk_00.mPos), 0xc);
    if (basabasa->mRotateZNegated != 0) {
        MTX_RotZ33_(rotationMatrix, gPairsByAngle[((u16) -drawAngle >> 4) * 2],
                    gPairsByAngle[((u16) -drawAngle >> 4) * 2 + 1]);
    } else {
        MTX_RotZ33_(rotationMatrix, gPairsByAngle[((u16) drawAngle >> 4) * 2],
                    gPairsByAngle[((u16) drawAngle >> 4) * 2 + 1]);
    }
    func_01ff9048(0x1a, rotationMatrix, 9);
    func_01ff9048(0x1b, &basabasa->mUnk_00.mScale, 3);
    SetMapObjectModelNsbtpFrameIndex(gBasabasa, basabasa->mNsbtpFrameIndex);
    DrawMapObjectModel(a, gBasabasa, basabasa);
}

void UpdateBasabasa(void *a, Basabasa *basabasa) {
    s32 nextFrameIndex;

    basabasa->mUnk_c4 += basabasa->mUnk_c8;
    basabasa->mUnk_c8 += 0x3c;
    if (basabasa->mUnk_c4 == 0) {
        basabasa->mUnk_c4 += basabasa->mUnk_c8;
        basabasa->mUnk_c8 += 0x3c;
    } else if (basabasa->mUnk_c4 >= 0x1fe0) {
        basabasa->mUnk_c8 = 0x3c - basabasa->mUnk_c8;
        basabasa->mRotateZNegated = basabasa->mRotateZNegated == 0;
    }
    switch (basabasa->mState) {
        case 0:
            if (basabasa->mDelayTimer-- > 0) {
                break;
            }
            basabasa->mUnk_00.mFlags &= ~1;
            basabasa->mUnk_00.mFlags &= ~2;
            basabasa->mUnk_00.mFlags &= ~8;
            basabasa->mUnk_00.mAlpha = 0x1f;
            basabasa->mVelocity.x += (s32) (((s64) basabasa->mUnk_00.mMatrix.mUnk_00[2].x * 0x19a) >> 12);
            basabasa->mVelocity.y += -0x19a;
            basabasa->mVelocity.z += (s32) (((s64) basabasa->mUnk_00.mMatrix.mUnk_00[2].z * 0x19a) >> 12);
            VEC_Add(&basabasa->mUnk_00.mPos, &basabasa->mVelocity, &basabasa->mUnk_00.mPos);
            if (basabasa->mState0Timer-- <= 0) {
                basabasa->mState = 1;
            }
            break;
        case 1:
            basabasa->mVelocity.x += (s32) (((s64) basabasa->mUnk_00.mMatrix.mUnk_00[2].x * 0x19a) >> 12);
            basabasa->mVelocity.y += 0x19a;
            basabasa->mVelocity.z += (s32) (((s64) basabasa->mUnk_00.mMatrix.mUnk_00[2].z * 0x19a) >> 12);
            VEC_Add(&basabasa->mUnk_00.mPos, &basabasa->mVelocity, &basabasa->mUnk_00.mPos);
            if (basabasa->mVelocity.y > 0) {
                basabasa->mVelocity.y = 0;
                basabasa->mState = 2;
            }
            break;
        case 2:
            VEC_Add(&basabasa->mUnk_00.mPos, &basabasa->mVelocity, &basabasa->mUnk_00.mPos);
            if (basabasa->mState2Timer-- <= 0) {
                basabasa->mState = 3;
            }
            break;
        case 3:
            basabasa->mVelocity.x -= (s32) (((s64) basabasa->mUnk_00.mMatrix.mUnk_00[2].x * 0xcd) >> 12);
            basabasa->mVelocity.y += 0x1000;
            basabasa->mVelocity.z -= (s32) (((s64) basabasa->mUnk_00.mMatrix.mUnk_00[2].z * 0xcd) >> 12);
            VEC_Add(&basabasa->mUnk_00.mPos, &basabasa->mVelocity, &basabasa->mUnk_00.mPos);
            if (basabasa->mUnk_00.mPos.y >= 0x1b8000) {
                ParkMapObject(&basabasa->mUnk_00);
            }
            break;
    }
    if (basabasa->mDelayTimer > 0) {
        return;
    }
    nextFrameIndex = basabasa->mNsbtpFrameIndex + 1;
    if (nextFrameIndex >= GetMapObjectModelNsbtpFrameCount(gBasabasa)) {
        nextFrameIndex = 0;
    }
    basabasa->mNsbtpFrameIndex = nextFrameIndex;
    if (basabasa->mSoundRequested == 0) {
        return;
    }
    StartMapObjectSoundWhileRequested(&basabasa->mUnk_00, 0x165);
}

void CreateBasabasaKindData(void) {
    CreateMapObjectKindData(&CollideKartWithBasabasa, NULL, NULL, 1, 0);
}

static inline u16 func_0209219c_inline(u32 limit) {
    RandomState64 *mapObjectRandom;
    u32 m;
    u32 r;

    if (limit == 0x10000) {
        mapObjectRandom = GetMapObjectRandom();
        mapObjectRandom->mValue = mapObjectRandom->mMultiplier * mapObjectRandom->mValue + mapObjectRandom->mIncrement;
        return ((mapObjectRandom->mValue >> 32) * 0x10000) >> 32;
    } else {
        mapObjectRandom = GetMapObjectRandom();
        m = (u16) limit;
        if (m == 0) {
            r = 0;
        } else {
            mapObjectRandom->mValue =
                mapObjectRandom->mMultiplier * mapObjectRandom->mValue + mapObjectRandom->mIncrement;
            if (m == 0) {
                r = mapObjectRandom->mValue >> 32;
            } else {
                r = ((mapObjectRandom->mValue >> 32) * m) >> 32;
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

void StartBasabasa(u32 state2TimerBase, const Vec3 *startPos, const Vec3 *velocity, u32 state0TimerBase,
                   s32 soundRequested, u16 f) {
    Basabasa *basabasa;
    RandomState64 *mapObjectRandom;
    u32 n;
    u16 w;

    basabasa = UnparkFirstParkedMapObject(func_02100138(MAP_OBJECT_KIND_BASABASA));
    if (basabasa == NULL) {
        return;
    }
    basabasa->mUnk_00.mFlags |= data_usa_02156460;
    basabasa->mUnk_00.mFlags |= data_usa_02156464;
    basabasa->mUnk_00.mFlags |= data_usa_02156468;
    basabasa->mSoundRequested = soundRequested;
    basabasa->mUnk_c0 = f;
    mapObjectRandom = GetMapObjectRandom();
    mapObjectRandom->mValue = mapObjectRandom->mMultiplier * mapObjectRandom->mValue + mapObjectRandom->mIncrement;
    basabasa->mDelayTimer = (u16) (((mapObjectRandom->mValue >> 32) * 30) >> 32);
    n = (state0TimerBase << 12) >> 16;
    w = func_0209219c_inline(n);
    basabasa->mState0Timer = state0TimerBase + w;
    n = (state2TimerBase << 12) >> 16;
    w = func_0209219c_inline(n);
    basabasa->mState2Timer = state2TimerBase + w;
    basabasa->mUnk_00.mPos = *startPos;
    basabasa->mVelocity = *velocity;
    basabasa->mState = 0;
    basabasa->mHitKartMask = 0;
}
