#include "00/code_021a6fb4.h"
#include "03/code_021b94b8.h"
#include "00/code_021a88a8.h"

#include "code_0200e77c.h"
#include "00/code_021a6d6c.h"
#include "00/unk_021b5000.h"
#include "code_0200dc3c.h"
#include "code_0200e0ec.h"
#include "code_0200edc0.h"

int func_ov000_021a72a4(Unk021a72a4 *a) {
    int v1;
    int v2;
    v1 = func_ov000_021a8a54(a->mUnk_03 << 2);
    v2 = func_ov000_021a8a54(a->mUnk_00);
    return v1 + v2;
}

u8 *func_ov000_021a71c0(Unk021a6fa8 *d, Unk021b49b8 *e) {
    u8 *a;
    Unk021a71c0 *b;
    Unk021a722a *c;

    d->mUnk_73 = e->mUnk_00;
    d->mUnk_72 = e->mUnk_01;
    a = (u8 *) &d->mUnk_80;
    if (e->mUnk_02 != 0) {
        b = &d->mUnk_80;
        d->mUnk_64 = a;
        b->mUnk_fc = e->mUnk_04;
        a = func_ov000_021a7154(b->mUnk_114, &b->mUnk_00, &e->mUnk_10);
        a = func_ov000_021a71a4(a, &d->mUnk_3c, e->mUnk_02);
        a = func_ov000_021a71a4(a, &d->mUnk_50, e->mUnk_08);
        b->mUnk_10a = e->mUnk_0e;
        b->mUnk_10c.mUnk_04 = 0;
        b->mUnk_10c.mUnk_00 = b->mUnk_10c.mUnk_04;
    }
    if (e->mUnk_06 != 0) {
        c = (Unk021a722a *) a;
        d->mUnk_68 = a;
        c->mUnk_10c = d;
        a = func_ov000_021a7154(c->mUnk_110, &c->mUnk_00, &e->mUnk_14);
        a = func_ov000_021a71a4(a, &d->mUnk_48, e->mUnk_06);
        a = func_ov000_021a71a4(a, &d->mUnk_58, e->mUnk_0a);
        a = func_ov000_021a71a4(a, &c->mUnk_f8, e->mUnk_0c);
        c->mUnk_108 = 0;
        c->mUnk_104 = c->mUnk_108;
    } else {
        d->mUnk_68 = data_ov000_021b5fa4->mUnk_68;
    }
    return a;
}

u8 *func_ov000_021a71a4(u8 *a, Unk021a71a4 *b, s32 c) {
    u8 *v1;
    v1 = a;
    if (c == 0) {
        v1 = 0;
    }
    b->mUnk_04 = v1;
    b->mUnk_00 = c;
    return a + func_ov000_021a8a54(c);
}

u8 *func_ov000_021a7154(u8 *b, Unk021a7154 *c, Unk021a72a4 *d) {
    u8 *a;

    a = b + func_ov000_021a72a4(d);
    func_0200eb90(&c->mUnk_00, (void **) b, d->mUnk_03);
    func_0200edc0(&c->mUnk_e0);
    func_0200e28c(&c->mUnk_20, func_ov000_021a6f18, c, a, d->mUnk_00, d->mUnk_02);
    func_0200df68(&c->mUnk_20);
    return a;
}

s32 func_ov000_021a70ec(s32 e) {
    s32 a;
    void **b;
    Unk021a7064 *c;
    s32 d;

    a = (e * 4 + 3) & ~3;
    d = (e * 0x2c + 3) & ~3;
    b = data_ov000_021b5f94->mUnk_18(d + a);
    if (b == 0) {
        return -1;
    }
    func_0200eb90(&data_ov000_021b5fdc, b, e);
    c = (Unk021a7064 *) ((u8 *) b + a);
    if (e > 0) {
        do {
            func_ov000_021a7048(c);
            c++;
            e--;
        } while (e > 0);
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

Unk021a7064 *func_ov000_021a7088(s32 a) {
    int v1;
    Unk021a7064 *v2[1];
    v1 = func_0200ea3c(&data_ov000_021b5fdc, (void **) (v2), (s32) (a));
    if (v1 != 0) {
        return v2[0];
    }
    return 0;
}

Unk021a7064 *func_ov000_021a7064(Unk021a7064Func b, Unk021a6fa8 *c, s32 d) {
    Unk021a7064 *a;

    a = func_ov000_021a7088(d);
    if (a != 0) {
        a->mUnk_00 = b;
        a->mUnk_04 = c;
        a->mUnk_0d = d;
        a->mUnk_0c = c->mUnk_73;
    }
    return a;
}

void func_ov000_021a7048(Unk021a7064 *a) {
    if (a != 0) {
        func_0200eae8(&data_ov000_021b5fdc, (void *) (a), 0);
    }
    return;
}

s32 func_ov000_021a7008(Unk021a7154 *b, Unk021a7064 *c) {
    s32 a;

    a = func_0200eae8(&b->mUnk_00, c, c != 0 ? c->mUnk_0d : 1);
    if (a == 0) {
        func_ov000_021a7048(c);
    }
    if (a != 0) {
        return 0;
    }
    return -42;
}

s32 func_ov000_021a6fc0(Unk021a7154 *d, Unk021a7064 *e) {
    s32 a;
    void *b;
    Unk0200eb90 c;

    if (e->mUnk_0d == 0) {
        e->mUnk_08 = 0;
        a = func_ov000_021a7008(d, e);
    } else {
        func_0200eb90(&c, &b, 1);
        e->mUnk_08 = &c;
        func_ov000_021a7008(d, e);
        func_0200ea3c(&c, (void **) &a, 1);
    }
    return a;
}

s32 func_ov000_021a6fb4(Unk021a6fa8 *a, Unk021a7064 *b) {
    return func_ov000_021a6fc0(a->mUnk_64, b);
}
