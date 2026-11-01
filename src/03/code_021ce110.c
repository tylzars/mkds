#include "03/code_021ce110.h"
#include "03/code_021cdc10.h"
#include "03/code_021cdcf0.h"
#include "03/code_021d1000.h"
#include "03/code_021d3488.h"
#include "03/code_021d1770.h"
#include "03/code_021d1970.h"
#include "03/code_021d27d8.h"
#include "03/code_021d34c8.h"
#include "03/code_021d3544.h"
#include "code_02134d30.h"
#include "code_0200f5ac.h"

void func_ov003_021ce110(Unk021d34e0 *a) {
    s32 i;
    s32 w;
    s32 h;
    func_ov003_021d1770(data_ov003_021da27c->mUnk_00[4], 0, (u32 *) &w, &h);
    w += 8;
    if (w < data_ov003_021d66a8[4].mUnk_00 || w > 0x100) {
        for (i = 4; i < 5; i++) {
            func_ov003_021d17d4(data_ov003_021da27c->mUnk_00[i], -1, w, data_ov003_021d66a8[i].mUnk_02);
        }
        return;
    }
    w = data_ov003_021d66a8[4].mUnk_00;
    for (i = 4; i < 5; i++) {
        func_ov003_021d17d4(data_ov003_021da27c->mUnk_00[i], -1, w, data_ov003_021d66a8[i].mUnk_02);
    }
    func_ov003_021d34e0(a, func_ov003_021ce0f0);
}

void func_ov003_021ce190(Unk021d34e0 *a) {
    s32 i;
    s32 w;
    s32 h;
    func_ov003_021d1770(data_ov003_021da27c->mUnk_00[3], 0, (u32 *) &w, &h);
    w += 8;
    if (w < data_ov003_021d66a8[3].mUnk_00 || w > 0x100) {
        for (i = 3; i < 5; i++) {
            func_ov003_021d17d4(data_ov003_021da27c->mUnk_00[i], -1, w, data_ov003_021d66a8[i].mUnk_02);
        }
        return;
    }
    w = data_ov003_021d66a8[3].mUnk_00;
    for (i = 3; i < 5; i++) {
        func_ov003_021d17d4(data_ov003_021da27c->mUnk_00[i], -1, w, data_ov003_021d66a8[i].mUnk_02);
    }
    func_ov003_021d34e0(a, func_ov003_021ce110);
}

void func_ov003_021ce230(Unk021d34e0 *a) {
    s32 i;
    s32 w;
    s32 h;
    func_ov003_021d1770(data_ov003_021da27c->mUnk_00[2], 0, (u32 *) &w, &h);
    w += 8;
    if (w < data_ov003_021d66a8[2].mUnk_00 || w > 0x100) {
        for (i = 2; i < 5; i++) {
            func_ov003_021d17d4(data_ov003_021da27c->mUnk_00[i], -1, w, data_ov003_021d66a8[i].mUnk_02);
        }
        return;
    }
    w = data_ov003_021d66a8[2].mUnk_00;
    for (i = 2; i < 5; i++) {
        func_ov003_021d17d4(data_ov003_021da27c->mUnk_00[i], -1, w, data_ov003_021d66a8[i].mUnk_02);
    }
    func_ov003_021d34e0(a, func_ov003_021ce190);
}

void func_ov003_021ce2d0(Unk021d34e0 *a) {
    s32 i;
    s32 w;
    s32 h;
    func_ov003_021d1770(data_ov003_021da27c->mUnk_00[1], 0, (u32 *) &w, &h);
    w += 8;
    if (w < data_ov003_021d66a8[1].mUnk_00 || w > 0x100) {
        for (i = 1; i < 5; i++) {
            func_ov003_021d17d4(data_ov003_021da27c->mUnk_00[i], -1, w, data_ov003_021d66a8[i].mUnk_02);
        }
        return;
    }
    w = data_ov003_021d66a8[1].mUnk_00;
    for (i = 1; i < 5; i++) {
        func_ov003_021d17d4(data_ov003_021da27c->mUnk_00[i], -1, w, data_ov003_021d66a8[i].mUnk_02);
    }
    func_ov003_021d34e0(a, func_ov003_021ce230);
}

void func_ov003_021ce370(Unk021d34e0 *a) {
    s32 i;
    s32 w;
    s32 h;
    func_ov003_021d1770(data_ov003_021da27c->mUnk_00[0], 0, (u32 *) &w, &h);
    w += 8;
    if (w < data_ov003_021d66a8[0].mUnk_00 || w > 0x100) {
        for (i = 0; i < 5; i++) {
            func_ov003_021d17d4(data_ov003_021da27c->mUnk_00[i], -1, w, data_ov003_021d66a8[i].mUnk_02);
        }
        return;
    }
    w = data_ov003_021d66a8[0].mUnk_00;
    for (i = 0; i < 5; i++) {
        func_ov003_021d17d4(data_ov003_021da27c->mUnk_00[i], -1, w, data_ov003_021d66a8[i].mUnk_02);
    }
    func_ov003_021d34e0(a, func_ov003_021ce2d0);
}

// non-matching: the original loads r5 (object offset from the counter at [sp, #4]) before r7 and the stack pointer, and
// steps r5 second in the loop; ours loads r5 after them and steps it last, same size
void func_ov003_021ce408(u32 a) {
    s32 i;
    u8 *b;
    Unk021cdd48_66a8 *d;
    u8 *c;
    data_ov003_021da27c = func_ov003_021d283c(0x1c, 4);
    i = 0;
    b = data_ov003_021d6688 + a * 5;
    d = data_ov003_021d66a8;
    c = data_ov003_021d6698 + a * 5;
    for (; i < 5; i++) {
        data_ov003_021da27c->mUnk_00[i] = (Unk021d1770 *) func_ov003_021d1be4(1, *b, 1);
        func_ov003_021d1790(data_ov003_021da27c->mUnk_00[i], -1, 0);
        func_ov003_021d17d4(data_ov003_021da27c->mUnk_00[i], -1, -0x2a, d->mUnk_02);
        func_ov003_021d1890(data_ov003_021da27c->mUnk_00[i], -1, 0, *c);
        b++;
        d++;
        c++;
    }
    data_ov003_021da27c->mTask = func_ov003_021d3544(0, (u32) func_ov003_021ce370, 0, 0x78);
    func_ov003_021cdcf0(a);
    func_ov003_021cdc10(0xd);
}

void func_ov003_021ce4d4(u32 a) {
    u32 f;
    Unk021ce4d4 *o;
    u32 g;
    s32 i;
    u64 t = func_0200f5ac();
    o = (Unk021ce4d4 *) data_ov003_021da280;
    if (t >= *(u64 *) o->mUnk_1b74 + 0x17f898) {
        g = 0;
        f = 0;
        for (i = 0; i < 0x10; i++) {
            if (func_02134d30(o->mUnk_1300[i].mUnk_00, data_ov003_021d66bc, 6) != 0) {
                if (o->mUnk_1300[i].mUnk_06 != 0) {
                    f = 1;
                } else {
                    g = 1;
                }
            }
        }
        if (f != 0 && g != 0) {
            if (o->mUnk_1370 != 0) {
                o->mUnk_1370(2);
            }
        } else if (f != 0) {
            if (o->mUnk_1370 != 0) {
                o->mUnk_1370(1);
            }
        } else if (g == 0) {
            if (o->mUnk_1370 != 0) {
                o->mUnk_1370(0);
            }
        }
        ((Unk021ce4d4 *) data_ov003_021da280)->mUnk_1b7c = 0;
        ((Unk021ce4d4 *) data_ov003_021da280)->mUnk_1b82 = 1;
        func_ov003_021d34c8(0, a);
    }
}
