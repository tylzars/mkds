#include "Main/Unknown/code_02008dbc.h"

#pragma thumb on

void func_02008dbc(u8 *param_1, int param_2) {
    int v1;
    v1 = 0x590 * param_2;
    if (*(u16 *) (param_1 + 0x48) !=
        *(u16 *) ((int) data_0216fc40 + v1 + 0x518)) {
        func_0200895c((u32) param_2);
        func_0214cffc((const void *) param_1, (void *) ((int) data_0216fc40 + 0x4d0 + v1),
                      (u32) 0xc0);
        func_02008a4c((u32) param_2);
    }
}

#pragma thumb off
