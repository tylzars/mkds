#include "code_0214a748.h"
#include "code_0214a5f0.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_0214a000.h"
#include "Main/Unknown/code_0214d000.h"
#include "registers.h"

void func_0214b048(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, int h, Unk0214ad4c *i) {
    s64 x;
    s64 y;
    s64 z;
    s32 e2;
    s32 t1;
    s32 t2;
    s32 t3;
    s32 t4;
    s32 u;
    vu32 *p;

    func_02147dec(d - c);
    if (h != 0) {
        reg_G3_MTX_MODE = 0;
        p = &reg_G3_MTX_LOAD_4x4;
    }
    if (i != 0) {
        i->mUnk_04 = 0;
        i->mUnk_08 = 0;
        i->mUnk_0c = 0;
        i->mUnk_10 = 0;
        i->mUnk_18 = 0;
        i->mUnk_1c = 0;
        i->mUnk_2c = -g;
        i->mUnk_30 = 0;
        i->mUnk_34 = 0;
        i->mUnk_3c = 0;
    }
    e2 = e << 1;
    x = func_02147e64();
    reg_CP_DIV_NUMER = 0x100000000000ULL;
    reg_CP_DIV_DENOM = (u32) (a - b);
    if (g != 0x1000) {
        x = x * g / 0x1000;
    }
    t1 = (x * e2 + 0x80000000) >> 32;
    if (h != 0) {
        *p = t1;
        *p = 0;
        *p = 0;
        *p = 0;
    }
    if (i != 0) {
        i->mUnk_00 = t1;
    }
    y = func_02147e64();
    reg_CP_DIV_NUMER = 0x100000000000ULL;
    reg_CP_DIV_DENOM = (u32) (e - f);
    if (g != 0x1000) {
        y = y * g / 0x1000;
    }
    t2 = (y * e2 + 0x80000000) >> 32;
    if (h != 0) {
        *p = 0;
        *p = t2;
        *p = 0;
        *p = 0;
    }
    if (i != 0) {
        i->mUnk_14 = t2;
    }
    {
        s32 m = d + c;
        s32 n = a + b;
        s32 k0 = (x * m + 0x80000000) >> 32;
        s32 k1 = (y * n + 0x80000000) >> 32;
        if (h != 0) {
            *p = k0;
            *p = k1;
        }
        if (i != 0) {
            i->mUnk_20 = k0;
            i->mUnk_24 = k1;
        }
    }
    z = func_02147e64();
    if (g != 0x1000) {
        z = z * g / 0x1000;
    }
    u = ((s64) e2 * f + 0x800) >> 12;
    t3 = (z * (f + e) + 0x80000000) >> 32;
    t4 = (z * u + 0x80000000) >> 32;
    if (h != 0) {
        *p = t3;
        *p = -g;
        *p = 0;
        *p = 0;
        *p = t4;
        *p = 0;
    }
    if (i != 0) {
        i->mUnk_28 = t3;
        i->mUnk_38 = t4;
    }
}

void func_0214ad4c(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, int h, Unk0214ad4c *i) {
    s64 x;
    s64 y;
    s64 z;
    s32 u;
    s32 v;
    s32 w;
    vu32 *p;

    func_02147dec(d - c);
    if (h != 0) {
        reg_G3_MTX_MODE = 0;
        p = &reg_G3_MTX_LOAD_4x4;
    }
    if (i != 0) {
        i->mUnk_04 = 0;
        i->mUnk_08 = 0;
        i->mUnk_0c = 0;
        i->mUnk_10 = 0;
        i->mUnk_18 = 0;
        i->mUnk_1c = 0;
        i->mUnk_20 = 0;
        i->mUnk_24 = 0;
        i->mUnk_2c = 0;
        i->mUnk_3c = g;
    }
    x = func_02147e64();
    reg_CP_DIV_NUMER = 0x100000000000ULL;
    reg_CP_DIV_DENOM = (u32) (a - b);
    if (g != 0x1000) {
        x = x * g / 0x1000;
    }
    u = ((x << 13) + 0x80000000) >> 32;
    if (h != 0) {
        *p = u;
        *p = 0;
        *p = 0;
        *p = 0;
        *p = 0;
    }
    if (i != 0) {
        i->mUnk_00 = u;
    }
    y = func_02147e64();
    reg_CP_DIV_NUMER = 0x100000000000ULL;
    reg_CP_DIV_DENOM = (u32) (e - f);
    if (g != 0x1000) {
        y = y * g / 0x1000;
    }
    v = ((y << 13) + 0x80000000) >> 32;
    if (h != 0) {
        *p = v;
        *p = 0;
        *p = 0;
        *p = 0;
        *p = 0;
    }
    if (i != 0) {
        i->mUnk_14 = v;
    }
    z = func_02147e64();
    if (g != 0x1000) {
        z = z * g / 0x1000;
    }
    w = ((z << 13) + 0x80000000) >> 32;
    if (h != 0) {
        *p = w;
        *p = 0;
    }
    if (i != 0) {
        i->mUnk_28 = w;
    }
    {
        s32 m = -(d + c);
        s32 n = -(a + b);
        s32 o = f + e;
        s32 k0 = (x * m + 0x80000000) >> 32;
        s32 k1 = (y * n + 0x80000000) >> 32;
        s32 k2 = (z * o + 0x80000000) >> 32;
        if (h != 0) {
            *p = k0;
            *p = k1;
            *p = k2;
            *p = g;
        }
        if (i != 0) {
            i->mUnk_30 = k0;
            i->mUnk_34 = k1;
            i->mUnk_38 = k2;
        }
    }
}

void func_0214abb4(const Vec3 *a, const Vec3 *b, const Vec3 *c, int d, Unk02012f58 *out) {
    Vec3 v0;
    Vec3 v1;
    Vec3 v2;
    s32 x;
    s32 y;
    s32 z;
    vu32 *p;

    v0.x = a->x - c->x;
    v0.y = a->y - c->y;
    v0.z = a->z - c->z;
    func_0214818c(&v0, &v0);
    func_021483a0(b, &v0, &v1);
    func_0214818c(&v1, &v1);
    func_021483a0(&v0, &v1, &v2);
    if (d != 0) {
        reg_G3_MTX_MODE = 2;
        p = &reg_G3_MTX_LOAD_4x3;
        *p = v1.x;
        *p = v2.x;
        *p = v0.x;
        *p = v1.y;
        *p = v2.y;
        *p = v0.y;
        *p = v1.z;
        *p = v2.z;
        *p = v0.z;
    }
    x = -func_0214848c(a, &v1);
    y = -func_0214848c(a, &v2);
    z = -func_0214848c(a, &v0);
    if (d != 0) {
        *p = x;
        *p = y;
        *p = z;
    }
    if (out != 0) {
        out->mUnk_00[0].x = v1.x;
        out->mUnk_00[0].y = v2.x;
        out->mUnk_00[0].z = v0.x;
        out->mUnk_00[1].x = v1.y;
        out->mUnk_00[1].y = v2.y;
        out->mUnk_00[1].z = v0.y;
        out->mUnk_00[2].x = v1.z;
        out->mUnk_00[2].y = v2.z;
        out->mUnk_00[2].z = v0.z;
        out->mUnk_00[3].x = x;
        out->mUnk_00[3].y = y;
        out->mUnk_00[3].z = z;
    }
}

void func_0214aa58(void) {
    func_0214a99c();
    reg_G3_END_VTXS = 0;
    while (reg_G3X_GXSTAT & 0x8000000) {
    }
    reg_G3X_DISP3DCNT = 0;
    reg_G3X_GXSTAT = 0;
    reg_G2_BG0OFS = 0;
    reg_G3X_DISP3DCNT |= 0x2000;
    reg_G3X_DISP3DCNT |= 0x1000;
    reg_G3X_DISP3DCNT &= 0xffffcffd;
    reg_G3X_DISP3DCNT = (reg_G3X_DISP3DCNT & ~0x3000) | 0x10;
    reg_G3X_DISP3DCNT &= 0xcffb;
    reg_G3X_GXSTAT |= 0x8000;
    reg_G3X_GXSTAT = (reg_G3X_GXSTAT & ~0xc0000000) | 0x80000000;
    func_0214a8ec();
    reg_G3X_CLEAR_COLOR = 0;
    reg_G3X_CLEAR_DEPTH = 0x7fff;
    reg_G3X_CLRIMAGE_OFFSET = 0;
    reg_G3X_FOG_COLOR = 0;
    reg_G3X_FOG_OFFSET = 0;
    reg_G2_BG0CNT &= ~3;
    func_0214a648();
    reg_G3_POLYGON_ATTR = 0x1f0080;
    reg_G3_TEXIMAGE_PARAM = 0;
    reg_G3_PLTT_BASE = 0;
}

void func_0214a9d0(void) {
    while (*(vu32 *) 0x4000600 & 0x8000000) {
    }
    *(vu32 *) 0x4000600 |= 0x8000;
    *(vu16 *) 0x4000060 |= 0x2000;
    *(vu16 *) 0x4000060 |= 0x1000;
    func_0214a840();
    *(vu32 *) 0x40004a4 = 0x1f0080;
    *(vu32 *) 0x40004a8 = 0;
    *(vu32 *) 0x40004ac = 0;
}

void func_0214a99c(void) {
    func_0214a54c((void *) 0x4000400);
    while (*(vu32 *) 0x4000600 & 0x8000000) {
    }
}

void func_0214a8ec(void) {
    u32 a;
    u32 b;

    *(vu32 *) 0x4000600 |= 0x8000;
    while (func_0214a61c(&a) != 0) {
    }
    while (func_0214a5f0(&b) != 0) {
    }
    *(vu32 *) 0x4000440 = 3;
    *(vu32 *) 0x4000454 = 0;
    *(vu32 *) 0x4000440 = 0;
    if (b != 0) {
        *(vu32 *) 0x4000448 = b;
    }
    *(vu32 *) 0x4000454 = 0;
    *(vu32 *) 0x4000440 = 2;
    *(vu32 *) 0x4000448 = a;
    *(vu32 *) 0x4000454 = 0;
}

void func_0214a840(void) {
    u32 a;
    u32 b;

    *(vu32 *) 0x4000600 |= 0x8000;
    while (func_0214a61c(&a) != 0) {
    }
    while (func_0214a5f0(&b) != 0) {
    }
    *(vu32 *) 0x4000440 = 3;
    *(vu32 *) 0x4000454 = 0;
    *(vu32 *) 0x4000440 = 0;
    if (b != 0) {
        *(vu32 *) 0x4000448 = b;
    }
    *(vu32 *) 0x4000440 = 2;
    *(vu32 *) 0x4000448 = a;
    *(vu32 *) 0x4000454 = 0;
}

void func_0214a7ec(s32 a, u32 b, u32 c, u32 d) {
    if (a != 0) {
        *(vu16 *) 0x400035c = d;
        *(vu16 *) 0x4000060 = (*(vu16 *) 0x4000060 & ~0x3f40) | ((c << 8) | (b << 6) | 0x80);
    } else {
        *(vu16 *) 0x4000060 = *(vu16 *) 0x4000060 & 0xcf7f;
    }
}

s32 func_0214a7a4(void *a) {
    if (*(vu32 *) 0x4000600 & 0x8000000) {
        return -1;
    }
    func_0214d13c((const void *) 0x4000640, a);
    return 0;
}

s32 func_0214a75c(void *a) {
    if (*(vu32 *) 0x4000600 & 0x8000000) {
        return -1;
    }
    func_0214d0fc((const void *) 0x4000680, a);
    return 0;
}

void func_0214a748(const void *a) {
    func_0214d0e0(a, (void *) 0x4000360);
}
