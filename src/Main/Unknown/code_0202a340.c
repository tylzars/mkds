#include "Main/Unknown/code_0202a340.h"

#pragma thumb on

void func_0202a340(s16 *param_1, int param_2) {
    int v1;
    v1 = (int) data_0217b488 + 0x98 + param_2 * 4;
    func_02025cd0((short *) ((short *) (u32) param_1), (u32) (*(u8 *) (v1 + 2)), (u32) (*(u8 *) (v1 + 3)),
                  (u32) (*(u16 *) ((int) data_0217b488 + 0x98 + param_2 * 4)));
}

#pragma thumb off
