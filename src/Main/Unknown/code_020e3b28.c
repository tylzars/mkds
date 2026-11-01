#include "Main/Unknown/code_020e3b28.h"
#include "Main/Unknown/unk_02158000.h"
#include "Main/Unknown/unk_0216c000.h"
#include "Main/Unknown/code_02084000.h"
#include "Main/Unknown/code_020ea588.h"
#include "Main/Unknown/code_020ea000.h"

#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_020e3618.h"
#include "Main/Unknown/code_020d275c.h"
#include "Main/Unknown/code_020d49d8.h"
#include "Main/Unknown/code_020e6f50.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02046be8.h"
#include "Main/Unknown/code_02146000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "code_02146d78.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_020f9c6c.h"

#pragma thumb off

void func_020e4380(Unk020e3ef4 *a) {
    if (a->mUnk_000.mUnk_80.mUnk_04 > a->mUnk_148) {
        a->mUnk_000.mUnk_80.mUnk_10 = 0;
        a->mUnk_000.mUnk_80.mUnk_12 = 1;
    }
}

void func_020e435c(void *a) {
    func_020e1e38((Unk020e1dc0 *) data_0217b7e4, a, func_020e1dec);
}

s32 func_020e4320(s32 a) {
    switch (a) {
        case 0xcb:
        case 0xce:
        case 0xd0:
        case 0xd1:
            return 1;
        default:
            return 0;
    }
}

#pragma thumb on

void func_020e4184(Unk020e1dc0 *a) {
    Unk020e3ef4 *e;
    s32 i;
    s32 k;
    s32 n;
    s32 j;
    s32 l;
    u32 *p;
    u32 m[5];

    for (k = 0; k < 5; k++) {
        m[k] = 0;
    }
    n = a->mUnk_04;
    for (i = 0; i < n; i++) {
        e = a->mUnk_00[i];
        p = &m[e->mUnk_158];
        if (m[e->mUnk_158] == 0) {
            switch (e->mUnk_158) {
                case 0:
                    func_020ea588(&data_0217b7e8, (void *) func_020d21ec((const char *) data_0216c188), 0);
                    func_02084968(data_0217b7e8, 0x3f, 2, 0x294a);
                    break;
                case 1:
                    func_020ea588(&data_0217b7d8, (void *) func_020d21ec((const char *) data_0216c19c), 0);
                    func_02084968(data_0217b7d8, 0x3f, 2, 0x294a);
                    break;
                case 2:
                    func_020ea588(&data_0217b7d4, (void *) func_020d21ec((const char *) data_0216c1b0), 0);
                    func_02084968(data_0217b7d4, 0x3f, 2, 0x294a);
                    break;
                case 3:
                    func_020ea588(&data_0217b7ec, (void *) func_020d21ec((const char *) data_0216c1c4), 0);
                    func_02084968(data_0217b7ec, 0x3f, 2, 0x294a);
                    break;
                case 4:
                    func_020ea588(&data_0217b7e0, (void *) func_020d21ec((const char *) data_0216c1d8), 0);
                    func_02084968(data_0217b7e0, 0x3f, 2, 0x294a);
                    break;
            }
            *p = 1;
        }
    }
    l = a->mUnk_04;
    for (j = 0; j < l; j++) {
        e = a->mUnk_00[j];
        switch (e->mUnk_158) {
            case 0:
                e->mUnk_140 = data_0217b7e8;
                break;
            case 1:
                e->mUnk_140 = data_0217b7d8;
                break;
            case 2:
                e->mUnk_140 = data_0217b7d4;
                break;
            case 3:
                e->mUnk_140 = data_0217b7ec;
                break;
            case 4:
                e->mUnk_140 = data_0217b7e0;
                break;
        }
    }
}

void func_020e410c(Unk020e1dc0 *a) {
    Unk020e3ef4 *e;
    s32 i;
    s32 j;
    s32 n;
    u32 z;
    u32 z2;
    Vec3 v;
    Unk020e3ef4 **p;

    p = a->mUnk_00;
    j = -1;
    z = 0;
    z2 = 0;
    n = a->mUnk_04;
    for (i = 0; i < n; i++) {
        e = p[i];
        if (e->mUnk_000.mUnk_00 == 0xcb) {
            if (j < 0) {
                e->mUnk_138 = z;
            } else {
                func_021484d0(&p[j]->mUnk_000.mUnk_04, &e->mUnk_000.mUnk_04, &v);
                v.y = z2;
                e->mUnk_154 = func_021482cc(&v);
                e->mUnk_154 -= p[j]->mUnk_000.mUnk_58.x;
            }
            j = i;
        }
    }
}

void func_020e3ef4(Unk020e3ef4 *a, struct Unk020fa294 *b, Unk020e1e98_154 *c) {
    func_02046be8(&a->mUnk_000.mUnk_80, (UnkFunc *const *) data_0216c168, 4, a);
    a->mUnk_0e8 = a->mUnk_000.mUnk_04;
    a->mUnk_0a0 = *(Unk020e38a0_28 *) &a->mUnk_000.mUnk_28;
    a->mUnk_0c4 = *(Unk020e38a0_28 *) &a->mUnk_000.mUnk_28;
    a->mUnk_124.x = 0;
    a->mUnk_124.y = 0;
    a->mUnk_124.z = 0;
    a->mUnk_130 = c->mUnk_00 != 0 ? 0 : 1;
    a->mUnk_144 = b->mUnk_2c;
    a->mUnk_146 = b->mUnk_2a;
    a->mUnk_148 = b->mUnk_2e;
    a->mUnk_14a = b->mUnk_28 * 0x80 / 100;
    if (b->mUnk_30 != 0) {
        a->mUnk_14a = -a->mUnk_14a;
    }
    a->mUnk_000.mUnk_7e = 0;
    if (a->mUnk_144 != 0) {
        a->mUnk_150 = 0x1000 / a->mUnk_144;
    } else {
        a->mUnk_150 = 0;
    }
    a->mUnk_14c = 0;
    a->mUnk_100 = (s32) (((s64) c->mUnk_04 * a->mUnk_000.mUnk_1c.x) >> 12);
    a->mUnk_104 = (s32) (((s64) c->mUnk_08 * a->mUnk_000.mUnk_1c.y) >> 12) >> 1;
    if (c->mUnk_00 != 0) {
        a->mUnk_110 = 0;
        a->mUnk_114.x = 1;
    } else {
        a->mUnk_110 = 1;
        a->mUnk_114.x = 0;
    }
    a->mUnk_114.z = 0;
    a->mUnk_120 = c->mUnk_10;
    a->mUnk_134 = 1;
    a->mUnk_138 = c->mUnk_14;
    a->mUnk_000.mUnk_02 |= data_02158d58;
    a->mUnk_000.mUnk_80.mUnk_10 = 0;
    a->mUnk_000.mUnk_80.mUnk_12 = 1;
    a->mUnk_158 = c->mUnk_0c;
    if (a->mUnk_158 == 1 && b->mUnk_32 == 0) {
        a->mUnk_158 = 2;
    }
    a->mUnk_000.mUnk_02 &= ~2;
    a->mUnk_000.mUnk_02 &= ~8;
    a->mUnk_000.mUnk_66 = 0x1f;
    if (c->mUnk_0c == 0) {
        a->mUnk_15c = b->mUnk_0c.x > 0 ? 0x175 : 0x176;
    } else {
        a->mUnk_15c = c->mUnk_18;
    }
    if (a->mUnk_15c != -1) {
        func_020d27fc(&a->mUnk_000);
    }
}

#pragma thumb off

void *func_020e3ea4(void) {
    void *p;

    p = func_02036bec(func_020364e0(func_020364e8()), 0x40);
    *(Unk020e03f8 *) p = *(const Unk020e03f8 *) data_02158d18;
    return p;
}

void *func_020e3e48(void) {
    void *p;

    p = func_02036bec(func_020364e0(func_020364e8()), 0x30);
    *(void **) data_0217b7c4 = p;
    *(Unk020e3e48 *) p = *(const Unk020e3e48 *) data_02158ce8;
    func_020d49d8(&data_0217b7c4);
    return *(void **) data_0217b7c4;
}

void *func_020e3dec(void) {
    void *p;

    p = func_02036bec(func_020364e0(func_020364e8()), 0x28);
    data_0217b7c8 = p;
    *(Unk020e0340 *) p = *(const Unk020e0340 *) data_02158cc0;
    func_020e6f50(&data_0217b7c8);
    return data_0217b7c8;
}

void func_020e3bc0(s32 a, Unk020e38a0 *b) {
    s16 t;
    s32 d;
    u16 x;
    u16 y;

    t = data_0215d4b4[(b->mUnk_148 >> 4) * 2];
    x = b->mUnk_144 + (s32) (((s64) t * b->mUnk_144) >> 12);
    y = 0x10000 - x;
    d = y - b->mUnk_14a;
    if (d > 0x8000) {
        d -= 0x10000;
    }
    if (d < -0x8000) {
        d += 0x10000;
    }
    b->mUnk_124.x = (s32) (((s64) b->mUnk_000.mUnk_28.mUnk_00.x * d) >> 12);
    b->mUnk_124.y = (s32) (((s64) b->mUnk_000.mUnk_28.mUnk_00.y * d) >> 12);
    b->mUnk_124.z = (s32) (((s64) b->mUnk_000.mUnk_28.mUnk_00.z * d) >> 12);
    b->mUnk_14a = y;
    b->mUnk_0a0 = *(Unk020e38a0_28 *) &b->mUnk_000.mUnk_28;
    func_02146d28((s32 *) &b->mUnk_000.mUnk_28, data_0215d4b4[(y >> 4) * 2], data_0215d4b4[(y >> 4) * 2 + 1]);
    func_02146dfc((const s32 *) &b->mUnk_000.mUnk_28, (const s32 *) &b->mUnk_0c4, (s32 *) &b->mUnk_000.mUnk_28);
    func_02147fd8(-b->mUnk_104, &b->mUnk_000.mUnk_28.mUnk_0c, &b->mUnk_000.mUnk_04, &b->mUnk_0f4);
    if (b->mUnk_150 != 0) {
        b->mUnk_150--;
        return;
    }
    if (b->mUnk_000.mUnk_94 != 0) {
        func_020d275c(&b->mUnk_000, 0x189);
    }
    b->mUnk_148 += b->mUnk_146;
    if (b->mUnk_148 >= 0x4000 && b->mUnk_148 < b->mUnk_146 + 0x4000) {
        b->mUnk_150 = b->mUnk_14c;
    } else if (b->mUnk_148 >= 0xc000 && b->mUnk_148 < b->mUnk_146 + 0xc000) {
        b->mUnk_150 = b->mUnk_14e;
    }
    y = 0x10000 - b->mUnk_14a;
    b->mUnk_154 = (s32) ((((s64) (s32) (u16) (0x10000 - b->mUnk_14a) * 0x1680000) + 0x80000) >> 20) << 1;
    if (b->mUnk_154 > ((Unk020e1dc0 *) *(void **) data_0217b7c4)->mUnk_2c) {
        b->mUnk_154 = ((Unk020e1dc0 *) *(void **) data_0217b7c4)->mUnk_2c;
    }
    if (b->mUnk_154 < 0) {
        b->mUnk_154 = 0;
    }
}

void func_020e3b4c(Unk020e3ef4 *a, void *b, u32 c) {
    Unk020e1e98_12c *p;

    a->mUnk_000.mUnk_28.mUnk_24.x = a->mUnk_000.mUnk_04.x >> 4;
    a->mUnk_000.mUnk_28.mUnk_24.y = a->mUnk_000.mUnk_04.y >> 4;
    a->mUnk_000.mUnk_28.mUnk_24.z = a->mUnk_000.mUnk_04.z >> 4;
    p = (Unk020e1e98_12c *) data_0217b7cc;
    p->mUnk_0c = a->mUnk_154;
    *p->mUnk_1c[p->mUnk_1a] = p->mUnk_0c;
    func_020ea8a8(a->mUnk_140, &a->mUnk_000.mUnk_28, &a->mUnk_000.mUnk_1c.x, c);
}

void func_020e3b28(void *a) {
    func_020e1e38((Unk020e1dc0 *) *(void **) data_0217b7c4, a, func_020e3b4c);
}
