#include "00/code_02199a00.h"
#include "00/code_0219a014.h"

s32 func_ov000_02199a00(const void *arg0, const void *arg1) {
    const u8 *p0 = arg0;
    const u8 *p1 = arg1;
    s32 value0;
    s32 value1;
    u32 value3;
    value0 = *(const u16 *) (p0 + 12);
    value1 = *(const u16 *) (p1 + 12);
    value3 = (u32) &func_ov000_0219a014;
    value0 = func_ov000_0219a014(value0, value1);
    return value0;
}
