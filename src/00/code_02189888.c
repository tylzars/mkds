#include "00/code_02189888.h"

u32 func_ov000_02189888(Unk02188ec0 *param_1) {
    u8 v1;
    int v2;
    u32 v3;
    if ((param_1->mUnk_d16 != 0) && (v2 = func_ov000_0218973c(2), v2 != 0)) {
        v1 = func_ov000_02189df8(0);
        param_1->mUnk_d11 = v1;
        return 5;
    }
    if (param_1->mUnk_d0b_4 < 1) {
        v3 = func_ov000_02189c04(param_1);
        return v3;
    }
    return 6;
}
