#include "03/code_021d250c.h"
#include "03/types_021d299c.h"

void func_ov003_021d2544(u16 a, u16 b, u16 *c) {
    *c = a;
    c[1] = b;
    return;
}

void func_ov003_021d2530(s32 a, s32 b, s32 c, s32 d, u16 *e) {
    *e = a;
    e[1] = b;
    e[2] = c;
    e[3] = d;
    return;
}

void func_ov003_021d250c(u16 *a, u16 *b, Unk021d299c *c) {
    c->mUnk_00 = *a;
    c->mUnk_02 = a[1];
    c->mUnk_04 = *a + *b;
    c->mUnk_06 = a[1] + b[1];
    return;
}
