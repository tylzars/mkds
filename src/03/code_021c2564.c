#include "03/code_021c2564.h"
#include "03/code_021bf620.h"
#include "03/code_021c25b4.h"
#include "03/code_021d1000.h"

Unk021c250c *func_ov003_021c2564(void *a) {
    Unk021c250c *b;
    u8 *c;
    u32 d;
    b = func_ov003_021d1cd4(data_ov003_021da190->mUnk_60);
    b->mUnk_08 = func_ov003_021d14b8(a, &d, 4);
    c = b->mUnk_08 + 0x20;
    b->mOffsets = (u32 *) (c + 0x10);
    b->mData = c + *(s32 *) (c + 4) + 8;
    return b;
}
