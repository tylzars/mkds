#include "Main/Unknown/code_0200850c.h"
#include "code_0214d018.h"

#pragma thumb on

void func_0200850c(u32 *a, u32 b, u32 c, int d) {
    u32 v1;
    if (b < ((u32) 0x00004000u)) {
        b = ((u32) 0x00004000u);
    }
    if (((u32) 0x00008000u) < c) {
        c = ((u32) 0x00008000u);
    }
    v1 = *a;
    if (b < v1) {
        b = v1;
    }
    if (c > v1 + a[3]) {
        c = v1 + a[3];
    }
    if (b < c) {
        if (d != 0) {
            func_0214d168((void *) ((u32 *) (u32) (a[2] + b)), (u8) 0, (u32) (c - b));
            return;
        }
        func_0214d1fc((const void *) ((u16 *) (u32) (a[1] + b)), (void *) ((u32 *) (u32) (a[2] + b)), (u32) (c - b));
    }
}

#pragma thumb off
