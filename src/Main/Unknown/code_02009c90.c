#include "Main/Unknown/code_02009c90.h"
#include "Main/Unknown/code_02009000.h"
#include "code_02142eac.h"
#include "Main/Unknown/unk_0216f000.h"

#pragma thumb on

int func_02009c98(void) {
    int v1;
    v1 = func_02143dd0(data_0216fda8->mUnk_508);
    func_02009928((u16) 1, v1);
    if (v1 == 2) {
        v1 = 0;
    }
    return v1;
}

#pragma thumb off

#pragma thumb on
u32 func_02009c90(void) {
    u32 value0;
    u32 value3;
    value3 = (u32) &func_02009c98;
    value0 = (u32) func_02009c98();
    return value0;
}
#pragma thumb off
