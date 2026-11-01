#include "00/code_021ae100.h"
#include "00/code_021a998c.h"

u32 func_ov000_021ae100(u16 *param_1, u32 *param_2) {
    Unk021a998c *v1;
    v1 = *(Unk021a998c **) data_0216ff5c.mUnk_04->mUnk_a4;
    if ((v1 != 0) && ((v1->mUnk_08 == 4 || (v1->mUnk_08 == '\n')))) {
        if (param_1 != (u16 *) 0x0) {
            *param_1 = v1->mUnk_18;
        }
        if (param_2 != (u32 *) 0x0) {
            *param_2 = v1->mUnk_14;
        }
        return v1->mUnk_1c;
    }
    return 0;
}
