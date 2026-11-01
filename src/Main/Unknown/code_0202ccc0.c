#include "Main/Unknown/code_0202ccc0.h"
#include "Main/Unknown/code_02025ebc.h"
#include "Main/Unknown/unk_02174000.h"
#include "Main/Unknown/code_02036000.h"
#include "code_0212df7c.h"
#include "code_0214cfe4.h"
#include "code_0214d018.h"
#include "00/code_02182fdc.h"
#include "01/code_021956dc.h"
#include "Main/Unknown/code_02025000.h"
#include "Main/Unknown/code_02025b84.h"
#include "Main/Unknown/code_02025bb4.h"
#include "Main/Unknown/code_0202d990.h"
#include "Main/Unknown/code_0202dd9c.h"
#include "Main/Unknown/code_0202e468.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02036c5c.h"
#include "Main/Unknown/code_020472a8.h"
#include "Main/Unknown/code_0204f5e4.h"
#include "Main/Unknown/code_0204f7f4.h"
#include "Main/Unknown/code_02053e74.h"
#include "Main/Unknown/code_02054f58.h"
#include "Main/Unknown/code_02108c04.h"
#include "Main/Unknown/code_02108c1c.h"
#include "Main/Unknown/code_02124094.h"
#include "Main/Unknown/code_02124bf0.h"
#include "Main/Unknown/code_02125f54.h"
#include "Main/Unknown/code_02125f6c.h"
#include "Main/Unknown/code_02126230.h"
#include "Main/Unknown/code_021262f0.h"
#include "Main/Unknown/code_021281b4.h"
#include "Main/Unknown/code_02128210.h"
#include "Main/Unknown/code_02128274.h"
#include "code_02148ca0.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_0202db04.h"
#include "Main/Unknown/unk_02153bec.h"
#include "Main/Unknown/unk_02162c74.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/code_0204ee64.h"
#include "Main/Unknown/code_0203be88.h"
#include "Main/Unknown/code_02126000.h"
#include "Main/Unknown/code_0202de00.h"
#include "Main/Unknown/code_02025cd0.h"
#include "Main/Unknown/code_02025d5c.h"

#pragma thumb on

void func_0202d868(s32 a, s32 b, s32 c, s32 d) {
    Unk0202de00_g t;
    u16 s[10];
    Unk02174e14_00 *p;
    s32 i;
    s32 j;
    s32 k;
    p = &data_02174e40->mUnk_050[1];
    if (a == 1) {
        func_0212426c(1, b, p->mUnk_14, func_020b3f7c(data_02174e40->mUnk_0ac, func_02025d74(func_0202db04(c))),
                      p->mUnk_0c, p->mUnk_18);
        func_0202dcf4(c, &t);
        func_02025cd0((short *) s, t.mUnk_02, t.mUnk_03, t.mUnk_00);
        func_02124224(1, b + 7, p->mUnk_14, s, p->mUnk_0c, p->mUnk_18, 7);
        j = func_0202dd80(c) == 0;
        p->mUnk_18[b].mUnk_00 = j;
        k = j == 0;
        p->mUnk_18[b + 7].mUnk_00 = k;
    } else if (a == 0) {
        for (i = 0; i < 7; i++) {
            j = i + 7;
            if (i == d) {
                k = 0xe;
            } else {
                k = 0xf;
            }
            func_02124100(i, k, p->mUnk_14, p->mUnk_18, p->mUnk_0c);
            func_02124100(j, k, p->mUnk_14, p->mUnk_18, p->mUnk_0c);
        }
    } else if (a == 2) {
        if (c >= 0 && c < (s32) func_0202ddc4()) {
            j = func_0202dd80(c) == 0;
            p->mUnk_18[b].mUnk_00 = j;
            k = j == 0;
            p->mUnk_18[b + 7].mUnk_00 = k;
        }
    }
}

#pragma thumb off

#pragma thumb on

void func_0202d82c(void) {
    void *v1;
    void *v2;
    v1 = func_020b3f7c((void *) data_02174e40->mUnk_0ac, 0xd);
    v2 = func_020b3f7c((void *) data_02174e40->mUnk_0a8, 4);
    data_02174e40->mUnk_0b0 = 8;
    func_02126230(v1, v2);
}

#pragma thumb off

#pragma thumb on

void func_0202d720(void) {
    u16 s[6];
    Unk02174e14_00 *p;
    s32 n;
    p = &data_02174e40->mUnk_050[1];
    func_0212426c(1, 0xe, p->mUnk_14, func_020b3f7c(data_02174e40->mUnk_0ac, 0x56), p->mUnk_0c, p->mUnk_18);
    func_0212426c(1, 0xf, p->mUnk_14, func_020b3f7c(data_02174e40->mUnk_0ac, 0x57), p->mUnk_0c, p->mUnk_18);
    n = (s32) func_0202ddb0();
    if (n < 10) {
        s[0] = ' ';
    } else {
        s[0] = n / 10 % 10 + '0';
    }
    s[1] = n % 10 + '0';
    s[2] = '/';
    s[3] = '3';
    s[4] = '2';
    s[5] = 0;
    func_02124224(1, 0x10, p->mUnk_14, s, p->mUnk_0c, p->mUnk_18, 6);
    n = (s32) func_0202dd9c();
    if (n < 10) {
        s[0] = ' ';
    } else {
        s[0] = n / 10 % 10 + '0';
    }
    s[1] = n % 10 + '0';
    s[2] = '/';
    s[3] = '1';
    s[4] = '0';
    s[5] = 0;
    func_02124224(1, 0x11, p->mUnk_14, s, p->mUnk_0c, p->mUnk_18, 6);
}

void func_0202d6a0(void) {
    Unk0202de00_g t;
    u16 n[10];
    u16 m[11];
    s32 a;
    s32 b;
    func_0202dcf4(data_02174e40->mUnk_0a4, &t);
    func_0202dc68(data_02174e40->mUnk_0a4, n);
    func_0214cffc(n, m, 0x14);
    m[10] = 0;
    a = func_0202dbe8(data_02174e40->mUnk_0a4);
    b = func_0202db68(data_02174e40->mUnk_0a4);
    func_0202de00((Unk02174e14 *) data_02174e40->mUnk_050, data_usa_02153bec, m, a, b,
                  func_0202db04(data_02174e40->mUnk_0a4), &t);
}

#pragma thumb off

#pragma thumb on

void func_0202d674(void) {
    void *v1;
    v1 = func_020b3f7c((void *) data_02174e40->mUnk_0ac, 0);
    func_0212658c(v1, (u32) 0, (u32) 0, (u32) 0, (u32) 0, (u32) 0, (u32) 0);
}

#pragma thumb off

#pragma thumb on

void func_0202d5f8(s32 a, s32 b) {
    u16 x[11];
    u16 y[0x100];
    void *r;
    r = func_020b3f7c(data_02174e40->mUnk_0ac, a);
    func_0214cffc(data_02174e40->mUnk_0b8, x, 0x14);
    x[10] = 0;
    func_0212513c(x, r, y, 0x100);
    if (b != 0) {
        func_02126230(y, func_020b3f7c(data_02174e40->mUnk_0a8, 4));
    } else {
        func_021262f0(y);
    }
}

void func_0202d5c0(void) {
    func_0202daa4(data_02174e40->mUnk_0a4);
    func_021262f0(func_020b3f7c(data_02174e40->mUnk_0ac, 9));
    func_021281c8(0xe);
    func_021282c8();
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
    func_02025b84(0, &data_02174e40->mUnk_050[2]);
    func_02025f80(&data_02174e40->mUnk_0cc, 3, 10, -0xc0, 0);
    func_021281c8(0xf);
    func_0204f804();
    data_02174e40->mUnk_0b0 = 1;
    func_02036820(data_02174e40->mUnk_0dc);
}

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
                    func_02126230(func_020b3f7c(data_02174e40->mUnk_0ac, 0x53),
                                  func_020b3f7c(data_02174e40->mUnk_0a8, 4));
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
                    func_0203bf04(func_0202ddec(), (void *) func_0202ddd8());
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

#pragma thumb off

#pragma thumb on

void func_0202cdd4(void) {
    func_02036ab0((void *) data_02174e40->mUnk_0dc);
    *(int *) &data_02174e40 = 0;
}

#pragma thumb off

#pragma thumb on

void func_0202ccc0(void) {
    s16 a = func_02025ebc((Unk02025ebc *) &data_02174e40->mUnk_0cc);
    int b;
    *(vu32 *) 0x4000010 = ((a << 16) & 0x1ff0000);
    b = -a;
    *(vu32 *) 0x400101c = ((b << 16) & 0x1ff0000);
    *(vu16 *) 0x400100e = (*(vu16 *) 0x400100e & ~3) | 1;
    if (a != 0) {
        *(vu32 *) 0x4000000 = (*(vu32 *) 0x4000000 & 0xffff1fff) | 0x2000;
        *(vu16 *) 0x4000048 = (u32) ((*(vu16 *) 0x4000048 & ~0x3f) | 0x1f) | 0x20;
        *(vu16 *) 0x400004a = (u32) ((*(vu16 *) 0x400004a & ~0x3f) | 0xe) | 0x20;
        *(vu16 *) 0x4000040 = 0xff;
        *(vu16 *) 0x4000044 = ((b << 8) & 0xff00) | 0xc0;
        *(vu32 *) 0x4001000 = (*(vu32 *) 0x4001000 & 0xffff1fff) | 0x2000;
        *(vu16 *) 0x4001048 = (u32) ((*(vu16 *) 0x4001048 & ~0x3f) | 0x1f) | 0x20;
        *(vu16 *) 0x400104a = (u32) ((*(vu16 *) 0x400104a & ~0x3f) | 7) | 0x20;
        *(vu16 *) 0x4001040 = 0xff;
        *(vu16 *) 0x4001044 = (a + 0xc0) & 0xff;
    } else {
        *(vu32 *) 0x4000000 = *(vu32 *) 0x4000000 & 0xffff1fff;
        *(vu32 *) 0x4001000 = *(vu32 *) 0x4001000 & 0xffff1fff;
    }
}

#pragma thumb off
