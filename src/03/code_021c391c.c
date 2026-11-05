#include "03/code_021c391c.h"
#include "03/types_021d299c.h"

#include "03/code_021bf000.h"
#include "03/code_021c3000.h"
#include "03/code_021c2000.h"
#include "03/code_021ce000.h"
#include "03/code_021bf4dc.h"
#include "03/code_021d1440.h"
#include "03/code_021d1dd0.h"
#include "03/unk_021da000.h"
#include "03/code_021bf098.h"
#include "03/code_021bf410.h"
#include "03/code_021bf698.h"
#include "03/code_021c209c.h"
#include "03/code_021c2b28.h"
#include "03/code_021c2c94.h"
#include "03/code_021c30f0.h"
#include "03/code_021c38f0.h"
#include "03/code_021c43f0.h"
#include "code_0212df7c.h"
#include "03/code_021cdbd0.h"
#include "03/code_021d1000.h"
#include "03/code_021d1f70.h"
#include "03/code_021d254c.h"
#include "03/code_021d2ecc.h"
#include "code_02147cd8.h"
#include "code_021510a4.h"
#include "code_02151868.h"
#include "03/code_021d2940.h"
#include "03/code_021d1fd0.h"
#include "03/unk_021d5000.h"
#include "03/code_021bf810.h"
#include "03/code_021d1c18.h"
#include "code_0200eddc.h"
#include "code_0214b824.h"
#include "code_0214d018.h"
#include "03/code_021cc8d4.h"
#include "03/code_021cdcb8.h"

void func_ov003_021c3dd4(void) {
    Unk021da104_04 *a;
    data_ov003_021da1b0[0] = 0;
    func_ov003_021c3cc4();
    func_ov003_021bf86c(0x10);
    func_ov003_021cdcf0(3);
    func_ov003_021bf43c(0x88, -1, 0);
    data_ov003_021da1b8 = func_ov003_021d1c18(0, 0x5b);
    a = data_ov003_021da1b8;
    a->mUnk_00 =
        ((data_ov003_021d634c[0] & 0x1ff) << 16) | ((a->mUnk_00 & 0xfe00ff00) | (data_ov003_021d634c[1] & 0xff));
    a = data_ov003_021da1b8;
    a->mUnk_04 = (a->mUnk_04 & 0xfffff3ff) | 0xc00;
    func_ov003_021bf6c8(data_ov003_021d6368[data_ov003_021da1ac * 4], data_ov003_021d636c[data_ov003_021da1ac * 4],
                        data_ov003_021d636a[data_ov003_021da1ac * 4], data_ov003_021d636e[data_ov003_021da1ac * 4]);
    func_ov003_021c212c(func_ov003_021c3c88);
}

void func_ov003_021c3cc4(void) {
    u8 *a;
    Unk021d70f8 b;
    Unk021d7110 c;
    Unk021510a4 d;
    u8 *e;
    u8 *f;
    s32 i;
    b = data_ov003_021d70f8;
    c = data_ov003_021d7110;
    func_ov003_021bf620(data_ov003_021d7128, MemCopyWordsToG2Bg2CntBits2To5Address);
    func_ov003_021bf620(data_ov003_021d7140, MemCopyHalfwordsToG2Bg2CntBits8To12Address);
    data_ov003_021da1b4 = func_ov003_021d14b8(func_ov003_021bf650(c.mUnk_00), NULL, 4);
    a = func_ov003_021d14b8(func_ov003_021bf650(b.mUnk_00), NULL, 4);
    func_02151910(&d);
    if (d.mUnk_00 == 0) {
        e = a + 0xc0;
        f = a + 0x40;
        for (i = 0; i < 2; i++, e += 0x20, f += 0x20) {
            MemCopy(e, f, 0x20);
        }
    }
    func_0200ee74(a, 0x200);
    func_0214c160(a, 0, 0x200);
    func_ov003_021d1490(a);
    *(u16 *) 0x4001008 = (*(u16 *) 0x4001008 & ~3) | 3;
    *(u16 *) 0x400100a = (*(u16 *) 0x400100a & ~3) | 3;
    *(u16 *) 0x400000a = (*(u16 *) 0x400000a & ~3) | 3;
    *(u16 *) 0x400000c = (*(u16 *) 0x400000c & ~3) | 3;
}

void func_ov003_021c3c88(void) {
    func_ov003_021d1ee0(2, 1, 1, (u16) (8));
    func_ov003_021d1ee0(2, 0, 0x14, (u16) (8));
    func_ov003_021d2784(1, 1);
    func_ov003_021d2784(0, 0x14);
    func_ov003_021c212c(func_ov003_021c3c58);
    return;
}

void func_ov003_021c3c58(void) {
    int v1;
    v1 = func_ov003_021d1f70(1);
    if ((v1 == 0) && (v1 = func_ov003_021d1f70(0), v1 == 0)) {
        func_ov003_021bf5c8(0);
        func_ov003_021c212c(func_ov003_021c3c34);
    }
    return;
}

void func_ov003_021c3c34(void) {
    if (func_ov003_021bf334() != -2) {
        func_ov003_021bf2e0();
        func_ov003_021c212c(func_ov003_021c3c1c);
    }
}

void func_ov003_021c3c1c(void) {
    func_ov003_021c3b60();
    func_ov003_021c3b5c();
    func_ov003_021c3ae4();
    return;
}

void func_ov003_021c3b60(void) {
    u32 i;
    for (i = 0; i < 3; i++) {
        if (func_ov003_021d2a34(&data_ov003_021d6350[i]) != 0) {
            func_ov003_021bf31c(1);
            data_ov003_021da1ac = i;
            func_ov003_021bf6c8(
                data_ov003_021d6368[data_ov003_021da1ac * 4], data_ov003_021d636c[data_ov003_021da1ac * 4],
                data_ov003_021d636a[data_ov003_021da1ac * 4], data_ov003_021d636e[data_ov003_021da1ac * 4]);
            return;
        }
    }
    if (func_ov003_021d2b04(1) != 0) {
        func_ov003_021bf31c(1);
    } else if (func_ov003_021d2b04(2) != 0) {
        func_ov003_021bf31c(0);
    } else if (func_ov003_021d2ae8(0x40) != 0) {
        func_ov003_021c3940(1);
    } else if (func_ov003_021d2ae8(0x80) != 0) {
        func_ov003_021c3940(3);
    }
}

void func_ov003_021c3b5c(void) {
    return;
}

void func_ov003_021c3ae4(void) {
    Unk021510a4 a;
    switch (func_ov003_021bf334()) {
        case 0:
            func_ov003_021cdc10(7);
            break;
        case 1:
            func_02151910(&a);
            if (data_ov003_021da1ac != 0 && a.mUnk_00 == 0) {
                func_ov003_021cdc10(9);
                func_ov003_021bf310(-1);
                return;
            }
            func_ov003_021cdc10(6);
            func_ov003_021c391c();
            data_ov003_021da1b0[0] = 1;
            break;
        default:
            return;
    }
    func_ov003_021c212c(func_ov003_021c3ac4);
}

void func_ov003_021c3ac4(void) {
    func_ov003_021bf2d0();
    func_ov003_021d1dd0((u16) 8);
    func_ov003_021c212c(func_ov003_021c3a7c);
}

void func_ov003_021c3a7c(void) {
    int v1;
    v1 = func_ov003_021d1f70(1);
    if (v1 == 0) {
        if ((*(u8 *) &data_ov003_021da1b0) != 0) {
            func_ov003_021bf344();
        }
        func_ov003_021d1ee0(3, 1, (u32) 1, (u16) 8);
        func_ov003_021d1ee0(3, 0, (u32) 0x14, (u16) 8);
        func_ov003_021c212c(func_ov003_021c39a4);
    }
}

void func_ov003_021c39a4(void) {
    if (func_ov003_021d1f70(1) == 0 && func_ov003_021d1f70(0) == 0 && func_ov003_021bf2f0() != 0) {
        func_ov003_021d2f00((u32 *) data_ov003_021da1b8);
        func_ov003_021bf698();
        func_ov003_021bf410();
        func_ov003_021d1490(data_ov003_021da1b4);
        func_ov003_021d272c(1, 1);
        func_ov003_021d272c(0, 0x14);
        if (data_ov003_021da1b0[0] == 0) {
            func_ov003_021c2120(0, 0);
            func_ov003_021c212c(func_ov003_021c3078);
        } else {
            switch (data_ov003_021da1ac) {
                case 0:
                    func_ov003_021c2120(0, 1);
                    func_ov003_021c212c(func_ov003_021c38f0);
                    break;
                case 1:
                    func_ov003_021c2120(0, 1);
                    func_ov003_021c212c(func_ov003_021c33ac);
                    break;
                case 2:
                    func_ov003_021c2120(0, 1);
                    func_ov003_021c212c(func_ov003_021c4670);
                    break;
            }
        }
    }
}

void func_ov003_021c3940(s32 a) {
    if (a == 1) {
        data_ov003_021da1ac = Div32Remainder(data_ov003_021da1ac + 2, 3);
    } else {
        data_ov003_021da1ac = Div32Remainder(data_ov003_021da1ac + 1, 3);
    }
    func_ov003_021cdc10(8);
    func_ov003_021bf6c8(data_ov003_021d6368[data_ov003_021da1ac * 4], data_ov003_021d636c[data_ov003_021da1ac * 4],
                        data_ov003_021d636a[data_ov003_021da1ac * 4], data_ov003_021d636e[data_ov003_021da1ac * 4]);
}

void func_ov003_021c391c(void) {
    u8 a = data_ov003_021d6348[data_ov003_021da1ac];
    func_ov003_021cc948(data_ov003_021da1b4, a, a);
}
