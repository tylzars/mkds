#include "00/code_021a6fb4.h"
#include "00/code_021a7048.h"
#include "code_0200e904.h"

s32 func_ov000_021a7008(Unk021a7154 *param_1, Unk021a7064 *param_2) {
    s32 a;

    a = func_0200eae8(&param_1->mUnk_00, param_2, param_2 != 0 ? param_2->mUnk_0d : 1);
    if (a == 0) {
        func_ov000_021a7048(param_2);
    }
    if (a != 0) {
        return 0;
    }
    return -42;
}

s32 func_ov000_021a6fc0(Unk021a7154 *param_1, Unk021a7064 *param_2) {
    s32 a;
    void *b;
    Unk0200eb90 c;

    if (param_2->mUnk_0d == 0) {
        param_2->mUnk_08 = 0;
        a = func_ov000_021a7008(param_1, param_2);
    } else {
        func_0200eb90(&c, &b, 1);
        param_2->mUnk_08 = &c;
        func_ov000_021a7008(param_1, param_2);
        func_0200ea3c(&c, (void **) &a, 1);
    }
    return a;
}

s32 func_ov000_021a6fb4(Unk021a6fa8 *param_1, Unk021a7064 *param_2) {
    return func_ov000_021a6fc0(param_1->mUnk_64, param_2);
}
