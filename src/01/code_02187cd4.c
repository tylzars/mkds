#include "01/code_02187cd4.h"

void func_ov001_02187cd4(int param_1, u32 param_2) {
    int *v1;
    *(u32 *) (param_1 + 0x2e4) = param_2;
    *(u32 *) (param_1 + 0x27c) = 3;
    v1 = (int *) (param_1 + 0x304);
    *(int *) (*(int *) (*v1 + 0x10) + 0x2c) = param_1;
    func_020109c4((void *) (*(u32 *) (*v1 + 0x10)), (void (*)(void *))((u32) &func_ov001_02187d14), (u32) 0,
                  (u8) 6, (u8) 3);
}
