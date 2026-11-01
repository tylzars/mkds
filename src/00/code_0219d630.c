#include "00/code_0219d630.h"

s32 func_ov000_0219d660(void) {
    if (data_ov000_021b5664 != 0) {
        return data_ov000_021b5664->mUnk_14;
    }
    return 0;
}

int func_ov000_0219d630(int param_1) {
    Unk02152500 *v1;
    u32 v2;
    v1 = func_ov000_0219c9c4();
    v2 = func_02152520((void *) (v1), &data_ov000_021b5664->mUnk_18[param_1]);
    if ((v2 == 0) || (v2 == -1)) {
        v2 = 0;
    }
    return v2;
}
