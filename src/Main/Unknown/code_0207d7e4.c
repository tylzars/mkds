#include "Main/Unknown/code_0207d7e4.h"
#include "Main/Unknown/code_020888b4.h"

void ResetAwardMissionRunKartAiSpeedLimit(struct Unk02089a24 *p0, struct KartAi *kartAi) {
    p0->mSpeedLimit = (u32) (((u32) p0->mBaseSpeedLimit));
    p0->mUnk_08 = 0x0u;
    p0->mTurnSpeedLimit = 0x0u;
    p0->mUnk_10 = (u32) (((u32) p0->mBaseSpeedLimit));
    p0->mRank = (u32) ((~(0x0u)));
    p0->mUnk_18 = 0x0u;
    p0->mUnk_10 = 0x0u;
}
