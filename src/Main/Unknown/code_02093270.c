#include "Main/Unknown/code_02093270.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_020d26f8.h"
#include "Main/Unknown/code_020d275c.h"
#include "Main/Unknown/code_020d3b10.h"
#include "Main/Unknown/code_020d7da8.h"
#include "Main/Unknown/code_020d8918.h"
#include "Main/Unknown/code_020d8cac.h"
#include "Main/Unknown/code_020e6b58.h"
#include "Main/Unknown/unk_02156000.h"
#include "Main/Unknown/unk_02166000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/unk_021759c0.h"

void func_02093270(void *a, Unk02093270 *p) {
    u16 n;
    s32 i;
    u8 c;

    switch (p->mUnk_ac) {
        case 0:
            p->mUnk_a0++;
            if (p->mUnk_a0 >= p->mUnk_00.mUnk_9c->mUnk_2a) {
                p->mUnk_a0 = 0;
                p->mUnk_ac = 1;
                p->mUnk_00.mUnk_02 &= ~1;
            }
            break;
        case 1:
            p->mUnk_a8 += 0x7b;
            if (p->mUnk_a8 >= 0x1000) {
                p->mUnk_a8 = 0x1000;
                p->mUnk_ac = 2;
            }
            p->mUnk_00.mUnk_58.y = ((s64) p->mUnk_00.mUnk_98->mUnk_10 * p->mUnk_a8) >> 12;
            break;
        case 2:
            p->mUnk_a0++;
            if (p->mUnk_a0 >= p->mUnk_00.mUnk_9c->mUnk_28) {
                p->mUnk_a0 = 0;
                p->mUnk_ac = 3;
            }
            func_020d275c(&p->mUnk_00, 0x170);
            break;
        case 3:
            p->mUnk_a8 -= 0x29;
            if (p->mUnk_a8 <= 0) {
                p->mUnk_a8 = 0;
                p->mUnk_ac = 0;
                p->mUnk_00.mUnk_02 |= data_usa_0215646c;
            }
            p->mUnk_00.mUnk_58.y = ((s64) p->mUnk_00.mUnk_98->mUnk_10 * p->mUnk_a8) >> 12;
            break;
        case 4:
            func_020d275c(&p->mUnk_00, 0x170);
            break;
    }
    n = func_0209b6ec(gMkdEfBurner);
    p->mUnk_a4++;
    if (p->mUnk_a4 >= n) {
        p->mUnk_a4 = 0;
    }
    if (p->mUnk_b0.mUnk_08 != 0xffff) {
        func_020d8cc8(&p->mUnk_b0);
        func_020d8a5c(&p->mUnk_b0, &p->mUnk_00.mUnk_04);
        p->mUnk_00.mUnk_04.y = p->mUnk_00.mUnk_04.y - p->mUnk_00.mUnk_58.y;
    } else {
        p->mUnk_00.mUnk_04.y = p->mUnk_00.mUnk_9c->mUnk_00.y - p->mUnk_00.mUnk_58.y;
    }
    c = data_021759c0->mUnk_3d0;
    for (i = 0; i < c; i++) {
        if (p->mUnk_d4[i] > 0) {
            p->mUnk_d4[i]--;
        }
    }
}

void func_02093484(Unk020e6fd4 *p) {
    s32 z;
    s32 i;
    Unk02093270 *e;
    u16 f;
    s32 n;

    if (p == 0) {
        return;
    }
    z = 0;
    f = data_usa_0215646c;
    for (i = 0; i < p->mUnk_04 && (e = p->mUnk_00[i]) != 0; i++) {
        e->mUnk_00.mUnk_04.y = e->mUnk_00.mUnk_9c->mUnk_00.y - e->mUnk_00.mUnk_58.y;
        if (e->mUnk_00.mUnk_9c->mUnk_26 < 0) {
            e->mUnk_b0.mUnk_08 = 0xffff;
        } else {
            func_020d7da8(&e->mUnk_b0, e->mUnk_00.mUnk_9c, z);
            n = (e->mUnk_00.mUnk_9c->mUnk_2e << 12) / 100;
            e->mUnk_b0.mUnk_04 = n;
            e->mUnk_b0.mUnk_10 = ((s64) n * e->mUnk_b0.mUnk_00->mUnk_00[e->mUnk_b0.mUnk_0c].mUnk_34) >> 12;
        }
        if (e->mUnk_00.mUnk_9c->mUnk_28 == 0 && e->mUnk_00.mUnk_9c->mUnk_2a == 0 && e->mUnk_00.mUnk_9c->mUnk_2c == 0) {
            e->mUnk_a8 = 0x1000;
            e->mUnk_ac = 4;
            e->mUnk_00.mUnk_02 &= ~1;
        } else {
            e->mUnk_a0++;
            if (e->mUnk_a0 >= e->mUnk_00.mUnk_9c->mUnk_2c) {
                e->mUnk_a0 = 0;
                e->mUnk_ac = 1;
                e->mUnk_00.mUnk_02 |= f;
                e->mUnk_00.mUnk_58.y = 0;
            }
        }
    }
}

void func_020935fc(void *a, Unk02093270 *p) {
    s32 s0;
    Vec3 s4;
    Vec3 s10;

    if (p->mUnk_a8 <= 0) {
        return;
    }
    func_0209b940(gMkdEfBurner, func_020d3c44());
    s0 = 0x1e;
    func_01ff9048(0x14, &s0, 1);
    func_01ff9048(0x19, func_020e6cbc(&p->mUnk_00.mUnk_04), 0xc);
    s4.y = p->mUnk_00.mUnk_58.y >> 4;
    s4.x = 0;
    s4.z = 0;
    func_01ff9048(0x1c, &s4, 3);
    s10.x = p->mUnk_a8;
    s10.y = s10.x;
    s10.z = s10.x;
    func_01ff9048(0x1b, &s10, 3);
    func_01ff9048(0x1b, &p->mUnk_00.mUnk_1c, 3);
    func_0209b6c8(gMkdEfBurner, p->mUnk_a4);
    func_0209bb2c(a, gMkdEfBurner, p);
}

void func_020936f0(void *a) {
    func_0209bbd0(a, gMkdEfBurner);
}

void func_02093708(Unk02093708 *p) {
    gMkdEfBurner = func_0209be84(p, gMkdEfBurnerNsbmdName);
    func_0209be1c(gMkdEfBurner, gMkdEfBurnerNsbtaName);
    func_0209b940(gMkdEfBurner, 0x3f);
    p->mUnk_1c = 1;
}

u8 func_02093754(Unk02093270 *a, Unk0206bcb0 *b, u8 *c, u8 *d) {
    u8 v;

    v = *d;
    if (a->mUnk_d4[b->mUnk_74] == 0 && func_020d26f8(&a->mUnk_00, b) != 0) {
        a->mUnk_00.mUnk_78 |= data_usa_02156470;
        a->mUnk_d4[b->mUnk_74] = 0x1f;
    }
    return v;
}
