#include "Main/Unknown/code_020e662c.h"

#include "Main/Unknown/code_020e66e4.h"
#include "Main/Unknown/code_020e5d0c.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_020d3000.h"
#include "Main/Unknown/code_02146000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020e6a74.h"
#include "Main/Unknown/code_020e6b58.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_0206bcb0.h"

void func_020e6df0(Unk02012f58 *p) {
    data_0217b850->mUnk_00.x = 0x1000;
    data_0217b850->mUnk_00.y = 0;
    data_0217b850->mUnk_00.z = 0;
    data_0217b850->mUnk_0c.x = 0;
    data_0217b850->mUnk_0c.y = p->mUnk_0c.y;
    data_0217b850->mUnk_0c.z = p->mUnk_0c.z;
    data_0217b850->mUnk_18.x = 0;
    data_0217b850->mUnk_18.y = -p->mUnk_0c.z;
    data_0217b850->mUnk_18.z = p->mUnk_0c.y;
    func_02146d0c(p, data_0217b848);
    func_02146dfc((const s32 *) data_0217b850, (const s32 *) data_0217b848, (s32 *) data_0217b860);
    {
        Unk02012f58 *h;
        Vec3 *v;
        s32 a;
        s32 b;

        h = data_0217b85c;
        v = &h->mUnk_18;
        *v = data_0217b848->mUnk_18;
        a = h->mUnk_18.x;
        b = v->z;
        h->mUnk_00.z = -a;
        h->mUnk_00.x = b;
        h->mUnk_00.y = 0;
    }
    if ((s64) data_0217b85c->mUnk_00.x * data_0217b85c->mUnk_00.x +
            (s64) data_0217b85c->mUnk_00.y * data_0217b85c->mUnk_00.y +
            (s64) data_0217b85c->mUnk_00.z * data_0217b85c->mUnk_00.z >=
        0x10) {
        func_02039860(&data_0217b85c->mUnk_00, &data_0217b85c->mUnk_00);
    }
    func_020397a8(&data_0217b85c->mUnk_18, &data_0217b85c->mUnk_00, &data_0217b85c->mUnk_0c);
    *data_0217b854 = *p;
}

s32 func_020e6d88(Vec3 *v) {
    data_0217b84c->mUnk_0c = *v;
    data_0217b84c->mUnk_18 = data_0217b860->mUnk_18;
    func_020397a8(&data_0217b84c->mUnk_0c, &data_0217b84c->mUnk_18, &data_0217b84c->mUnk_00);
    return func_02039860(&data_0217b84c->mUnk_00, &data_0217b84c->mUnk_00);
}

s32 func_020e6d34(Vec3 *v, Unk02012f58 *h) {
    h->mUnk_0c = *v;
    h->mUnk_18 = data_0217b860->mUnk_18;
    func_020397a8(&h->mUnk_0c, &h->mUnk_18, &h->mUnk_00);
    return func_02039860(&h->mUnk_00, &h->mUnk_00);
}

Unk02012f58 *func_020e6cf8(Vec3 *param_1) {
    Unk02012f58 *p;
    Vec3 *q;

    p = data_0217b848;
    q = &p->mUnk_24;
    q->x = param_1->x >> 4;
    q->y = param_1->y >> 4;
    q->z = param_1->z >> 4;
    return data_0217b848;
}

Unk02012f58 *func_020e6cbc(Vec3 *param_1) {
    Unk02012f58 *p;
    Vec3 *q;

    p = data_0217b860;
    q = &p->mUnk_24;
    q->x = param_1->x >> 4;
    q->y = param_1->y >> 4;
    q->z = param_1->z >> 4;
    return data_0217b860;
}

Unk02012f58 *func_020e6c3c(Vec3 *v, s32 a1, s32 a2) {
    Vec3 *q;

    data_0217b860->mUnk_0c.x = (a1 * data_0217b860->mUnk_00.x) >> 12;
    data_0217b860->mUnk_0c.y = a2 + 0x1000;
    data_0217b860->mUnk_0c.z = (a1 * data_0217b860->mUnk_00.z) >> 12;
    q = &data_0217b860->mUnk_24;
    q->x = v->x >> 4;
    q->y = v->y >> 4;
    q->z = v->z >> 4;
    return data_0217b860;
}

void func_020e6c0c(void) {
    data_0217b860->mUnk_0c.z = 0;
    data_0217b860->mUnk_0c.x = data_0217b860->mUnk_0c.z;
    data_0217b860->mUnk_0c.y = 0x1000;
}

Unk02012f58 *func_020e6bd0(Vec3 *param_1) {
    Unk02012f58 *p;
    Vec3 *q;

    p = data_0217b84c;
    q = &p->mUnk_24;
    q->x = param_1->x >> 4;
    q->y = param_1->y >> 4;
    q->z = param_1->z >> 4;
    return data_0217b84c;
}

Unk02012f58 *func_020e6b94(Vec3 *param_1) {
    Unk02012f58 *p;
    Vec3 *q;

    p = data_0217b85c;
    q = &p->mUnk_24;
    q->x = param_1->x >> 4;
    q->y = param_1->y >> 4;
    q->z = param_1->z >> 4;
    return data_0217b85c;
}

Unk02012f58 *func_020e6b58(Vec3 *param_1) {
    Unk02012f58 *p;
    Vec3 *q;

    p = data_0217b844;
    q = &p->mUnk_24;
    q->x = param_1->x >> 4;
    q->y = param_1->y >> 4;
    q->z = param_1->z >> 4;
    return data_0217b844;
}

u32 func_020e6b48(void) {
    return ((u32) data_0217b860);
}

void *func_020e6b38(void) {
    return data_0217b848;
}

u32 func_020e6b28(void) {
    return ((u32) data_0217b848);
}

u32 func_020e6b14(void) {
    return ((((u32) data_0217b848)) + (0x18u));
}

void func_020e6ab8(Unk020e6488 *p0) {
    p0->mUnk_10 = (u32) (((((u32) p0->mUnk_10)) & (0x8000ffffu)));
    p0->mUnk_10 = (u32) (((((u32) p0->mUnk_10)) | (0x294a0000u)));
    p0->mUnk_14 = (u32) ((p0->mUnk_14 & ~(0x3f000000u)));
    p0->mUnk_14 = (u32) ((p0->mUnk_14 | (0x3f000000u)));
    p0->mUnk_14 = (u32) ((p0->mUnk_14 & ~(0xfu)));
    p0->mUnk_14 = (u32) ((p0->mUnk_14 | (0x2u)));
}

void func_020e6a74(void) {
    u32 v1[1];
    func_01ff9048((u32) 0x17, (void *) (u32) data_0217b854, 0xc);
    v1[0] = 0x1e;
    func_01ff9048((u32) 0x13, (void *) ((u32) v1), 1);
}

void func_020e6a18(Unk020e6488 *p) {
    if (p->mUnk_1a == 1) {
        func_01ff9048(0x2b, p->mUnk_20, 1);
        func_01ff9048(0x2a, p->mUnk_1c, 1);
    }
    func_01ff9048(0x30, &p->mUnk_0c, 1);
    func_01ff9048(0x31, &p->mUnk_10, 1);
}

s32 func_020e69bc(Vec3 *v) {
    Unk02012f58 *t;
    s64 acc;

    t = data_0217b854;
    acc = (s64) v->x * t->mUnk_00.z + (s64) v->y * t->mUnk_0c.z + (s64) v->z * t->mUnk_18.z;
    return -(t->mUnk_24.z + (s32) (acc >> 12)) >> 9;
}

void func_020e6854(Unk020e6488 *p, Vec3 *q, s32 c, u32 d) {
    u32 a[3];
    u32 v;
    u32 e;
    Unk02012f58 *t;
    s32 m;
    u32 r;
    s64 acc;

    a[0] = p->mUnk_08;
    a[1] = a[0];
    a[2] = a[0];
    func_01ff9048(0x1b, a, 3);
    v = p->mUnk_14;
    e = (v & 0x1f0000) >> 16;
    if (d < e) {
        v &= ~0x1f0000;
        v |= d << 16;
        r = func_020d3c44();
        v &= 0xc0ffffff;
        v |= r << 24;
    } else if (c != 0) {
        t = data_0217b854;
        acc = (s64) q->x * t->mUnk_00.z + (s64) q->y * t->mUnk_0c.z + (s64) q->z * t->mUnk_18.z;
        m = -(t->mUnk_24.z + (s32) (acc >> 12)) >> 9;
        if (m < e) {
            if (m == 0) {
                m = 1;
            }
            v &= ~0x1f0000;
            v |= (u32) m << 16;
            r = func_020d3c44();
            v &= 0xc0ffffff;
            v |= r << 24;
        }
    }
    func_01ff9048(0x29, &v, 1);
    if (p->mUnk_1a != 1) {
        u16 n;

        n = p->mUnk_18;
        func_01ff9048(0x2b, p->mUnk_20 + n, 1);
        func_01ff9048(0x2a, p->mUnk_1c + n, 1);
    }
    func_01ff9144((const void *) p->mUnk_00, p->mUnk_04);
}

void func_020e67c4(Unk020e6488 *p, Unk02012f58 *q, Vec3 *v, s32 a4, u16 a5) {
    u32 n;
    Vec3 t;
    s32 x;
    s32 z;
    s32 y;

    n = 0x1e;
    func_01ff9048(0x14, &n, 1);
    func_01ff9048(0x19, q, 0xc);
    if (v != 0) {
        z = v->z;
        y = v->y;
        x = v->x;
        t.x = x;
        t.y = y;
        t.z = z;
        func_01ff9048(0x1b, &t, 3);
    }
    func_020e6854(p, &q->mUnk_24, a4, a5);
}

void func_020e66e4(Unk020e6488 *p, Unk02012f58 *q, s32 r, Vec3 *v, s32 a5, u16 a6) {
    u32 n;
    Vec3 t;
    s32 i;
    s32 x;
    s32 z;
    s32 y;

    n = 0x1e;
    func_01ff9048(0x14, &n, 1);
    func_01ff9048(0x19, q, 0xc);
    if (r != 0) {
        i = r >> 4;
        func_02146d60((s32 *) *(void **) data_0217b858, data_0215d4b4[i * 2], data_0215d4b4[i * 2 + 1]);
        func_01ff9048(0x1a, *(void **) data_0217b858, 9);
    }
    if (v != 0) {
        z = v->z;
        y = v->y;
        x = v->x;
        t.x = x;
        t.y = y;
        t.z = z;
        func_01ff9048(0x1b, &t, 3);
    }
    func_020e6854(p, &q->mUnk_24, a5, a6);
}

#pragma thumb on

void func_020e662c(void) {
    u32 v1;
    v1 = ((u32) func_02036bec((void *) data_021759d0->mUnk_24, (u32) 0x30));
    *(u32 *) &data_0217b848 = v1;
    v1 = ((u32) func_02036bec((void *) data_021759d0->mUnk_24, (u32) 0x30));
    *(u32 *) &data_0217b860 = v1;
    v1 = ((u32) func_02036bec((void *) data_021759d0->mUnk_24, (u32) 0x30));
    *(u32 *) &data_0217b850 = v1;
    v1 = ((u32) func_02036bec((void *) data_021759d0->mUnk_24, (u32) 0x30));
    *(u32 *) &data_0217b84c = v1;
    v1 = ((u32) func_02036bec((void *) data_021759d0->mUnk_24, (u32) 0x30));
    *(u32 *) &data_0217b85c = v1;
    v1 = ((u32) func_02036bec((void *) data_021759d0->mUnk_24, (u32) 0x30));
    *(u32 *) &data_0217b844 = v1;
    v1 = ((u32) func_02036bec((void *) data_021759d0->mUnk_24, (u32) 0x30));
    *(u32 *) &data_0217b854 = v1;
    v1 = ((u32) func_02036bec((void *) data_021759d0->mUnk_24, (u32) 0x24));
    *(u32 *) &data_0217b858 = v1;
    func_021471bc((Unk02012f58 *) (u32) data_0217b844);
}

#pragma thumb off
