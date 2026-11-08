#include "Main/Unknown/code_0206f04c.h"
#include "Main/Unknown/code_0206d000.h"
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
#include "Main/Unknown/code_02081374.h"
#include "Main/Unknown/code_020ed5c0.h"
#include "Main/Unknown/code_0210ab48.h"
#include "Main/Unknown/code_020ea670.h"
#include "Main/Unknown/unk_02154000.h"
#include "Main/Unknown/unk_02165000.h"
#include "Main/Unknown/code_020d50ec.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_020e73a0.h"
#include "Main/Unknown/code_020e6fd4.h"
#include "Main/Unknown/code_0208c16c.h"
#include "Main/Unknown/code_020b33d8.h"
#include "ITCM/code_01ffad14.h"
#include "ITCM/code_01ffb000.h"
#include "Main/Unknown/code_02109054.h"
#include "Main/Unknown/code_0207a000.h"
#include "Main/Unknown/code_020d3c94.h"
#include "Main/Unknown/code_0208d978.h"
#include "Main/Unknown/code_02081618.h"
#include "Main/Unknown/code_020888b4.h"
#include "Main/Unknown/code_02108ea0.h"
#include "Main/Unknown/code_0210dc7c.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_0208aea8.h"
#include "Main/Unknown/code_0208b484.h"
#include "Main/Unknown/code_020815a0.h"
#include "Main/Unknown/code_020c476c.h"
#include "Main/Unknown/code_02104a0c.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/code_02040de0.h"
#include "code_0212df7c.h"
#include "code_0212bcac.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/unk_027e0000.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_0206d020.h"
#include "Main/Unknown/code_020681f0.h"
#include "Main/Unknown/code_02077bc0.h"

#pragma opt_arithtransformation off

void func_0206ff50(Kart *kart, u32 collisionFlags) {
    u32 b;
    u32 respawnSlot;
    NNSSndSeqPlayer **soundHandleEntry;
    s32 f;
    s32 mode;
    u16 kartIndex;
    Vec3 g;
    KartFollowEffectIds e;

    if (kart->mUnk_7c & 0x400) {
        return;
    }
    if (collisionFlags & 0x8000) {
        if (kart->mState == KART_STATE_LAUNCH_DOUBLE_FLIP) {
            return;
        }
        b = (u16) ((PickCollisionHitValue(0x8000) & 0xe0) >> 5);
        mode = gRaceSetup->mMode;
        if (mode == MODE_BATTLE || mode == MODE_MISSION_RUN) {
            PlaceKartAtKeyedPlacement(kart, b);
            return;
        }
        kart->mUnk_48 |= 0x10000;
        ResetKartMotionState(kart, 0);
        return;
    }
    if (!(kart->mUnk_48 & 0x800)) {
        kart->mUnk_48 |= 0x800;
        kartIndex = kart->mIndex;
        if (gRaceSetup->mMode == MODE_BATTLE) {
            respawnSlot = GetCourseMapRespawnSlot(0);
        } else {
            respawnSlot = GetCourseMapRespawnSlot(gRaceProgress->mUnk_000[kartIndex].mCheckpoint);
        }
        kart->mRespawnSlot = respawnSlot;
        if ((kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) && gRaceSetup->mCourseId == COURSE_ID_RAINBOW &&
            (data_0217c780 & 1)) {
            soundHandleEntry = TakeSoundHandleEntry(func_02108ea0(0));
            if (data_0217d084.mUnk_0c != 0) {
                if (soundHandleEntry[0] != NULL) {
                    NNS_SndPlayerStopSeq(soundHandleEntry, 0);
                }
                if (soundHandleEntry[0] != NULL) {
                    NNS_SndPlayerStopSeq(soundHandleEntry, 0);
                }
                NNS_SndArcPlayerStartSeqArc(soundHandleEntry, 0, 0x1b7);
            }
        }
    }
    if (!(collisionFlags & 0xc00)) {
        return;
    }
    if (kart->mUnk_48 & 0x1000) {
        return;
    }
    HideRaceTaKartPositions(kart->mIndex);
    kart->mUnk_48 |= 0x41000;
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
    if (kart->mUnk_4c & 0x10000000) {
        kart->mUnk_4c &= ~0x10000000;
        func_0210515c(kart->mIndex);
        if (kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) {
            ResetCameraHalfFovAngleGoal();
        }
        kart->mRadiusFactor = 0x1000;
        kart->mSurfaceGroup = -1;
        f = 0;
        kart->mItemEffect = 0;
        if (kart->mKartModelsEntry->mUnk_058 == 0) {
            e = gKartFollowEffectIds;
            for (f = 0; f < 3; f++) {
                SetupKartFollowEffect(StartEffect(e.mEffectIds[f], &kart->mPos), kart->mIndex, 0x14);
            }
        }
        StopKartKillerEffect(kart->mIndex);
        StartSound(&kart->mSoundSource, 0xfd, 0x7f, 0);
    }
    func_020f00f0(&(gKartItems)[kart->mIndex]);
    if (collisionFlags & 0x400) {
        b = PickCollisionHitValue(0x400);
        kart->mUnk_48 |= 0x2000;
        if ((u16) ((b & 0xe0) >> 5) == 4) {
            kart->mUnk_48 |= 0x800000;
        }
        return;
    }
    b = (u16) ((PickCollisionHitValue(0x800) & 0xe0) >> 5);
    kart->mUnk_4bc = kart->mUnk_3f8;
    kart->mUnk_4c |= 0x200000;
    if (kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) {
        func_02075d08(1);
    }
    if ((u16) (b + 0xffff) <= 1) {
        g = kart->mPos;
        if (b == 1) {
            kart->mUnk_48 |= 0x800000;
            b = 0xce;
        } else {
            kart->mUnk_48 |= 0x1000000;
            b = 0x15d;
        }
        g.y = kart->mPos.y - GetHeightAboveWaterOrEfct(kart->mPos.y);
        func_0208d978(&g, (kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) != 0);
        kart->mUnk_4c |= 0x4000000;
        StartSound(&kart->mSoundSource, b, 0x7f, 0);
        kart->mGravity = 0;
    }
    func_0210af40(kart, kart->mSoundIndex, 0);
}

void ApplyKartWaterDepth(Kart *kart) {
    BOOL b;
    s32 heightAboveWater;
    s32 scaledFactorPerDepth;
    Vec3 waterSurfacePoint;

    heightAboveWater = GetHeightAboveWaterOrEfct(kart->mPos.y);
    if (heightAboveWater < 0 && !(kart->mUnk_4c & 0x4000000)) {
        b = FALSE;
        scaledFactorPerDepth = ((s64) kart->mSpeedLimitFactorPerDepth * kart->mScale.z) >> 12;
        kart->mSpeedLimitFactor = (s32) (((s64) scaledFactorPerDepth * heightAboveWater) >> 12) + 0x1000;
        if (kart->mSpeedLimitFactor < kart->mPhysicalParam->mSurfaceSpeedLimitFactors[4]) {
            kart->mSpeedLimitFactor = kart->mPhysicalParam->mSurfaceSpeedLimitFactors[4];
        }
        func_0207a6c0(kart);
        kart->mWaterDepth = -heightAboveWater;
        if (GetHeightAboveWaterOrEfct(kart->mPos.y) <= -0xa000 &&
            GetHeightAboveWaterOrEfct(kart->mPrevPos.y) > -0xa000 && kart->mVelocity.y < -0x2000) {
            waterSurfacePoint = kart->mPos;
            waterSurfacePoint.y = kart->mPos.y - heightAboveWater;
            func_0208d978(&waterSurfacePoint, (kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) != 0);
            b = FALSE;
        }
        if (b != FALSE) {
            return;
        }
        if (kart->mUnk_4c & 0x4000000) {
            return;
        }
        ApplyKartWaterEffects(kart);
    } else {
        kart->mWaterDepth = 0;
        StopKartWaterEffects(kart);
    }
}

void AdvanceKartRaceStartBoost(Kart *kart) {
    s32 a;
    s32 b;
    s32 c;
    s32 d;
    u32 bits7c;
    Vec3 e;
    Vec3 f;
    Unk02165608 g;
    Unk02165608 h;

    if (kart->mUnk_48 & 2) {
        a = kart->mUnk_4d4;
        if (a < 0) {
            b = 0x52;
        } else if (a > 0x1000) {
            b = 8;
        } else {
            b = FX_Div(0x4a, 0x1000);
            b = 0x52 - (s32) (((s64) b * a) >> 12);
        }
        kart->mUnk_4d4 = kart->mUnk_4d4 + b;
        if (kart->mUnk_4d4 > 0x1000) {
            kart->mUnk_4d4 = 0x1000;
        }
    } else {
        kart->mUnk_4d4 = ((s64) kart->mUnk_4d4 * 0xf5c) >> 12;
    }
    if (!(kart->mUnk_4c & 0x20000000)) {
        if (GetRaceStartSequenceFrames() - 0xaf > 0) {
            kart->mUnk_44 |= 0x1000000;
        }
    }
    if (GetRaceStartSequenceFrames() - 0xaf == 0) {
        if (kart->mUnk_7c & 2) {
            if (func_0208c180(kart->mAi) != 0) {
                if (!(kart->mUnk_4c & 0x20000000)) {
                    kart->mUnk_4c |= 0x20000000;
                    kart->mRaceStartFrameCount = 0x78;
                    func_02068a64(kart, 1, 1);
                    g = data_usa_02165608;
                    bits7c = kart->mUnk_7c;
                    if ((bits7c & 0x10) && kart->mKartModelsEntry->mUnk_058 == 0) {
                        if ((bits7c & 1) || !(bits7c & 0x402000)) {
                            VEC_MultAdd(g.mUnk_00[kart->mKartModelsEntry->mUnk_004] << 4, &kart->mUnk_138, &kart->mPos,
                                        &e);
                            func_0208b748(0x72, &e, kart, func_0206c1ac);
                            func_0208b748(0x73, &e, kart, func_0206c1ac);
                        }
                    }
                    if (!(kart->mUnk_48 & 0x840)) {
                        func_0210af40(kart, kart->mSoundIndex, 3);
                    }
                    StartKartModelScaleAnimation(kart, 1);
                    kart->mModelScaleKind = 1;
                }
            } else if (GetKartAiBoostsAtRaceStart(kart->mAi) != 0) {
                d = GetKartAiRaceStartBoostChoice(kart->mAi);
                kart->mRaceStartFrameCount = data_usa_02154a48[d - 1];
                kart->mUnk_44 |= 0x1800000;
                StartKartBoost(kart, KART_BOOST_RACE_START, (s16) kart->mRaceStartFrameCount);
                if (!(kart->mUnk_48 & 0x840)) {
                    func_0210af40(kart, kart->mSoundIndex, 5);
                }
                kart->mUnk_48 |= 0x8000;
                if (kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) {
                    GetEntryKartCounters()->mUnk_00 = 1;
                } else {
                    StartSound(&kart->mSoundSource, 0xa1, 0x7f, 0);
                }
            }
        } else if (kart->mUnk_48 & 2) {
            c = kart->mUnk_4d4;
            if (c > 0xf34) {
                if (!(kart->mUnk_4c & 0x20000000)) {
                    kart->mUnk_4c |= 0x20000000;
                    kart->mRaceStartFrameCount = 0x78;
                    func_02068a64(kart, 1, 1);
                    h = data_usa_02165608;
                    bits7c = kart->mUnk_7c;
                    if ((bits7c & 0x10) && kart->mKartModelsEntry->mUnk_058 == 0) {
                        if ((bits7c & 1) || !(bits7c & 0x402000)) {
                            VEC_MultAdd(h.mUnk_00[kart->mKartModelsEntry->mUnk_004] << 4, &kart->mUnk_138, &kart->mPos,
                                        &f);
                            func_0208b748(0x72, &f, kart, func_0206c1ac);
                            func_0208b748(0x73, &f, kart, func_0206c1ac);
                        }
                    }
                    if (!(kart->mUnk_48 & 0x840)) {
                        func_0210af40(kart, kart->mSoundIndex, 3);
                    }
                    StartKartModelScaleAnimation(kart, 1);
                    kart->mModelScaleKind = 1;
                }
            } else if (c > 0xd9a) {
                d = 5;
                if (c < 0xe14) {
                    d = 1;
                } else if (c < 0xe7b) {
                    d = 2;
                } else if (c < 0xecd) {
                    d = 3;
                } else if (c < 0xf0a) {
                    d = 4;
                }
                kart->mRaceStartFrameCount = data_usa_02154a48[d - 1];
                kart->mUnk_44 |= 0x1800000;
                StartKartBoost(kart, KART_BOOST_RACE_START, (s16) kart->mRaceStartFrameCount);
                if (!(kart->mUnk_48 & 0x840)) {
                    func_0210af40(kart, kart->mSoundIndex, 5);
                }
                kart->mUnk_48 |= 0x8000;
                if (kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) {
                    GetEntryKartCounters()->mUnk_00 = 1;
                } else {
                    StartSound(&kart->mSoundSource, 0xa1, 0x7f, 0);
                }
            }
        }
        kart->mUnk_230 = func_01ffb0cc;
        if (!(kart->mUnk_4c & 0x20000000)) {
            kart->mUnk_44 |= 0x1000000;
        }
    }
    kart->mUnk_4e8 = kart->mUnk_4d4 + 0x1000;
}

void func_0206f824(Kart *kart, Vec3 *groundNormal, s32 bit100000WasSet) {
    Vec3 *mapObjectPosition;
    s32 limit;
    s32 step;
    Vec3 f;
    Vec3 g;

    mapObjectPosition = GetMapObjectPositionByTableIndex((u16) kart->mUnk_4d8);
    limit = func_020e7388((u16) kart->mUnk_4d8) * 150;
    step = 0x333;
    if (kart->mUnk_7c & 2) {
        limit >>= 1;
        step >>= 1;
    }
    if (bit100000WasSet == 0) {
        VEC_Subtract(mapObjectPosition, &kart->mPos, &g);
        Vec3CrossUnrounded(groundNormal, &g, &f);
        Vec3CrossUnrounded(&f, groundNormal, &g);
        if (!((s64) g.x * g.x + (s64) g.y * g.y + (s64) g.z * g.z < 0x10)) {
            Vec3NormalizeAndGetLengthUnchecked(&g, &kart->mUnk_268);
        }
    }
    kart->mUnk_44 |= 0x100000;
    kart->mUnk_274 = kart->mUnk_274 + step;
    if (kart->mUnk_274 > limit) {
        kart->mUnk_274 = limit;
    }
}

void func_0206f694(Kart *kart, u32 collisionFlags, Vec3 *b, s32 headingDelta) {
    Vec3 d;
    Vec3 e;

    if (collisionFlags & 0x40000000) {
        kart->mUnk_44 |= 0x40000;
        kart->mHeadingAngle += headingDelta;
    } else if (collisionFlags & 0x1e34ef) {
        kart->mUnk_1fc.y = 0;
    }
    if (b->x | b->y | b->z) {
        VEC_Subtract(b, &kart->mUnk_1fc, &d);
        if ((s64) d.x * d.x + (s64) d.y * d.y + (s64) d.z * d.z < 0x1000000) {
            kart->mUnk_1fc = *b;
        } else {
            VEC_MultAdd(0x199, &d, &kart->mUnk_1fc, &kart->mUnk_1fc);
        }
        kart->mVerticalSpeed = kart->mVerticalSpeed + kart->mUnk_1fc.y;
        kart->mUnk_1fc.y = 0;
    } else {
        e = data_usa_02165554;
        kart->mUnk_1fc.x = ((s64) kart->mUnk_1fc.x * e.x) >> 12;
        kart->mUnk_1fc.y = ((s64) kart->mUnk_1fc.y * e.y) >> 12;
        kart->mUnk_1fc.z = ((s64) kart->mUnk_1fc.z * e.z) >> 12;
        if ((s64) kart->mUnk_1fc.x * kart->mUnk_1fc.x + (s64) kart->mUnk_1fc.y * kart->mUnk_1fc.y +
                (s64) kart->mUnk_1fc.z * kart->mUnk_1fc.z <
            0xa429) {
            kart->mUnk_1fc = data_02154f94;
        }
    }
}

void func_0206f574(Kart *kart, u32 collisionFlags, Vec3 *contactNormal) {
    s32 baseSpeedLimitHitFactor;
    s32 d;
    u32 hitValue;

    if (collisionFlags & 0x200000) {
        baseSpeedLimitHitFactor = 0x1000;
    } else {
        baseSpeedLimitHitFactor = 0xccd;
    }
    hitValue = PickCollisionHitValue(0x214300);
    func_0206f04c(kart, contactNormal, (kart->mUnk_44 & 0x80) != 0, baseSpeedLimitHitFactor,
                  (s32) (hitValue & 0x1f00) >> 8, ((hitValue & 0xe0) << 11) >> 16, 2);
    kart->mUnk_44 |= 0x80;
    kart->mUnk_250 = *contactNormal;
    if (kart->mState == KART_STATE_LAUNCH_DOUBLE_FLIP && contactNormal->y < -0x800 && kart->mVerticalSpeed > 0) {
        kart->mVerticalSpeed = -kart->mVerticalSpeed;
    }
    d = contactNormal->y;
    if (d <= 0) {
        d = -d;
    }
    if (d > 0x3e8) {
        kart->mUnk_44 |= 0x40000000;
    }
    if (!(collisionFlags & 0x2000000)) {
        return;
    }
    if (data_0217ac10 == 0) {
        return;
    }
    if (collisionFlags & 0x10000) {
        kart->mUnk_44 |= 0x4000000;
    }
}

s32 func_0206f04c(Kart *kart, Vec3 *contactNormal, s32 wasTouching, s32 baseSpeedLimitHitFactor, s32 d, s32 e, s32 f) {
    BOOL j;
    s32 g;
    s32 h;
    s32 i;
    s32 k;
    s16 l;
    Vec3 m;
    Vec3 o;
    Vec3 n;

    j = FALSE;
    i = Vec3DotUnrounded(&kart->mSignedTurnedForward, contactNormal) + 0x1000;
    if (i > 0x1000) {
        i = 0x1000;
    } else if (i < 0x29) {
        i = 0x29;
    }
    g = VEC_DotProduct(contactNormal, &kart->mHitVelocity);
    kart->mHitVelocity.x = kart->mHitVelocity.x - (s32) (((s64) contactNormal->x * g) >> 12);
    kart->mHitVelocity.y = kart->mHitVelocity.y - (s32) (((s64) contactNormal->y * g) >> 12);
    kart->mHitVelocity.z = kart->mHitVelocity.z - (s32) (((s64) contactNormal->z * g) >> 12);
    g = VEC_DotProduct(contactNormal, &kart->mPrevHitVelocity);
    kart->mPrevHitVelocity.x = kart->mPrevHitVelocity.x - (s32) (((s64) contactNormal->x * g) >> 12);
    kart->mPrevHitVelocity.y = kart->mPrevHitVelocity.y - (s32) (((s64) contactNormal->y * g) >> 12);
    k = ((s64) baseSpeedLimitHitFactor * i) >> 12;
    kart->mPrevHitVelocity.z = kart->mPrevHitVelocity.z - (s32) (((s64) contactNormal->z * g) >> 12);
    kart->mSpeedLimitHitFactor = k;
    if (Vec3DotUnrounded(&kart->mUnk_1fc, contactNormal) < -0x800) {
        kart->mUnk_1fc = data_02154f94;
    }
    if (wasTouching == 0) {
        h = Vec3DotUnrounded(&kart->mUnk_138, contactNormal);
        j = TRUE;
        g = VEC_DotProduct(contactNormal, &kart->mVelocity);
        m.x = ((s64) contactNormal->x * g) >> 12;
        m.y = ((s64) contactNormal->y * g) >> 12;
        m.z = ((s64) contactNormal->z * g) >> 12;
        kart->mDriftCharge = 0;
        kart->mRightTurnCount = 0;
        kart->mLeftTurnCount = kart->mRightTurnCount;
        kart->mTurnCountTimer = 0;
        kart->mHeadingAnglePerFrame = 0;
        if (kart->mVelocityLength > 0x1800) {
            if (!(kart->mUnk_48 & KART_48_BOOST) && (m.x != 0 || m.y != 0 || m.z != 0) &&
                baseSpeedLimitHitFactor != 0x1000) {
                BounceVelocityOffSurface(&m, contactNormal, 0, 0x4cd, 0, &m);
                kart->mHitVelocity.x = m.x;
                kart->mHitVelocity.z = m.z;
                kart->mVerticalSpeed = kart->mVerticalSpeed + m.y;
            }
            if (kart->mUnk_4da <= 0) {
                if (d >= 0) {
                    func_0210b234(kart, 0, d, e, 0);
                }
                if (f == 2 && e != 5 && kart->mKartModelsEntry->mUnk_058 == 0) {
                    k = kart->mUnk_7c;
                    g = 0;
                    if (!(k & 1) && (k & 0x402000)) {
                        g = 1;
                    }
                    if (g == 0) {
                        n = kart->mPos;
                        g = 0x800;
                        if (kart->mUnk_4c & 0x10000) {
                            g = 0x4cd;
                        }
                        VEC_MultAdd(-kart->mRadius, contactNormal, &kart->mPos, &n);
                        VEC_MultAdd(((s64) kart->mScale.y * (g << 4) + 0x800) >> 12, &kart->mUnk_12c, &n, &n);
                        func_0208b748(0x3b, &n, kart, func_0206c488);
                    }
                }
                StartKartModelScaleAnimation(kart, 2);
            }
        }
        if (h > 0) {
            kart->mSpeedLimitHitFactor = 0x4cd;
            if (kart->mSurfaceGroup != 0xb && kart->mSurfaceGroup != 8) {
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
            }
            if (kart->mVelocityLength > 0x2000 && baseSpeedLimitHitFactor != 0x1000) {
                l = (kart->mVelocityLength >> 12) * 100;
                if ((u16) kart->mTurnAngle > 0x7fff) {
                    l = l * -1;
                }
                kart->mHeadingAnglePerFrame = l;
            }
        } else if (kart->mVelocityLength > 0x2000 && baseSpeedLimitHitFactor != 0x1000) {
            k = 0x1000 - i;
            if (kart->mVelocityLength > 0x1800 && k > 0x19a) {
                l = ((s32) (((s64) kart->mVelocityLength * k) >> 12) >> 12) * 30;
                Vec3CrossUnrounded(&kart->mSignedTurnedForward, contactNormal, &o);
                if (Vec3DotUnrounded(&o, &kart->mUnk_12c) < 0) {
                    l = l * -1;
                }
                kart->mHeadingAnglePerFrame = l;
            }
        }
        if ((kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) && kart->mVelocityLength > 0x3000 && f == 2) {
            GetEntryKartCounters()->mUnk_10++;
        }
        kart->mTurnAngle = 0;
    } else if (e == 4) {
        func_020813ec(kart->mIndex, contactNormal);
    }
    if (kart->mState != KART_STATE_NORMAL) {
        kart->mHeadingAnglePerFrame = 0;
    }
    return j;
}
