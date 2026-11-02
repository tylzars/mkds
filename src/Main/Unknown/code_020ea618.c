#include "Main/Unknown/code_020ea618.h"

void func_020ea618(Unk0209bc74_14 *a, int b) {
    u16 v1;
    u16 v2;
    u16 v3;
    v1 = a->mUnk_6e;
    if (b < (s32) v1) {
        v2 = a->mUnk_6c;
        v3 = func_020d3c44();
        a->mUnk_6c = v3;
        a->mUnk_6e = b;
        func_0207ad88(a);
        a->mUnk_6c = v2;
        a->mUnk_6e = v1;
        return;
    }
    func_0207ad88();
}
