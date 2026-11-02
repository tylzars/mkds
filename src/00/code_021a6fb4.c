#include "00/code_021a6fb4.h"
#include "03/code_021b94b8.h"
#include "00/code_021a88a8.h"

#include "code_0200e77c.h"
#include "00/code_021a6d6c.h"
#include "00/unk_021b5000.h"
#include "code_0200dc3c.h"
#include "code_0200e0ec.h"
#include "Main/Unknown/code_0200edc0.h"

int func_ov000_021a72a4(Unk021a72a4 *param_1) {
    int v1;
    int v2;
    v1 = func_ov000_021a8a54((int) ((u32) param_1->mUnk_03 << 2));
    v2 = func_ov000_021a8a54((int) (param_1->mUnk_00));
    return v1 + v2;
}

u8 *func_ov000_021a71c0(Unk021a6fa8 *param_1, Unk021b49b8 *param_2) {
    u8 *a;
    Unk021a71c0 *b;
    Unk021a722a *c;

    param_1->mUnk_73 = param_2->mUnk_00;
    param_1->mUnk_72 = param_2->mUnk_01;
    a = (u8 *) &param_1->mUnk_80;
    if (param_2->mUnk_02 != 0) {
        b = &param_1->mUnk_80;
        param_1->mUnk_64 = a;
        b->mUnk_fc = param_2->mUnk_04;
        a = func_ov000_021a7154(b->mUnk_114, &b->mUnk_00, &param_2->mUnk_10);
        a = func_ov000_021a71a4(a, &param_1->mUnk_3c, param_2->mUnk_02);
        a = func_ov000_021a71a4(a, &param_1->mUnk_50, param_2->mUnk_08);
        b->mUnk_10a = param_2->mUnk_0e;
        b->mUnk_10c.mUnk_04 = 0;
        b->mUnk_10c.mUnk_00 = b->mUnk_10c.mUnk_04;
    }
    if (param_2->mUnk_06 != 0) {
        c = (Unk021a722a *) a;
        param_1->mUnk_68 = a;
        c->mUnk_10c = param_1;
        a = func_ov000_021a7154(c->mUnk_110, &c->mUnk_00, &param_2->mUnk_14);
        a = func_ov000_021a71a4(a, &param_1->mUnk_48, param_2->mUnk_06);
        a = func_ov000_021a71a4(a, &param_1->mUnk_58, param_2->mUnk_0a);
        a = func_ov000_021a71a4(a, &c->mUnk_f8, param_2->mUnk_0c);
        c->mUnk_108 = 0;
        c->mUnk_104 = c->mUnk_108;
    } else {
        param_1->mUnk_68 = data_ov000_021b5fa4->mUnk_68;
    }
    return a;
}

u8 *func_ov000_021a71a4(u8 *param_1, Unk021a71a4 *param_2, s32 param_3) {
    u8 *v1;
    v1 = param_1;
    if (param_3 == 0) {
        v1 = 0;
    }
    param_2->mUnk_04 = v1;
    param_2->mUnk_00 = param_3;
    return param_1 + func_ov000_021a8a54(param_3);
}

u8 *func_ov000_021a7154(u8 *param_1, Unk021a7154 *param_2, Unk021a72a4 *param_3) {
    u8 *a;

    a = param_1 + func_ov000_021a72a4(param_3);
    func_0200eb90(&param_2->mUnk_00, (void **) param_1, param_3->mUnk_03);
    func_0200edc0(&param_2->mUnk_e0);
    func_0200e28c(&param_2->mUnk_20, func_ov000_021a6f18, param_2, a, param_3->mUnk_00, param_3->mUnk_02);
    func_0200df68(&param_2->mUnk_20);
    return a;
}

s32 func_ov000_021a70ec(s32 param_1) {
    s32 a;
    void **b;
    Unk021a7064 *c;
    s32 d;

    a = (param_1 * 4 + 3) & ~3;
    d = (param_1 * 0x2c + 3) & ~3;
    b = data_ov000_021b5f94->mUnk_18(d + a);
    if (b == 0) {
        return -1;
    }
    func_0200eb90(&data_ov000_021b5fdc, b, param_1);
    c = (Unk021a7064 *) ((u8 *) b + a);
    if (param_1 > 0) {
        do {
            func_ov000_021a7048(c);
            c++;
            param_1--;
        } while (param_1 > 0);
    }
    data_ov000_021b5fd8 = b;
    return 0;
}

s32 func_ov000_021a70b0(void) {
    if (data_ov000_021b5fdc.mUnk_1c < data_ov000_021b5fdc.mUnk_14) {
        return -1;
    }
    data_ov000_021b5f94->mUnk_1c(data_ov000_021b5fd8);
    data_ov000_021b5fd8 = 0;
    return 0;
}

Unk021a7064 *func_ov000_021a7088(s32 param_1) {
    int v1;
    Unk021a7064 *v2[1];
    v1 = func_0200ea3c(&data_ov000_021b5fdc, (void **) (v2), (s32) (param_1));
    if (v1 != 0) {
        return v2[0];
    }
    return 0;
}

Unk021a7064 *func_ov000_021a7064(Unk021a7064Func param_1, Unk021a6fa8 *param_2, s32 param_3) {
    Unk021a7064 *a;

    a = func_ov000_021a7088(param_3);
    if (a != 0) {
        a->mUnk_00 = param_1;
        a->mUnk_04 = param_2;
        a->mUnk_0d = param_3;
        a->mUnk_0c = param_2->mUnk_73;
    }
    return a;
}

void func_ov000_021a7048(Unk021a7064 *param_1) {
    if (param_1 != 0) {
        ((u32) func_0200eae8(&data_ov000_021b5fdc, (void *) (param_1), 0));
    }
    return;
}

s32 func_ov000_021a7008(Unk021a7154 *param_1, Unk021a7064 *param_2) {
    s32 a;

    a = func_0200eae8(&param_1->mUnk_00, param_2, param_2 != 0 ? param_2->mUnk_0d : 1);
    if (a == 0) {
        func_ov000_021a7048(param_2);
    }
    if (a != 0) {
        return 0;
    }
    return -42;
}

s32 func_ov000_021a6fc0(Unk021a7154 *param_1, Unk021a7064 *param_2) {
    s32 a;
    void *b;
    Unk0200eb90 c;

    if (param_2->mUnk_0d == 0) {
        param_2->mUnk_08 = 0;
        a = func_ov000_021a7008(param_1, param_2);
    } else {
        func_0200eb90(&c, &b, 1);
        param_2->mUnk_08 = &c;
        func_ov000_021a7008(param_1, param_2);
        func_0200ea3c(&c, (void **) &a, 1);
    }
    return a;
}

s32 func_ov000_021a6fb4(Unk021a6fa8 *param_1, Unk021a7064 *param_2) {
    return func_ov000_021a6fc0(param_1->mUnk_64, param_2);
}
