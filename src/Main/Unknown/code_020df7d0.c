#include "Main/Unknown/code_020df7d0.h"
#include "Main/Unknown/code_020de9f8.h"
#include "Main/Unknown/code_020df48c.h"

#include "Main/Unknown/code_020df7d8.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_020df85c.h"

void EnterMkdEfBubbleState1(Unk020df85c *bubble) {
    bubble->mUnk_02 |= data_0215877c;
    bubble->mUnk_02 |= data_02158780;
}

void UpdateMkdEfBubbleState1(MkdEfBubbleObject *bubble) {
    if (bubble->mUnk_00.mStateMachine.mStateFrames >= bubble->mUnk_a0) {
        bubble->mUnk_00.mStateMachine.mNextState = 0;
        bubble->mUnk_00.mStateMachine.mNextStateRequested = 1;
    }
}

u8 func_020df7d8(MkdEfBubbleObject *bubble, Unk020dea50_1 *kart, void *unused, u8 *d) {
    u32 kartBit;

    kartBit = (1 << kart->mUnk_74) & 0xff;
    if ((bubble->mUnk_e4 & kartBit) == 0) {
        if (StartSoundIfKartStarOrKiller(&bubble->mUnk_00, (Kart *) kart) != 0) {
            bubble->mUnk_00.mDistanceSquaredAndFlags |= data_02158778;
            bubble->mUnk_e4 |= kartBit;
        }
    }
    return *d;
}

u32 func_020df7d0(u32 unused0, u32 unused1, u32 unused2, u32 bytePointer) {
    return (*OFFSET_PTR(const u8, bytePointer, 0));
}
