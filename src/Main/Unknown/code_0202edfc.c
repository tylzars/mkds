#include "Main/Unknown/code_0202edfc.h"
#include "Main/Unknown/unk_02174000.h"

#pragma thumb on

u32 func_0202ee20(u32 p0, u32 p1) {
    return (((data_02174e48->mUnk_008[p1].mUnk_0e)) - ((data_02174e48->mUnk_008[p0].mUnk_0e)));
}

u32 func_0202edfc(void) {
    u32 v1;
    v1 = (data_02174e48->mUnk_03c + data_02174e48->mUnk_044 + 1) % (7);
    return v1;
}

#pragma thumb off
