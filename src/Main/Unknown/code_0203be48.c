#include "Main/Unknown/code_0203be48.h"

#pragma thumb on

void func_0203be6c(u8 *a, u32 b, u32 c, u32 d) {
    func_0203bea4(a, b, c);
    func_0203be88((u8 *) ((u8 *) (u32) a), b, d);
}

void func_0203be48(u8 *a, u8 b, u32 *c, u32 *d) {
    if (c != (u32 *) 0x0) {
        *c = *(u32 *) (a + b * 4 + 4);
    }
    if (d != (u32 *) 0x0) {
        *d = *(u32 *) (a + b * 4 + 0x24);
    }
}

#pragma thumb off
