#include "Main/Unknown/code_0205928c.h"

#pragma thumb on

void func_020592d4(void) {
    int v1;
    v1 = func_02058dc0(func_0205933c);
    if (v1 == 1) {
        v1 = (int) data_0217aa00 + 0x1608;
        *(u16 *) (v1 + 0x10) = 0x14;
        *(u16 *) (v1 + 0x12) = 1;
    }
}

void func_020592ac(void) {
    int v1;
    if ((int *) (int) data_0217aa00 == (int *) 0x0) {
        v1 = 0;
    } else {
        v1 = *(int *) (int) data_0217aa00;
    }
    if (v1 == 1) {
        func_020518c8((u32) 1);
    }
}

void func_0205928c(void) {
    int v1;
    if (*(int *) ((int) data_0217aa00 + 0x10) == 0) {
        v1 = (int) data_0217aa00 + 0x1608;
        *(u16 *) (v1 + 0x10) = 0xf;
        *(u16 *) (v1 + 0x12) = 1;
    }
}

#pragma thumb off
