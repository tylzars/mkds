#include "Main/Unknown/code_02070398.h"
#include "Main/Unknown/code_020401ac.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"

#include "Main/Unknown/code_02068eac.h"
#include "Main/Unknown/code_02109000.h"
#include "ITCM/code_01ff9598.h"
#include "ITCM/code_01ffcf7c.h"
#include "ITCM/code_01ffd000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_020a1e40.h"
#include "Main/Unknown/code_020d50ec.h"
#include "Main/Unknown/code_02080cd0.h"
#include "Main/Unknown/code_020888b4.h"
#include "Main/Unknown/code_02108e6c.h"
#include "Main/Unknown/code_02108ea0.h"
#include "code_0212d214.h"
#include "Main/Unknown/code_0210bcf4.h"
#include "Main/Unknown/code_0210dc7c.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_0208aea8.h"
#include "Main/Unknown/code_0208b484.h"
#include "Main/Unknown/code_02146000.h"
#include "Main/Unknown/unk_02154000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/unk_02165000.h"
#include "code_0212bcac.h"
#include "code_02146cbc.h"
#include "code_02146d78.h"
#include "code_02147288.h"
#include "code_02147cd8.h"
#include "code_02148538.h"
#include "code_0212df7c.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_02069000.h"
#include "Main/Unknown/code_0206a000.h"
#include "Main/Unknown/code_0207b000.h"
#include "Main/Unknown/code_02081618.h"
#include "Main/Unknown/code_020ed5c0.h"
#include "Main/Unknown/code_02105ec0.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/code_02073eb8.h"
#include "Main/Unknown/code_02055730.h"
#include "Main/Unknown/code_0208c534.h"
#include "Main/Unknown/code_02086058.h"
#include "Main/Unknown/code_02089d14.h"
#include "Main/Unknown/code_02109054.h"
#include "Main/Unknown/code_0210a588.h"
#include "Main/Unknown/code_0210ab48.h"
#include "Main/Unknown/code_0210b564.h"
#include "Main/Unknown/code_0202578c.h"
#include "Main/Unknown/code_02024974.h"
#include "Main/Unknown/code_02109110.h"
#include "Main/Unknown/code_0210a598.h"
#include "Main/Unknown/code_0210b850.h"
#include "Main/Unknown/code_0210cf20.h"
#include "Main/Unknown/code_0210cf9c.h"
#include "Main/Unknown/unk_02161000.h"
#include "Main/Unknown/code_02036820.h"
#include "code_0201750c.h"
#include "Main/Unknown/code_0203c5e4.h"
#include "Main/Unknown/code_02036bec.h"
#include "code_020172d0.h"
#include "Main/Unknown/code_020681f0.h"
#include "ITCM/code_01ffba68.h"
#include "ITCM/code_01ffc000.h"
#include "Main/Unknown/code_02040de0.h"
#include "Main/Unknown/code_0207a104.h"
#include "Main/Unknown/code_02081338.h"
#include "Main/Unknown/code_020810e4.h"
#include "Main/Unknown/code_020815a0.h"
#include "Main/Unknown/code_0208ae60.h"
#include "Main/Unknown/code_0208c188.h"
#include "Main/Unknown/code_0208c4e8.h"
#include "Main/Unknown/code_02089f9c.h"
#include "Main/Unknown/code_020ec8bc.h"
#include "Main/Unknown/code_021031f4.h"
#include "Main/Unknown/code_02104a0c.h"
#include "Main/Unknown/code_0210a664.h"
#include "Main/Unknown/code_0210fa40.h"
#include "Main/Unknown/code_020e6fd4.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/unk_027e0000.h"
#include "Main/Unknown/code_02068000.h"
#include "Main/Unknown/code_0206390c.h"
#include "Main/Unknown/code_0206a354.h"
#include "Main/Unknown/code_02077bc0.h"
#include "code_021471bc.h"

void AdvanceKartScaleFactor(Kart *kart) {
    s32 frameIndex;
    enum { K0 } entryIndex;

    entryIndex = kart->mEntryIndex;
    data_0217566a[entryIndex].mBitMask = 0xff7;
    if (kart->mUnk_7c & 0x20) {
        func_02068b98(kart);
        return;
    }
    kart->mUnk_3c8 = kart->mUnk_3c8 + 1;
    frameIndex = kart->mUnk_3c8;
    if (frameIndex >= 0x19) {
        kart->mUnk_7c &= ~0x80;
        return;
    }
    kart->mScaleFactor.x = gKartScaleFactorXTable[frameIndex];
    kart->mScaleFactor.y = gKartScaleFactorYTable[frameIndex];
    kart->mScaleFactor.z = gKartScaleFactorZTable[frameIndex];
    kart->mScale.x = ((s64) kart->mScaleBase.x * kart->mScaleFactor.x) >> 12;
    kart->mScale.y = ((s64) kart->mScaleBase.y * kart->mScaleFactor.y) >> 12;
    kart->mScale.z = ((s64) kart->mScaleBase.z * kart->mScaleFactor.z) >> 12;
    kart->mScale.y = ((s64) kart->mScaleYFactor * kart->mScale.y) >> 12;
}

void ResetKartToRespawnPoint(Kart *kart) {
    Vec3 respawnPos;
    Vec3 respawnForward;
    Vec3 respawnAngles;
    Vec3 sideDirection;
    s32 rotationMatrix[9];
    PointLink *respawnLink;
    s32 x;
    s32 forwardOffset;
    s32 i;
    KartItems *kartItems;
    s64 l;

    if (kart->mRespawnSlot == -1) {
        i = kart->mIndex;
        if (gRaceSetup->mMode == MODE_BATTLE) {
            i = GetCourseMapRespawnSlot(0);
        } else {
            i = GetCourseMapRespawnSlot(gRaceProgress->mUnk_000[i].mCheckpoint);
        }
        kart->mRespawnSlot = i;
    }
    i = (u16) kart->mRespawnSlot;
    if (gRaceSetup->mMode == MODE_BATTLE) {
        respawnLink = GetCourseMapRespawnBattlePointLink(i, &respawnPos, &respawnAngles);
    } else {
        respawnLink = GetCourseMapRespawnRacePointLink(i, &respawnPos, &respawnAngles);
    }
    i = ((u16) ((s32) (((s64) respawnAngles.y * 0xb60b60b60bLL + 0x80000000LL) >> 32) >> 12)) >> 4;
    MTX_RotY33_(rotationMatrix, gPairsByAngle[i * 2], gPairsByAngle[i * 2 + 1]);
    MTX_MultVec33(&data_02154f70, rotationMatrix, &respawnForward);
    if (gRaceSetup->mMode != MODE_BATTLE && gCourseMap->mItemRouteCount != 0) {
        (kartItems = &gKartItems[kart->mIndex])->mUnk_1f0.mLink =
            GetCourseMapRespawnItemPointLink((u16) kart->mRespawnSlot);
        kartItems->mUnk_1f0.mNextLinksUsed = 1;
    }
    if (gRaceSetup->mMode != MODE_TIME_ATTACK) {
        x = data_usa_02154d4c[kart->mIndex][0];
        forwardOffset = data_usa_02154d50[kart->mIndex][0];
        Vec3CrossUnrounded(&data_02154f7c, &respawnForward, &sideDirection);
        VEC_MultAdd(((s64) data_usa_02165504 * x) >> 12, &sideDirection, &respawnPos, &respawnPos);
        VEC_MultAdd(((s64) data_usa_02165504 * forwardOffset) >> 12, &respawnForward, &respawnPos, &respawnPos);
        if (respawnAngles.x != 0 && forwardOffset != 0) {
            i = ((u16) ((s32) (((s64) respawnAngles.x * 0xb60b60b60bLL + 0x80000000LL) >> 32) >> 12)) >> 4;
            l = gPairsByAngle[i * 2];
            i = (l * -forwardOffset + 0x800) >> 12;
            respawnPos.y += (s32) (((s64) i * data_usa_02165504 + 0x800) >> 12);
        }
        if (respawnAngles.z != 0 && x != 0) {
            i = ((u16) ((s32) (((s64) respawnAngles.z * 0xb60b60b60bLL + 0x80000000LL) >> 32) >> 12)) >> 4;
            l = gPairsByAngle[i * 2];
            i = (l * x + 0x800) >> 12;
            respawnPos.y += (s32) (((s64) i * data_usa_02165504 + 0x800) >> 12);
        }
    }
    respawnPos.y += 0x28000;
    x = kart->mUnk_48;
    if (x & 0x800000) {
        SetupKartFollowEffect(StartEffect(0x71, &respawnPos), kart->mIndex, 0x32);
    } else if (x & 0x1000000) {
        SetupKartFollowEffect(StartEffect(0x70, &respawnPos), kart->mIndex, 0x32);
    }
    ResetKartAndSetPos(kart, &respawnPos, &respawnForward, respawnLink);
    if (kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) {
        GetEntryKartCounters()->mUnk_18++;
    } else {
        ResetSoundDistanceSquaredChange(&kart->mUnk_518);
    }
    kart->mUnk_4c |= 0xc00;
    kart->mUnk_48 |= 0x2000000;
    if (kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) {
        func_02055bd4(0x3c);
        func_02075d08(0);
    }
}

s32 AdvanceKartRespawnWait(Kart *kart, s32 *a) {
    BOOL finished;
    u32 flags;

    flags = kart->mUnk_4c;
    finished = FALSE;
    if (flags & 0x4000000) {
        if (kart->mUnk_4bc > 0x19a) {
            kart->mUnk_4bc = ((s64) kart->mUnk_4bc * 0xe66LL) >> 12;
        }
        *a = kart->mUnk_4bc;
    } else if (flags & 0x200000) {
        if (kart->mUnk_4bc > 0x666) {
            kart->mUnk_4bc = ((s64) kart->mUnk_4bc * 0xe66LL) >> 12;
        }
        *a = kart->mUnk_4bc;
    }
    kart->mRespawnFrames = kart->mRespawnFrames + 1;
    if (kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) {
        if (kart->mRespawnFrames == 0x16) {
            func_02055a94();
        } else if (kart->mRespawnFrames == 0x19) {
            func_02055c18(0x3c);
        }
    }
    if ((kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) && kart->mRespawnFrames == 0x55) {
        func_020e7a40();
    } else if (kart->mRespawnFrames > 0x78) {
        func_02063ad0(kart);
        finished = TRUE;
    }
    return finished;
}

void ResetKartAndSetPos(Kart *kart, const Vec3 *position, const Vec3 *forward, PointLink *link) {
    ParticipantKartRecordState *q;
    Vec3 axis;

    func_02072930(kart);
    SetKartModelsEntryCourseColors(kart->mKartModelsEntry);
    kart->mSlotFunctions[1](kart);
    kart->mUnk_7c &= ~0xe000;
    StopOrthoQuads(kart->mIndex);
    kart->mUnk_48 |= 0x240;
    kart->mPos = *position;
    if (kart->mUnk_7c & 0x400) {
        q = kart->mUnk_514;
        q->mUnk_00 = kart->mPos;
        q->mUnk_10 = q->mUnk_00;
        q->mUnk_4c = *(Vec4 *) &kart->mUnk_108.z;
        q->mUnk_a8 = data_02154f94;
        q->mUnk_b4 = 0;
    }
    if (forward != NULL) {
        kart->mHeadingAngle = (s32) (((s64) FX_Atan2(forward->x, forward->z) * 0x28be60dLL) >> 12) >> 12;
        axis = data_02165524;
        QuaternionFromAxisAngle(&axis, kart->mHeadingAngle, &kart->mUnk_e0_m);
    }
    Matrix4x3FromQuaternion(&kart->mUnk_120, &kart->mUnk_e0_m);
    GetKartForward(kart, &kart->mForward);
    kart->mTurnedForward = kart->mForward;
    kart->mEasedTurnedForward = kart->mTurnedForward;
    kart->mPrevPos = kart->mPos;
    kart->mDrawMatrixPos = kart->mPrevPos;
    kart->mPrevCollisionCenter = kart->mPos;
    kart->mCollisionCenter = kart->mPos;
    kart->mLastGroundY = kart->mPos.y;
    if (kart->mUnk_7c & 2) {
        if (link != NULL) {
            CallKartAiReset(kart->mAi, link);
        } else {
            CallKartAiSetup(kart->mAi, kart->mIndex);
        }
    }
    if (kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) {
        ResetCameraBehind(position, &kart->mUnk_e0_m);
        func_02089f9c(((u32(*)(void)) ResetCameraHalfFovAngle)());
        SetCameraHeightHold(0);
    }
}

void func_02072930(Kart *kart) {
    s32 i;
    KartFollowEffectIds effectIds;

    ReleaseKartItems(&gKartItems[kart->mIndex]);
    ReleaseKartSurfaceEffects(kart);
    ReleaseKartStarEffects(kart->mIndex);
    ReleaseKartKillerEffect(kart->mIndex);
    func_02081338(kart->mIndex);
    func_020810e4(kart->mIndex);
    func_02080fb8(kart);
    func_02080e9c(kart);
    ReleaseKartTurnEffects(GetKartTurnEffects(kart->mIndex));
    func_020719d0(kart);
    if (kart->mIndex == gRaceSetup->mEntryIndex) {
        func_0210fa74(0);
    }
    func_0210a664(kart);
    if (kart->mUnk_4c & 0x2000) {
        func_0207b0d0(kart);
    }
    if (kart->mUnk_4c & 0x40) {
        kart->mUnk_4c &= ~0x40;
        func_0207b1a8(kart);
        kart->mItemEffect = 0;
        StopKartStarEffects(kart->mIndex);
        func_02068a64(kart, 0, 1);
        if ((kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) && gRaceSetup->mRaceKind == RACE_KIND_NORMAL) {
            func_02106dc8();
        }
        if (kart->mUnk_4c & 0x2000) {
            func_0207b13c(kart);
        }
    }
    if (kart->mUnk_4c & 0x10000000) {
        kart->mUnk_4c &= ~0x10000000;
        func_0210515c(kart->mIndex);
        if (kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) {
            ResetCameraHalfFovAngleGoal();
        }
        kart->mRadiusFactor = 0x1000;
        kart->mSurfaceGroup = -1;
        i = 0;
        kart->mItemEffect = 0;
        if (kart->mKartModelsEntry->mUnk_058 == 0) {
            effectIds = gKartFollowEffectIds;
            for (i = 0; i < 3; i++) {
                SetupKartFollowEffect(StartEffect(effectIds.mEffectIds[i], &kart->mPos), kart->mIndex, 0x14);
            }
        }
        StopKartKillerEffect(kart->mIndex);
        StartSound(&kart->mSoundSource, 0xfd, 0x7f, 0);
    }
    if (kart->mUnk_7c & 0x2000) {
        kart->mUnk_7c &= ~0x2000;
        kart->mUnk_7c &= ~0xc000;
        kart->mItemEffect = 0;
        if (!(kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY)) {
            ShowKartTurnEffects(GetKartTurnEffects(kart->mIndex));
        } else {
            StartSound(&kart->mSoundSource, 0xf9, 0x7f, 0);
        }
        func_0210fa40(0, (kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) ? 1 : 0);
    }
}

void ResetKartToStartPlacement(Kart *kart) {
    Vec3 startPos;
    Vec3 forward;
    Vec3 startAngles;
    Vec3 *collisionPos;

    if (!(kart->mUnk_7c & 0x20)) {
        return;
    }
    GetCourseMapKartStartPlacement(&startPos, &startAngles, kart->mIndex);
    kart->mHeadingAngle = (u32) (startAngles.y * 0xb6) >> 12;
    QuaternionFromAxisAngle(&data_02154f7c, kart->mHeadingAngle, &kart->mUnk_e0_m);
    Matrix4x3FromQuaternion(&kart->mUnk_120, &kart->mUnk_e0_m);
    GetKartForward(kart, &forward);
    ResetKartAndSetPos(kart, &startPos, &forward, NULL);
    if (gRaceSetup->mMode == 5) {
        collisionPos = &kart->mPointAlongUp;
    } else {
        collisionPos = &kart->mCollisionCenter;
    }
    if (kart->mCollisionSlot == -1) {
        kart->mCollisionSlot = CreateCollisionSlot(collisionPos, kart->mPhysicalParam->mRadius + 0xd000, 0x8000, kart);
    }
    if (kart->mUnk_2ca == -1) {
        kart->mUnk_2ca =
            CreateCollisionSlot(&kart->mUnk_1f0, ((s64) kart->mPhysicalParam->mRadius << 15) >> 12, 0x800, kart);
    }
    kart->mUnk_7c |= 0x80;
    kart->mUnk_7c &= ~0x60;
    kart->mScale = data_02154f94;
}

void InitKartPhysicalParams(Kart *kart) {
    s32 a;
    s32 b;
    s16 i;
    KartPhysicalParam *physicalParam;
    s32 *charPhysicalParam;

    kart->mPhysicalParam = GetKartPhysicalParam(kart->mIndex);
    a = 0x1000;
    b = 0;
    if (IsRaceAwardOrStaffRoll() == 0) {
        switch (gRaceSetup->mEngineIndex) {
            case 0:
                a = 0xb33;
                b = -0x28;
                break;
            case 1:
                a = 0xd9a;
                b = -0x14;
                break;
        }
    }
    kart->mPhysicalParam->mBaseSpeedLimit = ((s64) kart->mPhysicalParam->mBaseSpeedLimit * a) >> 12;
    kart->mPhysicalParam->mUnk_32 = kart->mPhysicalParam->mUnk_32 + b;
    kart->mSpeedLimitFactorPerDepth = 0x1000 - kart->mPhysicalParam->mSurfaceSpeedLimitFactors[4];
    kart->mSpeedLimitFactorPerDepth = FX_Div(kart->mSpeedLimitFactorPerDepth, kart->mPhysicalParam->mRadius << 1);
    kart->mCharPhysicalParam = GetCharPhysicalParam(kart->mIndex);
    physicalParam = kart->mPhysicalParam;
    charPhysicalParam = kart->mCharPhysicalParam;
    for (i = 0; i < 12; i++) {
        a = physicalParam->mSurfaceSpeedLimitFactors[i];
        if (a < 0x1000) {
            physicalParam->mSurfaceSpeedLimitFactors[i] = ((s64) a * *charPhysicalParam + 0x800) >> 12;
        }
    }
}

void func_02072600(Kart *kart) {
    Vec3 zeroVector;

    kart->mUnk_d4 = 0x1000;
    kart->mUnk_d8 = 0x1000;
    kart->mSpeedLimitFactor = 0x1000;
    kart->mSpeedLimitHitFactor = 0x1000;
    zeroVector = data_02154f94;
    *(Vec3 *) &kart->mUnk_25c = zeroVector;
    kart->mUnk_268 = zeroVector;
    kart->mUnk_274 = 0;
    kart->mForward = zeroVector;
    kart->mHopStartForward = zeroVector;
    kart->mHitVelocity = zeroVector;
    kart->mPrevHitVelocity = zeroVector;
    kart->mUnk_2f0 = zeroVector;
    *(Vec3 *) &kart->mUnk_25c = zeroVector;
    kart->mAirborneFrames = 0;
    kart->mTurnAngle = 0;
    kart->mUnk_38a = 0;
    kart->mTurnedForwardEaseFactor = 0x1000;
    kart->mHeadingAnglePerFrame = 0;
}

void ResetKart(Kart *kart) {
    Vec3 zeroVector;
    u16 i;

    func_0207b8c4(kart->mKartModelsEntry);
    kart->mUnk_44 = 0;
    kart->mUnk_48 = 0;
    kart->mUnk_4c = 0;
    zeroVector = data_02154f94;
    kart->mDrawMatrixPos = zeroVector;
    kart->mPrevPos = kart->mDrawMatrixPos;
    kart->mPos = kart->mPrevPos;
    kart->mVelocity = zeroVector;
    kart->mVelocityDirection = zeroVector;
    kart->mScale.x = 0x1000;
    kart->mScale.y = 0x1000;
    kart->mScale.z = 0x1000;
    kart->mScaleFactor.x = 0x1000;
    kart->mScaleFactor.y = 0x1000;
    kart->mScaleFactor.z = 0x1000;
    kart->mScaleBase.x = 0x1000;
    kart->mScaleBase.y = 0x1000;
    kart->mScaleBase.z = 0x1000;
    kart->mScaleYFactor = 0x1000;
    kart->mGravity = -0x2b9;
    kart->mSpeedLimitGoal = 0;
    kart->mSpeedLimit = 0xd000;
    kart->mUnk_d4 = 0x1000;
    kart->mUnk_d8 = 0x1000;
    kart->mState = KART_STATE_NORMAL;
    func_02071ddc(&kart->mUnk_538);
    MTX_Identity43_(&kart->mUnk_120_m);
    MTX_Identity43_(&kart->mUnk_150_m);
    MTX_Identity43_(&kart->mWobbleMatrix);
    kart->mPointAlongUp = zeroVector;
    kart->mPrevPointAlongUp = kart->mPointAlongUp;
    kart->mPrevCollisionCenter = kart->mPrevPointAlongUp;
    kart->mCollisionCenter = kart->mPrevCollisionCenter;
    kart->mUnk_1f0 = zeroVector;
    kart->mUnk_1fc = zeroVector;
    kart->mSpeedLimitFactor = 0x1000;
    kart->mUnk_e0_m = data_usa_02154f14;
    *(Vec4 *) &kart->mUnk_f0 = data_usa_02154f24;
    *(Vec4 *) &kart->mUnk_100 = data_usa_02154f34;
    *(Vec4 *) &kart->mUnk_108.z = data_usa_02154f44;
    kart->mAirTiltAngle = 0;
    kart->mHeadingAngle = 0;
    kart->mBoostTimer = 0;
    kart->mUnk_23a = 0;
    kart->mMiniTurboTimer = 0;
    kart->mTurnedForwardEaseFactor = 0x1000;
    kart->mGroundNormal = data_02154f7c;
    kart->mUnk_250 = zeroVector;
    *(Vec3 *) &kart->mUnk_25c = zeroVector;
    kart->mUnk_268 = zeroVector;
    kart->mUnk_274 = 0;
    kart->mForward = zeroVector;
    kart->mHopStartForward = zeroVector;
    kart->mTurnedForward = zeroVector;
    kart->mEasedTurnedForward = kart->mTurnedForward;
    kart->mVelocityLengthRatio = 0;
    kart->mVelocityLength = 0;
    kart->mForwardSpeed = 0;
    kart->mLastGroundY = 0;
    kart->mTestedKartMask = 0;
    kart->mNearKartMask = 0;
    kart->mPrevNearKartMask = 0;
    kart->mItemEffect = 0;
    kart->mHopSpeed = 0;
    kart->mHopHeight = 0;
    kart->mHopTiltAngle = 0;
    kart->mTurnDirection = 0;
    kart->mTurnRatio = 0;
    kart->mHitVelocity = zeroVector;
    kart->mUnk_334 = 0;
    kart->mUnk_338 = 0;
    kart->mUnk_33c = 0;
    kart->mUnk_344 = 0;
    kart->mLaunchStartY = kart->mPos.y;
    kart->mLaunchFrames = 0;
    kart->mDriftCharge = 0;
    kart->mRightTurnCount = 0;
    kart->mLeftTurnCount = kart->mRightTurnCount;
    kart->mTowardTurnCounter = NULL;
    kart->mAwayTurnCounter = kart->mTowardTurnCounter;
    kart->mTurnCountTimer = 0;
    kart->mRotationAngle = 0;
    kart->mRotationAngleSum = 0;
    kart->mRotationAxis = zeroVector;
    kart->mRotationQuaternion = data_usa_02154f54;
    kart->mRotationEndFrames = 0;
    kart->mRotationAnglePerFrame = 0;
    kart->mYRotationAngle = 0;
    kart->mYRotationAnglePerFrame = 0;
    kart->mYRotationCount = 0;
    kart->mYRotationAngleSum = 0;
    kart->mUnk_370 = 0;
    kart->mUnk_374 = zeroVector;
    kart->mAirborneFrames = 0;
    kart->mVisible = 0xffff;
    kart->mHeadingAnglePerFrame = 0;
    kart->mTurnAngle = 0;
    kart->mUnk_38a = 0;
    kart->mSpeedLimitHitFactor = 0x1000;
    kart->mUnk_394 = 0x1000;
    kart->mMapObjectVectorLength = 0;
    kart->mMapObjectVectorForwardDot = 0;
    kart->mTireSpinAngle = 0;
    kart->mQuaternionBlendFactor = 0x1ec;
    kart->mSinkFrames = 0;
    kart->mVelocity = zeroVector;
    kart->mUnk_3bc = 0;
    kart->mRaceStartFrameCount = 0;
    kart->mRespawnFrames = 0;
    kart->mRespawnSlot = -1;
    kart->mUnk_3c8 = 0;
    kart->mKartCollisionTimer = 0;
    kart->mKartCollisionDelayTimer = 0;
    kart->mSurfaceGroup = -1;
    kart->mSurfaceKind = 0;
    kart->mSurfaceVariant = 0;
    kart->mUnk_3e8 = 0;
    kart->mTurnHeadingAnglePerFrameGoal = 0;
    kart->mTurnHeadingAnglePerFrame = 0;
    kart->mUnk_3f8 = 0x1000;
    kart->mModelScaleKind = 0;
    kart->mModelScaleFrameIndex = 0;
    kart->mModelScaleFrameCount = 0;
    kart->mModelScaleY = 0x1000;
    kart->mModelScaleX = 0x1000;
    kart->mModelScaleZ = 0x1000;
    for (i = 0; i < 2; i++) {
        kart->mPrevTouchingMapObjects[i] = NULL;
        kart->mUnk_440[i] = 0;
        kart->mUnk_444[i] = 0;
    }
    kart->mUnk_44c = NULL;
    kart->mModelOffsetY = 0;
    kart->mUnk_40c = 0;
    kart->mUnk_410 = 0;
    kart->mUnk_4bc = 0;
    kart->mUnk_4c0 = 0;
    kart->mUnk_4c4 = 0;
    kart->mRadiusFactor = 0x1000;
    kart->mUnk_4d0 = 0;
    kart->mUnk_4d4 = 0;
    kart->mUnk_4d8 = -1;
    kart->mLandingTimer = 0;
    kart->mUnk_4da = 0;
    kart->mHeadingAngleOffset = 0;
    kart->mHeadingAngleOffsetPerFrame = 0;
    kart->mHeadingAngleOffsetDirection = 1;
    kart->mHeadingAngleOffsetCount = 0;
    kart->mUnk_4ec = 0;
    kart->mUnk_4e8 = 0x1000;
    kart->mUnk_4f0 = data_usa_02154f64;
    kart->mUnk_4f0.z = 0;
    kart->mUnk_4fc = 0;
    kart->mWaterDepth = 0;
    kart->mUnk_506 = 0;
    kart->mUnk_504 = kart->mUnk_506;
    kart->mWobbleEasedAmplitude = 0;
    kart->mWobbleAmplitude = kart->mWobbleEasedAmplitude;
    kart->mWobbleAngle = 0;
    kart->mRank = 0;
    func_02068a64(kart, 0, 0);
    kart->mUnk_4cc = 0;
}

void func_02071fb8(Kart *kart, void *heap) {
    ParticipantKartRecordState *q;
    Vec3 zeroVector;
    u16 i;
    u8 *entries;

    q = kart->mUnk_514;
    if (q == NULL) {
        return;
    }
    q->mUnk_00 = kart->mPos;
    q->mUnk_10 = q->mUnk_00;
    q->mUnk_0e = kart->mHeadingAngle;
    q->mUnk_0c = q->mUnk_0e;
    q->mUnk_1c = 0;
    q->mUnk_20 = 0;
    q->mUnk_24 = 0;
    q->mUnk_28 = 0;
    q->mAppliedFlags = 0;
    q->mUnk_2c = q->mAppliedFlags;
    zeroVector = data_02154f94;
    q->mUnk_34 = zeroVector;
    q->mUnk_44 = 0;
    q->mUnk_48 = 0;
    q->mTargetTurnAngle = 0;
    q->mEasedTurnAngle = 0;
    q->mUnk_60 = 0;
    q->mUnk_64 = 0;
    q->mPushDirection = zeroVector;
    q->mUnk_a8 = zeroVector;
    q->mUnk_b4 = 0;
    NNS_FndInitList(&q->mPendingRecords, 0);
    NNS_FndInitList(&q->mFreeRecords, 0);
    entries = HeapAlloc(heap, 0x438);
    for (i = 0; i < 0x1e; i++) {
        NNS_FndAppendListObject(&q->mFreeRecords, entries + i * 0x24);
    }
}

void func_02071f44(Kart *kart) {
    ParticipantKartRecordState *q;

    if (!(kart->mUnk_7c & 0x400)) {
        return;
    }
    q = kart->mUnk_514;
    q->mUnk_00 = kart->mPos;
    q->mUnk_10 = q->mUnk_00;
    q->mUnk_4c = *(Vec4 *) &kart->mUnk_108.z;
    q->mUnk_a8 = data_02154f94;
    q->mUnk_b4 = 0;
}

void func_02071e28(Kart *kart) {
    kart->mUnk_7c = 0;
    if (kart->mIndex == gRaceSetup->mEntryIndex) {
        kart->mUnk_7c |= KART_7C_INDEX_IS_SELECTED_ENTRY;
        if (gRaceSetup->mMode == 5) {
            kart->mUnk_7c |= 0x200;
            if (func_0203c5e4() != 0) {
                kart->mUnk_7c &= ~0x200;
                kart->mUnk_7c |= 0x400;
            }
        }
    } else if (gRaceSetup->mMode == 5) {
        kart->mUnk_7c |= 0x400;
    }
    if (gRaceSetup->mCurrentEntries[kart->mIndex].mPlayer.mKind == PLAYER_KIND_GHOST) {
        kart->mUnk_7c |= KART_7C_ENTRY_KIND_2;
        kart->mVisible = 0;
    }
    if (kart->mKartModelsEntry->mCharacterAnimation != NULL) {
        kart->mUnk_7c |= KART_7C_MODELS_ENTRY_008_SET;
    }
    if (gRaceSetup->mMode == MODE_TIME_ATTACK || IsRaceAwardOrStaffRoll() != 0) {
        kart->mUnk_7c |= 0x8000000;
    }
}

void func_02071ddc(KartItemEffectState *itemEffectState) {
    itemEffectState->mUnk_00 = 0;
    itemEffectState->mUnk_02 = 0;
    itemEffectState->mUnk_04 = 0;
    itemEffectState->mUnk_06 = 0;
    itemEffectState->mUnk_08 = 0;
    itemEffectState->mUnk_0a = 0;
    itemEffectState->mUnk_0c = 0;
    itemEffectState->mUnk_0e = 0;
    itemEffectState->mUnk_12 = 0;
    itemEffectState->mUnk_14 = 0;
    itemEffectState->mUnk_16 = 0;
    itemEffectState->mUnk_18 = 0;
    itemEffectState->mUnk_1c = 0;
    itemEffectState->mKillerFrames = 0;
    itemEffectState->mUnk_20 = 0;
    itemEffectState->mKillerEnding = FALSE;
    itemEffectState->mKillerEndRank = 0;
}

void InitKartSound(Kart *kart) {
    InitSoundSource(&kart->mSoundSource, 0, kart->mPosSource);
    InitKartSoundCallbacks(kart, (Unk0210a5a8 *) &kart->mUnk_450);
    func_020719d0(kart);
    switch (kart->mKartModelsEntry->mUnk_000) {
        case 0:
            kart->mSoundIndex = 4;
            break;
        case 1:
            kart->mSoundIndex = 0;
            break;
        case 2:
            kart->mSoundIndex = 1;
            break;
        case 3:
            kart->mSoundIndex = 2;
            break;
        case 4:
            kart->mSoundIndex = 5;
            break;
        case 5:
            kart->mSoundIndex = 6;
            break;
        case 6:
            kart->mSoundIndex = 7;
            break;
        case 7:
            kart->mSoundIndex = 3;
            break;
        case 8:
            kart->mSoundIndex = 10;
            break;
        case 9:
            kart->mSoundIndex = 8;
            break;
        case 10:
            kart->mSoundIndex = 9;
            break;
        case 11:
            kart->mSoundIndex = 11;
            break;
        case 12:
            kart->mSoundIndex = 12;
            break;
    }
    kart->mUnk_3d0 = kart->mKartModelsEntry->mUnk_004 % 3;
    if (kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) {
        if (!(kart->mSoundSource.mSourceFlags & 1)) {
            SetSoundSourceFlagBit(&kart->mSoundSource, 2, 1);
        }
        if (gRaceSetup->mRaceKind == 2) {
            ResetSoundDistanceSquaredChange(&kart->mUnk_518);
        }
    } else {
        if (kart->mSoundSource.mSourceFlags & 1) {
            SetSoundSourceFlagBit(&kart->mSoundSource, 2, 1);
        }
        ResetSoundDistanceSquaredChange(&kart->mUnk_518);
    }
}

void func_020719d0(Kart *kart) {
    KartSound *kartSound;
    Unk02024eec_40 t;
    s32 i;
    s32 k;
    s32 rowOffset;
    s32 a;
    s32 b;
    s32 c;
    s32 d;
    s32 e;
    s32 f;
    s32 g;

    kart->mUnk_450.mUnk_00 = 0xa5;
    kartSound = (KartSound *) &kart->mUnk_450;
    kartSound->mUnk_04 = 0x64;
    kartSound->mUnk_08 = -1;
    kartSound->mUnk_0c = 0;
    kartSound->mUnk_10 = 0;
    kartSound->mUnk_14 = 0;
    kartSound->mUnk_18 = FX_Div(0x300000, 0xd000 - kart->mPhysicalParam->mBaseSpeedLimit);
    kartSound->mUnk_1c = FX_Div(0x580000, kart->mPhysicalParam->mBaseSpeedLimit);
    kartSound->mUnk_20 = FX_Div(0x480000, kart->mPhysicalParam->mBaseSpeedLimit);
    kartSound->mUnk_24 = FX_Div(0x280000, kart->mPhysicalParam->mBaseSpeedLimit);
    kartSound->mUnk_28 = 0;
    kartSound->mUnk_2c = 0;
    kartSound->mUnk_30 = 0;
    kartSound->mUnk_34 = -1;
    kartSound->mUnk_38 = -1;
    switch (kart->mKartModelsEntry->mUnk_004 / 3) {
        case 0:
            k = 4;
            break;
        case 1:
            k = 0;
            break;
        case 2:
            k = 1;
            break;
        case 3:
            k = 2;
            break;
        case 4:
            k = 5;
            break;
        case 5:
            k = 6;
            break;
        case 6:
            k = 7;
            break;
        case 7:
            k = 3;
            break;
        case 8:
            k = 10;
            break;
        case 9:
            k = 8;
            break;
        case 10:
            k = 9;
            break;
        case 11:
            k = 11;
            break;
        case 12:
            k = 12;
            break;
    }
    kartSound->mUnk_68 = k;
    i = func_0202578c(kart->mKartModelsEntry->mUnk_004);
    rowOffset = i * 0x1c;
    a = *(s32 *) (data_02161ae8 + rowOffset);
    b = *(s32 *) (data_02161aec + rowOffset);
    c = *(s32 *) (data_02161af0 + rowOffset);
    d = *(s32 *) (data_02161af4 + rowOffset);
    e = *(s32 *) (data_02161af8 + rowOffset);
    f = *(s32 *) (data_02161afc + rowOffset);
    g = *(s32 *) (data_02161b00 + rowOffset);
    t.mUnk_00 = i;
    t.mUnk_04 = a;
    t.mUnk_08 = b;
    t.mUnk_0c = c;
    t.mUnk_10 = d;
    t.mUnk_14 = e;
    t.mUnk_18 = f;
    t.mUnk_1c = g;
    if (kart->mIndex != gRaceSetup->mEntryIndex) {
        b = c;
    }
    if (kart->mIndex != gRaceSetup->mEntryIndex) {
        a = c;
    }
    t.mUnk_20 = b;
    t.mUnk_24 = a;
    kartSound->mUnk_40_m = t;
}

PlayingSound *func_020719bc(SoundSource *soundSource, u32 soundId) {
    SoundSource *sourceCopy = soundSource;
    u32 soundIdCopy = soundId;
    u32 volume;
    u32 pitch;
    u32 value12;
    value12 = (u32) &StartSound;
    volume = 0x7fu;
    pitch = 0u;
    return StartSound(sourceCopy, soundIdCopy, volume, pitch);
}

void func_020719a8(u32 soundSource, u32 soundId) {
    u32 sourceCopy = soundSource;
    u32 soundIdCopy = soundId;
    u32 volume;
    u32 pitch;
    u32 value12;
    volume = 0x7fu;
    pitch = 0u;
    StartSoundWhileRequested((SoundSource *) sourceCopy, soundIdCopy, volume, pitch);
}

void func_02071980(void *kart, int entryIndex) {
    StartKartSurfaceSoundWhileRequested(kart, entryIndex, ((Kart *) kart)->mSurfaceKind,
                                        ((Kart *) kart)->mSurfaceVariant, ((Kart *) kart)->mWaterDepth);
}

void func_02071958(Kart *kart, s32 entryIndex) {
    StartSurfaceSound(&kart->mSoundSource, entryIndex, kart->mSurfaceKind, kart->mSurfaceVariant, kart->mWaterDepth);
}

void func_02071944(void *soundSource, int soundId) {
    SoundSource *sourceCopy = soundSource;
    u32 soundIdCopy = soundId;
    u32 volume;
    u32 pitch;
    u32 v6;
    volume = 0x7fu;
    pitch = 0u;
    StartSound(sourceCopy, soundIdCopy, volume, pitch);
}

void func_02071914(void *kart, int soundId) {
    if (StartSoundWhileRequested(kart, soundId, 0x7f, 0) != NULL) {
        ((Kart *) kart)->mUnk_488 = soundId;
    }
}

void func_020718c8(void *kart, int soundId) {
    int sortKeyBase;

    sortKeyBase = func_02086080(((Kart *) kart)->mIndex);
    AddSoundRequest(&data_0217d284, sortKeyBase + func_0210a588(), func_02071914, kart, soundId);
}

void func_02071894(Kart *kart) {
    if (kart->mUnk_48 & 0x840) {
        return;
    }
    func_0210af40(kart, kart->mSoundIndex, 7);
}

void AdvanceKartModelScaleAnimation(Kart *kart) {
    kart->mModelScaleFrameIndex++;
    if (kart->mModelScaleFrameIndex >= kart->mModelScaleFrameCount) {
        kart->mModelScaleFrameIndex = 0;
        kart->mUnk_4c &= ~8;
        return;
    }
    if (kart->mModelScaleKind == 0) {
        kart->mModelScaleY = gKartModelScaleYKind0Table[kart->mModelScaleFrameIndex];
        kart->mModelOffsetY = gKartModelOffsetYKind0And2Table[kart->mModelScaleFrameIndex];
        kart->mModelScaleZ = 0x1000;
        kart->mModelScaleX = kart->mModelScaleZ;
    } else if (kart->mModelScaleKind == 1) {
        kart->mModelScaleY = gKartModelScaleYKind1Table[kart->mModelScaleFrameIndex];
        kart->mModelOffsetY = gKartModelOffsetYKind1Table[kart->mModelScaleFrameIndex];
        kart->mModelScaleZ = 0x1000;
        kart->mModelScaleX = kart->mModelScaleZ;
    } else if (kart->mModelScaleKind == 2) {
        kart->mModelScaleY = 0x1000;
        kart->mModelOffsetY = gKartModelOffsetYKind0And2Table[kart->mModelScaleFrameIndex];
        kart->mModelScaleX = gKartModelScaleXKind2Table[kart->mModelScaleFrameIndex];
        kart->mModelScaleZ = gKartModelScaleZKind2Table[kart->mModelScaleFrameIndex];
    }
}

void func_02071568(Kart *kart) {
    s32 fraction;
    u16 tableIndex;
    u16 nextTableIndex;
    s32 v;
    s32 s;
    s32 t;

    kart->mUnk_4ec = kart->mUnk_4ec + kart->mUnk_4e8;
    t = kart->mUnk_4ec - 0x8000;
    if (t >= 0) {
        kart->mUnk_4ec = t;
    }
    fraction = kart->mUnk_4ec & 0xfff;
    tableIndex = kart->mUnk_4ec >> 12;
    nextTableIndex = tableIndex + 1;
    if (nextTableIndex >= 8) {
        nextTableIndex = 0;
    }
    kart->mUnk_4f0.x =
        data_02154b64[tableIndex] +
        (s32) (((s64) ((data_02154b64[nextTableIndex] - data_02154b64[tableIndex]) >> 1) * fraction) >> 12);
    kart->mUnk_4f0.y =
        data_02154b84[tableIndex] +
        (s32) (((s64) ((data_02154b84[nextTableIndex] - data_02154b84[tableIndex]) >> 1) * fraction) >> 12);
    kart->mUnk_4f0.z =
        data_02154ba4[tableIndex] +
        (s32) (((s64) ((data_02154ba4[nextTableIndex] - data_02154ba4[tableIndex]) >> 1) * fraction) >> 12);
    v = kart->mUnk_4d4;
    s = ((s64) v * 0x333) >> 12;
    if (v > 0xf33) {
        t = ((s64) ((v - 0xf33) * 0x32) * 0x19a) >> 12;
        if (t > 0x19a) {
            t = 0x19a;
        }
        t = t + 0x333;
        s = ((s64) v * t) >> 12;
    } else if (v > 0xd9a) {
        t = ((s64) ((v - 0xd9a) * 0x32) * 0x52) >> 12;
        if (t > 0x52) {
            t = 0x52;
        }
        t = t + 0x333;
        s = ((s64) v * t) >> 12;
    }
    kart->mUnk_4f0.x = kart->mUnk_4f0.x + (s32) (((s64) kart->mUnk_4f0.x * s) >> 12);
    kart->mUnk_4f0.y = kart->mUnk_4f0.y + (s32) (((s64) kart->mUnk_4f0.y * s) >> 12);
    kart->mUnk_4f0.z = kart->mUnk_4f0.z + (s32) (((s64) kart->mUnk_4f0.z * s) >> 12);
}

void AdvanceKartHeadingSwing(Kart *kart) {
    s32 offset;

    if (kart->mHeadingAngleOffsetCount <= 2) {
        kart->mHeadingAngleOffsetPerFrame =
            kart->mHeadingAngleOffsetDirection * 0x3c + kart->mHeadingAngleOffsetPerFrame;
        if (kart->mHeadingAngleOffsetPerFrame > 0x17c) {
            kart->mHeadingAngleOffsetPerFrame = 0x17c;
        } else if (kart->mHeadingAngleOffsetPerFrame < -0x17c) {
            kart->mHeadingAngleOffsetPerFrame = -0x17c;
        }
        kart->mHeadingAngleOffset = kart->mHeadingAngleOffset + kart->mHeadingAngleOffsetPerFrame;
        offset = kart->mHeadingAngleOffset;
        if ((offset > 0 ? offset : -offset) > 0x1770) {
            if ((offset > 0 && kart->mHeadingAngleOffsetDirection > 0) ||
                (offset < 0 && kart->mHeadingAngleOffsetDirection < 0)) {
                kart->mHeadingAngleOffsetDirection *= -1;
                kart->mHeadingAngleOffsetCount = kart->mHeadingAngleOffsetCount + 1;
            }
        }
        kart->mUnk_4d4 = 0x1000;
    } else {
        kart->mHeadingAngleOffsetPerFrame =
            kart->mHeadingAngleOffsetDirection * 0x3c + kart->mHeadingAngleOffsetPerFrame;
        if (kart->mHeadingAngleOffsetPerFrame > 0xd2) {
            kart->mHeadingAngleOffsetPerFrame = 0xd2;
        } else if (kart->mHeadingAngleOffsetPerFrame < -0xd2) {
            kart->mHeadingAngleOffsetPerFrame = -0xd2;
        }
        kart->mHeadingAngleOffset = kart->mHeadingAngleOffset + kart->mHeadingAngleOffsetPerFrame;
        kart->mUnk_4d4 = ((s64) kart->mUnk_4d4 * 0xf5c) >> 12;
        offset = kart->mHeadingAngleOffset;
        if ((offset > 0 && kart->mHeadingAngleOffsetDirection > 0) ||
            (offset < 0 && kart->mHeadingAngleOffsetDirection < 0)) {
            kart->mHeadingAngleOffset = 0;
            kart->mUnk_4c &= ~KART_4C_HEADING_SWING;
            func_02068a64(kart, 0, 1);
            kart->mUnk_44 |= 0x1000000;
        }
    }
}

void StartKartModelScaleAnimation(Kart *kart, s32 a) {
    s32 state;

    state = kart->mState;
    if (state != KART_STATE_NORMAL && state != KART_STATE_LAUNCH_DOUBLE_FLIP) {
        return;
    }
    if (a == 2) {
        kart->mModelScaleKind = 2;
    } else if (kart->mUnk_44 & 2) {
        kart->mModelScaleKind = 1;
    } else if (kart->mAirborneFrames > 0xa) {
        kart->mModelScaleKind = 1;
    } else {
        kart->mModelScaleKind = 0;
    }
    kart->mModelScaleFrameIndex = 0;
    kart->mModelScaleFrameCount = 0xf;
    kart->mUnk_4c |= 8;
}

void ResetKartMotionState(Kart *kart, s32 b) {
    NNSSndSeqPlayer **sndHandleSlot;
    PlayingSound *playingSound;

    if (b == 0) {
        kart->mUnk_48 |= 0x40000;
        kart->mUnk_44 &= ~KART_44_ON_GROUND;
    }
    kart->mUnk_48 &= 0xdfe77fdf;
    kart->mBoostTimer = 0;
    kart->mUnk_538.mUnk_00 = 0;
    kart->mMiniTurboTimer = 0;
    if (kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) {
        if (!(kart->mUnk_4c & 0x10000000) && !(kart->mUnk_48 & 0x4000000)) {
            ResetCameraHalfFovAngleGoal();
        }
        StopDispCapBlend();
    }
    if (kart->mUnk_4c & 0x2000) {
        kart->mUnk_4c &= ~0x2000;
        kart->mUnk_d8 = 0x1000;
        if (!(kart->mUnk_4c & 0x8000000)) {
            func_0207b0d0(kart);
        }
        func_02080ee4(kart);
    }
    func_02080fb8(kart);
    kart->mUnk_44 &= 0xfffff7f4;
    kart->mTurnDirection = 0;
    kart->mDriftCharge = 0;
    kart->mRightTurnCount = 0;
    kart->mLeftTurnCount = kart->mRightTurnCount;
    kart->mTurnCountTimer = 0;
    StopKartTurnEffects(GetKartTurnEffects(kart->mIndex));
    kart->mState = KART_STATE_NORMAL;
    kart->mUnk_4c &= ~0x30;
    kart->mUnk_48 &= ~0x20000;
    func_02068a64(kart, 0, 1);
    kart->mUnk_44 |= 0x80000000;
    func_02072600(kart);
    func_02070f8c(kart);
    if (!(kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY)) {
        return;
    }
    StartCameraWobbleByCourse();
    switch (gRaceSetup->mCourseId) {
        case COURSE_ID_AIRSHIP:
            func_02089d14(0);
            playingSound = StartSound((SoundSource *) kart, 0x15c, 0x7f, 0);
            if (playingSound != NULL) {
                playingSound->mFlags |= 0x10;
            }
            sndHandleSlot = GetSndHandleSlot(7);
            if (!(data_0217c780 & 1)) {
                return;
            }
            if (data_0217d084.mUnk_0c == 0) {
                return;
            }
            if (sndHandleSlot[0] != NULL) {
                NNS_SndPlayerStopSeq(sndHandleSlot, 0);
            }
            if (sndHandleSlot[0] != NULL) {
                NNS_SndPlayerStopSeq(sndHandleSlot, 0);
            }
            NNS_SndArcPlayerStartSeqArc(sndHandleSlot, 0, 0x1d2);
            break;
        case COURSE_ID_PINBALL:
            playingSound = StartSound((SoundSource *) kart, 0x15b, 0x7f, 0);
            if (playingSound != NULL) {
                playingSound->mFlags |= 0x10;
            }
            break;
    }
}

void func_02070f8c(Kart *kart) {
    s32 effectIdsOther[2];
    Vec3 effectPos;
    Vec3 effectIdsSelected;
    Camera *currentCamera;
    Vec3 *cameraPos;
    BOOL cameraOutsideBox;
    s32 effectCount;
    s32 i;
    s32 *nextEffectId;
    s32 *w;

    effectPos = data_0216553c;
    cameraOutsideBox = TRUE;
    currentCamera = GetCurrentCamera();
    cameraPos = &currentCamera->mPos;
    if (cameraPos->x > -0x64f000) {
        if (cameraPos->x < -0x3cb000) {
            if (cameraPos->z > -0x1ad7000) {
                if (cameraPos->z < -0x164d000) {
                    cameraOutsideBox = FALSE;
                }
            }
        }
    }
    if (cameraOutsideBox != FALSE) {
        effectIdsSelected = data_02165548;
        w = effectIdsOther;
        effectIdsOther[0] = data_02165510[0];
        effectIdsOther[1] = data_02165510[1];
        effectCount = 3;
        nextEffectId = (s32 *) &effectIdsSelected;
        if (!(kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY)) {
            effectCount = 2;
            nextEffectId = w;
        }
        for (i = 0; i < effectCount; i++) {
            StartEffect(*nextEffectId, &effectPos);
            nextEffectId++;
        }
    } else {
        StartEffect((kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) ? 0x47 : 0x52, &effectPos);
    }
}

static inline s32 func_020708a4_inline(Vec3 *src, Vec3 *dst) {
    if ((s64) src->x * src->x + (s64) src->y * src->y + (s64) src->z * src->z < 0x10) {
        return 0;
    }
    return Vec3NormalizeAndGetLengthUnchecked(src, dst);
}

void AdvanceKartToKeyedPlacement(Kart *kart) {
    KartItemEffectState *itemEffectState;
    u16 placementIndex;
    s32 distance;
    s32 angleIndex;
    s32 t;
    u32 flags;
    Vec3 placementPos;
    Vec3 placementAngles;
    Vec3 groundNormal;
    Vec3 toTarget;
    Vec3 placementForward;
    Vec3 side;
    Vec3 toKart;
    Vec3 flatForward;
    Vec3 l;
    MtxFx43 m2;
    s32 rotationMatrix[9];
    Vec3 axis;

    placementAngles = data_02154f94;
    placementIndex = *gCourseMap->mKeyedPlacementIndexByKey;
    placementPos.x = gCourseMap->mKeyedPlacements[placementIndex].mPos.x;
    placementPos.y = gCourseMap->mKeyedPlacements[placementIndex].mPos.y;
    placementPos.z = gCourseMap->mKeyedPlacements[placementIndex].mPos.z;
    placementAngles.x = gCourseMap->mKeyedPlacements[*gCourseMap->mKeyedPlacementIndexByKey].mUnk_0c.x;
    placementAngles.y = gCourseMap->mKeyedPlacements[*gCourseMap->mKeyedPlacementIndexByKey].mUnk_0c.y;
    placementAngles.z = gCourseMap->mKeyedPlacements[*gCourseMap->mKeyedPlacementIndexByKey].mUnk_0c.z;
    angleIndex = (u16) (((s64) placementAngles.y * 0xb60b60b60bLL + 0x80000000LL) >> 44) >> 4;
    MTX_RotY33_(rotationMatrix, gPairsByAngle[angleIndex * 2], gPairsByAngle[angleIndex * 2 + 1]);
    MTX_MultVec33(&data_02154f70, rotationMatrix, &placementForward);
    SkipOrthoQuadsHoldAndSetVelocities(kart->mIndex);

    flags = kart->mUnk_4c;
    if (!(flags & 0x20000) && (flags & 0x8000000)) {
        itemEffectState = &kart->mUnk_538;
        if (itemEffectState->mUnk_1c <= 0x190) {
            itemEffectState->mUnk_1c = 0x190;
            kart->mUnk_4c |= 0x20000;
            StartKartModelColorBlend(kart->mKartModelsEntry, GetKartCourseDiffColor(), GetKartCourseEmiColor(),
                                     GetKartCourseAmbColor());
        }
    }
    if (kart->mUnk_4c & 0x8000000) {
        AdvanceKartGesso(kart);
    }
    flags = kart->mUnk_4c;
    if (flags & 0x10000000) {
        AdvanceKartKiller(kart);
    } else {
        if (flags & KART_4C_THUNDER_SHRINK) {
            AdvanceKartThunderShrink(kart);
        }
        if (kart->mUnk_4c & 0x10000) {
            func_02069f6c(kart);
        }
        if (kart->mUnk_7c & 0x402000) {
            AdvanceKartTeresa(kart);
        }
    }

    if (kart->mUnk_4c & 0x2000) {
        itemEffectState = &kart->mUnk_538;
        if (kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) {
            AddSoundRequest(data_0217d26c, func_02086080(kart->mIndex), func_020718c8, kart, 0xa3);
        }
        itemEffectState->mUnk_0a++;
        if (itemEffectState->mUnk_0a > KART_KILLER_RANK_END_FRAMES && (kart->mUnk_4c & 0x2000)) {
            kart->mUnk_4c &= ~0x2000;
            kart->mUnk_d8 = 0x1000;
            if (!(kart->mUnk_4c & 0x8000000)) {
                func_0207b0d0(kart);
            }
            func_02080ee4(kart);
        }
    }

    if (kart->mUnk_4c & 0x40) {
        itemEffectState = &kart->mUnk_538;
        AdvanceKartStarEffects(kart->mIndex);
        if ((kart->mUnk_7c & KART_7C_MODELS_ENTRY_008_SET) &&
            kart->mKartModelsEntry->mCharacterAnimation->mUnk_1a == 0) {
            func_02068a64(kart, 2, 1);
        }
        itemEffectState->mUnk_06++;
        if (itemEffectState->mUnk_06 > KART_TERESA_MAX_FRAMES) {
            kart->mUnk_4c &= ~0x40;
            func_0207b1a8(kart);
            kart->mItemEffect = 0;
            StopKartStarEffects(kart->mIndex);
            func_02068a64(kart, 0, 1);
            if ((kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) && gRaceSetup->mRaceKind == RACE_KIND_NORMAL) {
                func_02106dc8();
            }
            if (kart->mUnk_4c & 0x2000) {
                func_0207b13c(kart);
            }
        }
    }

    data_0217566a[kart->mEntryIndex].mBitMask = 0xe04;
    Vec3CrossUnrounded(&data_02154f7c, &placementForward, &side);
    VEC_Subtract(&kart->mPos, &placementPos, &toKart);
    toKart.y = 0;
    VEC_MultAdd(Vec3DotUnrounded(&side, &toKart), &side, &placementPos, &placementPos);
    Vec3DotUnrounded(&side, &toKart);
    VEC_Subtract(&placementPos, &kart->mPos, &toTarget);
    distance = func_020708a4_inline(&toTarget, &toTarget);

    if (Vec3DotUnrounded(&toTarget, &placementForward) <= 0) {
        StopDispCapBlend();
        kart->mUnk_48 &= ~0x10000;
        AdvanceKartQuaternionBlendFactor(kart, &kart->mGroundNormal);
        kart->mUnk_48 &= ~0x40000;
        kart->mUnk_3e8 = (s16) ((s32) (((s64) placementAngles.x * 0x4000) >> 12) >> 12) + 0x32;
        if ((kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) && gRaceSetup->mCourseId == COURSE_ID_AIRSHIP) {
            NNS_SndPlayerStopSeq(GetSndHandleSlot(7), 0x14);
        }
    } else {
        if (distance > 0x64000) {
            kart->mTurnedForward = toTarget;
        }
        flatForward = kart->mTurnedForward;
        flatForward.y = 0;
        kart->mQuaternionBlendFactor = 0x1000;
        func_020708a4_inline(&flatForward, &flatForward);
        kart->mHeadingAngle = (s32) (((s64) FX_Atan2(flatForward.x, flatForward.z) * 0x28be60d) >> 12) >> 12;
        axis = data_02165524;
        QuaternionFromAxisAngle(&axis, kart->mHeadingAngle, (Vec4 *) &kart->mUnk_e0);
        Vec3CrossUnrounded(&data_02154f7c, &kart->mTurnedForward, &l);
        Vec3CrossUnrounded(&kart->mTurnedForward, &l, &groundNormal);
        if (kart->mAirTiltAngle > -5000) {
            kart->mAirTiltAngle -= 300;
            if (kart->mAirTiltAngle < -5000) {
                kart->mAirTiltAngle = -5000;
            }
        }
        MTX_RotAxis33(&m2, &kart->mUnk_120, gPairsByAngle[((u16) kart->mAirTiltAngle >> 4) * 2],
                      gPairsByAngle[((u16) kart->mAirTiltAngle >> 4) * 2 + 1]);
        MTX_MultVec33(&groundNormal, &m2.mUnk_00[0].x, &groundNormal);
        kart->mGroundNormal = groundNormal;
        AdvanceKartOrientation(kart, &groundNormal);
    }

    kart->mForwardSpeed = 0x1e000;
    t = kart->mForwardSpeed;
    m2.mUnk_00[3].x = ((s64) kart->mTurnedForward.x * t) >> 12;
    m2.mUnk_00[3].y = ((s64) kart->mTurnedForward.y * t) >> 12;
    m2.mUnk_00[3].z = ((s64) kart->mTurnedForward.z * t) >> 12;
    kart->mEasedTurnedForward = kart->mTurnedForward;
    if (distance < 0x3e8000) {
        t = (s32) (((s64) distance * 0x29) >> 12) + 0x14000;
        if (kart->mForwardSpeed > t) {
            kart->mForwardSpeed = t;
        }
    }
    kart->mVelocity = m2.mUnk_00[3];
    VEC_Add(&kart->mPos, &kart->mVelocity, &kart->mPos);
}

void PlaceKartAtKeyedPlacement(Kart *kart, u32 key) {
    Vec3 placementPos;
    Vec3 placementForward;
    s32 rotationMatrix[9];
    Vec3 offset;
    Vec3 axis;
    NNSSndSeqPlayer **sndHandle;
    u16 placementIndex;
    s32 angleIndex;

    ResetKartMotionState(kart, 1);
    kart->mVerticalSpeed = 0x3000;
    placementIndex = gCourseMap->mKeyedPlacementIndexByKey[key];
    placementPos.x = gCourseMap->mKeyedPlacements[placementIndex].mPos.x;
    placementPos.y = gCourseMap->mKeyedPlacements[placementIndex].mPos.y;
    placementPos.z = gCourseMap->mKeyedPlacements[placementIndex].mPos.z;
    angleIndex = (u16) (((s64) gCourseMap->mKeyedPlacements[gCourseMap->mKeyedPlacementIndexByKey[key]].mUnk_0c.y *
                             0xb60b60b60bLL +
                         0x80000000LL) >>
                        44) >>
                 4;
    MTX_RotY33_(rotationMatrix, gPairsByAngle[angleIndex * 2], gPairsByAngle[angleIndex * 2 + 1]);
    MTX_MultVec33(&data_02154f70, rotationMatrix, &placementForward);
    if (gRaceSetup->mMode == MODE_BATTLE) {
        VEC_Subtract(&placementPos, &kart->mPos, &offset);
        CallStandingsKartOffsetCallback(kart->mIndex, (s32) &offset);
    }
    kart->mPos = placementPos;
    kart->mPrevPos = kart->mPos;
    kart->mDrawMatrixPos = kart->mPrevPos;
    kart->mForwardSpeed = 0x5000;
    kart->mTurnedForward = placementForward;
    kart->mEasedTurnedForward = kart->mTurnedForward;
    kart->mHeadingAngle = (s32) (((s64) FX_Atan2(placementForward.x, placementForward.z) * 0x28be60dLL) >> 12) >> 12;
    axis = data_02165524;
    QuaternionFromAxisAngle(&axis, kart->mHeadingAngle, (Vec4 *) &kart->mUnk_e0);
    if (kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) {
        SetupCameraBehindKart();
        if (data_0217c780 & 1) {
            sndHandle = TakeSoundHandleEntry(func_02108ea0(0));
            if (data_0217d084.mUnk_0c != 0) {
                if (sndHandle[0] != NULL) {
                    NNS_SndPlayerStopSeq(sndHandle, 0);
                }
                if (sndHandle[0] != NULL) {
                    NNS_SndPlayerStopSeq(sndHandle, 0);
                }
                NNS_SndArcPlayerStartSeqArc(sndHandle, 0, 0x159);
            }
        }
    }
    if (!(kart->mUnk_7c & 2)) {
        return;
    }
    if (gRaceSetup->mMode != MODE_BATTLE) {
        return;
    }
    ResetBattleKartAiAtPointLink(kart->mAi, GetKeyedPlacementBattlePointLink(key));
}

void func_02070484(Kart *kart, Vec4 *quaternion) {
    MtxFx43 m1;
    MtxFx43 m2;
    Vec3 v1;
    Vec3 v2;
    s32 dot;
    u16 headingAngle;
    u16 airTiltAngle;

    if (kart->mVelocityLength < 0x1000) {
        return;
    }
    if (Vec3DotUnrounded(&kart->mUnk_12c, &data_02154f7c) <= 0) {
        return;
    }
    kart->mAirTiltAngle = kart->mAirTiltAngle + kart->mUnk_3e8;
    headingAngle = kart->mHeadingAngle;
    airTiltAngle = kart->mAirTiltAngle;
    MTX_RotY43_(&m1, gPairsByAngle[(headingAngle >> 4) * 2], gPairsByAngle[(headingAngle >> 4) * 2 + 1]);
    MTX_MultVec43(&data_02154f88, &m1, &v1);
    MTX_RotAxis43(&m2, &v1, gPairsByAngle[(airTiltAngle >> 4) * 2], gPairsByAngle[(airTiltAngle >> 4) * 2 + 1]);
    MTX_MultVec43(&data_02154f7c, &m2, &v2);
    TryQuaternionFromVectors(quaternion, &data_02154f7c, &v2);
    if (kart->mUnk_48 & 0x80000000) {
        quaternion->x = -quaternion->x;
        quaternion->y = -quaternion->y;
        quaternion->z = -quaternion->z;
        quaternion->w = -quaternion->w;
    }
    if (kart->mUnk_44 & 2) {
        return;
    }
    dot = Vec3DotUnrounded(&kart->mVelocityDirection, &kart->mUnk_138);
    if (dot <= 0) {
        dot = -dot;
    }
    kart->mUnk_3f8 = dot;
    if (kart->mUnk_3f8 < 0xb33) {
        kart->mUnk_3f8 = 0xb33;
    }
}

BOOL TryHoldKartStill(Kart *kart, u32 b, void *c) {
    u32 flags;

    flags = kart->mUnk_44;
    if (!(flags & 0xc2200) && !(kart->mUnk_7c & 0x400)) {
        if (!(flags & 0xc0000) && !(kart->mUnk_4c & 0x100) && kart->mUnk_1fc.x == 0 && kart->mUnk_1fc.y == 0 &&
            kart->mUnk_1fc.z == 0 && kart->mUnk_274 == 0 && kart->mUnk_4d0 >= 0x64) {
            kart->mPos.x = kart->mPrevPos.x;
            kart->mPos.z = kart->mPrevPos.z;
        } else {
            func_020d5aa0(c, b, (Unk020e04b0 *) kart->mUnk_208, &kart->mPos, NULL);
        }
        kart->mVelocity = data_02154f94;
        kart->mVelocityLength = 0;
        kart->mUnk_44 |= 0x1000;
        return TRUE;
    }
    return FALSE;
}
