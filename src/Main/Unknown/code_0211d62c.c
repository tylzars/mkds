#include "Main/Unknown/code_0211d62c.h"

#pragma thumb on

u16 func_0211d62c(void) {
    int v1;
    v1 = *(int *) &data_0217d368;
    if (*(int *) (v1 + 0x6c) == 0) {
        return 0;
    }
    return *(u16 *) (v1 + 0xb0) + *(u16 *) (v1 + 0xb2);
}

#pragma thumb off
