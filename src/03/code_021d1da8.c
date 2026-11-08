#include "03/code_021d1da8.h"
#include "03/code_021d3488.h"

void AdvanceBlendBrightnessFadeWait(u32 task, BlendBrightnessFadeSlot *state) {
    state->mFrames++;
    if (state->mFrames >= state->mFrameCount) {
        state->mEnabled = 0;
        RequestTaskRemoval(1, task);
    }
}
