#include "Main/Unknown/code_02078f9c.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020846c0.h"
#include "Main/Unknown/code_0207a000.h"
#include "Main/Unknown/code_02078580.h"

#pragma thumb on

void *func_02079008(void *a, void *b) {
    return func_0207afa8(a, b, 3);
}

void func_02078f9c(void *param_1) {
    void *a;
    void *b;
    func_0207913c(param_1, data_usa_02165760, &a);
    func_0207913c(param_1, data_usa_0216577c, &b);
    data_0217ad08->mUnk_1cc = func_02036bec(param_1, 0x6c);
    func_02084d3c(data_0217ad08->mUnk_1cc, a, b);
    func_020849c0(data_0217ad08->mUnk_1cc, 2);
    func_02012ffc(data_0217ad08->mUnk_1cc->mUnk_04, 1);
}

#pragma thumb off
