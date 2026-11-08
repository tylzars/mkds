#include "Main/Unknown/code_0202cc78.h"
#include "Main/Unknown/code_0211d4a8.h"

#pragma thumb on

s32 GetTimerTensCellIndex(void) {
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2) {
        return 0x38;
    }
    return 0x39;
}

s32 GetTimerOnesCellIndex(void) {
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2) {
        return 0x39;
    }
    return 0x3a;
}

#pragma thumb off
