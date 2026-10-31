#include "Main/Unknown/code_0202f14c.h"

#pragma thumb on

void func_0202f160(void) {
    int v1;
    v1 = func_0202f19c();
    if (v1 == 0) {
        func_021258f0();
    }
    (**(UnkFunc **) ((int) data_02174e4c->mUnk_80c + 0xc))();
    func_020ae5f0((void *) data_02174e4c, (void *) ((int) data_02174e4c + 0x404));
}

Unk02174e4c_818 *func_0202f14c(void) {
    return &data_02174e4c->mUnk_818;
}

#pragma thumb off
