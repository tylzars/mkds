#include "Main/Unknown/code_020cebe4.h"
#include "Main/Unknown/unk_02175000.h"

u32 func_020cebe4(void) {
    u32 value0;
    value0 = (u32) &data_021759d0;
    value0 = *(const u32 *) ((value0) + (0));
    value0 = *(const u32 *) ((value0) + (28));
    value0 = (value0 << 29);
    value0 = ((s32) value0 >> 31);
    return value0;
}
