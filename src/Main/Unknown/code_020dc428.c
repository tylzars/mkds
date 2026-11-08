#include "Main/Unknown/code_020dc428.h"

#include "Main/Unknown/code_020dc448.h"
#include "Main/Unknown/code_020dc474.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_020dc5dc.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_020daf20.h"
#include "Main/Unknown/code_020d6000.h"
#include "Main/Unknown/code_020d8b88.h"
#include "code_02148538.h"
#include "Main/Unknown/code_020d4000.h"
#include "Main/Unknown/code_0210b760.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/code_020d8000.h"
#include "Main/Unknown/code_020d8474.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020d2000.h"
#include "ITCM/code_01ffba68.h"
#include "ITCM/code_01ffdee4.h"
#include "ITCM/code_01ffc000.h"
#include "Main/Unknown/code_020d7000.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Unknown/code_020b2ec0.h"
#include "Main/Unknown/code_020ea670.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020e6f50.h"
#include "Main/Unknown/code_020d49d8.h"
#include "Main/Unknown/code_020db000.h"
#include "Main/Unknown/code_020dc000.h"
#include "Main/Unknown/unk_0216b000.h"
#include "Main/Unknown/code_020dbf7c.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_02077bc0.h"

Unk020dd7a8 *gWanwanUpdateList = 0;
Unk020dd804 *gWanwanDrawList = 0;

const Unk020dd860 data_02158388 = {func_020dd230, func_020dd1f4, 1, 0x1b000, {0}, 1, 1, 0x12e, {0}};
const Unk020dd804 data_0215835c = {{0}, CreateWanwanAndRockShadow, {0}, func_020dd6c8, {0}, 1, {0}, 0};
const Unk020dd7a8 data_02158334 = {{0}, UpdateWanwan, {0}, 0};

Unk020dd860 *CreateWanwanKindData(void) {
    Unk020dd860 *kindData;

    kindData = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x40);
    *kindData = data_02158388;
    return kindData;
}

Unk020dd804 *CreateWanwanDrawList(void) {
    Unk020dd804 *drawList;

    drawList = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x2c);
    gWanwanDrawList = drawList;
    *drawList = data_0215835c;
    func_020d49d8(&gWanwanDrawList);
    return gWanwanDrawList;
}

Unk020dd7a8 *CreateWanwanUpdateList(void) {
    Unk020dd7a8 *updateList;

    updateList = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x28);
    gWanwanUpdateList = updateList;
    *updateList = data_02158334;
    SetUpdateListSlot(&gWanwanUpdateList);
    return gWanwanUpdateList;
}

void func_020dd6c8(void *unused0, Wanwan *wanwan, void *unused1, u32 maxAlpha) {
    MtxFx43 shadowMatrix;

    if (wanwan->mUnk_00.mStateMachine.mState == 4) {
        if (func_020b2ec0() == 0) {
            wanwan->mUnk_00.mPos.x += wanwan->mUnk_00.mUnk_10.x;
            wanwan->mUnk_00.mPos.z += wanwan->mUnk_00.mUnk_10.z;
        }
    }
    wanwan->mUnk_00.mMatrix.mUnk_00[3].x = wanwan->mUnk_00.mPos.x >> 4;
    wanwan->mUnk_00.mMatrix.mUnk_00[3].y = wanwan->mUnk_00.mPos.y >> 4;
    wanwan->mUnk_00.mMatrix.mUnk_00[3].z = wanwan->mUnk_00.mPos.z >> 4;
    DrawNsbmdWithMatrixAndMaxAlpha(gWanwan, &wanwan->mUnk_00.mMatrix, &wanwan->mUnk_00.mScale, maxAlpha);
    Matrix3x3FromQuaternion(&shadowMatrix, &wanwan->mUnk_d4);
    shadowMatrix.mUnk_00[3].x = wanwan->mUnk_00.mPos.x >> 4;
    shadowMatrix.mUnk_00[3].y = wanwan->mUnk_00.mPos.y >> 4;
    shadowMatrix.mUnk_00[3].z = wanwan->mUnk_00.mPos.z >> 4;
    DrawShadowWithMaxAlpha(gWanwanRockShadow, &shadowMatrix, &wanwan->mUnk_00.mScale, maxAlpha);
}

void UpdateWanwan(void *unused, Wanwan *wanwan) {
    u32 surfaceFlags;
    Quaternion targetOrientation;
    Vec3 probePos;
    Vec3 correction;
    Vec3 surfaceNormal;
    Unk0210b7a8 b;
    Unk0210b7a8 c;
    Unk0210b7a8 d;
    s32 h;
    BOOL k;
    s32 x;
    s32 z;
    s32 t;
    s32 y;

    h = wanwan->mUnk_b0;
    AdvanceStateMachine(&wanwan->mUnk_00.mStateMachine);
    wanwan->mUnk_00.mUnk_10.y -= 0x400;
    wanwan->mUnk_00.mPos.y += wanwan->mUnk_00.mUnk_10.y;
    k = FALSE;
    probePos.x = wanwan->mUnk_00.mPos.x;
    probePos.y = wanwan->mUnk_00.mPos.y + wanwan->mUnk_f4 + 0x5000;
    probePos.z = wanwan->mUnk_00.mPos.z;
    if (h == 0) {
        correction.y = wanwan->mUnk_ac + 0xd000 - probePos.y;
        if (correction.y > 0) {
            k = TRUE;
            correction.x = 0;
            correction.z = 0;
            if (wanwan->mUnk_fc != 0) {
                if (!(wanwan->mUnk_00.mDistanceSquaredAndFlags & 4)) {
                    if (wanwan->mUnk_00.mFarDistanceSquared == gSoundFalloffs[2].mUnk_20) {
                        y = 2;
                    } else if (wanwan->mUnk_00.mFarDistanceSquared == gSoundFalloffs[3].mUnk_20) {
                        y = 3;
                    } else {
                        y = 4;
                    }
                    c.mUnk_00 = 0x1a1;
                    c.mUnk_04 = &wanwan->mUnk_00.mPos;
                    c.mUnk_08 = y;
                    c.mUnk_0c = GetHorizontalCameraDistanceSquared(&wanwan->mUnk_00.mPos);
                    func_0210b7a8(&c);
                }
            }
        }
    } else {
        if (func_01ffdee4(&probePos, NULL, 0, 0xd000, 8, -2, &correction, &surfaceNormal, NULL, &surfaceFlags, NULL,
                          NULL, NULL, NULL) != 0) {
            k = TRUE;
            if (wanwan->mUnk_fc != 0) {
                if (!(wanwan->mUnk_00.mDistanceSquaredAndFlags & 4)) {
                    if (wanwan->mUnk_00.mFarDistanceSquared == gSoundFalloffs[2].mUnk_20) {
                        y = 2;
                    } else if (wanwan->mUnk_00.mFarDistanceSquared == gSoundFalloffs[3].mUnk_20) {
                        y = 3;
                    } else {
                        y = 4;
                    }
                    d.mUnk_00 = 0x1df;
                    d.mUnk_04 = &wanwan->mUnk_00.mPos;
                    d.mUnk_08 = y;
                    d.mUnk_0c = GetHorizontalCameraDistanceSquared(&wanwan->mUnk_00.mPos);
                    func_0210b7a8(&d);
                }
            }
        }
    }
    if (k != FALSE) {
        k = TRUE;
        if (wanwan->mUnk_00.mStateMachine.mState == 2) {
            if (wanwan->mUnk_00.mStateMachine.mStateFrames < 0x78) {
                k = FALSE;
            }
        }
        wanwan->mUnk_00.mPos.y += correction.y;
        if (wanwan->mUnk_fc != 0 || k != FALSE) {
            if (wanwan->mUnk_fc != 0) {
                x = wanwan->mFollower.mUnk_00.mToEntry->mPos.x;
                z = wanwan->mFollower.mUnk_00.mToEntry->mPos.z;
            } else {
                x = wanwan->mCurvePoints[2]->x - wanwan->mUnk_00.mPos.x;
                z = wanwan->mCurvePoints[2]->z - wanwan->mUnk_00.mPos.z;
            }
            t = ((s64) (s32) (((s64) wanwan->mUnk_00.mUnk_10.x * x + (s64) wanwan->mUnk_00.mUnk_10.z * z) >> 12)
                 << 9) >>
                12;
            if (t > 0x3000) {
                t = 0x3000;
            } else if (t < 0x2800) {
                t = 0x2800;
            }
            wanwan->mUnk_00.mUnk_10.y = t;
        } else if (wanwan->mUnk_e8 == 0xd000) {
            wanwan->mUnk_00.mUnk_10.y = 0x2000;
            wanwan->mUnk_e8 += 0x1000;
        } else {
            wanwan->mUnk_00.mUnk_10.y = 0;
        }
        if (h != 0) {
            if (surfaceFlags & 0x1e34ef) {
                t = ((s64) wanwan->mUnk_00.mUnk_10.x * surfaceNormal.x +
                     (s64) wanwan->mUnk_00.mUnk_10.z * surfaceNormal.z) >>
                    12;
                if (t < 0) {
                    wanwan->mUnk_00.mUnk_10.y += (s32) (((s64) -t * 0x14cd) >> 12);
                }
                QuaternionFromYAxisToVec3(&surfaceNormal, &wanwan->mUnk_c4);
            }
        }
        if (wanwan->mUnk_fc == 0 && !(wanwan->mUnk_00.mDistanceSquaredAndFlags & 4) && k != FALSE) {
            b = data_0216bedc;
            b.mUnk_04 = &wanwan->mUnk_00.mPos;
            b.mUnk_0c = wanwan->mUnk_00.mDistanceSquaredAndFlags & ~0xc000001f;
            func_0210b7a8(&b);
        }
    }
    if (h != 0) {
        func_020d7938(&wanwan->mUnk_c4, &wanwan->mUnk_d4, &targetOrientation);
    }
    wanwan->mUnk_e4 = wanwan->mUnk_e4 + ((-wanwan->mUnk_00.mUnk_10.y >> 1) - wanwan->mUnk_e4 >> 4);
    if (h != 0) {
        QuaternionMultiplyAngleAroundX(&targetOrientation, (u16) (wanwan->mUnk_e8 + wanwan->mUnk_e4),
                                       &targetOrientation);
    } else {
        func_020d76a8(&wanwan->mUnk_d4, (u16) (wanwan->mUnk_e8 + wanwan->mUnk_e4), &targetOrientation);
    }
    QuaternionBlendTowardNearerSign(&wanwan->mUnk_b4, &targetOrientation, &wanwan->mUnk_b4, wanwan->mUnk_ec);
    QuaternionNormalizeUnlessNearOne(&wanwan->mUnk_b4, &wanwan->mUnk_b4);
    Matrix3x3FromQuaternion(&wanwan->mUnk_00.mMatrix, &wanwan->mUnk_b4);
    if (wanwan->mUnk_00.mPos.y >= 0) {
        return;
    }
    ResetWanwan(wanwan);
}

u8 func_020dd230(Wanwan *wanwan, void *kart, u8 *b, u8 *c) {
    if (*b == 1) {
        if (wanwan->mUnk_00.mStateMachine.mState != 2 || wanwan->mUnk_00.mUnk_10.y < 0x4000) {
            wanwan->mUnk_00.mStateMachine.mNextState = 2;
            wanwan->mUnk_00.mStateMachine.mNextStateRequested = 1;
            StartSoundIfKartStarOrKiller(&wanwan->mUnk_00, kart);
        }
    }
    return *c;
}

u8 func_020dd1f4(Wanwan *wanwan, void *kart, u8 *b, u8 *c) {
    if (*b == 1) {
        if (wanwan->mUnk_00.mStateMachine.mState != 2 || wanwan->mUnk_00.mUnk_10.y < 0x4000) {
            wanwan->mUnk_00.mStateMachine.mNextState = 2;
            wanwan->mUnk_00.mStateMachine.mNextStateRequested = 1;
        }
    }
    return *c;
}

// Kind 0x196 only (kind 0x1a5 never reaches state 0).
void EnterWanwanState0(Wanwan *wanwan) {
    Vec3 *savedPoint;

    wanwan->mUnk_e8 = 0x555;
    wanwan->mUnk_ec = 0x1c2;
    wanwan->mChainObject->mUnk_a8 = 0x599;
    savedPoint = wanwan->mCurvePoints[0];
    wanwan->mCurvePoints[0] = NULL;
    *wanwan->mCurvePoints[1] = wanwan->mUnk_00.mPos;
    *wanwan->mCurvePoints[2] = *wanwan->mCurvePoints[1];
    wanwan->mCurvePoints[2]->x += (s32) (((s64) wanwan->mUnk_00.mMatrix.mUnk_00[2].x * wanwan->mUnk_f0) >> 12);
    wanwan->mCurvePoints[2]->z += (s32) (((s64) wanwan->mUnk_00.mMatrix.mUnk_00[2].z * wanwan->mUnk_f0) >> 12);
    *wanwan->mCurvePoints[3] = *wanwan->mCurvePoints[2];
    wanwan->mCurvePoints[3]->x += (s32) (((s64) wanwan->mUnk_00.mMatrix.mUnk_00[0].x * wanwan->mUnk_f0) >> 12);
    wanwan->mCurvePoints[3]->z += (s32) (((s64) wanwan->mUnk_00.mMatrix.mUnk_00[0].z * wanwan->mUnk_f0) >> 12);
    func_020d7d18(&wanwan->mSegmentProgress, 1, wanwan->mCurvePoints, 0x1000);
    wanwan->mCurvePoints[0] = savedPoint;
}

static inline s64 func_020dccc8_inline(const Vec3 *vector) {
    return (s64) vector->x * vector->x + (s64) vector->z * vector->z;
}

// Kind 0x196 only (kind 0x1a5 never reaches state 0).
void UpdateWanwanState0(Wanwan *wanwan) {
    Vec3 *candidate;
    Vec3 *lastPoint;
    Unk020f41c4_B *random;
    Kart *kart;
    s32 attemptCount;
    s32 lastStepZ;
    s32 lastStepX;
    s32 a;
    u32 n;
    s32 v;
    s32 radius;
    s32 offsetX;
    s32 offsetZ;
    s32 dot;
    s32 e;
    u32 angleIndex;
    u16 kartIndex;

    wanwan->mUnk_00.mUnk_10.x = wanwan->mUnk_00.mPos.x;
    wanwan->mUnk_00.mUnk_10.z = wanwan->mUnk_00.mPos.z;
    if (AdvanceSegmentProgress(&wanwan->mSegmentProgress) != FALSE) {
        lastStepX = wanwan->mCurvePoints[3]->x - wanwan->mCurvePoints[2]->x;
        lastStepZ = wanwan->mCurvePoints[3]->z - wanwan->mCurvePoints[2]->z;
        do {
            attemptCount = 0;
            candidate = wanwan->mCurvePoints[0];
            while (1) {
                a = wanwan->mUnk_f8;
                random = GetMapObjectRandom();
                n = a - 0x2d000;
                if (n == 0) {
                    v = 0;
                } else {
                    random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
                    if (n == 0) {
                        v = (u32) (random->mValue >> 32);
                    } else {
                        v = (u32) (((u64) (random->mValue >> 32) * (u64) n) >> 32);
                    }
                }
                random = GetMapObjectRandom();
                radius = v + 0x2d000;
                random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
                angleIndex = (u16) (((random->mValue >> 32) * 0x10000) >> 32) >> 4;
                attemptCount++;
                candidate->x = wanwan->mCenterPos.x + (s32) (((s64) gPairsByAngle[angleIndex * 2] * radius) >> 12);
                candidate->z = wanwan->mCenterPos.z + (s32) (((s64) gPairsByAngle[angleIndex * 2 + 1] * radius) >> 12);
                if (attemptCount > 5) {
                    break;
                }
                lastPoint = wanwan->mCurvePoints[3];
                offsetX = candidate->x - lastPoint->x;
                offsetZ = candidate->z - lastPoint->z;
                if ((s64) (s32) offsetX * offsetX + (s64) (s32) offsetZ * offsetZ < 0x7e9000000LL) {
                    continue;
                }
                dot = ((s64) offsetX * lastStepX + (s64) offsetZ * lastStepZ) >> 12;
                if (dot < 0) {
                    dot = -dot;
                    e = (-(s64) offsetX * lastStepZ + (s64) offsetZ * lastStepX) >> 12;
                    if (e < 0) {
                        e = -e;
                    }
                    if (dot >> 2 >= e) {
                        continue;
                    }
                }
                break;
            }
            wanwan->mCurvePoints[0] = wanwan->mCurvePoints[1];
            wanwan->mCurvePoints[1] = wanwan->mCurvePoints[2];
            wanwan->mCurvePoints[2] = wanwan->mCurvePoints[3];
            wanwan->mCurvePoints[3] = candidate;
        } while (func_020d7c84(&wanwan->mSegmentProgress, 1, wanwan->mCurvePoints) != FALSE);
    }
    GetSegmentProgressPointXz(&wanwan->mSegmentProgress, &wanwan->mUnk_00.mPos);
    if (!(wanwan->mUnk_00.mFlags & 0x800)) {
        kartIndex = GetRaceUpdateFramesModKartCount();
        kart = GetKart(kartIndex);
        if (func_0206c0e0(kart) == FALSE) {
            e = wanwan->mUnk_1dc;
            if ((s64) (kart->mPos.x - wanwan->mCenterPos.x) * (kart->mPos.x - wanwan->mCenterPos.x) +
                    (s64) (kart->mPos.z - wanwan->mCenterPos.z) * (kart->mPos.z - wanwan->mCenterPos.z) <
                (s64) e * e) {
                wanwan->mKartPos = &GetKart(kartIndex)->mPos;
                wanwan->mKartVelocity = &GetKart(kartIndex)->mVelocity;
                wanwan->mUnk_00.mStateMachine.mNextState = 1;
                wanwan->mUnk_00.mStateMachine.mNextStateRequested = 1;
            }
        }
    }
    wanwan->mUnk_00.mUnk_10.x = wanwan->mUnk_00.mPos.x - wanwan->mUnk_00.mUnk_10.x;
    wanwan->mUnk_00.mUnk_10.z = wanwan->mUnk_00.mPos.z - wanwan->mUnk_00.mUnk_10.z;
    if (func_020dccc8_inline(&wanwan->mUnk_00.mUnk_10) >= 0x10) {
        QuaternionFromAngleAroundY(
            (u16) (((s64) FX_Atan2(wanwan->mUnk_00.mUnk_10.x, wanwan->mUnk_00.mUnk_10.z) * 0x28be60db9391LL +
                    0x80000000000LL) >>
                   44),
            &wanwan->mUnk_d4);
    }
    if (wanwan->mUnk_00.mStateMachine.mStateFrames < 0x40) {
        wanwan->mUnk_ec += 0x1c;
    }
}

void EnterWanwanState1(Wanwan *wanwan) {
    Unk0210b7a8 soundRequest;
    s32 falloffIndex;

    wanwan->mUnk_e8 = 0x2000;
    wanwan->mUnk_ec = 0x1c2;
    wanwan->mUnk_1e0 = wanwan->mUnk_00.mPos;
    wanwan->mChainObject->mUnk_a8 = 0x219;
    wanwan->mUnk_1f8 = 0;
    if (wanwan->mUnk_00.mDistanceSquaredAndFlags & 4) {
        return;
    }
    if (wanwan->mUnk_00.mFarDistanceSquared == gSoundFalloffs[2].mUnk_20) {
        falloffIndex = 2;
    } else if (wanwan->mUnk_00.mFarDistanceSquared == gSoundFalloffs[3].mUnk_20) {
        falloffIndex = 3;
    } else {
        falloffIndex = 4;
    }
    soundRequest.mUnk_00 = 0x12c;
    soundRequest.mUnk_04 = &wanwan->mUnk_00.mPos;
    soundRequest.mUnk_08 = falloffIndex;
    soundRequest.mUnk_0c = GetHorizontalCameraDistanceSquared(&wanwan->mUnk_00.mPos);
    func_0210b7a8(&soundRequest);
}

void UpdateWanwanState1(Wanwan *wanwan) {
    Vec3 a;
    Vec3 predictedPos;
    s32 t;
    s32 k;
    s32 m;

    if (wanwan->mUnk_00.mStateMachine.mStateFrames > wanwan->mUnk_1f8) {
        VEC_Subtract(wanwan->mKartPos, &wanwan->mUnk_00.mPos, &a);
        t = ((s64) wanwan->mKartVelocity->x * a.z - (s64) wanwan->mKartVelocity->z * a.x) >> 12;
        t = -t >> 12;
        if (t < 0) {
            t = -t;
        }
        k = ((s64) t * 0x7a) >> 12;
        predictedPos.x = wanwan->mKartVelocity->x * k;
        predictedPos.z = wanwan->mKartVelocity->z * k;
        VEC_Add(&predictedPos, wanwan->mKartPos, &predictedPos);
        VEC_Subtract(&predictedPos, &wanwan->mCenterPos, &a);
        m = Vec3NormalizeXZAndGetLengthOrZero(&a, &a);
        if (m > wanwan->mUnk_f0) {
            m -= wanwan->mUnk_f0 >> 1;
        }
        if (m > wanwan->mMaxRadius) {
            m = wanwan->mMaxRadius;
        }
        a.x = ((s64) a.x * m) >> 12;
        a.y = ((s64) a.y * m) >> 12;
        a.z = ((s64) a.z * m) >> 12;
        VEC_Add(&a, &wanwan->mCenterPos, &wanwan->mUnk_1e0);
        wanwan->mUnk_1f8 += 0xb4;
    }
    VEC_Subtract(&wanwan->mUnk_1e0, &wanwan->mUnk_00.mPos, &a);
    wanwan->mUnk_00.mUnk_10.x += (s32) (((s64) a.x << 5) >> 12);
    wanwan->mUnk_00.mUnk_10.z += (s32) (((s64) a.z << 5) >> 12);
    if (func_020dccc8_inline(&wanwan->mUnk_00.mUnk_10) >= 0x40000000) {
        wanwan->mUnk_00.mUnk_10.x -= (s32) (((s64) wanwan->mUnk_00.mUnk_10.x * 0x4cc) >> 12);
        wanwan->mUnk_00.mUnk_10.z -= (s32) (((s64) wanwan->mUnk_00.mUnk_10.z * 0x4cc) >> 12);
    }
    if (func_020dccc8_inline(&a) < (s64) (wanwan->mUnk_f0 >> 1) * (wanwan->mUnk_f0 >> 1)) {
        wanwan->mUnk_00.mUnk_10.x >>= 1;
        wanwan->mUnk_00.mUnk_10.z >>= 1;
    } else {
        QuaternionFromAngleAroundY((u16) (((s64) FX_Atan2(a.x, a.z) * 0x28be60db9391LL + 0x80000000000LL) >> 44),
                                   &wanwan->mUnk_d4);
    }
    t = ((s64) wanwan->mUnk_00.mUnk_10.x * a.z) >> 12;
    t -= (s32) (((s64) wanwan->mUnk_00.mUnk_10.z * a.x) >> 12);
    if (((s64) a.x * a.x + (s64) a.z * a.z) * 10 < (s64) t * t) {
        wanwan->mUnk_00.mUnk_10.x >>= 1;
        wanwan->mUnk_00.mUnk_10.z >>= 1;
    }
    wanwan->mUnk_00.mPos.x += wanwan->mUnk_00.mUnk_10.x;
    wanwan->mUnk_00.mPos.z += wanwan->mUnk_00.mUnk_10.z;
    VEC_Subtract(&wanwan->mUnk_00.mPos, &wanwan->mCenterPos, &a);
    if ((s64) a.x * a.x + (s64) a.z * a.z >= (s64) wanwan->mMaxRadius * wanwan->mMaxRadius) {
        Vec3NormalizeXZAndGetLengthOrZero(&a, &a);
        wanwan->mUnk_00.mPos.x = wanwan->mCenterPos.x + (s32) (((s64) a.x * wanwan->mMaxRadius) >> 12);
        wanwan->mUnk_00.mPos.z = wanwan->mCenterPos.z + (s32) (((s64) a.z * wanwan->mMaxRadius) >> 12);
        k = ((s64) wanwan->mUnk_00.mUnk_10.x * a.x) >> 12;
        m = ((s64) wanwan->mUnk_00.mUnk_10.z * a.z) >> 12;
        if (k + m > 0) {
            wanwan->mUnk_00.mUnk_10.x -= (s32) (((s64) k * a.x) >> 12);
            wanwan->mUnk_00.mUnk_10.z -= (s32) (((s64) m * a.z) >> 12);
        }
    }
    if (wanwan->mUnk_00.mStateMachine.mStateFrames >= 0xb4) {
        wanwan->mUnk_00.mStateMachine.mNextState = 3;
        wanwan->mUnk_00.mStateMachine.mNextStateRequested = 1;
    }
}

void EnterWanwanState2(Wanwan *wanwan) {
    wanwan->mUnk_e8 = 0xd000;
    wanwan->mUnk_ec = 0x1c2;
    if (wanwan->mUnk_fc == 0) {
        wanwan->mChainObject->mUnk_a8 = 0x219;
    }
    wanwan->mUnk_00.mUnk_10.y = 0x8000;
}

void UpdateWanwanState2(Wanwan *wanwan) {
    const Vec3 *velocity;

    if (wanwan->mUnk_fc != 0) {
        wanwan->mUnk_00.mUnk_10.x = wanwan->mUnk_00.mPos.x;
        wanwan->mUnk_00.mUnk_10.z = wanwan->mUnk_00.mPos.z;
        AdvanceGroupFollowerWithSpeeds(&wanwan->mFollower);
        GetGroupFollowerCurveXz(&wanwan->mFollower.mUnk_00, &wanwan->mUnk_00.mPos);
        wanwan->mUnk_00.mUnk_10.x = wanwan->mUnk_00.mPos.x - wanwan->mUnk_00.mUnk_10.x;
        wanwan->mUnk_00.mUnk_10.z = wanwan->mUnk_00.mPos.z - wanwan->mUnk_00.mUnk_10.z;
        velocity = &wanwan->mUnk_00.mUnk_10;
        if ((s64) velocity->x * velocity->x + (s64) velocity->z * velocity->z >= 0x10) {
            QuaternionFromAngleAroundY(
                (u16) (((s64) FX_Atan2(wanwan->mUnk_00.mUnk_10.x, wanwan->mUnk_00.mUnk_10.z) * 0x28be60db9391LL +
                        0x80000000000LL) >>
                       44),
                &wanwan->mUnk_d4);
        }
        if (wanwan->mUnk_00.mStateMachine.mStateFrames < 0x40) {
            wanwan->mUnk_ec += 0x1c;
        }
        if (wanwan->mUnk_00.mStateMachine.mStateFrames >= 0x28) {
            wanwan->mUnk_e8 += 0x200;
        } else {
            wanwan->mUnk_00.mUnk_10.y -= 0x266;
        }
        if (wanwan->mUnk_e8 > 0x10555) {
            wanwan->mUnk_00.mStateMachine.mNextState = 5;
            wanwan->mUnk_00.mStateMachine.mNextStateRequested = 1;
        }
    } else {
        if (wanwan->mUnk_e8 == 0xd000) {
            wanwan->mUnk_00.mUnk_10.y -= 0x19a;
        }
        if (wanwan->mUnk_00.mStateMachine.mStateFrames >= 0x78) {
            wanwan->mUnk_e8 += 0x100;
        }
        if (wanwan->mUnk_e8 > 0x10555) {
            wanwan->mUnk_00.mStateMachine.mNextState = 3;
            wanwan->mUnk_00.mStateMachine.mNextStateRequested = 1;
        }
    }
}

void EnterWanwanState3(Wanwan *wanwan) {
    wanwan->mUnk_e8 = 0x555;
    wanwan->mUnk_ec = 0x1c2;
    wanwan->mChainObject->mUnk_a8 = 0x599;
}

static inline s64 func_020dc474_inline(const Vec3 *vector) {
    return (s64) vector->x * vector->x + (s64) vector->z * vector->z;
}

void UpdateWanwanState3(Wanwan *wanwan) {
    Vec3 toCenter;
    s32 radius;

    radius = wanwan->mUnk_1fc;
    if ((s64) (wanwan->mUnk_00.mPos.x - wanwan->mCenterPos.x) * (wanwan->mUnk_00.mPos.x - wanwan->mCenterPos.x) +
            (s64) (wanwan->mUnk_00.mPos.z - wanwan->mCenterPos.z) * (wanwan->mUnk_00.mPos.z - wanwan->mCenterPos.z) >=
        (s64) radius * radius) {
        VEC_Subtract(&wanwan->mCenterPos, &wanwan->mUnk_00.mPos, &toCenter);
        wanwan->mUnk_00.mUnk_10.x += (s32) (((s64) toCenter.x << 2) >> 12);
        wanwan->mUnk_00.mUnk_10.z += (s32) (((s64) toCenter.z << 2) >> 12);
        if (func_020dc474_inline(&wanwan->mUnk_00.mUnk_10) >= 0x1000000) {
            wanwan->mUnk_00.mUnk_10.x -= (s32) (((s64) wanwan->mUnk_00.mUnk_10.x * 0x199) >> 12);
            wanwan->mUnk_00.mUnk_10.z -= (s32) (((s64) wanwan->mUnk_00.mUnk_10.z * 0x199) >> 12);
        }
        wanwan->mUnk_00.mPos.x += wanwan->mUnk_00.mUnk_10.x;
        wanwan->mUnk_00.mPos.z += wanwan->mUnk_00.mUnk_10.z;
    }
    if (wanwan->mUnk_00.mStateMachine.mStateFrames >= 0xb4) {
        wanwan->mUnk_00.mStateMachine.mNextState = 0;
        wanwan->mUnk_00.mStateMachine.mNextStateRequested = 1;
    }
}

void EnterWanwanState4(Wanwan *wanwan) {
    wanwan->mUnk_e8 = 0x555;
    wanwan->mUnk_ec = 0x1c2;
    wanwan->mChainObject->mUnk_a8 = 0x599;
}

void func_020dc444(Wanwan *wanwan) {}

void EnterWanwanState5(Wanwan *wanwan) {
    wanwan->mUnk_e8 = 0x555;
    wanwan->mUnk_ec = 0x1c2;
}
