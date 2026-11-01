#include "01/code_0219de58.h"

void func_ov001_0219de58(void) {
    Unk020b4934 *a;
    Unk020b47d8 *b;
    Unk020b4a44 *c;

    func_020b4934(&a, func_0204799c((const char *) data_ov001_021a8ce0));
    func_020b47d8(&b, func_0204799c((const char *) data_ov001_021a8cfc));
    func_020b4a44(&c, func_0204799c((const char *) data_ov001_021a8d14));
    data_ov001_021a9bfc->mUnk_44 = func_0204799c((const char *) data_ov001_021a8d30);
    data_ov001_021a9bfc->mUnk_48 = func_0204799c((const char *) data_ov001_021a8d4c);
    data_ov001_021a9bfc->mUnk_4c = func_0204799c((const char *) data_ov001_021a8d68);
    func_020b49bc(&data_ov001_021a9bfc->mUnk_3c, func_0204799c((const char *) data_ov001_021a8d84));
    func_020b48b4(&data_ov001_021a9bfc->mUnk_38, func_0204799c((const char *) data_ov001_021a8da4));
    func_020b4a44(&data_ov001_021a9bfc->mUnk_40, func_0204799c((const char *) data_ov001_021a8dc4));
    func_02016468(4, 0, a->mUnk_14, a->mUnk_10);
    func_02016468(8, 0, b->mUnk_0c, b->mUnk_08);
    func_02016468(0xf, 0, c->mUnk_0c, 0x100);
    func_02016468(0x23, 0, data_ov001_021a9bfc->mUnk_3c->mUnk_14, data_ov001_021a9bfc->mUnk_3c->mUnk_10);
    func_02016468(0x1e, 0, data_ov001_021a9bfc->mUnk_40->mUnk_0c, data_ov001_021a9bfc->mUnk_40->mUnk_08);
}
