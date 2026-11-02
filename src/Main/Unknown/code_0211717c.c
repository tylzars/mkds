#include "Main/Unknown/code_0211717c.h"

#pragma thumb on

void func_0211717c(void *a) {
    u32 v1;
    v1 = ((u32) func_02036bec(a, (u32) 4));
    *(u32 *) &data_0217d358 = v1;
    v1 = (u32) func_0203bedc(a);
    *(u32 *) (*(u32 *) &data_0217d358) = v1;
}

#pragma thumb off
