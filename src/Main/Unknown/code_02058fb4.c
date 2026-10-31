#include "Main/Unknown/code_02058fb4.h"

#pragma thumb on

void func_02059034(void) {
    int v1;
    if ((int *) (int) data_0217aa00 == (int *) 0x0) {
        v1 = 0;
    } else {
        v1 = *(int *) (int) data_0217aa00;
    }
    if (v1 == 1) {
        func_020518c8((u32) 0);
    }
}

void func_02059008(void) {
    int v1;
    v1 = func_0205910c();
    if (v1 == 1) {
        v1 = (int) data_0217aa00 + 0x1608;
        *(u16 *) (v1 + 0x10) = 0x14;
        *(u16 *) (v1 + 0x12) = 1;
    }
}

void func_02058fe0(void) {
    int v1;
    if ((int *) (int) data_0217aa00 == (int *) 0x0) {
        v1 = 0;
    } else {
        v1 = *(int *) (int) data_0217aa00;
    }
    if (v1 == 1) {
        func_020518c8((u32) 0);
    }
}

void func_02058fb4(void) {
    int v1;
    v1 = func_0205905c();
    if (v1 == 1) {
        v1 = (int) data_0217aa00 + 0x1608;
        *(u16 *) (v1 + 0x10) = 0x13;
        *(u16 *) (v1 + 0x12) = 1;
    }
}

#pragma thumb off
