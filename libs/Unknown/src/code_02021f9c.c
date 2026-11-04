#include "code_02021f9c.h"

Unk02021fd0 *FindPartByTag(Unk02021f9c *a, u32 b) {
    u16 i;
    u16 n;
    Unk02021fd0 *p;

    p = (Unk02021fd0 *) ((u8 *) a + a->mUnk_0c);
    n = a->mUnk_0e;
    for (i = 0; i < n; i++) {
        if (p->mUnk_00 == b) {
            return p;
        }
        p = (Unk02021fd0 *) ((u8 *) p + p->mUnk_04);
    }
    return 0;
}

u32 func_02021f9c(Unk02021f9c *a, Unk02021fd0 **b) {
    Unk02021fd0 *p;

    p = FindPartByTag(a, 0x5343524e);
    if (p != 0) {
        *b = p + 1;
        return 1;
    }
    *b = 0;
    return 0;
}
