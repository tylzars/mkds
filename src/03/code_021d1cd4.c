#include "03/code_021d1cd4.h"
#include "code_0200c914.h"
#include "code_0200fd1c.h"
#include "code_02147cd8.h"

void func_ov003_021d1d0c(Unk021d1d88 *c, void *d) {
    u32 a = func_0200ca9c(1);
    u32 b = func_02147cd8(c->mUnk_03 + 1, c->mUnk_00);

    if (b == c->mUnk_02) {
        func_0200fd1c();
    }
    c->mUnk_04[c->mUnk_03] = d;
    c->mUnk_03 = b;
    func_0200cae4(a);
}

void *func_ov003_021d1cd4(Unk021d1d88 *d) {
    void *a = 0;
    u32 b = func_0200ca9c(1);
    u8 c = d->mUnk_03;

    if (d->mUnk_02 != c) {
        d->mUnk_03 = func_02147cd8(c + d->mUnk_00 - 1, d->mUnk_00);
        a = d->mUnk_04[d->mUnk_03];
    }
    func_0200cae4(b);
    return a;
}
