#include "Main/Unknown/code_020f1d40.h"

#pragma thumb on

u32 func_020f1d40(int param_1) {
    u32 v1;
    UnkWordFunc *v2;
    v2 = *(UnkWordFunc **) ((int) data_0217bc34 + param_1 * 0xa8 + 0x48);
    if (v2 != (UnkWordFunc *) 0x0) {
        v1 = (*v2)(0, 0, 1);
        return v1;
    }
    return 0;
}

#pragma thumb off
