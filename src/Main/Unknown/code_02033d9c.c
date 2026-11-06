#include "Main/Unknown/code_02033d9c.h"
#include "Main/Unknown/code_021277ac.h"
#include "Main/Unknown/unk_02174000.h"

#pragma thumb on

void func_02033d9c(void) {
    void *v1;
    void *v2;
    v1 = GetBmgEntry(data_02174e60->mUnk_0c8, 0x5d);
    v2 = GetBmgEntry(data_02174e60->mUnk_0c8, 0x5f);
    StartSelectChoises(v1, v2, 0);
}

#pragma thumb off
