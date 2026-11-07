#include "Main/Unknown/code_020901a0.h"
#include "Main/Unknown/code_0207c000.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/unk_027e0000.h"
#include "Main/Unknown/unk_0217b000.h"

void func_0209033c(Unk0208fd8c *a, KartAi *b) {
    AdvanceItemBitRequests(a, b);
}

void SetupBattleHeldItemEntry(Unk0208fd8c *a, KartAi *b) {
    enum { K0 } i;

    i = *(s32 *) &gKartItems[b->mIndex].mHeldItem;
    a->mHeldItemEntry = gBattleHeldItemEntries + i;
    ResetHeldItemTimer(a);
}

void UseItemWhenHasTarget(Unk0208fd8c *a, KartAi *b) {
    if (b->mTargetKart == NULL) {
        return;
    }
    UseItemAndResetInUseTimer(a, b);
}

void UseItemAfterHeldOrOnTarget(Unk0208fd8c *a, KartAi *b) {
    if (DecrementHeldItemTimer(a) == 0 && b->mTargetKart == NULL) {
        return;
    }
    UseItemAndResetInUseTimer(a, b);
}

void func_0209024c(Unk0208fd8c *a, KartAi *b) {
    if (DecrementHeldItemTimer(a) == 0) {
        return;
    }
    UseItemAndResetInUseTimer(a, b);
}

void func_020901f0(Unk0208fd8c *a, KartAi *b) {
    if (DecrementHeldItemTimer(a) == 0 && b->mTargetKart == NULL) {
        return;
    }
    if (b->mTurnAngleDegrees >= 0xa000) {
        return;
    }
    UseItemAndResetInUseTimer(a, b);
}

void UseItemAfterHeldIfTurnUnder10(Unk0208fd8c *a, KartAi *b) {
    if (DecrementHeldItemTimer(a) == 0) {
        return;
    }
    if (b->mTurnAngleDegrees >= 0xa000) {
        return;
    }
    UseItemAndResetInUseTimer(a, b);
}
