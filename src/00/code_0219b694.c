#include "00/code_0219b694.h"

void func_ov000_0219b6c0(int param_1, u32 param_2) {
    UnkFunc *v1;
    if (param_1 == 0) {
        data_ov000_021b54c8->mUnk_30 = param_2;
        func_ov000_0219b8a8(3);
        func_ov000_0219d5bc();
    } else {
        func_ov000_0219b8a8(0);
    }
    v1 = *(UnkFunc **) ((int) data_ov000_021b54c8 + 0x5c);
    if (v1 != (UnkFunc *) 0x0) {
        (*v1)(param_1, param_2, data_ov000_021b54c8->mUnk_60);
    }
    return;
}

void func_ov000_0219b694(u32 param_1, u32 param_2) {
    func_ov000_0219b8a8((u32) (data_ov000_021b54c8->mUnk_28));
    (**(UnkFunc **) ((int) data_ov000_021b54c8 + 100))(param_1, param_2, *(u32 *) ((int) data_ov000_021b54c8 + 0x68));
    return;
}
