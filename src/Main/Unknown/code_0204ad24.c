#include "Main/Unknown/code_0204ad24.h"
#include "Main/Unknown/unk_02175000.h"
#include "frameheap.h"

void func_0204ad24(void) {
    u32 value0;
    u32 value1;
    u32 value12;
    value0 = (u32) &data_021759d0;
    value0 = *(const u32 *) ((value0) + (0));
    value1 = 3u;
    value0 = *(const u32 *) ((value0) + (36));
    NNS_FndFreeToFrmHeap((void *) value0, value1);
}
