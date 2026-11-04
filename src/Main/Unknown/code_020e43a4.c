#include "Main/Unknown/code_020e43a4.h"

#include "Main/Unknown/code_020e43a8.h"
#include "Main/Unknown/code_020e4428.h"
#include "Main/Unknown/code_020e4434.h"
#include "Main/Unknown/code_020e4470.h"
#include "Main/Unknown/code_020e4474.h"
#include "Main/Unknown/code_020e44d8.h"

void func_020e44d8(Unk020e44d8 *p0) {
    p0->mUnk_14c = (u32) 0x0u;
}

void func_020e4474(Unk020e43a8 *p) {
    p->mUnk_14c = p->mUnk_14c + p->mUnk_150;
    p->mUnk_00.mAngle = p->mUnk_00.mAngle + (s16) (((s64) p->mUnk_14c * p->mUnk_14a) >> 12);
    if (p->mUnk_00.mUnk_80.mStateFrames > p->mUnk_144) {
        p->mUnk_00.mUnk_80.mNextState = 1;
        p->mUnk_00.mUnk_80.mNextStateRequested = 1;
    }
}

u32 func_020e4470(u32 p0) {
    return p0;
}

void func_020e4434(Unk020e43a8 *p) {
    p->mUnk_00.mAngle = p->mUnk_00.mAngle + p->mUnk_14a;
    if (p->mUnk_146 != 0) {
        if (p->mUnk_00.mUnk_80.mStateFrames > p->mUnk_146) {
            p->mUnk_00.mUnk_80.mNextState = 2;
            p->mUnk_00.mUnk_80.mNextStateRequested = 1;
        }
    }
}

void func_020e4428(Unk020e4428 *p0) {
    p0->mUnk_14c = (u32) 0x1000u;
}

void func_020e43a8(Unk020e43a8 *p) {
    p->mUnk_14c = p->mUnk_14c - p->mUnk_150;
    p->mUnk_00.mAngle = p->mUnk_00.mAngle + (s16) (((s64) p->mUnk_14c * p->mUnk_14a) >> 12);
    if (p->mUnk_00.mUnk_80.mStateFrames > p->mUnk_144) {
        p->mUnk_14a = -p->mUnk_14a;
        p->mUnk_00.mUnk_80.mNextState = 3;
        p->mUnk_00.mUnk_80.mNextStateRequested = 1;
    }
}

u32 func_020e43a4(u32 p0) {
    return p0;
}
