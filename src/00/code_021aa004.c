#include "00/code_021aa004.h"

u32 func_ov000_021aa004(int a, u32 b, u32 c) {
    u32 v1;
    u32 v2;
    do {
        v1 = (u32) func_ov000_021adfc8(&v2, (Unk021a998c *) c);
        if (v2 == 0) {
            return 0xffffffff;
        }
        if (v2 > b) {
            v2 = b;
        }
        func_0214d1fc((const void *) ((u16 *) (u32) (v1)), (void *) ((u32 *) (u32) (a)), (u32) (v2));
        func_ov000_021adf30(v2, (Unk021a998c *) c);
        a = a + v2;
        b = b - v2;
    } while (0 < (s32) b);
    return 0;
}
