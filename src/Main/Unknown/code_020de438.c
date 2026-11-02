#include "Main/Unknown/code_020de438.h"

#include "Main/Unknown/code_020de488.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_020ec1fc.h"
#include "Main/Unknown/code_020de4d4.h"
#include "Main/Unknown/code_020de4e4.h"

void func_020de4e4(u32 param_1, Unk020e43a8 *param_2, u32 param_3, u16 param_4) {
    Unk02012f58 *v1;
    if (param_2->mUnk_00.mUnk_80.mUnk_0e == 0) {
        v1 = func_020e6cbc(&param_2->mUnk_00.mUnk_04);
        func_020e67c4(data_0217b6f0, v1, &param_2->mUnk_00.mUnk_1c, 0, param_4);
        return;
    }
    func_020e6a18(data_0217b6f4);
    v1 = func_020e6cbc(&param_2->mUnk_00.mUnk_04);
    func_020e66e4(data_0217b6f4, v1, *(u16 *) &param_2->mUnk_a0.mUnk_0c.x, &param_2->mUnk_00.mUnk_1c, 0, param_4);
    func_020e6a18(data_0217b6f0);
}

void func_020de4d4(u32 arg0, u32 arg1) {
    u32 value0;
    u32 value1 = arg1;
    u32 value12;
    value12 = (u32) &func_02046b40;
    value0 = (value1) + (0x80u);
    func_02046b40((void *) value0);
}

u8 func_020de4a0(Unk020e43a8 *a, void *b, u8 *c, u8 *d) {
    if (func_020ec450(a, b, c) != 0) {
        func_020d26f8(&a->mUnk_00, b);
    }
    return *d;
}

u8 func_020de488(Unk020e43a8 *a, void *b, u8 *c, u8 *d) {
    func_020ec41c(a, b, c);
    return *d;
}

#pragma thumb on

void func_020de438(void) {
    u32 v1;
    v1 = (u32) func_020d21ec((const char *) data_0216bf7c);
    func_020e6488((Unk020e6488 **) (((u32 *) &data_0217b6f0)), (void *) v1, (u32) 0, (u32) 0);
    v1 = (u32) func_020d21ec((const char *) data_0216bf90);
    func_020e6488((Unk020e6488 **) (((u32 *) &data_0217b6f4)), (void *) v1, (u32) 0, (u32) 0);
    func_020e6ab8((Unk020e6488 *) data_0217b6f0);
    func_020e6ab8((Unk020e6488 *) data_0217b6f4);
}

#pragma thumb off
