#include "Main/Unknown/code_0211f2b8.h"

#pragma thumb on

void func_0211f328(void) {
    void *v1;
    Unk020b4934 *v2;
    Unk02021dc8 *v3;
    Unk020b4a44 *v4[1];
    v2 = 0;
    v3 = 0;
    v4[0] = 0;
    v1 = func_0204799c((const char *) ((*(u32 *) &data_0216e0a8)));
    func_020b496c(&v2, v1);
    v1 = func_0204799c((const char *) ((*(u32 *) &data_0216e0ac)));
    func_020b48ec(&v3, v1);
    v1 = func_0204799c((const char *) ((*(u32 *) &data_0216e0b4)));
    func_020b4a7c(v4, v1);
}

void func_0211f2b8(void *param_1) {
    int v1;
    u32 v2;
    v1 = ((u32) func_02036bec(param_1, (u32) 0x10));
    *(int *) &data_0217d37c = v1;
    v2 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216e0a8))));
    func_020b49bc(&data_0217d37c->mUnk_00, (void *) v2);
    v2 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216e0ac))));
    func_020b48b4(&data_0217d37c->mUnk_04, (void *) v2);
    v2 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216e0b4))));
    func_020b4a44(&data_0217d37c->mUnk_08, (void *) v2);
    v2 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216e0b0))));
    *(u32 *) ((int) data_0217d37c + 0xc) = v2;
}

#pragma thumb off
