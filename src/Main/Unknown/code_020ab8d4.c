#include "Main/Unknown/code_020ab8d4.h"

#pragma thumb on

void func_020ab910(u32 param_1, u32 param_2, u32 param_3, u32 param_4) {
    int *v1;
    int v2;
    v1 = (int *) &data_0217b334;
    *(u32 *) ((int) data_0217b334 + 0x58) = param_1;
    *(u32 *) (*v1 + 0x5c) = param_2;
    *(u32 *) (*v1 + 0x60) = param_3;
    *(u32 *) (*v1 + 100) = param_4;
    v2 = *v1;
    func_020a9efc(
        (u32) (*(int *) (v2 + 0x50) + *(int *) (v2 + 0x58)), (u32) (*(int *) (v2 + 0x54) + *(int *) (v2 + 0x5c)),
        (u32) (*(int *) (v2 + 0x50) + *(int *) (v2 + 0x60)), (u32) (*(int *) (v2 + 0x54) + *(int *) (v2 + 100)));
}

void func_020ab8d4(u32 param_1, u32 param_2, u32 param_3, u32 param_4) {
    int *v1;
    int v2;
    v1 = (int *) &data_0217b334;
    *(u32 *) ((int) data_0217b334 + 0x68) = param_1;
    *(u32 *) (*v1 + 0x6c) = param_2;
    *(u32 *) (*v1 + 0x70) = param_3;
    *(u32 *) (*v1 + 0x74) = param_4;
    v2 = *v1;
    func_020a9ed8(
        (u32) (*(int *) (v2 + 0x50) + *(int *) (v2 + 0x68)), (u32) (*(int *) (v2 + 0x54) + *(int *) (v2 + 0x6c)),
        (u32) (*(int *) (v2 + 0x50) + *(int *) (v2 + 0x70)), (u32) (*(int *) (v2 + 0x54) + *(int *) (v2 + 0x74)));
}

#pragma thumb off
