#include "Main/Unknown/code_020c3db4.h"
#include "Main/Unknown/unk_021759c0.h"

u32 func_020c3db4(void) {
    u32 v = gRaceGoalS->mUnk_00b4;
    Unk021759c0 *a = data_021759c0;

    if (a->mUnk_08 == 3 || a->mUnk_08 == 5 || a->mUnk_08 == 2) {
        if (a->mUnk_1c != 0) {
            return v;
        }
    }
    return 0;
}
