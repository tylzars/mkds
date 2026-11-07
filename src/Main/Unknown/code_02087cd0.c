#include "Main/Unknown/code_02087cd0.h"
#include "Main/Unknown/code_02087d0c.h"

void ResetModelAnimationLooping(ModelAnimation *animation, u32 frameCountFixed) {
    animation->mLoopMode = 1;
    animation->mDone = 0;
    animation->mFrameStep = 0x1000;
    animation->mFrameCountFixed = frameCountFixed;
    animation->mFrameIndex = 0;
    animation->mLoopsDone = 0;
    animation->mLoopCount = 0;
}
