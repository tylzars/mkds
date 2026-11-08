#include "Main/Unknown/code_0202f028.h"
#include "Main/Unknown/code_0202f020.h"
#include "Main/Unknown/unk_02175628.h"

#pragma optimize_for_size on

u32 func_0202f028(InputSlotPair *a) {
    u32 r = 0;
    if (func_0202f020(a) == 0 && a->mNoPairCount < 5) {
        r = 1;
    }
    return r;
}
