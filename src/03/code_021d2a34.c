#include "03/code_021d2a34.h"
#include "03/unk_021da000.h"

u32 func_ov003_021d2a34(const Unk021d299c *rect) {
    Unk021da2d4Input *input = data_ov003_021da2d4;
    if ((((u32) input->mUnk_38 << 30) >> 31) == 0) {
        return 0;
    }
    if (rect->mUnk_00 > input->mUnk_28) {
        return 0;
    }
    if (rect->mUnk_04 < input->mUnk_28) {
        return 0;
    }
    if (rect->mUnk_02 > input->mUnk_2a) {
        return 0;
    }
    if (rect->mUnk_06 >= input->mUnk_2a) {
        return 1;
    }
    return 0;
}
