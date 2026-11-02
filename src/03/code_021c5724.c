#include "03/code_021c5724.h"
#include "03/unk_021d5000.h"
#include "03/unk_021da000.h"
#include "03/code_021bf698.h"
#include "03/code_021c5994.h"
#include "03/code_021c5c68.h"
#include "03/code_021ccd18.h"
#include "code_0212df7c.h"
#include "03/code_021cdbd0.h"
#include "03/code_021d3000.h"
#include "03/code_021d3488.h"

// placeholder: the original keeps the byte at a stack offset between its load and the call; the volatile
// local reproduces that.
void func_ov003_021c5724(void) {
    volatile u8 a;
    u8 b;
    a = data_ov003_021d7228[0];
    b = a;
    func_ov003_021cc948(data_ov003_021da1f4->mUnk_08, b, b);
}

void func_ov003_021c574c(void) {
    if (*(u16 *) &data_ov003_021da1f0 == data_ov003_021da1f4->mUnk_40 || data_ov003_021da1f4->mUnk_51 <= 4) {
        if (data_ov003_021da1f4->mUnk_59 == 0) {
            func_ov003_021cdc10(9);
            data_ov003_021da1f4->mUnk_59 = 1;
        }
    } else {
        func_ov003_021cdc10(0x13);
        data_ov003_021da1f4->mUnk_38 = func_ov003_021d3544(0, func_ov003_021c5994, 0, 0x78);
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
        data_ov003_021da1f4->mUnk_38 = func_ov003_021d3544(0, func_ov003_021c5a0c, 0, 0x78);
    }
}

void func_ov003_021c580c(int param_0) {
    int a;
    u8 v;
    a = 1;
    v = data_ov003_021da1ec;
    switch (v) {
        case 0:
            if (param_0 == 1) {
                if (*(u16 *) &data_ov003_021da1f0 == 0) {
                    data_ov003_021da1ec = 4;
                } else {
                    func_ov003_021cdc10(0x13);
                    data_ov003_021da1f4->mUnk_38 = func_ov003_021d3544(0, func_ov003_021c5a0c, 0, 0x78);
                    return;
                }
            } else if (data_ov003_021da1f4->mUnk_51 > 1) {
                data_ov003_021da1ec = v + 1;
            } else {
                a = 0;
            }
            break;
        case 1:
        case 2:
            if (param_0 == 1) {
                data_ov003_021da1ec = v - 1;
            } else if (data_ov003_021da1f4->mUnk_51 > v + 1) {
                data_ov003_021da1ec++;
            } else {
                a = 0;
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
                a = 0;
            } else {
                *(u16 *) &data_ov003_021da1f0 = 0;
                data_ov003_021da1ec = 0;
                func_ov003_021c5c68();
                func_ov003_021cce58(0);
            }
            break;
    }
    if (a == 0) {
        if (data_ov003_021da1f4->mUnk_59 == 0) {
            func_ov003_021cdc10(9);
            data_ov003_021da1f4->mUnk_59 = 1;
        }
    } else {
        func_ov003_021cdc10(8);
        func_ov003_021c590c();
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
