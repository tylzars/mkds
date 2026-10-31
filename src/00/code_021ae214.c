#include "00/code_021ae214.h"

void func_ov000_021ae228(int param_1) {
    u32 v1;
    v1 = func_ov000_021ae314();
    *(u32 *) (param_1 + 0x28) = v1;
    *(u8 *) (param_1 + 8) = 1;
    *(u32 *) (param_1 + 4) = 1;
    func_0200e01c((Unk0200df9c *) 0);
}

void func_ov000_021ae214(Unk021a78a4Func param_1) {
    int v1;
    v1 = *(int *) (*(int *) (((int) (u32) ((u8 *) &data_0216ff5c)) + 4) + 0xa4);
    if (v1 != 0) {
        *(Unk021a78a4Func *) (v1 + 0x38) = param_1;
    }
}
