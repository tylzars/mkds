#include "Main/Unknown/code_02028e38.h"

#pragma thumb on

void func_02028e38(void) {
    int v1;
    Unk02174e14_00 *v3;
    short *v2;
    v1 = func_020280dc();
    if (v1 == 0) {
        v2 = (short *) func_02078b04((int) data_02174e18->mUnk_0a8, (int) data_02174e18->mUnk_0a4);
        v3 = (Unk02174e14_00 *) &data_02174e18->mUnk_064;
        func_02028ec0(10, (u32) 0x10, (int) ((int) *v2), v3);
        func_02028ec0(9, (u32) 0xf, (int) ((int) v2[1]), v3);
        func_02028ec0(8, (u32) 0xe, (int) ((int) v2[2]), v3);
        func_02028ec0(7, (u32) 0xd, (int) ((int) v2[3]), v3);
        func_02028ec0(6, (u32) 0xc, (int) ((int) v2[4]), v3);
        func_02028ec0(5, (u32) 0xb, (int) ((int) v2[5]), v3);
    }
}

#pragma thumb off
