#include "00/code_021ae01c.h"

u8 *func_ov000_021ae01c(u32 *param_1, Unk021a998c *param_2) {
    u32 v1;
    v1 = param_2->mUnk_44;
    while (v1 == 0) {
        param_2->mUnk_04 = 3;
        func_0200e01c((Unk0200df9c *) (0));
        v1 = param_2->mUnk_44;
    }
    *param_1 = v1;
    return param_2->mUnk_40;
}
