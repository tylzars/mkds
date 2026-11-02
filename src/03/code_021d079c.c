#include "03/code_021d079c.h"

#include "03/unk_021d7000.h"
#include "03/unk_021da000.h"

void func_ov003_021d0810(Unk021da2a8 *param_1) {
    data_ov003_021da2a8 = param_1;
    param_1->mUnk_40 = 0;
    data_ov003_021da2a8->mUnk_13a8 = 0;
    data_ov003_021da2a8->mUnk_13ac = 0;
    data_ov003_021da2a8->mUnk_13b0 = 0;
}

void func_ov003_021d07b0(u32 v1) {
    if (data_ov003_021da2a4 != 0) {
        data_ov003_021da2a4(0x08000000, data_ov003_021d7bc8, data_ov003_021d79a8[data_ov003_021da2a8->mUnk_40]);
    }
    data_ov003_021da2a8->mUnk_40 = v1;
    if (data_ov003_021da2a4 != 0) {
        data_ov003_021da2a4(0x08000000, data_ov003_021d7bd0, data_ov003_021d79a8[data_ov003_021da2a8->mUnk_40]);
    }
}

void func_ov003_021d079c(s32 value) {
    if ((u32) (data_ov003_021da2a8->mUnk_40 - 9) > 1) {
        data_ov003_021da2a8->mUnk_54 = value;
    }
}
