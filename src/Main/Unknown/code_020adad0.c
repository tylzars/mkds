#include "Main/Unknown/code_020adad0.h"
#include "Main/Unknown/unk_0217b000.h"

#pragma optimize_for_size on
#pragma thumb on

void SetTitleState(u32 a, u32 b) {
    gTitleScene->mStateFrames = 0;
    gTitleScene->mUnk_04 = TRUE;
    gTitleScene->mPrevState = gTitleScene->mState;
    gTitleScene->mState = a;
    gTitleScene->mNextState = b;
}

#pragma thumb off
