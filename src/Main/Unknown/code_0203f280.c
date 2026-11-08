#include "Main/Unknown/code_0203f280.h"
#include "Main/Unknown/code_020f36d8.h"

u32 func_0203f2a0(void) {
    return (gRaceSetup->mRuleKind);
}

u16 GetLeadingKart(void) {
    return gRaceProgress->mKartAtRank[0];
}
