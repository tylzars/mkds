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

BOOL func_020f14a0(Unk020f5d6c *a, s32 b, s32 c, s32 d) {
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
    p = &a->mUnk_000.mUnk_000.mUnk_000.mUnk_50;
    q = &a->mUnk_000.mUnk_000.mUnk_000.mUnk_5c;
    if ((a->mUnk_000.mUnk_000.mUnk_000.mUnk_48 & 1) == func_02061f7c()) {
        v = a->mUnk_228->mUnk_1fc;
        if (!(a->mUnk_000.mUnk_000.mUnk_000.mUnk_74 & 0x20000)) {
            if (func_0206c0e0(v) != FALSE) {
                b >>= 1;
            }
            Vec3Sub(&v->mUnk_98, p, &t);
            t.y = func_02039828(&a->mUnk_000.mUnk_000.mUnk_000.mUnk_f0, &t) >> 12;
            if (t.y * t.y > 0xbd1) {
                if ((s64) t.x * t.x + (s64) t.z * t.z < (s64) 0xe1000000u) {
                    r = TRUE;
                }
            }
            n = 0;
            t.y = 0;
            if ((s64) t.x * t.x + (s64) t.y * t.y + (s64) t.z * t.z >= 0x10) {
                n = func_02039860(&t, &t);
            }
            t.x = (s32) (((s64) t.x * b) >> 12);
            t.y = (s32) (((s64) t.y * b) >> 12);
            t.z = (s32) (((s64) t.z * b) >> 12);
            if (a->mUnk_000.mUnk_000.mUnk_000.mUnk_74 & 0x8000000) {
                if (n < (s32) (((s64) v->mUnk_2cc->mUnk_00 * v->mUnk_bc.z + 0x800) >> 12)) {
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
            Vec3Sub(&t, &a->mUnk_22c, &t);
            if (0x64000 - n > 0) {
                c += (s32) (((s64) (0x64000 - n) * 16) >> 12);
            }
            t.x = (s32) (((s64) t.x * c) >> 12);
            t.y = (s32) (((s64) t.y * c) >> 12);
            t.z = (s32) (((s64) t.z * c) >> 12);
            Vec3Add(&a->mUnk_22c, &t, &a->mUnk_22c);
            Vec3Sub(&a->mUnk_228->mUnk_1fc->mVelocity, q, &t);
            t.y = 0;
            t.x = (s32) (((s64) t.x * c) >> 12);
            t.y = (s32) (((s64) t.y * c) >> 12);
            t.z = (s32) (((s64) t.z * c) >> 12);
            Vec3Add(q, &t, q);
        }
    }
    a->mUnk_228->mUnk_208 = TRUE;
    Vec3Add(&a->mUnk_22c, p, p);
    Vec3Add(q, p, p);
    if (func_01ffdee4(&p->x, (u32 *) &a->mUnk_000.mUnk_000.mUnk_000.mUnk_0e4, 0, a->mUnk_000.mUnk_000.mUnk_000.mUnk_dc,
                      4, a->mUnk_000.mUnk_000.mUnk_000.mUnk_da, &t, &u, (s32 *) &w,
                      &a->mUnk_000.mUnk_000.mUnk_000.mUnk_fc, NULL, NULL, NULL, NULL) != 0) {
        Vec3Add(&t, p, p);
        if (a->mUnk_000.mUnk_000.mUnk_000.mUnk_fc & 0x1e34ef) {
            n = Vec3Dot(&u, q);
            q->x = q->x - (s32) (((s64) u.x * n) >> 12);
            q->y = q->y - (s32) (((s64) u.y * n) >> 12);
            q->z = q->z - (s32) (((s64) u.z * n) >> 12);
            e = (u.x == a->mUnk_000.mUnk_000.mUnk_000.mUnk_f0.x && u.y == a->mUnk_000.mUnk_000.mUnk_000.mUnk_f0.y &&
                 u.z == a->mUnk_000.mUnk_000.mUnk_000.mUnk_f0.z);
            if (e == FALSE) {
                a->mUnk_000.mUnk_000.mUnk_000.mUnk_f0 = u;
                a->mUnk_000.mUnk_000.mUnk_000.mUnk_74 |= 0x100;
            }
        }
        if (a->mUnk_000.mUnk_000.mUnk_000.mUnk_fc & 0x214300) {
            if (a->mUnk_000.mUnk_000.mUnk_158 == 0 && d != 0) {
                n = Vec3Dot(&w, q);
                t.x = (s32) (((s64) w.x * n) >> 12);
                t.y = (s32) (((s64) w.y * n) >> 12);
                t.z = (s32) (((s64) w.z * n) >> 12);
                q->x = q->x - t.x;
                q->y = q->y - t.y;
                q->z = q->z - t.z;
                Vec3Sub(q, &t, q);
                q->x = (s32) (((s64) q->x * 0x23d) >> 12);
                q->y = (s32) (((s64) q->y * 0x23d) >> 12);
                q->z = (s32) (((s64) q->z * 0x23d) >> 12);
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

int func_020f1258(int a0, int i, s32 c, u32 b) {
    Unk020f5d6c *a;
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

    a = (Unk020f5d6c *) a0;
    p = GetKart(i);
    x = (u16) (!(a->mUnk_000.mUnk_000.mUnk_000.mUnk_78 & 0x8000)
                   ? (u16) (a->mUnk_000.mUnk_000.mUnk_000.mUnk_78 & ~0xff00)
                   : 8);
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
    if ((p->mUnk_7c & 0x402020) || (p->mUnk_4c & 0x800) || (n != 1 && p->mState != 0)) {
        return 0;
    }
    func_0207a948(&v, i);
    Vec3Sub(&v, &a->mUnk_000.mUnk_000.mUnk_000.mUnk_50, &v);
    d = (v.x >> 12) * (v.x >> 12);
    d += (v.z >> 12) * (v.z >> 12);
    if (d > 0x27100 || (c != 0 && d > c)) {
        return 0;
    }
    dot = func_02039828(&a->mUnk_000.mUnk_000.mUnk_000.mUnk_5c, &v);
    if (dot < 0) {
        return 0;
    }
    vv = func_02039828(&v, &v) >> 12;
    ww = func_02039828(&a->mUnk_000.mUnk_000.mUnk_000.mUnk_5c, &a->mUnk_000.mUnk_000.mUnk_000.mUnk_5c);
    t2 = (s64) ww * vv;
    t1 = (s64) dot * (dot >> 12);
    if ((s32) (t1 >> 12) < (s32) (((s64) (s32) (t2 >> 12) * 0x400) >> 12)) {
        return 0;
    }
    dot = func_02039828(&a->mUnk_000.mUnk_000.mUnk_000.mUnk_f0, &v);
    if ((dot >> 12) * (dot >> 12) > 0x9c4) {
        return 0;
    }
    if (a->mUnk_000.mUnk_000.mUnk_000.mUnk_74 & 0x10000000) {
        return 0;
    }
    a->mUnk_228 = &data_027e00c8[i];
    a->mUnk_22c.x = 0;
    a->mUnk_22c.y = 0;
    a->mUnk_22c.z = 0;
    a->mUnk_238 = 0;
    return d;
}
