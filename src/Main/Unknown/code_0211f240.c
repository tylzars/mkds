#include "Main/Unknown/code_0211f240.h"

#pragma thumb on

void func_0211f244(int param_1, int param_2, void *param_3, void *param_4, u32 param_5, u16 param_6, int param_7) {
    u32 v1;
    u32 *v2;
    v1 = 0xe;
    if ((param_7 != 0) && (param_7 == 1)) {
        v1 = 0x1e;
    }
    v2 = (u32 *) (int) data_0217d37c;
    func_02124748((u32) (*(u16 *) (((u32) ((u8 *) &data_0215d014)) + param_1 * 2)), (void *) (v2[1]), (void *) (*v2), (void *) (v2[3]), param_7, param_5, param_3, param_4);
    ((u32) func_02016468(v1, (u32) ((u32) param_6 << 5),
                         (void *) (*(int *) ((int) data_0217d37c->mUnk_08 + 0xc) +
                                   (u32) ((u16 *) &data_0215d00c)[param_2] * 0x20),
                         (u32) 0x20));
}

void func_0211f240(void) {
}

#pragma thumb off
