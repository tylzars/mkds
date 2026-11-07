#include "Main/Unknown/code_02053e54.h"
#include "Main/Unknown/unk_0217a000.h"

u32 func_02053e54(void) {
    u32 value0;
    u32 flags;
    value0 = (u32) &data_0217aa00;
    value0 = *(const u32 *) ((value0) + (0));
    value0 = (value0) + (0x400u);
    flags = *(const u16 *) ((value0) + (84));
    flags = (flags) & ~(8u);
    *(u16 *) ((value0) + (84)) = flags;
    return value0;
}
