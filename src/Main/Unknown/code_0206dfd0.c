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
    z = p->mUnk_1d8.z - q->mUnk_1d8.z;
    if (z > r || z < m) {
        return FALSE;
    }
    x = p->mUnk_1d8.x - q->mUnk_1d8.x;
    if (x > r || x < m) {
        return FALSE;
    }
    y = p->mUnk_1d8.y - q->mUnk_1d8.y;
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
    return func_02039860(v, n);
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
    if (p->mUnk_3d4 > 0) {
        p->mUnk_3d4--;
        if (p->mUnk_3d4 <= 0) {
            p->mUnk_3d4 = 0;
        }
    }
    if (p->mUnk_7c & 0x402000) {
        return;
    }
    if (p->mUnk_48 & 0x40) {
        return;
    }
    for (i = 0; i < data_0217b5a8; i++) {
        if (!(data_0217b5bc[i] & 0x8000)) {
            continue;
        }
        q = data_0217b5c4[i];
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
        func_020eb3f0(&p->mUnk_1d8, &q->mUnk_1d8, r, &v);
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
            if (p->mUnk_44 & 0x10) {
                f = Vec3Dot(&p->mUnk_244, &a);
                a.x -= (s32) (((s64) p->mUnk_244.x * f) >> 12);
                a.y -= (s32) (((s64) p->mUnk_244.y * f) >> 12);
                a.z -= (s32) (((s64) p->mUnk_244.z * f) >> 12);
            }
            if (p->mUnk_44 & 0x80) {
                if (Vec3Dot(&p->mUnk_244, &a) < 0) {
                    f = Vec3Dot(&p->mUnk_250, &a);
                    a.x -= (s32) (((s64) p->mUnk_250.x * f) >> 12);
                    a.y -= (s32) (((s64) p->mUnk_250.y * f) >> 12);
                    a.z -= (s32) (((s64) p->mUnk_250.z * f) >> 12);
                }
            }
            if (q->mUnk_44 & 0x10) {
                f = Vec3Dot(&q->mUnk_244, &b);
                b.x -= (s32) (((s64) q->mUnk_244.x * f) >> 12);
                b.y -= (s32) (((s64) q->mUnk_244.y * f) >> 12);
                b.z -= (s32) (((s64) q->mUnk_244.z * f) >> 12);
            }
            if (q->mUnk_44 & 0x80) {
                if (Vec3Dot(&q->mUnk_244, &b) < 0) {
                    f = Vec3Dot(&q->mUnk_250, &b);
                    b.x -= (s32) (((s64) q->mUnk_250.x * f) >> 12);
                    b.y -= (s32) (((s64) q->mUnk_250.y * f) >> 12);
                    b.z -= (s32) (((s64) q->mUnk_250.z * f) >> 12);
                }
            }
            Vec3Add(p->mUnk_510, &a, p->mUnk_510);
            Vec3Add(q->mUnk_510, &b, q->mUnk_510);
            if (q->mUnk_44 & 0xc0) {
                Vec3Sub(&q->mVelocity, &p->mVelocity, &e);
                f = Vec3Dot(&n, &e);
                e.x = (s32) (((s64) n.x * f) >> 12);
                e.y = (s32) (((s64) n.y * f) >> 12);
                e.z = (s32) (((s64) n.z * f) >> 12);
                p->mForwardSpeed += Vec3Dot(&p->mUnk_50, &e);
            }
            if (p->mUnk_44 & 0xc0) {
                Vec3Sub(&p->mVelocity, &q->mVelocity, &g);
                f = Vec3Dot(&n, &g);
                g.x = (s32) (((s64) n.x * f) >> 12);
                g.y = (s32) (((s64) n.y * f) >> 12);
                g.z = (s32) (((s64) n.z * f) >> 12);
                q->mForwardSpeed += Vec3Dot(&q->mUnk_50, &g);
            }
            if (data_021759c0->mMode == MODE_BATTLE) {
                k = func_020a1ee4(p->mIndex, q->mIndex);
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
            } else if (p->mUnk_3d4 <= 0) {
                if (p->mVelocityLength > 0x1000 || q->mVelocityLength > 0x1000) {
                    if (data_0217c814.mUnk_00 > 0x78) {
                        func_021090c4(&p->mUnk_00, 0x80, 0x7f, 0);
                    }
                    if (p->mVelocityLength > q->mVelocityLength) {
                        q->mKartCollisionTimer = 0x14;
                    } else {
                        p->mKartCollisionTimer = 0x14;
                    }
                    func_02071318(p, 2);
                    func_02071318(q, 2);
                    p->mUnk_3d4 = 0xf;
                    if (s == 0) {
                        s = func_0206c354(p, &n, k);
                        if (s == 0) {
                            h.x = -n.x;
                            h.y = -n.y;
                            h.z = -n.z;
                            s = func_0206c354(q, &h, k);
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
