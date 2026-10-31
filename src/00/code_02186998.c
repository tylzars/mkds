#include "00/code_02186998.h"

u32 func_ov000_02186998(Unk021868d0 *param_1, Unk02186998 *param_2, int param_3) {
    char *v1;
    if (param_3 <= 0) {
        return 0;
    }
    v1 = param_1->mUnk_014(0, param_2->mUnk_0c + param_3);
    if (v1 == 0) {
        return 0;
    }
    func_0214d1fc(param_2->mUnk_00, v1, param_2->mUnk_0c);
    param_1->mUnk_018(0, param_2->mUnk_00, 0);
    if (v1 == 0) {
        return 0;
    }
    param_2->mUnk_04 = param_2->mUnk_04 + (v1 - param_2->mUnk_00);
    param_2->mUnk_0c = param_2->mUnk_0c + param_3;
    param_2->mUnk_00 = v1;
    param_2->mUnk_08 = v1 + param_2->mUnk_0c;
    return 1;
}
