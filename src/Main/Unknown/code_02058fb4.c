#include "Main/Unknown/code_02058fb4.h"

#pragma thumb on

void func_02059034(void) {
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

void func_02059008(void) {
    int v1;
    Unk0217aa00_1608 *v2;
    v1 = func_0205910c();
    if (v1 == 1) {
        v2 = &data_0217aa00->mUnk_1608;
        v2->mUnk_10 = 0x14;
        v2->mUnk_12 = 1;
    }
}

void func_02058fe0(void) {
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

void func_02058fb4(void) {
    int v1;
    Unk0217aa00_1608 *v2;
    v1 = func_0205905c();
    if (v1 == 1) {
        v2 = &data_0217aa00->mUnk_1608;
        v2->mUnk_10 = 0x13;
        v2->mUnk_12 = 1;
    }
}

#pragma thumb off
