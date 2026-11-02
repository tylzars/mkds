#include "Main/Unknown/code_02057524.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02057174.h"
#include "Main/Unknown/unk_0217a000.h"

#pragma thumb on

void func_02057524(void *a) {
    data_0217aa08 = func_02036bec(a, 0x48);
    data_0217aa08->mUnk_00 = func_02036b74(a, 0x100, 0x20);
    data_0217aa08->mUnk_04 = func_02036b74(a, 0x300, 0x20);
    data_0217aa08->mUnk_08 = func_02036b74(a, 0x400, 0x20);
    data_0217aa08->mUnk_0c = func_02036b74(a, 0x1600, 0x20);
    data_0217aa08->mUnk_10 = func_02036b74(a, 0x100, 0x20);
    data_0217aa08->mUnk_14 = func_02036b74(a, 0xe00, 0x20);
    data_0217aa08->mUnk_18 = func_02036b74(a, 0x1000, 0x20);
    data_0217aa08->mUnk_1c = func_02036b74(a, 0x1000, 0x20);
    data_0217aa08->mUnk_20 = func_02036b74(a, 0xc00, 0x20);
    data_0217aa08->mUnk_24 = func_02036b74(a, 0xb00, 0x20);
    data_0217aa08->mUnk_40 = NULL;
    func_0205721c(1);
    data_0217aa08->mUnk_2a = 0;
    data_0217aa08->mUnk_2c = 0;
    data_0217aa08->mUnk_44 &= ~1;
    data_0217aa08->mUnk_28 = 0;
}

#pragma thumb off
