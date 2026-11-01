#include "01/code_02193a00.h"

void func_ov001_02193a20(void) {
    Unk020b4934 *a;
    Unk020b47d8 *b;
    Unk020b4a44 *c;

    func_020b4934(&a, func_0204799c(data_ov001_021a8180));
    func_020b47d8(&b, func_0204799c(data_ov001_021a819c));
    func_020b4a44(&c, func_0204799c(data_ov001_021a81b4));
    data_ov001_021a9bd4->mUnk_30 = func_0204799c(data_ov001_021a81d0);
    data_ov001_021a9bd4->mUnk_34 = func_0204799c(data_ov001_021a81e8);
    func_020b49bc(&data_ov001_021a9bd4->mUnk_28, func_0204799c(data_ov001_021a8200));
    func_020b48b4(&data_ov001_021a9bd4->mUnk_24, func_0204799c(data_ov001_021a821c));
    func_020b4a44(&data_ov001_021a9bd4->mUnk_2c, func_0204799c(data_ov001_021a8238));
    func_02016468(4, 0, a->mUnk_14, a->mUnk_10);
    func_02016468(8, 0, b->mUnk_0c, b->mUnk_08);
    func_02016468(15, 0, c->mUnk_0c, 0x100);
    func_02016468(0x23, 0, data_ov001_021a9bd4->mUnk_28->mUnk_14, data_ov001_021a9bd4->mUnk_28->mUnk_10);
    func_02016468(0x1e, 0, data_ov001_021a9bd4->mUnk_2c->mUnk_0c, data_ov001_021a9bd4->mUnk_2c->mUnk_08);
}

void func_ov001_02193a00(void) {
    int v1;
    v1 = func_02036c5c();
    if (v1 != 0) {
        data_ov001_021a9bd4->mUnk_04 = 1;
    }
    return;
}
