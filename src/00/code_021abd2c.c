#include "00/code_021abd2c.h"
#include "code_0214d018.h"

void func_ov000_021abd2c(Hash20Context *a) {
    MI_CpuFill8(a, 0, 0x5c);
    a->mUnk_00 = (0x67452301u);
    a->mUnk_04 = (0xefcdab89u);
    a->mUnk_08 = (0x98badcfeu);
    a->mUnk_0c = (0x10325476u);
    a->mUnk_10 = (0xc3d2e1f0u);
}
