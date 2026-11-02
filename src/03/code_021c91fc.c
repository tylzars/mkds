#include "03/code_021c91fc.h"
#include "03/code_021c7000.h"
#include "03/code_021c8000.h"
#include "03/code_021c9000.h"
#include "03/code_021cd000.h"
#include "03/code_021b94b8.h"
#include "03/code_021cd4ac.h"
#include "03/unk_021da000.h"
#include "03/code_021c2000.h"
#include "03/code_021d1000.h"

#include "03/code_021c8e48.h"
#include "03/code_021c9084.h"
#include "03/code_021c209c.h"
#include "03/code_021cdbd0.h"
#include "03/code_021d2940.h"
#include "03/code_021d3000.h"
#include "03/code_021d3488.h"
#include "03/code_021d1f70.h"
#include "03/code_021d254c.h"

void func_ov003_021c94c8(void) {
    int v1[1];
    func_ov003_021cdb6c();
    func_ov003_021c20dc(0, v1);
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
