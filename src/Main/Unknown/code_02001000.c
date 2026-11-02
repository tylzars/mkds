#include "Main/Unknown/code_02001000.h"

void func_02001238(void) {
    Unk021a99c0_18 *v1;
    if (data_usa_02174e54 == 3) {
        v1 = &data_usa_ov001_021a99c0->mUnk_18;
        v1->mUnk_10 = 9;
        v1->mUnk_12 = 1;
        return;
    }
    v1 = &data_usa_ov001_021a99c0->mUnk_18;
    v1->mUnk_10 = 11;
    v1->mUnk_12 = 1;
}

void func_020011f0(void) {
    void *v1;
    v1 = GetBmgEntry(data_usa_ov001_021a99c0->mUnk_38, 137);
    func_02126230(v1, GetBmgEntry(data_usa_ov001_021a99c0->mUnk_38, 6));
}

void func_0200118c(void) {
    Unk021a99c0_18 *v1;
    if (func_02125f54() != 0) {
        func_02125fc0();
        return;
    }
    if (func_02125f88() == 0) {
        return;
    }
    v1 = &data_usa_ov001_021a99c0->mUnk_18;
    v1->mUnk_10 = 10;
    v1->mUnk_12 = 1;
}

void func_02001144(void) {
    void *v1;
    v1 = GetBmgEntry(data_usa_ov001_021a99c0->mUnk_38, 138);
    func_02126230(v1, GetBmgEntry(data_usa_ov001_021a99c0->mUnk_38, 4));
}

void func_020010e0(void) {
    Unk021a99c0_18 *v1;
    if (func_02125f54() != 0) {
        func_02125fc0();
        return;
    }
    if (func_02125f88() == 0) {
        return;
    }
    v1 = &data_usa_ov001_021a99c0->mUnk_18;
    v1->mUnk_10 = 11;
    v1->mUnk_12 = 1;
}

void func_0200104c(void) {
    data_0217aa00->mUnk_0004 = 2;
    data_0217aa00->mUnk_0044.mUnk_3e = 0;
    data_0217aa00->mUnk_008b &= ~8;
}

void func_02001000(void) {
    u8 v1;
    v1 = data_0217aa00->mUnk_008a;
    if (v1 == 0) {
        return;
    }
    if (func_02050320(7, data_0217aa00->mUnk_0044.mUnk_43, v1) == 0) {
        return;
    }
    func_020515b0(v1);
}
