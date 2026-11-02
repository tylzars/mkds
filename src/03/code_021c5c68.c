#include "03/code_021c5c68.h"
#include "Main/Unknown/code_02147000.h"
#include "03/unk_021d6000.h"
#include "03/code_021c6000.h"
#include "03/code_021c2000.h"
#include "03/code_021bf4dc.h"

#include "code_02147cd8.h"
#include "03/unk_021da000.h"
#include "03/code_021bf098.h"
#include "03/code_021bf410.h"
#include "03/code_021bf698.h"
#include "03/code_021c209c.h"
#include "03/code_021cb000.h"
#include "03/code_021cc8d4.h"
#include "03/code_021cd000.h"
#include "03/code_021cd0d0.h"
#include "03/code_021b94b8.h"
#include "03/code_021cd4ac.h"
#include "03/code_021d1000.h"
#include "03/code_021d1f70.h"
#include "03/code_021d254c.h"
#include "03/code_021d2ecc.h"
#include "03/code_021d1fd0.h"
#include "03/code_021d27d8.h"
#include "03/code_021d3488.h"
#include "03/code_021c5724.h"
#include "03/code_021bf000.h"
#include "03/code_021c5000.h"
#include "03/code_021ccd18.h"
#include "03/code_021ce000.h"
#include "03/unk_021d7000.h"
#include "code_0214b824.h"
#include "03/code_021c5548.h"
#include "03/code_021c5994.h"
#include "code_0212df7c.h"
#include "03/code_021cdbd0.h"
#include "03/code_021d2940.h"

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
                    func_02147d30(data_ov003_021da1f4->mUnk_40 * func_ov003_021cce6c(), data_ov003_021da1f4->mUnk_53);
                func_ov003_021c5c68();
                data_ov003_021da1f4->mUnk_55 = 4;
            }
            break;
        case 3:
            data_ov003_021da1f4->mUnk_57 = 0;
            func_ov003_021bf2e0();
            *(u16 *) &data_ov003_021da1f0 =
                func_02147d30(data_ov003_021da1f4->mUnk_40 * func_ov003_021cce6c(), data_ov003_021da1f4->mUnk_53);
            func_ov003_021cdc10(0x13);
            func_ov003_021c5c68();
            a = func_02147cd8(*(u16 *) &data_ov003_021da1f0, 0x1c);
            if (a == 0) {
                func_ov003_021c590c();
            } else if (a < 0xe) {
                data_ov003_021da1f4->mUnk_38 = func_ov003_021d3544(0, func_ov003_021c5a0c, 0, 0x78);
            } else {
                data_ov003_021da1f4->mUnk_38 = func_ov003_021d3544(0, func_ov003_021c5994, 0, 0x78);
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
                data_ov003_021da1f4->mUnk_38 = func_ov003_021d3544(0, func_ov003_021c5a0c, 0, 0x78);
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
                data_ov003_021da1f4->mUnk_38 = func_ov003_021d3544(0, func_ov003_021c5994, 0, 0x78);
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
                    b = data_ov003_021da1ec + func_02147d30(*(u16 *) &data_ov003_021da1f0, 0x1c);
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
        if (data_ov003_021da1f4->mUnk_10[i] != 0) {
            func_ov003_021d2f00((u32 *) data_ov003_021da1f4->mUnk_10[i]);
        }
        if (data_ov003_021da1f4->mUnk_24[i] != 0) {
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
        func_ov003_021cd790(*(u8 *) (func_ov003_021cdb6c() + 0xf4));
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
    v1 = func_02147d30((u32) ((*(u16 *) &data_ov003_021da1f0)), 0x1c);
    v4 = data_ov003_021da1f4->mUnk_51;
    func_ov003_021d2060(data_ov003_021da1f4->mUnk_0c, 0);
    if (5 < v4) {
        v4 = 5;
    }
    v2 = 0;
    v3 = v1;
    if (v4 > 0) {
        do {
            func_ov003_021c5b90((int) (v3), (int) (v2));
            v2 = v2 + 1;
            v3 = v3 + 1;
        } while (v2 < v4);
    }
    v3 = 0;
    if (v4 > 0) {
        do {
            func_ov003_021c5b34((int) (v1), (int) (v3));
            v3 = v3 + 1;
            v1 = v1 + 1;
        } while (v3 < v4);
    }
    func_ov003_021d1fd0(data_ov003_021da1f4->mUnk_0c);
    func_ov003_021c5aa4();
    return;
}
