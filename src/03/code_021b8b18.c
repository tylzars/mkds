#include "03/code_021b8b18.h"
#include "03/code_021b7bb4.h"
#include "03/code_021b8748.h"
#include "03/code_021b807c.h"
#include "03/code_021b7efc.h"

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

s32 func_ov003_021b8c44(s32 a, const u8 *b) {
    s32 c;
    s32 i;
    s32 d;
    u8 *p;
    c = 0;
    d = 0;
    i = 0;
    p = data_ov003_021d7c58;
    do {
        if (*p != 0) {
            d = 1;
            break;
        }
        p++;
        i++;
    } while (i < 6);
    if (d != 0) {
        if (func_ov003_021b7da0(data_ov003_021d7c58, b, 6) != 0) {
            c = 1;
        }
    } else if (a != 0x1000) {
        c = 2;
    }
    return c;
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
    if (f == 0) {
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
