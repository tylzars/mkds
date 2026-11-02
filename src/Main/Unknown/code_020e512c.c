#include "Main/Unknown/code_020e512c.h"

#pragma thumb on

u32 func_020e512c(Vec3 *a) {
    u32 v1[1];
    v1[0] = 0;
    func_01ffdee4((int *) ((int *) (u32) a), (u32 *) 0, (u32) 0, (int) (((u32) 0x0000a000u)), (u32) 8,
                  (short) 0xfffffffe, (int *) 0, (int *) 0, (int *) 0, (u32 *) v1, (u32 *) 0, (int *) 0, (u16 *) 0,
                  (u32 *) 0);
    return v1[0] & ((u32) 0x01000000u);
}

#pragma thumb off
