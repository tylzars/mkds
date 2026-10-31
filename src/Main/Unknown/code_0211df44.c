#include "Main/Unknown/code_0211df44.h"

#pragma thumb on

void func_0211e074(void) {
    void *v1;
    Unk020b4934 *v2;
    Unk02021dc8 *v3;
    Unk020b4a44 *v4[1];
    v2 = 0;
    v3 = 0;
    v4[0] = 0;
    v1 = func_0204799c((const char *) ((*(u32 *) &data_0216ded4)));
    func_020b496c(&v2, v1);
    v1 = func_0204799c((const char *) ((*(u32 *) &data_0216ded8)));
    func_020b48ec(&v3, v1);
    v1 = func_0204799c((const char *) ((*(u32 *) &data_0216dec4)));
    func_020b4a7c(v4, v1);
}

void func_0211e024(void) {
    void *v1;
    Unk020b4934 *v2;
    Unk02021dc8 *v3;
    Unk020b4a44 *v4[1];
    v2 = 0;
    v3 = 0;
    v4[0] = 0;
    v1 = func_0204799c((const char *) ((*(u32 *) &data_0216dedc)));
    func_020b496c(&v2, v1);
    v1 = func_0204799c((const char *) ((*(u32 *) &data_0216decc)));
    func_020b48ec(&v3, v1);
    v1 = func_0204799c((const char *) ((*(u32 *) &data_0216dee0)));
    func_020b4a7c(v4, v1);
}

void func_0211dfb4(u32 param_1) {
    int v1;
    u32 v2;
    v1 = ((u32) func_02036bec((void *) param_1, (u32) 0x10));
    *(int *) &data_0217d370 = v1;
    v2 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216ded4))));
    func_020b49bc(&data_0217d370->mUnk_00, (void *) v2);
    v2 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216ded8))));
    func_020b48b4(&data_0217d370->mUnk_04, (void *) v2);
    v2 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216dec4))));
    func_020b4a44(&data_0217d370->mUnk_08, (void *) v2);
    v2 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216dec8))));
    *(u32 *) ((int) data_0217d370 + 0xc) = v2;
}

void func_0211df44(void *param_1) {
    int v1;
    u32 v2;
    v1 = ((u32) func_02036bec(param_1, (u32) 0x10));
    *(int *) &data_0217d370 = v1;
    v2 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216dedc))));
    func_020b49bc(&data_0217d370->mUnk_00, (void *) v2);
    v2 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216decc))));
    func_020b48b4(&data_0217d370->mUnk_04, (void *) v2);
    v2 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216dee0))));
    func_020b4a44(&data_0217d370->mUnk_08, (void *) v2);
    v2 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216ded0))));
    *(u32 *) ((int) data_0217d370 + 0xc) = v2;
}

#pragma thumb off
