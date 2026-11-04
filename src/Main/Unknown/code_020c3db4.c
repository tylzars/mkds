#include "Main/Unknown/code_020c3db4.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217b000.h"

u32 func_020c3db4(void) {
    u32 v = gRaceGoalS->mUnk_00b4;
    Unk021759c0 *a = data_021759c0;

    if (a->mMode == 3 || a->mMode == 5 || a->mMode == 2) {
        if (a->mUnk_1c != 0) {
            return v;
        }
    }
    return 0;
}
