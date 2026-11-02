#include "Main/Unknown/code_020f2dac.h"

#include "Main/Unknown/code_020ed5c0.h"
#include "Main/Unknown/code_020f7000.h"
#include "Main/Unknown/code_020f9000.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "ITCM/code_01ffd000.h"
#include "Main/Unknown/code_020f92e8.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_02039860.h"
#include "code_02147cd8.h"

#pragma thumb on

void func_020f357c(void) {
    Unk020f371c *e;
    Vec3 v;
    u32 n;
    u16 i;

    n = gCourseMap->mUnk_58;
    e = gCourseMap->mUnk_ac;
    i = 0;
    for (i = 0; i < 4; i++) {
        data_0217bc38[i] = 0;
    }
    for (i = 0; i < n; i++, e++) {
        if (e->mUnk_1c >= 0x3e8000) {
            data_0217bc38[e->mUnk_20] = (s32) e;
        }
    }
    e = gCourseMap->mUnk_ac;
    for (i = 0; i < n; i++, e++) {
        func_021484d0(e->mUnk_00[0]->mUnk_18, e->mUnk_18, &v);
        if ((s64) v.x * v.x + (s64) v.y * v.y + (s64) v.z * v.z >= 0x10) {
            func_02039860(&v, &v);
        }
        e->mUnk_21 = v.x >> 6;
        e->mUnk_22 = v.y >> 6;
        e->mUnk_23 = v.z >> 6;
    }
}

#pragma thumb off

static inline u32 func_020f3150_inline(Unk020f41c4_B *x, u32 n) {
    x->mUnk_00 = x->mUnk_08 * x->mUnk_00 + x->mUnk_10;
    return (u32) (((u64) (u32) (x->mUnk_00 >> 32) * n) >> 32);
}

void func_020f3150(Unk020f2df0 *p, Unk020eda5c *a, s32 b, s32 c, s32 d, s32 e, s32 f) {
    Vec3 v;
    s32 n;
    s32 m;
    Vec3 *u;
    s32 dx;
    s32 dy;
    s32 dz;

    n = func_02039828((const Vec3 *) &a->mUnk_06c, (const Vec3 *) &a->mUnk_02c.mUnk_18);
    m = (a->mUnk_010->mUnk_48 & 1) != 0;
    n = (s32) (((s64) n * 0x1ec) >> 12);
    if (n < 0x666) {
        n = 0x666;
    }
    if (c != 0) {
        n = func_020edc9c(a, d, 0x1b33, 0x7000, &v);
    } else {
        n = func_020edb8c(a, n, 0x1000, 0x7000, &v);
    }
    if (c != 0) {
        if (a->mUnk_07c > 0) {
            n += (s32) (((s64) a->mUnk_07c * 0x14cd) >> 12);
        }
    }
    if (a->mUnk_068 < 0x3000) {
        v.z += func_020f3150_inline(&data_0217561c->mUnk_47c, 0xf6) - 0x7b;
        v.x += func_020f3150_inline(&data_0217561c->mUnk_47c, 0xf6) - 0x7b;
    }
    v.x = (s32) (((s64) v.x * n) >> 12);
    v.y = (s32) (((s64) v.y * n) >> 12);
    v.z = (s32) (((s64) v.z * n) >> 12);
    if (!m) {
        if (c != 0) {
            n = e + (s32) (((s64) a->mUnk_068 * 0x200) >> 12) + (s32) (((s64) a->mUnk_06c.y * 0x2000) >> 12);
        } else {
            n = f;
            dx = a->mUnk_06c.y > 0 ? 0x666 : 0x1333;
            n += (s32) (((s64) dx * a->mUnk_06c.y) >> 12);
        }
        func_02147fd8(n, (const Vec3 *) &a->mUnk_02c.mUnk_0c, &v, &p->mUnk_000.mUnk_5c);
    }
    if (c == 0) {
        func_02148504(&p->mUnk_000.mUnk_5c, &a->mUnk_010->mUnk_1fc, &p->mUnk_000.mUnk_5c);
    }
    if (c != 0) {
        p->mUnk_000.mUnk_50 = a->mUnk_010->mUnk_1b8;
        func_02147fd8(p->mUnk_000.mUnk_68.z * 10, (const Vec3 *) &a->mUnk_02c.mUnk_18, &p->mUnk_000.mUnk_50,
                      &p->mUnk_000.mUnk_50);
    } else {
        if (a->mUnk_07c != 0 && a->mUnk_068 < 0x2000 && p->mUnk_000.mUnk_68.z < 0xccd) {
            func_021484d0((const Vec3 *) &a->mUnk_02c.mUnk_0c, (const Vec3 *) &a->mUnk_02c.mUnk_18, &v);
            func_02147fd8(0x2000, &v, &p->mUnk_000.mUnk_50, &p->mUnk_000.mUnk_50);
        }
    }
    if (p->mUnk_000.mUnk_68.z < 0xccd) {
        u = &p->mUnk_000.mUnk_68;
        u->x = 0xccd;
        u->y = 0xccd;
        u->z = 0xccd;
    }
    p->mUnk_12c = b;
    p->mUnk_000.mUnk_124 = func_020f2dac;
    p->mUnk_000.mUnk_74 &= ~0x7000000;
    if (!m) {
        return;
    }
    n = func_0214848c((const Vec3 *) &a->mUnk_02c.mUnk_0c, &p->mUnk_000.mUnk_5c);
    dx = (s32) (((s64) a->mUnk_02c.mUnk_0c.x * n) >> 12);
    dy = (s32) (((s64) a->mUnk_02c.mUnk_0c.y * n) >> 12);
    dz = (s32) (((s64) a->mUnk_02c.mUnk_0c.z * n) >> 12);
    p->mUnk_000.mUnk_5c.x -= dx;
    p->mUnk_000.mUnk_5c.y -= dy;
    p->mUnk_000.mUnk_5c.z -= dz;
    func_02147fd8(c != 0 ? 0x8800 : -0x1000, (const Vec3 *) &a->mUnk_02c.mUnk_0c, &p->mUnk_000.mUnk_5c,
                  &p->mUnk_000.mUnk_5c);
    p->mUnk_12c = 0;
}

void func_020f30ec(Unk020f2df0 *a, s32 b, Vec3 *c) {
    if (c != 0) {
        a->mUnk_000.mUnk_5c = *c;
    }
    if (a->mUnk_000.mUnk_68.z < 0xccd) {
        a->mUnk_000.mUnk_68.x = 0xccd;
        a->mUnk_000.mUnk_68.y = 0xccd;
        a->mUnk_000.mUnk_68.z = 0xccd;
    }
    a->mUnk_12c = b;
    a->mUnk_000.mUnk_124 = func_020f2dac;
    a->mUnk_000.mUnk_74 &= ~0x7000000;
}

void func_020f2df0(Unk020f2df0 *a, s32 b, s32 c, s32 d, u32 *e) {
    Vec3 t;
    Vec3 u;
    Vec3 v;
    Vec3 *p;
    Vec3 *q;
    s32 n;

    p = &a->mUnk_000.mUnk_5c;
    q = &a->mUnk_000.mUnk_50;
    func_02148504(p, q, q);
    p->x = (s32) (((s64) p->x * c) >> 12);
    p->y = (s32) (((s64) p->y * c) >> 12);
    p->z = (s32) (((s64) p->z * c) >> 12);
    if (func_01ffdee4((int *) q, (u32 *) &a->mUnk_000.mUnk_0e4, 0, a->mUnk_000.mUnk_dc, 0x24, a->mUnk_000.mUnk_da,
                      (int *) &t, (int *) &u, (int *) &v, &a->mUnk_000.mUnk_fc, (u32 *) 0, (int *) 0, (u16 *) 0,
                      e) != 0) {
        func_02148504(&t, q, q);
        if (a->mUnk_000.mUnk_fc & 0x1e34ef) {
            n = a->mUnk_12c;
            a->mUnk_12c = n - 1;
            if (n <= 0) {
                func_020f9334(a, q, p, b, &u);
            } else {
                a->mUnk_000.mUnk_74 |= 0x10;
                n = func_0214848c(&u, p);
                t.x = (s32) (((s64) u.x * n) >> 12);
                t.y = (s32) (((s64) u.y * n) >> 12);
                t.z = (s32) (((s64) u.z * n) >> 12);
                p->x -= t.x;
                p->y -= t.y;
                p->z -= t.z;
                p->x = (s32) (((s64) p->x * 0x8cd) >> 12);
                p->y = (s32) (((s64) p->y * 0x8cd) >> 12);
                p->z = (s32) (((s64) p->z * 0x8cd) >> 12);
                func_02147fd8(-d, &t, p, p);
                a->mUnk_000.mUnk_f0 = u;
            }
        }
        if (a->mUnk_000.mUnk_fc & 0x214300) {
            a->mUnk_000.mUnk_74 |= 0x20;
            func_020f92e8((u32) p, (u32) &v);
            if (func_020f9290(a, &v) != 0) {
                return;
            }
            a->mUnk_000.mUnk_78 &= ~0x4000;
        }
        if (a->mUnk_000.mUnk_fc & 0x8000) {
            func_020f7070(a, 1);
            return;
        }
    }
    a->mUnk_000.mUnk_74 &= ~0x4000000;
    if (a->mUnk_000.mUnk_fc & 0x1e34ef) {
        return;
    }
    p->y -= b;
    if (p->y < -0xa000) {
        p->y = -0xa000;
    }
}

void func_020f2dac(Unk020f41c4_A *a, Vec3 *b, Vec3 *c) {
    func_020f92e8((u32) &a->mUnk_5c, (u32) c);
    if (a->mUnk_74 & 0x1000000) {
        return;
    }
    a->mUnk_74 |= 0x1000000;
    a->mUnk_108.x = 0;
    a->mUnk_108.y = 0;
    a->mUnk_108.z = 0;
}
