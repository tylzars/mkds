#include "00/code_02191284.h"

u32 func_ov000_02191284(Unk0218f960 *a, Unk021937c0Node *b, const u8 *c) {
    Unk0218f960_00 *d;
    Unk02191284Data *e;
    u8 f[0x21];
    u8 g[0x15];
    u8 h[0x200];
    u8 i[0x52];
    Unk02190ed4Cb j;
    Unk02191284Node *k;
    void *l;
    u32 m;

    d = a->mUnk_00;
    if (func_ov000_02196870(a, c, 0) != 0) {
        if (d->mUnk_418 == 0x106 && d->mUnk_1a0 != 0) {
            func_ov000_0219490c(a, d->mUnk_1a0);
            d->mUnk_19c = 0;
            d->mUnk_1a0 = 0;
        } else if (d->mUnk_418 == 0x201) {
            if (func_ov000_021967b4(c, data_ov000_021b2b98, h, 0x200) != 0) {
                d->mUnk_1a0 = func_0213bf90(h);
            }
        }
        if (func_02139f70(c, data_ov000_021b2ba0) != 0) {
            func_ov000_021965a0(a, d->mUnk_418, d);
            func_ov000_02190f4c(a, 4, 1);
            return 4;
        }
        func_ov000_021965a0(a, d->mUnk_418, d);
        func_ov000_02190f4c(a, 4, 0);
        return 4;
    }
    e = (Unk02191284Data *) b->mUnk_04;
    switch (b->mUnk_14) {
        case 1:
            if (func_0213a038(c, data_ov000_021b2ba8, 5) != 0) {
                func_ov000_021965a0(a, 1, data_ov000_021b2bb0);
                func_ov000_02190f4c(a, 3, 1);
                return 3;
            }
            if (func_ov000_021967b4(c, data_ov000_021b2be0, e, 0x80) == 0) {
                func_ov000_021965a0(a, 1, data_ov000_021b2bb0);
                func_ov000_02190f4c(a, 3, 1);
                return 3;
            }
            if (e->mUnk_304 != 0) {
                m = func_ov000_021917b0(a, e);
                if (m != 0) {
                    return m;
                }
                b->mUnk_14 = 3;
            } else {
                m = func_ov000_021919ac((Unk021919ac *) a, (Unk021919ac_q *) e);
                if (m != 0) {
                    return m;
                }
                b->mUnk_14 = 2;
            }
            break;
        case 3:
            if (func_0213a038(c, data_ov000_021b2bec, 5) != 0) {
                func_ov000_021965a0(a, 1, data_ov000_021b2bb0);
                func_ov000_02190f4c(a, 3, 1);
                return 3;
            }
            if (func_ov000_021967b4(c, data_ov000_021b2bf4, h, 0x200) == 0) {
                func_ov000_021965a0(a, 1, data_ov000_021b2c00);
                func_ov000_02190f4c(a, 3, 1);
                return 3;
            }
            d->mUnk_19c = func_0213bf90(h);
            if (func_ov000_021967b4(c, data_ov000_021b2c30, h, 0x200) == 0) {
                func_ov000_021965a0(a, 1, data_ov000_021b2c00);
                func_ov000_02190f4c(a, 3, 1);
                return 3;
            }
            d->mUnk_1a0 = func_0213bf90(h);
            m = func_ov000_021919ac((Unk021919ac *) a, (Unk021919ac_q *) e);
            if (m != 0) {
                return m;
            }
            b->mUnk_14 = 2;
            break;
        case 2:
            if (func_0213a038(c, data_ov000_021b2c3c, 5) != 0) {
                func_ov000_021965a0(a, 1, data_ov000_021b2bb0);
                func_ov000_02190f4c(a, 3, 1);
                return 3;
            }
            if (func_ov000_021967b4(c, data_ov000_021b2c44, h, 0x200) == 0) {
                func_ov000_021965a0(a, 1, data_ov000_021b2c00);
                func_ov000_02190f4c(a, 3, 1);
                return 3;
            }
            d->mUnk_198 = func_0213bf90(h);
            if (func_ov000_021967b4(c, data_ov000_021b2bf4, h, 0x200) == 0) {
                func_ov000_021965a0(a, 1, data_ov000_021b2c00);
                func_ov000_02190f4c(a, 3, 1);
                return 3;
            }
            d->mUnk_19c = func_0213bf90(h);
            if (func_ov000_021967b4(c, data_ov000_021b2c30, h, 0x200) == 0) {
                func_ov000_021965a0(a, 1, data_ov000_021b2c00);
                func_ov000_02190f4c(a, 3, 1);
                return 3;
            }
            d->mUnk_1a0 = func_0213bf90(h);
            if (func_ov000_021967b4(c, data_ov000_021b2c50, g, 0x15) == 0) {
                g[0] = 0;
            }
            if (func_ov000_021967b4(c, data_ov000_021b2c60, d->mUnk_474, 0x19) == 0) {
                d->mUnk_474[0] = 0;
            }
            if (e->mUnk_c2[0] != 0) {
                l = e->mUnk_c2;
            } else if (d->mUnk_12f[0] != 0) {
                l = d->mUnk_12f;
            } else {
                func_02135014(i, data_ov000_021b2c68, d->mUnk_110, d->mUnk_144);
                l = i;
            }
            func_02135014(h, data_ov000_021b2c70, e->mUnk_a1, data_ov000_021b2c80, l, e, e->mUnk_80, e->mUnk_a1);
            func_ov000_0218e0fc(h, func_0213a434(h), f);
            if (func_ov000_021967b4(c, data_ov000_021b2cb4, h, 0x200) == 0) {
                func_ov000_021965a0(a, 1, data_ov000_021b2c00);
                func_ov000_02190f4c(a, 3, 1);
                return 3;
            }
            if (func_02134d30(f, h, 0x20) != 0) {
                func_ov000_021965a0(a, 0x108, data_ov000_021b2cbc);
                func_ov000_02190f4c(a, 3, 1);
                return 3;
            }
            if (d->mUnk_100 != 0) {
                Unk02194934 *n = func_ov000_0219496c(a, d->mUnk_1a0);
                n->mUnk_00 = d->mUnk_1a0;
                n->mUnk_04 = d->mUnk_19c;
            }
            d->mUnk_1d8 = 3;
            j = b->mUnk_0c;
            if (j.mUnk_00 != 0) {
                k = func_ov000_021a3690(0x20);
                if (k == 0) {
                    func_ov000_02196590(a, data_ov000_021b2cdc);
                    return 1;
                }
                func_02134de0(k, 0, 0x20);
                k->mUnk_04 = d->mUnk_1a0;
                k->mUnk_00 = 0;
                func_ov000_02196914(k->mUnk_08, g, 0x15);
                m = func_ov000_02190ed4(a, j, k, b, 0);
                if (m != 0) {
                    return m;
                }
            }
            func_ov000_02193818(a, b);
            break;
    }
    return 0;
}

u32 func_ov000_021917b0(Unk0218f960 *a, Unk02191284Data *b) {
    Unk0218f960_00 *c;
    u32 d;
    u32 e;
    s8 t;
    s8 f[0x1f];
    s8 g[0x2d];
    s8 h[0x41];
    s8 i[0x59];

    c = a->mUnk_00;
    d = func_0213a434((const u8 *) c->mUnk_177);
    func_ov000_0218e2a4(0x79707367);
    for (e = 0; e < d; e++) {
        t = func_ov000_0218e284(0, 0xff);
        f[e] = t ^ c->mUnk_177[e];
    }
    f[e] = 0;
    func_ov000_0218e15c(f, g, d, 1);
    func_ov000_02190b80(a, &c->mUnk_1f4, data_ov000_021b2cec);
    func_ov000_02190b80(a, &c->mUnk_1f4, data_ov000_021b2cf8);
    func_ov000_02190b80(a, &c->mUnk_1f4, c->mUnk_144);
    func_ov000_02190b80(a, &c->mUnk_1f4, data_ov000_021b2d00);
    func_ov000_02190b80(a, &c->mUnk_1f4, c->mUnk_110);
    func_ov000_02190b80(a, &c->mUnk_1f4, data_ov000_021b2d08);
    func_ov000_02190b80(a, &c->mUnk_1f4, g);
    func_ov000_02190b80(a, &c->mUnk_1f4, data_ov000_021b2d18);
    func_ov000_02190b58(a, &c->mUnk_1f4, c->mUnk_46c);
    func_ov000_02190b80(a, &c->mUnk_1f4, data_ov000_021b2d24);
    func_ov000_02190b80(a, &c->mUnk_1f4, data_ov000_021b4d6c);
    func_ov000_02190b80(a, &c->mUnk_1f4, data_ov000_021b2d30);
    func_ov000_02190b58(a, &c->mUnk_1f4, c->mUnk_470);
    func_ov000_02190b80(a, &c->mUnk_1f4, data_ov000_021b2c50);
    func_ov000_02190b80(a, &c->mUnk_1f4, c->mUnk_12f);
    if (b->mUnk_2c2[0] != 0) {
        d = func_0213a434((const u8 *) b->mUnk_2c2);
        func_ov000_0218e2a4(0x79707367);
        for (e = 0; e < d; e++) {
            t = func_ov000_0218e284(0, 0xff);
            h[e] = t ^ b->mUnk_2c2[e];
        }
        h[e] = 0;
        func_ov000_0218e15c(h, i, d, 1);
        func_ov000_02190b80(a, &c->mUnk_1f4, data_ov000_021b2d40);
        func_ov000_02190b80(a, &c->mUnk_1f4, i);
    }
    func_ov000_02190b80(a, &c->mUnk_1f4, data_ov000_021b2d4c);
    func_ov000_02190b80(a, &c->mUnk_1f4, data_ov000_021b2b3c);
    return 0;
}
