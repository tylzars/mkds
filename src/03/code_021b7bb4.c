#include "03/code_021b7bb4.h"
#include "03/code_021b7000.h"
#include "03/unk_021d8000.h"
#include "Main/Unknown/code_02133000.h"

#include "code_02133048.h"
#include "code_0214d018.h"
#include "code_0214d93c.h"
#include "00/code_021ad734.h"
#include "03/code_021b94b8.h"
#include "00/code_021a8aa8.h"
#include "00/unk_021b6000.h"
#include "03/unk_021d7000.h"

s32 func_ov003_021b94ac(void) {
    u32 value0;
    value0 = (u32) &data_ov003_021d7c50;
    value0 = (u32) * (const u32 *) ((value0) + 0u);
    return (s32) value0;
}

s32 func_ov003_021b929c(Unk021b94c4 *a) {
    u8 *p = (u8 *) a + 0x117;
    Unk021d8374 *b = &data_ov003_021d8374;
    Unk021d8374 *c = &data_ov003_021d84a4;
    Unk021d8374 *d = &data_ov003_021d85d4;
    Unk021d8374 *e = &data_ov003_021d8644;
    if (p == NULL) {
        return -1;
    }
    a->mUnk_000 = data_ov003_021d7c6c.mUnk_08 & data_ov003_021d7c6c.mUnk_0c;
    func_ov003_021b7d84(p, 0, 0x154);
    if (a->mUnk_000 & 1) {
        func_ov003_021b7d90(p, b->mUnk_30, b->mUnk_04);
        func_ov003_021b7d90(p + 6, b->mUnk_70, b->mUnk_04);
        func_ov003_021b7d90(p + 0xc, b->mUnk_b0, b->mUnk_04);
        func_ov003_021b7d90(p + 0x12, b->mUnk_f0, b->mUnk_04);
        if (func_ov003_021b9278(b->mUnk_08, func_ov003_021b7c30(b->mUnk_08)) != 0) {
            goto fail;
        }
        func_ov003_021b7d90(p + 0x18, b->mUnk_08, func_ov003_021b7c30(b->mUnk_08));
    }
    if (a->mUnk_000 & 2) {
        func_ov003_021b7d90(p + 0x39, c->mUnk_30, c->mUnk_04);
        func_ov003_021b7d90(p + 0x47, c->mUnk_70, c->mUnk_04);
        func_ov003_021b7d90(p + 0x55, c->mUnk_b0, c->mUnk_04);
        func_ov003_021b7d90(p + 0x63, c->mUnk_f0, c->mUnk_04);
        if (func_ov003_021b9278(c->mUnk_08, func_ov003_021b7c30(c->mUnk_08)) != 0) {
            goto fail;
        }
        func_ov003_021b7d90(p + 0x71, c->mUnk_08, func_ov003_021b7c30(c->mUnk_08));
    }
    if (a->mUnk_000 & 4) {
        if (func_ov003_021b9278(d->mUnk_30, d->mUnk_04 - 1) != 0) {
            goto fail;
        }
        func_ov003_021b7d90(p + 0x92, d->mUnk_30, d->mUnk_04);
        if (func_ov003_021b9278(d->mUnk_08, func_ov003_021b7c30(d->mUnk_08)) != 0) {
            goto fail;
        }
        func_ov003_021b7d90(p + 0xd2, d->mUnk_08, func_ov003_021b7c30(d->mUnk_08));
    }
    if (a->mUnk_000 & 8) {
        if (func_ov003_021b9278(e->mUnk_30, e->mUnk_04 - 1) != 0) {
            goto fail;
        }
        func_ov003_021b7d90(p + 0xf3, e->mUnk_30, e->mUnk_04);
        if (func_ov003_021b9278(e->mUnk_08, func_ov003_021b7c30(e->mUnk_08)) != 0) {
            goto fail;
        }
        func_ov003_021b7d90(p + 0x133, e->mUnk_08, func_ov003_021b7c30(e->mUnk_08));
    }
    a->mUnk_116 = 0;
    return 0;
fail:
    func_ov003_021b7d84(p, 0, 0x154);
    return -1;
}

s32 func_ov003_021b9278(const u8 *bytes, s32 count) {
    s32 i;
    for (i = 0; i < count; i++) {
        u32 value = *bytes++;
        if (value < 0x20 || value > 0x7f) {
            return -1;
        }
    }
    return 0;
}

typedef struct Unk021b9078 {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u8 pad_02[4];
    /* 06 */ u16 mUnk_06;
    /* 08 */ u8 pad_08[7];
    /* 0f */ u8 mUnk_0f;
} Unk021b9078;

s32 func_ov003_021b91f0(Unk021ba734 *a) {
    s32 m;
    s32 r;
    s32 i;
    s32 n;
    r = 0;
    n = 0;
    m = a->mUnk_00;
    if (m == 0) {
        return 5;
    }
    if ((u32) m > 0x40) {
        m = 0x40;
    }
    for (i = 0; i < m; i++) {
        if (a->mUnk_04[i].mUnk_50 & 1) {
            if (a->mUnk_04[i].mUnk_00 == func_ov003_021b7c30(data_ov003_021d6870)) {
                if (func_ov003_021b7da0(a->mUnk_04[i].mUnk_04, data_ov003_021d6870,
                                        func_ov003_021b7c30(data_ov003_021d6870)) == 0) {
                    n++;
                }
            }
        }
    }
    if (n > 1) {
        r = 4;
    }
    if (n == 0) {
        r = 5;
    }
    return r;
}

s32 func_ov003_021b91a4(Unk021ba1b0 *a) {
    a->mUnk_00 = func_ov003_021b7c30(data_ov003_021d6870);
    func_ov003_021b7d90(a->mUnk_04, data_ov003_021d6870, a->mUnk_00);
    a->mUnk_24 = TRUE;
    a->mUnk_28 = func_ov003_021b7c30(data_ov003_021d6868);
    if ((u32) a->mUnk_28 > 0xd) {
        return -1;
    }
    func_ov003_021b7d90(a->mUnk_2c, data_ov003_021d6868, a->mUnk_28);
    return 0;
}

void func_ov003_021b916c(s32 a, Unk021b916c *b, const u8 *c) {
    s32 i;
    for (i = 0; i < a; i++) {
        func_ov003_021b7d90(b, c, 6);
        b->mUnk_06 = func_ov003_021b7bb4();
        b->mUnk_06 = func_ov003_021b7c94(b->mUnk_06);
        b++;
    }
}

s32 func_ov003_021b9134(s32 a) {
    BOOL r = FALSE;
    if (a == -1) {
        data_ov003_021d680c = a;
        return r;
    }
    if (data_ov003_021d680c != a) {
        data_ov003_021d680c = a;
        return func_ov003_021ba18c(a);
    }
    return r;
}

s32 func_ov003_021b9078(s32 a, Unk021d7c54 *b, s32 *c, Unk021b916c *d, s32 e) {
    Unk021b9078 *p = (Unk021b9078 *) b->mUnk_0c;
    u32 v;
    if (func_ov003_021b7c44(p->mUnk_00) < 1) {
        *c = *c + 1;
        return a;
    }
    if (p->mUnk_0f != 0x11) {
        *c = *c + 1;
        return a;
    }
    if (func_ov003_021b8c8c((Unk021b8c8c *) b->mUnk_0c) > 0) {
        *c = *c + 1;
        return a;
    }
    v = func_ov003_021b7c44(p->mUnk_06);
    switch (v) {
        case 0x1010:
            a = func_ov003_021b8f68(a, b, c, d);
            break;
        case 0x2010:
            a = func_ov003_021b8e60(a, b, c, d);
            break;
        case 0x3010:
            a = func_ov003_021b8d9c(a, b, c, d);
            break;
    }
    return a;
}

s32 func_ov003_021b8f68(s32 v1, Unk021d7c54 *v2, s32 *v3, Unk021b916c *v4) {
    Unk021b8c8c *a;
    Unk021b7cec *b;
    u32 *p;
    s32 c;
    if (v1 != 0) {
        (*v3)++;
        return v1;
    }
    a = (Unk021b8c8c *) v2->mUnk_0c;
    b = (Unk021b7cec *) &v2->mUnk_0c[0x18];
    c = func_ov003_021b8bf0(&v4[0], &a->mUnk_10);
    if (c < 0) {
        (*v3)++;
        return v1;
    }
    if (func_ov003_021b7c44(b->mUnk_02) == 0) {
        (*v3)++;
        return v1;
    }
    if (b->mUnk_00 == 7) {
        p = &b->mUnk_04;
        if (func_ov003_021b7c5c(b->mUnk_04) == -2) {
            func_ov003_021b94b8(0x14);
        } else if (func_ov003_021b7c5c(*p) == -3) {
            func_ov003_021b94b8(0x15);
        } else {
            func_ov003_021b94b8(0x18);
        }
        return -1;
    }
    if (b->mUnk_00 != 1) {
        (*v3)++;
        return v1;
    }
    c = func_ov003_021b8b18((Unk021b8760 *) &b->mUnk_04, data_ov003_021d7cec);
    if (c < 0) {
        if (c == -2) {
            func_ov003_021b94b8(0x16);
            return -1;
        }
        (*v3)++;
        return v1;
    }
    data_ov003_021d7c40 = func_ov003_021b8748(func_ov003_021b7c44(a->mUnk_0c));
    *v3 = 0;
    return 1;
}

s32 func_ov003_021b8e60(s32 v1, Unk021d7c54 *v2, s32 *v3, Unk021b916c *v4) {
    Unk021b8c8c *a;
    Unk021b7cec *b;
    s32 c;
    if (v1 != 1) {
        (*v3)++;
        return v1;
    }
    a = (Unk021b8c8c *) v2->mUnk_0c;
    b = (Unk021b7cec *) &v2->mUnk_0c[0x18];
    c = func_ov003_021b8bf0(&v4[1], &a->mUnk_10);
    if (c < 0) {
        (*v3)++;
        return v1;
    }
    if (func_ov003_021b7c44(b->mUnk_02) == 0) {
        (*v3)++;
        return v1;
    }
    if (b->mUnk_00 == 7) {
        if (func_ov003_021b7c5c(b->mUnk_04) == -2) {
            func_ov003_021b94b8(0x14);
        } else if (func_ov003_021b7c5c(b->mUnk_04) == -3) {
            func_ov003_021b94b8(0x15);
        } else {
            func_ov003_021b94b8(0x18);
        }
        return -1;
    }
    func_ov003_021b7d84(data_ov003_021d836c, 0, 0x6a0);
    c = func_ov003_021b8758(0, (Unk021b8760 *) b, func_ov003_021b7c44(a->mUnk_0a), data_ov003_021d836c,
                            data_ov003_021d7cec);
    if (c < 0) {
        (*v3)++;
        return v1;
    }
    if ((data_ov003_021d7c6c.mUnk_0c & data_ov003_021d7c6c.mUnk_08) == 0) {
        return v1;
    }
    *v3 = 0;
    return 2;
}

s32 func_ov003_021b8d9c(s32 v1, Unk021d7c54 *v2, s32 *v3, Unk021b916c *v4) {
    Unk021b8c8c *a;
    Unk021b7cec *b;
    s32 c;
    if (v1 != 2) {
        (*v3)++;
        return v1;
    }
    a = (Unk021b8c8c *) v2->mUnk_0c;
    b = (Unk021b7cec *) &v2->mUnk_0c[0x18];
    c = func_ov003_021b8bf0(&v4[2], &a->mUnk_10);
    if (c < 0) {
        (*v3)++;
        return v1;
    }
    if (b->mUnk_00 != 7) {
        (*v3)++;
        return v1;
    }
    if (func_ov003_021b7c44(b->mUnk_02) == 0) {
        (*v3)++;
        return v1;
    }
    if (func_ov003_021b7c5c(b->mUnk_04) == 0) {
        return 0x64;
    }
    if (func_ov003_021b7c5c(b->mUnk_04) == -2) {
        func_ov003_021b94b8(0x14);
        return -1;
    }
    if (func_ov003_021b7c5c(b->mUnk_04) == -3) {
        func_ov003_021b94b8(0x15);
        return -1;
    }
    func_ov003_021b94b8(0x18);
    return -1;
}

s32 func_ov003_021b8c8c(Unk021b8c8c *a) {
    Unk021b8340 *b;
    u8 c[8];
    s32 d;
    u32 e;
    u8 *f;
    b = (Unk021b8340 *) a->mUnk_18;
    func_ov003_021b7d90(c, &a->mUnk_10, 8);
    d = func_ov003_021b7f48(c, 8, data_ov003_021d6868, func_ov003_021b7c30(data_ov003_021d6868));
    if (d == -1) {
        func_ov003_021b94b8(2);
        return -100;
    }
    d = func_ov003_021b8c44(func_ov003_021b7c44(a->mUnk_06), c);
    if (d != 0) {
        return d;
    }
    if (func_ov003_021b7c44(a->mUnk_06) == 0x1000) {
        func_ov003_021b7d90(data_ov003_021d7c58, c, 8);
    }
    if ((func_ov003_021b7c44(a->mUnk_0c) & 0xf) == 0) {
        return 0;
    }
    e = func_ov003_021b7c44(b->mUnk_00);
    f = func_ov003_021ba178(e);
    if (f == NULL) {
        func_ov003_021b94b8(2);
        return 100;
    }
    if (func_ov003_021b8160(b->mUnk_04, f, e, a->mUnk_0e, b->mUnk_02, data_ov003_021d7c58, 8) < 0) {
        func_ov003_021ba164(f);
        if (func_ov003_021b94ac() == 2) {
            return 100;
        }
        return 200;
    }
    func_ov003_021b7d90(b, f, e);
    a->mUnk_0a = func_ov003_021b7c94(e);
    func_ov003_021ba164(f);
    return 0;
}

s32 func_ov003_021b8c44(s32 a, const u8 *b) {
    s32 c;
    s32 i;
    BOOL d;
    u8 *p;
    c = 0;
    d = FALSE;
    i = 0;
    p = data_ov003_021d7c58;
    do {
        if (*p != 0) {
            d = TRUE;
            break;
        }
        p++;
        i++;
    } while (i < 6);
    if (d != FALSE) {
        if (func_ov003_021b7da0(data_ov003_021d7c58, b, 6) != 0) {
            c = 1;
        }
    } else if (a != 0x1000) {
        c = 2;
    }
    return c;
}

s32 func_ov003_021b8bf0(Unk021b916c *a, Unk021b916c *b) {
    s32 c;
    c = 0;
    func_ov003_021b7f48(b->mUnk_00, 8, data_ov003_021d6868, func_ov003_021b7c30(data_ov003_021d6868));
    if (func_ov003_021b7da0(a->mUnk_00, b->mUnk_00, 6) != 0) {
        c = -1;
    } else if (func_ov003_021b7c44(a->mUnk_06) + 1 != func_ov003_021b7c44(b->mUnk_06)) {
        c = -2;
    }
    return c;
}

s32 func_ov003_021b8b18(Unk021b8760 *a, u8 *b) {
    Unk021b8760 *c;
    s32 d;
    s32 e;
    func_ov003_021b7d84(b, 0, 0x104);
    c = a;
    while (1) {
        d = func_ov003_021b7c44(c->mUnk_02);
        if (d <= 0) {
            return -1;
        }
        switch (c->mUnk_00) {
            case 0:
                func_ov003_021b7d90(b, c->mUnk_06, d);
                break;
            case 1:
                func_ov003_021b7d90(b + 0x80, c->mUnk_06, d);
                break;
            case 2:
                func_ov003_021b7d90(b + 0x100, c->mUnk_06, d);
                break;
            case 3:
            case 4:
                e = func_ov003_021b7c44(c->mUnk_06[0]);
                if (e <= 0) {
                    return -2;
                }
                break;
            case 5:
                data_ov003_021d7c6c.mUnk_10 = func_ov003_021b7c5c(func_ov003_021b8af4(c->mUnk_06, d));
                break;
            case 6:
                data_ov003_021d7c6c.mUnk_14 = func_ov003_021b7c5c(func_ov003_021b8af4(c->mUnk_06, d));
                break;
            default:
                return -1;
        }
        if (c->mUnk_04 != 0) {
            c = (Unk021b8760 *) ((u8 *) a + func_ov003_021b7c44(c->mUnk_04));
            continue;
        }
        return 0;
    }
}

u32 func_ov003_021b8af4(const u8 *bytes, s32 count) {
    u32 value = 0;
    s32 i;
    const u8 *cursor = bytes + (count - 1);
    for (i = 0; i < count; i++) {
        value = (value << 8) + *cursor--;
    }
    return value;
}

s32 func_ov003_021b8990(Unk021b8760 *a, Unk021b8990 *b) {
    Unk021b8760 *c = (Unk021b8760 *) ((u8 *) a + 6);
    u32 d;
    while (1) {
        d = func_ov003_021b7c44(c->mUnk_02);
        switch (c->mUnk_00) {
            case 0x10:
            case 0x11:
            case 0x12:
            case 0x13:
                if (d > 5) {
                    return -1;
                }
                break;
            case 0x20:
            case 0x21:
            case 0x22:
            case 0x23:
                if (d > 0xd) {
                    return -1;
                }
                break;
            case 0x15:
            case 0x25:
                if (d > 0x21) {
                    return -1;
                }
                break;
        }
        switch (c->mUnk_00) {
            case 0x10:
            case 0x20:
                func_ov003_021b7d90(b->mUnk_030, c->mUnk_06, d);
                b->mUnk_004 = d;
                break;
            case 0x11:
            case 0x21:
                func_ov003_021b7d90(b->mUnk_070, c->mUnk_06, d);
                b->mUnk_004 = d;
                break;
            case 0x12:
            case 0x22:
                func_ov003_021b7d90(b->mUnk_0b0, c->mUnk_06, d);
                b->mUnk_004 = d;
                break;
            case 0x13:
            case 0x23:
                func_ov003_021b7d90(b->mUnk_0f0, c->mUnk_06, d);
                b->mUnk_004 = d;
                break;
            case 0x15:
            case 0x25:
                if (d != 0 && c->mUnk_06[d - 1] != 0) {
                    return -1;
                }
                func_ov003_021b7d90(b->mUnk_008, c->mUnk_06, d);
                break;
            default:
                return -1;
        }
        if (c->mUnk_04 != 0) {
            c = (Unk021b8760 *) ((u8 *) a + 6 + func_ov003_021b7c44(c->mUnk_04));
            continue;
        }
        return 0;
    }
}

s32 func_ov003_021b88c0(Unk021b8760 *a, Unk021b88c0 *b) {
    Unk021b8760 *c = (Unk021b8760 *) ((u8 *) a + 6);
    u32 d;
    while (1) {
        d = func_ov003_021b7c44(c->mUnk_02);
        switch (c->mUnk_00) {
            case 0x30:
            case 0x40:
                if (d > 0x40) {
                    return -1;
                }
                break;
            case 0x35:
            case 0x45:
                if (d > 0x21) {
                    return -1;
                }
                break;
        }
        switch (c->mUnk_00) {
            case 0x30:
            case 0x40:
                func_ov003_021b7d90(b->mUnk_30, c->mUnk_06, d);
                b->mUnk_04 = d;
                break;
            case 0x35:
            case 0x45:
                if (d != 0 && c->mUnk_06[d - 1] != 0) {
                    return -1;
                }
                func_ov003_021b7d90(b->mUnk_08, c->mUnk_06, d);
                break;
            default:
                return -1;
        }
        if (c->mUnk_04 != 0) {
            c = (Unk021b8760 *) ((u8 *) a + 6 + func_ov003_021b7c44(c->mUnk_04));
            continue;
        }
        return 0;
    }
}

s32 func_ov003_021b887c(Unk021b8760 *a, u8 *b) {
    Unk021b8760 *c = (Unk021b8760 *) ((u8 *) a + 6);
    s32 d;
    d = func_ov003_021b7c44(c->mUnk_02);
    if (d <= 0) {
        return -1;
    }
    if (c->mUnk_00 != 0x70) {
        return -1;
    }
    func_ov003_021b7d90(b, c->mUnk_06, d);
    return 0;
}

s32 func_ov003_021b8758(s32 a, Unk021b8760 *b, s32 c, Unk021b8758 *d, u8 *e) {
    u32 f;
    s32 g;
    u32 h;
    u8 *i;
    Unk021b8758 *j;
    u8 *k;
    s32 l;
    Unk021b8760 *m;
    f = 0;
    if (c <= 0) {
        return -2;
    }
    i = data_ov003_021d6800 + a;
    for (;;) {
        m = b;
        if (b->mUnk_00 == *i) {
            break;
        }
        g = func_ov003_021b7c44(b->mUnk_02) + 4;
        b = (Unk021b8760 *) ((u8 *) b + g);
        c -= g;
        if (c <= 0) {
            return -4;
        }
    }
    b = (Unk021b8760 *) ((u8 *) b + 4);
    h = func_ov003_021b7c44(m->mUnk_02);
    j = d + a;
    k = e + (a + 3) * 0x80;
    l = -3;
    do {
        switch (b->mUnk_00) {
            case 3:
                l = func_ov003_021b8990(b, &j->mUnk_008);
                f |= 1;
                break;
            case 4:
                l = func_ov003_021b8990(b, &j->mUnk_138);
                f |= 2;
                break;
            case 5:
                l = func_ov003_021b88c0(b, &j->mUnk_268);
                f |= 4;
                break;
            case 6:
                l = func_ov003_021b88c0(b, &j->mUnk_2d8);
                f |= 8;
                break;
            case 10:
                l = func_ov003_021b887c(b, k);
                break;
            default:
                l = -3;
                break;
        }
        if (l != 0) {
            return l;
        }
        g = func_ov003_021b7c44(b->mUnk_02) + 4;
        b = (Unk021b8760 *) ((u8 *) b + g);
        h -= g;
    } while ((s32) h > 0);
    data_ov003_021d7c6c.mUnk_0c |= f;
    return 0;
}

s32 func_ov003_021b8748(u32 value) {
    BOOL result = FALSE;
    if (value & 0x10) {
        result = TRUE;
    }
    return result;
}

s32 func_ov003_021b86e4(s32 v1, Unk021b86e4 *v2, Unk021b916c *v3, s32 v4) {
    switch (v1) {
        case 0:
            func_ov003_021b9134(2);
            return func_ov003_021b858c(v2, v3, v4);
        case 1:
            func_ov003_021b9134(3);
            return func_ov003_021b8498(v2, v3, v4);
        case 2:
            func_ov003_021b9134(5);
            return func_ov003_021b8428(v2, v3, v4);
    }
    return -1;
}

s32 func_ov003_021b858c(Unk021b86e4 *a, Unk021b916c *b, s32 c) {
    Unk021b8498 d;
    Unk021d7c54 *e;
    Unk021b858c *f;
    u8 *g;
    d.mUnk_00 = 0;
    d.mUnk_02 = 0;
    d.mUnk_04 = 0;
    e = data_ov003_021d7c54;
    func_ov003_021b7d84(e, 0, 0x5dc);
    f = func_ov003_021ba178(0x210);
    if (f == NULL) {
        func_ov003_021b94b8(2);
        return -1;
    }
    func_ov003_021b7d84(f, 0, 0x210);
    g = &e->mUnk_0c[12];
    func_ov003_021b7d90(data_ov003_021d7c58, b, 8);
    func_ov003_021b7d90(d.mUnk_06, data_ov003_021d7c58, 8);
    d.mUnk_02 = func_ov003_021b839c(f->mUnk_04);
    if (d.mUnk_02 < 0) {
        func_ov003_021b94b8(3);
        if (f != NULL) {
            func_ov003_021ba164(f);
        }
        return -1;
    }
    f->mUnk_00 = 0;
    f->mUnk_02 = func_ov003_021b7c94(d.mUnk_02);
    d.mUnk_02 += 4;
    func_ov003_021b8340(0, g, f, &d.mUnk_02, &d.mUnk_04, &d.mUnk_00);
    d.mUnk_04 |= 0x10;
    if (func_ov003_021b7f48(d.mUnk_06, 8, data_ov003_021d6868, 6) != 0) {
        func_ov003_021b94b8(2);
        if (f != NULL) {
            func_ov003_021ba164(f);
        }
        return -1;
    }
    func_ov003_021b82e0(e, 0x1000, d.mUnk_02, d.mUnk_04, d.mUnk_00, 0x11, d.mUnk_06);
    d.mUnk_02 += 0x18;
    func_ov003_021b8278(e, d.mUnk_02, 0xff, c);
    if (f != NULL) {
        func_ov003_021ba164(f);
    }
    return 0;
}

s32 func_ov003_021b8498(Unk021b86e4 *a, Unk021b916c *b, s32 c) {
    s8 d;
    s16 g;
    s16 h;
    u8 k[8];
    Unk021b7cec e;
    Unk021d7c54 *f;
    d = 0;
    g = 0;
    h = 0;
    f = data_ov003_021d7c54;
    func_ov003_021b7d84(&e, 0, 8);
    func_ov003_021b7d84(f, 0, 0x5dc);
    e.mUnk_00 = 2;
    e.mUnk_01 = 0;
    e.mUnk_02 = func_ov003_021b7c94(4);
    e.mUnk_04 = data_ov003_021d7c6c.mUnk_08;
    e.mUnk_04 = func_ov003_021b7cac(e.mUnk_04);
    g = 8;
    func_ov003_021b8340(data_ov003_021d7c40, &f->mUnk_0c[12], &e, &g, &h, &d);
    func_ov003_021b7d90(k, &b[1], 8);
    if (func_ov003_021b7f48(k, 8, data_ov003_021d6868, 6) != 0) {
        func_ov003_021b94b8(2);
        return -1;
    }
    func_ov003_021b82e0(f, 0x2000, g, h, d, 0x11, k);
    g += 0x18;
    func_ov003_021b8278(f, g, 0, c);
    return 0;
}

s32 func_ov003_021b8428(Unk021b86e4 *a, Unk021b916c *b, s32 c) {
    Unk021d7c54 *d;
    u8 e[8];
    d = data_ov003_021d7c54;
    func_ov003_021b7d84(d, 0, 0x5dc);
    func_ov003_021b7d90(e, &b[2], 8);
    func_ov003_021b7f48(e, 8, data_ov003_021d6868, func_ov003_021b7c30(data_ov003_021d6868));
    func_ov003_021b82e0(d, 0x3000, 0, 0, 0, 0x11, e);
    func_ov003_021b8278(d, 0x18, 0, c);
    return 0;
}

s16 func_ov003_021b839c(void *a) {
    Unk021b839c *b = a;
    Unk021b839c *c;
    s16 d;
    s16 e;
    s16 f;
    u32 g;
    f = 0;
    b->mUnk_00 = data_ov003_021d7c6c.mUnk_19;
    b->mUnk_01 = 1;
    d = data_ov003_021d7c6c.mUnk_04;
    func_ov003_021b7d90(b->mUnk_06, data_ov003_021d7c6c.mUnk_00, d);
    b->mUnk_02 = func_ov003_021b7c94(d);
    d += 6;
    e = (d + 1) / 2 * 2;
    b->mUnk_04 = func_ov003_021b7c94(e);
    f += e;
    c = (Unk021b839c *) ((u8 *) b + e);
    ((u8 *) b)[e] = 0x60;
    c->mUnk_01 = 0;
    c->mUnk_04 = func_ov003_021b7c94(0);
    g = func_ov003_021b7cac(0xe);
    func_ov003_021b7d90(c->mUnk_06, &g, 4);
    c->mUnk_02 = func_ov003_021b7c94(4);
    f += 0xa;
    return f;
}

void func_ov003_021b8340(s32 a, void *b, const void *c, s16 *d, s16 *e, s8 *f) {
    Unk021b8340 *g = b;
    if (a == 1) {
        *e = 1;
        func_ov003_021b81f4(c, g->mUnk_04, *d, f, g->mUnk_02, data_ov003_021d7c58, 8);
        g->mUnk_00 = func_ov003_021b7c94(*d);
        *d += 4;
    } else {
        func_ov003_021b7d90(g, c, *d);
    }
}

void func_ov003_021b82e0(void *p, s32 b, s32 c, s32 d, s8 e, s8 f, const u8 *g) {
    Unk021b82e0 *h = p;
    h->mUnk_00 = func_ov003_021b7c94(1);
    h->mUnk_02 = 0;
    h->mUnk_04 = 0;
    h->mUnk_06 = func_ov003_021b7c94(b);
    h->mUnk_08 = 0;
    h->mUnk_0a = func_ov003_021b7c94(c);
    h->mUnk_0c = func_ov003_021b7c94(d);
    h->mUnk_0e = e;
    h->mUnk_0f = f;
    func_ov003_021b7d90(h->mUnk_10, g, 8);
}

s32 func_ov003_021b8278(void *a, s32 b, u32 c, s32 d) {
    Unk021b7cec t;
    func_ov003_021b7d84(&t, 0, 8);
    t.mUnk_01 = 2;
    t.mUnk_02 = func_ov003_021b7c94(0x5790);
    t.mUnk_04 = func_ov003_021b7cac(data_ov003_021d7c6c.mUnk_10);
    if (c == 0xff || data_ov003_021d7c6c.mUnk_18 == 0) {
        t.mUnk_04 = -1;
    }
    return func_ov003_021b7d04(d, a, b, 0, &t, 8);
}

s32 func_ov003_021b81f4(const u8 *a, u8 *b, s32 c, s8 *d, u8 *e, const u8 *f, s32 g) {
    u16 h;
    Unk021b807c t;
    *d = func_ov003_021b8050(a, c);
    t.mUnk_08 = func_ov003_021ba178(c);
    if (t.mUnk_08 == NULL) {
        return -1;
    }
    h = func_ov003_021b7bb4();
    func_ov003_021b7d90(e, &h, 2);
    func_ov003_021b7d90(data_ov003_021d7c88, e, 2);
    func_ov003_021b7d90(data_ov003_021d7c8a, f, g);
    func_ov003_021b80f4(&t, data_ov003_021d7c88, g + 2, c);
    func_ov003_021b80c4(&t, b, a, c);
    func_ov003_021ba164(t.mUnk_08);
    return 0;
}

s32 func_ov003_021b8160(const u8 *a, u8 *b, s32 c, u32 d, const u8 *e, const u8 *f, s32 g) {
    Unk021b807c t;
    u8 r;
    t.mUnk_08 = func_ov003_021ba178(c);
    if (t.mUnk_08 == NULL) {
        func_ov003_021b94b8(2);
        return -1;
    }
    func_ov003_021b7d90(data_ov003_021d7c88, e, 2);
    func_ov003_021b7d90(data_ov003_021d7c8a, f, g);
    func_ov003_021b80f4(&t, data_ov003_021d7c88, g + 2, c);
    func_ov003_021b80c4(&t, b, a, c);
    r = func_ov003_021b8050(b, c);
    if (r != d) {
        func_ov003_021b94b8(0x12);
        func_ov003_021ba164(t.mUnk_08);
        return -1;
    }
    func_ov003_021ba164(t.mUnk_08);
    return 0;
}

void func_ov003_021b80f4(Unk021b807c *p, const u8 *v1, u32 v2, u32 n) {
    u8 *s;
    u32 i;
    u32 j;
    u32 k;
    u8 a;
    u8 t;
    s = p->mUnk_08;
    p->mUnk_04 = 0;
    p->mUnk_00 = p->mUnk_04;
    p->mUnk_0c = n;
    for (i = 0; i < n; i++) {
        s[i] = i;
    }
    j = 0;
    k = 0;
    for (i = 0; i < n; i++) {
        a = s[i];
        j = (j + v1[k] + a) % p->mUnk_0c;
        t = s[j];
        s[j] = a;
        s[i] = t;
        k++;
        if (k >= v2) {
            k = 0;
        }
    }
}

void func_ov003_021b80c4(Unk021b807c *p, u8 *v1, const u8 *v2, u32 n) {
    u32 i;
    u8 a;
    for (i = 0; i < n; i++) {
        a = func_ov003_021b807c(p);
        v1[i] = a ^ v2[i];
    }
}

u32 func_ov003_021b807c(Unk021b807c *p) {
    u8 *s;
    u32 n;
    u8 i;
    u8 j;
    u8 a;
    u8 b;
    s = p->mUnk_08;
    n = p->mUnk_0c;
    i = (p->mUnk_00 + 1) % n;
    a = s[i];
    j = (a + p->mUnk_04) % n;
    b = s[j];
    p->mUnk_00 = i;
    p->mUnk_04 = j;
    s[j] = a;
    s[i] = b;
    return s[(a + b) % p->mUnk_0c];
}

u8 func_ov003_021b8050(const u8 *p0, s32 p1) {
    return func_ov003_021b8010(~0, p0, p1, 0, (u32 *) data_ov003_021d7f6c) ^ ~0;
}

u32 func_ov003_021b8010(u32 a, const u8 *b, s32 c, s32 d, u32 *e) {
    s32 i;
    if (d == 0) {
        func_ov003_021b7fd4(d, e);
    }
    for (i = 0; i < c; i++) {
        a = (a >> 8) ^ e[(a ^ b[i]) & 0xff];
    }
    return a;
}

void func_ov003_021b7fd4(s32 a, u32 *b) {
    u32 c;
    s32 i;
    s32 j;
    for (i = 0; i < 0x100; i++) {
        c = i;
        for (j = 0; j < 8; j++) {
            if (c & 1) {
                c = (c >> 1) ^ 0xedb88320;
            } else {
                c = c >> 1;
            }
        }
        *b++ = c;
    }
}

s32 func_ov003_021b7f48(u8 *a, s32 b, const s8 *c, s32 d) {
    s8 *e;
    u8 *f;
    s32 i;
    e = func_ov003_021ba178(b / 2);
    if (e == NULL) {
        return -1;
    }
    f = func_ov003_021ba178(b);
    if (f == NULL) {
        func_ov003_021ba164(e);
        return -1;
    }
    for (i = 0; i < 2; i++) {
        func_ov003_021b7efc(i, e, b, c, d);
        func_ov003_021b7ed0(e, a, b);
        func_ov003_021b7e94(a, b, f);
    }
    func_ov003_021ba164(e);
    func_ov003_021ba164(f);
    return 0;
}

void func_ov003_021b7efc(s32 a, s8 *b, s32 c, const s8 *d, s32 e) {
    s32 f = c / 2;
    s32 g = a % e;
    s32 i;
    for (i = 0; i < f; i++) {
        b[i] = i;
        b[i] ^= d[g++];
        if (g >= e) {
            g = 0;
        }
    }
}

void func_ov003_021b7ed0(const s8 *key, u8 *buffer, s32 size) {
    s32 half = size / 2;
    s32 i;
    for (i = 0; i < half; i++) {
        buffer[half + i] ^= key[i];
    }
}

void func_ov003_021b7e94(u8 *a, u32 b, u8 *c) {
    int v1;
    v1 = _s32_div_f(b, 2);
    func_ov003_021b7d90(c, (a + v1), v1);
    func_ov003_021b7d90((c + v1), a, v1);
    func_ov003_021b7d90(a, c, b);
    return;
}

u32 func_ov003_021b7e70(u32 a, int b) {
    u32 v1;
    if (0 < b) {
        v1 = (*(UnkWordFunc *) (*(u32 *) &data_ov003_021d8a0c))(b);
        return v1;
    }
    return 0;
}

void func_ov003_021b7e58(u32 a, u32 b) {
    (*(UnkFunc *) (*(u32 *) &data_ov003_021d8a18))(b);
    return;
}

s32 func_ov003_021b7df4(u32 a, u32 b, u32 c) {
    data_ov003_021d6810.mUnk_10 = func_ov003_021b7cac(a);
    data_ov003_021d6810.mUnk_14 = func_ov003_021b7cac(b);
    data_ov003_021d6810.mUnk_18 = func_ov003_021b7cac(c);
    if (func_ov000_021a8c94(&data_ov003_021d6810) < 0) {
        return -1;
    }
    while (data_ov000_021b63b4 == 0) {
        func_0200dc3c(100);
    }
    return 0;
}

s32 func_ov003_021b7dc8(void) {
    if (func_ov000_021a8c8c() < 0) {
        return -1;
    }
    return -(func_ov003_021ba524() != 0);
}

s32 func_ov003_021b7da0(const u8 *left, const u8 *right, s32 count) {
    s32 difference = 0;
    while (count-- > 0 && (difference = *left - *right) == 0) {
        left++;
        right++;
    }
    return difference;
}

void func_ov003_021b7d90(void *arg0, const void *arg1, u32 arg2) {
    MemCopy(arg1, arg0, arg2);
}

void func_ov003_021b7d84(void *arg0, s32 arg1, u32 arg2) {
    u32 value0 = (u32) arg0;
    u32 value1 = (u32) arg1;
    u32 value2 = arg2;
    u32 value3;
    value1 = (value1 << 24);
    value1 = (value1 >> 24);
    value3 = (u32) &MemFill;
    MemFill((void *) value0, (u8) value1, value2);
    return;
}

s32 func_ov003_021b7d68(s32 v1, void *v2, s32 v3, s32 v4, Unk021b7cec *v5, s32 *v6) {
    v5->mUnk_00 = *v6;
    return func_ov000_021a90a0(v1, v2, v3, v4, v5);
}

s32 func_ov003_021b7d1c(s32 v1, Unk021b7ba0 *v2, void *v3, void *v4, Unk021b7d1c *v5) {
    Unk021b7ba0 t;
    s64 s;
    s = 0;
    t = *v2;
    s += v5->mUnk_00 * 0x1ff6210 / 0x40;
    s += v5->mUnk_04 * 0x1ff6210 / 0x40;
    return func_ov000_021a8b20(&t, 1, s);
}

s32 func_ov003_021b7d04(s32 a, void *b, s32 c, s32 d, Unk021b7cec *e, u32 f) {
    e->mUnk_00 = f;
    return func_ov000_021a9018(a, b, c, d, e);
}

s32 func_ov003_021b7d00(s32 id, s32 arg1, s32 arg2, void *value, s32 length) {
    return id;
}

s32 func_ov003_021b7cf8(s32 domain, s32 type, s32 protocol) {
    return func_ov000_021a918c(domain, type, protocol);
}

s32 func_ov003_021b7cec(s32 v1, Unk021b7cec *v2, u32 v3) {
    v2->mUnk_00 = v3;
    return func_ov000_021a916c(v1, v2);
}

s32 func_ov003_021b7ce4(s32 descriptor) {
    return func_ov000_021a9008(descriptor);
}

u32 func_ov003_021b7cac(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    u32 value3;
    u32 value4;
    value1 = (value0 << 24);
    value2 = 0xff000000u;
    value1 = (value1) & (value2);
    value4 = (value0 << 8);
    value2 = 0xff0000u;
    value4 = (value4) & (value2);
    value3 = (value0 >> 24);
    value2 = 255u;
    value3 = (value3) & (value2);
    value2 = (value0 >> 8);
    value0 = 0xff00u;
    value2 = (value2) & (value0);
    value3 = (value3) | (value2);
    value4 = (value4) | (value3);
    value1 = (value1) | (value4);
    value0 = (value1) + (0u);
    return value0;
}

u16 func_ov003_021b7c94(u16 value) {
    return ((value >> 8) & 0xff) | ((value << 8) & 0xff00);
}

u32 func_ov003_021b7c5c(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    u32 value3;
    u32 value4;
    value1 = (value0 << 24);
    value2 = 0xff000000u;
    value1 = (value1) & (value2);
    value4 = (value0 << 8);
    value2 = 0xff0000u;
    value4 = (value4) & (value2);
    value3 = (value0 >> 24);
    value2 = 255u;
    value3 = (value3) & (value2);
    value2 = (value0 >> 8);
    value0 = 0xff00u;
    value2 = (value2) & (value0);
    value3 = (value3) | (value2);
    value4 = (value4) | (value3);
    value1 = (value1) | (value4);
    value0 = (value1) + (0u);
    return value0;
}

u16 func_ov003_021b7c44(u16 value) {
    return ((value >> 8) & 0xff) | ((value << 8) & 0xff00);
}

int func_ov003_021b7c30(const void *a) {
    const s8 *p = a;
    int i = 0;
    while (p[i] != 0) {
        i++;
    }
    return i;
}

u16 func_ov003_021b7bb4(void) {
    s32 a;
    u32 b[3];
    u32 *c;
    if (data_ov003_021d7c48 == 0) {
        a = 0;
        func_ov003_021b7d84(b, 0, 12);
        if (func_0214df78(b) == 0) {
            a += b[0] << 10;
            a += b[1] << 3;
            a += b[2];
        }
        data_ov003_021d7c60[0] = a;
        data_ov003_021d7c60[1] = 0x5d588b65;
        data_ov003_021d7c60[2] = 0x269ec3;
        data_ov003_021d7c48 = 1;
    }
    data_ov003_021d7c60[0] = data_ov003_021d7c60[2] + data_ov003_021d7c60[1] * data_ov003_021d7c60[0];
    return ((data_ov003_021d7c60[0] >> 16) * 0x7fff) >> 16;
}
