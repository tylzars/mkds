#include "01/code_021a1bb8.h"
#include "Main/Unknown/code_02056000.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_02029520.h"
#include "Main/Unknown/code_02061808.h"
#include "Main/Unknown/code_0208b000.h"
#include "Main/Unknown/code_020b4000.h"
#include "00/code_02182fdc.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_0209bef0.h"

void func_ov001_021a2300(Unk021a2300 *p) {
    s32 i;
    Unk021a2048 *o;
    Unk0217561c *d;
    Unk020f41c4_B *b;

    if (p != 0) {
        i = 0;
        while (i < p->mUnk_04 && (o = p->mUnk_00[i]) != 0) {
            d = data_0217561c;
            b = &d->mUnk_498;
            b->mUnk_00 = (s64) b->mUnk_08 * (s64) b->mUnk_00 + b->mUnk_10;
            o->mUnk_a0 = (u16) (((s64) (b->mUnk_00 >> 32) * 0x46) >> 32);
            o->mUnk_02 &= ~2;
            o->mUnk_02 &= ~8;
            o->mUnk_66 = 0x1f;
            i++;
        }
    }
}

void func_ov001_021a2284(void *p0, Unk021a2048 *p1) {
    Unk0217561c *d;
    Unk020f41c4_B *b;

    p1->mUnk_a0 -= 1;
    if (p1->mUnk_a0 < 0) {
        d = data_0217561c;
        b = &d->mUnk_498;
        b->mUnk_00 = (s64) b->mUnk_08 * (s64) b->mUnk_00 + b->mUnk_10;
        p1->mUnk_a0 = (u16) (((s64) (b->mUnk_00 >> 32) * 0x46) >> 32) + 0x46;
        if (!(p1->mUnk_02 & 0x12)) {
            func_0208b7bc(0x435, &p1->mUnk_04);
        }
    }
}

void *func_ov001_021a226c(void) {
    return (void *) func_0209bf48(func_ov001_021a2300, func_ov001_021a2284, 0);
}

void func_ov001_021a2218(Unk021a2048 *o, Unk02061808 *g, Vec3 *out) {
    out->x = g->mUnk_024.x + (s32) (((s64) g->mUnk_15c.x * 0x58000) >> 12);
    out->y = o->mUnk_04.y;
    out->z = g->mUnk_024.z + (s32) (((s64) g->mUnk_15c.z * 0x58000) >> 12);
}

void func_ov001_021a2048(void *p0, Unk021a2048 *p1) {
    Unk02061808 *g;
    Vec3 v = {0, 0, 0};

    g = func_02061808();
    switch (p1->mUnk_a0) {
        case 0:
            p1->mUnk_a0 = 1;
            switch (p1->mUnk_9c->mUnk_28) {
                case 0:
                    func_0208b7bc(0x400, &v);
                    func_0208b7bc(0x3ff, &v);
                    func_0208b7bc(0x402, &v);
                    func_0208b7bc(0x403, &v);
                    func_0208b7bc(0x404, &v);
                    func_0208b7bc(0x405, &v);
                    func_0208b7bc(0x406, &v);
                    func_0208b7bc(0x407, &v);
                    func_0208b7bc(0x408, &v);
                    func_0208b7bc(0x409, &v);
                    func_0208b7bc(0x40a, &v);
                    func_0208b7bc(0x40b, &v);
                    p1->mUnk_a4 = func_0208b7bc(0x42f, &g->mUnk_024);
                    break;
                case 1:
                    break;
                case 2:
                    func_0208b7bc(0x43c, &v);
                    func_0208b7bc(0x439, &v);
                    func_0208b7bc(0x43a, &v);
                    func_0208b7bc(0x43b, &v);
                    func_0208b7bc(0x438, &v);
                    func_0208b7bc(0x43d, &v);
                    func_0208b7bc(0x43e, &v);
                    func_0208b7bc(0x43f, &v);
                    func_ov001_021a2218(p1, g, &v);
                    p1->mUnk_a4 = func_0208b7bc(0x437, &v);
                    break;
            }
            break;
        case 1:
            switch (p1->mUnk_9c->mUnk_28) {
                case 0:
                    func_0208b5b0(p1->mUnk_a4, &g->mUnk_024);
                    break;
                case 1:
                    break;
                case 2:
                    func_ov001_021a2218(p1, g, &v);
                    func_0208b5b0(p1->mUnk_a4, &v);
                    break;
            }
            break;
    }
}

void *func_ov001_021a2034(void) {
    return (void *) func_0209bf48(0, func_ov001_021a2048, 0);
}

void func_ov001_021a1f60(void) {
    Unk020b4934 *l0 = 0;
    Unk02021dc8 *l1 = 0;
    Unk020b4a44 *l2 = 0;
    Unk020b4934 *l3 = 0;
    Unk02021dc8 *l4 = 0;
    Unk020b4a44 *l5 = 0;
    Unk020b4934 *l6 = 0;
    Unk020b47d8 *l7 = 0;
    Unk020b4a44 *l8 = 0;

    func_020b496c(&l6, func_0204799c(data_ov001_021a94ec));
    func_020b4a7c(&l8, func_0204799c(data_ov001_021a9508));
    func_020b4810(&l7, func_0204799c(data_ov001_021a94f0));
    func_020b49f4(&l0, func_0204799c(data_ov001_021a94dc));
    func_020b48ec(&l1, func_0204799c(data_ov001_021a94e4));
    func_020b4a7c(&l2, func_0204799c(data_ov001_021a950c));
    func_020b49f4(&l3, func_0204799c(data_ov001_021a94f4));
    func_020b48ec(&l4, func_0204799c(data_ov001_021a94f8));
    func_020b4a7c(&l5, func_0204799c(data_ov001_021a94fc));
}

void func_ov001_021a1d78(void) {
    Unk020b4934 *a = 0;
    Unk020b4a44 *b = 0;
    Unk020b4934 *c = 0;
    Unk020b4a44 *d = 0;
    Unk020b4934 *e = 0;
    Unk020b47d8 *f = 0;
    Unk020b4a44 *g = 0;
    u16 *h;

    func_020b4934(&e, func_0204799c(data_ov001_021a94ec));
    func_020b4a44(&g, func_0204799c(data_ov001_021a9508));
    func_020b47d8(&f, func_0204799c(data_ov001_021a94f0));
    data_ov001_021ca418->mUnk_1c = func_02036bec(data_ov001_021ca418->mUnk_20, 0x800);
    data_ov001_021ca418->mUnk_04 = func_0204799c(data_ov001_021a9504);
    func_020b49bc(&a, func_0204799c(data_ov001_021a94dc));
    func_020b48b4(&data_ov001_021ca418->mUnk_00, func_0204799c(data_ov001_021a94e4));
    func_020b4a44(&b, func_0204799c(data_ov001_021a950c));
    func_020b49bc(&c, func_0204799c(data_ov001_021a94f4));
    func_020b48b4(&data_ov001_021ca418->mUnk_08, func_0204799c(data_ov001_021a94f8));
    func_020b4a44(&d, func_0204799c(data_ov001_021a94fc));
    if (func_02056dec(0x10) != 0) {
        data_ov001_021ca418->mUnk_0c = func_0204799c(data_ov001_021a94e8);
        data_ov001_021ca418->mUnk_10 = func_0204799c(data_ov001_021a9510);
    } else {
        data_ov001_021ca418->mUnk_0c = func_0204799c(data_ov001_021a9500);
        data_ov001_021ca418->mUnk_10 = func_0204799c(data_ov001_021a94e0);
    }
    h = b->mUnk_0c;
    func_02016468(4, 0, e->mUnk_14, e->mUnk_10);
    func_02016468(0xf, 0, g->mUnk_0c, 0x100);
    func_02016468(8, 0, f->mUnk_0c, f->mUnk_08);
    func_02016468(8, 0x800, data_ov001_021ca418->mUnk_1c, 0x800);
    func_02016468(0x13, 0, a->mUnk_14, a->mUnk_10);
    func_02016468(0xe, 0, b->mUnk_0c, 0x1a0);
    func_02016468(0xe, 0x1c0, (u8 *) h + 0x1c0, 0x40);
    func_02016468(0x23, 0, c->mUnk_14, c->mUnk_10);
    func_02016468(0x1e, 0, d->mUnk_0c, d->mUnk_08);
}

void func_ov001_021a1cb0(void) {
    s32 i;
    s32 j;

    for (i = 0; i < 4; i++) {
        data_ov001_021ca418->mUnk_14[data_ov001_021a6f28[i]].mUnk_00 = 0;
        for (j = 0; j < 3; j++) {
            data_ov001_021ca418->mUnk_18[data_ov001_021a6fa0[i][j]].mUnk_00 = 0;
        }
    }
    for (i = 0; i < 6; i++) {
        data_ov001_021ca418->mUnk_14[data_ov001_021a6f68[i]].mUnk_00 = 1;
    }
    data_ov001_021ca418->mUnk_14[6].mUnk_00 = 1;
    data_ov001_021ca418->mUnk_14[data_ov001_021a6f28[data_ov001_021ca418->mUnk_34]].mUnk_00 = 1;
    for (i = 0; i < 4; i++) {
        data_ov001_021ca418->mUnk_18[data_ov001_021a6fa0[i][0]].mUnk_00 = 1;
        func_02124a98(data_ov001_021a6fa0[i][0], 1, data_ov001_021ca418->mUnk_08, data_ov001_021ca418->mUnk_0c);
    }
    func_02124a98(2, 1, data_ov001_021ca418->mUnk_00, data_ov001_021ca418->mUnk_04);
}

void func_ov001_021a1c34(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        data_ov001_021ca418->mUnk_18[data_ov001_021a6fa0[i][1]].mUnk_00 = 0;
        data_ov001_021ca418->mUnk_18[data_ov001_021a6fa0[i][2]].mUnk_00 = 0;
        if (data_ov001_021ca418->mUnk_34 == i && data_ov001_021ca418->mUnk_38 != 0) {
            data_ov001_021ca418->mUnk_18[data_ov001_021a6fa0[i][2]].mUnk_00 = 1;
        } else {
            data_ov001_021ca418->mUnk_18[data_ov001_021a6fa0[i][1]].mUnk_00 = 1;
        }
    }
    if (func_02056dec(0x10) == 0) {
        for (i = 0; i < 3; i++) {
            data_ov001_021ca418->mUnk_18[data_ov001_021a6fa0[3][i]].mUnk_00 = 0;
        }
    }
}

void func_ov001_021a1bf8(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        data_ov001_021ca418->mUnk_14[data_ov001_021a6f28[i]].mUnk_00 = 0;
    }
    data_ov001_021ca418->mUnk_14[data_ov001_021a6f28[data_ov001_021ca418->mUnk_34]].mUnk_00 = 1;
}

void func_ov001_021a1bb8(void) {
    if (data_ov001_021ca418->mUnk_34 == 3) {
        func_020295c0(data_ov001_021a6f90[2]);
        func_020295b0();
    } else {
        func_020295c0(data_ov001_021a6f90[data_ov001_021ca418->mUnk_34]);
        func_020295a0();
    }
    func_02029590(0);
}
