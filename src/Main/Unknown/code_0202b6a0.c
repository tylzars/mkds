#include "Main/Unknown/code_0202b6a0.h"

#pragma thumb on

void func_0202b6a0(int param_1, int param_2) {
    u32 v1;
    if ((*(int *) ((int) data_02174e3c + 0x204) != 0) &&
        (param_2 != *(int *) ((int) data_02174e3c + param_1 * 0x2c + 0x4c))) {
        if (param_2 == 1) {
            v1 = 2;
        } else {
            v1 = 1;
        }
        func_0202cc18(param_1, (int) v1);
    }
    *(int *) ((int) data_02174e3c + param_1 * 0x2c + 0x4c) = param_2;
}

#pragma thumb off
