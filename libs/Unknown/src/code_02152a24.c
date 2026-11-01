#include "code_02152a24.h"
#include "Main/Unknown/code_02152a6c.h"

#pragma thumb on

u32 func_02152a58(const Unk02152490 *a) {
    return func_02152a6c(a) & 3;
}

s32 func_02152a24(const void *a) {
    const Unk02152490 *p = a;

    if (func_02152a58(p) == 3) {
        if ((func_02152a6c(p) & 4) == 4) {
            return 1;
        }
        return 0;
    }
    return 0;
}

#pragma thumb off
