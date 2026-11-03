#include "Main/Unknown/code_0200b7e0.h"
#include "Main/Unknown/code_0200b9e0.h"
#include "Main/Unknown/unk_0216f000.h"

#pragma thumb on

void func_0200b9e0(UnkFunc *a, u32 b) {
    data_0216fde8->mUnk_05dc = a;
    data_0216fde8->mUnk_05e4 = b;
    data_0216fde8->mUnk_0580.mUnk_04 = 0;
    data_0216fde8->mUnk_0580.mUnk_00 = data_0216fde8->mUnk_04c0;
    data_0216fde8->mUnk_5ef8 = 1;
    data_0216fde8->mUnk_5f00 = 0;
    data_0216fde8->mUnk_05ee = 0;
    func_0200b934();
}

#pragma thumb off
