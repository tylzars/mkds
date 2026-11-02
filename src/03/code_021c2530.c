#include "03/code_021c2530.h"
#include "03/unk_021da000.h"

#include "03/code_021d1440.h"
#include "03/unk_021d5000.h"
#include "03/code_021bf4dc.h"
#include "03/code_021d1000.h"
#include "03/code_021d27d8.h"
#include "03/code_021d1d60.h"

void func_ov003_021c25b4(void) {
    data_ov003_021da190 = func_ov003_021d285c(sizeof(Unk021da190), 4);
    data_ov003_021da190->mUnk_60 = func_ov003_021d1d60(8, data_ov003_021da190, 12);
}

void func_ov003_021c25a4(void) {
    func_ov003_021d2808(&data_ov003_021da190);
}

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

void func_ov003_021c2544(int param_1) {
    func_ov003_021d1490(*(void **) (param_1 + 8));
    func_ov003_021d1d0c(data_ov003_021da190->mUnk_60, (void *) (param_1));
    return;
}

int func_ov003_021c2530(int *param_1, u32 param_2) {
    return param_1[1] + *(int *) (*param_1 + (param_2 & ((u32) 0x0000ffffu)) * 4);
}
