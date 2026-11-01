#include "Main/Unknown/code_02126ea8.h"

#pragma thumb on

void func_02126ef8(void) {
    int v1;
    v1 = *(int *) &data_0217d3f0;
    if (0 < *(int *) (v1 + 0x28)) {
        ((u32) func_02016468((u32) 0x1f, (u32) ((0xee - *(int *) (v1 + 0x2c)) * 2),
                             (void *) (v1 + 0x2246), (u32) 2));
        ((u32) func_02016468((u32) 0x1f, (u32) ((0xfe - data_0217d3f0->mUnk_2c) * 2),
                             (void *) &data_0217d3f0->mUnk_2246, (u32) 2));
        v1 = *(int *) &data_0217d3f0;
        if (*(int *) (v1 + 0x28) == 2) {
            ((u32) func_02016468((u32) 0x1f, (u32) ((*(int *) (v1 + 0x2c) + 0xed) * 2),
                                 (void *) (v1 + 0x2244), (u32) 2));
            ((u32) func_02016468((u32) 0x1f, (u32) ((data_0217d3f0->mUnk_2c + 0xfd) * 2),
                                 (void *) &data_0217d3f0->mUnk_2244, (u32) 2));
        }
    }
}

void func_02126ea8(void) {
    int v1;
    int v2;
    v1 = 0x2244;
    if (0 < data_0217d3f0->mUnk_28) {
        v2 = 0;
        do {
            ((u32) func_02016468((u32) 0x1f, (u32) ((v2 + 0xed) * 2), (void *) (*(int *) &data_0217d3f0 + v1),
                                 (u32) 2));
            ((u32) func_02016468((u32) 0x1f, (u32) ((v2 + 0xfd) * 2), (void *) (*(int *) &data_0217d3f0 + v1),
                                 (u32) 2));
            v2 = v2 + 1;
        } while (v2 < 2);
    }
}

#pragma thumb off
