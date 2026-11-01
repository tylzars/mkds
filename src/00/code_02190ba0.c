#include "00/code_02190ba0.h"

u32 func_ov000_02190ba0(void *a, Unk021906e4 *b, const void *c, s32 d) {
    s32 f;
    u8 *e;
    s32 g;

    if (c == 0) {
        func_0213442c(data_ov000_021b2a18, data_ov000_021b28a8, 0, 0x51);
    }
    if (d < 0) {
        func_0213442c(data_ov000_021b2a28, data_ov000_021b28a8, 0, 0x52);
    }
    if (b == 0) {
        func_0213442c(data_ov000_021b2890, data_ov000_021b28a8, 0, 0x53);
    }
    if (c == 0) {
        return 0;
    }
    g = b->mUnk_08;
    f = b->mUnk_04;
    e = b->mUnk_00;
    if (f - g < d) {
        f += d < 0x800 ? 0x800 : d;
        e = func_ov000_021a3678(e, f + 1);
        if (e == 0) {
            func_ov000_02196590(a, data_ov000_021b292c);
            return 1;
        }
    }
    func_02134eb8(e + g, c, d);
    e[g + d] = 0;
    b->mUnk_08 += d;
    b->mUnk_04 = f;
    b->mUnk_00 = e;
    return 0;
}

u32 func_ov000_02190c64(void *a, Unk021906e4 *b, s32 c) {
    u8 *d;
    s32 e;
    s32 f;

    if (b == 0) {
        func_0213442c(data_ov000_021b2890, data_ov000_021b28a8, 0, 0x25);
    }
    e = b->mUnk_08;
    f = b->mUnk_04;
    d = b->mUnk_00;
    if (f == e) {
        f += 0x800;
        d = func_ov000_021a3678(d, f + 1);
        if (d == 0) {
            func_ov000_02196590(a, data_ov000_021b292c);
            return 1;
        }
    }
    d[e] = c;
    d[e + 1] = 0;
    b->mUnk_08 += 1;
    b->mUnk_04 = f;
    b->mUnk_00 = d;
    return 0;
}

u32 func_ov000_02190cd4(Unk0218f960 *a, s32 b) {
    Unk0218f960_00 *c;
    Unk02190ed4Node *d;
    Unk02190ed4Node *e;
    Unk02190ed4Node *f;
    Unk02190ed4Node *g;

    c = a->mUnk_00;
    if (b != 0) {
        d = c->mUnk_438;
        e = c->mUnk_43c;
        f = 0;
        c->mUnk_438 = 0;
        c->mUnk_43c = 0;
        g = d;
        if (g != 0) {
            do {
                Unk02190ed4Node *h = g->mUnk_14;
                if (g->mUnk_10 == b || g->mUnk_0c == 1) {
                    if (f != 0) {
                        f->mUnk_14 = h;
                    } else {
                        d = h;
                    }
                    if (e == g) {
                        e = f;
                    }
                    func_ov000_02190da0(a, g);
                } else {
                    f = g;
                }
                g = h;
            } while (g != 0);
        }
        if (c->mUnk_438 != 0) {
            c->mUnk_43c->mUnk_14 = d;
            c->mUnk_43c = e;
        } else {
            c->mUnk_438 = d;
            c->mUnk_43c = e;
        }
        return 0;
    }
    g = c->mUnk_438;
    while (g != 0) {
        c->mUnk_438 = 0;
        c->mUnk_43c = 0;
        while (g != 0) {
            d = g->mUnk_14;
            func_ov000_02190da0(a, g);
            g = d;
        }
        g = c->mUnk_438;
    }
    return 0;
}

void func_ov000_02190da0(Unk0218f960 *a, Unk02190ed4Node *b) {
    Unk02190da0Data *c;
    Unk02190da0Data *e;
    s32 d;

    if (b->mUnk_00.mUnk_00 == 0) {
        func_0213442c(data_ov000_021b2a38, data_ov000_021b2a58, 0, 0x6e);
    }
    if (b->mUnk_08 == 0) {
        func_0213442c(data_ov000_021b2a68, data_ov000_021b2a58, 0, 0x6f);
    }
    b->mUnk_00.mUnk_00(a, b->mUnk_08, b->mUnk_00.mUnk_04);
    if (b->mUnk_0c == 2) {
        c = b->mUnk_08;
        func_ov000_021a3668(c->mUnk_08);
        c = b->mUnk_08;
        c->mUnk_08 = 0;
    } else if (b->mUnk_0c == 3) {
        e = b->mUnk_08;
        for (d = 0; d < e->mUnk_38; d++) {
            func_ov000_021a3668(e->mUnk_3c[d]);
            e->mUnk_3c[d] = 0;
            func_ov000_021a3668(e->mUnk_40[d]);
            e->mUnk_40[d] = 0;
        }
        func_ov000_021a3668(e->mUnk_3c);
        e->mUnk_3c = 0;
        func_ov000_021a3668(e->mUnk_40);
        e->mUnk_40 = 0;
    } else if (b->mUnk_0c == 4) {
        c = b->mUnk_08;
        func_ov000_021a3668(c->mUnk_0c);
        c->mUnk_0c = 0;
    } else if (b->mUnk_0c == 7) {
        c = b->mUnk_08;
        if (c->mUnk_10 != 0) {
            func_ov000_021a3668(c->mUnk_10);
            c->mUnk_10 = 0;
        }
    } else if (b->mUnk_0c == 8) {
        c = b->mUnk_08;
        if (c->mUnk_08 != 0) {
            func_ov000_021a3668(c->mUnk_08);
            c->mUnk_08 = 0;
        }
    } else if (b->mUnk_0c == 9) {
        Unk02190da0Data *f = b->mUnk_08;
        for (d = 0; d < f->mUnk_04; d++) {
            func_ov000_021a3668(f->mUnk_08[d]);
            f->mUnk_08[d] = 0;
        }
        func_ov000_021a3668(f->mUnk_08);
        f->mUnk_08 = 0;
    }
    func_ov000_021a3668(b->mUnk_08);
    b->mUnk_08 = 0;
    func_ov000_021a3668(b);
}

u32 func_ov000_02190ed4(Unk0218f960 *a, Unk02190ed4Cb b, void *c, Unk021937c0Node *d, s32 e) {
    Unk0218f960_00 *f;
    Unk02190ed4Node *g;

    f = a->mUnk_00;
    g = func_ov000_021a3690(0x18);
    if (g == 0) {
        func_ov000_02196590(a, data_ov000_021b2a7c);
        return 1;
    }
    g->mUnk_00 = b;
    g->mUnk_08 = c;
    if (d != 0) {
        g->mUnk_10 = d->mUnk_18;
    } else {
        g->mUnk_10 = 0;
    }
    g->mUnk_0c = e;
    g->mUnk_14 = 0;
    if (f->mUnk_438 == 0) {
        f->mUnk_438 = g;
    }
    if (f->mUnk_43c != 0) {
        f->mUnk_43c->mUnk_14 = g;
    }
    f->mUnk_43c = g;
    return 0;
}

void func_ov000_02190f4c(Unk0218f960 *a, s32 b, s32 c) {
    Unk0218f960_00 *d;
    Unk02190ed4Cb e;
    Unk02190f4c *f;

    d = a->mUnk_00;
    if (d == 0) {
        func_0213442c(data_ov000_021b2a8c, data_ov000_021b2a58, 0, 0x23);
    }
    if (b == 0) {
        func_0213442c(data_ov000_021b2aa0, data_ov000_021b2a58, 0, 0x24);
    }
    if (c != 1 && c != 0) {
        func_0213442c(data_ov000_021b2ab8, data_ov000_021b2a58, 0, 0x25);
    }
    if (c == 1) {
        d->mUnk_41c = 1;
    }
    e = d->mUnk_1a4[0];
    if (e.mUnk_00 != 0) {
        f = func_ov000_021a3690(0x10);
        if (f != 0) {
            f->mUnk_00 = b;
            f->mUnk_0c = c;
            f->mUnk_04 = d->mUnk_418;
            f->mUnk_08 = d;
        }
        func_ov000_02190ed4(a, e, f, 0, 1);
    }
}

void func_ov000_02190ff8(Unk0218f960 *a, s32 b) {
    Unk0218f960_00 *c;
    Unk021937c0Node *d;
    Unk02193f2cNode *e;
    u32 f;

    c = a->mUnk_00;
    if (c->mUnk_1d8 == 4) {
        return;
    }
    if (c->mUnk_1d8 != 0) {
        if (b != 0 && c->mUnk_1d8 == 3) {
            func_ov000_02190b80(a, &c->mUnk_1f4, data_ov000_021b2b28);
            func_ov000_02190b58(a, &c->mUnk_1f4, c->mUnk_198);
            func_ov000_02190b80(a, &c->mUnk_1f4, data_ov000_021b2b3c);
        }
        func_ov000_021906e4(a, c->mUnk_1d4, &c->mUnk_1f4, &f, 1, (const s8 *) data_ov000_021b2b44);
        if (c->mUnk_1d4 != -1) {
            func_ov000_0218e524(c->mUnk_1d4, 2);
            func_ov000_0218e53c(c->mUnk_1d4);
            c->mUnk_1d4 = -1;
        }
        if (c->mUnk_204 != -1) {
            func_ov000_0218e524(c->mUnk_204, 2);
            func_ov000_0218e53c(c->mUnk_204);
            c->mUnk_204 = -1;
        }
        c->mUnk_1d8 = 4;
        c->mUnk_19c = 0;
        c->mUnk_1a0 = 0;
    }
    func_ov000_021a3668(c->mUnk_1dc);
    c->mUnk_1dc = 0;
    func_ov000_021a3668(c->mUnk_1ec);
    c->mUnk_1ec = 0;
    func_ov000_021a3668(c->mUnk_1f4.mUnk_00);
    c->mUnk_1f4.mUnk_00 = 0;
    func_ov000_021a3668(c->mUnk_440);
    c->mUnk_440 = 0;
    func_ov000_021a3668(c->mUnk_450);
    c->mUnk_450 = 0;
    while (c->mUnk_424 != 0) {
        func_ov000_02193818(a, c->mUnk_424);
    }
    c->mUnk_424 = 0;
    e = c->mUnk_434;
    while (e != 0) {
        Unk02193f2cNode *g = e;
        e = e->mNext;
        func_ov000_02194120(a, g);
    }
    c->mUnk_434 = 0;
    while (func_ov000_02194840(a, func_ov000_02191180, 0) == 0) {
    }
}

u32 func_ov000_02191180(Unk0218f960 *a, Unk02194934 *b) {
    Unk0218f960_00 *c;

    c = a->mUnk_00;
    if (b->mUnk_08 != 0 && c->mUnk_104 == 0) {
        func_ov000_021a3668(b->mUnk_08->mUnk_08);
        b->mUnk_08->mUnk_08 = 0;
        func_ov000_021a3668(b->mUnk_08->mUnk_0c);
        b->mUnk_08->mUnk_0c = 0;
        func_ov000_021a3668(b->mUnk_08);
        b->mUnk_08 = 0;
    }
    func_ov000_021a3668(b->mUnk_10);
    b->mUnk_10 = 0;
    func_ov000_021a3668(b->mUnk_18);
    b->mUnk_18 = 0;
    b->mUnk_14 = 0;
    if (b->mUnk_0c == 0 || (c->mUnk_104 == 1 && b->mUnk_08 == 0)) {
        func_ov000_021948f8(a, b);
        return 0;
    }
    return 1;
}
