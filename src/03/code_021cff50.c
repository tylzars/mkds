#include "03/code_021cff50.h"
#include "03/code_021d0000.h"
#include "03/unk_021d7000.h"
#include "03/unk_021da000.h"
#include "Main/Unknown/code_0200f000.h"
#include "code_0200fc8c.h"
#include "code_021453ec.h"
#include "03/code_021cfa68.h"
#include "03/code_021d079c.h"
#include "code_02142eac.h"

BOOL func_ov003_021d0078(void) {
    u16 a[3];
    u32 r;
    u32 t;

    func_0200fe58(a);
    t = *(u32 *) 0x27ffc3c;
    t = a[0] + t + a[1] + a[2];
    data_ov003_021da2a8->mUnk_58 = t;
    data_ov003_021da2a8->mUnk_58 = data_ov003_021da2a8->mUnk_58 * 0x10dcd + 0x3039;
    data_ov003_021da2a8->mUnk_5c = 0;
    data_ov003_021da2a8->mUnk_5e = 0x65;
    func_ov003_021d07b0(3);
    r = func_ov003_021cfff8(1);
    if (r == 0x18) {
        func_ov003_021d079c(0x18);
        func_ov003_021d07b0(9);
        return FALSE;
    }
    if (r != 2) {
        func_ov003_021d079c(r);
        func_ov003_021d07b0(9);
        return FALSE;
    }
    return TRUE;
}

u32 func_ov003_021cfff8(u16 param_1) {
    u16 r = func_02143280();
    if (r == 0x8000) {
        func_ov003_021d079c(3);
        func_ov003_021d07b0(9);
        return 3;
    }
    if (r == 0) {
        func_ov003_021d079c(0x16);
        func_ov003_021d07b0(9);
        return 0x18;
    }
    while (((1 << (param_1 - 1)) & r) == 0) {
        param_1++;
        if (param_1 > 0x10) {
            return 0x18;
        }
    }
    return (u16) func_ov003_021cff38(func_ov003_021cff50, param_1);
}

void func_ov003_021cff50(Unk021425e8 *param_1) {
    u16 a;
    u16 b;
    u32 r;

    if (param_1->mUnk_02 != 0) {
        func_ov003_021d079c(param_1->mUnk_02);
        func_ov003_021d07b0(9);
        return;
    }
    if (data_ov003_021da2a4 != NULL) {
        data_ov003_021da2a4(0x08000000, data_ov003_021d7ae0, param_1->mUnk_08_0, param_1->mUnk_08_2);
    }
    a = param_1->mUnk_08_0;
    b = param_1->mUnk_08_2;
    if (data_ov003_021da2a8->mUnk_5e > b) {
        data_ov003_021da2a8->mUnk_5e = b;
        data_ov003_021da2a8->mUnk_60 = 1 << (a - 1);
    } else if (data_ov003_021da2a8->mUnk_5e == b) {
        data_ov003_021da2a8->mUnk_60 = data_ov003_021da2a8->mUnk_60 | (1 << (a - 1));
    }
    r = func_ov003_021cfff8(a + 1);
    if (r == 0x18) {
        func_ov003_021d07b0(7);
        return;
    }
    if (r != 2) {
        func_ov003_021d07b0(9);
    }
}
