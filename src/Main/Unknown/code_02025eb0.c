#include "Main/Unknown/code_02025eb0.h"
#include "Main/Unknown/unk_02153000.h"

#pragma thumb on
u32 func_02025eb0(u32 characterIndex) {
    u32 value0 = (u32) characterIndex;
    u32 byteOffset;
    byteOffset = (value0 << 2);
    value0 = (u32) &data_021532a8;
    value0 = *(const u32 *) ((value0) + (byteOffset));
    return value0;
}
#pragma thumb off
