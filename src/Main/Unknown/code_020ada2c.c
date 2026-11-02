#include "Main/Unknown/code_020ada2c.h"
#include "Main/Unknown/code_020ada7c.h"
#include "Main/Unknown/code_021258f0.h"
#include "Main/Unknown/unk_0217b000.h"

#pragma optimize_for_size on
#pragma thumb on

void func_020ada2c(s32 a) {
    enum { K0 } i;
    func_020ae6ac(&data_0217b340->mUnk_b0, &data_0217b340->mUnk_4b4);
    i = data_0217b340->mUnk_0c;
    data_0217b340->mUnk_14[i].mUnk_04(a);
    func_020ada7c((s32 *) data_0217b340);
    func_02125928();
    func_020ae630(&data_0217b340->mUnk_b0, &data_0217b340->mUnk_4b4);
}

#pragma thumb off
