#include "Main/Unknown/code_020e43a4.h"

#include "Main/Unknown/code_020e43a8.h"
#include "Main/Unknown/code_020e4428.h"
#include "Main/Unknown/code_020e4434.h"
#include "Main/Unknown/code_020e4470.h"
#include "Main/Unknown/code_020e4474.h"
#include "Main/Unknown/code_020e44d8.h"

void func_020e44d8(Unk020e44d8 *object) {
    object->mUnk_14c = 0x0u;
}

void func_020e4474(Unk020e43a8 *object) {
    object->mUnk_14c = object->mUnk_14c + object->mUnk_150;
    object->mUnk_00.mAngle = object->mUnk_00.mAngle + (s16) (((s64) object->mUnk_14c * object->mUnk_14a) >> 12);
    if (object->mUnk_00.mStateMachine.mStateFrames > object->mUnk_144) {
        object->mUnk_00.mStateMachine.mNextState = 1;
        object->mUnk_00.mStateMachine.mNextStateRequested = 1;
    }
}

u32 func_020e4470(u32 unused) {
    return unused;
}

void func_020e4434(Unk020e43a8 *object) {
    object->mUnk_00.mAngle = object->mUnk_00.mAngle + object->mUnk_14a;
    if (object->mUnk_146 != 0) {
        if (object->mUnk_00.mStateMachine.mStateFrames > object->mUnk_146) {
            object->mUnk_00.mStateMachine.mNextState = 2;
            object->mUnk_00.mStateMachine.mNextStateRequested = 1;
        }
    }
}

void func_020e4428(Unk020e4428 *object) {
    object->mUnk_14c = 0x1000u;
}

void func_020e43a8(Unk020e43a8 *object) {
    object->mUnk_14c = object->mUnk_14c - object->mUnk_150;
    object->mUnk_00.mAngle = object->mUnk_00.mAngle + (s16) (((s64) object->mUnk_14c * object->mUnk_14a) >> 12);
    if (object->mUnk_00.mStateMachine.mStateFrames > object->mUnk_144) {
        object->mUnk_14a = -object->mUnk_14a;
        object->mUnk_00.mStateMachine.mNextState = 3;
        object->mUnk_00.mStateMachine.mNextStateRequested = 1;
    }
}

u32 func_020e43a4(u32 unused) {
    return unused;
}
