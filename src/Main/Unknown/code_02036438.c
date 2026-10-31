#include "Main/Unknown/code_02036438.h"

#pragma thumb on

void func_02036438(void *heap) {
    u32 v1;
    int v2;
    int v3;
    v1 = (u32) func_02036948(heap);
    v2 = ((u32) func_02036bec((void *) v1, (u32) (((u32) 0x00000654u))));
    *(int *) &data_02174e6c = v2;
    func_02036264((void *) v2, (u32) (((u32) 0x00000654u)));
    *(u32 *) ((int) data_02174e6c + 0x650) = v1;
    func_020364a8(0, 0, 0x10, 0, 0);
    v2 = ((u32) func_020d1630());
    v3 = *(int *) (v2 + 0x24);
    v2 = ((u32) func_020d1630());
    v2 = *(int *) (v2 + 0x28);
    func_0214b9c4((const void *) (*(u32 *) (v3 + 0x14)), 0, (u32) (*(u32 *) (v3 + 0x10)));
    func_0214b824((const void *) (*(u32 *) (v3 + 0x14)), 0, (u32) (*(u32 *) (v3 + 0x10)));
    func_0214c0f8((const void *) (*(u32 *) (v2 + 0xc)), 0, (u32) (*(u32 *) (v2 + 8)));
}

#pragma thumb off
