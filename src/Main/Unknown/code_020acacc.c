#include "Main/Unknown/code_020acacc.h"
#include "Main/Unknown/code_020acaa4.h"
#include "Main/Unknown/code_020acff4.h"
#include "Main/Unknown/code_020adaf8.h"
#include "Main/Unknown/code_020ae428.h"
#include "Main/Unknown/unk_0217b000.h"

#pragma thumb on

void func_020acad0(void) {
    s32 n;

    n = func_020adaf8();
    data_0217b340->mUnk_60 = func_020ae488(n);
    if (n >= 10) {
        func_020adad0(3, 5);
    }
    func_020acff4();
}

void func_020acacc(void) {}

#pragma thumb off
