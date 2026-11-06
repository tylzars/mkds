#include "Main/Unknown/code_020e512c.h"
#include "ITCM/code_01ffdee4.h"

#pragma thumb on

u32 func_020e512c(Vec3 *a) {
    u32 v1[1];
    v1[0] = 0;
    func_01ffdee4(((s32 *) a), NULL, 0, 0x0000a000u, 8, 0xfffffffe, NULL, NULL, NULL, v1, NULL, NULL, NULL, NULL);
    return v1[0] & (0x01000000u);
}

#pragma thumb off
