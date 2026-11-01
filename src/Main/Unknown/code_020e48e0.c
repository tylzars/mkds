#include "Main/Unknown/code_020e48e0.h"

#include "Main/Unknown/code_020ec000.h"
#include "Main/Unknown/unk_02158000.h"

s32 func_020e48e0(Unk020e43a8 *p, void *param_2, u8 *param_3, u8 *param_4) {
    if (*param_3 == 1) {
        func_020ec538(p, param_2);
        p->mUnk_00.mUnk_02 |= data_02158fe4;
        p->mUnk_00.mUnk_80.mUnk_10 = 1;
        p->mUnk_00.mUnk_80.mUnk_12 = 1;
    }
    return *param_4;
}
