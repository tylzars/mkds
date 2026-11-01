#include "Main/Unknown/code_020e6a74.h"

u32 func_020e6b48(void) {
    return ((u32) data_0217b860);
}

u32 func_020e6b38(void) {
    return ((u32) data_0217b848);
}

u32 func_020e6b28(void) {
    return ((u32) data_0217b848);
}

u32 func_020e6b14(void) {
    return ((((u32) data_0217b848)) + (0x18u));
}

void func_020e6ab8(Unk020e6488 *p0) {
    p0->mUnk_10 = (u32) (((((u32) p0->mUnk_10)) & (0x8000ffffu)));
    p0->mUnk_10 = (u32) (((((u32) p0->mUnk_10)) | (0x294a0000u)));
    p0->mUnk_14 = (u32) ((p0->mUnk_14 & ~(0x3f000000u)));
    p0->mUnk_14 = (u32) ((p0->mUnk_14 | (0x3f000000u)));
    p0->mUnk_14 = (u32) ((p0->mUnk_14 & ~(0xfu)));
    p0->mUnk_14 = (u32) ((p0->mUnk_14 | (0x2u)));
}

void func_020e6a74(void) {
    u32 v1[1];
    func_01ff9048((u32) 0x17, (void *) (u32) data_0217b854, 0xc);
    v1[0] = 0x1e;
    func_01ff9048((u32) 0x13, (void *) ((u32) v1), 1);
}
