#include "03/code_021c1a60.h"
#include "03/code_021c105c.h"
#include "03/code_021c1000.h"
#include "03/code_021c1648.h"
#include "03/code_021d1770.h"
#include "03/code_021d3488.h"
#include "03/unk_021d6000.h"
#include "03/unk_021da000.h"

void func_ov003_021c1a60(Unk021d34e0 *param_1) {
    u32 a;
    s32 b;
    func_ov003_021d1770((Unk021d1770 *) data_ov003_021da160->mUnk_40[0], 0, &a, &b);
    b = b - 0xc;
    if (b > data_ov003_021d6244[1]) {
        func_ov003_021c1364(4, b);
        return;
    }
    func_ov003_021c1364(4, data_ov003_021d6244[1]);
    func_ov003_021c1268();
    func_ov003_021d34e0(param_1, func_ov003_021c1a44);
}

// non-matching: the original keeps the two coordinate locals in stack memory (extra stores and a reload after the
// call), size 0x50 against 0x68
void func_ov003_021c1abc(Unk021d34e0 *param_1) {
    u32 a;
    s32 b;
    Unk021bf920 *p;
    p = data_ov003_021da160->mUnk_10[9];
    a = (p->mUnk_00 & 0x1ff0000) >> 16;
    b = p->mUnk_00 & 0xff;
    b = b - 0xc;
    if (b > data_ov003_021d6274[19]) {
        func_ov003_021c1364(3, b);
        return;
    }
    func_ov003_021c1364(3, data_ov003_021d6274[19]);
    func_ov003_021c1364(4, 0xc0);
    func_ov003_021d34e0(param_1, func_ov003_021c1a60);
}

// non-matching: the original keeps the two coordinate locals in stack memory (extra stores and a reload after the
// call), size 0x50 against 0x68
void func_ov003_021c1b24(Unk021d34e0 *param_1) {
    u32 a;
    s32 b;
    Unk021bf920 *p;
    p = data_ov003_021da160->mUnk_10[6];
    a = (p->mUnk_00 & 0x1ff0000) >> 16;
    b = p->mUnk_00 & 0xff;
    b = b - 0xc;
    if (b > data_ov003_021d6274[13]) {
        func_ov003_021c1364(2, b);
        return;
    }
    func_ov003_021c1364(2, data_ov003_021d6274[13]);
    func_ov003_021c1364(3, 0xc0);
    func_ov003_021d34e0(param_1, func_ov003_021c1abc);
}

static inline void func_ov003_021c1b8c_inline(Unk021bf920 *p, u32 *x, u32 *y) {
    *x = (p->mUnk_00 & 0x1ff0000) >> 16;
    *y = p->mUnk_00 & 0xff;
}

void func_ov003_021c1b8c(Unk021d34e0 *param_1) {
    s32 a;
    s32 b;
    func_ov003_021c1b8c_inline(data_ov003_021da160->mUnk_10[3], (u32 *) &a, (u32 *) &b);
    b = b - 0xc;
    if (b > data_ov003_021d6274[7]) {
        func_ov003_021c1364(1, b);
        return;
    }
    func_ov003_021c1364(1, data_ov003_021d6274[7]);
    func_ov003_021c1364(2, 0xc0);
    func_ov003_021d34e0(param_1, func_ov003_021c1b24);
}

// non-matching: the original keeps the two coordinate locals in stack memory (extra stores and a reload after the
// call), size 0x50 against 0x68
void func_ov003_021c1bf4(Unk021d34e0 *param_1) {
    u32 a;
    s32 b;
    Unk021bf920 *p;
    p = data_ov003_021da160->mUnk_10[0];
    a = (p->mUnk_00 & 0x1ff0000) >> 16;
    b = p->mUnk_00 & 0xff;
    b = b - 0xc;
    if (b > data_ov003_021d6274[1]) {
        func_ov003_021c1364(0, b);
        return;
    }
    func_ov003_021c1364(0, data_ov003_021d6274[1]);
    func_ov003_021c1364(1, 0xc0);
    func_ov003_021d34e0(param_1, func_ov003_021c1b8c);
}
