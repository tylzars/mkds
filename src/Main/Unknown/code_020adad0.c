#include "Main/Unknown/code_020adad0.h"
#include "Main/Unknown/unk_0217b000.h"

#pragma optimize_for_size on
#pragma thumb on

void func_020adad0(u32 a, u32 b) {
    data_0217b340->mUnk_00 = 0;
    data_0217b340->mUnk_04 = TRUE;
    data_0217b340->mUnk_08 = data_0217b340->mUnk_0c;
    data_0217b340->mUnk_0c = a;
    data_0217b340->mUnk_10 = b;
}

#pragma thumb off
