#include "00/code_021abd2c.h"
#include "code_0214d018.h"

void func_ov000_021abd2c(u32 *a) {
    func_0214d168((void *) (a), (u8) (0), (u32) (0x5c));
    *a = ((u32) 0x67452301u);
    a[1] = ((u32) 0xefcdab89u);
    a[2] = ((u32) 0x98badcfeu);
    a[3] = ((u32) 0x10325476u);
    a[4] = ((u32) 0xc3d2e1f0u);
    return;
}
