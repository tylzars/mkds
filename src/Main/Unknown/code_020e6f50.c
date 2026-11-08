#include "Main/Unknown/code_020e6f50.h"

#pragma thumb on

void SetUpdateListSlot(void *listSlot) {
    *(u32 *) ((u8 *) (u32) (((u32) * (const u32 *) ((u8 *) (u32) listSlot + 0))) + 36) = (u32) listSlot;
}

#pragma thumb off
