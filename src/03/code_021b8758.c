#include "03/code_021b8758.h"
#include "03/code_021b8050.h"

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
