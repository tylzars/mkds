#include "Main/Unknown/code_02054f38.h"
#include "Main/Unknown/unk_0217a000.h"

s32 ResetOwnIndex(void) {
    u32 value0;
    u32 noOwnIndex;
    value0 = (u32) &data_0217aa00;
    noOwnIndex = 0xffffu;
    value0 = *(const u32 *) ((value0) + (0));
    value0 = (value0) + (0x400u);
    *(u16 *) ((value0) + (50)) = noOwnIndex;
    return value0;
}
