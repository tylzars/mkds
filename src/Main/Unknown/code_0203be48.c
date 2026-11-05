#include "Main/Unknown/code_0203be48.h"
#include "Main/Unknown/code_0203be88.h"

#pragma thumb on

void func_0203be6c(u8 *a, u32 b, u32 c, u32 d) {
    func_0203bea4(a, b, c);
    func_0203be88(a, b, d);
}

void func_0203be48(u8 *a, u8 b, u32 *c, u32 *d) {
    if (c != NULL) {
        *c = *(u32 *) (a + b * 4 + 4);
    }
    if (d != NULL) {
        *d = *(u32 *) (a + b * 4 + 0x24);
    }
}

#pragma thumb off
