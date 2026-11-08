#include "Main/Unknown/code_02073eb8.h"
#include "Main/Unknown/code_0207b960.h" // PosCurve

#include "ITCM/code_01ffba68.h"
#include "ITCM/code_01ffc000.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_020d50c4.h"
#include "Main/Unknown/unk_02154000.h"
#include "code_02147cd8.h"
#include "Main/Unknown/unk_02165000.h"
#include "Main/Unknown/code_02076cd0.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02042044.h"
#include "Main/Unknown/code_02076000.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "ITCM/code_01ffdee4.h"
#include "Main/Unknown/code_02040de0.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_0208d978.h"
#include "Main/Unknown/code_020f36d8.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020d3dbc.h"
#include "Main/Unknown/unk_02170000.h"
#include "code_02010c84.h"
#include "Main/Unknown/code_0203c5f8.h"

MtxFx43 *GetProjectionMatrix(void) {
    return (MtxFx43 *) data_0217acc0;
}

static inline s32 func_020760ec_inline(Vec3 *src, Vec3 *dst) {
    if ((s64) src->x * src->x + (s64) src->y * src->y + (s64) src->z * src->z < 0x10) {
        return 0;
    }
    return Vec3NormalizeAndGetLengthUnchecked(src, dst);
}

static inline void func_02076528_inline(Vec3 *vec, s32 scale) {
    vec->x = ((s64) vec->x * scale) >> 12;
    vec->y = ((s64) vec->y * scale) >> 12;
    vec->z = ((s64) vec->z * scale) >> 12;
}

// b selects the far plane: non-zero uses the second far value (mUnk_08c).
void ApplyCameraFrustum(Camera *camera, s32 useSecondFar) {
    s32 farPlane;

    if (useSecondFar != 0) {
        farPlane = camera->mUnk_08c;
    } else {
        farPlane = camera->mFar;
    }
    G3i_FrustumW_(camera->mFrustumTop, camera->mFrustumBottom, camera->mFrustumLeft, camera->mFrustumRight,
                  camera->mNear, farPlane, 0x1000, 0, &data_usa_02170284);
    data_0217029c.mFlag &= ~0x50;
}

void ApplyCameraLookAt(Camera *camera) {
    Vec3 *viewPos = &camera->mViewPos;
    Vec3 *viewLookAt = &camera->mViewLookAt;

    data_021704dc[0] = *viewPos;
    data_021704dc[1] = *(Vec3 *) camera;
    data_021704dc[2] = *viewLookAt;
    G3i_LookAt_(viewPos, (Vec3 *) camera, viewLookAt, 0, &data_usa_021702c8);
    data_0217029c.mFlag &= ~0xe8;
}

// Chase camera only: sets up the camera, then puts it behind the selected Kart.
void SetupCameraBehindKart(void) {
    Kart *kart;
    Camera *chaseCamera;
    Vec3 axes[3];
    Vec3 offset;
    s32 behindDistance;

    kart = GetKart(gRaceSetup->mEntryIndex);
    SetupCamera(gChaseCamera);
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        if (gRaceSetup->mUnk_044 & 0x20) {
            gChaseCamera->mFollowDirectionSign = -0x1000;
        }
    }
    chaseCamera = gChaseCamera;
    Matrix3x3FromQuaternion(&axes, &kart->mUnk_e0);
    behindDistance = ((s64) -gDefaultFollowDistance * chaseCamera->mFollowDirectionSign + 0x800) >> 12;
    offset.x = ((s64) axes[2].x * behindDistance) >> 12;
    offset.y = ((s64) axes[2].y * behindDistance) >> 12;
    offset.z = ((s64) axes[2].z * behindDistance) >> 12;
    VEC_Add(&kart->mPos, &offset, &chaseCamera->mPos);
    chaseCamera->mPos.y = chaseCamera->mPos.y + gFollowHeight;
    chaseCamera->mBaseUp = data_usa_02154fc4;
    chaseCamera->mPrevPos = chaseCamera->mPos;
    chaseCamera->mKartMoveScale = 0x1000;
    gChaseCamera->mHeightHold = 0;
    UpdateViewFrustum((Unk020d4f94 *) &chaseCamera->mViewMatrix);
    RequestViewTestRefresh();
    gChaseCamera->mLookAt.y = kart->mPos.y + gChaseCamera->mLookAtHeight;
}

void UpdateChaseCamera(Camera *camera, Kart *kart) {
    Vec3 kartPos = kart->mPos;
    Vec3 g;
    Vec3 kartMovement;
    Vec3 kartUp;
    Vec3 forward;
    Vec3 targetUp;
    Vec3 upStep;
    s32 scaledHopHeight;
    s32 fovEaseRate;
    s32 t;
    s32 kartOffsetScale;
    Vec3 *p;

    scaledHopHeight = ((s64) kart->mHopHeight * 0xcd0) >> 12;
    if (camera->mUnk_258 == FALSE) {
        camera->mPrevPos = camera->mPos;
    }
    if (kart->mUnk_4c & KART_4C_HEADING_SWING) {
        forward = camera->mSavedKartForward;
        func_02076528_inline(&forward, camera->mFollowDirectionSign);
    } else {
        GetKartForward(kart, &forward);
        func_02076528_inline(&forward, camera->mFollowDirectionSign);
    }
    if (kart->mUnk_7c & 0x20) {
        if (IsWaterPresent() == FALSE) {
            return;
        }
        t = GetHeightAboveWater(camera->mPos.y - 0x5000);
        if (t < 0) {
            camera->mViewPosYOffset = -t;
        } else {
            camera->mViewPosYOffset = 0;
        }
        return;
    }
    VEC_Subtract(&kart->mPos, &kart->mPrevPos, &kartMovement);
    fovEaseRate = 0x19a;
    if (camera->mHalfFovAngle > camera->mHalfFovAngleGoal) {
        fovEaseRate = 0xcd;
    }
    t = camera->mHalfFovAngleGoal - camera->mHalfFovAngle;
    camera->mHalfFovAngle = camera->mHalfFovAngle + (s32) (((s64) t * fovEaseRate + 0x800) >> 12);
    camera->mHalfFovPairFirst = gPairsByAngle[((u16) camera->mHalfFovAngle >> 4) * 2];
    camera->mHalfFovPairSecond = gPairsByAngle[((u16) camera->mHalfFovAngle >> 4) * 2 + 1];
    if (kart->mUnk_48 & 0x10000) {
        camera->mFollowDistanceScale =
            camera->mFollowDistanceScale + (s32) (((s64) (0x14cd - camera->mFollowDistanceScale) * 0xcd + 0x800) >> 12);
    } else {
        camera->mFollowDistanceScale = camera->mFollowDistanceScale +
                                       (s32) (((s64) (0x1000 - camera->mFollowDistanceScale) * 0x19a + 0x800) >> 12);
    }
    kartMovement.y = 0;
    GetKartUp(kart, &kartUp);
    UpdateChaseCameraLookAt(&camera->mLookAt, &camera->mUnk_0b4, &camera->mLookAtLowering, kart, scaledHopHeight,
                            camera->mLookAtHeight);
    kartPos.y = kartPos.y - scaledHopHeight;
    g = kartPos;
    UpdateChaseCameraPosGoalYOffset(camera, kart, &forward);
    UpdateChaseCameraPos(&camera->mPos, &camera->mUnk_0a8, camera, kart, &g, &forward,
                         ((s64) camera->mCollisionOffsetLength * 0x3000) >> 12);
    if (IsWaterPresent() != FALSE) {
        t = GetHeightAboveWater(camera->mPos.y - 0x5000);
        if (t < 0) {
            camera->mViewPosYOffset = -t;
        } else {
            camera->mViewPosYOffset = 0;
        }
    }
    UpdateChaseCameraCollision(camera, kart, &forward);
    p = &kart->mUnk_120;
    t = 0;
    if (kart->mUnk_44 & KART_44_DRIFTING) {
        t = data_usa_021656c4;
        if (kart->mTurnDirection > 0) {
            t *= -1;
        }
    }
    camera->mPosGoalKartOffsetScale =
        camera->mPosGoalKartOffsetScale + (s32) (((s64) (t - camera->mPosGoalKartOffsetScale) * 0xcd + 0x800) >> 12);
    kartOffsetScale = camera->mPosGoalKartOffsetScale;
    camera->mPosGoalKartOffset.x = ((s64) p->x * kartOffsetScale) >> 12;
    camera->mPosGoalKartOffset.y = ((s64) p->y * kartOffsetScale) >> 12;
    camera->mPosGoalKartOffset.z = ((s64) p->z * kartOffsetScale) >> 12;
    if (kart->mUnk_48 & 0x40000000) {
        GetKartUp(kart, &targetUp);
    } else {
        targetUp = data_usa_02154fc4;
    }
    VEC_Subtract(&targetUp, &camera->mBaseUp, &upStep);
    upStep.x = ((s64) upStep.x * 0x800) >> 12;
    upStep.y = ((s64) upStep.y * 0x800) >> 12;
    upStep.z = ((s64) upStep.z * 0x800) >> 12;
    VEC_Add(&camera->mBaseUp, &upStep, &camera->mBaseUp);
    if (camera->mHeightHold != 0) {
        camera->mLookAtHeight = camera->mLookAtHeight - 0x1000;
        if (camera->mLookAtHeight < 0x5000) {
            camera->mLookAtHeight = 0x5000;
        }
        if (camera->mHeldHeightEasing == FALSE && kart->mPos.y > camera->mHeldHeight) {
            camera->mHeldHeightEasing = TRUE;
        }
    } else if (camera->mLookAtHeight < gDefaultLookAtHeight) {
        camera->mLookAtHeight = camera->mLookAtHeight + 0x1000;
    } else {
        camera->mLookAtHeight = gDefaultLookAtHeight;
    }
    UpdateCameraWobble(camera);
}

void UpdateChaseCameraCollision(Camera *camera, Kart *kart, Vec3 *forward) {
    Vec3 pushOut = data_usa_02154fdc;
    Vec3 w;
    Vec3 x;
    Vec3 y;
    Vec3 z;
    Vec3 t;
    u32 j;
    BOOL m = FALSE;
    s32 k;
    s32 l;

    data_usa_0217ac80 = 0;
    camera->mUnk_258 = FALSE;
    if (func_01ffdee4(&camera->mPos, (u32 *) &camera->mPrevPos, 0, data_usa_021656c0, 2, -2, &pushOut, &w, (s32 *) &x,
                      &j, NULL, NULL, NULL, NULL) != 0 &&
        (j & 0xc00) == 0) {
        if (j & 0x214300) {
            y = kart->mTurnedForward;
            if (kart->mForwardSpeed <= 0) {
                y.x = -y.x;
                y.y = -y.y;
                y.z = -y.z;
                k = func_020760ec_inline(&pushOut, &z);
                if (k != 0) {
                    if (Vec3DotUnrounded(&z, &x) < 0xf5c) {
                        if (Vec3DotUnrounded(&z, forward) > 0xb5c) {
                            camera->mUnk_254 = 1;
                        }
                    }
                }
            }
            camera->mUnk_258 = TRUE;
            k = Vec3DotUnrounded(&y, &x);
            m = TRUE;
            l = camera->mUnk_254;
            if (l == 1 || (l == 3 && k < -0xd9a && Vec3DotUnrounded(&y, forward) < 0)) {
                if (x.y < -0xe66) {
                    camera->mUnk_254 = 3;
                    m = FALSE;
                    camera->mUnk_258 = FALSE;
                } else {
                    camera->mCollisionOffsetLengthGoal = VEC_Mag(&pushOut);
                    camera->mUnk_254 = 1;
                }
            } else if (Vec3DotUnrounded(forward, &x) > 0) {
                camera->mUnk_254 = 0;
            } else {
                camera->mUnk_25c = TRUE;
                m = FALSE;
            }
        } else if (j & 0x1e34ef) {
            if (gRaceSetup->mMode != MODE_BATTLE || VEC_DotProduct(&data_usa_02154fc4, &w) < 0xfae ||
                camera->mPos.y - kart->mPos.y < gFollowHeight) {
                VEC_Add(&pushOut, &camera->mPos, &camera->mPos);
            }
        }
    }
    if (camera->mUnk_258 == FALSE) {
        camera->mUnk_25c = FALSE;
    }
    if (m != FALSE && camera->mUnk_25c == FALSE) {
        if (camera->mUnk_254 == 0) {
            k = (s32) (((s64) (0x1000 - kart->mVelocityLengthRatio) * 0x5000) >> 12) + 0x3000;
            pushOut.x = ((s64) pushOut.x * k) >> 12;
            pushOut.y = ((s64) pushOut.y * k) >> 12;
            pushOut.z = ((s64) pushOut.z * k) >> 12;
            camera->mPosGoalCollisionOffset = pushOut;
            camera->mCollisionOffsetLengthGoal = 0;
        }
    } else {
        camera->mCollisionOffsetLengthGoal = 0;
        VEC_Subtract(&pushOut, &camera->mPosGoalCollisionOffset, &t);
        t.x = ((s64) t.x * 0x4cd) >> 12;
        t.y = ((s64) t.y * 0x4cd) >> 12;
        t.z = ((s64) t.z * 0x4cd) >> 12;
        VEC_Add(&camera->mPosGoalCollisionOffset, &t, &camera->mPosGoalCollisionOffset);
        camera->mUnk_254 = 3;
    }
    camera->mCollisionOffsetLength =
        camera->mCollisionOffsetLength +
        (s32) (((s64) (camera->mCollisionOffsetLengthGoal - camera->mCollisionOffsetLength) * 0x11f + 0x800) >> 12);
}

void UpdateChaseCameraPosGoalYOffset(Camera *camera, Kart *kart, Vec3 *forward) {
    s32 e = -0x2d000;
    s32 j;
    s32 goalYOffset = 0;
    s32 easeRate = 0x11f;
    u32 d = kart->mUnk_48;
    s32 forwardY;

    if (d & 0x10000) {
        e = -0x3c000;
    }
    if (kart->mUnk_3e8 > 0) {
        easeRate = 0x52;
    }
    if ((kart->mUnk_44 & KART_44_ON_GROUND) || (d & 0x10000)) {
        if ((forwardY = forward->y) > 0) {
            goalYOffset = ((s64) forwardY * e) >> 12;
        } else if (forwardY + 0x4cd < 0) {
            goalYOffset = ((s64) forwardY * -0xf000) >> 12;
        }
    }
    if (d & 0x40000000) {
        camera->mPosGoalYOffset =
            camera->mPosGoalYOffset + (s32) (((s64) -camera->mPosGoalYOffset * easeRate + 0x800) >> 12);
        return;
    }
    j = goalYOffset - camera->mPosGoalYOffset;
    camera->mPosGoalYOffset = camera->mPosGoalYOffset + (s32) (((s64) j * easeRate + 0x800) >> 12);
}

void StartEntryCameraKind6Entry(void) {
    Camera *entryCamera = gEntryCamera;
    CourseMapCamera *courseMapCamera;
    RandomState64 *localRandom;

    courseMapCamera = gCourseMap->mFirstKind6Entry;
    if (courseMapCamera == NULL) {
        return;
    }
    entryCamera->mKind6EntryRunning = TRUE;
    entryCamera->mCourseMapCamera = courseMapCamera;
    entryCamera->mFovBlend = 0;
    entryCamera->mHalfFovPairFirst = courseMapCamera->mHalfFovPairFirst;
    entryCamera->mHalfFovPairSecond = courseMapCamera->mHalfFovPairSecond;
    entryCamera->mShakeKind = courseMapCamera->mShakeKind;
    if ((s16) courseMapCamera->mEntryGroupIndex != -1) {
        SetupPosCurve(&entryCamera->mPosCurve, courseMapCamera);
        if (gRaceSetup->mMode == MODE_BATTLE) {
            func_0207bd6c(&entryCamera->mUnk_1d0, courseMapCamera);
        }
    }
    if (IsKartEnded(GetKart(gRaceSetup->mEntryIndex)->mIndex) != 0) {
        localRandom = &gRaceProgress->mLocalRandom;
        localRandom->mValue = localRandom->mMultiplier * localRandom->mValue + localRandom->mIncrement;
    }
    gCameraEntryChanged = 1;
}

// Sets mEntryUpdateHold; with a != 0 and the kind 6 entry still running, also picks the entry at the followed Kart's
// position.
void func_02075d08(s32 hold) {
    CourseMapCamera *courseMapCamera;
    Camera *entryCamera = gEntryCamera;
    RandomState64 *localRandom;
    Vec3 kartPos;
    s32 courseMapCameraIndex;

    if (entryCamera->mCourseMapCamera == NULL) {
        return;
    }
    if (hold != 0 && entryCamera->mCourseMapCamera->mKind != 5 && entryCamera->mCourseMapCamera->mKind != 6) {
        return;
    }
    entryCamera->mEntryUpdateHold = hold;
    if (hold == 0) {
        return;
    }
    if (entryCamera->mKind6EntryRunning == FALSE) {
        return;
    }
    entryCamera->mKind6EntryRunning = FALSE;
    GetKartPos(&kartPos, entryCamera->mFollowedKartIndex);
    courseMapCameraIndex = GetCourseMapCameraIndexAtPos(&kartPos);
    if (courseMapCameraIndex < 0) {
        return;
    }
    courseMapCamera = &gCourseMap->mCameras[(u16) courseMapCameraIndex];
    entryCamera->mCourseMapCamera = courseMapCamera;
    entryCamera->mFovBlend = 0;
    entryCamera->mHalfFovPairFirst = courseMapCamera->mHalfFovPairFirst;
    entryCamera->mHalfFovPairSecond = courseMapCamera->mHalfFovPairSecond;
    entryCamera->mShakeKind = courseMapCamera->mShakeKind;
    if ((s16) courseMapCamera->mEntryGroupIndex != -1) {
        SetupPosCurve(&entryCamera->mPosCurve, courseMapCamera);
        if (gRaceSetup->mMode == MODE_BATTLE) {
            func_0207bd6c(&entryCamera->mUnk_1d0, courseMapCamera);
        }
    }
    if (IsKartEnded(GetKart(gRaceSetup->mEntryIndex)->mIndex) != 0) {
        localRandom = &gRaceProgress->mLocalRandom;
        localRandom->mValue = localRandom->mMultiplier * localRandom->mValue + localRandom->mIncrement;
    }
    gCameraEntryChanged = 1;
}

u32 DisableEntryCameraUpdate(void) {
    u32 value0;
    u32 disabled;
    value0 = (u32) &gEntryCamera;
    disabled = 1u;
    value0 = *(const u32 *) ((value0) + (0));
    *(u32 *) ((value0) + (564)) = disabled;
    return value0;
}

static inline void func_02074b00_inline(Vec3 *v, const Vec3 *u, s32 s) {
    v->x = ((s64) u->x * s) >> 12;
    v->y = ((s64) u->y * s) >> 12;
    v->z = ((s64) u->z * s) >> 12;
}

BOOL TryUpdateEntryCamera(Camera *camera) {
    BOOL r = TRUE;
    CourseMapCamera *courseMapCamera;
    Vec3 kartPos;
    s32 courseMapCameraIndex;

    camera->mPrevPos = camera->mPos;
    gEntryCameraUpdateRan = 1;
    if (gRaceSetup->mRaceKind == RACE_KIND_STAFF_ROLL) {
        UpdateStaffRollCameraAndLight(camera);
        return TRUE;
    }
    if (camera->mEntryUpdateHold != 0 || camera->mEntryUpdateDisabled != FALSE) {
        return FALSE;
    }
    camera->mPrevPos = camera->mPos;
    if (camera->mKind8EntryRunning != FALSE) {
        UpdateCameraAngleEntry(camera);
        return TRUE;
    }
    GetKartPos(&kartPos, camera->mFollowedKartIndex);
    courseMapCameraIndex = GetCourseMapCameraIndexAtPos(&kartPos);
    if (camera->mKind6EntryRunning != FALSE) {
        if (gRaceSetup->mMode == MODE_BATTLE) {
            UpdateCameraByEntryKind(camera);
            return TRUE;
        }
        camera->mKind6EntryFrames = camera->mKind6EntryFrames + 1;
        if (camera->mKind6EntryFrames >= 300) {
            camera->mKind6EntryRunning = FALSE;
        }
    }
    if (courseMapCameraIndex == -1) {
        r = FALSE;
    } else {
        RandomState64 *localRandom;

        courseMapCamera = gCourseMap->mCameras + (u16) courseMapCameraIndex;
        if (courseMapCameraIndex != camera->mLastCourseMapCameraIndex) {
            camera->mLastCourseMapCameraIndex = courseMapCameraIndex;
            if (camera->mKind6EntryRunning == FALSE) {
                camera->mCourseMapCamera = courseMapCamera;
                camera->mFovBlend = 0;
                camera->mHalfFovPairFirst = courseMapCamera->mHalfFovPairFirst;
                camera->mHalfFovPairSecond = courseMapCamera->mHalfFovPairSecond;
                camera->mShakeKind = courseMapCamera->mShakeKind;
                if ((s16) courseMapCamera->mEntryGroupIndex != -1) {
                    SetupPosCurve(&camera->mPosCurve, courseMapCamera);
                    if (gRaceSetup->mMode == MODE_BATTLE) {
                        func_0207bd6c(&camera->mUnk_1d0, courseMapCamera);
                    }
                }
                if (IsKartEnded(GetKart(gRaceSetup->mEntryIndex)->mIndex) != 0) {
                    localRandom = &gRaceProgress->mLocalRandom;
                    localRandom->mValue = localRandom->mMultiplier * localRandom->mValue + localRandom->mIncrement;
                }
                gCameraEntryChanged = 1;
            }
        }
        UpdateCameraByEntryKind(camera);
    }
    return r;
}

void UpdateCameraByEntryKind(Camera *camera) {
    CourseMapCamera *courseMapCamera;
    s32 secondOffset;
    switch (camera->mCourseMapCamera->mKind) {
        case 0:
            camera->mPos = camera->mCourseMapCamera->mUnk_00;
            if (gRaceSetup->mRaceKind == RACE_KIND_AWARD) {
                camera->mFollowedKartIndex = (camera->mCourseMapCamera->mUnk_24.z >> 12) - 1;
                GetKartPos(&camera->mLookAt, camera->mFollowedKartIndex);
                camera->mLookAt.y = camera->mLookAt.y + camera->mCourseMapCamera->mUnk_18.y;
            } else {
                GetKartPos(&camera->mLookAt, camera->mFollowedKartIndex);
                camera->mLookAt.y = camera->mLookAt.y + 0x6000;
            }
            UpdateCameraView(camera);
            break;
        case 1:
            UpdateCameraPosCurveLookAtKart(camera);
            break;
        case 5:
        case 6:
            UpdateCameraAngleEntry(camera);
            break;
        case 2:
            camera->mPos = camera->mCourseMapCamera->mUnk_00;
            UpdateCameraLookAtBlend(camera);
            UpdateCameraViewWithWorldUp(camera);
            break;
        case 3:
            UpdateCameraPosCurveLookAtBlend(camera);
            break;
    }
    courseMapCamera = camera->mCourseMapCamera;
    if (courseMapCamera->mFovBlendPerFrame != 0) {
        enum { K0 } t = camera->mFovBlend;
        CourseMapCamera *q = courseMapCamera;

        s32 firstStart = q->mHalfFovPairFirst;
        s32 secondStart = q->mHalfFovPairSecond;
        s32 secondEnd = q->mHalfFovPairSecondEnd;
        s32 firstEnd = q->mHalfFovPairFirstEnd;
        s32 firstDelta = firstEnd - firstStart;
        s32 secondDelta = secondEnd - secondStart;

        secondOffset = ((s64) secondDelta * t) >> 12;
        camera->mHalfFovPairFirst = firstStart + (s32) (((s64) firstDelta * t) >> 12);
        camera->mHalfFovPairSecond = secondStart + secondOffset;
        camera->mFovBlend += q->mFovBlendPerFrame;
        if (camera->mFovBlend > 0x1000) {
            camera->mFovBlend = 0x1000;
        }
    } else {
        camera->mHalfFovPairFirst = courseMapCamera->mHalfFovPairFirst;
        camera->mHalfFovPairSecond = courseMapCamera->mHalfFovPairSecond;
    }
}

void StartEntryCameraKind8Entry(void) {
    Camera *entryCamera;
    CourseMapCamera *courseMapCamera;
    RandomState64 *localRandom;

    entryCamera = gEntryCamera;
    courseMapCamera = gCourseMap->mFirstKind8EntryInMode4;

    if (courseMapCamera == NULL) {
        return;
    }
    entryCamera->mKind8EntryRunning = TRUE;
    entryCamera->mCourseMapCamera = courseMapCamera;
    entryCamera->mFovBlend = 0;
    entryCamera->mHalfFovPairFirst = courseMapCamera->mHalfFovPairFirst;
    entryCamera->mHalfFovPairSecond = courseMapCamera->mHalfFovPairSecond;
    entryCamera->mShakeKind = courseMapCamera->mShakeKind;
    if ((s16) courseMapCamera->mEntryGroupIndex != -1) {
        SetupPosCurve(&entryCamera->mPosCurve, courseMapCamera);
        if (gRaceSetup->mMode == MODE_BATTLE) {
            func_0207bd6c(&entryCamera->mUnk_1d0, courseMapCamera);
        }
    }
    if (IsKartEnded(GetKart(gRaceSetup->mEntryIndex)->mIndex) != 0) {
        localRandom = &gRaceProgress->mLocalRandom;
        localRandom->mValue = localRandom->mMultiplier * localRandom->mValue + localRandom->mIncrement;
    }
    gCameraEntryChanged = 1;
}

static inline void func_02075424_inline(Camera *camera) {
    CourseMapCamera *nextCourseMapCamera;

    if (camera->mCourseMapCamera->mNextIndex == -1) {
        nextCourseMapCamera = NULL;
    } else {
        nextCourseMapCamera = gCourseMap->mCameras + (u16) camera->mCourseMapCamera->mNextIndex;
    }
    if (nextCourseMapCamera == NULL) {
        gRaceProgress->mCameraChainEnded = 1;
        return;
    }
    camera->mCourseMapCameraFrames = 0;
    camera->mCourseMapCamera = nextCourseMapCamera;
    camera->mLookAtBlend = 0;
    camera->mFovBlend = 0;
    if ((s16) nextCourseMapCamera->mEntryGroupIndex != -1) {
        SetupPosCurve(&camera->mPosCurve, nextCourseMapCamera);
    }
    if (gRaceSetup->mRaceKind == RACE_KIND_AWARD) {
        func_0208e808(nextCourseMapCamera->mShakeKind != 0);
    }
    gCameraEntryChanged = 1;
}

MtxFx43 *UpdateChainCameraPair(void) {
    if (gSecondChainCamera->mCourseMapCamera != NULL) {
        if (gSecondChainCamera->mCourseMapCamera->mKind == 4) {
            gFirstChainCamera->mFrustumShift = 1;
            gSecondChainCamera->mFrustumShift = 2;
        } else {
            gSecondChainCamera->mFrustumShift = 0;
            gFirstChainCamera->mFrustumShift = gSecondChainCamera->mFrustumShift;
        }
    }
    UpdateCameraEntry(gFirstChainCamera);
    if (gSecondChainCamera->mFrustumShift == 2) {
        gSecondChainCamera->mHalfFovPairFirst = gFirstChainCamera->mHalfFovPairFirst;
        gSecondChainCamera->mHalfFovPairSecond = gFirstChainCamera->mHalfFovPairSecond;
        gSecondChainCamera->mPos = gFirstChainCamera->mPos;
        gSecondChainCamera->mLookAt = gFirstChainCamera->mLookAt;
    } else {
        UpdateCameraEntry(gSecondChainCamera);
    }
    if (GetRaceUpdateFramesMod2() == 0) {
        UpdateCameraView(gFirstChainCamera);
        gCurrentChainCamera = gFirstChainCamera;
        return &gFirstChainCamera->mViewMatrix;
    }
    UpdateCameraView(gSecondChainCamera);
    gCurrentChainCamera = gSecondChainCamera;
    return &gSecondChainCamera->mViewMatrix;
}

MtxFx43 *UpdateFirstChainCamera(void) {
    UpdateCameraEntry(gFirstChainCamera);
    UpdateCameraView(gFirstChainCamera);
    gCurrentChainCamera = gFirstChainCamera;
    return &gFirstChainCamera->mViewMatrix;
}

void UpdateCameraEntry(Camera *camera) {
    if (camera->mCourseMapCamera == NULL) {
        return;
    }
    UpdateCameraByEntryKind(camera);
    camera->mCourseMapCameraFrames = camera->mCourseMapCameraFrames + 1;
    if (camera->mCourseMapCameraFrames != camera->mCourseMapCamera->mFrameCount) {
        return;
    }
    func_02075424_inline(camera);
    if (camera->mCourseMapCamera == NULL) {
        return;
    }
    if (camera != gFirstChainCamera) {
        return;
    }
    if (camera->mFrustumShift != 1) {
        return;
    }
    func_02075424_inline(gSecondChainCamera);
}

void UpdateCameraPosCurveLookAtKart(Camera *camera) {
    UpdateCameraPosCurve(camera, camera->mCourseMapCamera->mPosCurvePerFrame);
    if (gRaceSetup->mRaceKind == RACE_KIND_AWARD) {
        camera->mFollowedKartIndex = (camera->mCourseMapCamera->mUnk_24.z >> 12) - 1;
        GetKartPos(&camera->mLookAt, camera->mFollowedKartIndex);
        camera->mLookAt.y = camera->mLookAt.y + camera->mCourseMapCamera->mUnk_18.y;
    } else {
        GetKartPos(&camera->mLookAt, camera->mFollowedKartIndex);
        camera->mLookAt.y = camera->mLookAt.y + 0x6000;
    }
    UpdateCameraView(camera);
}

void UpdateCameraAngleEntry(Camera *camera) {
    CourseMapCamera *courseMapCamera = camera->mCourseMapCamera;
    Kart *kart;
    Vec3 *v;
    Vec3 a;
    Vec3 d;
    Vec3 t;
    s32 m3[9];
    s32 m2[9];
    s32 m4[9];
    s32 m0[9];
    s32 m6[9];
    s32 m5[9];
    s32 m7[9];
    Vec3 f;
    Vec3 g;
    Vec3 c;
    Vec3 n;
    Vec3 pushOut;
    Vec3 b;
    s32 i;
    s32 j;
    s32 k;
    s32 l;

    if (gRaceSetup->mRaceKind == RACE_KIND_AWARD) {
        camera->mFollowedKartIndex = (courseMapCamera->mUnk_24.z >> 12) - 1;
        GetKartPos(&camera->mLookAt, camera->mFollowedKartIndex);
        camera->mLookAt.y = camera->mLookAt.y + camera->mCourseMapCamera->mUnk_18.y;
    } else {
        GetKartPos(&camera->mLookAt, camera->mFollowedKartIndex);
        camera->mLookAt.y = camera->mLookAt.y + 0x6000;
    }
    kart = GetKart(camera->mFollowedKartIndex);
    a = kart->mUnk_138;
    i = (u16) ((s32) (((s64) courseMapCamera->mUnk_18.x * 0xb60b60b60bLL + 0x80000000LL) >> 32) >> 12);
    j = (u16) ((s32) (((s64) courseMapCamera->mUnk_18.y * 0xb60b60b60bLL + 0x80000000LL) >> 32) >> 12);
    k = (u16) ((s32) (((s64) courseMapCamera->mUnk_24.x * 0xb60b60b60bLL + 0x80000000LL) >> 32) >> 12);
    l = (u16) ((s32) (((s64) courseMapCamera->mUnk_24.y * 0xb60b60b60bLL + 0x80000000LL) >> 32) >> 12);
    MTX_RotAxis33((MtxFx43 *) m0, &kart->mUnk_120, gPairsByAngle[(kart->mHopTiltAngle >> 4) * 2],
                  gPairsByAngle[(kart->mHopTiltAngle >> 4) * 2 + 1]);
    MTX_MultVec33(&a, m0, &a);
    b = a;
    c = b;
    d = b;
    func_02074b00_inline(&n, &d, -courseMapCamera->mUnk_18.z);
    Vec3CrossUnrounded(&data_usa_02154fc4, &a, &f);
    Vec3CrossUnrounded(&c, &f, &g);
    MTX_RotAxis33((MtxFx43 *) m2, &g, gPairsByAngle[(i >> 4) * 2], gPairsByAngle[(i >> 4) * 2 + 1]);
    MTX_RotAxis33((MtxFx43 *) m3, &f, gPairsByAngle[(j >> 4) * 2], gPairsByAngle[(j >> 4) * 2 + 1]);
    MTX_Concat33(m3, m2, m4);
    MTX_MultVec33(&d, m4, &d);
    func_02074b00_inline(&t, &d, courseMapCamera->mUnk_18.z);
    VEC_Add(&camera->mLookAt, &t, &camera->mPos);
    f.x = -f.x;
    f.y = -f.y;
    f.z = -f.z;
    g.x = -g.x;
    g.y = -g.y;
    g.z = -g.z;
    MTX_RotAxis33((MtxFx43 *) m5, &g, gPairsByAngle[(k >> 4) * 2], gPairsByAngle[(k >> 4) * 2 + 1]);
    MTX_RotAxis33((MtxFx43 *) m6, &f, gPairsByAngle[(l >> 4) * 2], gPairsByAngle[(l >> 4) * 2 + 1]);
    MTX_Concat33(m5, m2, m5);
    MTX_Concat33(m6, m3, m6);
    MTX_Concat33(m6, m5, m7);
    MTX_MultVec33(&n, m7, &n);
    VEC_Add(&camera->mPos, &n, &camera->mLookAt);
    camera->mLookAt.y = camera->mLookAt.y - kart->mHopHeight;
    camera->mPos.y = camera->mPos.y - kart->mHopHeight;
    if (gRaceSetup->mMode != MODE_MISSION_RUN && gRaceSetup->mMode != MODE_BATTLE) {
        if (func_01ffdee4(&camera->mPos, (u32 *) &camera->mPrevPos, 0, data_usa_021656c0 >> 1, 2, -2, &pushOut, NULL,
                          NULL, NULL, NULL, NULL, NULL, NULL) != 0) {
            kart = GetKart(camera->mFollowedKartIndex);
            v = &kart->mUnk_120;
            k = VEC_DotProduct(v, &pushOut);
            pushOut.x = ((s64) kart->mUnk_120.x * k) >> 12;
            pushOut.y = ((s64) v->y * k) >> 12;
            pushOut.z = ((s64) v->z * k) >> 12;
            VEC_Add(&pushOut, &camera->mPos, &camera->mPos);
        }
    }
    UpdateCameraView(camera);
}

void UpdateStaffRollCameraAndLight(Camera *camera) {
    Kart *kart = GetKart(camera->mFollowedKartIndex);
    CourseMapCamera *courseMapCamera = camera->mCourseMapCamera;
    Vec3 newPos;
    Vec3 newLookAt;
    Vec3 offset;
    Vec3 lightDirection;
    s32 m[9];

    camera->mUnk_0b4 = camera->mLookAt;
    newLookAt = kart->mPos;
    VEC_MultAdd(courseMapCamera->mUnk_00.z, &kart->mUnk_120, &kart->mPos, &newPos);
    newPos.y = 0x1f4000;
    newLookAt.y = 0x1f4000;
    offset = kart->mUnk_138;
    offset.y = 0;
    if ((s64) offset.x * offset.x + (s64) offset.y * offset.y + (s64) offset.z * offset.z >= 0x10) {
        Vec3NormalizeAndGetLengthUnchecked(&offset, &offset);
    }
    func_02074b00_inline(&offset, &offset, courseMapCamera->mUnk_00.x);
    VEC_Add(&newPos, &offset, &newPos);
    VEC_Add(&newLookAt, &offset, &newLookAt);
    if (GetRaceUpdateFrames() < courseMapCamera->mFrameCount) {
        camera->mLookAt = newLookAt;
        camera->mPos = newPos;
    } else if (camera->mUnk_144 < 0x1000) {
        camera->mLookAt = newLookAt;
        camera->mPos = newPos;
        camera->mUnk_144 = camera->mUnk_144 + 0x52;
        VEC_Subtract(&camera->mPrevPos, &camera->mPos, &camera->mUnk_0a8);
        VEC_Subtract(&camera->mUnk_0b4, &camera->mLookAt, &camera->mUnk_0b4);
        VEC_MultAdd(camera->mUnk_144, &camera->mUnk_0a8, &newPos, &camera->mPos);
        VEC_MultAdd(camera->mUnk_144, &camera->mUnk_0b4, &newLookAt, &camera->mLookAt);
    }
    UpdateCameraView(camera);
    VEC_Subtract(&newPos, &newLookAt, &lightDirection);
    if ((s64) lightDirection.x * lightDirection.x + (s64) lightDirection.y * lightDirection.y +
            (s64) lightDirection.z * lightDirection.z >=
        0x10) {
        Vec3NormalizeAndGetLengthUnchecked(&lightDirection, &lightDirection);
    }
    MTX_RotAxis33((MtxFx43 *) m, &data_usa_02154fc4, gPairsByAngle[(data_usa_021656a0 >> 4) * 2],
                  gPairsByAngle[(data_usa_021656a0 >> 4) * 2 + 1]);
    MTX_MultVec33(&lightDirection, m, &lightDirection);
    lightDirection.x = ((s64) lightDirection.x * 0xfae) >> 12;
    lightDirection.y = ((s64) lightDirection.y * 0xfae) >> 12;
    lightDirection.z = ((s64) lightDirection.z * 0xfae) >> 12;
    SetRaceLightVector(&lightDirection);
    courseMapCamera = camera->mCourseMapCamera;
    if (courseMapCamera->mFovBlendPerFrame != 0) {
        s32 secondOffset;
        enum { K0 } t = camera->mFovBlend;
        s32 firstStart = courseMapCamera->mHalfFovPairFirst;
        s32 secondStart = courseMapCamera->mHalfFovPairSecond;
        s32 secondEnd = courseMapCamera->mHalfFovPairSecondEnd;
        s32 firstEnd = courseMapCamera->mHalfFovPairFirstEnd;
        s32 firstDelta = firstEnd - firstStart;
        s32 secondDelta = secondEnd - secondStart;

        secondOffset = ((s64) secondDelta * t) >> 12;
        camera->mHalfFovPairFirst = firstStart + (s32) (((s64) firstDelta * t) >> 12);
        camera->mHalfFovPairSecond = secondStart + secondOffset;
        camera->mFovBlend += courseMapCamera->mFovBlendPerFrame;
        if (camera->mFovBlend > 0x1000) {
            camera->mFovBlend = 0x1000;
        }
    } else {
        camera->mHalfFovPairFirst = courseMapCamera->mHalfFovPairFirst;
        camera->mHalfFovPairSecond = courseMapCamera->mHalfFovPairSecond;
    }
}

void UpdateCameraPosCurve(Camera *camera, s32 paramPerFrame) {
    CourseMapCamera *courseMapCamera = camera->mCourseMapCamera;
    u16 pointCount = gCourseMap->mEntryGroups[courseMapCamera->mEntryGroupIndex].mEntryCount;
    CourseMapGroupEntry *firstEntry;
    CourseMapGroupEntry *secondEntry;
    Vec3 startPos;
    Vec3 direction;
    Vec3 offset;
    s32 m;

    if (pointCount >= 4) {
        UpdatePosCurve(&camera->mPos, &camera->mPosCurve, courseMapCamera, paramPerFrame);
        return;
    }
    if (pointCount < 2) {
        return;
    }
    firstEntry = GetCourseMapGroupEntry(courseMapCamera->mEntryGroupIndex, 0);
    secondEntry = GetCourseMapGroupEntry(courseMapCamera->mEntryGroupIndex, 1);
    startPos = firstEntry->mPos;
    VEC_Subtract(&secondEntry->mPos, &firstEntry->mPos, &direction);
    if ((s64) direction.x * direction.x + (s64) direction.y * direction.y + (s64) direction.z * direction.z < 0x10) {
        m = 0;
    } else {
        m = Vec3NormalizeAndGetLengthUnchecked(&direction, &direction);
    }
    camera->mPosCurve.mParam += paramPerFrame;
    if (camera->mPosCurve.mParam >= 0x1000) {
        camera->mPosCurve.mParam = 0x1000;
    }
    m = ((s64) camera->mPosCurve.mParam * m) >> 12;
    offset.x = ((s64) direction.x * m) >> 12;
    offset.y = ((s64) direction.y * m) >> 12;
    offset.z = ((s64) direction.z * m) >> 12;
    VEC_Add(&startPos, &offset, &camera->mPos);
}

void UpdateCameraPosCurveLookAtBlend(Camera *camera) {
    UpdateCameraPosCurve(camera, camera->mCourseMapCamera->mPosCurvePerFrame);
    UpdateCameraLookAtBlend(camera);
    UpdateCameraViewWithWorldUp(camera);
}

void UpdateCameraLookAtBlend(Camera *camera) {
    CourseMapCamera *courseMapCamera = camera->mCourseMapCamera;
    s32 startX, startY, startZ;
    s32 deltaX, deltaY, deltaZ;
    s32 scaledDeltaX, scaledDeltaY, scaledDeltaZ;
    s64 blend;

    if (courseMapCamera->mLookAtBlendPerFrame != 0) {
        blend = camera->mLookAtBlend;
        startX = courseMapCamera->mUnk_18.x;
        deltaX = courseMapCamera->mUnk_24.x - startX;
        scaledDeltaX = (deltaX * blend) >> 12;
        startY = courseMapCamera->mUnk_18.y;
        deltaY = courseMapCamera->mUnk_24.y - startY;
        scaledDeltaY = (deltaY * blend) >> 12;
        startZ = courseMapCamera->mUnk_18.z;
        deltaZ = courseMapCamera->mUnk_24.z - startZ;
        scaledDeltaZ = (deltaZ * blend) >> 12;
        camera->mLookAt.x = startX + scaledDeltaX;
        camera->mLookAt.y = startY + scaledDeltaY;
        camera->mLookAt.z = startZ + scaledDeltaZ;
        camera->mLookAtBlend += courseMapCamera->mLookAtBlendPerFrame;
        if (camera->mLookAtBlend > 0x1000) {
            camera->mLookAtBlend = 0x1000;
        }
    } else {
        camera->mLookAt.x = courseMapCamera->mUnk_18.x;
        camera->mLookAt.y = courseMapCamera->mUnk_18.y;
        camera->mLookAt.z = courseMapCamera->mUnk_18.z;
    }
}

Camera *GetChaseCamera(void) {
    return gChaseCamera;
}

Camera *GetEntryCamera(void) {
    return gEntryCamera;
}

Camera *GetCurrentChainCamera(void) {
    return gCurrentChainCamera;
}

// Chase camera (gChaseCamera) only.
void SetCameraHalfFovAngleGoal(u32 halfFovAngleGoal) {
    gChaseCamera->mHalfFovAngleGoal = halfFovAngleGoal;
}

// Chase camera (gChaseCamera) only.
void ResetCameraHalfFovAngleGoal(void) {
    u32 value0;
    u32 value1;
    value1 = (u32) &gDefaultHalfFovAngle;
    value1 = *(const u16 *) ((value1) + (0));
    gChaseCamera->mHalfFovAngleGoal = value1;
}

// Chase camera only: resets the field-of-view angle goal to its default and the angle to default + 5.
void ResetCameraHalfFovAngle(void) {
    s32 defaultHalfFovAngle;

    defaultHalfFovAngle = gDefaultHalfFovAngle;
    gChaseCamera->mHalfFovAngleGoal = defaultHalfFovAngle;
    gChaseCamera->mHalfFovAngle = defaultHalfFovAngle + 5;
}

// Chase camera (gChaseCamera) only.
void SetCameraHeightHold(s32 hold) {
    gChaseCamera->mHeightHold = hold;
    if (hold == 0) {
        return;
    }
    gChaseCamera->mHeldHeight = gChaseCamera->mPos.y;
    gChaseCamera->mHeldHeightEasing = FALSE;
}

void UpdateChaseCameraLookAt(Vec3 *lookAt, Vec3 *lookAtOffset, s32 *lookAtLowering, Kart *kart, s32 scaledHopHeight,
                             s32 lookAtHeight) {
    Vec3 lookAtGoal;
    Vec3 v10;
    Vec3 offsetGoal;
    Vec3 offsetStep;
    s32 t;

    lookAtGoal = kart->mPos;
    v10 = kart->mPos;
    v10.y = v10.y - scaledHopHeight;
    VEC_MultAdd(lookAtHeight, &kart->mUnk_12c, &v10, &v10);
    lookAtGoal.y = lookAtGoal.y + (lookAtHeight - scaledHopHeight);
    if (!(kart->mUnk_48 & 0x40000000)) {
        offsetGoal = data_usa_02154fdc;
    } else {
        VEC_Subtract(&v10, &lookAtGoal, &offsetGoal);
        VEC_MultAdd(0xa000, &kart->mUnk_12c, &offsetGoal, &offsetGoal);
    }
    VEC_Subtract(&offsetGoal, lookAtOffset, &offsetStep);
    offsetStep.x = ((s64) offsetStep.x * 0x266) >> 12;
    offsetStep.y = ((s64) offsetStep.y * 0x266) >> 12;
    offsetStep.z = ((s64) offsetStep.z * 0x266) >> 12;
    VEC_Add(lookAtOffset, &offsetStep, lookAtOffset);
    VEC_Add(&lookAtGoal, lookAtOffset, &lookAtGoal);
    lookAt->x = lookAtGoal.x;
    lookAt->z = lookAtGoal.z;
    if (kart->mUnk_48 & 0x10000) {
        *lookAtLowering = *lookAtLowering + 0x1000;
        if (*lookAtLowering > 0xa000) {
            *lookAtLowering = 0xa000;
        }
    } else {
        t = *lookAtLowering;
        *lookAtLowering = t + (s32) (((s64) -t * 0x29 + 0x800) >> 12);
    }
    lookAtGoal.y = lookAtGoal.y - *lookAtLowering;
    t = lookAt->y;
    lookAt->y = t + (s32) (((s64) (lookAtGoal.y - t) * 0xccd + 0x800) >> 12);
}

void UpdateChaseCameraPos(Vec3 *pos, Vec3 *posOffset, Camera *camera, Kart *kart, Vec3 *kartPos, const Vec3 *forward,
                          s32 collisionShorten) {
    Vec3 kartMovement;
    Vec3 kartUp;
    Vec3 forwardCopy;
    Vec3 v28;
    Vec3 v34;
    Vec3 posGoal;
    Vec3 v2;
    Vec3 v58;
    Vec3 v64;
    Vec3 v70;
    Vec3 v3;
    Vec3 offsetGoal;
    Vec3 offsetStep;
    s32 followDistance;
    s32 i;
    s32 j;
    s32 k;

    forwardCopy = *forward;
    followDistance = camera->mFollowDistance - collisionShorten;
    GetKartUp(kart, &kartUp);
    if (followDistance < 500) {
        followDistance = 500;
    }
    VEC_Subtract(&kart->mPos, &kart->mPrevPos, &kartMovement);
    if (kart->mUnk_48 & 0x1000) {
        if (kart->mUnk_4c & 0x4000000) {
            return;
        }
        camera->mKartMoveScale = ((s64) camera->mKartMoveScale * 0xe66) >> 12;
        VEC_MultAdd(camera->mKartMoveScale, &kartMovement, pos, pos);
        return;
    }
    kartMovement.y = 0;
    VEC_Add(pos, &kartMovement, pos);
    i = -followDistance;
    v2.x = ((s64) forwardCopy.x * i) >> 12;
    v2.y = ((s64) forwardCopy.y * i) >> 12;
    v2.z = ((s64) forwardCopy.z * i) >> 12;
    VEC_Add(&v2, &camera->mPosGoalKartOffset, &v2);
    VEC_Add(&v2, &camera->mPosGoalCollisionOffset, &v2);
    VEC_MultAdd(gFollowHeight, &kartUp, &v2, &v3);
    VEC_Add(kartPos, &v3, &v70);
    v2.y = gFollowHeight;
    VEC_Add(kartPos, &v2, &v64);
    posGoal = v64;
    posGoal.y = posGoal.y + camera->mPosGoalYOffset;
    if (!(kart->mUnk_48 & 0x40000000)) {
        offsetGoal = data_usa_02154fdc;
    } else {
        VEC_Subtract(&v70, &posGoal, &offsetGoal);
        VEC_MultAdd(-0x1e000, &kartUp, &offsetGoal, &offsetGoal);
    }
    VEC_Subtract(&offsetGoal, posOffset, &offsetStep);
    offsetStep.x = ((s64) offsetStep.x * 0x19a) >> 12;
    offsetStep.y = ((s64) offsetStep.y * 0x19a) >> 12;
    offsetStep.z = ((s64) offsetStep.z * 0x19a) >> 12;
    VEC_Add(posOffset, &offsetStep, posOffset);
    VEC_Add(&posGoal, posOffset, &posGoal);
    VEC_Subtract(&posGoal, pos, &v58);
    j = v58.y;
    k = 0;
    v58.y = 0;
    if ((s64) v58.x * v58.x + (s64) v58.y * v58.y + (s64) v58.z * v58.z >= 16) {
        k = Vec3NormalizeAndGetLengthUnchecked(&v58, &v58);
    }
    VEC_MultAdd(((s64) k * 0x11f) >> 12, &v58, pos, pos);
    pos->y = pos->y + ((s32) (((s64) j * 0x11f) >> 9) + collisionShorten * 2);
    if (camera->mHeightHold != 0) {
        if (camera->mHeldHeightEasing != FALSE) {
            s32 l;
            l = pos->y - camera->mHeldHeight;
            camera->mHeldHeight = camera->mHeldHeight + (s32) (((s64) l * 0x29 + 0x800) >> 12);
        }
        pos->y = camera->mHeldHeight;
    }
    VEC_Subtract(pos, kartPos, &v28);
    v34 = v28;
    k = 0;
    if ((s64) v34.x * v34.x + (s64) v34.y * v34.y + (s64) v34.z * v34.z >= 16) {
        k = Vec3NormalizeAndGetLengthUnchecked(&v34, &v34);
    }
    if (k == 0) {
        return;
    }
    VEC_MultAdd(((s64) camera->mFollowDistance * camera->mFollowDistanceScale) >> 12, &v34, kartPos, pos);
}

// Puts the chase camera at a minus mFollowDistance along axis 2 of the matrix b (the kart's).
void ResetCameraBehind(const Vec3 *kartPos, void *quaternion) {
    Camera *chaseCamera;
    Vec3 axes[3];
    Vec3 offset;
    s32 behindDistance;

    chaseCamera = gChaseCamera;
    Matrix3x3FromQuaternion(axes, quaternion);
    behindDistance = ((s64) -gDefaultFollowDistance * chaseCamera->mFollowDirectionSign + 0x800) >> 12;
    offset.x = ((s64) axes[2].x * behindDistance) >> 12;
    offset.y = ((s64) axes[2].y * behindDistance) >> 12;
    offset.z = ((s64) axes[2].z * behindDistance) >> 12;
    VEC_Add(kartPos, &offset, &chaseCamera->mPos);
    chaseCamera->mPos.y = chaseCamera->mPos.y + gFollowHeight;
    chaseCamera->mBaseUp = data_usa_02154fc4;
    chaseCamera->mPrevPos = chaseCamera->mPos;
    chaseCamera->mKartMoveScale = 0x1000;
    gChaseCamera->mHeightHold = 0;
    UpdateViewFrustum((Unk020d4f94 *) &chaseCamera->mViewMatrix);
    RequestViewTestRefresh();
}

// Chase camera (gChaseCamera) only.
void StartCameraWobble(s32 baseAmplitude, u32 distance, s32 scale) {
    Camera *chaseCamera;
    s32 distanceFactor;
    s32 amplitude;

    distanceFactor = 0x1000;
    chaseCamera = gChaseCamera;
    if (distance > 1000000) {
        return;
    }
    if (distance > 0x57e40) {
        distanceFactor = 0x4cd;
    } else if (distance > 0x15f90) {
        distanceFactor = 0x99a;
    }
    amplitude = ((s64) baseAmplitude * (s32) (((s64) scale * distanceFactor) >> 12)) >> 12;
    if (chaseCamera->mWobbling != FALSE && chaseCamera->mWobbleAmplitude > amplitude) {
        return;
    }
    chaseCamera->mWobbleAmplitude = amplitude;
    chaseCamera->mWobbling = TRUE;
    chaseCamera->mUnk_144 = 0;
    chaseCamera->mWobblePerFrame = 0x800;
    chaseCamera->mWobbleDirection = 1;
    chaseCamera->mWobbleDecay = 0xe66;
    chaseCamera->mWobbleOffset = 0;
}

void StartCameraWobbleAtDistance(u32 distance, s32 scale) {
    StartCameraWobble(0x2800, distance, scale);
}

void StartCameraWobbleByCourse(void) {
    StartCameraWobble(gCourseWobbleAmplitude, 0, 0x1000);
}

void UpdateCameraWobble(Camera *camera) {
    s32 t;
    BOOL u;

    if (camera->mWobbling == FALSE) {
        return;
    }
    camera->mUnk_144 = camera->mUnk_144 + camera->mWobblePerFrame * camera->mWobbleDirection;
    t = camera->mUnk_144;
    if (t > 0x1000) {
        camera->mWobbleDirection *= -1;
        camera->mUnk_144 = 0x2000 - camera->mUnk_144;
    } else if (t < -0x1000) {
        camera->mWobbleDirection *= -1;
        camera->mUnk_144 = -0x2000 - camera->mUnk_144;
    }
    camera->mWobbleAmplitude = ((s64) camera->mWobbleAmplitude * camera->mWobbleDecay) >> 12;
    camera->mWobbleAmplitude = camera->mWobbleAmplitude - 0x14;
    camera->mWobbleOffset = ((s64) camera->mUnk_144 * camera->mWobbleAmplitude) >> 12;
    if (camera->mWobbleAmplitude <= 0) {
        u = FALSE;
        camera->mWobbleOffset = u;
        camera->mWobbling = u;
    }
}
