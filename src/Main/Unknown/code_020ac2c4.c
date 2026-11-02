#include "Main/Unknown/code_020ac2c4.h"

#pragma thumb on

#include "Main/Unknown/code_020ac2c4.h"

#pragma thumb on

void func_020ac2c4(const u8 *a, u8 *b, int c) {
    int i;
    int n = c * c / 2;
    for (i = 0; i < n; i++) {
        b[i] = a[i * 2] | (a[i * 2 + 1] << 4);
    }
}

#pragma thumb off

#pragma thumb off
