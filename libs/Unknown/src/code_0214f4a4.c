#include "code_0214f4a4.h"
#include "code_0200c4a4.h"
#include "code_0200c914.h"
#include "code_0200edc0.h"
#include "Main/Unknown/code_0200f000.h"
#include "code_0214d5b8.h"

u16 data_02180430;
vu32 data_02180438;
Unk0214f4bc *data_02180444;
u32 data_02180440;
Unk0214f4bc *data_0218043c;
vu32 data_02180434;
Unk0214f630 data_02180448;
Unk0200edc0 data_02180458;
Unk0214fe10 data_02180470[4];

int func_021501d8(void) {
    u32 v;

    v = func_0200fca0();
    if (data_02180448.mUnk_00 != 0) {
        func_0200fcb4(v);
        return 0;
    }
    data_02180448.mUnk_00 = 1;
    func_0200fcb4(v);
    return 1;
}

void func_021501c0(void) {
    vu32 *p;

    p = &data_02180448.mUnk_00;
    while (*p != 0) {
    }
}

void func_021501b8(u32 a, u32 *p) {
    *p = a;
}

void func_02150164(u32 a) {
    u32 f;
    void (*fn)(u32 a, u32 *b);
    u32 *arg;

    f = data_02180448.mUnk_00;
    fn = data_02180448.mUnk_04;
    arg = data_02180448.mUnk_08;
    if (f != 0) {
        data_02180448.mUnk_00 = 0;
    }
    if (fn == 0) {
        return;
    }
    data_02180448.mUnk_04 = 0;
    fn(a, arg);
}

void func_021500a0(void) {
    int i;

    if (data_02180430 != 0) {
        return;
    }
    data_02180430 = 1;
    data_02180448.mUnk_00 = 0;
    data_02180448.mUnk_04 = 0;
    func_0214d5b8();
    while (func_0214d79c(8, 1) == 0) {
    }
    func_0214d7c4(8, func_0214ffb4);
    for (i = 0; i < 4; i++) {
        data_02180470[i].mUnk_00 = 0;
    }
    func_0200edc0(&data_02180458);
    data_02180440 = *(u32 *) 0x27ffc3c;
}

void func_0214ffb4(u32 a, u32 b, u32 c) {
    u16 v;
    u16 t;
    u32 *p;

    if (c != 0) {
        func_02150164(2);
        return;
    }
    t = (b & 0x7f00) >> 8;
    v = b & 0xff;
    if (t >= 0x70 && t <= 0x73) {
        u16 *q;
        u16 w;

        w = v & 0xff;
        q = data_02180470[t - 0x70].mUnk_04;
        if (q != 0) {
            *q = w;
        }
        data_02180470[t - 0x70].mUnk_00 = 1;
        v = 0;
    } else if (t == 0x60) {
        data_02180434 = 1;
    } else if (t == 0x62) {
        data_02180438 = 1;
    } else if (t == 0x67) {
        p = data_02180448.mUnk_0c;
        if (p != 0) {
            *p = v;
        }
        v = 0;
    }
    func_02150164(v);
}

int func_0214fefc(u32 a, u16 b) {
    if (func_021501d8() == 0) {
        return 1;
    }
    data_02180434 = 0;
    func_0214fa7c(0x3006000);
    while (data_02180434 == 0) {
    }
    data_02180434 = 0;
    data_02180438 = 0;
    func_0214f74c(0, 2, 0, 0);
    func_0214fa7c((a & 0xff) | 0x2006100);
    func_0214fa7c((b & 0xffff) | 0x1010000);
    return 0;
}

int func_0214fe88(u32 a, void (*fn)(u32 a, u32 *b), u32 *arg) {
    if (func_021501d8() == 0) {
        return 1;
    }
    data_02180448.mUnk_04 = fn;
    data_02180448.mUnk_08 = arg;
    func_0214fa7c(((a >> 16) & 0xff) | 0x2006300);
    func_0214fa7c((a & 0xffff) | 0x1010000);
    return 0;
}

int func_0214fe10(u32 a, u16 *p, void (*fn)(u32 a, u32 *b), u32 *arg) {
    if (func_021501d8() == 0) {
        return 1;
    }
    data_02180470[a].mUnk_00 = 0;
    data_02180448.mUnk_04 = fn;
    data_02180448.mUnk_08 = arg;
    data_02180470[a].mUnk_04 = p;
    func_0214fa7c((a & 0xff) | 0x3006500);
    return 0;
}

int func_0214fdd4(u32 a, u16 *p) {
    u32 v;
    int r;

    r = func_0214fe10(a, p, func_021501b8, &v);
    if (r != 0) {
        return r;
    }
    func_021501c0();
    return v;
}

int func_0214fd54(u32 a, u16 b, void (*fn)(u32 a, u32 *b), u32 *arg) {
    if (func_021501d8() == 0) {
        return 1;
    }
    data_02180448.mUnk_04 = fn;
    data_02180448.mUnk_08 = arg;
    func_0214fa7c((a & 0xff) | 0x2006400);
    func_0214fa7c((b & 0xffff) | 0x1010000);
    return 0;
}

int func_0214fd18(u32 a, u16 b) {
    u32 v;
    int r;

    r = func_0214fd54(a, b, func_021501b8, &v);
    if (r != 0) {
        return r;
    }
    func_021501c0();
    return v;
}

int func_0214fcb0(u32 a, void (*fn)(u32 a, u32 *b), u32 *arg) {
    u32 b;

    switch (a) {
        case 1:
            b = 1;
            break;
        case 3:
            b = 2;
            break;
        case 2:
            b = 3;
            break;
        default:
            b = 0;
            break;
    }
    if (b == 0) {
        return 0xffff;
    }
    return func_0214fe88(b, fn, arg);
}

int func_0214fc74(u32 a) {
    u32 v;
    int r;

    r = func_0214fcb0(a, func_021501b8, &v);
    if (r != 0) {
        return r;
    }
    func_021501c0();
    return v;
}

int func_0214fbe4(u32 a, u32 b, void (*fn)(u32 a, u32 *b), u32 *arg) {
    u32 c;

    c = 0;
    if (a == 0) {
        if (b == 1) {
            c = 6;
        }
        if (b == 0) {
            c = 7;
        }
    } else if (a == 1) {
        if (b == 1) {
            c = 4;
        }
        if (b == 0) {
            c = 5;
        }
    } else if (a == 2) {
        if (b == 1) {
            c = 8;
        }
        if (b == 0) {
            c = 9;
        }
    }
    if (c == 0) {
        return 0xffff;
    }
    return func_0214fe88(c, fn, arg);
}

int func_0214fba8(u32 a, u32 b) {
    u32 v;
    int r;

    r = func_0214fbe4(a, b, func_021501b8, &v);
    if (r != 0) {
        return r;
    }
    func_021501c0();
    return v;
}

int func_0214fb90(void (*fn)(u32 a, u32 *b), u32 *arg) {
    return func_0214fe88(0xe, fn, arg);
}

int func_0214fb54(void) {
    u32 v;
    int r;

    r = func_0214fb90(func_021501b8, &v);
    if (r != 0) {
        return r;
    }
    func_021501c0();
    return v;
}

int func_0214fb3c(u32 a) {
    return func_0214fd18(2, a);
}

int func_0214fb24(u32 a) {
    return func_0214fd18(3, a);
}

int func_0214faac(u32 *a, u32 *b) {
    u16 v;
    int r;

    r = func_0214fdd4(0, &v);
    if (r != 0) {
        return r;
    }
    if (a != 0) {
        *a = (v & 8) != 0 ? 1 : 0;
    }
    if (b != 0) {
        *b = (v & 4) != 0 ? 1 : 0;
    }
    return r;
}

void func_0214fa7c(u32 a) {
    while (func_0214d6e8(8, a, 0) != 0) {
    }
}

static inline u32 func_0214f83c_inline(void) {
    return *(vu32 *) 0x27ffc3c;
}

void func_0214f83c(u32 a, u32 b, u32 c) {
    u32 v0;
    u32 v1;
    u32 v2;
    u32 w0;
    u32 w1;
    vu32 t;
    u32 d;
    u32 k0;
    u32 k1;
    u32 g;
    u16 saved;
    u16 tmp;

    d = 0;
    func_0214f51c(data_0218043c);
    saved = *(vu16 *) 0x4000208;
    *(vu16 *) 0x4000208 = 0;
    v0 = func_0200fca0();
    v1 = func_0200ca9c(0x3fffff);
    func_0200cb1c(0x40000);
    func_0200fcb4(v0);
    tmp = *(vu16 *) 0x4000208;
    *(vu16 *) 0x4000208 = 1;
    if ((a & 8) != 0) {
        if (*(vu16 *) 0x27ffc40 == 2) {
            a &= ~8;
        }
    }
    if ((a & 0x10) != 0) {
        if (func_0200c568() == 0) {
            a &= ~0x10;
        }
    }
    k0 = *(vu32 *) 0x4000000;
    k1 = *(vu32 *) 0x4001000;
    v2 = func_0214f710();
    func_0214faac(&w0, &w1);
    func_0214fba8(2, 0);
    t = func_0214f83c_inline();
    while (t == func_0214f83c_inline()) {
    }
    t = func_0214f83c_inline();
    *(vu32 *) 0x4000000 &= ~0x30000;
    *(vu32 *) 0x4001000 &= ~0x10000;
    while (t == func_0214f83c_inline()) {
    }
    t = func_0214f83c_inline();
    while (t == func_0214f83c_inline()) {
    }
    g = (u16) (a | (w0 << 5) | (w1 << 6));
    while (func_0214fefc(g, (u16) (b | c)) != 0) {
    }
    func_0200fd04();
    func_0200fd10(0x332340);
    if ((a & 8) != 0) {
        if ((*(vu32 *) 0x4000214 & 0x100000) != 0) {
            d = 1;
        }
    }
    if (d == 0) {
        if (v2 == 1) {
            func_0214f74c(1, 1, 1, 0);
        } else {
            func_0214fc74(1);
        }
        *(vu32 *) 0x4000000 = k0;
        *(vu32 *) 0x4001000 = k1;
    }
    func_0200fca0();
    func_0200cb1c(v1);
    func_0200fcb4(v0);
    tmp = *(vu16 *) 0x4000208;
    *(vu16 *) 0x4000208 = saved;
    if (d != 0) {
        func_0214fb54();
    }
    func_0214f51c(data_02180444);
}

int func_0214f74c(u32 a, u32 b, u32 c, u32 d) {
    switch (a) {
        case 1:
            if (c == 0) {
                if (*(vu32 *) 0x27ffc3c - data_02180440 <= 7) {
                    return 0;
                }
            }
            if (b != 0) {
                if (d != 0) {
                    func_0214fc74(b);
                } else {
                    func_0214fcb0(b, 0, 0);
                }
            }
            *(vu16 *) 0x4000304 |= 1;
            break;
        case 0:
            *(vu16 *) 0x4000304 &= ~1;
            data_02180440 = *(vu32 *) 0x27ffc3c;
            if (b != 0) {
                if (d != 0) {
                    func_0214fc74(b);
                } else {
                    func_0214fcb0(b, 0, 0);
                }
            }
            break;
    }
    return 1;
}

int func_0214f72c(u32 a) {
    if (a != 1) {
        a = 0;
    }
    return func_0214f74c(a, 0, 0, 1);
}

int func_0214f710(void) {
    return (*(vu16 *) 0x4000304 & 1) != 0 ? 1 : 0;
}

int func_0214f6bc(u32 a, void (*fn)(u32 a, u32 *b), u32 *arg) {
    if (func_021501d8() == 0) {
        return 1;
    }
    data_02180448.mUnk_04 = fn;
    data_02180448.mUnk_08 = arg;
    func_0214fa7c((a & 0xff) | 0x3006600);
    return 0;
}

int func_0214f680(u32 a) {
    u32 v;
    int r;

    r = func_0214f6bc(a, func_021501b8, &v);
    if (r != 0) {
        return r;
    }
    func_021501c0();
    return v;
}

int func_0214f630(u32 *p, void (*fn)(u32 a, u32 *b), u32 *arg) {
    if (func_021501d8() == 0) {
        return 1;
    }
    data_02180448.mUnk_04 = fn;
    data_02180448.mUnk_08 = arg;
    data_02180448.mUnk_0c = p;
    func_0214fa7c(0x3006700);
    return 0;
}

int func_0214f5f4(u32 *p) {
    u32 v;
    int r;

    r = func_0214f630(p, func_021501b8, &v);
    if (r != 0) {
        return r;
    }
    func_021501c0();
    return v;
}

void func_0214f5e0(Unk0214f4bc **pp, Unk0214f4bc *p) {
    if (pp != 0) {
        p->mUnk_08 = *pp;
        *pp = p;
    }
}

void func_0214f598(Unk0214f4bc **pp, Unk0214f4bc *p) {
    Unk0214f4bc *a;
    Unk0214f4bc *b;

    if (pp == 0) {
        return;
    }
    a = *pp;
    if (a == 0) {
        p->mUnk_08 = 0;
        *pp = p;
        return;
    }
    b = a->mUnk_08;
    while (b != 0) {
        a = b;
        b = b->mUnk_08;
    }
    p->mUnk_08 = b;
    a->mUnk_08 = p;
}

void func_0214f54c(Unk0214f4bc **pp, Unk0214f4bc *p) {
    Unk0214f4bc *a;
    Unk0214f4bc *b;

    if (pp == 0) {
        return;
    }
    a = *pp;
    b = a;
    if (a == 0) {
        return;
    }
    do {
        if (a == p) {
            if (a == b) {
                *pp = a->mUnk_08;
            } else {
                b->mUnk_08 = a->mUnk_08;
            }
            return;
        }
        b = a;
        a = a->mUnk_08;
    } while (a != 0);
}

void func_0214f51c(Unk0214f4bc *p) {
    if (p == 0) {
        return;
    }
    do {
        p->mUnk_00(p->mUnk_04);
        p = p->mUnk_08;
    } while (p != 0);
}

void func_0214f504(Unk0214f4bc *p) {
    func_0214f598(&data_0218043c, p);
}

void func_0214f4ec(Unk0214f4bc *p) {
    func_0214f5e0(&data_0218043c, p);
}

void func_0214f4d4(Unk0214f4bc *p) {
    func_0214f598(&data_02180444, p);
}

void func_0214f4bc(Unk0214f4bc *p) {
    func_0214f54c(&data_0218043c, p);
}

void func_0214f4a4(Unk0214f4bc *p) {
    func_0214f54c(&data_02180444, p);
}
