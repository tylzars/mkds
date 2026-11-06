#include "Main/Unknown/code_02076cd0.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02056d54.h"
#include "Main/Unknown/code_02057d10.h"
#include "Main/Unknown/code_0205ee14.h"
#include "Main/Unknown/code_020738f4.h"
#include "Main/Unknown/code_02073904.h"
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
#include "Main/Unknown/code_020d4a20.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_02154000.h"
#include "Main/Unknown/unk_02165000.h"
#include "code_02133048.h"
#include "code_02147cd8.h"
#include "code_0214a748.h"
#include "code_021471bc.h"

#pragma thumb on

void func_02077b3c(void) {
    if (data_0217ad08->mUnk_25c != 0 || data_0217ad08->mUnk_260 != 0) {
        data_0217ad08->mUnk_1f4[data_0217ad08->mUnk_266].mUnk_2c = TRUE;
        data_0217ad08->mUnk_020->mUnk_00 = data_0217ad08->mUnk_024.mUnk_00;
        data_0217ad08->mUnk_020->mUnk_04 = data_0217ad08->mUnk_024.mUnk_04;
        data_0217ad08->mUnk_020->mUnk_20 = data_0217ad08->mUnk_1c8 + data_0217ad08->mUnk_024.mUnk_04;
        func_02057df0(LoadKartAndCharacterFiles);
        data_0217aa0c->mUnk_f8 = 1;
    }
}

void func_02077b1c(void) {
    data_0217ad08->mUnk_260 = 0;
    data_0217ad08->mUnk_25c = data_0217ad08->mUnk_260;
}

u32 func_02077a70(s32 *a, u32 b) {
    u32 n;
    enum { K0 } i;

    *a = (s32) _s32_div_f((u16) b, 3);
    if (*a >= 8) {
        switch (*a) {
            case 8:
                n = 0x14;
                break;
            case 9:
                n = 0x15;
                break;
            case 10:
                n = 0x16;
                break;
            case 11:
                n = 0x17;
                break;
        }
        if (func_02056dec(n) == 0) {
            *a = -1;
            for (i = 0; i < 8; i++) {
                if (func_0205fd2c(data_0217ad08->mUnk_268, i, b) != 0) {
                    *a = i;
                    break;
                }
            }
            if (*a != -1) {
                return 1;
            }
            return 0;
        }
    }
    return func_0205fd2c(data_0217ad08->mUnk_268, *a, b);
}

u16 func_02077a5c(void) {
    return data_0217ad08->mUnk_004 + 1;
}

u16 func_02077a4c(void) {
    return data_0217ad08->mUnk_008;
}

void LoadEmblemSBNclr(void *a) {
    void *v;

    LoadKartModelMenuFile(a, data_usa_02165714, &v);
    LoadNclrData(&gEmblemSBNclr, v);
}

void func_02077998(void) {
    u32 i;

    *(u32 *) 0x4000580 = 0xbfff0000;
    gCameraEntryChanged = 1;
    i = gEntryCameraUpdateRan = 0;
    if (data_021759c0->mMode == MODE_MISSION_RUN) {
        i = data_021759c0->mUnk_036;
        i = (u16) i;
    } else {
        i = (u16) i;
        i = (u16) i;
    }
    data_usa_0217ac90 = data_usa_02154fa0[i][0];
    data_usa_0217ac7c = data_usa_02154fa4[i][0];
    data_usa_0217ac78 = data_usa_02154fa8[i][0];
    if (data_021759c0->mCourseId == COURSE_ID_AIRSHIP) {
        data_usa_021656b4 = 0xa000;
    } else {
        data_usa_021656b4 = 0x5000;
    }
}

void CreateChaseCamera(void) {
    Kart *a = GetKart(data_021759c0->mEntryIndex);

    gChaseCamera = HeapAlloc(GetHeap(func_020364e8()), 0x270);
    SetupCameraBehindKart();
    GetKartForward(a, &gChaseCamera->mSavedKartForward);
    RefreshCameraProjection(gChaseCamera);
}

void func_020777ac(u32 a) {
    void *h = GetHeap(func_020364e8());
    u16 i;
    u16 n;
    CourseMapCamera *e;
    u16 m;
    u16 j;
    s32 k;

    gEntryCamera = HeapAlloc(h, 0x270);
    SetupCamera(gEntryCamera);
    gEntryCamera->mFollowedKartIndex = a;
    gEntryCamera->mCourseMapCamera = NULL;
    gEntryCamera->mFrustumShift = 0;
    gEntryCamera->mKind = 1;
    if (data_021759c0->mUnk_00c == 6) {
        gEntryCamera->mCourseMapCamera = gCourseMap->mCameras;
    }
    if (data_021759c0->mMode == MODE_BATTLE) {
        gEntryCamera->mCourseMapCamera = gCourseMap->mFirstKind7EntryInMode2;
        if (gEntryCamera->mCourseMapCamera != NULL) {
            n = 0;
            k = -1;
            for (i = 0; i < gCourseMap->mCameraCount; i++) {
                if (gCourseMap->mCameras[i].mKind == 7) {
                    n++;
                }
            }
            data_usa_0217ac70 = n;
            gEntryCamera->mUnk_21c = HeapAlloc(h, n * 0x88);
            e = gEntryCamera->mCourseMapCamera;
            m = 0;
            j = 0;
            for (; m < gCourseMap->mCameraCount; m++) {
                if (k != -1) {
                    e = &gCourseMap->mCameras[(u16) k];
                    if (e == gEntryCamera->mCourseMapCamera) {
                        break;
                    }
                }
                if (e->mKind == 7) {
                    func_02077750(&gEntryCamera->mUnk_21c[j], e);
                    j++;
                    k = e->mNextIndex;
                }
            }
            gEntryCamera->mUnk_220 = gEntryCamera->mUnk_21c;
            gEntryCamera->mUnk_224 = 0;
            gEntryCamera->mKind = 3;
            gCameraEntryChanged = 1;
        }
    }
}

void func_02077750(Unk02077750 *a, CourseMapCamera *b) {
    CourseMapEntryGroup *v1 = &gCourseMap->mEntryGroups[b->mEntryGroupIndex];

    a->mUnk_7c = b->mPosCurvePerFrame;
    a->mUnk_7e = 2;
    a->mUnk_00 = b;
    a->mUnk_80 = 0;
    a->mUnk_84 = 0;
    if (v1->mEntryCount >= 4) {
        SetupPosCurve(&a->mUnk_04, b);
        func_0207bd6c(&a->mUnk_40, b);
    }
}

void CreateChainCameraPair(void) {
    void *h = GetHeap(func_020364e8());

    gFirstChainCamera = HeapAlloc(h, 0x270);
    gSecondChainCamera = HeapAlloc(h, 0x270);
    SetupCamera(gFirstChainCamera);
    SetupCamera(gSecondChainCamera);
    gFirstChainCamera->mCourseMapCamera = gCourseMap->mFirstChainStartEntry;
    gSecondChainCamera->mCourseMapCamera = gCourseMap->mSecondChainStartEntry;
    gFirstChainCamera->mKind = 2;
    gSecondChainCamera->mKind = 2;
    if (gFirstChainCamera->mCourseMapCamera == NULL) {
        gRaceProgress->mUnk_4d0 = 1;
        return;
    }
    if ((s16) gFirstChainCamera->mCourseMapCamera->mEntryGroupIndex != -1) {
        SetupPosCurve(&gFirstChainCamera->mPosCurve, gFirstChainCamera->mCourseMapCamera);
    }
    if ((s16) gSecondChainCamera->mCourseMapCamera->mEntryGroupIndex != -1) {
        SetupPosCurve(&gSecondChainCamera->mPosCurve, gSecondChainCamera->mCourseMapCamera);
    }
}

void CreateFirstChainCamera(void) {
    gFirstChainCamera = HeapAlloc(GetHeap(func_020364e8()), 0x270);
    gSecondChainCamera = NULL;
    SetupCamera(gFirstChainCamera);
    gFirstChainCamera->mCourseMapCamera = gCourseMap->mFirstChainStartEntry;
    gFirstChainCamera->mKind = 2;
    gFirstChainCamera->mFrustumShift = 0;
    if (gFirstChainCamera->mCourseMapCamera == NULL) {
        gRaceProgress->mUnk_4d0 = 1;
        return;
    }
    if ((s16) gFirstChainCamera->mCourseMapCamera->mEntryGroupIndex != -1) {
        SetupPosCurve(&gFirstChainCamera->mPosCurve, gFirstChainCamera->mCourseMapCamera);
    }
}

#pragma thumb off

// Writes the default values of 76 members; re-run by SetupCameraBehindKart when a kart is placed.
void SetupCamera(Camera *p) {
    Vec3 b;
    Vec3 a;
    Vec3 c;

    p->mPos.x = 0x1e3000;
    p->mPos.y = 0x4bd000;
    p->mPos.z = 0xc6b000;
    a = *(volatile Vec3 *) &data_usa_02154fdc;
    p->mLookAt = a;
    b = *(volatile Vec3 *) &data_usa_02154fc4;
    p->mUp = data_usa_02154fc4;
    p->mSide = data_usa_02154fd0;
    MTX_Identity43_(&p->mViewMatrix);
    p->mForward = data_usa_02154fb8;
    p->mPosGoalYOffset = 0;
    p->mHalfFovAngleGoal = data_0216569c;
    p->mHalfFovAngle = data_0216569c + 5;
    p->mHalfFovPairFirst = gPairsByAngle[((u16) p->mHalfFovAngle >> 4) * 2];
    p->mHalfFovPairSecond = gPairsByAngle[((u16) p->mHalfFovAngle >> 4) * 2 + 1];
    p->mAspectRatio = 0x1555;
    p->mNear = 0x400;
    p->mUnk_08c = 0x640000;
    p->mFar = gCourseMap->mSettings->mCameraFar;
    if (p->mFar < 0x1000) {
        p->mFar = 0x640000;
    }
    p->mFrustumTop = 0;
    p->mFrustumBottom = 0;
    p->mFrustumLeft = 0;
    p->mFrustumRight = 0;
    c = data_usa_02154fdc;
    p->mViewPos = c;
    p->mViewLookAt = c;
    p->mBaseUp = b;
    p->mHeldHeight = 0;
    p->mLookAtHeight = data_usa_0217ac78;
    p->mUnk_0d8 = 1;
    p->mFollowDistance = data_usa_0217ac90;
    p->mUnk_0e0 = p->mFollowDistance;
    p->mLookAtLowering = 0;
    p->mFollowDistanceScale = 0x1000;
    p->mUnk_0ec = 0;
    p->mFollowDirectionSign = 0x1000;
    p->mShakeLookAtOffsetGoal = c;
    p->mShakePosOffsetGoal = c;
    p->mShakeLookAtOffset = c;
    p->mShakePosOffset = c;
    p->mShakeKind = 0;
    p->mShakeLookAtCounterOffset = c;
    p->mFovBlend = 0;
    p->mLookAtBlend = 0;
    p->mHeightHold = 0;
    p->mPosGoalKartOffsetScale = 0;
    p->mCollisionOffsetLengthGoal = 0;
    p->mCollisionOffsetLength = 0;
    p->mViewPosYOffset = 0;
    p->mWobbling = FALSE;
    p->mUnk_144 = 0;
    p->mWobblePerFrame = 0;
    p->mWobbleDirection = 1;
    p->mWobbleDecay = 0;
    p->mWobbleOffset = 0;
    p->mWobbleAmplitude = 0;
    p->mFollowedKartIndex = 0;
    p->mLastCourseMapCameraIndex = -1;
    p->mCourseMapCameraFrames = 0;
    p->mKind6EntryRunning = FALSE;
    p->mKind6EntryFrames = 0;
    p->mEntryUpdateHold = 0;
    p->mEntryUpdateDisabled = FALSE;
    p->mKind8EntryRunning = FALSE;
    p->mFrustumShift = 0;
    p->mKind = 0;
    p->mPosGoalKartOffset = c;
    p->mPosGoalCollisionOffset = c;
    p->mUnk_254 = 3;
    p->mUnk_258 = FALSE;
    p->mUnk_25c = FALSE;
    p->mSavedKartForward = c;
    p->mUnk_0a8 = c;
    p->mUnk_0b4 = c;
    p->mSideDistanceSign = data_021759c0->mUnk_57 ? -1 : 1;
    p->mUnk_21c = NULL;
    p->mUnk_220 = NULL;
    p->mUnk_20c = 0;
    p->mUnk_20e = 0;
    p->mUnk_224 = 0;
    p->mKartMoveScale = 0x1000;
}

void RefreshCameraProjection(Camera *p) {
    s32 a;
    s32 b;
    s32 c;
    s32 d;

    if (p == gChaseCamera) {
        if (p->mHalfFovAngle == p->mHalfFovAngleGoal && gEntryCameraUpdateRan == 0) {
            return;
        }
        if (func_020738f8(p->mHalfFovAngle - p->mHalfFovAngleGoal) < 10) {
            p->mHalfFovAngle = p->mHalfFovAngleGoal;
        }
    }
    p->mFrustumTop = (s32) (((s64) p->mNear * FX_Div(p->mHalfFovPairFirst, p->mHalfFovPairSecond)) >> 12);
    p->mFrustumBottom = -p->mFrustumTop;
    p->mFrustumLeft = (s32) (((s64) -p->mFrustumTop * p->mAspectRatio) >> 12);
    a = p->mFrustumTop;
    b = p->mFrustumBottom;
    switch (p->mFrustumShift) {
        case 1:
            a <<= 1;
            b = -a;
            p->mFrustumTop = (s32) (((s64) a * (data_usa_021656b8 + 0x1000)) >> 12);
            p->mFrustumBottom = (s32) (((s64) a * data_usa_021656b8) >> 12);
            break;
        case 2:
            b <<= 1;
            a = -b;
            p->mFrustumBottom = (s32) (((s64) b * (data_usa_021656b8 + 0x1000)) >> 12);
            p->mFrustumTop = (s32) (((s64) b * data_usa_021656b8) >> 12);
            break;
    }
    if (data_021759c0->mUnk_57 != 0) {
        p->mFrustumLeft = -p->mFrustumLeft;
    }
    p->mFrustumRight = -p->mFrustumLeft;
    if (data_021759c0->mUnk_00c == 6 && p->mCourseMapCamera != NULL) {
        c = (s32) (((s64) p->mFrustumTop * p->mCourseMapCamera->mUnk_00.y + 0x800) >> 12);
        p->mFrustumBottom += c;
        p->mFrustumTop += c;
    }
    func_020d4a20(a, b, p->mFrustumLeft, p->mFrustumRight, p->mNear, p->mFar);
    *(u32 *) 0x4000440 = 0;
    G3i_FrustumW_(p->mFrustumTop, p->mFrustumBottom, p->mFrustumLeft, p->mFrustumRight, p->mNear, p->mFar, 0x1000, 1,
                  (Unk0214ad4c *) data_0217acc0);
}

void UpdateCameraViewWithWorldUp(Camera *p) {
    Vec3 c;
    Vec3 b;
    Vec3 a;
    Vec3 d;
    Vec3 e;

    a = data_usa_02154fc4;
    VEC_Subtract(&p->mLookAt, &p->mPos, &b);
    if ((s64) b.x * b.x + (s64) b.y * b.y + (s64) b.z * b.z >= 0x10) {
        Vec3NormalizeAndGetLengthUnchecked(&b, &b);
    }
    p->mForward = b;
    Vec3CrossUnrounded(&a, &b, &c);
    Vec3CrossUnrounded(&b, &c, &p->mUp);
    if (p->mUp.x == 0 && p->mUp.y == 0 && p->mUp.z == 0) {
        p->mUp.x = 0x1000;
        p->mUp.y = 0x1000;
        p->mUp.z = 0x1000;
        if ((s64) p->mUp.x * p->mUp.x + (s64) p->mUp.y * p->mUp.y + (s64) p->mUp.z * p->mUp.z >= 0x10) {
            Vec3NormalizeAndGetLengthUnchecked(&p->mUp, &p->mUp);
        }
    }
    *(u32 *) 0x4000440 = 2;
    d.x = p->mPos.x >> 4;
    d.y = (p->mPos.y + p->mViewPosYOffset) >> 4;
    d.z = p->mPos.z >> 4;
    e.x = p->mLookAt.x >> 4;
    e.y = p->mLookAt.y >> 4;
    e.z = p->mLookAt.z >> 4;
    G3i_LookAt_(&d, &p->mUp, &e, 1, &p->mViewMatrix);
}

// Per frame for each camera in use: axes, shake, view position and look-at in 1/16 scale, loads the view matrix.
void UpdateCameraView(Camera *p) {
    Vec3 a;
    Vec3 b;
    Vec3 c;
    Vec3 d;

    b = p->mBaseUp;
    c = p->mPos;
    d = p->mLookAt;
    d.y += p->mWobbleOffset;
    VEC_Subtract(&d, &c, &a);
    if ((s64) a.x * a.x + (s64) a.y * a.y + (s64) a.z * a.z >= 0x10) {
        Vec3NormalizeAndGetLengthUnchecked(&a, &a);
    }
    p->mForward = a;
    Vec3CrossUnrounded(&b, &a, &p->mSide);
    Vec3CrossUnrounded(&a, &p->mSide, &p->mUp);
    if (p->mUp.x == 0 && p->mUp.y == 0 && p->mUp.z == 0) {
        p->mUp.x = 0x1000;
        p->mUp.y = 0x1000;
        p->mUp.z = 0x1000;
        if ((s64) p->mUp.x * p->mUp.x + (s64) p->mUp.y * p->mUp.y + (s64) p->mUp.z * p->mUp.z >= 0x10) {
            Vec3NormalizeAndGetLengthUnchecked(&p->mUp, &p->mUp);
        }
    }
    if (p->mShakeKind != 0) {
        UpdateCameraShake(p);
        VEC_Add(&c, &p->mShakePosOffset, &c);
        VEC_Add(&d, &p->mShakeLookAtOffset, &d);
        VEC_Add(&p->mShakeLookAtCounterOffset, &d, &d);
    }
    p->mViewPos.x = c.x >> 4;
    p->mViewPos.y = c.y >> 4;
    p->mViewPos.z = c.z >> 4;
    p->mViewPos.y += p->mViewPosYOffset >> 4;
    p->mViewLookAt.x = d.x >> 4;
    p->mViewLookAt.y = d.y >> 4;
    p->mViewLookAt.z = d.z >> 4;
    *(u32 *) 0x4000440 = 2;
    G3i_LookAt_(&p->mViewPos, &p->mUp, &p->mViewLookAt, 1, &p->mViewMatrix);
}
