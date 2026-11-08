#include "01/code_02180cb4.h"

#pragma optimize_for_size on

void ClearChars(u16 *chars) {
    s32 i;

    for (i = 0; i < 0x3000; i++) {
        chars[i] = 0;
    }
}

void FillScreenMapIndices(u16 *screenMap) {
    u16 i;

    for (i = 0; i < 0x300; i++) {
        screenMap[i] = i;
    }
}
