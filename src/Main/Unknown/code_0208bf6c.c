#include "Main/Unknown/code_0208bf6c.h"
#include "Main/Unknown/code_02090348.h"
#include "Main/Unknown/code_02077bc0.h"

void SetupKartAiForBattle(KartAi *kartAi, s32 kartIndex) {
    Kart *kart;
    kart = GetKart(kartIndex);
    SetupBattleKartAi(kartAi, kart);
    SetupBattleKartAiSpeedLimit(&kartAi->mAiSpeedLimit, kartAi);
    func_02090348(&kartAi->mItemUse);
    PickBattleKartAiRaceStart(kartAi, &kartAi->mUnk_e8);
}

void ResetKartAiForBattle(KartAi *kartAi, PointLink *link) {
    ResetBattleKartAiAtPointLink(kartAi, link);
    SetupBattleKartAiSpeedLimit(&kartAi->mAiSpeedLimit, kartAi);
    func_02090348(&kartAi->mItemUse);
}
