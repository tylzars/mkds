#include "01/code_02188218.h"

u16 func_ov001_02188220(Unk02188950 *a) {
    u32 v1;
    v1 = a->mUnk_0ac;
    if ((s32) v1 < 0) {
        v1 = -v1;
    }
    return v1 & 0xffff;
}

void func_ov001_02188218(Unk02188950 *a, s32 b) {
    a->mUnk_0b4 = b;
}
