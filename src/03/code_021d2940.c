#include "03/code_021d2940.h"
#include "03/unk_021da000.h"

s32 func_ov003_021d2940(u16 *output) {
    Unk021da2d4Input *state = data_ov003_021da2d4;
    if (state->mBits.mBit_0 == 0) {
        output[0] = state->mUnk_2c;
        output[1] = state->mUnk_2e;
        return 0;
    }
    output[0] = state->mUnk_28;
    output[1] = state->mUnk_2a;
    return 1;
}
