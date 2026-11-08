#include "Main/Unknown/code_0204f220.h"
#include "Main/Unknown/unk_0217a000.h"

#pragma thumb on

void func_0204f220(u32 *payload, int length) {
    if ((length == 4) && (*payload == 0)) {
        data_0217aa00->mUnk_1e38 = 1;
    }
}

#pragma thumb off
