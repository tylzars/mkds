#include "Main/Unknown/code_0205928c.h"

#pragma thumb on

void func_020592d4(void) {
    int v1;
    Unk0217aa00_1608 *v2;
    v1 = func_02058dc0(func_0205933c);
    if (v1 == 1) {
        v2 = &data_0217aa00->mUnk_1608;
        v2->mUnk_10 = 0x14;
        v2->mUnk_12 = 1;
    }
}

void func_020592ac(void) {
    int v1;
    if (data_0217aa00 == 0) {
        v1 = 0;
    } else {
        v1 = data_0217aa00->mUnk_0000;
    }
    if (v1 == 1) {
        func_020518c8((u32) 1);
    }
}

void func_0205928c(void) {
    Unk0217aa00_1608 *v1;
    if (data_0217aa00->mUnk_0010 == 0) {
        v1 = &data_0217aa00->mUnk_1608;
        v1->mUnk_10 = 0xf;
        v1->mUnk_12 = 1;
    }
}

#pragma thumb off
