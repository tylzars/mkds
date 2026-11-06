#include "03/code_021d1cd4.h"
#include "03/code_021d1d88.h"
#include "code_0200c914.h"
#include "code_0200fc8c.h"
#include "code_02147cd8.h"

void func_ov003_021d1d0c(Unk021d1d88 *c, void *d) {
    u32 a = OS_DisableIrqMask(1);
    u32 b = FX_ModS32(c->mUnk_03 + 1, c->mUnk_00);

    if (b == c->mUnk_02) {
        OS_Terminate();
    }
    c->mUnk_04[c->mUnk_03] = d;
    c->mUnk_03 = b;
    OS_EnableIrqMask(a);
}

void *func_ov003_021d1cd4(Unk021d1d88 *d) {
    void *a = NULL;
    u32 b = OS_DisableIrqMask(1);
    u8 c = d->mUnk_03;

    if (d->mUnk_02 != c) {
        d->mUnk_03 = FX_ModS32(c + d->mUnk_00 - 1, d->mUnk_00);
        a = d->mUnk_04[d->mUnk_03];
    }
    OS_EnableIrqMask(b);
    return a;
}
