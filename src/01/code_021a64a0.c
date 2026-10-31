#include "01/code_021a64a0.h"

void func_ov001_021a651c(void) {
    void *v1;
    Unk020b4934 *v2;
    Unk02021dc8 *v3;
    Unk020b4a44 *v4[1];
    v2 = 0;
    v3 = 0;
    v4[0] = 0;
    v1 = func_0204799c(data_ov001_021a993c);
    func_020b496c(&v2, v1);
    v1 = func_0204799c(data_ov001_021a9938);
    func_020b48ec(&v3, v1);
    v1 = func_0204799c(data_ov001_021a9944);
    func_020b4a7c(v4, v1);
    return;
}

void func_ov001_021a64ac(void *a) {
    data_ov001_021ca424 = func_02036bec(a, 0x10);
    func_020b49bc(&data_ov001_021ca424->mUnk_00, func_0204799c(data_ov001_021a993c));
    func_020b48b4(&data_ov001_021ca424->mUnk_04, func_0204799c(data_ov001_021a9938));
    func_020b4a44((Unk020b4a44 **)&data_ov001_021ca424->mUnk_08, func_0204799c(data_ov001_021a9944));
    data_ov001_021ca424->mUnk_0c = func_0204799c(data_ov001_021a9940);
}

void func_ov001_021a64a0(void) {
    *(u32 *) &data_ov001_021ca424 = 0;
    return;
}
