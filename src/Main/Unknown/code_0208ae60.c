#include "Main/Unknown/code_0208ae60.h"
#include "Main/Unknown/unk_0217b000.h"

struct Unk0206cdd4_A *func_0208ae8c(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    value2 = (u32) &data_0217b038;
    value1 = 0x98u;
    value2 = (u32) * (const u32 *) ((value2) + (0));
    value2 = (u32) * (const u32 *) ((value2) + (0));
    value0 = (value1) * (value0) + (value2);
    return (struct Unk0206cdd4_A *) value0;
}

s32 *func_0208ae74(u32 p0) {
    return (s32 *) (data_0217b038->mUnk_04 + (p0 << 3));
}

u32 func_0208ae60(void) {
    return ((u32) data_0217b038->mUnk_08);
}
