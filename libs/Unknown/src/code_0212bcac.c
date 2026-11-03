#include "code_0212bcac.h"
#include "code_020172d0.h"
#include "code_020207ec.h"
#include "code_02020eb0.h"
#include "code_02021784.h"
#include "code_0212c688.h"
#include "code_0212c6ac.h"
#include "code_0212c7a0.h"
#include "code_0212da38.h"
#include "code_0212f788.h"
#include "code_0201750c.h"
#include "Main/Unknown/code_02017000.h"
#include "code_0201ec30.h"
#include "Main/Unknown/code_02021000.h"
#include "code_0212f864.h"
#include "Main/Unknown/unk_02152000.h"
#include "Main/Unknown/unk_0217d000.h"

Unk02017328 data_0217d450;
Unk02017328 data_0217d444;

u32 func_0212c400(Unk0212c400 **a, u32 b, s16 *c) {
    Unk0212c400 *p = *a;

    if (p == 0) {
        return 0;
    }
    if (p->mUnk_2d == 0) {
        *c = -1;
        return 1;
    }
    *c = func_02021868(p->mUnk_3c, b);
    return 1;
}

u32 func_0212c3c8(Unk0212c400 **a, u32 b, u32 c) {
    if (*a == 0) {
        return 0;
    }
    func_02020d34((*a)->mUnk_3c, b, c);
    return 1;
}

void func_0212c310(void) {
    s32 i;
    Unk0212c400 *p;
    Unk0212c7a0 *e;

    func_02017538(&data_0217d450, 0x14);
    func_02017538(&data_0217d444, 0x14);
    for (i = 0, p = data_0217d45c; i < 16; i++, p++) {
        p->mUnk_2c = 0;
        p->mUnk_3c = i;
        func_020174a4(&data_0217d444, p);
    }
    for (i = 0, e = data_0217d89c; i < 32; i++, e++) {
        func_02017538(&e->mUnk_00, 0xc);
        func_02017538(&e->mUnk_0c, 0);
        e->mUnk_20 = 0x7f;
        e->mUnk_18 = 1;
        e->mUnk_1c = 0;
    }
}

void func_0212c19c(void) {
    u32 m;
    Unk0212c400 *p;
    Unk0212c400 *q;
    s32 a;
    s32 b;
    s32 c;
    s32 v;

    m = func_020218bc();
    for (p = func_0201733c(&data_0217d450, 0); p != 0; p = q) {
        q = func_0201733c(&data_0217d450, p);
        if (p->mUnk_2d == 0 && func_020210c0(p->mUnk_30) != 0) {
            p->mUnk_2d = 1;
        }
        if (p->mUnk_2d != 0 && (m & (1 << p->mUnk_3c)) == 0) {
            func_0212bd6c(p);
            continue;
        }
        func_0212f7e0(&p->mUnk_1c);
        a = data_02152ce4[p->mUnk_41];
        b = data_02152ce4[p->mUnk_40];
        c = data_02152ce4[p->mUnk_04->mUnk_20];
        v = data_02152ce4[func_0212f7f8(&p->mUnk_1c) >> 8];
        v += c + (b + a);
        if (v < -723) {
            v = -723;
        } else if (v > 0) {
            v = 0;
        }
        if (v != p->mUnk_3e) {
            func_02020d80(p->mUnk_3c, v);
            p->mUnk_3e = v;
        }
        if (p->mUnk_2c == 2 && func_0212f7c8(&p->mUnk_1c) != 0) {
            func_0212be78(p);
        }
        if (p->mUnk_2f != 0) {
            func_02020db0(p->mUnk_3c);
            p->mUnk_2f = 0;
        }
    }
}

Unk0212c400 *func_0212c0e0(Unk0212c400 **a, s32 b, s32 c) {
    Unk0212c400 *p = *a;
    Unk0212c7a0 *e = &data_0217d89c[b];

    if (p != 0) {
        func_0212c688(a);
    }
    if (e->mUnk_00.mUnk_08 >= e->mUnk_18) {
        p = func_0201733c(&e->mUnk_00, 0);
        if (p == 0) {
            return 0;
        }
        if (c < p->mUnk_3d) {
            return 0;
        }
        func_0212be78(p);
    }
    p = func_0212bdfc(c);
    if (p == 0) {
        return 0;
    }
    func_0212bf14(e, p);
    p->mUnk_00 = a;
    *a = p;
    return p;
}

void func_0212c0d4(void *a) {
    func_0212bd6c(a);
}

void func_0212c078(Unk0212c400 *a, void *b, u32 c, void *d) {
    Unk0212c7a0 *e = a->mUnk_04;

    func_02020ddc(a->mUnk_3c, (u32) b, c, (u32) d);
    if (e->mUnk_1c != 0) {
        func_02020c60(a->mUnk_3c, 0xffff, e->mUnk_1c);
    }
    func_0212bf70(a);
    a->mUnk_30 = func_02021114();
    a->mUnk_2f = 1;
    a->mUnk_2c = 1;
}

void func_0212c018(Unk0212c400 *p, u32 b) {
    if (p == 0) {
        return;
    }
    if (p->mUnk_2c == 0) {
        return;
    }
    if (b == 0) {
        func_0212be78(p);
        return;
    }
    func_0212f834(&p->mUnk_1c, 0, b);
    func_0212bcac(p, 0);
    p->mUnk_2c = 2;
}

Unk0212d9dc *func_0212bfbc(u32 a, Unk0212c400 *b) {
    Unk0212c7a0 *e = &data_0217d89c[a];
    Unk0212c700 *q;

    q = func_0201733c(&e->mUnk_0c, 0);
    if (q == 0) {
        return 0;
    }
    func_02017354(&e->mUnk_0c, q);
    q->mUnk_0c = b;
    b->mUnk_08 = q;
    func_0212dbec(q->mUnk_08);
    return q->mUnk_08;
}

void func_0212bf70(Unk0212c400 *p) {
    p->mUnk_2e = 0;
    p->mUnk_2d = 0;
    p->mUnk_2f = 0;
    p->mUnk_34 = 0;
    p->mUnk_3e = 0;
    p->mUnk_40 = 0x7f;
    p->mUnk_41 = 0x7f;
    func_0212f864(&p->mUnk_1c);
    func_0212f834(&p->mUnk_1c, 0x7f00, 1);
}

void func_0212bf14(Unk0212c7a0 *e, Unk0212c400 *p) {
    Unk0212c400 *q;

    for (q = func_0201733c(&e->mUnk_00, 0); q != 0; q = func_0201733c(&e->mUnk_00, q)) {
        if (p->mUnk_3d < q->mUnk_3d) {
            break;
        }
    }
    func_020173c0(&e->mUnk_00, q, p);
    p->mUnk_04 = e;
}

void func_0212beb4(Unk0212c400 *p) {
    Unk0212c400 *q;

    for (q = func_0201733c(&data_0217d450, 0); q != 0; q = func_0201733c(&data_0217d450, q)) {
        if (p->mUnk_3d < q->mUnk_3d) {
            break;
        }
    }
    func_020173c0(&data_0217d450, q, p);
}

void func_0212be78(Unk0212c400 *p) {
    if (p->mUnk_2c == 2) {
        func_02020d80(p->mUnk_3c, -723);
    }
    func_02020e10(p->mUnk_3c);
    func_0212bd6c(p);
}

Unk0212c400 *func_0212bdfc(s32 a) {
    Unk0212c400 *p = func_0201733c(&data_0217d444, 0);

    if (p == 0) {
        p = func_0201733c(&data_0217d450, 0);
        if (a < p->mUnk_3d) {
            return 0;
        }
        func_0212be78(p);
    }
    func_02017354(&data_0217d444, p);
    p->mUnk_3d = a;
    func_0212beb4(p);
    return p;
}

void func_0212bd6c(Unk0212c400 *p) {
    Unk0212c7a0 *e;

    if (p->mUnk_00 != 0) {
        *p->mUnk_00 = 0;
        p->mUnk_00 = 0;
    }
    e = p->mUnk_04;
    func_02017354(&e->mUnk_00, p);
    p->mUnk_04 = 0;
    if (p->mUnk_08 != 0) {
        func_020174a4(&e->mUnk_0c, p->mUnk_08);
        p->mUnk_08->mUnk_0c = 0;
        p->mUnk_08 = 0;
    }
    func_02017354(&data_0217d450, p);
    func_020174a4(&data_0217d444, p);
    p->mUnk_2c = 0;
}

void func_0212bd10(Unk0212c700 *p) {
    if (p->mUnk_08 == 0) {
        return;
    }
    func_0212dcac(p->mUnk_08);
    if (p->mUnk_0c != 0) {
        p->mUnk_0c->mUnk_08 = 0;
        return;
    }
    func_02017354(&data_0217d89c[p->mUnk_10].mUnk_0c, p);
}

void func_0212bcac(Unk0212c400 *p, u32 b) {
    Unk0212c7a0 *e = p->mUnk_04;

    if (e != 0) {
        func_02017354(&e->mUnk_00, p);
        p->mUnk_04 = 0;
    }
    func_02017354(&data_0217d450, p);
    p->mUnk_3d = b;
    if (e != 0) {
        func_0212bf14(e, p);
    }
    func_0212beb4(p);
}
