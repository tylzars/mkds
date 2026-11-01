#include "03/code_021d1cd4.h"
#include "code_0200c914.h"
#include "code_0200fd1c.h"
#include "code_02147cd8.h"

void func_ov003_021d1d0c(Unk021d1d88 *param_1, void *param_2) {
    u32 a = func_0200ca9c(1);
    u32 b = func_02147cd8(param_1->mUnk_03 + 1, param_1->mUnk_00);

    if (b == param_1->mUnk_02) {
        func_0200fd1c();
    }
    param_1->mUnk_04[param_1->mUnk_03] = param_2;
    param_1->mUnk_03 = b;
    func_0200cae4(a);
}

void *func_ov003_021d1cd4(Unk021d1d88 *param_1) {
    void *a = 0;
    u32 b = func_0200ca9c(1);
    u8 c = param_1->mUnk_03;

    if (param_1->mUnk_02 != c) {
        param_1->mUnk_03 = func_02147cd8(c + param_1->mUnk_00 - 1, param_1->mUnk_00);
        a = param_1->mUnk_04[param_1->mUnk_03];
    }
    func_0200cae4(b);
    return a;
}
