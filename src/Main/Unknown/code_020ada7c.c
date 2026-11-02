#include "Main/Unknown/code_020ada7c.h"

#include "Main/Unknown/code_020ada94.h"

#pragma thumb on

void func_020ada94(void) {
    data_0217b340->mUnk_14[data_0217b340->mUnk_0c].mUnk_00();
    data_0217b340->mUnk_04 = 0;
    func_021258f0();
    func_020ae5f0((void *) &data_0217b340->mUnk_b0, (void *) &data_0217b340->mUnk_4b4);
}

#pragma thumb off

void func_020ada7c(int *a) {
    u32 v1;
    v1 = *(u32 *) a;
    if ((s32) v1 < 0x7fffffff) {
        *a = v1 + 1;
    }
}
