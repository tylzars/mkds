#include "03/code_021d2a80.h"
#include "03/unk_021da000.h"

u32 func_ov003_021d2a80(const Unk021d299c *v1) {
    Unk021da2d4Input *v2 = data_ov003_021da2d4;
    if (v2->mBits.mBit_0 == 0) {
        return 0;
    }
    if (v1->mUnk_00 > v2->mUnk_28) {
        return 0;
    }
    if (v1->mUnk_04 < v2->mUnk_28) {
        return 0;
    }
    if (v1->mUnk_02 > v2->mUnk_2a) {
        return 0;
    }
    if (v1->mUnk_06 >= v2->mUnk_2a) {
        return 1;
    }
    return 0;
}
