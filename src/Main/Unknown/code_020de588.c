#include "Main/Unknown/code_020de588.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_020d49d8.h"
#include "Main/Unknown/code_020e512c.h"
#include "Main/Unknown/code_020e516c.h"
#include "Main/Unknown/code_020e66e4.h"
#include "Main/Unknown/code_020e6a74.h"
#include "Main/Unknown/code_020e6f50.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217b000.h"

#pragma thumb on
void func_020de84c(void) {
    s32 i;
    s32 j;
    s32 a;
    s32 b;
    u32 n;
    Unk020e6488 *p;

    func_020e6488(&data_0217b71c, FindMainRaceOrMainEffectMapObjFile("box.nsbmd"), 0, 0);
    func_020e6488(&data_0217b710, FindMainRaceOrMainEffectMapObjFile("question.nsbmd"), 0, 0);
    func_020e6ab8(data_0217b71c);
    func_020e6ab8(data_0217b710);
    p = data_0217b71c;
    p->mUnk_10 = p->mUnk_10 & 0x8000ffff;
    p->mUnk_10 = p->mUnk_10 | 0x52940000;
    p = data_0217b710;
    p->mUnk_10 = p->mUnk_10 & 0x8000ffff;
    p->mUnk_10 = p->mUnk_10 | 0x52940000;
    data_0217b704 = func_02036bec(func_020364e0(func_020364e8()), 0x1770);
    for (i = 0; i < 0x12c; i++) {
        n = (u16) (((u32) i << 16) / 0x12c) >> 4;
        a = data_0215d4b4[n * 2 + 1];
        b = data_0215d4b4[n * 2];
        data_0217b704[i].mUnk_00 = a;
        data_0217b704[i].mUnk_04 = b;
        data_0217b704[i].mUnk_08 = (s32) (((s64) a * a) >> 12);
        data_0217b704[i].mUnk_0c = (s32) (((s64) b * b) >> 12);
        data_0217b704[i].mUnk_10 = (s32) (((s64) a * b) >> 12);
    }
    data_0217b708 = func_02036bec(func_020364e0(func_020364e8()), 0x410);
    for (j = 0; j < 0x82; j++) {
        n = (u16) (((u32) j << 16) / 0x82) >> 4;
        data_0217b708[j].mUnk_00 = data_0215d4b4[n * 2 + 1];
        data_0217b708[j].mUnk_04 = data_0215d4b4[n * 2];
    }
    if (data_021759c0->mUnk_00 == 0x1d) {
        data_0217b71c->mUnk_14 &= 0xffff7fff;
        data_0217b710->mUnk_14 &= 0xffff7fff;
    }
}

void func_020de6a8(Unk020de6a8 *a, Unk020de6a8_1 *b) {
    Unk020f41c4_B *r;
    Vec3 v;
    s32 v1;

    a->mUnk_000.mUnk_04.y += 0xc000;
    a->mUnk_0fc = &a->mUnk_000.mUnk_04;
    r = func_020d22d0();
    r->mUnk_00 = r->mUnk_08 * r->mUnk_00 + r->mUnk_10;
    a->mUnk_0a0 = (u16) (((u64) (u32) (r->mUnk_00 >> 32) * 0x12c) >> 32);
    r = func_020d22d0();
    r->mUnk_00 = r->mUnk_08 * r->mUnk_00 + r->mUnk_10;
    a->mUnk_0a2 = (u16) (((u64) (u32) (r->mUnk_00 >> 32) * 0x82) >> 32);
    a->mUnk_0a4 = 0x80;
    if (b != 0) {
        if (a->mUnk_000.mUnk_00 == 0xc9 && b->mUnk_26 >= 0) {
            v1 = 1;
        } else {
            v1 = 0;
        }
        a->mUnk_0a8 = v1;
        a->mUnk_0ac = b->mUnk_34;
        a->mUnk_0f8 = 0;
    } else {
        a->mUnk_0a8 = 1;
        a->mUnk_0ac = 0;
        a->mUnk_0f8 = 1;
        func_020d29cc(&a->mUnk_000, (Vec3 *) data_02158694);
    }
    if (a->mUnk_0f8 != 0) {
        a->mUnk_0f2 = 0;
        a->mUnk_0f4 = 0;
    } else {
        a->mUnk_0f2 = b->mUnk_2a;
        a->mUnk_0f4 = b->mUnk_2c;
    }
    if (a->mUnk_0f8 != 0) {
        a->mUnk_0b0 = 1;
    } else {
        a->mUnk_0b0 = b->mUnk_2e;
        if (a->mUnk_0b0 == 0) {
            v = b->mUnk_00;
            if (a->mUnk_0a8 != 0) {
                v.y += 0x800;
            }
            if (func_020e516c(&a->mUnk_0b4, &v, 0x14000, 0xd) == 0) {
                a->mUnk_0b0 = 2;
            }
        }
    }
    if (b != 0) {
        if (func_020e512c(&b->mUnk_00) != 0) {
            a->mUnk_000.mUnk_02 |= data_02158568;
        }
    }
    a->mUnk_000.mUnk_78 |= data_0215856c;
}
#pragma thumb off

Unk020de390 *func_020de658(void) {
    Unk020de390 *p;

    p = func_02036bec(func_020364e0(func_020364e8()), 0x40);
    *p = data_02158528;
    return p;
}

Unk020de334 *func_020de5fc(void) {
    data_0217b6f8 = func_02036bec(func_020364e0(func_020364e8()), 0x2c);
    *data_0217b6f8 = data_021584fc;
    func_020d49d8(&data_0217b6f8);
    return data_0217b6f8;
}

Unk020de2d8 *func_020de5a0(void) {
    data_0217b6ec = func_02036bec(func_020364e0(func_020364e8()), 0x28);
    *data_0217b6ec = data_021584d4;
    func_020e6f50(&data_0217b6ec);
    return data_0217b6ec;
}

void func_020de588(void) {
    func_020e6a18(data_0217b6f0);
}
