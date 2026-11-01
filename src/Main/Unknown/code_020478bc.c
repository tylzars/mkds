#include "Main/Unknown/code_020478bc.h"

#pragma thumb on

void *func_02047974(const char *param_1) {
    int v1;
    v1 = func_02047b30(data_02164e04[3], param_1);
    if (v1 == 0) {
        v1 = func_02047b30(data_02164e04[13], param_1);
    }
    return (void *) v1;
}

void *func_02047950(const char *param_1) {
    int v1;
    v1 = func_0205e0a0();
    if (v1 == 3) {
        return func_020478bc(param_1);
    }
    return func_02047780(param_1);
}

void *func_020478bc(const char *param_1) {
    int v1;
    int v2;
    v2 = 0;
    v1 = func_0205e0a0();
    if (((v1 == 1) || (v1 == 3)) || (v1 == 0xc)) {
        v2 = func_02047b30(data_02164e04[10], param_1);
    } else {
        if (*(int *) ((*(int *) &data_021759c8) + 0x308) != 0) {
            v2 = func_02047b30(data_02164e04[6], param_1);
        }
        if ((v2 == 0) && (*(int *) ((*(int *) &data_021759c8) + 0x378) != 0)) {
            v2 = func_02047b30(data_02164e04[7], param_1);
        }
        if ((v2 == 0) && (*(int *) ((*(int *) &data_021759c8) + 0x3e8) != 0)) {
            v2 = func_02047b30(data_02164e04[8], param_1);
        }
    }
    return (void *) v2;
}

#pragma thumb off
