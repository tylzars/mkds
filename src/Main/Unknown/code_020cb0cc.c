#include "Main/Unknown/code_020cb0cc.h"

#include "Main/Unknown/code_020cb0ec.h"
#include "Main/Unknown/code_020cb0f4.h"
#include "Main/Unknown/code_020cb114.h"
#include "Main/Unknown/unk_02175628.h"

u32 func_020cb114(u32 p0) {
    return (*OFFSET_PTR(const u16, p0, 0));
}

u32 func_020cb0f4(u32 slotIndex) {
    u32 value0 = slotIndex;
    u32 value1;
    u32 value2;
    u32 value12;
    value2 = (u32) &data_02175628;
    value1 = 0x5cu;
    value1 = (value0) * (value1) + (value2);
    value12 = (u32) &func_020cb114;
    value0 = (value1) + (0x48u);
    value0 = func_020cb114(value0);
    return value0;
}

u32 func_020cb0ec(u32 p0) {
    return (*OFFSET_PTR(const u16, p0, 2));
}

u32 func_020cb0cc(u32 slotIndex) {
    u32 value0 = slotIndex;
    u32 value1;
    u32 value2;
    u32 value12;
    value2 = (u32) &data_02175628;
    value1 = 0x5cu;
    value1 = (value0) * (value1) + (value2);
    value12 = (u32) &func_020cb0ec;
    value0 = (value1) + (0x48u);
    value0 = func_020cb0ec(value0);
    return value0;
}
