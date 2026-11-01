#include "00/code_0218dd38.h"
#include "00/code_0218db48.h"

void func_ov000_0218dd74(void *param_1, s32 param_2) {
    Unk0218dc94 *a = param_1;
    if (a->mUnk_10 != 0) {
        a->mUnk_10(func_ov000_0218dbf8(a, param_2));
    }
}

void func_ov000_0218dd38(Unk0218dc94 *param_1) {
    param_1->mUnk_04 = param_1->mUnk_04 + param_1->mUnk_0c;
    param_1->mUnk_14 = func_ov000_021a3678(param_1->mUnk_14, param_1->mUnk_04 * param_1->mUnk_08);
    if (param_1->mUnk_14 == 0) {
        func_0213442c(data_ov000_021b2348, data_ov000_021b22dc, 0, 0x41);
    }
}
