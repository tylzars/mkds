#include "00/code_0218b3ac.h"

void func_ov000_0218b3c8(void *param_1) {
    int v1;
    if (((int) data_ov000_021b4d18 != 0) && (v1 = func_ov000_0218df5c((Unk0218e004 *) (int) data_ov000_021b4d18), v1 == 0)) {
        func_ov000_0218dfb4((int *) ((int *) (u32) data_ov000_021b4d18));
        *(int *) &data_ov000_021b4d18 = 0;
    }
    return;
}

void func_ov000_0218b3ac(int *param_1) {
    int v1;
    v1 = *param_1;
    func_ov000_0218dfb4((int *) ((int *) (u32) (*(u32 *) (v1 + 0x18))));
    *(u32 *) (v1 + 0x18) = 0;
    func_ov000_021a3668((void *) (v1));
    return;
}
