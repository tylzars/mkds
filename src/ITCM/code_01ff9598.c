#include "ITCM/code_01ff9598.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "ITCM/code_01ffad14.h"
#include "ITCM/code_01ffba68.h"
#include "ITCM/code_01ffc000.h"
#include "ITCM/code_01ffcf7c.h"
#include "ITCM/code_01ffd000.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_0206d000.h"
#include "Main/Unknown/code_0208c534.h"
#include "Main/Unknown/code_02081618.h"
#include "Main/Unknown/code_02040de0.h"
#include "Main/Unknown/code_02061654.h"
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
#include "Main/Unknown/code_02108ea0.h"
#include "Main/Unknown/code_020d50ec.h"
#include "Main/Unknown/code_020e01f0.h"
#include "Main/Unknown/code_0210dc7c.h"
#include "Main/Unknown/unk_02154000.h"
#include "Main/Unknown/unk_02170000.h"
#include "Main/Unknown/unk_02171000.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/code_020f36d8.h"
#include "code_02147cd8.h"
#include "code_0212bcac.h"
#include "code_0212df7c.h"
#include "Main/Unknown/code_0206d020.h"
#include "Main/Unknown/code_0206f04c.h"

#pragma opt_arithtransformation off

BOOL func_01ffa478(Kart *p, u32 a, Vec3 *b) {
    BOOL t = FALSE;

    if (a & 0x2000000) {
        if ((s64) b->x * b->x + (s64) b->z * b->z > 0x1000000) {
            t = TRUE;
        }
    }
    return t != FALSE;
}

BOOL func_01ffa41c(Kart *p, u32 a, Vec3 *b) {
    BOOL r = TRUE;
    BOOL t = FALSE;

    if (a & 0x2000000) {
        if ((s64) b->x * b->x + (s64) b->z * b->z > 0x1000000) {
            t = TRUE;
        }
    }
    if (t == FALSE) {
        if (!(p->mUnk_44 & 0x4000000)) {
            r = FALSE;
        }
    }
    return r != FALSE;
}

BOOL func_01ffa380(Kart *p, u32 a, Vec3 *b) {
    BOOL r = TRUE;
    BOOL t = FALSE;

    if (a & 0x2000000) {
        if ((s64) b->x * b->x + (s64) b->z * b->z > 0x1000000) {
            t = TRUE;
        }
    }
    if (t == FALSE) {
        if (b->y <= (s32) (((s64) p->mRadius * -0xb33 + 0x800) >> 12)) {
            r = FALSE;
        }
    }
    return r != FALSE;
}

void func_01ffa350(Kart *p, u32 a) {
    p->mUnk_44 = p->mUnk_44 & ~a;
    p->mUnk_208->mUnk_00 = FALSE;
    p->mSurfaceGroup = -1;
    StopKartCurrentEffects(p);
}

BOOL func_01ffa1f8(Kart *p) {
    void *q;
    u32 i;
    u32 r;

    if (p->mPos.y < 0) {
        if (!(p->mUnk_7c & 0x400) && !(p->mUnk_48 & 0x800)) {
            p->mUnk_48 = p->mUnk_48 | 0x800;
            i = p->mIndex;
            if (gRaceSetup->mMode == MODE_BATTLE) {
                r = GetCourseMapRespawnSlot(0);
            } else {
                r = GetCourseMapRespawnSlot(gRaceProgress->mUnk_000[i].mCheckpoint);
            }
            p->mRespawnSlot = r;
            if (p->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) {
                if (gRaceSetup->mCourseId == COURSE_ID_RAINBOW && (data_0217c780 & 1)) {
                    q = func_0210e128(func_02108ea0(0));
                    if (data_0217d084.mUnk_0c != 0) {
                        if (*(u32 *) q != 0) {
                            NNS_SndPlayerStopSeq(q, 0);
                        }
                        if (*(u32 *) q != 0) {
                            NNS_SndPlayerStopSeq(q, 0);
                        }
                        NNS_SndArcPlayerStartSeqArc(q, 0, 0x1b7);
                    }
                }
            }
        }
        return TRUE;
    }
    p->mUnk_44 = p->mUnk_44 & 0xbbceffff;
    p->mUnk_48 = p->mUnk_48 & 0xff9ffbfe;
    return FALSE;
}

void AdvanceKartQuaternionBlendFactor(Kart *p, const Vec3 *a) {
    s32 d = Vec3DotUnrounded(&p->mUnk_244, a);
    s32 m;

    if (p->mUnk_48 & 1) {
        m = 0x4cd;
    } else {
        m = 0x1ec;
    }
    if (d < 0) {
        d = 0;
    }
    if (d >= 0xe66) {
        if (p->mUnk_44 & 0x1000) {
            if (p->mUnk_208->mUnk_00 == FALSE && p->mUnk_1fc.x == 0 && p->mUnk_1fc.y == 0 && p->mUnk_1fc.z == 0 &&
                p->mUnk_4d0 > 100) {
                p->mQuaternionBlendFactor = 0;
                return;
            }
        }
        if (p->mQuaternionBlendFactor >= m) {
            return;
        }
        p->mQuaternionBlendFactor = p->mQuaternionBlendFactor + 0x14;
        if (p->mQuaternionBlendFactor > m) {
            p->mQuaternionBlendFactor = m;
        }
    } else {
        p->mQuaternionBlendFactor = (s64) m * p->mVelocityLengthRatio >> 12;
    }
}

// Counts mAirborneFrames, also clears mUnk_234, sets or clears bit 0x4000 and stores mLastGroundY. Not run while the
// kart is below y = 0.
void UpdateKartAirborne(Kart *p) {
    if (p->mUnk_44 & KART_44_ON_GROUND) {
        p->mAirborneFrames = 0;
        p->mUnk_234 = 0;
        p->mUnk_44 = p->mUnk_44 & ~0x4000;
        p->mLastGroundY = p->mPos.y;
        return;
    }
    p->mAirborneFrames = p->mAirborneFrames + 1;
    if (p->mAirborneFrames > 5) {
        p->mUnk_44 = p->mUnk_44 | 0x4000;
    }
}

void AdvanceKartOrientation(Kart *p, Vec3 *a) {
    Vec4 v;
    u32 t;

    p->mUnk_3f8 = 0x1000;
    if (p->mAirborneFrames > 5) {
        p->mQuaternionBlendFactor = 0xf6;
        func_02070484(p, &p->mUnk_100_q);
    } else {
        func_01ffad14(p, a);
    }
    QuaternionBlend(&p->mUnk_f0_q, &p->mUnk_100_q, &p->mUnk_f0_q, p->mQuaternionBlendFactor);
    QuaternionFromAxisAngle(&data_02154f7c, (u16) (p->mHeadingAngle + p->mHeadingAngleOffset), &p->mUnk_e0_m);
    QuaternionMultiply(&p->mUnk_f0_q, &p->mUnk_e0_m, &p->mUnk_110_q);
    if (p->mUnk_44 & 2) {
        if (p->mHopSpeed > 0) {
            p->mHopTiltAngle = 0x9c4 - (u16) ((s64) p->mHopHeight * 500 >> 12);
            if (p->mHopTiltAngle > 0x6a4) {
                p->mHopTiltAngle = 0x352;
            }
        } else {
            p->mHopTiltAngle = 0;
        }
        QuaternionFromAxisAngle(&data_02154f88, (u16) -p->mHopTiltAngle, &v);
        QuaternionMultiply(&p->mUnk_110_q, &v, &p->mUnk_110_q);
    } else {
        p->mHopTiltAngle = 0;
    }
    QuaternionNormalize(&p->mUnk_110_q, &p->mUnk_110_q);
}

// Runs only on a step with a ground hit (non-zero normal).
void RefreshKartSurface(Kart *p) {
    s32 r = func_020d59f8(0x1e34ef);
    s32 k;
    s32 a;
    s32 b;
    s32 c;

    p->mSurfaceKind = (r & 0x1f00) >> 8;
    p->mSurfaceVariant = (u32) ((r & 0xe0) << 11) >> 16;
    a = 0x1000;
    k = gKartSurfaceFunctions[p->mSurfaceKind](p);
    if (k != 0) {
        a = p->mPhysicalParam->mSurfaceSpeedLimitFactors[k];
    }
    b = p->mSpeedLimitFactor;
    if (a >= b) {
        p->mSpeedLimitFactor = a;
    } else {
        p->mSpeedLimitFactor = b + (s32) (((s64) (a - b) * 0x4cd + 0x800) >> 12);
    }
    if (p->mUnk_4c & 0x10000040) {
        c = 0;
    } else {
        c = k;
    }
    p->mUnk_240 = p->mPhysicalParam->mUnk_38[c];
    if (p->mUnk_48 & 0x40000000) {
        if (p->mUnk_44 & KART_44_ON_GROUND) {
            if (k != 0xb) {
                p->mUnk_48 = p->mUnk_48 & ~0x40000000;
            }
        }
    }
    p->mSurfaceGroup = k;
}

void func_01ff9d18(Kart *p) {
    u32 r;
    s32 d;
    enum { K0 } j;

    if (p->mUnk_48 & KART_48_MINI_TURBO) {
        p->mMiniTurboTimer = p->mMiniTurboTimer - 1;
        if (p->mMiniTurboTimer <= 0) {
            p->mUnk_48 = p->mUnk_48 & ~KART_48_MINI_TURBO;
            p->mMiniTurboTimer = 0;
        }
    }
    if (p->mUnk_48 & 0x100000) {
        p->mUnk_538.mUnk_00 = p->mUnk_538.mUnk_00 - 1;
        if (p->mUnk_538.mUnk_00 <= 0) {
            p->mUnk_48 = p->mUnk_48 & ~0x20100000;
            p->mUnk_538.mUnk_00 = 0;
        }
    }
    if (!(p->mUnk_44 & 0x1000000) && !(p->mUnk_7c & 0x400)) {
        func_0206f914(p);
    }
    if (!(p->mUnk_4c & 0x400)) {
        return;
    }
    r = GetRaceUpdateFrames();
    if (p->mUnk_410 == 0) {
        j = p->mEntryIndex;
        if ((u16) (data_02175628[j].mUnk_00 & 1) != 0) {
            p->mUnk_410 = r;
        }
    }
    if (p->mUnk_40c == 0) {
        return;
    }
    if (p->mUnk_410 == 0) {
        return;
    }
    d = p->mUnk_410 - p->mUnk_40c;
    if (d <= 0) {
        d = -d;
    }
    if (d <= 2) {
        StartKartBoost(p, KART_BOOST_RESPAWN, 10);
    }
    p->mUnk_4c = p->mUnk_4c & ~0x400;
}

void func_01ff9cb0(Kart *p) {
    if (!(p->mUnk_4c & 2)) {
        if (IsRaceStarted() == 1) {
            func_01ffc9e8(p, 0);
        }
    }
    p->mUnk_44 = p->mUnk_44 & ~0x1000;
    if (p->mUnk_208->mUnk_00 == FALSE) {
        return;
    }
    func_020e0538((Unk020e04b0 *) p->mUnk_208, &p->mPos);
    p->mUnk_208->mUnk_00 = FALSE;
}

void func_01ff9c9c(Kart *p, u32 a) {
    u32 b = a & 0x1000000;

    if (b != p->mUnk_4c0) {
        p->mUnk_4c0 = b;
    }
}

void AdvanceKartHop(Kart *p) {
    if (!(p->mUnk_44 & 4)) {
        return;
    }
    p->mHopSpeed = p->mHopSpeed + p->mGravity;
    p->mHopHeight = p->mHopHeight + p->mHopSpeed;
    if (p->mHopHeight < 0) {
        p->mHopHeight = 0;
        p->mHopSpeed = 0;
        p->mUnk_44 = p->mUnk_44 & ~0x804;
    }
}

void AdvanceKartEffects(Kart *p) {
    KartTurnEffects *a;
    KartEffects *b;
    u32 f;

    if (p->mUnk_4c & 0x8000) {
        a = GetKartTurnEffects(p->mIndex);
        b = GetKartEffects(p->mIndex);
        AdvanceKartLevel4Effects(a, p);
        AdvanceKartTurnStartEffects(a, p);
        AdvanceKartLevel3Effects(a, b->mSideDirections, b->mSidePositions);
        AdvanceKartLevel2Effects(a, b->mSideDirections, b->mSidePositions);
    } else {
        StopKartTurnEffects(GetKartTurnEffects(p->mIndex));
    }
    p->mEffectVelocity = p->mVelocity;
    f = p->mUnk_44;
    if (f & KART_44_ON_GROUND) {
        if (!(f & 0x1000)) {
            p->mEffectVelocity.y = p->mEffectVelocity.y - p->mVerticalSpeed;
        }
    }
    p->mEffectVelocity.x = p->mEffectVelocity.x >> 4;
    p->mEffectVelocity.y = p->mEffectVelocity.y >> 4;
    p->mEffectVelocity.z = p->mEffectVelocity.z >> 4;
}

void func_01ff9a94(Unk01ff9940 *a) {
    BOOL r;
    u32 w = a->mUnk_00;

    r = FALSE;
    if ((w & 4) == 0) {
        r = TRUE;
    }
    if ((w & 0x20) && !(w & 8)) {
        if (r) {
            func_01ff9048(0x1c, &a->mUnk_4c, 3);
            r = FALSE;
        }
        func_01ff9048(0x1b, &a->mUnk_10, 3);
    }
    if (!(a->mUnk_00 & 2)) {
        if (r) {
            func_01ff9048(0x19, &a->mUnk_28, 0xc);
        } else {
            func_01ff9048(0x1a, &a->mUnk_28, 9);
        }
    } else if (r) {
        func_01ff9048(0x1c, &a->mUnk_4c, 3);
    }
    if (!(a->mUnk_00 & 1)) {
        func_01ff9048(0x1b, &a->mUnk_04, 3);
    }
}

void func_01ff9940(Unk01ff9940 *a, Unk01ff9940_B *b, Unk01ff9940_C *c, u32 d) {
    u8 t = c->mUnk_03;
    u32 i;

    if (d & 4) {
        a->mUnk_00 |= 1;
        if (t & 2) {
            i = c->mUnk_01;
            data_02170500->mUnk_c4[i >> 5] |= 1 << (i & 0x1f);
        }
    } else {
        a->mUnk_04.x = b->mUnk_00.x;
        a->mUnk_04.y = b->mUnk_00.y;
        a->mUnk_04.z = b->mUnk_00.z;
        if (t & 2) {
            i = c->mUnk_01;
            data_02170500->mUnk_c4[i >> 5] &= ~(1 << (i & 0x1f));
            data_usa_021712f0[i].mUnk_00.x = b->mUnk_0c.x;
            data_usa_021712f0[i].mUnk_00.y = b->mUnk_0c.y;
            data_usa_021712f0[i].mUnk_00.z = b->mUnk_0c.z;
        }
    }
    if (t & 1) {
        i = c->mUnk_02;
        a->mUnk_00 |= 0x20;
        if (data_02170500->mUnk_c4[i >> 5] & (1 << (i & 0x1f))) {
            a->mUnk_00 |= 8;
        } else {
            a->mUnk_10 = data_usa_021712f0[i].mUnk_00;
        }
    }
    a->mUnk_00 |= 0x10;
}

void func_01ff9828(Unk01ff9598_A *a, Unk01ff9598 *b) {
    s32 w = b->mUnk_2c << 12;
    s32 h = b->mUnk_2e << 12;
    s32 k22;
    s32 k18;
    s32 k20;
    s32 v1;
    s32 c;
    s32 d;
    s32 e;
    s32 f;

    FX_DivAsync(h, w);
    k22 = b->mUnk_22;
    k18 = b->mUnk_18;
    k20 = b->mUnk_20;
    v1 = b->mUnk_1c;
    d = (s64) k18 * k20 >> 12;
    c = (s64) k18 * k22 >> 12;
    e = (s64) v1 * k20 >> 12;
    f = (s64) v1 * k22 >> 12;
    a->mUnk_00 = c;
    a->mUnk_14 = f;
    a->mUnk_04 = -e * FX_GetDivResult() >> 12;
    FX_DivAsync(w, h);
    a->mUnk_30 = (b->mUnk_2c * (b->mUnk_18 - (d + c)) << 3) - b->mUnk_2c * (s32) ((s64) b->mUnk_18 * b->mUnk_24 >> 8);
    a->mUnk_34 =
        b->mUnk_2e * (s32) ((s64) b->mUnk_1c * b->mUnk_28 >> 8) + (b->mUnk_2e * (e - f - b->mUnk_1c + 0x2000) << 3);
    a->mUnk_10 = d * FX_GetDivResult() >> 12;
}

void func_01ff974c(Unk01ff9598_A *a, Unk01ff9598 *b) {
    s32 w = b->mUnk_2c << 12;
    s32 h = b->mUnk_2e << 12;
    s32 t;

    FX_DivAsync(h, w);
    a->mUnk_00 = b->mUnk_22;
    a->mUnk_14 = b->mUnk_22;
    a->mUnk_04 = -b->mUnk_20 * FX_GetDivResult() >> 12;
    FX_DivAsync(w, h);
    t = b->mUnk_20 + b->mUnk_22;
    a->mUnk_30 = (b->mUnk_2c * (-t + 0x1000) << 3) - (b->mUnk_24 * b->mUnk_2c << 4);
    a->mUnk_34 = (b->mUnk_2e * (b->mUnk_20 - b->mUnk_22 + 0x1000) << 3) + (b->mUnk_28 * b->mUnk_2e << 4);
    a->mUnk_10 = b->mUnk_20 * FX_GetDivResult() >> 12;
}

void func_01ff96cc(Unk01ff9598_A *a, Unk01ff9598 *b) {
    a->mUnk_00 = b->mUnk_18;
    a->mUnk_14 = b->mUnk_1c;
    a->mUnk_04 = 0;
    a->mUnk_30 = b->mUnk_2c * -(s32) ((s64) b->mUnk_18 * b->mUnk_24 >> 8);
    a->mUnk_34 =
        b->mUnk_2e * (s32) ((s64) b->mUnk_1c * b->mUnk_28 >> 8) + (b->mUnk_2e * (b->mUnk_1c * -2 + 0x2000) << 3);
    a->mUnk_10 = 0;
}

void func_01ff9684(Unk01ff9598_A *a, Unk01ff9598 *b) {
    a->mUnk_00 = 0x1000;
    a->mUnk_14 = 0x1000;
    a->mUnk_04 = 0;
    a->mUnk_30 = -(b->mUnk_24 * b->mUnk_2c) << 4;
    a->mUnk_34 = b->mUnk_28 * b->mUnk_2e << 4;
    a->mUnk_10 = 0;
}

void func_01ff9598(Unk01ff9598_A *a, Unk01ff9598 *b) {
    s32 w = b->mUnk_2c << 12;
    s32 h = b->mUnk_2e << 12;
    s32 k22;
    s32 k18;
    s32 k20;
    s32 v1;
    s32 c;
    s32 d;
    s32 e;
    s32 f;

    FX_DivAsync(h, w);
    k22 = b->mUnk_22;
    k18 = b->mUnk_18;
    k20 = b->mUnk_20;
    v1 = b->mUnk_1c;
    d = (s64) k18 * k20 >> 12;
    c = (s64) k18 * k22 >> 12;
    e = (s64) v1 * k20 >> 12;
    f = (s64) v1 * k22 >> 12;
    a->mUnk_00 = c;
    a->mUnk_14 = f;
    a->mUnk_04 = -e * FX_GetDivResult() >> 12;
    FX_DivAsync(w, h);
    a->mUnk_30 = b->mUnk_2c * (b->mUnk_18 - (d + c)) << 3;
    a->mUnk_34 = b->mUnk_2e * (e - f - b->mUnk_1c + 0x2000) << 3;
    a->mUnk_10 = d * FX_GetDivResult() >> 12;
}
