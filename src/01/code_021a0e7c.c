#include "01/code_021a0e7c.h"

void func_ov001_021a0e7c(void) {
    Unk020b4934 *a = 0;
    Unk020b4a44 *b = 0;
    Unk020b4934 *c = 0;
    Unk020b4934 *d = 0;
    Unk020b47d8 *e = 0;
    Unk020b47d8 *f = 0;
    Unk020b4a44 *g = 0;
    u16 *p;

    func_020b4934(&d, func_0204799c(data_ov001_021a92bc));
    func_020b4a44(&g, func_0204799c(data_ov001_021a92a8));
    func_020b47d8(&e, func_0204799c(data_ov001_021a928c));
    func_020b47d8(&f, func_0204799c(data_ov001_021a92c0));
    data_ov001_021ca414->mUnk_48 = func_02036bec(data_ov001_021ca414->mUnk_5c, 0x800);
    data_ov001_021ca414->mUnk_04 = func_0204799c(data_ov001_021a929c);
    data_ov001_021ca414->mUnk_08 = func_0204799c(data_ov001_021a92ac);
    func_020b49bc(&a, func_0204799c(data_ov001_021a9278));
    func_020b48b4(&data_ov001_021ca414->mUnk_00, func_0204799c(data_ov001_021a92c4));
    func_020b4a44(&b, func_0204799c(data_ov001_021a9298));
    data_ov001_021ca414->mUnk_10 = func_0204799c(data_ov001_021a92a4);
    data_ov001_021ca414->mUnk_14 = func_0204799c(data_ov001_021a92a0);
    data_ov001_021ca414->mUnk_18 = func_0204799c(data_ov001_021a9280);
    func_020b49bc(&c, func_0204799c(data_ov001_021a92b0));
    func_020b48b4(&data_ov001_021ca414->mUnk_0c, func_0204799c(data_ov001_021a9284));
    func_020b4a44((Unk020b4a44 **) &data_ov001_021ca414->mUnk_1c, func_0204799c(data_ov001_021a927c));
    p = b->mUnk_0c;
    func_02016468(4, 0, d->mUnk_14, d->mUnk_10);
    func_02016468(0xf, 0, g->mUnk_0c, 0x40);
    func_02016468(8, 0, e->mUnk_0c, e->mUnk_08);
    func_02016468(8, 0x800, data_ov001_021ca414->mUnk_48, 0x800);
    func_02016468(8, 0x1000, data_ov001_021ca414->mUnk_48, 0x800);
    func_02016468(8, 0x1800, data_ov001_021ca414->mUnk_48, 0x800);
    func_02016468(9, 0, f->mUnk_0c, f->mUnk_08);
    func_02016468(9, 0x800, data_ov001_021ca414->mUnk_48, 0x800);
    func_02016468(0x13, 0, a->mUnk_14, a->mUnk_10);
    func_02016468(0xe, 0, b->mUnk_0c, 0x1a0);
    func_02016468(0xe, 0x1c0, p + 0xe0, 0x40);
    func_02016468(0x23, 0, c->mUnk_14, c->mUnk_10);
    func_02016468(0x1e, 0, data_ov001_021ca414->mUnk_1c->mUnk_0c, data_ov001_021ca414->mUnk_1c->mUnk_08);
}
