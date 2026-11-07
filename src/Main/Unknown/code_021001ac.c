#include "Main/Unknown/code_021001ac.h"
#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_02046be8.h"
#include "Main/Unknown/code_0205a548.h"
#include "Main/Unknown/code_020681f0.h"
#include "Main/Unknown/code_02068eac.h"
#include "Main/Unknown/code_0208ab98.h"
#include "Main/Unknown/code_020d3b10.h"
#include "Main/Unknown/code_020e66e4.h"
#include "Main/Unknown/code_020f8e78.h"
#include "Main/Unknown/code_020f9c40.h"
#include "Main/Unknown/code_020fe4b4.h"

#include "Main/Unknown/code_0208a000.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/code_020f8000.h"
#include "Main/Unknown/code_020fe000.h"
#include "Main/Unknown/code_02100de4.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Unknown/code_020d3000.h"
#include "Main/Unknown/code_020e6000.h"
#include "Main/Unknown/code_020ed578.h"
#include "Main/Unknown/code_020ed588.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_020f813c.h"
#include "Main/Unknown/unk_0216c000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_027e0000.h"
#include "Main/Unknown/code_02100700.h"
#include "Main/Unknown/code_02100704.h"
#include "Main/Unknown/unk_0215a000.h"
#include "Main/Unknown/code_0205a000.h"
#include "Main/Unknown/code_020f8e3c.h"
#include "Main/Unknown/code_02100b78.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02100b84.h"
#include "Main/Unknown/code_02100dd8.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_02068000.h"
#include "Main/Unknown/code_02069000.h"
#include "Main/Unknown/code_020d8000.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_020d8474.h"
#include "Main/Unknown/code_020e6a74.h"
#include "code_02146d78.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_021025d8.h"
#include "01/code_021a2034.h"
#include "Main/Unknown/code_0203c8dc.h"
#include "Main/Unknown/code_02077bc0.h"

void func_02102668(Unk02102668 *p0) {
    p0->mUnk_170 = 0x1u;
}

void ResetItemTeresa(Unk021025d8 *a) {
    UnkFunc *const *v1;
    a->mUnk_154 = 0x13;
    a->mUnk_158 = 0;
    v1 = (UnkFunc *const *) gItemTeresaStateTable;
    a->mUnk_15c = 0;
    a->mUnk_160 = 0xe;
    func_02046be8(a->mUnk_12c, v1, 7, a);
    a->mUnk_140 = 8;
    a->mUnk_144 = 0;
    func_020f9c40((s32) a);
    a->mUnk_24c = 0;
    a->mUnk_250 = 0xffffffff;
    a->mUnk_254 = 0x12;
    a->mUnk_258 = 0xffffffff;
    a->mUnk_25c = 0x12;
    a->mUnk_260 = 0xffffffff;
    a->mUnk_264 = 0xffffffff;
    a->mUnk_268 = 0;
    a->mUnk_26c = 0;
    a->mUnk_270 = 0;
}

static inline u32 func_02101f7c_inline_2(Unk020f41c4_B *b, u32 n) {
    b->mUnk_00 = b->mUnk_08 * b->mUnk_00 + b->mUnk_10;
    if (n == 0) {
        return b->mUnk_00 >> 32;
    }
    return ((b->mUnk_00 >> 32) * n) >> 32;
}

static inline s32 func_02101f7c_inline(KartItems *v1, RaceSetup *o, s32 a, u16 k) {
    KartItems *e;
    Kart *q;
    BOOL v2;
    s32 l;

    l = 1;
    v2 = TRUE;
    e = &v1[k];
    q = e->mKart;
    if (q->mState < KART_STATE_PUSH_FLIP && (q->mUnk_7c & 0x400020) == 0) {
        v2 = FALSE;
    }
    if (v2 == FALSE && (q->mUnk_4c & 0x10000800) == 0) {
        l = 0;
    }
    if (l | ((q->mUnk_4c & 0x40) ? 1 : 0)) {
        v2 = FALSE;
    } else if (a != -1 && a == o->mCurrentEntries[k].mPlayer.mTeamIndex) {
        v2 = FALSE;
    } else {
        v2 = FALSE;
        if (e->mHeldItem.mUnk_00 != 0x13 && e->mHeldItem.mUnk_20 == 0) {
            v2 = e->mHeldItem.mUnk_00 != 0x10;
        }
    }
    return v2;
}

void PickItemTeresaKartByRank(ItemTeresa *p, s32 a) {
    u16 acc[7];
    u16 b2[7];
    u32 lim;
    RaceProgress *m;
    u32 j;
    u16 k;
    u16 v;
    Unk020f41c4_B *b;
    u16 i;
    s32 c;
    u16 s;
    u16 *t;
    u32 n;
    KartItems *v2;
    RaceSetup *v3;
    KartItems *v1;
    RaceSetup *o;

    lim = gRaceSetup->mKartCount;
    s = c = 0;
    t = data_0215a154;
    j = n = GetKartRank((u16) ((p->mUnk_000.mUnk_78 & 0x8000) == 0 ? (u16) (p->mUnk_000.mUnk_78 & ~0xff00) : 8));
    if (p->mUnk_148 != FALSE) {
        m = gRaceProgress;
        v1 = gKartItems;
        o = gRaceSetup;
        do {
            if (n > 1) {
                n = (u16) (n - 1);
                k = m->mKartAtRank[(u8) n - 1];
                if (func_02101f7c_inline(v1, o, a, k) != 0) {
                    s = s + *t;
                    b2[c] = k;
                    acc[c] = s;
                    c++;
                }
                t++;
            }
            if (j < lim) {
                j = (u16) (j + 1);
                k = m->mKartAtRank[(u8) j - 1];
                if (func_02101f7c_inline(v1, o, a, k) != 0) {
                    s = s + *t;
                    b2[c] = k;
                    acc[c] = s;
                    c++;
                }
                t++;
            }
        } while (j < lim || n > 1);
    } else {
        m = gRaceProgress;
        v2 = gKartItems;
        v3 = gRaceSetup;
        do {
            if (j < lim) {
                j = (u16) (j + 1);
                k = m->mKartAtRank[(u8) j - 1];
                if (func_02101f7c_inline(v2, v3, a, k) != 0) {
                    s = s + *t;
                    b2[c] = k;
                    acc[c] = s;
                    c++;
                }
                t++;
            }
            if (n > 1) {
                n = (u16) (n - 1);
                k = m->mKartAtRank[(u8) n - 1];
                if (func_02101f7c_inline(v2, v3, a, k) != 0) {
                    s = s + *t;
                    b2[c] = k;
                    acc[c] = s;
                    c++;
                }
                t++;
            }
        } while (j < lim || n > 1);
    }
    b = &m->mRandom;
    v = s == 0 ? 0 : func_02101f7c_inline_2(b, s);
    for (i = 0; i < c; i++) {
        if (v < acc[i]) {
            p->mPickedKartIndex = b2[i];
            return;
        }
    }
}

void PickItemTeresaKartBattle(ItemTeresa *p, s32 a) {
    RaceProgress *m;
    Unk020f41c4_B *b;
    s32 end;
    s32 i;
    u32 lim;
    s32 b3;
    KartItems *v1;
    RaceSetup *o;
    s32 k;
    KartItems *e;
    Kart *q;
    s32 l;
    s32 n;
    u8 *row;

    m = gRaceProgress;
    b = &m->mRandom;
    b->mUnk_00 = b->mUnk_08 * b->mUnk_00 + b->mUnk_10;
    o = gRaceSetup;
    i = (u16) (((u64) (u32) (b->mUnk_00 >> 32) * 8) >> 32);
    end = i + 8;
    lim = o->mKartCount;
    b3 = (u16) ((p->mUnk_000.mUnk_78 & 0x8000) == 0 ? (u16) (p->mUnk_000.mUnk_78 & ~0xff00) : 8);
    if (i >= end) {
        return;
    }
    v1 = gKartItems;
    row = &data_0215a164[i];
    do {
        k = *row;
        if (k < lim && k != b3) {
            e = &v1[k];
            q = e->mKart;
            n = l = 1;
            if (q->mState < KART_STATE_PUSH_FLIP && (q->mUnk_7c & 0x400020) == 0) {
                n = 0;
            }
            if (n == 0 && (q->mUnk_4c & 0x10000800) == 0) {
                l = 0;
            }
            if (l | ((q->mUnk_4c & 0x40) ? 1 : 0)) {
                l = 0;
            } else if (a != -1 && a == o->mCurrentEntries[k].mPlayer.mTeamIndex) {
                l = 0;
            } else {
                l = 0;
                if (e->mHeldItem.mUnk_00 != 0x13 && e->mHeldItem.mUnk_20 == 0) {
                    l = e->mHeldItem.mUnk_00 != 0x10;
                }
            }
            if (l != 0) {
                p->mPickedKartIndex = k;
                return;
            }
        }
        i++;
        row++;
    } while (i < end);
}

void InitItemTeresa(Unk02101d18 *x, ItemTeresa *p) {
    Kart *q;

    q = x->mUnk_10;
    StartKartTeresa(q);
    func_020f8e3c((u32) q, 0xf6);
    SetActiveItem(x->mUnk_0c, 0x10);
    func_0208adc8(&p->mUnk_000.mUnk_7c, 1);
    if (x->mUnk_0c->mFlags & 0x20) {
        p->mUnk_148 = FALSE;
    } else {
        p->mUnk_148 = TRUE;
    }
    func_02046bcc(p->mUnk_12c, 0);
    p->mUnk_24c = TRUE;
}

void AdvanceItemTeresa(ItemTeresa *p) {
    Kart *q;
    Vec3 *w;
    Vec3 v;

    func_02046b40(p->mUnk_12c);
    VEC_Subtract(&p->mUnk_000.mPos, &p->mUnk_000.mPrevPos, &p->mUnk_000.mVelocity);
    if (p->mUnk_000.mUnk_d0 != &p->mUnk_000.mUnk_0c4) {
        return;
    }
    q = p->mKart;
    if (q == NULL) {
        return;
    }
    w = &q->mUnk_98;
    VEC_Subtract(&p->mUnk_000.mPos, w, &v);
    MTX_MultVec33(&v, GetViewTransposeMatrix(), &v);
    VEC_Add(w, &v, &p->mUnk_000.mUnk_0c4);
}

void func_02101964(ItemTeresa *p, s32 a) {
    Kart *q;
    Vec3 *v;
    s32 *g;
    s32 *w;
    s32 d[3];
    s32 k;
    BOOL m;
    s32 s;
    s32 c;
    s32 t;
    s32 n;

    q = p->mKart;
    g = GetCurrentCamera();
    v = &p->mUnk_000.mPos;
    k = m = TRUE;
    if (q->mState < KART_STATE_PUSH_FLIP && (q->mUnk_7c & 0x400020) == 0) {
        k = 0;
    }
    if (k == 0 && (q->mUnk_4c & 0x10000800) == 0) {
        m = FALSE;
    }
    if (m != FALSE) {
        if (p->mUnk_144 == FALSE && (p->mUnk_000.mFlags & 0x8000000) && p->mUnk_24c != FALSE) {
            p->mUnk_144 = TRUE;
            func_020fe694(0xb, p->mUnk_000.mId, 1, p->mState & 0xff);
        } else {
            p->mUnk_144 = TRUE;
        }
    }
    ((Vec3 *) d)->x = v->x - (&p->mUnk_000.mVelocity)->x;
    d[2] = v->z - (&p->mUnk_000.mVelocity)->z;
    if (p->mUnk_144 != FALSE) {
        VEC_Add(&p->mUnk_184, &p->mUnk_190, &p->mUnk_184);
        p->mUnk_190.x = ((s64) p->mUnk_190.x * 0xeb8) >> 12;
        p->mUnk_190.y = ((s64) p->mUnk_190.y * 0xeb8) >> 12;
        p->mUnk_190.z = ((s64) p->mUnk_190.z * 0xeb8) >> 12;
        *v = p->mUnk_184;
    } else {
        *v = q->mUnk_98;
        VEC_Subtract(v, &p->mUnk_184, &p->mUnk_190);
        p->mUnk_184 = *v;
        v->y -= q->mHopHeight;
    }
    VEC_Add(v, (Vec3 *) &p->mUnk_16c, v);
    w = g + 3;
    if (p->mUnk_15c != FALSE) {
        s = 0xccd;
        c = 0x800;
    } else {
        s = 0x800;
        c = 0x400;
    }
    if (a != 0) {
        n = ((s64) * (s32 *) q->mPhysicalParam * q->mScale.z + 0x800) >> 12;
        v->x += (s32) (((s64) -n * w[0]) >> 12);
        v->z += (s32) (((s64) -n * w[2]) >> 12);
    }
    d[0] -= v->x;
    d[2] -= v->z;
    t = ((s64) w[0] * d[0] + (s64) w[2] * d[2]) >> 12;
    d[0] = ((s64) w[0] * t) >> 12;
    d[2] = ((s64) w[2] * t) >> 12;
    d[0] = ((s64) d[0] * s) >> 12;
    d[2] = ((s64) d[2] * s) >> 12;
    if (d[0] > c) {
        d[0] = c;
    } else if (d[0] < -c) {
        d[0] = -c;
    }
    if (d[2] > c) {
        d[2] = c;
    } else if (d[2] < -c) {
        d[2] = -c;
    }
    p->mUnk_16c = d[0] + (s32) p->mUnk_16c;
    p->mUnk_174 = d[2] + (s32) p->mUnk_174;
}

void EnterItemTeresaState0(ItemTeresa *p) {
    p->mKart = GetKart((u16) (p->mUnk_000.mUnk_78 & ~0xff00));
    p->mUnk_184 = p->mKart->mUnk_98;
    p->mUnk_190 = p->mKart->mVelocity;
    *(Vec3 *) &p->mUnk_16c =
        (Vec3){0, (s32) (((s64) * (s32 *) p->mKart->mPhysicalParam * p->mKart->mScale.z + 0x800) >> 12), 0};
    p->mUnk_17c = 0;
    p->mUnk_000.mUnk_d8 = 0x1f;
    if (p->mKart->mUnk_48 & 1) {
        p->mUnk_000.mUnk_d0 = &p->mUnk_000.mUnk_0c4;
    }
}

void func_0210174c(ItemTeresa *p) {
    Vec3 v;
    Vec3 s;
    Vec3 *q;

    if (p->mUnk_248 >= 0xb) {
        return;
    }
    if (func_020d849c(&p->mUnk_1a4.mUnk_00) != FALSE) {
        do {
            p->mUnk_248++;
            if (p->mUnk_248 >= 0xb) {
                return;
            }
        } while (func_020f3fa8(&p->mUnk_1a4, &data_0215a1c0[p->mUnk_248]) != 0);
    }
    func_020d8488(&p->mUnk_1a4, &s);
    func_020d84c0(&p->mUnk_1a4.mUnk_00, s.y);
    if (p->mUnk_000.mUnk_d0 == &p->mUnk_000.mUnk_0c4) {
        v = (Vec3){s.x};
    } else {
        s32 f = s.x;

        q = func_020e6b28();
        v.x = ((s64) q->x * f) >> 12;
        v.y = ((s64) q->y * f) >> 12;
        v.z = ((s64) q->z * f) >> 12;
    }
    v.y += s.z;
    VEC_Subtract(&v, (Vec3 *) &p->mUnk_16c, &s);
    VEC_MultAdd(0x4f6, &s, (Vec3 *) &p->mUnk_16c, (Vec3 *) &p->mUnk_16c);
}

BOOL func_02101618(ItemTeresa *p, s32 a, s32 b) {
    s32 n;
    s32 m;
    s32 d;

    n = p->mStateFrames;
    if (p->mUnk_15c != FALSE) {
        m = -7;
        d = GetRaceUpdateFramesMod8() > 2;
        func_0210174c(p);
    } else {
        if (b < 7) {
            p->mUnk_17c += 0x133;
            m = 0x1c;
            d = 6;
        } else {
            m = 0x14;
            d = 2;
            if (p->mUnk_17c < 0) {
                p->mUnk_17c += 0x2cd;
            } else {
                p->mUnk_17c += 0x8f;
            }
        }
        p->mUnk_170 += p->mUnk_17c;
    }
    func_02101964(p, a);
    if (n > m) {
        if (p->mUnk_000.mUnk_d8 > 0) {
            p->mUnk_000.mUnk_d8 -= d;
        }
        if (n >= (p->mUnk_15c != FALSE ? 0x37 : 0x28)) {
            if (b < 7) {
                if (p->mState == 0) {
                    p->mUnk_14c = p->mUnk_170;
                    p->mUnk_150 = p->mUnk_17c;
                }
                p->mNextState = b;
                p->mNextStateRequested = 1;
            }
            return TRUE;
        }
    }
    return FALSE;
}

s32 func_021014a0(ItemTeresa *p, s32 a, s32 b) {
    s32 n;
    u16 k;

    n = p->mStateFrames;
    if (p->mUnk_15c != FALSE) {
        func_0210174c(p);
    } else if (p->mUnk_26c != FALSE) {
        k = data_0217c630[n];
        p->mUnk_16c = ((s64) p->mUnk_16c * k) >> 12;
        p->mUnk_174 = ((s64) p->mUnk_174 * k) >> 12;
    } else {
        p->mUnk_170 += p->mUnk_17c;
        p->mUnk_17c += 0x133;
        k = data_0217c630[n];
        p->mUnk_16c = ((s64) p->mUnk_16c * k) >> 12;
        p->mUnk_174 = ((s64) p->mUnk_174 * k) >> 12;
    }
    func_02101964(p, a);
    if (n > 7) {
        if (p->mUnk_000.mUnk_d8 < 0x1f) {
            p->mUnk_000.mUnk_d8 += 6;
        }
        if (n == 0x27) {
            if (p->mUnk_15c == FALSE) {
                p->mUnk_178 = p->mUnk_16c;
                p->mUnk_180 = p->mUnk_174;
            }
        } else if (n == 0x28) {
            if (p->mUnk_15c == FALSE) {
                p->mUnk_178 = p->mUnk_16c - p->mUnk_178;
                p->mUnk_180 = p->mUnk_174 - p->mUnk_180;
            }
            p->mNextState = b;
            p->mNextStateRequested = 1;
            p->mUnk_26c = FALSE;
        }
    }
    return n;
}

void UpdateItemTeresaState0(ItemTeresa *p) {
    func_02101618(p, 0, (p->mUnk_000.mFlags & 0x8000000) ? 1 : 2);
    if (!(p->mUnk_000.mFlags & 0x8000000)) {
        return;
    }
    if (p->mUnk_24c != FALSE) {
        return;
    }
    if (p->mUnk_144 != FALSE) {
        return;
    }
    if (p->mUnk_264 == 0xffffffff) {
        return;
    }
    if (p->mUnk_264 == 0 || p->mUnk_264 == 7) {
        p->mUnk_144 = TRUE;
        p->mUnk_264 = -1;
    }
}

void EnterItemTeresaState1(ItemTeresa *p) {
    if (p->mUnk_24c == FALSE) {
        return;
    }
    PickItemTeresaKartByRank(p, -1);
    func_020fe694(0xb, p->mUnk_000.mId, 0, p->mPickedKartIndex & 0xff);
    p->mUnk_250 = p->mPickedKartIndex;
    p->mUnk_24c = FALSE;
}

void UpdateItemTeresaState1(ItemTeresa *p) {
    s32 n;

    if (p->mUnk_250 == 0xffffffff) {
        return;
    }
    n = p->mStateFrames;
    if (p->mUnk_24c == FALSE && n < 0x28) {
        return;
    }
    p->mUnk_268 = n - 0x28;
    p->mPickedKartIndex = p->mUnk_250;
    p->mNextState = 2;
    p->mNextStateRequested = 1;
}

void EnterItemTeresaState2(ItemTeresa *p) {
    s32 *v;
    Camera *g;
    RaceSetup *o;
    void (*f)(ItemTeresa *, s32);
    int i;

    v = &p->mUnk_16c;
    g = GetCurrentCamera();
    if (!(p->mUnk_000.mFlags & 0x8000000)) {
        o = gRaceSetup;
        f = (o->mMode == MODE_BATTLE) ? PickItemTeresaKartBattle : PickItemTeresaKartByRank;
        if (o->mUseTeams != 0) {
            if ((p->mUnk_000.mUnk_78 & 0x8000) == 0) {
                i = (u16) (p->mUnk_000.mUnk_78 & ~0xff00);
            } else {
                i = 8;
            }
            f(p, o->mCurrentEntries[(u16) i].mPlayer.mTeamIndex);
            if (p->mPickedKartIndex == 8) {
                f(p, -1);
            }
        } else {
            f(p, -1);
        }
    }
    if (p->mUnk_000.mUnk_d0 == &p->mUnk_000.mUnk_0c4) {
        p->mUnk_000.mPos = p->mUnk_000.mUnk_0c4;
        p->mUnk_000.mUnk_d0 = &p->mUnk_000.mPos;
    }
    if (p->mPickedKartIndex < 8) {
        p->mKart = GetKart(p->mPickedKartIndex);
        p->mUnk_184 = p->mKart->mUnk_98;
        p->mUnk_190 = p->mKart->mVelocity;
        p->mUnk_144 = FALSE;
        func_020f8e3c((u32) p->mKart, 0xf4);
        if (p->mKart->mUnk_48 & 1) {
            p->mUnk_000.mUnk_d0 = &p->mUnk_000.mUnk_0c4;
        }
    }
    v[0] = ((s64) g->mSide.x * -0xa000) >> 12;
    v[2] = ((s64) g->mSide.z * -0xa000) >> 12;
    v[0] += (s32) (((s64) g->mForward.x * -0x11000) >> 12);
    v[2] += (s32) (((s64) g->mForward.z * -0x11000) >> 12);
    p->mUnk_17c = -p->mUnk_17c;
    p->mStallFrames = 0;
}

s32 func_02101014(ItemTeresa *p) {
    KartItems *e;
    Kart *q;
    Unk020f40dc *r;
    s32 a;
    s32 b;
    enum { K0 } k;

    e = &gKartItems[(u16) p->mPickedKartIndex];
    q = e->mKart;
    r = &e->mHeldItem;
    if (r->mUnk_00 == 0x13 || r->mUnk_20 != 0) {
        return 0xf;
    }
    if (r->mUnk_00 == 0x10) {
        return 0xf;
    }
    if (p->mUnk_144 != FALSE) {
        return 0xf;
    }
    a = b = 1;
    if (q->mState < KART_STATE_PUSH_FLIP && (q->mUnk_7c & 0x400020) == 0) {
        a = 0;
    }
    if (a == 0 && (q->mUnk_4c & 0x10000800) == 0) {
        b = 0;
    }
    if (b | ((q->mUnk_4c & 0x40) ? 1 : 0)) {
        return 0xf;
    }
    if (p->mUnk_000.mFlags & 0x8000000) {
        p->mItemInfoIndex = r->mUnk_00;
        p->mItemCount = r->mUnk_08;
        func_0205a5b0(((u8 *) data_0217aa18)[p->mPickedKartIndex & 0xff]);
    } else {
        func_020f413c(r, &p->mItemInfoIndex, &p->mItemCount);
    }
    func_02068a10(q);
    k = p->mItemInfoIndex;
    return gItemInfos[k].mObjectKind;
}

void UpdateItemTeresaState2(ItemTeresa *p) {
    u32 n;
    BOOL k;

    if (p->mPickedKartIndex == 8) {
        if (p->mStateFrames > 0x6e) {
            p->mItemObjectKind = 0xf;
            p->mNextState = (p->mUnk_000.mFlags & 0x8000000) ? 4 : 5;
            p->mNextStateRequested = 1;
        }
    } else {
        n = 0x28 - func_021014a0(p, 1, 3);
        if (p->mItemObjectKind == 0xe) {
            if (p->mUnk_24c != FALSE) {
                if (n == 0xa) {
                    p->mItemObjectKind = func_02101014(p);
                    p->mUnk_164 = 0;
                    if (p->mUnk_000.mFlags & 0x8000000) {
                        func_020fe694(0xb, p->mUnk_000.mId, 2, ((p->mItemInfoIndex << 2) | p->mItemCount) & 0xff);
                    }
                }
            } else if (n <= 0xa) {
                if (p->mUnk_258 != -1) {
                    p->mItemInfoIndex = p->mUnk_254;
                    p->mItemCount = p->mUnk_258;
                    p->mUnk_254 = 0x12;
                    p->mUnk_258 = -1;
                    if (p->mItemInfoIndex == 0x13) {
                        p->mItemObjectKind = 0xf;
                    } else {
                        p->mItemObjectKind = gItemInfos[p->mItemInfoIndex].mObjectKind;
                        func_0205a5b0(((u8 *) data_0217aa18)[p->mPickedKartIndex & 0xff]);
                    }
                    p->mUnk_164 = 0;
                    k = TRUE;
                } else {
                    k = FALSE;
                }
                if (k == FALSE && n == 1) {
                    p->mStateFrames--;
                    p->mUnk_26c = TRUE;
                    p->mStallFrames++;
                    if (p->mStallFrames > 0x3c) {
                        p->mUnk_254 = 0x13;
                        p->mUnk_258 = 0;
                    }
                }
            }
        }
    }
    if (!(p->mUnk_000.mFlags & 0x8000000)) {
        return;
    }
    if (p->mUnk_24c != FALSE) {
        return;
    }
    if (p->mUnk_144 != FALSE) {
        return;
    }
    if (p->mUnk_264 == 0xffffffff) {
        return;
    }
    if (p->mUnk_264 == 2 || p->mUnk_264 == 7) {
        p->mUnk_144 = TRUE;
        p->mUnk_264 = -1;
    }
}

void EnterItemTeresaState3(Unk02100dd8 *p0) {
    p0->mUnk_19c = 0x0u;
}

void UpdateItemTeresaState3(ItemTeresa *p) {
    if (p->mUnk_164 < 0x1f) {
        p->mUnk_164 += 5;
    }
    p->mUnk_178 = ((s64) p->mUnk_178 * 0xf85) >> 12;
    p->mUnk_180 = ((s64) p->mUnk_180 * 0xf85) >> 12;
    if (p->mStateFrames == 0x12) {
        if (p->mUnk_19c == 0) {
            p->mUnk_19c = -0x1ae;
            p->mUnk_1a0 = p->mUnk_17c;
        }
        p->mUnk_17c += p->mUnk_19c;
        p->mUnk_170 += p->mUnk_17c;
        func_02101964(p, 1);
        if (p->mUnk_19c >= 0 && p->mUnk_17c >= p->mUnk_1a0) {
            return;
        }
        p->mStateFrames--;
        if (p->mUnk_19c >= 0) {
            return;
        }
        if (p->mUnk_17c < -0xc00) {
            p->mUnk_19c = 0x133;
            return;
        }
        if (p->mUnk_17c <= 0) {
            return;
        }
        if (p->mUnk_17c >= -p->mUnk_19c) {
            return;
        }
        func_020f8e3c((u32) p->mKart, 0xf5);
    } else {
        p->mUnk_16c += p->mUnk_178;
        p->mUnk_174 += p->mUnk_180;
        func_02101618(p, 1, (p->mUnk_000.mFlags & 0x8000000) ? 4 : 5);
        if (!(p->mUnk_000.mFlags & 0x8000000)) {
            return;
        }
        if (p->mUnk_24c != FALSE) {
            return;
        }
        if (p->mUnk_144 != FALSE) {
            return;
        }
        if (p->mUnk_264 == 0xffffffff) {
            return;
        }
        if (p->mUnk_264 - 2 <= 1) {
            p->mUnk_144 = TRUE;
            p->mUnk_264 = -1;
        }
    }
}

void EnterItemTeresaState4(ItemTeresa *p) {
    p->mUnk_268 = ((p->mUnk_000.mFlags & 0x10000000) ? 0xf : 0) - p->mUnk_268;
    p->mUnk_24c = FALSE;
}

void UpdateItemTeresaState4(ItemTeresa *p) {
    p->mUnk_268--;
    if (p->mUnk_268 >= 0) {
        return;
    }
    p->mUnk_24c = (p->mUnk_000.mFlags & 0x10000000) == 0;
    p->mNextState = 5;
    p->mNextStateRequested = 1;
}

void func_02100b78(ItemTeresa *p0) {
    p0->mUnk_000.mUnk_d0 = &p0->mUnk_000.mUnk_0c4;
}

void func_02100b54(ItemTeresa *p) {
    if (p->mUnk_000.mUnk_d0 == &p->mUnk_000.mUnk_0c4) {
        p->mUnk_000.mPos = p->mUnk_000.mUnk_0c4;
        p->mUnk_000.mUnk_d0 = &p->mUnk_000.mPos;
    }
}

void EnterItemTeresaState5(ItemTeresa *p) {
    int i;
    KartItems *e;
    void (*f)(ItemTeresa *);

    if ((p->mUnk_000.mUnk_78 & 0x8000) == 0) {
        i = (u16) (p->mUnk_000.mUnk_78 & ~0xff00);
    } else {
        i = 8;
    }
    e = &gKartItems[(u16) i];
    p->mKart = e->mKart;
    p->mUnk_144 = FALSE;
    if (p->mUnk_24c != FALSE) {
        if (e->mActiveItem == 0x10) {
            p->mUnk_184 = p->mKart->mUnk_98;
            p->mUnk_190 = p->mKart->mVelocity;
            p->mUnk_16c = 0;
            p->mUnk_174 = 0;
        } else {
            p->mUnk_144 = TRUE;
            if (p->mUnk_000.mFlags & 0x8000000) {
                func_020fe694(0xb, p->mUnk_000.mId, 1, 5);
            }
            p->mUnk_16c = 0;
            p->mUnk_174 = 0;
        }
    }
    if (p->mItemObjectKind == 0xf) {
        func_020f4020(&p->mUnk_1a4, data_0215a1c0, data_0215a1c0[0].y);
        p->mUnk_248 = 3;
        p->mUnk_15c = TRUE;
    } else {
        p->mUnk_17c = -p->mUnk_150;
        p->mUnk_170 = p->mUnk_14c;
    }
    if (p->mUnk_144 == FALSE) {
        func_020f8e3c((u32) p->mKart, 0xf7);
    }
    p->mStallFrames = 0;
    f = (p->mKart->mUnk_48 & 1) ? func_02100b78 : func_02100b54;
    f(p);
}

void UpdateItemTeresaState5(ItemTeresa *p) {
    s32 i;
    KartItems *e;
    u32 n;
    BOOL k;
    s32 a0;
    s32 a1;

    if ((p->mUnk_000.mUnk_78 & 0x8000) == 0) {
        i = (u16) (p->mUnk_000.mUnk_78 & ~0xff00);
    } else {
        i = 8;
    }
    e = &gKartItems[(u16) i];
    if (p->mUnk_24c != FALSE && e->mActiveItem != 0x10 && p->mItemCount != -0x40) {
        p->mUnk_144 = TRUE;
        if (p->mUnk_000.mFlags & 0x8000000) {
            func_020fe694(0xb, p->mUnk_000.mId, 1, 5);
        }
    } else {
        n = 0x28 - func_021014a0(p, p->mUnk_15c == FALSE ? 1 : 0, 6);
        if (n < 7) {
            if (p->mUnk_164 > 0) {
                p->mUnk_164 -= 5;
            }
            if (n == 1) {
                if (p->mUnk_24c == FALSE) {
                    if (p->mUnk_260 == -1) {
                        k = FALSE;
                    } else {
                        p->mItemInfoIndex = p->mUnk_25c;
                        p->mItemCount = p->mUnk_260;
                        p->mUnk_25c = 0x12;
                        p->mUnk_260 = -1;
                        k = TRUE;
                    }
                    if (k == FALSE) {
                        p->mStateFrames--;
                        p->mUnk_26c = TRUE;
                        p->mStallFrames++;
                        if (p->mStallFrames > 0x3c) {
                            p->mUnk_25c = 0x13;
                            p->mUnk_260 = -0x40;
                            p->mItemObjectKind = 0xe;
                        }
                        goto skip;
                    }
                }
                e->mActiveItem = 0x13;
                if (p->mItemInfoIndex != 0x13) {
                    if (p->mUnk_24c == FALSE) {
                        func_0205a548(((u8 *) data_0217aa18)[e->mKartIndex & 0xff], p->mItemInfoIndex, p->mItemCount);
                    } else {
                        func_020f40dc(&e->mHeldItem, p->mItemInfoIndex, p->mItemCount);
                    }
                    p->mItemInfoIndex = 0x13;
                    p->mItemCount = -0x40;
                    p->mItemObjectKind = 0xe;
                    func_020f8e3c((u32) e->mKart, 0xf8);
                } else {
                    p->mItemCount = -0x40;
                    p->mItemObjectKind = 0xe;
                }
                if ((p->mUnk_000.mFlags & 0x8000000) && p->mUnk_24c != FALSE) {
                    func_020fe694(0xb, p->mUnk_000.mId, 3, ((e->mHeldItem.mUnk_00 << 2) | e->mHeldItem.mUnk_08) & 0xff);
                }
            }
        }
    }
skip:
    if (p->mUnk_15c == FALSE && p->mUnk_144 != FALSE) {
        a0 = p->mUnk_16c;
        a1 = p->mUnk_174;
        func_021014a0(p, 1, 6);
        p->mUnk_178 = p->mUnk_16c - a0;
        p->mUnk_180 = p->mUnk_174 - a1;
        p->mNextState = 6;
        p->mNextStateRequested = 1;
        p->mUnk_26c = FALSE;
    }
    if (!(p->mUnk_000.mFlags & 0x8000000)) {
        return;
    }
    if (p->mUnk_24c != FALSE) {
        return;
    }
    if (p->mUnk_144 != FALSE) {
        return;
    }
    if (p->mUnk_264 == 0xffffffff) {
        return;
    }
    if (p->mUnk_264 == 5 || p->mUnk_264 == 7) {
        p->mUnk_144 = TRUE;
        p->mUnk_264 = -1;
    }
}

u32 EnterItemTeresaState6(u32 p0) {
    return p0;
}

void UpdateItemTeresaState6(ItemTeresa *p) {
    BOOL a;
    s32 i;

    a = p->mItemInfoIndex != 0x13;
    if (p->mUnk_15c == FALSE) {
        p->mUnk_178 = ((s64) p->mUnk_178 * 0xf85) >> 12;
        p->mUnk_180 = ((s64) p->mUnk_180 * 0xf85) >> 12;
        p->mUnk_16c += p->mUnk_178;
        p->mUnk_174 += p->mUnk_180;
    }
    if (a != FALSE) {
        if (p->mUnk_164 < 0x1f) {
            p->mUnk_164 += 8;
        }
    }
    if (func_02101618(p, p->mUnk_15c == FALSE ? 1 : 0, 7) != FALSE) {
        if (a != FALSE) {
            if ((p->mUnk_000.mUnk_78 & 0x8000) == 0) {
                i = (u16) (p->mUnk_000.mUnk_78 & ~0xff00);
            } else {
                i = 8;
            }
            ((void (*)(s32 param_1, s32 param_2, s32 param_3)) func_020f40a0)(p->mItemInfoIndex, p->mItemCount,
                                                                              (u16) i);
        }
        ReleaseItemPoolObject(gItemPools + p->mUnk_000.mKind, &p->mUnk_000);
    }
    if (!(p->mUnk_000.mFlags & 0x8000000)) {
        return;
    }
    if (p->mUnk_24c != FALSE) {
        return;
    }
    if (p->mUnk_144 != FALSE) {
        return;
    }
    if (p->mUnk_264 == 0xffffffff) {
        return;
    }
    if (p->mUnk_264 - 5 <= 1) {
        p->mUnk_144 = TRUE;
        p->mUnk_264 = -1;
    }
}

void func_0210050c(ItemTeresa *p) {
    int i;
    KartItems *e;

    if ((p->mUnk_000.mUnk_78 & 0x8000) == 0) {
        i = (u16) (p->mUnk_000.mUnk_78 & ~0xff00);
    } else {
        i = 8;
    }
    e = &gKartItems[(u16) i];
    if (e->mActiveItem != 0x10) {
        return;
    }
    if (p->mItemCount != -0x40) {
        e->mActiveItem = 0x13;
    }
}

void func_021004c4(void *p, ItemTeresa *a, void *b) {
    func_020fecdc(p, a, b);
    if (a == NULL) {
        return;
    }
    if (b == NULL) {
        return;
    }
    func_020fe8ac(a->mUnk_000.mKind);
}

void InitItemTeresaFromData(ItemTeresa *p) {
    int i;

    func_020f8e78(p);
    func_0208adc8(&p->mUnk_000.mUnk_7c, 1);
    func_02046bcc(p->mUnk_12c, 0);
    if ((p->mUnk_000.mUnk_78 & 0x8000) == 0) {
        i = (u16) (p->mUnk_000.mUnk_78 & ~0xff00);
    } else {
        i = 8;
    }
    SetActiveItem(&gKartItems[(u16) i], 0x10);
}

void func_021003e8(ItemTeresa *p, u32 sel, s32 v1) {
    switch (sel) {
        case 0:
            p->mUnk_250 = v1;
            if (p->mUnk_250 == gRaceSetup->mEntryIndex) {
                p->mUnk_24c = TRUE;
            }
            break;
        case 1:
            p->mUnk_264 = v1;
            break;
        case 2:
            p->mUnk_254 = v1 >> 2;
            p->mUnk_258 = v1 & 3;
            break;
        case 3:
            p->mUnk_25c = v1 >> 2;
            p->mUnk_260 = v1 & 3;
            break;
    }
}

void DrawItemTeresa(ItemTeresa *p, s32 c, Unk020e6488 *q) {
    s32 a;
    s32 n;
    s32 b;
    s32 t;
    u16 d;
    s32 v[3];
    s32 x;
    s32 y;
    s32 z;
    Unk020e6488 *r;
    s32 i;
    s32 b2;

    if (p->mUnk_000.mUnk_d8 <= 0) {
        return;
    }
    a = 0x1e;
    func_01ff9048(0x14, &a, 1);
    func_01ff9048(0x19, SetViewTransposeMatrixPos(p->mUnk_000.mUnk_d0), 0xc);
    z = p->mUnk_000.mUnk_68.z;
    y = p->mUnk_000.mUnk_68.y;
    x = p->mUnk_000.mUnk_68.x;
    v[0] = x;
    v[1] = y;
    v[2] = z;
    func_01ff9048(0x1b, v, 3);
    if (p->mItemObjectKind < 0xe && p->mState >= 3) {
        r = func_020ed578(p->mItemObjectKind);
        n = p->mUnk_164;
        b2 = p->mItemCount;
        if (p->mUnk_000.mUnk_d8 < 0x1f) {
            if (p->mUnk_000.mUnk_d8 < n) {
                n = p->mUnk_000.mUnk_d8;
            }
        }
        if (n > 0x1f) {
            n = 0x1f;
        }
        if (n < 1) {
            n = 1;
        }
        func_01ff9048(0x11, NULL, 0);
        r->mUnk_14 = r->mUnk_14 & ~0x1f0000;
        r->mUnk_14 = r->mUnk_14 | ((u16) n << 16);
        func_020e6a18(r);
        i = 0;
        r->mUnk_18 = 0;
        while (i < b2) {
            func_01ff9048(0x1c, &data_0215a190[b2 == 2 ? 1 - i : i + 1], 3);
            t = AllocPolygonIdWrapping();
            r->mUnk_14 = r->mUnk_14 & ~0x3f000000;
            r->mUnk_14 = r->mUnk_14 | (t << 24);
            func_020e6854(r, &p->mUnk_000.mPos, 1, 0x1f);
            i++;
        }
        b = 1;
        func_01ff9048(0x12, &b, 1);
        if (n != 0x1f) {
            r->mUnk_14 = r->mUnk_14 & ~0x1f0000;
            r->mUnk_14 = r->mUnk_14 | 0x1f0000;
        }
    }
    t = AllocPolygonIdWrapping();
    q->mUnk_14 = q->mUnk_14 & ~0x3f000000;
    q->mUnk_14 = q->mUnk_14 | (t << 24);
    d = p->mUnk_000.mUnk_d8;
    q->mUnk_14 = q->mUnk_14 & ~0x1f0000;
    q->mUnk_14 = q->mUnk_14 | (d << 16);
    func_020ed588(&p->mUnk_000, q);
}
