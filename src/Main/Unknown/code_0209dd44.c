#include "Main/Unknown/code_0209dd44.h"
#include "Main/Unknown/code_020d26f8.h"
#include "Main/Unknown/unk_02156000.h"

u8 func_0209ddec(Unk0209d694 *a, Unk0206bcb0 *b, u8 *c, u8 *d) {
    u8 x;
    u32 v;

    x = *c;
    v = *d;
    if (x == 1 && a->mUnk_b8 <= 1) {
        a->mUnk_00.mUnk_02 |= data_usa_021565d8;
        a->mUnk_00.mUnk_02 |= data_usa_021565dc;
        a->mUnk_b8 = 2;
        a->mUnk_a0 = 0x168;
        a->mUnk_00.mUnk_10.x = 0;
        a->mUnk_00.mUnk_10.y = 0x3000;
        a->mUnk_00.mUnk_10.z = 0;
        a->mUnk_bc->mUnk_70 = 0x23;
        a->mUnk_c0->mUnk_70 = 0x23;
        a->mUnk_bc->mUnk_80 = 5;
        a->mUnk_c0->mUnk_80 = 5;
        if (b->mUnk_29c == 1 || b->mUnk_29c == 3) {
            a->mUnk_00.mUnk_78 |= data_usa_021565e0;
        }
        func_020d26f8(&a->mUnk_00, b);
    }
    return v;
}

u8 func_0209dd44(Unk0209d694 *a, Unk0206bcb0 *b, u8 *c, u8 *d) {
    u8 x;
    u32 v;

    x = *c;
    v = *d;
    if (x == 1 && a->mUnk_b8 <= 1) {
        a->mUnk_00.mUnk_02 |= data_usa_021565d8;
        a->mUnk_00.mUnk_02 |= data_usa_021565dc;
        a->mUnk_b8 = 2;
        a->mUnk_a0 = 0x168;
        a->mUnk_00.mUnk_10.x = 0;
        a->mUnk_00.mUnk_10.y = 0x3000;
        a->mUnk_00.mUnk_10.z = 0;
        a->mUnk_bc->mUnk_70 = 0x23;
        a->mUnk_c0->mUnk_70 = 0x23;
        a->mUnk_bc->mUnk_80 = 5;
        a->mUnk_c0->mUnk_80 = 5;
    }
    return v;
}
