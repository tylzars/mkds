#include "Main/Unknown/code_0206e874.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_0206f04c.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_02070398.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02086058.h"
#include "Main/Unknown/code_020c476c.h"
#include "Main/Unknown/code_020d24d8.h"
#include "Main/Unknown/code_020d4104.h"
#include "Main/Unknown/code_020d411c.h"
#include "Main/Unknown/code_020d4130.h"
#include "Main/Unknown/code_020ea670.h"
#include "Main/Unknown/code_020d6538.h"
#include "Main/Unknown/code_020ed5c0.h"
#include "Main/Unknown/code_0210dc7c.h"
#include "Main/Unknown/unk_02154000.h"
#include "Main/Unknown/unk_0216c000.h"
#include "Main/Unknown/unk_02165000.h"
#include "code_02147cd8.h"

static inline s32 func_0206e874_inline(Vec3 *vector, Vec3 *normalized) {
    if ((s64) vector->x * vector->x + (s64) vector->y * vector->y + (s64) vector->z * vector->z < 0x10) {
        return 0;
    }
    return Vec3NormalizeAndGetLengthUnchecked(vector, normalized);
}

void func_0206edac(Kart *kart, Vec3 *groundNormal) {
    Vec3 v;
    s32 k;
    s32 s;
    s32 m;
    s32 n;
    u32 bits7c;
    s32 x;
    s32 distanceSquared;

    if (kart->mUnk_44 & 0x40000010) {
        return;
    }
    kart->mUnk_44 |= 0x10000;
    if (kart->mLandingTimer <= 0) {
        k = (kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) ? 3 : 2;
        x = data_usa_0216ca38[2];
        distanceSquared = GetKartCameraDistanceSquared(kart->mIndex);
        AddSoundRequest(data_0217d26c + k, distanceSquared + x, (void (*)(void *, int)) func_02071958, kart, 2);
        StartKartModelScaleAnimation(kart, 0);
    }
    kart->mLandingTimer = 7;
    if (kart->mUnk_48 & 0x2000000) {
        kart->mUnk_4c &= ~0x800;
        kart->mUnk_48 &= ~0x2000000;
        kart->mUnk_40c = GetRaceUpdateFrames();
        ResetRaceTaKartPositions(kart->mIndex);
        return;
    }
    if ((!(kart->mUnk_4c & 0x10000000) && kart->mVelocity.y < 0 &&
         (kart->mAirborneFrames > 0x19 || kart->mLastGroundY - kart->mPos.y > 0x1e000)) ||
        kart->mState == KART_STATE_LAUNCH_DOUBLE_FLIP) {
        s = VEC_DotProduct(groundNormal, &kart->mVelocity);
        v.x = ((s64) groundNormal->x * s) >> 12;
        v.y = ((s64) groundNormal->y * s) >> 12;
        v.z = ((s64) groundNormal->z * s) >> 12;
        if (VEC_Mag(&v) > 0x2000) {
            m = ((s64) kart->mSpeedLimitFactor * 0x1800) >> 12;
            n = v.y;
            if (n <= 0) {
                n = -n;
            }
            kart->mVerticalSpeed = ((s64) n * 0x99a) >> 12;
            if (kart->mVerticalSpeed > m) {
                kart->mVerticalSpeed = m;
            }
            bits7c = kart->mUnk_7c;
            if ((bits7c & 0x10) && kart->mKartModelsEntry->mUnk_058 == 0) {
                if ((bits7c & 1) || !(bits7c & 0x402000)) {
                    StartEffectWithCallback(0x4e, &kart->mPos, kart, func_0206c2b4);
                }
            }
        }
    }
    if (kart->mAirborneFrames <= 0x14) {
        return;
    }
    s = Vec3DotUnrounded(&kart->mUnk_138, groundNormal);
    if (s >= 0) {
        return;
    }
    if (kart->mAirTiltAngle <= 0x3e8) {
        return;
    }
    kart->mForwardSpeed = ((s64) kart->mForwardSpeed * (s + 0x1000)) >> 12;
}

void CollideKartWithMapObjects(Kart *kart) {
    MapObject *touchedMapObjects[2] = {0};
    s32 i;
    MapObject *mapObject;
    Vec3 positionOffset;
    Vec3 v;
    Vec3 w;
    Vec3 z;
    Vec3 *foundMapObjectVector;
    Vec3 *u;
    s32 v2;
    BOOL v3;
    u16 touchedCount;
    BOOL touchedBefore;
    s32 g;
    s32 handlerIndex;
    s32 foundCount;
    s32 handlerResult;
    s32 s;
    s32 d;
    s32 m;
    s32 v5;
    s32 v6;
    s32 v7;
    u16 j;

    v3 = FALSE;
    mapObject = NULL;
    touchedCount = 0;
    kart->mMapObjectVectorForwardDot = kart->mMapObjectVectorLength = 0;
    foundCount = FindMapObjectsTouchingKart(kart, &kart->mCollisionCenter, &positionOffset);
    if (foundCount != 0) {
        if (!(kart->mUnk_48 & 0x40)) {
            i = foundCount - 1;
            kart->mUnk_44 |= 0x40000;
            if (i >= 0) {
                z = data_02154f94;
                do {
                    s = 0;
                    touchedBefore = FALSE;
                    mapObject = GetFoundMapObject(i);
                    handlerIndex = func_020d6be0(kart, mapObject);
                    handlerResult =
                        ((s32(*)(Kart *, s32 *, MapObject *)) gCollideKartWithMapObjectResponses[handlerIndex])(
                            kart, &v2, mapObject);
                    if (handlerResult != 0) {
                        v = z;
                        u = &mapObject->mUnk_10;
                        foundMapObjectVector = GetFoundMapObjectVector(i);
                        d = func_0206e874_inline(foundMapObjectVector, &v);
                        if (d != 0) {
                            if (v2 != 2) {
                                ((void (*)(Kart *, Vec3 *, MapObject *)) data_0217ac54[handlerIndex])(kart, &v,
                                                                                                      mapObject);
                            }
                            if (handlerResult & 8) {
                                func_0206f04c(kart, &v, (kart->mUnk_44 & 0x40) ? 1 : 0, 0x1000, -1, -1, v2);
                            } else if (handlerResult & 2) {
                                s = Vec3DotUnrounded(&kart->mTurnedForward, &v) + 0x1000;
                                if (s > 0x1000) {
                                    s = 0x1000;
                                } else if (s < 0x29) {
                                    s = 0x29;
                                }
                                kart->mSpeedLimitHitFactor = ((s64) kart->mSpeedLimitHitFactor * s) >> 12;
                            }
                        }
                        if (handlerResult & 1) {
                            if (u->x != 0 || u->y != 0 || u->z != 0) {
                                w = z;
                                m = 1;
                                if (handlerResult & 4) {
                                    w = *u;
                                } else {
                                    if (d != 0) {
                                        s = VEC_DotProduct(&v, u);
                                        w.x = ((s64) v.x * s) >> 12;
                                        w.y = ((s64) v.y * s) >> 12;
                                        w.z = ((s64) v.z * s) >> 12;
                                    }
                                    if (Vec3DotUnrounded(&v, &w) < 0) {
                                        m = 0;
                                    }
                                }
                                kart->mMapObjectVectorLength = VEC_Mag(&w);
                                if (kart->mMapObjectVectorLength > 0x1000 && m != 0) {
                                    kart->mMapObjectVectorForwardDot = Vec3DotUnrounded(&kart->mTurnedForward, &w);
                                    s = VEC_DotProduct(&kart->mTurnedForward, &w);
                                    v6 = w.y - (s32) (((s64) kart->mTurnedForward.y * s) >> 12);
                                    v7 = w.z - (s32) (((s64) kart->mTurnedForward.z * s) >> 12);
                                    v5 = w.x - (s32) (((s64) kart->mTurnedForward.x * s) >> 12);
                                    kart->mHitVelocity.x += v5;
                                    kart->mHitVelocity.z += v7;
                                    kart->mVerticalSpeed += v6;
                                }
                            }
                        }
                        s = kart->mSpeedLimitHitFactor;
                        if (handlerResult & 8) {
                            v3 = TRUE;
                        }
                    }
                    g = mapObject->mFlags & 0x200;
                    if (g != 0) {
                        m = 0x1000;
                    } else {
                        m = ((s64) (0x1000 - s) * (s32) (((s64) kart->mVelocityLength * data_usa_021654ec) >> 12)) >>
                            12;
                    }
                    if (kart->mVelocityLength > 0x2000 || g != 0) {
                        if (touchedCount < 2) {
                            for (j = 0; j < 2; j++) {
                                if (mapObject == kart->mPrevTouchingMapObjects[j]) {
                                    touchedBefore = TRUE;
                                    break;
                                }
                            }
                            if (touchedBefore == FALSE) {
                                for (j = 0; j < 2; j++) {
                                    if (mapObject == kart->mPrevTouchingMapObjects[j] || kart->mUnk_444[j] != 0) {
                                        continue;
                                    }
                                    StartMapObjectKindSound(mapObject, &kart->mSoundSource, v2, m);
                                    kart->mUnk_444[j] = 1;
                                    break;
                                }
                            }
                            touchedMapObjects[touchedCount] = mapObject;
                            touchedCount++;
                        }
                    }
                    if (handlerIndex == 0xb) {
                        kart->mUnk_44c = mapObject;
                    }
                } while (--i >= 0);
            }
        }
        if (kart->mUnk_48 & 0x4000000) {
            if (kart->mUnk_44c == mapObject) {
                positionOffset.z = 0;
                positionOffset.x = 0;
            }
        }
        VEC_Add(&kart->mPos, &positionOffset, &kart->mPos);
    }
    for (j = 0; j < 2; j++) {
        kart->mPrevTouchingMapObjects[j] = touchedMapObjects[j];
        if (kart->mUnk_444[j] != 0) {
            kart->mUnk_440[j]++;
            if (kart->mUnk_440[j] > 10) {
                kart->mUnk_444[j] = 0;
                kart->mUnk_440[j] = 0;
            }
        }
    }
    if (v3 != FALSE) {
        kart->mUnk_44 |= 0x40;
    } else {
        kart->mUnk_44 &= ~0x40;
    }
}
