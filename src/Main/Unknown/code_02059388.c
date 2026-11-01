#include "Main/Unknown/code_02059388.h"

#pragma thumb on

void func_020593b4(void) {
    int v1;
    if (data_0217aa00 == 0) {
        v1 = 0;
    } else {
        v1 = data_0217aa00->mUnk_0000;
    }
    if (v1 == 1) {
        func_020518c8((u32) 0);
    }
}

void func_02059388(void) {
    int v1;
    Unk0217aa00_1608 *v2;
    v1 = func_020593dc();
    if (v1 == 1) {
        v2 = &data_0217aa00->mUnk_1608;
        v2->mUnk_10 = 0x11;
        v2->mUnk_12 = 1;
    }
}

#pragma thumb off
