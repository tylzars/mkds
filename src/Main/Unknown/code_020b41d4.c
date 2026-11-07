#include "Main/Unknown/code_020b41d4.h"
#include "Main/Unknown/unk_02175000.h"

#pragma thumb on

u32 IsArchiveSlotLoaded(u32 slotIndex) {
    return (data_021759c8->mUnk_00[slotIndex].mLoaded);
}

#pragma thumb off
