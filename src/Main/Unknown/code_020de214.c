#include "Main/Unknown/code_020de214.h"
#include "Main/Unknown/code_020e43a8.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_020d49d8.h"
#include "Main/Unknown/code_020e6f50.h"
#include "Main/Unknown/code_020ec1fc.h"
#include "Main/Unknown/code_020ec538.h"
#include "Main/Unknown/code_020ec884.h"
#include "Main/Unknown/code_02036bec.h"
#include "code_02147cd8.h"
#include "Main/Unknown/unk_0217b000.h"

#pragma thumb on
void func_020de3e0(Unk020e43a8 *a) {
    a->mUnk_00.mUnk_04.y += (s32) (((s64) a->mUnk_00.mUnk_1c.y * 0xd000) >> 12);
    func_020ec854(a, a->mUnk_00.mUnk_04.y - 0xc0000, 0x400, 0x400, 0x5000, 0x2000);
    func_020ec884(a);
}
#pragma thumb off

Unk020de390 *func_020de390(void) {
    Unk020de390 *p;

    p = func_02036bec(func_020364e0(func_020364e8()), 0x40);
    *p = data_02158460;
    return p;
}

Unk020de334 *func_020de334(void) {
    data_0217b6dc = func_02036bec(func_020364e0(func_020364e8()), 0x2c);
    *data_0217b6dc = data_02158434;
    func_020d49d8(&data_0217b6dc);
    return data_0217b6dc;
}

Unk020de2d8 *func_020de2d8(void) {
    data_0217b6e0 = func_02036bec(func_020364e0(func_020364e8()), 0x28);
    *data_0217b6e0 = data_0215840c;
    func_020e6f50(&data_0217b6e0);
    return data_0217b6e0;
}

void func_020de270(void *a, Unk020de000 *b, s32 c, u16 d) {
    func_020ddaa0(&b->mUnk_a4, gWanwanChain, c, d);
    if (b->mUnk_f4 == 0) {
        return;
    }
    func_020dda38(&b->mUnk_a4, gWanwanKui, &b->mUnk_04, c, d);
}

void func_020de214(void *a, Unk020de000 *b) {
    Vec3 v;
    Unk020dc474 *p;

    p = b->mUnk_a0;
    if (b->mUnk_f4 == 0) {
        b->mUnk_04 = p->mUnk_00.mUnk_04;
    }
    func_02147fd8(-p->mUnk_f0, &p->mUnk_00.mUnk_28.mUnk_18, &p->mUnk_00.mUnk_04, &v);
    func_020ddb44(&b->mUnk_a4, &v, &p->mUnk_00.mUnk_10);
}
