#include "Main/Unknown/code_0202cdf4.h"

#pragma thumb on

s32 func_0202cdf4(Unk0202cdf4 *p) {
    u16 e;
    s32 b;
    s32 a;
    s32 c;
    s32 x;
    u16 t;
    Unk021759d4 *d;
    Unk02174e14_00 *q;
    s32 i;
    e = func_020435bc();
    c = 0;
    func_02025edc(&data_02174e40->mUnk_0cc);
    b = c;
    a = b;
    x = data_02175628[e].mUnk_4c;
    if (x == 0 && data_02175628[e].mUnk_58 < 5) {
        a = 1;
    }
    if (a == 0 && data_02175628[e].mUnk_54 == 0 && x != 0) {
        b = 1;
    }
    if (b != 0) {
        c = func_02128210(data_02175628[e].mUnk_48, data_02175628[e].mUnk_4a);
    }
    switch (data_02174e40->mUnk_0b0) {
        case 0:
            if (func_02125f54() != 0) {
                data_0217b488->mUnk_08 = 5;
                if (p != 0) {
                    p->mUnk_04 = 1;
                }
                data_02174e40->mUnk_0b0 = 0xe;
            }
            break;
        case 1:
            if (func_02036c5c() == 0) {
                if (func_0202ddc4() == 0) {
                    func_02126230((u32) func_020b3f7c(data_02174e40->mUnk_0ac, 0x53),
                                  (u32) func_020b3f7c(data_02174e40->mUnk_0a8, 4));
                    data_02174e40->mUnk_0b0 = 0;
                } else {
                    func_0202d6a0();
                    func_0202d674();
                    func_02128374();
                    func_02025f14(&data_02174e40->mUnk_0cc, 0);
                    data_02174e40->mUnk_0b0 = 2;
                }
            }
            break;
        case 2:
            if (data_02174e40->mUnk_0cc.mUnk_00 == 1) {
                data_02174e40->mUnk_0b4 = 0;
                data_02174e40->mUnk_0b0 = 3;
            } else {
                func_0202d554();
            }
            break;
        case 3:
            if (func_02125fa4() != 0) {
                func_0202e4b0();
                i = func_0202e4a4();
                if (data_02174e40->mUnk_0a4 != i) {
                    data_02174e40->mUnk_0a4 = i;
                    func_0202d6a0();
                }
                if (func_0202e468() != 0) {
                    func_0212d5e0(&data_0217c868);
                    func_0212ecc0(&data_0217d068, 0, 7);
                    func_0212d5e0(&data_0217d0a0);
                }
                if (func_0202e47c() != 0) {
                    func_0202d5c0();
                    func_02108c1c();
                    data_02174e40->mUnk_0b0 = 4;
                } else {
                    t = data_02175628[e].mUnk_00 & 2;
                    if (t != 0 || c != 0) {
                        data_0217b488->mUnk_08 = 5;
                        if (p != 0) {
                            p->mUnk_04 = 1;
                        }
                        data_02174e40->mUnk_0b0 = 0xe;
                        func_02128310(0);
                    }
                }
            }
            break;
        case 4:
            d = data_021759d4;
            if (d->mUnk_0c != 0) {
                i = d->mUnk_10;
            } else {
                i = 0;
            }
            if (i == 0 && d->mUnk_04 == 0) {
                if (func_0202dd80(data_02174e40->mUnk_0a4) == 0) {
                    func_0203bf04((void *) func_0202ddec(), (void *) func_0202ddd8());
                }
                data_02174e40->mUnk_0b0 = 5;
            }
            break;
        case 5:
            i = func_02054c98(1, (void *) func_0202ddd8());
            switch (i) {
                case 1:
                    func_0204f5e4();
                    func_0204eeac((void *) func_0202ddd8(), 0x1000);
                    func_02128374();
                    data_02174e40->mUnk_0b0 = 6;
                    break;
                case 2:
                    break;
            }
            break;
        case 6:
            t = data_02175628[e].mUnk_00 & 2;
            if (t != 0 || c != 0) {
                func_02128310(0);
                func_021281c8(0xf);
                func_02108c04();
                data_02174e40->mUnk_0b0 = 0xb;
            } else if (func_0204eb08(data_02174e40->mUnk_0b8) != 0) {
                func_021282c8();
                func_02108c04();
                func_0212d5e0(&data_0217c868);
                func_0212ecc0(&data_0217d068, 0, 9);
                func_0212d5e0(&data_0217d0a0);
                func_0202d5f8(0xb, 0);
                data_02174e40->mUnk_0b0 = 7;
            }
            break;
        case 7:
            i = func_0205465c();
            switch (i) {
                case 1:
                    func_0212d5e0(&data_0217c868);
                    func_0212ecc0(&data_0217d068, 0, 0xa);
                    func_0212d5e0(&data_0217d0a0);
                    data_02174e40->mUnk_0b0 = 0xa;
                    break;
                case 2:
                    func_0202d82c();
                    break;
            }
            break;
        case 8:
            if (func_02125f6c() != 0) {
                func_0212ecc0(&data_0217d068, 0, 0x15);
            }
            if (func_02125f54() != 0) {
                data_02174e40->mUnk_0b0 = 9;
            }
            break;
        case 9:
            if (func_02054f58() == 1) {
                func_0204f804();
                data_0217b488->mUnk_08 = 5;
                if (p != 0) {
                    p->mUnk_04 = 1;
                }
                data_02174e40->mUnk_0b0 = 0xe;
            }
            break;
        case 10:
            if (func_02054f58() == 1) {
                func_0204f804();
                func_0202d5f8(0xc, 1);
                data_02174e40->mUnk_0b0 = 0xd;
            }
            break;
        case 11:
            if (func_02054f58() == 1) {
                func_0204f804();
                func_0202d674();
                data_02174e40->mUnk_0b0 = 3;
            }
            break;
        case 13:
            if (func_02125f54() != 0) {
                data_0217b488->mUnk_08 = 5;
                if (p != 0) {
                    p->mUnk_04 = 1;
                }
                data_02174e40->mUnk_0b0 = 0xe;
            }
            break;
    }
    func_02054aa0();
    for (i = 0; i < 2; i++) {
        q = data_02174e40->mUnk_050;
        func_02124c30(q[i].mUnk_0c, q[i].mUnk_08, q[i].mUnk_14, data_02174e40->mUnk_048[i], q[i].mUnk_18);
    }
    return -1;
}

void func_0202d210(void *a, void *b, void *c) {
    s16 r[4];
    s32 j;
    s32 k;
    Unk02124b1c *u;
    Unk02174e14_00 *p;
    Unk02174e14_00 *q;
    void *h;
    s32 i;
    s32 n;
    s32 w;
    s32 m;
    h = func_02036948(a);
    data_02174e40 = func_02036bec(h, 0xe0);
    func_0214d05c_inline(data_02174e40, 0xe0);
    data_02174e40->mUnk_0dc = h;
    data_02174e40->mUnk_048[0] = b;
    data_02174e40->mUnk_048[1] = c;
    data_02174e40->mUnk_0a8 = func_02047a28(data_usa_02162d04);
    data_02174e40->mUnk_0ac = func_0204799c(data_usa_02162d10);
    func_0204f240(data_02174e40->mUnk_0dc, 2);
    func_020258d4(0, data_02174e40, data_usa_02162d1c, data_usa_02162d3c, data_usa_02162d5c, 0, func_0204799c);
    p = &data_02174e40->mUnk_050[0];
    n = func_02148cb8();
    func_02025b20(p, data_usa_02162d7c, data_usa_02162da0, data_usa_02162dc4, data_usa_02162de4, data_usa_02162e04, 0,
                  func_0204799c);
    func_02025a50(0, data_02174e40->mUnk_0dc, p);
    for (i = 0; i < p->mUnk_14->mUnk_06; i++) {
        n -= func_02025a00(0, data_02174e40->mUnk_0dc, p, data_usa_02153bec[i], n);
    }
    func_020258d4(1, &data_02174e40->mUnk_024, data_usa_02162e24, data_usa_02162e44, data_usa_02162e64, 3,
                  func_0204799c);
    q = &data_02174e40->mUnk_050[1];
    n = func_02148ca0();
    m = 0;
    func_02025b20(q, data_usa_02162e84, data_usa_02162ea8, data_usa_02162ecc, data_usa_02162eec, data_usa_02162f0c,
                  data_usa_02162f2c, func_0204799c);
    func_02025a50(1, data_02174e40->mUnk_0dc, q);
    w = q->mUnk_0c->mUnk_06;
    for (i = 0; i < q->mUnk_14->mUnk_06; i++) {
        if (data_usa_02162c74[i][3] < 0) {
            data_usa_02162c74[i][3] = w + m++;
        }
        n -= func_02025a00(1, data_02174e40->mUnk_0dc, q, (s16(*)[4]) data_usa_02162c74 + i, n);
    }
    func_0202d720();
    for (i = 0; i < 0xf; i++) {
        func_021249a8(i, 3, q->mUnk_08, q->mUnk_0c);
    }
    for (i = 0; i < 0xe; i++) {
        func_02124094(i, 2, q->mUnk_14, q->mUnk_18, q->mUnk_0c);
    }
    for (i = 0; i < 0xe; i++) {
        j = data_usa_02162c74[i][3];
        k = data_usa_02162c74[i][0];
        u = q->mUnk_18;
        func_02025c1c(j, (int) &u[j], (u32) q->mUnk_0c);
        func_02025bf0(k, (int) (u + w + k), (u32) q->mUnk_14);
    }
    func_02025c1c(0xe, (int) ((u8 *) q->mUnk_18 + 0x380), (u32) q->mUnk_0c);
    if (func_0202ddc4() != 0) {
        Unk02174e40_24 *s = &data_02174e40->mUnk_024;
        r[0] = 0;
        r[1] = 7;
        r[2] = w;
        r[3] = w + 7;
        func_0202e530(data_02174e40->mUnk_0dc, 4, r, 0xe, 0xf, 0x7c, q->mUnk_18, q->mUnk_10, s->mUnk_20 + 0xc, 0, 1, 2,
                      func_0202ddc4(), func_0202d868);
    } else {
        for (i = 0; i < w; i++) {
            q->mUnk_18[i].mUnk_00 = 0;
        }
        for (i = 0; i < 0xe; i++) {
            q->mUnk_18[w + i].mUnk_00 = 0;
        }
    }
    func_02025b84(0, (u32) &data_02174e40->mUnk_050[2]);
    func_02025f80(&data_02174e40->mUnk_0cc, 3, 10, -0xc0, 0);
    func_021281c8(0xf);
    func_0204f804();
    data_02174e40->mUnk_0b0 = 1;
    func_02036820(data_02174e40->mUnk_0dc);
}

void func_0202d554(void) {
    Unk02174e14_00 *p;
    Unk02174e14_00 *q;
    s32 n;
    s32 m;
    s32 i;
    s16 k;
    p = &data_02174e40->mUnk_050[0];
    q = &data_02174e40->mUnk_050[1];
    n = p->mUnk_0c->mUnk_06 + p->mUnk_14->mUnk_06;
    m = q->mUnk_0c->mUnk_06 + q->mUnk_14->mUnk_06;
    k = func_02025ebc(&data_02174e40->mUnk_0cc);
    for (i = 0; i < n; i++) {
        p->mUnk_18[i].mUnk_06 = -k;
    }
    for (i = 0; i < m; i++) {
        q->mUnk_18[i].mUnk_06 = k;
    }
}

void func_0202d5c0(void) {
    func_0202daa4(data_02174e40->mUnk_0a4);
    func_021262f0((u32) func_020b3f7c(data_02174e40->mUnk_0ac, 9));
    func_021281c8(0xe);
    func_021282c8();
}

void func_0202d5f8(s32 a, s32 b) {
    u16 x[11];
    u16 y[0x100];
    void *r;
    r = func_020b3f7c(data_02174e40->mUnk_0ac, a);
    func_0214cffc(data_02174e40->mUnk_0b8, x, 0x14);
    x[10] = 0;
    func_0212513c(x, r, y, 0x100);
    if (b != 0) {
        func_02126230((u32) y, (u32) func_020b3f7c(data_02174e40->mUnk_0a8, 4));
    } else {
        func_021262f0((u32) y);
    }
}

#pragma thumb off
