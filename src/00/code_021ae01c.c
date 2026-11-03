#include "00/code_021a998c.h"
#include "00/code_021ae01c.h"
#include "code_0200dc3c.h"

u8 *func_ov000_021ae01c(u32 *a, Unk021a998c *b) {
    u32 v1;
    v1 = b->mUnk_44;
    while (v1 == 0) {
        b->mUnk_04 = 3;
        func_0200e01c((Unk0200df9c *) (0));
        v1 = b->mUnk_44;
    }
    *a = v1;
    return b->mUnk_40;
}
