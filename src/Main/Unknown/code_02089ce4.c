#include "Main/Unknown/code_02089ce4.h"
#include "Main/Unknown/code_020888b4.h"

void func_02089ce4(KartAiSpeedLimit *p0, KartAi *p1) {
    p0->mBaseSpeedLimit = p1->mKart->mPhysicalParam->mBaseSpeedLimit;
    p0->mSpeedLimit = p0->mBaseSpeedLimit;
    p0->mUnk_08 = 0x5000;
    p0->mUnk_0c = FALSE;
    p0->mTurnSpeedLimit = 0;
}
