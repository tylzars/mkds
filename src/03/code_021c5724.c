#include "03/code_021c5724.h"

#include "03/unk_021d5000.h"
#include "03/unk_021da000.h"
#include "03/code_021bf698.h"
#include "03/code_021cca74.h"
#include "code_0212df7c.h"
#include "03/code_021cdbd0.h"
#include "03/code_021d3000.h"
#include "03/code_021d3488.h"
#include "registers.h"
#include "code_02147cd8.h"
#include "03/code_021d3254.h"
#include "code_0214d018.h"
#include "Main/Unknown/code_02147000.h"
#include "03/code_021cb4d0.h"
#include "03/code_021cbf60.h"
#include "03/code_021cef90.h"
#include "03/code_021d1440.h"
#include "03/code_021d1dd0.h"
#include "03/unk_021d6000.h"
#include "03/code_021c6000.h"
#include "03/code_021c2000.h"
#include "03/code_021bf4dc.h"
#include "03/code_021bf098.h"
#include "03/code_021bf410.h"
#include "03/code_021c209c.h"
#include "03/code_021cb000.h"
#include "03/code_021cc8d4.h"
#include "03/code_021cd000.h"
#include "03/code_021cd0d0.h"
#include "03/code_021b94b8.h"
#include "03/code_021cd2e0.h"
#include "03/code_021d1000.h"
#include "03/code_021d1f70.h"
#include "03/code_021d254c.h"
#include "03/code_021d2ecc.h"
#include "03/code_021d1fd0.h"
#include "03/code_021d27d8.h"
#include "03/code_021bf000.h"
#include "03/code_021c5000.h"
#include "03/code_021ce000.h"
#include "03/unk_021d7000.h"
#include "code_0214b824.h"
#include "03/code_021c5548.h"
#include "03/code_021d2940.h"
#include "03/code_021bf810.h"
#include "Main/Unknown/code_0200e000.h"
#include "code_0214cfe4.h"
#include "03/code_021d1c18.h"
#include "03/code_021c6764.h"
#include "03/code_021ca56c.h"
#include "03/code_021cce78.h"

void func_ov003_021c6668(void) {
    s32 a;
    data_ov003_021da1f4 = func_ov003_021d283c(0x5c, 4);
    func_ov003_021c20dc(&a, NULL);
    if (a == 0) {
        data_ov003_021da1ec = 0;
        *(u16 *) &data_ov003_021da1f0 = 0;
    }
    data_ov003_021da1f4->mUnk_51 = func_ov003_021cd0d0((s32 *) data_ov003_021da1f4);
    func_ov003_021c6588();
    func_ov003_021bf854();
    func_ov003_021bf43c(0x80, -1, 0);
    func_ov003_021bf5ec(2);
    func_ov003_021c6508();
    func_ov003_021c6400();
    data_ov003_021da1f4->mUnk_0c = func_ov003_021d2288(0, 0);
    data_ov003_021da1f4->mUnk_3c = func_ov003_021d3544(1, func_ov003_021c5944, NULL, 0x6e);
    func_ov003_021c5c68();
    func_ov003_021c590c();
    func_ov003_021c212c(func_ov003_021c63c4);
}

void func_ov003_021c6588(void) {
    u8 a[0x19] = "char/xb4ApListBack.nsc.l";
    u8 b[0x16] = "char/ybBgStep31.ncl.l";
    func_ov003_021bf620(data_ov003_021d7260, MemCopyHalfwordsToG2Bg3CntBits8To12Address);
    data_ov003_021da1f4->mUnk_04 = func_ov003_021d14b8(func_ov003_021bf650(a), NULL, 4);
    func_ov003_021cca30(data_ov003_021da1f4->mUnk_04);
    func_ov003_021cc9fc();
    data_ov003_021da1f4->mUnk_08 = func_ov003_021d14b8(func_ov003_021bf650(b), NULL, 4);
    *(vu16 *) 0x4001008 = (*(vu16 *) 0x4001008 & ~3) | 3;
    *(vu16 *) 0x400100a = (*(vu16 *) 0x400100a & ~3) | 3;
    *(vu16 *) 0x4000008 = (*(vu16 *) 0x4000008 & ~3) | 3;
    *(vu16 *) 0x400000a = (*(vu16 *) 0x400000a & ~3) | 2;
    *(vu16 *) 0x400000c = (*(vu16 *) 0x400000c & ~3) | 3;
    *(vu16 *) 0x400000e = (*(vu16 *) 0x400000e & ~3) | 2;
}

void func_ov003_021c6508(void) {
    int a;
    u32 b;
    b = 0;
    data_ov003_021da1f4->mUnk_40 = (data_ov003_021da1f4->mUnk_51 - 4) * 0x1c;
    if (data_ov003_021da1f4->mUnk_51 <= 4) {
        a = 0;
        data_ov003_021da1f4->mUnk_53 = 0;
    } else if (data_ov003_021da1f4->mUnk_51 <= 8) {
        a = 1;
        data_ov003_021da1f4->mUnk_53 = 0x1f;
    } else {
        a = 2;
        data_ov003_021da1f4->mUnk_53 = 0x37;
    }
    if (a != 0) {
        b = Div32(*(u16 *) &data_ov003_021da1f0 * data_ov003_021da1f4->mUnk_53, data_ov003_021da1f4->mUnk_40);
    }
    func_ov003_021ccea4(a, 0x55, 0xec, 0x3f, b);
}

void func_ov003_021c6400(void) {
    int n;
    int i;
    u32 j;
    n = data_ov003_021da1f4->mUnk_51;
    if (n > 5) {
        n = 5;
    }
    for (i = 0; i < n; i++) {
        data_ov003_021da1f4->mUnk_10[i] = func_ov003_021d1c18(0, data_ov003_021d6388[0]);
        data_ov003_021da1f4->mUnk_24[i] = func_ov003_021d1c18(0, data_ov003_021d638c[0]);
    }
    for (j = 0; j < 3; j++) {
        func_ov003_021d1c3c(0, data_ov003_021d6388[j], (u8 *) data_ov003_021da1f4->mUnk_10[0]);
        data_ov003_021da1f4->mUnk_42[j] = data_ov003_021da1f4->mUnk_10[0]->mUnk_04 & 0x3ff;
    }
    for (j = 0; j < 4; j++) {
        func_ov003_021d1c3c(0, data_ov003_021d638c[j], (u8 *) data_ov003_021da1f4->mUnk_24[0]);
        data_ov003_021da1f4->mUnk_48[j] = data_ov003_021da1f4->mUnk_24[0]->mUnk_04 & 0x3ff;
    }
    for (i = 0; i < n; i++) {
        Unk021da104_04 *q;
        q = data_ov003_021da1f4->mUnk_10[i];
        q->mUnk_04 = (q->mUnk_04 & 0xfffff3ff) | 0xc00;
        q = data_ov003_021da1f4->mUnk_24[i];
        q->mUnk_04 = (q->mUnk_04 & 0xfffff3ff) | 0xc00;
    }
}

void func_ov003_021c63c4(void) {
    func_ov003_021d1ee0(2, 1, 1, (u16) (8));
    func_ov003_021d1ee0(2, 0, 0x1d, (u16) (8));
    func_ov003_021d2784(1, 1);
    func_ov003_021d2784(0, 0x1d);
    func_ov003_021c212c(func_ov003_021c6394);
    return;
}

void func_ov003_021c6394(void) {
    int v1;
    v1 = func_ov003_021d1f70(1);
    if ((v1 == 0) && (v1 = func_ov003_021d1f70(0), v1 == 0)) {
        func_ov003_021bf5c8(0);
        func_ov003_021c212c(func_ov003_021c6370);
    }
    return;
}

void func_ov003_021c6370(void) {
    if (func_ov003_021bf334() != -2) {
        func_ov003_021bf2e0();
        func_ov003_021c212c(func_ov003_021c6358);
    }
}

void func_ov003_021c6358(void) {
    func_ov003_021c6184();
    func_ov003_021c5f9c();
    func_ov003_021c5ec4();
    return;
}

void func_ov003_021c6184(void) {
    int i;
    Unk021d299c *p;
    if (data_ov003_021da1f4->mUnk_38 != 0) {
        return;
    }
    if (data_ov003_021da1f4->mUnk_57 != 0) {
        return;
    }
    if (func_ov003_021d2a34(&data_ov003_021d67e8) != 0) {
        i = 0;
        data_ov003_021da1f4->mUnk_50 = -1;
        p = data_ov003_021d6390;
        do {
            if (func_ov003_021d2a34(p) != 0) {
                if (i < 4) {
                    data_ov003_021da1f4->mUnk_50 = i;
                    break;
                }
                func_ov003_021bf31c(1);
                data_ov003_021da1ec = i;
                func_ov003_021c590c();
                return;
            }
            p++;
            i++;
        } while ((u32) i < 5);
    }
    if (func_ov003_021d299c(&data_ov003_021d67e8) != 0) {
        i = 0;
        p = data_ov003_021d6390;
        do {
            if (func_ov003_021d299c(p) != 0) {
                if (data_ov003_021da1f4->mUnk_50 != i) {
                    break;
                }
                if (i >= data_ov003_021da1f4->mUnk_51) {
                    func_ov003_021cdc10(9);
                    break;
                }
                func_ov003_021bf31c(1);
                data_ov003_021da1ec = i;
                func_ov003_021c590c();
                return;
            }
            p++;
            i++;
        } while (i < 4);
    }
    if (func_ov003_021d2b04(1) != 0) {
        func_ov003_021bf31c(1);
        func_ov003_021cce38();
        return;
    }
    if (func_ov003_021d2b04(2) != 0) {
        func_ov003_021bf31c(0);
        return;
    }
    if (func_ov003_021d2ae8(0x200) != 0) {
        func_ov003_021c574c();
        return;
    }
    if (func_ov003_021d2acc(0x200) != 0) {
        data_ov003_021da1f4->mUnk_59 = 0;
        return;
    }
    if (func_ov003_021d2ae8(0x100) != 0) {
        func_ov003_021c57b4();
        return;
    }
    if (func_ov003_021d2acc(0x100) != 0) {
        data_ov003_021da1f4->mUnk_59 = 0;
        return;
    }
    if (func_ov003_021d2ae8(0x40) != 0) {
        func_ov003_021c580c(1);
        return;
    }
    if (func_ov003_021d2acc(0x40) != 0) {
        data_ov003_021da1f4->mUnk_59 = 0;
        return;
    }
    if (func_ov003_021d2ae8(0x80) != 0) {
        func_ov003_021c580c(3);
        return;
    }
    if (func_ov003_021d2acc(0x80) != 0) {
        data_ov003_021da1f4->mUnk_59 = 0;
    }
}

void func_ov003_021c5f9c(void) {
    Unk021c5c68State *s;
    int a;
    s = data_ov003_021da1f4;
    if (s->mUnk_38 != 0) {
        return;
    }
    if (s->mUnk_55 != 0) {
        s->mUnk_55--;
    }
    switch (func_ov003_021cce60()) {
        case 1:
            data_ov003_021da1f4->mUnk_57 = 1;
            func_ov003_021bf2d0();
            break;
        case 2:
            if (data_ov003_021da1f4->mUnk_55 == 0) {
                func_ov003_021bf698();
                *(u16 *) &data_ov003_021da1f0 =
                    Div32(data_ov003_021da1f4->mUnk_40 * func_ov003_021cce6c(), data_ov003_021da1f4->mUnk_53);
                func_ov003_021c5c68();
                data_ov003_021da1f4->mUnk_55 = 4;
            }
            break;
        case 3:
            data_ov003_021da1f4->mUnk_57 = 0;
            func_ov003_021bf2e0();
            *(u16 *) &data_ov003_021da1f0 =
                Div32(data_ov003_021da1f4->mUnk_40 * func_ov003_021cce6c(), data_ov003_021da1f4->mUnk_53);
            func_ov003_021cdc10(0x13);
            func_ov003_021c5c68();
            a = Div32Remainder(*(u16 *) &data_ov003_021da1f0, 0x1c);
            if (a == 0) {
                func_ov003_021c590c();
            } else if (a < 0xe) {
                data_ov003_021da1f4->mUnk_38 = func_ov003_021d3544(0, func_ov003_021c5a0c, NULL, 0x78);
            } else {
                data_ov003_021da1f4->mUnk_38 = func_ov003_021d3544(0, func_ov003_021c5994, NULL, 0x78);
            }
            break;
        case 4:
            if (*(u16 *) &data_ov003_021da1f0 == 0) {
                if (data_ov003_021da1f4->mUnk_58 == 0) {
                    func_ov003_021cdc10(9);
                    data_ov003_021da1f4->mUnk_58 = 1;
                }
            } else {
                func_ov003_021cdc10(0x13);
                data_ov003_021da1f4->mUnk_38 = func_ov003_021d3544(0, func_ov003_021c5a0c, NULL, 0x78);
            }
            break;
        case 6:
            s = data_ov003_021da1f4;
            if (s->mUnk_51 <= 4 || *(u16 *) &data_ov003_021da1f0 == s->mUnk_40) {
                if (s->mUnk_58 == 0) {
                    func_ov003_021cdc10(9);
                    data_ov003_021da1f4->mUnk_58 = 1;
                }
            } else {
                func_ov003_021cdc10(0x13);
                data_ov003_021da1f4->mUnk_38 = func_ov003_021d3544(0, func_ov003_021c5994, NULL, 0x78);
            }
            break;
        case 5:
        case 7:
            data_ov003_021da1f4->mUnk_58 = 0;
            break;
    }
}

void func_ov003_021c5ec4(void) {
    int b;
    if (data_ov003_021da1f4->mUnk_38 == 0 && data_ov003_021da1f4->mUnk_57 == 0) {
        switch (func_ov003_021bf334()) {
            case 0:
                func_ov003_021cdc10(7);
                break;
            case 1:
                if (data_ov003_021da1ec == 4) {
                    data_ov003_021da1f4->mUnk_54 = 1;
                    func_ov003_021cdc10(6);
                    func_ov003_021c5724();
                } else {
                    b = data_ov003_021da1ec + Div32(*(u16 *) &data_ov003_021da1f0, 0x1c);
                    if ((data_ov003_021da1f4->mUnk_00 + b * 0x2a)[0x28] == 2) {
                        func_ov003_021cdc10(9);
                        func_ov003_021cce38();
                        func_ov003_021bf2d0();
                        func_ov003_021cefc0(0x42, 1, 1, -1, 0);
                        func_ov003_021c212c(func_ov003_021c56fc);
                        return;
                    }
                    data_ov003_021da1f4->mUnk_54 = 1;
                    data_ov003_021da1f4->mUnk_52 = b;
                    func_ov003_021cdc10(6);
                }
                break;
            default:
                return;
        }
        func_ov003_021c212c(func_ov003_021c5ea4);
    }
}

void func_ov003_021c5ea4(void) {
    func_ov003_021bf2d0();
    func_ov003_021d1dd0((u16) (8));
    func_ov003_021c212c(func_ov003_021c5e54);
    return;
}

void func_ov003_021c5e54(void) {
    if (func_ov003_021d1f70(1) == 0) {
        if (data_ov003_021da1f4->mUnk_54 != 0) {
            func_ov003_021bf344();
        } else {
            func_ov003_021bf2d0();
        }
        func_ov003_021d1ee0(3, 1, 1, 8);
        func_ov003_021d1ee0(3, 0, 0x1d, 8);
        func_ov003_021c212c(func_ov003_021c5cdc);
    }
}

void func_ov003_021c5cdc(void) {
    int i;
    Unk021c5c68State *s;
    if (func_ov003_021d1f70(1) != 0) {
        return;
    }
    if (func_ov003_021d1f70(0) != 0) {
        return;
    }
    if (func_ov003_021bf2f0() == 0) {
        return;
    }
    func_ov003_021d34c0(1, data_ov003_021da1f4->mUnk_3c);
    for (i = 0; i < 5; i++) {
        if (data_ov003_021da1f4->mUnk_10[i] != NULL) {
            func_ov003_021d2f00((u32 *) data_ov003_021da1f4->mUnk_10[i]);
        }
        if (data_ov003_021da1f4->mUnk_24[i] != NULL) {
            func_ov003_021d2f00((u32 *) data_ov003_021da1f4->mUnk_24[i]);
        }
    }
    func_ov003_021d2188(data_ov003_021da1f4->mUnk_0c);
    func_ov003_021cce78();
    func_ov003_021bf698();
    func_ov003_021bf410();
    func_ov003_021cca10();
    func_ov003_021d1490(data_ov003_021da1f4->mUnk_04);
    func_ov003_021d1490(data_ov003_021da1f4->mUnk_08);
    func_ov003_021d272c(1, 1);
    func_ov003_021d272c(0, 0x1d);
    *(vu32 *) 0x4000010 = 0;
    *(vu32 *) 0x4000018 = 0;
    s = data_ov003_021da1f4;
    if (s->mUnk_54 == 0) {
        func_ov003_021cd27c();
        func_ov003_021cd790(func_ov003_021cdb6c()->mUnk_f4);
        func_ov003_021c2120(2, 0);
        func_ov003_021c212c(func_ov003_021cb7fc);
    } else if (data_ov003_021da1ec == 4) {
        func_ov003_021cd27c();
        func_ov003_021c2120(0, 1);
        func_ov003_021c212c(func_ov003_021ca8e8);
    } else {
        func_ov003_021cdb14(s->mUnk_00 + s->mUnk_52 * 0x2a);
        func_ov003_021c2120(0, 0);
        if ((data_ov003_021da1f4->mUnk_00 + data_ov003_021da1f4->mUnk_52 * 0x2a)[0x28] != 0) {
            func_ov003_021c2120(0, 1);
            func_ov003_021c20f8(1, 1);
            func_ov003_021c212c(func_ov003_021c6e38);
        } else {
            func_ov003_021c2120(0, 1);
            func_ov003_021c20f8(0, 1);
            func_ov003_021c212c(func_ov003_021cbf60);
        }
    }
    func_ov003_021d2808(&data_ov003_021da1f4);
}

void func_ov003_021c5c68(void) {
    int v1;
    int v2;
    int v3;
    int v4;
    v1 = Div32((u32) ((*(u16 *) &data_ov003_021da1f0)), 0x1c);
    v4 = data_ov003_021da1f4->mUnk_51;
    func_ov003_021d2060(data_ov003_021da1f4->mUnk_0c, 0);
    if (5 < v4) {
        v4 = 5;
    }
    v2 = 0;
    v3 = v1;
    if (v4 > 0) {
        do {
            func_ov003_021c5b90(v3, v2);
            v2 = v2 + 1;
            v3 = v3 + 1;
        } while (v2 < v4);
    }
    v3 = 0;
    if (v4 > 0) {
        do {
            func_ov003_021c5b34(v1, v3);
            v3 = v3 + 1;
            v1 = v1 + 1;
        } while (v3 < v4);
    }
    func_ov003_021d1fd0(data_ov003_021da1f4->mUnk_0c);
    func_ov003_021c5aa4();
    return;
}

void func_ov003_021c5b90(int param_0, int param_1) {
    u16 a[17];
    int b;
    int c;
    int i;
    int n;
    c = param_0 * 0x2a;
    b = func_ov003_021d3254(data_ov003_021da1f4->mUnk_00 + c, 0x20);
    param_1 *= 0x1c;
    if (param_0 < data_ov003_021da1f4->mUnk_51) {
        if (b <= 0x10) {
            param_1 += 6;
        }
        MI_CpuFill8(a, 0, 0x22);
        if (b <= 0x10) {
            n = b;
        } else {
            n = 0x10;
        }
        for (i = 0; i < n; i++) {
            a[i] = (data_ov003_021da1f4->mUnk_00 + c)[i];
        }
        func_ov003_021d2094(data_ov003_021da1f4->mUnk_0c, 0xa, param_1, 2, 0xa, a, 1);
        if (b > 0x10) {
            MI_CpuFill8(a, 0, 0x22);
            n = b - 0x10;
            for (i = 0; i < n; i++) {
                a[i] = (data_ov003_021da1f4->mUnk_00 + c)[i + 0x10];
            }
            param_1 += 0xc;
            func_ov003_021d2094(data_ov003_021da1f4->mUnk_0c, 0xa, param_1, 2, 0xa, a, 1);
        }
    }
}

void func_ov003_021c5b34(int param_0, int param_1) {
    Unk021da104_04 *p;
    int m;
    if (param_0 < data_ov003_021da1f4->mUnk_51) {
        p = data_ov003_021da1f4->mUnk_10[param_1];
        m = param_0 * 0x2a;
        p->mUnk_04 = (p->mUnk_04 & ~0x3ff) | data_ov003_021da1f4->mUnk_42[*(data_ov003_021da1f4->mUnk_00 + m + 0x28)];
        p = data_ov003_021da1f4->mUnk_24[param_1];
        p->mUnk_04 =
            (p->mUnk_04 & ~0x3ff) | data_ov003_021da1f4->mUnk_48[*(u16 *) (data_ov003_021da1f4->mUnk_00 + m + 0x26)];
    }
}

void func_ov003_021c5aa4(void) {
    int a;
    int b;
    int i;
    a = 0x36 - Div32Remainder(*(u16 *) &data_ov003_021da1f0, 0x1c);
    b = data_ov003_021da1f4->mUnk_51;
    if (b > 5) {
        b = 5;
    }
    for (i = 0; i < b; i++, a += 0x1c) {
        Unk021da104_04 *p;
        p = data_ov003_021da1f4->mUnk_10[i];
        p->mUnk_00 = (p->mUnk_00 & 0xfe00ff00) | ((a - 2) & 0xff) | 0xb30000;
        p = data_ov003_021da1f4->mUnk_24[i];
        p->mUnk_00 = (p->mUnk_00 & 0xfe00ff00) | ((a + 1) & 0xff) | 0xd20000;
    }
    data_ov003_021da1f4->mUnk_56 = 1;
}

void func_ov003_021c5a0c(u32 param_0) {
    int a;
    func_ov003_021cce38();
    func_ov003_021bf698();
    if (*(u16 *) &data_ov003_021da1f0 > 4) {
        *(u16 *) &data_ov003_021da1f0 = *(u16 *) &data_ov003_021da1f0 - 4;
    } else {
        *(u16 *) &data_ov003_021da1f0 = 0;
    }
    a = Div32Remainder(*(u16 *) &data_ov003_021da1f0, 0x1c);
    if (a == 0x18) {
        func_ov003_021c5c68();
        return;
    }
    if (a > 0x18) {
        *(u16 *) &data_ov003_021da1f0 = *(u16 *) &data_ov003_021da1f0 + (0x1c - a);
        a = 0;
    }
    func_ov003_021c5aa4();
    if (a == 0) {
        func_ov003_021cce58(
            Div32(*(u16 *) &data_ov003_021da1f0 * data_ov003_021da1f4->mUnk_53, data_ov003_021da1f4->mUnk_40));
        func_ov003_021cce48();
        func_ov003_021c590c();
        data_ov003_021da1f4->mUnk_38 = 0;
        func_ov003_021d34c8(0, param_0);
    }
}

void func_ov003_021c5994(u32 param_0) {
    int a;
    func_ov003_021cce38();
    func_ov003_021bf698();
    *(u16 *) &data_ov003_021da1f0 = *(u16 *) &data_ov003_021da1f0 + 4;
    a = Div32Remainder(*(u16 *) &data_ov003_021da1f0, 0x1c);
    if (a >= 4) {
        func_ov003_021c5aa4();
        return;
    }
    *(u16 *) &data_ov003_021da1f0 = *(u16 *) &data_ov003_021da1f0 - a;
    func_ov003_021c5c68();
    func_ov003_021cce58(
        Div32(*(u16 *) &data_ov003_021da1f0 * data_ov003_021da1f4->mUnk_53, data_ov003_021da1f4->mUnk_40));
    func_ov003_021cce48();
    func_ov003_021c590c();
    data_ov003_021da1f4->mUnk_38 = 0;
    func_ov003_021d34c8(0, param_0);
}

void func_ov003_021c5944(void) {
    int v1;
    u32 v2;
    if (data_ov003_021da1f4->mUnk_56 != 0) {
        v1 = Div32Remainder((u32) ((*(u16 *) &data_ov003_021da1f0)), (u32) 0x1c);
        v2 = (v1 + -0x32) * 0x10000 & ((u32) 0x01ff0000u);
        reg_G2_BG0OFS = v2;
        reg_G2_BG2OFS = v2;
        data_ov003_021da1f4->mUnk_56 = 0;
    }
}

void func_ov003_021c590c(void) {
    u8 a;
    int b;
    a = data_ov003_021da1ec;
    if (a < 4) {
        b = 2;
    } else {
        b = 3;
    }
    func_ov003_021bf760(b, data_ov003_021d63b8[a * 4], data_ov003_021d63bc[a * 4], data_ov003_021d63ba[a * 4]);
}

void func_ov003_021c580c(int param_0) {
    BOOL a;
    u8 v;
    a = TRUE;
    v = data_ov003_021da1ec;
    switch (v) {
        case 0:
            if (param_0 == 1) {
                if (*(u16 *) &data_ov003_021da1f0 == 0) {
                    data_ov003_021da1ec = 4;
                } else {
                    func_ov003_021cdc10(0x13);
                    data_ov003_021da1f4->mUnk_38 = func_ov003_021d3544(0, func_ov003_021c5a0c, NULL, 0x78);
                    return;
                }
            } else if (data_ov003_021da1f4->mUnk_51 > 1) {
                data_ov003_021da1ec = v + 1;
            } else {
                a = FALSE;
            }
            break;
        case 1:
        case 2:
            if (param_0 == 1) {
                data_ov003_021da1ec = v - 1;
            } else if (data_ov003_021da1f4->mUnk_51 > v + 1) {
                data_ov003_021da1ec++;
            } else {
                a = FALSE;
            }
            break;
        case 3:
            if (param_0 == 1) {
                data_ov003_021da1ec = v - 1;
            } else {
                func_ov003_021c574c();
                return;
            }
            break;
        case 4:
            if (param_0 == 1) {
                a = FALSE;
            } else {
                *(u16 *) &data_ov003_021da1f0 = 0;
                data_ov003_021da1ec = 0;
                func_ov003_021c5c68();
                func_ov003_021cce58(0);
            }
            break;
    }
    if (a == FALSE) {
        if (data_ov003_021da1f4->mUnk_59 == 0) {
            func_ov003_021cdc10(9);
            data_ov003_021da1f4->mUnk_59 = 1;
        }
    } else {
        func_ov003_021cdc10(8);
        func_ov003_021c590c();
    }
}

void func_ov003_021c57b4(void) {
    if (*(u16 *) &data_ov003_021da1f0 == 0) {
        if (data_ov003_021da1f4->mUnk_59 == 0) {
            func_ov003_021cdc10(9);
            data_ov003_021da1f4->mUnk_59 = 1;
        }
    } else {
        func_ov003_021cdc10(0x13);
        data_ov003_021da1f4->mUnk_38 = func_ov003_021d3544(0, func_ov003_021c5a0c, NULL, 0x78);
    }
}

void func_ov003_021c574c(void) {
    if (*(u16 *) &data_ov003_021da1f0 == data_ov003_021da1f4->mUnk_40 || data_ov003_021da1f4->mUnk_51 <= 4) {
        if (data_ov003_021da1f4->mUnk_59 == 0) {
            func_ov003_021cdc10(9);
            data_ov003_021da1f4->mUnk_59 = 1;
        }
    } else {
        func_ov003_021cdc10(0x13);
        data_ov003_021da1f4->mUnk_38 = func_ov003_021d3544(0, func_ov003_021c5994, NULL, 0x78);
    }
}

// placeholder: the original keeps the byte at a stack offset between its load and the call; the volatile
// local reproduces that.
void func_ov003_021c5724(void) {
    volatile u8 a;
    u8 b;
    a = data_ov003_021d7228[0];
    b = a;
    func_ov003_021cc948(data_ov003_021da1f4->mUnk_08, b, b);
}
