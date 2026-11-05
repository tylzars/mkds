#include "Main/Unknown/code_02046be8.h"
#include "Main/Unknown/code_020e005c.h"

void func_02046be8(void *p0, UnkFunc *const *p1, s32 p2, void *p3) {
    Unk020e005c_080 *p = p0;
    p->mUnk_08 = p3;
    p->mUnk_00 = p1;
    p->mUnk_0c = p2;
    p->mStateFrames = 0x0u;
    p->mNextStateRequested = 0x1u;
    p->mState = 0x0u;
    p->mNextState = 0x0u;
}
