#include "Main/Unknown/code_020ea618.h"

void func_020ea618(Unk0209bc74_14 *param_1, int param_2) {
    u16 uVar1;
    u16 uVar2;
    u16 uVar3;
    uVar1 = param_1->mUnk_6e;
    if (param_2 < (int) (u32) uVar1) {
        uVar2 = param_1->mUnk_6c;
        uVar3 = func_020d3c44();
        param_1->mUnk_6c = uVar3;
        param_1->mUnk_6e = (short) param_2;
        func_0207ad88(param_1);
        param_1->mUnk_6c = uVar2;
        param_1->mUnk_6e = uVar1;
        return;
    }
    func_0207ad88();
}
