#include "Main/Unknown/code_0202f028.h"
#include "Main/Unknown/code_0202f020.h"
#include "Main/Unknown/unk_02175628.h"

#pragma optimize_for_size on

u32 func_0202f028(InputSlotPair *pair) {
    u32 result = 0;
    if (func_0202f020(pair) == 0 && pair->mNoPairCount < 5) {
        result = 1;
    }
    return result;
}
