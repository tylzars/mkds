#include "00/code_021a2f98.h"

void func_ov000_021a2ff8(int param_1) {
    int *v1;
    v1 = (int *) &data_ov000_021b5dd0;
    if ((int) data_ov000_021b5dd0 != 0) {
        param_1 = param_1 * 0x30;
        *(u32 *) ((int) data_ov000_021b5dd0 + param_1 + 0xc) = 0;
        *(u32 *) (*v1 + param_1 + 0x10) = 0;
        *(u32 *) (*v1 + param_1 + 0x14) = 0;
        *(u32 *) (*v1 + param_1 + 0x18) = 0;
        *(u8 *) (*v1 + param_1 + 0x1c) = 0;
        *(u16 *) (*v1 + param_1 + 0x22) = 0;
    }
    return;
}

void func_ov000_021a2fec(void) {
    *(u32 *) &data_ov000_021b5dd0 = 0;
    return;
}

int func_ov000_021a2fdc(int param_1) {
    return (int) data_ov000_021b5dd0 + param_1 * 0x30;
}

u8 func_ov000_021a2fc8(int param_1) {
    return *(u8 *) ((int) data_ov000_021b5dd0 + param_1 * 0x30 + 0x1c);
}

u8 func_ov000_021a2fb4(int param_1) {
    return *(u8 *) ((int) data_ov000_021b5dd0 + param_1 * 0x30 + 0x1d);
}

void func_ov000_021a2f98(u32 param_1, u32 param_2, u32 param_3, u32 param_4) {
    u32 v1;
    v1 = func_ov000_0219b9d4(param_1);
    func_ov000_02198914((Unk02197fe8 *) v1, (u8 *) param_2, (int) param_3, (int) param_4);
    return;
}
