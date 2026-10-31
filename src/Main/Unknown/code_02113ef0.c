#include "Main/Unknown/code_02113ef0.h"

#pragma thumb on

u32 func_02113ef0(int param_1) {
    int v1;
    int v2;
    v1 = func_02113f1c();
    v2 = func_021143b4();
    if (v2 > v1 + param_1) {
        return 1;
    }
    return 0;
}

#pragma thumb off
