#include "00/code_021aa004.h"

u32 func_ov000_021aa004(int param_1, u32 param_2, u32 param_3) {
    u32 v1;
    u32 v2;
    do {
        v1 = (u32) func_ov000_021adfc8(&v2, (Unk021a998c *) param_3);
        if (v2 == 0) {
            return 0xffffffff;
        }
        if (v2 > param_2) {
            v2 = param_2;
        }
        func_0214d1fc((const void *) ((u16 *) (u32) (v1)), (void *) ((u32 *) (u32) (param_1)), (u32) (v2));
        func_ov000_021adf30(v2, (Unk021a998c *) param_3);
        param_1 = param_1 + v2;
        param_2 = param_2 - v2;
    } while (0 < (int) param_2);
    return 0;
}
