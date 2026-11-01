#include "Main/Unknown/code_020483e4.h"

#pragma thumb on

u32 func_02048440(void) {
    u32 v1;
    v1 = (int) data_0217aa00->mUnk_043c;
    if ((data_021759d0->mUnk_00 == 2) && (((int *) (u32) data_021759d0)[1] == 1)) {
        v1 = v1 + 5;
    }
    return ((u32 *) &data_02164dc8)[v1];
}

void func_0204840c(u32 param_1, u8 *param_2) {
    u32 v1;
    if (*param_2 != 0) {
        v1 = func_02048474();
        func_0200d9e0((char *) param_1, 0x80, (const char *) ((u32) &data_02165148), param_2, v1, (u32) &data_0216515c);
    }
}

void func_020483e4(u32 param_1, u8 *param_2) {
    if (*param_2 != 0) {
        func_0200d9e0((char *) param_1, 0x80, (const char *) ((u32) &data_0216512c), param_2, (u32) &data_02165140);
    }
}

#pragma thumb off
