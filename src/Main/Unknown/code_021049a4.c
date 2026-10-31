#include "Main/Unknown/code_021049a4.h"

#pragma thumb on

void func_021049a4(void) {
    int v1;
    int v2;
    int v3;
    int *v4;
    u32 v5;
    int v6;
    if (*(int *) ((int) data_0217bc48 + 0x1dc) != 0) {
        v6 = (int) data_027e00cc + 0x220;
        v4 = *(int **) (v6 + 4);
        v1 = *(int *) (v6 + 8);
        v2 = 0;
        if (0 < v1) {
            do {
                v3 = *v4;
                v5 = func_0210543c();
                *(u32 *) (v3 + 0x134) = v5;
                *(int *) (*(int *) (v3 + 0x134) + 0xfc) = v3 + 0x13c;
                v4 = v4 + 1;
                v2 = v2 + 1;
            } while (v2 < v1);
        }
        *(u32 *) (v6 + 0x40) = 1;
    }
}

#pragma thumb off
