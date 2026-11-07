#include "Main/Unknown/code_02056c6c.h"
#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_02056cac.h"
#include "Main/Unknown/unk_0217a000.h"

#pragma thumb on

void func_02056c6c(u32 a, int b, TimeRecord *c) {
    int v1;
    v1 = func_0204684c(a);
    if (v1 != -1) {
        func_02056cac(&data_0217aa08->mUnk_0c->mUnk_004[b][v1], c);
    }
}

#pragma thumb off
