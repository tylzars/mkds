#include "Main/Unknown/code_020d2450.h"

void func_020d2450(void *a) {
    int v1;
    u8 v2[12];
    u8 v3[20];
    v1 = func_01ffdee4((int *) ((int *) ((u32) a + 4)), NULL, (u32) 0, 0xa000, (u32) 8, (short) 0xfffffffe, NULL,
                       (int *) ((int *) (void *) v2), NULL, NULL, NULL, NULL, NULL, NULL);
    if (v1 != 0) {
        func_020d7b88((Vec3 *) v2, (u32 *) ((u32 *) (void *) v3));
        func_01ffccd0((int *) ((int *) ((u32) a + 0x28)), (void *) v3);
        return;
    }
}
