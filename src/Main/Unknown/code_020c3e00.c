#include "Main/Unknown/code_020c3e00.h"
#include "Main/Unknown/unk_0217b000.h"

Unk020c3e2c *GetRaceGoalSBPaletteAndChars(u32 index) {
    return (Unk020c3e2c *) &gRaceGoalS->mRaceGoalSBNclr + index;
}

Nscr *GetRaceGoalSNscr(u32 index) {
    return (gRaceGoalS->mRaceGoalSNscrs[index]);
}

s32 func_020c3e00(void) {
    return gRaceGoalS->mUnk_00a0;
}
