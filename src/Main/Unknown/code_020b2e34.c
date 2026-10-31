#include "Main/Unknown/code_020b2e34.h"

#pragma thumb on

void func_020b2e64(u32 param_1) {
    int v1;
    int v2;
    v1 = func_020b2ec0();
    v2 = func_020b29c4();
    if (v2 != 0) {
        func_020b2f88((int) param_1);
    }
    v2 = func_020b2ec0();
    if ((v1 == 0) && (v2 != 0)) {
        func_02105d70();
    }
}

u32 func_020b2e58(void) {
    return ((u32) *(
        const u32 *) ((u8 *) (u32) (((u32) *(
                                   const u32 *) ((u8 *) (u32) (((u32) (&data_0217b354))) +
                                                          0))) +
                               4));
}

int func_020b2e34(void) {
    int v1;
    int v2;
    v2 = *(int *) ((int) data_0217b354 + 0x24);
    if ((v2 == 2) && (v1 = func_020c3db4(), v1 != 0)) {
        v2 = 7;
    }
    return v2;
}

#pragma thumb off
