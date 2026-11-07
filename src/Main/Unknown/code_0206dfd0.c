#include "Main/Unknown/code_0206dfd0.h"
#include "Main/Unknown/code_0206d020.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_0206d000.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_02070398.h"
#include "Main/Unknown/code_02071000.h"
#include "Main/Unknown/code_020a1e40.h"
#include "Main/Unknown/code_020ea670.h"
#include "Main/Unknown/code_02105ec0.h"
#include "Main/Unknown/code_02109054.h"
#include "Main/Unknown/unk_02154000.h"
#include "Main/Unknown/unk_02165000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "code_02147cd8.h"

static inline BOOL func_0206dfd0_inline(Kart *p, Kart *q, s32 r) {
    s32 x;
    s32 y;
    s32 z;
    s32 m;

    m = -r;
    z = p->mPointAlongUp.z - q->mPointAlongUp.z;
    if (z > r || z < m) {
        return FALSE;
    }
    x = p->mPointAlongUp.x - q->mPointAlongUp.x;
    if (x > r || x < m) {
        return FALSE;
    }
    y = p->mPointAlongUp.y - q->mPointAlongUp.y;
    if (y > r || y < m) {
        return FALSE;
    }
    if ((s64) x * x + (s64) y * y + (s64) z * z < (s64) r * r) {
        return TRUE;
    }
    return FALSE;
}

static inline s32 func_0206dfd0_inline_2(Vec3 *v, Vec3 *n) {
    if ((s64) v->x * v->x + (s64) v->y * v->y + (s64) v->z * v->z < 0x10) {
        return 0;
    }
    return Vec3NormalizeAndGetLengthUnchecked(v, n);
}

void CollideKartWithKarts(Kart *p) {
    s32 i;
    Kart *q;
    s32 r;
    s32 d;
    s32 f;
    s32 k;
    BOOL c;
    s32 s;
    u32 w;
    u32 x;
    Vec3 n;
    Vec3 v;
    Vec3 a;
    Vec3 b;
    Vec3 e;
    Vec3 g;
    Vec3 m;
    Vec3 h;
    Vec3 u;

    s = 0;
    if (p->mKartCollisionDelayTimer > 0) {
        p->mKartCollisionDelayTimer--;
        if (p->mKartCollisionDelayTimer <= 0) {
            p->mKartCollisionDelayTimer = 0;
        }
    }
    if (p->mUnk_7c & 0x402000) {
        return;
    }
    if (p->mUnk_48 & 0x40) {
        return;
    }
    for (i = 0; i < gFoundCollisionSlotCount; i++) {
        if (!(gFoundCollisionSlotFlags[i] & 0x8000)) {
            continue;
        }
        q = gFoundCollisionSlotObjects[i];
        if (p->mTestedKartMask & (1 << q->mIndex)) {
            continue;
        }
        if (q->mUnk_7c & 0x402020) {
            continue;
        }
        if (q->mUnk_48 & 0x40) {
            continue;
        }
        r = p->mRadius + q->mRadius;
        q->mTestedKartMask |= 1 << p->mIndex;
        p->mTestedKartMask |= 1 << q->mIndex;
        if (func_0206dfd0_inline(p, q, r) == FALSE) {
            continue;
        }
        ComputeSphereOverlapOffset(&p->mPointAlongUp, &q->mPointAlongUp, r, &v);
        d = func_0206dfd0_inline_2(&v, &n);
        if (d > 0) {
            a.x = v.x >> 1;
            a.y = v.y >> 1;
            a.z = v.z >> 1;
            b.x = -a.x;
            b.y = -a.y;
            b.z = -a.z;
            k = 0;
            c = FALSE;
            if (p->mUnk_44 & KART_44_ON_GROUND) {
                f = VEC_DotProduct(&p->mGroundNormal, &a);
                a.x -= (s32) (((s64) p->mGroundNormal.x * f) >> 12);
                a.y -= (s32) (((s64) p->mGroundNormal.y * f) >> 12);
                a.z -= (s32) (((s64) p->mGroundNormal.z * f) >> 12);
            }
            if (p->mUnk_44 & 0x80) {
                if (VEC_DotProduct(&p->mGroundNormal, &a) < 0) {
                    f = VEC_DotProduct(&p->mUnk_250, &a);
                    a.x -= (s32) (((s64) p->mUnk_250.x * f) >> 12);
                    a.y -= (s32) (((s64) p->mUnk_250.y * f) >> 12);
                    a.z -= (s32) (((s64) p->mUnk_250.z * f) >> 12);
                }
            }
            if (q->mUnk_44 & KART_44_ON_GROUND) {
                f = VEC_DotProduct(&q->mGroundNormal, &b);
                b.x -= (s32) (((s64) q->mGroundNormal.x * f) >> 12);
                b.y -= (s32) (((s64) q->mGroundNormal.y * f) >> 12);
                b.z -= (s32) (((s64) q->mGroundNormal.z * f) >> 12);
            }
            if (q->mUnk_44 & 0x80) {
                if (VEC_DotProduct(&q->mGroundNormal, &b) < 0) {
                    f = VEC_DotProduct(&q->mUnk_250, &b);
                    b.x -= (s32) (((s64) q->mUnk_250.x * f) >> 12);
                    b.y -= (s32) (((s64) q->mUnk_250.y * f) >> 12);
                    b.z -= (s32) (((s64) q->mUnk_250.z * f) >> 12);
                }
            }
            VEC_Add(p->mUnk_510, &a, p->mUnk_510);
            VEC_Add(q->mUnk_510, &b, q->mUnk_510);
            if (q->mUnk_44 & 0xc0) {
                VEC_Subtract(&q->mVelocity, &p->mVelocity, &e);
                f = VEC_DotProduct(&n, &e);
                e.x = ((s64) n.x * f) >> 12;
                e.y = ((s64) n.y * f) >> 12;
                e.z = ((s64) n.z * f) >> 12;
                p->mForwardSpeed += VEC_DotProduct(&p->mTurnedForward, &e);
            }
            if (p->mUnk_44 & 0xc0) {
                VEC_Subtract(&p->mVelocity, &q->mVelocity, &g);
                f = VEC_DotProduct(&n, &g);
                g.x = ((s64) n.x * f) >> 12;
                g.y = ((s64) n.y * f) >> 12;
                g.z = ((s64) n.z * f) >> 12;
                q->mForwardSpeed += VEC_DotProduct(&q->mTurnedForward, &g);
            }
            if (gRaceSetup->mMode == MODE_BATTLE) {
                k = CallKartCollisionCallbacks(p->mIndex, q->mIndex);
            }
            w = p->mUnk_4c;
            if (w & 0x10000000) {
                if (!(q->mUnk_4c & 0x10000040)) {
                    c = TRUE;
                    func_0206dbf8(p, q);
                }
            } else if ((x = q->mUnk_4c) & 0x10000000) {
                if (!(w & 0x10000040)) {
                    c = TRUE;
                    func_0206dbf8(q, p);
                }
            } else if (w & 0x40) {
                if (!(x & 0x10000040)) {
                    m.x = -n.x;
                    m.y = -n.y;
                    m.z = -n.z;
                    c = TRUE;
                    func_0206de18(p, q, &m);
                }
            } else if (x & 0x40) {
                if (!(w & 0x10000040)) {
                    c = TRUE;
                    func_0206de18(q, p, &n);
                }
            } else if (p->mKartCollisionDelayTimer <= 0) {
                if (p->mVelocityLength > 0x1000 || q->mVelocityLength > 0x1000) {
                    if (gSceneSoundState.mRaceFrames > 0x78) {
                        StartSound(&p->mSoundSource, 0x80, 0x7f, 0);
                    }
                    if (p->mVelocityLength > q->mVelocityLength) {
                        q->mKartCollisionTimer = 0x14;
                    } else {
                        p->mKartCollisionTimer = 0x14;
                    }
                    StartKartModelScaleAnimation(p, 2);
                    StartKartModelScaleAnimation(q, 2);
                    p->mKartCollisionDelayTimer = 0xf;
                    if (s == 0) {
                        s = TryStartKartCollisionEffects(p, &n, k);
                        if (s == 0) {
                            h.x = -n.x;
                            h.y = -n.y;
                            h.z = -n.z;
                            s = TryStartKartCollisionEffects(q, &h, k);
                        }
                    }
                }
            }
            if (d > data_021654f4) {
                p->mUnk_4c |= 0x100000;
                q->mUnk_4c |= 0x100000;
            }
            if (c == FALSE) {
                u = data_02154f94;
                func_0206d7c8(q, p, &n, 1, &u);
                n.x = -n.x;
                n.y = -n.y;
                n.z = -n.z;
                func_0206d7c8(p, q, &n, 0, &u);
            }
        }
        p->mUnk_44 |= KART_44_NEAR_KART;
        q->mUnk_44 |= KART_44_NEAR_KART;
        p->mNearKartMask |= 1 << q->mIndex;
        q->mNearKartMask |= 1 << p->mIndex;
    }
}
