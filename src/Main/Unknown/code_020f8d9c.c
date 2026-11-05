#include "Main/Unknown/code_020f8d9c.h"
#include "Main/Unknown/code_020e0650.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_02109054.h"
#include "Main/Unknown/code_02109110.h"

#pragma thumb on

void func_020f8d9c(Unk020f41c4_A *a, u32 b, int c) {
    a->mUnk_48 = b;
    func_020e0650((u32 *) &a->mUnk_104);
    func_02109110(&a->mUnk_00, data_0217bc34[c].mUnk_a0, &a->mUnk_50);
    func_02109054(&a->mUnk_00);
}

#pragma thumb off
