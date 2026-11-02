#include "03/code_021c85a0.h"
#include "03/code_021bf410.h"
#include "03/code_021d1440.h"
#include "03/unk_021d5000.h"
#include "03/code_021bf4dc.h"
#include "03/code_021bf698.h"
#include "03/code_021c209c.h"
#include "03/unk_021da000.h"
#include "Main/Unknown/code_02147000.h"
#include "03/code_021c7d30.h"
#include "03/code_021c97c0.h"
#include "03/code_021cb000.h"
#include "Main/Unknown/code_0200e000.h"
#include "code_0214b824.h"
#include "code_0214cfe4.h"
#include "03/code_021cc8d4.h"
#include "03/code_021cd000.h"
#include "03/code_021b94b8.h"
#include "03/code_021cd4ac.h"
#include "03/code_021d1000.h"
#include "03/code_021d1f70.h"
#include "03/code_021d1fd0.h"
#include "03/code_021d254c.h"
#include "03/code_021d2ecc.h"
#include "03/code_021d27d8.h"
#include "03/code_021d3254.h"
#include "03/code_021d3488.h"
#include "code_02133048.h"
#include "code_02134d30.h"
#include "code_0213c9f8.h"
#include "code_02147cd8.h"
#include "code_0214d018.h"
#include "code_021510a4.h"

static inline void func_ov003_021c85a0_inline(Unk021da104_04 *p, u32 *x, u32 *y) {
    *x = (p->mUnk_00 & 0x1ff0000) >> 16;
    *y = p->mUnk_00 & 0xff;
}

void func_ov003_021c8c14(void) {
    int i;
    u32 v;
    Unk021c8a60 *r;
    if (func_ov003_021d1f70(1) != 0) {
        return;
    }
    if (func_ov003_021d1f70(0) != 0) {
        return;
    }
    func_ov003_021d34c0(0, data_ov003_021da214->mUnk_00);
    func_ov003_021d34c0(1, data_ov003_021da214->mUnk_3c);
    for (i = 0; i < 7; i++) {
        func_ov003_021d2f00((u32 *) data_ov003_021da214->mUnk_18[i]);
    }
    if (data_ov003_021da214->mUnk_34 != 0) {
        func_ov003_021d2f00((u32 *) data_ov003_021da214->mUnk_34);
    }
    func_ov003_021cce78();
    func_ov003_021d2168(0);
    func_ov003_021bf698();
    if (data_ov003_021da214->mUnk_40 != 0xc) {
        func_ov003_021bf410();
    }
    func_ov003_021cca10();
    func_ov003_021d1490(data_ov003_021da214->mUnk_08);
    for (i = 0; i < 2; i++) {
        func_ov003_021d1490(data_ov003_021da214->mUnk_0c[i]);
    }
    func_ov003_021bf620(data_ov003_021d7448, func_0214c090);
    func_ov003_021d272c(1, 1);
    func_ov003_021d272c(0, 0x1d);
    *(u32 *) 0x4000010 = 0;
    *(u32 *) 0x4000018 = 0;
    *(u16 *) 0x400000c = (*(u16 *) 0x400000c & 0x43) | 0xe10;
    v = data_ov003_021da214->mUnk_40;
    switch (v) {
        case 0:
        case 1:
            func_ov003_021c20f8(v, 0);
            func_ov003_021c2120(2, 0);
            func_ov003_021c212c(func_ov003_021c6e38);
            break;
        case 4:
        case 5:
        case 6:
        case 9:
        case 10:
            i = v - 4;
            if (v >= 9) {
                i -= 2;
            }
            func_ov003_021c2120(2, 0);
            func_ov003_021c20f8(i, 0);
            func_ov003_021c212c(func_ov003_021c7748);
            break;
        case 11:
            r = (Unk021c8a60 *) func_ov003_021cdb6c();
            r->mUnk_d0 = func_021516d8(r->mUnk_f0);
            if (r->mUnk_f5 != 0) {
                func_0214d168(r->mUnk_c0, 0, 4);
                func_0214d168(r->mUnk_c4, 0, 4);
                func_0214d168(r->mUnk_f0, 0, 4);
                r->mUnk_d0 = 0;
            }
            if (r->mUnk_f6 != 0) {
                func_0214d168(r->mUnk_c8, 0, 8);
            }
            func_ov003_021c2120(2, 0);
            func_ov003_021c20f8(0, 0);
            func_ov003_021c212c(func_ov003_021cbb98);
            break;
        case 12:
            func_ov003_021c2120(0, 0);
            func_ov003_021c212c(func_ov003_021c9944);
            break;
        case 13:
            if (*(u8 *) &data_ov003_021da208 == 0) {
                func_ov003_021c2120(2, 1);
                func_ov003_021c212c(func_ov003_021cb294);
            } else {
                func_ov003_021cd790(((Unk021c8a60 *) func_ov003_021cdb6c())->mUnk_f4);
                func_ov003_021c2120(0, 1);
                func_ov003_021c212c(func_ov003_021cb7fc);
            }
            break;
    }
    func_ov003_021d2808(&data_ov003_021da214);
}

void func_ov003_021c8b94(void) {
    int a;
    int i;
    int j;
    a = func_02147d30(*(u16 *) &data_ov003_021da210, 0x1d);
    func_ov003_021d2060(data_ov003_021da214->mUnk_14, 0);
    for (i = 0, j = a; i < 5; i++, j++) {
        func_ov003_021c8a60(j, i);
    }
    func_ov003_021cc9c0((int) (data_ov003_021da214->mUnk_08 + data_ov003_021d6488[a]), 0, 0x1e, 0x13);
    for (i = 0; i < 5; i++, a++) {
        func_ov003_021c8974(a, i);
    }
    func_ov003_021cc9fc();
    func_ov003_021d1fd0(data_ov003_021da214->mUnk_14);
    func_ov003_021c85a0();
}

void func_ov003_021c8a60(u32 param_1, int param_2) {
    Unk021c8a60 *r;
    int x;
    u8 y[0x21];
    r = (Unk021c8a60 *) func_ov003_021cdb6c();
    switch (param_1) {
        case 0:
            func_ov003_021c876c(r->mUnk_40, param_2);
            return;
        case 1:
            switch (r->mUnk_e6_0) {
                case 0:
                    return;
                case 1:
                    x = 10;
                    break;
                case 2:
                    x = 0x1a;
                    break;
                case 3:
                    x = 0x20;
                    break;
            }
            if (r->mUnk_e6_2 == 1) {
                x = _s32_div_f(x, 2);
            }
            func_0214d168(y, 0, 0x21);
            func_02134de0(y, 0x2a, x);
            func_ov003_021c876c(y, param_2);
            return;
        case 3:
            if (r->mUnk_f5 == 0) {
                func_ov003_021c8718(r->mUnk_c0, param_2);
            }
            break;
        case 4:
            if (r->mUnk_f5 == 0) {
                func_ov003_021c8718(r->mUnk_f0, param_2);
            }
            break;
        case 5:
            if (r->mUnk_f5 == 0) {
                func_ov003_021c8718(r->mUnk_c4, param_2);
            }
            break;
        case 7:
            if (r->mUnk_f6 == 0) {
                func_ov003_021c8718(r->mUnk_c8, param_2);
            }
            break;
        case 8:
            if (r->mUnk_f6 == 0) {
                func_ov003_021c8718(&r->mUnk_c8[4], param_2);
            }
            break;
    }
}

void func_ov003_021c8974(u32 param_1, int param_2) {
    Unk021c8a60 *r;
    int x;
    int y;
    int z;
    int w;
    r = (Unk021c8a60 *) func_ov003_021cdb6c();
    switch (param_1) {
        case 0:
        case 1:
            x = 0;
            y = 0;
            if (func_ov003_021c8904(x) == 0) {
                y = 2;
            }
            break;
        case 2:
            z = 0;
            y = 0;
            if (r->mUnk_f5 != 0) {
                x = 1;
                w = 4;
            } else {
                x = 2;
                w = 3;
            }
            if (data_ov003_021da214->mUnk_04[0] != 0) {
                y = 1;
            }
            if (data_ov003_021da214->mUnk_04[1] != 0) {
                z = 1;
            }
            func_ov003_021c8838(w, z, param_2);
            break;
        case 3:
        case 4:
        case 5:
            x = 0;
            if (r->mUnk_f5 != 0) {
                y = 2;
            } else {
                y = x;
            }
            break;
        case 6:
            z = 0;
            y = 0;
            if (r->mUnk_f6 != 0) {
                x = 1;
                w = 4;
            } else {
                if (r->mUnk_f5 == 0) {
                    y = 2;
                }
                x = 2;
                w = 3;
            }
            if (data_ov003_021da214->mUnk_04[2] != 0) {
                y = 1;
            }
            if (data_ov003_021da214->mUnk_04[3] != 0) {
                z = 1;
            }
            func_ov003_021c8838(w, z, param_2);
            break;
        case 7:
        case 8:
            x = 0;
            if (r->mUnk_f6 != 0) {
                y = 2;
            } else {
                y = x;
            }
            break;
        default:
            x = 0;
            y = 2;
            break;
    }
    func_ov003_021c8838(x, y, param_2);
}

u32 func_ov003_021c8904(u32 param_1) {
    Unk021c8a60 *r;
    u32 v1;
    r = (Unk021c8a60 *) func_ov003_021cdb6c();
    v1 = 1;
    switch (param_1) {
        case 7:
            if (r->mUnk_f5 == 0) {
                v1 = 0;
            }
            break;
        case 0:
        case 1:
            if ((u8) (r->mUnk_e7 + 0xff) <= 1) {
                v1 = 0;
            }
            break;
        case 4:
        case 5:
        case 6:
            if (r->mUnk_f5 != 0) {
                v1 = 0;
            }
            break;
        case 9:
        case 10:
            if (r->mUnk_f6 != 0) {
                v1 = 0;
            }
            break;
    }
    return v1;
}

void func_ov003_021c8838(int param_1, int param_2, int param_3) {
    u16 a[5];
    u16 b;
    u32 c;
    Unk021da104_04 **p;
    a[0] = data_ov003_021d643c.mUnk_00;
    b = data_ov003_021d644c.mUnk_00;
    a[1] = b;
    a[2] = b;
    b = data_ov003_021d6444.mUnk_00;
    a[3] = b;
    a[4] = b;
    p = &data_ov003_021da214->mUnk_18[param_3];
    if ((u32) (param_1 - 1) <= 1) {
        if (func_ov003_021c83b0(param_3) == 2) {
            p = &data_ov003_021da214->mUnk_18[5];
        } else {
            p = &data_ov003_021da214->mUnk_18[6];
        }
    }
    if (data_ov003_021d6478[param_1][param_2] != 0) {
        func_ov003_021d1c3c(0, data_ov003_021d6478[param_1][param_2], (u8 *) *p);
        c = (a[param_1] & 0x1ff) << 16;
        (*p)->mUnk_00 = c | ((*p)->mUnk_00 & 0xfe00ff00);
        (*p)->mUnk_04 = ((*p)->mUnk_04 & ~0xc00) | 0xc00;
    } else {
        (*p)->mUnk_00 = ((*p)->mUnk_00 & 0xfe00ff00) | 0x1000000;
    }
}

void func_ov003_021c876c(const u8 *param_1, int param_2) {
    u16 f[17];
    int a;
    int b;
    int c;
    int i;
    int d;
    int e;
    func_0214d168(f, 0, 0x22);
    a = func_ov003_021d3254(param_1, 0x20);
    if (a <= 0x10) {
        b = a;
    } else {
        b = 0x10;
    }
    for (i = 0; i < b; i++) {
        c = param_1[i];
        if (c == 0x20) {
            f[i] = 0xe01d;
        } else {
            f[i] = c;
        }
    }
    d = param_2 * 0x1d + 2;
    if (a <= 0x10) {
        d += 5;
    }
    func_ov003_021d2094(data_ov003_021da214->mUnk_14, 0x48, d, 2, 8, f, 1);
    if (a > 0x10) {
        func_0214d168(f, 0, 0x22);
        e = a - 0x10;
        for (i = 0; i < e; i++) {
            c = param_1[i + 0x10];
            if (c == 0x20) {
                f[i] = 0xe01d;
            } else {
                f[i] = c;
            }
        }
        func_ov003_021d2094(data_ov003_021da214->mUnk_14, 0x48, d + 0xc, 2, 8, f, 1);
    }
}

void func_ov003_021c8718(const u8 *param_1, int param_2) {
    u16 a[16];
    func_0213ca64(a, 0x10, data_ov003_021d7428, param_1[0], param_1[1], param_1[2], param_1[3]);
    func_ov003_021d2094(data_ov003_021da214->mUnk_14, 0x5f, param_2 * 0x1d + 8, 2, 7, a, 1);
}

void func_ov003_021c85a0(void) {
    int a;
    int b;
    Unk021da104_04 *p;
    int c;
    int i;
    u32 x;
    u32 y;
    a = func_02147d30(*(u16 *) &data_ov003_021da210, 0x1d);
    b = 0x34 - func_02147cd8(*(u16 *) &data_ov003_021da210, 0x1d);
    if (data_ov003_021da214->mUnk_34 != 0) {
        if (a == 0) {
            x = 0x26;
        } else {
            x = 0x100;
        }
        data_ov003_021da214->mUnk_34->mUnk_00 =
            ((x & 0x1ff) << 16) | ((data_ov003_021da214->mUnk_34->mUnk_00 & 0xfe00ff00) | (b & 0xff));
    }
    for (i = 0, c = b; i < 5; i++, c += 0x1d) {
        func_ov003_021c85a0_inline(data_ov003_021da214->mUnk_18[i], (u32 *) &x, (u32 *) &y);
        p = data_ov003_021da214->mUnk_18[i];
        p->mUnk_00 = ((x & 0x1ff) << 16) | ((p->mUnk_00 & 0xfe00ff00) | (c & 0xff));
    }
    if (a <= 2) {
        func_ov003_021c85a0_inline(data_ov003_021da214->mUnk_18[5], (u32 *) &x, (u32 *) &y);
        data_ov003_021da214->mUnk_18[5]->mUnk_00 =
            ((x & 0x1ff) << 16) |
            ((data_ov003_021da214->mUnk_18[5]->mUnk_00 & 0xfe00ff00) | ((b + (2 - a) * 0x1d) & 0xff));
    } else {
        data_ov003_021da214->mUnk_18[5]->mUnk_00 = (data_ov003_021da214->mUnk_18[5]->mUnk_00 & 0xfe00ff00) | 0x1000000;
    }
    if (a >= 2 && a <= 6) {
        func_ov003_021c85a0_inline(data_ov003_021da214->mUnk_18[6], (u32 *) &x, (u32 *) &y);
        data_ov003_021da214->mUnk_18[6]->mUnk_00 =
            ((x & 0x1ff) << 16) |
            ((data_ov003_021da214->mUnk_18[6]->mUnk_00 & 0xfe00ff00) | ((b + (6 - a) * 0x1d) & 0xff));
    } else {
        data_ov003_021da214->mUnk_18[6]->mUnk_00 = (data_ov003_021da214->mUnk_18[6]->mUnk_00 & 0xfe00ff00) | 0x1000000;
    }
    data_ov003_021da214->mUnk_44 = 1;
}
