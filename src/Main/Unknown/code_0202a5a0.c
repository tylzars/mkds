#include "Main/Unknown/code_0202a5a0.h"

#pragma thumb on

void func_0202a604(u32 param_1) {
    int v1;
    v1 = func_02049b6c();
    if (v1 == 0) {
        func_020ae6ac((void *) data_02174e24, (void *) ((int) data_02174e24 + 0x404));
        if (data_02174e24->mUnk_808 == 0) {
            func_02029aa0((Unk02029aa0 *) param_1);
        } else {
            func_02032ac4((Unk02032ac4 *) param_1);
        }
        func_020ae630((void *) data_02174e24, (void *) ((int) data_02174e24 + 0x404));
        func_0212a920();
    }
}

void func_0202a5d8(void) {
    if (data_02174e24->mUnk_808 == 0) {
        func_02029a98();
    } else {
        func_02032ab0();
    }
    func_0212abd0();
}

void func_0202a5a0(void) {
    if (data_02174e24->mUnk_808 == 0) {
        func_02029a90();
    } else {
        func_02032aa8();
    }
    func_020ae5f0((void *) data_02174e24, (void *) ((int) data_02174e24 + 0x404));
}

#pragma thumb off
