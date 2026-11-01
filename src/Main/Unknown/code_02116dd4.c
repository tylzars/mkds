#include "Main/Unknown/code_02116dd4.h"

#pragma thumb on

void func_02116e70(void) {
    void *v1;
    Unk02021dc8 *v2;
    Unk020b4934 *v3;
    Unk020b4a44 *v4[1];
    v2 = 0;
    v3 = 0;
    v4[0] = 0;
    v1 = func_0204799c((const char *) ((*(u32 *) &data_0216d4c4)));
    func_020b48ec(&v2, v1);
    v1 = func_0204799c((const char *) ((*(u32 *) &data_0216d4bc)));
    func_020b49f4(&v3, v1);
    v1 = func_0204799c((const char *) ((*(u32 *) &data_0216d4c0)));
    func_020b4a7c(v4, v1);
}

void func_02116dd4(void *param_1, void *param_2, void *param_3, u32 param_4, u16 param_5, u32 param_6) {
    int *v1;
    int v2;
    u32 v3;
    v2 = ((u32) func_02036bec(param_1, (u32) 0x2c));
    *(int *) &data_0217d354 = v2;
    v3 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216d4c4))));
    func_020b48b4(&data_0217d354->mUnk_00, (void *) v3);
    v3 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216d4bc))));
    func_020b49bc((Unk020b4934 **) &data_0217d354->mUnk_04, (void *) v3);
    v3 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216d4c0))));
    func_020b4a44((Unk020b4a44 **) ((int *) (u32) ((int) data_0217d354 + 8)), (void *) v3);
    v3 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216d4c8))));
    v1 = (int *) &data_0217d354;
    *(u32 *) ((int) data_0217d354 + 0xc) = v3;
    *(void **) (*v1 + 0x10) = param_2;
    *(void **) (*v1 + 0x14) = param_3;
    *(u32 *) (*v1 + 0x18) = param_4;
    *(u16 *) (*v1 + 0x1c) = param_5;
    *(u32 *) (*v1 + 0x20) = param_6;
    *(u16 *) (*v1 + 0x24) = 2;
    *(u32 *) (*v1 + 0x28) = 3;
}

#pragma thumb off
