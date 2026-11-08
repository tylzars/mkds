#include "Main/Unknown/code_020acebc.h"

#include "Main/Unknown/code_020acec4.h"
#include "Main/Unknown/code_020ad230.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/code_020acef4.h"
#include "Main/Unknown/code_020acefc.h"

#pragma thumb on
u32 func_020acefc(u32 value) {
    u32 value0 = value;
    u32 functionAddress;
    functionAddress = (u32) &func_020ad230;
    value0 = func_020ad230(value0);
    return value0;
}
#pragma thumb off

u32 func_020acef4(void) {
    return 0x8u;
}

u16 func_020acee0(InputSlot *slot, u32 mask) {
    return slot->mPressedBits & mask;
}

u16 func_020acec4(u32 slotIndex, u32 mask) {
    return func_020acee0(&data_02175628[slotIndex], mask);
}

u32 func_020acebc(const void *pair) {
    return (*OFFSET_PTR(const u16, pair, 4));
}
