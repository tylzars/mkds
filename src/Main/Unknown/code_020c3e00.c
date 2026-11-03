#include "Main/Unknown/code_020c3e00.h"
#include "Main/Unknown/unk_0217b000.h"

Unk020c3e2c *func_020c3e2c(u32 p0) {
    return (Unk020c3e2c *) &gRaceGoalS->mRaceGoalSBNclr + p0;
}

Nscr *func_020c3e14(u32 p0) {
    return ((Nscr *) gRaceGoalS->mRaceGoalSNscrs[p0]);
}

s32 func_020c3e00(void) {
    return gRaceGoalS->mUnk_00a0;
}
