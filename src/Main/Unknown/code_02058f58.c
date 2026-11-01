#include "Main/Unknown/code_02058f58.h"
#include "Main/Unknown/code_0210e33c.h"

#pragma thumb on

void func_02058f7c(void) {
    data_0217aa00->mUnk_1e34 = 0;
    data_0217aa00->mUnk_1e44 &= ~2;
    data_0217aa00->mUnk_164f = 0;
}

void func_02058f58(void) {
    if (func_0210e524() == 0) {
        data_0217aa00->mUnk_164f = 1;
    }
}

#pragma thumb off
