#include "Main/Unknown/code_02059304.h"
#include "Main/Unknown/code_0210e33c.h"
#include "Main/Unknown/code_02043000.h"

#pragma thumb on

void func_0205933c(void) {
    u32 a;

    a = func_0210e5e4((u32) data_0217aa00->mUnk_1654, (u32) data_0217aa00->mUnk_1650);
    if (*(u16 *) 0x027ffc40 == 2) {
        func_02043f28(0);
    }
    if (a == 0) {
        data_0217aa00->mUnk_164f = 1;
    }
}

void func_02059304(void) {
    data_0217aa00->mUnk_1e34 = 0;
    data_0217aa00->mUnk_1e44 &= ~2;
    data_0217aa00->mUnk_164f = 0;
}

#pragma thumb off
