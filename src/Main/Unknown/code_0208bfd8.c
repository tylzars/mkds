#include "Main/Unknown/code_0208bfd8.h"
#include "Main/Unknown/code_0207d814.h"
#include "Main/Unknown/code_0207e654.h"
#include "Main/Unknown/code_02040de0.h"
#include "Main/Unknown/code_0207b000.h"
#include "Main/Unknown/code_0207c000.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_0207d000.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_0207e000.h"
#include "Main/Unknown/code_0207f000.h"
#include "Main/Unknown/code_02077bc0.h"

void SetupKartAiForRace(KartAi *kartAi, s32 kartIndex) {
    Kart *kart = GetKart(kartIndex);

    kartAi->mUnk_154 = (gRaceSetup->mCurrentEntries[kartIndex].mPlayer.mUnk_14 & 1) != 0;
    SetupRaceKartAi(kartAi, kart, kartAi->mUnk_154);
    SetupRaceKartAiSpeedLimit(&kartAi->mUnk_e8, kartAi);
    ClearKartAiItemUse(&kartAi->mItemUse);
    PickKartAiRaceStart(&kartAi->mUnk_e8, kartAi);
}

void ResetKartAiForRace(KartAi *kartAi) {
    ResetRaceKartAiAtPointLink(kartAi);
    ResetRaceKartAiSpeedLimit(&kartAi->mUnk_e8, kartAi);
    ClearKartAiItemUse(&kartAi->mItemUse);
}

void AdvanceKartAiForRace(KartAi *kartAi) {
    AdvanceRaceKartAi(kartAi);
    AdvanceRaceKartAiSpeedLimit(&kartAi->mUnk_e8, kartAi);
    AdvanceRaceItemBitRequests(&kartAi->mItemUse, kartAi);
}

void RequestKartAiPointLink(KartAi *kartAi) {
    if (kartAi->mUnk_08.mUnk_00.mRequestedLink != NULL) {
        if (kartAi->mUnk_08.mUnk_00.mUnk_18 != FALSE) {
            return;
        }
    }
    kartAi->mUnk_08.mUnk_00.mRequestedLink = FindCourseMapKind4ShapeRacePointLink(&kartAi->mKart->mPos);
    if (kartAi->mUnk_08.mUnk_00.mRequestedLink != NULL) {
        kartAi->mUnk_08.mUnk_00.mUnk_18 = TRUE;
    }
}

BOOL IsKartAiLinkRequested(KartAi *kartAi) {
    return kartAi->mUnk_08.mUnk_00.mRequestedLink != NULL;
}

void CopyKartAiLinkPosAndDirection(Vec3 *position, Vec3 *direction, KartAi *kartAi) {
    LinkCursor *cursor = &kartAi->mUnk_08.mUnk_00;

    *position = *cursor->mLink->mUnk_18;
    *direction = cursor->mDirection;
}

void func_0208bfec(KartAi *kartAi) {
    SetupHeldItemEntry(&kartAi->mItemUse, kartAi);
}

void func_0208bfd8(KartAi *kartAi) {
    SetupItemInUseEntry(&kartAi->mItemUse, kartAi);
}
