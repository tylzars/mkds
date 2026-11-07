#include "Main/Unknown/code_0200850c.h"
#include "code_0214d018.h"

#pragma thumb on

void CopyOrClearRange(u32 *a, u32 b, u32 c, int d) {
    u32 rangeStart;
    if (b < (0x00004000u)) {
        b = (0x00004000u);
    }
    if ((0x00008000u) < c) {
        c = (0x00008000u);
    }
    rangeStart = *a;
    if (b < rangeStart) {
        b = rangeStart;
    }
    if (c > rangeStart + a[3]) {
        c = rangeStart + a[3];
    }
    if (b < c) {
        if (d != 0) {
            MI_CpuFill8(((u32 *) (u32) (a[2] + b)), 0, c - b);
            return;
        }
        MI_CpuCopy8(((u16 *) (u32) (a[1] + b)), ((u32 *) (u32) (a[2] + b)), c - b);
    }
}

#pragma thumb off
