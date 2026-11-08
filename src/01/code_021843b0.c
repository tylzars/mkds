#include "01/code_021843b0.h"

#include "01/code_02184cc8.h"
#include "01/code_02188950.h"
#include "01/code_02185ef4.h"
#include "01/code_02188000.h"
#include "01/code_02188cd8.h"
#include "01/code_02188da4.h"
#include "01/code_02188158.h"
#include "01/code_02184000.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_0208b484.h"
#include "Main/Unknown/code_020f36d8.h"
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
#include "code_02147cd8.h"
#include "Main/Unknown/code_0208b000.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_02073000.h"
#include "01/unk_021a6000.h"
#include "Main/Unknown/code_02109000.h"
#include "Main/Unknown/code_02109054.h"
#include "Main/Unknown/code_020d275c.h"
#include "Main/Unknown/code_021000d0.h"

void func_ov001_02184874(Unk02188950 *donketu, Kart *kart) {
    s32 scale;

    if ((GetKart(kart->mIndex)->mUnk_48 & KART_48_BOOST) && kart->mBoostTimer > 0) {
        if (func_ov001_021871f8(donketu, 8)) {
            if (donketu->mPrm->mUnk_1dc > 0 || donketu->mPrm->mUnk_1e0 > 0) {
                Vec3 velocityWhenBoosted = {0, 0, 0};
                velocityWhenBoosted.x = kart->mVelocity.x;
                velocityWhenBoosted.z = kart->mVelocity.z;
                if ((s64) velocityWhenBoosted.z * velocityWhenBoosted.z +
                        ((s64) velocityWhenBoosted.x * velocityWhenBoosted.x +
                         (s64) velocityWhenBoosted.y * velocityWhenBoosted.y) >=
                    0x10) {
                    Vec3NormalizeAndGetLengthUnchecked(&velocityWhenBoosted, &velocityWhenBoosted);
                }
                scale = donketu->mPrm->mUnk_1e0;
                velocityWhenBoosted.x = ((s64) velocityWhenBoosted.x * scale) >> 12;
                velocityWhenBoosted.y = ((s64) velocityWhenBoosted.y * scale) >> 12;
                velocityWhenBoosted.z = ((s64) velocityWhenBoosted.z * scale) >> 12;
                velocityWhenBoosted.y = donketu->mPrm->mUnk_1dc;
                func_ov001_02187218(donketu, 7, NULL);
                func_ov001_02188d64(donketu, donketu->mPrm->mUnk_1d4, donketu->mPrm->mUnk_1d8);
                func_ov001_02188a8c(donketu, donketu->mPrm->mUnk_1e4, 0x270f000);
                SetVelocity(donketu, &velocityWhenBoosted);
                func_ov001_02188dcc(donketu, func_ov001_02184d70);
                func_ov001_02188cec(donketu, 0);
            }
            {
                Vec3 effectPosition;

                VEC_Subtract(&donketu->mUnk_000.mPos, &kart->mCollisionCenter, &effectPosition);
                if ((s64) effectPosition.z * effectPosition.z +
                        ((s64) effectPosition.x * effectPosition.x + (s64) effectPosition.y * effectPosition.y) >=
                    0x10) {
                    Vec3NormalizeAndGetLengthUnchecked(&effectPosition, &effectPosition);
                }
                VEC_MultAdd(kart->mRadius, &effectPosition, &kart->mCollisionCenter, &effectPosition);
                if (donketu->mUnk_000.mKind == MAP_OBJECT_KIND_BOSS_DONKETU) {
                    donketu->mUnk_000.mDistanceSquaredAndFlags |= data_ov001_021a657c;
                    StopSound(&donketu->mUnk_000.mSound->mSoundSource, 0x214);
                    StartMapObjectSound(&donketu->mUnk_000, 0x211);
                    StartEffect(0x3e9, &effectPosition);
                    StartEffect(0x3e8, &effectPosition);
                    StartEffect(0x3ea, &effectPosition);
                    func_ov001_02187518(donketu, 0x99a, 0, 0x75c, 0x3f3, 0);
                    func_ov001_02187518(donketu, -0x99a, 0, 0x75c, 0x3f3, 0);
                } else if (donketu->mUnk_000.mKind == MAP_OBJECT_KIND_KING_ICE_DONKETU) {
                    donketu->mUnk_000.mDistanceSquaredAndFlags |= data_ov001_021a657c;
                    StopSound(&donketu->mUnk_000.mSound->mSoundSource, 0x245);
                    StartMapObjectSound(&donketu->mUnk_000, 0x23f);
                    StartEffect(0x3fa, &effectPosition);
                    StartEffect(0x3fb, &effectPosition);
                    StartEffect(0x3fc, &effectPosition);
                    func_ov001_02187518(donketu, -0x11ec, 0, 0x1800, 0x445, 0);
                    func_ov001_02187518(donketu, 0x11ec, 0, 0x1800, 0x445, 0);
                }
            }
        }
    } else if (func_ov001_021871f8(donketu, 7)) {
        if (donketu->mPrm->mUnk_1c4 > 0 || donketu->mPrm->mUnk_1c8 > 0) {
            Vec3 velocityWhenNotBoosted = {0, 0, 0};
            velocityWhenNotBoosted.x = kart->mVelocity.x;
            velocityWhenNotBoosted.z = kart->mVelocity.z;
            if ((s64) velocityWhenNotBoosted.z * velocityWhenNotBoosted.z +
                    ((s64) velocityWhenNotBoosted.x * velocityWhenNotBoosted.x +
                     (s64) velocityWhenNotBoosted.y * velocityWhenNotBoosted.y) >=
                0x10) {
                Vec3NormalizeAndGetLengthUnchecked(&velocityWhenNotBoosted, &velocityWhenNotBoosted);
            }
            scale = donketu->mPrm->mUnk_1c8;
            velocityWhenNotBoosted.x = ((s64) velocityWhenNotBoosted.x * scale) >> 12;
            velocityWhenNotBoosted.y = ((s64) velocityWhenNotBoosted.y * scale) >> 12;
            velocityWhenNotBoosted.z = ((s64) velocityWhenNotBoosted.z * scale) >> 12;
            velocityWhenNotBoosted.y = donketu->mPrm->mUnk_1c4;
            func_ov001_02187218(donketu, 7, NULL);
            func_ov001_02188d64(donketu, donketu->mPrm->mUnk_1bc, donketu->mPrm->mUnk_1c0);
            func_ov001_02188a8c(donketu, donketu->mPrm->mUnk_1cc, 0x270f000);
            SetVelocity(donketu, &velocityWhenNotBoosted);
            func_ov001_02188dcc(donketu, NULL);
            func_ov001_02188cec(donketu, 0);
        }
    }
    func_ov001_02188200(donketu, func_ov001_02184874);
    donketu->mUnk_2d8 = 13;
}

void func_ov001_021843b0(Unk02188950 *donketu, Kart *kart) {
    Vec3 velocityWhenBoosted;
    Vec3 effectPosition;
    Vec3 velocityWhenNotBoosted;

    if ((GetKart(kart->mIndex)->mUnk_48 & KART_48_BOOST) && kart->mBoostTimer > 0) {
        if (func_ov001_021871f8(donketu, 8)) {
            if (donketu->mPrm->mUnk_1a8 > 0 || donketu->mPrm->mUnk_1ac > 0) {
                velocityWhenBoosted.x =
                    ((s64) -donketu->mPrm->mUnk_1ac * gPairsByAngle[((u16) donketu->mMoveAngle >> 4) * 2]) >> 12;
                velocityWhenBoosted.y = donketu->mPrm->mUnk_1a8;
                velocityWhenBoosted.z =
                    ((s64) -donketu->mPrm->mUnk_1ac * gPairsByAngle[((u16) donketu->mMoveAngle >> 4) * 2 + 1]) >> 12;
                func_ov001_02187218(donketu, 7, NULL);
                func_ov001_02188d64(donketu, donketu->mPrm->mUnk_1a0, donketu->mPrm->mUnk_1a4);
                func_ov001_02188a8c(donketu, donketu->mPrm->mUnk_1b0, 0x270f000);
                SetVelocity(donketu, &velocityWhenBoosted);
                func_ov001_02188dcc(donketu, func_ov001_02184d70);
                func_ov001_02188cec(donketu, 0);
            }
            VEC_Subtract(&donketu->mUnk_000.mPos, &kart->mCollisionCenter, &effectPosition);
            if ((s64) effectPosition.x * effectPosition.x + (s64) effectPosition.y * effectPosition.y +
                    (s64) effectPosition.z * effectPosition.z >=
                0x10) {
                Vec3NormalizeAndGetLengthUnchecked(&effectPosition, &effectPosition);
            }
            VEC_MultAdd(kart->mRadius, &effectPosition, &kart->mCollisionCenter, &effectPosition);
            if (donketu->mUnk_000.mKind == MAP_OBJECT_KIND_BOSS_DONKETU) {
                donketu->mUnk_000.mDistanceSquaredAndFlags |= data_ov001_021a657c;
                StopSound(&donketu->mUnk_000.mSound->mSoundSource, 0x214);
                StartMapObjectSound(&donketu->mUnk_000, 0x211);
                StartEffect(0x3e9, &effectPosition);
                StartEffect(0x3e8, &effectPosition);
                StartEffect(0x3ea, &effectPosition);
                func_ov001_02187518(donketu, 0x99a, 0, 0x75c, 0x3f3, 0);
                func_ov001_02187518(donketu, -0x99a, 0, 0x75c, 0x3f3, 0);
            } else if (donketu->mUnk_000.mKind == MAP_OBJECT_KIND_KING_ICE_DONKETU) {
                donketu->mUnk_000.mDistanceSquaredAndFlags |= data_ov001_021a657c;
                StopSound(&donketu->mUnk_000.mSound->mSoundSource, 0x245);
                StartMapObjectSound(&donketu->mUnk_000, 0x23f);
                StartEffect(0x3fa, &effectPosition);
                StartEffect(0x3fb, &effectPosition);
                StartEffect(0x3fc, &effectPosition);
                func_ov001_02187518(donketu, -0x11ec, 0, 0x1800, 0x445, 0);
                func_ov001_02187518(donketu, 0x11ec, 0, 0x1800, 0x445, 0);
            }
            donketu->mUnk_000.mUnk_10.x =
                ((s64) donketu->mPrm->mUnk_1b8 * gPairsByAngle[((u16) donketu->mMoveAngle >> 4) * 2]) >> 12;
            donketu->mUnk_000.mUnk_10.y = 0;
            donketu->mUnk_000.mUnk_10.z =
                ((s64) donketu->mPrm->mUnk_1b8 * gPairsByAngle[((u16) donketu->mMoveAngle >> 4) * 2 + 1]) >> 12;
            donketu->mUnk_000.mPos.x -= donketu->mUnk_000.mUnk_10.x;
            donketu->mUnk_000.mPos.y -= donketu->mUnk_000.mUnk_10.y;
            donketu->mUnk_000.mPos.z -= donketu->mUnk_000.mUnk_10.z;
        }
    } else if (func_ov001_021871f8(donketu, 7)) {
        if (donketu->mPrm->mUnk_18c > 0 || donketu->mPrm->mUnk_190 > 0) {
            velocityWhenNotBoosted.x =
                ((s64) -donketu->mPrm->mUnk_190 * gPairsByAngle[((u16) donketu->mMoveAngle >> 4) * 2]) >> 12;
            velocityWhenNotBoosted.y = donketu->mPrm->mUnk_18c;
            velocityWhenNotBoosted.z =
                ((s64) -donketu->mPrm->mUnk_190 * gPairsByAngle[((u16) donketu->mMoveAngle >> 4) * 2 + 1]) >> 12;
            func_ov001_02187218(donketu, 7, NULL);
            func_ov001_02188d64(donketu, donketu->mPrm->mUnk_184, donketu->mPrm->mUnk_188);
            func_ov001_02188a8c(donketu, donketu->mPrm->mUnk_194, 0x270f000);
            SetVelocity(donketu, &velocityWhenNotBoosted);
            func_ov001_02188dcc(donketu, func_ov001_02184cc8);
            func_ov001_02188cec(donketu, 0);
        }
        donketu->mUnk_000.mUnk_10.x =
            ((s64) donketu->mPrm->mUnk_19c * gPairsByAngle[((u16) donketu->mMoveAngle >> 4) * 2]) >> 12;
        donketu->mUnk_000.mUnk_10.y = 0;
        donketu->mUnk_000.mUnk_10.z =
            ((s64) donketu->mPrm->mUnk_19c * gPairsByAngle[((u16) donketu->mMoveAngle >> 4) * 2 + 1]) >> 12;
        donketu->mUnk_000.mPos.x -= donketu->mUnk_000.mUnk_10.x;
        donketu->mUnk_000.mPos.y -= donketu->mUnk_000.mUnk_10.y;
        donketu->mUnk_000.mPos.z -= donketu->mUnk_000.mUnk_10.z;
        donketu->mUnk_000.mDistanceSquaredAndFlags |= data_ov001_021a657c;
        StartMapObjectSound(&donketu->mUnk_000, 0x213);
    }
    func_ov001_02188200(donketu, func_ov001_02184874);
    donketu->mUnk_2d8 = 0xd;
    StartCameraWobbleAtDistance(donketu->mUnk_000.mDistanceSquaredAndFlags & 0x3fffffe0, 0x1000);
}
