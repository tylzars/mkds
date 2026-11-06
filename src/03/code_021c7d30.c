#include "03/code_021c7d30.h"

#include "03/code_021bf000.h"
#include "03/code_021c209c.h"
#include "03/code_021c7000.h"
#include "03/code_021c2000.h"
#include "03/code_021cd2e0.h"
#include "03/code_021ce000.h"
#include "03/code_021bf4dc.h"
#include "03/code_021cef90.h"
#include "03/code_021d1000.h"
#include "03/code_021d1f70.h"
#include "03/code_021c7844.h"
#include "03/code_021c8000.h"
#include "03/code_021c9000.h"
#include "03/code_021cc8d4.h"
#include "03/code_021cd000.h"
#include "03/unk_021d7000.h"
#include "03/unk_021da000.h"
#include "code_0214b824.h"
#include "03/code_021d1fd0.h"
#include "03/unk_021d5000.h"
#include "03/code_021bf410.h"
#include "03/code_021bf698.h"
#include "03/code_021cca74.h"
#include "code_0212df7c.h"
#include "03/code_021cdbd0.h"
#include "03/code_021d3488.h"
#include "03/unk_021d6000.h"
#include "code_021510a4.h"
#include "code_02133048.h"
#include "Main/Unknown/code_02147000.h"
#include "03/code_021d2940.h"
#include "03/code_021cea3c.h"
#include "code_02147cd8.h"
#include "03/code_021cb11c.h"
#include "03/code_021cb4d0.h"
#include "03/code_021cb8d8.h"
#include "03/code_021d1440.h"
#include "03/code_021d1c18.h"
#include "03/code_021c97c0.h"
#include "03/code_021cb000.h"
#include "Main/Unknown/code_0200e000.h"
#include "code_0214cfe4.h"
#include "03/code_021b94b8.h"
#include "03/code_021d254c.h"
#include "03/code_021d2ecc.h"
#include "03/code_021d27d8.h"
#include "03/code_021d3254.h"
#include "string.h"
#include "code_02134398.h"
#include "code_0213c9f8.h"
#include "code_0214d018.h"
#include "03/code_021d1dd0.h"
#include "03/code_021d3000.h"
#include "03/code_021bf810.h"
#include "03/code_021c6764.h"
#include "03/code_021c6f08.h"
#include "03/code_021cce78.h"

void func_ov003_021c965c(void) {
    int a;
    Unk021cd5e0_400 *b;
    int i;
    Unk021da214 *p;
    b = func_ov003_021cdb6c();
    p = func_ov003_021d283c(0x48, 4);
    data_ov003_021da214 = p;
    p->mUnk_43 = b->mUnk_f6;
    data_ov003_021da214->mUnk_42 = 0xc;
    func_ov003_021c94c8();
    func_ov003_021c9500();
    if (*(u8 *) &data_ov003_021da208 == 0) {
        func_ov003_021bf43c(0x7c, data_ov003_021d6434[func_ov003_021c20d0()], b->mUnk_f4 + 1);
    } else {
        func_ov003_021bf43c(0x97, -1, 0);
    }
    func_ov003_021bf5ec(1);
    func_ov003_021bf83c();
    func_ov003_021ccea4(2, 0x55, 0xf1, 0x41, _s32_div_f(*(u16 *) &data_ov003_021da210 * 0x37, 0x91));
    data_ov003_021da214->mUnk_14 = func_ov003_021d2288(0, 1);
    for (i = 0; i < 7; i++) {
        data_ov003_021da214->mUnk_18[i] = func_ov003_021d1c18(0, data_ov003_021d6478[0][1]);
    }
    switch (b->mUnk_00.mUnk_e7) {
        case 1:
            data_ov003_021da214->mUnk_34 = func_ov003_021d1c18(0, 0x50);
            data_ov003_021da214->mUnk_34->mUnk_04 = (data_ov003_021da214->mUnk_34->mUnk_04 & ~0xc00) | 0xc00;
            break;
        case 2:
            data_ov003_021da214->mUnk_34 = func_ov003_021d1c18(0, 0x51);
            data_ov003_021da214->mUnk_34->mUnk_04 = (data_ov003_021da214->mUnk_34->mUnk_04 & ~0xc00) | 0xc00;
            break;
    }
    data_ov003_021da214->mUnk_3c = func_ov003_021d3544(1, func_ov003_021c824c, NULL, 0x6e);
    data_ov003_021da214->mUnk_00 = func_ov003_021d3544(0, func_ov003_021c7e8c, NULL, 0x78);
    func_ov003_021c8b94();
    func_ov003_021c81b8();
    func_ov003_021c212c(func_ov003_021c948c);
}

void func_ov003_021c9500(void) {
    Unk021d7410 a;
    Unk021d73e0 b;
    Unk021d73f8 c;
    a = data_ov003_021d7410;
    b = data_ov003_021d73e0;
    c = data_ov003_021d73f8;
    *(u16 *) 0x400000c = (*(u16 *) 0x400000c & 0x43) | 0xe18;
    func_ov003_021bf620(data_ov003_021d7460, GX_LoadOBJPltt);
    func_ov003_021bf620(data_ov003_021d7474, MemCopyWordsToG2Bg3CntBits2To5Address);
    func_ov003_021bf620(data_ov003_021d748c, MemCopyWordsToG2Bg2CntBits2To5Address);
    func_ov003_021bf620(&b, GX_LoadBGPltt);
    func_ov003_021bf620(data_ov003_021d74a4, MemCopyHalfwordsToG2Bg3CntBits8To12Address);
    data_ov003_021da214->mUnk_08 = func_ov003_021d14b8(func_ov003_021bf650((u8 *) &a), NULL, 4);
    func_ov003_021cca30(data_ov003_021da214->mUnk_08);
    func_ov003_021cc9fc();
    data_ov003_021da214->mUnk_0c[0] = func_ov003_021d14b8(func_ov003_021bf650((u8 *) &b), NULL, 4);
    data_ov003_021da214->mUnk_0c[1] = func_ov003_021d14b8(func_ov003_021bf650((u8 *) &c), NULL, 4);
    *(u16 *) 0x4001008 = (*(u16 *) 0x4001008 & ~0x3) | 0x3;
    *(u16 *) 0x400100a = (*(u16 *) 0x400100a & ~0x3) | 0x3;
    *(u16 *) 0x4000008 = (*(u16 *) 0x4000008 & ~0x3) | 0x3;
    *(u16 *) 0x400000a = (*(u16 *) 0x400000a & ~0x3) | 0x2;
    *(u16 *) 0x400000c = (*(u16 *) 0x400000c & ~0x3) | 0x3;
    *(u16 *) 0x400000e = (*(u16 *) 0x400000e & ~0x3) | 0x2;
}

void func_ov003_021c94c8(void) {
    int v1[1];
    func_ov003_021cdb6c();
    func_ov003_021c20dc(NULL, v1);
    if (v1[0] == 0) {
        *(u16 *) &data_ov003_021da210 = 0;
        *(u8 *) &data_ov003_021da204 = 0;
        *(u8 *) &data_ov003_021da20c = 0;
    }
    return;
}

void func_ov003_021c948c(void) {
    func_ov003_021d1ee0(2, 1, 1, (u16) (8));
    func_ov003_021d1ee0(2, 0, 0x1d, (u16) (8));
    func_ov003_021d2784(1, 1);
    func_ov003_021d2784(0, 0x1d);
    func_ov003_021c212c(func_ov003_021c9464);
    return;
}

void func_ov003_021c9464(void) {
    if (func_ov003_021d1f70(1) == 0 && func_ov003_021d1f70(0) == 0) {
        func_ov003_021c212c(func_ov003_021c9450);
    }
}

void func_ov003_021c9450(void) {
    func_ov003_021c9268();
    func_ov003_021c8ea0();
    return;
}

void func_ov003_021c9268(void) {
    Unk021da214 *s;
    s = data_ov003_021da214;
    if (s->mUnk_38 != 0) {
        return;
    }
    if (s->mUnk_45 != 0) {
        return;
    }
    if (func_ov003_021c91fc() != 0) {
        return;
    }
    if (func_ov003_021d2b04(1) != 0) {
        func_ov003_021c90dc(data_ov003_021da204[0]);
        return;
    }
    if (func_ov003_021d2b04(2) != 0) {
        func_ov003_021cdc10(7);
        data_ov003_021da214->mUnk_40 = 0xd;
        func_ov003_021c212c(func_ov003_021c8e80);
        return;
    }
    if (func_ov003_021d2ae8(0x200) != 0) {
        if (*(u16 *) &data_ov003_021da210 == 0x91) {
            if (data_ov003_021da214->mUnk_47 != 0) {
                return;
            }
            func_ov003_021cdc10(9);
            data_ov003_021da214->mUnk_47 = 1;
            return;
        }
        func_ov003_021cdc10(0x13);
        data_ov003_021da214->mUnk_38 = func_ov003_021d3544(0, func_ov003_021c82b4, NULL, 0x78);
        return;
    }
    if (func_ov003_021d2acc(0x200) != 0) {
        data_ov003_021da214->mUnk_47 = 0;
        return;
    }
    if (func_ov003_021d2ae8(0x100) != 0) {
        if (*(u16 *) &data_ov003_021da210 == 0) {
            if (data_ov003_021da214->mUnk_47 != 0) {
                return;
            }
            func_ov003_021cdc10(9);
            data_ov003_021da214->mUnk_47 = 1;
            return;
        }
        func_ov003_021cdc10(0x13);
        data_ov003_021da214->mUnk_38 = func_ov003_021d3544(0, func_ov003_021c8320, NULL, 0x78);
        return;
    }
    if (func_ov003_021d2acc(0x100) != 0) {
        data_ov003_021da214->mUnk_47 = 0;
        return;
    }
    if (func_ov003_021d2ae8(0x40) != 0) {
        func_ov003_021c7eec(1);
        return;
    }
    if (func_ov003_021d2acc(0x40) != 0) {
        data_ov003_021da214->mUnk_47 = 0;
        return;
    }
    if (func_ov003_021d2ae8(0x80) != 0) {
        func_ov003_021c7eec(3);
        return;
    }
    if (func_ov003_021d2acc(0x80) != 0) {
        data_ov003_021da214->mUnk_47 = 0;
        return;
    }
    if (func_ov003_021d2ae8(0x20) != 0) {
        func_ov003_021c7eec(0);
        return;
    }
    if (func_ov003_021d2ae8(0x10) != 0) {
        func_ov003_021c7eec(2);
    }
}

u32 func_ov003_021c91fc(void) {
    int v1;
    int v2;
    func_ov003_021cdb6c();
    v1 = func_ov003_021c8400();
    if (v1 == 0xe) {
        return 0;
    }
    v2 = func_ov003_021c8904(v1);
    if (v2 == 0) {
        func_ov003_021cdc10(9);
        return 1;
    }
    func_ov003_021c8100(v1);
    switch (v1) {
        case 2:
        case 3:
        case 7:
        case 8:
            func_ov003_021c7e20();
    }
    func_ov003_021c90dc(v1);
    return 1;
}

void func_ov003_021c90dc(u32 param_1) {
    if (func_ov003_021c8904(param_1) == 0) {
        func_ov003_021cdc10(9);
        return;
    }
    switch (param_1) {
        case 2:
        case 3:
            func_ov003_021cdc10(6);
            func_ov003_021c9084(((param_1 - 2) ^ 1) != 0);
            return;
        case 7:
        case 8:
            func_ov003_021cdc10(6);
            func_ov003_021c9058(((param_1 - 7) ^ 1) != 0);
            return;
    }
    data_ov003_021da214->mUnk_40 = param_1;
    if (param_1 - 0xb <= 1) {
        func_ov003_021c7ec4();
        if (func_ov003_021c7d8c() == 0) {
            func_ov003_021cdc10(9);
            func_ov003_021cefc0(0x2f, 1, 1, -1, 0);
            func_ov003_021c212c(func_ov003_021c7d58);
            return;
        }
        if (param_1 == 0xb) {
            func_ov003_021cdc10(6);
        } else {
            func_ov003_021cdc10(0xe);
        }
    } else if (param_1 == 0xd) {
        func_ov003_021c7ec4();
        func_ov003_021cdc10(7);
    } else {
        func_ov003_021cdc10(6);
        func_ov003_021c8838(0, 1, func_ov003_021c83cc(data_ov003_021d646c[param_1]));
        func_ov003_021c85a0();
    }
    func_ov003_021cce38();
    func_ov003_021c212c(func_ov003_021c8e80);
}

void func_ov003_021c9084(u32 param_1) {
    Unk021cd5e0_400 *r;
    BOOL a;
    r = func_ov003_021cdb6c();
    if (r->mUnk_f5 != param_1) {
        if (param_1 != 0) {
            if (data_ov003_021da214->mUnk_43 != 0) {
                a = TRUE;
            } else {
                a = FALSE;
            }
        } else {
            data_ov003_021da214->mUnk_43 = r->mUnk_f6;
            a = FALSE;
        }
        func_ov003_021cdb58(param_1);
        func_ov003_021cdb44(a);
        func_ov003_021c8b94();
    }
}

void func_ov003_021c9058(u32 a) {
    Unk021cd5e0_400 *v1;
    v1 = func_ov003_021cdb6c();
    if (v1->mUnk_f6 != a) {
        data_ov003_021da214->mUnk_43 = (s8) a;
        func_ov003_021cdb44(a);
        func_ov003_021c8b94();
    }
    return;
}

void func_ov003_021c8ea0(void) {
    int a;
    Unk021da214 *s;
    s = data_ov003_021da214;
    if (s->mUnk_38 == 0) {
        if (s->mUnk_41 != 0) {
            s->mUnk_41--;
        }
        switch (func_ov003_021cce60()) {
            case 1:
                data_ov003_021da214->mUnk_45 = 1;
                break;
            case 2:
                if (data_ov003_021da214->mUnk_41 != 0) {
                    return;
                }
                func_ov003_021bf698();
                *(u16 *) &data_ov003_021da210 = _s32_div_f(func_ov003_021cce6c() * 0x91, 0x37);
                func_ov003_021c8b94();
                data_ov003_021da214->mUnk_41 = 4;
                break;
            case 3:
                data_ov003_021da214->mUnk_45 = 0;
                *(u16 *) &data_ov003_021da210 = _s32_div_f(func_ov003_021cce6c() * 0x91, 0x37);
                func_ov003_021cdc10(0x13);
                func_ov003_021c8b94();
                a = Div32Remainder(*(u16 *) &data_ov003_021da210, 0x1d);
                if (a == 0) {
                    func_ov003_021c812c();
                    return;
                }
                if (a < 0x10) {
                    data_ov003_021da214->mUnk_38 = func_ov003_021d3544(0, func_ov003_021c8320, NULL, 0x78);
                } else {
                    data_ov003_021da214->mUnk_38 = func_ov003_021d3544(0, func_ov003_021c82b4, NULL, 0x78);
                }
                break;
            case 4:
                if (*(u16 *) &data_ov003_021da210 == 0) {
                    if (data_ov003_021da214->mUnk_46 != 0) {
                        return;
                    }
                    func_ov003_021cdc10(9);
                    data_ov003_021da214->mUnk_46 = 1;
                } else {
                    func_ov003_021cdc10(0x13);
                    data_ov003_021da214->mUnk_38 = func_ov003_021d3544(0, func_ov003_021c8320, NULL, 0x78);
                }
                break;
            case 6:
                if (*(u16 *) &data_ov003_021da210 == 0x91) {
                    if (data_ov003_021da214->mUnk_46 != 0) {
                        return;
                    }
                    func_ov003_021cdc10(9);
                    data_ov003_021da214->mUnk_46 = 1;
                } else {
                    func_ov003_021cdc10(0x13);
                    data_ov003_021da214->mUnk_38 = func_ov003_021d3544(0, func_ov003_021c82b4, NULL, 0x78);
                }
                break;
            case 5:
            case 7:
                data_ov003_021da214->mUnk_46 = 0;
                break;
        }
    }
}

void func_ov003_021c8e80(void) {
    func_ov003_021cce38();
    func_ov003_021d1dd0((u16) (8));
    func_ov003_021c212c(func_ov003_021c8e48);
    return;
}

void func_ov003_021c8e48(void) {
    int v1;
    v1 = func_ov003_021d1f70(1);
    if (v1 == 0) {
        func_ov003_021d1ee0(3, 1, 1, (u16) (8));
        func_ov003_021d1ee0(3, 0, 0x1d, (u16) (8));
        func_ov003_021c212c(func_ov003_021c8c14);
    }
    return;
}

static inline void func_ov003_021c85a0_inline(Unk021da104_04 *p, u32 *x, u32 *y) {
    *x = (p->mUnk_00 & 0x1ff0000) >> 16;
    *y = p->mUnk_00 & 0xff;
}

void func_ov003_021c8c14(void) {
    int i;
    u32 v;
    Unk021cd5e0_400 *r;
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
    if (data_ov003_021da214->mUnk_34 != NULL) {
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
    func_ov003_021bf620(data_ov003_021d7448, GX_LoadOBJPltt);
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
            r = func_ov003_021cdb6c();
            r->mUnk_00.mUnk_d0 = CountSetBitsInBytes4(r->mUnk_f0);
            if (r->mUnk_f5 != 0) {
                MI_CpuFill8(r->mUnk_00.mUnk_c0, 0, 4);
                MI_CpuFill8(r->mUnk_00.mUnk_c4, 0, 4);
                MI_CpuFill8(r->mUnk_f0, 0, 4);
                r->mUnk_00.mUnk_d0 = 0;
            }
            if (r->mUnk_f6 != 0) {
                MI_CpuFill8(r->mUnk_00.mUnk_c8, 0, 8);
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
                func_ov003_021cd790((func_ov003_021cdb6c())->mUnk_f4);
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
    a = Div32(*(u16 *) &data_ov003_021da210, 0x1d);
    func_ov003_021d2060(data_ov003_021da214->mUnk_14, 0);
    for (i = 0, j = a; i < 5; i++, j++) {
        func_ov003_021c8a60(j, i);
    }
    func_ov003_021cc9c0((s32) (data_ov003_021da214->mUnk_08 + data_ov003_021d6488[a]), 0, 0x1e, 0x13);
    for (i = 0; i < 5; i++, a++) {
        func_ov003_021c8974(a, i);
    }
    func_ov003_021cc9fc();
    func_ov003_021d1fd0(data_ov003_021da214->mUnk_14);
    func_ov003_021c85a0();
}

void func_ov003_021c8a60(u32 a, int b) {
    Unk021cd5e0_400 *r;
    int x;
    u8 y[0x21];
    r = func_ov003_021cdb6c();
    switch (a) {
        case 0:
            func_ov003_021c876c(r->mUnk_00.mUnk_40, b);
            return;
        case 1:
            switch (r->mUnk_00.mUnk_e6_0) {
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
            if (r->mUnk_00.mUnk_e6_2 == 1) {
                x = _s32_div_f(x, 2);
            }
            MI_CpuFill8(y, 0, 0x21);
            memset(y, 0x2a, x);
            func_ov003_021c876c(y, b);
            return;
        case 3:
            if (r->mUnk_f5 == 0) {
                func_ov003_021c8718(r->mUnk_00.mUnk_c0, b);
            }
            break;
        case 4:
            if (r->mUnk_f5 == 0) {
                func_ov003_021c8718(r->mUnk_f0, b);
            }
            break;
        case 5:
            if (r->mUnk_f5 == 0) {
                func_ov003_021c8718(r->mUnk_00.mUnk_c4, b);
            }
            break;
        case 7:
            if (r->mUnk_f6 == 0) {
                func_ov003_021c8718(r->mUnk_00.mUnk_c8, b);
            }
            break;
        case 8:
            if (r->mUnk_f6 == 0) {
                func_ov003_021c8718(&r->mUnk_00.mUnk_c8[4], b);
            }
            break;
    }
}

void func_ov003_021c8974(u32 a, int b) {
    Unk021cd5e0_400 *r;
    int x;
    int y;
    BOOL z;
    int w;
    r = func_ov003_021cdb6c();
    switch (a) {
        case 0:
        case 1:
            x = 0;
            y = 0;
            if (func_ov003_021c8904(x) == 0) {
                y = 2;
            }
            break;
        case 2:
            z = FALSE;
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
                z = TRUE;
            }
            func_ov003_021c8838(w, z, b);
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
            z = FALSE;
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
                z = TRUE;
            }
            func_ov003_021c8838(w, z, b);
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
    func_ov003_021c8838(x, y, b);
}

u32 func_ov003_021c8904(u32 a) {
    Unk021cd5e0_400 *r;
    u32 v1;
    r = func_ov003_021cdb6c();
    v1 = 1;
    switch (a) {
        case 7:
            if (r->mUnk_f5 == 0) {
                v1 = 0;
            }
            break;
        case 0:
        case 1:
            if ((u8) (r->mUnk_00.mUnk_e7 + 0xff) <= 1) {
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

void func_ov003_021c8838(int d, int e, int f) {
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
    p = &data_ov003_021da214->mUnk_18[f];
    if ((u32) (d - 1) <= 1) {
        if (func_ov003_021c83b0(f) == 2) {
            p = &data_ov003_021da214->mUnk_18[5];
        } else {
            p = &data_ov003_021da214->mUnk_18[6];
        }
    }
    if (data_ov003_021d6478[d][e] != 0) {
        func_ov003_021d1c3c(0, data_ov003_021d6478[d][e], (u8 *) *p);
        c = (a[d] & 0x1ff) << 16;
        (*p)->mUnk_00 = c | ((*p)->mUnk_00 & 0xfe00ff00);
        (*p)->mUnk_04 = ((*p)->mUnk_04 & ~0xc00) | 0xc00;
    } else {
        (*p)->mUnk_00 = ((*p)->mUnk_00 & 0xfe00ff00) | 0x1000000;
    }
}

void func_ov003_021c876c(const u8 *g, int h) {
    u16 f[17];
    int a;
    int b;
    int c;
    int i;
    int d;
    int e;
    MI_CpuFill8(f, 0, 0x22);
    a = func_ov003_021d3254(g, 0x20);
    if (a <= 0x10) {
        b = a;
    } else {
        b = 0x10;
    }
    for (i = 0; i < b; i++) {
        c = g[i];
        if (c == 0x20) {
            f[i] = 0xe01d;
        } else {
            f[i] = c;
        }
    }
    d = h * 0x1d + 2;
    if (a <= 0x10) {
        d += 5;
    }
    func_ov003_021d2094(data_ov003_021da214->mUnk_14, 0x48, d, 2, 8, f, 1);
    if (a > 0x10) {
        MI_CpuFill8(f, 0, 0x22);
        e = a - 0x10;
        for (i = 0; i < e; i++) {
            c = g[i + 0x10];
            if (c == 0x20) {
                f[i] = 0xe01d;
            } else {
                f[i] = c;
            }
        }
        func_ov003_021d2094(data_ov003_021da214->mUnk_14, 0x48, d + 0xc, 2, 8, f, 1);
    }
}

void func_ov003_021c8718(const u8 *b, int c) {
    u16 a[16];
    swprintf(a, 0x10, data_ov003_021d7428, b[0], b[1], b[2], b[3]);
    func_ov003_021d2094(data_ov003_021da214->mUnk_14, 0x5f, c * 0x1d + 8, 2, 7, a, 1);
}

void func_ov003_021c85a0(void) {
    int a;
    int b;
    Unk021da104_04 *p;
    int c;
    int i;
    u32 x;
    u32 y;
    a = Div32(*(u16 *) &data_ov003_021da210, 0x1d);
    b = 0x34 - Div32Remainder(*(u16 *) &data_ov003_021da210, 0x1d);
    if (data_ov003_021da214->mUnk_34 != NULL) {
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

u32 func_ov003_021c8400(void) {
    Unk021d299c a;
    Unk021d299c *b;
    s32 c;
    s32 d;
    s32 e;
    Unk021d299c *f;
    if (func_ov003_021d2a34(&data_ov003_021d67e8) == 0) {
        return 0xe;
    }
    c = Div32(*(u16 *) data_ov003_021da210, 0x1d);
    b = &a;
    a = data_ov003_021d643c;
    for (d = 0; d < 4; d++, c++, a.mUnk_02 += 0x1d) {
        if (c != 2 && c != 6) {
            if (func_ov003_021d2970(b) != 0) {
                return data_ov003_021d6454[c];
            }
        }
    }
    e = Div32(*(u16 *) data_ov003_021da210, 0x1d);
    for (d = 0; d < 4; d++, e++) {
        if (e == 2) {
            a = data_ov003_021d644c;
            d = d * 0x1d;
            a.mUnk_02 = a.mUnk_02 + d;
            if (func_ov003_021d2970(&a) != 0) {
                return 2;
            }
            a = data_ov003_021d6444;
            a.mUnk_02 = a.mUnk_02 + d;
            if (func_ov003_021d2970(&a) != 0) {
                return 3;
            }
            break;
        }
    }
    e = Div32(*(u16 *) data_ov003_021da210, 0x1d);
    for (d = 0; d < 4; d++, e++) {
        if (e == 6) {
            a = data_ov003_021d644c;
            d = d * 0x1d;
            a.mUnk_02 = a.mUnk_02 + d;
            if (func_ov003_021d2970(&a) != 0) {
                return 7;
            }
            a = data_ov003_021d6444;
            a.mUnk_02 = a.mUnk_02 + d;
            if (func_ov003_021d2970(&a) != 0) {
                return 8;
            }
            break;
        }
    }
    d = 0;
    f = data_ov003_021d649c;
    for (; d < 3; d++) {
        if (func_ov003_021d2a34(f) != 0) {
            return d + 0xb;
        }
        f++;
    }
    return 0xe;
}

int func_ov003_021c83cc(int a) {
    int v1;
    int v2;
    v1 = Div32((u32) ((*(u16 *) &data_ov003_021da210)), 0x1d);
    v2 = 0;
    do {
        if (v1 == a) {
            return v2;
        }
        v2 = v2 + 1;
        v1 = v1 + 1;
    } while (v2 < 4);
    return -1;
}

int func_ov003_021c83b0(int a) {
    int v1;
    v1 = Div32((u32) ((*(u16 *) &data_ov003_021da210)), 0x1d);
    return v1 + a;
}

void func_ov003_021c8320(u32 b) {
    s32 a;
    func_ov003_021cce38();
    func_ov003_021bf698();
    if (*(u16 *) data_ov003_021da210 > 6) {
        *(u16 *) data_ov003_021da210 = *(u16 *) data_ov003_021da210 - 6;
    } else {
        *(u16 *) data_ov003_021da210 = 0;
    }
    a = Div32Remainder(*(u16 *) data_ov003_021da210, 0x1d);
    if (a == 0x17) {
        func_ov003_021c8b94();
        return;
    }
    if (a > 0x17) {
        *(u16 *) data_ov003_021da210 = *(u16 *) data_ov003_021da210 + (0x1d - a);
        a = 0;
    }
    func_ov003_021c85a0();
    if (a == 0) {
        func_ov003_021cce58((s32) _s32_div_f(*(u16 *) data_ov003_021da210 * 0x37, 0x91));
        func_ov003_021cce48();
        func_ov003_021c812c();
        data_ov003_021da214->mUnk_38 = 0;
        func_ov003_021d34c8(0, b);
    }
}

void func_ov003_021c82b4(u32 b) {
    s32 a;
    func_ov003_021cce38();
    func_ov003_021bf698();
    *(u16 *) data_ov003_021da210 = *(u16 *) data_ov003_021da210 + 6;
    a = Div32Remainder(*(u16 *) data_ov003_021da210, 0x1d);
    if (a >= 6) {
        func_ov003_021c85a0();
        return;
    }
    *(u16 *) data_ov003_021da210 = *(u16 *) data_ov003_021da210 - a;
    func_ov003_021c8b94();
    func_ov003_021cce58((s32) _s32_div_f(*(u16 *) data_ov003_021da210 * 0x37, 0x91));
    func_ov003_021cce48();
    func_ov003_021c812c();
    data_ov003_021da214->mUnk_38 = 0;
    func_ov003_021d34c8(0, b);
}

void func_ov003_021c824c(void) {
    u32 a;
    s32 b;
    if (data_ov003_021da214->mUnk_44 != 0) {
        a = Div32(*(u16 *) data_ov003_021da210, 0x1d);
        b = Div32Remainder(*(u16 *) data_ov003_021da210, 0x1d) - 0x33;
        *(vu32 *) 0x4000010 = (b << 16) & 0x1ff0000;
        *(vu32 *) 0x4000018 = ((b + data_ov003_021d6460[a]) << 16) & 0x1ff0000;
        data_ov003_021da214->mUnk_44 = 0;
    }
}

void func_ov003_021c81b8(void) {
    Unk021d73d0 a;
    Unk021d299c b;
    s32 d;
    a = data_ov003_021d73d0;
    d = a.mUnk_00[data_ov003_021da204[0]];
    if (d >= 3) {
        func_ov003_021bf760(3, data_ov003_021d64b4[d].mUnk_00, data_ov003_021d64b4[d].mUnk_04,
                            data_ov003_021d64b4[d].mUnk_02);
        return;
    }
    b = data_ov003_021d64b4[d];
    b.mUnk_02 = b.mUnk_02 + data_ov003_021da20c[0] * 0x1d;
    func_ov003_021bf760(1, b.mUnk_00, b.mUnk_04, b.mUnk_02);
}

void func_ov003_021c812c(void) {
    Unk021cd5e0_400 *a;
    s32 b;
    if ((u8) (data_ov003_021da204[0] + 0xf5) <= 2) {
        func_ov003_021c81b8();
        return;
    }
    a = func_ov003_021cdb6c();
    b = data_ov003_021da20c[0] + Div32(*(u16 *) data_ov003_021da210, 0x1d);
    switch (b) {
        case 2:
            if (a->mUnk_f5 != 0) {
                data_ov003_021da204[0] = 2;
            } else {
                data_ov003_021da204[0] = 3;
            }
            break;
        case 6:
            if (a->mUnk_f6 != 0) {
                data_ov003_021da204[0] = 7;
            } else {
                data_ov003_021da204[0] = 8;
            }
            break;
        default:
            data_ov003_021da204[0] = data_ov003_021d6454[b];
            break;
    }
    func_ov003_021c81b8();
}

void func_ov003_021c8100(u32 a) {
    data_ov003_021da204[0] = a;
    data_ov003_021da20c[0] = func_ov003_021c83cc(data_ov003_021d646c[a]);
    func_ov003_021c81b8();
}

void func_ov003_021c7eec(s32 d) {
    Unk021cd5e0_400 *a;
    s32 b;
    s32 c;
    a = func_ov003_021cdb6c();
    b = 0;
    c = data_ov003_021da204[0];
    if (c == 8 && a->mUnk_f5 == 0) {
        if (d == 0) {
            return;
        }
        if (d == 2) {
            return;
        }
    }
    switch (c) {
        case 0:
            if (d == 1) {
                data_ov003_021da204[0] = 0xb;
            } else if (d == 3) {
                data_ov003_021da20c[0] = data_ov003_021da20c[0] + 1;
            } else {
                b = 2;
            }
            break;
        case 0xa:
            if (d == 1) {
                data_ov003_021da20c[0] = data_ov003_021da20c[0] - 1;
            } else if (d == 3) {
                data_ov003_021da204[0] = data_ov003_021da214->mUnk_42;
            } else {
                b = 2;
            }
            break;
        case 0xb:
            if (d == 1) {
                if (data_ov003_021da214->mUnk_47 != 0) {
                    return;
                }
                func_ov003_021cdc10(9);
                data_ov003_021da214->mUnk_47 = 1;
                return;
            } else if (d == 3) {
                data_ov003_021da204[0] = 0;
                data_ov003_021da20c[0] = 0;
                *(u16 *) data_ov003_021da210 = 0;
                func_ov003_021c8b94();
                func_ov003_021cce58(0);
            } else {
                b = 2;
            }
            break;
        case 0xc:
        case 0xd:
            data_ov003_021da214->mUnk_42 = c;
            if (d == 1) {
                data_ov003_021da204[0] = 0xa;
                data_ov003_021da20c[0] = 3;
                *(u16 *) data_ov003_021da210 = 0x91;
                func_ov003_021c8b94();
                func_ov003_021cce58(0x37);
            } else if (d == 3) {
                if (data_ov003_021da214->mUnk_47 != 0) {
                    return;
                }
                func_ov003_021cdc10(9);
                data_ov003_021da214->mUnk_47 = 1;
                return;
            } else if (c == 0xc) {
                data_ov003_021da204[0] = 0xd;
            } else {
                data_ov003_021da204[0] = 0xc;
            }
            break;
        default:
            if (d == 1) {
                if (data_ov003_021da20c[0] != 0) {
                    data_ov003_021da20c[0] = data_ov003_021da20c[0] - 1;
                    break;
                }
                func_ov003_021cdc10(0x13);
                data_ov003_021da214->mUnk_38 = func_ov003_021d3544(0, func_ov003_021c8320, NULL, 0x78);
                return;
            } else if (d == 3) {
                if (data_ov003_021da20c[0] < 3) {
                    data_ov003_021da20c[0] = data_ov003_021da20c[0] + 1;
                    break;
                }
                func_ov003_021cdc10(0x13);
                data_ov003_021da214->mUnk_38 = func_ov003_021d3544(0, func_ov003_021c82b4, NULL, 0x78);
                return;
            } else {
                b = 2;
                if (c == 2) {
                    data_ov003_021da204[0] = 3;
                } else if (c == 3) {
                    data_ov003_021da204[0] = b;
                } else if (c == 7) {
                    data_ov003_021da204[0] = 8;
                } else if (c == 8) {
                    data_ov003_021da204[0] = 7;
                } else {
                    break;
                }
                func_ov003_021cdc10(8);
                func_ov003_021c81b8();
            }
            break;
    }
    if (b != 2) {
        func_ov003_021cdc10(8);
        if (b == 0) {
            func_ov003_021c812c();
        }
    }
}

void func_ov003_021c7ec4(void) {
    u8 a;
    a = data_ov003_021d6430[data_ov003_021da204[0] - 0xb];
    func_ov003_021cc948(data_ov003_021da214->mUnk_0c[1], a, a);
}

void func_ov003_021c7e8c(void) {
    s32 a;
    for (a = 0; a < 4; a++) {
        if (data_ov003_021da214->mUnk_04[a] != 0) {
            data_ov003_021da214->mUnk_04[a] = data_ov003_021da214->mUnk_04[a] - 1;
            if (data_ov003_021da214->mUnk_04[a] == 0) {
                func_ov003_021c8b94();
            }
        }
    }
}

void func_ov003_021c7e20(void) {
    u8 a[4];
    s32 c;
    u8 *b;
    u8 d;
    b = a;
    a[0] = data_ov003_021d73cc[0];
    a[1] = data_ov003_021d73cc[1];
    a[2] = data_ov003_021d73cc[2];
    a[3] = data_ov003_021d73cc[3];
    c = 0;
    d = data_ov003_021da204[0];
    for (; c < 4; c++) {
        if (d == *b) {
            data_ov003_021da214->mUnk_04[c] = 0x14;
            if ((c & 1) != 0) {
                data_ov003_021da214->mUnk_04[c - 1] = 0;
            } else {
                data_ov003_021da214->mUnk_04[c + 1] = 0;
            }
            return;
        }
        b++;
    }
}

u32 func_ov003_021c7d8c(void) {
    Unk021cd5e0_400 *a;
    a = func_ov003_021cdb6c();
    if (a->mUnk_00.mUnk_40[0] == 0) {
        return 0;
    }
    if (a->mUnk_f6 == 0) {
        if (func_02151620(a->mUnk_00.mUnk_c8) == 0 && func_02151620(&a->mUnk_00.mUnk_c8[4]) == 0) {
            return 0;
        }
    }
    if (a->mUnk_f5 == 0) {
        if (func_02151620(a->mUnk_00.mUnk_c0) == 0) {
            return 0;
        }
        if (func_02151620(a->mUnk_00.mUnk_c4) == 0) {
            return 0;
        }
        if (func_02151640(a->mUnk_00.mUnk_c0, a->mUnk_f0) == 0) {
            return 0;
        }
    }
    return 1;
}

void func_ov003_021c7d58(void) {
    int v1;
    v1 = func_ov003_021cef80();
    if (v1 == 0) {
        func_ov003_021cdc10((u32) 6);
        func_ov003_021cef90();
        func_ov003_021cc900((u32) data_ov003_021da214->mUnk_0c[0]);
        func_ov003_021c212c(func_ov003_021c7d3c);
    }
}

void func_ov003_021c7d3c(void) {
    int v1;
    v1 = func_ov003_021cef6c();
    if (v1 == 0) {
        func_ov003_021c212c(func_ov003_021c9450);
    }
}

void func_ov003_021c7d30(u8 a) {
    *(u8 *) &data_ov003_021da208 = a;
}
