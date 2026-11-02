#include "Main/Unknown/code_020f5d6c.h"

#include "Main/Unknown/unk_02159000.h"
#include "Main/Unknown/unk_0216c000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_02069000.h"
#include "Main/Unknown/code_020d3000.h"
#include "Main/Unknown/code_020d5000.h"
#include "Main/Unknown/code_020f9000.h"
#include "Main/Unknown/code_020ff000.h"
#include "Main/Unknown/code_0210a000.h"
#include "ITCM/code_01ffd000.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02046be8.h"
#include "Main/Unknown/code_02061f7c.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_02108ea0.h"
#include "Main/Unknown/code_0210b000.h"
#include "Main/Unknown/code_0210b850.h"
#include "Main/Unknown/code_0210e000.h"
#include "Main/Unknown/code_020e01f0.h"
#include "Main/Unknown/code_020ec8bc.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/code_020f1000.h"
#include "Main/Unknown/code_020f1a14.h"
#include "Main/Unknown/code_020f1d70.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_020f6000.h"
#include "Main/Unknown/code_020f7000.h"
#include "Main/Unknown/code_020f82c4.h"
#include "Main/Unknown/code_020f8000.h"
#include "Main/Unknown/code_020f92e8.h"
#include "Main/Unknown/code_020fe000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "code_02147cd8.h"
#include "code_0212c6ac.h"
#include "code_0212df7c.h"

void func_020f6a6c(Unk020f41c4_A *a, void *b) {
    s32 t;
    enum { K0 } i;
    s32 k;

    func_02147fd8(-a->mUnk_dc, &a->mUnk_f0, &a->mUnk_50, &a->mUnk_108);
    func_020d5aa0(b, a->mUnk_fc, a->mUnk_104, &a->mUnk_108, &a->mUnk_f0);
    if (a->mUnk_104->mUnk_00 != 0 && func_020e0448((Unk020e0448 *) a->mUnk_104) != 0) {
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

    if (a->mUnk_104->mUnk_00 != 0) {
        if (func_020e04b0(a->mUnk_104, &a->mUnk_108, &a->mUnk_f0) != 0) {
            func_020f65c4(a);
        }
        if (a->mUnk_104->mUnk_00->mUnk_130 != 0) {
            if (a->mUnk_f0.y < 0xff4) {
                a->mUnk_74 |= 0x80;
            }
        }
        func_02147fd8(a->mUnk_dc, &a->mUnk_f0, &a->mUnk_108, &a->mUnk_50);
        if (a->mUnk_11a > 0) {
            a->mUnk_11a -= 1;
            if ((a->mUnk_48 & 7) != func_02061f90()) {
                return;
            }
            if (func_01ffdee4(&a->mUnk_50.x, 0, 0, a->mUnk_dc, 0x44, a->mUnk_da, 0, 0, 0, &a->mUnk_fc, 0, 0, 0, &w) ==
                0) {
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
            func_021484d0(&a->mUnk_50, &a->mUnk_0e4, &a->mUnk_5c);
        }
    } else {
        if (!(a->mUnk_74 & 0x40)) {
            return;
        }
        func_02147fd8(a->mUnk_dc, &a->mUnk_f0, &a->mUnk_108, &a->mUnk_50);
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
    if (data_021759c0->mUnk_08 == 1 || (a->mUnk_74 & 0x8000000)) {
        t = 0;
    }
    a->mUnk_74 |= 0x4000;
    a->mUnk_78 |= data_02159b64;
    n = func_0214848c(e, p);
    p->x -= (s32) (((s64) e->x * n) >> 12);
    p->y -= (s32) (((s64) e->y * n) >> 12);
    p->z -= (s32) (((s64) e->z * n) >> 12);
    n = func_02039828(d, e);
    if (n < 0) {
        n = 0;
    } else if (n > 0x1333) {
        n = 0x1333;
    }
    func_02147fd8(n + (t != 0 ? 0x2800 : 0x3800), e, p, p);
    if (b != 0) {
        func_021484d0(&a->mUnk_50, c, &v);
        if ((s64) v.x * v.x + (s64) v.y * v.y + (s64) v.z * v.z >= 0x10) {
            func_02039860(&v, &v);
        }
        func_02147fd8(b * 0x14cd, &v, p, p);
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

    func_02148504(p, q, q);
    a->mUnk_5c.x = (s32) (((s64) a->mUnk_5c.x * 0xfec) >> 12);
    p->z = (s32) (((s64) p->z * 0xfec) >> 12);
    if (func_01ffdee4(q, (u32 *) &a->mUnk_0e4, 0, a->mUnk_dc, 0x44, a->mUnk_da, &v1, &v2,
                      (s32 *) &v3, &a->mUnk_fc, 0, 0, 0, &w) != 0) {
        func_02148504(&v1, q, q);
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
            if (*p != 0) {
                func_0212c6f0(p, 0);
            }
            if (*p != 0) {
                func_0212c6f0(p, 0);
            }
            func_0212ecc0(p, 0, 0xde);
        }
    }
    func_02069e10(b->mUnk_04->mUnk_1fc);
    func_020d3cc8();
    func_020f82e8(0);
    func_020f4754(b, 1);
    if (data_021759c0->mUnk_08 != 5) {
        return;
    }
    func_020fe958(6);
}

void func_020f6264(Unk020eda5c *a, Unk020f40dc *b) {
    func_02069c38(b->mUnk_04->mUnk_1fc);
    func_020f4754(b, 1);
    if (data_021759c0->mUnk_08 != 5) {
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

s32 func_020f6150(Unk020eda5c *a, Unk020f6150 *b) {
    s32 v;

    v = data_021759c0->mUnk_08 == 2;
    func_020f9114(b);
    func_0210b850(&b->mUnk_16c);
    b->mUnk_000.mUnk_000.mUnk_00.mUnk_30 = (void (*)(void *, void *, void *)) func_0210a77c;
    if (a->mUnk_00c->mUnk_1ec & 0x20) {
        func_020f2b94(b, a, v != 0 ? 2 : 4, 0, 0, 0x5000);
        return 0;
    }
    func_020f2b94(b, a, v != 0 ? 5 : 9, 1, 0, 0x5000);
    return 1;
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

    if (b != 0 && c != 0) {
        func_020ff1b8(func_02039828(&b->mUnk_000.mUnk_000.mUnk_5c, &b->mUnk_000.mUnk_130) < 0,
                      &b->mUnk_000.mUnk_000.mUnk_5c.y);
    }
    p = func_020fecdc(a, b, c);
    if (b != 0 && c == 0) {
        func_020ff1a0(b->mUnk_000.mUnk_000.mUnk_5c.y, &b->mUnk_168);
    }
    if (b != 0 && c != 0) {
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
    a->mUnk_23c.mUnk_10 = 1;
    a->mUnk_23c.mUnk_12 = 1;
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
        b->mUnk_23c.mUnk_10 = 1;
        b->mUnk_23c.mUnk_12 = 1;
        b->mUnk_000.mUnk_21c.mUnk_00 = 0;
        b->mUnk_000.mUnk_21c.mUnk_04 = 1;
    } else {
        b->mUnk_254 = 1;
        if (data_021759c0->mUnk_08 != 2 && a->mUnk_00c->mUnk_1f0.mUnk_00 != 0) {
            x = (u16) (!(b->mUnk_000.mUnk_000.mUnk_000.mUnk_78 & 0x8000)
                           ? (u16) (b->mUnk_000.mUnk_000.mUnk_000.mUnk_78 & ~0xff00)
                           : 8);
            if (x >= 8) {
                v = 8;
            } else {
                n = (u16) (func_0203c8dc(x) - 1);
                if (n < 1) {
                    n = data_021759c0->mUnk_3d0;
                }
                v = (u16) data_0217561c->mUnk_474[(u8) n - 1];
            }
            func_020ed268(&b->mUnk_000, a, 0x2d, 0x5b, 1, 0, 1, 0x5000, v, 0);
            b->mUnk_23c.mUnk_10 = 3;
            b->mUnk_23c.mUnk_12 = 1;
        } else {
            func_020f2b94(b, a, 0, 1, 0, 0x5000);
            b->mUnk_23c.mUnk_10 = 2;
            b->mUnk_23c.mUnk_12 = 1;
            b->mUnk_000.mUnk_21c.mUnk_00 = 0;
            b->mUnk_000.mUnk_21c.mUnk_04 = 1;
        }
        b->mUnk_000.mUnk_000.mUnk_000.mUnk_74 |= 0x200000;
    }
    func_020f1a14((u32) b);
    if (b->mUnk_000.mUnk_000.mUnk_000.mUnk_74 & 0x8000000) {
        b->mUnk_23c.mUnk_10 = 0;
        b->mUnk_23c.mUnk_12 = 1;
    }
    return b->mUnk_254;
}
