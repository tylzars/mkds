#include "00/code_021ae304.h"
#include "Main/Unknown/unk_0216f000.h"

void func_ov000_021ae304(void *arg0) {
    u32 value0 = (u32) arg0;
    u32 value1;
    value1 = (u32) &data_0216ff5c;
    value1 = (u32) * (const u32 *) ((value1) + 4u);
    value1 = (value1) + 164u;
    *(u32 *) ((value1) + 0u) = value0;
    return;
}
