#include "03/code_021c0a40.h"
#include "03/code_021bf8c0.h"
#include "03/code_021c04ec.h"
#include "03/code_021d1770.h"
#include "03/code_021d3488.h"
#include "03/unk_021d5f00.h"
#include "03/unk_021da000.h"

static inline void func_ov003_021c0ab0_inline(Unk021bf920 *p, u32 *x, u32 *y) {
    *x = (p->mUnk_00 & 0x1ff0000) >> 16;
    *y = p->mUnk_00 & 0xff;
}

void func_ov003_021c0c2c(u32 param_1) {
    s32 a;
    s32 y;
    func_ov003_021c0ab0_inline(data_ov003_021da15c->mUnk_030[0], (u32 *) &a, (u32 *) &y);
    y -= 12;
    if (y > data_ov003_021d5fb0[0][1]) {
        func_ov003_021c0154(data_ov003_021da15c->mUnk_11d, 0, y);
        return;
    }
    func_ov003_021c0154(data_ov003_021da15c->mUnk_11d, 0, data_ov003_021d5fb0[0][1]);
    func_ov003_021c0154(data_ov003_021da15c->mUnk_11d, 1, 0xc0);
    func_ov003_021d34e0((Unk021d34e0 *) param_1, func_ov003_021c0bb0);
}

void func_ov003_021c0bb0(u32 param_1) {
    s32 a;
    s32 y;
    func_ov003_021c0ab0_inline(data_ov003_021da15c->mUnk_030[12], (u32 *) &a, (u32 *) &y);
    y -= 12;
    if (y > data_ov003_021d5fb0[12][1]) {
        func_ov003_021c0154(data_ov003_021da15c->mUnk_11d, 1, y);
        return;
    }
    func_ov003_021c0154(data_ov003_021da15c->mUnk_11d, 1, data_ov003_021d5fb0[12][1]);
    func_ov003_021c0154(data_ov003_021da15c->mUnk_11d, 2, 0xc0);
    func_ov003_021d34e0((Unk021d34e0 *) param_1, func_ov003_021c0b30);
}

void func_ov003_021c0b30(u32 param_1) {
    s32 a;
    s32 y;
    func_ov003_021c0ab0_inline(data_ov003_021da15c->mUnk_030[24], (u32 *) &a, (u32 *) &y);
    y -= 12;
    if (y > data_ov003_021d5ff0[8][1]) {
        func_ov003_021c0154(data_ov003_021da15c->mUnk_11d, 2, y);
        return;
    }
    func_ov003_021c0154(data_ov003_021da15c->mUnk_11d, 2, data_ov003_021d5ff0[8][1]);
    func_ov003_021c0154(data_ov003_021da15c->mUnk_11d, 3, 0xc0);
    func_ov003_021d34e0((Unk021d34e0 *) param_1, func_ov003_021c0ab0);
}

void func_ov003_021c0ab0(u32 param_1) {
    s32 a;
    s32 b;
    func_ov003_021c0ab0_inline(data_ov003_021da15c->mUnk_030[36], (u32 *) &a, (u32 *) &b);
    b -= 12;
    if (b > data_ov003_021d6030[4][1]) {
        func_ov003_021c0154(data_ov003_021da15c->mUnk_11d, 3, b);
        return;
    }
    func_ov003_021c0154(data_ov003_021da15c->mUnk_11d, 3, data_ov003_021d6030[4][1]);
    func_ov003_021c0154(data_ov003_021da15c->mUnk_11d, 4, 0xc0);
    func_ov003_021d34e0((Unk021d34e0 *) param_1, func_ov003_021c0a40);
}

void func_ov003_021c0a40(u32 param_1) {
    u32 x;
    s32 y;
    func_ov003_021d1770(data_ov003_021da15c->mUnk_0fc[0], 0, &x, &y);
    y -= 12;
    if (y > data_ov003_021d5f88[0][1]) {
        func_ov003_021c0154(data_ov003_021da15c->mUnk_11d, 4, y);
        return;
    }
    func_ov003_021c0154(data_ov003_021da15c->mUnk_11d, 4, data_ov003_021d5f88[0][1]);
    func_ov003_021bffb0();
    func_ov003_021d34e0((Unk021d34e0 *) param_1, func_ov003_021c0a24);
}
