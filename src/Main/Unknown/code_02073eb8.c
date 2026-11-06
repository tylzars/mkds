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

MtxFx43 *func_02076cc4(void) {
    return (MtxFx43 *) data_0217acc0;
}

static inline s32 func_020760ec_inline(Vec3 *v, Vec3 *n) {
    if ((s64) v->x * v->x + (s64) v->y * v->y + (s64) v->z * v->z < 0x10) {
        return 0;
    }
    return Vec3NormalizeAndGetLengthUnchecked(v, n);
}

static inline void func_02076528_inline(Vec3 *v, s32 k) {
    v->x = (s32) (((s64) v->x * k) >> 12);
    v->y = (s32) (((s64) v->y * k) >> 12);
    v->z = (s32) (((s64) v->z * k) >> 12);
}

void func_02076c50(Camera *a, s32 b) {
    s32 c;

    if (b != 0) {
        c = a->mUnk_08c;
    } else {
        c = a->mFar;
    }
    G3i_FrustumW_(a->mFrustumTop, a->mFrustumBottom, a->mFrustumLeft, a->mFrustumRight, a->mNear, c, 0x1000, 0,
                  &data_usa_02170284);
    data_0217029c.mFlag &= ~0x50;
}

void func_02076bcc(Camera *a) {
    Vec3 *b = &a->mViewPos;
    Vec3 *c = &a->mViewLookAt;

    data_021704dc[0] = *b;
    data_021704dc[1] = *(Vec3 *) a;
    data_021704dc[2] = *c;
    G3i_LookAt_(b, (Vec3 *) a, c, 0, &data_usa_021702c8);
    data_0217029c.mFlag &= ~0xe8;
}

// Chase camera (gChaseCamera) only. Runs SetupCamera, then places the camera behind the selected Kart (as
// ResetCameraBehind does) and points the look-at at the Kart.
void SetupCameraBehindKart(void) {
    Kart *q;
    Camera *p;
    Vec3 m[3];
    Vec3 u;
    s32 t;

    q = GetKart(data_021759c0->mEntryIndex);
    SetupCamera(gChaseCamera);
    if (data_021759c0->mMode == MODE_MISSION_RUN) {
        if (data_021759c0->mUnk_044 & 0x20) {
            (gChaseCamera)->mFollowDirectionSign = -0x1000;
        }
    }
    p = gChaseCamera;
    Matrix3x3FromQuaternion(&m, &q->mUnk_e0);
    t = (s32) (((s64) -data_usa_0217ac90 * p->mFollowDirectionSign + 0x800) >> 12);
    u.x = (s32) (((s64) m[2].x * t) >> 12);
    u.y = (s32) (((s64) m[2].y * t) >> 12);
    u.z = (s32) (((s64) m[2].z * t) >> 12);
    VEC_Add(&q->mPos, &u, &p->mPos);
    p->mPos.y = p->mPos.y + data_usa_0217ac7c;
    p->mBaseUp = data_usa_02154fc4;
    p->mPrevPos = p->mPos;
    p->mKartMoveScale = 0x1000;
    (gChaseCamera)->mHeightHold = 0;
    func_020d4f94((Unk020d4f94 *) &p->mViewMatrix);
    func_020d50c4();
    (gChaseCamera)->mLookAt.y = q->mPos.y + (gChaseCamera)->mLookAtHeight;
}

void UpdateChaseCamera(Camera *a, Kart *b) {
    Vec3 v = b->mPos;
    Vec3 g;
    Vec3 w;
    Vec3 z;
    Vec3 u;
    Vec3 q;
    Vec3 r;
    s32 s;
    s32 k;
    s32 t;
    s32 n;
    Vec3 *p;

    s = (s32) (((s64) b->mHopHeight * 0xcd0) >> 12);
    if (a->mUnk_258 == FALSE) {
        a->mPrevPos = a->mPos;
    }
    if (b->mUnk_4c & 0x20000000) {
        u = a->mSavedKartForward;
        func_02076528_inline(&u, a->mFollowDirectionSign);
    } else {
        GetKartForward(b, &u);
        func_02076528_inline(&u, a->mFollowDirectionSign);
    }
    if (b->mUnk_7c & 0x20) {
        if (IsWaterPresent() == FALSE) {
            return;
        }
        t = GetHeightAboveWater(a->mPos.y - 0x5000);
        if (t < 0) {
            a->mViewPosYOffset = -t;
        } else {
            a->mViewPosYOffset = 0;
        }
        return;
    }
    VEC_Subtract(&b->mPos, &b->mPrevPos, &w);
    k = 0x19a;
    if (a->mHalfFovAngle > a->mHalfFovAngleGoal) {
        k = 0xcd;
    }
    t = a->mHalfFovAngleGoal - a->mHalfFovAngle;
    a->mHalfFovAngle = a->mHalfFovAngle + (s32) (((s64) t * k + 0x800) >> 12);
    a->mHalfFovPairFirst = gPairsByAngle[((u16) a->mHalfFovAngle >> 4) * 2];
    a->mHalfFovPairSecond = gPairsByAngle[((u16) a->mHalfFovAngle >> 4) * 2 + 1];
    if (b->mUnk_48 & 0x10000) {
        a->mFollowDistanceScale =
            a->mFollowDistanceScale + (s32) (((s64) (0x14cd - a->mFollowDistanceScale) * 0xcd + 0x800) >> 12);
    } else {
        a->mFollowDistanceScale =
            a->mFollowDistanceScale + (s32) (((s64) (0x1000 - a->mFollowDistanceScale) * 0x19a + 0x800) >> 12);
    }
    w.y = 0;
    GetKartUp(b, &z);
    UpdateChaseCameraLookAt(&a->mLookAt, &a->mUnk_0b4, &a->mLookAtLowering, b, s, a->mLookAtHeight);
    v.y = v.y - s;
    g = v;
    UpdateChaseCameraPosGoalYOffset(a, b, &u);
    UpdateChaseCameraPos(&a->mPos, &a->mUnk_0a8, a, b, &g, &u,
                         (s32) (((s64) a->mCollisionOffsetLength * 0x3000) >> 12));
    if (IsWaterPresent() != FALSE) {
        t = GetHeightAboveWater(a->mPos.y - 0x5000);
        if (t < 0) {
            a->mViewPosYOffset = -t;
        } else {
            a->mViewPosYOffset = 0;
        }
    }
    UpdateChaseCameraCollision(a, b, &u);
    p = &b->mUnk_120;
    t = 0;
    if (b->mUnk_44 & 8) {
        t = data_usa_021656c4;
        if (b->mTurnDirection > 0) {
            t *= -1;
        }
    }
    a->mPosGoalKartOffsetScale =
        a->mPosGoalKartOffsetScale + (s32) (((s64) (t - a->mPosGoalKartOffsetScale) * 0xcd + 0x800) >> 12);
    n = a->mPosGoalKartOffsetScale;
    a->mPosGoalKartOffset.x = (s32) (((s64) p->x * n) >> 12);
    a->mPosGoalKartOffset.y = (s32) (((s64) p->y * n) >> 12);
    a->mPosGoalKartOffset.z = (s32) (((s64) p->z * n) >> 12);
    if (b->mUnk_48 & 0x40000000) {
        GetKartUp(b, &q);
    } else {
        q = data_usa_02154fc4;
    }
    VEC_Subtract(&q, &a->mBaseUp, &r);
    r.x = (s32) (((s64) r.x * 0x800) >> 12);
    r.y = (s32) (((s64) r.y * 0x800) >> 12);
    r.z = (s32) (((s64) r.z * 0x800) >> 12);
    VEC_Add(&a->mBaseUp, &r, &a->mBaseUp);
    if (a->mHeightHold != 0) {
        a->mLookAtHeight = a->mLookAtHeight - 0x1000;
        if (a->mLookAtHeight < 0x5000) {
            a->mLookAtHeight = 0x5000;
        }
        if (a->mHeldHeightEasing == FALSE && b->mPos.y > a->mHeldHeight) {
            a->mHeldHeightEasing = TRUE;
        }
    } else if (a->mLookAtHeight < data_usa_0217ac78) {
        a->mLookAtHeight = a->mLookAtHeight + 0x1000;
    } else {
        a->mLookAtHeight = data_usa_0217ac78;
    }
    UpdateCameraWobble(a);
}

void UpdateChaseCameraCollision(Camera *a, Kart *b, Vec3 *c) {
    Vec3 v = data_usa_02154fdc;
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
    a->mUnk_258 = FALSE;
    if (func_01ffdee4(&a->mPos, (u32 *) &a->mPrevPos, 0, data_usa_021656c0, 2, -2, &v, &w, (s32 *) &x, &j, NULL, NULL,
                      NULL, NULL) != 0 &&
        (j & 0xc00) == 0) {
        if (j & 0x214300) {
            y = b->mUnk_50;
            if (b->mForwardSpeed <= 0) {
                y.x = -y.x;
                y.y = -y.y;
                y.z = -y.z;
                k = func_020760ec_inline(&v, &z);
                if (k != 0) {
                    if (Vec3DotUnrounded(&z, &x) < 0xf5c) {
                        if (Vec3DotUnrounded(&z, c) > 0xb5c) {
                            a->mUnk_254 = 1;
                        }
                    }
                }
            }
            a->mUnk_258 = TRUE;
            k = Vec3DotUnrounded(&y, &x);
            m = TRUE;
            l = a->mUnk_254;
            if (l == 1 || (l == 3 && k < -0xd9a && Vec3DotUnrounded(&y, c) < 0)) {
                if (x.y < -0xe66) {
                    a->mUnk_254 = 3;
                    m = FALSE;
                    a->mUnk_258 = FALSE;
                } else {
                    a->mCollisionOffsetLengthGoal = VEC_Mag(&v);
                    a->mUnk_254 = 1;
                }
            } else if (Vec3DotUnrounded(c, &x) > 0) {
                a->mUnk_254 = 0;
            } else {
                a->mUnk_25c = TRUE;
                m = FALSE;
            }
        } else if (j & 0x1e34ef) {
            if (data_021759c0->mMode != MODE_BATTLE || VEC_DotProduct(&data_usa_02154fc4, &w) < 0xfae ||
                a->mPos.y - b->mPos.y < data_usa_0217ac7c) {
                VEC_Add(&v, &a->mPos, &a->mPos);
            }
        }
    }
    if (a->mUnk_258 == FALSE) {
        a->mUnk_25c = FALSE;
    }
    if (m != FALSE && a->mUnk_25c == FALSE) {
        if (a->mUnk_254 == 0) {
            k = (s32) (((s64) (0x1000 - b->mVelocityLengthRatio) * 0x5000) >> 12) + 0x3000;
            v.x = (s32) (((s64) v.x * k) >> 12);
            v.y = (s32) (((s64) v.y * k) >> 12);
            v.z = (s32) (((s64) v.z * k) >> 12);
            a->mPosGoalCollisionOffset = v;
            a->mCollisionOffsetLengthGoal = 0;
        }
    } else {
        a->mCollisionOffsetLengthGoal = 0;
        VEC_Subtract(&v, &a->mPosGoalCollisionOffset, &t);
        t.x = (s32) (((s64) t.x * 0x4cd) >> 12);
        t.y = (s32) (((s64) t.y * 0x4cd) >> 12);
        t.z = (s32) (((s64) t.z * 0x4cd) >> 12);
        VEC_Add(&a->mPosGoalCollisionOffset, &t, &a->mPosGoalCollisionOffset);
        a->mUnk_254 = 3;
    }
    a->mCollisionOffsetLength =
        a->mCollisionOffsetLength +
        (s32) (((s64) (a->mCollisionOffsetLengthGoal - a->mCollisionOffsetLength) * 0x11f + 0x800) >> 12);
}

void UpdateChaseCameraPosGoalYOffset(Camera *a, Kart *b, Vec3 *c) {
    s32 e = -0x2d000;
    s32 j;
    s32 g = 0;
    s32 f = 0x11f;
    u32 d = b->mUnk_48;
    s32 h;

    if (d & 0x10000) {
        e = -0x3c000;
    }
    if (b->mUnk_3e8 > 0) {
        f = 0x52;
    }
    if ((b->mUnk_44 & 0x10) || (d & 0x10000)) {
        if ((h = c->y) > 0) {
            g = (s32) (((s64) h * e) >> 12);
        } else if (h + 0x4cd < 0) {
            g = (s32) (((s64) h * -0xf000) >> 12);
        }
    }
    if (d & 0x40000000) {
        a->mPosGoalYOffset = a->mPosGoalYOffset + (s32) (((s64) -a->mPosGoalYOffset * f + 0x800) >> 12);
        return;
    }
    j = g - a->mPosGoalYOffset;
    a->mPosGoalYOffset = a->mPosGoalYOffset + (s32) (((s64) j * f + 0x800) >> 12);
}

void StartEntryCameraKind6Entry(void) {
    Camera *p = gEntryCamera;
    CourseMapCamera *q;
    Unk020f41c4_B *r;

    q = gCourseMap->mFirstKind6Entry;
    if (q == NULL) {
        return;
    }
    p->mKind6EntryRunning = TRUE;
    p->mCourseMapCamera = q;
    p->mFovBlend = 0;
    p->mHalfFovPairFirst = q->mHalfFovPairFirst;
    p->mHalfFovPairSecond = q->mHalfFovPairSecond;
    p->mShakeKind = q->mShakeKind;
    if ((s16) q->mEntryGroupIndex != -1) {
        SetupPosCurve(&p->mPosCurve, q);
        if (data_021759c0->mMode == MODE_BATTLE) {
            func_0207bd6c(&p->mUnk_1d0, q);
        }
    }
    if (IsKartEnded(GetKart(data_021759c0->mEntryIndex)->mIndex) != 0) {
        r = &gRaceProgress->mLocalRandom;
        r->mUnk_00 = r->mUnk_08 * r->mUnk_00 + r->mUnk_10;
    }
    gCameraEntryChanged = 1;
}

void func_02075d08(s32 a) {
    CourseMapCamera *q;
    Camera *p = gEntryCamera;
    Unk020f41c4_B *r;
    Vec3 v;
    s32 s;

    if (p->mCourseMapCamera == NULL) {
        return;
    }
    if (a != 0 && p->mCourseMapCamera->mKind != 5 && p->mCourseMapCamera->mKind != 6) {
        return;
    }
    p->mEntryUpdateHold = a;
    if (a == 0) {
        return;
    }
    if (p->mKind6EntryRunning == FALSE) {
        return;
    }
    p->mKind6EntryRunning = FALSE;
    GetKartPos(&v, p->mFollowedKartIndex);
    s = GetCourseMapCameraIndexAtPos(&v);
    if (s < 0) {
        return;
    }
    q = &gCourseMap->mCameras[(u16) s];
    p->mCourseMapCamera = q;
    p->mFovBlend = 0;
    p->mHalfFovPairFirst = q->mHalfFovPairFirst;
    p->mHalfFovPairSecond = q->mHalfFovPairSecond;
    p->mShakeKind = q->mShakeKind;
    if ((s16) q->mEntryGroupIndex != -1) {
        SetupPosCurve(&p->mPosCurve, q);
        if (data_021759c0->mMode == MODE_BATTLE) {
            func_0207bd6c(&p->mUnk_1d0, q);
        }
    }
    if (IsKartEnded(GetKart(data_021759c0->mEntryIndex)->mIndex) != 0) {
        r = &gRaceProgress->mLocalRandom;
        r->mUnk_00 = r->mUnk_08 * r->mUnk_00 + r->mUnk_10;
    }
    gCameraEntryChanged = 1;
}

u32 func_02075cf0(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &gEntryCamera;
    value1 = 1u;
    value0 = (u32) * (const u32 *) ((value0) + (0));
    *(u32 *) ((value0) + (564)) = value1;
    return value0;
}

static inline void func_02074b00_inline(Vec3 *v, const Vec3 *u, s32 s) {
    v->x = (s32) (((s64) u->x * s) >> 12);
    v->y = (s32) (((s64) u->y * s) >> 12);
    v->z = (s32) (((s64) u->z * s) >> 12);
}

BOOL TryUpdateEntryCamera(Camera *p) {
    BOOL r = TRUE;
    CourseMapCamera *q;
    Vec3 v;
    s32 i;

    p->mPrevPos = p->mPos;
    gEntryCameraUpdateRan = 1;
    if (data_021759c0->mUnk_00c == 6) {
        func_02074b00(p);
        return TRUE;
    }
    if (p->mEntryUpdateHold != 0 || p->mEntryUpdateDisabled != FALSE) {
        return FALSE;
    }
    p->mPrevPos = p->mPos;
    if (p->mKind8EntryRunning != FALSE) {
        UpdateCameraAngleEntry(p);
        return TRUE;
    }
    GetKartPos(&v, p->mFollowedKartIndex);
    i = GetCourseMapCameraIndexAtPos(&v);
    if (p->mKind6EntryRunning != FALSE) {
        if (data_021759c0->mMode == MODE_BATTLE) {
            UpdateCameraByEntryKind(p);
            return TRUE;
        }
        p->mKind6EntryFrames = p->mKind6EntryFrames + 1;
        if (p->mKind6EntryFrames >= 300) {
            p->mKind6EntryRunning = FALSE;
        }
    }
    if (i == -1) {
        r = FALSE;
    } else {
        Unk020f41c4_B *b;

        q = gCourseMap->mCameras + (u16) i;
        if (i != p->mLastCourseMapCameraIndex) {
            p->mLastCourseMapCameraIndex = i;
            if (p->mKind6EntryRunning == FALSE) {
                p->mCourseMapCamera = q;
                p->mFovBlend = 0;
                p->mHalfFovPairFirst = q->mHalfFovPairFirst;
                p->mHalfFovPairSecond = q->mHalfFovPairSecond;
                p->mShakeKind = q->mShakeKind;
                if ((s16) q->mEntryGroupIndex != -1) {
                    SetupPosCurve(&p->mPosCurve, q);
                    if (data_021759c0->mMode == MODE_BATTLE) {
                        func_0207bd6c(&p->mUnk_1d0, q);
                    }
                }
                if (IsKartEnded(GetKart(data_021759c0->mEntryIndex)->mIndex) != 0) {
                    b = &gRaceProgress->mLocalRandom;
                    b->mUnk_00 = b->mUnk_08 * b->mUnk_00 + b->mUnk_10;
                }
                gCameraEntryChanged = 1;
            }
        }
        UpdateCameraByEntryKind(p);
    }
    return r;
}

void UpdateCameraByEntryKind(Camera *p) {
    CourseMapCamera *a;
    s32 b;
    switch (p->mCourseMapCamera->mKind) {
        case 0:
            p->mPos = p->mCourseMapCamera->mUnk_00;
            if (data_021759c0->mUnk_00c == 5) {
                p->mFollowedKartIndex = (p->mCourseMapCamera->mUnk_24.z >> 12) - 1;
                GetKartPos(&p->mLookAt, p->mFollowedKartIndex);
                p->mLookAt.y = p->mLookAt.y + p->mCourseMapCamera->mUnk_18.y;
            } else {
                GetKartPos(&p->mLookAt, p->mFollowedKartIndex);
                p->mLookAt.y = p->mLookAt.y + 0x6000;
            }
            UpdateCameraView(p);
            break;
        case 1:
            UpdateCameraPosCurveLookAtKart(p);
            break;
        case 5:
        case 6:
            UpdateCameraAngleEntry(p);
            break;
        case 2:
            p->mPos = p->mCourseMapCamera->mUnk_00;
            UpdateCameraLookAtBlend(p);
            UpdateCameraViewWithWorldUp(p);
            break;
        case 3:
            UpdateCameraPosCurveLookAtBlend(p);
            break;
    }
    a = p->mCourseMapCamera;
    if (a->mFovBlendPerFrame != 0) {
        enum { K0 } t = p->mFovBlend;
        CourseMapCamera *q = a;

        s32 x0 = q->mHalfFovPairFirst;
        s32 y0 = q->mHalfFovPairSecond;
        s32 y1 = q->mHalfFovPairSecondEnd;
        s32 x1 = q->mHalfFovPairFirstEnd;
        s32 v1 = x1 - x0;
        s32 v2 = y1 - y0;

        b = ((s64) v2 * t) >> 12;
        p->mHalfFovPairFirst = x0 + (s32) (((s64) v1 * t) >> 12);
        p->mHalfFovPairSecond = y0 + (s32) b;
        p->mFovBlend += q->mFovBlendPerFrame;
        if (p->mFovBlend > 0x1000) {
            p->mFovBlend = 0x1000;
        }
    } else {
        p->mHalfFovPairFirst = a->mHalfFovPairFirst;
        p->mHalfFovPairSecond = a->mHalfFovPairSecond;
    }
}

void StartEntryCameraKind8Entry(void) {
    Camera *p;
    CourseMapCamera *q;
    Unk020f41c4_B *b;

    p = gEntryCamera;
    q = gCourseMap->mFirstKind8EntryInMode4;

    if (q == NULL) {
        return;
    }
    p->mKind8EntryRunning = TRUE;
    p->mCourseMapCamera = q;
    p->mFovBlend = 0;
    p->mHalfFovPairFirst = q->mHalfFovPairFirst;
    p->mHalfFovPairSecond = q->mHalfFovPairSecond;
    p->mShakeKind = q->mShakeKind;
    if ((s16) q->mEntryGroupIndex != -1) {
        SetupPosCurve(&p->mPosCurve, q);
        if (data_021759c0->mMode == MODE_BATTLE) {
            func_0207bd6c(&p->mUnk_1d0, q);
        }
    }
    if (IsKartEnded(GetKart(data_021759c0->mEntryIndex)->mIndex) != 0) {
        b = &gRaceProgress->mLocalRandom;
        b->mUnk_00 = b->mUnk_08 * b->mUnk_00 + b->mUnk_10;
    }
    gCameraEntryChanged = 1;
}

static inline void func_02075424_inline(Camera *p) {
    CourseMapCamera *q;

    if (p->mCourseMapCamera->mNextIndex == -1) {
        q = NULL;
    } else {
        q = gCourseMap->mCameras + (u16) p->mCourseMapCamera->mNextIndex;
    }
    if (q == NULL) {
        gRaceProgress->mUnk_4d0 = 1;
        return;
    }
    p->mCourseMapCameraFrames = 0;
    p->mCourseMapCamera = q;
    p->mLookAtBlend = 0;
    p->mFovBlend = 0;
    if ((s16) q->mEntryGroupIndex != -1) {
        SetupPosCurve(&p->mPosCurve, q);
    }
    if (data_021759c0->mUnk_00c == 5) {
        func_0208e808(q->mShakeKind != 0);
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

void UpdateCameraEntry(Camera *p) {
    if (p->mCourseMapCamera == NULL) {
        return;
    }
    UpdateCameraByEntryKind(p);
    p->mCourseMapCameraFrames = p->mCourseMapCameraFrames + 1;
    if (p->mCourseMapCameraFrames != p->mCourseMapCamera->mFrameCount) {
        return;
    }
    func_02075424_inline(p);
    if (p->mCourseMapCamera == NULL) {
        return;
    }
    if (p != gFirstChainCamera) {
        return;
    }
    if (p->mFrustumShift != 1) {
        return;
    }
    func_02075424_inline(gSecondChainCamera);
}

void UpdateCameraPosCurveLookAtKart(Camera *p) {
    UpdateCameraPosCurve(p, p->mCourseMapCamera->mPosCurvePerFrame);
    if (data_021759c0->mUnk_00c == 5) {
        p->mFollowedKartIndex = (p->mCourseMapCamera->mUnk_24.z >> 12) - 1;
        GetKartPos(&p->mLookAt, p->mFollowedKartIndex);
        p->mLookAt.y = p->mLookAt.y + p->mCourseMapCamera->mUnk_18.y;
    } else {
        GetKartPos(&p->mLookAt, p->mFollowedKartIndex);
        p->mLookAt.y = p->mLookAt.y + 0x6000;
    }
    UpdateCameraView(p);
}

void UpdateCameraAngleEntry(Camera *p) {
    CourseMapCamera *q = p->mCourseMapCamera;
    Kart *o;
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
    Vec3 w;
    Vec3 b;
    s32 i;
    s32 j;
    s32 k;
    s32 l;

    if (data_021759c0->mUnk_00c == 5) {
        p->mFollowedKartIndex = (q->mUnk_24.z >> 12) - 1;
        GetKartPos(&p->mLookAt, p->mFollowedKartIndex);
        p->mLookAt.y = p->mLookAt.y + p->mCourseMapCamera->mUnk_18.y;
    } else {
        GetKartPos(&p->mLookAt, p->mFollowedKartIndex);
        p->mLookAt.y = p->mLookAt.y + 0x6000;
    }
    o = GetKart(p->mFollowedKartIndex);
    a = o->mUnk_138;
    i = (u16) ((s32) (((s64) q->mUnk_18.x * 0xb60b60b60bLL + 0x80000000LL) >> 32) >> 12);
    j = (u16) ((s32) (((s64) q->mUnk_18.y * 0xb60b60b60bLL + 0x80000000LL) >> 32) >> 12);
    k = (u16) ((s32) (((s64) q->mUnk_24.x * 0xb60b60b60bLL + 0x80000000LL) >> 32) >> 12);
    l = (u16) ((s32) (((s64) q->mUnk_24.y * 0xb60b60b60bLL + 0x80000000LL) >> 32) >> 12);
    MTX_RotAxis33((MtxFx43 *) m0, &o->mUnk_120, gPairsByAngle[(o->mHopTiltAngle >> 4) * 2],
                  gPairsByAngle[(o->mHopTiltAngle >> 4) * 2 + 1]);
    MTX_MultVec33(&a, m0, &a);
    b = a;
    c = b;
    d = b;
    func_02074b00_inline(&n, &d, -q->mUnk_18.z);
    Vec3CrossUnrounded(&data_usa_02154fc4, &a, &f);
    Vec3CrossUnrounded(&c, &f, &g);
    MTX_RotAxis33((MtxFx43 *) m2, &g, gPairsByAngle[(i >> 4) * 2], gPairsByAngle[(i >> 4) * 2 + 1]);
    MTX_RotAxis33((MtxFx43 *) m3, &f, gPairsByAngle[(j >> 4) * 2], gPairsByAngle[(j >> 4) * 2 + 1]);
    MTX_Concat33(m3, m2, m4);
    MTX_MultVec33(&d, m4, &d);
    func_02074b00_inline(&t, &d, q->mUnk_18.z);
    VEC_Add(&p->mLookAt, &t, &p->mPos);
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
    VEC_Add(&p->mPos, &n, &p->mLookAt);
    p->mLookAt.y = p->mLookAt.y - o->mHopHeight;
    p->mPos.y = p->mPos.y - o->mHopHeight;
    if (data_021759c0->mMode != MODE_MISSION_RUN && data_021759c0->mMode != MODE_BATTLE) {
        if (func_01ffdee4(&p->mPos, (u32 *) &p->mPrevPos, 0, data_usa_021656c0 >> 1, 2, -2, &w, NULL, NULL, NULL, NULL,
                          NULL, NULL, NULL) != 0) {
            o = GetKart(p->mFollowedKartIndex);
            v = &o->mUnk_120;
            k = VEC_DotProduct(v, &w);
            w.x = (s32) (((s64) o->mUnk_120.x * k) >> 12);
            w.y = (s32) (((s64) v->y * k) >> 12);
            w.z = (s32) (((s64) v->z * k) >> 12);
            VEC_Add(&w, &p->mPos, &p->mPos);
        }
    }
    UpdateCameraView(p);
}

void func_02074b00(Camera *p) {
    Kart *o = GetKart(p->mFollowedKartIndex);
    CourseMapCamera *q = p->mCourseMapCamera;
    Vec3 a;
    Vec3 b;
    Vec3 c;
    Vec3 d;
    s32 m[9];

    p->mUnk_0b4 = p->mLookAt;
    b = o->mPos;
    VEC_MultAdd(q->mUnk_00.z, &o->mUnk_120, &o->mPos, &a);
    a.y = 0x1f4000;
    b.y = 0x1f4000;
    c = o->mUnk_138;
    c.y = 0;
    if ((s64) c.x * c.x + (s64) c.y * c.y + (s64) c.z * c.z >= 0x10) {
        Vec3NormalizeAndGetLengthUnchecked(&c, &c);
    }
    func_02074b00_inline(&c, &c, q->mUnk_00.x);
    VEC_Add(&a, &c, &a);
    VEC_Add(&b, &c, &b);
    if (GetRaceUpdateFrames() < q->mFrameCount) {
        p->mLookAt = b;
        p->mPos = a;
    } else if (p->mUnk_144 < 0x1000) {
        p->mLookAt = b;
        p->mPos = a;
        p->mUnk_144 = p->mUnk_144 + 0x52;
        VEC_Subtract(&p->mPrevPos, &p->mPos, &p->mUnk_0a8);
        VEC_Subtract(&p->mUnk_0b4, &p->mLookAt, &p->mUnk_0b4);
        VEC_MultAdd(p->mUnk_144, &p->mUnk_0a8, &a, &p->mPos);
        VEC_MultAdd(p->mUnk_144, &p->mUnk_0b4, &b, &p->mLookAt);
    }
    UpdateCameraView(p);
    VEC_Subtract(&a, &b, &d);
    if ((s64) d.x * d.x + (s64) d.y * d.y + (s64) d.z * d.z >= 0x10) {
        Vec3NormalizeAndGetLengthUnchecked(&d, &d);
    }
    MTX_RotAxis33((MtxFx43 *) m, &data_usa_02154fc4, gPairsByAngle[(data_usa_021656a0 >> 4) * 2],
                  gPairsByAngle[(data_usa_021656a0 >> 4) * 2 + 1]);
    MTX_MultVec33(&d, m, &d);
    d.x = (s32) (((s64) d.x * 0xfae) >> 12);
    d.y = (s32) (((s64) d.y * 0xfae) >> 12);
    d.z = (s32) (((s64) d.z * 0xfae) >> 12);
    SetRaceLightVector(&d);
    q = p->mCourseMapCamera;
    if (q->mFovBlendPerFrame != 0) {
        s32 r;
        enum { K0 } t = p->mFovBlend;
        s32 x0 = q->mHalfFovPairFirst;
        s32 y0 = q->mHalfFovPairSecond;
        s32 y1 = q->mHalfFovPairSecondEnd;
        s32 x1 = q->mHalfFovPairFirstEnd;
        s32 v1 = x1 - x0;
        s32 v2 = y1 - y0;

        r = ((s64) v2 * t) >> 12;
        p->mHalfFovPairFirst = x0 + (s32) (((s64) v1 * t) >> 12);
        p->mHalfFovPairSecond = y0 + (s32) r;
        p->mFovBlend += q->mFovBlendPerFrame;
        if (p->mFovBlend > 0x1000) {
            p->mFovBlend = 0x1000;
        }
    } else {
        p->mHalfFovPairFirst = q->mHalfFovPairFirst;
        p->mHalfFovPairSecond = q->mHalfFovPairSecond;
    }
}

void UpdateCameraPosCurve(Camera *p, s32 a) {
    CourseMapCamera *q = p->mCourseMapCamera;
    u16 n = gCourseMap->mEntryGroups[q->mEntryGroupIndex].mEntryCount;
    Unk02042044 *e0;
    Unk02042044 *e1;
    Vec3 v;
    Vec3 d;
    Vec3 s;
    s32 m;

    if (n >= 4) {
        UpdatePosCurve(&p->mPos, &p->mPosCurve, q, a);
        return;
    }
    if (n < 2) {
        return;
    }
    e0 = GetCourseMapGroupEntry(q->mEntryGroupIndex, 0);
    e1 = GetCourseMapGroupEntry(q->mEntryGroupIndex, 1);
    v = e0->mUnk_00;
    VEC_Subtract(&e1->mUnk_00, &e0->mUnk_00, &d);
    if ((s64) d.x * d.x + (s64) d.y * d.y + (s64) d.z * d.z < 0x10) {
        m = 0;
    } else {
        m = Vec3NormalizeAndGetLengthUnchecked(&d, &d);
    }
    p->mPosCurve.mParam += a;
    if (p->mPosCurve.mParam >= 0x1000) {
        p->mPosCurve.mParam = 0x1000;
    }
    m = (s32) (((s64) p->mPosCurve.mParam * m) >> 12);
    s.x = (s32) (((s64) d.x * m) >> 12);
    s.y = (s32) (((s64) d.y * m) >> 12);
    s.z = (s32) (((s64) d.z * m) >> 12);
    VEC_Add(&v, &s, &p->mPos);
}

void UpdateCameraPosCurveLookAtBlend(Camera *p) {
    UpdateCameraPosCurve(p, p->mCourseMapCamera->mPosCurvePerFrame);
    UpdateCameraLookAtBlend(p);
    UpdateCameraViewWithWorldUp(p);
}

void UpdateCameraLookAtBlend(Camera *p) {
    CourseMapCamera *q = p->mCourseMapCamera;
    s32 a, b, c;
    s32 d, e, f;
    s32 x, y, z;
    s64 t;

    if (q->mLookAtBlendPerFrame != 0) {
        t = p->mLookAtBlend;
        a = q->mUnk_18.x;
        d = q->mUnk_24.x - a;
        x = (s32) ((d * t) >> 12);
        b = q->mUnk_18.y;
        e = q->mUnk_24.y - b;
        y = (s32) ((e * t) >> 12);
        c = q->mUnk_18.z;
        f = q->mUnk_24.z - c;
        z = (s32) ((f * t) >> 12);
        p->mLookAt.x = a + x;
        p->mLookAt.y = b + y;
        p->mLookAt.z = c + z;
        p->mLookAtBlend += q->mLookAtBlendPerFrame;
        if (p->mLookAtBlend > 0x1000) {
            p->mLookAtBlend = 0x1000;
        }
    } else {
        p->mLookAt.x = q->mUnk_18.x;
        p->mLookAt.y = q->mUnk_18.y;
        p->mLookAt.z = q->mUnk_18.z;
    }
}

void *GetChaseCamera(void) {
    return gChaseCamera;
}

Camera *func_02074898(void) {
    return gEntryCamera;
}

Camera *func_02074888(void) {
    return gCurrentChainCamera;
}

// Chase camera (gChaseCamera) only.
void SetCameraHalfFovAngleGoal(u32 p0) {
    gChaseCamera->mHalfFovAngleGoal = p0;
}

// Chase camera (gChaseCamera) only.
void ResetCameraHalfFovAngleGoal(void) {
    u32 value0;
    u32 value1;
    value1 = (u32) &data_0216569c;
    value1 = (u32) * (const u16 *) ((value1) + (0));
    gChaseCamera->mHalfFovAngleGoal = value1;
}

// Chase camera (gChaseCamera) only. Sets the angle goal to its default and the angle to default + 5, as SetupCamera
// does. The caller hands the leftover r0 (the Camera pointer) to a no-op function.
void ResetCameraHalfFovAngle(void) {
    s32 t;

    t = data_0216569c;
    gChaseCamera->mHalfFovAngleGoal = t;
    gChaseCamera->mHalfFovAngle = t + 5;
}

// Chase camera (gChaseCamera) only.
void SetCameraHeightHold(s32 a) {
    gChaseCamera->mHeightHold = a;
    if (a == 0) {
        return;
    }
    gChaseCamera->mHeldHeight = gChaseCamera->mPos.y;
    gChaseCamera->mHeldHeightEasing = FALSE;
}

void UpdateChaseCameraLookAt(Vec3 *a, Vec3 *b, s32 *c, Kart *d, s32 e, s32 f) {
    Vec3 v4;
    Vec3 v10;
    Vec3 v1;
    Vec3 v28;
    s32 t;

    v4 = d->mPos;
    v10 = d->mPos;
    v10.y = v10.y - e;
    VEC_MultAdd(f, &d->mUnk_12c, &v10, &v10);
    v4.y = v4.y + (f - e);
    if (!(d->mUnk_48 & 0x40000000)) {
        v1 = data_usa_02154fdc;
    } else {
        VEC_Subtract(&v10, &v4, &v1);
        VEC_MultAdd(0xa000, &d->mUnk_12c, &v1, &v1);
    }
    VEC_Subtract(&v1, b, &v28);
    v28.x = (s32) (((s64) v28.x * 0x266) >> 12);
    v28.y = (s32) (((s64) v28.y * 0x266) >> 12);
    v28.z = (s32) (((s64) v28.z * 0x266) >> 12);
    VEC_Add(b, &v28, b);
    VEC_Add(&v4, b, &v4);
    a->x = v4.x;
    a->z = v4.z;
    if (d->mUnk_48 & 0x10000) {
        *c = *c + 0x1000;
        if (*c > 0xa000) {
            *c = 0xa000;
        }
    } else {
        t = *c;
        *c = t + (s32) (((s64) -t * 0x29 + 0x800) >> 12);
    }
    v4.y = v4.y - *c;
    t = a->y;
    a->y = t + (s32) (((s64) (v4.y - t) * 0xccd + 0x800) >> 12);
}

void UpdateChaseCameraPos(Vec3 *a, Vec3 *b, Camera *c, Kart *d, Vec3 *e, const Vec3 *f, s32 g) {
    Vec3 v4;
    Vec3 v10;
    Vec3 v1;
    Vec3 v28;
    Vec3 v34;
    Vec3 v40;
    Vec3 v2;
    Vec3 v58;
    Vec3 v64;
    Vec3 v70;
    Vec3 v3;
    Vec3 v88;
    Vec3 v94;
    s32 h;
    s32 i;
    s32 j;
    s32 k;

    v1 = *f;
    h = c->mFollowDistance - g;
    GetKartUp(d, &v10);
    if (h < 500) {
        h = 500;
    }
    VEC_Subtract(&d->mPos, &d->mPrevPos, &v4);
    if (d->mUnk_48 & 0x1000) {
        if (d->mUnk_4c & 0x4000000) {
            return;
        }
        c->mKartMoveScale = (s32) (((s64) c->mKartMoveScale * 0xe66) >> 12);
        VEC_MultAdd(c->mKartMoveScale, &v4, a, a);
        return;
    }
    v4.y = 0;
    VEC_Add(a, &v4, a);
    i = -h;
    v2.x = (s32) (((s64) v1.x * i) >> 12);
    v2.y = (s32) (((s64) v1.y * i) >> 12);
    v2.z = (s32) (((s64) v1.z * i) >> 12);
    VEC_Add(&v2, &c->mPosGoalKartOffset, &v2);
    VEC_Add(&v2, &c->mPosGoalCollisionOffset, &v2);
    VEC_MultAdd(data_usa_0217ac7c, &v10, &v2, &v3);
    VEC_Add(e, &v3, &v70);
    v2.y = data_usa_0217ac7c;
    VEC_Add(e, &v2, &v64);
    v40 = v64;
    v40.y = v40.y + c->mPosGoalYOffset;
    if (!(d->mUnk_48 & 0x40000000)) {
        v88 = data_usa_02154fdc;
    } else {
        VEC_Subtract(&v70, &v40, &v88);
        VEC_MultAdd(-0x1e000, &v10, &v88, &v88);
    }
    VEC_Subtract(&v88, b, &v94);
    v94.x = (s32) (((s64) v94.x * 0x19a) >> 12);
    v94.y = (s32) (((s64) v94.y * 0x19a) >> 12);
    v94.z = (s32) (((s64) v94.z * 0x19a) >> 12);
    VEC_Add(b, &v94, b);
    VEC_Add(&v40, b, &v40);
    VEC_Subtract(&v40, a, &v58);
    j = v58.y;
    k = 0;
    v58.y = 0;
    if ((s64) v58.x * v58.x + (s64) v58.y * v58.y + (s64) v58.z * v58.z >= 16) {
        k = Vec3NormalizeAndGetLengthUnchecked(&v58, &v58);
    }
    VEC_MultAdd((s32) (((s64) k * 0x11f) >> 12), &v58, a, a);
    a->y = a->y + ((s32) (((s64) j * 0x11f) >> 9) + g * 2);
    if (c->mHeightHold != 0) {
        if (c->mHeldHeightEasing != FALSE) {
            s32 l;
            l = a->y - c->mHeldHeight;
            c->mHeldHeight = c->mHeldHeight + (s32) (((s64) l * 0x29 + 0x800) >> 12);
        }
        a->y = c->mHeldHeight;
    }
    VEC_Subtract(a, e, &v28);
    v34 = v28;
    k = 0;
    if ((s64) v34.x * v34.x + (s64) v34.y * v34.y + (s64) v34.z * v34.z >= 16) {
        k = Vec3NormalizeAndGetLengthUnchecked(&v34, &v34);
    }
    if (k == 0) {
        return;
    }
    VEC_MultAdd((s32) (((s64) c->mFollowDistance * c->mFollowDistanceScale) >> 12), &v34, e, a);
}

// Puts the chase camera at a minus mFollowDistance along axis 2 of the matrix b (the kart's).
void ResetCameraBehind(const Vec3 *a, void *b) {
    Camera *p;
    Vec3 m[3];
    Vec3 v;
    s32 t;

    p = gChaseCamera;
    Matrix3x3FromQuaternion(m, b);
    t = (s32) (((s64) -data_usa_0217ac90 * p->mFollowDirectionSign + 0x800) >> 12);
    v.x = (s32) (((s64) m[2].x * t) >> 12);
    v.y = (s32) (((s64) m[2].y * t) >> 12);
    v.z = (s32) (((s64) m[2].z * t) >> 12);
    VEC_Add(a, &v, &p->mPos);
    p->mPos.y = p->mPos.y + data_usa_0217ac7c;
    p->mBaseUp = data_usa_02154fc4;
    p->mPrevPos = p->mPos;
    p->mKartMoveScale = 0x1000;
    gChaseCamera->mHeightHold = 0;
    func_020d4f94((Unk020d4f94 *) &p->mViewMatrix);
    func_020d50c4();
}

// Chase camera (gChaseCamera) only.
void StartCameraWobble(s32 a, u32 b, s32 c) {
    Camera *p;
    s32 d;
    s32 t;

    d = 0x1000;
    p = gChaseCamera;
    if (b > 1000000) {
        return;
    }
    if (b > 0x57e40) {
        d = 0x4cd;
    } else if (b > 0x15f90) {
        d = 0x99a;
    }
    t = (s32) (((s64) a * (s32) (((s64) c * d) >> 12)) >> 12);
    if (p->mWobbling != FALSE && p->mWobbleAmplitude > t) {
        return;
    }
    p->mWobbleAmplitude = t;
    p->mWobbling = TRUE;
    p->mUnk_144 = 0;
    p->mWobblePerFrame = 0x800;
    p->mWobbleDirection = 1;
    p->mWobbleDecay = 0xe66;
    p->mWobbleOffset = 0;
}

void func_02073fb0(u32 a, s32 b) {
    StartCameraWobble(0x2800, a, b);
}

void func_02073f90(void) {
    StartCameraWobble(data_usa_021656b4, 0, 0x1000);
}

void UpdateCameraWobble(Camera *p) {
    s32 t;
    BOOL u;

    if (p->mWobbling == FALSE) {
        return;
    }
    p->mUnk_144 = p->mUnk_144 + p->mWobblePerFrame * p->mWobbleDirection;
    t = p->mUnk_144;
    if (t > 0x1000) {
        p->mWobbleDirection *= -1;
        p->mUnk_144 = 0x2000 - p->mUnk_144;
    } else if (t < -0x1000) {
        p->mWobbleDirection *= -1;
        p->mUnk_144 = -0x2000 - p->mUnk_144;
    }
    p->mWobbleAmplitude = (s32) (((s64) p->mWobbleAmplitude * p->mWobbleDecay) >> 12);
    p->mWobbleAmplitude = p->mWobbleAmplitude - 0x14;
    p->mWobbleOffset = (s32) (((s64) p->mUnk_144 * p->mWobbleAmplitude) >> 12);
    if (p->mWobbleAmplitude <= 0) {
        u = FALSE;
        p->mWobbleOffset = u;
        p->mWobbling = u;
    }
}
