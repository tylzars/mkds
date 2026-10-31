#include "Main/Unknown/code_020589ec.h"

#pragma thumb on

void func_020589ec(void) {
    int v1;
    v1 = func_0205955c();
    if (v1 == 1) {
        v1 = (int) data_0217aa00 + 0x1608;
        *(u16 *) (v1 + 0x10) = 4;
        *(u16 *) (v1 + 0x12) = 1;
    }
}

#pragma thumb off
