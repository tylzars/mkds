#include "Main/Unknown/code_020d7d80.h"

#pragma thumb on

void func_020d7d80(u32 *a) {
    int *v1;
    int v2;
    int v3;
    int v4;
    int v5;
    v1 = (int *) *a;
    v3 = v1[1];
    v2 = 0;
    if (0 < v3) {
        v4 = 0;
        do {
            v5 = *v1 + v4;
            *(u32 *) (v5 + 0x30) = *(u32 *) (v5 + 0x40);
            *(u32 *) (v5 + 0x34) = *(u32 *) (v5 + 0x44);
            v4 = v4 + 0x54;
            v2 = v2 + 1;
        } while (v2 < v3);
    }
}

#pragma thumb off
