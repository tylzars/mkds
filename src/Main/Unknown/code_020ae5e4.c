#include "Main/Unknown/code_020ae5e4.h"

#pragma thumb on

void func_020ae5f0(void *param_1, void *param_2) {
    if (param_1 != 0) {
        func_0200ee74((param_1), (int) 0x00000400u);
        func_0214bfcc((const void *) param_1, 0, (u32) 0x00000400u);
    }
    if (param_2 != 0) {
        func_0200ee74((param_2), (int) 0x00000400u);
        func_0214bf64((const void *) param_2, 0, (u32) 0x00000400u);
    }
}

u16 func_020ae5e4(u32 p0) {
    return ((u32) * (const u16 *) ((u8 *) p0 + 0 + (0x402u)));
}

#pragma thumb off
