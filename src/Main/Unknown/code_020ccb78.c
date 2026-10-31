#include "Main/Unknown/code_020ccb78.h"

#pragma thumb on

void func_020ccb78(void) {
    u8 v1;
    u32 *v2;
    int v3;
    v2 = (u32 *) ((u32) func_02029930());
    v3 = ((u32) func_02029930());
    func_020468b0(0, (u32) (*v2), (u32) (*(u32 *) (v3 + 4)), 0, (u32) 0xffffffff, 3);
    v1 = 1;
    do {
        func_020ccb48((u32) v1);
        v1 = v1 + 1;
    } while (v1 < 8);
}

#pragma thumb off
