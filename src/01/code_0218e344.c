#include "01/code_0218e344.h"

void func_ov001_0218e344(int param_1) {
    int v1;
    v1 = func_ov001_021871f8((Unk02188950 *) (param_1), 5);
    if (v1 != 0) {
        func_ov001_0218edc8((Unk02188950 *) (param_1));
    }
    *(u32 *) (param_1 + 0x2d8) = 0xd;
    func_ov001_02188200((Unk02188950 *) (param_1), (UnkFunc *) ((u32) &func_ov001_0218e344));
    if (*(int *) (param_1 + 0x2d0) == 0) {
        func_020d2774((Unk020e71a0 *) (param_1), (u32) (((u32) 0x00000234u)));
    }
}
