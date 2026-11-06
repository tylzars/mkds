#include "Main/Unknown/code_020dc428.h"

#include "Main/Unknown/code_020dc448.h"
#include "Main/Unknown/code_020dc474.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_020dc5dc.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_020daf20.h"
#include "Main/Unknown/code_020d6000.h"
#include "Main/Unknown/code_020d8b88.h"
#include "code_02148538.h"
#include "Main/Unknown/code_020d4000.h"
#include "Main/Unknown/code_0210b760.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/code_020d8000.h"
#include "Main/Unknown/code_020d8474.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020d2000.h"
#include "ITCM/code_01ffba68.h"
#include "ITCM/code_01ffdee4.h"
#include "ITCM/code_01ffc000.h"
#include "Main/Unknown/code_020d7000.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Unknown/code_020b2ec0.h"
#include "Main/Unknown/code_020ea670.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020e6f50.h"
#include "Main/Unknown/code_020d49d8.h"
#include "Main/Unknown/code_020db000.h"
#include "Main/Unknown/code_020dc000.h"
#include "Main/Unknown/unk_0216b000.h"
#include "Main/Unknown/code_020dbf7c.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_02077bc0.h"

Unk020dd7a8 *data_0217b6d4 = 0;
Unk020dd804 *data_0217b6d8 = 0;

const Unk020dd860 data_02158388 = {func_020dd230, func_020dd1f4, 1, 0x1b000, {0}, 1, 1, 0x12e, {0}};
const Unk020dd804 data_0215835c = {{0}, CreateWanwanAndRockShadow, {0}, func_020dd6c8, {0}, 1, {0}, 0};
const Unk020dd7a8 data_02158334 = {{0}, UpdateWanwan, {0}, 0};

Unk020dd860 *func_020dd860(void) {
    Unk020dd860 *p;

    p = HeapAlloc(GetHeap(func_020364e8()), 0x40);
    *p = data_02158388;
    return p;
}

Unk020dd804 *func_020dd804(void) {
    Unk020dd804 *p;

    p = HeapAlloc(GetHeap(func_020364e8()), 0x2c);
    data_0217b6d8 = p;
    *p = data_0215835c;
    func_020d49d8(&data_0217b6d8);
    return data_0217b6d8;
}

Unk020dd7a8 *func_020dd7a8(void) {
    Unk020dd7a8 *p;

    p = HeapAlloc(GetHeap(func_020364e8()), 0x28);
    data_0217b6d4 = p;
    *p = data_02158334;
    func_020e6f50(&data_0217b6d4);
    return data_0217b6d4;
}

void func_020dd6c8(void *a, Wanwan *p, void *b, u32 c) {
    Unk02012f58 s;

    if (p->mUnk_00.mStateMachine.mState == 4) {
        if (func_020b2ec0() == 0) {
            p->mUnk_00.mPos.x += p->mUnk_00.mUnk_10.x;
            p->mUnk_00.mPos.z += p->mUnk_00.mUnk_10.z;
        }
    }
    p->mUnk_00.mMatrix.mUnk_00[3].x = p->mUnk_00.mPos.x >> 4;
    p->mUnk_00.mMatrix.mUnk_00[3].y = p->mUnk_00.mPos.y >> 4;
    p->mUnk_00.mMatrix.mUnk_00[3].z = p->mUnk_00.mPos.z >> 4;
    func_020ea8a8(gWanwan, &p->mUnk_00.mMatrix, &p->mUnk_00.mScale, c);
    Matrix3x3FromQuaternion(&s, &p->mUnk_d4);
    s.mUnk_00[3].x = p->mUnk_00.mPos.x >> 4;
    s.mUnk_00[3].y = p->mUnk_00.mPos.y >> 4;
    s.mUnk_00[3].z = p->mUnk_00.mPos.z >> 4;
    func_020ea868(gWanwanRockShadow, &s, &p->mUnk_00.mScale, c);
}

void UpdateWanwan(void *a, Wanwan *p) {
    u32 f;
    Unk020d7b88 m;
    Vec3 v;
    Vec3 w;
    Vec3 u;
    Unk0210b7a8 b;
    Unk0210b7a8 c;
    Unk0210b7a8 d;
    s32 h;
    BOOL k;
    s32 x;
    s32 z;
    s32 t;
    s32 y;

    h = p->mUnk_b0;
    func_02046b40(&p->mUnk_00.mStateMachine);
    p->mUnk_00.mUnk_10.y -= 0x400;
    p->mUnk_00.mPos.y += p->mUnk_00.mUnk_10.y;
    k = FALSE;
    v.x = p->mUnk_00.mPos.x;
    v.y = p->mUnk_00.mPos.y + p->mUnk_f4 + 0x5000;
    v.z = p->mUnk_00.mPos.z;
    if (h == 0) {
        w.y = p->mUnk_ac + 0xd000 - v.y;
        if (w.y > 0) {
            k = TRUE;
            w.x = 0;
            w.z = 0;
            if (p->mUnk_fc != 0) {
                if (!(p->mUnk_00.mDistanceSquaredAndFlags & 4)) {
                    if (p->mUnk_00.mFarDistanceSquared == gSoundFalloffs[2].mUnk_20) {
                        y = 2;
                    } else if (p->mUnk_00.mFarDistanceSquared == gSoundFalloffs[3].mUnk_20) {
                        y = 3;
                    } else {
                        y = 4;
                    }
                    c.mUnk_00 = 0x1a1;
                    c.mUnk_04 = &p->mUnk_00.mPos;
                    c.mUnk_08 = y;
                    c.mUnk_0c = func_020d4ef4(&p->mUnk_00.mPos);
                    func_0210b7a8(&c);
                }
            }
        }
    } else {
        if (func_01ffdee4(&v, NULL, 0, 0xd000, 8, -2, &w, &u, NULL, &f, NULL, NULL, NULL, NULL) != 0) {
            k = TRUE;
            if (p->mUnk_fc != 0) {
                if (!(p->mUnk_00.mDistanceSquaredAndFlags & 4)) {
                    if (p->mUnk_00.mFarDistanceSquared == gSoundFalloffs[2].mUnk_20) {
                        y = 2;
                    } else if (p->mUnk_00.mFarDistanceSquared == gSoundFalloffs[3].mUnk_20) {
                        y = 3;
                    } else {
                        y = 4;
                    }
                    d.mUnk_00 = 0x1df;
                    d.mUnk_04 = &p->mUnk_00.mPos;
                    d.mUnk_08 = y;
                    d.mUnk_0c = func_020d4ef4(&p->mUnk_00.mPos);
                    func_0210b7a8(&d);
                }
            }
        }
    }
    if (k != FALSE) {
        k = TRUE;
        if (p->mUnk_00.mStateMachine.mState == 2) {
            if (p->mUnk_00.mStateMachine.mStateFrames < 0x78) {
                k = FALSE;
            }
        }
        p->mUnk_00.mPos.y += w.y;
        if (p->mUnk_fc != 0 || k != FALSE) {
            if (p->mUnk_fc != 0) {
                x = p->mUnk_1a0.mUnk_00.mUnk_20->mUnk_00.x;
                z = p->mUnk_1a0.mUnk_00.mUnk_20->mUnk_00.z;
            } else {
                x = p->mUnk_160[2]->x - p->mUnk_00.mPos.x;
                z = p->mUnk_160[2]->z - p->mUnk_00.mPos.z;
            }
            t = (s32) (((s64) (s32) (((s64) p->mUnk_00.mUnk_10.x * x + (s64) p->mUnk_00.mUnk_10.z * z) >> 12) << 9) >>
                       12);
            if (t > 0x3000) {
                t = 0x3000;
            } else if (t < 0x2800) {
                t = 0x2800;
            }
            p->mUnk_00.mUnk_10.y = t;
        } else if (p->mUnk_e8 == 0xd000) {
            p->mUnk_00.mUnk_10.y = 0x2000;
            p->mUnk_e8 += 0x1000;
        } else {
            p->mUnk_00.mUnk_10.y = 0;
        }
        if (h != 0) {
            if (f & 0x1e34ef) {
                t = (s32) (((s64) p->mUnk_00.mUnk_10.x * u.x + (s64) p->mUnk_00.mUnk_10.z * u.z) >> 12);
                if (t < 0) {
                    p->mUnk_00.mUnk_10.y += (s32) (((s64) -t * 0x14cd) >> 12);
                }
                func_020d7b88(&u, &p->mUnk_c4);
            }
        }
        if (p->mUnk_fc == 0 && !(p->mUnk_00.mDistanceSquaredAndFlags & 4) && k != FALSE) {
            b = data_0216bedc;
            b.mUnk_04 = &p->mUnk_00.mPos;
            b.mUnk_0c = p->mUnk_00.mDistanceSquaredAndFlags & ~0xc000001f;
            func_0210b7a8(&b);
        }
    }
    if (h != 0) {
        func_020d7938(&p->mUnk_c4, &p->mUnk_d4, &m);
    }
    p->mUnk_e4 = p->mUnk_e4 + ((-p->mUnk_00.mUnk_10.y >> 1) - p->mUnk_e4 >> 4);
    if (h != 0) {
        func_020d788c(&m, (u16) (p->mUnk_e8 + p->mUnk_e4), &m);
    } else {
        func_020d76a8(&p->mUnk_d4, (u16) (p->mUnk_e8 + p->mUnk_e4), &m);
    }
    func_020d759c(&p->mUnk_b4, &m, &p->mUnk_b4, p->mUnk_ec);
    func_020d73f0(&p->mUnk_b4, &p->mUnk_b4);
    Matrix3x3FromQuaternion(&p->mUnk_00.mMatrix, &p->mUnk_b4);
    if (p->mUnk_00.mPos.y >= 0) {
        return;
    }
    func_020dbf7c(p);
}

u8 func_020dd230(Wanwan *p, void *a, u8 *b, u8 *c) {
    if (*b == 1) {
        if (p->mUnk_00.mStateMachine.mState != 2 || p->mUnk_00.mUnk_10.y < 0x4000) {
            p->mUnk_00.mStateMachine.mNextState = 2;
            p->mUnk_00.mStateMachine.mNextStateRequested = 1;
            func_020d26f8(&p->mUnk_00, a);
        }
    }
    return *c;
}

u8 func_020dd1f4(Wanwan *p, void *a, u8 *b, u8 *c) {
    if (*b == 1) {
        if (p->mUnk_00.mStateMachine.mState != 2 || p->mUnk_00.mUnk_10.y < 0x4000) {
            p->mUnk_00.mStateMachine.mNextState = 2;
            p->mUnk_00.mStateMachine.mNextStateRequested = 1;
        }
    }
    return *c;
}

// Kind 0x196 only (kind 0x1a5 never reaches state 0).
void EnterWanwanState0(Wanwan *p) {
    Vec3 *q;

    p->mUnk_e8 = 0x555;
    p->mUnk_ec = 0x1c2;
    p->mUnk_1d8->mUnk_a8 = 0x599;
    q = p->mUnk_160[0];
    p->mUnk_160[0] = NULL;
    *p->mUnk_160[1] = p->mUnk_00.mPos;
    *p->mUnk_160[2] = *p->mUnk_160[1];
    p->mUnk_160[2]->x += (s32) (((s64) p->mUnk_00.mMatrix.mUnk_00[2].x * p->mUnk_f0) >> 12);
    p->mUnk_160[2]->z += (s32) (((s64) p->mUnk_00.mMatrix.mUnk_00[2].z * p->mUnk_f0) >> 12);
    *p->mUnk_160[3] = *p->mUnk_160[2];
    p->mUnk_160[3]->x += (s32) (((s64) p->mUnk_00.mMatrix.mUnk_00[0].x * p->mUnk_f0) >> 12);
    p->mUnk_160[3]->z += (s32) (((s64) p->mUnk_00.mMatrix.mUnk_00[0].z * p->mUnk_f0) >> 12);
    func_020d7d18(&p->mUnk_100, 1, p->mUnk_160, 0x1000);
    p->mUnk_160[0] = q;
}

static inline s64 func_020dccc8_inline(const Vec3 *v) {
    return (s64) v->x * v->x + (s64) v->z * v->z;
}

// Kind 0x196 only (kind 0x1a5 never reaches state 0).
void UpdateWanwanState0(Wanwan *p) {
    Vec3 *q;
    Vec3 *c;
    Unk020f41c4_B *r;
    Kart *o;
    s32 j;
    s32 dz;
    s32 dx;
    s32 a;
    u32 n;
    s32 v;
    s32 d;
    s32 xp;
    s32 zp;
    s32 g;
    s32 e;
    u32 i;
    u16 u;

    p->mUnk_00.mUnk_10.x = p->mUnk_00.mPos.x;
    p->mUnk_00.mUnk_10.z = p->mUnk_00.mPos.z;
    if (func_020d849c(&p->mUnk_100) != FALSE) {
        dx = p->mUnk_160[3]->x - p->mUnk_160[2]->x;
        dz = p->mUnk_160[3]->z - p->mUnk_160[2]->z;
        do {
            j = 0;
            q = p->mUnk_160[0];
            while (1) {
                a = p->mUnk_f8;
                r = func_020d22d0();
                n = a - 0x2d000;
                if (n == 0) {
                    v = 0;
                } else {
                    r->mUnk_00 = r->mUnk_08 * r->mUnk_00 + r->mUnk_10;
                    if (n == 0) {
                        v = (u32) (r->mUnk_00 >> 32);
                    } else {
                        v = (u32) (((u64) (r->mUnk_00 >> 32) * (u64) n) >> 32);
                    }
                }
                r = func_020d22d0();
                d = v + 0x2d000;
                r->mUnk_00 = r->mUnk_08 * r->mUnk_00 + r->mUnk_10;
                i = (u16) (((r->mUnk_00 >> 32) * 0x10000) >> 32) >> 4;
                j++;
                q->x = p->mUnk_a0.x + (s32) (((s64) gPairsByAngle[i * 2] * d) >> 12);
                q->z = p->mUnk_a0.z + (s32) (((s64) gPairsByAngle[i * 2 + 1] * d) >> 12);
                if (j > 5) {
                    break;
                }
                c = p->mUnk_160[3];
                xp = q->x - c->x;
                zp = q->z - c->z;
                if ((s64) (s32) xp * xp + (s64) (s32) zp * zp < 0x7e9000000LL) {
                    continue;
                }
                g = (s32) (((s64) xp * dx + (s64) zp * dz) >> 12);
                if (g < 0) {
                    g = -g;
                    e = (s32) ((-(s64) xp * dz + (s64) zp * dx) >> 12);
                    if (e < 0) {
                        e = -e;
                    }
                    if (g >> 2 >= e) {
                        continue;
                    }
                }
                break;
            }
            p->mUnk_160[0] = p->mUnk_160[1];
            p->mUnk_160[1] = p->mUnk_160[2];
            p->mUnk_160[2] = p->mUnk_160[3];
            p->mUnk_160[3] = q;
        } while (func_020d7c84(&p->mUnk_100, 1, p->mUnk_160) != FALSE);
    }
    func_020d8474(&p->mUnk_100, &p->mUnk_00.mPos);
    if (!(p->mUnk_00.mFlags & 0x800)) {
        u = GetRaceUpdateFramesModKartCount();
        o = GetKart(u);
        if (func_0206c0e0(o) == FALSE) {
            e = p->mUnk_1dc;
            if ((s64) (o->mPos.x - p->mUnk_a0.x) * (o->mPos.x - p->mUnk_a0.x) +
                    (s64) (o->mPos.z - p->mUnk_a0.z) * (o->mPos.z - p->mUnk_a0.z) <
                (s64) e * e) {
                p->mUnk_1f0 = &GetKart(u)->mPos;
                p->mUnk_1f4 = &GetKart(u)->mVelocity;
                p->mUnk_00.mStateMachine.mNextState = 1;
                p->mUnk_00.mStateMachine.mNextStateRequested = 1;
            }
        }
    }
    p->mUnk_00.mUnk_10.x = p->mUnk_00.mPos.x - p->mUnk_00.mUnk_10.x;
    p->mUnk_00.mUnk_10.z = p->mUnk_00.mPos.z - p->mUnk_00.mUnk_10.z;
    if (func_020dccc8_inline(&p->mUnk_00.mUnk_10) >= 0x10) {
        func_020d7b34(
            (u16) (((s64) FX_Atan2(p->mUnk_00.mUnk_10.x, p->mUnk_00.mUnk_10.z) * 0x28be60db9391LL + 0x80000000000LL) >>
                   44),
            &p->mUnk_d4);
    }
    if (p->mUnk_00.mStateMachine.mStateFrames < 0x40) {
        p->mUnk_ec += 0x1c;
    }
}

void EnterWanwanState1(Wanwan *p) {
    Unk0210b7a8 a;
    s32 k;

    p->mUnk_e8 = 0x2000;
    p->mUnk_ec = 0x1c2;
    p->mUnk_1e0 = p->mUnk_00.mPos;
    p->mUnk_1d8->mUnk_a8 = 0x219;
    p->mUnk_1f8 = 0;
    if (p->mUnk_00.mDistanceSquaredAndFlags & 4) {
        return;
    }
    if (p->mUnk_00.mFarDistanceSquared == gSoundFalloffs[2].mUnk_20) {
        k = 2;
    } else if (p->mUnk_00.mFarDistanceSquared == gSoundFalloffs[3].mUnk_20) {
        k = 3;
    } else {
        k = 4;
    }
    a.mUnk_00 = 0x12c;
    a.mUnk_04 = &p->mUnk_00.mPos;
    a.mUnk_08 = k;
    a.mUnk_0c = func_020d4ef4(&p->mUnk_00.mPos);
    func_0210b7a8(&a);
}

void UpdateWanwanState1(Wanwan *p) {
    Vec3 a;
    Vec3 b;
    s32 t;
    s32 k;
    s32 m;

    if (p->mUnk_00.mStateMachine.mStateFrames > p->mUnk_1f8) {
        VEC_Subtract(p->mUnk_1f0, &p->mUnk_00.mPos, &a);
        t = (s32) (((s64) p->mUnk_1f4->x * a.z - (s64) p->mUnk_1f4->z * a.x) >> 12);
        t = -t >> 12;
        if (t < 0) {
            t = -t;
        }
        k = (s32) (((s64) t * 0x7a) >> 12);
        b.x = p->mUnk_1f4->x * k;
        b.z = p->mUnk_1f4->z * k;
        VEC_Add(&b, p->mUnk_1f0, &b);
        VEC_Subtract(&b, &p->mUnk_a0, &a);
        m = Vec3NormalizeXZAndGetLengthOrZero(&a, &a);
        if (m > p->mUnk_f0) {
            m -= p->mUnk_f0 >> 1;
        }
        if (m > p->mUnk_1ec) {
            m = p->mUnk_1ec;
        }
        a.x = (s32) (((s64) a.x * m) >> 12);
        a.y = (s32) (((s64) a.y * m) >> 12);
        a.z = (s32) (((s64) a.z * m) >> 12);
        VEC_Add(&a, &p->mUnk_a0, &p->mUnk_1e0);
        p->mUnk_1f8 += 0xb4;
    }
    VEC_Subtract(&p->mUnk_1e0, &p->mUnk_00.mPos, &a);
    p->mUnk_00.mUnk_10.x += (s32) (((s64) a.x << 5) >> 12);
    p->mUnk_00.mUnk_10.z += (s32) (((s64) a.z << 5) >> 12);
    if (func_020dccc8_inline(&p->mUnk_00.mUnk_10) >= 0x40000000) {
        p->mUnk_00.mUnk_10.x -= (s32) (((s64) p->mUnk_00.mUnk_10.x * 0x4cc) >> 12);
        p->mUnk_00.mUnk_10.z -= (s32) (((s64) p->mUnk_00.mUnk_10.z * 0x4cc) >> 12);
    }
    if (func_020dccc8_inline(&a) < (s64) (p->mUnk_f0 >> 1) * (p->mUnk_f0 >> 1)) {
        p->mUnk_00.mUnk_10.x >>= 1;
        p->mUnk_00.mUnk_10.z >>= 1;
    } else {
        func_020d7b34((u16) (((s64) FX_Atan2(a.x, a.z) * 0x28be60db9391LL + 0x80000000000LL) >> 44), &p->mUnk_d4);
    }
    t = (s32) (((s64) p->mUnk_00.mUnk_10.x * a.z) >> 12);
    t -= (s32) (((s64) p->mUnk_00.mUnk_10.z * a.x) >> 12);
    if (((s64) a.x * a.x + (s64) a.z * a.z) * 10 < (s64) t * t) {
        p->mUnk_00.mUnk_10.x >>= 1;
        p->mUnk_00.mUnk_10.z >>= 1;
    }
    p->mUnk_00.mPos.x += p->mUnk_00.mUnk_10.x;
    p->mUnk_00.mPos.z += p->mUnk_00.mUnk_10.z;
    VEC_Subtract(&p->mUnk_00.mPos, &p->mUnk_a0, &a);
    if ((s64) a.x * a.x + (s64) a.z * a.z >= (s64) p->mUnk_1ec * p->mUnk_1ec) {
        Vec3NormalizeXZAndGetLengthOrZero(&a, &a);
        p->mUnk_00.mPos.x = p->mUnk_a0.x + (s32) (((s64) a.x * p->mUnk_1ec) >> 12);
        p->mUnk_00.mPos.z = p->mUnk_a0.z + (s32) (((s64) a.z * p->mUnk_1ec) >> 12);
        k = (s32) (((s64) p->mUnk_00.mUnk_10.x * a.x) >> 12);
        m = (s32) (((s64) p->mUnk_00.mUnk_10.z * a.z) >> 12);
        if (k + m > 0) {
            p->mUnk_00.mUnk_10.x -= (s32) (((s64) k * a.x) >> 12);
            p->mUnk_00.mUnk_10.z -= (s32) (((s64) m * a.z) >> 12);
        }
    }
    if (p->mUnk_00.mStateMachine.mStateFrames >= 0xb4) {
        p->mUnk_00.mStateMachine.mNextState = 3;
        p->mUnk_00.mStateMachine.mNextStateRequested = 1;
    }
}

void EnterWanwanState2(Wanwan *p) {
    p->mUnk_e8 = 0xd000;
    p->mUnk_ec = 0x1c2;
    if (p->mUnk_fc == 0) {
        p->mUnk_1d8->mUnk_a8 = 0x219;
    }
    p->mUnk_00.mUnk_10.y = 0x8000;
}

void UpdateWanwanState2(Wanwan *p) {
    const Vec3 *v;

    if (p->mUnk_fc != 0) {
        p->mUnk_00.mUnk_10.x = p->mUnk_00.mPos.x;
        p->mUnk_00.mUnk_10.z = p->mUnk_00.mPos.z;
        func_020d84e4(&p->mUnk_1a0);
        func_020d8b88(&p->mUnk_1a0.mUnk_00, &p->mUnk_00.mPos);
        p->mUnk_00.mUnk_10.x = p->mUnk_00.mPos.x - p->mUnk_00.mUnk_10.x;
        p->mUnk_00.mUnk_10.z = p->mUnk_00.mPos.z - p->mUnk_00.mUnk_10.z;
        v = &p->mUnk_00.mUnk_10;
        if ((s64) v->x * v->x + (s64) v->z * v->z >= 0x10) {
            func_020d7b34((u16) (((s64) FX_Atan2(p->mUnk_00.mUnk_10.x, p->mUnk_00.mUnk_10.z) * 0x28be60db9391LL +
                                  0x80000000000LL) >>
                                 44),
                          &p->mUnk_d4);
        }
        if (p->mUnk_00.mStateMachine.mStateFrames < 0x40) {
            p->mUnk_ec += 0x1c;
        }
        if (p->mUnk_00.mStateMachine.mStateFrames >= 0x28) {
            p->mUnk_e8 += 0x200;
        } else {
            p->mUnk_00.mUnk_10.y -= 0x266;
        }
        if (p->mUnk_e8 > 0x10555) {
            p->mUnk_00.mStateMachine.mNextState = 5;
            p->mUnk_00.mStateMachine.mNextStateRequested = 1;
        }
    } else {
        if (p->mUnk_e8 == 0xd000) {
            p->mUnk_00.mUnk_10.y -= 0x19a;
        }
        if (p->mUnk_00.mStateMachine.mStateFrames >= 0x78) {
            p->mUnk_e8 += 0x100;
        }
        if (p->mUnk_e8 > 0x10555) {
            p->mUnk_00.mStateMachine.mNextState = 3;
            p->mUnk_00.mStateMachine.mNextStateRequested = 1;
        }
    }
}

void EnterWanwanState3(Wanwan *p) {
    p->mUnk_e8 = 0x555;
    p->mUnk_ec = 0x1c2;
    p->mUnk_1d8->mUnk_a8 = 0x599;
}

static inline s64 func_020dc474_inline(const Vec3 *v) {
    return (s64) v->x * v->x + (s64) v->z * v->z;
}

void UpdateWanwanState3(Wanwan *p) {
    Vec3 a;
    s32 k;

    k = p->mUnk_1fc;
    if ((s64) (p->mUnk_00.mPos.x - p->mUnk_a0.x) * (p->mUnk_00.mPos.x - p->mUnk_a0.x) +
            (s64) (p->mUnk_00.mPos.z - p->mUnk_a0.z) * (p->mUnk_00.mPos.z - p->mUnk_a0.z) >=
        (s64) k * k) {
        VEC_Subtract(&p->mUnk_a0, &p->mUnk_00.mPos, &a);
        p->mUnk_00.mUnk_10.x += (s32) (((s64) a.x << 2) >> 12);
        p->mUnk_00.mUnk_10.z += (s32) (((s64) a.z << 2) >> 12);
        if (func_020dc474_inline(&p->mUnk_00.mUnk_10) >= 0x1000000) {
            p->mUnk_00.mUnk_10.x -= (s32) (((s64) p->mUnk_00.mUnk_10.x * 0x199) >> 12);
            p->mUnk_00.mUnk_10.z -= (s32) (((s64) p->mUnk_00.mUnk_10.z * 0x199) >> 12);
        }
        p->mUnk_00.mPos.x += p->mUnk_00.mUnk_10.x;
        p->mUnk_00.mPos.z += p->mUnk_00.mUnk_10.z;
    }
    if (p->mUnk_00.mStateMachine.mStateFrames >= 0xb4) {
        p->mUnk_00.mStateMachine.mNextState = 0;
        p->mUnk_00.mStateMachine.mNextStateRequested = 1;
    }
}

void EnterWanwanState4(Wanwan *p) {
    p->mUnk_e8 = 0x555;
    p->mUnk_ec = 0x1c2;
    p->mUnk_1d8->mUnk_a8 = 0x599;
}

void func_020dc444(Wanwan *p) {}

void EnterWanwanState5(Wanwan *p) {
    p->mUnk_e8 = 0x555;
    p->mUnk_ec = 0x1c2;
}
