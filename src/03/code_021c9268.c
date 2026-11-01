#include "03/code_021c9268.h"
#include "03/code_021c8e48.h"
#include "03/code_021c8ea0.h"
#include "03/code_021c9084.h"
#include "03/code_021c91fc.h"
#include "03/code_021c2120.h"
#include "03/code_021cdbd0.h"
#include "03/code_021d2acc.h"
#include "03/code_021d3544.h"

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
        data_ov003_021da214->mUnk_38 = func_ov003_021d3544(0, func_ov003_021c82b4, 0, 0x78);
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
        data_ov003_021da214->mUnk_38 = func_ov003_021d3544(0, func_ov003_021c8320, 0, 0x78);
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
