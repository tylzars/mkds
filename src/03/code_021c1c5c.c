#include "03/code_021c1c5c.h"

void func_ov003_021c1cb0(void) {
    func_ov003_021d197c(*(Unk021d1770 **) ((int) data_ov003_021da160 + 0x58));
    func_ov003_021d34e0((Unk021d34e0 *) (data_ov003_021da160->mUnk_5c), func_ov003_021c118c);
    return;
}

u8 func_ov003_021c1ca0(void) {
    return data_ov003_021da160->mUnk_60;
}

void func_ov003_021c1c90(u8 param_1) {
    data_ov003_021da160->mUnk_66 = param_1;
    return;
}

void func_ov003_021c1c80(u8 param_1) {
    data_ov003_021da160->mUnk_67 = param_1;
    return;
}

void func_ov003_021c1c70(u8 param_1) {
    data_ov003_021da160->mUnk_68 = param_1;
    return;
}

u32 func_ov003_021c1c5c(void) {
    if ((int) data_ov003_021da160 != 0) {
        return 1;
    }
    return 0;
}
