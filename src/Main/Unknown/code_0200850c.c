#include "Main/Unknown/code_0200850c.h"

#pragma thumb on

void func_0200850c(u32 *param_1, u32 param_2, u32 param_3, int param_4) {
    u32 v1;
    if (param_2 < ((u32) 0x00004000u)) {
        param_2 = ((u32) 0x00004000u);
    }
    if (((u32) 0x00008000u) < param_3) {
        param_3 = ((u32) 0x00008000u);
    }
    v1 = *param_1;
    if (param_2 < v1) {
        param_2 = v1;
    }
    if (param_3 > v1 + param_1[3]) {
        param_3 = v1 + param_1[3];
    }
    if (param_2 < param_3) {
        if (param_4 != 0) {
            func_0214d168((void *) ((u32 *) (u32) (param_1[2] + param_2)), (u8) 0, (u32) (param_3 - param_2));
            return;
        }
        func_0214d1fc((const void *) ((u16 *) (u32) (param_1[1] + param_2)),
                      (void *) ((u32 *) (u32) (param_1[2] + param_2)), (u32) (param_3 - param_2));
    }
}

#pragma thumb off
