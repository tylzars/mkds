#include "Main/Unknown/code_0202b888.h"

#pragma thumb on

u32 func_0202b8c0(void) {
    if (data_02174e3c->mUnk_040 == 0) {
        return 1;
    }
    return 0;
}

u32 func_0202b888(void) {
    u32 v1;
    int v2;
    int v3;
    int v4;
    v1 = 1;
    v2 = 0;
    if (0 < data_02174e3c->mUnk_048) {
        v3 = 0;
        do {
            v4 = ((u32) func_02029930());
            v1 = v1 & *(u32 *) (v4 + v3 + 0x14);
            v3 = v3 + 0x18;
            v2 = v2 + 1;
        } while (v2 < *(int *) (*(int *) &data_02174e3c + 0x48));
    }
    return v1;
}

#pragma thumb off
