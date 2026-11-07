#include "Main/Unknown/code_020c3db4.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217b000.h"

u32 func_020c3db4(void) {
    u32 v = gRaceGoalS->mUnk_00b4;
    RaceSetup *a = gRaceSetup;

    if (a->mMode == MODE_VS || a->mMode == 5 || a->mMode == MODE_BATTLE) {
        if (a->mUnk_1c != 0) {
            return v;
        }
    }
    return 0;
}
