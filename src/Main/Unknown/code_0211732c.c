#include "Main/Unknown/code_0211732c.h"

#pragma thumb on

void func_02117388(void) {
    void *v1;
    int v2;
    u32 *v3;
    Unk020b4934 *v4;
    Unk02021dc8 *v5;
    Unk020b4a44 *v6[2];
    v4 = 0;
    v5 = 0;
    v6[0] = 0;
    v1 = func_0204799c((const char *) data_0216d534);
    func_020b496c(&v4, v1);
    v1 = func_0204799c((const char *) data_0216d538);
    func_020b48ec(&v5, v1);
    v2 = 0;
    v3 = (u32 *) &data_0216d53c;
    do {
        v1 = func_0204799c((const char *) (*v3));
        func_020b4a7c(v6, v1);
        v3 = v3 + 1;
        v2 = v2 + 1;
    } while (v2 < 3);
}

void func_0211732c(void) {
    void *v1;
    int v2;
    u32 *v3;
    Unk020b4934 *v4;
    Unk02021dc8 *v5;
    Unk020b4a44 *v6[2];
    v4 = 0;
    v5 = 0;
    v6[0] = 0;
    v1 = func_0204799c((const char *) data_0216d524);
    func_020b496c(&v4, v1);
    v1 = func_0204799c((const char *) data_0216d528);
    func_020b48ec(&v5, v1);
    v2 = 0;
    v3 = (u32 *) &data_0216d548;
    do {
        v1 = func_0204799c((const char *) (*v3));
        func_020b4a7c(v6, v1);
        v3 = v3 + 1;
        v2 = v2 + 1;
    } while (v2 < 3);
}

#pragma thumb off
