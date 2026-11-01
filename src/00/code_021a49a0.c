#include "00/code_021a49a0.h"

void func_ov000_021a49f4(void *param_1, UnkFunc *param_2) {
    if (param_1 == 0) {
        param_1 = data_ov000_021b426c;
    }
    *(UnkFunc **) ((u8 *) param_1 + 0xa0) = param_2;
    return;
}

void func_ov000_021a49e0(void *param_1, UnkFunc *param_2) {
    if (param_1 == 0) {
        param_1 = data_ov000_021b426c;
    }
    *(UnkFunc **) ((u8 *) param_1 + 0xa4) = param_2;
    return;
}

void func_ov000_021a49cc(void *param_1, void (*param_2)(void *, u16)) {
    if (param_1 == 0) {
        param_1 = data_ov000_021b426c;
    }
    *(void (**)(void *, u16))((u8 *) param_1 + 0xa8) = param_2;
    return;
}

void func_ov000_021a49a0(Unk021a4a08 *param_1) {
    if (param_1 == 0) {
        param_1 = data_ov000_021b426c;
    }
    if (param_1->mUnk_0bc != 0) {
        func_ov000_021a4868(param_1);
    }
    func_ov000_021a4940(param_1);
    return;
}
