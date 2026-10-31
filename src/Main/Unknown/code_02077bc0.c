#include "Main/Unknown/code_02077bc0.h"
#include "code_020172d0.h"

#pragma thumb on

void func_02077bc0(void *param_1) {
    u32 v1;
    u32 v2;
    Unk020169a4 *v3;
    u32 v4;
    v1 = func_020170dc(0x20);
    v2 = func_020172d0(0x20);
    v3 = func_02036bec(param_1, v1);
    v4 = ((u32) func_02036bec(param_1, v2));
    func_02017070((u32) 0x00040000u, (u32) 0x00020000u, v3, v1, 1);
    func_02017274((u32) 0x00010000u, v4, v2, 1);
}

#pragma thumb off
