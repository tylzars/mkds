#include "Main/Unknown/code_02036438.h"
#include "Main/Unknown/code_02035db4.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020d1640.h"

#pragma thumb on

void func_02036438(void *heap) {
    void *v1;
    int v2;
    Unk020b4934 *v3;
    Unk020b4a44 *v4;
    v1 = func_02036948(heap);
    v2 = ((u32) func_02036bec(v1, (u32) (((u32) 0x00000654u))));
    *(int *) &data_02174e6c = v2;
    func_02036264((void *) v2, (u32) (((u32) 0x00000654u)));
    data_02174e6c->mUnk_650 = v1;
    func_020364a8(0, 0, 0x10, 0, 0);
    v3 = func_020d1630()->mUnk_24;
    v4 = func_020d1630()->mUnk_28;
    func_0214b9c4(v3->mUnk_14, 0, v3->mUnk_10);
    func_0214b824(v3->mUnk_14, 0, v3->mUnk_10);
    func_0214c0f8(v4->mUnk_0c, 0, v4->mUnk_08);
}

#pragma thumb off
