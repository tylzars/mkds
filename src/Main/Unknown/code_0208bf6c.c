#include "Main/Unknown/code_0208bf6c.h"
#include "Main/Unknown/code_02090348.h"
#include "Main/Unknown/code_02077bc0.h"

void func_0208bf94(KartAi *a, s32 b) {
    Kart *v1;
    v1 = GetKart(b);
    SetupBattleKartAi(a, v1);
    func_02089ce4(&a->mAiSpeedLimit, a);
    func_02090348(&a->mItemUse);
    func_02089a24(a, &a->mUnk_e8);
}

void func_0208bf6c(KartAi *a, Unk02175620_bc *b) {
    ResetBattleKartAiAtPointLink(a, b);
    func_02089ce4(&a->mAiSpeedLimit, a);
    func_02090348(&a->mItemUse);
}
