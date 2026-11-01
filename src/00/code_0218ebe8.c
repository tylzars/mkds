#include "00/code_0218ebe8.h"
#include "00/code_02194808.h"
#include "00/code_021948f8.h"
#include "00/code_02196590.h"
#include "00/code_02196914.h"
#include "00/unk_021b23b0.h"
#include "code_0213442c.h"
#include "code_02134d30.h"

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
        func_02134de0(c, 0, 0x210);
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
