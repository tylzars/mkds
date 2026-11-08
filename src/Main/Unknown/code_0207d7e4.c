#include "Main/Unknown/code_0207d7e4.h"
#include "Main/Unknown/code_020888b4.h"

void ResetAwardMissionRunKartAiSpeedLimit(struct KartAiRaceSpeedLimit *p0, struct KartAi *kartAi) {
    p0->mSpeedLimit = (u32) (((u32) p0->mBaseSpeedLimit));
    p0->mSpeedLimitAddition = 0x0u;
    p0->mTurnSpeedLimit = 0x0u;
    p0->mSpeedLimitBeforeTurn = (u32) (((u32) p0->mBaseSpeedLimit));
    p0->mRank = (u32) ((~(0x0u)));
    p0->mSpeedLimitReduced = 0x0u;
    p0->mSpeedLimitBeforeTurn = 0x0u;
}
