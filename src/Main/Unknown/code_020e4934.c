#include "Main/Unknown/code_020e4934.h"

u8 func_020e4934(Unk020e43a8 *param_1, Unk020ec6e4 *param_2, u8 *param_3, u8 *param_4) {
    if (*param_3 == 1) {
        func_020ec6e4(param_1, param_2);
        param_1->mUnk_00.mUnk_80.mUnk_10 = 1;
        param_1->mUnk_00.mUnk_80.mUnk_12 = 1;
        param_1->mUnk_00.mUnk_02 = param_1->mUnk_00.mUnk_02 | (data_02158fe4);
        func_020d26f8((void *) param_1, (void *) param_2);
    }
    return *param_4;
}
