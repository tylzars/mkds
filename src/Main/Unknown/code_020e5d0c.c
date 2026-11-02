#include "Main/Unknown/code_020e5d0c.h"

#include "Main/Unknown/unk_02159000.h"
#include "Main/Unknown/unk_0216c000.h"
#include "Main/Unknown/code_020d7000.h"
#include "Main/Unknown/code_020ea514.h"
#include "Main/Unknown/code_020ea55c.h"
#include "Main/Unknown/code_020ea588.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_02087000.h"
#include "Main/Unknown/code_020ea000.h"
#include "ITCM/code_01ffc000.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_02084000.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_020d4000.h"
#include "Main/Unknown/code_020d49d8.h"
#include "Main/Unknown/code_020e6000.h"
#include "Main/Unknown/code_020e6f50.h"
#include "Main/Unknown/code_0210b000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/code_020e337c.h"

#pragma thumb on

// non-matching: n * 4 is computed before the func_020364e8 and func_020364e0 calls, and the 0xc00f0000 mask and the
// zero store are emitted before the loop pre-test; the original computes n * 4 after the two calls and puts the mask
// and the store after cmp/bls (5 words differ, first +0x58).
void func_020e6514(Unk020e52bc *param_1, Unk020e6514 *param_2, Unk020e6488 *p) {
    Unk020e52bc_4 *a;
    Unk020e52bc_8 *b;
    Unk020e52bc_c *c;
    Unk020e53ac *d;
    Unk020e54e4 *e;
    Unk020e6514_8 x;
    u16 n;
    u16 i;

    a = param_1->mUnk_004;
    b = (Unk020e52bc_8 *) &a->mUnk_000[a->mUnk_008];
    d = (Unk020e53ac *) &b->mUnk_000[((u32 *) &b->mUnk_000[b->mUnk_00a])[2]];
    c = (Unk020e52bc_c *) &a->mUnk_000[a->mUnk_00c];
    e = (Unk020e54e4 *) &c->mUnk_000[((u32 *) &c->mUnk_000[c->mUnk_006])[1]];
    p->mUnk_00 = (u32) &e->mUnk_000[e->mUnk_008];
    p->mUnk_04 = e->mUnk_00c;
    p->mUnk_08 = param_1->mUnk_004->mUnk_01c;
    p->mUnk_0c = d->mUnk_004;
    p->mUnk_10 = d->mUnk_008;
    p->mUnk_14 = d->mUnk_00c & 0xfffffff0;
    p->mUnk_18 = 0;
    if (param_2 != 0) {
        x.mUnk_00 = d->mUnk_014;
        n = (u16) (func_02087d0c(param_2) >> 12);
        p->mUnk_1a = n;
        p->mUnk_1c = func_02036bec(func_020364e0(func_020364e8()), n * 4);
        p->mUnk_20 = func_02036bec(func_020364e0(func_020364e8()), n * 4);
        x.mUnk_00 &= 0xc00f0000;
        x.mUnk_04 = 0;
        for (i = 0; i < n; i++) {
            param_2->mUnk_00c = i << 12;
            param_2->mUnk_1c[param_2->mUnk_1a]->mUnk_00 = param_2->mUnk_00c;
            func_02015b9c(&x.mUnk_08, param_2->mUnk_1c[0], x.mUnk_04);
            p->mUnk_1c[i] = x.mUnk_08.mUnk_10 & 0x3ff0ffff;
            p->mUnk_1c[i] |= x.mUnk_00;
            p->mUnk_20[i] = x.mUnk_08.mUnk_14;
        }
    } else {
        p->mUnk_1a = 1;
        p->mUnk_1c = func_02036bec(func_020364e0(func_020364e8()), 4);
        p->mUnk_20 = func_02036bec(func_020364e0(func_020364e8()), 4);
        p->mUnk_1c[0] = d->mUnk_014;
        p->mUnk_20[0] = d->mUnk_01c;
    }
}

void func_020e64b8(void *p, void *a, void *b, s32 c) {
    ((Unk020e6488 *) p)->mUnk_24 = func_02036bec(func_020364e0(func_020364e8()), 0x6c);
    func_02084e28(((Unk020e6488 *) p)->mUnk_24, a);
    if (b != 0) {
        ((Unk020e6488 *) p)->mUnk_28 = func_02036bec(func_020364e0(func_020364e8()), 0x38);
        func_020ea514(2, ((Unk020e6488 *) p)->mUnk_24, ((Unk020e6488 *) p)->mUnk_28, a, b);
    } else {
        ((Unk020e6488 *) p)->mUnk_28 = 0;
    }
    func_020e6514(((Unk020e6488 *) p)->mUnk_24, (Unk020e6514 *) ((Unk020e6488 *) p)->mUnk_28, (Unk020e6488 *) p);
}

void func_020e6488(Unk020e6488 **param_1, void *param_2, u32 param_3, u32 param_4) {
    *param_1 = func_02036bec(func_020364e0(func_020364e8()), 0x2c);
    func_020e64b8((void *) *param_1, param_2, (void *) param_3, param_4);
}

#pragma thumb off

Unk020e5a9c *func_020e6438(void) {
    Unk020e5a9c *p;
    p = func_02036bec(func_020364e0(func_020364e8()), 0x40);
    *p = *(Unk020e5a9c *) data_021592d0;
    return p;
}

Unk020e5a40 *func_020e63dc(void) {
    Unk020e5a40 *p;
    p = func_02036bec(func_020364e0(func_020364e8()), 0x2c);
    data_0217b840 = p;
    *p = *(Unk020e5a40 *) data_021592a4;
    func_020d49d8(&data_0217b840);
    return data_0217b840;
}

Unk020e59e4 *func_020e6380(void) {
    Unk020e59e4 *p;
    p = func_02036bec(func_020364e0(func_020364e8()), 0x28);
    data_0217b834 = p;
    *p = *(Unk020e59e4 *) data_0215927c;
    func_020e6f50(&data_0217b834);
    return data_0217b834;
}

void func_020e630c(u32 param_1, Unk020e5e24 *a, u32 param_3, u32 param_4) {
    a->mUnk_4c.x = a->mUnk_bc.x >> 4;
    a->mUnk_4c.y = a->mUnk_bc.y >> 4;
    a->mUnk_4c.z = a->mUnk_bc.z >> 4;
    func_020ea8a8(data_0217b838, &a->mUnk_28, &a->mUnk_1c, param_4);
    func_020ea868(data_0217b83c, &a->mUnk_c8, &a->mUnk_1c, param_4);
}

void func_020e61a8(u32 param_1, Unk020e5e24 *a) {
    u32 buf[4];
    Unk0210b7a8 s;
    u32 t;
    u16 v;
    s32 n;

    t = a->mUnk_100;
    a->mUnk_100 = t + a->mUnk_fe;
    v = (u16) (((s64) (s32) a->mUnk_fc * data_0215d4b4[(a->mUnk_100 >> 4) * 2]) >> 12);
    if ((t < 0x58f0 && a->mUnk_100 >= 0x58f0) || (t < 0xd8f0 && a->mUnk_100 >= 0xd8f0)) {
        if ((a->mUnk_78 & 4) == 0) {
            if (a->mUnk_70 == data_0217ca6c[2].mUnk_20) {
                n = 2;
            } else if (a->mUnk_70 == data_0217ca6c[3].mUnk_20) {
                n = 3;
            } else {
                n = 4;
            }
            s.mUnk_00 = 0x173;
            s.mUnk_04 = &a->mUnk_04;
            s.mUnk_08 = n;
            s.mUnk_0c = func_020d4ef4(&a->mUnk_04);
            func_0210b7a8(&s);
        }
    }
    func_020d7734(a->mUnk_a0, v, buf);
    func_01ffccd0((int *) &a->mUnk_28, (void *) buf);
    func_02147fd8(-a->mUnk_f8, &a->mUnk_28.mUnk_0c, &a->mUnk_bc, &a->mUnk_04);
    a->mUnk_ec.x = a->mUnk_04.x >> 4;
    a->mUnk_ec.y = a->mUnk_04.y >> 4;
    a->mUnk_ec.z = a->mUnk_04.z >> 4;
    func_021484d0(&a->mUnk_04, &a->mUnk_b0, &a->mUnk_10);
    a->mUnk_b0 = a->mUnk_04;
}

// non-matching: register assignment at the top; the original holds a in r6, c in r4, out in r5 and t in r0, the
// compiled code a in r4, c in r5, out in r6 and t in r3.
s32 func_020e5fb4(Unk020e5e24 *a, Vec3 *b, s32 c, Vec3 *out) {
    Vec3 v;
    s32 r;
    s32 t;
    s32 t2;
    s64 sq;

    func_021484d0(b, &a->mUnk_04, &v);
    r = func_02039828(&v, &a->mUnk_28.mUnk_18);
    if (r > 0) {
        t = a->mUnk_108 + c - r;
        if (t < 0) {
            return 0;
        }
    } else {
        t = -(a->mUnk_108 + c + r);
        if (t > 0) {
            return 0;
        }
    }
    t2 = c + a->mUnk_104;
    sq = (s64) v.y * v.y;
    sq += (s64) v.x * v.x;
    sq += (s64) v.z * v.z;
    if (sq >= (s64) t2 * t2) {
        return 0;
    }
    *(volatile u16 *) 0x40002b0 = 1;
    *(volatile u32 *) 0x40002b8 = (u32) sq;
    *(volatile u32 *) 0x40002bc = (u32) (sq >> 32);
    while (*(volatile u16 *) 0x40002b0 & 0x8000) {
    }
    t2 = t2 - *(volatile u32 *) 0x40002b4;
    if ((t > 0 ? t : -t) < t2) {
        out->x = (s32) (((s64) a->mUnk_28.mUnk_18.x * t) >> 12);
        out->y = (s32) (((s64) a->mUnk_28.mUnk_18.y * t) >> 12);
        out->z = (s32) (((s64) a->mUnk_28.mUnk_18.z * t) >> 12);
        a->mUnk_10c = 0;
    } else {
        if (v.y < 0) {
            v.y = 0;
        }
        sq = (s64) v.y * v.y;
        sq += (s64) v.x * v.x;
        sq += (s64) v.z * v.z;
        if (sq >= 16) {
            func_02039860(&v, &v);
        }
        out->x = (s32) (((s64) v.x * t2) >> 12);
        out->y = (s32) (((s64) v.y * t2) >> 12);
        out->z = (s32) (((s64) v.z * t2) >> 12);
        a->mUnk_10c = 1;
    }
    return 1;
}

#pragma thumb on

void func_020e5f68(void) {
    func_020ea588((void **) &data_0217b838, (void *) FindCourseMapObjFile((const char *) data_0216c29c), 0);
    func_020ea55c((void **) &data_0217b83c, (void *) FindCourseMapObjFile((const char *) data_0216c2ac), 0x3f);
    func_02084968(data_0217b838, 0x3f, 2, 0x294a);
}

void func_020e5e24(Unk020e5e24 *p, Unk020e5e24_2 *q) {
    s32 m;

    p->mUnk_5c = (s32) (((s64) p->mUnk_98->mUnk_10 * q->mUnk_20) >> 12);
    func_020d720c(&q->mUnk_0c, p->mUnk_a0);
    p->mUnk_c8 = p->mUnk_28;
    p->mUnk_f8 = (s32) (((s64) p->mUnk_1c.y * 0x1f4000) >> 12);
    p->mUnk_100 = 0;
    p->mUnk_bc.x = q->mUnk_00.x;
    p->mUnk_bc.y = q->mUnk_00.y;
    p->mUnk_bc.z = q->mUnk_00.z;
    func_02147fd8(-p->mUnk_f8, &p->mUnk_28.mUnk_0c, &p->mUnk_bc, &p->mUnk_04);
    p->mUnk_b0 = p->mUnk_04;
    p->mUnk_ec.x = p->mUnk_04.x >> 4;
    p->mUnk_ec.y = p->mUnk_04.y >> 4;
    p->mUnk_ec.z = p->mUnk_04.z >> 4;
    m = q->mUnk_2a;
    p->mUnk_fe = (u16) (0x640000u / (u32) q->mUnk_28 / 0xf0u);
    p->mUnk_fc = (u16) ((u32) (m * 0x1111) / 0x64u);
    p->mUnk_104 = (s32) (((s64) p->mUnk_1c.x * 0x64000) >> 12);
    p->mUnk_108 = (s32) (((s64) p->mUnk_1c.z * 0x32000) >> 12);
    p->mUnk_10c = 0;
}

#pragma thumb off

Unk020e5a9c *func_020e5dd4(void) {
    Unk020e5a9c *p;
    p = func_02036bec(func_020364e0(func_020364e8()), 0x40);
    *p = *(Unk020e5a9c *) data_02159208;
    return p;
}

Unk020e5a40 *func_020e5d78(void) {
    Unk020e5a40 *p;
    p = func_02036bec(func_020364e0(func_020364e8()), 0x2c);
    data_0217b82c = p;
    *p = *(Unk020e5a40 *) data_021591dc;
    func_020d49d8(&data_0217b82c);
    return data_0217b82c;
}

Unk020e59e4 *func_020e5d24(void) {
    Unk020e59e4 *p;
    p = func_02036bec(func_020364e0(func_020364e8()), 0x28);
    data_0217b828 = p;
    *p = *(Unk020e59e4 *) data_021591b4;
    return p;
}

void func_020e5d0c(void) {
    func_020e6a18(data_0217b830);
}
