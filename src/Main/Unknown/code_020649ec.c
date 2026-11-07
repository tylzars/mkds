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

void func_020651fc(Kart *a) {
    Unk0206bcb0_514 *b;
    s32 c;
    u32 f;

    f = a->mUnk_7c;
    if ((f & 0xa0) != 0) {
        if ((f & 0x20) != 0) {
            func_02068b98(a);
            return;
        }
        a->mUnk_3c8 = a->mUnk_3c8 + 1;
        c = a->mUnk_3c8;
        if (c >= 0x19) {
            a->mUnk_7c = a->mUnk_7c & ~0x80;
            return;
        }
        a->mScaleFactor.x = gKartScaleFactorXTable[c];
        a->mScaleFactor.y = gKartScaleFactorYTable[c];
        a->mScaleFactor.z = gKartScaleFactorZTable[c];
        a->mScale.x = (s64) a->mScaleBase.x * a->mScaleFactor.x >> 12;
        a->mScale.y = (s64) a->mScaleBase.y * a->mScaleFactor.y >> 12;
        a->mScale.z = (s64) a->mScaleBase.z * a->mScaleFactor.z >> 12;
        a->mScale.y = (s64) a->mScaleYFactor * a->mScale.y >> 12;
        return;
    }
    b = a->mUnk_514;
    Matrix4x3FromQuaternion(&a->mUnk_120, &a->mUnk_110_q);
    func_02066ac0(a);
    if (a->mForwardSpeed > 0x3000) {
        b->mUnk_a8 = data_02154f94;
    }
    func_01ffca50(a);
    UpdateKartSpeedLimitGoal(a);
    UpdateKartSpeedLimit(a);
    func_01ffbd9c(a);
    func_01ffc6c0(a);
    func_01ff9d18(a);
    b = a->mUnk_514;
    b->mUnk_64 = b->mUnk_64 + a->mGravity;
    b->mUnk_60 = b->mUnk_60 + b->mUnk_64;
    if (b->mUnk_60 < 0) {
        b->mUnk_60 = 0;
        b->mUnk_64 = 0;
    }
    if (IsRaceStarted() == 1) {
        a->mUnk_230 = func_01ffb0cc;
    }
    if ((a->mUnk_514->mUnk_44 & 1) != 0) {
        a->mVerticalSpeed = 0;
    }
    func_01ffb130(a);
}

void func_02064f50(Kart *a) {
    Unk0206bcb0_514 *b;
    s32 c;
    Vec3 d;
    Vec3 e;
    Vec3 i;
    Vec3 h;
    Vec3 g;
    Vec3 f;
    u32 j;
    Vec3 *k;

    b = a->mUnk_514;
    if ((a->mUnk_7c & 0x20) != 0) {
        return;
    }
    if ((a->mUnk_44 & KART_44_NEAR_KART) != 0) {
        a->mUnk_44 = a->mUnk_44 | 0x80000;
    } else {
        a->mUnk_44 = a->mUnk_44 & ~0x80000;
    }
    ComputeKartPointAlongUp(&a->mCollisionCenter, &a->mPos, 0x400, a);
    func_01ffa4b4(a, &d);
    func_02064d60(a, &d);
    a->mUnk_244 = d;
    a->mUnk_4d0 = a->mUnk_4d0 + 1;
    func_01ffc920(a);
    AdvanceKartCollisionTimer(a);
    if ((a->mUnk_4c & 0x8000) != 0) {
        ComputeKartSidePoints(a);
    }
    if ((a->mUnk_4c & 8) != 0) {
        AdvanceKartModelScaleAnimation(a);
    }
    a->mUnk_230(a);
    e = a->mPos;
    e.y = e.y - b->mUnk_60;
    c = b->mUnk_24;
    VEC_Subtract(&e, &b->mUnk_00, &f);
    f.x = (s64) f.x * c >> 12;
    f.y = (s64) f.y * c >> 12;
    f.z = (s64) f.z * c >> 12;
    VEC_Add(&b->mUnk_00, &f, &b->mUnk_00);
    if ((a->mUnk_514->mUnk_44 & 1) != 0) {
        ComputeKartPointAlongUp(&g, &b->mUnk_00, 0x400, a);
        k = &a->mUnk_12c;
        h.x = (s64) k->x * -0x7000 >> 12;
        h.y = (s64) k->y * -0x7000 >> 12;
        h.z = (s64) k->z * -0x7000 >> 12;
        VEC_Add(&g, &h, &g);
        if (func_01ffdee4(&g, NULL, 0, a->mRadius, 1, a->mUnk_2c8, &i, NULL, NULL, &j, NULL, NULL, NULL, NULL) != 0) {
            VEC_Add(&i, &h, &i);
            VEC_Add(&b->mUnk_00, &i, &b->mUnk_00);
        }
    }
    b->mUnk_10 = b->mUnk_00;
    b->mUnk_10.y = b->mUnk_10.y + b->mUnk_60;
    QuaternionBlend(&b->mUnk_4c, &a->mUnk_110_q, &b->mUnk_4c, 0x333);
}

void func_02064d60(Kart *a, Vec3 *b) {
    Unk0206bcb0_514 *c;
    Vec4 d;
    s32 e;
    s32 f;

    c = a->mUnk_514;
    a->mUnk_3f8 = 0x1000;
    if (a->mAirborneFrames > 5 && (a->mUnk_514->mUnk_44 & 1) == 0) {
        a->mQuaternionBlendFactor = 0xf6;
        func_02070484(a, &a->mUnk_100_q);
    } else {
        AdvanceKartQuaternionFromVector(a, b);
    }
    QuaternionBlend(&a->mUnk_f0_q, &a->mUnk_100_q, &a->mUnk_f0_q, a->mQuaternionBlendFactor);
    e = a->mHeadingAngle - c->mUnk_0e;
    if ((e > 0 ? e : -e) > 0x7fff) {
        if (e > 0) {
            e = -(0xffff - e);
        } else {
            e = e + 0xffff;
        }
    }
    c->mUnk_0e = c->mUnk_0e + (s32) ((s64) e * 0x19a >> 12);
    QuaternionFromAxisAngle(&data_02154f7c, (u16) (a->mHeadingAngle + a->mHeadingAngleOffset), &a->mUnk_e0_m);
    QuaternionMultiply(&a->mUnk_f0_q, &a->mUnk_e0_m, &a->mUnk_110_q);
    if ((a->mUnk_44 & 2) != 0) {
        if (a->mHopSpeed > 0) {
            f = (u16) ((s64) a->mHopHeight * 0x1f4 >> 12);
            a->mHopTiltAngle = 0x9c4 - f;
            if (a->mHopTiltAngle > 0x6a4) {
                a->mHopTiltAngle = 0x352;
            }
        } else {
            a->mHopTiltAngle = 0;
        }
        QuaternionFromAxisAngle(&data_02154f88, (u16) -a->mHopTiltAngle, &d);
        QuaternionMultiply(&a->mUnk_110_q, &d, &a->mUnk_110_q);
    } else {
        a->mHopTiltAngle = 0;
    }
    QuaternionNormalize(&a->mUnk_110_q, &a->mUnk_110_q);
}

void SetKartPrevCollisionCenterFromPrevPos(Kart *a) {
    ComputeKartPointAlongUp(&a->mPrevCollisionCenter, &a->mPrevPos, 0x400, a);
}

void InitKart(Kart *a, void (**b)(Kart *)) {
    u32 c;
    u16 i;
    Unk0206bcb0_590_08 *d;

    GetHeap(func_020364e8());
    c = gRaceSetup->mCurrentEntries[a->mIndex].mPlayer.mKind == 3;
    a->mKartModelsEntry = GetKartModelsEntry(a->mIndex);
    func_0208adc8(&a->mKartModelsEntry->mUnk_040, 1);
    if (gRaceSetup->mMode == 5) {
        for (i = 0; i < 9; i++) {
            if (i == 3) {
                a->mSlotFunctions[i] = c != 0 ? func_020637e0 : func_02063830;
            } else if (i == 4) {
                a->mSlotFunctions[i] = c != 0 ? func_020637c4 : func_02063880;
            } else if (i == 5) {
                a->mSlotFunctions[i] = c != 0 ? SetKartPrevCollisionCenterFromPrevPos : SetKartPrevCollisionCenter;
            } else {
                a->mSlotFunctions[i] = *b;
            }
            b++;
        }
    } else {
        for (i = 0; i < 9; i++) {
            if (i == 3) {
                a->mSlotFunctions[i] = func_020646c0;
            } else if (i == 4) {
                a->mSlotFunctions[i] = func_020641d4;
            } else if (i == 5) {
                a->mSlotFunctions[i] = SetKartPrevCollisionCenter;
            } else {
                a->mSlotFunctions[i] = *b;
            }
            b++;
        }
    }
    a->mUnk_514 = NULL;
    if (a->mSlotFunctions[1] != 0) {
        a->mSlotFunctions[1](a);
    }
    a->mPosSource = &a->mPos;
    a->mUnk_50c = &a->mUnk_110_q;
    a->mUnk_510 = &a->mPos;
    if (a->mSlotFunctions[0] != 0) {
        a->mSlotFunctions[0](a);
    }
    if (gRaceSetup->mRaceKind == 2 || (a->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) == 0) {
        a->mSlotFunctions[2] = SetKartSoundDistanceSquaredAndChange;
    } else {
        a->mSlotFunctions[2] = SetKartSoundDistanceSquared;
    }
    if (gRaceSetup->mMode == 5) {
        if (c != 0) {
            a->mPosSource = &a->mUnk_514->mUnk_10;
            a->mUnk_50c = &a->mUnk_514->mUnk_4c;
            a->mUnk_510 = &a->mUnk_514->mUnk_00;
        } else {
            a->mPosSource = &a->mPos;
            a->mUnk_50c = &a->mUnk_110_q;
            a->mUnk_510 = &a->mPos;
        }
    } else {
        a->mPosSource = &a->mPos;
        a->mUnk_50c = &a->mUnk_110_q;
        a->mUnk_510 = &a->mPos;
    }
    a->mUnk_534 = a->mPosSource;
    func_020646f0(a, 0);
    if (GetRaceUseChainCameras() != 0 && gRaceSetup->mRaceKind != RACE_KIND_AWARD) {
        a->mSlotFunctions[3] = func_020649e8;
        a->mSlotFunctions[4] = func_020649e8;
        a->mUnk_98 = a->mUnk_174;
        a->mUnk_174.x = a->mUnk_174.x >> 4;
        a->mUnk_174.y = a->mUnk_174.y >> 4;
        a->mUnk_174.z = a->mUnk_174.z >> 4;
        if ((a->mUnk_7c & KART_7C_MODELS_ENTRY_008_SET) != 0) {
            func_0207b734(a);
            d = a->mKartModelsEntry->mCharacterAnimation;
            *d->mUnk_1c[d->mUnk_1a] = d->mUnk_0c;
        }
    }
    func_02071f44(a);
    if ((a->mUnk_7c & 2) != 0) {
        func_0208c260(a->mAi, a->mIndex);
    }
}
