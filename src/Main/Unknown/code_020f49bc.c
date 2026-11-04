#include "Main/Unknown/code_020f49bc.h"

#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_0208ab98.h"
#include "Main/Unknown/code_020f73fc.h"
#include "Main/Unknown/code_02109054.h"
#include "Main/Unknown/unk_02159000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_0208a000.h"
#include "Main/Unknown/code_020f7000.h"
#include "Main/Unknown/code_020f9000.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020ed5c0.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/code_020f2dac.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_020f4000.h"
#include "Main/Unknown/code_020f6000.h"
#include "Main/Unknown/code_020f9c40.h"
#include "Main/Unknown/code_020fa000.h"
#include "Main/Unknown/code_02109000.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_02068eac.h"
#include "Main/Unknown/code_020fe4b4.h"
#include "Main/Unknown/code_0210a598.h"
#include "Main/Unknown/code_0210a67c.h"
#include "Main/Unknown/unk_0216c000.h"
#include "Main/Unknown/code_02069000.h"
#include "Main/Unknown/code_020ff000.h"
#include "Main/Unknown/code_0210a000.h"
#include "Main/Unknown/code_020f1d70.h"
#include "Main/Unknown/code_020f1104.h"
#include "Main/Unknown/code_020f1258.h"
#include "Main/Unknown/code_020f1a14.h"
#include "Main/Unknown/code_020f2d98.h"
#include "Main/Unknown/code_0210b850.h"
#include "Main/Unknown/code_02046be8.h"
#include "Main/Unknown/code_020ec8bc.h"
#include "Main/Unknown/code_020fe000.h"
#include "Main/Unknown/code_020f8000.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_020f5978.h"
#include "Main/Unknown/code_020f11f0.h"
#include "Main/Unknown/code_020f1180.h"
#include "Main/Unknown/code_020f5b74.h"
#include "Main/Unknown/code_020f5b84.h"
#include "Main/Unknown/code_020f5cc4.h"
#include "Main/Unknown/code_020f5d00.h"
#include "Main/Unknown/code_020f5d5c.h"
#include "Main/Unknown/code_020d3c94.h"
#include "Main/Unknown/code_020d50ec.h"
#include "Main/Unknown/code_020d3000.h"
#include "Main/Unknown/code_020d5000.h"
#include "ITCM/code_01ffd000.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_02108ea0.h"
#include "Main/Unknown/code_0210b000.h"
#include "Main/Unknown/code_0210e000.h"
#include "Main/Unknown/code_020e01f0.h"
#include "Main/Unknown/code_020f1000.h"
#include "Main/Unknown/code_020f82c4.h"
#include "Main/Unknown/code_020f92e8.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "code_0212bcac.h"
#include "code_0212df7c.h"

void func_020f6a6c(Unk020f41c4_A *a, void *b) {
    s32 t;
    enum { K0 } i;
    s32 k;

    Vec3AddScaled(-a->mUnk_dc, &a->mUnk_f0, &a->mUnk_50, &a->mUnk_108);
    func_020d5aa0(b, a->mUnk_fc, a->mUnk_104, &a->mUnk_108, &a->mUnk_f0);
    if (a->mUnk_104->mUnk_00 != NULL && func_020e0448((Unk020e0448 *) a->mUnk_104) != 0) {
        a->mUnk_11a = 0xe10;
    } else {
        a->mUnk_11a = 0;
    }
    a->mUnk_74 |= 0x8000;
    i = *(vs32 *) &a->mUnk_44;
    if (data_0217bc34[i].mUnk_44 == 0) {
        if (!(a->mUnk_74 & 0x180000)) {
            a->mUnk_120 = func_020f68b0;
        }
    }
    a->mUnk_124 = func_020f6830;
    i = a->mUnk_44;
    k = data_0217bc34[i].mUnk_7c;
    t = a->mUnk_5c.y;
    if (t <= 0) {
        t = -t;
    }
    a->mUnk_100 = -(s32) (((s64) t * k) >> 12);
    if (a->mUnk_100 < -0x5c3) {
        a->mUnk_100 = -0x5c3;
    }
    a->mUnk_5c.x = 0;
    a->mUnk_5c.y = 0;
    a->mUnk_5c.z = 0;
    func_020f90dc(a);
    func_020f0e2c(&data_027e00cc[*(vs32 *) &a->mUnk_44], a);
    i = *(vs32 *) &a->mUnk_44;
    func_020f91fc(a, data_0217bc34[i].mUnk_9c);
}

void func_020f68b0(Unk020f41c4_A *a) {
    u32 w;

    if (a->mUnk_104->mUnk_00 != NULL) {
        if (func_020e04b0(a->mUnk_104, &a->mUnk_108, &a->mUnk_f0) != 0) {
            func_020f65c4(a);
        }
        if (a->mUnk_104->mUnk_00->mUnk_130 != 0) {
            if (a->mUnk_f0.y < 0xff4) {
                a->mUnk_74 |= 0x80;
            }
        }
        Vec3AddScaled(a->mUnk_dc, &a->mUnk_f0, &a->mUnk_108, &a->mUnk_50);
        if (a->mUnk_11a > 0) {
            a->mUnk_11a -= 1;
            if ((a->mUnk_48 & 7) != func_02061f90()) {
                return;
            }
            if (func_01ffdee4(&a->mUnk_50.x, NULL, 0, a->mUnk_dc, 0x44, a->mUnk_da, NULL, NULL, NULL, &a->mUnk_fc, NULL,
                              NULL, NULL, &w) == 0) {
                return;
            }
            if (func_020d5a68(&w, a->mUnk_fc, a->mUnk_104) != 0) {
                a->mUnk_5c.x = 0;
                a->mUnk_5c.y = 0;
                a->mUnk_5c.z = 0;
                func_020f6fc4(a, 1);
            }
            if (!(a->mUnk_fc & 0x8000)) {
                return;
            }
            func_020f7070(a, 1);
        } else {
            Vec3Sub(&a->mUnk_50, &a->mUnk_0e4, &a->mUnk_5c);
        }
    } else {
        if (!(a->mUnk_74 & 0x40)) {
            return;
        }
        Vec3AddScaled(a->mUnk_dc, &a->mUnk_f0, &a->mUnk_108, &a->mUnk_50);
    }
}

void func_020f6830(Unk020f41c4_A *a, Vec3 *b, Vec3 *c) {
    s32 d;
    s32 n;
    u32 i;

    d = a->mUnk_68.z - a->mUnk_68.y;
    if (d * d >= 0x68be1) {
        return;
    }
    n = func_02039828(b, c);
    if (n <= 0) {
        n = -n;
    }
    i = *(vs32 *) &a->mUnk_44;
    a->mUnk_100 = (s32) (((s64) n * data_0217bc34[i].mUnk_7c) >> 12);
    a->mUnk_100 = a->mUnk_100 >> 1;
}

void func_020f6630(void *a0, s32 b, Vec3 *c, Vec3 *d, Vec3 *e) {
    Unk020f41c4_A *a;
    Vec3 v;
    Vec3 *p;
    s32 t;
    s32 n;
    u32 i;

    a = a0;
    p = &a->mUnk_5c;
    i = *(vs32 *) &a->mUnk_44;
    t = data_0217bc34[i].mUnk_80;
    if (data_021759c0->mMode == 1 || (a->mUnk_74 & 0x8000000)) {
        t = 0;
    }
    a->mUnk_74 |= 0x4000;
    a->mUnk_78 |= data_02159b64;
    n = Vec3Dot(e, p);
    p->x -= (s32) (((s64) e->x * n) >> 12);
    p->y -= (s32) (((s64) e->y * n) >> 12);
    p->z -= (s32) (((s64) e->z * n) >> 12);
    n = func_02039828(d, e);
    if (n < 0) {
        n = 0;
    } else if (n > 0x1333) {
        n = 0x1333;
    }
    Vec3AddScaled(n + (t != 0 ? 0x2800 : 0x3800), e, p, p);
    if (b != 0) {
        Vec3Sub(&a->mUnk_50, c, &v);
        if ((s64) v.x * v.x + (s64) v.y * v.y + (s64) v.z * v.z >= 0x10) {
            func_02039860(&v, &v);
        }
        Vec3AddScaled(b * 0x14cd, &v, p, p);
    }
    if (t != 0) {
        if (!(a->mUnk_74 & 0x180000)) {
            a->mUnk_120 = func_020f63cc;
        }
        a->mUnk_124 = func_020f6388;
        a->mUnk_74 &= ~0x7000000;
    } else {
        a->mUnk_74 &= ~0x4000;
        func_020f7070(a, 1);
    }
}

void func_020f65c4(Unk020f41c4_A *a) {
    u32 i;

    a->mUnk_74 &= ~0x8000;
    a->mUnk_74 |= 0x4000;
    i = *(vs32 *) &a->mUnk_44;
    if (data_0217bc34[i].mUnk_44 == 0) {
        if (!(a->mUnk_74 & 0x180000)) {
            a->mUnk_120 = func_020f63cc;
        }
    }
    a->mUnk_124 = func_020f6388;
    a->mUnk_74 &= ~0x7000000;
}

void func_020f63cc(Unk020f41c4_A *a) {
    u32 w;
    Vec3 v1;
    Vec3 v2;
    Vec3 v3;
    Vec3 *q;
    Vec3 *p;

    q = &a->mUnk_50;
    p = &a->mUnk_5c;

    Vec3Add(p, q, q);
    a->mUnk_5c.x = (s32) (((s64) a->mUnk_5c.x * 0xfec) >> 12);
    p->z = (s32) (((s64) p->z * 0xfec) >> 12);
    if (func_01ffdee4(q, &a->mUnk_0e4, 0, a->mUnk_dc, 0x44, a->mUnk_da, &v1, &v2, (s32 *) &v3, &a->mUnk_fc, NULL, NULL,
                      NULL, &w) != 0) {
        Vec3Add(&v1, q, q);
        if (a->mUnk_fc & 0x1e34ef) {
            func_020f9334(a, q, p, 0x385, &v2);
        }
        if (a->mUnk_fc & 0x214300) {
            a->mUnk_74 |= 0x20;
            func_020f92e8((u32) p, (u32) &v3);
            if (func_020f9290(a, &v3) != 0) {
                return;
            }
        }
        if (a->mUnk_fc & 0x8000) {
            func_020f7070(a, 1);
            return;
        }
    }
    a->mUnk_74 &= ~0x4000000;
    if (!(a->mUnk_fc & 0x1e34ef)) {
        p->y -= 0x385;
        if (p->y < -0xa000) {
            p->y = -0xa000;
        }
    }
    if (!(a->mUnk_74 & 8)) {
        return;
    }
    if (a->mUnk_74 & 3) {
        return;
    }
    func_020f6a6c(a, &w);
}

void func_020f6388(Unk020f41c4_A *a, Vec3 *b, Vec3 *c) {
    func_020f92e8((u32) &a->mUnk_5c, (u32) c);
    if (a->mUnk_74 & 0x1000000) {
        return;
    }
    a->mUnk_74 |= 0x1000000;
    a->mUnk_108.x = 0;
    a->mUnk_108.y = 0;
    a->mUnk_108.z = 0;
}

void func_020f62b0(Unk020eda5c *a, Unk020f40dc *b) {
    Unk0212c400 **p;

    if (data_0217c780 & 1) {
        p = (Unk0212c400 **) func_0210e128(func_02108ea0(0));
        if (data_0217d084.mUnk_0c != 0) {
            if (*p != NULL) {
                func_0212c6f0(p, 0);
            }
            if (*p != NULL) {
                func_0212c6f0(p, 0);
            }
            func_0212ecc0(p, 0, 0xde);
        }
    }
    func_02069e10(b->mUnk_04->mUnk_1fc);
    func_020d3cc8();
    func_020f82e8(0);
    func_020f4754(b, 1);
    if (data_021759c0->mMode != 5) {
        return;
    }
    func_020fe958(6);
}

void func_020f6264(Unk020eda5c *a, Unk020f40dc *b) {
    func_02069c38(b->mUnk_04->mUnk_1fc);
    func_020f4754(b, 1);
    if (data_021759c0->mMode != 5) {
        return;
    }
    func_020fe958(4);
}

void func_020f6220(void *a0, s32 b) {
    Unk020f6150 *a;

    a = a0;
    if (!(a->mUnk_000.mUnk_000.mUnk_74 & 0x400000)) {
        return;
    }
    func_0210b7ec(&a->mUnk_16c, a->mUnk_000.mUnk_000.mUnk_d4 & ~0xc000001f);
    func_02109078(&a->mUnk_000.mUnk_000.mUnk_00, 0xd7, 0x7f, 0);
}

BOOL func_020f6150(Unk020eda5c *a, Unk020f6150 *b) {
    BOOL v;

    v = data_021759c0->mMode == 2;
    func_020f9114(b);
    func_0210b850(&b->mUnk_16c);
    b->mUnk_000.mUnk_000.mUnk_00.mUnk_30 = (void (*)(void *, void *, void *)) func_0210a77c;
    if (a->mUnk_00c->mUnk_1ec & 0x20) {
        func_020f2b94(b, a, v != FALSE ? 2 : 4, 0, 0, 0x5000);
        return FALSE;
    }
    func_020f2b94(b, a, v != FALSE ? 5 : 9, 1, 0, 0x5000);
    return TRUE;
}

void func_020f60d0(Unk020f6150 *a) {
    if (a->mUnk_000.mUnk_000.mUnk_11c > 0x258) {
        a->mUnk_000.mUnk_154 = 0;
    }
    func_020f2228(&a->mUnk_000, 0x84cd);
    if (a->mUnk_000.mUnk_000.mUnk_74 & 1) {
        return;
    }
    func_0210ddf4(&data_0217d294, (a->mUnk_000.mUnk_000.mUnk_d4 & ~0xc000001f) + 0x9c40, func_020f6220, a, 0);
}

void *func_020f6038(void *a, Unk020f6150 *b, void *c) {
    void *p;

    if (b != NULL && c != NULL) {
        func_020ff1b8(func_02039828(&b->mUnk_000.mUnk_000.mUnk_5c, &b->mUnk_000.mUnk_130) < 0,
                      &b->mUnk_000.mUnk_000.mUnk_5c.y);
    }
    p = func_020fecdc(a, b, c);
    if (b != NULL && c == NULL) {
        func_020ff1a0(b->mUnk_000.mUnk_000.mUnk_5c.y, &b->mUnk_168);
    }
    if (b != NULL && c != NULL) {
        return func_020fe8ac(b->mUnk_000.mUnk_000.mUnk_44);
    }
    return p;
}

void func_020f5ffc(Unk020f6150 *a) {
    func_020f8e78(a);
    func_0210b850(&a->mUnk_16c);
    a->mUnk_000.mUnk_000.mUnk_00.mUnk_30 = (void (*)(void *, void *, void *)) func_0210a77c;
    func_020f1ea4(a, 9, a->mUnk_168, 0);
}

void func_020f5fb8(void *a0, s32 b) {
    Unk020f5d6c *a;

    a = a0;
    if (!(a->mUnk_000.mUnk_000.mUnk_000.mUnk_74 & 0x400000)) {
        return;
    }
    func_0210b7ec(&a->mUnk_258, a->mUnk_000.mUnk_000.mUnk_000.mUnk_d4 & ~0xc000001f);
    func_02109078(&a->mUnk_000.mUnk_000.mUnk_000.mUnk_00, 0xd8, 0x7f, 0);
}

void func_020f5f7c(Unk020f5d6c *a, Vec3 *b, Vec3 *c) {
    func_020f29e8((u32) a);
    func_020f1f98(&a->mUnk_000.mUnk_000, b, c);
    a->mUnk_23c.mNextState = 1;
    a->mUnk_23c.mNextStateRequested = 1;
}

s32 func_020f5d6c(Unk020eda5c *a, Unk020f5d6c *b) {
    u16 x;
    u16 v;
    u16 n;

    func_020f9114(b);
    func_0210b850(&b->mUnk_258);
    b->mUnk_000.mUnk_000.mUnk_000.mUnk_00.mUnk_30 = (void (*)(void *, void *, void *)) func_0210a77c;
    func_02046be8(&b->mUnk_23c, (UnkFunc *const *) data_0216c648, 7, b);
    if (a->mUnk_00c->mUnk_1ec & 0x20) {
        b->mUnk_254 = 0;
        func_020f2b94(b, a, 0, 0, 0, 0x5000);
        b->mUnk_23c.mNextState = 1;
        b->mUnk_23c.mNextStateRequested = 1;
        b->mUnk_000.mUnk_21c.mUnk_00 = NULL;
        b->mUnk_000.mUnk_21c.mUnk_04 = 1;
    } else {
        b->mUnk_254 = 1;
        if (data_021759c0->mMode != 2 && a->mUnk_00c->mUnk_1f0.mUnk_00 != NULL) {
            x = (u16) (!(b->mUnk_000.mUnk_000.mUnk_000.mUnk_78 & 0x8000)
                           ? (u16) (b->mUnk_000.mUnk_000.mUnk_000.mUnk_78 & ~0xff00)
                           : 8);
            if (x >= 8) {
                v = 8;
            } else {
                n = (u16) (func_0203c8dc(x) - 1);
                if (n < 1) {
                    n = data_021759c0->mKartCount;
                }
                v = (u16) data_0217561c->mUnk_474[(u8) n - 1];
            }
            func_020ed268(&b->mUnk_000, a, 0x2d, 0x5b, 1, 0, 1, 0x5000, v, 0);
            b->mUnk_23c.mNextState = 3;
            b->mUnk_23c.mNextStateRequested = 1;
        } else {
            func_020f2b94(b, a, 0, 1, 0, 0x5000);
            b->mUnk_23c.mNextState = 2;
            b->mUnk_23c.mNextStateRequested = 1;
            b->mUnk_000.mUnk_21c.mUnk_00 = NULL;
            b->mUnk_000.mUnk_21c.mUnk_04 = 1;
        }
        b->mUnk_000.mUnk_000.mUnk_000.mUnk_74 |= 0x200000;
    }
    func_020f1a14((u32) b);
    if (b->mUnk_000.mUnk_000.mUnk_000.mUnk_74 & 0x8000000) {
        b->mUnk_23c.mNextState = 0;
        b->mUnk_23c.mNextStateRequested = 1;
    }
    return b->mUnk_254;
}

void func_020f5d5c(u32 arg0) {
    u32 value0 = arg0;
    u32 value12;
    value12 = (u32) &func_02046b40;
    value0 = (value0) + (0x23cu);
    func_02046b40((void *) value0);
}

void func_020f5d00(Unk020f5d6c *a) {
    func_020f2228(&a->mUnk_000.mUnk_000, 0x8800);
    if (a->mUnk_000.mUnk_000.mUnk_000.mUnk_74 & 1) {
        return;
    }
    func_0210ddf4(&data_0217d294, a->mUnk_000.mUnk_000.mUnk_000.mUnk_d4 & ~0xc000001f, func_020f5fb8, a, 0);
}

void func_020f5cc4(u32 arg0, u32 arg1) {
    u32 value0 = (u32) arg0;
    u32 value1 = (u32) arg1;
    u32 value2;
    u32 value3;
    u32 value4;
    u32 compareLeft0;
    u32 compareRight0;
    value4 = value0;
    value3 = (u32) * (const s16 *) ((value4) + (218));
    value2 = ~(0u);
    compareLeft0 = value3;
    compareRight0 = value2;
    if ((u32) compareLeft0 == (u32) compareRight0) {
    }
    if ((u32) compareLeft0 == (u32) compareRight0) {
        return;
    }
    func_020f1150(value0, value1);
    value0 = (value4) + (0x200u);
    value1 = 4u;
    *(u16 *) ((value0) + (76)) = (u16) value1;
    value1 = 1u;
    *(u16 *) ((value0) + (78)) = (u16) value1;
}

void func_020f5b84(Unk020f5d6c *a) {
    func_020f2228(&a->mUnk_000.mUnk_000, 0x8800);
    if (!(a->mUnk_000.mUnk_000.mUnk_000.mUnk_74 & 1)) {
        func_0210ddf4(&data_0217d294, a->mUnk_000.mUnk_000.mUnk_000.mUnk_d4 & ~0xc000001f, func_020f5fb8, a, 0);
    }
    if (a->mUnk_000.mUnk_000.mUnk_000.mUnk_74 & 1) {
        return;
    }
    if (a->mUnk_23c.mStateFrames > 0x10) {
        if (func_020f11f0((u32) a, 0) == 0) {
            return;
        }
        a->mUnk_23c.mNextState = 4;
        a->mUnk_23c.mNextStateRequested = 1;
        if (!(a->mUnk_000.mUnk_000.mUnk_000.mUnk_74 & 0x8000000)) {
            return;
        }
        func_020fe71c(1, a->mUnk_228->mUnk_1f8, a->mUnk_000.mUnk_000.mUnk_000.mUnk_4e);
        return;
    }
    if (a->mUnk_23c.mStateFrames > 4) {
        if (func_020f1180(a, 0) == 0) {
            return;
        }
        a->mUnk_23c.mNextState = 4;
        a->mUnk_23c.mNextStateRequested = 1;
        if (!(a->mUnk_000.mUnk_000.mUnk_000.mUnk_74 & 0x8000000)) {
            return;
        }
        func_020fe71c(1, a->mUnk_228->mUnk_1f8, a->mUnk_000.mUnk_000.mUnk_000.mUnk_4e);
    }
}

void func_020f5b74(u32 p0) {
    *(u32 *) ((u8 *) p0 + 292) = (u32) (((u32) (&func_020f5f7c)));
}

void func_020f5978(Unk020f5d6c *a) {
    u16 x;
    u16 v;
    u16 n;

    x = (u16) (!(a->mUnk_000.mUnk_000.mUnk_000.mUnk_78 & 0x8000)
                   ? (u16) (a->mUnk_000.mUnk_000.mUnk_000.mUnk_78 & ~0xff00)
                   : 8);
    if (x >= 8) {
        v = 8;
    } else {
        n = (u16) (func_0203c8dc(x) - 1);
        if (n < 1) {
            n = data_021759c0->mKartCount;
        }
        v = (u16) data_0217561c->mUnk_474[(u8) n - 1];
    }
    func_020ec918(&a->mUnk_000, 0xd000, 0x29, v, 0);
    if (!(a->mUnk_000.mUnk_000.mUnk_000.mUnk_74 & 1)) {
        func_0210ddf4(&data_0217d294, a->mUnk_000.mUnk_000.mUnk_000.mUnk_d4 & ~0xc000001f, func_020f5fb8, a, 0);
    }
    if (a->mUnk_000.mUnk_000.mUnk_000.mUnk_74 & 1) {
        return;
    }
    if (a->mUnk_23c.mStateFrames > 0x708) {
        func_020f29e8((u32) a);
        a->mUnk_23c.mNextState = 1;
        a->mUnk_23c.mNextStateRequested = 1;
        return;
    }
    if (a->mUnk_23c.mStateFrames > 0x10) {
        if (func_020f11f0((u32) a, 1) == 0) {
            return;
        }
        a->mUnk_23c.mNextState = 4;
        a->mUnk_23c.mNextStateRequested = 1;
        if (!(a->mUnk_000.mUnk_000.mUnk_000.mUnk_74 & 0x8000000)) {
            return;
        }
        func_020fe71c(1, a->mUnk_228->mUnk_1f8, a->mUnk_000.mUnk_000.mUnk_000.mUnk_4e);
        return;
    }
    if (a->mUnk_23c.mStateFrames > 4) {
        if (func_020f1180(a, 1) == 0) {
            return;
        }
        a->mUnk_23c.mNextState = 4;
        a->mUnk_23c.mNextStateRequested = 1;
        if (!(a->mUnk_000.mUnk_000.mUnk_000.mUnk_74 & 0x8000000)) {
            return;
        }
        func_020fe71c(1, a->mUnk_228->mUnk_1f8, a->mUnk_000.mUnk_000.mUnk_000.mUnk_4e);
    }
}

void func_020f5968(u32 p0) {
    *(u32 *) ((u8 *) p0 + 292) = (u32) (((u32) (&func_020f5f7c)));
}

// Runs the two 0x7c/0x4c checks of the object in the 0x1fc word of the 0x1c pointer, then
// one of the four func_020f14a0 calls, and stores the 0x24c/0x24e halfwords it picks.
void func_020f5824(Unk020f5d6c *a) {
    Unk020ee684 *o;
    Kart *b;
    BOOL d;
    u32 c;
    s32 n;

    o = a->mUnk_228;
    b = o->mUnk_1fc;
    c = *(u32 *) &b->mUnk_7c;
    d = TRUE;
    if ((c & 0x402020) == 0) {
        if ((b->mUnk_4c & 0x800) == 0) {
            d = FALSE;
        }
    }
    if (d != FALSE) {
        func_020f1104((s32) a);
        a->mUnk_23c.mNextState = 6;
        a->mUnk_23c.mNextStateRequested = 1;
    } else {
        n = a->mUnk_000.mUnk_000.mUnk_000.mUnk_74;
        if (n & 0x10000000) {
            if (c & 1) {
                n = func_020f14a0(a, 0x5333, 0x19a, 1);
            } else {
                n = func_020f14a0(a, 0x4b33, 0x19a, 0);
            }
        } else {
            n = func_020f14a0(a, 0x4800, 0x19a, (n & 0x8000000) == 0);
        }
        if (n != 0) {
            func_020f1104((s32) a);
            a->mUnk_23c.mNextState = 2;
            a->mUnk_23c.mNextStateRequested = 1;
            a->mUnk_000.mUnk_21c.mUnk_00 = NULL;
            a->mUnk_000.mUnk_21c.mUnk_04 = 1;
        }
    }
    if (a->mUnk_000.mUnk_000.mUnk_000.mUnk_74 & 1) {
        return;
    }
    func_0210ddf4(&data_0217d294, a->mUnk_000.mUnk_000.mUnk_000.mUnk_d4 & ~0xc000001f, func_020f5fb8, a, 0);
}

// Checks func_0206c0e0 of the 0x1fc object, then the 0x240 counter and the sum of the two
// squares of the 0x50/0x54/0x58 differences against the 0x1d0/0x1d4/0x1e0 square.
void func_020f572c(Unk020f5d6c *a) {
    Unk020ee684 *o;
    Kart *k;
    s32 n;
    s32 r;
    s32 t;

    o = a->mUnk_228;
    k = o->mUnk_1fc;
    if (func_0206c0e0(k) != 0) {
        func_020f6f10(&a->mUnk_000.mUnk_000.mUnk_000, 0, 8);
    } else {
        func_020f14a0(a, 0x10000, 0x333, 0);
    }
    if ((a->mUnk_000.mUnk_000.mUnk_000.mUnk_74 & 1) == 0) {
        func_0210ddf4(&data_0217d294, a->mUnk_000.mUnk_000.mUnk_000.mUnk_d4 & ~0xc000001f, func_020f5fb8, a, 0);
    }
    if (a->mUnk_23c.mStateFrames <= 0x14) {
        r = k->mUnk_1d0 + (s32) ((a->mUnk_000.mUnk_000.mUnk_000.mUnk_e0 * 3) >> 1);
        n = a->mUnk_000.mUnk_000.mUnk_000.mUnk_50.z - k->mUnk_1d8.z;
        t = a->mUnk_000.mUnk_000.mUnk_000.mUnk_50.x - k->mUnk_1d8.x;
        if ((s64) t * t + (s64) n * n >= (s64) r * r) {
            return;
        }
    }
    func_020f6f10(&a->mUnk_000.mUnk_000.mUnk_000, 0, 8);
}

// Runs func_020f2228 and hands func_020f5fb8 to func_0210ddf4 when the 0x74 bit 0 is clear.
void func_020f56d0(Unk020f5d6c *a) {
    func_020f2228(&a->mUnk_000.mUnk_000, 0xc000);
    if (a->mUnk_000.mUnk_000.mUnk_000.mUnk_74 & 1) {
        return;
    }
    func_0210ddf4(&data_0217d294, a->mUnk_000.mUnk_000.mUnk_000.mUnk_d4 & ~0xc000001f, func_020f5fb8, a, 0);
}

// Runs func_0210a598 with the 0x3bc word of the 0x1fc object when the 0x78 high bits of the
// third parameter match that object's 0x74 halfword and the 0x74/0x78/0xdc tests pass.
void func_020f5614(void *a0, s32 b, void *c0) {
    Unk020f5d6c *a;
    Unk020f41c4_A *c;
    Unk020ee684 *o;
    Kart *k;
    u16 n;
    u32 f;

    a = a0;
    c = c0;
    if ((u32) (b - 1) > 1) {
        return;
    }
    o = a->mUnk_228;
    n = (u16) (!(c->mUnk_78 & 0x8000) ? (u16) (c->mUnk_78 & ~0xff00) : 8);
    if (o == NULL) {
        return;
    }
    k = o->mUnk_1fc;
    if (n != *(u16 *) &k->mIndex) {
        return;
    }
    f = c->mUnk_74;
    if ((f & 0x1000) == 0) {
        if ((f & 0x2000) == 0) {
            return;
        }
        if ((c->mUnk_78 & 0x1000) == 0) {
            return;
        }
        if (c->mUnk_11c >= 0x78) {
            return;
        }
    }
    func_0210a598(k, k->mUnk_3cc);
}

// Hands the 0x44 word and the 0x5c/0x130/0x250/0x254/0x60/0x54 addresses of b to
// func_020fecdc, func_020ff040, func_020ff1b8, func_020ff1a0 and func_020fe8ac.
void *func_020f5550(void *a, Unk020f5d6c *b, void *c) {
    s32 dot;
    void *p;

    if (b != NULL && c != NULL) {
        dot = func_02039828(&b->mUnk_000.mUnk_000.mUnk_000.mUnk_5c, &b->mUnk_000.mUnk_000.mUnk_130);
        func_020ff1b8(dot < 0, &b->mUnk_000.mUnk_000.mUnk_000.mUnk_5c.y);
        func_020ff1b8(b->mUnk_254, &b->mUnk_000.mUnk_000.mUnk_000.mUnk_50.y);
    }
    p = func_020fecdc(a, b, c);
    p = func_020ff040(p, b != NULL ? &b->mUnk_000.mUnk_21c : 0, c);
    if (b != NULL && c == NULL) {
        func_020ff1a0(b->mUnk_000.mUnk_000.mUnk_000.mUnk_5c.y, &b->mUnk_250);
        func_020ff1a0(b->mUnk_000.mUnk_000.mUnk_000.mUnk_50.y, &b->mUnk_254);
    }
    if (b != NULL && c != NULL) {
        return func_020fe8ac(b->mUnk_000.mUnk_000.mUnk_000.mUnk_44);
    }
    return p;
}

// Stores func_0210a77c in the 0x30 word, moves the seven words of data_0216c648 to 0x23c,
// then picks one of three calls from the 0x254/0x21c words.
void func_020f53d0(Unk020f5d6c *a) {
    u16 x;
    u32 n;
    u16 v;
    u16 i;

    func_020f8e78(a);
    func_0210b850(&a->mUnk_258);
    a->mUnk_000.mUnk_000.mUnk_000.mUnk_00.mUnk_30 = (void (*)(void *, void *, void *)) func_0210a77c;
    func_02046be8(&a->mUnk_23c, (UnkFunc *const *) data_0216c648, 7, a);
    if (a->mUnk_254 != 0) {
        if (a->mUnk_000.mUnk_21c.mUnk_00 != NULL) {
            a->mUnk_23c.mNextState = 3;
            a->mUnk_23c.mNextStateRequested = 1;
            x = (u16) (!(a->mUnk_000.mUnk_000.mUnk_000.mUnk_78 & 0x8000)
                           ? (u16) (a->mUnk_000.mUnk_000.mUnk_000.mUnk_78 & ~0xff00)
                           : 8);
            if (x >= 8) {
                v = 8;
            } else {
                n = func_0203c8dc((u32) x);
                i = (u16) (n - 1);
                if (i < 1) {
                    i = (u16) data_021759c0->mKartCount;
                }
                v = (u16) data_0217561c->mUnk_474[(i & 0xff) - 1];
            }
            func_020ec8bc(&a->mUnk_000, 0x2d, 0x5b, 0, 1, a->mUnk_250, v, 0);
        } else {
            a->mUnk_23c.mNextState = 2;
            a->mUnk_23c.mNextStateRequested = 1;
            func_020f1ea4(a, 0, a->mUnk_250, 0);
        }
        a->mUnk_000.mUnk_000.mUnk_000.mUnk_74 |= 0x200000;
    } else {
        a->mUnk_23c.mNextState = 1;
        a->mUnk_23c.mNextStateRequested = 1;
        func_020f1ea4(a, 0, a->mUnk_250, 0);
    }
    func_020f1a14((u32) a);
}

// Returns 1 while GetKart(b) is within the 0x1d0/0x1d4 radius of the 0x50/0x54/0x58
// words, or when the 0xda halfword is -1; otherwise sets the 0x24c/0x24e halfwords, returns 0.
BOOL func_020f5324(void *a0, s32 b) {
    Unk020f5d6c *a;
    Kart *k;
    s32 n;
    s32 r;
    s32 t;

    a = a0;
    k = GetKart(b);
    r = k->mUnk_1d0 + (s32) ((a->mUnk_000.mUnk_000.mUnk_000.mUnk_e0 * 3) >> 1);
    n = a->mUnk_000.mUnk_000.mUnk_000.mUnk_50.z - k->mUnk_1d8.z;
    t = a->mUnk_000.mUnk_000.mUnk_000.mUnk_50.x - k->mUnk_1d8.x;
    if ((s64) t * t + (s64) n * n < (s64) r * r) {
        return TRUE;
    }
    if (a->mUnk_000.mUnk_000.mUnk_000.mUnk_da == -1) {
        return TRUE;
    }
    func_020f9c40((s32) a);
    a->mUnk_23c.mNextState = 5;
    a->mUnk_23c.mNextStateRequested = 1;
    func_020f112c((s32) a, b);
    return FALSE;
}

// Runs func_020f9114, ors data_02159834 into the 0x78 halfword, then makes one of two
// func_020f3150 calls depending on the 0x1ec halfword of the 0x0c pointer, and returns the
// 0x130 word it stores.
s32 func_020f5240(Unk020eda5c *a, Unk020f5240 *b) {
    Unk020ee684 *o;
    s32 n;

    func_020f9114(b);
    b->mUnk_000.mUnk_000.mUnk_78 |= data_02159834;
    o = a->mUnk_00c;
    if (o->mUnk_1ec & 0x10) {
        func_020f3150(&b->mUnk_000, a, 0, 1, 0x4000, 0x3000, 0x59a);
        func_021090c4(&b->mUnk_000.mUnk_000.mUnk_00, 0xda, 0x7f, 0);
        b->mUnk_130 = 1;
        return b->mUnk_130;
    }
    func_020f3150(&b->mUnk_000, a, 0, 0, 0x4000, 0x3000, 0x59a);
    b->mUnk_130 = 0;
    return b->mUnk_130;
}

// Calls func_020f2df0 with one of two pairs of numbers, and when the 0x74 bits allow it
// doubles the 0x60 word and runs func_02109060 and func_020f6a6c.
void func_020f518c(Unk020f5240 *a) {
    u32 v;
    u32 n;

    if (a->mUnk_130 != 0) {
        func_020f2df0(&a->mUnk_000, 0x1ec, 0xfec, 0, &v);
    } else {
        func_020f2df0(&a->mUnk_000, 0x2e1, 0xf85, 0, &v);
    }
    n = a->mUnk_000.mUnk_000.mUnk_74;
    if ((n & 8) == 0) {
        return;
    }
    if (n & 3) {
        return;
    }
    if (a->mUnk_130 != 0) {
        a->mUnk_000.mUnk_000.mUnk_5c.y = a->mUnk_000.mUnk_000.mUnk_5c.y * 2;
    }
    func_02109060(&a->mUnk_000.mUnk_000.mUnk_00, 0xda);
    func_020f6a6c(&a->mUnk_000.mUnk_000, &v);
}

// Hands the 0x130 word and the 0x60 word to func_020ff1b8/func_020ff1a0 around the
// func_020fecdc call, and returns func_020fe8ac's value when b and c are both set.
void *func_020f5108(void *a, Unk020f5240 *b, void *c) {
    void *p;

    if (b != NULL && c != NULL) {
        func_020ff1b8(b->mUnk_130, &b->mUnk_000.mUnk_000.mUnk_5c.y);
    }
    p = func_020fecdc(a, b, c);
    if (b != NULL && c == NULL) {
        func_020ff1a0(b->mUnk_000.mUnk_000.mUnk_5c.y, &b->mUnk_130);
    }
    if (b != NULL && c != NULL) {
        return func_020fe8ac(b->mUnk_000.mUnk_000.mUnk_44);
    }
    return p;
}

// Runs func_020f8e78 and func_020f2d98, then func_021090c4 when the two 0x74/0x130 tests pass.
void func_020f50b4(Unk020f5240 *a) {
    func_020f8e78(a);
    func_020f2d98((u32) a, 0);
    if ((a->mUnk_000.mUnk_000.mUnk_74 & 0x10000000) == 0) {
        return;
    }
    if (a->mUnk_130 == 0) {
        return;
    }
    func_021090c4(&a->mUnk_000.mUnk_000.mUnk_00, 0xda, 0x7f, 0);
}

// Runs func_02069db8 on the 0x1fc word of b's 0x04 object, marks b, sets the 0x204 word of
// a's 0x0c object, and runs func_020fe958 when the 0x08 word is 5.
void func_020f504c(Unk020eda5c *a, Unk020f40dc *b) {
    func_02069db8(b->mUnk_04->mUnk_1fc);
    func_020f4754(b, 1);
    a->mUnk_00c->mUnk_204 = 1;
    if (data_021759c0->mMode != 5) {
        return;
    }
    func_020fe958(3);
}

void func_020f5040(Unk020f5008 *p0) {
    p0->mUnk_134 = 0x1;
}

#pragma thumb off

// Runs func_020ed5c0 with the last two parameters swapped when the 0x134 word is set.
void func_020f5008(Unk020f5008 *a, void *b, void *c) {
    if (a->mUnk_134 == 0) {
        return;
    }
    func_020ed5c0(&a->mUnk_000.mUnk_000, c, b);
}

// Decreases the 0x130 word by one; when it goes below zero func_020f7658 runs first.
void func_020f4fd0(Unk020f5008 *a) {
    a->mUnk_130--;
    if (a->mUnk_130 < 0) {
        func_020f7658(&a->mUnk_000.mUnk_000, 0);
    }
    func_020f68b0(&a->mUnk_000.mUnk_000);
}

// Sets the object up through func_020f2df0 when the 0x74 word allows it.
void func_020f4f44(Unk020f5008 *a) {
    u32 n;

    func_020f2df0(&a->mUnk_000, 0x385, 0xff8, 0x733, &n);
    if ((a->mUnk_000.mUnk_000.mUnk_74 & 8) == 0) {
        return;
    }
    if ((a->mUnk_000.mUnk_000.mUnk_74 & 3) != 0) {
        return;
    }
    func_02109060(&a->mUnk_000.mUnk_000.mUnk_00, 0xda);
    func_020f6a6c(&a->mUnk_000.mUnk_000, &n);
    if ((a->mUnk_000.mUnk_000.mUnk_74 & 0x180000) == 0) {
        a->mUnk_000.mUnk_000.mUnk_120 = (void (*)(Unk020f41c4_A *)) func_020f4fd0;
    }
}

// Returns what func_020fa3d0 gives, with its 0x134 and 0x130 words cleared.
Unk020f5008 *func_020f4ee8(void) {
    Unk020f5008 *p;

    p = func_020fa3d0(3, 8, &data_02159764, &data_02159764);
    if (p == NULL) {
        return NULL;
    }
    if ((p->mUnk_000.mUnk_000.mUnk_74 & 0x180000) == 0) {
        p->mUnk_000.mUnk_000.mUnk_120 = NULL;
    }
    func_020f9c40((s32) p);
    p->mUnk_134 = 0;
    p->mUnk_130 = 0;
    return p;
}

// Stores the two Vec3s in the object and sets the word at 0x80.
void func_020f4e78(Unk020f5008 *a, Vec3 *b, Vec3 *c) {
    a->mUnk_134 = 1;
    func_0208ad74(&a->mUnk_000.mUnk_000.mUnk_7c, 1);
    if (b != NULL) {
        a->mUnk_000.mUnk_000.mUnk_f0 = *b;
        a->mUnk_000.mUnk_000.mUnk_74 |= 0x80;
    }
    if (c == NULL) {
        return;
    }
    a->mUnk_000.mUnk_000.mUnk_50 = *c;
    Vec3Sub(&a->mUnk_000.mUnk_000.mUnk_50, &a->mUnk_000.mUnk_000.mUnk_0e4, &a->mUnk_000.mUnk_000.mUnk_5c);
}

// Runs the object's first word and stores the 0x120 and 0x130 words.
void func_020f4dfc(void **a, Vec3 *b, s32 c) {
    Unk020f5008 *p;

    p = a[0];
    p->mUnk_000.mUnk_000.mUnk_78 |= data_0215969c;
    func_020f9ca8(p);
    func_020f9114(p);
    func_020f30ec(&p->mUnk_000, 0, b);
    if ((p->mUnk_000.mUnk_000.mUnk_74 & 0x180000) == 0) {
        p->mUnk_000.mUnk_000.mUnk_120 = (void (*)(Unk020f41c4_A *)) func_020f4f44;
    }
    p->mUnk_130 = c;
    a[0] = NULL;
}

#pragma thumb on

// Fills a table of eighteen 0x1c-byte objects allocated here.
void func_020f4b8c(void) {
    Unk0217bc48 *p;
    s32 i;

    p = HeapAlloc(GetHeap(func_020364e8()), 0x1f8);
    data_0217bc48 = p;
    p[0] = data_02159918;
    p[1] = data_02159838;
    p[2] = data_02159770;
    p[3] = data_02159f68;
    p[4] = data_021596a0;
    p[5] = data_02159664;
    p[6] = data_02159e54;
    p[7] = data_02159cc0;
    p[8] = data_02159aa0;
    p[9] = data_02159f4c;
    p[10] = data_02159680;
    p[11] = data_021598fc;
    p[12] = data_021599dc;
    p[13] = data_02159d90;
    p[14] = data_0215a588;
    p[15] = data_0215a2ec;
    p[16] = data_0215a174;
    p[17] = data_0215a4c0;
    switch (data_021759c0->mMode) {
        case 2:
            p[17].mUnk_00 = 1;
            break;
        case 5:
            for (i = 0; i < 0x12; i++) {
                if (data_0217bc48[(u32) i].mUnk_00 != 0 && data_0217bc48[(u32) i].mUnk_04 == 0) {
                    data_0217bc48[i].mUnk_00 = 0;
                }
            }
            break;
    }
    if (data_021759c0->mUnk_00c == 1) {
        data_0217bc48[15].mUnk_00 = 0;
    }
}

#pragma thumb off

void func_020f4b20(Unk020f40dc *a, Unk020ee684 *b) {
    s32 i;

    a->mUnk_04 = b;
    a->mUnk_00 = 0x13;
    a->mUnk_08 = 0;
    a->mUnk_20 = 0;
    a->mUnk_0c = 0;
    a->mUnk_10 = 0;
    a->mUnk_12 = 0;
    for (i = 0; i < 3; i++) {
        a->mUnk_14[i] = NULL;
    }
    a->mUnk_24 = data_021759c0->mCurrentEntries[b->mUnk_1f8].mUnk_08.mKind == 3;
}

void func_020f49bc(Unk020f40dc *a) {
    Unk020f41c4_A *e;
    Kart *p;
    Vec3 *q;
    Vec3 *r;
    void (*h)(void *);
    s32 i;
    enum { K0 } k;

    if (a->mUnk_20 <= 0) {
        return;
    }
    a->mUnk_20--;
    if (a->mUnk_20 != 7 && a->mUnk_20 != 5 && a->mUnk_20 != 3) {
        return;
    }
    p = a->mUnk_04->mUnk_1fc;
    a->mUnk_08--;
    e = a->mUnk_14[a->mUnk_08];
    q = &p->mUnk_98;
    r = &p->mVelocity;
    func_020f0ea0(data_027e00cc + e->mUnk_44, e);
    func_020efd1c(a->mUnk_04, e);
    Vec3AddScaled(0xb33, r, &e->mUnk_5c, &e->mUnk_5c);
    *(Vec3 *) &e->mUnk_50 = *q;
    func_020f6630(e, 0, q, r, &p->mUnk_244);
    k = e->mUnk_44;
    h = data_0217bc34[k].mUnk_38;
    if (h != NULL) {
        h(e);
    }
    if (a->mUnk_08 != 0) {
        return;
    }
    a->mUnk_00 = 0x13;
    a->mUnk_08 = 0;
    a->mUnk_20 = 0;
    a->mUnk_0c = 0;
    a->mUnk_10 = 0;
    a->mUnk_12 = 0;
    for (i = 0; i < 3; i++) {
        a->mUnk_14[i] = NULL;
    }
}
