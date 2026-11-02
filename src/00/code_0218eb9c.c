#include "00/code_0218eb9c.h"
#include "00/code_021947e4.h"
#include "00/code_02196000.h"
#include "00/code_021a3000.h"
#include "00/code_0218f15c.h"
#include "00/code_02190000.h"

#include "00/code_02194808.h"
#include "00/code_021948f8.h"
#include "00/code_02196590.h"
#include "00/code_02196914.h"
#include "00/unk_021b23b0.h"
#include "code_0213442c.h"
#include "code_02134d30.h"
#include "00/code_0218f960.h"
#include "code_02139f70.h"
#include "00/code_0218d000.h"
#include "00/unk_021b2000.h"
#include "00/code_0218dc44.h"
#include "00/code_0218e368.h"
#include "00/code_021965a0.h"
#include "00/code_02190ba0.h"
#include "code_02135014.h"
#include "00/code_021906e4.h"
#include "00/code_0219218c.h"
#include "00/code_021960a4.h"

void func_ov000_0218f130(Unk0218f960 *a) {
    if (a != 0 && a->mUnk_00 != 0 && a->mUnk_00->mUnk_108 == 0) {
        func_ov000_02190ff8(a, 1);
        func_ov000_0218f654(a);
    }
    return;
}

u32 func_ov000_0218f0a8(Unk0218f960 *a, s8 *b, s8 *c, s8 *d, s8 *e, s8 *f, s32 g, u32 h, Unk0218f0a8Cb i, u32 j) {
    Unk0218f960_00 *o;
    if (a == 0 || (o = a->mUnk_00) == 0) {
        return 2;
    }
    if (i == 0) {
        func_ov000_02196590(a, data_ov000_021b242c);
        return 2;
    }
    if (o->mUnk_108 != 0) {
        Unk0218f0a8Arg k = {0};
        k.mUnk_08 = 0x601;
        i(a, &k, j);
        return 0;
    }
    return func_ov000_021960a4(a, b, c, d, e, f, g, 0, h, (u32) i, j);
}

u32 func_ov000_0218eff8(Unk0218f960 *a, u32 b, s32 c, u32 d, Unk0218eff8Cb e, u32 f) {
    Unk0218f960_00 *o;
    if (a == 0 || (o = a->mUnk_00) == 0 || b == 0) {
        return 2;
    }
    if (e == 0) {
        func_ov000_02196590(a, data_ov000_021b242c);
        return 2;
    }
    if (o->mUnk_108 != 0) {
        Unk0218eff8Arg g = {0};
        e(a, &g, f);
        return 0;
    }
    if (o->mUnk_1d8 == 4) {
        func_ov000_02196590(a, data_ov000_021b23e8);
        return 2;
    }
    return func_ov000_0219222c(a, b, c, d, (u32) e, f);
}

u32 func_ov000_0218efa8(Unk0218f960 *a, s32 b, const s8 *c) {
    Unk0218f960_00 *o;
    if (a == 0 || (o = a->mUnk_00) == 0) {
        return 2;
    }
    if (o->mUnk_108 != 0) {
        return 0;
    }
    if (o->mUnk_1d8 == 4) {
        func_ov000_02196590(a, data_ov000_021b23e8);
        return 2;
    }
    return func_ov000_021923b4(a, b, c);
}

u32 func_ov000_0218ee70(Unk0218f960 *a, u32 b, const u8 *c) {
    Unk0218f960_00 *o;
    u8 e[0x401];
    s8 *g;
    if (a == 0 || (o = a->mUnk_00) == 0) {
        return 2;
    }
    if (o->mUnk_108 != 0) {
        return 0;
    }
    if (o->mUnk_1d8 == 4) {
        func_ov000_02196590(a, data_ov000_021b23e8);
        return 2;
    }
    if (c == 0) {
        func_ov000_02196590(a, data_ov000_021b24dc);
        return 2;
    }
    func_ov000_02196914(e, c, 0x401);
    if (*(s8 *) e != 0) {
        g = (s8 *) e;
        do {
            if (*g == 0x5c) {
                *g = 0x2f;
            }
            g++;
        } while (*g != 0);
    }
    func_ov000_02190b80(a, &o->mUnk_1f4, data_ov000_021b24ec);
    func_ov000_02190b80(a, &o->mUnk_1f4, data_ov000_021b2418);
    func_ov000_02190b58(a, &o->mUnk_1f4, o->mUnk_198);
    func_ov000_02190b80(a, &o->mUnk_1f4, data_ov000_021b24f8);
    func_ov000_02190b58(a, &o->mUnk_1f4, b);
    func_ov000_02190b80(a, &o->mUnk_1f4, data_ov000_021b2508);
    func_ov000_02190b80(a, &o->mUnk_1f4, e);
    func_ov000_02190b80(a, &o->mUnk_1f4, data_ov000_021b2424);
    return 0;
}

u32 func_ov000_0218ee1c(Unk0218f960 *a, u32 b) {
    Unk0218f960_00 *o;
    if (a == 0 || (o = a->mUnk_00) == 0) {
        return 2;
    }
    if (o->mUnk_108 != 0) {
        return 0;
    }
    if (o->mUnk_1d8 == 4) {
        func_ov000_02196590(a, data_ov000_021b23e8);
        return 2;
    }
    return func_ov000_0218faac(a, b);
}

u32 func_ov000_0218ed74(Unk0218f960 *b, int c) {
    int v1;
    int v2;
    Unk0218f960_00 *a;
    int v3;
    if ((b == 0) || (a = b->mUnk_00, a == 0)) {
        return 2;
    }
    if (a->mUnk_108 != 0) {
        return 0;
    }
    if (a->mUnk_1d8 == 4) {
        func_ov000_02196590(b, data_ov000_021b23e8);
        return 2;
    }
    v1 = func_ov000_02194934(b, c, (Unk02194934 **) &v3);
    if (v1 == 0) {
        return 0;
    }
    *(s32 *) (v3 + 0x14) = *(s32 *) (v3 + 0x14) + -1;
    if ((a->mUnk_100 == 0) && (*(s32 *) (v3 + 0x14) <= 0)) {
        func_ov000_021a3668((void *) (*(u32 *) (v3 + 0x10)));
        *(u32 *) (v3 + 0x10) = 0;
        v2 = func_ov000_021947e4((Unk02194934 *) v3);
        if (v2 != 0) {
            func_ov000_021948f8(b, (Unk02194934 *) v3);
        }
    }
    return 0;
}

s32 func_ov000_0218ed44(Unk0218f960 *object, s32 *output) {
    Unk0218f960_00 *state;
    if (object == 0 || object->mUnk_00 == 0) {
        return 2;
    }
    state = object->mUnk_00;
    if (state->mUnk_108 != 0) {
        *output = 0;
        return 0;
    }
    *output = state->mUnk_430;
    return 0;
}

u32 func_ov000_0218ec44(Unk0218f960 *a, s32 b, Unk0218ec44 *c) {
    Unk0218f960_00 *o;
    Unk02194934 *e;
    Unk02194934_08 *n;
    void *v;
    s32 m;
    if (a == 0 || (o = a->mUnk_00) == 0) {
        return 2;
    }
    if (o->mUnk_108 != 0) {
        memset(c, 0, 0x210);
        return 0;
    }
    if (c == 0) {
        func_ov000_02196590(a, data_ov000_021b24a8);
        return 2;
    }
    m = o->mUnk_430;
    if (b < 0 || b >= m) {
        func_ov000_02196590(a, data_ov000_021b24b8);
        return 2;
    }
    e = (Unk02194934 *) func_ov000_02194808(a, b);
    if (e == 0) {
        func_ov000_02196590(a, data_ov000_021b24b8);
        return 2;
    }
    n = e->mUnk_08;
    if (n == 0) {
        func_0213442c(data_ov000_021b24c8, data_ov000_021b24d4, 0, 0x5cf);
    }
    c->mUnk_000 = e->mUnk_00;
    c->mUnk_004 = n->mUnk_04;
    v = n->mUnk_08;
    if (v != 0) {
        func_ov000_02196914(c->mUnk_008, v, 0x100);
    } else {
        *(u8 *) v = 0;
    }
    v = n->mUnk_0c;
    if (v != 0) {
        func_ov000_02196914(c->mUnk_108, v, 0x100);
    } else {
        *(u8 *) v = 0;
    }
    c->mUnk_208 = n->mUnk_10;
    c->mUnk_20c = n->mUnk_14;
    return 0;
}

u32 func_ov000_0218ebe8(Unk0218f960 *a, u32 b, s32 *c) {
    Unk0218f960_00 *o;
    Unk02194934 *e;
    if (a == 0 || (o = a->mUnk_00) == 0) {
        return 2;
    }
    if (o->mUnk_108 != 0) {
        *c = 0;
        return 0;
    }
    if (func_ov000_02194934(a, b, &e) != 0 && e->mUnk_08 != 0) {
        *c = e->mUnk_08->mUnk_00;
    } else {
        *c = -1;
    }
    return 0;
}

u32 func_ov000_0218eb9c(Unk0218f960 *a, u32 b) {
    int v1;
    int v2[1];
    if ((a == 0) || (a->mUnk_00 == 0)) {
        return 0;
    }
    if (a->mUnk_00->mUnk_108 != 0) {
        return 0;
    }
    v1 = func_ov000_02194934(a, b, (Unk02194934 **) v2);
    if ((v1 != 0) && (*(s32 *) (v2[0] + 8) != 0)) {
        return 1;
    }
    return 0;
}
