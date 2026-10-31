#include "Main/Unknown/code_020ce8d0.h"

#pragma thumb on

void func_020ce8d0(void) {
    int v1;
    v1 = func_020cccc0();
    if (v1 != 0) {
        v1 = func_020ce778();
        if (v1 == 0) {
            func_020ce760(0x19);
            func_02148950((u16) 1, (u32) 0, 0);
            func_020ce744(0x16);
            func_02148934((u32) 0);
        } else {
            func_020ce760(0x18);
            func_02148950((u16) 1, (u32) 0, 0);
            func_020ce744(0x12);
            func_02148934((u32) 0);
        }
    }
    func_021173e4();
}

#pragma thumb off
