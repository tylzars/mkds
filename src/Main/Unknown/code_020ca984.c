#include "Main/Unknown/code_020ca984.h"

#include "Main/Unknown/code_020ca994.h"
#include "Main/Unknown/code_020ca9ac.h"
#include "Main/Unknown/code_020ca9dc.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/unk_0217d068.h"
#include "code_0212df7c.h"

u32 func_020ca9dc(void) {
    return 0x8u;
}

u16 func_020ca9c8(Unk02175628 *a, u32 b) {
    return a->mUnk_00 & b;
}

u16 func_020ca9ac(u32 a, u32 b) {
    return func_020ca9c8(&data_02175628[a], b);
}

u32 func_020ca994(u32 arg0, u32 arg1) {
    u32 value0 = arg0;
    u32 value1 = arg1;
    u32 value2;
    u32 value12;
    value12 = (u32) &func_0212ecc0;
    value2 = value0;
    value0 = (u32) &data_0217d068;
    value0 = (u32) func_0212ecc0((const void *) value0, value1, value2);
    return value0;
}

u32 func_020ca984(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value12;
    value12 = (u32) &func_020ca994;
    value1 = 0u;
    value0 = (u32) func_020ca994(value0, value1);
    return value0;
}
