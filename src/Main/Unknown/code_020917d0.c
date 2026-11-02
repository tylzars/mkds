#include "Main/Unknown/code_020917d0.h"

#include "Main/Unknown/code_020d26f8.h"
#include "Main/Unknown/unk_02156000.h"

void func_0209188c(Unk0209188c *p0) {
    p0->mUnk_02 = (u16) (((((u32) p0->mUnk_02)) | (((u32) data_0215645c))));
}

u8 func_02091828(Unk020912a0 *a, Unk0206bcb0 *b, u8 *c, u8 *d) {
    u8 r;
    r = *d;
    if (*c == 1) {
        a->mUnk_b8 = 0xf333;
        a->mUnk_bc = 0x8000;
        a->mUnk_b0 = 0;
        a->mUnk_b4 = 0;
        a->mUnk_00.mUnk_02 = a->mUnk_00.mUnk_02 | *(u16 *) &data_02156458;
        a->mUnk_c8 = 1;
        func_020d26f8(&a->mUnk_00, b);
    }
    return r;
}

u8 func_020917d0(int a, u32 b, u8 *c, u8 *d) {
    u8 v1;
    v1 = *d;
    if (*c == 1) {
        *(u32 *) (a + 0xb8) = ((u32) 0x0000f333u);
        *(u32 *) (a + 0xbc) = 0x8000;
        *(u32 *) (a + 0xb0) = 0;
        *(u32 *) (a + 0xb4) = 0;
        *(u16 *) (a + 2) = *(u16 *) (a + 2) | (*(u16 *) &data_02156458);
        *(u32 *) (a + 200) = 1;
    }
    return v1;
}
