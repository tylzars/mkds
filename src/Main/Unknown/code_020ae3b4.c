#include "Main/Unknown/code_020ae3b4.h"

#include "Main/Unknown/code_02045874.h"
#include "Main/Unknown/code_020ae3d8.h"
#include "Main/Unknown/code_020ae408.h"

#pragma thumb on

u16 func_020ae408(u32 a, u32 b) {
    int v1;
    int v2;
    v1 = func_020ae458(a, b);
    v2 = func_020ae428(a, b);
    return v1 | v2;
}

#pragma thumb off

u32 func_020ae3f4(void) {
    return ((u32) data_021759d0->mUnk_20);
}

u32 func_020ae3d8(void) {
    return ((u32) &data_0217aa00->mUnk_1ee8);
}

#pragma thumb on

u32 func_020ae3b4(u32 a) {
    int v1;
    u32 v2;
    v1 = func_020ae3f4();
    if (v1 == 0) {
        v2 = (u32) func_0204aa60();
    } else {
        v2 = func_020ae3d8();
    }
    return func_02046524((Unk020f41c4_B *) v2, a);
}

#pragma thumb off
