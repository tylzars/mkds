#include "01/code_02188218.h"

u16 func_ov001_02188220(Unk02188950 *param_1) {
    u32 v1;
    v1 = param_1->mUnk_0ac;
    if ((int) v1 < 0) {
        v1 = -v1;
    }
    return v1 & 0xffff;
}

void func_ov001_02188218(Unk02188950 *param_1, s32 param_2) {
    param_1->mUnk_0b4 = param_2;
}
