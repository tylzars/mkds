#include "00/code_021abd2c.h"
#include "code_0214d018.h"

void func_ov000_021abd2c(Unk021abca0 *a) {
    MemFill((void *) (a), (u8) (0), (u32) (0x5c));
    a->mUnk_00 = ((u32) 0x67452301u);
    a->mUnk_04 = ((u32) 0xefcdab89u);
    a->mUnk_08 = ((u32) 0x98badcfeu);
    a->mUnk_0c = ((u32) 0x10325476u);
    a->mUnk_10 = ((u32) 0xc3d2e1f0u);
    return;
}
