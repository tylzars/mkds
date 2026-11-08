#include "ITCM/code_01ffb130.h"
#include "ITCM/code_01ff9598.h"
#include "ITCM/code_01ffad14.h"
#include "ITCM/code_01ff9000.h"
#include "ITCM/code_01ffb000.h"
#include "ITCM/code_01ffb930.h"
#include "ITCM/code_01ffba68.h"
#include "ITCM/code_01ffc000.h"
#include "ITCM/code_01ffcf7c.h"
#include "ITCM/code_01ffd000.h"
#include "Main/Unknown/code_02068eac.h"
#include "Main/Unknown/code_02069000.h"
#include "Main/Unknown/code_0206a000.h"
#include "Main/Unknown/code_0206d000.h"
#include "Main/Unknown/code_0206d020.h"
#include "Main/Unknown/code_0206dfd0.h"
#include "Main/Unknown/code_0206e000.h"
#include "Main/Unknown/code_02070398.h"
#include "Main/Unknown/code_0207a000.h"
#include "Main/Unknown/code_0207a74c.h"
#include "Main/Unknown/code_0207b000.h"
#include "Main/Unknown/code_02080cd0.h"
#include "Main/Unknown/code_02081618.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02086058.h"
#include "Main/Unknown/code_020e6fd4.h"
#include "Main/Unknown/code_02105ec0.h"
#include "Main/Unknown/code_0210dc7c.h"
#include "Main/Unknown/code_020ed5c0.h"
#include "Main/Unknown/unk_02154000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_02165000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "code_02146d78.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_0206a354.h"
#include "Main/Unknown/code_0206e874.h"
#include "Main/Unknown/code_020681f0.h"

void func_01ffb130(Kart *p) {
    s32 k;
    s32 a;
    s32 b;
    Vec3 v1;
    Vec3 v2;
    MtxFx33 m1;
    MtxFx33 m2;
    Vec3 v3;
    Vec3 v4;
    Unk0206ceb4 *q;
    s32 d;
    s32 f;
    u32 w;

    b = p->mUnk_3f8;
    if (p->mUnk_4c & 0x8000000) {
        func_02069134(p);
    }
    w = p->mUnk_4c;
    if (w & 0x10000000) {
        AdvanceKartKiller(p);
    } else {
        if (w & KART_4C_THUNDER_SHRINK) {
            AdvanceKartThunderShrink(p);
        }
        if (p->mUnk_4c & 0x10000) {
            func_02069f6c(p);
        }
        if (p->mUnk_7c & 0x402000) {
            AdvanceKartTeresa(p);
        }
    }
    if (p->mUnk_4c & 0x2000) {
        q = &p->mUnk_538;
        if (p->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) {
            AddSoundRequest(data_0217d26c, func_02086080(p->mIndex), func_020718c8, p, 0xa3);
        }
        q->mUnk_0a++;
        if (q->mUnk_0a > 0xb4 && (p->mUnk_4c & 0x2000)) {
            p->mUnk_4c &= ~0x2000;
            p->mUnk_d8 = 0x1000;
            if (!(p->mUnk_4c & 0x8000000)) {
                func_0207b0d0(p);
            }
            func_02080ee4(p);
        }
    }
    if (p->mUnk_4c & 0x40) {
        q = &p->mUnk_538;
        AdvanceKartStarEffects(p->mIndex);
        if ((p->mUnk_7c & KART_7C_MODELS_ENTRY_008_SET) && p->mKartModelsEntry->mCharacterAnimation->mUnk_1a == 0) {
            func_02068a64(p, 2, 1);
        }
        q->mUnk_06++;
        if (q->mUnk_06 > 0x1c2) {
            p->mUnk_4c &= ~0x40;
            func_0207b1a8(p);
            p->mItemEffect = 0;
            StopKartStarEffects(p->mIndex);
            func_02068a64(p, 0, 1);
            if ((p->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) && gRaceSetup->mRaceKind == RACE_KIND_NORMAL) {
                func_02106dc8();
            }
            if (p->mUnk_4c & 0x2000) {
                func_0207b13c(p);
            }
        }
    }
    if ((p->mUnk_48 & 0x800) && AdvanceKartRespawnWait(p, &b) != 0) {
        return;
    }
    if (p->mUnk_7c & 0x20) {
        return;
    }
    gKartStateFunctions[p->mState](p);
    func_01ffb9e0(p);
    if (p->mUnk_48 & 0x40) {
        p->mSinkFrames++;
        if (p->mSinkFrames > 0x41) {
            p->mUnk_48 &= ~0x240;
            if (p->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) {
                func_020e7a18();
            }
        } else {
            p->mPos.y -= 0x19a;
        }
    } else {
        ApplyKartGravity(p);
    }
    if (p->mUnk_44 & KART_44_ON_GROUND) {
        GetKartForward(p, &v2);
        if (!(p->mUnk_48 & 6) && p->mGroundNormal.y > 0 && (v2.y > 0 ? v2.y : -v2.y) > 0xcd &&
            p->mSpeedLimitHitFactor <= 0) {
            p->mForwardSpeed += (s32) (((s64) -v2.y * 0x19a) >> 12);
        }
    }
    if ((p->mUnk_44 & KART_44_ON_GROUND) || (p->mUnk_4c & 0x10000000)) {
        MTX_RotAxis33((MtxFx43 *) &m1, &p->mGroundNormal, gPairsByAngle[((u16) p->mTurnAngle >> 4) * 2],
                      gPairsByAngle[((u16) p->mTurnAngle >> 4) * 2 + 1]);
        if (p->mUnk_48 & 1) {
            MTX_RotAxis33((MtxFx43 *) &m2, &p->mUnk_120, gPairsByAngle[0xba], gPairsByAngle[0xbb]);
            MTX_Concat33(m2.mUnk_00, m1.mUnk_00, m1.mUnk_00);
        }
        MTX_MultVec33(&p->mForward, m1.mUnk_00, &p->mTurnedForward);
        d = VEC_DotProduct(&p->mGroundNormal, &p->mTurnedForward);
        v3.x = p->mTurnedForward.x - (s32) (((s64) p->mGroundNormal.x * d) >> 12);
        v3.y = p->mTurnedForward.y - (s32) (((s64) p->mGroundNormal.y * d) >> 12);
        v3.z = p->mTurnedForward.z - (s32) (((s64) p->mGroundNormal.z * d) >> 12);
        p->mUnk_d4 = VEC_Mag(&v3);
    } else {
        d = Vec3DotUnrounded(&p->mForward, &p->mGroundNormal);
        p->mTurnedForward = p->mForward;
        if (p->mUnk_3e8 > 0) {
            p->mUnk_d4 = 0x1000;
        } else if (d < 0) {
            p->mUnk_d4 = 0x1000 - d;
        } else {
            p->mUnk_d4 = 0x1000;
        }
    }
    a = LimitKartForwardSpeedAndGetScaled(p);
    ReduceKartSpeedByTurnRatio(&a, p);
    if ((p->mUnk_44 & 0x90) || (p->mUnk_4c & 0x10000000)) {
        k = p->mTurnedForwardEaseFactor;
        VEC_Subtract(&p->mTurnedForward, &p->mEasedTurnedForward, &v4);
        v4.x = ((s64) v4.x * k) >> 12;
        v4.y = ((s64) v4.y * k) >> 12;
        v4.z = ((s64) v4.z * k) >> 12;
        VEC_Add(&p->mEasedTurnedForward, &v4, &p->mEasedTurnedForward);
        p->mEasedTurnedForward.y = p->mTurnedForward.y;
    }
    v1.x = ((s64) p->mEasedTurnedForward.x * a) >> 12;
    v1.y = ((s64) p->mEasedTurnedForward.y * a) >> 12;
    v1.z = ((s64) p->mEasedTurnedForward.z * a) >> 12;
    if (a >= 0) {
        p->mSignedTurnedForward = p->mTurnedForward;
    } else {
        p->mSignedTurnedForward.x = -p->mTurnedForward.x;
        p->mSignedTurnedForward.y = -p->mTurnedForward.y;
        p->mSignedTurnedForward.z = -p->mTurnedForward.z;
    }
    if (p->mState == KART_STATE_LAUNCH_DOUBLE_FLIP) {
        v1.y = 0;
    }
    p->mVelocity = v1;
    VEC_Add(&p->mVelocity, &p->mUnk_374, &p->mVelocity);
    p->mVelocity.y += p->mVerticalSpeed;
    VEC_MultAdd(p->mUnk_274, &p->mUnk_268, &p->mVelocity, &p->mVelocity);
    if (!(p->mUnk_44 & KART_44_ON_GROUND) && p->mAirborneFrames > 5 && p->mVelocity.y < -0x6000) {
        p->mVelocity.y = -0x6000;
    }
    VEC_Add(&p->mVelocity, &p->mUnk_2f0, &p->mVelocity);
    VEC_Add(&p->mVelocity, &p->mUnk_1fc, &p->mVelocity);
    AdvanceKartHop(p);
    ScaleKartVelocityAndSetCappedLengthAndDirection(p, b);
    if (p->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) {
        SetKartForwardSpeedRatio(Vec3DotUnrounded(&p->mVelocity, &p->mTurnedForward));
        if ((p->mUnk_44 & 0x1000000) && p->mUnk_4d4 != 0) {
            p->mUnk_4d4 = ((s64) p->mUnk_4d4 * 0xfae) >> 12;
            if (p->mUnk_4d4 < 0xcd) {
                p->mUnk_4d4 = 0;
            }
        }
    }
    if (!(p->mUnk_7c & 0x20)) {
        VEC_Add(&p->mPos, &p->mVelocity, &p->mPos);
        p->mSpeedLimitHitFactor = 0x1000;
    }
    f = (p->mUnk_44 & KART_44_ON_GROUND) ? 0xee1 : 0xfae;
    p->mHitVelocity.x = ((s64) p->mHitVelocity.x * f) >> 12;
    p->mHitVelocity.y = ((s64) p->mHitVelocity.y * f) >> 12;
    p->mHitVelocity.z = ((s64) p->mHitVelocity.z * f) >> 12;
    if ((s64) p->mHitVelocity.x * p->mHitVelocity.x + (s64) p->mHitVelocity.y * p->mHitVelocity.y +
            (s64) p->mHitVelocity.z * p->mHitVelocity.z >=
        0xa429) {
        p->mUnk_44 |= 0x2000;
    } else {
        p->mHitVelocity = data_02154f94;
        p->mUnk_44 &= ~0x2000;
    }
    FindCollisionSlotsOverlappingSlot(p->mCollisionSlot, 0xe800);
    func_0206e874(p);
    if (p->mUnk_7c & 0x8000000) {
        return;
    }
    ComputeKartPointAlongUp(&p->mPointAlongUp, p->mUnk_510, p->mPhysicalParam->mUnk_04, p);
    func_0206d18c(p);
    CollideKartWithKarts(p);
    func_0206d578(p);
}
