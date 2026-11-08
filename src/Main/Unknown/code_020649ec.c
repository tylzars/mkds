#include "Main/Unknown/code_020649ec.h"
#include "ITCM/code_01ff9000.h"
#include "ITCM/code_01ff9598.h"
#include "ITCM/code_01ffa4b4.h"
#include "ITCM/code_01ffad14.h"
#include "ITCM/code_01ffb000.h"
#include "ITCM/code_01ffb130.h"
#include "ITCM/code_01ffba68.h"
#include "ITCM/code_01ffc000.h"
#include "ITCM/code_01ffcf7c.h"
#include "ITCM/code_01ffd000.h"
#include "ITCM/code_01ffdee4.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02066ac0.h"
#include "Main/Unknown/code_020681f0.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_02064000.h"
#include "Main/Unknown/code_020641b8.h"
#include "Main/Unknown/code_020646c0.h"
#include "Main/Unknown/code_020649e8.h"
#include "Main/Unknown/code_02066000.h"
#include "Main/Unknown/code_02068000.h"
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
#include "Main/Unknown/code_02070398.h"
#include "Main/Unknown/code_02071000.h"
#include "Main/Unknown/code_02079bcc.h"
#include "Main/Unknown/code_020ed5c0.h"
#include "Main/Unknown/code_0207b000.h"
#include "Main/Unknown/code_02081618.h"
#include "Main/Unknown/code_0208ab98.h"
#include "Main/Unknown/code_0208c188.h"
#include "code_02147cd8.h"
#include "Main/Unknown/unk_02154000.h"
#include "Main/Unknown/code_02063b70.h"
#include "Main/Unknown/code_02062ed8.h"

void func_020651fc(Kart *kart) {
    Unk0206bcb0_514 *b;
    s32 tableIndex;
    u32 f;

    f = kart->mUnk_7c;
    if ((f & 0xa0) != 0) {
        if ((f & 0x20) != 0) {
            func_02068b98(kart);
            return;
        }
        kart->mUnk_3c8 = kart->mUnk_3c8 + 1;
        tableIndex = kart->mUnk_3c8;
        if (tableIndex >= 0x19) {
            kart->mUnk_7c = kart->mUnk_7c & ~0x80;
            return;
        }
        kart->mScaleFactor.x = gKartScaleFactorXTable[tableIndex];
        kart->mScaleFactor.y = gKartScaleFactorYTable[tableIndex];
        kart->mScaleFactor.z = gKartScaleFactorZTable[tableIndex];
        kart->mScale.x = (s64) kart->mScaleBase.x * kart->mScaleFactor.x >> 12;
        kart->mScale.y = (s64) kart->mScaleBase.y * kart->mScaleFactor.y >> 12;
        kart->mScale.z = (s64) kart->mScaleBase.z * kart->mScaleFactor.z >> 12;
        kart->mScale.y = (s64) kart->mScaleYFactor * kart->mScale.y >> 12;
        return;
    }
    b = kart->mUnk_514;
    Matrix4x3FromQuaternion(&kart->mUnk_120, &kart->mUnk_110_q);
    func_02066ac0(kart);
    if (kart->mForwardSpeed > 0x3000) {
        b->mUnk_a8 = data_02154f94;
    }
    func_01ffca50(kart);
    UpdateKartSpeedLimitGoal(kart);
    UpdateKartSpeedLimit(kart);
    func_01ffbd9c(kart);
    func_01ffc6c0(kart);
    func_01ff9d18(kart);
    b = kart->mUnk_514;
    b->mUnk_64 = b->mUnk_64 + kart->mGravity;
    b->mUnk_60 = b->mUnk_60 + b->mUnk_64;
    if (b->mUnk_60 < 0) {
        b->mUnk_60 = 0;
        b->mUnk_64 = 0;
    }
    if (IsRaceStarted() == 1) {
        kart->mUnk_230 = func_01ffb0cc;
    }
    if ((kart->mUnk_514->mUnk_44 & 1) != 0) {
        kart->mVerticalSpeed = 0;
    }
    func_01ffb130(kart);
}

void func_02064f50(Kart *kart) {
    Unk0206bcb0_514 *b;
    s32 c;
    Vec3 groundNormal;
    Vec3 e;
    Vec3 i;
    Vec3 h;
    Vec3 g;
    Vec3 f;
    u32 j;
    Vec3 *k;

    b = kart->mUnk_514;
    if ((kart->mUnk_7c & 0x20) != 0) {
        return;
    }
    if ((kart->mUnk_44 & KART_44_NEAR_KART) != 0) {
        kart->mUnk_44 = kart->mUnk_44 | 0x80000;
    } else {
        kart->mUnk_44 = kart->mUnk_44 & ~0x80000;
    }
    ComputeKartPointAlongUp(&kart->mCollisionCenter, &kart->mPos, 0x400, kart);
    func_01ffa4b4(kart, &groundNormal);
    func_02064d60(kart, &groundNormal);
    kart->mGroundNormal = groundNormal;
    kart->mUnk_4d0 = kart->mUnk_4d0 + 1;
    func_01ffc920(kart);
    AdvanceKartCollisionTimer(kart);
    if ((kart->mUnk_4c & 0x8000) != 0) {
        ComputeKartSidePoints(kart);
    }
    if ((kart->mUnk_4c & 8) != 0) {
        AdvanceKartModelScaleAnimation(kart);
    }
    kart->mUnk_230(kart);
    e = kart->mPos;
    e.y = e.y - b->mUnk_60;
    c = b->mUnk_24;
    VEC_Subtract(&e, &b->mUnk_00, &f);
    f.x = (s64) f.x * c >> 12;
    f.y = (s64) f.y * c >> 12;
    f.z = (s64) f.z * c >> 12;
    VEC_Add(&b->mUnk_00, &f, &b->mUnk_00);
    if ((kart->mUnk_514->mUnk_44 & 1) != 0) {
        ComputeKartPointAlongUp(&g, &b->mUnk_00, 0x400, kart);
        k = &kart->mUnk_12c;
        h.x = (s64) k->x * -0x7000 >> 12;
        h.y = (s64) k->y * -0x7000 >> 12;
        h.z = (s64) k->z * -0x7000 >> 12;
        VEC_Add(&g, &h, &g);
        if (func_01ffdee4(&g, NULL, 0, kart->mRadius, 1, kart->mCollisionSlot, &i, NULL, NULL, &j, NULL, NULL, NULL,
                          NULL) != 0) {
            VEC_Add(&i, &h, &i);
            VEC_Add(&b->mUnk_00, &i, &b->mUnk_00);
        }
    }
    b->mUnk_10 = b->mUnk_00;
    b->mUnk_10.y = b->mUnk_10.y + b->mUnk_60;
    QuaternionBlend(&b->mUnk_4c, &kart->mUnk_110_q, &b->mUnk_4c, 0x333);
}

void func_02064d60(Kart *kart, Vec3 *groundNormal) {
    Unk0206bcb0_514 *c;
    Vec4 hopTiltQuaternion;
    s32 headingDifference;
    s32 f;

    c = kart->mUnk_514;
    kart->mUnk_3f8 = 0x1000;
    if (kart->mAirborneFrames > 5 && (kart->mUnk_514->mUnk_44 & 1) == 0) {
        kart->mQuaternionBlendFactor = 0xf6;
        func_02070484(kart, &kart->mUnk_100_q);
    } else {
        AdvanceKartQuaternionFromVector(kart, groundNormal);
    }
    QuaternionBlend(&kart->mUnk_f0_q, &kart->mUnk_100_q, &kart->mUnk_f0_q, kart->mQuaternionBlendFactor);
    headingDifference = kart->mHeadingAngle - c->mUnk_0e;
    if ((headingDifference > 0 ? headingDifference : -headingDifference) > 0x7fff) {
        if (headingDifference > 0) {
            headingDifference = -(0xffff - headingDifference);
        } else {
            headingDifference = headingDifference + 0xffff;
        }
    }
    c->mUnk_0e = c->mUnk_0e + (s32) ((s64) headingDifference * 0x19a >> 12);
    QuaternionFromAxisAngle(&data_02154f7c, (u16) (kart->mHeadingAngle + kart->mHeadingAngleOffset), &kart->mUnk_e0_m);
    QuaternionMultiply(&kart->mUnk_f0_q, &kart->mUnk_e0_m, &kart->mUnk_110_q);
    if ((kart->mUnk_44 & 2) != 0) {
        if (kart->mHopSpeed > 0) {
            f = (u16) ((s64) kart->mHopHeight * 0x1f4 >> 12);
            kart->mHopTiltAngle = 0x9c4 - f;
            if (kart->mHopTiltAngle > 0x6a4) {
                kart->mHopTiltAngle = 0x352;
            }
        } else {
            kart->mHopTiltAngle = 0;
        }
        QuaternionFromAxisAngle(&data_02154f88, (u16) -kart->mHopTiltAngle, &hopTiltQuaternion);
        QuaternionMultiply(&kart->mUnk_110_q, &hopTiltQuaternion, &kart->mUnk_110_q);
    } else {
        kart->mHopTiltAngle = 0;
    }
    QuaternionNormalize(&kart->mUnk_110_q, &kart->mUnk_110_q);
}

void SetKartPrevCollisionCenterFromPrevPos(Kart *kart) {
    ComputeKartPointAlongUp(&kart->mPrevCollisionCenter, &kart->mPrevPos, 0x400, kart);
}

void InitKart(Kart *kart, void (**slotFunctions)(Kart *)) {
    u32 isPeer;
    u16 i;
    KartModelAnimationView *characterAnimation;

    GetHeap(GetCurrentHeapCall());
    isPeer = gRaceSetup->mCurrentEntries[kart->mIndex].mPlayer.mKind == PLAYER_KIND_PEER;
    kart->mKartModelsEntry = GetKartModelsEntry(kart->mIndex);
    InitCourseColorBlend(&kart->mKartModelsEntry->mUnk_040, 1);
    if (gRaceSetup->mMode == 5) {
        for (i = 0; i < 9; i++) {
            if (i == 3) {
                kart->mSlotFunctions[i] = isPeer != 0 ? func_020637e0 : func_02063830;
            } else if (i == 4) {
                kart->mSlotFunctions[i] = isPeer != 0 ? func_020637c4 : func_02063880;
            } else if (i == 5) {
                kart->mSlotFunctions[i] =
                    isPeer != 0 ? SetKartPrevCollisionCenterFromPrevPos : SetKartPrevCollisionCenter;
            } else {
                kart->mSlotFunctions[i] = *slotFunctions;
            }
            slotFunctions++;
        }
    } else {
        for (i = 0; i < 9; i++) {
            if (i == 3) {
                kart->mSlotFunctions[i] = func_020646c0;
            } else if (i == 4) {
                kart->mSlotFunctions[i] = func_020641d4;
            } else if (i == 5) {
                kart->mSlotFunctions[i] = SetKartPrevCollisionCenter;
            } else {
                kart->mSlotFunctions[i] = *slotFunctions;
            }
            slotFunctions++;
        }
    }
    kart->mUnk_514 = NULL;
    if (kart->mSlotFunctions[1] != 0) {
        kart->mSlotFunctions[1](kart);
    }
    kart->mPosSource = &kart->mPos;
    kart->mUnk_50c = &kart->mUnk_110_q;
    kart->mUnk_510 = &kart->mPos;
    if (kart->mSlotFunctions[0] != 0) {
        kart->mSlotFunctions[0](kart);
    }
    if (gRaceSetup->mRaceKind == 2 || (kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) == 0) {
        kart->mSlotFunctions[2] = SetKartSoundDistanceSquaredAndChange;
    } else {
        kart->mSlotFunctions[2] = SetKartSoundDistanceSquared;
    }
    if (gRaceSetup->mMode == 5) {
        if (isPeer != 0) {
            kart->mPosSource = &kart->mUnk_514->mUnk_10;
            kart->mUnk_50c = &kart->mUnk_514->mUnk_4c;
            kart->mUnk_510 = &kart->mUnk_514->mUnk_00;
        } else {
            kart->mPosSource = &kart->mPos;
            kart->mUnk_50c = &kart->mUnk_110_q;
            kart->mUnk_510 = &kart->mPos;
        }
    } else {
        kart->mPosSource = &kart->mPos;
        kart->mUnk_50c = &kart->mUnk_110_q;
        kart->mUnk_510 = &kart->mPos;
    }
    kart->mUnk_534 = kart->mPosSource;
    func_020646f0(kart, 0);
    if (GetRaceUseChainCameras() != 0 && gRaceSetup->mRaceKind != RACE_KIND_AWARD) {
        kart->mSlotFunctions[3] = func_020649e8;
        kart->mSlotFunctions[4] = func_020649e8;
        kart->mDrawMatrixPos = kart->mUnk_174;
        kart->mUnk_174.x = kart->mUnk_174.x >> 4;
        kart->mUnk_174.y = kart->mUnk_174.y >> 4;
        kart->mUnk_174.z = kart->mUnk_174.z >> 4;
        if ((kart->mUnk_7c & KART_7C_MODELS_ENTRY_008_SET) != 0) {
            AdvanceKartCharacterAnimation(kart);
            characterAnimation = kart->mKartModelsEntry->mCharacterAnimation;
            *characterAnimation->mUnk_1c[characterAnimation->mUnk_1a] = characterAnimation->mUnk_0c;
        }
    }
    func_02071f44(kart);
    if ((kart->mUnk_7c & 2) != 0) {
        CallKartAiSetup(kart->mAi, kart->mIndex);
    }
}
