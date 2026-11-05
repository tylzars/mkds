#include "03/code_021c50f8.h"

#include "03/code_021c5000.h"
#include "03/code_021c5528.h"
#include "03/code_021cb4d0.h"
#include "03/code_021cd000.h"
#include "03/code_021be000.h"
#include "03/code_021bf000.h"
#include "03/code_021bf410.h"
#include "03/code_021b94b8.h"
#include "03/code_021c1f34.h"
#include "03/code_021cef90.h"
#include "03/code_021d1dd0.h"
#include "03/unk_021da000.h"
#include "03/code_021bf098.h"
#include "03/code_021c209c.h"
#include "03/code_021c6000.h"
#include "03/code_021c5724.h"
#include "03/code_021cca74.h"
#include "03/code_021ce000.h"
#include "03/code_021d1000.h"
#include "03/unk_021d7000.h"
#include "code_0214b824.h"
#include "03/code_021c5548.h"
#include "03/code_021cb000.h"
#include "03/code_021d1f70.h"
#include "03/code_021d3000.h"
#include "03/code_021d2940.h"
#include "03/code_021c53b4.h"
#include "03/code_021cdbd0.h"
#include "03/code_021cea3c.h"
#include "03/code_021d1fd0.h"
#include "03/code_021d254c.h"
#include "03/code_021d3488.h"
#include "03/code_021c2000.h"
#include "03/code_021bf4dc.h"
#include "03/code_021d1440.h"
#include "03/unk_021d5000.h"
#include "03/code_021cd2e0.h"
#include "03/code_021bf810.h"
#include "03/code_021be610.h"
#include "code_0212df7c.h"

void func_ov003_021c54dc(void) {
    data_ov003_021da1e0 = 0;
    func_ov003_021c5458();
    func_ov003_021bf854();
    func_ov003_021bf43c(0x82, -1, 0);
    func_ov003_021bf5ec(2);
    func_ov003_021bf578(0x67);
    func_ov003_021beef8(0);
    func_ov003_021c1fc8();
    func_ov003_021cdc10(0xb);
    func_ov003_021c212c(func_ov003_021c541c);
}

void func_ov003_021c5458(void) {
    func_ov003_021bf620(data_ov003_021d71d0, MemCopyWordsToG2Bg2CntBits2To5Address);
    func_ov003_021bf620(data_ov003_021d71e8, GX_LoadBGPltt);
    func_ov003_021bf620(data_ov003_021d7200, MemCopyHalfwordsToG2Bg2CntBits8To12Address);
    *(vu16 *) 0x4001008 = (*(vu16 *) 0x4001008 & ~3) | 3;
    *(vu16 *) 0x400100a = (*(vu16 *) 0x400100a & ~3) | 3;
    *(vu16 *) 0x4000008 = (*(vu16 *) 0x4000008 & ~3) | 3;
    *(vu16 *) 0x400000a = (*(vu16 *) 0x400000a & ~3) | 3;
    *(vu16 *) 0x400000c = (*(vu16 *) 0x400000c & ~3) | 3;
}

void func_ov003_021c541c(void) {
    func_ov003_021d1ee0(2, 1, 1, 8);
    func_ov003_021d1ee0(2, 0, 0x15, 8);
    func_ov003_021d2784(1, 1);
    func_ov003_021d2784(0, 0x15);
    func_ov003_021c212c(func_ov003_021c53ec);
}

void func_ov003_021c53ec(void) {
    if (func_ov003_021d1f70(1) == 0 && func_ov003_021d1f70(0) == 0) {
        func_ov003_021bf5c8(1);
        func_ov003_021c212c(func_ov003_021c53b4);
    }
}

void func_ov003_021c53b4(void) {
    if (func_ov003_021bf334() != -2) {
        data_ov003_021da1e4 = func_ov003_021d3544(1, func_ov003_021c51a0, NULL, 0x78);
        func_ov003_021c212c(func_ov003_021c5324);
    }
}

void func_ov003_021c5324(void) {
    int a;
    func_ov003_021c52f4();
    func_ov003_021c52f0();
    func_ov003_021c52d0();
    a = func_ov003_021c1f34();
    switch (a) {
        case 0:
            break;
        case 1:
            data_ov003_021da1dc = 1;
            func_ov003_021d34c0(1, data_ov003_021da1e4);
            data_ov003_021da1e4 = 0;
            func_ov003_021c212c(func_ov003_021c5120);
            break;
        case 2:
            func_ov003_021cdbd0();
            func_ov003_021cefc0(0x40, 1, 1, -1, 0);
            func_ov003_021cdc10(9);
            func_ov003_021bf2d0();
            func_ov003_021d34c0(1, data_ov003_021da1e4);
            data_ov003_021da1e4 = 0;
            func_ov003_021c212c(func_ov003_021c5178);
            break;
    }
}

void func_ov003_021c52f4(void) {
    int v1;
    v1 = func_ov003_021d2b20(2);
    if (v1 != 0) {
        func_ov003_021bf31c((u8) (0));
        return;
    }
    v1 = func_ov003_021c5528();
    if (v1 != 0) {
        func_ov003_021bf31c((u8) (0));
    }
    return;
}

void func_ov003_021c52f0(void) {
    return;
}

void func_ov003_021c52d0(void) {
    int v1;
    v1 = func_ov003_021bf334();
    if (v1 == 0) {
        func_ov003_021bf2d0();
        func_ov003_021c212c(func_ov003_021c50f8);
    }
    return;
}

void func_ov003_021c52a0(void) {
    func_ov003_021bf2d0();
    if (data_ov003_021da1e4 != 0) {
        func_ov003_021d34c0(1, data_ov003_021da1e4);
    }
    func_ov003_021d1dd0(8);
    func_ov003_021c212c(func_ov003_021c5258);
}

void func_ov003_021c5258(void) {
    int v1;
    v1 = func_ov003_021d1f70(1);
    if (v1 == 0) {
        func_ov003_021bf344();
        if (data_ov003_021da1dc == 0) {
            func_ov003_021d1ee0(3, 1, 1, 8);
        }
        func_ov003_021d1ee0(3, 0, 0x15, 8);
        func_ov003_021c212c(func_ov003_021c51bc);
    }
    return;
}

void func_ov003_021c51bc(void) {
    int v1;
    v1 = func_ov003_021d1f70(0);
    if ((v1 == 0) && (((data_ov003_021da1dc != 0 || (v1 = func_ov003_021d1f70(1), v1 == 0)) &&
                       (v1 = func_ov003_021bf2f0(), v1 != 0)))) {
        func_ov003_021c1f84((data_ov003_021da1dc != 0));
        func_ov003_021beecc();
        func_ov003_021d2168(0);
        if (data_ov003_021da1dc == 0) {
            func_ov003_021bf410();
            func_ov003_021d272c(1, 1);
        }
        func_ov003_021d272c(0, 0x15);
        if (data_ov003_021da1dc == 0) {
            func_ov003_021c2120(2, 1);
            func_ov003_021c212c(func_ov003_021cb7fc);
            return;
        }
        func_ov003_021c2120(0, 0);
        func_ov003_021c212c(func_ov003_021c56a4);
    }
    return;
}

void func_ov003_021c51a0(void) {
    func_ov003_021d2d14();
    func_ov003_021d3558(0);
    func_ov003_021c52f4();
    func_ov003_021c52d0();
    return;
}

void func_ov003_021c5178(void) {
    int v1;
    v1 = func_ov003_021cef80();
    if (v1 == 0) {
        func_ov003_021cdc10(6);
        func_ov003_021cef90();
        func_ov003_021c212c(func_ov003_021c515c);
    }
    return;
}

void func_ov003_021c515c(void) {
    int v1;
    v1 = func_ov003_021cef6c();
    if (v1 == 0) {
        func_ov003_021c212c(func_ov003_021c52a0);
    }
    return;
}

void func_ov003_021c5120(void) {
    func_ov003_021c52f4();
    func_ov003_021c52f0();
    func_ov003_021c52d0();
    data_ov003_021da1e0 = data_ov003_021da1e0 + 1;
    if (data_ov003_021da1e0 >= 0x438) {
        func_ov003_021cdbd0();
        func_ov003_021c212c(func_ov003_021c52a0);
    }
}

void func_ov003_021c50f8(void) {
    func_ov003_021cdbd0();
    func_ov003_021cdc10((u32) (7));
    *(u8 *) &data_ov003_021da1dc = 0;
    func_ov003_021c212c(func_ov003_021c52a0);
    return;
}
