#include "Main/Unknown/code_020f1d40.h"

#pragma thumb on

u32 func_020f1d40(int a) {
    u32 v1;
    UnkWordFunc *v2;
    v2 = (UnkWordFunc *) data_0217bc34[a].mUnk_48;
    if (v2 != (UnkWordFunc *) 0x0) {
        v1 = (*v2)(0, 0, 1);
        return v1;
    }
    return 0;
}

#pragma thumb off
