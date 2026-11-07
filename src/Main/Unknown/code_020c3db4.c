#include "Main/Unknown/code_020c3db4.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217b000.h"

u32 func_020c3db4(void) {
    u32 v = gRaceGoalS->mUnk_00b4;
    RaceSetup *setup = gRaceSetup;

    if (setup->mMode == MODE_VS || setup->mMode == 5 || setup->mMode == MODE_BATTLE) {
        if (setup->mUnk_1c != 0) {
            return v;
        }
    }
    return 0;
}
