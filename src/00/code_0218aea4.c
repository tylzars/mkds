#include "00/code_0218aea4.h"

void func_ov000_0218af24(int param_1, s32 param_2) {
    *(u8 *) (param_1 + 0x15) = param_2;
    return;
}

void func_ov000_0218af1c(int param_1, u32 param_2, u16 param_3) {
    *(u32 *) (param_1 + 8) = param_2;
    *(u16 *) (param_1 + 0xc) = param_3;
    return;
}

void func_ov000_0218af18(int param_1, u32 param_2) {
    *(u32 *) (param_1 + 0x10) = param_2;
    return;
}

void func_ov000_0218af14(int param_1, u8 param_2) {
    *(u8 *) (param_1 + 0x14) = param_2;
    return;
}

u8 func_ov000_0218af10(int param_1) {
    return *(u8 *) (param_1 + 0x14);
}

u32 func_ov000_0218aefc(int param_1) {
    if (param_1 == (*(int *) &data_ov000_021b4d1c)) {
        return 1;
    }
    return 0;
}

void func_ov000_0218aedc(int *param_1, int param_2) {
    if (param_1[1] != 0) {
        *(int *) (param_1[1] + 0x20) = param_2;
    }
    param_1[1] = param_2;
    *(u32 *) (param_2 + 0x20) = 0;
    if (*param_1 == 0) {
        *param_1 = param_2;
    }
    param_1[2] = param_1[2] + 1;
    return;
}

void func_ov000_0218aec4(int *param_1, int param_2) {
    *(int *) (param_2 + 0x20) = *param_1;
    *param_1 = param_2;
    if (param_1[1] == 0) {
        param_1[1] = param_2;
    }
    param_1[2] = param_1[2] + 1;
    return;
}

int func_ov000_0218aea4(int *param_1) {
    int v1;
    v1 = *param_1;
    if (v1 != 0) {
        *param_1 = *(int *) (v1 + 0x20);
        if (*param_1 == 0) {
            param_1[1] = 0;
        }
        param_1[2] = param_1[2] + -1;
    }
    return v1;
}
