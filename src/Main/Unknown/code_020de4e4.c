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
