#include "03/code_021c5ec4.h"
#include "03/code_021bf2d0.h"
#include "03/code_021bf31c.h"
#include "03/code_021bf334.h"
#include "03/code_021bf698.h"
#include "03/code_021c2120.h"
#include "03/code_021c5628.h"
#include "03/code_021c5724.h"
#include "03/code_021c5994.h"
#include "03/code_021c5c68.h"
#include "03/code_021c5ea4.h"
#include "03/code_021cce38.h"
#include "03/code_021cce60.h"
#include "03/code_021cdc10.h"
#include "03/code_021ce000.h"
#include "03/code_021d299c.h"
#include "03/code_021d2a34.h"
#include "03/code_021d2acc.h"
#include "03/code_021d3544.h"
#include "03/unk_021da000.h"
#include "code_02147cd8.h"

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
