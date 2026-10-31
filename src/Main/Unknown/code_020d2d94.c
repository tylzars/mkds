#include "Main/Unknown/code_020d2d94.h"

#pragma thumb on

void func_020d2d94(void) {
    int v1;
    int *v2;
    u32 *v3;
    int *v4;
    v2 = (int *) ((int) data_0217b4f0 + 8);
    v4 = (int *) ((int) data_0217b4f0 + 0x134);
    v1 = 0;
    do {
        if (*v2 != 0) {
            v3 = *(u32 **) (*v2 + 0x28);
            if (v3 != (u32 *) 0x0) {
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
            v3 = *(u32 **) (*v4 + 0x24);
            if (v3 != (u32 *) 0x0) {
                *v3 = 0;
            }
            *v4 = 0;
        }
        v4 = v4 + 1;
        v1 = v1 + 1;
    } while (v1 < 0x10);
}

#pragma thumb off
