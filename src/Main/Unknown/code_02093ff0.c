#include "Main/Unknown/code_02093ff0.h"
#include "Main/Unknown/code_0209b634.h"
#include "Main/Unknown/code_020d2000.h"

#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_02074854.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_021000d0.h"
#include "Main/Unknown/code_02102674.h"
#include "Main/Unknown/unk_0217b000.h"
#include "code_02148538.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_0209bef0.h"
#include "Main/Unknown/code_020d22e0.h"
#include "Main/Unknown/code_020d3b10.h"
#include "Main/Unknown/code_020e6b58.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_02166000.h"
#include "Main/Unknown/unk_021759c0.h"

u32 func_02094df4(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    func_020d2398((void *) value0);
    value0 = (u32) &data_0217b0d8;
    value1 = 0u;
    *(u32 *) ((value0) + (0)) = value1;
    return value0;
}

void func_02094db4(Unk02094db4 *a) {
    gTeresa = func_0209bc74(a, gTeresaNsbmdName, gTeresaNsbtpName);
    func_0209b940(gTeresa, 0x3f);
    a->mUnk_1c = 1;
}

void func_02094d9c(void *a) {
    func_0209bbd0(a, gTeresa);
}

void func_02094c70(void *a, Unk02094000 *b) {
    s32 w;
    s32 v[3];

    if (b->mUnk_ac == 0) {
        return;
    }
    func_0207a974((u16) data_021759c0->mUnk_62);
    func_0209b940(gTeresa, func_020d3c44());
    func_0209b688(gTeresa, b->mUnk_ae);
    func_0209b9a4(gTeresa, b->mUnk_ac);
    func_0209b8ac(gTeresa, func_0206183c());
    func_0209b7a0(gTeresa, b->mUnk_b0, 0);
    w = 0x1e;
    func_01ff9048(0x14, &w, 1);
    func_01ff9048(0x19, func_020e6cf8(&b->mUnk_00.mUnk_04), 0xc);
    if (func_02061818() == 2) {
        v[0] = 0x2000;
        v[1] = 0x2000;
        v[2] = 0x2000;
        func_01ff9048(0x1b, v, 3);
    }
    func_01ff9048(0x1b, &b->mUnk_00.mUnk_1c, 3);
    func_0209bb2c(a, gTeresa, b);
}

static inline void func_02094768_inline(Unk02094000 *o) {
    o->mUnk_fc = o->mUnk_fc + o->mUnk_100;
    if (o->mUnk_fc >= o->mUnk_108) {
        o->mUnk_100 = -o->mUnk_100;
        o->mUnk_fc = o->mUnk_108 * 2 - o->mUnk_fc;
    } else if (o->mUnk_fc <= o->mUnk_104) {
        o->mUnk_100 = -o->mUnk_100;
        o->mUnk_fc = o->mUnk_104 * 2 - o->mUnk_fc;
    }
    o->mUnk_ac = o->mUnk_fc >> 12;
}

static inline void func_02094768_inline_2(s32 *p, s32 *q) {
    s32 k = *p;
    if (k > 0) {
        k += *q;
        if (k <= 0) {
            k = 0;
        }
        *p = k;
    } else if (k < 0) {
        k += *q;
        if (k >= 0) {
            k = 0;
        }
        *p = k;
    }
}

void func_02094c24(Unk020946b8 *a) {
    s32 i;
    Unk02094000 *o;

    if (a == NULL) {
        return;
    }
    for (i = 0; i < a->mUnk_04 && (o = a->mUnk_00[i]) != NULL; i++) {
        o->mUnk_ae = i & 1;
        o->mUnk_b0 = (i / 2) & 1;
    }
}

s16 func_02094c0c(s32 a) {
    return data_0215d4b4[(a >> 4) * 2];
}

s32 func_02094bf0(s32 a, s32 b) {
    return (s32) (((s64) a * b + 0x800) >> 12);
}

s16 func_02094bd0(s32 a) {
    return data_0215d4b4[(a >> 4) * 2 + 1];
}

void func_02094768(void *a, Unk02094000 *o) {
    s32 t;
    s32 x;
    s32 y;
    u16 w;
    s32 n;
    s32 m;
    Unk0206bcb0 *g;

    switch (o->mUnk_110) {
        case 1:
            t = o->mUnk_b4;
            o->mUnk_b4 = t - 1;
            if (t <= 0) {
                o->mUnk_b4 = 0;
                func_02094768_inline(o);
                if (o->mUnk_fc >= 0x2000) {
                    o->mUnk_110 = 0;
                }
            }
            break;
        case 0:
            t = o->mUnk_b8;
            o->mUnk_b8 = t - 1;
            if (t <= 0) {
                o->mUnk_b8 = 0;
                o->mUnk_fc = o->mUnk_fc - 0x1000;
                if (o->mUnk_fc > 0) {
                    o->mUnk_ac = o->mUnk_fc >> 12;
                } else {
                    o->mUnk_ac = 0;
                    func_020d2398(&o->mUnk_00);
                    data_0217b0d8--;
                }
            } else {
                func_02094768_inline(o);
            }
            break;
    }
    if (o->mUnk_b8 <= 0) {
        return;
    }
    o->mUnk_bc.mUnk_00 = o->mUnk_bc.mUnk_00 + o->mUnk_bc.mUnk_18;
    x = func_02094bf0(o->mUnk_bc.mUnk_10, func_02094c0c(o->mUnk_bc.mUnk_00));
    o->mUnk_bc.mUnk_08 = o->mUnk_bc.mUnk_0c + x - o->mUnk_bc.mUnk_04;
    o->mUnk_bc.mUnk_04 = o->mUnk_bc.mUnk_04 + o->mUnk_bc.mUnk_08;
    func_02094768_inline_2(&o->mUnk_bc.mUnk_10, &o->mUnk_bc.mUnk_14);
    func_02094768_inline_2(&o->mUnk_bc.mUnk_18, &o->mUnk_bc.mUnk_1c);
    w = o->mUnk_bc.mUnk_04;
    o->mUnk_dc.mUnk_00 = o->mUnk_dc.mUnk_00 + o->mUnk_dc.mUnk_18;
    y = func_02094bd0(o->mUnk_dc.mUnk_00);
    x = func_02094bf0(o->mUnk_dc.mUnk_10 / 2, 0x1000 - y);
    o->mUnk_dc.mUnk_08 = o->mUnk_dc.mUnk_0c + x - o->mUnk_dc.mUnk_04;
    o->mUnk_dc.mUnk_04 = o->mUnk_dc.mUnk_04 + o->mUnk_dc.mUnk_08;
    func_02094768_inline_2(&o->mUnk_dc.mUnk_10, &o->mUnk_dc.mUnk_14);
    func_02094768_inline_2(&o->mUnk_dc.mUnk_18, &o->mUnk_dc.mUnk_1c);
    m = o->mUnk_dc.mUnk_04;
    n = o->mUnk_10c;
    if (func_02061818() == 2) {
        o->mUnk_00.mUnk_04.x = o->mUnk_a0.x + (s32) (((s64) n * data_0215d4b4[(w >> 4) * 2 + 1]) >> 12);
        o->mUnk_00.mUnk_04.y = o->mUnk_a0.y + m;
        o->mUnk_00.mUnk_04.z = o->mUnk_a0.z + (s32) (((s64) n * data_0215d4b4[(w >> 4) * 2]) >> 12);
    } else {
        g = func_0207a974((u16) data_021759c0->mUnk_62);
        o->mUnk_00.mUnk_04.x =
            g->mUnk_80.x + (o->mUnk_a0.x + (s32) (((s64) n * data_0215d4b4[(w >> 4) * 2 + 1]) >> 12));
        o->mUnk_00.mUnk_04.y = o->mUnk_a0.y + m;
        o->mUnk_00.mUnk_04.z = g->mUnk_80.z + (o->mUnk_a0.z + (s32) (((s64) n * data_0215d4b4[(w >> 4) * 2]) >> 12));
    }
}

void func_02094744(void) {
    func_0209bef0(func_02094db4, func_02094c70, func_02094d9c);
}

void func_02094724(void) {
    func_0209bf48(func_02094c24, func_02094768, NULL);
}

void func_020946b8(void) {
    Unk020946b8 *l;
    Unk02094000 *o;
    s32 i;

    l = func_02100138(0x13b);
    if (l == NULL) {
        return;
    }
    for (i = 0; i < l->mUnk_04 && (o = l->mUnk_00[i]) != NULL; i++) {
        o->mUnk_b4 = 0;
        o->mUnk_b8 = 0;
    }
}

static inline u32 func_02094000_inline(Unk020f41c4_B *b, u32 n) {
    b->mUnk_00 = b->mUnk_08 * b->mUnk_00 + b->mUnk_10;
    if (n == 0) {
        return (u32) (b->mUnk_00 >> 32);
    }
    return (u32) (((b->mUnk_00 >> 32) * n) >> 32);
}

static inline void func_02094000_inline_2(Unk02094000_bc *p, u16 a, s32 b, s32 c, s32 d, s32 e, s32 f) {
    p->mUnk_00 = a;
    p->mUnk_0c = b;
    p->mUnk_10 = c;
    p->mUnk_14 = d;
    p->mUnk_18 = e;
    p->mUnk_1c = f;
}

void func_02094000(Vec3 *a) {
    Unk02094000 *o;
    Unk020748a8 *g;
    s32 p;
    s32 q;
    s32 e;
    s16 c;
    u16 b;
    s32 k;
    s32 d;
    s32 f;

    o = func_0209bbfc(func_02100138(0x13b));
    if (o == NULL) {
        return;
    }
    o->mUnk_ac = 0;
    o->mUnk_a0 = *a;
    if (func_02061818() == 0) {
        g = func_020748a8();
        e = func_02094000_inline(&data_0217561c->mUnk_498, 0x30);
        c = (u16) (func_02094000_inline(&data_0217561c->mUnk_498, 0) >> 20);
        b = func_02094000_inline(&data_0217561c->mUnk_498, 0x5555);
        k = func_02148714(g->mUnk_18.z - g->mUnk_24.z, g->mUnk_18.x - g->mUnk_24.x) + b - 0x2aaa;
        func_02094000_inline_2(&o->mUnk_bc, func_02094000_inline(&data_0217561c->mUnk_498, 0x10000), k, c + 0x1000, 0,
                               e + 0x60, 0);
    } else {
        e = func_02094000_inline(&data_0217561c->mUnk_498, 0x30);
        c = (u16) (func_02094000_inline(&data_0217561c->mUnk_498, 0) >> 20);
        func_02094000_inline_2(&o->mUnk_bc, func_02094000_inline(&data_0217561c->mUnk_498, 0x10000),
                               (u16) func_02094000_inline(&data_0217561c->mUnk_498, 0x10000), c + 0x1000, 0, e + 0x60,
                               0);
    }
    d = func_02094000_inline(&data_0217561c->mUnk_498, 0x80);
    f = func_02094000_inline(&data_0217561c->mUnk_498, 0xa000);
    func_02094000_inline_2(&o->mUnk_dc, 0, func_02094000_inline(&data_0217561c->mUnk_498, 0x19000) + 0x19000,
                           f + 0xa000, 0, d + 0x100, 0);
    o->mUnk_10c = func_02094000_inline(&data_0217561c->mUnk_498, 0x3c000) + 0x3c000;
    p = func_02094000_inline(&data_0217561c->mUnk_498, 0xc000) + 0xe000;
    q = func_02094000_inline(&data_0217561c->mUnk_498, 0x200) + 0x400;
    o->mUnk_fc = 0;
    o->mUnk_100 = q;
    o->mUnk_104 = 0x2000;
    o->mUnk_108 = p;
    if (func_02061818() == 2) {
        o->mUnk_b4 = 0;
        o->mUnk_b8 = 0xffff;
        o->mUnk_110 = 0;
    } else {
        o->mUnk_b4 = (u16) func_02094000_inline(&data_0217561c->mUnk_498, 0x4b);
        o->mUnk_b8 = (u16) func_02094000_inline(&data_0217561c->mUnk_498, 0x96) + 0x12c;
        o->mUnk_110 = 1;
    }
    data_0217b0d8++;
}

s32 func_02093ff0(void) {
    return data_0217b0d8;
}
