#include "Main/Unknown/code_020ae3b4.h"
#include "Main/Unknown/code_02045874.h"

#pragma thumb on

u32 func_020ae3b4(u32 param_1) {
    int v1;
    u32 v2;
    v1 = func_020ae3f4();
    if (v1 == 0) {
        v2 = (u32) func_0204aa60();
    } else {
        v2 = func_020ae3d8();
    }
    return func_02046524((Unk020f41c4_B *) v2, param_1);
}

#pragma thumb off
