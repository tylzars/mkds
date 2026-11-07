#include "Main/Unknown/code_02087cd0.h"
#include "Main/Unknown/code_02087d0c.h"

void func_02087cd0(ModelAnimation *p0, u32 p1) {
    p0->mLoopMode = 1;
    p0->mDone = 0;
    p0->mFrameStep = 0x1000;
    p0->mFrameCountFixed = p1;
    p0->mFrameIndex = 0;
    p0->mLoopsDone = 0;
    p0->mLoopCount = 0;
}
