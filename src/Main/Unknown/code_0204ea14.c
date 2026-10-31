#include "Main/Unknown/code_0204ea14.h"

#pragma thumb on

u32 func_0204ea3c(void) {
    u32 v1;
    int v2;
    u32 v3;
    v3 = 0;
    v1 = func_02008880(0);
    if (((u32) 0x00010000u) <= v1) {
        v2 = func_02008570((u8 *) 0, (int) (*(u32 *) ((int) data_0217aa00 + 0x1658)),
                              (u32) (*(u32 *) ((int) data_0217aa00 + 0x168c)));
        if ((v2 != 0) && (v2 = func_02008310(data_0215472c,
                                                   (Unk02008188 *) (*(u32 *) ((int) data_0217aa00 + 0x1658))),
                             v2 != 0)) {
            v3 = 1;
        }
    }
    return v3;
}

void func_0204ea14(u32 param_1) {
    int v1;
    u32 v2;
    u32 v3;
    v2 = ((int) func_020b3f7c((void *) param_1, 0));
    v3 = ((int) func_020b3f7c((void *) param_1, 1));
    v1 = ((int) (u32) ((u8 *) &data_0215472c));
    *(u32 *) (((int) (u32) ((u8 *) &data_0215472c)) + 4) = v2;
    *(u32 *) (v1 + 8) = v3;
}

#pragma thumb off
