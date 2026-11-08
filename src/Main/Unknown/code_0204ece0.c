#include "Main/Unknown/code_0204ece0.h"
#include "Main/Unknown/code_02050080.h"
#include "Main/Unknown/unk_0217a000.h"

#pragma thumb on

void func_0204ece0(u16 entryIndex) {
    int result;
    result = func_020501b0(entryIndex);
    if (result != 0) {
        data_0217aa00->mUnk_1e45 = entryIndex;
    }
}

#pragma thumb off
