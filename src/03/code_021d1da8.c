#include "03/code_021d1da8.h"
#include "03/code_021d3488.h"

void func_ov003_021d1da8(u32 task, Unk021d1da8 *state) {
    state->mFrames++;
    if (state->mFrames >= state->mFrameCount) {
        state->mEnabled = 0;
        func_ov003_021d34c8(1, task);
    }
}
