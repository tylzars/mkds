#include "03/code_021d2940.h"

#include "03/unk_021da000.h"

u32 func_ov003_021d2b20(u32 a) {
    if (a == (a & data_ov003_021da2d4->mUnk_30)) {
        return 1;
    }
    return 0;
}

u32 func_ov003_021d2b04(u32 a) {
    if (a == (a & data_ov003_021da2d4->mUnk_32)) {
        return 1;
    }
    return 0;
}

u32 func_ov003_021d2ae8(u32 a) {
    if (a == (a & data_ov003_021da2d4->mUnk_34)) {
        return 1;
    }
    return 0;
}

u32 func_ov003_021d2acc(u32 a) {
    if (a == (a & data_ov003_021da2d4->mUnk_36)) {
        return 1;
    }
    return 0;
}

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

u32 func_ov003_021d29e8(const Unk021d299c *rect) {
    Unk021da2d4Input *input = data_ov003_021da2d4;
    if ((((u32) input->mUnk_38 << 29) >> 31) == 0) {
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

u32 func_ov003_021d299c(const Unk021d299c *rect) {
    Unk021da2d4Input *input = data_ov003_021da2d4;
    if ((((u32) input->mUnk_38 << 28) >> 31) == 0) {
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

u32 func_ov003_021d2970(const Unk021d299c *input) {
    Unk021d299c rect;
    rect.mUnk_00 = input->mUnk_00;
    rect.mUnk_02 = input->mUnk_02;
    rect.mUnk_04 = input->mUnk_00 + input->mUnk_04;
    rect.mUnk_06 = input->mUnk_02 + input->mUnk_06;
    return func_ov003_021d2a34(&rect);
}

BOOL func_ov003_021d2940(u16 *output) {
    Unk021da2d4Input *state = data_ov003_021da2d4;
    if (state->mBits.mBit_0 == 0) {
        output[0] = state->mUnk_2c;
        output[1] = state->mUnk_2e;
        return FALSE;
    }
    output[0] = state->mUnk_28;
    output[1] = state->mUnk_2a;
    return TRUE;
}
