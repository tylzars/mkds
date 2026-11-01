#include "Main/Unknown/code_020ea618.h"

void func_020ea618(Unk0209bc74_14 *param_1, int param_2) {
    u16 v1;
    u16 v2;
    u16 v3;
    v1 = param_1->mUnk_6e;
    if (param_2 < (int) (u32) v1) {
        v2 = param_1->mUnk_6c;
        v3 = func_020d3c44();
        param_1->mUnk_6c = v3;
        param_1->mUnk_6e = (short) param_2;
        func_0207ad88(param_1);
        param_1->mUnk_6c = v2;
        param_1->mUnk_6e = v1;
        return;
    }
    func_0207ad88();
}
