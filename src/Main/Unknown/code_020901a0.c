#include "Main/Unknown/code_020901a0.h"
#include "Main/Unknown/code_0207c000.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/unk_027e0000.h"
#include "Main/Unknown/unk_0217b000.h"

void func_0209033c(KartAiItemUse *a, KartAi *b) {
    AdvanceItemBitRequests(a, b);
}

void SetupBattleHeldItemEntry(KartAiItemUse *a, KartAi *b) {
    enum { K0 } i;

    i = *(s32 *) &gKartItems[b->mIndex].mHeldItem;
    a->mHeldItemEntry = gBattleHeldItemEntries + i;
    ResetHeldItemTimer(a);
}

void UseItemWhenHasTarget(KartAiItemUse *a, KartAi *b) {
    if (b->mTargetKart == NULL) {
        return;
    }
    UseItemAndResetInUseTimer(a, b);
}

void UseItemAfterHeldOrOnTarget(KartAiItemUse *a, KartAi *b) {
    if (DecrementHeldItemTimer(a) == 0 && b->mTargetKart == NULL) {
        return;
    }
    UseItemAndResetInUseTimer(a, b);
}

void func_0209024c(KartAiItemUse *a, KartAi *b) {
    if (DecrementHeldItemTimer(a) == 0) {
        return;
    }
    UseItemAndResetInUseTimer(a, b);
}

void func_020901f0(KartAiItemUse *a, KartAi *b) {
    if (DecrementHeldItemTimer(a) == 0 && b->mTargetKart == NULL) {
        return;
    }
    if (b->mTurnAngleDegrees >= 0xa000) {
        return;
    }
    UseItemAndResetInUseTimer(a, b);
}

void UseItemAfterHeldIfTurnUnder10(KartAiItemUse *a, KartAi *b) {
    if (DecrementHeldItemTimer(a) == 0) {
        return;
    }
    if (b->mTurnAngleDegrees >= 0xa000) {
        return;
    }
    UseItemAndResetInUseTimer(a, b);
}
