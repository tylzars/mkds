#include "Main/Unknown/code_020f1258.h"

#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020f49bc.h"
#include "Main/Unknown/code_020f6000.h"
#include "Main/Unknown/code_020f6be8.h"
#include "Main/Unknown/code_020f7000.h"
#include "Main/Unknown/unk_027e0000.h"
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
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_02061654.h"
#include "ITCM/code_01ffd000.h"
#include "Main/Unknown/code_020f1d70.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/code_0203c8dc.h"
#include "Main/Unknown/code_02077bc0.h"

BOOL func_020f14a0(ItemKouraR *a, s32 b, s32 c, s32 d) {
    Vec3 t;
    Vec3 u;
    Vec3 w;
    s32 n;
    BOOL e;
    Vec3 *p;
    Vec3 *q;
    Kart *v;
    BOOL r;

    r = FALSE;
    p = &a->mUnk_000.mUnk_000.mUnk_000.mPos;
    q = &a->mUnk_000.mUnk_000.mUnk_000.mVelocity;
    if ((a->mUnk_000.mUnk_000.mUnk_000.mUnk_48 & 1) == GetRaceUpdateFramesMod2()) {
        v = a->mKartItems->mKart;
        if (!(a->mUnk_000.mUnk_000.mUnk_000.mFlags & 0x20000)) {
            if (func_0206c0e0(v) != FALSE) {
                b >>= 1;
            }
            VEC_Subtract(&v->mDrawMatrixPos, p, &t);
            t.y = Vec3DotUnrounded(&a->mUnk_000.mUnk_000.mUnk_000.mUnk_f0, &t) >> 12;
            if (t.y * t.y > 0xbd1) {
                if ((s64) t.x * t.x + (s64) t.z * t.z < (s64) 0xe1000000u) {
                    r = TRUE;
                }
            }
            n = 0;
            t.y = 0;
            if ((s64) t.x * t.x + (s64) t.y * t.y + (s64) t.z * t.z >= 0x10) {
                n = Vec3NormalizeAndGetLengthUnchecked(&t, &t);
            }
            t.x = ((s64) t.x * b) >> 12;
            t.y = ((s64) t.y * b) >> 12;
            t.z = ((s64) t.z * b) >> 12;
            if (a->mUnk_000.mUnk_000.mUnk_000.mFlags & 0x8000000) {
                if (n < (s32) (((s64) v->mPhysicalParam->mRadius * v->mScale.z + 0x800) >> 12)) {
                    a->mUnk_238 = a->mUnk_238 + 1;
                    if (a->mUnk_238 > 0x5a) {
                        func_020f7070(a, 1);
                        return FALSE;
                    }
                    t.x = 0;
                    t.y = 0;
                    t.z = 0;
                }
            }
            VEC_Subtract(&t, &a->mUnk_22c, &t);
            if (0x64000 - n > 0) {
                c += (s32) (((s64) (0x64000 - n) * 16) >> 12);
            }
            t.x = ((s64) t.x * c) >> 12;
            t.y = ((s64) t.y * c) >> 12;
            t.z = ((s64) t.z * c) >> 12;
            VEC_Add(&a->mUnk_22c, &t, &a->mUnk_22c);
            VEC_Subtract(&a->mKartItems->mKart->mVelocity, q, &t);
            t.y = 0;
            t.x = ((s64) t.x * c) >> 12;
            t.y = ((s64) t.y * c) >> 12;
            t.z = ((s64) t.z * c) >> 12;
            VEC_Add(q, &t, q);
        }
    }
    a->mKartItems->mUnk_208 = TRUE;
    VEC_Add(&a->mUnk_22c, p, p);
    VEC_Add(q, p, p);
    if (func_01ffdee4(&p->x, (u32 *) &a->mUnk_000.mUnk_000.mUnk_000.mPrevPos, 0, a->mUnk_000.mUnk_000.mUnk_000.mUnk_dc,
                      4, a->mUnk_000.mUnk_000.mUnk_000.mCollisionSlotIndex, &t, &u, (s32 *) &w,
                      &a->mUnk_000.mUnk_000.mUnk_000.mUnk_fc, NULL, NULL, NULL, NULL) != 0) {
        VEC_Add(&t, p, p);
        if (a->mUnk_000.mUnk_000.mUnk_000.mUnk_fc & 0x1e34ef) {
            n = VEC_DotProduct(&u, q);
            q->x = q->x - (s32) (((s64) u.x * n) >> 12);
            q->y = q->y - (s32) (((s64) u.y * n) >> 12);
            q->z = q->z - (s32) (((s64) u.z * n) >> 12);
            e = (u.x == a->mUnk_000.mUnk_000.mUnk_000.mUnk_f0.x && u.y == a->mUnk_000.mUnk_000.mUnk_000.mUnk_f0.y &&
                 u.z == a->mUnk_000.mUnk_000.mUnk_000.mUnk_f0.z);
            if (e == FALSE) {
                a->mUnk_000.mUnk_000.mUnk_000.mUnk_f0 = u;
                a->mUnk_000.mUnk_000.mUnk_000.mFlags |= 0x100;
            }
        }
        if (a->mUnk_000.mUnk_000.mUnk_000.mUnk_fc & 0x214300) {
            if (a->mUnk_000.mUnk_000.mUnk_158 == 0 && d != 0) {
                n = VEC_DotProduct(&w, q);
                t.x = ((s64) w.x * n) >> 12;
                t.y = ((s64) w.y * n) >> 12;
                t.z = ((s64) w.z * n) >> 12;
                q->x = q->x - t.x;
                q->y = q->y - t.y;
                q->z = q->z - t.z;
                VEC_Subtract(q, &t, q);
                q->x = ((s64) q->x * 0x23d) >> 12;
                q->y = ((s64) q->y * 0x23d) >> 12;
                q->z = ((s64) q->z * 0x23d) >> 12;
                func_020f6fc4(a, 1);
                return FALSE;
            }
        }
        if (a->mUnk_000.mUnk_000.mUnk_000.mUnk_fc & 0x8000) {
            func_020f7070(a, 1);
            return FALSE;
        }
    }
    func_020f2028(&a->mUnk_000.mUnk_000.mUnk_000);
    return r;
}

int func_020f1258(ItemKouraR *a, int i, s32 c, u32 b) {
    u16 x;
    Kart *p;
    u32 n;
    s32 t;
    Vec3 v;
    s32 d;
    s32 dot;
    s32 vv;
    s32 ww;
    s64 t1;
    s64 t2;

    p = GetKart(i);
    x = !(a->mUnk_000.mUnk_000.mUnk_000.mUnk_78 & 0x8000) ? (u16) (a->mUnk_000.mUnk_000.mUnk_000.mUnk_78 & ~0xff00) : 8;
    n = GetKartRank(i);
    if (x < 8 && b != 0) {
        t = GetKartRank(x);
        if (t <= n) {
            if (t != 1) {
                return 0;
            }
            if (n > 3) {
                return 0;
            }
        }
    }
    if ((p->mUnk_7c & 0x402020) || (p->mUnk_4c & 0x800) || (n != 1 && p->mState != KART_STATE_NORMAL)) {
        return 0;
    }
    GetKartPos(&v, i);
    VEC_Subtract(&v, &a->mUnk_000.mUnk_000.mUnk_000.mPos, &v);
    d = (v.x >> 12) * (v.x >> 12);
    d += (v.z >> 12) * (v.z >> 12);
    if (d > 0x27100 || (c != 0 && d > c)) {
        return 0;
    }
    dot = Vec3DotUnrounded(&a->mUnk_000.mUnk_000.mUnk_000.mVelocity, &v);
    if (dot < 0) {
        return 0;
    }
    vv = Vec3DotUnrounded(&v, &v) >> 12;
    ww = Vec3DotUnrounded(&a->mUnk_000.mUnk_000.mUnk_000.mVelocity, &a->mUnk_000.mUnk_000.mUnk_000.mVelocity);
    t2 = (s64) ww * vv;
    t1 = (s64) dot * (dot >> 12);
    if ((s32) (t1 >> 12) < (s32) (((s64) (s32) (t2 >> 12) * 0x400) >> 12)) {
        return 0;
    }
    dot = Vec3DotUnrounded(&a->mUnk_000.mUnk_000.mUnk_000.mUnk_f0, &v);
    if ((dot >> 12) * (dot >> 12) > 0x9c4) {
        return 0;
    }
    if (a->mUnk_000.mUnk_000.mUnk_000.mFlags & 0x10000000) {
        return 0;
    }
    a->mKartItems = &gKartItems[i];
    a->mUnk_22c.x = 0;
    a->mUnk_22c.y = 0;
    a->mUnk_22c.z = 0;
    a->mUnk_238 = 0;
    return d;
}
