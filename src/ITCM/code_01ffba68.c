#include "ITCM/code_01ffba68.h"
#include "ITCM/code_01ff9598.h"
#include "ITCM/code_01ffa4b4.h"
#include "ITCM/code_01ffb000.h"
#include "ITCM/code_01ffc000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_0207a780.h"
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
#include "Main/Unknown/code_0207a790.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_02105ec0.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_0210ab48.h"
#include "Main/Unknown/code_0210dc7c.h"
#include "Main/Unknown/code_02024974.h"
#include "Main/Unknown/code_02081618.h"
#include "Main/Unknown/code_02066ac0.h"
#include "ITCM/code_01ffb130.h"
#include "code_02147cd8.h"
#include "Main/Unknown/unk_02165000.h"
#include "Main/Unknown/unk_0216c000.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/code_0203c8dc.h"
#include "Main/Unknown/code_02077bc0.h"

void QuaternionMultiply(const Vec4 *a, const Vec4 *b, Vec4 *c) {
    Vec4 t;

    t.x = (a->w * b->x + a->x * b->w + (a->y * b->z - a->z * b->y)) >> 12;
    t.y = (a->w * b->y + a->y * b->w + (a->z * b->x - a->x * b->z)) >> 12;
    t.z = (a->w * b->z + a->z * b->w + (a->x * b->y - a->y * b->x)) >> 12;
    t.w = (a->w * b->w - (a->x * b->x + a->y * b->y + a->z * b->z)) >> 12;
    *c = t;
}

void QuaternionBlend(Vec4 *a, const Vec4 *b, Vec4 *c, s32 d) {
    c->x = a->x + ((d * (b->x - a->x)) >> 12);
    c->y = a->y + ((d * (b->y - a->y)) >> 12);
    c->z = a->z + ((d * (b->z - a->z)) >> 12);
    c->w = a->w + ((d * (b->w - a->w)) >> 12);
}

void Matrix4x3FromQuaternion(void *a, const Vec4 *b) {
    s32 *o = a;
    s32 w;
    s32 x;
    s32 y;
    s32 z;
    s32 zx;
    s32 xx;
    s32 ww;
    s32 yy;
    s32 zw;
    s32 zy;
    s32 wx;
    s32 wy;
    s32 xy;

    w = b->x;
    x = b->y;
    y = b->z;
    z = b->w;
    zx = z * x >> 11;
    xx = x * x >> 11;
    ww = w * w >> 11;
    yy = y * y >> 11;
    zw = z * w >> 11;
    zy = z * y >> 11;
    wx = w * x >> 11;
    wy = w * y >> 11;
    xy = x * y >> 11;
    o[0] = 0x1000 - (xx + yy);
    o[1] = wx + zy;
    o[2] = wy - zx;
    o[3] = wx - zy;
    o[4] = 0x1000 - (yy + ww);
    o[5] = xy + zw;
    o[6] = wy + zx;
    o[7] = xy - zw;
    o[8] = 0x1000 - (ww + xx);
    o[9] = 0;
    o[10] = 0;
    o[11] = 0;
}

void Matrix3x3FromQuaternion(void *a, void *b) {
    s32 *o = a;
    const Vec4 *q = b;
    s32 w;
    s32 x;
    s32 y;
    s32 z;
    s32 zx;
    s32 xx;
    s32 ww;
    s32 yy;
    s32 zw;
    s32 zy;
    s32 wx;
    s32 wy;
    s32 xy;

    w = q->x;
    x = q->y;
    y = q->z;
    z = q->w;
    zx = z * x >> 11;
    xx = x * x >> 11;
    ww = w * w >> 11;
    yy = y * y >> 11;
    zw = z * w >> 11;
    zy = z * y >> 11;
    wx = w * x >> 11;
    wy = w * y >> 11;
    xy = x * y >> 11;
    o[0] = 0x1000 - (xx + yy);
    o[1] = wx + zy;
    o[2] = wy - zx;
    o[3] = wx - zy;
    o[4] = 0x1000 - (yy + ww);
    o[5] = xy + zw;
    o[6] = wy + zx;
    o[7] = xy - zw;
    o[8] = 0x1000 - (ww + xx);
}

void AdvanceKartMotion(Kart *p) {
    if (p->mUnk_7c & 0xa0) {
        AdvanceKartScaleFactor(p);
        return;
    }
    func_01ffca50(p);
    UpdateKartSpeedLimitGoal(p);
    func_02067488(p);
    UpdateKartSpeedLimit(p);
    func_01ffbd9c(p);
    func_01ffc6c0(p);
    func_01ff9d18(p);
    if (p->mUnk_48 & 0x10000) {
        AdvanceKartToKeyedPlacement(p);
    } else {
        func_01ffb130(p);
    }
}

void AdvanceKartCollision(Kart *p) {
    Vec3 v;

    if (p->mUnk_7c & 0x20) {
        return;
    }
    if (p->mUnk_44 & KART_44_NEAR_KART) {
        p->mUnk_44 |= 0x80000;
    } else {
        p->mUnk_44 &= ~0x80000;
    }
    ComputeKartCollisionCenter(&p->mCollisionCenter, &p->mUnk_98, 0x400, p);
    func_01ffa4b4(p, &v);
    AdvanceKartOrientation(p, &v);
    p->mUnk_244 = v;
    p->mUnk_4d0 = p->mUnk_4d0 + 1;
    if (p->mUnk_4c & 0x8000) {
        ComputeKartSidePoints(p);
    }
    if ((p->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) && IsRaceStarted() == 1) {
        SetKartKind3ShapeMask(p->mIndex);
    }
    func_01ffc920(p);
    AdvanceKartCollisionTimer(p);
    if (p->mUnk_4c & 8) {
        AdvanceKartModelScaleAnimation(p);
    }
    p->mUnk_230(p);
}

void UpdateKartPrevValuesAndClearFlags(Kart *p) {
    p->mTestedKartMask = 0;
    p->mUnk_44 &= 0x57ffffdf;
    p->mUnk_4c &= 0xffeb7efd;
    p->mPrevNearKartMask = p->mNearKartMask;
    p->mNearKartMask = 0;
    p->mPrevPos = p->mPos;
    p->mUnk_1e4 = p->mUnk_1d8;
    p->mUnk_2f0 = p->mUnk_2e4;
    p->mUnk_2e4 = p->mUnk_2d8;
    p->mSlotFunctions[5](p);
}

static inline const s32 func_01ffc090_inline(void) {
    return data_usa_02165500;
}

void func_01ffca50(Kart *p) {
    p->mUnk_48 &= ~(KART_48_TURN_LEFT | KART_48_TURN_RIGHT);
    p->mRadius = ((s64) p->mUnk_4c8 * (s32) (((s64) p->mPhysicalParam->mRadius * p->mUnk_394) >> 12)) >> 12;
    p->mUnk_1d4 = ((s64) p->mPhysicalParam->mUnk_04 * p->mScale.z) >> 12;
    p->mTurnHeadingAnglePerFrameGoal = 0;
}

void func_01ffc9e8(Kart *p, s32 a) {
    s32 b;
    s32 c;
    s32 d;

    c = (p->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) ? 3 : 2;
    b = data_usa_0216ca38[a];
    d = func_02086080(p->mIndex);
    func_0210ddf4(&(data_0217d26c)[c], d + b, func_02071980, p, a);
}

s32 AdvanceKartRank(Kart *p) {
    BOOL b;
    s32 a;
    s32 c;
    Kart *o;

    b = FALSE;
    a = GetKartRank(p->mIndex);
    if (a != p->mRank) {
        if (p->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) {
            SetSceneSoundRank((u8) (a - 1));
        }
        if (a < p->mRank && a < gRaceSetup->mKartCount) {
            c = gRaceProgress->mKartAtRank[(u8) (a + 1) - 1];
            if (c >= 0) {
                o = GetKart((u16) c);
                if (!(o->mUnk_7c & 0x402004)) {
                    b = TRUE;
                }
            }
        }
    }
    p->mRank = a;
    return b;
}

void func_01ffc920(Kart *p) {
    func_02024a88(p);
}

void AdvanceKartCollisionTimer(Kart *p) {
    if (p->mKartCollisionTimer <= 0) {
        return;
    }
    p->mKartCollisionTimer = p->mKartCollisionTimer - 1;
    if (p->mKartCollisionTimer > 0) {
        return;
    }
    StartKartCollisionSound(p, p->mUnk_3cc, p->mUnk_3d0);
    p->mKartCollisionTimer = 0;
}

void func_01ffc6c0(Kart *p) {
    s32 a;
    s32 b;
    enum { K0 } k;

    if (p->mUnk_48 & 0x4000) {
        p->mUnk_23a = p->mUnk_23a - 1;
        if (p->mUnk_23a <= 0) {
            p->mUnk_23a = 0;
            p->mUnk_48 &= ~0x44000;
        }
    }
    if (IsRaceStarted() == 1) {
        a = 0;
        if (func_01ffc67c(p) != FALSE) {
            k = p->mEntryIndex;
            data_02175628[k].mBitMask = 0xe04;
            if (p->mUnk_4c & 0x10000000) {
                k = p->mEntryIndex;
                data_02175628[k].mBitMask = 0xe34;
            }
            if (p->mUnk_48 & 0x2000000) {
                k = p->mEntryIndex;
                data_02175628[k].mBitMask = 0xe05;
            }
        } else {
            k = p->mEntryIndex;
            data_02175628[k].mBitMask = 0xff7;
            func_01ffc558(p);
        }
        func_01ffc5a0(p);
        if (p->mState == KART_STATE_NORMAL) {
            b = 0;
            if (!(p->mUnk_44 & KART_44_DRIFTING)) {
                b = TryTurnKartAtLowSpeed(p);
            }
            a = func_01ffc27c(p, b);
            AdvanceKartDrift(p);
            func_01ffba68(p);
        }
        func_01ffc090(p, a);
        if (AdvanceKartRank(p) == 0) {
            return;
        }
        if (p->mUnk_48 & 0x840) {
            return;
        }
        func_0210af40(p, p->mUnk_3cc, 8);
        return;
    }
    AdvanceKartRank(p);
    func_01ffc558(p);
    func_01ffc5a0(p);
    k = p->mEntryIndex;
    a = data_02175628[k].mBits;
    if ((u16) (a & PAD_KEY_LEFT)) {
        p->mUnk_48 |= KART_48_TURN_LEFT;
    } else if ((u16) (a & PAD_KEY_RIGHT)) {
        p->mUnk_48 |= KART_48_TURN_RIGHT;
    }
    p->mUnk_44 |= KART_44_ON_GROUND;
}

BOOL func_01ffc67c(Kart *p) {
    if (p->mState != KART_STATE_NORMAL || (p->mUnk_48 & 0x6052840) || (p->mUnk_7c & 0x200000a8)) {
        return TRUE;
    }
    return FALSE;
}

void func_01ffc5a0(Kart *p) {
    u32 *r;
    u32 *q;
    u32 f;
    enum { K0 } k;

    p->mUnk_48 &= ~0x186;
    p->mUnk_44 &= ~0x40500;
    q = (u32 *) &p->mUnk_48;
    k = p->mEntryIndex;
    if ((u16) (data_02175628[k].mBits & PAD_KEY_A)) {
        *q |= 2;
    }
    k = p->mEntryIndex;
    if ((u16) (data_02175628[k].mBits & PAD_KEY_B)) {
        r = (u32 *) &p->mUnk_48;
        p->mUnk_48 |= 4;
        f = p->mUnk_48;
        if ((f & 2) && !(f & 0x8020)) {
            *r &= ~6;
            *r |= 0x80;
        }
    }
    if (p->mForwardSpeed < 0) {
        p->mUnk_44 |= 0x100;
    }
}

void func_01ffc558(Kart *p) {
    RaceSetup *d;
    enum { K0 } k;

    d = gRaceSetup;
    if (d->mMode != MODE_MISSION_RUN) {
        return;
    }
    if (!(d->mUnk_044 & 1)) {
        return;
    }
    k = p->mEntryIndex;
    data_02175628[k].mBitMask = 0xff6;
}

void DecayValueToZero(s32 *p) {
    *p = ((s64) *p * 0xe6a) >> 12;
    if ((*p <= 0 ? -*p : *p) < 0x7b) {
        *p = 0;
    }
}

s32 func_01ffc27c(Kart *p, s32 a) {
    s32 x = p->mPhysicalParam->mUnk_30;
    BOOL d = FALSE;
    s32 r = 0;
    enum { K1 } b = 1;
    s32 t;
    s32 v;
    u32 f;
    u16 w;
    enum { K0 } k;
    u32 c;

    if (p->mUnk_4c & 0x30000000) {
        return 0;
    }
    v = p->mForwardSpeed;
    t = v > 0 ? v : -v;
    if (t < 0x2000) {
        t = v <= 0 ? -v : v;
        x = ((x + (s16) (s32) (((s64) x * (t >> 1)) >> 12)) << 15) >> 16;
    }
    f = p->mUnk_44;
    if ((f & 0x800) && (f & 2)) {
        t = p->mTurnDirection * 0x168;
        if (a == 0) {
            t = t * ((f & 0x100) ? -1 : 1);
        }
        if (p->mUnk_7c & 2) {
            t = t << 1;
        }
        p->mHeadingAngle = p->mHeadingAngle - t;
        k = p->mEntryIndex;
        w = data_02175628[k].mBits;
        if ((u16) (w & PAD_KEY_LEFT)) {
            p->mUnk_48 |= KART_48_TURN_LEFT;
        } else if ((u16) (w & PAD_KEY_RIGHT)) {
            p->mUnk_48 |= KART_48_TURN_RIGHT;
        }
        return 1;
    }
    if (!(f & KART_44_ON_GROUND)) {
        k = p->mEntryIndex;
        w = data_02175628[k].mBits;
        if ((u16) (w & PAD_KEY_UP)) {
            p->mAirTiltAngle += 0x96;
            if (p->mAirTiltAngle > 0x157c) {
                p->mAirTiltAngle = 0x157c;
            }
        } else if ((u16) (w & PAD_KEY_DOWN)) {
            p->mAirTiltAngle -= 0x12c;
            if (p->mAirTiltAngle < -0x157c) {
                p->mAirTiltAngle = -0x157c;
            }
        }
        d = TRUE;
    }
    c = p->mUnk_44;
    f = c;
    if (((f & 0x100) && (u16) (data_02175628[k = p->mEntryIndex].mBits & PAD_KEY_B)) || ((f & 0x100) && !(f & 0xa))) {
        b = -1;
        x = (s16) ((s16) x * (s16) b);
    }
    k = p->mEntryIndex;
    w = data_02175628[k].mBits;
    if ((u16) (w & PAD_KEY_LEFT)) {
        r = ((s32(*)(Kart *, s32, s32, s32, s32, u32)) ApplyKartTurn)(p, x, b, 1, d, KART_48_TURN_LEFT);
    } else if ((u16) (w & PAD_KEY_RIGHT)) {
        r = ((s32(*)(Kart *, s32, s32, s32, s32, u32)) ApplyKartTurn)(p, x, b, -1, d, KART_48_TURN_RIGHT);
    }
    return r;
}

s32 ApplyKartTurn(Kart *p, s16 a, s16 b, s32 c, s32 d, u32 e) {
    s16 k;
    s16 x;
    u32 f;
    s32 m;

    k = p->mUnk_38a;
    p->mUnk_48 |= e;
    if (d != 0) {
        if (!(p->mUnk_44 & KART_44_DRIFTING)) {
            p->mTurnHeadingAnglePerFrameGoal = 0x32 * c;
        }
        return 1;
    }
    f = p->mUnk_44;
    if (f & KART_44_DRIFTING) {
        m = p->mTurnDirection * c;
        x = p->mPhysicalParam->mUnk_32;
        if (m > 0) {
            x = -k;
        } else {
            x = x + k;
        }
    } else {
        m = data_usa_021654c0 * b;
        x = a - (s32) (((s64) m * p->mVelocityLengthRatio) >> 12);
    }
    if (f & KART_44_ON_GROUND) {
        p->mTurnRatio += c * 0x666;
        if (p->mTurnRatio > 0x1000) {
            p->mTurnRatio = 0x1000;
        } else if (p->mTurnRatio < -0x1000) {
            p->mTurnRatio = -0x1000;
        }
    }
    if (p->mVelocityLength != 0 && !(p->mUnk_44 & 0x8000000)) {
        p->mTurnHeadingAnglePerFrameGoal = x * c;
    }
    return 1;
}

void func_01ffc090(Kart *p, s32 a) {
    if (a == 0) {
        if (p->mUnk_44 & KART_44_DRIFTING) {
            p->mTurnHeadingAnglePerFrameGoal = -p->mTurnDirection * ((p->mPhysicalParam->mUnk_32 + p->mUnk_38a) >> 1);
        }
        DecayValueToZero(&p->mTurnRatio);
    }
    if (p->mTurnHeadingAnglePerFrameGoal == 0 &&
        (p->mTurnHeadingAnglePerFrame <= 0 ? -p->mTurnHeadingAnglePerFrame : p->mTurnHeadingAnglePerFrame) < 5) {
        p->mTurnHeadingAnglePerFrame = 0;
    } else {
        p->mTurnHeadingAnglePerFrame =
            p->mTurnHeadingAnglePerFrame +
            (s32) (((s64) (p->mTurnHeadingAnglePerFrameGoal - p->mTurnHeadingAnglePerFrame) * func_01ffc090_inline() +
                    0x800) >>
                   12);
    }
    p->mHeadingAngle += (u16) p->mTurnHeadingAnglePerFrame;
}

// Writes base + (mRadius + extra) * up to the out vector, where up is row 1 of the matrix at 0x120 (the vector
// GetKartUp returns), and nothing else.
void ComputeKartPointAlongUp(Vec3 *a, const Vec3 *b, s32 c, Kart *p) {
    VEC_MultAdd(p->mRadius + c, &p->mUnk_12c, b, a);
}

void ComputeKartCollisionCenter(Vec3 *a, const Vec3 *b, s32 c, Kart *p) {
    Vec3 d;
    Vec3 e;

    VEC_Subtract(&p->mPos, &p->mPrevPos, &d);
    VEC_Add(&d, b, &e);
    VEC_MultAdd(p->mRadius + c, &p->mUnk_15c, &e, a);
}

void SetKartPrevCollisionCenter(Kart *p) {
    VEC_MultAdd(p->mRadius + 0x400, &p->mUnk_15c, &p->mUnk_98, &p->mPrevCollisionCenter);
}

// Called once per step of the driving states (AdvanceKartMotion, func_020651fc); also writes mUnk_dc in five branches.
void UpdateKartSpeedLimitGoal(Kart *p) {
    s32 *q;
    u32 f;

    p->mSpeedLimitGoal = ((s64) (s32) (((s64) p->mPhysicalParam->mBaseSpeedLimit * p->mSpeedLimitFactor) >> 12) *
                          (s32) (((s64) (s32) p->mUnk_d4 * p->mUnk_d8) >> 12)) >>
                         12;
    q = &p->mSpeedLimitGoal;
    if (p->mUnk_7c & 0x402000) {
        *q = p->mPhysicalParam->mBaseSpeedLimit;
        p->mSpeedLimitFactor = 0x1000;
    }
    if (p->mUnk_48 & 0x10000000) {
        *q = p->mUnk_4c4;
        p->mSpeedLimitFactor = 0x1000;
    }
    f = p->mUnk_48;
    if (f & KART_48_BOOST) {
        if ((p->mUnk_4c & 0x10000040) || (f & 0x20000000)) {
            *q = p->mPhysicalParam->mBaseSpeedLimit;
            p->mSpeedLimitFactor = 0x1000;
        }
        *q = ((s64) *q * 0x14cd) >> 12;
        if (p->mUnk_48 & 0x400001) {
            if (*q < 0x8800) {
                *q = 0x8800;
                p->mSpeedLimitFactor = 0x1000;
            }
        }
    } else if (p->mUnk_4c & 0x10000040) {
        *q = ((s64) p->mPhysicalParam->mBaseSpeedLimit * 0x1333) >> 12;
        p->mSpeedLimitFactor = 0x1000;
    }
}

// Called right after UpdateKartSpeedLimitGoal: the limit falls by 0xf37/0x1000 per step down to the goal and rises to
// it at once.
void UpdateKartSpeedLimit(Kart *p) {
    if (p->mSpeedLimit > p->mSpeedLimitGoal) {
        p->mSpeedLimit = ((s64) p->mSpeedLimit * 0xf37) >> 12;
        if (p->mSpeedLimit < p->mSpeedLimitGoal) {
            p->mSpeedLimit = p->mSpeedLimitGoal;
        }
    } else {
        p->mSpeedLimit = p->mSpeedLimitGoal;
    }
}

void func_01ffbd9c(Kart *p) {
    FX_DivAsync(p->mVelocityLength, p->mSpeedLimit);
    if (p->mUnk_44 & KART_44_ON_GROUND) {
        Vec3CrossUnrounded(&p->mUnk_120, &p->mUnk_244, &p->mForward);
    } else {
        GetKartForward(p, &p->mForward);
    }
    p->mVelocityLengthRatio = FX_GetDivResult();
    if (p->mVelocityLengthRatio > 0x1000) {
        p->mVelocityLengthRatio = 0x1000;
        p->mVelocityLength = p->mSpeedLimit;
    }
}

void func_01ffba68(Kart *p) {
    s32 v;
    s32 a;
    s32 b;
    s32 c;
    BOOL d;
    s32 e;
    s32 f;
    u32 g;

    d = (p->mUnk_44 & KART_44_DRIFTING) == 0;
    if (d) {
        v = p->mPhysicalParam->mUnk_14;
        a = p->mPhysicalParam->mUnk_18;
        b = p->mPhysicalParam->mUnk_1c;
    } else {
        v = p->mPhysicalParam->mUnk_20;
        a = p->mPhysicalParam->mUnk_24;
        b = p->mPhysicalParam->mUnk_28;
    }
    c = v;
    f = p->mUnk_48;
    if (f & KART_48_BOOST) {
        AdvanceKartBoost(&v, p);
    } else if (f & 4) {
        v = -0x19a;
        if (p->mUnk_4c & 0x40) {
            v = -0x4cd;
        }
    } else if (d) {
        if (p->mUnk_4c & 0x10000040) {
            v = 0x4cd;
        } else {
            e = p->mForwardSpeed;
            f = p->mVelocityLengthRatio;
            if (e < 0) {
                v = c + (s32) (((s64) -e * 0x52 + 0x800) >> 12);
            } else if (f < 0x800) {
                v = c;
            } else if (f > b) {
                v = a;
            } else {
                e = FX_Div(c - a, b - 0x800);
                f = f - 0x800;
                v = c - (s32) (((s64) e * f) >> 12);
            }
        }
    }
    if (p->mUnk_4c & 0x20000000) {
        func_020713a0(p);
    }
    f = p->mUnk_48;
    if (f & 0x10000000) {
        p->mForwardSpeed += 0x1000;
    } else if (p->mUnk_44 & KART_44_ON_GROUND) {
        g = p->mUnk_4c;
        if (!(g & 0x20000000)) {
            if (f & 0x80) {
                p->mForwardSpeed = ((s64) p->mForwardSpeed * 0xfae) >> 12;
            } else if (f & 0x26) {
                p->mForwardSpeed += v;
            } else if (!(g & 0x10000000)) {
                p->mUnk_44 |= 0x400;
            }
        }
    }
    g = p->mUnk_44;
    if ((g & 0x8000) && (g & KART_44_ON_GROUND)) {
        p->mUnk_44 &= ~0x8000;
    }
    if (p->mHeadingAnglePerFrame != 0) {
        p->mHeadingAnglePerFrame = (s32) (((s64) p->mHeadingAnglePerFrame * 0xe66) >> 12);
        if ((p->mHeadingAnglePerFrame <= 0 ? -p->mHeadingAnglePerFrame : p->mHeadingAnglePerFrame) < 0x14) {
            p->mHeadingAnglePerFrame = 0;
        }
        p->mHeadingAngle += (u16) p->mHeadingAnglePerFrame;
    }
    g = p->mUnk_44;
    if (!(g & KART_44_ON_GROUND) || !d || (g & 0x8008002)) {
        return;
    }
    if (p->mTurnAngle > 0) {
        p->mTurnAngle = p->mTurnAngle - p->mPhysicalParam->mUnk_34;
        if (p->mTurnAngle < 0) {
            p->mTurnAngle = 0;
        }
    } else if (p->mTurnAngle < 0) {
        p->mTurnAngle = p->mTurnAngle + p->mPhysicalParam->mUnk_34;
        if (p->mTurnAngle > 0) {
            p->mTurnAngle = 0;
        }
    }
}
