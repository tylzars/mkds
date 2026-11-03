#include "Main/Unknown/code_020d6d8c.h"

#include "Main/Unknown/code_020d6dc0.h"
#include "Main/Unknown/code_020d7df8.h"
#include "Main/Unknown/code_020d7da8.h"
#include "Main/Unknown/code_020d8000.h"
#include "Main/Unknown/code_020d849c.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_02146000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_0216b000.h"
#include "code_02146d78.h"
#include "code_02147cd8.h"
#include "code_02148538.h"

#pragma thumb on

void func_020d7d4c(Unk020d84e4 *a, struct Unk020fa294 *b, s32 c, s32 d) {
    func_020d7da8(&a->mUnk_00, b, c);
    a->mUnk_24 = c / 100;
    a->mUnk_28 = (c * d) / 100;
    func_020d859c(a, 0, 1);
}

void func_020d7d18(Unk020d849c *p, s32 a, Vec3 **b, s32 c) {
    func_020d80e4(&p->mUnk_00, a, 0, b[0], b[1], b[2], b[3]);
    func_020d84c0(p, c);
    p->mUnk_5c = 0;
}

BOOL func_020d7c84(Unk020d849c *p, s32 a, Vec3 **b) {
    s32 v;
    p->mUnk_5c = p->mUnk_5c - 0x1000000;
    p->mUnk_5c = (s32) (((s64) p->mUnk_5c * (s64) p->mUnk_00.mUnk_30) >> 12);
    func_020d80e4(&p->mUnk_00, a, 0, b[0], b[1], b[2], b[3]);
    v = p->mUnk_00.mUnk_34;
    if (v != 0) {
        p->mUnk_5c = (s32) (((s64) p->mUnk_5c * (s64) v) >> 24);
    }
    if (v != 0) {
        v = (s32) (((s64) p->mUnk_54 * (s64) v) >> 12);
    } else {
        v = 0x1000000;
    }
    p->mUnk_58 = v;
    if (p->mUnk_5c >= 0x1000000) {
        return TRUE;
    }
    return FALSE;
}

#pragma thumb off

void func_020d7bec(Unk02012f58 *a) {
    s32 t;
    s32 i;
    t = func_02148538(a->mUnk_00[0].z, a->mUnk_00[2].z);
    t = (((s64) t * 0x28BE60DB9391LL) + 0x80000000000LL) >> 44;
    i = (u16) ((u16) t >> 1) >> 4;
    data_0217b660.mUnk_00[0] = 0;
    data_0217b660.mUnk_00[1] = data_0215d4b4[i * 2];
    data_0217b660.mUnk_00[2] = 0;
    data_0217b660.mUnk_00[3] = data_0215d4b4[i * 2 + 1];
}

void func_020d7b88(Vec3 *a, void *q) {
    Unk020d7b88 *b = q;
    s32 r = func_02147e8c((a->y + 0x1000) << 1);
    func_02147d88(a->z, r);
    b->mUnk_00[1] = 0;
    b->mUnk_00[0] = func_02147e28();
    func_02147d88(-a->x, r);
    b->mUnk_00[3] = r >> 1;
    b->mUnk_00[2] = func_02147e28();
}

void func_020d7b34(s32 a, Unk020d7b88 *b) {
    s32 i = (u16) (a >> 1) >> 4;
    b->mUnk_00[0] = 0;
    b->mUnk_00[1] = data_0215d4b4[i * 2];
    b->mUnk_00[2] = 0;
    b->mUnk_00[3] = data_0215d4b4[i * 2 + 1];
}

void func_020d7a3c(void *p, s32 b, void *q) {
    Vec3 *a = p;
    Unk020d7b88 *c = q;
    s32 r;
    s32 d;
    s32 i;
    s32 s;
    s32 k;
    s64 w = (s64) ((a->y + 0x1000) << 1) << 32;
    *(vu16 *) 0x40002b0 = 1;
    *(vu64 *) 0x40002b8 = w;
    r = func_02147dc0();
    func_02147d88(a->z, r);
    i = (u16) (b >> 1) >> 4;
    s = data_0215d4b4[i * 2];
    k = data_0215d4b4[i * 2 + 1];
    c->mUnk_00[1] = ((r >> 1) * s) >> 12;
    c->mUnk_00[3] = ((r >> 1) * k) >> 12;
    d = func_02147e28();
    func_02147d88(-a->x, r);
    c->mUnk_00[0] = (d * k) >> 12;
    c->mUnk_00[2] = (d * s) >> 12;
    d = func_02147e28();
    c->mUnk_00[0] = c->mUnk_00[0] - ((d * s) >> 12);
    c->mUnk_00[2] = c->mUnk_00[2] + ((d * k) >> 12);
}

void func_020d79b0(void *p, u32 b, void *q) {
    Unk020d7b88 *a = p;
    Unk020d7b88 *c = q;
    s32 i = (u16) (b >> 1) >> 4;
    s32 s = data_0215d4b4[i * 2];
    s32 k = data_0215d4b4[i * 2 + 1];
    c->mUnk_00[0] = (a->mUnk_00[0] * k - a->mUnk_00[2] * s) >> 12;
    c->mUnk_00[1] = (a->mUnk_00[3] * s) >> 12;
    c->mUnk_00[2] = (a->mUnk_00[2] * k + a->mUnk_00[0] * s) >> 12;
    c->mUnk_00[3] = (a->mUnk_00[3] * k) >> 12;
}

void func_020d7938(Unk020d7b88 *a, Unk020d7b88 *b, Unk020d7b88 *c) {
    c->mUnk_00[0] = (a->mUnk_00[0] * b->mUnk_00[3] - a->mUnk_00[2] * b->mUnk_00[1]) >> 12;
    c->mUnk_00[1] = (a->mUnk_00[3] * b->mUnk_00[1]) >> 12;
    c->mUnk_00[2] = (a->mUnk_00[2] * b->mUnk_00[3] + a->mUnk_00[0] * b->mUnk_00[1]) >> 12;
    c->mUnk_00[3] = (a->mUnk_00[3] * b->mUnk_00[3]) >> 12;
}

void func_020d788c(Unk020d7b88 *a, s32 b, Unk020d7b88 *c) {
    Unk020d7b88 q = *a;
    s32 i = (u16) (b >> 1) >> 4;
    s32 s = data_0215d4b4[i * 2];
    s32 k = data_0215d4b4[i * 2 + 1];
    c->mUnk_00[0] = (q.mUnk_00[3] * s + q.mUnk_00[0] * k) >> 12;
    c->mUnk_00[1] = (q.mUnk_00[1] * k + q.mUnk_00[2] * s) >> 12;
    c->mUnk_00[2] = (q.mUnk_00[2] * k - q.mUnk_00[1] * s) >> 12;
    c->mUnk_00[3] = (q.mUnk_00[3] * k - q.mUnk_00[0] * s) >> 12;
}

void func_020d77e0(void *m, s32 b, void *o) {
    Unk020d7b88 *a = m;
    Unk020d7b88 *c = o;
    Unk020d7b88 q = *a;
    s32 i = (u16) (b >> 1) >> 4;
    s32 s = data_0215d4b4[i * 2];
    s32 k = data_0215d4b4[i * 2 + 1];
    c->mUnk_00[0] = (q.mUnk_00[0] * k - q.mUnk_00[2] * s) >> 12;
    c->mUnk_00[1] = (q.mUnk_00[3] * s + q.mUnk_00[1] * k) >> 12;
    c->mUnk_00[2] = (q.mUnk_00[2] * k + q.mUnk_00[0] * s) >> 12;
    c->mUnk_00[3] = (q.mUnk_00[3] * k - q.mUnk_00[1] * s) >> 12;
}

void func_020d7734(void *m, s32 b, void *o) {
    Unk020d7b88 *a = m;
    Unk020d7b88 *c = o;
    Unk020d7b88 q = *a;
    s32 i = (u16) (b >> 1) >> 4;
    s32 s = data_0215d4b4[i * 2];
    s32 k = data_0215d4b4[i * 2 + 1];
    c->mUnk_00[0] = (q.mUnk_00[0] * k + q.mUnk_00[1] * s) >> 12;
    c->mUnk_00[1] = (q.mUnk_00[1] * k - q.mUnk_00[0] * s) >> 12;
    c->mUnk_00[2] = (q.mUnk_00[3] * s + q.mUnk_00[2] * k) >> 12;
    c->mUnk_00[3] = (q.mUnk_00[3] * k - q.mUnk_00[2] * s) >> 12;
}

void func_020d76a8(Unk020d7b88 *a, s32 b, Unk020d7b88 *c) {
    Unk020d7b88 q = *a;
    s32 i = (u16) (b >> 1) >> 4;
    s32 s = data_0215d4b4[i * 2];
    s32 k = data_0215d4b4[i * 2 + 1];
    c->mUnk_00[0] = (q.mUnk_00[3] * s) >> 12;
    c->mUnk_00[1] = (q.mUnk_00[1] * k) >> 12;
    c->mUnk_00[2] = (-q.mUnk_00[1] * s) >> 12;
    c->mUnk_00[3] = (q.mUnk_00[3] * k) >> 12;
}

void func_020d759c(void *p, void *q, void *r, s32 d) {
    Unk020d7b88 *a = p;
    Unk020d7b88 *b = q;
    Unk020d7b88 *c = r;
    s32 v = a->mUnk_00[0] * b->mUnk_00[0] + a->mUnk_00[1] * b->mUnk_00[1] + a->mUnk_00[2] * b->mUnk_00[2] + a->mUnk_00[3] * b->mUnk_00[3];
    if (v < 0) {
        c->mUnk_00[0] = a->mUnk_00[0] + ((d * -(b->mUnk_00[0] + a->mUnk_00[0])) >> 12);
        c->mUnk_00[1] = a->mUnk_00[1] + ((d * -(b->mUnk_00[1] + a->mUnk_00[1])) >> 12);
        c->mUnk_00[2] = a->mUnk_00[2] + ((d * -(b->mUnk_00[2] + a->mUnk_00[2])) >> 12);
        c->mUnk_00[3] = a->mUnk_00[3] + ((d * -(b->mUnk_00[3] + a->mUnk_00[3])) >> 12);
    } else {
        c->mUnk_00[0] = a->mUnk_00[0] + ((d * (b->mUnk_00[0] - a->mUnk_00[0])) >> 12);
        c->mUnk_00[1] = a->mUnk_00[1] + ((d * (b->mUnk_00[1] - a->mUnk_00[1])) >> 12);
        c->mUnk_00[2] = a->mUnk_00[2] + ((d * (b->mUnk_00[2] - a->mUnk_00[2])) >> 12);
        c->mUnk_00[3] = a->mUnk_00[3] + ((d * (b->mUnk_00[3] - a->mUnk_00[3])) >> 12);
    }
}

void func_020d73f0(Unk020d7b88 *a, Unk020d7b88 *b) {
    s64 w;
    s32 r;
    s64 q;
    s64 t;
    w = a->mUnk_00[0] * a->mUnk_00[0] + a->mUnk_00[1] * a->mUnk_00[1] + a->mUnk_00[2] * a->mUnk_00[2] + a->mUnk_00[3] * a->mUnk_00[3];
    if (w > 0xE66666 && w < 0x119999A) {
        *b = *a;
        return;
    }
    *(vu16 *) 0x4000280 = 2;
    *(vu64 *) 0x4000290 = 0x1000000000000LL << 8;
    *(vu64 *) 0x4000298 = w;
    *(vu16 *) 0x40002b0 = 1;
    *(vu64 *) 0x40002b8 = w << 2;
    while (*(vu16 *) 0x40002b0 & 0x8000) {
    }
    r = *(vu32 *) 0x40002b4;
    while (*(vu16 *) 0x4000280 & 0x8000) {
    }
    q = *(vu64 *) 0x40002a0;
    t = q * r;
    b->mUnk_00[0] = (s32) ((t * a->mUnk_00[0] + 0x100000000000LL) >> 45);
    b->mUnk_00[1] = (s32) ((t * a->mUnk_00[1] + 0x100000000000LL) >> 45);
    b->mUnk_00[2] = (s32) ((t * a->mUnk_00[2] + 0x100000000000LL) >> 45);
    b->mUnk_00[3] = (s32) ((t * a->mUnk_00[3] + 0x100000000000LL) >> 45);
}

void func_020d720c(Vec3 *a, u32 *m) {
    Unk020d7b88 *b = (Unk020d7b88 *) m;
    Unk020d7b88 p;
    Unk020d7b88 q;
    Unk020d7b88 r;
    s32 i;
    s32 s;
    s32 c;
    s32 t;
    t = ((s64) a->x * 0xB60B60B60BLL + 0x80000000000LL) >> 44;
    i = (u16) ((u16) t >> 1) >> 4;
    p.mUnk_00[0] = data_0215d4b4[i * 2];
    p.mUnk_00[3] = data_0215d4b4[i * 2 + 1];
    p.mUnk_00[1] = 0;
    p.mUnk_00[2] = 0;
    q = p;
    t = ((s64) a->y * 0xB60B60B60BLL + 0x80000000000LL) >> 44;
    i = (u16) ((u16) t >> 1) >> 4;
    s = data_0215d4b4[i * 2];
    c = data_0215d4b4[i * 2 + 1];
    p.mUnk_00[0] = (q.mUnk_00[0] * c - q.mUnk_00[2] * s) >> 12;
    p.mUnk_00[2] = (q.mUnk_00[2] * c + q.mUnk_00[0] * s) >> 12;
    p.mUnk_00[1] = (q.mUnk_00[3] * s + q.mUnk_00[1] * c) >> 12;
    p.mUnk_00[3] = (q.mUnk_00[3] * c - q.mUnk_00[1] * s) >> 12;
    r = p;
    t = ((s64) a->z * 0xB60B60B60BLL + 0x80000000000LL) >> 44;
    i = (u16) ((u16) t >> 1) >> 4;
    s = data_0215d4b4[i * 2];
    c = data_0215d4b4[i * 2 + 1];
    b->mUnk_00[0] = (r.mUnk_00[0] * c + r.mUnk_00[1] * s) >> 12;
    b->mUnk_00[1] = (r.mUnk_00[1] * c - r.mUnk_00[0] * s) >> 12;
    b->mUnk_00[2] = (r.mUnk_00[3] * s + r.mUnk_00[2] * c) >> 12;
    b->mUnk_00[3] = (r.mUnk_00[3] * c - r.mUnk_00[2] * s) >> 12;
}

s32 func_020d70ac(Vec3 *a, Vec3 *b) {
    s64 w;
    s32 r;
    s64 q;
    s64 t;
    w = (s64) a->x * a->x;
    w += (s64) a->y * a->y;
    w += (s64) a->z * a->z;
    if (w < 16) {
        return 0;
    }
    *(vu16 *) 0x4000280 = 2;
    *(vu64 *) 0x4000290 = 0x1000000000000LL << 8;
    *(vu64 *) 0x4000298 = w;
    *(vu16 *) 0x40002b0 = 1;
    *(vu64 *) 0x40002b8 = w << 2;
    while (*(vu16 *) 0x40002b0 & 0x8000) {
    }
    r = *(vu32 *) 0x40002b4;
    while (*(vu16 *) 0x4000280 & 0x8000) {
    }
    q = *(vu64 *) 0x40002a0;
    t = q * r;
    b->x = (s32) ((t * a->x + 0x100000000000LL) >> 45);
    b->y = (s32) ((t * a->y + 0x100000000000LL) >> 45);
    b->z = (s32) ((t * a->z + 0x100000000000LL) >> 45);
    return (r + 1) >> 1;
}

s32 func_020d6f78(Vec3 *a, Vec3 *b) {
    s64 w;
    s32 r;
    s64 q;
    s64 t;
    s32 x = a->x;
    s32 z = a->z;
    w = (s64) x * x + (s64) z * z;
    if (w < 16) {
        return 0;
    }
    *(vu16 *) 0x4000280 = 2;
    *(vu64 *) 0x4000290 = 0x1000000000000LL << 8;
    *(vu64 *) 0x4000298 = w;
    *(vu16 *) 0x40002b0 = 1;
    *(vu64 *) 0x40002b8 = w << 2;
    while (*(vu16 *) 0x40002b0 & 0x8000) {
    }
    r = *(vu32 *) 0x40002b4;
    while (*(vu16 *) 0x4000280 & 0x8000) {
    }
    q = *(vu64 *) 0x40002a0;
    t = q * r;
    b->x = (s32) ((t * a->x + 0x100000000000LL) >> 45);
    b->z = (s32) ((t * a->z + 0x100000000000LL) >> 45);
    return (r + 1) >> 1;
}

void func_020d6f20(Vec3 *a, s32 b, Vec3 *c) {
    s32 m[9];
    s32 i = b >> 4;
    func_02146d44(m, data_0215d4b4[i * 2], data_0215d4b4[i * 2 + 1]);
    func_02146d78(a, m, c);
}

void func_020d6df0(Vec3 *a, s32 *b) {
    s32 m[9];
    s32 i;
    s32 j;
    s32 k;
    i = (u16) ((((s64) a->x * 0xB60B60B60BLL) + 0x80000000000LL) >> 44);
    j = (u16) ((((s64) a->y * 0xB60B60B60BLL) + 0x80000000000LL) >> 44);
    k = (u16) ((((s64) a->z * 0xB60B60B60BLL) + 0x80000000000LL) >> 44);
    func_02146d28(b, data_0215d4b4[(i >> 4) * 2], data_0215d4b4[(i >> 4) * 2 + 1]);
    func_02146d44(m, data_0215d4b4[(j >> 4) * 2], data_0215d4b4[(j >> 4) * 2 + 1]);
    func_02146dfc(b, m, b);
    func_02146d60(m, data_0215d4b4[(k >> 4) * 2], data_0215d4b4[(k >> 4) * 2 + 1]);
    func_02146dfc(b, m, b);
}

u32 func_020d6dc0(s32 a, s32 b, s32 c, s32 d) {
    u32 v = data_0216b96c[c][b][d];
    if (v == 1) {
        v = a != 0 ? 2 : 0;
    }
    return v;
}

u32 func_020d6d8c(u32 arg0, u32 arg1, u32 arg2, u32 arg3) {
    u32 value0 = arg0;
    u32 value1 = arg1;
    u32 value2 = arg2;
    u32 value3 = arg3;
    u32 value12;
    u32 value14;
    u32 compareLeft0;
    u32 compareRight0;
    value14 = (u32) &data_0216bb7c;
    value12 = 0x38u;
    value12 = (value2) * (value12) + (value14);
    value1 = (u32) * (const u32 *) ((value12) + ((value1 << 2)));
    compareLeft0 = value0;
    compareRight0 = 0u;
    value0 = (u32) * (const u8 *) ((value1) + (value3));
    if (compareLeft0 != compareRight0) {
        value0 = 0u;
    }
    return value0;
}
