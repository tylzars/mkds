#include "03/code_021c2b28.h"
#include "03/code_021d1c3c.h"
#include "03/code_021bf2d0.h"
#include "03/code_021bf410.h"
#include "03/code_021bf4d0.h"
#include "03/code_021bf620.h"
#include "03/code_021bf698.h"
#include "03/code_021bf7f4.h"
#include "03/code_021c209c.h"
#include "03/code_021c20c0.h"
#include "03/code_021c20d0.h"
#include "03/code_021c2120.h"
#include "03/code_021c250c.h"
#include "03/code_021c2564.h"
#include "03/code_021c25b4.h"
#include "03/code_021c2afc.h"
#include "03/code_021c3cc4.h"
#include "03/code_021cb000.h"
#include "03/code_021cdb90.h"
#include "03/code_021cdc10.h"
#include "03/code_021d1000.h"
#include "03/code_021d1f70.h"
#include "03/code_021d254c.h"
#include "03/code_021bf43c.h"
#include "code_0214b824.h"

void func_ov003_021c2d18(void) {
    if (func_ov003_021d1f70(1) == 0 && func_ov003_021d1f70(0) == 0) {
        func_ov003_021bf698();
        func_ov003_021bf410();
        func_ov003_021d1490(data_ov003_021da1a4);
        func_ov003_021d272c(1, 1);
        func_ov003_021d272c(0, 0x14);
        switch (data_ov003_021da1a0) {
            case 0:
                func_ov003_021c2120(1, 0);
                func_ov003_021c212c(func_ov003_021cb294);
                break;
            case 1:
                func_ov003_021c2120(0, 0);
                func_ov003_021c212c(func_ov003_021c3dd4);
                break;
        }
    }
}

void func_ov003_021c2cc8(s32 a) {
    if (a != 1 && a != 3) {
        data_ov003_021da1a0 ^= 1;
        func_ov003_021cdc10(8);
        func_ov003_021bf6c8(data_ov003_021d6328[data_ov003_021da1a0 * 4], data_ov003_021d632c[data_ov003_021da1a0 * 4],
                            data_ov003_021d632a[data_ov003_021da1a0 * 4], data_ov003_021d632e[data_ov003_021da1a0 * 4]);
    }
}

void func_ov003_021c2c94(void) {
    Unk021d6fd0 a;
    u8 b;
    a = data_ov003_021d6fd0;
    b = a.mUnk_00[data_ov003_021da1a0];
    func_ov003_021cc948(data_ov003_021da1a4, b, b);
}

void func_ov003_021c2b28(void) {
    func_ov003_021cdb90();
    func_ov003_021c25b4();
    func_ov003_021bf7f4();
    func_ov003_021bf8c0();
    func_ov003_021bf4d0();
    if (func_ov003_021c20d0() == 1 && func_ov003_021c20a8(2) != 0) {
        data_ov003_021da19c = func_ov003_021c2564(data_ov003_021d6eb8);
    } else {
        data_ov003_021da19c = func_ov003_021c2564(data_ov003_021d6ea0[func_ov003_021c20d0()]);
    }
    func_ov003_021d1cb0(1, func_ov003_021bf650(data_ov003_021d6ec8));
    func_ov003_021d1cb0(0, func_ov003_021bf650(data_ov003_021d6edc));
    func_ov003_021bf620(data_ov003_021d6ef0, func_0214b9c4);
    func_ov003_021bf620(data_ov003_021d6f04, func_0214c0f8);
    func_ov003_021bf620(data_ov003_021d6f18, func_0214bea4);
    func_ov003_021bf620(data_ov003_021d6f30, func_0214c028);
    func_ov003_021bf620(data_ov003_021d6f48, func_0214b95c);
    func_ov003_021bf620(data_ov003_021d6f60, func_0214c160);
    func_ov003_021bf620(data_ov003_021d6f78, func_0214bf04);
    func_ov003_021bf620(data_ov003_021d6f90, func_0214c090);
    switch (func_ov003_021c20c0()) {
        case 0:
            func_ov003_021bf620(data_ov003_021d6fa8, func_0214bd04);
            break;
        case 1:
            func_ov003_021bf620(data_ov003_021d6fbc, func_0214bd04);
            break;
    }
    *(u16 *) 0x400100a = (*(u16 *) 0x400100a & ~3) | 3;
    *(u16 *) 0x400000a = (*(u16 *) 0x400000a & ~3) | 3;
    *(u16 *) 0x400000a = (*(u16 *) 0x400000a & ~3) | 3;
    func_ov003_021d2784(1, 2);
    func_ov003_021d2784(0, 2);
    func_ov003_021c212c(func_ov003_021c2afc);
}
