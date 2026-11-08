#include "Main/Unknown/code_0206a354.h"
#include "01/code_0218155c.h"
#include "ITCM/code_01ffba68.h"
#include "ITCM/code_01ffc000.h"
#include "ITCM/code_01ffcf7c.h"
#include "ITCM/code_01ffd000.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02055730.h"
#include "Main/Unknown/code_02063b50.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_02073eb8.h"
#include "Main/Unknown/code_02070398.h"
#include "Main/Unknown/code_02080cd0.h"
#include "Main/Unknown/code_020888b4.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_0208aea8.h"
#include "Main/Unknown/code_0208b484.h"
#include "Main/Unknown/code_02109054.h"
#include "Main/Unknown/code_0210a644.h"
#include "Main/Unknown/code_0210a664.h"
#include "Main/Unknown/code_0210f868.h"
#include "Main/Unknown/code_0210fa3c.h"
#include "Main/Unknown/code_0210fa40.h"
#include "Main/Unknown/code_020ed5c0.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/unk_02154000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_027e0000.h"
#include "code_02146d78.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_0203c8dc.h"
#include "Main/Unknown/code_020681f0.h"

void StartKartState2(Kart *p, int a, int b) {
    int d = 1;

    StartKartState(p, KART_STATE_SPIN);
    if (p->mUnk_44 & 0xa) {
        if (p->mTurnDirection == 1) {
            d = -1;
        }
    } else if (p->mTurnRatio < 0) {
        d = -1;
    }
    p->mYRotationAnglePerFrame = 0x750;
    p->mYRotationAnglePerFrame = p->mYRotationAnglePerFrame * d;
    p->mYRotationAngle = 0;
    p->mYRotationAngleSum = 0;
    p->mYRotationCount = a;
    p->mUnk_4c |= 0x20;
    func_020efea4(&(gKartItems)[p->mIndex]);
    if (gRaceSetup->mMode == MODE_MISSION_RUN && gRaceSetup->mMode == MODE_MISSION_RUN) {
        func_ov001_0218173c();
    }
    if (b != 0) {
        return;
    }
    if (p->mUnk_48 & 0x840) {
        return;
    }
    func_0210af40(p, p->mSoundIndex, 1);
}

void AdvanceKartState1And2(Kart *p) {
    if (p->mUnk_4c & 0x20) {
        return;
    }
    p->mUnk_48 |= 0x44000;
    p->mUnk_23a = 0xa;
    p->mState = KART_STATE_NORMAL;
    p->mUnk_4c &= ~0x30;
    p->mUnk_48 &= ~0x20000;
    func_02068a64(p, 0, 1);
    p->mUnk_44 |= 0x80000000;
    if ((p->mUnk_7c & 0x2) && gRaceSetup->mMode == MODE_BATTLE && gRaceSetup->mBattleKind == BATTLE_KIND_BALLOON) {
        PickKartAiBalloonCountGoal(p->mAi);
    }
}

BOOL TryStartKartState6(Kart *p) {
    if (!TryStartKartState(p, KART_STATE_LAUNCH_DOUBLE_FLIP)) {
        return FALSE;
    }
    StartKartState6(p);
    if (p->mUnk_7c & 0x200) {
        p->mUnk_514->mUnk_2c ^= 0x20000;
    }
    return TRUE;
}

void StartKartState6(Kart *p) {
    p->mForwardSpeed = 0;
    p->mTurnAngle = 0;
    p->mUnk_48 &= 0xdfe77fdf;
    p->mBoostTimer = 0;
    p->mUnk_538.mUnk_00 = 0;
    p->mMiniTurboTimer = 0;
    if (p->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) {
        if (!(p->mUnk_4c & 0x10000000) && !(p->mUnk_48 & 0x4000000)) {
            ResetCameraHalfFovAngleGoal();
        }
        StopDispCapBlend();
    }
    if (p->mUnk_4c & 0x2000) {
        p->mUnk_4c &= ~0x2000;
        p->mUnk_d8 = 0x1000;
        if (!(p->mUnk_4c & 0x8000000)) {
            func_0207b0d0(p);
        }
        func_02080ee4(p);
    }
    p->mState = KART_STATE_LAUNCH_DOUBLE_FLIP;
    p->mUnk_4c |= 0x10;
    p->mVerticalSpeed = 0x6000;
    p->mRotationAngleSum = 0;
    p->mRotationAngle = 0;
    p->mRotationAnglePerFrame = 0xfa0;
    p->mRotationEndFrames = 0;
    GetKartMatrixRow0(p, &p->mRotationAxis);
    GetKartForward(p, &p->mLaunchForward);
    p->mUnk_334 = 0;
    p->mUnk_338 = 0;
    p->mUnk_33c = 0;
    p->mUnk_344 = 0;
    p->mLaunchStartY = p->mPos.y;
    p->mLaunchFrames = 0;
    func_020eff40(&(gKartItems)[p->mIndex]);
    if (gRaceSetup->mMode == MODE_MISSION_RUN && gRaceSetup->mMode == MODE_MISSION_RUN) {
        func_ov001_0218173c();
    }
    if (!(p->mUnk_48 & 0x840)) {
        func_0210af40(p, p->mSoundIndex, 2);
    }
    p->mUnk_4c &= ~0x80000000;
    if (p->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) {
        SetCameraHeightHold(1);
    }
}

void AdvanceKartState6(Kart *p) {
    Vec3 a;
    s32 c;
    u16 i;

    if (p->mRotationEndFrames == 0) {
        MtxFx33 m;

        p->mForwardSpeed = 0;
        if ((p->mRotationAngleSum > 0 ? p->mRotationAngleSum : -p->mRotationAngleSum) < 0x1ffff) {
            p->mRotationAngle = p->mRotationAngle - p->mRotationAnglePerFrame;
            p->mRotationAngleSum = p->mRotationAngleSum + p->mRotationAnglePerFrame;
            c = p->mRotationAnglePerFrame;
            if (c <= 0xc8) {
                p->mRotationAnglePerFrame = 0xc8;
            } else {
                p->mRotationAnglePerFrame = ((s64) c * 0xf85) >> 12;
            }
        } else {
            p->mRotationAngle = 0;
        }
        if (p->mUnk_44 & 0x10000) {
            if (p->mRotationAngleSum < 0x13000) {
                p->mVerticalSpeed += 0x1800;
            }
        }
        if ((p->mUnk_33c > 0 ? p->mUnk_33c : -p->mUnk_33c) >= 0xffff) {
            p->mUnk_338 = 0;
            p->mUnk_334 = 0;
        } else {
            p->mUnk_338 += 0x3e8;
            p->mUnk_33c += 0x3e8;
            p->mUnk_334 = gPairsByAngle[(p->mUnk_338 >> 4) * 2];
        }
        i = ((s64) p->mUnk_334 * 0xce4) >> 12;
        MTX_RotAxis33((MtxFx43 *) &m, &p->mLaunchForward, gPairsByAngle[(i >> 4) * 2], gPairsByAngle[(i >> 4) * 2 + 1]);
        MTX_MultVec33(&p->mRotationAxis, m.mUnk_00, &a);
        QuaternionFromAxisAngle(&a, p->mRotationAngle, &p->mRotationQuaternion);
    } else {
        Vec4 q;

        q = data_usa_0216556c;
        QuaternionBlend(&p->mRotationQuaternion, &q, &p->mRotationQuaternion, 0x266);
    }
    QuaternionNormalize(&p->mRotationQuaternion, &p->mRotationQuaternion);
    if (!(p->mUnk_4c & 0x80000000)) {
        if ((u32) p->mLaunchFrames > 2 && (p->mLaunchStartY >= p->mPos.y || (p->mUnk_44 & KART_44_ON_GROUND))) {
            if (p->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) {
                SetCameraHeightHold(0);
            }
            if (p->mRotationEndFrames != 0) {
                return;
            }
            p->mUnk_4d0 = 0x46;
            c = p->mRotationEndFrames;
            p->mUnk_48 |= 0x44000;
            p->mUnk_23a = c;
            p->mUnk_4c |= 0x80000000;
            return;
        }
        p->mLaunchFrames = p->mLaunchFrames + 1;
        return;
    }
    p->mRotationEndFrames++;
    if (p->mRotationEndFrames < 0x1e) {
        return;
    }
    p->mState = KART_STATE_NORMAL;
    p->mUnk_4c &= ~0x30;
    p->mUnk_48 &= ~0x20000;
    func_02068a64(p, 0, 1);
    p->mUnk_44 |= 0x80000000;
    if ((p->mUnk_7c & 0x2) && gRaceSetup->mMode == MODE_BATTLE && gRaceSetup->mBattleKind == BATTLE_KIND_BALLOON) {
        PickKartAiBalloonCountGoal(p->mAi);
    }
    p->mUnk_4c &= ~0x80000010;
    if (p->mUnk_44 & KART_44_ON_GROUND) {
        p->mTurnAngle = 0;
    }
}

BOOL TryStartKartState3(Kart *p) {
    BOOL v1;
    BOOL v2;
    BOOL c;
    int v;
    u32 f = p->mUnk_4c;

    if (f & 0x400000) {
        v1 = FALSE;
    } else if (p->mUnk_7c & 0x200) {
        if (p->mState == KART_STATE_NORMAL && !(p->mUnk_48 & 0x1800) && !(f & 0x10000040)) {
            v1 = TRUE;
        } else {
            v1 = FALSE;
        }
    } else {
        v2 = TRUE;
        if (!(f & 0x10000040) && !(p->mUnk_48 & 0x1800)) {
            v = p->mState;
            c = FALSE;
            if (v != KART_STATE_NORMAL && v != KART_STATE_1 && v != KART_STATE_SPIN) {
                c = TRUE;
            }
            if (c == FALSE) {
                v2 = FALSE;
            }
        }
        v1 = v2 == FALSE;
    }
    if (!v1) {
        return FALSE;
    }
    StartKartState3(p);
    if (p->mUnk_7c & 0x200) {
        p->mUnk_514->mUnk_2c ^= 0x10;
    }
    return TRUE;
}

void StartKartState3(Kart *p) {
    Vec3 v;

    StartKartState(p, KART_STATE_FLIP);
    p->mUnk_4c |= 0x10;
    p->mRotationAngle = 0;
    p->mRotationAnglePerFrame = 0x666;
    p->mUnk_370 = 0;
    p->mRotationEndFrames = 0;
    p->mRotationAngleSum = 0;
    p->mForwardSpeed = p->mForwardSpeed + 0x800;
    GetKartMatrixRow0(p, &p->mRotationAxis);
    GetKartForward(p, &v);
    VEC_MultAdd(0x2e2, &v, &p->mRotationAxis, &p->mRotationAxis);
    Vec3NormalizeAndGetLengthUnchecked(&p->mRotationAxis, &p->mRotationAxis);
    QuaternionFromAxisAngle(&p->mRotationAxis, p->mRotationAngle, &p->mRotationQuaternion);
    p->mForwardSpeed = ((s64) p->mForwardSpeed * 0x99a) >> 12;
    if (p->mKartModelsEntry->mUnk_058 == 0) {
        StartEffect(0xc, &p->mPos);
        StartEffect(0xd, &p->mPos);
        StartEffect(0xe, &p->mPos);
    }
    if (!(p->mUnk_48 & 0x840)) {
        func_0210af40(p, p->mSoundIndex, 2);
    }
    func_020efea4(&(gKartItems)[p->mIndex]);
    if (gRaceSetup->mMode == MODE_MISSION_RUN && gRaceSetup->mMode == MODE_MISSION_RUN) {
        func_ov001_0218173c();
    }
}

void AdvanceKartState3(Kart *p) {
    s16 n;

    if (p->mRotationAngleSum == 0) {
        p->mVerticalSpeed = data_usa_021654e8;
    } else if (p->mUnk_44 & 0x10000) {
        switch (p->mUnk_370) {
            case 0:
                p->mVerticalSpeed = data_usa_021654f0;
                break;
            case 1:
                p->mVerticalSpeed = data_usa_02165508;
                break;
        }
        p->mUnk_370++;
    }
    if ((p->mRotationAngleSum > 0 ? p->mRotationAngleSum : -p->mRotationAngleSum) <= 0xffff) {
        p->mRotationAngleSum = p->mRotationAngleSum + p->mRotationAnglePerFrame;
        if ((p->mRotationAngleSum > 0 ? p->mRotationAngleSum : -p->mRotationAngleSum) > 0xffff) {
            p->mRotationAngle = 0;
        } else {
            p->mRotationAngle = p->mRotationAngle + p->mRotationAnglePerFrame;
        }
        p->mRotationAnglePerFrame = p->mRotationAnglePerFrame - 0xa;
        QuaternionFromAxisAngle(&p->mRotationAxis, p->mRotationAngle, &p->mRotationQuaternion);
        QuaternionNormalize(&p->mRotationQuaternion, &p->mRotationQuaternion);
        return;
    }
    n = p->mRotationEndFrames;
    if (n == 0) {
        p->mUnk_48 |= 0x44000;
        p->mUnk_23a = n;
        p->mUnk_4c &= ~0x10;
    }
    p->mRotationEndFrames++;
    if (p->mRotationEndFrames < data_usa_021654c4) {
        return;
    }
    p->mState = KART_STATE_NORMAL;
    p->mUnk_4c &= ~0x30;
    p->mUnk_48 &= ~0x20000;
    func_02068a64(p, 0, 1);
    p->mUnk_44 |= 0x80000000;
    if ((p->mUnk_7c & 0x2) && gRaceSetup->mMode == MODE_BATTLE && gRaceSetup->mBattleKind == BATTLE_KIND_BALLOON) {
        PickKartAiBalloonCountGoal(p->mAi);
    }
}

BOOL TryStartKartState4(Kart *p, Unk0206b020 *a) {
    Vec3 t;
    Vec3 u;
    Vec3 w;
    BOOL v1;
    BOOL v2;
    BOOL c;
    int v;
    u32 f = p->mUnk_4c;

    if (f & 0x400000) {
        v1 = FALSE;
    } else if (p->mUnk_7c & 0x200) {
        if (p->mState == KART_STATE_NORMAL && !(p->mUnk_48 & 0x1800) && !(f & 0x10000040)) {
            v1 = TRUE;
        } else {
            v1 = FALSE;
        }
    } else {
        v2 = TRUE;
        if (!(f & 0x10000040) && !(p->mUnk_48 & 0x1800)) {
            v = p->mState;
            c = FALSE;
            if (v != KART_STATE_NORMAL && v != KART_STATE_1 && v != KART_STATE_SPIN) {
                c = TRUE;
            }
            if (c == FALSE) {
                v2 = FALSE;
            }
        }
        v1 = v2 == FALSE;
    }
    if (!v1) {
        return FALSE;
    }
    t = a->mUnk_28;
    VEC_Subtract(&p->mPos, &a->mUnk_04, &u);
    VEC_CrossProduct(&a->mUnk_40, &u, &w);
    if (VEC_DotProduct(&w, &a->mUnk_34) < 0) {
        t.x = -t.x;
        t.y = -t.y;
        t.z = -t.z;
    }
    StartKartState4(p, &t, 0);
    return TRUE;
}

void StartKartState4(Kart *p, const Vec3 *a, s32 b) {
    Vec3 v;
    s32 r;
    s32 x;
    s32 y;
    s32 z;

    StartKartState(p, KART_STATE_PUSH_FLIP);
    p->mUnk_4c |= 0x10;
    p->mRotationAngle = 0;
    p->mRotationAngleSum = 0;
    p->mRotationAnglePerFrame = data_usa_021654d4;
    p->mUnk_370 = 0;
    p->mRotationEndFrames = 0;
    v = data_02154f7c;
    Vec3CrossUnrounded(&v, a, &p->mRotationAxis);
    func_020eff40(&(gKartItems)[p->mIndex]);
    if (gRaceSetup->mMode == MODE_MISSION_RUN && gRaceSetup->mMode == MODE_MISSION_RUN) {
        func_ov001_0218173c();
    }
    if (!(p->mUnk_7c & 0x400)) {
        x = ((s64) a->x * 0x1b33) >> 12;
        y = ((s64) a->y * 0x1b33) >> 12;
        z = ((s64) a->z * 0x1b33) >> 12;
        p->mHitVelocity.x += x;
        p->mHitVelocity.z += z;
        p->mVerticalSpeed += y;
        r = Vec3DotUnrounded(&p->mTurnedForward, a);
        if (r <= 0) {
            p->mForwardSpeed = 0;
        } else {
            p->mForwardSpeed = (s32) (((s64) p->mForwardSpeed * r) >> 12) >> 2;
        }
    }
    QuaternionFromAxisAngle(&p->mRotationAxis, p->mRotationAngle, &p->mRotationQuaternion);
    if (p->mKartModelsEntry->mUnk_058 == 0) {
        StartEffect(0xc, &p->mPos);
        StartEffect(0xd, &p->mPos);
        StartEffect(0xe, &p->mPos);
    }
    p->mUnk_4c |= 0x1;
    if (!(p->mUnk_48 & 0x840)) {
        func_0210af40(p, p->mSoundIndex, 2);
    }
    if (b == 0) {
        return;
    }
    if (p->mUnk_7c & 0x200) {
        p->mUnk_514->mUnk_2c ^= 0x20;
    }
    if (p->mUnk_7c & 0x200) {
        p->mUnk_514->mPushDirection = *a;
        p->mUnk_514->mUnk_a4 = 4;
    }
}

void AdvanceKartState4(Kart *p) {
    s16 n;

    if (p->mRotationAngleSum == 0) {
        p->mVerticalSpeed = data_usa_0216550c;
    }
    if ((p->mRotationAngleSum > 0 ? p->mRotationAngleSum : -p->mRotationAngleSum) <= 0xffff) {
        p->mRotationAngleSum = p->mRotationAngleSum + p->mRotationAnglePerFrame;
        if ((p->mRotationAngleSum > 0 ? p->mRotationAngleSum : -p->mRotationAngleSum) > 0xffff) {
            p->mRotationAngle = 0;
            p->mUnk_4c &= ~0x1;
        } else {
            p->mRotationAngle = p->mRotationAngle + p->mRotationAnglePerFrame;
        }
        p->mRotationAnglePerFrame =
            p->mRotationAnglePerFrame - (p->mRotationAnglePerFrame > 0 ? data_usa_021654d0 : -data_usa_021654d0);
        QuaternionFromAxisAngle(&p->mRotationAxis, p->mRotationAngle, &p->mRotationQuaternion);
        QuaternionNormalize(&p->mRotationQuaternion, &p->mRotationQuaternion);
        return;
    }
    n = p->mRotationEndFrames;
    if (n == 0) {
        p->mUnk_48 |= 0x44000;
        p->mUnk_23a = n;
        p->mUnk_4c &= ~0x10;
    }
    p->mRotationEndFrames++;
    if (p->mRotationEndFrames < 0x1e) {
        return;
    }
    p->mState = KART_STATE_NORMAL;
    p->mUnk_4c &= ~0x30;
    p->mUnk_48 &= ~0x20000;
    func_02068a64(p, 0, 1);
    p->mUnk_44 |= 0x80000000;
    if ((p->mUnk_7c & 0x2) && gRaceSetup->mMode == MODE_BATTLE && gRaceSetup->mBattleKind == BATTLE_KIND_BALLOON) {
        PickKartAiBalloonCountGoal(p->mAi);
    }
    if (p->mUnk_44 & KART_44_ON_GROUND) {
        p->mTurnAngle = 0;
    }
}

s32 StartKartState5(Kart *p, const Vec3 *a, s32 b) {
    Vec3 v;
    Vec3 w;
    s32 r;
    s32 x;
    s32 y;
    s32 z;

    StartKartState(p, KART_STATE_PUSH_DOUBLE_FLIP);
    v = *a;
    v.y = 0;
    if ((s64) v.x * v.x + (s64) v.y * v.y + (s64) v.z * v.z >= 16) {
        r = Vec3NormalizeAndGetLengthUnchecked(&v, &v);
    } else {
        r = 0;
    }
    if (r == 0) {
        v = data_02154f88;
    }
    p->mUnk_4c |= 0x10;
    p->mRotationAngle = 0;
    p->mRotationAngleSum = 0;
    p->mRotationAnglePerFrame = data_usa_021654e0;
    p->mUnk_370 = 0;
    p->mRotationEndFrames = 0;
    w = data_02154f7c;
    Vec3CrossUnrounded(&w, &v, &p->mRotationAxis);
    if (!(p->mUnk_7c & 0x400)) {
        x = ((s64) v.x << 14) >> 12;
        y = ((s64) v.y << 14) >> 12;
        z = ((s64) v.z << 14) >> 12;
        p->mHitVelocity.x += x;
        p->mHitVelocity.z += z;
        p->mVerticalSpeed += y;
        r = Vec3DotUnrounded(&p->mTurnedForward, &v);
        if (r <= 0) {
            p->mForwardSpeed = 0;
        } else {
            p->mForwardSpeed = (s32) (((s64) p->mForwardSpeed * r) >> 12) >> 2;
        }
    }
    QuaternionFromAxisAngle(&p->mRotationAxis, p->mRotationAngle, &p->mRotationQuaternion);
    func_020eff40(&(gKartItems)[p->mIndex]);
    if (gRaceSetup->mMode == MODE_MISSION_RUN && gRaceSetup->mMode == MODE_MISSION_RUN) {
        func_ov001_0218173c();
    }
    if (p->mKartModelsEntry->mUnk_058 == 0) {
        StartEffect(0xc, &p->mPos);
        StartEffect(0xd, &p->mPos);
        StartEffect(0xe, &p->mPos);
    }
    if (!(p->mUnk_48 & 0x840)) {
        func_0210af40(p, p->mSoundIndex, 2);
    }
    p->mUnk_4c |= 0x1;
    if (b != 0) {
        if (p->mUnk_7c & 0x200) {
            p->mUnk_514->mUnk_2c ^= 0x40;
        }
        if (p->mUnk_7c & 0x200) {
            p->mUnk_514->mPushDirection = *a;
            p->mUnk_514->mUnk_a4 = 5;
        }
    }
    return 1;
}

void AdvanceKartState5(Kart *p) {
    s16 n;

    if (p->mRotationAngleSum == 0) {
        p->mVerticalSpeed = data_usa_0216550c;
    } else if (p->mUnk_44 & 0x10000) {
        if (p->mUnk_370 == 0) {
            p->mVerticalSpeed = data_usa_021654e4;
        }
        p->mUnk_370++;
    }
    if ((p->mRotationAngleSum > 0 ? p->mRotationAngleSum : -p->mRotationAngleSum) <= 0x1fffe) {
        p->mRotationAngleSum = p->mRotationAngleSum + p->mRotationAnglePerFrame;
        if ((p->mRotationAngleSum > 0 ? p->mRotationAngleSum : -p->mRotationAngleSum) > 0x1fffe) {
            p->mRotationAngle = 0;
            p->mUnk_4c &= ~0x1;
        } else {
            p->mRotationAngle = p->mRotationAngle + p->mRotationAnglePerFrame;
        }
        p->mRotationAnglePerFrame =
            p->mRotationAnglePerFrame - (p->mRotationAnglePerFrame > 0 ? data_usa_021654d0 : -data_usa_021654d0);
        QuaternionFromAxisAngle(&p->mRotationAxis, p->mRotationAngle, &p->mRotationQuaternion);
        QuaternionNormalize(&p->mRotationQuaternion, &p->mRotationQuaternion);
        return;
    }
    n = p->mRotationEndFrames;
    if (n == 0) {
        p->mUnk_48 |= 0x44000;
        p->mUnk_23a = n;
        p->mUnk_4c &= ~0x10;
    }
    p->mRotationEndFrames++;
    if (p->mRotationEndFrames < 10) {
        return;
    }
    p->mState = KART_STATE_NORMAL;
    p->mUnk_4c &= ~0x30;
    p->mUnk_48 &= ~0x20000;
    func_02068a64(p, 0, 1);
    p->mUnk_44 |= 0x80000000;
    if ((p->mUnk_7c & 0x2) && gRaceSetup->mMode == MODE_BATTLE && gRaceSetup->mBattleKind == BATTLE_KIND_BALLOON) {
        PickKartAiBalloonCountGoal(p->mAi);
    }
    if (p->mUnk_44 & KART_44_ON_GROUND) {
        p->mTurnAngle = 0;
    }
}

void StartKartThunderShrink(Kart *p) {
    KartItemEffectState *q = &p->mUnk_538;

    if (p->mUnk_4c & 0x10000040) {
        return;
    }
    if (p->mUnk_7c & 0x402000) {
        return;
    }
    if (p->mUnk_48 & 0x10040) {
        return;
    }
    q->mUnk_02 = data_usa_02154a54[GetKartRank(p->mIndex) - 1];
    q->mUnk_04 = 0;
    p->mUnk_394 = 0xb33;
    p->mUnk_4c |= KART_4C_THUNDER_SHRINK;
    TrySpinKart(p, 2, 1);
    func_0210f9ac(p);
    func_020eff40(&(gKartItems)[p->mIndex]);
    if (gRaceSetup->mMode == MODE_MISSION_RUN && gRaceSetup->mMode == MODE_MISSION_RUN) {
        func_ov001_0218173c();
    }
    p->mScaleFactor.x = 0x1000;
    p->mScaleFactor.y = 0x1000;
    p->mScaleFactor.z = 0x1000;
    func_0210a644(p);
    if (p->mIndex == gRaceSetup->mEntryIndex) {
        func_0210fa74(1);
    }
    if (p->mUnk_7c & 0x200) {
        p->mUnk_514->mUnk_2c ^= 0x8000;
    }
}

void AdvanceKartThunderShrink(Kart *p) {
    KartItemEffectState *q = &p->mUnk_538;

    if (q->mUnk_02 <= 0) {
        if (q->mUnk_04 == 0) {
            StartSound(&p->mSoundSource, 0xed, 0x7f, 0);
        }
        q->mUnk_04 = q->mUnk_04 + 1;
        if (q->mUnk_04 >= 0x19) {
            p->mScaleBase.x = 0x1000;
            p->mScaleBase.y = 0x1000;
            p->mScaleBase.z = 0x1000;
            p->mScaleFactor.x = 0x1000;
            p->mScaleFactor.y = 0x1000;
            p->mScaleFactor.z = 0x1000;
            p->mScale.x = ((s64) p->mScaleBase.x * p->mScaleFactor.x) >> 12;
            p->mScale.y = ((s64) p->mScaleBase.y * p->mScaleFactor.y) >> 12;
            p->mScale.z = ((s64) p->mScaleBase.z * p->mScaleFactor.z) >> 12;
            p->mScale.y = ((s64) p->mScaleYFactor * p->mScale.y) >> 12;
            if (q->mUnk_04 > 0x19) {
                p->mUnk_4c &= ~KART_4C_THUNDER_SHRINK;
                if (!(p->mUnk_4c & 0x10080)) {
                    p->mUnk_394 = 0x1000;
                }
                if (p->mIndex == gRaceSetup->mEntryIndex) {
                    func_0210fa74(0);
                }
                func_0210a664(p);
                return;
            }
            p->mUnk_4c |= 0x100;
            return;
        }
        p->mUnk_4c |= 0x100;
        p->mScaleFactor.x = gKartScaleFactorXTable[q->mUnk_04];
        p->mScaleFactor.y = gKartScaleFactorYTable[q->mUnk_04];
        p->mScaleFactor.z = gKartScaleFactorZTable[q->mUnk_04];
        p->mScaleBase.x = 0x1000;
        p->mScaleBase.y = 0x1000;
        p->mScaleBase.z = 0x1000;
        p->mScale.x = ((s64) p->mScaleBase.x * p->mScaleFactor.x) >> 12;
        p->mScale.y = ((s64) p->mScaleBase.y * p->mScaleFactor.y) >> 12;
        p->mScale.z = ((s64) p->mScaleBase.z * p->mScaleFactor.z) >> 12;
        p->mScale.y = ((s64) p->mScaleYFactor * p->mScale.y) >> 12;
        return;
    }
    q->mUnk_02 = q->mUnk_02 - 1;
    if (p->mScaleBase.y > 0x800) {
        s32 v = p->mScaleBase.y;

        if (v < 0x800) {
            v += 0x29;
            if (v > 0x800) {
                v = 0x800;
            }
        } else {
            v -= 0x29;
            if (v <= 0x800) {
                v = 0x800;
            }
        }
        p->mScaleBase.y = v;
        p->mScaleBase.z = p->mScaleBase.y;
        p->mScaleBase.x = p->mScaleBase.z;
        p->mScale.x = ((s64) p->mScaleBase.x * p->mScaleFactor.x) >> 12;
        p->mScale.y = ((s64) p->mScaleBase.y * p->mScaleFactor.y) >> 12;
        p->mScale.z = ((s64) p->mScaleBase.z * p->mScaleFactor.z) >> 12;
        p->mScale.y = ((s64) p->mScaleYFactor * p->mScale.y) >> 12;
    }
    func_0210fa3c();
}
