#include "Main/Unknown/code_020d2d94.h"
#include "Main/Unknown/code_020d2000.h"

#pragma thumb on

void func_020d2d94(void) {
    int v1;
    Unk020e6fd4 **v2;
    void **v3;
    Unk020e6fd4 **v4;
    v2 = data_0217b4f0->mUnk_008;
    v4 = data_0217b4f0->mUnk_134;
    v1 = 0;
    do {
        if (*v2 != 0) {
            v3 = *(void ***) ((int) *v2 + 0x28);
            if (v3 != 0) {
                *v3 = 0;
            }
            *v2 = 0;
        }
        v2 = v2 + 1;
        v1 = v1 + 1;
    } while (v1 < 0x18);
    v1 = 0;
    do {
        if (*v4 != 0) {
            v3 = (*v4)->mUnk_24;
            if (v3 != 0) {
                *v3 = 0;
            }
            *v4 = 0;
        }
        v4 = v4 + 1;
        v1 = v1 + 1;
    } while (v1 < 0x10);
}

#pragma thumb off
