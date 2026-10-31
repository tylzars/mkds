#include "03/code_021cfc4c.h"
#include "03/code_021cfdc8.h"
#include "03/code_021d06b0.h"
#include "03/code_021d079c.h"
#include "03/code_021d07b0.h"
#include "03/unk_021d7000.h"
#include "03/unk_021da000.h"
#include "code_0200fd1c.h"
#include "code_02142eac.h"

s32 func_ov003_021cfc4c(u32 param_1, u16 param_2, u16 param_3) {
    if (data_ov003_021da2a8->mUnk_40 != 1) {
        func_0200fd1c();
    }
    data_ov003_021da2a8->mUnk_12a4 = 0x180;
    data_ov003_021da2a8->mUnk_12a0 = 0xe0;
    if (data_ov003_021da2a4 != 0) {
        data_ov003_021da2a4(0x08000000, data_ov003_021d7a7c, data_ov003_021da2a8->mUnk_12a4);
    }
    if (data_ov003_021da2a4 != 0) {
        data_ov003_021da2a4(0x08000000, data_ov003_021d7a94, data_ov003_021da2a8->mUnk_12a0);
    }
    data_ov003_021da2a8->mUnk_44 = param_1;
    func_ov003_021d07b0(3);
    data_ov003_021da2a8->mUnk_0c = param_2;
    data_ov003_021da2a8->mUnk_32 = param_3;
    data_ov003_021da2a8->mUnk_18 = func_02143134();
    data_ov003_021da2a8->mUnk_34 = 0xd0;
    data_ov003_021da2a8->mUnk_36 = 0x44;
    data_ov003_021da2a8->mUnk_10 = 2;
    data_ov003_021da2a8->mUnk_16 = 0;
    data_ov003_021da2a8->mUnk_12 = 0;
    data_ov003_021da2a8->mUnk_0e = 1;
    data_ov003_021da2a8->mUnk_14 = param_1 == 2 ? 1 : 0;
    if (param_1 == 0 || param_1 == 2 || param_1 == 4) {
        return func_ov003_021d0760();
    }
    if (data_ov003_021da2a4 != 0) {
        data_ov003_021da2a4(0x08000000, data_ov003_021d7aac, param_1);
    }
    return 0;
}

void func_ov003_021cfd44(Unk021425e8 *param_1) {
    if (param_1->mUnk_02 != 0) {
        func_ov003_021d079c(param_1->mUnk_02);
        func_ov003_021d07b0(10);
    } else {
        s32 r = func_021435e8(func_ov003_021cfdc8);
        if (r != 0) {
            func_ov003_021d079c(r);
            func_ov003_021d07b0(10);
        } else {
            func_ov003_021d07b0(1);
        }
    }
}

s32 func_ov003_021cfd88(void) {
    s32 r;
    func_ov003_021d07b0(3);
    r = func_02143e10(data_ov003_021da2a8->mUnk_80, func_ov003_021cfd44, 2);
    if (r != 2) {
        func_ov003_021d079c(r);
        func_ov003_021d07b0(10);
        return 0;
    }
    return 1;
}
