#include "code_0214a034.h"

// Returns the address in the sub engine BG VRAM of the character base block set in the BG0 control register.
// Returns the sub engine BG VRAM address of the character base block set in BG0CNT.
u32 G2S_GetBG0CharPtr(void) {
    u32 control;

    control = *(vu16 *) 0x4001008;
    control &= 0x3c;
    control = (s32) control >> 2;
    return (control << 14) + 0x6200000;
}
