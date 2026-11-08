#include "Main/Unknown/code_020901a0.h"
#include "Main/Unknown/code_0207c000.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/unk_027e0000.h"
#include "Main/Unknown/unk_0217b000.h"

void AdvanceBattleItemBitRequests(KartAiItemUse *itemUse, KartAi *kartAi) {
    AdvanceItemBitRequests(itemUse, kartAi);
}

void SetupBattleHeldItemEntry(KartAiItemUse *itemUse, KartAi *kartAi) {
    enum { K0 } heldItemIndex;

    heldItemIndex = *(s32 *) &gKartItems[kartAi->mIndex].mHeldItem;
    itemUse->mHeldItemEntry = gBattleHeldItemEntries + heldItemIndex;
    ResetHeldItemTimer(itemUse);
}

void UseItemWhenHasTarget(KartAiItemUse *itemUse, KartAi *kartAi) {
    if (kartAi->mTargetKart == NULL) {
        return;
    }
    UseItemAndResetInUseTimer(itemUse, kartAi);
}

void UseItemAfterHeldOrOnTarget(KartAiItemUse *itemUse, KartAi *kartAi) {
    if (DecrementHeldItemTimer(itemUse) == 0 && kartAi->mTargetKart == NULL) {
        return;
    }
    UseItemAndResetInUseTimer(itemUse, kartAi);
}

void func_0209024c(KartAiItemUse *itemUse, KartAi *kartAi) {
    if (DecrementHeldItemTimer(itemUse) == 0) {
        return;
    }
    UseItemAndResetInUseTimer(itemUse, kartAi);
}

void func_020901f0(KartAiItemUse *itemUse, KartAi *kartAi) {
    if (DecrementHeldItemTimer(itemUse) == 0 && kartAi->mTargetKart == NULL) {
        return;
    }
    if (kartAi->mTurnAngleDegrees >= 0xa000) {
        return;
    }
    UseItemAndResetInUseTimer(itemUse, kartAi);
}

void UseItemAfterHeldIfTurnUnder10(KartAiItemUse *itemUse, KartAi *kartAi) {
    if (DecrementHeldItemTimer(itemUse) == 0) {
        return;
    }
    if (kartAi->mTurnAngleDegrees >= 0xa000) {
        return;
    }
    UseItemAndResetInUseTimer(itemUse, kartAi);
}
