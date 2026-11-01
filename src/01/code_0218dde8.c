#include "01/code_0218dde8.h"

void func_ov001_0218de14(u32 param_1, int param_2) {
    func_ov001_02186368((void *) param_1, (Unk02188950 *) param_2);
    if (*(int *) (param_2 + 0xa8) == 0) {
        func_ov001_021861f4((void *) param_1, (Unk02188950 *) param_2, 0);
        return;
    }
    func_ov001_021861f4((void *) param_1, (Unk02188950 *) param_2, 1);
}

void func_ov001_0218dde8(void) {
    void *v6 = &func_ov001_02185fb0;
    void *v7 = &func_ov001_02185f04;
    void *v8 = &func_ov001_021860cc;
    u32 v10 =
        (u32) func_ov001_0219b510(v6, v7, v8, (u32) 0x2u, (u16) ((u32) 0x0u), (u16) ((u32) 0x0u), (u16) ((u32) 0x0u));
}
