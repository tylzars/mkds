#include "Main/Unknown/code_0206bcb0.h"
#include "01/code_0218155c.h"
#include "code_02147cd8.h"
#include "code_0201c528.h"
#include "Main/Unknown/code_02109000.h"
#include "Main/Unknown/code_02080cd0.h"
#include "Main/Unknown/code_0208c188.h"
#include "Main/Unknown/code_0208c534.h"
#include "Main/Unknown/code_02109054.h"
#include "Main/Unknown/code_0206a354.h"
#include "Main/Unknown/code_0206d020.h"
#include "ITCM/code_01ffba68.h"
#include "Main/Unknown/code_020681f0.h"

void AdvanceKartBoost(s32 *acceleration, Kart *kart) {
    int secondArgument;
    u32 flags;
    KartItemEffectState *q;
    u16 diffColor;
    u16 emiColor;
    u16 ambColor;

    kart->mBoostTimer = kart->mBoostTimer - 1;
    if (kart->mBoostTimer <= 0) {
        kart->mUnk_48 &= 0xdfff7fdf;
        kart->mBoostTimer = 0;
        if (!(kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY)) {
            return;
        }
        if (!(kart->mUnk_4c & 0x10000000)) {
            ResetCameraHalfFovAngleGoal();
        }
        StopDispCapBlend();
        return;
    }
    *acceleration = 0x1000;
    if (kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) {
        secondArgument = (kart->mUnk_48 & 0x8000) ? 0xa0 : 0x9e;
        AddSoundRequest(data_0217d26c, GetKartCameraDistanceSquared(kart->mIndex), func_020718c8, kart, secondArgument);
    }
    if (!(kart->mUnk_48 & 0x20000000)) {
        return;
    }
    SkipOrthoQuadsHoldAndSetVelocities(kart->mIndex);
    flags = kart->mUnk_4c;
    if (flags & 0x20000) {
        return;
    }
    if (!(flags & 0x8000000)) {
        return;
    }
    q = &kart->mUnk_538;
    if (q->mUnk_1c > 400) {
        return;
    }
    q->mUnk_1c = 400;
    kart->mUnk_4c |= 0x20000;
    diffColor = GetKartCourseDiffColor();
    emiColor = GetKartCourseEmiColor();
    ambColor = GetKartCourseAmbColor();
    StartKartModelColorBlend(kart->mKartModelsEntry, diffColor, emiColor, ambColor);
}

void EndKartDrift(Kart *kart) {
    if (!(kart->mUnk_44 & KART_44_ON_GROUND)) {
        kart->mUnk_44 |= 0x8000;
    }
    if (kart->mDriftCharge == 4) {
        StartKartBoost(kart, KART_BOOST_MINI_TURBO, kart->mPhysicalParam->mUnk_0e);
        kart->mUnk_48 |= KART_48_MINI_TURBO;
        kart->mMiniTurboTimer = kart->mPhysicalParam->mUnk_0e;
        if (kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) {
            GetEntryKartCounters()->mUnk_04++;
            // placeholder: the same test twice gives the original's two loads and compares
            if (gRaceSetup->mMode == MODE_MISSION_RUN && gRaceSetup->mMode == MODE_MISSION_RUN) {
                func_ov001_0218171c();
            }
        }
    }
    kart->mUnk_44 &= 0xfffff7f4;
    kart->mTurnDirection = 0;
    kart->mDriftCharge = 0;
    kart->mRightTurnCount = 0;
    kart->mLeftTurnCount = kart->mRightTurnCount;
    kart->mTurnCountTimer = 0;
    StopKartTurnEffects(GetKartTurnEffects(kart->mIndex));
}

void func_0206cc60(Kart *kart, int fromLowSpeedTurn) {
    if (kart->mTurnDirection > 0) {
        if (kart->mTurnAngle > 11000) {
            kart->mTurnAngle = kart->mTurnAngle - 200;
            if (kart->mTurnAngle < 11000) {
                kart->mTurnAngle = 11000;
            }
        } else if (kart->mTurnAngle < 11000) {
            kart->mTurnAngle += 375;
            if (kart->mTurnAngle > 11000) {
                kart->mTurnAngle = 11000;
            }
        }
    } else {
        if (kart->mTurnAngle < -11000) {
            kart->mTurnAngle = kart->mTurnAngle + 200;
            if (kart->mTurnAngle > -11000) {
                kart->mTurnAngle = -11000;
            }
        } else if (kart->mTurnAngle > -11000) {
            kart->mTurnAngle -= 375;
            if (kart->mTurnAngle < -11000) {
                kart->mTurnAngle = -11000;
            }
        }
    }
    if (fromLowSpeedTurn != 0) {
        return;
    }
    if (kart->mUnk_38a <= 50) {
        kart->mUnk_38a = 50;
    } else {
        kart->mUnk_38a = (s32) (((s64) kart->mUnk_38a * 0xf33) >> 12);
    }
    AdvanceKartDriftCharge(kart);
    if (!(kart->mUnk_44 & KART_44_ON_GROUND)) {
        return;
    }
    func_01ffc9e8(kart, 1);
    kart->mUnk_4c |= 0x2;
    if (kart->mDriftCharge < 3) {
        return;
    }
    if (!(kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY)) {
        return;
    }
    StartSoundWhileRequested(&kart->mSoundSource, 0xd1, 0x7f, 0);
}

// Drift step: the hop, the turn held after it, the charge, and the release with the mini-turbo.
void AdvanceKartDrift(Kart *kart) {
    u32 bits44 = kart->mUnk_44;
    BOOL hasB = (bits44 & 2) != 0;
    u32 g;
    KartTurnEffects *turnEffects;
    int distanceSquared;
    enum { K0 } entryIndex;

    if (kart->mUnk_7c & 0x400) {
        return;
    }
    if (kart->mAirborneFrames >= 5 && !(bits44 & 0x1a)) {
        entryIndex = kart->mEntryIndex;
        if ((u16) (data_02175628[entryIndex].mBits & PAD_KEY_R)) {
            if (bits44 & 1) {
                goto recheck;
            }
            if (kart->mTurnDirection != 0) {
                goto recheck;
            }
            g = kart->mUnk_48;
            if (g & KART_48_TURN_RIGHT) {
                kart->mTurnDirection = 1;
                kart->mUnk_44 |= 1;
            } else if (g & KART_48_TURN_LEFT) {
                kart->mTurnDirection = -1;
                kart->mUnk_44 |= 1;
            }
        } else {
            kart->mUnk_44 &= ~1;
        }
    }
recheck:
    if (kart->mUnk_44 & 2) {
        if (kart->mTurnDirection == 0) {
            g = kart->mUnk_48;
            if (g & KART_48_TURN_RIGHT) {
                kart->mTurnDirection = 1;
            } else if (g & KART_48_TURN_LEFT) {
                kart->mTurnDirection = -1;
            }
        }
    }
    bits44 = kart->mUnk_44;
    g = kart->mTurnDirection;
    if (!(bits44 & KART_44_DRIFTING) && (bits44 & KART_44_ON_GROUND)) {
        if ((bits44 & 3) &&
            kart->mVelocityLength > (s32) (((s64) kart->mPhysicalParam->mBaseSpeedLimit * 0x8cd) >> 12) && g != 0 &&
            (u16) (data_02175628[entryIndex = kart->mEntryIndex].mBits & PAD_KEY_R)) {
            kart->mUnk_44 |= KART_44_DRIFTING;
            kart->mDriftCharge = 1;
            if (kart->mTurnDirection > 0) {
                kart->mAwayTurnCounter = &kart->mLeftTurnCount;
                kart->mTowardTurnCounter = &kart->mRightTurnCount;
            } else {
                kart->mAwayTurnCounter = &kart->mRightTurnCount;
                kart->mTowardTurnCounter = &kart->mLeftTurnCount;
            }
            if (kart->mUnk_4c & 0x8000) {
                turnEffects = GetKartTurnEffects(kart->mIndex);
                ResetKartLevel4Effects(turnEffects);
                StartKartTurnStartEffects(turnEffects);
            }
        } else {
            kart->mTurnDirection = 0;
        }
        kart->mUnk_44 &= 0xfffff7fc;
    }
    bits44 = kart->mUnk_44;
    if (bits44 & KART_44_DRIFTING) {
        entryIndex = kart->mEntryIndex;
        if (!((u16) (data_02175628[entryIndex].mBits & PAD_KEY_R) && (kart->mUnk_48 & 2) &&
              kart->mVelocityLength >= kart->mPhysicalParam->mBaseSpeedLimit / 2 && !(bits44 & 0x2000c0))) {
            if (!(bits44 & KART_44_ON_GROUND)) {
                kart->mUnk_44 |= 0x8000;
            }
            if (kart->mDriftCharge == 4) {
                StartKartBoost(kart, KART_BOOST_MINI_TURBO, kart->mPhysicalParam->mUnk_0e);
                kart->mUnk_48 |= KART_48_MINI_TURBO;
                kart->mMiniTurboTimer = kart->mPhysicalParam->mUnk_0e;
                if (kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) {
                    GetEntryKartCounters()->mUnk_04++;
                    // placeholder: the same test twice gives the original's two loads and compares
                    if (gRaceSetup->mMode == MODE_MISSION_RUN && gRaceSetup->mMode == MODE_MISSION_RUN) {
                        func_ov001_0218171c();
                    }
                }
            }
            kart->mUnk_44 &= 0xfffff7f4;
            kart->mTurnDirection = 0;
            kart->mDriftCharge = 0;
            kart->mRightTurnCount = 0;
            kart->mLeftTurnCount = kart->mRightTurnCount;
            kart->mTurnCountTimer = 0;
            StopKartTurnEffects(GetKartTurnEffects(kart->mIndex));
        } else if (bits44 & KART_44_ON_GROUND) {
            func_0206cc60(kart, 0);
        }
    }
    if (hasB && (kart->mUnk_44 & KART_44_ON_GROUND)) {
        int turn = 0;
        int dot;
        int ang;
        int len;
        Vec3 v;
        Vec3 w;
        Vec3 *q = &kart->mUnk_138;

        dot = VEC_DotProduct(&kart->mHopStartUp, q);
        v.x = kart->mUnk_138.x - (s32) (((s64) kart->mHopStartUp.x * dot) >> 12);
        v.y = q->y - (s32) (((s64) kart->mHopStartUp.y * dot) >> 12);
        v.z = q->z - (s32) (((s64) kart->mHopStartUp.z * dot) >> 12);
        if ((s64) v.x * v.x + (s64) v.y * v.y + (s64) v.z * v.z >= 16 ? Vec3NormalizeAndGetLengthUnchecked(&v, &v)
                                                                      : 0) {
            Vec3CrossUnrounded(&kart->mHopStartForward, &v, &w);
            len = VEC_Mag(&w);
            ang = FX_Atan2(len, Vec3DotUnrounded(&kart->mHopStartForward, &v));
            turn = (s16) (((s64) ang * 0x28be60db9391LL + 0x80000000LL) >> 44);
        }
        if (kart->mForwardSpeed < 0) {
            g = -g;
        }
        kart->mTurnAngle += (s16) (turn * g);
        if (kart->mTurnAngle > 0x2af8) {
            kart->mTurnAngle = 0x2af8;
        } else if (kart->mTurnAngle < -0x2af8) {
            kart->mTurnAngle = -0x2af8;
        }
        if (!(kart->mUnk_44 & KART_44_DRIFTING)) {
            return;
        }
        kart->mUnk_38a = (s32) (((s64) kart->mVelocityLength * 0x1a) >> 12);
        return;
    }
    entryIndex = kart->mEntryIndex;
    if (!(u16) (data_02175628[entryIndex].mPressedBits & PAD_KEY_R)) {
        if (!(kart->mUnk_44 & 0x20000000)) {
            return;
        }
    }
    if (kart->mUnk_4c & 0x10000000) {
        return;
    }
    if (!(kart->mUnk_44 & KART_44_ON_GROUND)) {
        return;
    }
    if (kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) {
        distanceSquared = GetKartCameraDistanceSquared(kart->mIndex);
        AddSoundRequest(&data_0217d284, distanceSquared + func_0210a578(), func_02071944, kart, 0xcf);
    }
    kart->mUnk_44 |= 0x806;
    kart->mUnk_44 &= 0xffff7ff7;
    kart->mHopSpeed = 0x1405;
    kart->mVerticalSpeed += 0x21a2;
    kart->mHopHeight = 0;
    kart->mTurnDirection = 0;
    kart->mUnk_38a = 0;
    kart->mDriftCharge = 0;
    kart->mRightTurnCount = 0;
    kart->mLeftTurnCount = kart->mRightTurnCount;
    kart->mTurnCountTimer = 0;
    GetKartForward(kart, &kart->mHopStartForward);
    GetKartUp(kart, &kart->mHopStartUp);
    if (kart->mUnk_208->mUnk_00 != FALSE) {
        kart->mUnk_208->mUnk_00 = FALSE;
    }
    if (kart->mUnk_7c & 0x200) {
        kart->mUnk_514->mUnk_2c ^= 0x1;
    }
}

// At low speed, with the A and B keys held and no boost running, steers the kart with the left and right keys; TRUE
// when it acts.
int TryTurnKartAtLowSpeed(Kart *kart) {
    BOOL result = FALSE;
    BOOL pending = TRUE;
    BOOL dir = FALSE;
    int delta;
    u16 bits;
    KartTurnEffects *turnEffects;
    enum { K0 } entryIndex;

    if (kart->mVelocityLength < 0x1800 && (kart->mUnk_48 & 0x80)) {
        kart->mTurnDirection = 0;
        result = TRUE;
        pending = FALSE;
        entryIndex = kart->mEntryIndex;
        bits = data_02175628[entryIndex].mBits;
        if ((u16) (bits & PAD_KEY_LEFT)) {
            dir = TRUE;
            kart->mTurnDirection = -1;
            delta = 500;
        } else if ((u16) (bits & PAD_KEY_RIGHT)) {
            dir = TRUE;
            kart->mTurnDirection = 1;
            delta = -500;
        }
        if (kart->mUnk_44 & KART_44_ON_GROUND) {
            if (GetKartTurnEffects(kart->mIndex)->mTurnStartPresent == 0 && (kart->mUnk_4c & 0x8000)) {
                turnEffects = GetKartTurnEffects(kart->mIndex);
                ResetKartLevel4Effects(turnEffects);
                StartKartTurnStartEffects(turnEffects);
            }
            kart->mUnk_48 |= 0x100;
            if (kart->mTurnDirection != 0) {
                kart->mUnk_44 |= 0x8000000;
                kart->mHeadingAngle += delta;
                func_0206cc60(kart, 1);
            }
        }
        func_0210b4e0(kart, dir, kart->mSurfaceKind, kart->mSurfaceVariant);
    }
    if (pending) {
        StopKartTurnStartEffects(GetKartTurnEffects(kart->mIndex));
    }
    return result;
}

void func_0206c488(Unk0201ca6c *emitter, Kart *kart) {
    func_02080e88(emitter, kart);
}

void func_0206c450(Unk0201ca6c *emitter, Kart *kart) {
    emitter->mUnk_40 = kart->mEffectVelocity;
    func_02080e88(emitter, kart);
}

// Starts the effects of a kart-kart hit at the contact point; flag picks the four-effect set.
BOOL TryStartKartCollisionEffects(Kart *kart, const Vec3 *overlapDirection, int flag) {
    if (kart->mUnk_7c & KART_7C_MODELS_ENTRY_008_SET) {
        int fourEffectIds[4] = {0x77, 0x76, 0x78, 0x79};
        u16 i = 0;
        u32 effectCount = 1;
        int *effectIds = data_02154f10;
        Vec3 contactPoint;

        if (flag) {
            effectIds = fourEffectIds;
            effectCount = 4;
        }
        VEC_MultAdd(-kart->mRadius, overlapDirection, &kart->mPos, &contactPoint);
        VEC_MultAdd(((s64) kart->mScale.y * 0x8000 + 0x800) >> 12, &kart->mUnk_12c, &contactPoint, &contactPoint);
        for (; i < effectCount; i++) {
            StartEffectWithCallback(effectIds[i], &contactPoint, kart, func_0206c450);
        }
        return TRUE;
    }
    return FALSE;
}

void func_0206c2b4(Unk0201ca6c *emitter, Kart *kart) {
    Vec3 velocity = kart->mEffectVelocity;

    velocity.y = 0;
    velocity.x = ((s64) velocity.x * 0xe66) >> 12;
    velocity.y = ((s64) velocity.y * 0xe66) >> 12;
    velocity.z = ((s64) velocity.z * 0xe66) >> 12;
    emitter->mUnk_40 = velocity;
}

void func_0206c1ac(Unk0201ca6c *emitter, Kart *kart) {
    Vec3 position = kart->mPos;
    Vec3s16 rot;
    Vec3 *q;

    VEC_MultAdd(((s64) kart->mRadius * -0x1333 + 0x800) >> 12, &kart->mUnk_138, &position, &position);
    position.x >>= 4;
    position.y >>= 4;
    position.z >>= 4;
    emitter->mUnk_28.x = emitter->mUnk_20->mUnk_00->mUnk_04.x + position.x;
    emitter->mUnk_28.y = position.y + emitter->mUnk_20->mUnk_00->mUnk_04.y;
    emitter->mUnk_28.z = position.z + emitter->mUnk_20->mUnk_00->mUnk_04.z;
    q = &kart->mUnk_138;
    rot.x = q->x;
    rot.y = q->y;
    rot.z = q->z;
    emitter->mUnk_50 = rot;
}

void func_0206c17c(Kart *kart) {
    if (kart->mUnk_7c & 0x40000) {
        return;
    }
    kart->mUnk_4c |= 0x400000;
    kart->mUnk_506 = 0;
    kart->mUnk_504 = kart->mUnk_506;
}

void SetupKartAiHeldItemEntry(Kart *kart) {
    if (kart->mUnk_7c & 0x2) {
        CallKartAiSetupHeldItemEntry(kart->mAi);
    }
}

void SetupKartAiItemInUseEntry(Kart *kart) {
    if (kart->mUnk_7c & 0x2) {
        CallKartAiSetupItemInUseEntry(kart->mAi);
    }
}

BOOL func_0206c0e0(Kart *kart) {
    if ((kart->mUnk_7c & 0x402020) || (kart->mUnk_4c & 0x800) || kart->mState != KART_STATE_NORMAL) {
        return TRUE;
    }
    return FALSE;
}

BOOL func_0206c0b0(Kart *kart) {
    if ((kart->mUnk_7c & 0x400020) || (kart->mUnk_4c & 0x800)) {
        return TRUE;
    }
    return FALSE;
}

int func_0206c0a8(Kart *kart) {
    return kart->mUnk_4c0;
}

BOOL func_0206c094(Kart *kart) {
    return (kart->mUnk_4c & 0x800000) != 0;
}

void StartKartState(Kart *kart, KartState mode) {
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
    func_02068a64(kart, 1, 0);
    kart->mState = mode;
    kart->mUnk_44 &= 0xfffff7f4;
    kart->mTurnDirection = 0;
    kart->mDriftCharge = 0;
    kart->mRightTurnCount = 0;
    kart->mLeftTurnCount = kart->mRightTurnCount;
    kart->mTurnCountTimer = 0;
    StopKartTurnEffects(GetKartTurnEffects(kart->mIndex));
    if (kart->mUnk_4c & 0x2000) {
        kart->mUnk_4c &= ~0x2000;
        kart->mUnk_d8 = 0x1000;
        if (!(kart->mUnk_4c & 0x8000000)) {
            func_0207b0d0(kart);
        }
        func_02080ee4(kart);
    }
}

BOOL TryStartKartState(Kart *kart, KartState newState) {
    BOOL ok;
    BOOL res;
    BOOL t;
    int currentState;
    u32 bits4c = kart->mUnk_4c;

    if (bits4c & 0x400000) {
        ok = FALSE;
    } else if (kart->mUnk_7c & 0x200) {
        if (kart->mState == KART_STATE_NORMAL && !(kart->mUnk_48 & 0x1800) && !(bits4c & 0x10000040)) {
            ok = TRUE;
        } else {
            ok = FALSE;
        }
    } else {
        switch (newState) {
            case KART_STATE_1:
            case KART_STATE_SPIN:
                res = TRUE;
                if (!(bits4c & 0x10000040) && !(kart->mUnk_48 & 0x1800)) {
                    currentState = kart->mState;
                    t = FALSE;
                    if (currentState != KART_STATE_NORMAL && currentState != KART_STATE_1 &&
                        currentState != KART_STATE_SPIN) {
                        t = TRUE;
                    }
                    if (t == FALSE) {
                        res = FALSE;
                    }
                }
                ok = res == FALSE;
                break;
            default:
                res = TRUE;
                if (!(bits4c & 0x10000040) && !(kart->mUnk_48 & 0x1800)) {
                    currentState = kart->mState;
                    t = FALSE;
                    if (currentState != KART_STATE_NORMAL && currentState != KART_STATE_1 &&
                        currentState != KART_STATE_SPIN) {
                        t = TRUE;
                    }
                    if (t == FALSE) {
                        res = FALSE;
                    }
                }
                ok = res == FALSE;
                break;
        }
    }
    if (!ok) {
        return FALSE;
    }
    StartKartState(kart, newState);
    return TRUE;
}

// Starts a spin, or adds a turn to the spin already running.
BOOL TrySpinKart(Kart *kart, int rotationCount, int b) {
    int currentState = kart->mState;
    BOOL x;
    BOOL ok;
    BOOL res;
    BOOL t;
    int v;
    u32 bits4c;

    x = currentState != KART_STATE_1 && currentState != KART_STATE_SPIN;
    if (x == FALSE) {
        if (kart->mYRotationCount * 0xffff - kart->mYRotationAngleSum > 0xffff || (kart->mUnk_7c & 0x200)) {
            return FALSE;
        }
    }
    bits4c = kart->mUnk_4c;
    if (bits4c & 0x400000) {
        ok = FALSE;
    } else if (kart->mUnk_7c & 0x200) {
        if (kart->mState == KART_STATE_NORMAL && !(kart->mUnk_48 & 0x1800) && !(bits4c & 0x10000040)) {
            ok = TRUE;
        } else {
            ok = FALSE;
        }
    } else {
        res = TRUE;
        if (!(bits4c & 0x10000040) && !(kart->mUnk_48 & 0x1800)) {
            v = kart->mState;
            t = FALSE;
            if (v != KART_STATE_NORMAL && currentState != KART_STATE_1 && currentState != KART_STATE_SPIN) {
                t = TRUE;
            }
            if (t == FALSE) {
                res = FALSE;
            }
        }
        ok = res == FALSE;
    }
    if (!ok) {
        return FALSE;
    }
    if (x) {
        StartKartState2(kart, rotationCount, b);
        if (b == 0) {
            if (rotationCount == 1) {
                if (kart->mUnk_7c & 0x200) {
                    kart->mUnk_514->mUnk_2c ^= 0x4;
                }
            } else if (rotationCount == 2) {
                if (kart->mUnk_7c & 0x200) {
                    kart->mUnk_514->mUnk_2c ^= 0x8;
                }
            }
        }
    } else {
        kart->mYRotationCount++;
    }
    return TRUE;
}
