#include "03/code_021cd5e0.h"
#include "03/code_021cd2e0.h"
#include "code_02134d30.h"
#include "code_021510a4.h"
#include "code_0214d018.h"

void func_ov003_021cd5e0(const Unk021cd5e0_arg *a) {
    Unk021cd5e0_400 *p;
    u32 n;
    s32 i;
    u8 *v1;
    u8 *v2;
    p = &data_ov003_021da270->mUnk_400;
    func_0214d168(p, 0, 0xef);
    func_0214d1fc(a, p->mUnk_00.mUnk_40, 0x20);
    switch (a->mUnk_20) {
        case 1:
            p->mUnk_00.mUnk_e6_0 = 1;
            n = 5;
            break;
        case 2:
            p->mUnk_00.mUnk_e6_0 = 2;
            n = 0xd;
            break;
        case 3:
            p->mUnk_00.mUnk_e6_0 = 3;
            n = 0x10;
            break;
        default:
            p->mUnk_00.mUnk_e6_0 = 0;
            n = 0;
            break;
    }
    p->mUnk_00.mUnk_e6_2 = 0;
    i = 0;
    v2 = p->mUnk_00.mUnk_80[0];
    v1 = (u8 *) a->mUnk_28;
    for (; i < 4; i++) {
        func_0214d1fc(v1, v2, n);
        v2 += 0x10;
        v1 += 0x20;
    }
    p->mUnk_00.mUnk_e7 = 2;
    func_0214d168(p->mUnk_f0, 0, 4);
    p->mUnk_f5 = 1;
    p->mUnk_f6 = 1;
    func_ov003_021cd6d0();
}

void func_ov003_021cd6d0(void) {
    Unk021cd5e0_400 *p = &data_ov003_021da270->mUnk_400;
    Unk021cd5e0_entry *q = &data_ov003_021da270->mUnk_000[p->mUnk_f4].mUnk_00;
    *q = p->mUnk_00;
    if (p->mUnk_f5 != 0) {
        func_0214d168(q->mUnk_c0, 0, 4);
        func_0214d168(q->mUnk_c4, 0, 4);
        q->mUnk_d0 = 0;
    } else {
        func_0214d1fc(p->mUnk_00.mUnk_c0, q->mUnk_c0, 4);
        func_0214d1fc(p->mUnk_00.mUnk_c4, q->mUnk_c4, 4);
        q->mUnk_d0 = func_021516d8(p->mUnk_f0);
    }
    if (p->mUnk_f6 != 0) {
        func_0214d168(q->mUnk_c8, 0, 8);
    } else {
        func_0214d1fc(p->mUnk_00.mUnk_c8, q->mUnk_c8, 8);
    }
    func_ov003_021cd338(p->mUnk_f4);
}

void func_ov003_021cd790(s32 a) {
    Unk021cd5e0 *o = data_ov003_021da270;
    Unk021cd5e0_entry *q = &o->mUnk_000[a].mUnk_00;
    o->mUnk_400.mUnk_00 = *q;
    o->mUnk_400.mUnk_f4 = a;
    if (func_02134d30(q->mUnk_c0, data_ov003_021d6684, 4) != 0) {
        data_ov003_021da270->mUnk_400.mUnk_f5 = 0;
    } else {
        data_ov003_021da270->mUnk_400.mUnk_f5 = 1;
    }
    if (func_02134d30(q->mUnk_c8, data_ov003_021d6684, 4) != 0 ||
        func_02134d30(q->mUnk_c8 + 4, data_ov003_021d6684, 4) != 0) {
        data_ov003_021da270->mUnk_400.mUnk_f6 = 0;
    } else {
        data_ov003_021da270->mUnk_400.mUnk_f6 = 1;
    }
    func_021516b0(q->mUnk_d0, data_ov003_021da270->mUnk_400.mUnk_f0);
}
