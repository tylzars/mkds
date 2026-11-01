#include "Main/Unknown/code_02031208.h"

#pragma thumb on

u32 func_02031268(void) {
    if (*(int *) ((int) data_02174e58 + 0xc0) == 1) {
        return 1;
    }
    return 0;
}

u32 func_02031250(void) {
    if (*(int *) ((int) data_02174e58 + 0xc0) == 3) {
        return 1;
    }
    return 0;
}

void func_02031208(void) {
    int v1;
    int v2;
    int v3;
    int v4;
    int *v5;
    v5 = (int *) &data_02174e58;
    if (*(int *) (0x94 + (int) data_02174e58) != 6) {
        v1 = 0;
        v2 = 0;
        v3 = 0;
        do {
            v4 = *v5 + 0x24 + v2;
            func_02124c30((void *) (*(u32 *) (v4 + 0xc)), (void *) (*(u32 *) (v4 + 8)), (void *) (*(u32 *) (v4 + 0x14)),
                          (void *) (*(u32 *) (*v5 + v3 + 0x5c)), (void *) (*(u32 *) (v4 + 0x18)));
            v2 = v2 + 0x1c;
            v3 = v3 + 4;
            v1 = v1 + 1;
        } while (v1 < 2);
    }
}

#pragma thumb off
