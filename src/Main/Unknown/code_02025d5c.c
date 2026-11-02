#include "Main/Unknown/code_02025d5c.h"

#pragma thumb on

int func_02025d74(int a) {
    int v1;
    v1 = ((int *) &data_021533fc)[a];
    if (v1 != -1) {
        v1 = v1 + -0x1a;
    }
    return v1;
}

int func_02025d5c(int a) {
    int v1;
    v1 = ((int *) &data_021533fc)[a];
    if (v1 != -1) {
        v1 = v1 + 4;
    }
    return v1;
}

#pragma thumb off
