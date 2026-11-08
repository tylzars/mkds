#include "Main/Unknown/code_0208bd44.h"
#include "Main/Unknown/code_0207d814.h"
#include "Main/Unknown/code_02040de0.h"
#include "Main/Unknown/code_02089ce4.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_0207d000.h"
#include "Main/Unknown/code_020901a0.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_0207d7e4.h"
#include "Main/Unknown/code_0207e000.h"
#include "Main/Unknown/code_02090000.h"
#include "Main/Unknown/code_02077bc0.h"

void AdvanceKartAiForBattle(KartAi *kartAi) {
    AdvanceBattleKartAi(kartAi);
    AdvanceBattleKartAiSpeedLimit(&kartAi->mAiSpeedLimit, kartAi);
    AdvanceBattleItemBitRequests(&kartAi->mItemUse, kartAi);
}

void RequestBattleKartAiPointLink(KartAi *kartAi) {
    if (kartAi->mBattleLinkCursor.mRequestedLink != NULL) {
        if (kartAi->mBattleLinkCursor.mUnk_18 != FALSE) {
            return;
        }
    }
    kartAi->mBattleLinkCursor.mRequestedLink = FindCourseMapKind4ShapeBattlePointLink(&kartAi->mKart->mPos);
    if (kartAi->mBattleLinkCursor.mRequestedLink != NULL) {
        kartAi->mBattleLinkCursor.mUnk_18 = TRUE;
    }
}

BOOL IsBattleKartAiLinkRequested(KartAi *kartAi) {
    return kartAi->mBattleLinkCursor.mRequestedLink != NULL;
}

void CopyBattleKartAiLinkPosAndDirection(Vec3 *position, Vec3 *direction, KartAi *kartAi) {
    LinkCursor *cursor = &kartAi->mBattleLinkCursor;

    *position = *cursor->mLink->mUnk_20;
    *direction = cursor->mDirection;
}

void SetupBattleKartAiHeldItemEntry(KartAi *kartAi) {
    SetupBattleHeldItemEntry(&kartAi->mItemUse, kartAi);
}

void SetupBattleKartAiItemInUseEntry(KartAi *kartAi) {
    SetupBattleItemInUseEntry(&kartAi->mItemUse, kartAi);
}

void SetupKartAiForAwardMissionRun(KartAi *kartAi, s32 kartIndex) {
    Kart *kart = GetKart(kartIndex);

    kartAi->mUnk_154 = 0;
    SetupAwardMissionRunKartAi(kartAi, kart, kartAi->mUnk_154);
    func_0207d814(&kartAi->mUnk_e8, kartAi);
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        kartAi->mUnk_e8.mBoostsAtRaceStart = 1;
        kartAi->mUnk_e8.mRaceStartBoostChoice = 4;
    } else {
        kartAi->mUnk_e8.mBoostsAtRaceStart = 0;
        kartAi->mUnk_e8.mRaceStartBoostChoice = 0;
    }
}

void func_0208bde0(KartAi *kartAi, PointLink *pointLink) {
    ResetAwardMissionRunKartAi(kartAi, pointLink);
    ResetAwardMissionRunKartAiSpeedLimit(&kartAi->mUnk_e8, kartAi);
}

void func_0208bdc0(KartAi *kartAi) {
    AdvanceAwardMissionRunKartAi(kartAi);
    func_0207d6a4(&kartAi->mUnk_e8, kartAi);
}

void SetupKartAiForStaffRoll(KartAi *kartAi, s32 kartIndex) {
    Kart *kart = GetKart(kartIndex);

    kartAi->mUnk_154 = 0;
    SetupStaffRollKartAi(kartAi, kart, kartAi->mUnk_154);
    func_0207d814(&kartAi->mUnk_e8, kartAi);
    kartAi->mUnk_e8.mBoostsAtRaceStart = 0;
    kartAi->mUnk_e8.mRaceStartBoostChoice = 0;
    if (kart->mIndex != gRaceSetup->mEntryIndex) {
        kart->mUnk_7c |= 0x40;
    }
}
