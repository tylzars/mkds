#include "Main/Unknown/code_02118114.h"

#pragma thumb on

void func_02118114(void) {
    int *v1;
    v1 = (int *) &data_0217d360;
    *(u32 *) ((int) data_0217d360 + 0x34) = 6;
    *(u32 *) (*v1 + 0x38) = 0;
    func_0212775c(0, (u32) 7);
    func_0212775c(1, (u32) 0x10);
    func_0212775c((int) 0xffffffff, (u32) 0x10);
}

#pragma thumb off
