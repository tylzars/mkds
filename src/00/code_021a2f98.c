#include "00/code_021a2f98.h"

void func_ov000_021a2ff8(int param_1) {
    if (data_ov000_021b5dd0 != 0) {
        data_ov000_021b5dd0->mUnk_000[param_1].mUnk_0c = 0;
        data_ov000_021b5dd0->mUnk_000[param_1].mUnk_10 = 0;
        data_ov000_021b5dd0->mUnk_000[param_1].mUnk_14 = 0;
        data_ov000_021b5dd0->mUnk_000[param_1].mUnk_18 = 0;
        data_ov000_021b5dd0->mUnk_000[param_1].mUnk_1c = 0;
        data_ov000_021b5dd0->mUnk_000[param_1].mUnk_22 = 0;
    }
    return;
}

void func_ov000_021a2fec(void) {
    data_ov000_021b5dd0 = 0;
    return;
}

Unk021a2d68 *func_ov000_021a2fdc(int param_1) {
    return &data_ov000_021b5dd0->mUnk_000[param_1];
}

u8 func_ov000_021a2fc8(int param_1) {
    return data_ov000_021b5dd0->mUnk_000[param_1].mUnk_1c;
}

u8 func_ov000_021a2fb4(int param_1) {
    return data_ov000_021b5dd0->mUnk_000[param_1].mUnk_1d;
}

void func_ov000_021a2f98(u32 param_1, u32 param_2, u32 param_3, u32 param_4) {
    u32 v1;
    v1 = func_ov000_0219b9d4(param_1);
    func_ov000_02198914((Unk02197fe8 *) v1, (u8 *) param_2, (int) param_3, (int) param_4);
    return;
}
