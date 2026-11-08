#include "Main/Unknown/code_020653d0.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_02068eac.h"
#include "Main/Unknown/code_02081618.h"
#include "Main/Unknown/code_020d50ec.h"
#include "Main/Unknown/code_02109054.h"
#include "Main/Unknown/unk_02154000.h"
#include "Main/Unknown/unk_02165000.h"
#include "ITCM/code_01ffb000.h"
#include "ITCM/code_01ffba68.h"
#include "ITCM/code_01ffc000.h"
#include "ITCM/code_01ffcf7c.h"
#include "ITCM/code_01ffdee4.h"
#include "Main/Unknown/code_0206a000.h"
#include "Main/Unknown/code_0206b000.h"
#include "Main/Unknown/code_02070398.h"
#include "Main/Unknown/code_0207b000.h"
#include "Main/Unknown/code_02082000.h"
#include "Main/Unknown/code_0210a000.h"
#include "ITCM/code_01ffd000.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02061000.h"
#include "Main/Unknown/code_02069000.h"
#include "Main/Unknown/code_020d5000.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_020ec8bc.h"
#include "Main/Unknown/code_021031f4.h"
#include "Main/Unknown/code_02109000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "code_02146d78.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_0206a354.h"
#include "Main/Unknown/code_02077bc0.h"

static inline void func_020653d0_inline(Kart *entryKart, Kart *sourceKart, Vec3 *direction) {
    Vec3 offset;
    Vec3 crossProduct;

    *direction = *(Vec3 *) &sourceKart->mUnk_120;
    VEC_Subtract(&entryKart->mPos, &sourceKart->mPos, &offset);
    VEC_CrossProduct(&sourceKart->mUnk_138, &offset, &crossProduct);
    if (VEC_DotProduct(&crossProduct, &sourceKart->mUnk_12c) < 0) {
        direction->x = -direction->x;
        direction->y = -direction->y;
        direction->z = -direction->z;
    }
}

void func_020653d0(Kart *kart, ParticipantKartRecord *record, s32 stepCount) {
    Vec3 newPos;
    Vec3 moveStep;
    Vec3 headingAxis;
    Vec3 axisOffset;
    Vec3 collisionOffset;
    Vec3 prevPos;
    MtxFx33 turnMatrix;
    MtxFx33 fixedAngleMatrix;
    u32 w;
    u32 recordFlags;
    ParticipantKartRecordState *state;
    s32 wasOnGround;
    u16 i;
    u16 s;
    ParticipantKartRecordState *stateAgain;
    s32 k;
    s32 startedState;
    Kart *o;
    Kart *sourceKart;
    s32 e;
    u8 byte;
    Vec3 *axis;

    recordFlags = record->mFlags;
    wasOnGround = (kart->mUnk_44 & KART_44_ON_GROUND) != 0;
    state = kart->mUnk_514;
    newPos.x = record->mPosX << 10;
    newPos.y = record->mPosY << 10;
    newPos.z = record->mPosZ << 10;
    kart->mForwardSpeed = record->mForwardSpeed << 2;
    kart->mHeadingAngle = record->mHeadingAngle;
    state->mUnk_44 = record->mUnk_14;
    state->mUnk_48 = record->mUnk_10;
    byte = state->mUnk_48 >> 24;
    state->mPushDirection.x = (s16) (((byte & 0x80) ? 0xc000 : 0) | (byte << 6));
    byte = state->mUnk_48 >> 16;
    state->mPushDirection.y = (s16) (((byte & 0x80) ? 0xc000 : 0) | (byte << 6));
    byte = state->mUnk_48 >> 8;
    state->mPushDirection.z = (s16) (((byte & 0x80) ? 0xc000 : 0) | (byte << 6));
    state->mUnk_48 = state->mUnk_48 & 0xff;
    state->mTargetTurnAngle = record->mTurnAngle;
    kart->mTurnAngle = record->mTurnAngle;
    if (wasOnGround) {
        kart->mUnk_44 |= KART_44_ON_GROUND;
    } else {
        kart->mUnk_44 &= ~KART_44_ON_GROUND;
    }
    if (kart->mUnk_514->mUnk_48 & 2) {
        kart->mUnk_44 |= 2;
    } else {
        kart->mUnk_44 &= ~2;
    }
    if (kart->mUnk_514->mUnk_48 & 8) {
        kart->mUnk_44 |= KART_44_DRIFTING;
    } else {
        kart->mUnk_44 &= ~KART_44_DRIFTING;
    }
    if (((kart->mUnk_514->mAppliedFlags & 0x10000) != 0) != ((recordFlags & 0x10000) != 0)) {
        s = kart->mHeadingAngle;
        ResetKartAndSetPos(kart, &newPos, 0, 0);
        kart->mHeadingAngle = s;
        headingAxis = data_02165530;
        QuaternionFromAxisAngle(&headingAxis, kart->mHeadingAngle, (Vec4 *) &kart->mUnk_e0);
        *(Vec4 *) &kart->mUnk_108.z = *(Vec4 *) &kart->mUnk_e0;
        if (kart->mUnk_7c & 0x400) {
            stateAgain = kart->mUnk_514;
            stateAgain->mUnk_00 = kart->mPos;
            stateAgain->mUnk_10 = stateAgain->mUnk_00;
            stateAgain->mUnk_4c = *(Vec4 *) &kart->mUnk_108.z;
            stateAgain->mUnk_a8 = data_02154f94;
            stateAgain->mUnk_b4 = 0;
        }
    }
    if ((s64) (kart->mPos.x - newPos.x) * (kart->mPos.x - newPos.x) +
            (s64) (kart->mPos.y - newPos.y) * (kart->mPos.y - newPos.y) +
            (s64) (kart->mPos.z - newPos.z) * (kart->mPos.z - newPos.z) >=
        0x15f90000000LL) {
        switch (state->mUnk_b4) {
            case 0:
                axis = &kart->mUnk_138;
                axisOffset.x = ((s64) axis->x * -0x7000) >> 12;
                axisOffset.y = ((s64) axis->y * -0x7000) >> 12;
                axisOffset.z = ((s64) axis->z * -0x7000) >> 12;
                break;
            case 1:
                axis = &kart->mUnk_138;
                axisOffset.x = ((s64) axis->x * 0x7000) >> 12;
                axisOffset.y = ((s64) axis->y * 0x7000) >> 12;
                axisOffset.z = ((s64) axis->z * 0x7000) >> 12;
                break;
            case 2:
                axis = &kart->mUnk_120;
                axisOffset.x = ((s64) axis->x * 0x7000) >> 12;
                axisOffset.y = ((s64) axis->y * 0x7000) >> 12;
                axisOffset.z = ((s64) axis->z * 0x7000) >> 12;
                break;
            case 3:
            default:
                axis = &kart->mUnk_120;
                axisOffset.x = ((s64) axis->x * -0x7000) >> 12;
                axisOffset.y = ((s64) axis->y * -0x7000) >> 12;
                axisOffset.z = ((s64) axis->z * -0x7000) >> 12;
                break;
        }
        state->mUnk_a8 = axisOffset;
        newPos.y += 0x14000;
        VEC_Add(&newPos, &axisOffset, &newPos);
        kart->mPos = newPos;
        kart->mPrevPos = kart->mPos;
        kart->mDrawMatrixPos = kart->mPrevPos;
        state->mUnk_00 = kart->mDrawMatrixPos;
        *(Vec3 *) &kart->mUnk_25c = data_02154f94;
        ComputeKartPointAlongUp(&kart->mCollisionCenter, &newPos, 0x400, kart);
        SetKartPrevCollisionCenter(kart);
        state->mUnk_b4++;
        if (state->mUnk_b4 > 3) {
            state->mUnk_b4 = 0;
        }
    } else if (!(kart->mUnk_48 & 0x20000)) {
        prevPos = kart->mPrevPos;
        VEC_Add(&newPos, &state->mUnk_a8, &newPos);
        FindCollisionSlotsAroundPos(&newPos, stepCount * 0xd000 + kart->mRadius, 0x8000);
        for (i = 0; i < stepCount; i++) {
            if (kart->mUnk_48 & 0x40) {
                kart->mPos.y -= 0x19a;
            } else {
                if (i < 3 && i < stepCount / 2) {
                    func_01ffc090(kart, func_01ffc27c(kart, 0));
                }
                QuaternionFromAxisAngle(&data_02154f7c, kart->mHeadingAngle, (Vec4 *) &kart->mUnk_e0);
                QuaternionMultiply((Vec4 *) &kart->mUnk_f0, (Vec4 *) &kart->mUnk_e0, (Vec4 *) &kart->mUnk_108.z);
                Matrix4x3FromQuaternion(&kart->mUnk_120, (Vec4 *) &kart->mUnk_108.z);
                stateAgain = kart->mUnk_514;
                stateAgain->mEasedTurnAngle =
                    stateAgain->mEasedTurnAngle +
                    (s32) (((s64) (stateAgain->mTargetTurnAngle - stateAgain->mEasedTurnAngle) * 0x333 + 0x800) >> 12);
                kart->mTurnAngle = stateAgain->mEasedTurnAngle;
                MTX_RotAxis33((MtxFx43 *) &turnMatrix, &kart->mUnk_12c,
                              gPairsByAngle[((u16) kart->mTurnAngle >> 4) * 2],
                              gPairsByAngle[((u16) kart->mTurnAngle >> 4) * 2 + 1]);
                if (kart->mUnk_48 & 1) {
                    MTX_RotAxis33((MtxFx43 *) &fixedAngleMatrix, &kart->mUnk_120, gPairsByAngle[0xba],
                                  gPairsByAngle[0xbb]);
                    MTX_Concat33(fixedAngleMatrix.mUnk_00, turnMatrix.mUnk_00, turnMatrix.mUnk_00);
                }
                MTX_MultVec33(&kart->mForward, turnMatrix.mUnk_00, &kart->mTurnedForward);
                k = kart->mForwardSpeed;
                moveStep.x = ((s64) kart->mTurnedForward.x * k) >> 12;
                moveStep.y = ((s64) kart->mTurnedForward.y * k) >> 12;
                moveStep.z = ((s64) kart->mTurnedForward.z * k) >> 12;
                VEC_Add(&newPos, &moveStep, &newPos);
                VEC_Add(&newPos, &kart->mHitVelocity, &newPos);
                VEC_Add(&kart->mVelocity, &kart->mHitVelocity, &kart->mVelocity);
                if (kart->mUnk_514->mUnk_44 & 1) {
                    kart->mVerticalSpeed = 0;
                }
                k = (kart->mUnk_44 & KART_44_ON_GROUND) ? 0xee1 : 0xfae;
                kart->mHitVelocity.x = ((s64) kart->mHitVelocity.x * k) >> 12;
                kart->mHitVelocity.y = ((s64) kart->mHitVelocity.y * k) >> 12;
                kart->mHitVelocity.z = ((s64) kart->mHitVelocity.z * k) >> 12;
                if ((s64) kart->mHitVelocity.x * kart->mHitVelocity.x +
                        (s64) kart->mHitVelocity.y * kart->mHitVelocity.y +
                        (s64) kart->mHitVelocity.z * kart->mHitVelocity.z >=
                    0xa429) {
                    kart->mUnk_44 |= 0x2000;
                } else {
                    kart->mHitVelocity = data_02154f94;
                    kart->mUnk_44 &= ~0x2000;
                }
            }
            if (func_01ffdee4(&newPos, (u32 *) &prevPos, 0, kart->mRadius, 1, kart->mCollisionSlot, &collisionOffset, 0,
                              0, &w, 0, 0, 0, 0)) {
                VEC_Add(&newPos, &collisionOffset, &newPos);
            }
            prevPos = newPos;
        }
    }
    if (kart->mUnk_48 & 0x40) {
        goto l0;
    }
    kart->mPos.x = newPos.x;
    kart->mPos.z = newPos.z;
    startedState = 0;
    if (((kart->mUnk_514->mAppliedFlags & 1) != 0) != ((recordFlags & 1) != 0) && (kart->mUnk_44 & KART_44_ON_GROUND)) {
        stateAgain = ((volatile Kart *) kart)->mUnk_514;
        stateAgain->mUnk_64 = 0x1405;
        stateAgain->mUnk_60 = 0;
        kart->mVerticalSpeed += 0x21a2;
    }
    if (((kart->mUnk_514->mAppliedFlags & 0x20000) != 0) != ((recordFlags & 0x20000) != 0)) {
        StartKartState6(kart);
        startedState = 1;
    }
    if (((kart->mUnk_514->mAppliedFlags & 4) != 0) != ((recordFlags & 4) != 0)) {
        StartKartState2(kart, 1, 0);
        startedState = 1;
    }
    if (((kart->mUnk_514->mAppliedFlags & 8) != 0) != ((recordFlags & 8) != 0)) {
        StartKartState2(kart, 2, 0);
        startedState = 1;
    }
    if (((kart->mUnk_514->mAppliedFlags & 0x10) != 0) != ((recordFlags & 0x10) != 0)) {
        StartKartState3(kart);
        startedState = 1;
    }
    if (((kart->mUnk_514->mAppliedFlags & 0x2000) != 0) != ((recordFlags & 0x2000) != 0)) {
        StartKartStar(kart);
    }
    if (((kart->mUnk_514->mAppliedFlags & 0x4000) != 0) != ((recordFlags & 0x4000) != 0)) {
        i = 0;
        StartFadeFog();
        StartEffectsAtOtherKarts(kart->mIndex);
        e = kart->mUnk_7c & 0x200;
        if (e) {
            if (e) {
                kart->mUnk_514->mUnk_2c ^= 0x4000;
            }
        } else {
            for (; i < (u32) gRaceSetup->mKartCount; i++) {
                if (i != kart->mIndex) {
                    StartKartThunderShrink(GetKart(i));
                }
            }
        }
    }
    if (((kart->mUnk_514->mAppliedFlags & 0x8000) != 0) != ((recordFlags & 0x8000) != 0)) {
        StartKartThunderShrink(kart);
    }
    if (((kart->mUnk_514->mAppliedFlags & 0x100000) != 0) != ((recordFlags & 0x100000) != 0)) {
        StartKartKiller(kart);
    }
    if (((kart->mUnk_514->mAppliedFlags & 0x200000) != 0) != ((recordFlags & 0x200000) != 0)) {
        kart->mUnk_538.mKillerEnding = TRUE;
    }
    if (((kart->mUnk_514->mAppliedFlags & 0x4000000) != 0) != ((recordFlags & 0x4000000) != 0)) {
        StartKartTeresa(kart);
    }
    if (((kart->mUnk_514->mAppliedFlags & 0x40) != 0) != ((recordFlags & 0x40) != 0)) {
        if (kart->mUnk_7c & 0x200) {
            if ((kart->mUnk_4c & 0x10000040) || kart->mState == KART_STATE_PUSH_FLIP) {
                goto l1;
            }
        } else if (kart->mState == KART_STATE_PUSH_DOUBLE_FLIP) {
            goto l1;
        }
        StartSound(&kart->mSoundSource, 0xe8, 0x7f, 0);
        StartKartState5(kart, &state->mPushDirection, 0);
    l1:
        if (((kart->mUnk_514->mAppliedFlags & 0x80) != 0) != ((recordFlags & 0x80) != 0)) {
            StartSound(&kart->mSoundSource, 0xe8, 0x7f, 0);
        }
    } else if (((kart->mUnk_514->mAppliedFlags & 0x20) != 0) != ((recordFlags & 0x20) != 0)) {
        if (kart->mUnk_7c & 0x200) {
            if ((kart->mUnk_4c & 0x10000040) || kart->mState == KART_STATE_PUSH_FLIP) {
                goto l2;
            }
        } else if (kart->mState == KART_STATE_PUSH_FLIP) {
            goto l2;
        }
        StartKartState4(kart, &state->mPushDirection, 0);
    l2:
        if (((kart->mUnk_514->mAppliedFlags & 0x80) != 0) != ((recordFlags & 0x80) != 0)) {
            StartSound(&kart->mSoundSource, 0xe8, 0x7f, 0);
        }
    }
    if (((kart->mUnk_514->mAppliedFlags & 0x40000) != 0) != ((recordFlags & 0x40000) != 0)) {
        func_02069068(kart);
    }
    if (((kart->mUnk_514->mAppliedFlags & 0x80000) != 0) != ((recordFlags & 0x80000) != 0)) {
        kart->mUnk_538.mUnk_1c = 0;
        kart->mUnk_4c |= 0x8000000;
        kart->mUnk_4c &= ~0x20000;
        if (kart->mUnk_4c & 0x2000) {
            func_0207b0d0(kart);
        }
        StartKartModelColorBlend(kart->mKartModelsEntry, 0, 0x1084, 0);
        if (kart->mUnk_7c & KART_7C_MODELS_ENTRY_008_SET) {
            StartKartCharacterAnimationOnce(kart, 1, 0);
            SetCharacterFaceFrameIndex(kart->mKartModelsEntry, 1);
        }
        if (!(kart->mUnk_48 & 0x840)) {
            func_0210af40(kart, kart->mSoundIndex, 0);
        }
        StartOrthoQuadsGesoSumi(kart->mIndex, 0);
    }
    if (startedState) {
        o = GetKart((u16) ((recordFlags & 0x60000000) >> 29));
        if (o != kart) {
            o->mUnk_4c |= 0x1000;
        }
    }
    o = GetKart(gRaceSetup->mEntryIndex);
    e = 0;
    if (((kart->mUnk_514->mAppliedFlags & 0x400000) != 0) != ((recordFlags & 0x400000) != 0) && o->mIndex == 0) {
        Vec3 direction;

        s = kart->mIndex;
        direction = data_02154f88;
        sourceKart = GetKart(s);
        if (o->mUnk_7c & 0x200) {
            if ((o->mUnk_4c & 0x10000040) || o->mState == KART_STATE_PUSH_FLIP) {
                goto l3;
            }
        } else if (o->mState == KART_STATE_PUSH_FLIP) {
            goto l3;
        }
        func_020653d0_inline(o, sourceKart, &direction);
        StartSound(&o->mSoundSource, 0xe8, 0x7f, 0);
        StartKartState5(o, &direction, 0);
    l3:
        e = 1;
    }
    if (((kart->mUnk_514->mAppliedFlags & 0x800000) != 0) != ((recordFlags & 0x800000) != 0) && o->mIndex == 1) {
        Vec3 direction;

        s = kart->mIndex;
        direction = data_02154f88;
        sourceKart = GetKart(s);
        if (o->mUnk_7c & 0x200) {
            if ((o->mUnk_4c & 0x10000040) || o->mState == KART_STATE_PUSH_FLIP) {
                goto l4;
            }
        } else if (o->mState == KART_STATE_PUSH_FLIP) {
            goto l4;
        }
        func_020653d0_inline(o, sourceKart, &direction);
        StartSound(&o->mSoundSource, 0xe8, 0x7f, 0);
        StartKartState5(o, &direction, 0);
    l4:
        e = 1;
    }
    if (((kart->mUnk_514->mAppliedFlags & 0x1000000) != 0) != ((recordFlags & 0x1000000) != 0) && o->mIndex == 2) {
        Vec3 direction;

        s = kart->mIndex;
        direction = data_02154f88;
        sourceKart = GetKart(s);
        if (o->mUnk_7c & 0x200) {
            if ((o->mUnk_4c & 0x10000040) || o->mState == KART_STATE_PUSH_FLIP) {
                goto l5;
            }
        } else if (o->mState == KART_STATE_PUSH_FLIP) {
            goto l5;
        }
        func_020653d0_inline(o, sourceKart, &direction);
        StartSound(&o->mSoundSource, 0xe8, 0x7f, 0);
        StartKartState5(o, &direction, 0);
    l5:
        e = 1;
    }
    if (((kart->mUnk_514->mAppliedFlags & 0x2000000) != 0) != ((recordFlags & 0x2000000) != 0) && o->mIndex == 3) {
        Vec3 direction;

        s = kart->mIndex;
        direction = data_02154f88;
        sourceKart = GetKart(s);
        if (o->mUnk_7c & 0x200) {
            if ((o->mUnk_4c & 0x10000040) || o->mState == KART_STATE_PUSH_FLIP) {
                goto l6;
            }
        } else if (o->mState == KART_STATE_PUSH_FLIP) {
            goto l6;
        }
        func_020653d0_inline(o, sourceKart, &direction);
        StartSound(&o->mSoundSource, 0xe8, 0x7f, 0);
        StartKartState5(o, &direction, 0);
    l6:
        e = 1;
    }
    if (e) {
        goto l0;
    }
    if (((kart->mUnk_514->mAppliedFlags & 0x200) != 0) != ((recordFlags & 0x200) != 0) && o->mIndex == 0) {
        Vec3 direction;

        s = kart->mIndex;
        direction = data_02154f88;
        sourceKart = GetKart(s);
        if (o->mUnk_7c & 0x200) {
            if ((o->mUnk_4c & 0x10000040) || o->mState == KART_STATE_PUSH_FLIP) {
                goto l7;
            }
        } else if (o->mState == KART_STATE_PUSH_FLIP) {
            goto l7;
        }
        VEC_Subtract(&o->mPointAlongUp, &sourceKart->mPointAlongUp, &direction);
        if ((s64) direction.x * direction.x + (s64) direction.y * direction.y + (s64) direction.z * direction.z >=
            0x10) {
            Vec3NormalizeAndGetLengthUnchecked(&direction, &direction);
        }
        StartSound(&o->mSoundSource, 0xe8, 0x7f, 0);
        StartKartState4(o, &direction, 0);
    l7:
    }
    if (((kart->mUnk_514->mAppliedFlags & 0x400) != 0) != ((recordFlags & 0x400) != 0) && o->mIndex == 1) {
        Vec3 direction;

        s = kart->mIndex;
        direction = data_02154f88;
        sourceKart = GetKart(s);
        if (o->mUnk_7c & 0x200) {
            if ((o->mUnk_4c & 0x10000040) || o->mState == KART_STATE_PUSH_FLIP) {
                goto l8;
            }
        } else if (o->mState == KART_STATE_PUSH_FLIP) {
            goto l8;
        }
        VEC_Subtract(&o->mPointAlongUp, &sourceKart->mPointAlongUp, &direction);
        if ((s64) direction.x * direction.x + (s64) direction.y * direction.y + (s64) direction.z * direction.z >=
            0x10) {
            Vec3NormalizeAndGetLengthUnchecked(&direction, &direction);
        }
        StartSound(&o->mSoundSource, 0xe8, 0x7f, 0);
        StartKartState4(o, &direction, 0);
    l8:
    }
    if (((kart->mUnk_514->mAppliedFlags & 0x800) != 0) != ((recordFlags & 0x800) != 0) && o->mIndex == 2) {
        Vec3 direction;

        s = kart->mIndex;
        direction = data_02154f88;
        sourceKart = GetKart(s);
        if (o->mUnk_7c & 0x200) {
            if ((o->mUnk_4c & 0x10000040) || o->mState == KART_STATE_PUSH_FLIP) {
                goto l9;
            }
        } else if (o->mState == KART_STATE_PUSH_FLIP) {
            goto l9;
        }
        VEC_Subtract(&o->mPointAlongUp, &sourceKart->mPointAlongUp, &direction);
        if ((s64) direction.x * direction.x + (s64) direction.y * direction.y + (s64) direction.z * direction.z >=
            0x10) {
            Vec3NormalizeAndGetLengthUnchecked(&direction, &direction);
        }
        StartSound(&o->mSoundSource, 0xe8, 0x7f, 0);
        StartKartState4(o, &direction, 0);
    l9:
    }
    if (((kart->mUnk_514->mAppliedFlags & 0x1000) != 0) != ((recordFlags & 0x1000) != 0) && o->mIndex == 3) {
        Vec3 direction;

        s = kart->mIndex;
        direction = data_02154f88;
        sourceKart = GetKart(s);
        if (o->mUnk_7c & 0x200) {
            if ((o->mUnk_4c & 0x10000040) || o->mState == KART_STATE_PUSH_FLIP) {
                goto l10;
            }
        } else if (o->mState == KART_STATE_PUSH_FLIP) {
            goto l10;
        }
        VEC_Subtract(&o->mPointAlongUp, &sourceKart->mPointAlongUp, &direction);
        if ((s64) direction.x * direction.x + (s64) direction.y * direction.y + (s64) direction.z * direction.z >=
            0x10) {
            Vec3NormalizeAndGetLengthUnchecked(&direction, &direction);
        }
        StartSound(&o->mSoundSource, 0xe8, 0x7f, 0);
        StartKartState4(o, &direction, 0);
    l10:
    }
l0:
    kart->mUnk_514->mAppliedFlags = recordFlags;
}
