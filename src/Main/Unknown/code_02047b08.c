#include "Main/Unknown/code_02047b08.h"

#pragma thumb on

void *func_02047b08(const char *param_1) {
    int v1;
    v1 = func_02047b30((u32) (*(u32 *) (((u32) (u32) ((u8 *) &data_02164e04)) + 0x0)), param_1);
    if (v1 == 0) {
        v1 = func_02047b30((u32) (*(u32 *) (((int) (u32) ((u8 *) &data_02164e04)) + 0x48)), param_1);
    }
    return (void *) v1;
}

#pragma thumb off
