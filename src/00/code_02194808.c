#include "00/code_02194808.h"
#include "00/code_02194828.h"
#include "00/code_02194840.h"

Unk02194828 *GpiFindProfileByBuddyIndex(GpConnection *a, u32 b) {
    GpiProfileSearch s;

    s.mKey = b;
    s.mEntry = NULL;
    GpiForEachProfileWhileNonZero(a, func_ov000_02194828, &s);
    return s.mEntry;
}
