#include "03/code_021cb4d0.h"

#include "03/code_021bf000.h"
#include "03/code_021cb000.h"
#include "03/code_021d1000.h"
#include "03/code_021d1dd0.h"
#include "03/code_021d1f70.h"
#include "03/unk_021da000.h"
#include "03/code_021bf098.h"
#include "03/code_021c209c.h"
#include "03/code_021cb11c.h"
#include "code_0212df7c.h"
#include "03/code_021cdbd0.h"
#include "03/unk_021d6000.h"
#include "03/code_021c2000.h"
#include "03/code_021ce000.h"
#include "03/code_021bf4dc.h"
#include "03/code_021bf698.h"
#include "03/code_021d2940.h"
#include "03/code_021d254c.h"

void func_ov003_021cb71c(void) {
    func_ov003_021d1ee0(2, 1, 1, (u16) (8));
    func_ov003_021d1ee0(2, 0, 0x14, (u16) (8));
    func_ov003_021d2784(1, 1);
    func_ov003_021d2784(0, 0x14);
    func_ov003_021c212c(func_ov003_021cb6ec);
    return;
}

void func_ov003_021cb6ec(void) {
    int v1;
    v1 = func_ov003_021d1f70(1);
    if ((v1 == 0) && (v1 = func_ov003_021d1f70(0), v1 == 0)) {
        func_ov003_021bf5c8(0);
        func_ov003_021c212c(func_ov003_021cb6c8);
    }
    return;
}

void func_ov003_021cb6c8(void) {
    if (func_ov003_021bf334() != -2) {
        func_ov003_021bf2e0();
        func_ov003_021c212c(func_ov003_021cb6b0);
    }
}

void func_ov003_021cb6b0(void) {
    func_ov003_021cb580();
    func_ov003_021cb57c();
    func_ov003_021cb538();
    return;
}

void func_ov003_021cb580(void) {
    u32 i;
    for (i = 0; i < 4; i++) {
        if (func_ov003_021d2a34(&data_ov003_021d65a0[func_ov003_021c20a8(1)][i]) != 0) {
            func_ov003_021bf31c(1);
            data_ov003_021da23c = i;
            func_ov003_021bf6c8(data_ov003_021d65e0[func_ov003_021c20a8(1)][data_ov003_021da23c].mUnk_00,
                                data_ov003_021d65e0[func_ov003_021c20a8(1)][data_ov003_021da23c].mUnk_04,
                                data_ov003_021d65e0[func_ov003_021c20a8(1)][data_ov003_021da23c].mUnk_02,
                                data_ov003_021d65e0[func_ov003_021c20a8(1)][data_ov003_021da23c].mUnk_06);
            return;
        }
    }
    if (func_ov003_021d2b04(1) != 0) {
        func_ov003_021bf31c(1);
    } else if (func_ov003_021d2b04(2) != 0) {
        func_ov003_021bf31c(0);
    } else if (func_ov003_021d2ae8(0x40) != 0) {
        func_ov003_021cb320(1);
    } else if (func_ov003_021d2ae8(0x80) != 0) {
        func_ov003_021cb320(3);
    } else if (func_ov003_021d2ae8(0x20) != 0) {
        func_ov003_021cb320(0);
    } else if (func_ov003_021d2ae8(0x10) != 0) {
        func_ov003_021cb320(2);
    }
}

void func_ov003_021cb57c(void) {
    return;
}

void func_ov003_021cb538(void) {
    switch (func_ov003_021bf334()) {
        case 0:
            func_ov003_021cdc10(7);
            break;
        case 1:
            func_ov003_021cdc10(6);
            func_ov003_021cb2e0();
            data_ov003_021da240[0] = 1;
            break;
        default:
            return;
    }
    func_ov003_021c212c(func_ov003_021cb518);
}

void func_ov003_021cb518(void) {
    func_ov003_021bf2d0();
    func_ov003_021d1dd0((u16) 8);
    func_ov003_021c212c(func_ov003_021cb4d0);
}

void func_ov003_021cb4d0(void) {
    int v1;
    v1 = func_ov003_021d1f70(1);
    if (v1 == 0) {
        if ((*(u8 *) &data_ov003_021da240) != 0) {
            func_ov003_021bf344();
        }
        func_ov003_021d1ee0(3, 1, (u32) 1, (u16) 8);
        func_ov003_021d1ee0(3, 0, (u32) 0x14, (u16) 8);
        func_ov003_021c212c(func_ov003_021cb3d8);
    }
}
